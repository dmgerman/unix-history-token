begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)if_ilreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * Interlan Ethernet Communications Controller interface  */
end_comment

begin_struct
struct|struct
name|ildevice
block|{
name|short
name|il_csr
decl_stmt|;
comment|/* Command and Status Register */
name|short
name|il_bar
decl_stmt|;
comment|/* Buffer Address Register */
name|short
name|il_bcr
decl_stmt|;
comment|/* Byte Count Register */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Command and status bits  */
end_comment

begin_define
define|#
directive|define
name|IL_EUA
value|0xc000
end_define

begin_comment
comment|/* Extended Unibus Address */
end_comment

begin_define
define|#
directive|define
name|IL_CMD
value|0x3f00
end_define

begin_comment
comment|/* Command Function Code */
end_comment

begin_define
define|#
directive|define
name|IL_CDONE
value|0x0080
end_define

begin_comment
comment|/* Command Done */
end_comment

begin_define
define|#
directive|define
name|IL_CIE
value|0x0040
end_define

begin_comment
comment|/* Command Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|IL_RDONE
value|0x0020
end_define

begin_comment
comment|/* Receive DMA Done */
end_comment

begin_define
define|#
directive|define
name|IL_RIE
value|0x0010
end_define

begin_comment
comment|/* Receive Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|IL_STATUS
value|0x000f
end_define

begin_comment
comment|/* Command Status Code */
end_comment

begin_define
define|#
directive|define
name|IL_BITS
value|"\20\10CDONE\7CIE\6RDONE\5RIE"
end_define

begin_comment
comment|/* command definitions */
end_comment

begin_define
define|#
directive|define
name|ILC_MLPBAK
value|0x0100
end_define

begin_comment
comment|/* Set Module Interface Loopback Mode */
end_comment

begin_define
define|#
directive|define
name|ILC_ILPBAK
value|0x0200
end_define

begin_comment
comment|/* Set Internal Loopback Mode */
end_comment

begin_define
define|#
directive|define
name|ILC_CLPBAK
value|0x0300
end_define

begin_comment
comment|/* Clear Loopback Mode */
end_comment

begin_define
define|#
directive|define
name|ILC_PRMSC
value|0x0400
end_define

begin_comment
comment|/* Set Promiscuous Receive Mode */
end_comment

begin_define
define|#
directive|define
name|ILC_CLPRMSC
value|0x0500
end_define

begin_comment
comment|/* Clear Promiscuous Receive Mode */
end_comment

begin_define
define|#
directive|define
name|ILC_RCVERR
value|0x0600
end_define

begin_comment
comment|/* Set Receive-On-Error Bit */
end_comment

begin_define
define|#
directive|define
name|ILC_CRCVERR
value|0x0700
end_define

begin_comment
comment|/* Clear Receive-On-Error Bit */
end_comment

begin_define
define|#
directive|define
name|ILC_OFFLINE
value|0x0800
end_define

begin_comment
comment|/* Go Offline */
end_comment

begin_define
define|#
directive|define
name|ILC_ONLINE
value|0x0900
end_define

begin_comment
comment|/* Go Online */
end_comment

begin_define
define|#
directive|define
name|ILC_DIAG
value|0x0a00
end_define

begin_comment
comment|/* Run On-board Diagnostics */
end_comment

begin_define
define|#
directive|define
name|ILC_ISA
value|0x0d00
end_define

begin_comment
comment|/* Set Insert Source Address Mode */
end_comment

begin_define
define|#
directive|define
name|ILC_CISA
value|0x0e00
end_define

begin_comment
comment|/* Clear Insert Source Address Mode */
end_comment

begin_define
define|#
directive|define
name|ILC_DEFPA
value|0x0f00
end_define

begin_comment
comment|/* Set Physical Address to Default */
end_comment

begin_define
define|#
directive|define
name|ILC_ALLMC
value|0x1000
end_define

begin_comment
comment|/* Set Receive All Multicast Packets */
end_comment

begin_define
define|#
directive|define
name|ILC_CALLMC
value|0x1100
end_define

begin_comment
comment|/* Clear Receive All Multicast */
end_comment

begin_define
define|#
directive|define
name|ILC_STAT
value|0x1800
end_define

begin_comment
comment|/* Report and Reset Statistics */
end_comment

begin_define
define|#
directive|define
name|ILC_DELAYS
value|0x1900
end_define

begin_comment
comment|/* Report Collision Delay Times */
end_comment

begin_define
define|#
directive|define
name|ILC_RCV
value|0x2000
end_define

begin_comment
comment|/* Supply Receive Buffer */
end_comment

begin_define
define|#
directive|define
name|ILC_LDXMIT
value|0x2800
end_define

begin_comment
comment|/* Load Transmit Data */
end_comment

begin_define
define|#
directive|define
name|ILC_XMIT
value|0x2900
end_define

begin_comment
comment|/* Load Transmit Data and Send */
end_comment

begin_define
define|#
directive|define
name|ILC_LDGRPS
value|0x2a00
end_define

begin_comment
comment|/* Load Group Addresses */
end_comment

begin_define
define|#
directive|define
name|ILC_RMGRPS
value|0x2b00
end_define

begin_comment
comment|/* Delete Group Addresses */
end_comment

begin_define
define|#
directive|define
name|ILC_LDPA
value|0x2c00
end_define

begin_comment
comment|/* Load Physical Address */
end_comment

begin_define
define|#
directive|define
name|ILC_FLUSH
value|0x3000
end_define

begin_comment
comment|/* Flush Receive BAR/BCR Queue */
end_comment

begin_define
define|#
directive|define
name|ILC_RESET
value|0x3f00
end_define

begin_comment
comment|/* Reset */
end_comment

begin_comment
comment|/*  * Error codes found in the status bits of the csr.  */
end_comment

begin_define
define|#
directive|define
name|ILERR_SUCCESS
value|0
end_define

begin_comment
comment|/* command successful */
end_comment

begin_define
define|#
directive|define
name|ILERR_RETRIES
value|1
end_define

begin_comment
comment|/* " " with retries */
end_comment

begin_define
define|#
directive|define
name|ILERR_BADCMD
value|2
end_define

begin_comment
comment|/* illegal command */
end_comment

begin_define
define|#
directive|define
name|ILERR_INVCMD
value|3
end_define

begin_comment
comment|/* invalid command */
end_comment

begin_define
define|#
directive|define
name|ILERR_RECVERR
value|4
end_define

begin_comment
comment|/* receiver error */
end_comment

begin_define
define|#
directive|define
name|ILERR_BUFSIZ
value|5
end_define

begin_comment
comment|/* buffer size too big */
end_comment

begin_define
define|#
directive|define
name|ILERR_FRAMESIZ
value|6
end_define

begin_comment
comment|/* frame size too small */
end_comment

begin_define
define|#
directive|define
name|ILERR_COLLISIONS
value|8
end_define

begin_comment
comment|/* excessive collisions */
end_comment

begin_define
define|#
directive|define
name|ILERR_BUFALIGNMENT
value|10
end_define

begin_comment
comment|/* buffer not word aligned */
end_comment

begin_define
define|#
directive|define
name|ILERR_NXM
value|15
end_define

begin_comment
comment|/* non-existent memory */
end_comment

begin_define
define|#
directive|define
name|NILERRS
value|16
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ILERRS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ilerrs
index|[
name|NILERRS
index|]
init|=
block|{
literal|"success"
block|,
comment|/*  0 */
literal|"success with retries"
block|,
comment|/*  1 */
literal|"illegal command"
block|,
comment|/*  2 */
literal|"inappropriate command"
block|,
comment|/*  3 */
literal|"failure"
block|,
comment|/*  4 */
literal|"buffer size exceeded"
block|,
comment|/*  5 */
literal|"frame too small"
block|,
comment|/*  6 */
literal|0
block|,
comment|/*  7 */
literal|"excessive collisions"
block|,
comment|/*  8 */
literal|0
block|,
comment|/*  9 */
literal|"buffer alignment error"
block|,
comment|/* 10 */
literal|0
block|,
comment|/* 11 */
literal|0
block|,
comment|/* 12 */
literal|0
block|,
comment|/* 13 */
literal|0
block|,
comment|/* 14 */
literal|"non-existent memory"
comment|/* 15 */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Diagnostics codes.  */
end_comment

begin_define
define|#
directive|define
name|ILDIAG_SUCCESS
value|0
end_define

begin_comment
comment|/* no problems */
end_comment

begin_define
define|#
directive|define
name|ILDIAG_CHKSUMERR
value|1
end_define

begin_comment
comment|/* ROM/RAM checksum error */
end_comment

begin_define
define|#
directive|define
name|ILDIAG_DMAERR
value|2
end_define

begin_comment
comment|/* DMA not working */
end_comment

begin_define
define|#
directive|define
name|ILDIAG_XMITERR
value|3
end_define

begin_comment
comment|/* xmit circuitry failure */
end_comment

begin_define
define|#
directive|define
name|ILDIAG_RECVERR
value|4
end_define

begin_comment
comment|/* rcvr circuitry failure */
end_comment

begin_define
define|#
directive|define
name|ILDIAG_LOOPBACK
value|5
end_define

begin_comment
comment|/* loopback test failed */
end_comment

begin_define
define|#
directive|define
name|NILDIAGS
value|6
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ILDIAGS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ildiag
index|[
name|NILDIAGS
index|]
init|=
block|{
literal|"success"
block|,
comment|/* 0 */
literal|"checksum error"
block|,
comment|/* 1 */
literal|"NM10 dma error"
block|,
comment|/* 2 */
literal|"transmitter error"
block|,
comment|/* 3 */
literal|"receiver error"
block|,
comment|/* 4 */
literal|"loopback failure"
block|,
comment|/* 5 */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Frame status bits, returned in frame status byte  * at the top of each received packet.  */
end_comment

begin_define
define|#
directive|define
name|ILFSTAT_C
value|0x1
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|ILFSTAT_A
value|0x2
end_define

begin_comment
comment|/* alignment error */
end_comment

begin_define
define|#
directive|define
name|ILFSTAT_L
value|0x4
end_define

begin_comment
comment|/* 1+ frames lost just before */
end_comment

end_unit

