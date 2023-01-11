List p=18f4520
    #include<p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF
    org 0x00

LIST_INT macro n1, n2, n3, n4, n5, n6, n7
    LFSR 0, 0x400
    MOVLW n1
    MOVWF POSTINC0
    MOVLW n2
    MOVWF POSTINC0
    MOVLW n3
    MOVWF POSTINC0
    MOVLW n4
    MOVWF POSTINC0
    MOVLW n5
    MOVWF POSTINC0
    MOVLW n6
    MOVWF POSTINC0
    MOVLW n7
    MOVWF POSTINC0
endm
    
Initial:
    LIST_INT 0x09, 0x0A, 0x01, 0x02, 0x00, 0xFF, 0x03
end