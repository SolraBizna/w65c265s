.MEMORYMAP
SLOTSIZE $10000
DEFAULTSLOT 0
SLOT 0 $0000
.ENDME
.ROMBANKSIZE $10000
.ROMBANKS 256

; Pages full of $C2 are considered empty by mks28
.EMPTYFILL $C2

.BANK 0

; Block us from putting data in reserved areas of the memory map
.ORG $0000
.SECTION "!__ZeroPage" SIZE 256 FORCE
.DS 256, $C2
.ENDS
.ORG $0100
.SECTION "!__StackPage" SIZE 256 FORCE
.DS 256, $C2
.ENDS
.ORG $DF00
.SECTION "!__MCUReg" SIZE 128 FORCE
.DS 128, $C2
; leave open DF80-DFBF (on-chip RAM) and DFCO-DFFF (which will be SRAM on ours)
.ENDS
; Monitor ROM stuff
.ORG $E000
.SECTION "!__MonROM" SIZE 8192 FORCE
.DS 8192, $C2
.ENDS
.ORG $DEFC
.SECTION "!__LowPowerSentinel" SIZE 4 FORCE
.DS 4, $C2
.ENDS
.ORG $DF80
.SECTION "!__MonInternalVars" SIZE 64 FORCE
.DS 64, $C2
.ENDS

; And now, the registers
.ENUM $DF00
rPD0 DB ; Port 0 Data Register
rPD1 DB ; Port 1 Data Register
rPD2 DB ; Port 2 Data Register
rPD3 DB ; Port 3 Data Register
rPDD0 DB ; Port 0 Data Direction Register
rPDD1 DB ; Port 1 Data Direction Register
rPDD2 DB ; Port 2 Data Direction Register
rPDD3 DB ; Port 3 Data Direction Register
.ENDE

.ENUM $DF20
rPD4 DB ; Port 4 Data Register
rPD5 DB ; Port 5 Data Register
rPD6 DB ; Port 6 Data Register
rPD7 DB ; Port 7 Data Register
rPDD4 DB ; Port 4 Data Direction Register
rPDD5 DB ; Port 5 Data Direction Register
rPDD6 DB ; Port 6 Data Direction Register
rPDD7 DB ; Port 7 Data Direction Register
.ENDE

.ENUM $DF40
rBCR DB ; Bus Control Register
rSSCR DB ; System Speed Control Register
rTCR DB ; Timer Control Register
rTER DB ; Timer Enable Register
rTIFR DB ; Timer Interrupt Flag Register
rEIFR DB ; Edge Interrupt Flag Register
rTIER DB ; Timer Interrupt Enable Register
rEIER DB ; Edge Interrupt Enable Register
rUIFR DB ; UART Interrupt Flag Register
rUIER DB ; UART Interrupt Enable Register
.ENDE

.ENUM $DF50
rT0LL DB ; Timer 0 Latch Low
rT0LH DB ; Timer 0 Latch High
rT1LL DB ; Timer 1 Latch Low
rT1LH DB ; Timer 1 Latch High
rT2LL DB ; Timer 2 Latch Low
rT2LH DB ; Timer 2 Latch High
rT3LL DB ; Timer 3 Latch Low
rT3LH DB ; Timer 3 Latch High
rT4LL DB ; Timer 4 Latch Low
rT4LH DB ; Timer 4 Latch High
rT5LL DB ; Timer 5 Latch Low
rT5LH DB ; Timer 5 Latch High
rT6LL DB ; Timer 6 Latch Low
rT6LH DB ; Timer 6 Latch High
rT7LL DB ; Timer 7 Latch Low
rT7LH DB ; Timer 7 Latch High
rT0CL DB ; Timer 0 Counter Low
rT0CH DB ; Timer 0 Counter High
rT1CL DB ; Timer 1 Counter Low
rT1CH DB ; Timer 1 Counter High
rT2CL DB ; Timer 2 Counter Low
rT2CH DB ; Timer 2 Counter High
rT3CL DB ; Timer 3 Counter Low
rT3CH DB ; Timer 3 Counter High
rT4CL DB ; Timer 4 Counter Low
rT4CH DB ; Timer 4 Counter High
rT5CL DB ; Timer 5 Counter Low
rT5CH DB ; Timer 5 Counter High
rT6CL DB ; Timer 6 Counter Low
rT6CH DB ; Timer 6 Counter High
rT7CL DB ; Timer 7 Counter Low
rT7CH DB ; Timer 7 Counter High
; $DF70
rACSR0 DB ; UART 0 Control/Status Register
rARTD0 DB ; UART 0 Data Register
rACSR1 DB ; UART 1 Control/Status Register
rARTD1 DB ; UART 0 Data Register
rACSR2 DB ; UART 2 Control/Status Register
rARTD2 DB ; UART 0 Data Register
rACSR3 DB ; UART 3 Control/Status Register
rARTD3 DB ; UART 0 Data Register
rPIBFR DB ; Parallel Interface Flag Register
rPIBER DB ; Parallel Interface Enable Register
rPIR2 DB ; Parallel Interface Register 2
rPIR3 DB ; Parallel Interface Register 3
rPIR4 DB ; Parallel Interface Register 4
rPIR5 DB ; Parallel Interface Register 5
rPIR6 DB ; Parallel Interface Register 6
rPIR7 DB ; Parallel Interface Register 7
.ENDE
