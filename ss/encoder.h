#ifndef _ENCODER_H_
#define _ENCODER_H_

#include <Arduino.h>

namespace encdr {
    
    const long
        MAX_CHECK_TIME = 20, 
        DEBOUNCE_ENC = 5;

    const int8_t ECDR_SHIFTS[] = { 0,  1, -1,  0,
                                  -1,  0,  0,  1,
                                   1,  0,  0, -1,
                                   0, -1,  1,  0};
                                   
    class Encoder {
        public:
            Encoder(byte encA, byte encB);
            
            // should be called to update encoder state 
            void tick();
            
            // return accumulated value and clears value
            int get_value();
                    
        protected:
            // encoder's pins
            int8_t pa, pb;
    
            // encoder value accumulator
            int value;
    
            uint8_t epos;
                            
            long enc_change_time;  
            
    };
    
}; // encdr

#endif // _ENCODER_H_
