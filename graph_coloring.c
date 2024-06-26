#include<stdio.h>

int G[50][50], x[50]; // G: adjacency matrix, x: array to store colors of vertices

// Function to display colors assigned to vertices
void display(int n) {
    int i;
    printf("Colors of vertices -->\n");
    for(i = 0; i < n; i++)
        printf("Vertex[%d] : %d\n", i + 1, x[i]);
}

// Function to recursively assign colors to vertices
void next_color(int k, int n) {
    int i, j;
    if(k == n) {
        display(n); // If all vertices are colored, display the result
        return;
    }

    x[k] = 1; // Start with the first color for vertex k
    for(i = 0; i < k; i++) {
        // Check all previously colored adjacent vertices
        if(G[i][k] != 0 && x[k] == x[i]) // If there's an edge and same color is assigned
            x[k] = x[i] + 1; // Assign the next available color
    }
    next_color(k + 1, n); // Recursively color next vertex
}

int main() {
    int no, eg, i, j, k, l;
    
    printf("\nEnter no. of vertices : ");
    scanf("%d", &no); // Input number of vertices
    
    printf("\nEnter no. of edges : ");
    scanf("%d", &eg); // Input number of edges
    
    // Initialize adjacency matrix
    for(i = 0; i < no; i++)
        for(j = 0; j < no; j++)
            G[i][j] = 0; // Set all elements to 0 initially
    
    printf("Enter indexes where value is 1-->\n");
    // Input the edges (undirected graph)
    for(i = 0; i < eg; i++) {
        scanf("%d %d", &k, &l);
        G[k][l] = 1; // Mark the edge between vertex k and vertex l
        G[l][k] = 1; // Since it's an undirected graph, mark the reverse edge as well
    }

    next_color(0, no); // Start coloring from vertex 0

    return 0;
}
