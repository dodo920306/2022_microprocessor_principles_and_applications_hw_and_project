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
    MOVLF 0x01, 0x00
    MOVLF 0x03, 0x01
    MOVLF 0x03, 0x03
    MOVF 0x00, W
    MOVWF 0x04
    MOVLF 0x26, PCL

GP:
    MOVF 0x04, W
    ADDWF 0x02, F
    DCFSNZ 0x03
	RETURN
    MULWF 0x01
    MOVFF PRODL, 0x004
    MOVLF 0x14, PCL

Main:
    RCALL GP
end    