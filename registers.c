#include "registers.h"

ByteBlock common_register(ByteBlock D, int INV, int RST){
    ByteBlock byte = EMPTY_BYTE_BLOCK();
    ByteBlock output;
    ByteLatch b = BYTE_LATCH_FROM_BYTE_BLOCK(D);
    int i;
    if (RST == 1){
        return byte;
    }
    else
    {
        if(INV == 1){
            for(i = 0; i < 8; i++){
                output.block[i] = b.invq[i];
            }
            return output;
        }
        else
        {
            for(i = 0; i < 8; i++){
                output.block[i] = b.q[i];
            }
            return output;
        }
        
    }

}

ByteBlock program_counter_register(ByteBlock D, int INV, int RST){
    ByteBlock byte = EMPTY_BYTE_BLOCK();
    ByteBlock output;
    ByteLatch b = BYTE_LATCH_FROM_BYTE_BLOCK(D);
    int i;
    if (RST == 1){
        return byte;
    }
    else
    {
        for(i = 0; i < 8; i++){
            output.block[i] = b.q[i];
        }
        return output;
    
    }

}

WordBlock ram_register(WordBlock D, int RST){
    if (RST = 1){
        return EMPTY_WORD_BLOCK();
    }
    else
    {
        return D;
    }
    
}