#include "xc.inc"
GLOBAL _mypow
    
PSECT mytext, local, class=CODE, reloc=2


_mypow:
    TSTFSZ 0x03
	GOTO INITIALIZATION
    MOVLW 0x01
    MOVWF 0x01
    CLRF 0x02
    RETURN
INITIALIZATION:
    MOVFF 0x003, 0x005
    MOVFF 0x001, 0x003
    DECF 0x05   
LOOP:
    MOVF 0x03, W
    MULWF 0x01
    MOVFF PRODL, 0x011
    MOVFF PRODH, 0x010
    MULWF 0x00
    MOVF PRODL, W
    ADDWF 0x10
    MOVFF 0x011, 0x001
    MOVFF 0x010, 0x000
    DECFSZ 0x05
	GOTO LOOP
    MOVFF 0x000, 0x002
BREAK:
    RETURN
    
    
    
    