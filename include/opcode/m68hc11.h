begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m68hc11.h -- Header file for Motorola 68HC11& 68HC12 opcode table    Copyright 1999, 2000, 2002, 2003 Free Software Foundation, Inc.    Written by Stephane Carrez (stcarrez@nerim.fr)  This file is part of GDB, GAS, and the GNU binutils.  GDB, GAS, and the GNU binutils are free software; you can redistribute them and/or modify them under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB, GAS, and the GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this file; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPCODE_M68HC11_H
end_ifndef

begin_define
define|#
directive|define
name|_OPCODE_M68HC11_H
end_define

begin_comment
comment|/* Flags for the definition of the 68HC11& 68HC12 CCR.  */
end_comment

begin_define
define|#
directive|define
name|M6811_S_BIT
value|0x80
end_define

begin_comment
comment|/* Stop disable */
end_comment

begin_define
define|#
directive|define
name|M6811_X_BIT
value|0x40
end_define

begin_comment
comment|/* X-interrupt mask */
end_comment

begin_define
define|#
directive|define
name|M6811_H_BIT
value|0x20
end_define

begin_comment
comment|/* Half carry flag */
end_comment

begin_define
define|#
directive|define
name|M6811_I_BIT
value|0x10
end_define

begin_comment
comment|/* I-interrupt mask */
end_comment

begin_define
define|#
directive|define
name|M6811_N_BIT
value|0x08
end_define

begin_comment
comment|/* Negative */
end_comment

begin_define
define|#
directive|define
name|M6811_Z_BIT
value|0x04
end_define

begin_comment
comment|/* Zero */
end_comment

begin_define
define|#
directive|define
name|M6811_V_BIT
value|0x02
end_define

begin_comment
comment|/* Overflow */
end_comment

begin_define
define|#
directive|define
name|M6811_C_BIT
value|0x01
end_define

begin_comment
comment|/* Carry */
end_comment

begin_comment
comment|/* 68HC11 register address offsets (range 0..0x3F or 0..64).    The absolute address of the I/O register depends on the setting    of the M6811_INIT register.  At init time, the I/O registers are    mapped at 0x1000.  Address of registers is then:     0x1000 + M6811_xxx */
end_comment

begin_define
define|#
directive|define
name|M6811_PORTA
value|0x00
end_define

begin_comment
comment|/* Port A register */
end_comment

begin_define
define|#
directive|define
name|M6811__RES1
value|0x01
end_define

begin_comment
comment|/* Unused/Reserved */
end_comment

begin_define
define|#
directive|define
name|M6811_PIOC
value|0x02
end_define

begin_comment
comment|/* Parallel I/O Control register */
end_comment

begin_define
define|#
directive|define
name|M6811_PORTC
value|0x03
end_define

begin_comment
comment|/* Port C register */
end_comment

begin_define
define|#
directive|define
name|M6811_PORTB
value|0x04
end_define

begin_comment
comment|/* Port B register */
end_comment

begin_define
define|#
directive|define
name|M6811_PORTCL
value|0x05
end_define

begin_comment
comment|/* Alternate latched port C */
end_comment

begin_define
define|#
directive|define
name|M6811__RES6
value|0x06
end_define

begin_comment
comment|/* Unused/Reserved */
end_comment

begin_define
define|#
directive|define
name|M6811_DDRC
value|0x07
end_define

begin_comment
comment|/* Data direction register for port C */
end_comment

begin_define
define|#
directive|define
name|M6811_PORTD
value|0x08
end_define

begin_comment
comment|/* Port D register */
end_comment

begin_define
define|#
directive|define
name|M6811_DDRD
value|0x09
end_define

begin_comment
comment|/* Data direction register for port D */
end_comment

begin_define
define|#
directive|define
name|M6811_PORTE
value|0x0A
end_define

begin_comment
comment|/* Port E input register */
end_comment

begin_define
define|#
directive|define
name|M6811_CFORC
value|0x0B
end_define

begin_comment
comment|/* Compare Force Register */
end_comment

begin_define
define|#
directive|define
name|M6811_OC1M
value|0x0C
end_define

begin_comment
comment|/* OC1 Action Mask register */
end_comment

begin_define
define|#
directive|define
name|M6811_OC1D
value|0x0D
end_define

begin_comment
comment|/* OC1 Action Data register */
end_comment

begin_define
define|#
directive|define
name|M6811_TCTN
value|0x0E
end_define

begin_comment
comment|/* Timer Counter Register */
end_comment

begin_define
define|#
directive|define
name|M6811_TCTN_H
value|0x0E
end_define

begin_comment
comment|/* "	 "	 " High part */
end_comment

begin_define
define|#
directive|define
name|M6811_TCTN_L
value|0x0F
end_define

begin_comment
comment|/* "	 "	 " Low part */
end_comment

begin_define
define|#
directive|define
name|M6811_TIC1
value|0x10
end_define

begin_comment
comment|/* Input capture 1 register */
end_comment

begin_define
define|#
directive|define
name|M6811_TIC1_H
value|0x10
end_define

begin_comment
comment|/* "	 "	 " High part */
end_comment

begin_define
define|#
directive|define
name|M6811_TIC1_L
value|0x11
end_define

begin_comment
comment|/* "	 "	 " Low part */
end_comment

begin_define
define|#
directive|define
name|M6811_TIC2
value|0x12
end_define

