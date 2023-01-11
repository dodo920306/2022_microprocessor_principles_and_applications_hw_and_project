#include "setting.h"
#include <stdlib.h>
#include "stdio.h"
#include "string.h"
// using namespace std;
#define _XTAL_FREQ 4000000

#define DATA_pin PORTEbits.RE0
#define LATCH_pin  PORTEbits.RE1
#define CLCOK_pin  PORTEbits.RE2

#define L1 PORTCbits.RC4
#define L2 PORTCbits.RC3
#define L3 PORTAbits.RA7
#define L4 PORTBbits.RB4
#define L5 PORTBbits.RB5
#define L6 PORTCbits.RC5
#define L7 PORTDbits.RD0
#define L8 PORTAbits.RA6
#define L9 PORTBbits.RB3
#define L10 PORTAbits.RA1
#define L11 PORTDbits.RD4
#define L12 PORTDbits.RD1
#define L13 PORTCbits.RC0
#define L14 PORTBbits.RB2
#define L15 PORTAbits.RA2
#define L16 PORTDbits.RD5
#define L17 PORTAbits.RA5
#define L18 PORTCbits.RC1
#define L19 PORTBbits.RB1
#define L20 PORTAbits.RA3
#define L21 PORTDbits.RD6
#define L22 PORTDbits.RD3
#define L23 PORTDbits.RD7
#define L24 PORTBbits.RB0
#define L25 PORTAbits.RA4

char str[20];
char state[20];
int lightstate = 0;
int e = 1;
int mode = 0;
int stage = 0;          //Cube motion stage
int ground_stage = 1;   //Cube motion ground stage
int motion = 5;         //Cube motion mode
int direction = 1;      //Cube motion direction



void clock_signal(void)
{
   CLCOK_pin = 1;
    __delay_us(500);
   CLCOK_pin = 0;
    __delay_us(500);
}
void latch_enable(void)
{
    LATCH_pin = 1;
    __delay_us(500);
    LATCH_pin = 0;
}

void send_data(unsigned int data_out)
{
    int i;
    for (i=0 ; i<8 ; i++)
    {
        DATA_pin = (data_out >> i) & (0x01);
        clock_signal();
    }
    latch_enable(); // Data finally submitted
}

void Mode1(){   // Todo : Mode1
    return ;
}
void Mode2(){   // Todo : Mode2 
    return ;
}

void clear_lights(){
    LATA = 0;
    LATB = 0;
    LATC = 0;
    LATD = 0;
    LATE = 0;
}
void cube_motion();
void A();
void B();
void C();
void D();
void E();
void F();
void G();
void H();
void I();
void J();
void K();
void L();
void M();
void N();
void O();
void P();
void Q();
void R();
void S();
void T();
void U();
void V();
void W();
void X();
void Y();
void Z();
void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void eight();
void nine();
void zero();

void main(void) 
{
    
    SYSTEM_Initialize() ;
    srand(15);
    TRISA = 0;
    TRISB = 0;
    TRISC = 0;
    TRISD = 0;
    TRISE = 0;
    clear_lights();
    //PORTAbits.RA4 = 1;
    //PORTDbits.RD7 = 1;
    //PORTBbits.RB0 = 1;
    //PORTDbits.RD6 = 1;
    //PORTDbits.RD3 = 1;
    
    //send_data(0b00000000);
    
    while(1) {
        if (stage == 0xFFFF)
            stage = 0;
        cube_motion();
    }
        
        
    return;
}

