List p=18f4520
    #include<p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF
    org 0x00

MOVLF macro l, f
    MOVLW l
    MOVWF f
endm

Initialization:
    MOVLF 0x04, 0x01
    MOVLW 0x01
    GOTO Main

Hanoitower:
    MULLW 0x02
    MOVF PRODL, W
    DECFSZ 0x01
	GOTO Hanoitower
    RETURN
    
 
Main:
    RCALL Hanoitower
    SUBLW 0x01
    NEGF WREG
    MOVWF 0x00
end