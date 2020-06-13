#include <stdio.h>
#include <stdlib.h>
 
int K, N, L;
char buffer[1<<12];
 
void solve(char C, int index) {
    if (N == 0)
        return;

    buffer[index] = C;
    if (index == L - 1 && N > 0) {
        printf("%s\n", buffer);
        N--;
        return;
    }

    int alphabet = C - 'a';

    if (alphabet + K >= 26) {

    	// cope with all over-wrapped
        for(int i = 0; i <= (alphabet + K) % 26; i++)
            solve('a' + i, index + 1);

        //cope with the other situation left
        for(int i = alphabet + 1; N > 0; i++)
            solve('a' + i , index + 1);
    } else
        for(int i = 1; i <= K; i++)
            solve('a' + alphabet + i , index + 1);
}
 
int main() {
    char C;
    scanf("%c %d %d %d" , &C , &K , &L , &N);
    solve(C , 0);
}