begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Paul Kranenburg.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: NetBSD: hmereg.h,v 1.7 2001/04/30 03:47:34 lukem Exp  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * HME Shared Ethernet Block register offsets  */
end_comment

begin_define
define|#
directive|define
name|HME_SEBI_RESET
value|(0*4)
end_define

begin_define
define|#
directive|define
name|HME_SEBI_CFG
value|(1*4)
end_define

begin_define
define|#
directive|define
name|HME_SEBI_STAT
value|(64*4)
end_define

begin_define
define|#
directive|define
name|HME_SEBI_IMASK
value|(65*4)
end_define

begin_comment
comment|/* HME SEB bits. */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_RESET_ETX
value|0x00000001
end_define

begin_comment
comment|/* reset external transmitter */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_RESET_ERX
value|0x00000002
end_define

begin_comment
comment|/* reset external receiver */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_CFG_BURSTMASK
value|0x00000003
end_define

begin_comment
comment|/* covers all burst bits */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_CFG_BURST16
value|0x00000000
end_define

begin_comment
comment|/* 16 byte bursts */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_CFG_BURST32
value|0x00000001
end_define

begin_comment
comment|/* 32 byte bursts */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_CFG_BURST64
value|0x00000002
end_define

begin_comment
comment|/* 64 byte bursts */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_CFG_64BIT
value|0x00000004
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_CFG_PARITY
value|0x00000008
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_GOTFRAME
value|0x00000001
end_define

begin_comment
comment|/* frame received */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_RCNTEXP
value|0x00000002
end_define

begin_comment
comment|/* rx frame count expired */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_ACNTEXP
value|0x00000004
end_define

begin_comment
comment|/* align error count expired */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_CCNTEXP
value|0x00000008
end_define

begin_comment
comment|/* crc error count expired */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_LCNTEXP
value|0x00000010
end_define

begin_comment
comment|/* length error count expired */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_RFIFOVF
value|0x00000020
end_define

begin_comment
comment|/* rx fifo overflow */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_CVCNTEXP
value|0x00000040
end_define

begin_comment
comment|/* code violation counter exp */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_STSTERR
value|0x00000080
end_define

begin_comment
comment|/* xif sqe test failed */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_SENTFRAME
value|0x00000100
end_define

begin_comment
comment|/* frame sent */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_TFIFO_UND
value|0x00000200
end_define

begin_comment
comment|/* tx fifo underrun */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_MAXPKTERR
value|0x00000400
end_define

begin_comment
comment|/* max-packet size error */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_NCNTEXP
value|0x00000800
end_define

begin_comment
comment|/* normal collision count exp */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_ECNTEXP
value|0x00001000
end_define

begin_comment
comment|/* excess collision count exp */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_LCCNTEXP
value|0x00002000
end_define

begin_comment
comment|/* late collision count exp */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_FCNTEXP
value|0x00004000
end_define

begin_comment
comment|/* first collision count exp */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_DTIMEXP
value|0x00008000
end_define

begin_comment
comment|/* defer timer expired */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_RXTOHOST
value|0x00010000
end_define

begin_comment
comment|/* pkt moved from rx fifo->memory */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_NORXD
value|0x00020000
end_define

begin_comment
comment|/* out of receive descriptors */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_RXERR
value|0x00040000
end_define

begin_comment
comment|/* rx dma error */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_RXLATERR
value|0x00080000
end_define

begin_comment
comment|/* late error during rx dma */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_RXPERR
value|0x00100000
end_define

begin_comment
comment|/* parity error during rx dma */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_RXTERR
value|0x00200000
end_define

begin_comment
comment|/* tag error during rx dma */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_EOPERR
value|0x00400000
end_define

begin_comment
comment|/* tx descriptor did not set EOP */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_MIFIRQ
value|0x00800000
end_define

begin_comment
comment|/* mif needs attention */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_HOSTTOTX
value|0x01000000
end_define

begin_comment
comment|/* pkt moved from memory->tx fifo */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_TXALL
value|0x02000000
end_define

begin_comment
comment|/* all pkts in fifo transmitted */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_TXEACK
value|0x04000000
end_define

