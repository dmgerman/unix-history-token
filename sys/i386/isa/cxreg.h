begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Defines for Cronyx-Sigma adapter, based on Cirrus Logic multiprotocol  * controller RISC processor CL-CD2400/2401.  *  * Copyright (C) 1994 Cronyx Ltd.  * Author: Serge Vakulenko,<vak@zebub.msk.su>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organizations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * Version 1.0, Fri Oct  7 19:34:06 MSD 1994  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|NBRD
value|3
end_define

begin_comment
comment|/* the maximum number of installed boards */
end_comment

begin_define
define|#
directive|define
name|NPORT
value|16
end_define

begin_comment
comment|/* the number of i/o ports per board */
end_comment

begin_define
define|#
directive|define
name|REVCL_MIN
value|7
end_define

begin_comment
comment|/* CD2400 min. revision number G */
end_comment

begin_define
define|#
directive|define
name|REVCL_MAX
value|11
end_define

begin_comment
comment|/* CD2400 max. revision number K */
end_comment

begin_define
define|#
directive|define
name|BRD_INTR_LEVEL
value|0x5a
end_define

begin_comment
comment|/* interrupt level (arbitrary PILR value) */
end_comment

begin_define
define|#
directive|define
name|CS0
parameter_list|(
name|p
parameter_list|)
value|((p) | 0x8000)
end_define

begin_comment
comment|/* chip select 0 */
end_comment

begin_define
define|#
directive|define
name|CS1
parameter_list|(
name|p
parameter_list|)
value|((p) | 0xc000)
end_define

begin_comment
comment|/* chip select 1 */
end_comment

begin_define
define|#
directive|define
name|BSR
parameter_list|(
name|p
parameter_list|)
value|(p)
end_define

begin_comment
comment|/* board status register, read only */
end_comment

begin_define
define|#
directive|define
name|BCR0
parameter_list|(
name|p
parameter_list|)
value|(p)
end_define

begin_comment
comment|/* board command register 0, write only */
end_comment

begin_define
define|#
directive|define
name|BCR1
parameter_list|(
name|p
parameter_list|)
value|((p) | 0x2000)
end_define

begin_comment
comment|/* board command register 1, write only */
end_comment

begin_comment
comment|/*  * Chip register address, B is chip base port, R is chip register number.  */
end_comment

begin_define
define|#
directive|define
name|R
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|((b) | (((r)<<6& 0x3c00) | ((r)& 0xf)))
end_define

begin_comment
comment|/*  * Interrupt acknowledge register, P is board port, L is interrupt level,  * as programmed in PILR.  */
end_comment

begin_define
define|#
directive|define
name|IACK
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|)
value|(R(p,l) | 0x4000)
end_define

begin_comment
comment|/*  * Global registers.  */
end_comment

begin_define
define|#
directive|define
name|GFRCR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x82)
end_define

begin_comment
comment|/* global firmware revision code register */
end_comment

begin_define
define|#
directive|define
name|CAR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xec)
end_define

begin_comment
comment|/* channel access register */
end_comment

begin_comment
comment|/*  * Option registers.  */
end_comment

begin_define
define|#
directive|define
name|CMR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x18)
end_define

begin_comment
comment|/* channel mode register */
end_comment

begin_define
define|#
directive|define
name|COR1
parameter_list|(
name|b
parameter_list|)
value|R(b,0x13)
end_define

begin_comment
comment|/* channel option register 1 */
end_comment

begin_define
define|#
directive|define
name|COR2
parameter_list|(
name|b
parameter_list|)
value|R(b,0x14)
end_define

begin_comment
comment|/* channel option register 2 */
end_comment

begin_define
define|#
directive|define
name|COR3
parameter_list|(
name|b
parameter_list|)
value|R(b,0x15)
end_define

begin_comment
comment|/* channel option register 3 */
end_comment

begin_define
define|#
directive|define
name|COR4
parameter_list|(
name|b
parameter_list|)
value|R(b,0x16)
end_define

begin_comment
comment|/* channel option register 4 */
end_comment

begin_define
define|#
directive|define
name|COR5
parameter_list|(
name|b
parameter_list|)
value|R(b,0x17)
end_define

begin_comment
comment|/* channel option register 5 */
end_comment

begin_define
define|#
directive|define
name|COR6
parameter_list|(
name|b
parameter_list|)
value|R(b,0x1b)
end_define

begin_comment
comment|/* channel option register 6 */
end_comment

begin_define
define|#
directive|define
name|COR7
parameter_list|(
name|b
parameter_list|)
value|R(b,0x04)
end_define

begin_comment
comment|/* channel option register 7 */
end_comment

begin_define
define|#
directive|define
name|SCHR1
parameter_list|(
name|b
parameter_list|)
value|R(b,0x1c)
end_define

begin_comment
comment|/* special character register 1 */
end_comment

begin_define
define|#
directive|define
name|SCHR2
parameter_list|(
name|b
parameter_list|)
value|R(b,0x1d)
end_define

begin_comment
comment|/* special character register 2 */
end_comment

begin_define
define|#
directive|define
name|SCHR3
parameter_list|(
name|b
parameter_list|)
value|R(b,0x1e)
end_define

begin_comment
comment|/* special character register 3 */
end_comment

begin_define
define|#
directive|define
name|SCHR4
parameter_list|(
name|b
parameter_list|)
value|R(b,0x1f)
end_define

begin_comment
comment|/* special character register 4 */
end_comment

begin_define
define|#
directive|define
name|SCRL
parameter_list|(
name|b
parameter_list|)
value|R(b,0x20)
end_define

begin_comment
comment|/* special character range low */
end_comment

