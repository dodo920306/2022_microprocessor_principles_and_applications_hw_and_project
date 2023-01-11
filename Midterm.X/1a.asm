List p=18f4520
    #include<p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF
    org 0x00
    
Reverse macro n
    MOVLW n
    BTFSC WREG, 7
	INCF 0x00
    RRNCF 0x00
    BTFSC WREG, 6
	INCF 0x00
    RRNCF 0x00
    BTFSC WREG, 5
	INCF 0x00
    RRNCF 0x00
    BTFSC WREG, 4
	INCF 0x00
    RRNCF 0x00
    BTFSC WREG, 3
	INCF 0x00
    RRNCF 0x00
    BTFSC WREG, 2
	INCF 0x00
    RRNCF 0x00
    BTFSC WREG, 1
	INCF 0x00
    RRNCF 0x00
    BTFSC WREG, 0
	INCF 0x00
    RRNCF 0x00
endm
    
Initail:
    Reverse 0x44
end