begin_comment
comment|/* error during tx dma */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_TXLERR
value|0x08000000
end_define

begin_comment
comment|/* late error during tx dma */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_TXPERR
value|0x10000000
end_define

begin_comment
comment|/* parity error during tx dma */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_TXTERR
value|0x20000000
end_define

begin_comment
comment|/* tag error durig tx dma */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_SLVERR
value|0x40000000
end_define

begin_comment
comment|/* pio access error */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_SLVPERR
value|0x80000000
end_define

begin_comment
comment|/* pio access parity error */
end_comment

begin_define
define|#
directive|define
name|HME_SEB_STAT_BITS
value|"\177\020"				\ 			"b\0GOTFRAME\0b\1RCNTEXP\0b\2ACNTEXP\0"		\ 			"b\3CCNTEXP\0b\4LCNTEXP\0b\5RFIFOVF\0"		\ 			"b\6CVCNTEXP\0b\7STSTERR\0b\10SENTFRAME\0"	\ 			"b\11TFIFO_UND\0b\12MAXPKTERR\0b\13NCNTEXP\0"	\ 			"b\14ECNTEXP\0b\15LCCNTEXP\0b\16FCNTEXP\0"	\ 			"b\17DTIMEXP\0b\20RXTOHOST\0b\21NORXD\0"	\ 			"b\22RXERR\0b\23RXLATERR\0b\24RXPERR\0"		\ 			"b\25RXTERR\0b\26EOPERR\0b\27MIFIRQ\0"		\ 			"b\30HOSTTOTX\0b\31TXALL\0b\32XTEACK\0"		\ 			"b\33TXLERR\0b\34TXPERR\0b\35TXTERR\0"		\ 			"b\36SLVERR\0b\37SLVPERR\0\0"
end_define

begin_define
define|#
directive|define
name|HME_SEB_STAT_ALL_ERRORS
define|\
value|(HME_SEB_STAT_SLVPERR  | HME_SEB_STAT_SLVERR  | HME_SEB_STAT_TXTERR   |\ 	 HME_SEB_STAT_TXPERR   | HME_SEB_STAT_TXLERR  | HME_SEB_STAT_TXEACK   |\ 	 HME_SEB_STAT_EOPERR   | HME_SEB_STAT_RXTERR  | HME_SEB_STAT_RXPERR   |\ 	 HME_SEB_STAT_RXLATERR | HME_SEB_STAT_RXERR   | HME_SEB_STAT_NORXD    |\ 	 HME_SEB_STAT_DTIMEXP  | HME_SEB_STAT_FCNTEXP | HME_SEB_STAT_LCCNTEXP |\ 	 HME_SEB_STAT_ECNTEXP  | HME_SEB_STAT_NCNTEXP | HME_SEB_STAT_MAXPKTERR|\ 	 HME_SEB_STAT_TFIFO_UND| HME_SEB_STAT_STSTERR | HME_SEB_STAT_CVCNTEXP |\ 	 HME_SEB_STAT_RFIFOVF  | HME_SEB_STAT_LCNTEXP | HME_SEB_STAT_CCNTEXP  |\ 	 HME_SEB_STAT_ACNTEXP)
end_define

begin_define
define|#
directive|define
name|HME_SEB_STAT_VLAN_ERRORS
define|\
value|(HME_SEB_STAT_SLVPERR  | HME_SEB_STAT_SLVERR  | HME_SEB_STAT_TXTERR   |\ 	 HME_SEB_STAT_TXPERR   | HME_SEB_STAT_TXLERR  | HME_SEB_STAT_TXEACK   |\ 	 HME_SEB_STAT_EOPERR   | HME_SEB_STAT_RXTERR  | HME_SEB_STAT_RXPERR   |\ 	 HME_SEB_STAT_RXLATERR | HME_SEB_STAT_RXERR   | HME_SEB_STAT_NORXD    |\ 	 HME_SEB_STAT_DTIMEXP  | HME_SEB_STAT_FCNTEXP | HME_SEB_STAT_LCCNTEXP |\ 	 HME_SEB_STAT_ECNTEXP  | HME_SEB_STAT_NCNTEXP |                        \ 	 HME_SEB_STAT_TFIFO_UND| HME_SEB_STAT_STSTERR | HME_SEB_STAT_CVCNTEXP |\ 	 HME_SEB_STAT_RFIFOVF  | HME_SEB_STAT_LCNTEXP | HME_SEB_STAT_CCNTEXP  |\ 	 HME_SEB_STAT_ACNTEXP)
end_define

