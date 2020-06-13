#include <stdio.h>
#include <stdbool.h>

int main(){
	char chr[2];
	int line = 0;

	while((chr[0] = getchar()) != EOF){
		if(chr[0] == '.'){

			
			while((chr[1] = getchar()) == '.'){
				continue;
			}

			if(chr[1] == ' '){
				chr[0] = getchar();

				if(chr[0] == ' '){
					line++;
				}else if(chr[0] == '\0'){
					line++;
				}else if(chr[0] == EOF){
					line++;
				}else if(chr[0] == '\n'){
					while(1){
						chr[1] = getchar();
						if(chr[0] == '\0' || chr[0] == EOF || chr[1] == '\0' || chr[1] == EOF){
							line++;
							break;
						}else if(chr[1] == ' ' || chr[1] == '\n'){
							continue;
						}else {
							break;
						}
					}
				}
			}else if(chr[1] == '\0'){
				line++;
			}else if(chr[1] == EOF){
				line++;
			}else if(chr[1] == '\n'){
				line++;
			}
		}
	}

	printf("%d\n", line);
}