begin_comment
comment|/* Input capture 2 register */
end_comment

begin_define
define|#
directive|define
name|M6811_TIC2_H
value|0x12
end_define

begin_comment
comment|/* "	 "	 " High part */
end_comment

begin_define
define|#
directive|define
name|M6811_TIC2_L
value|0x13
end_define

begin_comment
comment|/* "	 "	 " Low part */
end_comment

begin_define
define|#
directive|define
name|M6811_TIC3
value|0x14
end_define

begin_comment
comment|/* Input capture 3 register */
end_comment

begin_define
define|#
directive|define
name|M6811_TIC3_H
value|0x14
end_define

begin_comment
comment|/* "	 "	 " High part */
end_comment

begin_define
define|#
directive|define
name|M6811_TIC3_L
value|0x15
end_define

begin_comment
comment|/* "	 "	 " Low part */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC1
value|0x16
end_define

begin_comment
comment|/* Output Compare 1 register */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC1_H
value|0x16
end_define

begin_comment
comment|/* "	 "	 " High part */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC1_L
value|0x17
end_define

begin_comment
comment|/* "	 "	 " Low part */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC2
value|0x18
end_define

begin_comment
comment|/* Output Compare 2 register */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC2_H
value|0x18
end_define

begin_comment
comment|/* "	 "	 " High part */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC2_L
value|0x19
end_define

begin_comment
comment|/* "	 "	 " Low part */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC3
value|0x1A
end_define

begin_comment
comment|/* Output Compare 3 register */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC3_H
value|0x1A
end_define

begin_comment
comment|/* "	 "	 " High part */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC3_L
value|0x1B
end_define

begin_comment
comment|/* "	 "	 " Low part */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC4
value|0x1C
end_define

begin_comment
comment|/* Output Compare 4 register */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC4_H
value|0x1C
end_define

begin_comment
comment|/* "	 "	 " High part */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC4_L
value|0x1D
end_define

begin_comment
comment|/* "	 "	 " Low part */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC5
value|0x1E
end_define

begin_comment
comment|/* Output Compare 5 register */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC5_H
value|0x1E
end_define

begin_comment
comment|/* "	 "	 " High part */
end_comment

begin_define
define|#
directive|define
name|M6811_TOC5_L
value|0x1F
end_define

begin_comment
comment|/* "	 "	 " Low part */
end_comment

begin_define
define|#
directive|define
name|M6811_TCTL1
value|0x20
end_define

begin_comment
comment|/* Timer Control register 1 */
end_comment

begin_define
define|#
directive|define
name|M6811_TCTL2
value|0x21
end_define

begin_comment
comment|/* Timer Control register 2 */
end_comment

begin_define
define|#
directive|define
name|M6811_TMSK1
value|0x22
end_define

begin_comment
comment|/* Timer Interrupt Mask Register 1 */
end_comment

begin_define
define|#
directive|define
name|M6811_TFLG1
value|0x23
end_define

begin_comment
comment|/* Timer Interrupt Flag Register 1 */
end_comment

begin_define
define|#
directive|define
name|M6811_TMSK2
value|0x24
end_define

begin_comment
comment|/* Timer Interrupt Mask Register 2 */
end_comment

begin_define
define|#
directive|define
name|M6811_TFLG2
value|0x25
end_define

begin_comment
comment|/* Timer Interrupt Flag Register 2 */
end_comment

begin_define
define|#
directive|define
name|M6811_PACTL
value|0x26
end_define

begin_comment
comment|/* Pulse Accumulator Control Register */
end_comment

begin_define
define|#
directive|define
name|M6811_PACNT
value|0x27
end_define

begin_comment
comment|/* Pulse Accumulator Count Register */
end_comment

begin_define
define|#
directive|define
name|M6811_SPCR
value|0x28
end_define

begin_comment
comment|/* SPI Control register */
end_comment

begin_define
define|#
directive|define
name|M6811_SPSR
value|0x29
end_define

begin_comment
comment|/* SPI Status register */
end_comment

begin_define
define|#
directive|define
name|M6811_SPDR
value|0x2A
end_define

begin_comment
comment|/* SPI Data register */
end_comment

begin_define
define|#
directive|define
name|M6811_BAUD
value|0x2B
end_define

begin_comment
comment|/* SCI Baud register */
end_comment

begin_define
define|#
directive|define
name|M6811_SCCR1
value|0x2C
end_define

begin_comment
comment|/* SCI Control register 1 */
end_comment

begin_define
define|#
directive|define
name|M6811_SCCR2
value|0x2D
end_define

begin_comment
comment|/* SCI Control register 2 */
end_comment

begin_define
define|#
directive|define
name|M6811_SCSR
value|0x2E
end_define

begin_comment
comment|/* SCI Status register */
end_comment

begin_define
define|#
directive|define
name|M6811_SCDR
value|0x2F
end_define

begin_comment
comment|/* SCI Data (Read => RDR, Write => TDR) */
end_comment

begin_define
define|#
directive|define
name|M6811_ADCTL
value|0x30
end_define

begin_comment
comment|/* A/D Control register */
end_comment

begin_define
define|#
directive|define
name|M6811_ADR1
value|0x31
end_define

begin_comment
comment|/* A/D, Analog Result register 1 */
end_comment

begin_define
define|#
directive|define
name|M6811_ADR2
value|0x32
end_define

begin_comment
comment|/* A/D, Analog Result register 2 */
end_comment

