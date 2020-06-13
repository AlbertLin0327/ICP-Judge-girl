#include <stdio.h>

int main(){

	int n;
	scanf("%d" , &n);

	while(n--){

		int Ax , Ay , Bx , By , Cx , Cy , Dx , Dy , temp;

		scanf("%d %d %d %d %d %d %d %d" , &Ax , &Ay , &Bx , &By , &Cx , &Cy , &Dx , &Dy);

		if( ( ((Bx - Ax) * (Cy - Ay) - (Cx - Ax) * (By - Ay)) < 0 && ((Cx - Ax) * (Dy - Ay) - (Dx - Ax) * (Cy - Ay)) > 0 ) ||\
			( ((Bx - Ax) * (Cy - Ay) - (Cx - Ax) * (By - Ay)) > 0 && ((Cx - Ax) * (Dy - Ay) - (Dx - Ax) * (Cy - Ay)) < 0 ) ) {

			if( (((Ax - Bx) * (Cy - By) - (Cx - Bx) * (Ay - By)) > 0 && ((Ax - Bx) * (Dy - By) - (Dx - Bx) * (Ay - By)) < 0 ) ||\
				(((Ax - Bx) * (Cy - By) - (Cx - Bx) * (Ay - By)) < 0 && ((Ax - Bx) * (Dy - By) - (Dx - Bx) * (Ay - By)) > 0 )){

				temp = Bx;
				Bx = Cx;
				Cx = temp;

				temp = By;
				By = Cy;
				Cy = temp;

			} else {

				temp = Cx;
				Cx = Dx;
				Dx = temp;

				temp = Cy;
				Cy = Dy;
				Dy = temp;

			}
			
		} 

		if( ((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By)) == ((Bx - Cx) * (Bx - Cx) + (By - Cy) * (By - Cy)) &&\
			((Bx - Cx) * (Bx - Cx) + (By - Cy) * (By - Cy)) == ((Cx - Dx) * (Cx - Dx) + (Cy - Dy) * (Cy - Dy)) &&\
			((Cx - Dx) * (Cx - Dx) + (Cy - Dy) * (Cy - Dy)) == ((Dx - Ax) * (Dx - Ax) + (Dy - Ay) * (Dy - Ay)) ){

			if((Ax - Bx) * (Cx - Bx) + (Ay - By) * (Cy - By) == 0){
				printf("square\n");
			} else {
				printf("diamond\n");
			}

		} else {

			if( (Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By) == (Cx - Dx) * (Cx - Dx) + (Cy - Dy) * (Cy - Dy) &&\
				(Bx - Cx) * (Bx - Cx) + (By - Cy) * (By - Cy) == (Ax - Dx) * (Ax - Dx) + (Ay - Dy) * (Ay - Dy) &&\
				(Ax - Bx) * (Cx - Bx) + (Ay - By) * (Cy - By) == 0){
				printf("rectangle\n");
			} else {
				printf("other\n");
			}
		}

	}

	return 0;

}