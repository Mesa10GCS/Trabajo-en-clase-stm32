#include "stm32f103xb.h"
#define B0 0
int num=0;
int leds[8]={0,1,2,3,4,5,6,7};
int an1 [10][8]={
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,0,0,1},
{0,1,1,0,1,1,0,1},
{0,1,1,1,1,0,0,1},
{0,0,1,1,0,0,1,1},
{0,1,0,1,1,0,1,1},
{0,1,0,1,1,1,1,1},
{0,1,1,1,0,0,0,0},
{0,1,1,1,1,1,1,1},
{0,1,1,1,0,0,1,1}
};


int main (void){

RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN|RCC_APB2ENR_IOPBEN;
for(int i=0; i<8; i++){
GPIOA -> CRL &=~(0xF<<(i));
GPIOA -> CRL |=(0x1<<leds[i]);
}
GPIOB -> CRL&=~(0xF<<B0);
GPIOB -> CRL |= (0x8 << B0);
GPIOB -> BSRR |= (1 << (B0+16));



while(1){
    
    if(GPIOB -> IDR & (1<<B0)){
        num++;
        if(num>9)num=0;
    }
    for(int i=0; i<7; i++){
        if(an1[num][i]) GPIOB -> BSRR |= (1<<leds[i]);
          else GPIOB -> BSRR |= (1<<(leds[i]+16));

    }
    
}
}
