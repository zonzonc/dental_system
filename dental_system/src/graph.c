#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

Graph *graph_create(size_t v)
{
    Graph *g = malloc(sizeof *g);
    if(!g) return NULL;
    g->adj = calloc(v,sizeof(GraphEdge*));
    if(!g->adj){ free(g); return NULL;}
    g->n = v;
    return g;
}

void graph_destroy(Graph *g)
{
    if(!g) return;
    for(size_t i=0;i<g->n;i++){
        GraphEdge *cur=g->adj[i];
        while(cur){ GraphEdge *nxt=cur->next; free(cur); cur=nxt;}
    }
    free(g->adj); free(g);
}

bool graph_add_edge(Graph *g, int u, int v)
{
    if(!g || u<0||v<0|| (size_t)u>=g->n || (size_t)v>=g->n) return false;
    GraphEdge *e = malloc(sizeof *e);
    e->to=v; e->next=g->adj[u];
    g->adj[u]=e;
    return true;
}

void graph_display(const Graph *g)
{
    if(!g) return;
    for(size_t i=0;i<g->n;i++){
        printf("%zu:",i);
        for(GraphEdge *e=g->adj[i]; e; e=e->next)
            printf(" %d",e->to);
        puts("");
    }
}
