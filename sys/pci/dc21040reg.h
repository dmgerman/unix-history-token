begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: dc21040reg.h,v 1.15 1998/05/22 18:50:59 matt Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1994, 1995, 1996 Matt Thomas<matt@3am-software.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Id: dc21040reg.h,v 1.24 1997/05/16 19:47:09 thomas Exp  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_DC21040_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|_DC21040_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
operator|&&
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|TULIP_BITFIELD2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|b, a
end_define

begin_define
define|#
directive|define
name|TULIP_BITFIELD3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|c, b, a
end_define

begin_define
define|#
directive|define
name|TULIP_BITFIELD4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|d, c, b, a
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TULIP_BITFIELD2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a, b
end_define

begin_define
define|#
directive|define
name|TULIP_BITFIELD3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a, b, c
end_define

begin_define
define|#
directive|define
name|TULIP_BITFIELD4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|a, b, c, d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|d_status
decl_stmt|;
name|u_int32_t
name|TULIP_BITFIELD3
argument_list|(
name|d_length1
operator|:
literal|11
argument_list|,
name|d_length2
operator|:
literal|11
argument_list|,
name|d_flag
operator|:
literal|10
argument_list|)
decl_stmt|;
name|u_int32_t
name|d_addr1
decl_stmt|;
name|u_int32_t
name|d_addr2
decl_stmt|;
block|}
name|tulip_desc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TULIP_DSTS_OWNER
value|0x80000000
end_define

begin_comment
comment|/* Owner (1 = 21040) */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_ERRSUM
value|0x00008000
end_define

begin_comment
comment|/* Error Summary */
end_comment

begin_comment
comment|/*  * Transmit Status  */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_TxBABBLE
value|0x00004000
end_define

begin_comment
comment|/* Transmitter Babbled */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_TxCARRLOSS
value|0x00000800
end_define

begin_comment
comment|/* Carrier Loss */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_TxNOCARR
value|0x00000400
end_define

begin_comment
comment|/* No Carrier */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_TxLATECOLL
value|0x00000200
end_define

begin_comment
comment|/* Late Collision */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_TxEXCCOLL
value|0x00000100
end_define

begin_comment
comment|/* Excessive Collisions */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_TxNOHRTBT
value|0x00000080
end_define

begin_comment
comment|/* No Heartbeat */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_TxCOLLMASK
value|0x00000078
end_define

begin_comment
comment|/* Collision Count (mask) */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_V_TxCOLLCNT
value|0x00000003
end_define

begin_comment
comment|/* Collision Count (bit) */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_TxLINKFAIL
value|0x00000004
end_define

begin_comment
comment|/* Link Failure */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_TxUNDERFLOW
value|0x00000002
end_define

begin_comment
comment|/* Underflow Error */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_TxDEFERRED
value|0x00000001
end_define

begin_comment
comment|/* Initially Deferred */
end_comment

begin_comment
comment|/*  * Receive Status  */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_RxBADLENGTH
value|0x00004000
end_define

begin_comment
comment|/* Length Error */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_RxDATATYPE
value|0x00003000
end_define

begin_comment
comment|/* Data Type */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_RxRUNT
value|0x00000800
end_define

begin_comment
comment|/* Runt Frame */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_RxMULTICAST
value|0x00000400
end_define

begin_comment
comment|/* Multicast Frame */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_RxFIRSTDESC
value|0x00000200
end_define

begin_comment
comment|/* First Descriptor */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_RxLASTDESC
value|0x00000100
end_define

begin_comment
comment|/* Last Descriptor */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_RxTOOLONG
value|0x00000080
end_define

begin_comment
comment|/* Frame Too Long */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_RxCOLLSEEN
value|0x00000040
end_define

begin_comment
comment|/* Collision Seen */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_RxFRAMETYPE
value|0x00000020
end_define

begin_comment
comment|/* Frame Type */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_RxWATCHDOG
value|0x00000010
end_define

begin_comment
comment|/* Receive Watchdog */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_RxDRBBLBIT
value|0x00000004
end_define

begin_comment
comment|/* Dribble Bit */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_RxBADCRC
value|0x00000002
end_define

begin_comment
comment|/* CRC Error */
end_comment

begin_define
define|#
directive|define
name|TULIP_DSTS_RxOVERFLOW
value|0x00000001
end_define

begin_comment
comment|/* Overflow */
end_comment

begin_define
define|#
directive|define
name|TULIP_DFLAG_ENDRING
value|0x0008
end_define

begin_comment
comment|/* End of Transmit Ring */
end_comment

begin_define
define|#
directive|define
name|TULIP_DFLAG_CHAIN
value|0x0004
end_define

begin_comment
comment|/* Chain using d_addr2 */
end_comment

begin_define
define|#
directive|define
name|TULIP_DFLAG_TxWANTINTR
value|0x0200
end_define

begin_comment
comment|/* Signal Interrupt on Completion */
end_comment

begin_define
define|#
directive|define
name|TULIP_DFLAG_TxLASTSEG
value|0x0100
end_define

begin_comment
comment|/* Last Segment */
end_comment

begin_define
define|#
directive|define
name|TULIP_DFLAG_TxFIRSTSEG
value|0x0080
end_define

begin_comment
comment|/* First Segment */
end_comment

begin_define
define|#
directive|define
name|TULIP_DFLAG_TxINVRSFILT
value|0x0040
end_define

begin_comment
comment|/* Inverse Filtering */
end_comment

begin_define
define|#
directive|define
name|TULIP_DFLAG_TxSETUPPKT
value|0x0020
end_define

begin_comment
comment|/* Setup Packet */
end_comment

begin_define
define|#
directive|define
name|TULIP_DFLAG_TxHASCRC
value|0x0010
end_define

begin_comment
comment|/* Don't Append the CRC */
end_comment

