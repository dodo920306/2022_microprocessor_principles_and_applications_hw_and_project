#include "xc.inc"
GLOBAL _divide_signed
    
PSECT mytext, local, class=CODE, reloc=2 

_divide_signed:
    MOVWF 0x00
    CLRF WREG
    MOVF 0x00
    BNN 0x0E
	NEGF 0x00
	INCF WREG
	MOVWF 0x02
    MOVF 0x01
    BNN 0x16
	NEGF 0x01
	DECF WREG
    MOVF WREG
    BZ 0x1E
	MOVLW 0x01
	MOVWF 0x03
    CLRF WREG
LOOP:
    ADDWF 0x01, W
    INCF 0x10
    CPFSLT 0x00
	GOTO LOOP
    SUBWF 0x01, W
    NEGF WREG
    DECF 0x10
    SUBWF 0x00, W
    MOVWF 0x11
    MOVF 0x03
    BZ 0x38
	NEGF 0x10
    MOVF 0x02
    BZ 0x3E
	NEGF 0x11
    MOVF 0x11, W
    ANDLW 0x0F
    MOVWF 0x01
    MOVF 0x10, W
    ANDLW 0x0F
    RLNCF WREG
    RLNCF WREG
    RLNCF WREG
    RLNCF WREG
    ADDWF 0x01, F
    MOVF 0x10, W
    ANDLW 0xF0
    RLNCF WREG
    RLNCF WREG
    RLNCF WREG
    RLNCF WREG
    MOVWF 0x02
    RETURN
    