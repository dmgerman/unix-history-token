begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Matt Thomas (thomas@lkg.dec.com)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $Id: dc21040.h,v 1.2 1994/08/15 20:42:25 thomas Exp thomas $  *  * $Log: dc21040.h,v $  * Revision 1.2  1994/08/15  20:42:25  thomas  * misc additions  *  * Revision 1.1  1994/08/12  21:02:46  thomas  * Initial revision  *  * Revision 1.8  1994/08/05  20:20:54  thomas  * Enable change log  *  * Revision 1.7  1994/08/05  20:20:14  thomas  * *** empty log message ***  *  */
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

begin_typedef
typedef|typedef
name|signed
name|int
name|tulip_sint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|tulip_uint32_t
typedef|;
end_typedef

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
name|tulip_uint32_t
name|d_status
decl_stmt|;
name|tulip_uint32_t
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
name|tulip_uint32_t
name|d_addr1
decl_stmt|;
name|tulip_uint32_t
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
comment|/* Owner (1 = DC21040) */
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
comment|/*  * The DC21040 Registers (IO Space Addresses)  */
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
comment|/* (RW)  Link Failure */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_FULDPLXSHRT
value|0x00000800L
end_define

begin_comment
comment|/* (RW)  Full Duplex Short Fram Rcvd */
end_comment

begin_define
define|#
directive|define
name|TULIP_STS_AUI
value|0x00000400L
end_define

begin_comment
comment|/* (RW)  AUI/TP Switch */
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
comment|/* (RW)  Back Pressure (!802.3) */
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
name|TULIP_CMD_FULLDULPEX
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
name|TULIP_SIASTS_LINKFAIL
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|TULIP_SIACONN_RESET
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|TULIP_SIACONN_AUI
value|0x0000000DL
end_define

begin_define
define|#
directive|define
name|TULIP_SIACONN_10BASET
value|0x00000005L
end_define

begin_define
define|#
directive|define
name|TULIP_BUSMODE_SWRESET
value|0x00000001L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_DC21040_H) */
end_comment

end_unit

