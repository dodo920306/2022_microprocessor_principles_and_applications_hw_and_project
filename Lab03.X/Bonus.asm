List p=18f4520
#include<p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF
org 0x00
    
Initialization:
    MOVLW 0XF5
    MOVWF 0x10
    MOVLW 0X5A
    MOVWF 0x11
    MOVLW 0x01
    MOVWF 0x20
    LFSR 0, 0x10
    LFSR 1, 0x20
    MOVWF FSR1, W
Start:
    ADDLW 0x01
Loop:
    COMF WREG
    ADDLW 0x01
    MOVWF 0x13
    MOVF INDF0, W
    ADDWF 0x13, W
    BZ Forward
    BNN Loop
    
Forward:
    MOVWF 0x13, W
    DECF WREG
    COMF WREG
    MOVWF PREINC1
    GOTO Start
