LIST p=18f4520
    #include<p18f4520.inc>
	CONFIG OSC = INTIO67 ; 1 MHZ
	CONFIG WDT = OFF
	CONFIG LVP = OFF
	
	L1	EQU 0x14
	L2	EQU 0x15
	org 0x00

; Total 2 + (2 + 7 * num1 + 2) * num2 cycles = C
DELAY macro
num1 EQU d'200'
num2 EQU d'180'
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

GOTO start
       
lightup0:
    CLRF LATA
    BTG LATA, 0
    BTG LATA, 1
    RETURN
lightup1:
    CLRF LATA
    BTG LATA, 1
    BTG LATA, 2
    RETURN
lightup2:
    CLRF LATA
    BTG LATA, 2
    BTG LATA, 3
    RETURN
lightup3:
    CLRF LATA
    BTG LATA, 3
    BTG LATA, 0
    RETURN
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

loop:    
    check_process
    RCALL lightup0
    DELAY
    RCALL lightup1
    DELAY
    RCALL lightup2
    DELAY
    RCALL lightup3
    DELAY
    CLRF LATA
    
    check_process
    RCALL lightup1
    DELAY
    RCALL lightup2
    DELAY
    RCALL lightup3
    DELAY
    RCALL lightup0
    DELAY
    CLRF LATA
    
    check_process
    RCALL lightup2
    DELAY
    RCALL lightup3
    DELAY
    RCALL lightup0
    DELAY
    RCALL lightup1
    DELAY
    CLRF LATA
    
    check_process
    RCALL lightup3
    DELAY
    RCALL lightup0
    DELAY
    RCALL lightup1
    DELAY
    RCALL lightup2
    DELAY
    CLRF LATA
    
    GOTO loop
end