begin_comment
comment|/*  * HME Transmitter register offsets  */
end_comment

begin_define
define|#
directive|define
name|HME_ETXI_PENDING
value|(0*4)
end_define

begin_comment
comment|/* Pending/wakeup */
end_comment

begin_define
define|#
directive|define
name|HME_ETXI_CFG
value|(1*4)
end_define

begin_define
define|#
directive|define
name|HME_ETXI_RING
value|(2*4)
end_define

begin_comment
comment|/* Descriptor Ring pointer */
end_comment

begin_define
define|#
directive|define
name|HME_ETXI_BBASE
value|(3*4)
end_define

begin_comment
comment|/* Buffer base address (ro) */
end_comment

begin_define
define|#
directive|define
name|HME_ETXI_BDISP
value|(4*4)
end_define

begin_comment
comment|/* Buffer displacement (ro) */
end_comment

begin_define
define|#
directive|define
name|HME_ETXI_FIFO_WPTR
value|(5*4)
end_define

begin_comment
comment|/* FIFO write pointer */
end_comment

begin_define
define|#
directive|define
name|HME_ETXI_FIFO_SWPTR
value|(6*4)
end_define

begin_comment
comment|/* FIFO shadow write pointer */
end_comment

begin_define
define|#
directive|define
name|HME_ETXI_FIFO_RPTR
value|(7*4)
end_define

begin_comment
comment|/* FIFO read pointer */
end_comment

begin_define
define|#
directive|define
name|HME_ETXI_FIFO_SRPTR
value|(8*4)
end_define

begin_comment
comment|/* FIFO shadow read pointer */
end_comment

begin_define
define|#
directive|define
name|HME_ETXI_FIFO_PKTCNT
value|(9*4)
end_define

begin_comment
comment|/* FIFO packet counter */
end_comment

begin_define
define|#
directive|define
name|HME_ETXI_STATEMACHINE
value|(10*4)
end_define

begin_comment
comment|/* State machine */
end_comment

begin_define
define|#
directive|define
name|HME_ETXI_RSIZE
value|(11*4)
end_define

begin_comment
comment|/* Ring size */
end_comment

begin_define
define|#
directive|define
name|HME_ETXI_BPTR
value|(12*4)
end_define

begin_comment
comment|/* Buffer pointer */
end_comment

begin_comment
comment|/* TXI_PENDING bits */
end_comment

begin_define
define|#
directive|define
name|HME_ETX_TP_DMAWAKEUP
value|0x00000001
end_define

begin_comment
comment|/* Start tx (rw, auto-clear) */
end_comment

begin_comment
comment|/* TXI_CFG bits */
end_comment

begin_define
define|#
directive|define
name|HME_ETX_CFG_DMAENABLE
value|0x00000001
end_define

begin_comment
comment|/* Enable TX dma */
end_comment

begin_define
define|#
directive|define
name|HME_ETX_CFG_FIFOTHRESH
value|0x000003fe
end_define

begin_comment
comment|/* TX fifo threshold */
end_comment

begin_define
define|#
directive|define
name|HME_ETX_CFG_IRQDAFTER
value|0x00000400
end_define

begin_comment
comment|/* Intr after tx-fifo empty */
end_comment

begin_define
define|#
directive|define
name|HME_ETX_CFG_IRQDBEFORE
value|0x00000000
end_define

begin_comment
comment|/* Intr before tx-fifo empty */
end_comment

begin_comment
comment|/*  * HME Receiver register offsets  */
end_comment

begin_define
define|#
directive|define
name|HME_ERXI_CFG
value|(0*4)
end_define

