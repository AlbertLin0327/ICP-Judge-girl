#include <stdio.h>

int main(){
	int dps[5000];
	int healer[5000];
	int tank[5000];

	int dps_front = 0 , healer_front = 0 , tank_front = 0;
	int dps_rear = 0 , healer_rear = 0 , tank_rear = 0;

	int player;
	while(scanf("%d" , &player) != EOF){
		if(player % 3 == 0){
			dps[dps_rear % 5000] = player;
			dps_rear++;
		}else if(player % 3 == 1){
			healer[healer_rear % 5000] = player;
			healer_rear++;
		}else{
			tank[tank_rear % 5000] = player;
			tank_rear++;
		}



		if(dps_rear - dps_front >= 3 && healer_rear - healer_front >= 1 && tank_rear - tank_front >= 1){
			printf("%d %d %d %d %d\n", dps[dps_front % 5000] , dps[(dps_front + 1) % 5000] , dps[(dps_front + 2) % 5000] , healer[healer_front] , tank[tank_front]);
			dps_front += 3; healer_front++; tank_front++;
		}
		if(dps_front / 5000 == dps_rear / 5000){
			dps_front %= 5000; dps_rear %= 5000;
		}
		if(healer_front / 5000 == healer_rear / 5000){
			healer_front %= 5000; healer_rear %= 5000;
		}
		if(tank_front / 5000 == tank_rear / 5000){
			tank_front %= 5000; tank_rear %= 5000;
		}

	}

	return 0;

}