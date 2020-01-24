#include <stdio.h>
#include "logic-gates.h"

int main(){

    int buffer_value = 1;
    int buffer_out = -1;
    int NOT_out = -1;
    int AND_out = -1;

    buffer_out = buffer(buffer_value);
    NOT_out = NOT_gate(buffer_value);
    AND_out = NAND_gate(buffer_value, buffer_value);

    printf( "buffer: %d\n", buffer_out);
    printf( "NOT: %d\n", NOT_out);
    printf( "AND: %d\n", AND_out);
    return 0;
}

int buffer(int input_bool){
    int result = 0;
    
    if (input_bool == 1){
        result = 1;
    }
    
    return result;
}


int NOT_gate(int input_bool){
    int result = 1;
    
    if (input_bool == 1){
        result = 0;
    }
    
    return result;
}

int AND_gate(int A, int B){
    int result = 0;

    if (A == 1){
        if (B == 1){
            result = 1;
        }
    }

    return result;
}

int OR_gate(int A, int B){
    int result = 0;

    if (A == 1){ 
        result = 1;
    }
    else if (B == 1){
        result = 1;
    }

    return result;
}

int NAND_gate(int A, int B){
    int result = 0;

    result = NOT_gate(AND_gate(A, B));

    return result;
}

int NOR_gate(int A, int B){
    int result = 0;

    result = NOT_gate(OR_gate(A, B));

    return result;
}

int XOR_gate(int A, int B){
    int result = 0;

    if (A == 1){
        if (B != 1){
            result = 1;
        }
    }
    if (B == 1){
        if (A != 1){
            result = 1;
        }
    }

    return result;
}

int XNOR_gate(int A, int B){
    int result = 0;

    if (A == 1){
        if (B == 1){
            result = 1;
        }
    }
    else if (A == 0){
        if (B == 0){
            result = 1;
        }
    }

    return result;
}