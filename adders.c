#include "adders.h"
#include "logic-gates.c"

HalfAdder halfadder(int A, int B){
    HalfAdder output;

    output.cout = AND_gate(A, B);
    output.sum = XOR_gate(A, B);

    return output;
}

FullAdder fulladder(int A, int B, int CIN){
    FullAdder output;
    HalfAdder ha1;
    HalfAdder ha2;

    ha1 = halfadder(A, B);
    ha2 = halfadder(ha1.sum, CIN);

    output.cout = OR_gate(ha1.cout, ha2.cout);
    output.sum = ha2.sum;

    return output;

}

RippleAdder rippleadder(ByteBlock A, ByteBlock B, int CIN){
    ByteBlock out = EMPTY_BYTE_BLOCK();
    RippleAdder r;
    FullAdder f;  
    
    int cout = 0;
    int i = 7;
    
    do {
        if (i == 7){
            f = fulladder(A.block[i], B.block[i], CIN);
            cout = f.cout;
            out.block[i] = f.sum;
        }
        else{
            f = fulladder(A.block[i], B.block[i], cout);
            cout = f.cout; 
            out.block[i] = f.sum;
        }
        i--;    
    }while(i >= 0);
    
    r.cout = f.cout;
    r.sum = out;

    return r;
}
