#include <stdio.h>
#include <stdbool.h>
 
int n , m; bool relation[100][100];
int answer[100]; bool legal[100];
 
bool dfs(int index){
 
    if(index == m){
        for(int i = 0; i < m - 1; i++)
            printf("%d ", answer[i]);
        printf("%d\n", answer[m - 1]);
        return 1;
    }
 
    for(int i = (index == 0 ? 0 : answer[index - 1]); i < n; i++){
        if(!legal[i])
            continue;
 
         legal[i] = 0;
         int changed[100]; int count = 0;
         for(int j = 0; j < n; j++){
             if(relation[i][j] && legal[j]){
                 legal[j] = 0; changed[count] = j; count++;
             }
         }
 
        answer[index] = i;
        if(dfs(index + 1))
            return 1;
 
        legal[i] = 1;
        for(int j = 0; j < count; j++)
            legal[changed[j]] = 1;
    }

    return 0;
}
 
int main(){
 
    while(scanf("%d%d" , &n , &m) == 2){
    	int ones = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0 ; j < n; j++){
                scanf("%d" , &relation[i][j]);
                ones += relation[i][j];
            }
 
        for(int i = 0; i < n; i++)
            legal[i] = 1;
 
        if(!dfs(0))
            printf("no solution\n");
 
    }
}