begin_define
define|#
directive|define
name|TULIP_DFLAG_TxNOPADDING
value|0x0002
end_define

begin_comment
comment|/* Don't AutoPad */
end_comment

begin_define
define|#
directive|define
name|TULIP_DFLAG_TxHASHFILT
value|0x0001
end_define

begin_comment
comment|/* Hash/Perfect Filtering */
end_comment

begin_comment
comment|/*  * The 21040 Registers (IO Space Addresses)  */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_BUSMODE
value|0x00
end_define

begin_comment
comment|/* CSR0  -- Bus Mode */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_TXPOLL
value|0x08
end_define

begin_comment
comment|/* CSR1  -- Transmit Poll Demand */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_RXPOLL
value|0x10
end_define

begin_comment
comment|/* CSR2  -- Receive Poll Demand */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_RXLIST
value|0x18
end_define

begin_comment
comment|/* CSR3  -- Receive List Base Addr */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_TXLIST
value|0x20
end_define

begin_comment
comment|/* CSR4  -- Transmit List Base Addr */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_STATUS
value|0x28
end_define

begin_comment
comment|/* CSR5  -- Status */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_CMD
value|0x30
end_define

begin_comment
comment|/* CSR6  -- Command */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_INTR
value|0x38
end_define

begin_comment
comment|/* CSR7  -- Interrupt Control */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_MISSES
value|0x40
end_define

begin_comment
comment|/* CSR8  -- Missed Frame Counter */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_ADDRROM
value|0x48
end_define

begin_comment
comment|/* CSR9  -- ENET ROM Register */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_RSRVD
value|0x50
end_define

begin_comment
comment|/* CSR10 -- Reserved */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_FULL_DUPLEX
value|0x58
end_define

begin_comment
comment|/* CSR11 -- Full Duplex */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_SIA_STATUS
value|0x60
end_define

begin_comment
comment|/* CSR12 -- SIA Status */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_SIA_CONN
value|0x68
end_define

begin_comment
comment|/* CSR13 -- SIA Connectivity */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_SIA_TXRX
value|0x70
end_define

begin_comment
comment|/* CSR14 -- SIA Tx Rx */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_SIA_GEN
value|0x78
end_define

begin_comment
comment|/* CSR15 -- SIA General */
end_comment

begin_comment
comment|/*  * CSR5 -- Status Register  * CSR7 -- Interrupt Control  */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_ERRORMASK
value|0x03800000L
end_define

begin_comment
comment|/* ( R)  Error Bits (Valid when SYSERROR is set) */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_ERR_PARITY
value|0x00000000L
end_define

begin_comment
comment|/*        000 - Parity Error (Perform Reset) */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_ERR_MASTER
value|0x00800000L
end_define

begin_comment
comment|/*        001 - Master Abort */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_ERR_TARGET
value|0x01000000L
end_define

begin_comment
comment|/*        010 - Target Abort */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_ERR_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|TULIP_STS_TXSTATEMASK
value|0x00700000L
end_define

begin_comment
comment|/* ( R)  Transmission Process State */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_TXS_RESET
value|0x00000000L
end_define

begin_comment
comment|/*        000 - Rset or transmit jabber expired */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_TXS_FETCH
value|0x00100000L
end_define

begin_comment
comment|/*        001 - Fetching transmit descriptor */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_TXS_WAITEND
value|0x00200000L
end_define

begin_comment
comment|/*        010 - Wait for end of transmission */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_TXS_READING
value|0x00300000L
end_define

begin_comment
comment|/*        011 - Read buffer and enqueue data */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_TXS_RSRVD
value|0x00400000L
end_define

begin_comment
comment|/*        100 - Reserved */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_TXS_SETUP
value|0x00500000L
end_define

begin_comment
comment|/*        101 - Setup Packet */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_TXS_SUSPEND
value|0x00600000L
end_define

begin_comment
comment|/*        110 - Transmit FIFO underflow or an 								  unavailable transmit descriptor */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_TXS_CLOSE
value|0x00700000L
end_define

begin_comment
comment|/*        111 - Close transmit descriptor */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_RXSTATEMASK
value|0x000E0000L
end_define

begin_comment
comment|/* ( R)  Receive Process State*/
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_RXS_STOPPED
value|0x00000000L
end_define

begin_comment
comment|/*        000 - Stopped */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_RXS_FETCH
value|0x00020000L
end_define

begin_comment
comment|/*        001 - Running -- Fetch receive descriptor */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_RXS_ENDCHECK
value|0x00040000L
end_define

begin_comment
comment|/*        010 - Running -- Check for end of receive 								  packet before prefetch of next descriptor */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_RXS_WAIT
value|0x00060000L
end_define

begin_comment
comment|/*        011 - Running -- Wait for receive packet */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_RXS_SUSPEND
value|0x00080000L
end_define

begin_comment
comment|/*        100 - Suspended -- As a result of 								  unavailable receive buffers */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_RXS_CLOSE
value|0x000A0000L
end_define

begin_comment
comment|/*        101 - Running -- Close receive descriptor */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_RXS_FLUSH
value|0x000C0000L
end_define

begin_comment
comment|/*        110 - Running -- Flush the current frame 								  from the receive FIFO as a result of 								  an unavailable receive buffer */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_RXS_DEQUEUE
value|0x000E0000L
end_define

begin_comment
comment|/*        111 - Running -- Dequeue the receive frame 								  from the receive FIFO into the receive 								  buffer. */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_NORMALINTR
value|0x00010000L
end_define

begin_comment
comment|/* (RW)  Normal Interrupt */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_ABNRMLINTR
value|0x00008000L
end_define

begin_comment
comment|/* (RW)  Abnormal Interrupt */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_SYSERROR
value|0x00002000L
end_define

begin_comment
comment|/* (RW)  System Error */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_LINKFAIL
value|0x00001000L
end_define

