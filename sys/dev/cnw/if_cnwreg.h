begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_cnwreg.h,v 1.3 2000/07/05 18:42:19 itojun Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Michael Eriksson.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* I/O area */
end_comment

begin_define
define|#
directive|define
name|CNW_IO_SIZE
value|0x10
end_define

begin_comment
comment|/* I/O area can be accessed via mapped memory too */
end_comment

begin_define
define|#
directive|define
name|CNW_IOM_ADDR
value|0x28000
end_define

begin_define
define|#
directive|define
name|CNW_IOM_SIZE
value|CNW_IO_SIZE
end_define

begin_define
define|#
directive|define
name|CNW_IOM_OFF
value|(CNW_IOM_ADDR - CNW_MEM_ADDR)
end_define

begin_comment
comment|/* I/O registers */
end_comment

begin_define
define|#
directive|define
name|CNW_REG_COR
value|0x0
end_define

begin_define
define|#
directive|define
name|CNW_COR_IENA
value|0x01
end_define

begin_comment
comment|/* Interrupt enable */
end_comment

begin_define
define|#
directive|define
name|CNW_COR_LVLREQ
value|0x40
end_define

begin_comment
comment|/* Keep high */
end_comment

begin_define
define|#
directive|define
name|CNW_REG_CCSR
value|0x2
end_define

begin_define
define|#
directive|define
name|CNW_REG_ASR
value|0x4
end_define

begin_define
define|#
directive|define
name|CNW_ASR_TXBA
value|0x01
end_define

begin_comment
comment|/* Trasmit buffer available */
end_comment

begin_define
define|#
directive|define
name|CNW_ASR_WOC
value|0x08
end_define

begin_comment
comment|/* Write Operation Complete */
end_comment

begin_define
define|#
directive|define
name|CNW_ASR_TXDN
value|0x20
end_define

begin_comment
comment|/* Transmit done */
end_comment

begin_define
define|#
directive|define
name|CNW_ASR_RXERR
value|0x40
end_define

begin_comment
comment|/* Receive error */
end_comment

begin_define
define|#
directive|define
name|CNW_ASR_RXRDY
value|0x80
end_define

begin_comment
comment|/* Packet received */
end_comment

begin_define
define|#
directive|define
name|CNW_REG_IOLOW
value|0x6
end_define

begin_define
define|#
directive|define
name|CNW_REG_IOHI
value|0x7
end_define

begin_define
define|#
directive|define
name|CNW_REG_IOCONTROL
value|0x8
end_define

begin_define
define|#
directive|define
name|CNW_REG_IMR
value|0xa
end_define

begin_define
define|#
directive|define
name|CNW_IMR_IENA
value|0x02
end_define

begin_comment
comment|/* Interrupt enable */
end_comment

begin_define
define|#
directive|define
name|CNW_IMR_RFU1
value|0x10
end_define

begin_comment
comment|/* RFU intr mask, keep high */
end_comment

begin_define
define|#
directive|define
name|CNW_REG_PMR
value|0xc
end_define

begin_define
define|#
directive|define
name|CNW_PMR_RESET
value|0x80
end_define

begin_define
define|#
directive|define
name|CNW_REG_DATA
value|0xf
end_define

begin_comment
comment|/* Mapped memory */
end_comment

begin_define
define|#
directive|define
name|CNW_MEM_ADDR
value|0x20000
end_define

begin_define
define|#
directive|define
name|CNW_MEM_SIZE
value|0x8000
end_define

begin_comment
comment|/* Extended I/O registers (memory mapped) */
end_comment

begin_define
define|#
directive|define
name|CNW_EREG_CB
value|0x100
end_define

begin_define
define|#
directive|define
name|CNW_EREG_ASCC
value|0x114
end_define

begin_define
define|#
directive|define
name|CNW_EREG_RSER
value|0x120
end_define

begin_define
define|#
directive|define
name|CNW_RSER_RXBIG
value|0x02
end_define

begin_define
define|#
directive|define
name|CNW_RSER_RXCRC
value|0x04
end_define

begin_define
define|#
directive|define
name|CNW_RSER_RXOVERRUN
value|0x08
end_define

begin_define
define|#
directive|define
name|CNW_RSER_RXOVERFLOW
value|0x10
end_define

begin_define
define|#
directive|define
name|CNW_RSER_RXERR
value|0x40
end_define

begin_define
define|#
directive|define
name|CNW_RSER_RXAVAIL
value|0x80
end_define

begin_define
define|#
directive|define
name|CNW_EREG_RSERW
value|0x124
end_define

begin_define
define|#
directive|define
name|CNW_EREG_TSER
value|0x130
end_define

begin_define
define|#
directive|define
name|CNW_TSER_RTRY
value|0x0f
end_define

begin_define
define|#
directive|define
name|CNW_TSER_TXERR
value|0x10
end_define

begin_define
define|#
directive|define
name|CNW_TSER_TXOK
value|0x20
end_define

begin_define
define|#
directive|define
name|CNW_TSER_TXNOAP
value|0x40
end_define

begin_define
define|#
directive|define
name|CNW_TSER_TXGU
value|0x80
end_define

begin_define
define|#
directive|define
name|CNW_TSER_ERROR
value|(CNW_TSER_TXERR | CNW_TSER_TXNOAP | \ 					 CNW_TSER_TXGU)
end_define

begin_define
define|#
directive|define
name|CNW_EREG_TSERW
value|0x134
end_define

begin_define
define|#
directive|define
name|CNW_EREG_TDP
value|0x140
end_define

