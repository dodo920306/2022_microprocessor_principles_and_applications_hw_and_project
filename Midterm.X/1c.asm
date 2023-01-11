List p=18f4520
    #include<p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF
    org 0x00
    
Initial:
    MOVLW 0x04
    MOVWF 0x10
    MOVLW 0x01
    MOVWF 0x11
    MOVF 0x11, W
    SUBWF 0x10, W
    BZ Same
    MOVWF 0x02
    MOVF 0x11, W
    MOVWF 0x10
    MOVF 0x02, W
    MOVWF 0x11
    MOVLW 0x01
    MOVWF PRODL
    GOTO Loop1
Same:
    MOVLW 0x01
    MOVWF 0x00
    GOTO Final
Loop1:
    MULWF PRODL
    INCF WREG
    DECFSZ 0x11
	GOTO Loop1
    MOVWF 0x02
    MOVF PRODL, W
    MOVWF 0x31
    MOVLW 0x01
    MOVWF PRODL
    MOVF 0x02, W
Loop2:
    MULWF PRODL
    INCF WREG
    DECFSZ 0x10
	GOTO Loop2
    MOVF PRODL, W
    MOVWF 0x21
    MOVF PRODH, W
    MOVWF 0x20
    INCF 0x20
Div:
    MOVF 0x31, W
    SUBWF 0x21, F
    BN Plus
    INCF 0x00
    GOTO Div
Plus:
    DECFSZ 0x20
	GOTO Div
Final:
    NOP
end

