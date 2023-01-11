#include "setting_hardaware/setting.h"
#include <stdlib.h>
#include <pic18f4520.h>
#include "stdio.h"
#include "string.h"
#define _XTAL_FREQ 4000000
// using namespace std;

char str[20];
char state[20];
int lightmode;
void Mode1(){
    ClearBuffer();
    return ;
}
void main(void) 
{
    
    SYSTEM_Initialize() ;
    TRISA = 0;
    LATA = 0;
    lightmode = 0;
//    OSCCON = 0x20;
    PR2 = 244;
    
    PIR1bits.TMR2IF = 0;
    T2CON = 0xFF;
    int count = 20;
    LATA = 1;
    while(1){
        if (PIR1bits.TMR2IF) {
            count--;
            if (!count){
                LATA = LATA == 2 ? 1 : 2;
                count = 20;
            }
            PIR1bits.TMR2IF = 0;
        }
        
    }
    
    return;
}

void __interrupt(high_priority) Hi_ISR(void)
{
    if(RCIF)
    {
        if(RCSTAbits.OERR)
        {
            CREN = 0;
            Nop();
            CREN = 1;
        }
        
        MyusartRead();
        strcpy(str, GetString());
        strcat(state, GetString());
        UART_Write_Text(str);
        ClearBuffer();
        if (str[0] == '\r'){
            if (state[0] == '0') {
                PR2 = 244;
                
            }
            else if (state[0] == '1') {
                
                PR2 = 122;
            }
            else if (state[0] == '2') {
                
                PR2 = 61;
            }
            strcpy(state, "");
        }
    }
    
   // process other interrupt sources here, if required
    return;
}