void __interrupt(high_priority) Hi_ISR(void)
{
    MyusartRead();
    strcpy(str, GetString()); // TODO : GetString() in uart.c
    strcat(state,GetString());
    UART_Write_Text(str);
    ClearBuffer();
    
    //Change light motion mode
    if (state[0] == 'm' && state[1] == '1' && state[2] == '\r'){
        stage = 0;
        motion = 1;
        strcpy(state, "");
    } else if (state[0] == 'm' && state[1] == '2' && state[2] == '\r'){
        
        stage = 0;
        motion = 2;
        strcpy(state, "");
        
    } else if (state[0] == 'm' && state[1] == '3' && state[2] == '\r'){
        
        stage = 0;
        motion = 3;
        strcpy(state, "");
        
    } else if (state[0] == 'm' && state[1] == '4' && state[2] == '\r'){
        stage = 0;
        motion = 4;
        strcpy(state, "");
        
    } else if (state[0] == 'm' && state[1] == '5' && state[2] == '\r'){
        stage = 0;
        motion = 5;
        strcpy(state, "");
    } else if (str[0] == '\r') {
        for (int i = 0; i < strlen(state); i++) {
            switch (state[i]) {
                case 'a':
                case 'A': {
                    A();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'b':
                case 'B': {
                    B();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'c':
                case 'C': {
                    C();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'd':
                case 'D': {
                    D();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'e':
                case 'E': {
                    E();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'f':
                case 'F': {
                    F();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'g':
                case 'G': {
                    G();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'h':
                case 'H': {
                    H();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'i':
                case 'I': {
                    I();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'j':
                case 'J': {
                    J();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'k':
                case 'K': {
                    K();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'l':
                case 'L': {
                    L();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'm':
                case 'M': {
                    M();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'n':
                case 'N': {
                    N();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'o':
                case 'O': {
                    O();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'p':
                case 'P': {
                    P();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'q':
                case 'Q': {
                    Q();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'r':
                case 'R': {
                    R();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 's':
                case 'S': {
                    S();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 't':
                case 'T': {
                    T();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'u':
                case 'U': {
                    U();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'v':
                case 'V': {
                    V();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'w':
                case 'W': {
                    W();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'x':
                case 'X': {
                    X();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'y':
                case 'Y': {
                    Y();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case 'z':
                case 'Z': {
                    Z();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case ' ': {
                    clear_lights();
                    __delay_ms(500);
                }
                case '0': {
                    zero();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case '1': {
                    one();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case '2': {
                    two();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case '3': {
                    three();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case '4': {
                    four();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case '5': {
                    five();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case '6': {
                    six();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case '7': {
                    seven();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case '8': {
                    eight();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
                case '9': {
                    nine();
                    clear_lights();
                    __delay_ms(100);
                    break;
                }
            }
        }
        strcpy(str, "");
        strcpy(state, "");
    }
}

void cube_motion(){
    switch (motion){
        case 1: {   //????
            send_data(0b00000000);
            switch (stage){
                case 0: 
                    clear_lights(); L1 = 1; L2 = 1; L3 = 1; L4 = 1; L5 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 1: 
                    clear_lights(); L6 = 1; L7 = 1; L8 = 1; L9 = 1; L10 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 2: 
                    clear_lights(); L11 = 1; L12 = 1; L13 = 1; L14 = 1; L15 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 3: 
                    clear_lights(); L16 = 1; L17 = 1; L18 = 1; L19 = 1; L20 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 4: 
                    clear_lights(); L21 = 1; L22 = 1; L23 = 1; L24 = 1; L25 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 5: 
                    clear_lights(); L1 = 1; L6 = 1; L11 = 1; L16 = 1; L21 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 6: 
                    clear_lights(); L2 = 1; L7 = 1; L12 = 1; L17 = 1; L22 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 7: 
                    clear_lights(); L3 = 1; L8 = 1; L13 = 1; L18 = 1; L23 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 8: 
                    clear_lights(); L4 = 1; L9 = 1; L14 = 1; L19 = 1; L24 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 9: 
                    clear_lights(); L5 = 1; L10 = 1; L15 = 1; L20 = 1; L25 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 10: 
                    clear_lights(); L21 = 1; L22 = 1; L23 = 1; L24 = 1; L25 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 11: 
                    clear_lights(); L16 = 1; L17 = 1; L18 = 1; L19 = 1; L20 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 12: 
                    clear_lights(); L11 = 1; L12 = 1; L13 = 1; L14 = 1; L15 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 13: 
                    clear_lights(); L6 = 1; L7 = 1; L8 = 1; L9 = 1; L10 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 14: 
                    clear_lights(); L1 = 1; L2 = 1; L3 = 1; L4 = 1; L5 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 15: 
                    clear_lights(); L5 = 1; L10 = 1; L15 = 1; L20 = 1; L25 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 16: 
                    clear_lights(); L4 = 1; L9 = 1; L14 = 1; L19 = 1; L24 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 17: 
                    clear_lights(); L3 = 1; L8 = 1; L13 = 1; L18 = 1; L23 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 18: 
                    clear_lights(); L2 = 1; L7 = 1; L12 = 1; L17 = 1; L22 = 1;
                    __delay_ms(100);
                    stage++;
                    break;
                case 19: 
                    clear_lights(); L1 = 1; L6 = 1; L11 = 1; L16 = 1; L21 = 1;
                    __delay_ms(100);
                    stage=0;
                    break;
            }
            break;
        }
        case 2: {
            switch (stage) {
                case 0: 
                    send_data(0b00011011);
                    clear_lights(); L13 = 1;
                    direction = 1;
                    stage += direction;
                    __delay_ms(100);
                    break;
                case 1:
                    ground_stage = 2;
                    for (int i = 0; i < 20; i++){
                        switch (ground_stage){
                            case 2: 
                                 send_data(0b00010101);
                                 clear_lights(); L7 = 1; L8 = 1; L9 = 1; L12 = 1; L14 = 1; L17 = 1; L18 = 1; L19 = 1;
                                 ground_stage++;
                                 __delay_us(25);
                                 break;
                            case 3: 
                                 send_data(0b00011011);
                                 clear_lights(); L7 = 1; L9 = 1; L17 = 1; L19 = 1;
                                 ground_stage=2;
                                 __delay_us(13);
                                 break;
                        }
                    }
                    stage += direction;
                    break;
                case 2:
                    ground_stage = 1;
                    for (int i = 0; i < 20; i++){
                        switch (ground_stage){
                            case 1:
                                send_data(0b00001110);
                                clear_lights(); L1 = 1; L2 = 1; L3 = 1; L4 = 1; L5 = 1; L6 = 1; L10 = 1; L11 = 1; L15 = 1; L16 = 1; L20 = 1; L21 = 1; L22 = 1; L23 = 1; L24 = 1; L25 = 1;
                                ground_stage++;
                                __delay_us(25);
                                break;
                            case 2:
                                send_data(0b00010001);
                                clear_lights(); L1 = 1; L5 = 1; L21 = 1; L25 = 1;
                                ground_stage=1;
                                __delay_us(37);
                                break;
                        }
                    }
                    direction = -1;
                    stage += direction;
                    break;
            }
            break;
        }
        case 3: {
            switch (stage) {
                case 0: {
                    direction = 1;
                    for (int i = 0; i < 8; i++){
                        send_data(0b00000000);
                        clear_lights(); L6 = 1; L16 = 1;
                        
                        send_data(0b00001110);
                        clear_lights(); L11 = 1;
                    }
                    for (int i = 0; i < 8; i++){
                        send_data(0b00000000);
                        clear_lights(); L7 = 1; L17 = 1;
                        
                        send_data(0b00001110);
                        clear_lights(); L12 = 1;
                    }
                    for (int i = 0; i < 8; i++){
                        send_data(0b00000000);
                        clear_lights(); L8 = 1; L18 = 1;
                        
                        send_data(0b00001110);
                        clear_lights(); L13 = 1;
                    }
                    for (int i = 0; i < 8; i++){
                        send_data(0b00000000);
                        clear_lights(); L9 = 1; L19 = 1;
                        
                        send_data(0b00001110);
                        clear_lights(); L14 = 1;
                    }
                    for (int i = 0; i < 8; i++){
                        send_data(0b00000000);
                        clear_lights(); L10 = 1; L20 = 1;
                        
                        send_data(0b00001110);
                        clear_lights(); L15 = 1;
                    }
                    stage += direction;
                    break;
                }
                case 1: {
                    for (int i = 0; i < 5; i++){
                        send_data(0b00000000);
                        clear_lights(); L11 = 1;
                        
                        send_data(0b00010110);
                        clear_lights(); L16 = 1;
                        
                        send_data(0b00011110);
                        clear_lights(); L6 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00000000);
                        clear_lights(); L12 = 1;
                        
                        send_data(0b00010110);
                        clear_lights(); L17 = 1;
                        
                        send_data(0b00011110);
                        clear_lights(); L7 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00000000);
                        clear_lights(); L13 = 1;
                        
                        send_data(0b00010110);
                        clear_lights(); L18 = 1;
                        
                        send_data(0b00011110);
                        clear_lights(); L8 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00000000);
                        clear_lights(); L14 = 1;
                        
                        send_data(0b00010110);
                        clear_lights(); L19 = 1;
                        
                        send_data(0b00011110);
                        clear_lights(); L9 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00000000);
                        clear_lights(); L15 = 1;
                        
                        send_data(0b00010110);
                        clear_lights(); L20 = 1;
                        
                        send_data(0b00011110);
                        clear_lights(); L10 = 1;
                    }
                    stage += direction;
                    break;
                }
                case 2: {
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001010);
                        clear_lights(); L11 = 1;
                        
                        send_data(0b00001000);
                        clear_lights(); L16 = 1;
                        
                        send_data(0b00000010);
                        clear_lights(); L6 = 1; 
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001010);
                        clear_lights(); L12 = 1;
                        
                        send_data(0b00001000);
                        clear_lights(); L17 = 1;
                        
                        send_data(0b00000010);
                        clear_lights(); L7 = 1; 
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001010);
                        clear_lights(); L13 = 1;
                        
                        send_data(0b00001000);
                        clear_lights(); L18 = 1;
                        
                        send_data(0b00000010);
                        clear_lights(); L8 = 1; 
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001010);
                        clear_lights(); L14 = 1;
                        
                        send_data(0b00001000);
                        clear_lights(); L19 = 1;
                        
                        send_data(0b00000010);
                        clear_lights(); L9 = 1; 
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001010);
                        clear_lights(); L15 = 1;
                        
                        send_data(0b00001000);
                        clear_lights(); L20 = 1;
                        
                        send_data(0b00000010);
                        clear_lights(); L10 = 1; 
                    }
                    stage += direction;
                    break;
                }
                case 3: {
                    for (int i = 0; i <8; i++){
                        send_data(0b00001010);
                        clear_lights(); L11 = 1; L16 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L6 = 1;
                    }
                    for (int i = 0; i <8; i++){
                        send_data(0b00001010);
                        clear_lights(); L12 = 1; L17 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L7 = 1;
                    }
                    for (int i = 0; i <8; i++){
                        send_data(0b00001010);
                        clear_lights(); L13 = 1; L18 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L8 = 1;
                    }
                    for (int i = 0; i <8; i++){
                        send_data(0b00001010);
                        clear_lights(); L14 = 1; L19 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L9 = 1;
                    }
                    for (int i = 0; i <8; i++){
                        send_data(0b00001010);
                        clear_lights(); L15 = 1; L20 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L10 = 1;
                    }
                    stage += direction;
                    break;
                }
                case 4: {
                    for (int i = 0; i < 5; i++){
                        send_data(0b00000011);
                        clear_lights(); L16 = 1;
                       
                        send_data(0b00011011);
                        clear_lights(); L11 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L6 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00000011);
                        clear_lights(); L17 = 1;
                       
                        send_data(0b00011011);
                        clear_lights(); L12 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L7 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00000011);
                        clear_lights(); L18 = 1;
                       
                        send_data(0b00011011);
                        clear_lights(); L13 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L8 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00000011);
                        clear_lights(); L19 = 1;
                       
                        send_data(0b00011011);
                        clear_lights(); L14 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L9 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00000011);
                        clear_lights(); L20 = 1;
                       
                        send_data(0b00011011);
                        clear_lights(); L15 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L10 = 1;
                    }
                    stage += direction;
                    break;
                }
                case 5: {
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001010);
                        clear_lights(); L11 = 1;
                        
                        send_data(0b00001000);
                        clear_lights(); L6 = 1;
                        
                        send_data(0b00000010);
                        clear_lights(); L16 = 1;
                        
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001010);
                        clear_lights(); L12 = 1;
                        
                        send_data(0b00001000);
                        clear_lights(); L7 = 1;
                        
                        send_data(0b00000010);
                        clear_lights(); L17 = 1;
                        
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001010);
                        clear_lights(); L13 = 1;
                        
                        send_data(0b00001000);
                        clear_lights(); L8 = 1;
                        
                        send_data(0b00000010);
                        clear_lights(); L18 = 1;
                        
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001010);
                        clear_lights(); L14 = 1;
                        
                        send_data(0b00001000);
                        clear_lights(); L9 = 1;
                        
                        send_data(0b00000010);
                        clear_lights(); L19 = 1;
                        
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001010);
                        clear_lights(); L15 = 1;
                        
                        send_data(0b00001000);
                        clear_lights(); L10 = 1;
                        
                        send_data(0b00000010);
                        clear_lights(); L20 = 1;
                        
                    }
                    stage += direction;
                    break;
                }
                case 6: {
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001000);
                        clear_lights(); L6 = 1;
                        
                        send_data(0b00001010);
                        clear_lights(); L11 = 1;
                        
                        send_data(0b00010000);
                        clear_lights(); L16 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001000);
                        clear_lights(); L7 = 1;
                        
                        send_data(0b00001010);
                        clear_lights(); L12 = 1;
                        
                        send_data(0b00010000);
                        clear_lights(); L17 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001000);
                        clear_lights(); L8 = 1;
                        
                        send_data(0b00001010);
                        clear_lights(); L13 = 1;
                        
                        send_data(0b00010000);
                        clear_lights(); L18 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001000);
                        clear_lights(); L9 = 1;
                        
                        send_data(0b00001010);
                        clear_lights(); L14 = 1;
                        
                        send_data(0b00010000);
                        clear_lights(); L19 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001000);
                        clear_lights(); L10 = 1;
                        
                        send_data(0b00001010);
                        clear_lights(); L15 = 1;
                        
                        send_data(0b00010000);
                        clear_lights(); L20 = 1;
                    }
                    stage += direction;
                    break;
                }
                case 7: {
                    for (int i = 0; i < 8; i++){
                        send_data(0b00000000);
                        clear_lights(); L6 = 1;
                        
                        send_data(0b00001111);
                        clear_lights(); L11 = 1; L16 = 1;
                        
                    }
                    for (int i = 0; i < 8; i++){
                        send_data(0b00000000);
                        clear_lights(); L7 = 1;
                        
                        send_data(0b00001111);
                        clear_lights(); L12 = 1; L17 = 1;
                        
                    }
                    for (int i = 0; i < 8; i++){
                        send_data(0b00000000);
                        clear_lights(); L8 = 1;
                        
                        send_data(0b00001111);
                        clear_lights(); L13 = 1; L18 = 1;
                        
                    }
                    for (int i = 0; i < 8; i++){
                        send_data(0b00000000);
                        clear_lights(); L9 = 1;
                        
                        send_data(0b00001111);
                        clear_lights(); L14 = 1; L19 = 1;
                        
                    }
                    for (int i = 0; i < 8; i++){
                        send_data(0b00000000);
                        clear_lights(); L10 = 1;
                        
                        send_data(0b00001111);
                        clear_lights(); L15 = 1; L20 = 1;
                        
                    }
                    stage += direction;
                    break;
                }
                case 8: {
                    for (int i = 0; i < 8; i++){
                        send_data(0b00001010);
                        clear_lights(); L11 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L6 = 1; L16 = 1;
                    }
                    for (int i = 0; i < 8; i++){
                        send_data(0b00001010);
                        clear_lights(); L12 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L7 = 1; L17 = 1;
                    }
                    for (int i = 0; i < 8; i++){
                        send_data(0b00001010);
                        clear_lights(); L13 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L8 = 1; L18 = 1;
                    }
                    for (int i = 0; i < 8; i++){
                        send_data(0b00001010);
                        clear_lights(); L14 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L9 = 1; L19 = 1;
                    }
                    for (int i = 0; i < 8; i++){
                        send_data(0b00001010);
                        clear_lights(); L15 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L10 = 1; L20 = 1;
                    }
                    stage += direction;
                    break;
                }
                case 9: {
                    direction = -1;
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001011);
                        clear_lights(); L11 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L6 = 1;
                        
                        send_data(0b00000011);
                        clear_lights(); L16 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001011);
                        clear_lights(); L12 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L7 = 1;
                        
                        send_data(0b00000011);
                        clear_lights(); L17 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001011);
                        clear_lights(); L13 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L8 = 1;
                        
                        send_data(0b00000011);
                        clear_lights(); L18 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001011);
                        clear_lights(); L14 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L9 = 1;
                        
                        send_data(0b00000011);
                        clear_lights(); L19 = 1;
                    }
                    for (int i = 0; i < 5; i++){
                        send_data(0b00001011);
                        clear_lights(); L15 = 1;
                        
                        send_data(0b00000000);
                        clear_lights(); L10 = 1;
                        
                        send_data(0b00000011);
                        clear_lights(); L20 = 1;
                    }
                    stage += direction;
                    break;
                }
            }
            break;
        }
        case 4: {
            direction = 1;
            for (int k = 0; k < 2; k++){
                clear_lights();
                __delay_ms(2);
                for (int j = 0; j < 2; j++){
                    int random = (rand() % 25) + 1;
                    switch (random){ //????
                        case 1: L1 = 1; break;
                        case 2: L2 = 1; break;
                        case 3: L3 = 1; break;
                        case 4: L4 = 1; break;
                        case 5: L5 = 1; break;
                        case 6: L6 = 1; break;
                        case 7: L7 = 1; break;
                        case 8: L8 = 1; break;
                        case 9: L9 = 1; break;
                        case 10: L10 = 1; break;
                        case 11: L11 = 1; break;
                        case 12: L12 = 1; break;
                        case 13: L13 = 1; break;
                        case 14: L14 = 1; break;
                        case 15: L15 = 1; break;
                        case 16: L16 = 1; break;
                        case 17: L17 = 1; break;
                        case 18: L18 = 1; break;
                        case 19: L19 = 1; break;
                        case 20: L20 = 1; break;
                        case 21: L21 = 1; break;
                        case 22: L22 = 1; break;
                        case 23: L23 = 1; break;
                        case 24: L24 = 1; break;
                        case 25: L25 = 1; break;
                    }
                }
                if (direction == 1){
                    send_data(0b00001111); __delay_ms(50);
                    send_data(0b00010111); __delay_ms(50);
                    send_data(0b00011011); __delay_ms(50);
                    send_data(0b00011101); __delay_ms(50);
                    send_data(0b00011110); __delay_ms(50);
                    direction = -1;
                }
                else{
                    send_data(0b00011110); __delay_ms(50);
                    send_data(0b00011101); __delay_ms(50);
                    send_data(0b00011011); __delay_ms(50);
                    send_data(0b00010111); __delay_ms(50);
                    send_data(0b00001111); __delay_ms(50);
                    direction = 1;
                }
            }
            break;
        }
        case 5: {
            if (ground_stage == 0) direction = 1;
            else if (ground_stage == 20) direction = -1;
            switch (stage){
                case 0: 
                    clear_lights(); 
                    send_data(0b00011011);
                    L1 = 1; L2 = 1; L3 = 1; L4 = 1; L5 = 1; L6 = 1; L7 = 1; L8 = 1; L9 = 1; L10 = 1; L11 = 1; L12 = 1; L13 = 1; L14 = 1; L15 = 1; L16 = 1; L17 = 1; L18 = 1; L19 = 1; L20 = 1; L21 = 1; L22 = 1; L23 = 1; L24 = 1; L25 = 1; 
                    __delay_ms(60);
                    if (direction == 1) stage++;
                    else stage = 3;
                    break;
                case 1:
                    for (int i = 0; i < 3; i++){
                        send_data(0b00001111); clear_lights(); 
                        L21 = 1; L22 = 1; L23 = 1; L24 = 1; L25 = 1;
                        send_data(0b00010111); clear_lights(); 
                        L16 = 1; L7 = 1; L8 = 1; L9 = 1; L20 = 1;
                        send_data(0b00011011); clear_lights(); 
                        L11 = 1; L12 = 1; L13 = 1; L14 = 1; L15 = 1;
                        send_data(0b00011101); clear_lights(); 
                        L6 = 1; L17 = 1; L18 = 1; L19 = 1; L10 = 1;
                        send_data(0b00011110); clear_lights(); 
                        L1 = 1; L2 = 1; L3 = 1; L4 = 1; L5 = 1;
                    }
                    stage+=direction; break;
                case 2:
                    clear_lights(); send_data(0b00000000);
                    L11 = 1; L12 = 1; L13 = 1; L14 = 1; L15 = 1;
                    __delay_ms(60);
                    stage+=direction; break;
                case 3:
                    for (int i = 0; i < 3; i++){
                        send_data(0b00011110); clear_lights(); 
                        L21 = 1; L22 = 1; L23 = 1; L24 = 1; L25 = 1;
                        send_data(0b00011101); clear_lights(); 
                        L16 = 1; L7 = 1; L18 = 1; L9 = 1; L20 = 1;
                        send_data(0b00011011); clear_lights(); 
                        L11 = 1; L12 = 1; L13 = 1; L14 = 1; L15 = 1;
                        send_data(0b00010111); clear_lights(); 
                        L6 = 1; L17 = 1; L18 = 1; L19 = 1; L10 = 1;
                        send_data(0b00001111); clear_lights(); 
                        L1 = 1; L2 = 1; L3 = 1; L4 = 1; L5 = 1;
                    }
                    if (direction == 1) stage=0; 
                    else stage--; 
                    break;
            }
            ground_stage += direction;
        }
    }
}

void A() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00001011);
        clear_lights();
        L11 = 1;

        send_data(0b00000000);
        clear_lights();
        L6 = 1; L16 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001011);
        clear_lights();
        L12 = 1;

        send_data(0b00000000);
        clear_lights();
        L7 = 1; L17 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001011);
        clear_lights();
        L13 = 1;

        send_data(0b00000000);
        clear_lights();
        L8 = 1; L18 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001011);
        clear_lights();
        L14 = 1;

        send_data(0b00000000);
        clear_lights();
        L9 = 1; L19 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001011);
        clear_lights();
        L15 = 1;

        send_data(0b00000000);
        clear_lights();
        L10 = 1; L20 = 1;
    }
}

