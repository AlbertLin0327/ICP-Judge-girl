#include <stdio.h>
#include "findLength.h"

int main () {
    int N; scanf("%d" , &N);

    int array[256][256];
    int direction[4][2] = {{1,0}, {1,1}, {0,1}, {-1,1}};

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d" , &array[i][j]);
        }
    }

    int max = 0;
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < 4; k++){

                int temp = 0;

                if(array[i][j] == 1){
                    temp = findLength(array , N , i , j , direction[k][0] , direction[k][1]);
                }


                
                max = (temp > max ? temp : max);

            }
        }
    }

    printf("%d\n", max);

    return 0;

}