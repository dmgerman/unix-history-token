begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_ilreg.h	4.1	82/05/21	*/
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
value|0xC000
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
value|"\10\10CDONE\7CIE\6RDONE\5RIE"
end_define

begin_comment
comment|/* Command definitions */
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
comment|/*  * Error codes  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ilerrs
index|[]
init|=
block|{
literal|"success"
block|,
comment|/* 0 */
literal|"success with retries"
block|,
comment|/* 01 */
literal|"illegal command"
block|,
comment|/* 02 */
literal|"inappropriate command"
block|,
comment|/* 03 */
literal|"failure"
block|,
comment|/* 04 */
literal|"buffer size exceeded"
block|,
comment|/* 05 */
literal|"frame too small"
block|,
comment|/* 06 */
literal|0
block|,
comment|/* 07 */
literal|"excessive collisions"
block|,
comment|/* 010 */
literal|0
block|,
comment|/* 011 */
literal|"buffer alignment error"
block|,
comment|/* 012 */
literal|0
block|,
comment|/* 013 */
literal|0
block|,
comment|/* 014 */
literal|0
block|,
comment|/* 015 */
literal|0
block|,
comment|/* 016 */
literal|"non-existent memory"
comment|/* 017 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ildiag
index|[]
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

end_unit

