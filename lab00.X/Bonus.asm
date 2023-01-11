LIST p=18f4520
    #include<p18f4520.inc>
	CONFIG OSC = INTIO67
	CONFIG WDT = OFF
	org 0x00
	
;*****************
;???ANDWF?IORWF?COMF?????????[0x000]?[0x001]?????XOR(exclusive or)???????
;??????[0x002]???????????XORWF???
;*****************	
	
Initial:
    CLRF 0x00
    CLRF 0x01
    CLRF 0x02
    CLRF 0x03
Input:
    MOVLW b'00001111'
    MOVWF 0x00
    MOVLW b'00110011'
    MOVWF 0x01
Check:
    MOVF 0x00, 0
    IORWF 0x01, 0
    MOVWF 0x03
    MOVF 0x00, 0
    ANDWF 0x01, 0
    COMF WREG
    ANDWF 0x03, 0
    MOVWF 0x02
end
    