void B() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00010101);
        clear_lights();
        L6 = 1; L16 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L11 = 1; L16 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010101);
        clear_lights();
        L7 = 1; L17 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L12 = 1; L17 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010101);
        clear_lights();
        L8 = 1; L18 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L13 = 1; L18 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010101);
        clear_lights();
        L9 = 1; L19 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L14 = 1; L19 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010101);
        clear_lights();
        L10 = 1; L20 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L15 = 1; L20 = 1;
    }
}

void C() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00001110);
        clear_lights();
        L6 = 1; L11 = 1;

        send_data(0b00000000);
        clear_lights();
        L16 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001110);
        clear_lights();
        L7 = 1; L12 = 1;

        send_data(0b00000000);
        clear_lights();
        L17 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001110);
        clear_lights();
        L8 = 1; L13 = 1;

        send_data(0b00000000);
        clear_lights();
        L18 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001110);
        clear_lights();
        L9 = 1; L14 = 1;

        send_data(0b00000000);
        clear_lights();
        L19 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001110);
        clear_lights();
        L10 = 1; L15 = 1;

        send_data(0b00000000);
        clear_lights();
        L20 = 1;
    }
}

void D() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00010001);
        clear_lights();
        L6 = 1; L16 = 1;
        
        send_data(0b00001110);
        clear_lights();
        L11 = 1; L16 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010001);
        clear_lights();
        L7 = 1; L17 = 1;
        
        send_data(0b00001110);
        clear_lights();
        L12 = 1; L17 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010001);
        clear_lights();
        L8 = 1; L18 = 1;
        
        send_data(0b00001110);
        clear_lights();
        L13 = 1; L18 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010001);
        clear_lights();
        L9 = 1; L19 = 1;
        
        send_data(0b00001110);
        clear_lights();
        L14 = 1; L19 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010001);
        clear_lights();
        L10 = 1; L20 = 1;
        
        send_data(0b00001110);
        clear_lights();
        L15 = 1; L20 = 1;
    }
}