begin_define
define|#
directive|define
name|CNW_EREG_LIF
value|0x14e
end_define

begin_define
define|#
directive|define
name|CNW_EREG_RDP
value|0x150
end_define

begin_define
define|#
directive|define
name|CNW_EREG_SPCQ
value|0x154
end_define

begin_define
define|#
directive|define
name|CNW_EREG_SPU
value|0x155
end_define

begin_define
define|#
directive|define
name|CNW_EREG_ISPLQ
value|0x156
end_define

begin_define
define|#
directive|define
name|CNW_EREG_HHC
value|0x158
end_define

begin_define
define|#
directive|define
name|CNW_EREG_PA
value|0x160
end_define

begin_define
define|#
directive|define
name|CNW_EREG_ARW
value|0x166
end_define

begin_define
define|#
directive|define
name|CNW_EREG_MHS
value|0x16b
end_define

begin_define
define|#
directive|define
name|CNW_EREG_NI
value|0x16e
end_define

begin_define
define|#
directive|define
name|CNW_EREG_CRBP
value|0x17a
end_define

begin_define
define|#
directive|define
name|CNW_EREG_EC
value|0x180
end_define

begin_define
define|#
directive|define
name|CNW_EREG_STAT_RXERR
value|0x184
end_define

begin_define
define|#
directive|define
name|CNW_EREG_STAT_FRAME
value|0x186
end_define

begin_define
define|#
directive|define
name|CNW_EREG_STAT_IBEAT
value|0x188
end_define

begin_define
define|#
directive|define
name|CNW_EREG_STAT_RXBUF
value|0x18e
end_define

begin_define
define|#
directive|define
name|CNW_EREG_STAT_RXMULTI
value|0x190
end_define

begin_define
define|#
directive|define
name|CNW_EREG_STAT_TXRETRY
value|0x192
end_define

begin_define
define|#
directive|define
name|CNW_EREG_STAT_TXABORT
value|0x194
end_define

begin_define
define|#
directive|define
name|CNW_EREG_STAT_OBEAT
value|0x198
end_define

begin_define
define|#
directive|define
name|CNW_EREG_STAT_TXOK
value|0x19a
end_define

begin_define
define|#
directive|define
name|CNW_EREG_STAT_TXSENT
value|0x19c
end_define

begin_comment
comment|/*  * Commands used in the extended command buffer  * CNW_EREG_CB (0x100-0x10f)   */
end_comment

begin_define
define|#
directive|define
name|CNW_CMD_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|CNW_CMD_SRC
value|0x01
end_define

begin_define
define|#
directive|define
name|CNW_RXCONF_RXENA
value|0x80
end_define

begin_comment
comment|/* Receive Enable */
end_comment

begin_define
define|#
directive|define
name|CNW_RXCONF_MAC
value|0x20
end_define

begin_comment
comment|/* MAC host receive mode */
end_comment

begin_define
define|#
directive|define
name|CNW_RXCONF_PRO
value|0x10
end_define

begin_comment
comment|/* Promiscuous */
end_comment

begin_define
define|#
directive|define
name|CNW_RXCONF_AMP
value|0x08
end_define

begin_comment
comment|/* Accept Multicast Packets */
end_comment

begin_define
define|#
directive|define
name|CNW_RXCONF_BCAST
value|0x04
end_define

begin_comment
comment|/* Accept Broadcast Packets */
end_comment

begin_define
define|#
directive|define
name|CNW_CMD_STC
value|0x02
end_define

begin_define
define|#
directive|define
name|CNW_TXCONF_TXENA
value|0x80
end_define

begin_comment
comment|/* Transmit Enable */
end_comment

begin_define
define|#
directive|define
name|CNW_TXCONF_MAC
value|0x20
end_define

begin_comment
comment|/* Host sends MAC mode */
end_comment

begin_define
define|#
directive|define
name|CNW_TXCONF_EUD
value|0x10
end_define

begin_comment
comment|/* Enable Uni-Data packets */
end_comment

begin_define
define|#
directive|define
name|CNW_TXCONF_KEY
value|0x02
end_define

begin_comment
comment|/* Scramble data packets */
end_comment

begin_define
define|#
directive|define
name|CNW_TXCONF_LOOP
value|0x01
end_define

begin_comment
comment|/* Loopback mode */
end_comment

begin_define
define|#
directive|define
name|CNW_CMD_AMA
value|0x03
end_define

begin_define
define|#
directive|define
name|CNW_CMD_DMA
value|0x04
end_define

begin_define
define|#
directive|define
name|CNW_CMD_SAMA
value|0x05
end_define

begin_define
define|#
directive|define
name|CNW_CMD_ER
value|0x06
end_define

begin_define
define|#
directive|define
name|CNW_CMD_DR
value|0x07
end_define

begin_define
define|#
directive|define
name|CNW_CMD_TL
value|0x08
end_define

begin_define
define|#
directive|define
name|CNW_CMD_SRP
value|0x09
end_define

begin_define
define|#
directive|define
name|CNW_CMD_SSK
value|0x0a
end_define

begin_define
define|#
directive|define
name|CNW_CMD_SMD
value|0x0b
end_define

begin_define
define|#
directive|define
name|CNW_CMD_SAPD
value|0x0c
end_define

begin_define
define|#
directive|define
name|CNW_CMD_SSS
value|0x11
end_define

begin_define
define|#
directive|define
name|CNW_CMD_EOC
value|0x00
end_define

begin_comment
comment|/* End-of-command marker */
end_comment

end_unit

