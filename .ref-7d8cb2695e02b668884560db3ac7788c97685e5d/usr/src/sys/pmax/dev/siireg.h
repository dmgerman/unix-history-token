begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)siireg.h	7.1 (Berkeley) %G%  *  * sii.h --  *  * 	SII registers.  *  *	Copyright (C) 1989 Digital Equipment Corporation.  *	Permission to use, copy, modify, and distribute this software and  *	its documentation for any purpose and without fee is hereby granted,  *	provided that the above copyright notice appears in all copies.  *	Digital Equipment Corporation makes no representations about the  *	suitability of this software for any purpose.  It is provided "as is"  *	without express or implied warranty.  *  * from: $Header: /sprite/src/kernel/dev/ds3100.md/RCS/sii.h,  *	v 1.2 89/08/15 19:53:04 rab Exp $ SPRITE (DECWRL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SII
end_ifndef

begin_define
define|#
directive|define
name|_SII
end_define

begin_comment
comment|/*  * SII hardware registers  */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
struct|struct
block|{
name|u_short
name|sdb
decl_stmt|;
comment|/* SCSI Data Bus and Parity */
name|u_short
name|pad0
decl_stmt|;
name|u_short
name|sc1
decl_stmt|;
comment|/* SCSI Control Signals One */
name|u_short
name|pad1
decl_stmt|;
name|u_short
name|sc2
decl_stmt|;
comment|/* SCSI Control Signals Two */
name|u_short
name|pad2
decl_stmt|;
name|u_short
name|csr
decl_stmt|;
comment|/* Control/Status register */
name|u_short
name|pad3
decl_stmt|;
name|u_short
name|id
decl_stmt|;
comment|/* Bus ID register */
name|u_short
name|pad4
decl_stmt|;
name|u_short
name|slcsr
decl_stmt|;
comment|/* Select Control and Status Register */
name|u_short
name|pad5
decl_stmt|;
name|u_short
name|destat
decl_stmt|;
comment|/* Selection Detector Status Register */
name|u_short
name|pad6
decl_stmt|;
name|u_short
name|dstmo
decl_stmt|;
comment|/* DSSI Timeout Register */
name|u_short
name|pad7
decl_stmt|;
name|u_short
name|data
decl_stmt|;
comment|/* Data Register */
name|u_short
name|pad8
decl_stmt|;
name|u_short
name|dmctrl
decl_stmt|;
comment|/* DMA Control Register */
name|u_short
name|pad9
decl_stmt|;
name|u_short
name|dmlotc
decl_stmt|;
comment|/* DMA Length of Transfer Counter */
name|u_short
name|pad10
decl_stmt|;
name|u_short
name|dmaddrl
decl_stmt|;
comment|/* DMA Address Register Low */
name|u_short
name|pad11
decl_stmt|;
name|u_short
name|dmaddrh
decl_stmt|;
comment|/* DMA Address Register High */
name|u_short
name|pad12
decl_stmt|;
name|u_short
name|dmabyte
decl_stmt|;
comment|/* DMA Initial Byte Register */
name|u_short
name|pad13
decl_stmt|;
name|u_short
name|stlp
decl_stmt|;
comment|/* DSSI Short Target List Pointer */
name|u_short
name|pad14
decl_stmt|;
name|u_short
name|ltlp
decl_stmt|;
comment|/* DSSI Long Target List Pointer */
name|u_short
name|pad15
decl_stmt|;
name|u_short
name|ilp
decl_stmt|;
comment|/* DSSI Initiator List Pointer */
name|u_short
name|pad16
decl_stmt|;
name|u_short
name|dsctrl
decl_stmt|;
comment|/* DSSI Control Register */
name|u_short
name|pad17
decl_stmt|;
name|u_short
name|cstat
decl_stmt|;
comment|/* Connection Status Register */
name|u_short
name|pad18
decl_stmt|;
name|u_short
name|dstat
decl_stmt|;
comment|/* Data Transfer Status Register */
name|u_short
name|pad19
decl_stmt|;
name|u_short
name|comm
decl_stmt|;
comment|/* Command Register */
name|u_short
name|pad20
decl_stmt|;
name|u_short
name|dictrl
decl_stmt|;
comment|/* Diagnostic Control Register */
name|u_short
name|pad21
decl_stmt|;
name|u_short
name|clock
decl_stmt|;
comment|/* Diagnostic Clock Register */
name|u_short
name|pad22
decl_stmt|;
name|u_short
name|bhdiag
decl_stmt|;
comment|/* Bus Handler Diagnostic Register */
name|u_short
name|pad23
decl_stmt|;
name|u_short
name|sidiag
decl_stmt|;
comment|/* SCSI IO Diagnostic Register */
name|u_short
name|pad24
decl_stmt|;
name|u_short
name|dmdiag
decl_stmt|;
comment|/* Data Mover Diagnostic Register */
name|u_short
name|pad25
decl_stmt|;
name|u_short
name|mcdiag
decl_stmt|;
comment|/* Main Control Diagnostic Register */
name|u_short
name|pad26
decl_stmt|;
block|}
name|SIIRegs
typedef|;
end_typedef

begin_comment
comment|/*  * SC1 - SCSI Control Signals One  */
end_comment

begin_define
define|#
directive|define
name|SII_SC1_MSK
value|0x1ff
end_define

begin_comment
comment|/* All possible signals on the bus */
end_comment

begin_define
define|#
directive|define
name|SII_SC1_SEL
value|0x80
end_define

begin_comment
comment|/* SCSI SEL signal active on bus */
end_comment

begin_define
define|#
directive|define
name|SII_SC1_ATN
value|0x08
end_define

begin_comment
comment|/* SCSI ATN signal active on bus */
end_comment

begin_comment
comment|/*  * SC2 - SCSI Control Signals Two  */
end_comment

begin_define
define|#
directive|define
name|SII_SC2_IGS
value|0x8
end_define

begin_comment
comment|/* SCSI drivers for initiator mode */
end_comment

begin_comment
comment|/*  * CSR - Control/Status Register  */
end_comment

begin_define
define|#
directive|define
name|SII_HPM
value|0x10
end_define

begin_comment
comment|/* SII in on an arbitrated SCSI bus */
end_comment

begin_define
define|#
directive|define
name|SII_RSE
value|0x08
end_define

begin_comment
comment|/* 1 = respond to reselections */
end_comment

begin_define
define|#
directive|define
name|SII_SLE
value|0x04
end_define

begin_comment
comment|/* 1 = respond to selections */
end_comment

begin_define
define|#
directive|define
name|SII_PCE
value|0x02
end_define

begin_comment
comment|/* 1 = report parity errors */
end_comment

begin_define
define|#
directive|define
name|SII_IE
value|0x01
end_define

begin_comment
comment|/* 1 = enable interrupts */
end_comment

begin_comment
comment|/*  * ID - Bus ID Register  */
end_comment

begin_define
define|#
directive|define
name|SII_ID_IO
value|0x8000
end_define

begin_comment
comment|/* I/O */
end_comment

begin_comment
comment|/*  * DESTAT - Selection Detector Status Register  */
end_comment

begin_define
define|#
directive|define
name|SII_IDMSK
value|0x7
end_define

begin_comment
comment|/* ID of target reselected the SII */
end_comment

begin_comment
comment|/*  * DMCTRL - DMA Control Register  */
end_comment

begin_define
define|#
directive|define
name|SII_ASYNC
value|0x00
end_define

begin_comment
comment|/* REQ/ACK Offset for async mode */
end_comment

begin_define
define|#
directive|define
name|SII_SYNC
value|0x03
end_define

begin_comment
comment|/* REQ/ACK Offset for sync mode */
end_comment

begin_comment
comment|/*  * DMLOTC - DMA Length Of Transfer Counter  */
end_comment

begin_define
define|#
directive|define
name|SII_TCMSK
value|0x1fff
end_define

begin_comment
comment|/* transfer count mask */
end_comment

begin_comment
comment|/*  * CSTAT - Connection Status Register  */
end_comment

begin_define
define|#
directive|define
name|SII_CI
value|0x8000
end_define

begin_comment
comment|/* composite interrupt bit for CSTAT */
end_comment

begin_define
define|#
directive|define
name|SII_DI
value|0x4000
end_define

begin_comment
comment|/* composite interrupt bit for DSTAT */
end_comment

begin_define
define|#
directive|define
name|SII_RST
value|0x2000
end_define

begin_comment
comment|/* 1 if reset is asserted on SCSI bus */
end_comment

begin_define
define|#
directive|define
name|SII_BER
value|0x1000
end_define

begin_comment
comment|/* Bus error */
end_comment

begin_define
define|#
directive|define
name|SII_OBC
value|0x0800
end_define

begin_comment
comment|/* Out_en Bit Cleared (DSSI mode) */
end_comment

begin_define
define|#
directive|define
name|SII_TZ
value|0x0400
end_define

begin_comment
comment|/* Target pointer Zero (STLP or LTLP is zero) */
end_comment

begin_define
define|#
directive|define
name|SII_BUF
value|0x0200
end_define

begin_comment
comment|/* Buffer service - outbound pkt to non-DSSI */
end_comment

begin_define
define|#
directive|define
name|SII_LDN
value|0x0100
end_define

begin_comment
comment|/* List element Done */
end_comment

begin_define
define|#
directive|define
name|SII_SCH
value|0x0080
end_define

begin_comment
comment|/* State Change */
end_comment

begin_define
define|#
directive|define
name|SII_CON
value|0x0040
end_define

begin_comment
comment|/* SII is Connected to another device */
end_comment

begin_define
define|#
directive|define
name|SII_DST
value|0x0020
end_define

begin_comment
comment|/* SII was Destination of current transfer */
end_comment

begin_define
define|#
directive|define
name|SII_TGT
value|0x0010
end_define

begin_comment
comment|/* SII is operating as a Target */
end_comment

begin_define
define|#
directive|define
name|SII_STATE_MSK
value|0x0070
end_define

begin_comment
comment|/* State Mask */
end_comment

begin_define
define|#
directive|define
name|SII_SWA
value|0x0008
end_define

begin_comment
comment|/* Selected With Attention */
end_comment

begin_define
define|#
directive|define
name|SII_SIP
value|0x0004
end_define

begin_comment
comment|/* Selection In Progress */
end_comment

begin_define
define|#
directive|define
name|SII_LST
value|0x0002
end_define

begin_comment
comment|/* Lost arbitration */
end_comment

begin_comment
comment|/*  * DSTAT - Data Transfer Status Register  */
end_comment

begin_define
define|#
directive|define
name|SII_DNE
value|0x2000
end_define

begin_comment
comment|/* DMA transfer Done */
end_comment

begin_define
define|#
directive|define
name|SII_TCZ
value|0x1000
end_define

begin_comment
comment|/* Transfer Count register is Zero */
end_comment

begin_define
define|#
directive|define
name|SII_TBE
value|0x0800
end_define

begin_comment
comment|/* Transmit Buffer Empty */
end_comment

begin_define
define|#
directive|define
name|SII_IBF
value|0x0400
end_define

begin_comment
comment|/* Input Buffer Full */
end_comment

begin_define
define|#
directive|define
name|SII_IPE
value|0x0200
end_define

begin_comment
comment|/* Incoming Parity Error */
end_comment

begin_define
define|#
directive|define
name|SII_OBB
value|0x0100
end_define

begin_comment
comment|/* Odd Byte Boundry */
end_comment

begin_define
define|#
directive|define
name|SII_MIS
value|0x0010
end_define

begin_comment
comment|/* Phase Mismatch */
end_comment

begin_define
define|#
directive|define
name|SII_ATN
value|0x0008
end_define

begin_comment
comment|/* ATN set by initiator if in Target mode */
end_comment

begin_define
define|#
directive|define
name|SII_MSG
value|0x0004
end_define

begin_comment
comment|/* current bus state of MSG */
end_comment

begin_define
define|#
directive|define
name|SII_CD
value|0x0002
end_define

begin_comment
comment|/* current bus state of C/D */
end_comment

begin_define
define|#
directive|define
name|SII_IO
value|0x0001
end_define

begin_comment
comment|/* current bus state of I/O */
end_comment

begin_define
define|#
directive|define
name|SII_PHASE_MSK
value|0x0007
end_define

begin_comment
comment|/* Phase Mask */
end_comment

begin_comment
comment|/*  * The different phases.  */
end_comment

begin_define
define|#
directive|define
name|SII_MSG_IN_PHASE
value|0x7
end_define

begin_define
define|#
directive|define
name|SII_MSG_OUT_PHASE
value|0x6
end_define

begin_define
define|#
directive|define
name|SII_STATUS_PHASE
value|0x3
end_define

begin_define
define|#
directive|define
name|SII_CMD_PHASE
value|0x2
end_define

begin_define
define|#
directive|define
name|SII_DATA_IN_PHASE
value|0x1
end_define

begin_define
define|#
directive|define
name|SII_DATA_OUT_PHASE
value|0x0
end_define

begin_comment
comment|/*  * COMM - Command Register  */
end_comment

begin_define
define|#
directive|define
name|SII_DMA
value|0x8000
end_define

begin_comment
comment|/* DMA mode */
end_comment

begin_define
define|#
directive|define
name|SII_DO_RST
value|0x4000
end_define

begin_comment
comment|/* Assert reset on SCSI bus for 25 usecs */
end_comment

begin_define
define|#
directive|define
name|SII_RSL
value|0x1000
end_define

begin_comment
comment|/* 0 = select, 1 = reselect desired device */
end_comment

begin_comment
comment|/* Commands: I - Initiator, T - Target, D - Disconnected */
end_comment

begin_define
define|#
directive|define
name|SII_INXFER
value|0x0800
end_define

begin_comment
comment|/* Information Transfer command	(I,T) */
end_comment

begin_define
define|#
directive|define
name|SII_SELECT
value|0x0400
end_define

begin_comment
comment|/* Select command		(D) */
end_comment

begin_define
define|#
directive|define
name|SII_REQDATA
value|0x0200
end_define

begin_comment
comment|/* Request Data command		(T) */
end_comment

begin_define
define|#
directive|define
name|SII_DISCON
value|0x0100
end_define

begin_comment
comment|/* Disconnect command		(I,T,D) */
end_comment

begin_define
define|#
directive|define
name|SII_CHRESET
value|0x0080
end_define

begin_comment
comment|/* Chip Reset command		(I,T,D) */
end_comment

begin_comment
comment|/* Command state bits same as connection status register */
end_comment

begin_comment
comment|/* Command phase bits same as data transfer status register */
end_comment

begin_comment
comment|/*  * DICTRL - Diagnostic Control Register  */
end_comment

begin_define
define|#
directive|define
name|SII_PRE
value|0x4
end_define

begin_comment
comment|/* Enable the SII to drive the SCSI bus */
end_comment

begin_define
define|#
directive|define
name|SII_WAIT_COUNT
value|10000
end_define

begin_comment
comment|/* Delay count used for the SII chip */
end_comment

begin_comment
comment|/*  * Max DMA transfer length for SII  * The SII chip only has a 13 bit counter. If 8192 is used as the max count,  * you can't tell the difference between a count of zero and 8192.  * 8190 is used instead of 8191 so the count is even.  */
end_comment

begin_define
define|#
directive|define
name|SII_MAX_DMA_XFER_LENGTH
value|8192
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SII */
end_comment

end_unit