begin_define
define|#
directive|define
name|HME_ERXI_RING
value|(1*4)
end_define

begin_comment
comment|/* Descriptor Ring pointer */
end_comment

begin_define
define|#
directive|define
name|HME_ERXI_BPTR
value|(2*4)
end_define

begin_comment
comment|/* Data Buffer pointer (ro) */
end_comment

begin_define
define|#
directive|define
name|HME_ERXI_FIFO_WPTR
value|(3*4)
end_define

begin_comment
comment|/* FIFO write pointer */
end_comment

begin_define
define|#
directive|define
name|HME_ERXI_FIFO_SWPTR
value|(4*4)
end_define

begin_comment
comment|/* FIFO shadow write pointer */
end_comment

begin_define
define|#
directive|define
name|HME_ERXI_FIFO_RPTR
value|(5*4)
end_define

begin_comment
comment|/* FIFO read pointer */
end_comment

begin_define
define|#
directive|define
name|HME_ERXI_FIFO_SRPTR
value|(6*4)
end_define

begin_comment
comment|/* FIFO shadow read pointer */
end_comment

begin_define
define|#
directive|define
name|HME_ERXI_STATEMACHINE
value|(7*4)
end_define

begin_comment
comment|/* State machine */
end_comment

begin_comment
comment|/* RXI_CFG bits */
end_comment

begin_define
define|#
directive|define
name|HME_ERX_CFG_DMAENABLE
value|0x00000001
end_define

begin_comment
comment|/* Enable RX dma */
end_comment

begin_define
define|#
directive|define
name|HME_ERX_CFG_FBO_MASK
value|0x00000038
end_define

begin_comment
comment|/* RX first byte offset */
end_comment

begin_define
define|#
directive|define
name|HME_ERX_CFG_FBO_SHIFT
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HME_ERX_CFG_RINGSIZE32
value|0x00000000
end_define

begin_comment
comment|/* Descriptor ring size: 32 */
end_comment

begin_define
define|#
directive|define
name|HME_ERX_CFG_RINGSIZE64
value|0x00000200
end_define

begin_comment
comment|/* Descriptor ring size: 64 */
end_comment

begin_define
define|#
directive|define
name|HME_ERX_CFG_RINGSIZE128
value|0x00000400
end_define

begin_comment
comment|/* Descriptor ring size: 128 */
end_comment

begin_define
define|#
directive|define
name|HME_ERX_CFG_RINGSIZE256
value|0x00000600
end_define

begin_comment
comment|/* Descriptor ring size: 256 */
end_comment

begin_define
define|#
directive|define
name|HME_ERX_CFG_RINGSIZEMSK
value|0x00000600
end_define

begin_comment
comment|/* Descriptor ring size: 256 */
end_comment

begin_define
define|#
directive|define
name|HME_ERX_CFG_CSUMSTART
value|0x007f0000
end_define

begin_comment
comment|/* cksum offset */
end_comment

begin_comment
comment|/*  * HME MAC-core register offsets  */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_XIF
value|(0*4)
end_define

begin_define
define|#
directive|define
name|HME_MACI_TXSWRST
value|(130*4)
end_define

begin_comment
comment|/* TX reset */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_TXCFG
value|(131*4)
end_define

begin_comment
comment|/* TX config */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_JSIZE
value|(139*4)
end_define

begin_comment
comment|/* TX jam size */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_TXSIZE
value|(140*4)
end_define

begin_comment
comment|/* TX max size */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_NCCNT
value|(144*4)
end_define

begin_comment
comment|/* TX normal collision cnt */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_FCCNT
value|(145*4)
end_define

begin_comment
comment|/* TX first collision cnt */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_EXCNT
value|(146*4)
end_define

begin_comment
comment|/* TX excess collision cnt */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_LTCNT
value|(147*4)
end_define

begin_comment
comment|/* TX late collision cnt */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_RANDSEED
value|(148*4)
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_RXSWRST
value|(194*4)
end_define

begin_comment
comment|/* RX reset */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_RXCFG
value|(195*4)
end_define

begin_comment
comment|/* RX config */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_RXSIZE
value|(196*4)
end_define

