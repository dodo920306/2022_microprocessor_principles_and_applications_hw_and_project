LIST p=18f4520
    #include<p18f4520.inc>
	CONFIG OSC = INTIO67 ; 1 MHZ
	CONFIG WDT = OFF
	CONFIG LVP = OFF
	
	L1	EQU 0x14
	L2	EQU 0x15
	org 0x00
	
; Total 2 + (2 + 7 * num1 + 2) * num2 cycles = C
DELAY macro num1, num2
    local LOOP1 
    local LOOP2
    MOVLW num2
    MOVWF L2
    LOOP2:
	MOVLW num1
	MOVWF L1
    LOOP1:
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	DECFSZ L1, 1
	BRA LOOP1
	DECFSZ L2, 1
	BRA LOOP2
endm
	
check_process macro
   local LOOP
    LOOP:
       BTFSC PORTB, 0
       BRA LOOP
endm
	
start:
int:
    ; let pin can receive digital signal 
    MOVLW 0x0f
    MOVWF ADCON1
    CLRF PORTB
    BSF TRISB, 0
    CLRF LATA
    BCF TRISA, 0
    BCF TRISA, 1
    BCF TRISA, 2
    BCF TRISA, 3
LOOP:
    check_process
    BTG LATA, 0
    DELAY d'200', d'18'
    check_process
    BTG LATA, 1
    DELAY d'200', d'18'
    check_process
    BTG LATA, 2
    DELAY d'200', d'18'
    check_process
    BTG LATA, 3
    DELAY d'200', d'18'
    check_process
    CLRF LATA
    DELAY d'200', d'18'
    GOTO  LOOP
end