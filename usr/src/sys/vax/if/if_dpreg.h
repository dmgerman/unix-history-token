begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)if_dpreg.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * DPV-11 Registers and bits.  */
end_comment

begin_struct
struct|struct
name|dpdevice
block|{
name|short
name|dprcsr
decl_stmt|;
comment|/* Receive Control and Status Register */
union|union
block|{
name|short
name|u_rdsr
decl_stmt|;
comment|/* Receive Data and Status Reg, rd only */
name|short
name|u_sar
decl_stmt|;
comment|/* Parameter Control Sync/Address Reg, wr only*/
block|}
name|dpun
union|;
name|short
name|dpclr
decl_stmt|;
comment|/* Parameter Control/Character Length Reg */
name|short
name|dptdsr
decl_stmt|;
comment|/* Transmit Data and Status Register */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dprdsr
value|dpun.u_rdsr
end_define

begin_define
define|#
directive|define
name|dpsar
value|dpun.u_sar
end_define

begin_comment
comment|/* bits in dprcsr */
end_comment

begin_define
define|#
directive|define
name|DP_RL
value|0x0001
end_define

begin_comment
comment|/* Remote Loopback Mode */
end_comment

begin_define
define|#
directive|define
name|DP_DTR
value|0x0002
end_define

begin_comment
comment|/* Data Terminal Ready (modem) */
end_comment

begin_define
define|#
directive|define
name|DP_RTS
value|0x0004
end_define

begin_comment
comment|/* Request to Send (modem) */
end_comment

begin_define
define|#
directive|define
name|DP_LL
value|0x0008
end_define

begin_comment
comment|/* Local Loopback */
end_comment

begin_define
define|#
directive|define
name|DP_RE
value|0x0010
end_define

begin_comment
comment|/* Enable Receiver */
end_comment

begin_define
define|#
directive|define
name|DP_MIE
value|0x0020
end_define

begin_comment
comment|/* Modem (Change) Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|DP_RIE
value|0x0040
end_define

begin_comment
comment|/* Receiver Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|DP_RDR
value|0x0080
end_define

begin_comment
comment|/* Receiver Data Ready */
end_comment

begin_define
define|#
directive|define
name|DP_SFD
value|0x0100
end_define

begin_comment
comment|/* Sync or Flag Detected */
end_comment

begin_define
define|#
directive|define
name|DP_DSR
value|0x0200
end_define

begin_comment
comment|/* Data Set Ready (modem) */
end_comment

begin_define
define|#
directive|define
name|DP_RSR
value|0x0400
end_define

begin_comment
comment|/* Receiver Status Ready (attention) */
end_comment

begin_define
define|#
directive|define
name|DP_RA
value|0x0800
end_define

begin_comment
comment|/* Receiver Active (receiving data) */
end_comment

begin_define
define|#
directive|define
name|DP_RR
value|0x1000
end_define

begin_comment
comment|/* Receiver Ready (modem) */
end_comment

begin_define
define|#
directive|define
name|DP_CTS
value|0x2000
end_define

begin_comment
comment|/* Clear to Send (modem) */
end_comment

begin_define
define|#
directive|define
name|DP_IC
value|0x4000
end_define

begin_comment
comment|/* Incoming Call */
end_comment

begin_define
define|#
directive|define
name|DP_MSC
value|0x8000
end_define

begin_comment
comment|/* Modem Status Change (CTS, RR, IC, DM) */
end_comment

begin_comment
comment|/* flags for modem-control */
end_comment

begin_define
define|#
directive|define
name|DP_ON
value|DP_DTR
end_define

begin_define
define|#
directive|define
name|DP_OFF
value|0
end_define

begin_comment
comment|/* bits in dprdsr */
end_comment

begin_define
define|#
directive|define
name|DP_RBUF
value|0x00ff
end_define

begin_comment
comment|/* Received Data */
end_comment

begin_define
define|#
directive|define
name|DP_RSM
value|0x0100
end_define

begin_comment
comment|/* Receiver Start of Message */
end_comment

begin_define
define|#
directive|define
name|DP_REM
value|0x0200
end_define

begin_comment
comment|/* Receiver End of Message */
end_comment

begin_define
define|#
directive|define
name|DP_RGA
value|0x0400
end_define

begin_comment
comment|/* Receiver Go-Ahead or Abort */
end_comment

begin_define
define|#
directive|define
name|DP_ROVR
value|0x0800
end_define

begin_comment
comment|/* Receiver Receiver Over-Run */
end_comment

begin_define
define|#
directive|define
name|DP_RABC
value|0x7000
end_define

begin_comment
comment|/* Reciever Assembled Bit Count */
end_comment

begin_define
define|#
directive|define
name|DP_REC
value|0x8000
end_define

begin_comment
comment|/* Reciever Error Check */
end_comment

begin_comment
comment|/* bits in dpsar */
end_comment

begin_define
define|#
directive|define
name|DP_SYNC
value|0x00ff
end_define

begin_comment
comment|/* Sync Char or Station Address */
end_comment

begin_define
define|#
directive|define
name|DP_EM
value|0x0700
end_define

begin_comment
comment|/* Error Detection Mode */
end_comment

begin_define
define|#
directive|define
name|DP_IDLE
value|0x0800
end_define

begin_comment
comment|/* Idle Mode Select */
end_comment

begin_define
define|#
directive|define
name|DP_SAM
value|0x1000
end_define

begin_comment
comment|/* Secondary Address Mode */
end_comment

begin_define
define|#
directive|define
name|DP_SSLM
value|0x2000
end_define

begin_comment
comment|/* Strip Synch/Loop Mode */
end_comment

begin_define
define|#
directive|define
name|DP_CHRM
value|0x4000
end_define

begin_comment
comment|/* Character/Bit Mode */
end_comment

begin_define
define|#
directive|define
name|DP_APA
value|0x8000
end_define

begin_comment
comment|/* Recognize All Parties Addressed */
end_comment

begin_comment
comment|/* bits in dpclr */
end_comment

begin_define
define|#
directive|define
name|DP_CLR
value|0x0001
end_define

begin_comment
comment|/* Reset DP */
end_comment

begin_define
define|#
directive|define
name|DP_XA
value|0x0002
end_define

begin_comment
comment|/* Transmiter Active (transmitting data) */
end_comment

begin_define
define|#
directive|define
name|DP_XBE
value|0x0004
end_define

begin_comment
comment|/* Transmit Buffer Available */
end_comment

begin_define
define|#
directive|define
name|DP_ILB
value|0x0008
end_define

begin_comment
comment|/* Internal Loopback (Maintenance Mode) */
end_comment

begin_define
define|#
directive|define
name|DP_XE
value|0x0010
end_define

begin_comment
comment|/* Transmit Enable */
end_comment

begin_define
define|#
directive|define
name|DP_SQTM
value|0x0020
end_define

begin_comment
comment|/* Signal Quality/Test Mode */
end_comment

begin_define
define|#
directive|define
name|DP_XIE
value|0x0040
end_define

begin_comment
comment|/* Transmit Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|DP_MBZ1
value|0x0080
end_define

begin_comment
comment|/* Reserved (must be zero) */
end_comment

begin_define
define|#
directive|define
name|DP_RCL
value|0x0700
end_define

begin_comment
comment|/* Receive Character Length */
end_comment

begin_define
define|#
directive|define
name|DP_RL8
value|0x0000
end_define

begin_comment
comment|/* RCL = 8 bits */
end_comment

begin_define
define|#
directive|define
name|DP_RL7
value|0x0700
end_define

begin_comment
comment|/* RCL = 7 bits */
end_comment

begin_define
define|#
directive|define
name|DP_RL6
value|0x0600
end_define

begin_comment
comment|/* RCL = 6 bits */
end_comment

begin_define
define|#
directive|define
name|DP_ECF
value|0x0800
end_define

begin_comment
comment|/* Extended Control Field Option */
end_comment

begin_define
define|#
directive|define
name|DP_EAF
value|0x1000
end_define

begin_comment
comment|/* Extended Address Field Option */
end_comment

begin_define
define|#
directive|define
name|DP_XCL
value|0xE000
end_define

begin_comment
comment|/* Transmit Character Length */
end_comment

begin_define
define|#
directive|define
name|DP_XL8
value|0x0000
end_define

begin_comment
comment|/* XCL = 8 bits */
end_comment

begin_define
define|#
directive|define
name|DP_XL7
value|0xE000
end_define

begin_comment
comment|/* XCL = 7 bits */
end_comment

begin_define
define|#
directive|define
name|DP_XL6
value|0xC000
end_define

begin_comment
comment|/* XCL = 6 bits */
end_comment

begin_comment
comment|/* bits in dptdsr */
end_comment

begin_define
define|#
directive|define
name|DP_XBUF
value|0x00FF
end_define

begin_comment
comment|/* data to be transmitted */
end_comment

begin_define
define|#
directive|define
name|DP_XSM
value|0x0100
end_define

begin_comment
comment|/* Transmit Start of Message */
end_comment

begin_define
define|#
directive|define
name|DP_XEM
value|0x0200
end_define

begin_comment
comment|/* Transmit End of Message */
end_comment

begin_define
define|#
directive|define
name|DP_XABO
value|0x0400
end_define

begin_comment
comment|/* Tranmsit Abort */
end_comment

begin_define
define|#
directive|define
name|DP_XGA
value|0x0800
end_define

begin_comment
comment|/* Tranmsit Go - Ahead */
end_comment

begin_define
define|#
directive|define
name|DP_MBZ2
value|0x7000
end_define

begin_comment
comment|/* Reserved (must be zero) */
end_comment

begin_define
define|#
directive|define
name|DP_XERR
value|0x8000
end_define

begin_comment
comment|/* Data Late -- XBUF not serviced in time */
end_comment

begin_define
define|#
directive|define
name|DP_MTU
value|2048
end_define

begin_comment
comment|/* Very Big X.25 data, normally 128 */
end_comment

end_unit

