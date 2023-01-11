LIST p=18f4520
    #include<p18f4520.inc>
	CONFIG OSC = INTIO67
	CONFIG WDT = OFF
	org 0x00

;*****************
;???????????????ANDWF?RRNCF????0b00010111?????bit??1?????????? [0x002]??
;*****************	
	
Initial:
    CLRF 0x00
    CLRF 0x01
    CLRF 0x02
Input:
    MOVLW b'00010111'
    MOVWF 0x00
    MOVLW 0x08
    MOVWF 0x01
    MOVLW b'00000001'
Loop:
    ANDWF 0x00, 0
    ADDWF 0x02
    MOVLW b'00000001'
    RRNCF 0x00
    DECFSZ 0x01
    GOTO Loop
end


