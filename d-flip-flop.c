#include "d-flip-flop.h"


Latch d_flip_flop(int D){
    Latch result;
    result.q = D;
    result.invq = NOT_gate(D);
    return result;
}

