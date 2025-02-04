#include <stdbool.h>
#include "mst.h"
 
void init(MST *mst, int N){
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            mst->road[i][j] = 0;
    mst->cities = N;
}
 
void addRoad(MST *mst, int city1, int city2, int len){
    mst->road[city1][city2] = mst->road[city2][city1] = len;
}
 
int removeRoad(MST *mst, int city1, int city2){
    int len = mst->road[city1][city2];
    mst->road[city1][city2] = mst->road[city2][city1] = 0;
    return len;
}

bool myhasPath(MST *mst, int city1, int city2 , int N , bool visited[]){
    bool result = 0;
    for(int i = 0; i < N; i++){
        if(mst->road[city1][i] && !visited[i]){
            if(i == city2) return 1;
            visited[i] = 1;
            result += myhasPath(mst , i , city2 , N , visited);
            visited[i] = 0;
        }
    }
    return result;
}
 
bool hasPath(MST *mst, int city1, int city2){
    bool visited[10] = {0};
    return myhasPath(mst , city1 , city2 , mst->cities , visited);
}
 
bool connected(MST *mst){
    for(int i = 1; i < mst->cities; i++)
        if(!hasPath(mst , 0 , i))
            return 0;
    return 1;
}