begin_comment
comment|/* RX max size */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_MACADDR2
value|(198*4)
end_define

begin_comment
comment|/* MAC address */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_MACADDR1
value|(199*4)
end_define

begin_define
define|#
directive|define
name|HME_MACI_MACADDR0
value|(200*4)
end_define

begin_define
define|#
directive|define
name|HME_MACI_HASHTAB3
value|(208*4)
end_define

begin_comment
comment|/* Address hash table */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_HASHTAB2
value|(209*4)
end_define

begin_define
define|#
directive|define
name|HME_MACI_HASHTAB1
value|(210*4)
end_define

begin_define
define|#
directive|define
name|HME_MACI_HASHTAB0
value|(211*4)
end_define

begin_define
define|#
directive|define
name|HME_MACI_AFILTER2
value|(212*4)
end_define

begin_comment
comment|/* Address filter */
end_comment

begin_define
define|#
directive|define
name|HME_MACI_AFILTER1
value|(213*4)
end_define

begin_define
define|#
directive|define
name|HME_MACI_AFILTER0
value|(214*4)
end_define

begin_define
define|#
directive|define
name|HME_MACI_AFILTER_MASK
value|(215*4)
end_define

begin_comment
comment|/* XIF config register. */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_XIF_OE
value|0x00000001
end_define

begin_comment
comment|/* Output driver enable */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_XIF_XLBACK
value|0x00000002
end_define

begin_comment
comment|/* Loopback-mode XIF enable */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_XIF_MLBACK
value|0x00000004
end_define

begin_comment
comment|/* Loopback-mode MII enable */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_XIF_MIIENABLE
value|0x00000008
end_define

begin_comment
comment|/* MII receive buffer enable */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_XIF_SQENABLE
value|0x00000010
end_define

begin_comment
comment|/* SQE test enable */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_XIF_SQETWIN
value|0x000003e0
end_define

begin_comment
comment|/* SQE time window */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_XIF_LANCE
value|0x00000010
end_define

begin_comment
comment|/* Lance mode enable */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_XIF_LIPG0
value|0x000003e0
end_define

begin_comment
comment|/* Lance mode IPG0 */
end_comment

begin_comment
comment|/* Transmit config register. */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_TXCFG_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* Enable the transmitter */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_TXCFG_SMODE
value|0x00000020
end_define

begin_comment
comment|/* Enable slow transmit mode */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_TXCFG_CIGN
value|0x00000040
end_define

begin_comment
comment|/* Ignore transmit collisions */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_TXCFG_FCSOFF
value|0x00000080
end_define

begin_comment
comment|/* Do not emit FCS */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_TXCFG_DBACKOFF
value|0x00000100
end_define

begin_comment
comment|/* Disable backoff */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_TXCFG_FULLDPLX
value|0x00000200
end_define

begin_comment
comment|/* Enable full-duplex */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_TXCFG_DGIVEUP
value|0x00000400
end_define

begin_comment
comment|/* Don't give up on transmits */
end_comment

begin_comment
comment|/* Receive config register. */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_RXCFG_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* Enable the receiver */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_RXCFG_PSTRIP
value|0x00000020
end_define

begin_comment
comment|/* Pad byte strip enable */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_RXCFG_PMISC
value|0x00000040
end_define

begin_comment
comment|/* Enable promiscous mode */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_RXCFG_DERR
value|0x00000080
end_define

begin_comment
comment|/* Disable error checking */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_RXCFG_DCRCS
value|0x00000100
end_define

begin_comment
comment|/* Disable CRC stripping */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_RXCFG_ME
value|0x00000200
end_define

begin_comment
comment|/* Receive packets addressed to me */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_RXCFG_PGRP
value|0x00000400
end_define

begin_comment
comment|/* Enable promisc group mode */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_RXCFG_HENABLE
value|0x00000800
end_define

begin_comment
comment|/* Enable the hash filter */
end_comment

begin_define
define|#
directive|define
name|HME_MAC_RXCFG_AENABLE
value|0x00001000
end_define