begin_comment
comment|/* (RW)  Link Failure (21040) */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_FULDPLXSHRT
value|0x00000800L
end_define

begin_comment
comment|/* (RW)  Full Duplex Short Fram Rcvd (21040) */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_GPTIMEOUT
value|0x00000800L
end_define

begin_comment
comment|/* (RW)  General Purpose Timeout (21140) */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_AUI
value|0x00000400L
end_define

begin_comment
comment|/* (RW)  AUI/TP Switch (21040) */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_RXTIMEOUT
value|0x00000200L
end_define

begin_comment
comment|/* (RW)  Receive Watchbog Timeout */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_RXSTOPPED
value|0x00000100L
end_define

begin_comment
comment|/* (RW)  Receive Process Stopped */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_RXNOBUF
value|0x00000080L
end_define

begin_comment
comment|/* (RW)  Receive Buffer Unavailable */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_RXINTR
value|0x00000040L
end_define

begin_comment
comment|/* (RW)  Receive Interrupt */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_TXUNDERFLOW
value|0x00000020L
end_define

begin_comment
comment|/* (RW)  Transmit Underflow */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_LINKPASS
value|0x00000010L
end_define

begin_comment
comment|/* (RW)  LinkPass (21041) */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_TXBABBLE
value|0x00000008L
end_define

begin_comment
comment|/* (RW)  Transmit Jabber Timeout */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_TXNOBUF
value|0x00000004L
end_define

begin_comment
comment|/* (RW)  Transmit Buffer Unavailable */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_TXSTOPPED
value|0x00000002L
end_define

begin_comment
comment|/* (RW)  Transmit Process Stopped */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_TXINTR
value|0x00000001L
end_define

begin_comment
comment|/* (RW)  Transmit Interrupt */
end_comment

begin_comment
comment|/*  * CSR6 -- Command (Operation Mode) Register  */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_MUSTBEONE
value|0x02000000L
end_define

begin_comment
comment|/* (RW)  Must Be One (21140) */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_SCRAMBLER
value|0x01000000L
end_define

begin_comment
comment|/* (RW)  Scrambler Mode (21140) */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_PCSFUNCTION
value|0x00800000L
end_define

begin_comment
comment|/* (RW)  PCS Function (21140) */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_TXTHRSHLDCTL
value|0x00400000L
end_define

begin_comment
comment|/* (RW)  Transmit Threshold Mode (21140) */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_STOREFWD
value|0x00200000L
end_define

begin_comment
comment|/* (RW)  Store and Foward (21140) */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_NOHEARTBEAT
value|0x00080000L
end_define

begin_comment
comment|/* (RW)  No Heartbeat (21140) */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_PORTSELECT
value|0x00040000L
end_define

begin_comment
comment|/* (RW)  Post Select (100Mb) (21140) */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_ENHCAPTEFFCT
value|0x00040000L
end_define

begin_comment
comment|/* (RW)  Enhanced Capture Effecty (21041) */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_CAPTREFFCT
value|0x00020000L
end_define

begin_comment
comment|/* (RW)  Capture Effect (!802.3) */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_BACKPRESSURE
value|0x00010000L
end_define

begin_comment
comment|/* (RW)  Back Pressure (!802.3) (21040) */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_THRESHOLDCTL
value|0x0000C000L
end_define

begin_comment
comment|/* (RW)  Threshold Control */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_THRSHLD72
value|0x00000000L
end_define

begin_comment
comment|/*       00 - 72 Bytes */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_THRSHLD96
value|0x00004000L
end_define

begin_comment
comment|/*       01 - 96 Bytes */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_THRSHLD128
value|0x00008000L
end_define

begin_comment
comment|/*       10 - 128 bytes */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_THRSHLD160
value|0x0000C000L
end_define

begin_comment
comment|/*       11 - 160 Bytes */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_TXRUN
value|0x00002000L
end_define

begin_comment
comment|/* (RW)  Start/Stop Transmitter */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_FORCECOLL
value|0x00001000L
end_define

begin_comment
comment|/* (RW)  Force Collisions */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_OPERMODE
value|0x00000C00L
end_define

begin_comment
comment|/* (RW)  Operating Mode */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_FULLDUPLEX
value|0x00000200L
end_define

begin_comment
comment|/* (RW)  Full Duplex Mode */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_FLAKYOSCDIS
value|0x00000100L
end_define

begin_comment
comment|/* (RW)  Flakey Oscillator Disable */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_ALLMULTI
value|0x00000080L
end_define

begin_comment
comment|/* (RW)  Pass All Multicasts */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_PROMISCUOUS
value|0x00000040L
end_define

begin_comment
comment|/* (RW)  Promiscuous Mode */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_BACKOFFCTR
value|0x00000020L
end_define

begin_comment
comment|/* (RW)  Start/Stop Backoff Counter (!802.3) */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_INVFILTER
value|0x00000010L
end_define

begin_comment
comment|/* (R )  Inverse Filtering */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_PASSBADPKT
value|0x00000008L
end_define

begin_comment
comment|/* (RW)  Pass Bad Frames  */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_HASHONLYFLTR
value|0x00000004L
end_define

begin_comment
comment|/* (R )  Hash Only Filtering */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_RXRUN
value|0x00000002L
end_define

begin_comment
comment|/* (RW)  Start/Stop Receive Filtering */
end_comment

begin_define
define|#
directive|define
name|TULIP_CMD_HASHPRFCTFLTR
value|0x00000001L
end_define

begin_comment
comment|/* (R )  Hash/Perfect Receive Filtering */
end_comment

begin_define
define|#
directive|define
name|TULIP_SIASTS_OTHERRXACTIVITY
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|TULIP_SIASTS_RXACTIVITY
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|TULIP_SIASTS_LINKFAIL
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|TULIP_SIASTS_LINK100FAIL
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|TULIP_SIACONN_RESET
value|0x00000000L
end_define

