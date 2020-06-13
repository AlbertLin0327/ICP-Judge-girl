#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "compute.h"

void compute(paper P[], int N){
	int cite[N];
	memset(cite , 0 , N * sizeof(int));

	char journal_sequence[N][64];

	for(int i = 0; i < N; i++){
		memcpy(journal_sequence[i] , P[i].journalName , strlen(P[i].journalName) + 1);
		for(int j = 0; j < P[i].numCitedPaper; j++){
			cite[P[i].citedPaperIndex[j]]++;
		}
	}

	for(int i = 0; i < N - 1; i++){
		for(int j = 0; j < N - i - 1; j++){
			if(strcmp(journal_sequence[j] , journal_sequence[j + 1]) > 0){
				char temp[64];
				memcpy(temp , journal_sequence[j] , strlen(journal_sequence[j]) + 1);
				memcpy(journal_sequence[j] , journal_sequence[j + 1] , strlen(journal_sequence[j + 1]) + 1);
				memcpy(journal_sequence[j + 1] , temp , strlen(temp) + 1);

				cite[j] ^= cite[j + 1] ^= cite[j] ^= cite[j + 1];
			}
		}
	}

	int count_cite = cite[0] , same_journal = 1;

	for(int i = 0; i < N - 1; i++){
		if(!strcmp(journal_sequence[i] , journal_sequence[i + 1])){
			same_journal++; count_cite += cite[i + 1];
		}else{
			printf("%s %d/%d\n", journal_sequence[i] , count_cite , same_journal);
			count_cite = cite[i + 1]; same_journal = 1;
		}
	}
	printf("%s %d/%d\n", journal_sequence[N - 1] , count_cite , same_journal);

	return;
}
