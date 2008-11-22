begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: z8530reg.h,v 1.8 1996/12/13 21:02:39 gwr Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)zsreg.h	8.1 (Berkeley) 6/11/93  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Zilog SCC registers, as implemented on the Sun-4c.  *  * Each Z8530 implements two channels (called `a' and `b').  *  * The damnable chip was designed to fit on Z80 I/O ports, and thus  * has everything multiplexed out the wazoo.  We have to select  * a register, then read or write the register, and so on.  Worse,  * the parameter bits are scattered all over the register space.  * This thing is full of `miscellaneous' control registers.  *  * Worse yet, the registers have incompatible functions on read  * and write operations.  We describe the registers below according  * to whether they are `read registers' (RR) or `write registers' (WR).  * As if this were not enough, some of the channel B status bits show  * up in channel A, and vice versa.  The blasted thing shares write  * registers 2 and 9 across both channels, and reads registers 2 and 3  * differently for the two channels.  We can, however, ignore this much  * of the time.  *  * This file also includes flags for the Z85C30 and Z85230 enhanced scc.  * The CMOS 8530 includes extra SDLC functionality, and is used in a  * number of Macs (often in the Z85C80, an 85C30 combined w/ a SCSI  * controller). -wrs  *  * Some of the names in this files were chosen to make the hsis driver  * work unchanged (which means that they will match some in SunOS).  *  * `S.C.' stands for Special Condition, which is any of these:  *	receiver overrun	(aka silo overflow)  *	framing error		(missing stop bit, etc)  *	end of frame		(in synchronous modes)  *	parity error		(when `parity error is S.C.' is set)  *  * Registers with only a single `numeric value' get a name.  * Other registers hold bits and are only numbered; the bit  * definitions imply the register number (see below).  *  * We never use the receive and transmit data registers as  * indirects (choosing instead the zc_data register), so they  * are not defined here.  */
end_comment

begin_define
define|#
directive|define
name|ZS_NCHAN
value|2
end_define

begin_define
define|#
directive|define
name|ZSRR_IVEC
value|2
end_define

begin_comment
comment|/* interrupt vector (channel 0) */
end_comment

begin_define
define|#
directive|define
name|ZSRR_IPEND
value|3
end_define

begin_comment
comment|/* interrupt pending (ch. 0 only) */
end_comment

begin_define
define|#
directive|define
name|ZSRR_TXSYNC
value|6
end_define

begin_comment
comment|/* sync transmit char (monosync mode) */
end_comment

begin_define
define|#
directive|define
name|ZSRR_RXSYNC
value|7
end_define

begin_comment
comment|/* sync receive char (monosync mode) */
end_comment

begin_define
define|#
directive|define
name|ZSRR_SYNCLO
value|6
end_define

begin_comment
comment|/* sync low byte (bisync mode) */
end_comment

begin_define
define|#
directive|define
name|ZSRR_SYNCHI
value|7
end_define

begin_comment
comment|/* sync high byte (bisync mode) */
end_comment

begin_define
define|#
directive|define
name|ZSRR_SDLC_ADDR
value|6
end_define

begin_comment
comment|/* SDLC address (SDLC mode) */
end_comment

begin_define
define|#
directive|define
name|ZSRR_SDLC_FLAG
value|7
end_define

begin_comment
comment|/* SDLC flag 0x7E (SDLC mode) */
end_comment

begin_define
define|#
directive|define
name|ZSRR_BAUDLO
value|12
end_define

begin_comment
comment|/* baud rate generator (low half) */
end_comment

begin_define
define|#
directive|define
name|ZSRR_BAUDHI
value|13
end_define

begin_comment
comment|/* baud rate generator (high half) */
end_comment

begin_define
define|#
directive|define
name|ZSRR_ENHANCED
value|14
end_define

begin_comment
comment|/* read address of WR7' - yes, it's not 7!*/
end_comment

begin_define
define|#
directive|define
name|ZSWR_IVEC
value|2
end_define

begin_comment
comment|/* interrupt vector (shared) */
end_comment

begin_define
define|#
directive|define
name|ZSWR_TXSYNC
value|6
end_define

begin_comment
comment|/* sync transmit char (monosync mode) */
end_comment

begin_define
define|#
directive|define
name|ZSWR_RXSYNC
value|7
end_define

begin_comment
comment|/* sync receive char (monosync mode) */
end_comment

begin_define
define|#
directive|define
name|ZSWR_SYNCLO
value|6
end_define

begin_comment
comment|/* sync low byte (bisync mode) */
end_comment

begin_define
define|#
directive|define
name|ZSWR_SYNCHI
value|7
end_define

begin_comment
comment|/* sync high byte (bisync mode) */
end_comment

begin_define
define|#
directive|define
name|ZSWR_SDLC_ADDR
value|6
end_define

begin_comment
comment|/* SDLC address (SDLC mode) */
end_comment

begin_define
define|#
directive|define
name|ZSWR_SDLC_FLAG
value|7
end_define

begin_comment
comment|/* SDLC flag 0x7E (SDLC mode) */
end_comment

begin_define
define|#
directive|define
name|ZSWR_BAUDLO
value|12
end_define

begin_comment
comment|/* baud rate generator (low half) */
end_comment

begin_define
define|#
directive|define
name|ZSWR_BAUDHI
value|13
end_define

begin_comment
comment|/* baud rate generator (high half) */
end_comment

begin_define
define|#
directive|define
name|ZSWR_ENHANCED
value|7
end_define

begin_comment
comment|/* write address of WR7' */
end_comment

begin_comment
comment|/*  * Registers 0 through 7 may be written with any one of the 8 command  * modifiers, and/or any one of the 4 reset modifiers, defined below.  * To write registers 8 through 15, however, the command modifier must  * always be `point high'.  Rather than track this bizzareness all over  * the driver, we try to avoid using any modifiers, ever (but they are  * defined here if you want them).  */
end_comment

begin_define
define|#
directive|define
name|ZSM_RESET_TXUEOM
value|0xc0
end_define

begin_comment
comment|/* reset xmit underrun / eom latch */
end_comment

begin_define
define|#
directive|define
name|ZSM_RESET_TXCRC
value|0x80
end_define

begin_comment
comment|/* reset xmit crc generator */
end_comment

begin_define
define|#
directive|define
name|ZSM_RESET_RXCRC
value|0x40
end_define

begin_comment
comment|/* reset recv crc checker */
end_comment

begin_define
define|#
directive|define
name|ZSM_NULL
value|0x00
end_define

begin_comment
comment|/* nothing special */
end_comment

begin_define
define|#
directive|define
name|ZSM_RESET_IUS
value|0x38
end_define

begin_comment
comment|/* reset interrupt under service */
end_comment

begin_define
define|#
directive|define
name|ZSM_RESET_ERR
value|0x30
end_define

begin_comment
comment|/* reset error cond */
end_comment

begin_define
define|#
directive|define
name|ZSM_RESET_TXINT
value|0x28
end_define

begin_comment
comment|/* reset xmit interrupt pending */
end_comment

begin_define
define|#
directive|define
name|ZSM_EI_NEXTRXC
value|0x20
end_define

begin_comment
comment|/* enable int. on next rcvd char */
end_comment

begin_define
define|#
directive|define
name|ZSM_SEND_ABORT
value|0x18
end_define

begin_comment
comment|/* send abort (SDLC) */
end_comment

begin_define
define|#
directive|define
name|ZSM_RESET_STINT
value|0x10
end_define

begin_comment
comment|/* reset external/status interrupt */
end_comment

begin_define
define|#
directive|define
name|ZSM_POINTHIGH
value|0x08
end_define

begin_comment
comment|/* `point high' (use r8-r15) */
end_comment

begin_define
define|#
directive|define
name|ZSM_NULL
value|0x00
end_define

begin_comment
comment|/* nothing special */
end_comment

begin_comment
comment|/*  * Commands for Write Register 0 (`Command Register').  * These are just the command modifiers or'ed with register number 0  * (which of course equals the command modifier).  */
end_comment

begin_define
define|#
directive|define
name|ZSWR0_RESET_EOM
value|ZSM_RESET_TXUEOM
end_define

begin_define
define|#
directive|define
name|ZSWR0_RESET_TXCRC
value|ZSM_RESET_TXCRC
end_define

begin_define
define|#
directive|define
name|ZSWR0_RESET_RXCRC
value|ZSM_RESET_RXCRC
end_define

begin_define
define|#
directive|define
name|ZSWR0_CLR_INTR
value|ZSM_RESET_IUS
end_define

begin_define
define|#
directive|define
name|ZSWR0_RESET_ERRORS
value|ZSM_RESET_ERR
end_define

begin_define
define|#
directive|define
name|ZSWR0_EI_NEXTRXC
value|ZSM_EI_NEXTRXC
end_define

begin_define
define|#
directive|define
name|ZSWR0_SEND_ABORT
value|ZSM_SEND_ABORT
end_define

begin_define
define|#
directive|define
name|ZSWR0_RESET_STATUS
value|ZSM_RESET_STINT
end_define

begin_define
define|#
directive|define
name|ZSWR0_RESET_TXINT
value|ZSM_RESET_TXINT
end_define

begin_comment
comment|/*  * Bits in Write Register 1 (`Transmit/Receive Interrupt and Data  * Transfer Mode Definition').  Note that bits 3 and 4 are taken together  * as a single unit, and bits 5 and 6 are useful only if bit 7 is set.  */
end_comment

begin_define
define|#
directive|define
name|ZSWR1_REQ_WAIT
value|0x80
end_define

begin_comment
comment|/* WAIT*-REQ* pin gives WAIT* */
end_comment

begin_define
define|#
directive|define
name|ZSWR1_REQ_REQ
value|0xc0
end_define

begin_comment
comment|/* WAIT*-REQ* pin gives REQ* */
end_comment

begin_define
define|#
directive|define
name|ZSWR1_REQ_TX
value|0x00
end_define

begin_comment
comment|/* WAIT*-REQ* pin follows xmit buf */
end_comment

begin_define
define|#
directive|define
name|ZSWR1_REQ_RX
value|0x20
end_define

begin_comment
comment|/* WAIT*-REQ* pin follows recv buf */
end_comment

begin_define
define|#
directive|define
name|ZSWR1_RIE_NONE
value|0x00
end_define

begin_comment
comment|/* disable rxint entirely */
end_comment

begin_define
define|#
directive|define
name|ZSWR1_RIE_FIRST
value|0x08
end_define

begin_comment
comment|/* rxint on first char& on S.C. */
end_comment

begin_define
define|#
directive|define
name|ZSWR1_RIE
value|0x10
end_define

begin_comment
comment|/* rxint per char& on S.C. */
end_comment

begin_define
define|#
directive|define
name|ZSWR1_RIE_SPECIAL_ONLY
value|0x18
end_define

begin_comment
comment|/* rxint on S.C. only */
end_comment

begin_define
define|#
directive|define
name|ZSWR1_PE_SC
value|0x04
end_define

begin_comment
comment|/* parity error is special condition */
end_comment

begin_define
define|#
directive|define
name|ZSWR1_TIE
value|0x02
end_define

begin_comment
comment|/* transmit interrupt enable */
end_comment

begin_define
define|#
directive|define
name|ZSWR1_SIE
value|0x01
end_define

begin_comment
comment|/* external/status interrupt enable */
end_comment

begin_define
define|#
directive|define
name|ZSWR1_IMASK
value|0x1F
end_define

begin_comment
comment|/* mask of all itr. enable bits. */
end_comment

begin_comment
comment|/* HSIS compat */
end_comment

begin_define
define|#
directive|define
name|ZSWR1_REQ_ENABLE
value|(ZSWR1_REQ_WAIT | ZSWR1_REQ_TX)
end_define

begin_comment
comment|/*  * Bits in Write Register 3 (`Receive Parameters and Control').  * Bits 7 and 6 are taken as a unit.  Note that the receive bits  * per character ordering is insane.  *  * Here `hardware flow control' means CTS enables the transmitter  * and DCD enables the receiver.  The latter is neither interesting  * nor useful, and gets in our way, making it almost unusable.  */
end_comment

begin_define
define|#
directive|define
name|ZSWR3_RX_5
value|0x00
end_define

begin_comment
comment|/* receive 5 bits per char */
end_comment

begin_define
define|#
directive|define
name|ZSWR3_RX_7
value|0x40
end_define

begin_comment
comment|/* receive 7 bits per char */
end_comment

begin_define
define|#
directive|define
name|ZSWR3_RX_6
value|0x80
end_define

begin_comment
comment|/* receive 6 bits per char */
end_comment

begin_define
define|#
directive|define
name|ZSWR3_RX_8
value|0xc0
end_define

begin_comment
comment|/* receive 8 bits per char */
end_comment

begin_define
define|#
directive|define
name|ZSWR3_RXSIZE
value|0xc0
end_define

begin_comment
comment|/* receive char size mask */
end_comment

begin_define
define|#
directive|define
name|ZSWR3_HFC
value|0x20
end_define

begin_comment
comment|/* hardware flow control */
end_comment

begin_define
define|#
directive|define
name|ZSWR3_HUNT
value|0x10
end_define

begin_comment
comment|/* enter hunt mode */
end_comment

begin_define
define|#
directive|define
name|ZSWR3_RXCRC_ENABLE
value|0x08
end_define

begin_comment
comment|/* enable recv crc calculation */
end_comment

begin_define
define|#
directive|define
name|ZSWR3_ADDR_SEARCH_MODE
value|0x04
end_define

begin_comment
comment|/* address search mode (SDLC only) */
end_comment

begin_define
define|#
directive|define
name|ZSWR3_SDLC_SHORT_ADDR
value|0x02
end_define

begin_comment
comment|/* short address mode (SDLC only) */
end_comment

begin_define
define|#
directive|define
name|ZSWR3_SYNC_LOAD_INH
value|0x02
end_define

begin_comment
comment|/* sync character load inhibit */
end_comment

begin_define
define|#
directive|define
name|ZSWR3_RX_ENABLE
value|0x01
end_define

begin_comment
comment|/* receiver enable */
end_comment

begin_comment
comment|/*  * Bits in Write Register 4 (`Transmit/Receive Miscellaneous Parameters  * and Modes').  Bits 7&6, 5&4, and 3&2 are taken as units.  */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_CLK_X1
value|0x00
end_define

begin_comment
comment|/* clock divisor = 1 */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_CLK_X16
value|0x40
end_define

begin_comment
comment|/* clock divisor = 16 */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_CLK_X32
value|0x80
end_define

begin_comment
comment|/* clock divisor = 32 */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_CLK_X64
value|0xc0
end_define

begin_comment
comment|/* clock divisor = 64 */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_CLK_MASK
value|0xc0
end_define

begin_comment
comment|/* clock divisor mask */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_MONOSYNC
value|0x00
end_define

begin_comment
comment|/* 8 bit sync char (sync only) */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_BISYNC
value|0x10
end_define

begin_comment
comment|/* 16 bit sync char (sync only) */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_SDLC
value|0x20
end_define

begin_comment
comment|/* SDLC mode */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_EXTSYNC
value|0x30
end_define

begin_comment
comment|/* external sync mode */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_SYNC_MASK
value|0x30
end_define

begin_comment
comment|/* sync mode bit mask */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_SYNCMODE
value|0x00
end_define

begin_comment
comment|/* no stop bit (sync mode only) */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_ONESB
value|0x04
end_define

begin_comment
comment|/* 1 stop bit */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_1P5SB
value|0x08
end_define

begin_comment
comment|/* 1.5 stop bits (clk cannot be 1x) */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_TWOSB
value|0x0c
end_define

begin_comment
comment|/* 2 stop bits */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_SBMASK
value|0x0c
end_define

begin_comment
comment|/* mask of all stop bits */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_EVENP
value|0x02
end_define

begin_comment
comment|/* check for even parity */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_PARENB
value|0x01
end_define

begin_comment
comment|/* enable parity checking */
end_comment

begin_define
define|#
directive|define
name|ZSWR4_PARMASK
value|0x03
end_define

begin_comment
comment|/* mask of all parity bits */
end_comment

begin_comment
comment|/*  * Bits in Write Register 5 (`Transmit Parameter and Controls').  * Bits 6 and 5 are taken as a unit; the ordering is, as with RX  * bits per char, not sensible.  */
end_comment

begin_define
define|#
directive|define
name|ZSWR5_DTR
value|0x80
end_define

begin_comment
comment|/* assert (set to -12V) DTR */
end_comment

begin_define
define|#
directive|define
name|ZSWR5_TX_5
value|0x00
end_define

begin_comment
comment|/* transmit 5 or fewer bits */
end_comment

begin_define
define|#
directive|define
name|ZSWR5_TX_7
value|0x20
end_define

begin_comment
comment|/* transmit 7 bits */
end_comment

begin_define
define|#
directive|define
name|ZSWR5_TX_6
value|0x40
end_define

begin_comment
comment|/* transmit 6 bits */
end_comment

begin_define
define|#
directive|define
name|ZSWR5_TX_8
value|0x60
end_define

begin_comment
comment|/* transmit 8 bits */
end_comment

begin_define
define|#
directive|define
name|ZSWR5_TXSIZE
value|0x60
end_define

begin_comment
comment|/* transmit char size mask */
end_comment

begin_define
define|#
directive|define
name|ZSWR5_BREAK
value|0x10
end_define

begin_comment
comment|/* send break (continuous 0s) */
end_comment

begin_define
define|#
directive|define
name|ZSWR5_TX_ENABLE
value|0x08
end_define

begin_comment
comment|/* enable transmitter */
end_comment

begin_define
define|#
directive|define
name|ZSWR5_CRC16
value|0x04
end_define

begin_comment
comment|/* use CRC16 (off => use SDLC) */
end_comment

begin_define
define|#
directive|define
name|ZSWR5_RTS
value|0x02
end_define

begin_comment
comment|/* assert RTS */
end_comment

begin_define
define|#
directive|define
name|ZSWR5_TXCRC_ENABLE
value|0x01
end_define

begin_comment
comment|/* enable xmit crc calculation */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|not_done_here
end_ifdef

begin_comment
comment|/*  * Bits in Write Register 7 when the chip is in SDLC mode.  */
end_comment

begin_define
define|#
directive|define
name|ZSWR7_SDLCFLAG
value|0x7e
end_define

begin_comment
comment|/* this value makes SDLC mode work */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Bits in Write Register 7' (ZSWR_ENHANCED above). This register is  * only available on the 85230. Dispite the fact it contains flags  * and not a single value, the register was named as it is read  * via RR14. Weird.  */
end_comment

begin_comment
comment|/*	0x80	unused */
end_comment

begin_define
define|#
directive|define
name|ZSWR7P_EXTEND_READ
value|0x40
end_define

begin_comment
comment|/* modify read map; make most regs readable */
end_comment

begin_define
define|#
directive|define
name|ZSWR7P_TX_FIFO
value|0x20
end_define

begin_comment
comment|/* change level for Tx FIFO empty int */
end_comment

begin_define
define|#
directive|define
name|ZSWR7P_DTR_TIME
value|0x10
end_define

begin_comment
comment|/* modifies deact. speed of /DTR//REQ */
end_comment

begin_define
define|#
directive|define
name|ZSWR7P_RX_FIFO
value|0x08
end_define

begin_comment
comment|/* Rx FIFO int on 1/2 full? */
end_comment

begin_define
define|#
directive|define
name|ZSWR7P_RTS_DEACT
value|0x04
end_define

begin_comment
comment|/* automatically deassert RTS */
end_comment

begin_define
define|#
directive|define
name|ZSWR7P_AUTO_EOM_RESET
value|0x02
end_define

begin_comment
comment|/* automatically reset EMO/Tx Underrun */
end_comment

begin_define
define|#
directive|define
name|ZSWR7P_AUTO_TX_FLAG
value|0x01
end_define

begin_comment
comment|/* Auto send SDLC flag at transmit start */
end_comment

begin_comment
comment|/*  * Bits in Write Register 9 (`Master Interrupt Control').  Bits 7& 6  * are taken as a unit and indicate the type of reset; 00 means no reset  * (and is not defined here).  */
end_comment

begin_define
define|#
directive|define
name|ZSWR9_HARD_RESET
value|0xc0
end_define

begin_comment
comment|/* force hardware reset */
end_comment

begin_define
define|#
directive|define
name|ZSWR9_A_RESET
value|0x80
end_define

begin_comment
comment|/* reset channel A (0) */
end_comment

begin_define
define|#
directive|define
name|ZSWR9_B_RESET
value|0x40
end_define

begin_comment
comment|/* reset channel B (1) */
end_comment

begin_define
define|#
directive|define
name|ZSWR9_SOFT_INTAC
value|0x20
end_define

begin_comment
comment|/* Not in NMOS version */
end_comment

begin_define
define|#
directive|define
name|ZSWR9_STATUS_HIGH
value|0x10
end_define

begin_comment
comment|/* status in high bits of intr vec */
end_comment

begin_define
define|#
directive|define
name|ZSWR9_MASTER_IE
value|0x08
end_define

begin_comment
comment|/* master interrupt enable */
end_comment

begin_define
define|#
directive|define
name|ZSWR9_DLC
value|0x04
end_define

begin_comment
comment|/* disable lower chain */
end_comment

begin_define
define|#
directive|define
name|ZSWR9_NO_VECTOR
value|0x02
end_define

begin_comment
comment|/* no vector */
end_comment

begin_define
define|#
directive|define
name|ZSWR9_VECTOR_INCL_STAT
value|0x01
end_define

begin_comment
comment|/* vector includes status */
end_comment

begin_comment
comment|/*  * Bits in Write Register 10 (`Miscellaneous Transmitter/Receiver Control  * Bits').  Bits 6& 5 are taken as a unit, and some of the bits are  * meaningful only in certain modes.  Bleah.  */
end_comment

begin_define
define|#
directive|define
name|ZSWR10_PRESET_ONES
value|0x80
end_define

begin_comment
comment|/* preset CRC to all 1 (else all 0) */
end_comment

begin_define
define|#
directive|define
name|ZSWR10_NRZ
value|0x00
end_define

begin_comment
comment|/* NRZ encoding */
end_comment

begin_define
define|#
directive|define
name|ZSWR10_NRZI
value|0x20
end_define

begin_comment
comment|/* NRZI encoding */
end_comment

begin_define
define|#
directive|define
name|ZSWR10_FM1
value|0x40
end_define

begin_comment
comment|/* FM1 encoding */
end_comment

begin_define
define|#
directive|define
name|ZSWR10_FM0
value|0x60
end_define

begin_comment
comment|/* FM0 encoding */
end_comment

begin_define
define|#
directive|define
name|ZSWR10_GA_ON_POLL
value|0x10
end_define

begin_comment
comment|/* go active on poll (loop mode) */
end_comment

begin_define
define|#
directive|define
name|ZSWR10_MARK_IDLE
value|0x08
end_define

begin_comment
comment|/* all 1s (vs flag) when idle (SDLC) */
end_comment

begin_define
define|#
directive|define
name|ZSWR10_ABORT_ON_UNDERRUN
value|0x4
end_define

begin_comment
comment|/* abort on xmit underrun (SDLC) */
end_comment

begin_define
define|#
directive|define
name|ZSWR10_LOOP_MODE
value|0x02
end_define

begin_comment
comment|/* loop mode (SDLC) */
end_comment

begin_define
define|#
directive|define
name|ZSWR10_6_BIT_SYNC
value|0x01
end_define

begin_comment
comment|/* 6 bits per sync char (sync modes) */
end_comment

begin_comment
comment|/*  * Bits in Write Register 11 (`Clock Mode Control').  Bits 6&5, 4&3, and  * 1&0 are taken as units.  Various bits depend on other bits in complex  * ways; see the Zilog manual.  */
end_comment

begin_define
define|#
directive|define
name|ZSWR11_XTAL
value|0x80
end_define

begin_comment
comment|/* have xtal between RTxC* and SYNC* */
end_comment

begin_comment
comment|/* (else have TTL oscil. on RTxC*) */
end_comment

begin_define
define|#
directive|define
name|ZSWR11_RXCLK_RTXC
value|0x00
end_define

begin_comment
comment|/* recv clock taken from RTxC* pin */
end_comment

begin_define
define|#
directive|define
name|ZSWR11_RXCLK_TRXC
value|0x20
end_define

begin_comment
comment|/* recv clock taken from TRxC* pin */
end_comment

begin_define
define|#
directive|define
name|ZSWR11_RXCLK_BAUD
value|0x40
end_define

begin_comment
comment|/* recv clock taken from BRG */
end_comment

begin_define
define|#
directive|define
name|ZSWR11_RXCLK_DPLL
value|0x60
end_define

begin_comment
comment|/* recv clock taken from DPLL */
end_comment

begin_define
define|#
directive|define
name|ZSWR11_TXCLK_RTXC
value|0x00
end_define

begin_comment
comment|/* xmit clock taken from RTxC* pin */
end_comment

begin_define
define|#
directive|define
name|ZSWR11_TXCLK_TRXC
value|0x08
end_define

begin_comment
comment|/* xmit clock taken from TRxC* pin */
end_comment

begin_define
define|#
directive|define
name|ZSWR11_TXCLK_BAUD
value|0x10
end_define

begin_comment
comment|/* xmit clock taken from BRG */
end_comment

begin_define
define|#
directive|define
name|ZSWR11_TXCLK_DPLL
value|0x18
end_define

begin_comment
comment|/* xmit clock taken from DPLL */
end_comment

begin_define
define|#
directive|define
name|ZSWR11_TRXC_OUT_ENA
value|0x04
end_define

begin_comment
comment|/* TRxC* pin will be an output */
end_comment

begin_comment
comment|/* (unless it is being used above) */
end_comment

begin_define
define|#
directive|define
name|ZSWR11_TRXC_XTAL
value|0x00
end_define

begin_comment
comment|/* TRxC output from xtal oscillator */
end_comment

begin_define
define|#
directive|define
name|ZSWR11_TRXC_XMIT
value|0x01
end_define

begin_comment
comment|/* TRxC output from xmit clock */
end_comment

begin_define
define|#
directive|define
name|ZSWR11_TRXC_BAUD
value|0x02
end_define

begin_comment
comment|/* TRxC output from BRG */
end_comment

begin_define
define|#
directive|define
name|ZSWR11_TRXC_DPLL
value|0x03
end_define

begin_comment
comment|/* TRxC output from DPLL */
end_comment

begin_comment
comment|/*  * Formula for Write Registers 12 and 13 (`Lower Byte of Baud Rate  * Generator Time Constant' and `Upper Byte of ...').  Inputs:  *  *	f	BRG input clock frequency (in Hz) AFTER division  *		by 1, 16, 32, or 64 (per clock divisor in WR4)  *	bps	desired rate in bits per second (9600, etc)  *  * We want  *  *	  f  *	----- + 0.5 - 2  *	2 bps  *  * rounded down to an integer.  This can be computed entirely  * in integer arithemtic as:  *  *	f + bps  *	------- - 2  *	 2 bps  */
end_comment

begin_define
define|#
directive|define
name|BPS_TO_TCONST
parameter_list|(
name|f
parameter_list|,
name|bps
parameter_list|)
value|((((f) + (bps)) / (2 * (bps))) - 2)
end_define

begin_comment
comment|/* inverse of above: given a BRG Time Constant, return Bits Per Second */
end_comment

begin_define
define|#
directive|define
name|TCONST_TO_BPS
parameter_list|(
name|f
parameter_list|,
name|tc
parameter_list|)
value|((f) / 2 / ((tc) + 2))
end_define

begin_comment
comment|/*  * Bits in Write Register 14 (`Miscellaneous Control Bits').  * Bits 7 through 5 are taken as a unit and make up a `DPLL command'.  */
end_comment

begin_define
define|#
directive|define
name|ZSWR14_DPLL_NOOP
value|0x00
end_define

begin_comment
comment|/* leave DPLL alone */
end_comment

begin_define
define|#
directive|define
name|ZSWR14_DPLL_SEARCH
value|0x20
end_define

begin_comment
comment|/* enter search mode */
end_comment

begin_define
define|#
directive|define
name|ZSWR14_DPLL_RESET_CM
value|0x40
end_define

begin_comment
comment|/* reset `clock missing' in RR10 */
end_comment

begin_define
define|#
directive|define
name|ZSWR14_DPLL_DISABLE
value|0x60
end_define

begin_comment
comment|/* disable DPLL (continuous search) */
end_comment

begin_define
define|#
directive|define
name|ZSWR14_DPLL_SRC_BAUD
value|0x80
end_define

begin_comment
comment|/* set DPLL src = BRG */
end_comment

begin_define
define|#
directive|define
name|ZSWR14_DPLL_SRC_RTXC
value|0xa0
end_define

begin_comment
comment|/* set DPLL src = RTxC* or xtal osc */
end_comment

begin_define
define|#
directive|define
name|ZSWR14_DPLL_FM
value|0xc0
end_define

begin_comment
comment|/* operate in FM mode */
end_comment

begin_define
define|#
directive|define
name|ZSWR14_DPLL_NRZI
value|0xe0
end_define

begin_comment
comment|/* operate in NRZI mode */
end_comment

begin_define
define|#
directive|define
name|ZSWR14_LOCAL_LOOPBACK
value|0x10
end_define

begin_comment
comment|/* set local loopback mode */
end_comment

begin_define
define|#
directive|define
name|ZSWR14_AUTO_ECHO
value|0x08
end_define

begin_comment
comment|/* set auto echo mode */
end_comment

begin_define
define|#
directive|define
name|ZSWR14_DTR_REQ
value|0x04
end_define

begin_comment
comment|/* DTR* / REQ* pin gives REQ* */
end_comment

begin_define
define|#
directive|define
name|ZSWR14_BAUD_FROM_PCLK
value|0x02
end_define

begin_comment
comment|/* BRG clock taken from PCLK */
end_comment

begin_comment
comment|/* (else from RTxC* pin or xtal osc) */
end_comment

begin_define
define|#
directive|define
name|ZSWR14_BAUD_ENA
value|0x01
end_define

begin_comment
comment|/* enable BRG countdown */
end_comment

begin_comment
comment|/*  * Bits in Write Register 15 (`External/Status Interrupt Control').  * Most of these cause status interrupts whenever the corresponding  * bit or pin changes state (i.e., any rising or falling edge).  *  * NOTE: ZSWR15_SDLC_FIFO& ZSWR15_ENABLE_ENHANCED should not be  * set on an NMOS 8530. Also, ZSWR15_ENABLE_ENHANCED is only  * available on the 85230.  */
end_comment

begin_define
define|#
directive|define
name|ZSWR15_BREAK_IE
value|0x80
end_define

begin_comment
comment|/* enable break/abort status int */
end_comment

begin_define
define|#
directive|define
name|ZSWR15_TXUEOM_IE
value|0x40
end_define

begin_comment
comment|/* enable TX underrun/EOM status int */
end_comment

begin_define
define|#
directive|define
name|ZSWR15_CTS_IE
value|0x20
end_define

begin_comment
comment|/* enable CTS* pin status int */
end_comment

begin_define
define|#
directive|define
name|ZSWR15_SYNCHUNT_IE
value|0x10
end_define

begin_comment
comment|/* enable SYNC* pin/hunt status int */
end_comment

begin_define
define|#
directive|define
name|ZSWR15_DCD_IE
value|0x08
end_define

begin_comment
comment|/* enable DCD* pin status int */
end_comment

begin_define
define|#
directive|define
name|ZSWR15_SDLC_FIFO
value|0x04
end_define

begin_comment
comment|/* enable SDLC FIFO enhancements */
end_comment

begin_define
define|#
directive|define
name|ZSWR15_ZERO_COUNT_IE
value|0x02
end_define

begin_comment
comment|/* enable BRG-counter = 0 status int */
end_comment

begin_define
define|#
directive|define
name|ZSWR15_ENABLE_ENHANCED
value|0x01
end_define

begin_comment
comment|/* enable writing WR7' at reg 7 */
end_comment

begin_comment
comment|/*  * Bits in Read Register 0 (`Transmit/Receive Buffer Status and External  * Status').  */
end_comment

begin_define
define|#
directive|define
name|ZSRR0_BREAK
value|0x80
end_define

begin_comment
comment|/* break/abort detected */
end_comment

begin_define
define|#
directive|define
name|ZSRR0_TXUNDER
value|0x40
end_define

begin_comment
comment|/* transmit underrun/EOM (sync) */
end_comment

begin_define
define|#
directive|define
name|ZSRR0_CTS
value|0x20
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|ZSRR0_SYNC_HUNT
value|0x10
end_define

begin_comment
comment|/* sync/hunt (sync mode) */
end_comment

begin_define
define|#
directive|define
name|ZSRR0_DCD
value|0x08
end_define

begin_comment
comment|/* data carrier detect */
end_comment

begin_define
define|#
directive|define
name|ZSRR0_TX_READY
value|0x04
end_define

begin_comment
comment|/* transmit buffer empty */
end_comment

begin_define
define|#
directive|define
name|ZSRR0_ZERO_COUNT
value|0x02
end_define

begin_comment
comment|/* zero count in baud clock */
end_comment

begin_define
define|#
directive|define
name|ZSRR0_RX_READY
value|0x01
end_define

begin_comment
comment|/* received character ready */
end_comment

begin_comment
comment|/*  * Bits in Read Register 1 (the Zilog book does not name this one).  */
end_comment

begin_define
define|#
directive|define
name|ZSRR1_EOF
value|0x80
end_define

begin_comment
comment|/* end of frame (SDLC mode) */
end_comment

begin_define
define|#
directive|define
name|ZSRR1_FE
value|0x40
end_define

begin_comment
comment|/* CRC/framing error */
end_comment

begin_define
define|#
directive|define
name|ZSRR1_DO
value|0x20
end_define

begin_comment
comment|/* data (receiver) overrun */
end_comment

begin_define
define|#
directive|define
name|ZSRR1_PE
value|0x10
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|ZSRR1_RC0
value|0x08
end_define

begin_comment
comment|/* residue code 0 (SDLC mode) */
end_comment

begin_define
define|#
directive|define
name|ZSRR1_RC1
value|0x04
end_define

begin_comment
comment|/* residue code 1 (SDLC mode) */
end_comment

begin_define
define|#
directive|define
name|ZSRR1_RC2
value|0x02
end_define

begin_comment
comment|/* residue code 2 (SDLC mode) */
end_comment

begin_define
define|#
directive|define
name|ZSRR1_ALL_SENT
value|0x01
end_define

begin_comment
comment|/* all chars out of xmitter (async) */
end_comment

begin_comment
comment|/*  * Read Register 2 in B channel contains status bits if VECTOR_INCL_STAT  * is set.  */
end_comment

begin_comment
comment|/*  * Bits in Read Register 3 (`Interrupt Pending').  Only channel A  * has an RR3.  */
end_comment

begin_comment
comment|/*	0x80	   unused, returned as 0 */
end_comment

begin_comment
comment|/*	0x40	   unused, returned as 0 */
end_comment

begin_define
define|#
directive|define
name|ZSRR3_IP_A_RX
value|0x20
end_define

begin_comment
comment|/* channel A recv int pending */
end_comment

begin_define
define|#
directive|define
name|ZSRR3_IP_A_TX
value|0x10
end_define

begin_comment
comment|/* channel A xmit int pending */
end_comment

begin_define
define|#
directive|define
name|ZSRR3_IP_A_STAT
value|0x08
end_define

begin_comment
comment|/* channel A status int pending */
end_comment

begin_define
define|#
directive|define
name|ZSRR3_IP_B_RX
value|0x04
end_define

begin_comment
comment|/* channel B recv int pending */
end_comment

begin_define
define|#
directive|define
name|ZSRR3_IP_B_TX
value|0x02
end_define

begin_comment
comment|/* channel B xmit int pending */
end_comment

begin_define
define|#
directive|define
name|ZSRR3_IP_B_STAT
value|0x01
end_define

begin_comment
comment|/* channel B status int pending */
end_comment

begin_comment
comment|/*  * Bits in Read Register 10 (`contains some miscellaneous status bits').  */
end_comment

begin_define
define|#
directive|define
name|ZSRR10_1_CLOCK_MISSING
value|0x80
end_define

begin_comment
comment|/* 1 clock edge missing (FM mode) */
end_comment

begin_define
define|#
directive|define
name|ZSRR10_2_CLOCKS_MISSING
value|0x40
end_define

begin_comment
comment|/* 2 clock edges missing (FM mode) */
end_comment

begin_comment
comment|/*	0x20	   unused */
end_comment

begin_define
define|#
directive|define
name|ZSRR10_LOOP_SENDING
value|0x10
end_define

begin_comment
comment|/* xmitter controls loop (SDLC loop) */
end_comment

begin_comment
comment|/*	0x08	   unused */
end_comment

begin_comment
comment|/*	0x04	   unused */
end_comment

begin_define
define|#
directive|define
name|ZSRR10_ON_LOOP
value|0x02
end_define

begin_comment
comment|/* SCC is on loop (SDLC/X.21 modes) */
end_comment

begin_comment
comment|/*  * Bits in Read Register 15.  This register is one of the few that  * simply reads back the corresponding Write Register.  */
end_comment

begin_define
define|#
directive|define
name|ZSRR15_BREAK_IE
value|0x80
end_define

begin_comment
comment|/* break/abort status int enable */
end_comment

begin_define
define|#
directive|define
name|ZSRR15_TXUEOM_IE
value|0x40
end_define

begin_comment
comment|/* TX underrun/EOM status int enable */
end_comment

begin_define
define|#
directive|define
name|ZSRR15_CTS_IE
value|0x20
end_define

begin_comment
comment|/* CTS* pin status int enable */
end_comment

begin_define
define|#
directive|define
name|ZSRR15_SYNCHUNT_IE
value|0x10
end_define

begin_comment
comment|/* SYNC* pin/hunt status int enable */
end_comment

begin_define
define|#
directive|define
name|ZSRR15_DCD_IE
value|0x08
end_define

begin_comment
comment|/* DCD* pin status int enable */
end_comment

begin_comment
comment|/*	0x04	   unused, returned as zero */
end_comment

begin_define
define|#
directive|define
name|ZSRR15_ZERO_COUNT_IE
value|0x02
end_define

begin_comment
comment|/* BRG-counter = 0 status int enable */
end_comment

begin_comment
comment|/*	0x01	   unused, returned as zero */
end_comment

end_unit

