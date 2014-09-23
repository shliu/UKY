/*
Steven Liu
CS315
HW5

______PLEASE COMPILE USING g++!______

This program will use my version of dijkstra's algorithm to find
the shortest path/distance from a source node to a destination node.

When entering the source and destination nodes, please use the node's
character names!  Eg: 'A', 'a', 'd', 'g', etc

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

#define MAXLEN 128	/* maximum number characters in a line of the input file */
#define MAXNODE 26	/* maximum number of nodes in a graph */

typedef struct edge_r {	        
    int n_index;        	/* index of the destination node */
    int len;
    struct edge_r * next;
} edge_t;			/* An edge of a graph is represented by the index
				of the destination node, the length of the edge */

typedef struct {		
    char name;	//the node's letter "name"
	int visited;	//"boolean" used to represent H?
	int dist;	//distance to this node from user specified origin node
	int prev_index;	//index of previous node (of shortest path)
    edge_t *edge_list;
} node_t;			/* A node of a graph is represented by the name of 
				of the node and edges starting from it */

node_t graph[MAXNODE];          /* A graph is a list of nodes and associated edges */
int    num_of_nodes;            /* the number of nodes in a graph */

/* Create an edge with destination node index equal to np and length equal to weight */		
edge_t *create_edge(int np, int weight) {
    edge_t *ep;
    ep = (edge_t *) malloc(sizeof(edge_t));
    ep->next = NULL;
    ep->n_index = np;
    ep->len = weight;
    return(ep);
}

/* Read a graph from file "filename", either with lengths on edges if with_weight=1
                                        or without lengths on edges if with_weight=0 */
void readgraph(char *filename, int with_weight) {
    FILE *fp;
    char buf[MAXLEN]; 	    /* Buffer for a line from the text file */
    char *tmp[MAXNODE*2];   /* Pointers to the names of nodes, and lengths if available */
    char sep_ch[]=" \r\n";    /* names and nodes are separated by space and newline */
    char nodename;          /* name of the node */
    int  ni;		/* index to the node */
    int  desti, len;		/* the destination index and the length of an edge */
    edge_t *ep, *ep1;	/* pointer to the edge structure */
    int  i, j;		

    fp = fopen(filename, "r");
    if (fp==NULL) {printf("File %s does not exist!\n", filename);
                   exit(1);
                  }
    num_of_nodes = 0; 
    while ( fgets (buf, MAXLEN, fp) != NULL ) {	/* read from the file until the end */
       j=0;
       tmp[j] = strtok(buf, sep_ch);		/* separate line by space and new line */
           while (tmp[j] != NULL) {
               j++;
	       tmp[j] = strtok(NULL, (char *) sep_ch);
               }
           if (j>0) {nodename = tmp[0][0];  	/* get the name of the node  */
               ni=nodename - 'A';		/* get the index of the node */
	       if (num_of_nodes < ni + 1) num_of_nodes = ni+1;  /* set the number of nodes */
               graph[ni].name = nodename;
	       graph[ni].edge_list = NULL;
               ep = NULL;
               for (i=1; i<j; i++) {		/* process each edge from the node */
                   desti=tmp[i][0] - 'A';	/* get the destination node index  */
                   len = 1;                     /* default length is set to 1      */
                   if (with_weight) {len = atoi(tmp[i+1]); i++;}   /* with weight format */
	   	   ep1 = create_edge(desti, len); 		/* allocate an edge  */
                   if (ep==NULL) graph[ni].edge_list = ep1;
                            else ep->next = ep1;   	/* put the edge to the link list */
                   ep = ep1; 		/* ep points to the end of the list */
		   }
               }
       }
    fclose(fp);
}



void printNodes()
{
	for(int i=0; i<num_of_nodes; i++)
	{
		printf("%c", graph[i].name);
		printf(" %i", graph[i].dist);
		printf(" %c", graph[graph[i].prev_index].name);
		printf("\n");
		edge_t *pointer = graph[i].edge_list;
		while(pointer != NULL)
		{
			printf("  %c", graph[pointer->n_index].name);
			printf(" %i", pointer->len);
			printf("\n");
			pointer = pointer->next;
		}
	}
	printf("END\n\n");
}




