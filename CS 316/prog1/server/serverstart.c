// server.c
// Server to return the request/header/data lines received
// from the browser back to the browser for display
// Author:	Paul Piwowarski
// Date: 	August 2012
//
// Preconditions:
//		Server can listen on port number (no conflict)
//		HTTP 1.1 protocol used
//		Tested on Multilab system
//		Port number passed as parameter
//              Executable program is created from this source file:
//              g++ -o serverStart serverStart.c 
//              You can ignore warning messages
//		Server started on cor with command:
//		  nohup serverStart  &    OR
//		  nohup  ./serverStart  &   
//		  if the current directory is not in your path
//  
//      The nohup command allows the program to run after
//		you have quit your multilab session.
//      Any displayed output (printf) goes to the screen
//      or you can use redirection:
//		  nohup server   > debug.txt  &
//        to save displayed lines to the file debug.txt instead
//      Browser URL used:
//		  http://cor.cs.uky.edu:xxxx/yyy
//			where: 
//			    	cor is where server was started
//                  xxxx is port number that server started on
//					yyy is normally the file to get, but is only
//					echoed back to the browser in the request line
//      or use a form in an html page like:
// <FORM action="http://cor.cs.uky.edu:xxxx/filename" method="post">
//      where 
//           xxxx is the port number of the server
//      any post data in the form will be displayed
//      see cs316post.html in 
//      ~paulp/cs316programs/program1
//      Get method can also be used:
//      see cs316get.html in 
//      ~paulp/cs316programs/program1
//	
// Postconditions:
//	Received request/header lines sent back to browser 
//      If data received after header lines (post), data returned to browser
//      Request logged to log.txt:
//		   client IP address
//		   time of request
//	Program runs forever waiting for client requests
//	Kill server before starting another one on your port number
//  For more information on making an HTTP connection see:
//		http://www.linuxhowtos.org/C_C++/socket.htm

#include <stdio.h>		
#include <sys/wait.h>	// C support for wait  
#include <sys/types.h>	// C support for HTTP  
#include <sys/stat.h>   // stat comamnd
#include <sys/socket.h> // C support for HTTP
#include <netinet/in.h> // C support for HTTP
#include <string.h>		
#include <stdlib.h>
#include <time.h>
#include <arpa/inet.h>	// inet_itoa

// Constant strings for messages sent to client
// response line sent to client
const char HTTP[] = "HTTP/1.1 ";
const char RC200[] = "200";
const char RC200MSG[] = " OK";
// header lines follow response line
// This is a simple header containing the minimum information.
// The client must know what data it is getting (text/plain).
const char CONTENTTYPE[]="\r\nContent-type: text/html\r\n";
// If the data contained HTML tags this would be text/html.
// The server tells the client the size of the data via the
// Content-length header
const char CONTENTLENGTH[] = "Content-length: ";
// Note that the header lines are terminated with a blank line:
// \r\n
const char BLANKLINE[] = "\r\n";
// After this blank line the data is sent to the client.
// For GET this is an HTML file to be displayed. In this
// program all data from the client is returned.

// These messages not used in this program, but must
// be returned in the 404 response as data for program 1
// so that Firefox displays a 404 error to the client
// IE does not use this with 404 responses, however just
// always send it. You do not have to determine which browser
// sent the request
const char FIREFOX1[] ="<html><head><title>404 - Not Found</title></head>";
const char FIREFOX2[]="<body><h1>404 - Not found</h1>";
const char FIREFOX3[]="<p>The server could not find the file you were requesting";
const char FIREFOX4[]="</body></html>";
// For Program 1, also add a Firefox message for 403 (read flag off for others) 
// Function prototypes
void httpthread(int, struct sockaddr_in); 
void handleRequest(int sock, char*, char*);
// Simple error function to print message and exit
void error(char *msg)
{
    printf("Error detected. Error message: %s\n",msg);
    exit(1);
}