void E() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L16 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L11 = 1; L6 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L17 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L12 = 1; L7 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L18 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L13 = 1; L8 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L19 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L14 = 1; L9 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L20 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L15 = 1; L10 = 1;
    }
}

void F() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L16 = 1;
        
        send_data(0b00001011);
        clear_lights();
        L11 = 1; L6 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L17 = 1;
        
        send_data(0b00001011);
        clear_lights();
        L12 = 1; L7 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L18 = 1;
        
        send_data(0b00001011);
        clear_lights();
        L13 = 1; L8 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L19 = 1;
        
        send_data(0b00001011);
        clear_lights();
        L14 = 1; L9 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L20 = 1;
        
        send_data(0b00001011);
        clear_lights();
        L15 = 1; L10 = 1;
    }
}

void G() {
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L16 = 1;
        
        send_data(0b00001110);
        clear_lights();
        L11 = 1;
        
        send_data(0b00001000);
        clear_lights();
        L6 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L17 = 1;
        
        send_data(0b00001110);
        clear_lights();
        L12 = 1;
        
        send_data(0b00001000);
        clear_lights();
        L7 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L18 = 1;
        
        send_data(0b00001110);
        clear_lights();
        L13 = 1;
        
        send_data(0b00001000);
        clear_lights();
        L8 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L19 = 1;
        
        send_data(0b00001110);
        clear_lights();
        L14 = 1;
        
        send_data(0b00001000);
        clear_lights();
        L9 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L20 = 1;
        
        send_data(0b00001110);
        clear_lights();
        L15 = 1;
        
        send_data(0b00001000);
        clear_lights();
        L10 = 1;
    }
}

