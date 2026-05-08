#include "stm32f103xb.h"
#define B0 0
#define B1 1
#define B2 2
int leds[5]={1,2,3,4,5};
int puls[3]={B0,B1,B2};
int an1 [2][5]={
    {1,1,1,1,1},
    {0,0,0,0,0}
};

int an2 [2][5]={
    {0,1,0,1,0},
    {1,0,1,0,1}
};

int an3 [2][5]={
    {0,1,0,0,1},
    {1,0,1,1,0}
};

int main (void){
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN|RCC_APB2ENR_IOPBEN;
for(int i=0; i<5; i++){

GPIOA -> CRL &=~(0xF<<(i));
GPIOA -> CRL |=(0x1<<leds[i]);
if(i<3){
    GPIOB -> CRL&=~(0xF<<puls[i]);
    GPIOB -> CRL |= (0x8 << puls[i]);
    GPIOB -> BSRR |= (1 << (puls[i]+16));
}
}

while (1){
    if(GPIOB -> IDR&(1<<puls[0])){
        for(int f=0; f<2; f++){
            for(int c=0; c<5; c++){
                if(an1[f][c]) GPIOA -> BSRR|= (1<<leds[c]);
                else GPIOA -> BSRR|= (1<<(leds[c]+16));

            }
        }
    }
    
     if(GPIOB -> IDR&(1<<puls[1])){
        for(int f=0; f<2; f++){
            for(int c=0; c<5; c++){
                if(an2[f][c]) GPIOA -> BSRR|= (1<<leds[c]);
                else GPIOA -> BSRR|= (1<<(leds[c]+16));

            }
        }
    }
    
     if(GPIOB -> IDR&(1<<puls[2])){
        for(int f=0; f<2; f++){
            for(int c=0; c<5; c++){
                if(an3[f][c]) GPIOA -> BSRR|= (1<<leds[c]);
                else GPIOA -> BSRR|= (1<<(leds[c]+16));

            }
        }
    }
}}
    