begin_comment
comment|/*  * 21040 SIA definitions  */
end_comment

begin_define
define|#
directive|define
name|TULIP_21040_PROBE_10BASET_TIMEOUT
value|2500
end_define

begin_define
define|#
directive|define
name|TULIP_21040_PROBE_AUIBNC_TIMEOUT
value|300
end_define

begin_define
define|#
directive|define
name|TULIP_21040_PROBE_EXTSIA_TIMEOUT
value|300
end_define

begin_define
define|#
directive|define
name|TULIP_21040_SIACONN_10BASET
value|0x0000EF01L
end_define

begin_define
define|#
directive|define
name|TULIP_21040_SIATXRX_10BASET
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|TULIP_21040_SIAGEN_10BASET
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|TULIP_21040_SIACONN_10BASET_FD
value|0x0000EF01L
end_define

begin_define
define|#
directive|define
name|TULIP_21040_SIATXRX_10BASET_FD
value|0x0000FFFDL
end_define

begin_define
define|#
directive|define
name|TULIP_21040_SIAGEN_10BASET_FD
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|TULIP_21040_SIACONN_AUIBNC
value|0x0000EF09L
end_define

begin_define
define|#
directive|define
name|TULIP_21040_SIATXRX_AUIBNC
value|0x00000705L
end_define

begin_define
define|#
directive|define
name|TULIP_21040_SIAGEN_AUIBNC
value|0x00000006L
end_define

begin_define
define|#
directive|define
name|TULIP_21040_SIACONN_EXTSIA
value|0x00003041L
end_define

begin_define
define|#
directive|define
name|TULIP_21040_SIATXRX_EXTSIA
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|TULIP_21040_SIAGEN_EXTSIA
value|0x00000006L
end_define

begin_comment
comment|/*  * 21041 SIA definitions  */
end_comment

begin_define
define|#
directive|define
name|TULIP_21041_PROBE_10BASET_TIMEOUT
value|2500
end_define

begin_define
define|#
directive|define
name|TULIP_21041_PROBE_AUIBNC_TIMEOUT
value|300
end_define

begin_define
define|#
directive|define
name|TULIP_21041_SIACONN_10BASET
value|0x0000EF01L
end_define

begin_define
define|#
directive|define
name|TULIP_21041_SIATXRX_10BASET
value|0x0000FF3FL
end_define

begin_define
define|#
directive|define
name|TULIP_21041_SIAGEN_10BASET
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|TULIP_21041P2_SIACONN_10BASET
value|0x0000EF01L
end_define

begin_define
define|#
directive|define
name|TULIP_21041P2_SIATXRX_10BASET
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|TULIP_21041P2_SIAGEN_10BASET
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|TULIP_21041_SIACONN_10BASET_FD
value|0x0000EF01L
end_define

begin_define
define|#
directive|define
name|TULIP_21041_SIATXRX_10BASET_FD
value|0x0000FF3DL
end_define

begin_define
define|#
directive|define
name|TULIP_21041_SIAGEN_10BASET_FD
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|TULIP_21041P2_SIACONN_10BASET_FD
value|0x0000EF01L
end_define

begin_define
define|#
directive|define
name|TULIP_21041P2_SIATXRX_10BASET_FD
value|0x0000FFFFL
end_define

begin_define
define|#
directive|define
name|TULIP_21041P2_SIAGEN_10BASET_FD
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|TULIP_21041_SIACONN_AUI
value|0x0000EF09L
end_define

begin_define
define|#
directive|define
name|TULIP_21041_SIATXRX_AUI
value|0x0000F73DL
end_define

begin_define
define|#
directive|define
name|TULIP_21041_SIAGEN_AUI
value|0x0000000EL
end_define

begin_define
define|#
directive|define
name|TULIP_21041P2_SIACONN_AUI
value|0x0000EF09L
end_define

begin_define
define|#
directive|define
name|TULIP_21041P2_SIATXRX_AUI
value|0x0000F7FDL
end_define

begin_define
define|#
directive|define
name|TULIP_21041P2_SIAGEN_AUI
value|0x0000000EL
end_define

begin_define
define|#
directive|define
name|TULIP_21041_SIACONN_BNC
value|0x0000EF09L
end_define

begin_define
define|#
directive|define
name|TULIP_21041_SIATXRX_BNC
value|0x0000F73DL
end_define

begin_define
define|#
directive|define
name|TULIP_21041_SIAGEN_BNC
value|0x00000006L
end_define

begin_define
define|#
directive|define
name|TULIP_21041P2_SIACONN_BNC
value|0x0000EF09L
end_define

begin_define
define|#
directive|define
name|TULIP_21041P2_SIATXRX_BNC
value|0x0000F7FDL
end_define

begin_define
define|#
directive|define
name|TULIP_21041P2_SIAGEN_BNC
value|0x00000006L
end_define

begin_comment
comment|/*  * 21142 SIA definitions  */
end_comment

begin_define
define|#
directive|define
name|TULIP_21142_PROBE_10BASET_TIMEOUT
value|2500
end_define

begin_define
define|#
directive|define
name|TULIP_21142_PROBE_AUIBNC_TIMEOUT
value|300
end_define

begin_define
define|#
directive|define
name|TULIP_21142_SIACONN_10BASET
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|TULIP_21142_SIATXRX_10BASET
value|0x00007F3FL
end_define

begin_define
define|#
directive|define
name|TULIP_21142_SIAGEN_10BASET
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|TULIP_21142_SIACONN_10BASET_FD
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|TULIP_21142_SIATXRX_10BASET_FD
value|0x00007F3DL
end_define

begin_define
define|#
directive|define
name|TULIP_21142_SIAGEN_10BASET_FD
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|TULIP_21142_SIACONN_AUI
value|0x00000009L
end_define

