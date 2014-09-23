/*
Steven Liu
CS315
HW3

______PLEASE COMPILE USING g++!______

This program will use depth-first-search on an adjacency list to
find out if the given graph is a directed acyclic graph (DAG)

The program will first print out the graph's pre and post numbers.
Then the program will print any backedges found.  Finally the program
will print out the linearization of the graph if the graph is verified
to be a valid DAG.

The program should have a time complexity of O(|E| + |V|) because
all the program does is iterate through the edges and vertexes
of the given graph.  Though it may iterate through the graph a total of
2 times, that multiplicative constant is dropped in big O notation.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 128	/* maximum number characters in a line of the input file */
#define MAXNODE 26	/* maximum number of nodes in a graph */

typedef struct edge_r {	        
    int n_index;        	/* index of the destination node */
    struct edge_r * next;
} edge_t;			/* An edge of a graph is represented by the index
				of the destination node, the length of the edge */

typedef struct {		
    char name;
	int visited;
	int pre;
	int post;
    edge_t *edge_list;
} node_t;			/* A node of a graph is represented by the name of 
				of the node and edges starting from it */

node_t graph[MAXNODE];          /* A graph is a list of nodes and associated edges */
int    num_of_nodes;            /* the number of nodes in a graph */

/* Create an edge with destination node index equal to np and length equal to weight */		
edge_t *create_edge(int np) {
    edge_t *ep;
    ep = (edge_t *) malloc(sizeof(edge_t));
    ep->next = NULL;
    ep->n_index = np;
    return(ep);
}

/* Read a graph from file "filename" */
void readgraph(char *filename) {
    FILE *fp;
    char buf[MAXLEN]; 	    /* Buffer for a line from the text file */
    char *tmp[MAXNODE*2];   /* Pointers to the names of nodes, and lengths if available */
    char sep_ch[]=" \n";    /* names and nodes are separated by space and newline */
    char nodename;          /* name of the node */
    int  ni;		/* index to the node */
    int  desti;		/* the destination index */
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
	   	   ep1 = create_edge(desti); 		/* allocate an edge  */
                   if (ep==NULL) graph[ni].edge_list = ep1;
                            else ep->next = ep1;   	/* put the edge to the link list */
                   ep = ep1; 		/* ep points to the end of the list */
		   }
               }
       }
    fclose(fp);
}





int CLOCK = 1;

int linearization_list[MAXNODE];
int POST_CTR = 0;

int HAS_BACKEDGE = 0;



void previsit(node_t * mygraph, int node)
{
	mygraph[node].pre = CLOCK;
	CLOCK++;
}

void postvisit(node_t * mygraph, int node)
{
	mygraph[node].post = CLOCK;
	CLOCK++;
	linearization_list[POST_CTR] = node;
	POST_CTR++;
}


void explore(node_t * mygraph, int node)
{
	mygraph[node].visited = 1;
	previsit(mygraph, node);
	edge_t *pointer = mygraph[node].edge_list;
	while(pointer != NULL)
	{
		if(mygraph[pointer->n_index].visited != 1)
		{
			explore(mygraph, pointer->n_index);
		}
		pointer = pointer->next;
	}
	postvisit(mygraph, node);
}


void dfs(node_t * mygraph)
{
	for(int i=0; i<num_of_nodes; i++)
	{
		mygraph[i].visited = 0;
	}
	
	for(int i=0; i<num_of_nodes; i++)
	{
		if(mygraph[i].visited != 1)
		{
			explore(mygraph, i);
		}
	}
}


void exploreBackedge(node_t * mygraph, int node)
{
	mygraph[node].visited = 1;
	edge_t *pointer = mygraph[node].edge_list;
	while(pointer != NULL)
	{
		if(mygraph[pointer->n_index].visited != 1)
		{
			exploreBackedge(mygraph, pointer->n_index);
		}
		else	//verify the visited node is not a back edge
		{
			//backedge is defined by visited_pre<this_pre && visited_post>this_post
			if(mygraph[pointer->n_index].pre < mygraph[node].pre
				&& mygraph[pointer->n_index].post > mygraph[node].post)
			{
				printf("Node '%c' has a backedge to node '%c'\n", mygraph[node].name, mygraph[pointer->n_index].name);
				HAS_BACKEDGE = 1;
			}
		}
		pointer = pointer->next;
	}
}


void dfsBackedge(node_t * mygraph)
{
	for(int i=0; i<num_of_nodes; i++)
	{
		mygraph[i].visited = 0;
	}
	
	for(int i=0; i<num_of_nodes; i++)
	{
		if(mygraph[i].visited != 1)
		{
			exploreBackedge(mygraph, i);
		}
	}
}


void printNodes()
{
	for(int i=0; i<num_of_nodes; i++)
	{
		printf("%c\n", graph[i].name);
		edge_t *pointer = graph[i].edge_list;
		while(pointer != NULL)
		{
			printf("  %c\n", graph[pointer->n_index].name);
			pointer = pointer->next;
		}
	}
	printf("END\n\n");
}


void printNodesWithNumber()
{
	printf("The graph has the following nodes and node numbers:\n");
	for(int i=0; i<num_of_nodes; i++)
	{
		printf("%c\n", graph[i].name);
		printf("  pre: %d", graph[i].pre);
		printf("  post: %d", graph[i].post);
		printf("\n");
	}
	printf("END\n\n");
}


void printLinearization()
{
	printf("The linearization of the graph is:\n");
	for(int i=POST_CTR-1; i>=0; i--)
	{
		printf("%c", graph[linearization_list[i]].name);
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
   	if (argc==2) readgraph(argv[1]);
      		else printf("Usage: %s name_of_file_containing_the_graph\n", argv[0]);
	
	dfs(graph);		//O(|E| + |V|) depth first search
	
	printNodesWithNumber();
	
	dfsBackedge(graph);	//a second O(|E| + |V|) depth first search to check for backedges
	
	if(HAS_BACKEDGE==0)	//no backedges found
	{
		printf("Is a valid DAG\n");
		printLinearization();
	}
	else
	{
		printf("Not a valid DAG\n");
	}
}