begin_define
define|#
directive|define
name|M6811_ADR3
value|0x33
end_define

begin_comment
comment|/* A/D, Analog Result register 3 */
end_comment

begin_define
define|#
directive|define
name|M6811_ADR4
value|0x34
end_define

begin_comment
comment|/* A/D, Analog Result register 4 */
end_comment

begin_define
define|#
directive|define
name|M6811__RES35
value|0x35
end_define

begin_define
define|#
directive|define
name|M6811__RES36
value|0x36
end_define

begin_define
define|#
directive|define
name|M6811__RES37
value|0x37
end_define

begin_define
define|#
directive|define
name|M6811__RES38
value|0x38
end_define

begin_define
define|#
directive|define
name|M6811_OPTION
value|0x39
end_define

begin_comment
comment|/* System Configuration Options */
end_comment

begin_define
define|#
directive|define
name|M6811_COPRST
value|0x3A
end_define

begin_comment
comment|/* Arm/Reset COP Timer Circuitry */
end_comment

begin_define
define|#
directive|define
name|M6811_PPROG
value|0x3B
end_define

begin_comment
comment|/* EEPROM Programming Control Register */
end_comment

begin_define
define|#
directive|define
name|M6811_HPRIO
value|0x3C
end_define

begin_comment
comment|/* Highest priority I-Bit int and misc */
end_comment

begin_define
define|#
directive|define
name|M6811_INIT
value|0x3D
end_define

begin_comment
comment|/* Ram and I/O mapping register */
end_comment

begin_define
define|#
directive|define
name|M6811_TEST1
value|0x3E
end_define

begin_comment
comment|/* Factory test control register */
end_comment

begin_define
define|#
directive|define
name|M6811_CONFIG
value|0x3F
end_define

begin_comment
comment|/* COP, ROM and EEPROM enables */
end_comment

begin_comment
comment|/* Flags of the CONFIG register (in EEPROM).  */
end_comment

begin_define
define|#
directive|define
name|M6811_NOSEC
value|0x08
end_define

begin_comment
comment|/* Security mode disable */
end_comment

begin_define
define|#
directive|define
name|M6811_NOCOP
value|0x04
end_define

begin_comment
comment|/* COP system disable */
end_comment

begin_define
define|#
directive|define
name|M6811_ROMON
value|0x02
end_define

begin_comment
comment|/* Enable on-chip rom */
end_comment

begin_define
define|#
directive|define
name|M6811_EEON
value|0x01
end_define

begin_comment
comment|/* Enable on-chip eeprom */
end_comment

begin_comment
comment|/* Flags of the PPROG register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_BYTE
value|0x10
end_define

begin_comment
comment|/* Byte mode */
end_comment

begin_define
define|#
directive|define
name|M6811_ROW
value|0x08
end_define

begin_comment
comment|/* Row mode */
end_comment

begin_define
define|#
directive|define
name|M6811_ERASE
value|0x04
end_define

begin_comment
comment|/* Erase mode select (1 = erase, 0 = read) */
end_comment

begin_define
define|#
directive|define
name|M6811_EELAT
value|0x02
end_define

begin_comment
comment|/* EEPROM Latch Control */
end_comment

begin_define
define|#
directive|define
name|M6811_EEPGM
value|0x01
end_define

begin_comment
comment|/* EEPROM Programming Voltage Enable */
end_comment

begin_comment
comment|/* Flags of the PIOC register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_STAF
value|0x80
end_define

begin_comment
comment|/* Strobe A Interrupt Status Flag */
end_comment

begin_define
define|#
directive|define
name|M6811_STAI
value|0x40
end_define

begin_comment
comment|/* Strobe A Interrupt Enable Mask */
end_comment

begin_define
define|#
directive|define
name|M6811_CWOM
value|0x20
end_define

begin_comment
comment|/* Port C Wire OR mode */
end_comment

begin_define
define|#
directive|define
name|M6811_HNDS
value|0x10
end_define

begin_comment
comment|/* Handshake mode */
end_comment

begin_define
define|#
directive|define
name|M6811_OIN
value|0x08
end_define

begin_comment
comment|/* Output or Input handshaking */
end_comment

begin_define
define|#
directive|define
name|M6811_PLS
value|0x04
end_define

begin_comment
comment|/* Pulse/Interlocked Handshake Operation */
end_comment

begin_define
define|#
directive|define
name|M6811_EGA
value|0x02
end_define

begin_comment
comment|/* Active Edge for Strobe A */
end_comment

begin_define
define|#
directive|define
name|M6811_INVB
value|0x01
end_define

begin_comment
comment|/* Invert Strobe B */
end_comment

begin_comment
comment|/* Flags of the SCCR1 register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_R8
value|0x80
end_define

begin_comment
comment|/* Receive Data bit 8 */
end_comment

begin_define
define|#
directive|define
name|M6811_T8
value|0x40
end_define

begin_comment
comment|/* Transmit data bit 8 */
end_comment

begin_define
define|#
directive|define
name|M6811__SCCR1_5
value|0x20
end_define

begin_comment
comment|/* Unused */
end_comment

begin_define
define|#
directive|define
name|M6811_M
value|0x10
end_define

begin_comment
comment|/* SCI Character length */
end_comment

begin_define
define|#
directive|define
name|M6811_WAKE
value|0x08
end_define