void H() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L6 = 1; L16 = 1;
        
        send_data(0b00011011);
        clear_lights();
        L11 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L7 = 1; L17 = 1;
        
        send_data(0b00011011);
        clear_lights();
        L12 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L8 = 1; L18 = 1;
        
        send_data(0b00011011);
        clear_lights();
        L13 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L9 = 1; L19 = 1;
        
        send_data(0b00011011);
        clear_lights();
        L14 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L10 = 1; L20 = 1;
        
        send_data(0b00011011);
        clear_lights();
        L15 = 1;
    }
}

void I() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L11 = 1;

        
        send_data(0b00001110);
        clear_lights();
        L6 = 1; L16 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L12 = 1;

        
        send_data(0b00001110);
        clear_lights();
        L7 = 1; L17 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L13 = 1;

        
        send_data(0b00001110);
        clear_lights();
        L8 = 1; L18 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L14 = 1;

        
        send_data(0b00001110);
        clear_lights();
        L9 = 1; L19 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L15 = 1;

        
        send_data(0b00001110);
        clear_lights();
        L10 = 1; L20 = 1;
    }
}

void J() {
    for (int i = 0; i < 5; i++) {
        send_data(0b00001111);
        clear_lights();
        L6 = 1;
        
        send_data(0b00000000);
        clear_lights();
        L11 = 1;

        send_data(0b00001110);
        clear_lights();
        L16 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001111);
        clear_lights();
        L7 = 1;
        
        send_data(0b00000000);
        clear_lights();
        L12 = 1;
        
        send_data(0b00001110);
        clear_lights();
        L17 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001111);
        clear_lights();
        L8 = 1;
        
        send_data(0b00000000);
        clear_lights();
        L13 = 1;

        
        send_data(0b00001110);
        clear_lights();
        L18 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001111);
        clear_lights();
        L9 = 1;
        
        send_data(0b00000000);
        clear_lights();
        L14 = 1;

        send_data(0b00001110);
        clear_lights();
        L19 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001111);
        clear_lights();
        L10 = 1;
        
        send_data(0b00000000);
        clear_lights();
        L15 = 1;

        send_data(0b00001110);
        clear_lights();
        L20 = 1;
    }
}

