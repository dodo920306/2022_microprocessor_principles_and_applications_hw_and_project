List p=18f4520
#include<p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF
org 0x00
    
Initialization:
    CLRF 0x00
    MOVLW 0x09
    MOVWF 0x10
    MOVLW 0x17
    MOVWF 0x01
    MOVLW 0x06
    MOVWF 0x11
    COMF 0x11, F
    MOVLW 0x01
    ADDWF 0x11, F
Start:
    DECF 0x10
    BZ Termination
    BCF STATUS, C
    RLCF 0x00
    MOVLW 0x01
    BTFSC 0x01, 7
	ADDWF 0x00
    BCF STATUS, C
    RLCF 0x01
    MOVF 0x00, W
    ADDWF 0x11, W
    BN Start
    MOVWF 0x00
    MOVLW 0x01
    ADDWF 0x01, F
    BNZ Start
Termination:
    MOVFF 0x00, 0x02
    MOVFF 0x01, 0x00
    MOVFF 0x02, 0x01
end
	