begin_comment
comment|/* Wake up method select (0=idle, 1=addr mark) */
end_comment

begin_comment
comment|/* Flags of the SCCR2 register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_TIE
value|0x80
end_define

begin_comment
comment|/* Transmit Interrupt enable */
end_comment

begin_define
define|#
directive|define
name|M6811_TCIE
value|0x40
end_define

begin_comment
comment|/* Transmit Complete Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|M6811_RIE
value|0x20
end_define

begin_comment
comment|/* Receive Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|M6811_ILIE
value|0x10
end_define

begin_comment
comment|/* Idle Line Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|M6811_TE
value|0x08
end_define

begin_comment
comment|/* Transmit Enable */
end_comment

begin_define
define|#
directive|define
name|M6811_RE
value|0x04
end_define

begin_comment
comment|/* Receive Enable */
end_comment

begin_define
define|#
directive|define
name|M6811_RWU
value|0x02
end_define

begin_comment
comment|/* Receiver Wake Up */
end_comment

begin_define
define|#
directive|define
name|M6811_SBK
value|0x01
end_define

begin_comment
comment|/* Send Break */
end_comment

begin_comment
comment|/* Flags of the SCSR register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_TDRE
value|0x80
end_define

begin_comment
comment|/* Transmit Data Register Empty */
end_comment

begin_define
define|#
directive|define
name|M6811_TC
value|0x40
end_define

begin_comment
comment|/* Transmit Complete */
end_comment

begin_define
define|#
directive|define
name|M6811_RDRF
value|0x20
end_define

begin_comment
comment|/* Receive Data Register Full */
end_comment

begin_define
define|#
directive|define
name|M6811_IDLE
value|0x10
end_define

begin_comment
comment|/* Idle Line Detect */
end_comment

begin_define
define|#
directive|define
name|M6811_OR
value|0x08
end_define

begin_comment
comment|/* Overrun Error */
end_comment

begin_define
define|#
directive|define
name|M6811_NF
value|0x04
end_define

begin_comment
comment|/* Noise Flag */
end_comment

begin_define
define|#
directive|define
name|M6811_FE
value|0x02
end_define

begin_comment
comment|/* Framing Error */
end_comment

begin_define
define|#
directive|define
name|M6811__SCSR_0
value|0x01
end_define

begin_comment
comment|/* Unused */
end_comment

begin_comment
comment|/* Flags of the BAUD register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_TCLR
value|0x80
end_define

begin_comment
comment|/* Clear Baud Rate (TEST mode) */
end_comment

begin_define
define|#
directive|define
name|M6811__BAUD_6
value|0x40
end_define

begin_comment
comment|/* Not used */
end_comment

begin_define
define|#
directive|define
name|M6811_SCP1
value|0x20
end_define

begin_comment
comment|/* SCI Baud rate prescaler select */
end_comment

begin_define
define|#
directive|define
name|M6811_SCP0
value|0x10
end_define

begin_define
define|#
directive|define
name|M6811_RCKB
value|0x08
end_define

begin_comment
comment|/* Baud Rate Clock Check (TEST mode) */
end_comment

begin_define
define|#
directive|define
name|M6811_SCR2
value|0x04
end_define

begin_comment
comment|/* SCI Baud rate select */
end_comment

begin_define
define|#
directive|define
name|M6811_SCR1
value|0x02
end_define

begin_define
define|#
directive|define
name|M6811_SCR0
value|0x01
end_define

begin_define
define|#
directive|define
name|M6811_BAUD_DIV_1
value|(0)
end_define

begin_define
define|#
directive|define
name|M6811_BAUD_DIV_3
value|(M6811_SCP0)
end_define

begin_define
define|#
directive|define
name|M6811_BAUD_DIV_4
value|(M6811_SCP1)
end_define

begin_define
define|#
directive|define
name|M6811_BAUD_DIV_13
value|(M6811_SCP1|M6811_SCP0)
end_define

begin_comment
comment|/* Flags of the SPCR register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_SPIE
value|0x80
end_define

begin_comment
comment|/* Serial Peripheral Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|M6811_SPE
value|0x40
end_define

begin_comment
comment|/* Serial Peripheral System Enable */
end_comment

begin_define
define|#
directive|define
name|M6811_DWOM
value|0x20
end_define

begin_comment
comment|/* Port D Wire-OR mode option */
end_comment

begin_define
define|#
directive|define
name|M6811_MSTR
value|0x10
end_define

begin_comment
comment|/* Master Mode Select */
end_comment

begin_define
define|#
directive|define
name|M6811_CPOL
value|0x08
end_define

begin_comment
comment|/* Clock Polarity */
end_comment

begin_define
define|#
directive|define
name|M6811_CPHA
value|0x04
end_define

begin_comment
comment|/* Clock Phase */
end_comment

begin_define
define|#
directive|define
name|M6811_SPR1
value|0x02
end_define

begin_comment
comment|/* SPI Clock Rate Select */
end_comment

begin_define
define|#
directive|define
name|M6811_SPR0
value|0x01
end_define

begin_comment
comment|/* Flags of the SPSR register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_SPIF
value|0x80
end_define

begin_comment
comment|/* SPI Transfer Complete flag */
end_comment

begin_define
define|#
directive|define
name|M6811_WCOL
value|0x40
end_define

begin_comment
comment|/* Write Collision */
end_comment

begin_define
define|#
directive|define
name|M6811_MODF
value|0x10
end_define

