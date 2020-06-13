#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _graph {
	int total_road;
    int path[20000][2];
}Graph;

typedef struct _map{
    int* head[10000];
}Map;

int cmp(const void* a, const void* b){
	return *(int *)a > *(int *)b ? 1 : *(int *)a < *(int *)b ? -1 : *((int *)a + 1) > *((int *)b + 1) ? 1 : *((int *)a + 1) < *((int *)b + 1) ? -1 : 0;
}
 
void init(Graph *graph , int M){
	memset(graph , 0 , sizeof(Graph));
	graph->total_road = 2 * M;
	return;
}

void addRoad(Graph *graph , int city1 , int city2 , int index){
	graph->path[index * 2][0] = graph->path[index * 2 + 1][1] = city1;
	graph->path[index * 2][1] = graph->path[index * 2 + 1][0] = city2;
	return;
}

void normalized(Graph *graph, Map *map){
	int prev = -1;
	for(int i = 0; i < graph->total_road; i++){
		if(prev != graph->path[i][0]){
			prev = graph->path[i][0];
			map->head[prev] = &graph->path[i][0];
		}
	}
}

bool used[10000];

bool hasPath(Graph *graph, Map *map, int city1, int city2){
	if(city1 == city2)
		return true;

	for(int* ptr = map->head[city1]; ptr != NULL && *ptr == city1; ptr += 2){
		if(!used[*(ptr + 1)]){
			used[*(ptr + 1)] = 1;
			if(hasPath(graph , map , *(ptr + 1) , city2))
				return 1;
			//used[*(ptr + 1)] = 0;
		}
	}
	return 0;
}

int main(){
	int M; scanf("%d" , &M);
	Graph graph; init(&graph , M);

	for(int i = 0; i < M; i++){
		int a , b; scanf("%d%d" , &a , &b);
		addRoad(&graph , a , b , i);
	}

	qsort(graph.path , 2 * M , sizeof(int) * 2 , cmp);
	Map map; normalized(&graph , &map);

	int Q; scanf("%d" , &Q);
	for(int i = 0; i < Q; i++){
		int a , b; scanf("%d%d" , &a , &b);
		memset(used , 0 , sizeof(used)); used[a] = 0;
		printf("There is %s path.\n" , hasPath(&graph , &map , a , b) ? "a" : "no");
	}
	
}