// getpermissions: verify that file can be opened and read permission for others is on
// preconditions:
//     file name to check passed as parameter
// returns:
//    1 file not found
//    0 read permission on
//    2 read permission off 
int getpermissions(char * file_name)
{  
    struct stat  stat_buf; 
    // Check if file exists
    if ( stat( file_name, &stat_buf) == -1) {
        printf("File not found: %s.\n",file_name);  // testing mesage
        return 1;
    }
    // Check file read permission for others
    if (stat_buf.st_mode & S_IROTH) {
         printf("Read permission for others on for file %s.\n",file_name);  // test
         return(0);
    }
    printf("Read permission for others off for file %s.\n",file_name); // test
    return(2);
}
// Function to eliminate zombies
void SigCatcher(int n)
{
  wait3(NULL,WNOHANG,NULL);
}

int main(int argc, char *argv[])
{
	 //check port number argument for invalid characters 
	 //each character must be numeric
	 unsigned int
		curr_char		= 0,
		total_char		= strlen(argv[1]);
	 while(curr_char<total_char)
	 {
		//error out if ascii value of character is not a number between 0-9
		if(argv[1][curr_char]<'0' || argv[1][curr_char]>'9')
		{
			error("PORT number must be all numeric");
		}
		curr_char++;
	 }
	 int portno;  // port number passed as parameter 
	 portno = atoi(argv[1]);  // convert port num to integer
	 //port number must be greater than or equal to 1024
	 if(portno<1024)
	 {
		error("PORT number must be >= 1024");
	 }
	 
     printf("Port: %i\n",portno);
     // Signal SigCatcher to eliminate zombies
     // a zombie is a thread that has ended but must
     // be terminated to remove it
     signal(SIGCHLD,SigCatcher);
     int sockfd;   	// socket for binding
     int newsockfd;  	// socket for this connection
     int clilen;	// size of client address
     int pid;		// PID of created thread
     // socket structures used in socket creation
     struct sockaddr_in serv_addr, cli_addr;
     // Create a socket for the connection
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) {
        error("ERROR opening socket\n");
     }
     // bzero zeroes buffers, zero the server address buffer
     bzero((char *) &serv_addr, sizeof(serv_addr));
     // set up the server address 
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     // bind to the socket
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding. Did you forget to kill the last server?\n");
     listen(sockfd,5);    // Listen on socket
     clilen = sizeof(cli_addr);  // size of client address
     while (1) {     // loop forever listening on socket
         newsockfd = accept(sockfd, 
               (struct sockaddr *) &cli_addr, (socklen_t *)&clilen);
 	 if (newsockfd < 0) 
             error("ERROR on accept");
         // Server waits on accept waiting for client request
         // When request received fork a new thread to handle it
         pid = fork();
         if (pid < 0)
             error("ERROR on fork\n");
         if (pid == 0)  {  // request received
             close(sockfd);
	     // Create thread and socket to handle 
             httpthread(newsockfd,cli_addr);
             exit(0);
         }
         else close(newsockfd);
     } /* end of while */
     return 0; /* we never get here */
}

//  httpthread
// There is a separate instance of this function 
// for each connection.  It handles all communication
// once a connnection has been established.
// If the server is canceled while waiting for a client
// request, a "zombie" may result. See the link in the prolog.
// We will ignore this in this simple program.
void httpthread (int sock,  // socket to use
struct sockaddr_in cli_addr) // client address

{
   int n;
   char space[] = " ";
   char buffer[10000];  // buffer for all data from client
   bzero(buffer,10000); // Zero it
   char buffer1[10000]; // buffer for each read of client data
                        // buffer1 is concatentated to buffer 
						// on each read
   bzero(buffer1,10000);
 