begin_define
define|#
directive|define
name|SCRH
parameter_list|(
name|b
parameter_list|)
value|R(b,0x21)
end_define

begin_comment
comment|/* special character range high */
end_comment

begin_define
define|#
directive|define
name|LNXT
parameter_list|(
name|b
parameter_list|)
value|R(b,0x2d)
end_define

begin_comment
comment|/* LNext character */
end_comment

begin_define
define|#
directive|define
name|RFAR1
parameter_list|(
name|b
parameter_list|)
value|R(b,0x1c)
end_define

begin_comment
comment|/* receive frame address register 1 */
end_comment

begin_define
define|#
directive|define
name|RFAR2
parameter_list|(
name|b
parameter_list|)
value|R(b,0x1d)
end_define

begin_comment
comment|/* receive frame address register 2 */
end_comment

begin_define
define|#
directive|define
name|RFAR3
parameter_list|(
name|b
parameter_list|)
value|R(b,0x1e)
end_define

begin_comment
comment|/* receive frame address register 3 */
end_comment

begin_define
define|#
directive|define
name|RFAR4
parameter_list|(
name|b
parameter_list|)
value|R(b,0x1f)
end_define

begin_comment
comment|/* receive frame address register 4 */
end_comment

begin_define
define|#
directive|define
name|CPSR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xd4)
end_define

begin_comment
comment|/* CRC polynomial select register */
end_comment

begin_comment
comment|/*  * Bit rate and clock option registers.  */
end_comment

begin_define
define|#
directive|define
name|RBPR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xc9)
end_define

begin_comment
comment|/* receive baud rate period register */
end_comment

begin_define
define|#
directive|define
name|RCOR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xca)
end_define

begin_comment
comment|/* receive clock option register */
end_comment

begin_define
define|#
directive|define
name|TBPR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xc1)
end_define

begin_comment
comment|/* transmit baud rate period register */
end_comment

begin_define
define|#
directive|define
name|TCOR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xc2)
end_define

begin_comment
comment|/* receive clock option register */
end_comment

begin_comment
comment|/*  * Channel command and status registers.  */
end_comment

begin_define
define|#
directive|define
name|CCR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x10)
end_define

begin_comment
comment|/* channel command register */
end_comment

begin_define
define|#
directive|define
name|STCR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x11)
end_define

begin_comment
comment|/* special transmit command register */
end_comment

begin_define
define|#
directive|define
name|CSR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x19)
end_define

begin_comment
comment|/* channel status register */
end_comment

begin_define
define|#
directive|define
name|MSVR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xdc)
end_define

begin_comment
comment|/* modem signal value register */
end_comment

begin_define
define|#
directive|define
name|MSVR_RTS
parameter_list|(
name|b
parameter_list|)
value|R(b,0xdc)
end_define

begin_comment
comment|/* modem RTS setup register */
end_comment

begin_define
define|#
directive|define
name|MSVR_DTR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xdd)
end_define

begin_comment
comment|/* modem DTR setup register */
end_comment

begin_comment
comment|/*  * Interrupt registers.  */
end_comment

begin_define
define|#
directive|define
name|LIVR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x0a)
end_define

begin_comment
comment|/* local interrupt vector register */
end_comment

begin_define
define|#
directive|define
name|IER
parameter_list|(
name|b
parameter_list|)
value|R(b,0x12)
end_define

begin_comment
comment|/* interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|LICR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x25)
end_define

begin_comment
comment|/* local interrupting channel register */
end_comment

begin_define
define|#
directive|define
name|STK
parameter_list|(
name|b
parameter_list|)
value|R(b,0xe0)
end_define

begin_comment
comment|/* stack register */
end_comment

begin_comment
comment|/*  * Receive interrupt registers.  */
end_comment

begin_define
define|#
directive|define
name|RPILR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xe3)
end_define

begin_comment
comment|/* receive priority interrupt level register */
end_comment

begin_define
define|#
directive|define
name|RIR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xef)
end_define

begin_comment
comment|/* receive interrupt register */
end_comment

begin_define
define|#
directive|define
name|RISR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x8a)
end_define

begin_comment
comment|/* receive interrupt status register */
end_comment

begin_define
define|#
directive|define
name|RISRL
parameter_list|(
name|b
parameter_list|)
value|R(b,0x8a)
end_define

begin_comment
comment|/* receive interrupt status register low */
end_comment

begin_define
define|#
directive|define
name|RISRH
parameter_list|(
name|b
parameter_list|)
value|R(b,0x8b)
end_define

begin_comment
comment|/* receive interrupt status register high */
end_comment

begin_define
define|#
directive|define
name|RFOC
parameter_list|(
name|b
parameter_list|)
value|R(b,0x33)
end_define

begin_comment
comment|/* receive FIFO output count */
end_comment

begin_define
define|#
directive|define
name|RDR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xf8)
end_define

begin_comment
comment|/* receive data register */
end_comment

begin_define
define|#
directive|define
name|REOIR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x87)
end_define

begin_comment
comment|/* receive end of interrupt register */
end_comment

begin_comment
comment|/*  * Transmit interrupt registers.  */
end_comment

begin_define
define|#
directive|define
name|TPILR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xe2)
end_define

begin_comment
comment|/* transmit priority interrupt level reg */
end_comment

begin_define
define|#
directive|define
name|TIR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xee)
end_define

begin_comment
comment|/* transmit interrupt register */
end_comment

begin_define
define|#
directive|define
name|TISR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x89)
end_define

begin_comment
comment|/* transmit interrupt status register */
end_comment

begin_define
define|#
directive|define
name|TFTC
parameter_list|(
name|b
parameter_list|)
value|R(b,0x83)
end_define

