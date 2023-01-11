#INCLUDE <p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF 
    org 0x00

Inital:
    MOVLB 0x1
    CLRF 0x00
    CLRF 0x00, 1
    CLRF 0x01, 1
    CLRF 0x02, 1
    CLRF 0x03, 1
    CLRF 0x04, 1
    CLRF 0x05, 1
    CLRF 0x06, 1
    CLRF 0x07, 1
    CLRF 0x08, 1
    MOVLW 0x01
    MOVWF 0x00, 1
    MOVWF 0x01, 1
    MOVLW 0x07
    MOVWF 0x00
    LFSR 0, 0x100
    LFSR 1, 0x101
    LFSR 2, 0x102
Start:
    MOVLW 0x00
    ADDWF POSTINC0, 0
    ADDWF POSTINC1, 0
    MOVWF POSTINC2
    DECFSZ 0x00
    GOTO Start
end
    