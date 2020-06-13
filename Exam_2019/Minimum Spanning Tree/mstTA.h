#include <stdbool.h>
 
typedef struct mstTA {
    int cities;
    int road[10][10];
} MSTTA;
 
void initTA(MSTTA *mst, int N);
void addRoadTA(MSTTA *mst, int city1, int city2, int len);
int removeRoadTA(MSTTA *mst, int city1, int city2);
bool hasPathTA(MSTTA *mst, int city1, int city2);
bool connectedTA(MSTTA *mst);