begin_comment
comment|/* Mode Fault */
end_comment

begin_comment
comment|/* Flags of the ADCTL register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_CCF
value|0x80
end_define

begin_comment
comment|/* Conversions Complete Flag */
end_comment

begin_define
define|#
directive|define
name|M6811_SCAN
value|0x20
end_define

begin_comment
comment|/* Continuous Scan Control */
end_comment

begin_define
define|#
directive|define
name|M6811_MULT
value|0x10
end_define

begin_comment
comment|/* Multiple Channel/Single Channel Control */
end_comment

begin_define
define|#
directive|define
name|M6811_CD
value|0x08
end_define

begin_comment
comment|/* Channel Select D */
end_comment

begin_define
define|#
directive|define
name|M6811_CC
value|0x04
end_define

begin_comment
comment|/*                C */
end_comment

begin_define
define|#
directive|define
name|M6811_CB
value|0x02
end_define

begin_comment
comment|/*                B */
end_comment

begin_define
define|#
directive|define
name|M6811_CA
value|0x01
end_define

begin_comment
comment|/*                A */
end_comment

begin_comment
comment|/* Flags of the CFORC register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_FOC1
value|0x80
end_define

begin_comment
comment|/* Force Output Compare 1 */
end_comment

begin_define
define|#
directive|define
name|M6811_FOC2
value|0x40
end_define

begin_comment
comment|/*			2 */
end_comment

begin_define
define|#
directive|define
name|M6811_FOC3
value|0x20
end_define

begin_comment
comment|/*			3 */
end_comment

begin_define
define|#
directive|define
name|M6811_FOC4
value|0x10
end_define

begin_comment
comment|/*			4 */
end_comment

begin_define
define|#
directive|define
name|M6811_FOC5
value|0x08
end_define

begin_comment
comment|/*			5 */
end_comment

begin_comment
comment|/* Flags of the OC1M register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_OC1M7
value|0x80
end_define

begin_comment
comment|/* Output Compare 7 */
end_comment

begin_define
define|#
directive|define
name|M6811_OC1M6
value|0x40
end_define

begin_comment
comment|/*                6 */
end_comment

begin_define
define|#
directive|define
name|M6811_OC1M5
value|0x20
end_define

begin_comment
comment|/*                5 */
end_comment

begin_define
define|#
directive|define
name|M6811_OC1M4
value|0x10
end_define

begin_comment
comment|/*                4 */
end_comment

begin_define
define|#
directive|define
name|M6811_OC1M3
value|0x08
end_define

begin_comment
comment|/*                3 */
end_comment

begin_comment
comment|/* Flags of the OC1D register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_OC1D7
value|0x80
end_define

begin_define
define|#
directive|define
name|M6811_OC1D6
value|0x40
end_define

begin_define
define|#
directive|define
name|M6811_OC1D5
value|0x20
end_define

begin_define
define|#
directive|define
name|M6811_OC1D4
value|0x10
end_define

begin_define
define|#
directive|define
name|M6811_OC1D3
value|0x08
end_define

begin_comment
comment|/* Flags of the TCTL1 register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_OM2
value|0x80
end_define

begin_comment
comment|/* Output Mode 2 */
end_comment

begin_define
define|#
directive|define
name|M6811_OL2
value|0x40
end_define

begin_comment
comment|/* Output Level 2 */
end_comment

begin_define
define|#
directive|define
name|M6811_OM3
value|0x20
end_define

begin_define
define|#
directive|define
name|M6811_OL3
value|0x10
end_define

begin_define
define|#
directive|define
name|M6811_OM4
value|0x08
end_define

begin_define
define|#
directive|define
name|M6811_OL4
value|0x04
end_define

begin_define
define|#
directive|define
name|M6811_OM5
value|0x02
end_define

begin_define
define|#
directive|define
name|M6811_OL5
value|0x01
end_define

begin_comment
comment|/* Flags of the TCTL2 register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_EDG1B
value|0x20
end_define

begin_comment
comment|/* Input Edge Capture Control 1 */
end_comment

begin_define
define|#
directive|define
name|M6811_EDG1A
value|0x10
end_define

begin_define
define|#
directive|define
name|M6811_EDG2B
value|0x08
end_define

begin_comment
comment|/* Input 2 */
end_comment

begin_define
define|#
directive|define
name|M6811_EDG2A
value|0x04
end_define

begin_define
define|#
directive|define
name|M6811_EDG3B
value|0x02
end_define

begin_comment
comment|/* Input 3 */
end_comment

begin_define
define|#
directive|define
name|M6811_EDG3A
value|0x01
end_define

begin_comment
comment|/* Flags of the TMSK1 register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_OC1I
value|0x80
end_define

begin_comment
comment|/* Output Compare 1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|M6811_OC2I
value|0x40
end_define

begin_comment
comment|/*		  2	      */
end_comment

begin_define
define|#
directive|define
name|M6811_OC3I
value|0x20
end_define

begin_comment
comment|/*		  3	      */
end_comment

begin_define
define|#
directive|define
name|M6811_OC4I
value|0x10
end_define

begin_comment
comment|/*		  4	      */
end_comment

begin_define
define|#
directive|define
name|M6811_OC5I
value|0x08
end_define

begin_comment
comment|/*		  5	      */
end_comment

begin_define
define|#
directive|define
name|M6811_IC1I
value|0x04
end_define

