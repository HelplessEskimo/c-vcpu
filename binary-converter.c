#include "binary-converter.h"
#include "utils.h"

int eight_bit_to_decimal(ByteBlock input){
    int i = 7;
    int place = 1; 
    int out = 0;
    do{
        if (input.block[i] == 1){
            out = out + place;
        }
        place = place * 2;
        i--;
    } while (i>=0);
    return out;
}


ByteBlock decimal_to_binary(int a){
    int x = 7;
    ByteBlock n = EMPTY_BYTE_BLOCK();
    do{
        n.block[x] = a%2;
        a = a/2;
        x--;
    } while (x>=0);
    
    return n;
}
