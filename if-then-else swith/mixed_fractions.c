#include <stdio.h>
#include <stdlib.h>

int main(){

	 int a , b , c , d , e , f , g , h , i , j;

	 scanf("%d\n%d\n%d\n%d\n%d\n%d\n%d" , &a , &b , &c , &d , &e , &f , &g);

	
	

	if(a < 0){
		b = a * c - b;
	}else {
		b += a * c;
	}

	if(e < 0){
		f = e * g - f;
	}else {
		f += e * g;
	}

	 switch (d) {

	 	case 0:

			i = b * g + f * c;
			j = c * g;
	 		break;

	 	case 1:

	 		i = b * g - f * c;
	 		j = c * g;
	 		break;

	 	case 2:

	 		 i = b * f;
	 		 j = c * g;
	 		break;

	 	case 3:

	 		i = b * g;
	 		j = c * f;
	 	 	break;

	 	default:
	 		break;

	 }

	h = i / j;
	i = abs(i %= j);
	j = abs(j);

	for(int gcf = 2; gcf < j; gcf++){
		while(!(i % gcf) && !(j % gcf)){
			i /= gcf;
			j /= gcf;
		}
	}

	if(i == 0) j=1;

	printf("%d\n%d\n%d\n" , h , i , j);

	return 0;
	
}