begin_comment
comment|/* transmit FIFO transfer count */
end_comment

begin_define
define|#
directive|define
name|TDR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xf8)
end_define

begin_comment
comment|/* transmit data register */
end_comment

begin_define
define|#
directive|define
name|TEOIR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x86)
end_define

begin_comment
comment|/* transmit end of interrupt register */
end_comment

begin_comment
comment|/*  * Modem interrupt registers.  */
end_comment

begin_define
define|#
directive|define
name|MPILR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xe1)
end_define

begin_comment
comment|/* modem priority interrupt level register */
end_comment

begin_define
define|#
directive|define
name|MIR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xed)
end_define

begin_comment
comment|/* modem interrupt register */
end_comment

begin_define
define|#
directive|define
name|MISR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x88)
end_define

begin_comment
comment|/* modem/timer interrupt status register */
end_comment

begin_define
define|#
directive|define
name|MEOIR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x85)
end_define

begin_comment
comment|/* modem end of interrupt register */
end_comment

begin_comment
comment|/*  * DMA registers.  */
end_comment

begin_define
define|#
directive|define
name|DMR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xf4)
end_define

begin_comment
comment|/* DMA mode register */
end_comment

begin_define
define|#
directive|define
name|BERCNT
parameter_list|(
name|b
parameter_list|)
value|R(b,0x8d)
end_define

begin_comment
comment|/* bus error retry count */
end_comment

begin_define
define|#
directive|define
name|DMABSTS
parameter_list|(
name|b
parameter_list|)
value|R(b,0x1a)
end_define

begin_comment
comment|/* DMA buffer status */
end_comment

begin_comment
comment|/*  * DMA receive registers.  */
end_comment

begin_define
define|#
directive|define
name|ARBADRL
parameter_list|(
name|b
parameter_list|)
value|R(b,0x40)
end_define

begin_comment
comment|/* A receive buffer address lower */
end_comment

begin_define
define|#
directive|define
name|ARBADRU
parameter_list|(
name|b
parameter_list|)
value|R(b,0x42)
end_define

begin_comment
comment|/* A receive buffer address upper */
end_comment

begin_define
define|#
directive|define
name|BRBADRL
parameter_list|(
name|b
parameter_list|)
value|R(b,0x44)
end_define

begin_comment
comment|/* B receive buffer address lower */
end_comment

begin_define
define|#
directive|define
name|BRBADRU
parameter_list|(
name|b
parameter_list|)
value|R(b,0x46)
end_define

begin_comment
comment|/* B receive buffer address upper */
end_comment

begin_define
define|#
directive|define
name|ARBCNT
parameter_list|(
name|b
parameter_list|)
value|R(b,0x48)
end_define

begin_comment
comment|/* A receive buffer byte count */
end_comment

begin_define
define|#
directive|define
name|BRBCNT
parameter_list|(
name|b
parameter_list|)
value|R(b,0x4a)
end_define

begin_comment
comment|/* B receive buffer byte count */
end_comment

begin_define
define|#
directive|define
name|ARBSTS
parameter_list|(
name|b
parameter_list|)
value|R(b,0x4c)
end_define

begin_comment
comment|/* A receive buffer status */
end_comment

begin_define
define|#
directive|define
name|BRBSTS
parameter_list|(
name|b
parameter_list|)
value|R(b,0x4d)
end_define

begin_comment
comment|/* B receive buffer status */
end_comment

begin_define
define|#
directive|define
name|RCBADRL
parameter_list|(
name|b
parameter_list|)
value|R(b,0x3c)
end_define

begin_comment
comment|/* receive current buffer address lower */
end_comment

begin_define
define|#
directive|define
name|RCBADRU
parameter_list|(
name|b
parameter_list|)
value|R(b,0x3e)
end_define

begin_comment
comment|/* receive current buffer address upper */
end_comment

begin_comment
comment|/*  * DMA transmit registers.  */
end_comment

begin_define
define|#
directive|define
name|ATBADRL
parameter_list|(
name|b
parameter_list|)
value|R(b,0x50)
end_define

begin_comment
comment|/* A transmit buffer address lower */
end_comment

begin_define
define|#
directive|define
name|ATBADRU
parameter_list|(
name|b
parameter_list|)
value|R(b,0x52)
end_define

begin_comment
comment|/* A transmit buffer address upper */
end_comment

begin_define
define|#
directive|define
name|BTBADRL
parameter_list|(
name|b
parameter_list|)
value|R(b,0x54)
end_define

begin_comment
comment|/* B transmit buffer address lower */
end_comment

begin_define
define|#
directive|define
name|BTBADRU
parameter_list|(
name|b
parameter_list|)
value|R(b,0x56)
end_define

begin_comment
comment|/* B transmit buffer address upper */
end_comment

begin_define
define|#
directive|define
name|ATBCNT
parameter_list|(
name|b
parameter_list|)
value|R(b,0x58)
end_define

begin_comment
comment|/* A transmit buffer byte count */
end_comment

begin_define
define|#
directive|define
name|BTBCNT
parameter_list|(
name|b
parameter_list|)
value|R(b,0x5a)
end_define

begin_comment
comment|/* B transmit buffer byte count */
end_comment

begin_define
define|#
directive|define
name|ATBSTS
parameter_list|(
name|b
parameter_list|)
value|R(b,0x5c)
end_define

begin_comment
comment|/* A transmit buffer status */
end_comment

begin_define
define|#
directive|define
name|BTBSTS
parameter_list|(
name|b
parameter_list|)
value|R(b,0x5d)
end_define

begin_comment
comment|/* B transmit buffer status */
end_comment

