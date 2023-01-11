#INCLUDE <p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF 
    org 0x00

Inital:
    MOVLB 0x1
    CLRF 0x00, 1
    CLRF 0x01, 1
    CLRF 0x02, 1
    CLRF 0x03, 1
    CLRF 0x04, 1
    CLRF 0x05, 1
    CLRF 0x10, 1
    CLRF 0x11, 1
    CLRF 0x12, 1
    CLRF 0x13, 1
    CLRF 0x14, 1
    CLRF 0x20, 1
    CLRF 0x21, 1
    CLRF 0x22, 1
    CLRF 0x23, 1
    CLRF 0x24, 1
    CLRF 0x25, 1
    CLRF 0x26, 1
    CLRF 0x27, 1
    CLRF 0x28, 1
    MOVLW 0xa1
    MOVWF 0x00, 1
    MOVLW 0xb2
    MOVWF 0x01, 1
    MOVLW 0xc3
    MOVWF 0x02, 1
    MOVLW 0xd4
    MOVWF 0x03, 1
    MOVLW 0xe5
    MOVWF 0x04, 1
    MOVLW 0xa7
    MOVWF 0x10, 1
    MOVLW 0xb3
    MOVWF 0x11, 1
    MOVLW 0xc9
    MOVWF 0x12, 1
    MOVLW 0xf6
    MOVWF 0x13, 1
    MOVLW 0xff
    MOVWF 0x05, 1
    MOVLW 0xff
    MOVWF 0x14, 1
    LFSR 0, 0x100
    LFSR 1, 0x110
    LFSR 2, 0x120
    MOVLW 0x09
    MOVWF 0x00
Start:
    MOVF INDF0, 0
    CPFSLT INDF1
	GOTO Otherwise
    MOVF POSTINC1, 0
    MOVWF POSTINC2
    DECFSZ 0x00
    GOTO Start
    GOTO Termination
Otherwise:
    MOVF POSTINC0, 0
    MOVWF POSTINC2
    DECFSZ 0x00
    GOTO Start
Termination:
    NOP
end