   int count = 1;
   fd_set read_flags,write_flags; 
   FD_ZERO(&read_flags); // Zero the flags 
   FD_ZERO(&write_flags); 
   FD_SET(sock, &read_flags);
   struct timeval waitd; 
   waitd.tv_sec = 1;     // Make select wait up to 1 second for data
   waitd.tv_usec = 0;    // and 0 milliseconds.
   // read data from client 
   while (count > 0) {  // select command sets count
	n = read(sock,buffer1,9999); // read from the socked
	if (n <= 0){
		error("ERROR reading from socket in httpthread");
	} else {
			strcat(buffer,buffer1); // concatenate it to previous data
 			bzero(buffer1,1000);
	}
	// select checks if data is available from client
	// count is zero when all data is read
	count=select(sock+1, &read_flags,&write_flags,
               (fd_set*)0,&waitd);  
   }
   // You can use fscanf or strtok to extract data from 
   // client request:
   //    request type(GET POST)
   //	  file name for GET request
   // This program doesn't care, just echoes back 
   // what was sent to it
   char message[200];
   handleRequest(sock, buffer, message);
   // On return, log request
   // File locking
   // For a "real" server, a lock must be obtained
   // on the log file before writing to it 
   // This program (and program 1) will ignore this
   FILE *file_ptr;
   // Open log file for appending
   file_ptr = fopen("logfile.txt", "a");    
   time_t timer;
   timer=time(NULL);  // get time or request
   // get client IP address and write to file
   fputs((char*)inet_ntoa(cli_addr.sin_addr), file_ptr);
   fputs(space, file_ptr);
   //write HTTP method, status, and file requested to file
   fputs(message, file_ptr);
   fputs(space, file_ptr);
   // get time of request and write to file
   fputs((char*)asctime(localtime(&timer)), file_ptr);
   fclose(file_ptr);
}