begin_comment
comment|/* Input Capture  1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|M6811_IC2I
value|0x02
end_define

begin_comment
comment|/*		  2	      */
end_comment

begin_define
define|#
directive|define
name|M6811_IC3I
value|0x01
end_define

begin_comment
comment|/*		  3	      */
end_comment

begin_comment
comment|/* Flags of the TFLG1 register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_OC1F
value|0x80
end_define

begin_comment
comment|/* Output Compare 1 Flag */
end_comment

begin_define
define|#
directive|define
name|M6811_OC2F
value|0x40
end_define

begin_comment
comment|/*		  2	 */
end_comment

begin_define
define|#
directive|define
name|M6811_OC3F
value|0x20
end_define

begin_comment
comment|/*		  3	 */
end_comment

begin_define
define|#
directive|define
name|M6811_OC4F
value|0x10
end_define

begin_comment
comment|/*		  4	 */
end_comment

begin_define
define|#
directive|define
name|M6811_OC5F
value|0x08
end_define

begin_comment
comment|/*		  5	 */
end_comment

begin_define
define|#
directive|define
name|M6811_IC1F
value|0x04
end_define

begin_comment
comment|/* Input Capture  1 Flag */
end_comment

begin_define
define|#
directive|define
name|M6811_IC2F
value|0x02
end_define

begin_comment
comment|/*		  2	 */
end_comment

begin_define
define|#
directive|define
name|M6811_IC3F
value|0x01
end_define

begin_comment
comment|/*		  3	 */
end_comment

begin_comment
comment|/* Flags of Timer Interrupt Mask Register 2 (TMSK2).  */
end_comment

begin_define
define|#
directive|define
name|M6811_TOI
value|0x80
end_define

begin_comment
comment|/* Timer Overflow Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|M6811_RTII
value|0x40
end_define

begin_comment
comment|/* RTI Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|M6811_PAOVI
value|0x20
end_define

begin_comment
comment|/* Pulse Accumulator Overflow Interrupt En. */
end_comment

begin_define
define|#
directive|define
name|M6811_PAII
value|0x10
end_define

begin_comment
comment|/* Pulse Accumulator Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|M6811_PR1
value|0x02
end_define

begin_comment
comment|/* Timer prescaler */
end_comment

begin_define
define|#
directive|define
name|M6811_PR0
value|0x01
end_define

begin_comment
comment|/* Timer prescaler */
end_comment

begin_define
define|#
directive|define
name|M6811_TPR_1
value|0x00
end_define

begin_comment
comment|/* " " prescale div 1 */
end_comment

begin_define
define|#
directive|define
name|M6811_TPR_4
value|0x01
end_define

begin_comment
comment|/* " " prescale div 4 */
end_comment

begin_define
define|#
directive|define
name|M6811_TPR_8
value|0x02
end_define

begin_comment
comment|/* " " prescale div 8 */
end_comment

begin_define
define|#
directive|define
name|M6811_TPR_16
value|0x03
end_define

begin_comment
comment|/* " " prescale div 16 */
end_comment

begin_comment
comment|/* Flags of Timer Interrupt Flag Register 2 (M6811_TFLG2).  */
end_comment

begin_define
define|#
directive|define
name|M6811_TOF
value|0x80
end_define

begin_comment
comment|/* Timer overflow bit */
end_comment

begin_define
define|#
directive|define
name|M6811_RTIF
value|0x40
end_define

begin_comment
comment|/* Read time interrupt flag */
end_comment

begin_define
define|#
directive|define
name|M6811_PAOVF
value|0x20
end_define

begin_comment
comment|/* Pulse accumulator overflow Interrupt flag */
end_comment

begin_define
define|#
directive|define
name|M6811_PAIF
value|0x10
end_define

begin_comment
comment|/* Pulse accumulator Input Edge " " " */
end_comment

begin_comment
comment|/* Flags of Pulse Accumulator Control Register (PACTL).  */
end_comment

begin_define
define|#
directive|define
name|M6811_DDRA7
value|0x80
end_define

begin_comment
comment|/* Data direction for port A bit 7 */
end_comment

begin_define
define|#
directive|define
name|M6811_PAEN
value|0x40
end_define

begin_comment
comment|/* Pulse accumulator system enable */
end_comment

begin_define
define|#
directive|define
name|M6811_PAMOD
value|0x20
end_define

begin_comment
comment|/* Pulse accumulator mode */
end_comment

begin_define
define|#
directive|define
name|M6811_PEDGE
value|0x10
end_define

begin_comment
comment|/* Pulse accumulator edge control */
end_comment

begin_define
define|#
directive|define
name|M6811_RTR1
value|0x02
end_define

begin_comment
comment|/* RTI Interrupt rates select */
end_comment

begin_define
define|#
directive|define
name|M6811_RTR0
value|0x01
end_define

begin_comment
comment|/* " " " " */
end_comment

begin_comment
comment|/* Flags of the Options register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_ADPU
value|0x80
end_define

begin_comment
comment|/* A/D Powerup */
end_comment

begin_define
define|#
directive|define
name|M6811_CSEL
value|0x40
end_define

begin_comment
comment|/* A/D/EE Charge pump clock source select */
end_comment

begin_define
define|#
directive|define
name|M6811_IRQE
value|0x20
end_define

begin_comment
comment|/* IRQ Edge/Level sensitive */
end_comment