void K() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00000100);
        clear_lights();
        L6 = 1; L16 = 1;

        
        send_data(0b00011011);
        clear_lights();
        L16 = 1; L11 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000100);
        clear_lights();
        L7 = 1; L17 = 1;

        
        send_data(0b00011011);
        clear_lights();
        L17 = 1; L12 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000100);
        clear_lights();
        L8 = 1; L18 = 1;

        
        send_data(0b00011011);
        clear_lights();
        L18 = 1; L13 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000100);
        clear_lights();
        L9 = 1; L19 = 1;
        
        send_data(0b00011011);
        clear_lights();
        L19 = 1; L14 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000100);
        clear_lights();
        L10 = 1; L20 = 1;

        send_data(0b00011011);
        clear_lights();
        L20 = 1; L15 = 1;
    }
}

void L() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L16 = 1;

        
        send_data(0b00011110);
        clear_lights();
        L6 = 1; L11 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L17 = 1;

        
        send_data(0b00011110);
        clear_lights();
        L7 = 1; L12 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L18 = 1;

        
        send_data(0b00011110);
        clear_lights();
        L8 = 1; L13 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L19 = 1;

        
        send_data(0b00011110);
        clear_lights();
        L9 = 1; L14 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L20 = 1;

        
        send_data(0b00011110);
        clear_lights();
        L10 = 1; L15 = 1;
    }
}

void M() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L6 = 1; L16 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L11 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L7 = 1; L17 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L12 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L8 = 1; L18 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L13 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L9 = 1; L19 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L14 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L10 = 1; L20 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L15 = 1;
    }
}

void N() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00010000);
        clear_lights();
        L6 = 1; L16 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L11 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010000);
        clear_lights();
        L7 = 1; L17 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L12 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010000);
        clear_lights();
        L8 = 1; L18 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L13 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010000);
        clear_lights();
        L9 = 1; L19 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L14 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010000);
        clear_lights();
        L10 = 1; L20 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L15 = 1;
    }
}

void O() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00010001);
        clear_lights();
        L6 = 1; L16 = 1;

        
        send_data(0b00001110);
        clear_lights();
        L11 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010001);
        clear_lights();
        L7 = 1; L17 = 1;

        
        send_data(0b00001110);
        clear_lights();
        L12 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010001);
        clear_lights();
        L8 = 1; L18 = 1;

        
        send_data(0b00001110);
        clear_lights();
        L13 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010001);
        clear_lights();
        L9 = 1; L19 = 1;

        
        send_data(0b00001110);
        clear_lights();
        L14 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010001);
        clear_lights();
        L10 = 1; L20 = 1;

        
        send_data(0b00001110);
        clear_lights();
        L15 = 1;
    }
}

void P() {
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L16 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L6 = 1;
        
        send_data(0b00001011);
        clear_lights();
        L11 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L17 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L7 = 1;
        
        send_data(0b00001011);
        clear_lights();
        L12 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L18 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L8 = 1;
        
        send_data(0b00001011);
        clear_lights();
        L13 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L19 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L9 = 1;
        
        send_data(0b00001011);
        clear_lights();
        L14 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L20 = 1;

        
        send_data(0b00010111);
        clear_lights();
        L10 = 1;
        
        send_data(0b00001011);
        clear_lights();
        L15 = 1;
    }
}

void Q() {
    for (int i = 0; i < 5; i++) {
        send_data(0b00000011);
        clear_lights();
        L16 = 1;

        send_data(0b00000010);
        clear_lights();
        L6 = 1;
        
        send_data(0b00001101);
        clear_lights();
        L11 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000011);
        clear_lights();
        L17 = 1;

        send_data(0b00000010);
        clear_lights();
        L7 = 1;
        
        send_data(0b00001101);
        clear_lights();
        L12 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000011);
        clear_lights();
        L18 = 1;

        send_data(0b00000010);
        clear_lights();
        L8 = 1;
        
        send_data(0b00001101);
        clear_lights();
        L13 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000011);
        clear_lights();
        L19 = 1;

        send_data(0b00000010);
        clear_lights();
        L9 = 1;
        
        send_data(0b00001101);
        clear_lights();
        L14 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000011);
        clear_lights();
        L20 = 1;

        send_data(0b00000010);
        clear_lights();
        L10 = 1;
        
        send_data(0b00001101);
        clear_lights();
        L15 = 1;
    }
}

void R() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00010100);
        clear_lights();
        L6 = 1; L16 = 1;

        
        send_data(0b00001011);
        clear_lights();
        L16 = 1; L11 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010100);
        clear_lights();
        L7 = 1; L17 = 1;

        
        send_data(0b00001011);
        clear_lights();
        L17 = 1; L12 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010100);
        clear_lights();
        L8 = 1; L18 = 1;

        
        send_data(0b00001011);
        clear_lights();
        L18 = 1; L13 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010100);
        clear_lights();
        L9 = 1; L19 = 1;

        
        send_data(0b00001011);
        clear_lights();
        L19 = 1; L14 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00010100);
        clear_lights();
        L10 = 1; L20 = 1;

        
        send_data(0b00001011);
        clear_lights();
        L20 = 1; L15 = 1;
    }
}

void S() {
    for (int i = 0; i < 5; i++) {
        send_data(0b00001101);
        clear_lights();
        L6 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L11 = 1;
        
        send_data(0b00010110);
        clear_lights();
        L16 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001101);
        clear_lights();
        L7 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L12 = 1;
        
        send_data(0b00010110);
        clear_lights();
        L17 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001101);
        clear_lights();
        L8 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L13 = 1;
        
        send_data(0b00010110);
        clear_lights();
        L18 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001101);
        clear_lights();
        L9 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L14 = 1;
        
        send_data(0b00010110);
        clear_lights();
        L19 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001101);
        clear_lights();
        L10 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L15 = 1;
        
        send_data(0b00010110);
        clear_lights();
        L20 = 1;
    }
}

void T() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L11 = 1;
        
        send_data(0b00001111);
        clear_lights();
        L6 = 1; L16 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L12 = 1;
        
        send_data(0b00001111);
        clear_lights();
        L7 = 1; L17 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L13 = 1;
        
        send_data(0b00001111);
        clear_lights();
        L8 = 1; L18 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L14 = 1;
        
        send_data(0b00001111);
        clear_lights();
        L9 = 1; L19 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L15 = 1;
        
        send_data(0b00001111);
        clear_lights();
        L10 = 1; L20 = 1;
    }
}