// handleRequest 
// Echo back to client what the client sent to server
// Send:
//	response line
//	headers of content type, content length
//	blank line
//	Data received from client
void handleRequest(int sock,  // socket to use
		   char* buffer,	// buffer of client data
		   char *return_message) 
{	
	char temp_buffer[10000]; // buffer used to print tokens
	strcpy(temp_buffer, buffer); // copy browser request to temp_buffer
	
	
	char
		http_method[4],		//stores GET/POST
		file_name[100],		//stores filename
		last_line[10000];	//stores last line
	int is_internet_explorer	= 1;
	/*
		Why strtok_r() and *save_line, *save_word?
		
		strtok() stores the position of the string statically.
		I want to split the string into both lines and words, so I had
		to use strtok_r(), which allows me to specify my own unique 
		variables to store string position.
	*/
	char 
		*save_line,	//stores line position for strtok_r()
		*line_ptr;	//PEP Pointer to next line token
	int line	= 0; //counts lines
	
	//split by lines
	line_ptr	= (char*)strtok_r(temp_buffer, "\n", &save_line); //point to first line
	while(line_ptr!=NULL)
	{
		line++;
		char 
			curr_line[10000],	//temp line storage
			*save_word,	//stores word position for strtok_r()
			*word_ptr;	//PEP Pointer to next word token
		int	word	= 0;	//counts words

		strcpy(curr_line, line_ptr);	//keep a temp copy of the current line
		
		//split by words
		word_ptr	= (char*)strtok_r(line_ptr, " ", &save_word);	//point to first word
		while(word_ptr!=NULL)
		{
			word++;
			
			if(line==1)
			{
				if(word==1)	//http method always on line 1, word 1
				{
					strcpy(http_method, word_ptr);
				}
				else if(word==2) //filename always on line 1, word 2
				{
					strcpy(file_name, word_ptr);
				}
			}
			else if(word==1 && strcmp(word_ptr, "User-Agent:")==0)	//if first word is "User-Agent:"
			{
				//check "User-Agent:" line for "Chrome" or "Firefox" user agent
				if(strstr(curr_line, "Chrome")!=NULL || strstr(curr_line, "Firefox")!=NULL)
				{
					is_internet_explorer	= 0;
				}
			}
			
			word_ptr	= (char*)strtok_r(NULL, " ", &save_word);	//point to next word
		}//end word split while loop
		
		line_ptr = (char*)strtok_r(NULL, "\n", &save_line);	//point to next line
		
		//save last line of data (it may be name/value pair send by client)
		if(line_ptr==NULL)
		{
			strcpy(last_line, curr_line);
		}
	}//end line split while loop
	
	
	char
		http_status[3],			//holds http numerical status
		http_status_message[20],	//holds http text status
		detailed_error_message[100],	//holds detailed error message
		html_document[10000];	//holds html to send back to client
	
	if(strcmp(http_method, "GET")==0)	//for http method GET
	{
		char full_file_path[200];	//holds full file path
		strcpy(full_file_path, "public");	//set "public" as start of full path
		strcat(full_file_path, file_name);	//append file_name
		
		switch(getpermissions(full_file_path))
		{
			case 0:		//file found and read permisson on
				strcpy(http_status, "200");
				strcpy(http_status_message, "OK");
				
				//since file exist and has read permissions,
				//open and read file contents to send back to browser
				strcpy(html_document, "");
				FILE *file_ptr;
				file_ptr = fopen(full_file_path, "r");	//open file for read
				char buffer[100];	//buffer to hold each 'word'
				while(fgets(buffer, 100, file_ptr))	//loop to get file content word by word
				{
					strcat(html_document, buffer);	//append word to html_document
				}
				fclose(file_ptr);	//close file
				break;
			case 1:		//file not found
				strcpy(http_status, "404");
				strcpy(http_status_message, "Not Found");
				strcpy(detailed_error_message, "The server could not find the file you were requesting");
				break;
			case 2:		//file found but read permission off
				strcpy(http_status, "403");
				strcpy(http_status_message, "Forbidden");
				strcpy(detailed_error_message, "You don't have permission to access this file");
				break;
		}
	}
	else	//for http method POST
	{
		strcpy(http_status, "200");
		strcpy(http_status_message, "OK");
		
		//the last line of buffer contains name/value data pairs
		strcpy(html_document, last_line);
	}
	
	
	//if status isn't 200 and browser isn't internet explorer,
	//generate html error message to send back to browser
	if(strcmp(http_status, "200")!=0 && is_internet_explorer!=1)
	{
		strcpy(html_document, "<html><head><title>");
		strcat(html_document, http_status);
		strcat(html_document, " ");
		strcat(html_document, http_status_message);
		strcat(html_document, "</title></head><body><h1>");
		strcat(html_document, http_status_message);
		strcat(html_document, "</h1><p>");
		strcat(html_document, detailed_error_message);
		strcat(html_document, "</p></body></html>");
	}
	
	
	int buffersize;	  // buffer size as integer
	char buffsizechar[5];  // buffer size as chars to send
	// reponse line:
	write(sock, HTTP, strlen(HTTP));
	write(sock, http_status, strlen(http_status));
	write(sock, http_status_message, strlen(http_status_message));
	// headers:
	write(sock,CONTENTTYPE,strlen(CONTENTTYPE));
	write(sock,CONTENTLENGTH,strlen(CONTENTLENGTH));
	buffersize = strlen(html_document);  // size as int
	// zero the char size field
	bzero(buffsizechar,sizeof(buffsizechar)); 
	sprintf(buffsizechar,"%i",buffersize);  // convert to chars
	write(sock,buffsizechar,strlen(buffsizechar));
	write(sock,BLANKLINE,strlen(BLANKLINE)); // end last header line
	// headers terminated by blank line
	write(sock,BLANKLINE,strlen(BLANKLINE));
	//send html content to client
	write(sock,html_document,strlen(html_document));
	
	
	
	//return_message = http_method + http_status + file_name
	strcpy(return_message, http_method);
	strcat(return_message, " ");
	strcat(return_message, http_status);
	strcat(return_message, " ");
	strcat(return_message, file_name);
	
	
    return;
}

