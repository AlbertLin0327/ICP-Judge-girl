double payment(int itemID[], double price[], int orderItemID[], int orderQuantity[], int onSaleItemID[]){
    double sum = 0;
 
    int num_of_item = 0;
    while(itemID[num_of_item] != 0){
        num_of_item++;
    }
 
    int index = 0 , id;
    while((id = orderItemID[index]) != 0){
        double id_price , id_quantity = orderQuantity[index];
        int itemID_index = -1 , discount = -1;
        for(int i = 0; i < num_of_item; i++){
            if(itemID[i] == id){
                itemID_index = i;
                id_price = price[i];
                break;
            }else if(itemID[i] == 0){
                itemID_index = -1;
                break;
            }
        }
 
        for(int i = 0; i < num_of_item; i++){
            if(onSaleItemID[i] == id){
                discount = 1;
            }else if(onSaleItemID[i] == 0){
                break;
            }
        }
 
        if(itemID_index != -1){
            if(discount == 1){
                sum += id_price * id_quantity * 0.8;
            }else{
                sum += id_price * id_quantity;
            }
        }
        index++;
    }
 
    if(sum < 490.00){
        sum += 80;
    }
 
    return sum;
 
}