/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2 Structurre and Dynamic Array
 *   Hari dan Tanggal    : Rabu, 22 April 2026
 *   Nama (NIM)          : Muhammad Adnan Habibi Handoyo (13224093)
 *   Nama File           : soal2.c
 *   Deskripsi           : 
 * Program menerima data nama meteor, massa, dan kemurnian kemudian diurutkan
 * berdasarkan kemurnian, massa, dan alfabet
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{
    int vertex;
    int adj[MAX][MAX];
} Graph;

void initGraph(Graph *g, int v){

    g->vertex = v;

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int src, int dest){

    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1;
}

int degree(Graph *g, int v){

    int count = 0;

    for(int i=0; i<g->vertex; i++){

        if(g->adj[v][i] == 1){
            count++;
        }
    }

    return count;
}

int main(){
    Graph g;

    int N, nilai;
    scanf("%d", &N);

    initGraph(&g, N);

    int idxIsolated = 0;
    int maxDerajat = 0;
    int idxderajat = 0;
    int count = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N;j++){
            scanf("%d", &g.adj[i][j]);
            count += g.adj[i][j];
        }
        if(maxDerajat < count){
            maxDerajat = count;
            idxderajat = i;
        }
        if(count == 0){
            idxIsolated = i;
        }
        printf("DEGREE %d %d\n", i, count);
        count = 0;
    }
    printf("MAX_VERTEX %d\n", idxderajat);
    printf("ISOLATED %d\n", idxIsolated);

    return 0;
}
