#include <stdio.h>
#define max(x , y) (x > y? x: y)
#define min(x , y) (x < y? x: y)

int main(){
	int N , m;
	scanf("%d%d" , &N , &m);

	int num[N];

	int ans[m][3];


	//To initialize vairable-sized array, you have to use loop instead of initializing it by giving it a value at one time
	for(int i = 0; i < m; i++){
		for(int j = 0; j < 3; j++){
			ans[i][j] = 0;
		}
	}

	for(int i = 0; i < N; i++){
		scanf("%d" , &(num[i]));
	}
	

	for (int i = 0; i < m; i++){

		ans[i][1] = -1; ans[i][2] = 10001; ans[i][0] = 0;

		for (int j = 0; j < N; j++)
		{
			if(num[j] % m == i){
				ans[i][0] += num[j];
				ans[i][1] = max(ans[i][1] , num[j]);
				ans[i][2] = min(ans[i][2] , num[j]);
			}
		}

	}

	for(int i = 0; i < m; i++){
		printf("%d %d %d\n", ans[i][0] , ans[i][1] , ans[i][2]);
		
	}

	return 0;

}