begin_define
define|#
directive|define
name|TULIP_21142_SIATXRX_AUI
value|0x00000705L
end_define

begin_define
define|#
directive|define
name|TULIP_21142_SIAGEN_AUI
value|0x0000000EL
end_define

begin_define
define|#
directive|define
name|TULIP_21142_SIACONN_BNC
value|0x00000009L
end_define

begin_define
define|#
directive|define
name|TULIP_21142_SIATXRX_BNC
value|0x00000705L
end_define

begin_define
define|#
directive|define
name|TULIP_21142_SIAGEN_BNC
value|0x00000006L
end_define

begin_define
define|#
directive|define
name|TULIP_WATCHDOG_TXDISABLE
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|TULIP_WATCHDOG_RXDISABLE
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_SWRESET
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_DESCSKIPLEN_MASK
value|0x0000007CL
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_BIGENDIAN
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_BURSTLEN_MASK
value|0x00003F00L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_BURSTLEN_DEFAULT
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_BURSTLEN_1LW
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_BURSTLEN_2LW
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_BURSTLEN_4LW
value|0x00000400L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_BURSTLEN_8LW
value|0x00000800L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_BURSTLEN_16LW
value|0x00001000L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_BURSTLEN_32LW
value|0x00002000L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_CACHE_NOALIGN
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_CACHE_ALIGN8
value|0x00004000L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_CACHE_ALIGN16
value|0x00008000L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_CACHE_ALIGN32
value|0x0000C000L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_TXPOLL_NEVER
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_TXPOLL_200000ns
value|0x00020000L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_TXPOLL_800000ns
value|0x00040000L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_TXPOLL_1600000ns
value|0x00060000L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_TXPOLL_12800ns
value|0x00080000L
end_define

begin_comment
comment|/* 21041 only */
end_comment

begin_define
define|#
directive|define
name|TULIP_BUSMODE_TXPOLL_25600ns
value|0x000A0000L
end_define

begin_comment
comment|/* 21041 only */
end_comment

begin_define
define|#
directive|define
name|TULIP_BUSMODE_TXPOLL_51200ns
value|0x000C0000L
end_define

begin_comment
comment|/* 21041 only */
end_comment

begin_define
define|#
directive|define
name|TULIP_BUSMODE_TXPOLL_102400ns
value|0x000E0000L
end_define

begin_comment
comment|/* 21041 only */
end_comment

begin_define
define|#
directive|define
name|TULIP_BUSMODE_DESC_BIGENDIAN
value|0x00100000L
end_define

begin_comment
comment|/* 21041 only */
end_comment

begin_define
define|#
directive|define
name|TULIP_BUSMODE_READMULTIPLE
value|0x00200000L
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|TULIP_REG_CFDA
value|0x40
end_define

begin_define
define|#
directive|define
name|TULIP_CFDA_SLEEP
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|TULIP_CFDA_SNOOZE
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|TULIP_GP_PINSET
value|0x00000100L
end_define

begin_comment
comment|/*  * These are the defintitions used for the DEC 21140  * evaluation board.  */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_EB_PINS
value|0x0000001F
end_define

begin_comment
comment|/* General Purpose Pin directions */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_EB_OK10
value|0x00000080
end_define

begin_comment
comment|/* 10 Mb/sec Signal Detect gep<7> */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_EB_OK100
value|0x00000040
end_define

begin_comment
comment|/* 100 Mb/sec Signal Detect gep<6> */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_EB_INIT
value|0x0000000B
end_define

begin_comment
comment|/* No loopback --- point-to-point */
end_comment

begin_comment
comment|/*  * These are the defintitions used for the SMC9332 (21140) board.  */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_SMC_9332_PINS
value|0x0000003F
end_define

begin_comment
comment|/* General Purpose Pin directions */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_SMC_9332_OK10
value|0x00000080
end_define

begin_comment
comment|/* 10 Mb/sec Signal Detect gep<7> */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_SMC_9332_OK100
value|0x00000040
end_define

begin_comment
comment|/* 100 Mb/sec Signal Detect gep<6> */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_SMC_9332_INIT
value|0x00000009
end_define

begin_comment
comment|/* No loopback --- point-to-point */
end_comment

begin_define
define|#
directive|define
name|TULIP_OUI_SMC_0
value|0x00
end_define

begin_define
define|#
directive|define
name|TULIP_OUI_SMC_1
value|0x00
end_define

begin_define
define|#
directive|define
name|TULIP_OUI_SMC_2
value|0xC0
end_define

begin_comment
comment|/*  * There are the definitions used for the DEC DE500  * 10/100 family of boards  */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_DE500_PINS
value|0x0000001FL
end_define

begin_define
define|#
directive|define
name|TULIP_GP_DE500_LINK_PASS
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|TULIP_GP_DE500_SYM_LINK
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|TULIP_GP_DE500_SIGNAL_DETECT
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|TULIP_GP_DE500_PHY_RESET
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|TULIP_GP_DE500_HALFDUPLEX
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|TULIP_GP_DE500_PHY_LOOPBACK
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|TULIP_GP_DE500_FORCE_LED
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|TULIP_GP_DE500_FORCE_100
value|0x00000001L
end_define

begin_comment
comment|/*  * These are the defintitions used for the Cogent EM100  * 21140 board.  */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_EM100_PINS
value|0x0000003F
end_define

begin_comment
comment|/* General Purpose Pin directions */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_EM100_INIT
value|0x00000009
end_define

begin_comment
comment|/* No loopback --- point-to-point */
end_comment

begin_define
define|#
directive|define
name|TULIP_OUI_COGENT_0
value|0x00
end_define

begin_define
define|#
directive|define
name|TULIP_OUI_COGENT_1
value|0x00
end_define

begin_define
define|#
directive|define
name|TULIP_OUI_COGENT_2
value|0x92
end_define

begin_define
define|#
directive|define
name|TULIP_COGENT_EM100TX_ID
value|0x12
end_define