void U() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L6 = 1; L16 = 1;
        
        send_data(0b00011110);
        clear_lights();
        L11 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L7 = 1; L17 = 1;
        
        send_data(0b00011110);
        clear_lights();
        L12 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L8 = 1; L18 = 1;
        
        send_data(0b00011110);
        clear_lights();
        L13 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L9 = 1; L19 = 1;
        
        send_data(0b00011110);
        clear_lights();
        L14 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L10 = 1; L20 = 1;
        
        send_data(0b00011110);
        clear_lights();
        L15 = 1;
    }
}

void V() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00000001);
        clear_lights();
        L6 = 1; L16 = 1;
        
        send_data(0b00011110);
        clear_lights();
        L11 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000001);
        clear_lights();
        L7 = 1; L17 = 1;
        
        send_data(0b00011110);
        clear_lights();
        L12 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000001);
        clear_lights();
        L8 = 1; L18 = 1;
        
        send_data(0b00011110);
        clear_lights();
        L13 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000001);
        clear_lights();
        L9 = 1; L19 = 1;
        
        send_data(0b00011110);
        clear_lights();
        L14 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000001);
        clear_lights();
        L10 = 1; L20 = 1;
        
        send_data(0b00011110);
        clear_lights();
        L15 = 1;
    }
}

void W() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L6 = 1; L16 = 1;
        
        send_data(0b00011101);
        clear_lights();
        L11 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L7 = 1; L17 = 1;
        
        send_data(0b00011101);
        clear_lights();
        L12 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L8 = 1; L18 = 1;
        
        send_data(0b00011101);
        clear_lights();
        L13 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L9 = 1; L19 = 1;
        
        send_data(0b00011101);
        clear_lights();
        L14 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L10 = 1; L20 = 1;
        
        send_data(0b00011101);
        clear_lights();
        L15 = 1;
    }
}

void X() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00000100);
        clear_lights();
        L6 = 1; L16 = 1;
        
        send_data(0b00011011);
        clear_lights();
        L11 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000100);
        clear_lights();
        L7 = 1; L17 = 1;
        
        send_data(0b00011011);
        clear_lights();
        L12 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000100);
        clear_lights();
        L8 = 1; L18 = 1;
        
        send_data(0b00011011);
        clear_lights();
        L13 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000100);
        clear_lights();
        L9 = 1; L19 = 1;
        
        send_data(0b00011011);
        clear_lights();
        L14 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000100);
        clear_lights();
        L10 = 1; L20 = 1;
        
        send_data(0b00011011);
        clear_lights();
        L15 = 1;
    }
}

void Y() {
    for (int i = 0; i < 10; i++) {
        send_data(0b00000011);
        clear_lights();
        L6 = 1; L16 = 1;
        
        send_data(0b00011000);
        clear_lights();
        L11 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000011);
        clear_lights();
        L7 = 1; L17 = 1;
        
        send_data(0b00011000);
        clear_lights();
        L12 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000011);
        clear_lights();
        L8 = 1; L18 = 1;
        
        send_data(0b00011000);
        clear_lights();
        L13 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000011);
        clear_lights();
        L9 = 1; L19 = 1;
        
        send_data(0b00011000);
        clear_lights();
        L14 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000011);
        clear_lights();
        L10 = 1; L20 = 1;
        
        send_data(0b00011000);
        clear_lights();
        L15 = 1;
    }
}

void Z() {
    for (int i = 0; i < 5; i++) {
        send_data(0b00000110);
        clear_lights();
        L6 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L11 = 1;
        
        send_data(0b00001100);
        clear_lights();
        L16 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000110);
        clear_lights();
        L7 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L12 = 1;
        
        send_data(0b00001100);
        clear_lights();
        L17 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000110);
        clear_lights();
        L8 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L13 = 1;
        
        send_data(0b00001100);
        clear_lights();
        L18 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000110);
        clear_lights();
        L9 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L14 = 1;
        
        send_data(0b00001100);
        clear_lights();
        L19 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000110);
        clear_lights();
        L10 = 1;
        
        send_data(0b00001010);
        clear_lights();
        L15 = 1;
        
        send_data(0b00001100);
        clear_lights();
        L20 = 1;
    }
}

void zero()
{
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L6 = 1;
        L16 = 1;

        send_data(0b00001110);
        clear_lights();
        L11 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L7 = 1;
        L17 = 1;

        send_data(0b00001110);
        clear_lights();
        L12 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L8 = 1;
        L18 = 1;

        send_data(0b00001110);
        clear_lights();
        L13 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L9 = 1;
        L19 = 1;

        send_data(0b00001110);
        clear_lights();
        L14 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L10 = 1;
        L20 = 1;

        send_data(0b00001110);
        clear_lights();
        L15 = 1;
    }
}

void one()
{
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L11 = 1;

        send_data(0b00010110);
        clear_lights();
        L16 = 1;

        send_data(0b00011110);
        clear_lights();
        L6 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L12 = 1;

        send_data(0b00010110);
        clear_lights();
        L17 = 1;

        send_data(0b00011110);
        clear_lights();
        L7 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L13 = 1;

        send_data(0b00010110);
        clear_lights();
        L18 = 1;

        send_data(0b00011110);
        clear_lights();
        L8 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L14 = 1;

        send_data(0b00010110);
        clear_lights();
        L19 = 1;

        send_data(0b00011110);
        clear_lights();
        L9 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000000);
        clear_lights();
        L15 = 1;

        send_data(0b00010110);
        clear_lights();
        L20 = 1;

        send_data(0b00011110);
        clear_lights();
        L10 = 1;
    }
}

void two()
{
    for (int i = 0; i < 5; i++) {
        send_data(0b00001010);
        clear_lights();
        L11 = 1;

        send_data(0b00001000);
        clear_lights();
        L16 = 1;

        send_data(0b00000010);
        clear_lights();
        L6 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001010);
        clear_lights();
        L12 = 1;

        send_data(0b00001000);
        clear_lights();
        L17 = 1;

        send_data(0b00000010);
        clear_lights();
        L7 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001010);
        clear_lights();
        L13 = 1;

        send_data(0b00001000);
        clear_lights();
        L18 = 1;

        send_data(0b00000010);
        clear_lights();
        L8 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001010);
        clear_lights();
        L14 = 1;

        send_data(0b00001000);
        clear_lights();
        L19 = 1;

        send_data(0b00000010);
        clear_lights();
        L9 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001010);
        clear_lights();
        L15 = 1;

        send_data(0b00001000);
        clear_lights();
        L20 = 1;

        send_data(0b00000010);
        clear_lights();
        L10 = 1;
    }
}

