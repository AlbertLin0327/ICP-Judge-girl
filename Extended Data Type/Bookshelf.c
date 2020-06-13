#include <stdio.h>
#include <string.h>

int hasEOF = 0;

int readchar(){
    static int N = 1 << 20;
    static char buf[1 << 20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf , 1 , N , stdin)) == buf) {
            hasEOF = 1;
            return EOF;   
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x){
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c - '0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c - '0';
    *x *= neg;
    return 1;
}

int main(){
	unsigned long long int bookshelf = 0;
	int num;
	int book = 0;

	while(ReadInt(&num)){
		for(int i = 0; i < 8; i++){
			if((unsigned char)(bookshelf >> (i * 8)) == (unsigned char)num){
				memcpy((char *)&bookshelf + i , (char *)&bookshelf + i + 1 , 7 - i);

			if(book < 8){
				for(int j = 7; j >= 0; j--){
					if(j == 0 || *((char *)&bookshelf + j - 1) != 0){
						memcpy((unsigned char *)&bookshelf + j , (char *)&num , 1);
						break;
					}
				}
			}else{
				memcpy((char *)&bookshelf + 7 , (char *)&num , 1);
				break;
			}	
			break;
			}else if((unsigned char)(bookshelf >> (i * 8)) == 0){
				bookshelf |= ((unsigned long long int)num) << (i * 8);
				book++; break;
			}else if(i == 7){
				memcpy((char *)&bookshelf , (char *)&bookshelf + 1 , 7);
				memcpy((char *)&bookshelf + 7 , (char *)&num , 1);
				book++; break;
			}	
		}
	}

	if(book < 8){
		memmove((char *)&bookshelf + 8 - book , (char *)&bookshelf , book);
		memset((char *)&bookshelf , 0 , 8 - book);
	}

	for(int i = 0; i < 8; i++){
		printf("%d%c", (unsigned char)(bookshelf >> (i * 8)) , i == 7 ? '\n' : ' ');
	}
}