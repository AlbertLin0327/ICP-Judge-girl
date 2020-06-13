#include <stdio.h>
 
void fill_rectangle_neg(int *upper_left, int *bottom_right, int n_row, int n_col, int fill){
    int r = 0;
    while(bottom_right - (upper_left + r * n_col) >= n_col){
        r++;
    }
    int c = bottom_right - (upper_left + r * n_col);

    for(int i = 0; i <= r; i++){
        for(int j = 0; j <= c; j++){
            *(upper_left + i * n_col + j) = fill;
        }
    }
 
    return;
}
 
 
 
 
void fill_rectangle_pos(int *upper_right, int *bottom_left, int n_row, int n_col, int fill){
    int r = 0;
    while(upper_right < (bottom_left - r * n_col)){
        r++;
    }
    int c = upper_right - (bottom_left - r * n_col);
 
    int *head = (upper_right - c);
 
    for(int i = 0; i <= r; i++){
        for(int j = 0; j <= c; j++){
            *(head + i * n_col + j) = fill;
        }
    }
 
    return;
}