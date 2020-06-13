#include "book.h"
#include "date.h"
#include <stdbool.h>

// concept : add all date before today

// accumulate days before current month
const int day_per_month[12] = {0 , 31 , 59 , 90 , 120 , 151 , 181 , 212 , 243 , 273 , 304 , 334};
 
unsigned int leap_year(struct Date* current){
    int year = current->year;

    // if current month is JAN or FEB, u won;t have to worry about leap year
    if(current->month <= 2)
        year--;
 
    return (year / 4 - year / 100 + year / 400);
}
 
unsigned int day_in_a_year(struct Date* current){
    int day = leap_year(current);

    // add days month before 
    day += day_per_month[current->month - 1];
    day += current->day;
 
    return day;
}
 
unsigned int bit_distance(struct Book* book){
    int position[2];
    bool index = 0;
    unsigned int importance = book->importance;
    for(int i = 0; i < 64; i++){
        if((bool)((importance >> i) & 1) == 1){
            position[index] = i;
            index = !index;
        }
    }
 
    return (position[1] - position[0] - 1);
 
}
 
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned){
    unsigned int day_between = (date_returned.year - date_borrowed.year) * 365 + (day_in_a_year(&date_returned) - day_in_a_year(&date_borrowed)) + 1;
    unsigned int importance = bit_distance(&book);

    switch(book.type){
        case NOVEL:
            if(day_between > 90){
                return (day_between - 90) * importance;
            }
            break;
        case COMICS:
            if(day_between > 10){
                return (day_between - 10) * importance;
            }
            break;
        case MANUAL:
            if(day_between > 100){
                return (day_between - 100) * importance;
            }
            break;
        case TEXTBOOK:
            if(day_between > 5){
                return (day_between - 5) * importance;
            }
            break;
    }
    return 0;
}