void three()
{
    for (int i = 0; i < 10; i++) {
        send_data(0b00001010);
        clear_lights();
        L11 = 1;
        L16 = 1;

        send_data(0b00000000);
        clear_lights();
        L6 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001010);
        clear_lights();
        L12 = 1;
        L17 = 1;

        send_data(0b00000000);
        clear_lights();
        L7 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001010);
        clear_lights();
        L13 = 1;
        L18 = 1;

        send_data(0b00000000);
        clear_lights();
        L8 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001010);
        clear_lights();
        L14 = 1;
        L19 = 1;

        send_data(0b00000000);
        clear_lights();
        L9 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001010);
        clear_lights();
        L15 = 1;
        L20 = 1;

        send_data(0b00000000);
        clear_lights();
        L10 = 1;
    }
}

void four()
{
    for (int i = 0; i < 5; i++) {
        send_data(0b00000011);
        clear_lights();
        L16 = 1;

        send_data(0b00011011);
        clear_lights();
        L11 = 1;

        send_data(0b00000000);
        clear_lights();
        L6 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000011);
        clear_lights();
        L17 = 1;

        send_data(0b00011011);
        clear_lights();
        L12 = 1;

        send_data(0b00000000);
        clear_lights();
        L7 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000011);
        clear_lights();
        L18 = 1;

        send_data(0b00011011);
        clear_lights();
        L13 = 1;

        send_data(0b00000000);
        clear_lights();
        L8 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000011);
        clear_lights();
        L19 = 1;

        send_data(0b00011011);
        clear_lights();
        L14 = 1;

        send_data(0b00000000);
        clear_lights();
        L9 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00000011);
        clear_lights();
        L20 = 1;

        send_data(0b00011011);
        clear_lights();
        L15 = 1;

        send_data(0b00000000);
        clear_lights();
        L10 = 1;
    }
}


void five()
{
    for (int i = 0; i < 5; i++) {
        send_data(0b00001010);
        clear_lights();
        L11 = 1;

        send_data(0b00001000);
        clear_lights();
        L6 = 1;

        send_data(0b00000010);
        clear_lights();
        L16 = 1;

    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001010);
        clear_lights();
        L12 = 1;

        send_data(0b00001000);
        clear_lights();
        L7 = 1;

        send_data(0b00000010);
        clear_lights();
        L17 = 1;

    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001010);
        clear_lights();
        L13 = 1;

        send_data(0b00001000);
        clear_lights();
        L8 = 1;

        send_data(0b00000010);
        clear_lights();
        L18 = 1;

    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001010);
        clear_lights();
        L14 = 1;

        send_data(0b00001000);
        clear_lights();
        L9 = 1;

        send_data(0b00000010);
        clear_lights();
        L19 = 1;

    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001010);
        clear_lights();
        L15 = 1;

        send_data(0b00001000);
        clear_lights();
        L10 = 1;

        send_data(0b00000010);
        clear_lights();
        L20 = 1;

    }
}

void six()
{
    for (int i = 0; i < 5; i++) {
        send_data(0b00001000);
        clear_lights();
        L6 = 1;

        send_data(0b00001010);
        clear_lights();
        L11 = 1;

        send_data(0b00010000);
        clear_lights();
        L16 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001000);
        clear_lights();
        L7 = 1;

        send_data(0b00001010);
        clear_lights();
        L12 = 1;

        send_data(0b00010000);
        clear_lights();
        L17 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001000);
        clear_lights();
        L8 = 1;

        send_data(0b00001010);
        clear_lights();
        L13 = 1;

        send_data(0b00010000);
        clear_lights();
        L18 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001000);
        clear_lights();
        L9 = 1;

        send_data(0b00001010);
        clear_lights();
        L14 = 1;

        send_data(0b00010000);
        clear_lights();
        L19 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001000);
        clear_lights();
        L10 = 1;

        send_data(0b00001010);
        clear_lights();
        L15 = 1;

        send_data(0b00010000);
        clear_lights();
        L20 = 1;
    }
}

void seven()
{
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L6 = 1;

        send_data(0b00001111);
        clear_lights();
        L11 = 1;
        L16 = 1;

    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L7 = 1;

        send_data(0b00001111);
        clear_lights();
        L12 = 1;
        L17 = 1;

    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L8 = 1;

        send_data(0b00001111);
        clear_lights();
        L13 = 1;
        L18 = 1;

    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L9 = 1;

        send_data(0b00001111);
        clear_lights();
        L14 = 1;
        L19 = 1;

    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00000000);
        clear_lights();
        L10 = 1;

        send_data(0b00001111);
        clear_lights();
        L15 = 1;
        L20 = 1;

    }
}

void eight()
{
    for (int i = 0; i < 10; i++) {
        send_data(0b00001010);
        clear_lights();
        L11 = 1;

        send_data(0b00000000);
        clear_lights();
        L6 = 1;
        L16 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001010);
        clear_lights();
        L12 = 1;

        send_data(0b00000000);
        clear_lights();
        L7 = 1;
        L17 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001010);
        clear_lights();
        L13 = 1;

        send_data(0b00000000);
        clear_lights();
        L8 = 1;
        L18 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001010);
        clear_lights();
        L14 = 1;

        send_data(0b00000000);
        clear_lights();
        L9 = 1;
        L19 = 1;
    }
    for (int i = 0; i < 10; i++) {
        send_data(0b00001010);
        clear_lights();
        L15 = 1;

        send_data(0b00000000);
        clear_lights();
        L10 = 1;
        L20 = 1;
    }
}


void nine()
{
    for (int i = 0; i < 5; i++) {
        send_data(0b00001011);
        clear_lights();
        L11 = 1;

        send_data(0b00000000);
        clear_lights();
        L6 = 1;

        send_data(0b00000011);
        clear_lights();
        L16 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001011);
        clear_lights();
        L12 = 1;

        send_data(0b00000000);
        clear_lights();
        L7 = 1;

        send_data(0b00000011);
        clear_lights();
        L17 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001011);
        clear_lights();
        L13 = 1;

        send_data(0b00000000);
        clear_lights();
        L8 = 1;

        send_data(0b00000011);
        clear_lights();
        L18 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001011);
        clear_lights();
        L14 = 1;

        send_data(0b00000000);
        clear_lights();
        L9 = 1;

        send_data(0b00000011);
        clear_lights();
        L19 = 1;
    }
    for (int i = 0; i < 5; i++) {
        send_data(0b00001011);
        clear_lights();
        L15 = 1;

        send_data(0b00000000);
        clear_lights();
        L10 = 1;

        send_data(0b00000011);
        clear_lights();
        L20 = 1;
    }

}