begin_define
define|#
directive|define
name|M6811_DLY
value|0x10
end_define

begin_comment
comment|/* Stop exit turn on delay */
end_comment

begin_define
define|#
directive|define
name|M6811_CME
value|0x08
end_define

begin_comment
comment|/* Clock Monitor enable */
end_comment

begin_define
define|#
directive|define
name|M6811_CR1
value|0x02
end_define

begin_comment
comment|/* COP timer rate select */
end_comment

begin_define
define|#
directive|define
name|M6811_CR0
value|0x01
end_define

begin_comment
comment|/* COP timer rate select */
end_comment

begin_comment
comment|/* Flags of the HPRIO register.  */
end_comment

begin_define
define|#
directive|define
name|M6811_RBOOT
value|0x80
end_define

begin_comment
comment|/* Read Bootstrap ROM */
end_comment

begin_define
define|#
directive|define
name|M6811_SMOD
value|0x40
end_define

begin_comment
comment|/* Special Mode */
end_comment

begin_define
define|#
directive|define
name|M6811_MDA
value|0x20
end_define

begin_comment
comment|/* Mode Select A */
end_comment

begin_define
define|#
directive|define
name|M6811_IRV
value|0x10
end_define

begin_comment
comment|/* Internal Read Visibility */
end_comment

begin_define
define|#
directive|define
name|M6811_PSEL3
value|0x08
end_define

begin_comment
comment|/* Priority Select */
end_comment

begin_define
define|#
directive|define
name|M6811_PSEL2
value|0x04
end_define

begin_define
define|#
directive|define
name|M6811_PSEL1
value|0x02
end_define

begin_define
define|#
directive|define
name|M6811_PSEL0
value|0x01
end_define

begin_comment
comment|/* Some insns used by gas to turn relative branches into absolute ones.  */
end_comment

begin_define
define|#
directive|define
name|M6811_BRA
value|0x20
end_define

begin_define
define|#
directive|define
name|M6811_JMP
value|0x7e
end_define

begin_define
define|#
directive|define
name|M6811_BSR
value|0x8d
end_define

begin_define
define|#
directive|define
name|M6811_JSR
value|0xbd
end_define

begin_define
define|#
directive|define
name|M6812_JMP
value|0x06
end_define

begin_define
define|#
directive|define
name|M6812_BSR
value|0x07
end_define

begin_define
define|#
directive|define
name|M6812_JSR
value|0x16
end_define

begin_comment
comment|/* Instruction code pages. Code page 1 is the default.  */
end_comment

begin_comment
comment|/*#define	M6811_OPCODE_PAGE1	0x00*/
end_comment

begin_define
define|#
directive|define
name|M6811_OPCODE_PAGE2
value|0x18
end_define

begin_define
define|#
directive|define
name|M6811_OPCODE_PAGE3
value|0x1A
end_define

begin_define
define|#
directive|define
name|M6811_OPCODE_PAGE4
value|0xCD
end_define

begin_comment
comment|/* 68HC11 operands formats as stored in the m6811_opcode table.  These    flags do not correspond to anything in the 68HC11 or 68HC12.    They are only used by GAS to recognize operands.  */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_NONE
value|0
end_define

begin_comment
comment|/* No operand */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_DIRECT
value|0x0001
end_define

begin_comment
comment|/* Page 0 addressing:   *<val-8bits>  */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_IMM8
value|0x0002
end_define

begin_comment
comment|/*  8 bits immediat:    #<val-8bits>  */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_IMM16
value|0x0004
end_define

begin_comment
comment|/* 16 bits immediat:    #<val-16bits> */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_IND16
value|0x0008
end_define

begin_comment
comment|/* Indirect abs:<val-16>      */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_IND16_P2
value|0x0010
end_define

begin_comment
comment|/* Second parameter indirect abs.     */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_REG
value|0x0020
end_define

begin_comment
comment|/* Register operand 1                 */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_REG_2
value|0x0040
end_define

begin_comment
comment|/* Register operand 2                 */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_IX
value|0x0080
end_define

begin_comment
comment|/* Indirect IX:<val-8>,x     */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_IY
value|0x0100
end_define

begin_comment
comment|/* Indirect IY:<val-8>,y     */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_IDX
value|0x0200
end_define

begin_comment
comment|/* Indirect: N,r N,[+-]r[+-] N:5-bits */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_IDX_1
value|0x0400
end_define

begin_comment
comment|/* N,r N:9-bits  */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_IDX_2
value|0x0800
end_define

begin_comment
comment|/* N,r N:16-bits */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_D_IDX
value|0x1000
end_define

begin_comment
comment|/* Indirect indexed: [D,r] */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_D_IDX_2
value|0x2000
end_define

begin_comment
comment|/* [N,r] N:16-bits */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_PAGE
value|0x4000
end_define

begin_comment
comment|/* Page number */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_MASK
value|0x07FFF
end_define

begin_define
define|#
directive|define
name|M6811_OP_BRANCH
value|0x00008000
end_define

begin_comment
comment|/* Branch, jsr, call */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_BITMASK
value|0x00010000
end_define

begin_comment
comment|/* Bitmask:             #<val-8>    */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_JUMP_REL
value|0x00020000
end_define

begin_comment
comment|/* Pc-Relative:<val-8>     */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_JUMP_REL16
value|0x00040000
end_define