begin_define
define|#
directive|define
name|TULIP_COGENT_EM100FX_ID
value|0x15
end_define

begin_comment
comment|/*  * These are the defintitions used for the Znyx ZX342  * 10/100 board  */
end_comment

begin_define
define|#
directive|define
name|TULIP_OUI_ZNYX_0
value|0x00
end_define

begin_define
define|#
directive|define
name|TULIP_OUI_ZNYX_1
value|0xC0
end_define

begin_define
define|#
directive|define
name|TULIP_OUI_ZNYX_2
value|0x95
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX312
value|0x0602
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX312T
value|0x0622
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX314_INTA
value|0x0701
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX314
value|0x0711
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX315_INTA
value|0x0801
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX315
value|0x0811
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX342
value|0x0901
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX342B
value|0x0921
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX342_X3
value|0x0902
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX342_X4
value|0x0903
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX344
value|0x0A01
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX351
value|0x0B01
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX345
value|0x0C01
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX311
value|0x0D01
end_define

begin_define
define|#
directive|define
name|TULIP_ZNYX_ID_ZX346
value|0x0E01
end_define

begin_define
define|#
directive|define
name|TULIP_GP_ZX34X_PINS
value|0x0000001F
end_define

begin_comment
comment|/* General Purpose Pin directions */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX344_PINS
value|0x0000000B
end_define

begin_comment
comment|/* General Purpose Pin directions */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX345_PINS
value|0x00000003
end_define

begin_comment
comment|/* General Purpose Pin directions */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX346_PINS
value|0x00000043
end_define

begin_comment
comment|/* General Purpose Pin directions */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX34X_LNKFAIL
value|0x00000080
end_define

begin_comment
comment|/* 10Mb/s Link Failure */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX34X_SYMDET
value|0x00000040
end_define

begin_comment
comment|/* 100Mb/s Symbol Detect */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX345_PHYACT
value|0x00000040
end_define

begin_comment
comment|/* PHY Activity */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX34X_SIGDET
value|0x00000020
end_define

begin_comment
comment|/* 100Mb/s Signal Detect */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX346_AUTONEG_ENABLED
value|0x00000020
end_define

begin_comment
comment|/* 802.3u autoneg enabled */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX342_COLENA
value|0x00000008
end_define

begin_comment
comment|/* 10t Ext LB */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX344_ROTINT
value|0x00000008
end_define

begin_comment
comment|/* PPB IRQ rotation */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX345_SPEED10
value|0x00000008
end_define

begin_comment
comment|/* 10Mb speed detect */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX346_SPEED100
value|0x00000008
end_define

begin_comment
comment|/* 100Mb speed detect */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX34X_NCOLENA
value|0x00000004
end_define

begin_comment
comment|/* 10t Int LB */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX34X_RXMATCH
value|0x00000004
end_define

begin_comment
comment|/* RX Match */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX346_FULLDUPLEX
value|0x00000004
end_define

begin_comment
comment|/* Full Duplex Sensed */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX34X_LB102
value|0x00000002
end_define

begin_comment
comment|/* 100tx twister LB */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX34X_NLB101
value|0x00000001
end_define

begin_comment
comment|/* PDT/PDR LB */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ZX34X_INIT
value|0x00000009
end_define

begin_comment
comment|/*  * Compex's OUI.  We need to twiddle a bit on their 21041 card.  */
end_comment

begin_define
define|#
directive|define
name|TULIP_OUI_COMPEX_0
value|0x00
end_define

begin_define
define|#
directive|define
name|TULIP_OUI_COMPEX_1
value|0x80
end_define

begin_define
define|#
directive|define
name|TULIP_OUI_COMPEX_2
value|0x48
end_define

begin_define
define|#
directive|define
name|TULIP_21041_COMPEX_XREGDATA
value|1
end_define

begin_comment
comment|/*  * Asante's OUI and stuff...  */
end_comment

begin_define
define|#
directive|define
name|TULIP_OUI_ASANTE_0
value|0x00
end_define

begin_define
define|#
directive|define
name|TULIP_OUI_ASANTE_1
value|0x00
end_define

begin_define
define|#
directive|define
name|TULIP_OUI_ASANTE_2
value|0x94
end_define

begin_define
define|#
directive|define
name|TULIP_GP_ASANTE_PINS
value|0x000000bf
end_define

begin_comment
comment|/* GP pin config */
end_comment

begin_define
define|#
directive|define
name|TULIP_GP_ASANTE_PHYRESET
value|0x00000008
end_define

begin_comment
comment|/* Reset PHY */
end_comment

begin_comment
comment|/*  * ACCTON EN1207 specialties  */
end_comment

begin_define
define|#
directive|define
name|TULIP_OUI_EN1207_0
value|0x00
end_define

begin_define
define|#
directive|define
name|TULIP_OUI_EN1207_1
value|0x00
end_define

begin_define
define|#
directive|define
name|TULIP_OUI_EN1207_2
value|0xE8
end_define

begin_define
define|#
directive|define
name|TULIP_CSR8_EN1207
value|0x08
end_define

begin_define
define|#
directive|define
name|TULIP_CSR9_EN1207
value|0x00
end_define

begin_define
define|#
directive|define
name|TULIP_CSR10_EN1207
value|0x03
end_define

begin_define
define|#
directive|define
name|TULIP_CSR11_EN1207
value|0x1F
end_define

begin_define
define|#
directive|define
name|TULIP_GP_EN1207_BNC_INIT
value|0x0000011B
end_define

begin_define
define|#
directive|define
name|TULIP_GP_EN1207_UTP_INIT
value|0x9E00000B
end_define

begin_define
define|#
directive|define
name|TULIP_GP_EN1207_100_INIT
value|0x6D00031B
end_define

begin_comment
comment|/*  * SROM definitions for the 21140 and 21041.  */
end_comment

