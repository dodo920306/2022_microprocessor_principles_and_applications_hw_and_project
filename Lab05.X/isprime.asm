#include "xc.inc"
GLOBAL _isprime
    
PSECT mytext, local, class=CODE, reloc=2 
 
_isprime:
    MOVLW 0x02
    MOVWF 0x02, 0
    RCALL LOOP
    MOVLW 0xFF
    CPFSLT 0x00, 0
	RETURN
    MOVLW 0x01
    RETURN

LOOP:
    CLRF WREG
    RCALL MUL
    MOVLW 0xFF
    CPFSLT 0x00, 0
	RETURN
    INCF 0x02, F
    MOVF 0x02, W
    MULWF WREG
    MOVF PRODL, W
    SUBWF 0x01, W
    BNN LOOP
	RETURN

MUL:
    ADDWF 0x02, W
    CPFSLT 0x01
	GOTO MUL
    SUBWF 0x02, W
    NEGF WREG
    CPFSEQ 0x01
	RETURN
    MOVLW 0xFF
    MOVWF 0x00
    RETURN

    