begin_define
define|#
directive|define
name|TCBADRL
parameter_list|(
name|b
parameter_list|)
value|R(b,0x38)
end_define

begin_comment
comment|/* transmit current buffer address lower */
end_comment

begin_define
define|#
directive|define
name|TCBADRU
parameter_list|(
name|b
parameter_list|)
value|R(b,0x3a)
end_define

begin_comment
comment|/* transmit current buffer address upper */
end_comment

begin_comment
comment|/*  * Timer registers.  */
end_comment

begin_define
define|#
directive|define
name|TPR
parameter_list|(
name|b
parameter_list|)
value|R(b,0xd8)
end_define

begin_comment
comment|/* timer period register */
end_comment

begin_define
define|#
directive|define
name|RTPR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x26)
end_define

begin_comment
comment|/* receive timeout period register */
end_comment

begin_define
define|#
directive|define
name|RTPRL
parameter_list|(
name|b
parameter_list|)
value|R(b,0x26)
end_define

begin_comment
comment|/* receive timeout period register low */
end_comment

begin_define
define|#
directive|define
name|RTPTH
parameter_list|(
name|b
parameter_list|)
value|R(b,0x27)
end_define

begin_comment
comment|/* receive timeout period register high */
end_comment

begin_define
define|#
directive|define
name|GT1
parameter_list|(
name|b
parameter_list|)
value|R(b,0x28)
end_define

begin_comment
comment|/* general timer 1 */
end_comment

begin_define
define|#
directive|define
name|GT1L
parameter_list|(
name|b
parameter_list|)
value|R(b,0x28)
end_define

begin_comment
comment|/* general timer 1 low */
end_comment

begin_define
define|#
directive|define
name|GT1H
parameter_list|(
name|b
parameter_list|)
value|R(b,0x29)
end_define

begin_comment
comment|/* general timer 1 high */
end_comment

begin_define
define|#
directive|define
name|GT2
parameter_list|(
name|b
parameter_list|)
value|R(b,0x2a)
end_define

begin_comment
comment|/* general timer 2 */
end_comment

begin_define
define|#
directive|define
name|TTR
parameter_list|(
name|b
parameter_list|)
value|R(b,0x2a)
end_define

begin_comment
comment|/* transmit timer register */
end_comment

begin_comment
comment|/*  * Board status register bits.  */
end_comment

begin_define
define|#
directive|define
name|BSR_NOINTR
value|0x01
end_define

begin_comment
comment|/* no interrupt pending flag */
end_comment

begin_define
define|#
directive|define
name|BSR_VAR_MASK
value|0x66
end_define

begin_comment
comment|/* adapter variant mask */
end_comment

begin_define
define|#
directive|define
name|BSR_OSC_MASK
value|0x18
end_define

begin_comment
comment|/* oscillator frequency mask */
end_comment

begin_define
define|#
directive|define
name|BSR_OSC_20
value|0x18
end_define

begin_comment
comment|/* 20 MHz */
end_comment

begin_define
define|#
directive|define
name|BSR_OSC_18432
value|0x10
end_define

begin_comment
comment|/* 18.432 MHz */
end_comment

begin_define
define|#
directive|define
name|BSR_NOCHAIN
value|0x80
end_define

begin_comment
comment|/* no daisy chained board */
end_comment

begin_define
define|#
directive|define
name|BSR_NODSR
parameter_list|(
name|n
parameter_list|)
value|(0x100<< (n))
end_define

begin_comment
comment|/* DSR from channels 0-3, inverted */
end_comment

begin_define
define|#
directive|define
name|BSR_NOCD
parameter_list|(
name|n
parameter_list|)
value|(0x1000<< (n))
end_define

begin_comment
comment|/* CD from channels 0-3, inverted */
end_comment

begin_comment
comment|/*  * Board revision mask.  */
end_comment

begin_define
define|#
directive|define
name|BSR_REV_MASK
value|(BSR_OSC_MASK|BSR_VAR_MASK|BSR_NOCHAIN)
end_define

begin_comment
comment|/*  * Board control register 0 bits.  */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_DIS
value|0x00
end_define

begin_comment
comment|/* no interrupt generated */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_3
value|0x01
end_define

begin_comment
comment|/* select IRQ number 3 */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_5
value|0x02
end_define

begin_comment
comment|/* select IRQ number 5 */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_7
value|0x03
end_define

begin_comment
comment|/* select IRQ number 7 */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_10
value|0x04
end_define

begin_comment
comment|/* select IRQ number 10 */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_11
value|0x05
end_define

begin_comment
comment|/* select IRQ number 11 */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_12
value|0x06
end_define

begin_comment
comment|/* select IRQ number 12 */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_15
value|0x07
end_define

begin_comment
comment|/* select IRQ number 15 */
end_comment

begin_define
define|#
directive|define
name|BCR0_NORESET
value|0x08
end_define

begin_comment
comment|/* CD2400 reset flag (inverted) */
end_comment

begin_define
define|#
directive|define
name|BCR0_DMA_DIS
value|0x00
end_define

begin_comment
comment|/* no interrupt generated */
end_comment

begin_define
define|#
directive|define
name|BCR0_DMA_5
value|0x10
end_define

begin_comment
comment|/* select DMA channel 5 */
end_comment

begin_define
define|#
directive|define
name|BCR0_DMA_6
value|0x20
end_define

begin_comment
comment|/* select DMA channel 6 */
end_comment

begin_define
define|#
directive|define
name|BCR0_DMA_7
value|0x30
end_define

begin_comment
comment|/* select DMA channel 7 */
end_comment

begin_define
define|#
directive|define
name|BCR0_UM_ASYNC
value|0x00
end_define