//linear search for smallest distances to a node that has yet to be visited
int shortest_node_index()
{
	int smallest = -1;
	int index = -1;
	
	for(int i=0; i<num_of_nodes; i++)
	{
		if(graph[i].visited==0 && graph[i].dist!=-1)
		{
			if(smallest == -1)	//first non-visited element is the smallest
			{
				smallest = graph[i].dist;
				index = i;
			}
			else if(graph[i].dist < smallest)
			{
				smallest = graph[i].dist;
				index = i;
			}
		}
	}
	
	return index;
}


void dijkstra(int starting_node_index)
{
	for(int i=0; i<num_of_nodes; i++)
	{
		graph[i].visited = 0;
		graph[i].dist = -1;	//-1 used to represent infinity
	}
	graph[starting_node_index].visited = 1;
	graph[starting_node_index].dist = 0;
	graph[starting_node_index].prev_index = starting_node_index;
	
	//creates the initial distance using user specified starting node index
	edge_t *pointer = graph[starting_node_index].edge_list;
	while(pointer != NULL)
	{
		graph[pointer->n_index].dist = pointer->len;
		graph[pointer->n_index].prev_index = starting_node_index;
		pointer = pointer->next;
	}
	
	//look through all immediate neighbors of unvisited nodes with smallest known distance
	int current_node_index = shortest_node_index();
	while(current_node_index != -1)
	{
		//visit all neighboring nodes
		edge_t *pointer = graph[current_node_index].edge_list;
		while(pointer != NULL)
		{
			int dist_to_target = graph[current_node_index].dist + pointer->len;	//total distance to target from current_node
			//update distance of neighboring nodes IF
				//1) this is the first time calculating total distance to target node
				//2) previous known distance to target is > distance to target through current node
			if(graph[pointer->n_index].dist == -1	//1) this is the first time calculating total distance to target node
				|| dist_to_target < graph[pointer->n_index].dist) //2) previous known distance to target is > distance to target through current node
			{
				graph[pointer->n_index].dist = dist_to_target;	//update distance
				graph[pointer->n_index].prev_index = current_node_index;	//update previous node index
			}
			pointer = pointer->next;	//go to next neighbor
		}
		graph[current_node_index].visited = 1;	//mark this node as visited so we don't visit it again in outer loop
		current_node_index = shortest_node_index();	//get the next unvisited node with shortest distance
	}
}


//follows the prev_index from destination to source and prints out all the nodes
void print_shortest_path(int source_index, int destination_index)
{
	int curr_index = destination_index;
	while(curr_index != graph[curr_index].prev_index)
	{
		cout << graph[curr_index].name << " <- ";
		curr_index = graph[curr_index].prev_index;
	}
	cout << graph[source_index].name << endl;
}


int main(int argc, char *argv[]) {
   	if (argc==2) readgraph(argv[1], 1);    
      		else printf("Usage: %s name_of_file_containing_the_graph\n", argv[0]);
			
	char source, destination;
	cout << "Enter the CHARACTER of the source node: ";
	cin >> source;	
	source = tolower(source);
	cout << "Enter the CHARACTER of the destination node: ";
	cin >> destination;
	destination = tolower(destination);
	
	int source_i, destination_i;
	source_i = source - 'a';
	destination_i = destination - 'a';
	
	dijkstra(source_i);
	
	//sometimes it's possible the user specifies sources that do not have paths to 
	//reach destinations, in those cases the destination distance is infinity (-1),
	//and we show the user the appropriate error message
	if(graph[destination_i].dist < 0)
	{
		cout << "The destination could not be reached!" << endl
			<< "There are no path from '" << source << "' to '" << destination << "'" 
			<<endl;
	}
	else
	{
		cout << "The shortest path is: " << endl;
		print_shortest_path(source_i, destination_i);
		cout << "The total distance is: " << graph[destination_i].dist
			<< endl;
	}
}