begin_comment
comment|/* Pc-relative:<val-16>    */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_PAGE1
value|0x0000
end_define

begin_define
define|#
directive|define
name|M6811_OP_PAGE2
value|0x00080000
end_define

begin_comment
comment|/* Need a page2 opcode before       */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_PAGE3
value|0x00100000
end_define

begin_comment
comment|/* Need a page3 opcode before       */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_PAGE4
value|0x00200000
end_define

begin_comment
comment|/* Need a page4 opcode before       */
end_comment

begin_define
define|#
directive|define
name|M6811_MAX_OPERANDS
value|3
end_define

begin_comment
comment|/* Max operands: brset<dst><mask><b> */
end_comment

begin_define
define|#
directive|define
name|M6812_ACC_OFFSET
value|0x00400000
end_define

begin_comment
comment|/* A,r B,r D,r			    */
end_comment

begin_define
define|#
directive|define
name|M6812_ACC_IND
value|0x00800000
end_define

begin_comment
comment|/* [D,r]			    */
end_comment

begin_define
define|#
directive|define
name|M6812_PRE_INC
value|0x01000000
end_define

begin_comment
comment|/* n,+r   n = -8..8		    */
end_comment

begin_define
define|#
directive|define
name|M6812_PRE_DEC
value|0x02000000
end_define

begin_comment
comment|/* n,-r			    */
end_comment

begin_define
define|#
directive|define
name|M6812_POST_INC
value|0x04000000
end_define

begin_comment
comment|/* n,r+			    */
end_comment

begin_define
define|#
directive|define
name|M6812_POST_DEC
value|0x08000000
end_define

begin_comment
comment|/* n,r-			    */
end_comment

begin_define
define|#
directive|define
name|M6812_INDEXED_IND
value|0x10000000
end_define

begin_comment
comment|/* [n,r]  n = 16-bits		    */
end_comment

begin_define
define|#
directive|define
name|M6812_INDEXED
value|0x20000000
end_define

begin_comment
comment|/* n,r    n = 5, 9 or 16-bits	    */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_IDX_P2
value|0x40000000
end_define

begin_comment
comment|/* Markers to identify some instructions.  */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_EXG_MARKER
value|0x01000000
end_define

begin_comment
comment|/* exg r1,r2 */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_TFR_MARKER
value|0x02000000
end_define

begin_comment
comment|/* tfr r1,r2 */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_SEX_MARKER
value|0x04000000
end_define

begin_comment
comment|/* sex r1,r2 */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_EQ_MARKER
value|0x80000000
end_define

begin_comment
comment|/* dbeq/ibeq/tbeq */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_DBCC_MARKER
value|0x04000000
end_define

begin_comment
comment|/* dbeq/dbne */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_IBCC_MARKER
value|0x02000000
end_define

begin_comment
comment|/* ibeq/ibne */
end_comment

begin_define
define|#
directive|define
name|M6812_OP_TBCC_MARKER
value|0x01000000
end_define

begin_define
define|#
directive|define
name|M6812_OP_TRAP_ID
value|0x80000000
end_define

begin_comment
comment|/* trap #N */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_HIGH_ADDR
value|0x01000000
end_define

begin_comment
comment|/* Used internally by gas.  */
end_comment

begin_define
define|#
directive|define
name|M6811_OP_LOW_ADDR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|M68HC12_BANK_VIRT
value|0x010000
end_define

begin_define
define|#
directive|define
name|M68HC12_BANK_MASK
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|M68HC12_BANK_BASE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|M68HC12_BANK_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|M68HC12_BANK_PAGE_MASK
value|0x0ff
end_define

begin_comment
comment|/* CPU identification.  */
end_comment

begin_define
define|#
directive|define
name|cpu6811
value|0x01
end_define

begin_define
define|#
directive|define
name|cpu6812
value|0x02
end_define

begin_define
define|#
directive|define
name|cpu6812s
value|0x04
end_define

begin_comment
comment|/* The opcode table is an array of struct m68hc11_opcode.  */
end_comment

begin_struct
struct|struct
name|m68hc11_opcode
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Op-code name */
name|long
name|format
decl_stmt|;
name|unsigned
name|char
name|size
decl_stmt|;
name|unsigned
name|char
name|opcode
decl_stmt|;
name|unsigned
name|char
name|cycles_low
decl_stmt|;
name|unsigned
name|char
name|cycles_high
decl_stmt|;
name|unsigned
name|char
name|set_flags_mask
decl_stmt|;
name|unsigned
name|char
name|clr_flags_mask
decl_stmt|;
name|unsigned
name|char
name|chg_flags_mask
decl_stmt|;
name|unsigned
name|char
name|arch
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Alias definition for 68HC12.  */
end_comment

begin_struct
struct|struct
name|m68hc12_opcode_alias
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|translation
decl_stmt|;
name|unsigned
name|char
name|size
decl_stmt|;
name|unsigned
name|char
name|code1
decl_stmt|;
name|unsigned
name|char
name|code2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The opcode table.  The table contains all the opcodes (all pages).    You can't rely on the order.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|m68hc11_opcode
name|m68hc11_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|m68hc11_num_opcodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Alias table for 68HC12.  It translates some 68HC11 insn which are not    implemented in 68HC12 but have equivalent translations.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|m68hc12_opcode_alias
name|m68hc12_alias
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|m68hc12_num_alias
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPCODE_M68HC11_H */
end_comment

end_unit