begin_comment
comment|/* channel 0 mode - async */
end_comment

begin_define
define|#
directive|define
name|BCR0_UM_SYNC
value|0x80
end_define

begin_comment
comment|/* channel 0 mode - sync */
end_comment

begin_define
define|#
directive|define
name|BCR0_UI_RS232
value|0x00
end_define

begin_comment
comment|/* channel 0 interface - RS-232 */
end_comment

begin_define
define|#
directive|define
name|BCR0_UI_RS449
value|0x40
end_define

begin_comment
comment|/* channel 0 interface - RS-449/V.35 */
end_comment

begin_define
define|#
directive|define
name|BCR0_UMASK
value|0xc0
end_define

begin_comment
comment|/* channel 0 interface mask */
end_comment

begin_comment
comment|/*  * Board control register 1 bits.  */
end_comment

begin_define
define|#
directive|define
name|BCR1_DTR
parameter_list|(
name|n
parameter_list|)
value|(0x100<< (n))
end_define

begin_comment
comment|/* DTR for channels 0-3 sync */
end_comment

begin_comment
comment|/*  * Cronyx board variants.  */
end_comment

begin_define
define|#
directive|define
name|CRONYX_100
value|0x64
end_define

begin_define
define|#
directive|define
name|CRONYX_400
value|0x62
end_define

begin_define
define|#
directive|define
name|CRONYX_500
value|0x60
end_define

begin_define
define|#
directive|define
name|CRONYX_410
value|0x24
end_define

begin_define
define|#
directive|define
name|CRONYX_810
value|0x20
end_define

begin_define
define|#
directive|define
name|CRONYX_410s
value|0x04
end_define

begin_define
define|#
directive|define
name|CRONYX_810s
value|0x00
end_define

begin_define
define|#
directive|define
name|CRONYX_440
value|0x44
end_define

begin_define
define|#
directive|define
name|CRONYX_840
value|0x40
end_define

begin_define
define|#
directive|define
name|CRONYX_401
value|0x26
end_define

begin_define
define|#
directive|define
name|CRONYX_801
value|0x22
end_define

begin_define
define|#
directive|define
name|CRONYX_401s
value|0x06
end_define

begin_define
define|#
directive|define
name|CRONYX_801s
value|0x02
end_define

begin_define
define|#
directive|define
name|CRONYX_404
value|0x46
end_define

begin_define
define|#
directive|define
name|CRONYX_703
value|0x42
end_define

begin_comment
comment|/*  * Channel commands (CCR).  */
end_comment

begin_define
define|#
directive|define
name|CCR_CLRCH
value|0x40
end_define

begin_comment
comment|/* clear channel */
end_comment

begin_define
define|#
directive|define
name|CCR_INITCH
value|0x20
end_define

begin_comment
comment|/* initialize channel */
end_comment

begin_define
define|#
directive|define
name|CCR_RSTALL
value|0x10
end_define

begin_comment
comment|/* reset all channels */
end_comment

begin_define
define|#
directive|define
name|CCR_ENTX
value|0x08
end_define

begin_comment
comment|/* enable transmitter */
end_comment

begin_define
define|#
directive|define
name|CCR_DISTX
value|0x04
end_define

begin_comment
comment|/* disable transmitter */
end_comment

begin_define
define|#
directive|define
name|CCR_ENRX
value|0x02
end_define

begin_comment
comment|/* enable receiver */
end_comment

begin_define
define|#
directive|define
name|CCR_DISRX
value|0x01
end_define

begin_comment
comment|/* disable receiver */
end_comment

begin_define
define|#
directive|define
name|CCR_CLRT1
value|0xc0
end_define

begin_comment
comment|/* clear timer 1 */
end_comment

begin_define
define|#
directive|define
name|CCR_CLRT2
value|0xa0
end_define

begin_comment
comment|/* clear timer 2 */
end_comment

begin_define
define|#
directive|define
name|CCR_CLRRCV
value|0x90
end_define

begin_comment
comment|/* clear receiver */
end_comment

begin_comment
comment|/*  * Interrupt enable register (IER) bits.  */
end_comment

begin_define
define|#
directive|define
name|IER_MDM
value|0x80
end_define

begin_comment
comment|/* modem status changed */
end_comment

begin_define
define|#
directive|define
name|IER_RET
value|0x20
end_define

begin_comment
comment|/* receive exception timeout */
end_comment

begin_define
define|#
directive|define
name|IER_RXD
value|0x08
end_define

begin_comment
comment|/* data received */
end_comment

begin_define
define|#
directive|define
name|IER_TIMER
value|0x04
end_define

begin_comment
comment|/* timer expired */
end_comment

begin_define
define|#
directive|define
name|IER_TXMPTY
value|0x02
end_define

begin_comment
comment|/* transmitter empty */
end_comment

begin_define
define|#
directive|define
name|IER_TXD
value|0x01
end_define

begin_comment
comment|/* data transmitted */
end_comment

begin_comment
comment|/*  * Modem signal values register bits (MSVR).  */
end_comment

begin_define
define|#
directive|define
name|MSV_DSR
value|0x80
end_define

begin_comment
comment|/* state of Data Set Ready input */
end_comment

begin_define
define|#
directive|define
name|MSV_CD
value|0x40
end_define

begin_comment
comment|/* state of Carrier Detect input */
end_comment

begin_define
define|#
directive|define
name|MSV_CTS
value|0x20
end_define

begin_comment
comment|/* state of Clear to Send input */
end_comment

begin_define
define|#
directive|define
name|MSV_TXCOUT
value|0x10
end_define

begin_comment
comment|/* TXCout/DTR pin output flag */
end_comment

