begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) Comtrol Corporation<support@comtrol.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted prodived that the follwoing conditions  * are met.  * 1. Redistributions of source code must retain the above copyright   *    notive, this list of conditions and the following disclainer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials prodided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *       This product includes software developed by Comtrol Corporation.  * 4. The name of Comtrol Corporation may not be used to endorse or   *    promote products derived from this software without specific   *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY COMTROL CORPORATION ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL COMTROL CORPORATION BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Begin OS-specific defines -  rpreg.h - for RocketPort FreeBSD  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Byte_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ByteIO_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|Word_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|WordIO_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|DWord_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|DWordIO_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sOutB
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|outb(a, b)
end_define

begin_define
define|#
directive|define
name|sOutW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|outw(a, b)
end_define

begin_define
define|#
directive|define
name|sOutDW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|outl(a, b)
end_define

begin_define
define|#
directive|define
name|sInB
parameter_list|(
name|a
parameter_list|)
value|(inb(a))
end_define

begin_define
define|#
directive|define
name|sInW
parameter_list|(
name|a
parameter_list|)
value|(inw(a))
end_define

begin_define
define|#
directive|define
name|sOutStrW
parameter_list|(
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
value|outsw(port, addr, count)
end_define

begin_define
define|#
directive|define
name|sInStrW
parameter_list|(
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
value|insw(port, addr, count)
end_define

begin_comment
comment|/*  * End of OS-specific defines  */
end_comment

begin_define
define|#
directive|define
name|ROCKET_H
end_define

begin_define
define|#
directive|define
name|CTL_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|AIOP_CTL_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|CHAN_AIOP_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|MAX_PORTS_PER_AIOP
value|8
end_define

begin_define
define|#
directive|define
name|MAX_AIOPS_PER_BOARD
value|4
end_define

begin_define
define|#
directive|define
name|MAX_PORTS_PER_BOARD
value|32
end_define

begin_comment
comment|/* Bus Type ID */
end_comment

begin_define
define|#
directive|define
name|isISA
value|0
end_define

begin_define
define|#
directive|define
name|isPCI
value|1
end_define

begin_define
define|#
directive|define
name|isMC
value|2
end_define

begin_comment
comment|/* Controller ID numbers */
end_comment

begin_define
define|#
directive|define
name|CTLID_NULL
value|-1
end_define

begin_comment
comment|/* no controller exists */
end_comment

begin_define
define|#
directive|define
name|CTLID_0001
value|0x0001
end_define

begin_comment
comment|/* controller release 1 */
end_comment

begin_comment
comment|/* PCI IDs  */
end_comment

begin_define
define|#
directive|define
name|RP_VENDOR_ID
value|0x11FE
end_define

begin_define
define|#
directive|define
name|RP_DEVICE_ID_8OCTA
value|0x0001
end_define

begin_define
define|#
directive|define
name|RP_DEVICE_ID_8INTF
value|0x0002
end_define

begin_define
define|#
directive|define
name|RP_DEVICE_ID_16INTF
value|0x0003
end_define

begin_define
define|#
directive|define
name|RP_DEVICE_ID_32INTF
value|0x0004
end_define

begin_comment
comment|/* AIOP ID numbers, identifies AIOP type implementing channel */
end_comment

begin_define
define|#
directive|define
name|AIOPID_NULL
value|-1
end_define

begin_comment
comment|/* no AIOP or channel exists */
end_comment

begin_define
define|#
directive|define
name|AIOPID_0001
value|0x0001
end_define

begin_comment
comment|/* AIOP release 1 */
end_comment

begin_define
define|#
directive|define
name|NULLDEV
value|-1
end_define

begin_comment
comment|/* identifies non-existant device */
end_comment

begin_define
define|#
directive|define
name|NULLCTL
value|-1
end_define

begin_comment
comment|/* identifies non-existant controller */
end_comment

begin_define
define|#
directive|define
name|NULLCTLPTR
value|(CONTROLLER_T *)0
end_define

begin_comment
comment|/* identifies non-existant controller */
end_comment

begin_define
define|#
directive|define
name|NULLAIOP
value|-1
end_define

begin_comment
comment|/* identifies non-existant AIOP */
end_comment

begin_define
define|#
directive|define
name|NULLCHAN
value|-1
end_define

begin_comment
comment|/* identifies non-existant channel */
end_comment

begin_comment
comment|/************************************************************************  Global Register Offsets - Direct Access - Fixed values ************************************************************************/
end_comment

begin_define
define|#
directive|define
name|_CMD_REG
value|0x38
end_define

begin_comment
comment|/* Command Register		 8    Write */
end_comment

begin_define
define|#
directive|define
name|_INT_CHAN
value|0x39
end_define

begin_comment
comment|/* Interrupt Channel Register  8    Read */
end_comment

begin_define
define|#
directive|define
name|_INT_MASK
value|0x3A
end_define

begin_comment
comment|/* Interrupt Mask Register	 8    Read / Write */
end_comment

begin_define
define|#
directive|define
name|_UNUSED
value|0x3B
end_define

begin_comment
comment|/* Unused			 8 */
end_comment

begin_define
define|#
directive|define
name|_INDX_ADDR
value|0x3C
end_define

begin_comment
comment|/* Index Register Address	 16   Write */
end_comment

begin_define
define|#
directive|define
name|_INDX_DATA
value|0x3E
end_define

begin_comment
comment|/* Index Register Data	 8/16 Read / Write */
end_comment

begin_comment
comment|/************************************************************************  Channel Register Offsets for 1st channel in AIOP - Direct Access ************************************************************************/
end_comment

begin_define
define|#
directive|define
name|_TD0
value|0x00
end_define

begin_comment
comment|/* Transmit Data		16   Write */
end_comment

begin_define
define|#
directive|define
name|_RD0
value|0x00
end_define

begin_comment
comment|/* Receive Data		16   Read */
end_comment

begin_define
define|#
directive|define
name|_CHN_STAT0
value|0x20
end_define

begin_comment
comment|/* Channel Status		8/16 Read / Write */
end_comment

begin_define
define|#
directive|define
name|_FIFO_CNT0
value|0x10
end_define

begin_comment
comment|/* Transmit/Receive FIFO Count 16   Read */
end_comment

begin_define
define|#
directive|define
name|_INT_ID0
value|0x30
end_define

begin_comment
comment|/* Interrupt Identification	8    Read */
end_comment

begin_comment
comment|/************************************************************************  Tx Control Register Offsets - Indexed - External - Fixed ************************************************************************/
end_comment

begin_define
define|#
directive|define
name|_TX_ENBLS
value|0x980
end_define

begin_comment
comment|/* Tx Processor Enables Register 8 Read / Write */
end_comment

begin_define
define|#
directive|define
name|_TXCMP1
value|0x988
end_define

begin_comment
comment|/* Transmit Compare Value #1     8 Read / Write */
end_comment

begin_define
define|#
directive|define
name|_TXCMP2
value|0x989
end_define

begin_comment
comment|/* Transmit Compare Value #2     8 Read / Write */
end_comment

begin_define
define|#
directive|define
name|_TXREP1B1
value|0x98A
end_define

begin_comment
comment|/* Tx Replace Value #1 - Byte 1  8 Read / Write */
end_comment

begin_define
define|#
directive|define
name|_TXREP1B2
value|0x98B
end_define

begin_comment
comment|/* Tx Replace Value #1 - Byte 2  8 Read / Write */
end_comment

begin_define
define|#
directive|define
name|_TXREP2
value|0x98C
end_define

begin_comment
comment|/* Transmit Replace Value #2     8 Read / Write */
end_comment

begin_comment
comment|/************************************************************************  Receive FIFO ************************************************************************/
end_comment

begin_define
define|#
directive|define
name|RXFIFO_DATA
value|0x5f
end_define

begin_define
define|#
directive|define
name|RXFIFO_OUT
value|0x5c
end_define

begin_define
define|#
directive|define
name|RXFIFO_EN
value|0x08
end_define

begin_define
define|#
directive|define
name|RXFIFO_DIS
value|0xa7
end_define

begin_comment
comment|/************************************************************************ Memory Controller Register Offsets - Indexed - External - Fixed ************************************************************************/
end_comment

begin_define
define|#
directive|define
name|_RX_FIFO
value|0x000
end_define

begin_comment
comment|/* Rx FIFO */
end_comment

begin_define
define|#
directive|define
name|_TX_FIFO
value|0x800
end_define

begin_comment
comment|/* Tx FIFO */
end_comment

begin_define
define|#
directive|define
name|_RXF_OUTP
value|0x990
end_define

begin_comment
comment|/* Rx FIFO OUT pointer	   16 Read / Write */
end_comment

begin_define
define|#
directive|define
name|_RXF_INP
value|0x992
end_define

begin_comment
comment|/* Rx FIFO IN pointer	   16 Read / Write */
end_comment

begin_define
define|#
directive|define
name|_TXF_OUTP
value|0x994
end_define

begin_comment
comment|/* Tx FIFO OUT pointer	   8  Read / Write */
end_comment

begin_define
define|#
directive|define
name|_TXF_INP
value|0x995
end_define

begin_comment
comment|/* Tx FIFO IN pointer	   8  Read / Write */
end_comment

begin_define
define|#
directive|define
name|_TXP_CNT
value|0x996
end_define

begin_comment
comment|/* Tx Priority Count	   8  Read / Write */
end_comment

begin_define
define|#
directive|define
name|_TXP_PNTR
value|0x997
end_define

begin_comment
comment|/* Tx Priority Pointer	   8  Read / Write */
end_comment

begin_define
define|#
directive|define
name|PRI_PEND
value|0x80
end_define

begin_comment
comment|/* Priority data pending (bit7, Tx pri cnt) */
end_comment

begin_define
define|#
directive|define
name|TXFIFO_SIZE
value|255
end_define

begin_comment
comment|/* size of Tx FIFO */
end_comment

begin_define
define|#
directive|define
name|RXFIFO_SIZE
value|1023
end_define

begin_comment
comment|/* size of Rx FIFO */
end_comment

begin_comment
comment|/************************************************************************ Tx Priority Buffer - Indexed - External - Fixed ************************************************************************/
end_comment

begin_define
define|#
directive|define
name|_TXP_BUF
value|0x9C0
end_define

begin_comment
comment|/* Tx Priority Buffer  32	Bytes	Read / Write */
end_comment

begin_define
define|#
directive|define
name|TXP_SIZE
value|0x20
end_define

begin_comment
comment|/* 32 bytes */
end_comment

begin_comment
comment|/************************************************************************ Channel Register Offsets - Indexed - Internal - Fixed ************************************************************************/
end_comment

begin_define
define|#
directive|define
name|_TX_CTRL
value|0xFF0
end_define

begin_comment
comment|/* Transmit Control	       16  Write */
end_comment

begin_define
define|#
directive|define
name|_RX_CTRL
value|0xFF2
end_define

begin_comment
comment|/* Receive Control 		8  Write */
end_comment

begin_define
define|#
directive|define
name|_BAUD
value|0xFF4
end_define

begin_comment
comment|/* Baud Rate		       16  Write */
end_comment

begin_define
define|#
directive|define
name|_CLK_PRE
value|0xFF6
end_define

begin_comment
comment|/* Clock Prescaler 		8  Write */
end_comment

begin_define
define|#
directive|define
name|CLOCK_PRESC
value|0x19
end_define

begin_comment
comment|/* mod 9 (divide by 10) prescale */
end_comment

begin_define
define|#
directive|define
name|BRD50
value|4607
end_define

begin_define
define|#
directive|define
name|BRD75
value|3071
end_define

begin_define
define|#
directive|define
name|BRD110
value|2094
end_define

begin_define
define|#
directive|define
name|BRD134
value|1712
end_define

begin_define
define|#
directive|define
name|BRD150
value|1535
end_define

begin_define
define|#
directive|define
name|BRD200
value|1151
end_define

begin_define
define|#
directive|define
name|BRD300
value|767
end_define

begin_define
define|#
directive|define
name|BRD600
value|383
end_define

begin_define
define|#
directive|define
name|BRD1200
value|191
end_define

begin_define
define|#
directive|define
name|BRD1800
value|127
end_define

begin_define
define|#
directive|define
name|BRD2000
value|114
end_define

begin_define
define|#
directive|define
name|BRD2400
value|95
end_define

begin_define
define|#
directive|define
name|BRD3600
value|64
end_define

begin_define
define|#
directive|define
name|BRD4800
value|47
end_define

begin_define
define|#
directive|define
name|BRD7200
value|31
end_define

begin_define
define|#
directive|define
name|BRD9600
value|23
end_define

begin_define
define|#
directive|define
name|BRD14400
value|15
end_define

begin_define
define|#
directive|define
name|BRD19200
value|11
end_define

begin_define
define|#
directive|define
name|BRD38400
value|5
end_define

begin_define
define|#
directive|define
name|BRD57600
value|3
end_define

begin_define
define|#
directive|define
name|BRD76800
value|2
end_define

begin_define
define|#
directive|define
name|BRD115200
value|1
end_define

begin_define
define|#
directive|define
name|BRD230400
value|0
end_define

begin_define
define|#
directive|define
name|STMBREAK
value|0x08
end_define

begin_comment
comment|/* BREAK */
end_comment

begin_define
define|#
directive|define
name|STMFRAME
value|0x04
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|STMRCVROVR
value|0x02
end_define

begin_comment
comment|/* receiver over run error */
end_comment

begin_define
define|#
directive|define
name|STMPARITY
value|0x01
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|STMERROR
value|(STMBREAK | STMFRAME | STMPARITY)
end_define

begin_define
define|#
directive|define
name|STMBREAKH
value|0x800
end_define

begin_comment
comment|/* BREAK */
end_comment

begin_define
define|#
directive|define
name|STMFRAMEH
value|0x400
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|STMRCVROVRH
value|0x200
end_define

begin_comment
comment|/* receiver over run error */
end_comment

begin_define
define|#
directive|define
name|STMPARITYH
value|0x100
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|STMERRORH
value|(STMBREAKH | STMFRAMEH | STMPARITYH)
end_define

begin_define
define|#
directive|define
name|CTS_ACT
value|0x20
end_define

begin_comment
comment|/* CTS input asserted */
end_comment

begin_define
define|#
directive|define
name|DSR_ACT
value|0x10
end_define

begin_comment
comment|/* DSR input asserted */
end_comment

begin_define
define|#
directive|define
name|CD_ACT
value|0x08
end_define

begin_comment
comment|/* CD input asserted */
end_comment

begin_define
define|#
directive|define
name|TXFIFOMT
value|0x04
end_define

begin_comment
comment|/* Tx FIFO is empty */
end_comment

begin_define
define|#
directive|define
name|TXSHRMT
value|0x02
end_define

begin_comment
comment|/* Tx shift register is empty */
end_comment

begin_define
define|#
directive|define
name|RDA
value|0x01
end_define

begin_comment
comment|/* Rx data available */
end_comment

begin_define
define|#
directive|define
name|DRAINED
value|(TXFIFOMT | TXSHRMT)
end_define

begin_comment
comment|/* indicates Tx is drained */
end_comment

begin_define
define|#
directive|define
name|STATMODE
value|0x8000
end_define

begin_comment
comment|/* status mode enable bit */
end_comment

begin_define
define|#
directive|define
name|RXFOVERFL
value|0x2000
end_define

begin_comment
comment|/* receive FIFO overflow */
end_comment

begin_define
define|#
directive|define
name|RX2MATCH
value|0x1000
end_define

begin_comment
comment|/* receive compare byte 2 match */
end_comment

begin_define
define|#
directive|define
name|RX1MATCH
value|0x0800
end_define

begin_comment
comment|/* receive compare byte 1 match */
end_comment

begin_define
define|#
directive|define
name|RXBREAK
value|0x0400
end_define

begin_comment
comment|/* received BREAK */
end_comment

begin_define
define|#
directive|define
name|RXFRAME
value|0x0200
end_define

begin_comment
comment|/* received framing error */
end_comment

begin_define
define|#
directive|define
name|RXPARITY
value|0x0100
end_define

begin_comment
comment|/* received parity error */
end_comment

begin_define
define|#
directive|define
name|STATERROR
value|(RXBREAK | RXFRAME | RXPARITY)
end_define

begin_define
define|#
directive|define
name|CTSFC_EN
value|0x80
end_define

begin_comment
comment|/* CTS flow control enable bit */
end_comment

begin_define
define|#
directive|define
name|RTSTOG_EN
value|0x40
end_define

begin_comment
comment|/* RTS toggle enable bit */
end_comment

begin_define
define|#
directive|define
name|TXINT_EN
value|0x10
end_define

begin_comment
comment|/* transmit interrupt enable */
end_comment

begin_define
define|#
directive|define
name|STOP2
value|0x08
end_define

begin_comment
comment|/* enable 2 stop bits (0 = 1 stop) */
end_comment

begin_define
define|#
directive|define
name|PARITY_EN
value|0x04
end_define

begin_comment
comment|/* enable parity (0 = no parity) */
end_comment

begin_define
define|#
directive|define
name|EVEN_PAR
value|0x02
end_define

begin_comment
comment|/* even parity (0 = odd parity) */
end_comment

begin_define
define|#
directive|define
name|DATA8BIT
value|0x01
end_define

begin_comment
comment|/* 8 bit data (0 = 7 bit data) */
end_comment

begin_define
define|#
directive|define
name|SETBREAK
value|0x10
end_define

begin_comment
comment|/* send break condition (must clear) */
end_comment

begin_define
define|#
directive|define
name|LOCALLOOP
value|0x08
end_define

begin_comment
comment|/* local loopback set for test */
end_comment

begin_define
define|#
directive|define
name|SET_DTR
value|0x04
end_define

begin_comment
comment|/* assert DTR */
end_comment

begin_define
define|#
directive|define
name|SET_RTS
value|0x02
end_define

begin_comment
comment|/* assert RTS */
end_comment

begin_define
define|#
directive|define
name|TX_ENABLE
value|0x01
end_define

begin_comment
comment|/* enable transmitter */
end_comment

begin_define
define|#
directive|define
name|RTSFC_EN
value|0x40
end_define

begin_comment
comment|/* RTS flow control enable */
end_comment

begin_define
define|#
directive|define
name|RXPROC_EN
value|0x20
end_define

begin_comment
comment|/* receive processor enable */
end_comment

begin_define
define|#
directive|define
name|TRIG_NO
value|0x00
end_define

begin_comment
comment|/* Rx FIFO trigger level 0 (no trigger) */
end_comment

begin_define
define|#
directive|define
name|TRIG_1
value|0x08
end_define

begin_comment
comment|/* trigger level 1 char */
end_comment

begin_define
define|#
directive|define
name|TRIG_1_2
value|0x10
end_define

begin_comment
comment|/* trigger level 1/2 */
end_comment

begin_define
define|#
directive|define
name|TRIG_7_8
value|0x18
end_define

begin_comment
comment|/* trigger level 7/8 */
end_comment

begin_define
define|#
directive|define
name|TRIG_MASK
value|0x18
end_define

begin_comment
comment|/* trigger level mask */
end_comment

begin_define
define|#
directive|define
name|SRCINT_EN
value|0x04
end_define

begin_comment
comment|/* special Rx condition interrupt enable */
end_comment

begin_define
define|#
directive|define
name|RXINT_EN
value|0x02
end_define

begin_comment
comment|/* Rx interrupt enable */
end_comment

begin_define
define|#
directive|define
name|MCINT_EN
value|0x01
end_define

begin_comment
comment|/* modem change interrupt enable */
end_comment

begin_define
define|#
directive|define
name|RXF_TRIG
value|0x20
end_define

begin_comment
comment|/* Rx FIFO trigger level interrupt */
end_comment

begin_define
define|#
directive|define
name|TXFIFO_MT
value|0x10
end_define

begin_comment
comment|/* Tx FIFO empty interrupt */
end_comment

begin_define
define|#
directive|define
name|SRC_INT
value|0x08
end_define

begin_comment
comment|/* special receive condition interrupt */
end_comment

begin_define
define|#
directive|define
name|DELTA_CD
value|0x04
end_define

begin_comment
comment|/* CD change interrupt */
end_comment

begin_define
define|#
directive|define
name|DELTA_CTS
value|0x02
end_define

begin_comment
comment|/* CTS change interrupt */
end_comment

begin_define
define|#
directive|define
name|DELTA_DSR
value|0x01
end_define

begin_comment
comment|/* DSR change interrupt */
end_comment

begin_define
define|#
directive|define
name|REP1W2_EN
value|0x10
end_define

begin_comment
comment|/* replace byte 1 with 2 bytes enable */
end_comment

begin_define
define|#
directive|define
name|IGN2_EN
value|0x08
end_define

begin_comment
comment|/* ignore byte 2 enable */
end_comment

begin_define
define|#
directive|define
name|IGN1_EN
value|0x04
end_define

begin_comment
comment|/* ignore byte 1 enable */
end_comment

begin_define
define|#
directive|define
name|COMP2_EN
value|0x02
end_define

begin_comment
comment|/* compare byte 2 enable */
end_comment

begin_define
define|#
directive|define
name|COMP1_EN
value|0x01
end_define

begin_comment
comment|/* compare byte 1 enable */
end_comment

begin_define
define|#
directive|define
name|RESET_ALL
value|0x80
end_define

begin_comment
comment|/* reset AIOP (all channels) */
end_comment

begin_define
define|#
directive|define
name|TXOVERIDE
value|0x40
end_define

begin_comment
comment|/* Transmit software off override */
end_comment

begin_define
define|#
directive|define
name|RESETUART
value|0x20
end_define

begin_comment
comment|/* reset channel's UART */
end_comment

begin_define
define|#
directive|define
name|RESTXFCNT
value|0x10
end_define

begin_comment
comment|/* reset channel's Tx FIFO count register */
end_comment

begin_define
define|#
directive|define
name|RESRXFCNT
value|0x08
end_define

begin_comment
comment|/* reset channel's Rx FIFO count register */
end_comment

begin_define
define|#
directive|define
name|INTSTAT0
value|0x01
end_define

begin_comment
comment|/* AIOP 0 interrupt status */
end_comment

begin_define
define|#
directive|define
name|INTSTAT1
value|0x02
end_define

begin_comment
comment|/* AIOP 1 interrupt status */
end_comment

begin_define
define|#
directive|define
name|INTSTAT2
value|0x04
end_define

begin_comment
comment|/* AIOP 2 interrupt status */
end_comment

begin_define
define|#
directive|define
name|INTSTAT3
value|0x08
end_define

begin_comment
comment|/* AIOP 3 interrupt status */
end_comment

begin_define
define|#
directive|define
name|INTR_EN
value|0x08
end_define

begin_comment
comment|/* allow interrupts to host */
end_comment

begin_define
define|#
directive|define
name|INT_STROB
value|0x04
end_define

begin_comment
comment|/* strobe and clear interrupt line (EOI) */
end_comment

begin_comment
comment|/**************************************************************************   MUDBAC remapped for PCI **************************************************************************/
end_comment

begin_define
define|#
directive|define
name|_CFG_INT_PCI
value|0x40
end_define

begin_define
define|#
directive|define
name|_PCI_INT_FUNC
value|0x3A
end_define

begin_define
define|#
directive|define
name|PCI_STROB
value|0x2000
end_define

begin_define
define|#
directive|define
name|INTR_EN_PCI
value|0x0010
end_define

begin_define
define|#
directive|define
name|CHAN3_EN
value|0x08
end_define

begin_comment
comment|/* enable AIOP 3 */
end_comment

begin_define
define|#
directive|define
name|CHAN2_EN
value|0x04
end_define

begin_comment
comment|/* enable AIOP 2 */
end_comment

begin_define
define|#
directive|define
name|CHAN1_EN
value|0x02
end_define

begin_comment
comment|/* enable AIOP 1 */
end_comment

begin_define
define|#
directive|define
name|CHAN0_EN
value|0x01
end_define

begin_comment
comment|/* enable AIOP 0 */
end_comment

begin_define
define|#
directive|define
name|FREQ_DIS
value|0x00
end_define

begin_define
define|#
directive|define
name|FREQ_274HZ
value|0x60
end_define

begin_define
define|#
directive|define
name|FREQ_137HZ
value|0x50
end_define

begin_define
define|#
directive|define
name|FREQ_69HZ
value|0x40
end_define

begin_define
define|#
directive|define
name|FREQ_34HZ
value|0x30
end_define

begin_define
define|#
directive|define
name|FREQ_17HZ
value|0x20
end_define

begin_define
define|#
directive|define
name|FREQ_9HZ
value|0x10
end_define

begin_define
define|#
directive|define
name|PERIODIC_ONLY
value|0x80
end_define

begin_comment
comment|/* only PERIODIC interrupt */
end_comment

begin_define
define|#
directive|define
name|CHANINT_EN
value|0x0100
end_define

begin_comment
comment|/* flags to enable/disable channel ints */
end_comment

begin_define
define|#
directive|define
name|RDATASIZE
value|72
end_define

begin_define
define|#
directive|define
name|RREGDATASIZE
value|52
end_define

begin_comment
comment|/* Controller level information structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|CtlID
decl_stmt|;
name|int
name|CtlNum
decl_stmt|;
name|int
name|BusType
decl_stmt|;
name|WordIO_t
name|PCIIO
decl_stmt|;
name|ByteIO_t
name|MBaseIO
decl_stmt|;
name|ByteIO_t
name|MReg1IO
decl_stmt|;
name|ByteIO_t
name|MReg2IO
decl_stmt|;
name|ByteIO_t
name|MReg3IO
decl_stmt|;
name|Byte_t
name|MReg2
decl_stmt|;
name|Byte_t
name|MReg3
decl_stmt|;
name|int
name|NumAiop
decl_stmt|;
name|WordIO_t
name|AiopIO
index|[
name|AIOP_CTL_SIZE
index|]
decl_stmt|;
name|ByteIO_t
name|AiopIntChanIO
index|[
name|AIOP_CTL_SIZE
index|]
decl_stmt|;
name|int
name|AiopID
index|[
name|AIOP_CTL_SIZE
index|]
decl_stmt|;
name|int
name|AiopNumChan
index|[
name|AIOP_CTL_SIZE
index|]
decl_stmt|;
block|}
name|CONTROLLER_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CONTROLLER_T
name|CONTROLLER_t
typedef|;
end_typedef

begin_comment
comment|/* Channel level information structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CONTROLLER_T
modifier|*
name|CtlP
decl_stmt|;
name|int
name|AiopNum
decl_stmt|;
name|int
name|ChanID
decl_stmt|;
name|int
name|ChanNum
decl_stmt|;
name|ByteIO_t
name|Cmd
decl_stmt|;
name|ByteIO_t
name|IntChan
decl_stmt|;
name|ByteIO_t
name|IntMask
decl_stmt|;
name|DWordIO_t
name|IndexAddr
decl_stmt|;
name|WordIO_t
name|IndexData
decl_stmt|;
name|WordIO_t
name|TxRxData
decl_stmt|;
name|WordIO_t
name|ChanStat
decl_stmt|;
name|WordIO_t
name|TxRxCount
decl_stmt|;
name|ByteIO_t
name|IntID
decl_stmt|;
name|Word_t
name|TxFIFO
decl_stmt|;
name|Word_t
name|TxFIFOPtrs
decl_stmt|;
name|Word_t
name|RxFIFO
decl_stmt|;
name|Word_t
name|RxFIFOPtrs
decl_stmt|;
name|Word_t
name|TxPrioCnt
decl_stmt|;
name|Word_t
name|TxPrioPtr
decl_stmt|;
name|Word_t
name|TxPrioBuf
decl_stmt|;
name|Byte_t
name|R
index|[
name|RREGDATASIZE
index|]
decl_stmt|;
name|Byte_t
name|BaudDiv
index|[
literal|4
index|]
decl_stmt|;
name|Byte_t
name|TxControl
index|[
literal|4
index|]
decl_stmt|;
name|Byte_t
name|RxControl
index|[
literal|4
index|]
decl_stmt|;
name|Byte_t
name|TxEnables
index|[
literal|4
index|]
decl_stmt|;
name|Byte_t
name|TxCompare
index|[
literal|4
index|]
decl_stmt|;
name|Byte_t
name|TxReplace1
index|[
literal|4
index|]
decl_stmt|;
name|Byte_t
name|TxReplace2
index|[
literal|4
index|]
decl_stmt|;
block|}
name|CHANNEL_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CHANNEL_T
name|CHANNEL_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CHANNEL_T
modifier|*
name|CHANPTR_T
typedef|;
end_typedef

begin_comment
comment|/*************************************************************************** Function: sClrBreak Purpose:  Stop sending a transmit BREAK signal Call:	  sClrBreak(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sClrBreak
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[3]&= ~SETBREAK; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sClrDTR Purpose:  Clr the DTR output Call:	  sClrDTR(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sClrDTR
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[3]&= ~SET_DTR; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sClrRTS Purpose:  Clr the RTS output Call:	  sClrRTS(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sClrRTS
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[3]&= ~SET_RTS; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sClrTxXOFF Purpose:  Clear any existing transmit software flow control off condition Call:	  sClrTxXOFF(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sClrTxXOFF
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    sOutB((ChP)->Cmd,TXOVERIDE | (Byte_t)(ChP)->ChanNum); \    sOutB((ChP)->Cmd,(Byte_t)(ChP)->ChanNum); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sCtlNumToCtlPtr Purpose:  Convert a controller number to controller structure pointer Call:	  sCtlNumToCtlPtr(CtlNum) 	  int CtlNum; Controller number Return:   CONTROLLER_T *: Ptr to controller structure */
end_comment

begin_define
define|#
directive|define
name|sCtlNumToCtlPtr
parameter_list|(
name|CTLNUM
parameter_list|)
value|&sController[CTLNUM]
end_define

begin_comment
comment|/*************************************************************************** Function: sControllerEOI Purpose:  Strobe the MUDBAC's End Of Interrupt bit. Call:	  sControllerEOI(CtlP) 	  CONTROLLER_T *CtlP; Ptr to controller structure */
end_comment

begin_define
define|#
directive|define
name|sControllerEOI
parameter_list|(
name|CTLP
parameter_list|)
value|sOutB((CTLP)->MReg2IO,(CTLP)->MReg2 | INT_STROB)
end_define

begin_comment
comment|/*************************************************************************** Function: sPCIControllerEOI Purpose:  Strobe the MUDBAC's End Of Interrupt bit. Call:	  sPCIControllerEOI(CtlP) 	  CONTROLLER_T *CtlP; Ptr to controller structure */
end_comment

begin_define
define|#
directive|define
name|sPCIControllerEOI
parameter_list|(
name|CTLP
parameter_list|)
value|sOutW((CTLP)->PCIIO, PCI_STROB)
end_define

begin_comment
comment|/*************************************************************************** Function: sDisAiop Purpose:  Disable I/O access to an AIOP Call:	  sDisAiop(CltP) 	  CONTROLLER_T *CtlP; Ptr to controller structure 	  int AiopNum; Number of AIOP on controller */
end_comment

begin_define
define|#
directive|define
name|sDisAiop
parameter_list|(
name|CTLP
parameter_list|,
name|AIOPNUM
parameter_list|)
define|\
value|{ \    (CTLP)->MReg3&= sBitMapClrTbl[AIOPNUM]; \    sOutB((CTLP)->MReg3IO,(CTLP)->MReg3); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sDisCTSFlowCtl Purpose:  Disable output flow control using CTS Call:	  sDisCTSFlowCtl(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sDisCTSFlowCtl
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[2]&= ~CTSFC_EN; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: DisParity Purpose:  Disable parity Call:	  sDisParity(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Comments: Function sSetParity() can be used in place of functions sEnParity(), 	  sDisParity(), sSetOddParity(), and sSetEvenParity(). */
end_comment

begin_define
define|#
directive|define
name|sDisParity
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[2]&= ~PARITY_EN; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sDisRxFIFO Purpose:  Disable Rx FIFO Call:	  sDisRxFIFO(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sDisRxFIFO
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->R[0x32] = 0x0a; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->R[0x30]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sDisRxStatusMode Purpose:  Disable the Rx status mode Call:	  sDisRxStatusMode(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Comments: This takes the channel out of the receive status mode.  All 	  subsequent reads of receive data using sReadRxWord() will return 	  two data bytes. */
end_comment

begin_define
define|#
directive|define
name|sDisRxStatusMode
parameter_list|(
name|ChP
parameter_list|)
value|sOutW((ChP)->ChanStat,0)
end_define

begin_comment
comment|/*************************************************************************** Function: sDisTransmit Purpose:  Disable transmit Call:	  sDisTransmit(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure 	  This disables movement of Tx data from the Tx FIFO into the 1 byte 	  Tx buffer.  Therefore there could be up to a 2 byte latency 	  between the time sDisTransmit() is called and the transmit buffer 	  and transmit shift register going completely empty. */
end_comment

begin_define
define|#
directive|define
name|sDisTransmit
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[3]&= ~TX_ENABLE; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sDisTxSoftFlowCtl Purpose:  Disable Tx Software Flow Control Call:	  sDisTxSoftFlowCtl(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sDisTxSoftFlowCtl
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->R[0x06] = 0x8a; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->R[0x04]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sEnAiop Purpose:  Enable I/O access to an AIOP Call:	  sEnAiop(CltP) 	  CONTROLLER_T *CtlP; Ptr to controller structure 	  int AiopNum; Number of AIOP on controller */
end_comment

begin_define
define|#
directive|define
name|sEnAiop
parameter_list|(
name|CTLP
parameter_list|,
name|AIOPNUM
parameter_list|)
define|\
value|{ \    (CTLP)->MReg3 |= sBitMapSetTbl[AIOPNUM]; \    sOutB((CTLP)->MReg3IO,(CTLP)->MReg3); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sEnCTSFlowCtl Purpose:  Enable output flow control using CTS Call:	  sEnCTSFlowCtl(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sEnCTSFlowCtl
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[2] |= CTSFC_EN; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: EnParity Purpose:  Enable parity Call:	  sEnParity(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Comments: Function sSetParity() can be used in place of functions sEnParity(), 	  sDisParity(), sSetOddParity(), and sSetEvenParity().  Warnings: Before enabling parity odd or even parity should be chosen using 	  functions sSetOddParity() or sSetEvenParity(). */
end_comment

begin_define
define|#
directive|define
name|sEnParity
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[2] |= PARITY_EN; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sEnRTSFlowCtl Return: void */
end_comment

begin_define
define|#
directive|define
name|sEnRTSFlowCtl
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \ 	(ChP)->TxControl[2]&= ~RTSTOG_EN; \ 	(ChP)->TxControl[3]&= ~SET_RTS; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ 	(ChP)->RxControl[2] |= RTSFC_EN; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->RxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sDisRTSFlowCtl Return: void */
end_comment

begin_define
define|#
directive|define
name|sDisRTSFlowCtl
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \ 	(ChP)->RxControl[2]&= ~RTSFC_EN; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->RxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sEnRxFIFO Purpose:  Enable Rx FIFO Call:	  sEnRxFIFO(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sEnRxFIFO
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->R[0x32] = 0x08; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->R[0x30]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sEnRxProcessor Purpose:  Enable the receive processor Call:	  sEnRxProcessor(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Comments: This function is used to start the receive processor.  When 	  the channel is in the reset state the receive processor is not 	  running.  This is done to prevent the receive processor from 	  executing invalid microcode instructions prior to the 	  downloading of the microcode.  Warnings: This function must be called after valid microcode has been 	  downloaded to the AIOP, and it must not be called before the 	  microcode has been downloaded. */
end_comment

begin_define
define|#
directive|define
name|sEnRxProcessor
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->RxControl[2] |= RXPROC_EN; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->RxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sEnRxStatusMode Purpose:  Enable the Rx status mode Call:	  sEnRxStatusMode(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Comments: This places the channel in the receive status mode.  All subsequent 	  reads of receive data using sReadRxWord() will return a data byte 	  in the low word and a status byte in the high word.  */
end_comment

begin_define
define|#
directive|define
name|sEnRxStatusMode
parameter_list|(
name|ChP
parameter_list|)
value|sOutW((ChP)->ChanStat,STATMODE)
end_define

begin_comment
comment|/*************************************************************************** Function: sEnTransmit Purpose:  Enable transmit Call:	  sEnTransmit(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sEnTransmit
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[3] |= TX_ENABLE; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sGetAiopIntStatus Purpose:  Get the AIOP interrupt status Call:	  sGetAiopIntStatus(CtlP,AiopNum) 	  CONTROLLER_T *CtlP; Ptr to controller structure 	  int AiopNum; AIOP number Return:   Byte_t: The AIOP interrupt status.  Bits 0 through 7 			 represent channels 0 through 7 respectively.  If a 			 bit is set that channel is interrupting. */
end_comment

begin_define
define|#
directive|define
name|sGetAiopIntStatus
parameter_list|(
name|CTLP
parameter_list|,
name|AIOPNUM
parameter_list|)
value|sInB((CTLP)->AiopIntChanIO[AIOPNUM])
end_define

begin_comment
comment|/*************************************************************************** Function: sGetAiopNumChan Purpose:  Get the number of channels supported by an AIOP Call:	  sGetAiopNumChan(CtlP,AiopNum) 	  CONTROLLER_T *CtlP; Ptr to controller structure 	  int AiopNum; AIOP number Return:   int: The number of channels supported by the AIOP */
end_comment

begin_define
define|#
directive|define
name|sGetAiopNumChan
parameter_list|(
name|CTLP
parameter_list|,
name|AIOPNUM
parameter_list|)
value|(CTLP)->AiopNumChan[AIOPNUM]
end_define

begin_comment
comment|/*************************************************************************** Function: sGetChanIntID Purpose:  Get a channel's interrupt identification byte Call:	  sGetChanIntID(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Return:   Byte_t: The channel interrupt ID.  Can be any 	     combination of the following flags: 		RXF_TRIG:     Rx FIFO trigger level interrupt 		TXFIFO_MT:    Tx FIFO empty interrupt 		SRC_INT:      Special receive condition interrupt 		DELTA_CD:     CD change interrupt 		DELTA_CTS:    CTS change interrupt 		DELTA_DSR:    DSR change interrupt */
end_comment

begin_define
define|#
directive|define
name|sGetChanIntID
parameter_list|(
name|ChP
parameter_list|)
value|(sInB((ChP)->IntID)& (RXF_TRIG | TXFIFO_MT | SRC_INT | DELTA_CD | DELTA_CTS | DELTA_DSR))
end_define

begin_comment
comment|/*************************************************************************** Function: sGetChanNum Purpose:  Get the number of a channel within an AIOP Call:	  sGetChanNum(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Return:   int: Channel number within AIOP, or NULLCHAN if channel does 	       not exist. */
end_comment

begin_define
define|#
directive|define
name|sGetChanNum
parameter_list|(
name|ChP
parameter_list|)
value|(ChP)->ChanNum
end_define

begin_comment
comment|/*************************************************************************** Function: sGetChanStatus Purpose:  Get the channel status Call:	  sGetChanStatus(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Return:   Word_t: The channel status.  Can be any combination of 	     the following flags: 		LOW BYTE FLAGS 		CTS_ACT:      CTS input asserted 		DSR_ACT:      DSR input asserted 		CD_ACT:       CD input asserted 		TXFIFOMT:     Tx FIFO is empty 		TXSHRMT:      Tx shift register is empty 		RDA:	      Rx data available  		HIGH BYTE FLAGS 		STATMODE:     status mode enable bit 		RXFOVERFL:    receive FIFO overflow 		RX2MATCH:     receive compare byte 2 match 		RX1MATCH:     receive compare byte 1 match 		RXBREAK:      received BREAK 		RXFRAME:      received framing error 		RXPARITY:     received parity error Warnings: This function will clear the high byte flags in the Channel 	  Status Register. */
end_comment

begin_define
define|#
directive|define
name|sGetChanStatus
parameter_list|(
name|ChP
parameter_list|)
value|sInW((ChP)->ChanStat)
end_define

begin_comment
comment|/*************************************************************************** Function: sGetChanStatusLo Purpose:  Get the low byte only of the channel status Call:	  sGetChanStatusLo(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Return:   Byte_t: The channel status low byte.	Can be any combination 	     of the following flags: 		CTS_ACT:      CTS input asserted 		DSR_ACT:      DSR input asserted 		CD_ACT:       CD input asserted 		TXFIFOMT:     Tx FIFO is empty 		TXSHRMT:      Tx shift register is empty 		RDA:	      Rx data available */
end_comment

begin_define
define|#
directive|define
name|sGetChanStatusLo
parameter_list|(
name|ChP
parameter_list|)
value|sInB((ByteIO_t)(ChP)->ChanStat)
end_define

begin_comment
comment|/*************************************************************************** Function: sGetControllerIntStatus Purpose:  Get the controller interrupt status Call:	  sGetControllerIntStatus(CtlP) 	  CONTROLLER_T *CtlP; Ptr to controller structure Return:   Byte_t: The controller interrupt status in the lower 4 			 bits.	Bits 0 through 3 represent AIOP's 0 			 through 3 respectively.  If a bit is set that 			 AIOP is interrupting.	Bits 4 through 7 will 			 always be cleared. */
end_comment

begin_define
define|#
directive|define
name|sGetControllerIntStatus
parameter_list|(
name|CTLP
parameter_list|)
value|(sInB((CTLP)->MReg1IO)& 0x0f)
end_define

begin_comment
comment|/*************************************************************************** Function: sPCIGetControllerIntStatus Purpose:  Get the controller interrupt status Call:	  sPCIGetControllerIntStatus(CtlP) 	  CONTROLLER_T *CtlP; Ptr to controller structure Return:   Byte_t: The controller interrupt status in the lower 4 			 bits.	Bits 0 through 3 represent AIOP's 0 			 through 3 respectively.  If a bit is set that 			 AIOP is interrupting.	Bits 4 through 7 will 			 always be cleared. */
end_comment

begin_define
define|#
directive|define
name|sPCIGetControllerIntStatus
parameter_list|(
name|CTLP
parameter_list|)
value|((sInW((CTLP)->PCIIO)>> 8)& 0x1f)
end_define

begin_comment
comment|/*************************************************************************** Function: sGetRxCnt Purpose:  Get the number of data bytes in the Rx FIFO Call:	  sGetRxCnt(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Return:   int: The number of data bytes in the Rx FIFO. Comments: Byte read of count register is required to obtain Rx count.  */
end_comment

begin_define
define|#
directive|define
name|sGetRxCnt
parameter_list|(
name|ChP
parameter_list|)
value|sInW((ChP)->TxRxCount)
end_define

begin_comment
comment|/*************************************************************************** Function: sGetTxCnt Purpose:  Get the number of data bytes in the Tx FIFO Call:	  sGetTxCnt(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Return:   Byte_t: The number of data bytes in the Tx FIFO. Comments: Byte read of count register is required to obtain Tx count.  */
end_comment

begin_define
define|#
directive|define
name|sGetTxCnt
parameter_list|(
name|ChP
parameter_list|)
value|sInB((ByteIO_t)(ChP)->TxRxCount)
end_define

begin_comment
comment|/***************************************************************************** Function: sGetTxRxDataIO Purpose:  Get the I/O address of a channel's TxRx Data register Call:	  sGetTxRxDataIO(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Return:   WordIO_t: I/O address of a channel's TxRx Data register */
end_comment

begin_define
define|#
directive|define
name|sGetTxRxDataIO
parameter_list|(
name|ChP
parameter_list|)
value|(ChP)->TxRxData
end_define

begin_comment
comment|/*************************************************************************** Function: sInitChanDefaults Purpose:  Initialize a channel structure to its default state. Call:	  sInitChanDefaults(ChP) 	  CHANNEL_T *ChP; Ptr to the channel structure Comments: This function must be called once for every channel structure 	  that exists before any other SSCI calls can be made.  */
end_comment

begin_define
define|#
directive|define
name|sInitChanDefaults
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->CtlP = NULLCTLPTR; \    (ChP)->AiopNum = NULLAIOP; \    (ChP)->ChanID = AIOPID_NULL; \    (ChP)->ChanNum = NULLCHAN; \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sResetAiopByNum Purpose:  Reset the AIOP by number Call:	  sResetAiopByNum(CTLP,AIOPNUM) 	CONTROLLER_T CTLP; Ptr to controller structure 	AIOPNUM; AIOP index */
end_comment

begin_define
define|#
directive|define
name|sResetAiopByNum
parameter_list|(
name|CTLP
parameter_list|,
name|AIOPNUM
parameter_list|)
define|\
value|{ \    sOutB((CTLP)->AiopIO[(AIOPNUM)]+_CMD_REG,RESET_ALL); \    sOutB((CTLP)->AiopIO[(AIOPNUM)]+_CMD_REG,0x0); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sSendBreak Purpose:  Send a transmit BREAK signal Call:	  sSendBreak(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sSendBreak
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[3] |= SETBREAK; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sSetBaud Purpose:  Set baud rate Call:	  sSetBaud(ChP,Divisor) 	  CHANNEL_T *ChP; Ptr to channel structure 	  Word_t Divisor; 16 bit baud rate divisor for channel */
end_comment

begin_define
define|#
directive|define
name|sSetBaud
parameter_list|(
name|ChP
parameter_list|,
name|DIVISOR
parameter_list|)
define|\
value|{ \    (ChP)->BaudDiv[2] = (Byte_t)(DIVISOR); \    (ChP)->BaudDiv[3] = (Byte_t)((DIVISOR)>> 8); \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->BaudDiv[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sSetData7 Purpose:  Set data bits to 7 Call:	  sSetData7(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sSetData7
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[2]&= ~DATA8BIT; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sSetData8 Purpose:  Set data bits to 8 Call:	  sSetData8(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sSetData8
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[2] |= DATA8BIT; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sSetDTR Purpose:  Set the DTR output Call:	  sSetDTR(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sSetDTR
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[3] |= SET_DTR; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sSetEvenParity Purpose:  Set even parity Call:	  sSetEvenParity(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Comments: Function sSetParity() can be used in place of functions sEnParity(), 	  sDisParity(), sSetOddParity(), and sSetEvenParity().  Warnings: This function has no effect unless parity is enabled with function 	  sEnParity(). */
end_comment

begin_define
define|#
directive|define
name|sSetEvenParity
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[2] |= EVEN_PAR; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sSetOddParity Purpose:  Set odd parity Call:	  sSetOddParity(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Comments: Function sSetParity() can be used in place of functions sEnParity(), 	  sDisParity(), sSetOddParity(), and sSetEvenParity().  Warnings: This function has no effect unless parity is enabled with function 	  sEnParity(). */
end_comment

begin_define
define|#
directive|define
name|sSetOddParity
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[2]&= ~EVEN_PAR; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sSetRTS Purpose:  Set the RTS output Call:	  sSetRTS(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sSetRTS
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[3] |= SET_RTS; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sSetRxTrigger Purpose:  Set the Rx FIFO trigger level Call:	  sSetRxProcessor(ChP,Level) 	  CHANNEL_T *ChP; Ptr to channel structure 	  Byte_t Level; Number of characters in Rx FIFO at which the 	     interrupt will be generated.  Can be any of the following flags:  	     TRIG_NO:	no trigger 	     TRIG_1:	1 character in FIFO 	     TRIG_1_2:	FIFO 1/2 full 	     TRIG_7_8:	FIFO 7/8 full Comments: An interrupt will be generated when the trigger level is reached 	  only if function sEnInterrupt() has been called with flag 	  RXINT_EN set.  The RXF_TRIG flag in the Interrupt Idenfification 	  register will be set whenever the trigger level is reached 	  regardless of the setting of RXINT_EN.  */
end_comment

begin_define
define|#
directive|define
name|sSetRxTrigger
parameter_list|(
name|ChP
parameter_list|,
name|LEVEL
parameter_list|)
define|\
value|{ \    (ChP)->RxControl[2]&= ~TRIG_MASK; \    (ChP)->RxControl[2] |= LEVEL; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->RxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sSetStop1 Purpose:  Set stop bits to 1 Call:	  sSetStop1(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sSetStop1
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[2]&= ~STOP2; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sSetStop2 Purpose:  Set stop bits to 2 Call:	  sSetStop2(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure */
end_comment

begin_define
define|#
directive|define
name|sSetStop2
parameter_list|(
name|ChP
parameter_list|)
define|\
value|{ \    (ChP)->TxControl[2] |= STOP2; \    sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->TxControl[0]); \ }
end_define

begin_comment
comment|/*************************************************************************** Function: sStartRxProcessor Purpose:  Start a channel's receive processor Call:	  sStartRxProcessor(ChP) 	  CHANNEL_T *ChP; Ptr to channel structure Comments: This function is used to start a Rx processor after it was 	  stopped with sStopRxProcessor() or sStopSWInFlowCtl().  It 	  will restart both the Rx processor and software input flow control.  */
end_comment

begin_define
define|#
directive|define
name|sStartRxProcessor
parameter_list|(
name|ChP
parameter_list|)
value|sOutDW((ChP)->IndexAddr,*(DWord_t *)&(ChP)->R[0])
end_define

begin_comment
comment|/*************************************************************************** Function: sWriteTxByte Purpose:  Write a transmit data byte to a channel. 	  ByteIO_t io: Channel transmit register I/O address.  This can 			   be obtained with sGetTxRxDataIO(). 	  Byte_t Data; The transmit data byte. Warnings: This function writes the data byte without checking to see if 	  sMaxTxSize is exceeded in the Tx FIFO. */
end_comment

begin_define
define|#
directive|define
name|sWriteTxByte
parameter_list|(
name|IO
parameter_list|,
name|DATA
parameter_list|)
value|sOutB(IO,DATA)
end_define

begin_function_decl
name|int
name|sInitController
parameter_list|(
name|CONTROLLER_T
modifier|*
name|CtlP
parameter_list|,
name|int
name|CtlNum
parameter_list|,
name|ByteIO_t
name|MudbacIO
parameter_list|,
name|ByteIO_t
modifier|*
name|AiopIOList
parameter_list|,
name|int
name|AiopIOListSize
parameter_list|,
name|int
name|IRQNum
parameter_list|,
name|Byte_t
name|Frequency
parameter_list|,
name|int
name|PeriodicOnly
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sPCIInitController
parameter_list|(
name|CONTROLLER_T
modifier|*
name|CtlP
parameter_list|,
name|int
name|CtlNum
parameter_list|,
name|ByteIO_t
modifier|*
name|AiopIOList
parameter_list|,
name|int
name|AiopIOListSize
parameter_list|,
name|int
name|IRQNum
parameter_list|,
name|Byte_t
name|Frequency
parameter_list|,
name|int
name|PeriodicOnly
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sReadAiopID
parameter_list|(
name|ByteIO_t
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sReadAiopNumChan
parameter_list|(
name|WordIO_t
name|io
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sInitChan
parameter_list|(
name|CONTROLLER_T
modifier|*
name|CtlP
parameter_list|,
name|CHANNEL_T
modifier|*
name|ChP
parameter_list|,
name|int
name|AiopNum
parameter_list|,
name|int
name|ChanNum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Byte_t
name|sGetRxErrStatus
parameter_list|(
name|CHANNEL_T
modifier|*
name|ChP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sStopRxProcessor
parameter_list|(
name|CHANNEL_T
modifier|*
name|ChP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sStopSWInFlowCtl
parameter_list|(
name|CHANNEL_T
modifier|*
name|ChP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sFlushRxFIFO
parameter_list|(
name|CHANNEL_T
modifier|*
name|ChP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sFlushTxFIFO
parameter_list|(
name|CHANNEL_T
modifier|*
name|ChP
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sWriteTxPrioByte
parameter_list|(
name|CHANNEL_T
modifier|*
name|ChP
parameter_list|,
name|Byte_t
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sEnInterrupts
parameter_list|(
name|CHANNEL_T
modifier|*
name|ChP
parameter_list|,
name|Word_t
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sDisInterrupts
parameter_list|(
name|CHANNEL_T
modifier|*
name|ChP
parameter_list|,
name|Word_t
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|ROCKET_C
end_ifndef

begin_decl_stmt
specifier|extern
name|Byte_t
name|R
index|[
name|RDATASIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CONTROLLER_T
name|sController
index|[
name|CTL_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Byte_t
name|sIRQMap
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Byte_t
name|sBitMapClrTbl
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Byte_t
name|sBitMapSetTbl
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