begin_comment
comment|/* Enable the address filter */
end_comment

begin_comment
comment|/*  * HME MIF register offsets  */
end_comment

begin_define
define|#
directive|define
name|HME_MIFI_BB_CLK
value|(0*4)
end_define

begin_comment
comment|/* bit-bang clock */
end_comment

begin_define
define|#
directive|define
name|HME_MIFI_BB_DATA
value|(1*4)
end_define

begin_comment
comment|/* bit-bang data */
end_comment

begin_define
define|#
directive|define
name|HME_MIFI_BB_OE
value|(2*4)
end_define

begin_comment
comment|/* bit-bang output enable */
end_comment

begin_define
define|#
directive|define
name|HME_MIFI_FO
value|(3*4)
end_define

begin_comment
comment|/* frame output */
end_comment

begin_define
define|#
directive|define
name|HME_MIFI_CFG
value|(4*4)
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|HME_MIFI_IMASK
value|(5*4)
end_define

begin_comment
comment|/* Interrupt mask for status change */
end_comment

begin_define
define|#
directive|define
name|HME_MIFI_STAT
value|(6*4)
end_define

begin_comment
comment|/* Status (ro, auto-clear) */
end_comment

begin_define
define|#
directive|define
name|HME_MIFI_SM
value|(7*4)
end_define

begin_comment
comment|/* State machine (ro) */
end_comment

begin_comment
comment|/* MIF Configuration register */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_CFG_PHY
value|0x00000001
end_define

begin_comment
comment|/* PHY select */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_CFG_PE
value|0x00000002
end_define

begin_comment
comment|/* Poll enable */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_CFG_BBMODE
value|0x00000004
end_define

begin_comment
comment|/* Bit-bang mode */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_CFG_PRADDR
value|0x000000f8
end_define

begin_comment
comment|/* Poll register adddress */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_CFG_MDI0
value|0x00000100
end_define

begin_comment
comment|/* MDI_0 (ro) */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_CFG_MDI1
value|0x00000200
end_define

begin_comment
comment|/* MDI_1 (ro) */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_CFG_PPADDR
value|0x00007c00
end_define

begin_comment
comment|/* Poll phy adddress */
end_comment

begin_comment
comment|/* MIF Frame/Output register */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_FO_ST
value|0xc0000000
end_define

begin_comment
comment|/* Start of frame */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_FO_ST_SHIFT
value|30
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_FO_OPC
value|0x30000000
end_define

begin_comment
comment|/* Opcode */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_FO_OPC_SHIFT
value|28
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_FO_PHYAD
value|0x0f800000
end_define

begin_comment
comment|/* PHY Address */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_FO_PHYAD_SHIFT
value|23
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_FO_REGAD
value|0x007c0000
end_define

begin_comment
comment|/* Register Address */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_FO_REGAD_SHIFT
value|18
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_FO_TAMSB
value|0x00020000
end_define

begin_comment
comment|/* Turn-around MSB */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_FO_TALSB
value|0x00010000
end_define

begin_comment
comment|/* Turn-around LSB */
end_comment

begin_define
define|#
directive|define
name|HME_MIF_FO_DATA
value|0x0000ffff
end_define

begin_comment
comment|/* data to read or write */
end_comment

begin_comment
comment|/* Wired HME PHY addresses */
end_comment

begin_define
define|#
directive|define
name|HME_PHYAD_INTERNAL
value|1
end_define

begin_define
define|#
directive|define
name|HME_PHYAD_EXTERNAL
value|0
end_define

begin_comment
comment|/*  * Buffer Descriptors.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_struct
struct|struct
name|hme_xd
block|{
specifier|volatile
name|u_int32_t
name|xd_flags
decl_stmt|;
specifier|volatile
name|u_int32_t
name|xd_addr
decl_stmt|;
comment|/* Buffer address (DMA) */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HME_XD_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|HME_XD_FLAGS
parameter_list|(
name|base
parameter_list|,
name|index
parameter_list|)
value|((base) + ((index) * HME_XD_SIZE) + 0)
end_define