begin_define
define|#
directive|define
name|MSV_PORTID
value|0x04
end_define

begin_comment
comment|/* device is CL-CD2401 (not 2400) */
end_comment

begin_define
define|#
directive|define
name|MSV_DTR
value|0x02
end_define

begin_comment
comment|/* state of Data Terminal Ready output */
end_comment

begin_define
define|#
directive|define
name|MSV_RTS
value|0x01
end_define

begin_comment
comment|/* state of Request to Send output */
end_comment

begin_define
define|#
directive|define
name|MSV_BITS
value|"\20\1rts\2dtr\3cd2400\5txcout\6cts\7cd\10dsr"
end_define

begin_comment
comment|/*  * DMA buffer status register bits (DMABSTS).  */
end_comment

begin_define
define|#
directive|define
name|DMABSTS_TDALIGN
value|0x80
end_define

begin_comment
comment|/* internal data alignment in transmit FIFO */
end_comment

begin_define
define|#
directive|define
name|DMABSTS_RSTAPD
value|0x40
end_define

begin_comment
comment|/* reset append mode */
end_comment

begin_define
define|#
directive|define
name|DMABSTS_CRTTBUF
value|0x20
end_define

begin_comment
comment|/* internal current transmit buffer in use */
end_comment

begin_define
define|#
directive|define
name|DMABSTS_APPEND
value|0x10
end_define

begin_comment
comment|/* append buffer is in use */
end_comment

begin_define
define|#
directive|define
name|DMABSTS_NTBUF
value|0x08
end_define

begin_comment
comment|/* next transmit buffer is B (not A) */
end_comment

begin_define
define|#
directive|define
name|DMABSTS_TBUSY
value|0x04
end_define

begin_comment
comment|/* current transmit buffer is in use */
end_comment

begin_define
define|#
directive|define
name|DMABSTS_NRBUF
value|0x02
end_define

begin_comment
comment|/* next receive buffer is B (not A) */
end_comment

begin_define
define|#
directive|define
name|DMABSTS_RBUSY
value|0x01
end_define

begin_comment
comment|/* current receive buffer is in use */
end_comment

begin_comment
comment|/*  * Buffer status register bits ([AB][RT]BSTS).  */
end_comment

begin_define
define|#
directive|define
name|BSTS_BUSERR
value|0x80
end_define

begin_comment
comment|/* bus error */
end_comment

begin_define
define|#
directive|define
name|BSTS_EOFR
value|0x40
end_define

begin_comment
comment|/* end of frame */
end_comment

begin_define
define|#
directive|define
name|BSTS_EOBUF
value|0x20
end_define

begin_comment
comment|/* end of buffer */
end_comment

begin_define
define|#
directive|define
name|BSTS_APPEND
value|0x08
end_define

begin_comment
comment|/* append mode */
end_comment

begin_define
define|#
directive|define
name|BSTS_INTR
value|0x02
end_define

begin_comment
comment|/* interrupt required */
end_comment

begin_define
define|#
directive|define
name|BSTS_OWN24
value|0x01
end_define

begin_comment
comment|/* buffer is (free to be) used by CD2400 */
end_comment

begin_define
define|#
directive|define
name|BSTS_BITS
value|"\20\1own24\2intr\4append\6eobuf\7eofr\10buserr"
end_define

begin_comment
comment|/*  * Receive interrupt status register (RISR) bits.  */
end_comment

begin_define
define|#
directive|define
name|RIS_OVERRUN
value|0x0008
end_define

begin_comment
comment|/* overrun error */
end_comment

begin_define
define|#
directive|define
name|RIS_BB
value|0x0800
end_define

begin_comment
comment|/* buffer B status (not A) */
end_comment

begin_define
define|#
directive|define
name|RIS_EOBUF
value|0x2000
end_define

begin_comment
comment|/* end of buffer reached */
end_comment

begin_define
define|#
directive|define
name|RIS_EOFR
value|0x4000
end_define

begin_comment
comment|/* frame reception complete */
end_comment

begin_define
define|#
directive|define
name|RIS_BUSERR
value|0x8000
end_define

begin_comment
comment|/* bus error */
end_comment

begin_define
define|#
directive|define
name|RISH_CLRDCT
value|0x0001
end_define

begin_comment
comment|/* X.21 clear detect */
end_comment

begin_define
define|#
directive|define
name|RISH_RESIND
value|0x0004
end_define

begin_comment
comment|/* residual indication */
end_comment

begin_define
define|#
directive|define
name|RISH_CRCERR
value|0x0010
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|RISH_RXABORT
value|0x0020
end_define

begin_comment
comment|/* abort sequence received */
end_comment

begin_define
define|#
directive|define
name|RISH_EOFR
value|0x0040
end_define

begin_comment
comment|/* complete frame received */
end_comment

begin_define
define|#
directive|define
name|RISH_BITS
value|"\20\1clrdct\3resind\4overrun\5crcerr\6rxabort\7eofr\14bb\16eobuf\17eofr\20buserr"
end_define

begin_define
define|#
directive|define
name|RISA_BREAK
value|0x0001
end_define

begin_comment
comment|/* break signal detected */
end_comment

begin_define
define|#
directive|define
name|RISA_FRERR
value|0x0002
end_define

begin_comment
comment|/* frame error (bad stop bits) */
end_comment

begin_define
define|#
directive|define
name|RISA_PARERR
value|0x0004
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|RISA_SCMASK
value|0x0070
end_define

begin_comment
comment|/* special character detect mask */
end_comment

begin_define
define|#
directive|define
name|RISA_SCHR1
value|0x0010
end_define

begin_comment
comment|/* special character 1 detected */
end_comment