begin_define
define|#
directive|define
name|SROMXREG
value|0x0400
end_define

begin_define
define|#
directive|define
name|SROMSEL
value|0x0800
end_define

begin_define
define|#
directive|define
name|SROMRD
value|0x4000
end_define

begin_define
define|#
directive|define
name|SROMWR
value|0x2000
end_define

begin_define
define|#
directive|define
name|SROMDIN
value|0x0008
end_define

begin_define
define|#
directive|define
name|SROMDOUT
value|0x0004
end_define

begin_define
define|#
directive|define
name|SROMDOUTON
value|0x0004
end_define

begin_define
define|#
directive|define
name|SROMDOUTOFF
value|0x0004
end_define

begin_define
define|#
directive|define
name|SROMCLKON
value|0x0002
end_define

begin_define
define|#
directive|define
name|SROMCLKOFF
value|0x0002
end_define

begin_define
define|#
directive|define
name|SROMCSON
value|0x0001
end_define

begin_define
define|#
directive|define
name|SROMCSOFF
value|0x0001
end_define

begin_define
define|#
directive|define
name|SROMCS
value|0x0001
end_define

begin_define
define|#
directive|define
name|SROMCMD_MODE
value|4
end_define

begin_define
define|#
directive|define
name|SROMCMD_WR
value|5
end_define

begin_define
define|#
directive|define
name|SROMCMD_RD
value|6
end_define

begin_define
define|#
directive|define
name|SROM_BITWIDTH
value|6
end_define

begin_comment
comment|/*  * MII Definitions for the 21041 and 21140/21140A/21142  */
end_comment

begin_define
define|#
directive|define
name|MII_PREAMBLE
value|(~0)
end_define

begin_define
define|#
directive|define
name|MII_TEST
value|0xAAAAAAAA
end_define

begin_define
define|#
directive|define
name|MII_RDCMD
value|0xF6
end_define

begin_comment
comment|/* 1111.0110 */
end_comment

begin_define
define|#
directive|define
name|MII_WRCMD
value|0xF5
end_define

begin_comment
comment|/* 1111.0101 */
end_comment

begin_define
define|#
directive|define
name|MII_DIN
value|0x00080000
end_define

begin_define
define|#
directive|define
name|MII_RD
value|0x00040000
end_define

begin_define
define|#
directive|define
name|MII_WR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MII_DOUT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MII_CLK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MII_CLKON
value|MII_CLK
end_define

begin_define
define|#
directive|define
name|MII_CLKOFF
value|MII_CLK
end_define

begin_define
define|#
directive|define
name|PHYREG_CONTROL
value|0
end_define

begin_define
define|#
directive|define
name|PHYREG_STATUS
value|1
end_define

begin_define
define|#
directive|define
name|PHYREG_IDLOW
value|2
end_define

begin_define
define|#
directive|define
name|PHYREG_IDHIGH
value|3
end_define

begin_define
define|#
directive|define
name|PHYREG_AUTONEG_ADVERTISEMENT
value|4
end_define

begin_define
define|#
directive|define
name|PHYREG_AUTONEG_ABILITIES
value|5
end_define

begin_define
define|#
directive|define
name|PHYREG_AUTONEG_EXPANSION
value|6
end_define

begin_define
define|#
directive|define
name|PHYREG_AUTONEG_NEXTPAGE
value|7
end_define

begin_define
define|#
directive|define
name|PHYSTS_100BASET4
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHYSTS_100BASETX_FD
value|0x4000
end_define

begin_define
define|#
directive|define
name|PHYSTS_100BASETX
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHYSTS_10BASET_FD
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHYSTS_10BASET
value|0x0800
end_define

begin_define
define|#
directive|define
name|PHYSTS_AUTONEG_DONE
value|0x0020
end_define

begin_define
define|#
directive|define
name|PHYSTS_REMOTE_FAULT
value|0x0010
end_define

begin_define
define|#
directive|define
name|PHYSTS_CAN_AUTONEG
value|0x0008
end_define

begin_define
define|#
directive|define
name|PHYSTS_LINK_UP
value|0x0004
end_define

begin_define
define|#
directive|define
name|PHYSTS_JABBER_DETECT
value|0x0002
end_define

begin_define
define|#
directive|define
name|PHYSTS_EXTENDED_REGS
value|0x0001
end_define

begin_define
define|#
directive|define
name|PHYCTL_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHYCTL_SELECT_100MB
value|0x2000
end_define

begin_define
define|#
directive|define
name|PHYCTL_AUTONEG_ENABLE
value|0x1000
end_define

begin_define
define|#
directive|define
name|PHYCTL_ISOLATE
value|0x0400
end_define

begin_define
define|#
directive|define
name|PHYCTL_AUTONEG_RESTART
value|0x0200
end_define

begin_define
define|#
directive|define
name|PHYCTL_FULL_DUPLEX
value|0x0100
end_define

begin_comment
comment|/*  * Definitions for the DE425.  */
end_comment

begin_define
define|#
directive|define
name|DE425_CFID
value|0x08
end_define

begin_comment
comment|/* Configuration Id */
end_comment

begin_define
define|#
directive|define
name|DE425_CFCS
value|0x0C
end_define

begin_comment
comment|/* Configuration Command-Status */
end_comment

begin_define
define|#
directive|define
name|DE425_CFRV
value|0x18
end_define

begin_comment
comment|/* Configuration Revision */
end_comment

begin_define
define|#
directive|define
name|DE425_CFLT
value|0x1C
end_define

begin_comment
comment|/* Configuration Latency Timer */
end_comment

begin_define
define|#
directive|define
name|DE425_CBIO
value|0x28
end_define

begin_comment
comment|/* Configuration Base IO Address */
end_comment

begin_define
define|#
directive|define
name|DE425_CFDA
value|0x2C
end_define

