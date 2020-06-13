#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bidding.h"
 
struct transaction{
    int bidder;
    int Item;
    int price;
};
 
typedef struct transaction Trans;
 
int cmp(const void* a , const void* b){
    return ((((Trans *)a)->bidder > ((Trans *)b)->bidder) ? 1 : (((Trans *)a)->bidder < ((Trans *)b)->bidder) ? -1 : (((Trans *)a)->Item - ((Trans *)b)->Item));
}
 
 
void bidding(Bid bidSeq[], int m, ItemMinPrice minPriceSeq[], int n){
    Trans data[1000];
    int success_trans = 0;
 
    for(int i = 0; i < n; i++){
        int current_bidder = -1 , current_price = 0;
        for(int j = 0; j < m; j++)
            if(bidSeq[j].itemID == minPriceSeq[i].itemID && bidSeq[j].bidPrice >= minPriceSeq[i].minPrice && bidSeq[j].bidPrice > current_price)
                current_bidder = bidSeq[j].bidderID; current_price = bidSeq[j].bidPrice;
        
        if(current_bidder != -1){
            data[success_trans].bidder = current_bidder; data[success_trans].Item = minPriceSeq[i].itemID; 
            data[success_trans].price = current_price; success_trans++;
        }
    }
 
    qsort(data , success_trans , sizeof(Trans) , cmp);
 
    for(int i = 0; i < success_trans; i++)
        printf("Bidder %d gets item %d with %d dollars\n", data[i].bidder , data[i].Item , data[i].price);
 
    return;
}