begin_define
define|#
directive|define
name|RISA_SCHR2
value|0x0020
end_define

begin_comment
comment|/* special character 2 detected */
end_comment

begin_define
define|#
directive|define
name|RISA_SCHR3
value|0x0030
end_define

begin_comment
comment|/* special character 3 detected */
end_comment

begin_define
define|#
directive|define
name|RISA_SCHR4
value|0x0040
end_define

begin_comment
comment|/* special character 4 detected */
end_comment

begin_define
define|#
directive|define
name|RISA_SCRANGE
value|0x0070
end_define

begin_comment
comment|/* special character in range detected */
end_comment

begin_define
define|#
directive|define
name|RISA_TIMEOUT
value|0x0080
end_define

begin_comment
comment|/* receive timeout, no data */
end_comment

begin_define
define|#
directive|define
name|RISA_BITS
value|"\20\1break\2frerr\3parerr\4overrun\5schr1\6schr2\7schr4\10timeout\14bb\16eobuf\17eofr\20buserr"
end_define

begin_define
define|#
directive|define
name|RISB_CRCERR
value|0x0010
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|RISB_RXABORT
value|0x0020
end_define

begin_comment
comment|/* abort sequence received */
end_comment

begin_define
define|#
directive|define
name|RISB_EOFR
value|0x0040
end_define

begin_comment
comment|/* complete frame received */
end_comment

begin_define
define|#
directive|define
name|RISX_LEADCHG
value|0x0001
end_define

begin_comment
comment|/* CTS lead change */
end_comment

begin_define
define|#
directive|define
name|RISX_PARERR
value|0x0004
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|RISX_SCMASK
value|0x0070
end_define

begin_comment
comment|/* special character detect mask */
end_comment

begin_define
define|#
directive|define
name|RISX_SCHR1
value|0x0010
end_define

begin_comment
comment|/* special character 1 detected */
end_comment

begin_define
define|#
directive|define
name|RISX_SCHR2
value|0x0020
end_define

begin_comment
comment|/* special character 2 detected */
end_comment

begin_define
define|#
directive|define
name|RISX_SCHR3
value|0x0030
end_define

begin_comment
comment|/* special character 3 detected */
end_comment

begin_define
define|#
directive|define
name|RISX_ALLZERO
value|0x0040
end_define

begin_comment
comment|/* all 0 condition detected */
end_comment

begin_define
define|#
directive|define
name|RISX_ALLONE
value|0x0050
end_define

begin_comment
comment|/* all 1 condition detected */
end_comment

begin_define
define|#
directive|define
name|RISX_ALTOZ
value|0x0060
end_define

begin_comment
comment|/* alternating 1 0 condition detected */
end_comment

begin_define
define|#
directive|define
name|RISX_SYN
value|0x0070
end_define

begin_comment
comment|/* SYN detected */
end_comment

begin_define
define|#
directive|define
name|RISX_LEAD
value|0x0080
end_define

begin_comment
comment|/* leading value */
end_comment

begin_comment
comment|/*  * Channel mode register (CMR) bits.  */
end_comment

begin_define
define|#
directive|define
name|CMR_RXDMA
value|0x80
end_define

begin_comment
comment|/* DMA receive transfer mode */
end_comment

begin_define
define|#
directive|define
name|CMR_TXDMA
value|0x40
end_define

begin_comment
comment|/* DMA transmit transfer mode */
end_comment

begin_define
define|#
directive|define
name|CMR_HDLC
value|0x00
end_define

begin_comment
comment|/* HDLC protocol mode */
end_comment

begin_define
define|#
directive|define
name|CMR_BISYNC
value|0x01
end_define

begin_comment
comment|/* BISYNC protocol mode */
end_comment

begin_define
define|#
directive|define
name|CMR_ASYNC
value|0x02
end_define

begin_comment
comment|/* ASYNC protocol mode */
end_comment

begin_define
define|#
directive|define
name|CMR_X21
value|0x03
end_define

begin_comment
comment|/* X.21 protocol mode */
end_comment

begin_comment
comment|/*  * Modem interrupt status register (MISR) bits.  */
end_comment

begin_define
define|#
directive|define
name|MIS_CDSR
value|0x80
end_define

begin_comment
comment|/* DSR changed */
end_comment

begin_define
define|#
directive|define
name|MIS_CCD
value|0x40
end_define

begin_comment
comment|/* CD changed */
end_comment

begin_define
define|#
directive|define
name|MIS_CCTS
value|0x20
end_define

begin_comment
comment|/* CTS changed */
end_comment

begin_define
define|#
directive|define
name|MIS_CGT2
value|0x02
end_define

begin_comment
comment|/* GT2 timer expired */
end_comment

begin_define
define|#
directive|define
name|MIS_CGT1
value|0x01
end_define

begin_comment
comment|/* GT1 timer expired */
end_comment

begin_define
define|#
directive|define
name|MIS_BITS
value|"\20\1gt1\2gt2\6ccts\7ccd\10cdsr"
end_define

begin_comment
comment|/*  * Transmit interrupt status register (TISR) bits.  */
end_comment

begin_define
define|#
directive|define
name|TIS_BUSERR
value|0x80
end_define

begin_comment
comment|/* Bus error */
end_comment

begin_define
define|#
directive|define
name|TIS_EOFR
value|0x40
end_define

begin_comment
comment|/* End of frame */
end_comment

begin_define
define|#
directive|define
name|TIS_EOBUF
value|0x20
end_define

begin_comment
comment|/* end of transmit buffer reached */
end_comment

begin_define
define|#
directive|define
name|TIS_UNDERRUN
value|0x10
end_define

