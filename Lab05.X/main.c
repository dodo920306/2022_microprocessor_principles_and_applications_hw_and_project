//#include "xc.h"
//
//extern unsigned char isprime(unsigned int a);
//
//void main(void) {
//    volatile unsigned char res = isprime(57);
//    while(1);
//    return;
//}

//#include "xc.h"
//
//extern unsigned int divide_signed(unsigned char a, unsigned char b);
//
//void main(void) {
//    volatile unsigned int res = divide_signed(3, -4);
//    volatile char quotient = res / 16;
//    volatile char reminder = res % 16;
//    while(1);
//    return;
//}

#include "xc.h"

extern unsigned int mypow(unsigned int a, unsigned int b);

void main(void) {
    volatile unsigned int res = mypow(3, 0);
    while(1);
    return;
}