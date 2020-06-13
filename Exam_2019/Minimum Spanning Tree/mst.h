#include <stdbool.h>
 
typedef struct mst {
    int cities;
    int road[10][10];
} MST;
 
void init(MST *mst, int N);
void addRoad(MST *mst, int city1, int city2, int len);
int removeRoad(MST *mst, int city1, int city2);
bool hasPath(MST *mst, int city1, int city2);
bool connected(MST *mst);