begin_comment
comment|/* transmit underrun */
end_comment

begin_define
define|#
directive|define
name|TIS_BB
value|0x08
end_define

begin_comment
comment|/* buffer B status (not A) */
end_comment

begin_define
define|#
directive|define
name|TIS_TXEMPTY
value|0x02
end_define

begin_comment
comment|/* transmitter empty */
end_comment

begin_define
define|#
directive|define
name|TIS_TXDATA
value|0x01
end_define

begin_comment
comment|/* transmit data below threshold */
end_comment

begin_define
define|#
directive|define
name|TIS_BITS
value|"\20\1txdata\2txempty\4bb\5underrun\6eobuf\7eofr\10buserr"
end_define

begin_comment
comment|/*  * Local interrupt vector register (LIVR) bits.  */
end_comment

begin_define
define|#
directive|define
name|LIV_EXCEP
value|0
end_define

begin_define
define|#
directive|define
name|LIV_MODEM
value|1
end_define

begin_define
define|#
directive|define
name|LIV_TXDATA
value|2
end_define

begin_define
define|#
directive|define
name|LIV_RXDATA
value|3
end_define

begin_comment
comment|/*  * Transmit end of interrupt registers (TEOIR) bits.  */
end_comment

begin_define
define|#
directive|define
name|TEOI_TERMBUFF
value|0x80
end_define

begin_comment
comment|/* force current buffer to be discarded */
end_comment

begin_define
define|#
directive|define
name|TEOI_EOFR
value|0x40
end_define

begin_comment
comment|/* end of frame in interrupt mode */
end_comment

begin_define
define|#
directive|define
name|TEOI_SETTM2
value|0x20
end_define

begin_comment
comment|/* set general timer 2 in sync mode */
end_comment

begin_define
define|#
directive|define
name|TEOI_SETTM1
value|0x10
end_define

begin_comment
comment|/* set general timer 1 in sync mode */
end_comment

begin_define
define|#
directive|define
name|TEOI_NOTRANSF
value|0x08
end_define

begin_comment
comment|/* no transfer of data on this interrupt */
end_comment

begin_comment
comment|/*  * Receive end of interrupt registers (REOIR) bits.  */
end_comment

begin_define
define|#
directive|define
name|REOI_TERMBUFF
value|0x80
end_define

begin_comment
comment|/* force current buffer to be terminated */
end_comment

begin_define
define|#
directive|define
name|REOI_DISCEXC
value|0x40
end_define

begin_comment
comment|/* discard exception character */
end_comment

begin_define
define|#
directive|define
name|REOI_SETTM2
value|0x20
end_define

begin_comment
comment|/* set general timer 2 */
end_comment

begin_define
define|#
directive|define
name|REOI_SETTM1
value|0x10
end_define

begin_comment
comment|/* set general timer 1 */
end_comment

begin_define
define|#
directive|define
name|REOI_NOTRANSF
value|0x08
end_define

begin_comment
comment|/* no transfer of data */
end_comment

begin_define
define|#
directive|define
name|REOI_GAP_MASK
value|0x07
end_define

begin_comment
comment|/* optional gap size to leave in buffer */
end_comment

begin_comment
comment|/*  * Special transmit command register (STCR) bits.  */
end_comment

begin_define
define|#
directive|define
name|STC_ABORTTX
value|0x40
end_define

begin_comment
comment|/* abort transmission (HDLC mode) */
end_comment

begin_define
define|#
directive|define
name|STC_APPDCMP
value|0x20
end_define

begin_comment
comment|/* append complete (async DMA mode) */
end_comment

begin_define
define|#
directive|define
name|STC_SNDSPC
value|0x08
end_define

begin_comment
comment|/* send special characters (async mode) */
end_comment

begin_define
define|#
directive|define
name|STC_SSPC_MASK
value|0x07
end_define

begin_comment
comment|/* special character select */
end_comment

begin_define
define|#
directive|define
name|STC_SSPC_1
value|0x01
end_define

begin_comment
comment|/* send special character #1 */
end_comment

begin_define
define|#
directive|define
name|STC_SSPC_2
value|0x02
end_define

begin_comment
comment|/* send special character #2 */
end_comment

begin_define
define|#
directive|define
name|STC_SSPC_3
value|0x03
end_define

begin_comment
comment|/* send special character #3 */
end_comment

begin_define
define|#
directive|define
name|STC_SSPC_4
value|0x04
end_define

begin_comment
comment|/* send special character #4 */
end_comment

begin_comment
comment|/*  * Channel status register (CSR) bits, asynchronous mode.  */
end_comment

begin_define
define|#
directive|define
name|CSRA_RXEN
value|0x80
end_define

begin_comment
comment|/* receiver enable */
end_comment

begin_define
define|#
directive|define
name|CSRA_RXFLOFF
value|0x40
end_define

begin_comment
comment|/* receiver flow off */
end_comment

begin_define
define|#
directive|define
name|CSRA_RXFLON
value|0x20
end_define

begin_comment
comment|/* receiver flow on */
end_comment

begin_define
define|#
directive|define
name|CSRA_TXEN
value|0x08
end_define

begin_comment
comment|/* transmitter enable */
end_comment

begin_define
define|#
directive|define
name|CSRA_TXFLOFF
value|0x04
end_define

begin_comment
comment|/* transmitter flow off */
end_comment

begin_define
define|#
directive|define
name|CSRA_TXFLON
value|0x02
end_define

begin_comment
comment|/* transmitter flow on */
end_comment

begin_define
define|#
directive|define
name|CSRA_BITS
value|"\20\2txflon\3txfloff\4txen\6rxflon\7rxfloff\10rxen"
end_define

end_unit