begin_comment
comment|/* Configuration Driver Area */
end_comment

begin_define
define|#
directive|define
name|DE425_ENETROM_OFFSET
value|0xC90
end_define

begin_comment
comment|/* Offset in I/O space for ENETROM */
end_comment

begin_define
define|#
directive|define
name|DE425_CFG0
value|0xC88
end_define

begin_comment
comment|/* IRQ register */
end_comment

begin_define
define|#
directive|define
name|DE425_EISAID
value|0x10a34250
end_define

begin_comment
comment|/* EISA device id */
end_comment

begin_define
define|#
directive|define
name|DE425_EISA_IOSIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|DEC_VENDORID
value|0x1011
end_define

begin_define
define|#
directive|define
name|CHIPID_21040
value|0x0002
end_define

begin_define
define|#
directive|define
name|CHIPID_21140
value|0x0009
end_define

begin_define
define|#
directive|define
name|CHIPID_21041
value|0x0014
end_define

begin_define
define|#
directive|define
name|CHIPID_21142
value|0x0019
end_define

begin_define
define|#
directive|define
name|PCI_VENDORID
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|PCI_CHIPID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_comment
comment|/*  * Generic SROM Format  *  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|sh_idbuf
index|[
literal|18
index|]
decl_stmt|;
name|u_int8_t
name|sh_version
decl_stmt|;
name|u_int8_t
name|sh_adapter_count
decl_stmt|;
name|u_int8_t
name|sh_ieee802_address
index|[
literal|6
index|]
decl_stmt|;
block|}
name|tulip_srom_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int8_t
name|sai_device
decl_stmt|;
name|u_int8_t
name|sai_leaf_offset_lowbyte
decl_stmt|;
name|u_int8_t
name|sai_leaf_offset_highbyte
decl_stmt|;
block|}
name|tulip_srom_adapter_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|TULIP_SROM_CONNTYPE_10BASET
init|=
literal|0x0000
block|,
name|TULIP_SROM_CONNTYPE_BNC
init|=
literal|0x0001
block|,
name|TULIP_SROM_CONNTYPE_AUI
init|=
literal|0x0002
block|,
name|TULIP_SROM_CONNTYPE_100BASETX
init|=
literal|0x0003
block|,
name|TULIP_SROM_CONNTYPE_100BASET4
init|=
literal|0x0006
block|,
name|TULIP_SROM_CONNTYPE_100BASEFX
init|=
literal|0x0007
block|,
name|TULIP_SROM_CONNTYPE_MII_10BASET
init|=
literal|0x0009
block|,
name|TULIP_SROM_CONNTYPE_MII_100BASETX
init|=
literal|0x000D
block|,
name|TULIP_SROM_CONNTYPE_MII_100BASET4
init|=
literal|0x000F
block|,
name|TULIP_SROM_CONNTYPE_MII_100BASEFX
init|=
literal|0x0010
block|,
name|TULIP_SROM_CONNTYPE_10BASET_NWAY
init|=
literal|0x0100
block|,
name|TULIP_SROM_CONNTYPE_10BASET_FD
init|=
literal|0x0204
block|,
name|TULIP_SROM_CONNTYPE_MII_10BASET_FD
init|=
literal|0x020A
block|,
name|TULIP_SROM_CONNTYPE_100BASETX_FD
init|=
literal|0x020E
block|,
name|TULIP_SROM_CONNTYPE_MII_100BASETX_FD
init|=
literal|0x0211
block|,
name|TULIP_SROM_CONNTYPE_10BASET_NOLINKPASS
init|=
literal|0x0400
block|,
name|TULIP_SROM_CONNTYPE_AUTOSENSE
init|=
literal|0x0800
block|,
name|TULIP_SROM_CONNTYPE_AUTOSENSE_POWERUP
init|=
literal|0x8800
block|,
name|TULIP_SROM_CONNTYPE_AUTOSENSE_NWAY
init|=
literal|0x9000
block|,
name|TULIP_SROM_CONNTYPE_NOT_USED
init|=
literal|0xFFFF
block|}
name|tulip_srom_connection_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|TULIP_SROM_MEDIA_10BASET
init|=
literal|0x0000
block|,
name|TULIP_SROM_MEDIA_BNC
init|=
literal|0x0001
block|,
name|TULIP_SROM_MEDIA_AUI
init|=
literal|0x0002
block|,
name|TULIP_SROM_MEDIA_100BASETX
init|=
literal|0x0003
block|,
name|TULIP_SROM_MEDIA_10BASET_FD
init|=
literal|0x0004
block|,
name|TULIP_SROM_MEDIA_100BASETX_FD
init|=
literal|0x0005
block|,
name|TULIP_SROM_MEDIA_100BASET4
init|=
literal|0x0006
block|,
name|TULIP_SROM_MEDIA_100BASEFX
init|=
literal|0x0007
block|,
name|TULIP_SROM_MEDIA_100BASEFX_FD
init|=
literal|0x0008
block|}
name|tulip_srom_media_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TULIP_SROM_21041_EXTENDED
value|0x40
end_define

begin_define
define|#
directive|define
name|TULIP_SROM_2114X_NOINDICATOR
value|0x8000
end_define

begin_define
define|#
directive|define
name|TULIP_SROM_2114X_DEFAULT
value|0x4000
end_define

begin_define
define|#
directive|define
name|TULIP_SROM_2114X_POLARITY
value|0x0080
end_define

begin_define
define|#
directive|define
name|TULIP_SROM_2114X_CMDBITS
parameter_list|(
name|n
parameter_list|)
value|(((n)& 0x0071)<< 18)
end_define

begin_define
define|#
directive|define
name|TULIP_SROM_2114X_BITPOS
parameter_list|(
name|b
parameter_list|)
value|(1<< (((b)& 0x0E)>> 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_DC21040_H) */
end_comment

end_unit