begin_define
define|#
directive|define
name|HME_XD_ADDR
parameter_list|(
name|base
parameter_list|,
name|index
parameter_list|)
value|((base) + ((index) * HME_XD_SIZE) + 4)
end_define

begin_define
define|#
directive|define
name|HME_XD_GETFLAGS
parameter_list|(
name|p
parameter_list|,
name|b
parameter_list|,
name|i
parameter_list|)
define|\
value|((p) ? le32toh(*((u_int32_t *)HME_XD_FLAGS(b,i))) :		\ 		(*((u_int32_t *)HME_XD_FLAGS(b,i))))
end_define

begin_define
define|#
directive|define
name|HME_XD_SETFLAGS
parameter_list|(
name|p
parameter_list|,
name|b
parameter_list|,
name|i
parameter_list|,
name|f
parameter_list|)
value|do {				\ 	*((u_int32_t *)HME_XD_FLAGS(b,i)) = ((p) ? htole32(f) : (f));	\ } while(0)
end_define

begin_define
define|#
directive|define
name|HME_XD_SETADDR
parameter_list|(
name|p
parameter_list|,
name|b
parameter_list|,
name|i
parameter_list|,
name|a
parameter_list|)
value|do {				\ 	*((u_int32_t *)HME_XD_ADDR(b,i)) = ((p) ? htole32(a) : (a));	\ } while(0)
end_define

begin_comment
comment|/* Descriptor flag values */
end_comment

begin_define
define|#
directive|define
name|HME_XD_OWN
value|0x80000000
end_define

begin_comment
comment|/* ownership: 1=hw, 0=sw */
end_comment

begin_define
define|#
directive|define
name|HME_XD_SOP
value|0x40000000
end_define

begin_comment
comment|/* start of packet marker (tx) */
end_comment

begin_define
define|#
directive|define
name|HME_XD_OFL
value|0x40000000
end_define

begin_comment
comment|/* buffer overflow (rx) */
end_comment

begin_define
define|#
directive|define
name|HME_XD_EOP
value|0x20000000
end_define

begin_comment
comment|/* end of packet marker (tx) */
end_comment

begin_define
define|#
directive|define
name|HME_XD_TXCKSUM
value|0x10000000
end_define

begin_comment
comment|/* checksum enable (tx) */
end_comment

begin_define
define|#
directive|define
name|HME_XD_RXLENMSK
value|0x3fff0000
end_define

begin_comment
comment|/* packet length mask (rx) */
end_comment

begin_define
define|#
directive|define
name|HME_XD_RXLENSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HME_XD_TXLENMSK
value|0x00003fff
end_define

begin_comment
comment|/* packet length mask (tx) */
end_comment

begin_define
define|#
directive|define
name|HME_XD_RXCKSUM
value|0x0000ffff
end_define

begin_comment
comment|/* packet checksum (rx) */
end_comment

begin_comment
comment|/* Macros to encode/decode the receive buffer size from the flags field */
end_comment

begin_define
define|#
directive|define
name|HME_XD_ENCODE_RSIZE
parameter_list|(
name|sz
parameter_list|)
define|\
value|(((sz)<< HME_XD_RXLENSHIFT)& HME_XD_RXLENMSK)
end_define

begin_define
define|#
directive|define
name|HME_XD_DECODE_RSIZE
parameter_list|(
name|flags
parameter_list|)
define|\
value|(((flags)& HME_XD_RXLENMSK)>> HME_XD_RXLENSHIFT)
end_define

begin_comment
comment|/* Provide encode/decode macros for the transmit buffers for symmetry */
end_comment

begin_define
define|#
directive|define
name|HME_XD_ENCODE_TSIZE
parameter_list|(
name|sz
parameter_list|)
define|\
value|(((sz)<< 0)& HME_XD_TXLENMSK)
end_define

begin_define
define|#
directive|define
name|HME_XD_DECODE_TSIZE
parameter_list|(
name|flags
parameter_list|)
define|\
value|(((flags)& HME_XD_TXLENMSK)>> 0)
end_define

begin_define
define|#
directive|define
name|PCI_HME_BASEADDR
value|0x10
end_define

end_unit

