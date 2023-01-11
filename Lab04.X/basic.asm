List p=18f4520
    #include<p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF
    org 0x00

Dist macro x1, y1, x2, y2, F1, F2
    MOVLW x2
    SUBLW x1
    MULWF WREG
    MOVF PRODH, W
    MOVWF F1
    MOVF PRODL, W
    MOVWF F2
    MOVLW y2
    SUBLW y1
    MULWF WREG
    MOVF PRODL, W
    ADDWF F2, F
    MOVF PRODH, W
    ADDWFC F1, F
endm 
   
Main:
    Dist 0x05, 0x07, 0x02, 0x03, 0x00, 0x01
end