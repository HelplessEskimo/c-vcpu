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

int main(){
    ByteBlock A = EMPTY_BYTE_BLOCK();
    A.block[7] = 1;
    A.block[6] = 1;
    int output = eight_bit_to_decimal(A);
    printf("%d\n", output);

    ByteBlock out = decimal_to_binary(3);
    print_byteblock(out);
    return 0;
}