begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: screg_1185.h,v 4.300 91/06/09 06:22:14 root Rel41 $ SONY  *  *	@(#)screg_1185.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1989- by SONY Corporation.  */
end_comment

begin_comment
comment|/*  *	screg_1185.h	ver 0.0		  *		for SCSI I/F Chip CXD1185Q  */
end_comment

begin_comment
comment|/*  *		SCSI I/F Chip CXD1185Q Register address assignment  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|mips
end_ifdef

begin_define
define|#
directive|define
name|SCSI_BASE
value|0xbfe00100
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCSI_BASE
value|0xe1900000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|U_CHAR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|mips
end_ifdef

begin_define
define|#
directive|define
name|U_CHAR
value|volatile u_char
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|U_CHAR
value|u_char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|sc_statr
value|*( (U_CHAR *)(SCSI_BASE + 0x0) )
end_define

begin_define
define|#
directive|define
name|sc_comr
value|*( (U_CHAR *)(SCSI_BASE + 0x0) )
end_define

begin_define
define|#
directive|define
name|sc_datr
value|*( (U_CHAR *)(SCSI_BASE + 0x1) )
end_define

begin_define
define|#
directive|define
name|sc_intrq1
value|*( (U_CHAR *)(SCSI_BASE + 0x2) )
end_define

begin_define
define|#
directive|define
name|sc_intrq2
value|*( (U_CHAR *)(SCSI_BASE + 0x3) )
end_define

begin_define
define|#
directive|define
name|sc_envir
value|*( (U_CHAR *)(SCSI_BASE + 0x3) )
end_define

begin_define
define|#
directive|define
name|sc_cmonr
value|*( (U_CHAR *)(SCSI_BASE + 0x4) )
end_define

begin_define
define|#
directive|define
name|sc_timer
value|*( (U_CHAR *)(SCSI_BASE + 0x4) )
end_define

begin_define
define|#
directive|define
name|sc_ffstr
value|*( (U_CHAR *)(SCSI_BASE + 0x5) )
end_define

begin_define
define|#
directive|define
name|sc_idenr
value|*( (U_CHAR *)(SCSI_BASE + 0x6) )
end_define

begin_define
define|#
directive|define
name|sc_tclow
value|*( (U_CHAR *)(SCSI_BASE + 0x7) )
end_define

begin_define
define|#
directive|define
name|sc_tcmid
value|*( (U_CHAR *)(SCSI_BASE + 0x8) )
end_define

begin_define
define|#
directive|define
name|sc_tchi
value|*( (U_CHAR *)(SCSI_BASE + 0x9) )
end_define

begin_define
define|#
directive|define
name|sc_intok1
value|*( (U_CHAR *)(SCSI_BASE + 0xa) )
end_define

begin_define
define|#
directive|define
name|sc_intok2
value|*( (U_CHAR *)(SCSI_BASE + 0xb) )
end_define

begin_define
define|#
directive|define
name|sc_moder
value|*( (U_CHAR *)(SCSI_BASE + 0xc) )
end_define

begin_define
define|#
directive|define
name|sc_syncr
value|*( (U_CHAR *)(SCSI_BASE + 0xd) )
end_define

begin_define
define|#
directive|define
name|sc_busconr
value|*( (U_CHAR *)(SCSI_BASE + 0xe) )
end_define

begin_define
define|#
directive|define
name|sc_ioptr
value|*( (U_CHAR *)(SCSI_BASE + 0xf) )
end_define

begin_comment
comment|/*  *		CXD1185Q Register bit assignment  */
end_comment

begin_comment
comment|/*	sc_statr (status register) bit define */
end_comment

begin_define
define|#
directive|define
name|R0_MRST
value|0x80
end_define

begin_define
define|#
directive|define
name|R0_MDBP
value|0x40
end_define

begin_define
define|#
directive|define
name|R0_INIT
value|0x10
end_define

begin_define
define|#
directive|define
name|R0_TARG
value|8
end_define

begin_define
define|#
directive|define
name|R0_TRBZ
value|4
end_define

begin_define
define|#
directive|define
name|R0_MIRQ
value|2
end_define

begin_define
define|#
directive|define
name|R0_CIP
value|1
end_define

begin_comment
comment|/*	sc_comr (command register) bit define */
end_comment

begin_define
define|#
directive|define
name|R0_DMA
value|0x20
end_define

begin_define
define|#
directive|define
name|R0_TRBE
value|0x10
end_define

begin_comment
comment|/*	sc_intrq1 (interrupt request register 1) bit define */
end_comment

begin_define
define|#
directive|define
name|R2_STO
value|0x10
end_define

begin_define
define|#
directive|define
name|R2_RSL
value|8
end_define

begin_define
define|#
directive|define
name|R2_SWA
value|4
end_define

begin_define
define|#
directive|define
name|R2_SWOA
value|2
end_define

begin_define
define|#
directive|define
name|R2_ARBF
value|1
end_define

begin_comment
comment|/*	sc_intrq2 (interrupt request register 2) bit define */
end_comment

begin_define
define|#
directive|define
name|R3_FNC
value|0x80
end_define

begin_define
define|#
directive|define
name|R3_DCNT
value|0x40
end_define

begin_define
define|#
directive|define
name|R3_SRST
value|0x20
end_define

begin_define
define|#
directive|define
name|R3_PHC
value|0x10
end_define

begin_define
define|#
directive|define
name|R3_DATN
value|8
end_define

begin_define
define|#
directive|define
name|R3_DPE
value|4
end_define

begin_define
define|#
directive|define
name|R3_SPE
value|2
end_define

begin_define
define|#
directive|define
name|R3_RMSG
value|1
end_define

begin_comment
comment|/*	sc_envir (environment register) bit define */
end_comment

begin_define
define|#
directive|define
name|R3_DIFE
value|0x80
end_define

begin_define
define|#
directive|define
name|R3_SDPM
value|0x40
end_define

begin_define
define|#
directive|define
name|R3_DPEN
value|0x20
end_define

begin_define
define|#
directive|define
name|R3_SIRM
value|0x10
end_define

begin_define
define|#
directive|define
name|R3_FS_MASK
value|3
end_define

begin_comment
comment|/*	sc_cmonr (scsi control monitor register) bit define */
end_comment

begin_define
define|#
directive|define
name|R4_MBSY
value|0x80
end_define

begin_define
define|#
directive|define
name|R4_MSEL
value|0x40
end_define

begin_define
define|#
directive|define
name|R4_MMSG
value|0x20
end_define

begin_define
define|#
directive|define
name|R4_MCD
value|0x10
end_define

begin_define
define|#
directive|define
name|R4_MIO
value|8
end_define

begin_define
define|#
directive|define
name|R4_MREQ
value|4
end_define

begin_define
define|#
directive|define
name|R4_MACK
value|2
end_define

begin_define
define|#
directive|define
name|R4_MATN
value|1
end_define

begin_comment
comment|/*	sc_ffstr (FIFO status register) bit define */
end_comment

begin_define
define|#
directive|define
name|R5_FIE
value|0x80
end_define

begin_define
define|#
directive|define
name|R5_FIF
value|0x10
end_define

begin_define
define|#
directive|define
name|R5_FIFOREM
value|0x1f
end_define

begin_comment
comment|/*	sc_idenr (scsi identify register) bit define */
end_comment

begin_define
define|#
directive|define
name|R6_OID_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|R6_SID_MASK
value|0xe0
end_define

begin_define
define|#
directive|define
name|R6_TID_MASK
value|0xe0
end_define

begin_comment
comment|/*	sc_intok1 (interrupt enable register 1) bit define */
end_comment

begin_define
define|#
directive|define
name|Ra_STO
value|0x10
end_define

begin_define
define|#
directive|define
name|Ra_RSL
value|8
end_define

begin_define
define|#
directive|define
name|Ra_SWA
value|4
end_define

begin_define
define|#
directive|define
name|Ra_SWOA
value|2
end_define

begin_define
define|#
directive|define
name|Ra_ARBF
value|1
end_define

begin_comment
comment|/*	sc_intok2 (interrupt enable register 2) bit define */
end_comment

begin_define
define|#
directive|define
name|Rb_FNC
value|0x80
end_define

begin_define
define|#
directive|define
name|Rb_DCNT
value|0x40
end_define

begin_define
define|#
directive|define
name|Rb_SRST
value|0x20
end_define

begin_define
define|#
directive|define
name|Rb_PHC
value|0x10
end_define

begin_define
define|#
directive|define
name|Rb_DATN
value|8
end_define

begin_define
define|#
directive|define
name|Rb_DPE
value|4
end_define

begin_define
define|#
directive|define
name|Rb_SPE
value|2
end_define

begin_define
define|#
directive|define
name|Rb_RMSG
value|1
end_define

begin_comment
comment|/*	sc_moder (mode register) bit define */
end_comment

begin_define
define|#
directive|define
name|Rc_HDPE
value|0x80
end_define

begin_define
define|#
directive|define
name|Rc_HSPE
value|0x40
end_define

begin_define
define|#
directive|define
name|Rc_HATN
value|0x20
end_define

begin_define
define|#
directive|define
name|Rc_TMSL
value|0x10
end_define

begin_define
define|#
directive|define
name|Rc_SPHI
value|8
end_define

begin_define
define|#
directive|define
name|Rc_BDMA
value|1
end_define

begin_comment
comment|/*	sc_syncr (synchronous transfer control register) bit define */
end_comment

begin_define
define|#
directive|define
name|Rd_TPD_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|Rd_TOF_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|MIN_TP
value|62
end_define

begin_comment
comment|/* minimum transfer period 4ns * 25 */
end_comment

begin_define
define|#
directive|define
name|MAX_OFFSET
value|15
end_define

begin_comment
comment|/*	sc_busconr (scsi bus control register) bit define */
end_comment

begin_define
define|#
directive|define
name|Re_ABSY
value|0x80
end_define

begin_define
define|#
directive|define
name|Re_ASEL
value|0x40
end_define

begin_define
define|#
directive|define
name|Re_AMSG
value|0x20
end_define

begin_define
define|#
directive|define
name|Re_ACD
value|0x10
end_define

begin_define
define|#
directive|define
name|Re_AIO
value|8
end_define

begin_define
define|#
directive|define
name|Re_AREQ
value|4
end_define

begin_define
define|#
directive|define
name|Re_AACK
value|2
end_define

begin_define
define|#
directive|define
name|Re_AATN
value|1
end_define

begin_comment
comment|/*	sc_ioptr (I/O port) bit define */
end_comment

begin_define
define|#
directive|define
name|Rf_PCN_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|Rf_PCN3
value|0x80
end_define

begin_define
define|#
directive|define
name|Rf_PCN2
value|0x40
end_define

begin_define
define|#
directive|define
name|Rf_PCN1
value|0x20
end_define

begin_define
define|#
directive|define
name|Rf_PCN0
value|0x10
end_define

begin_define
define|#
directive|define
name|Rf_PRT_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|Rf_PRT3
value|8
end_define

begin_define
define|#
directive|define
name|Rf_PRT2
value|4
end_define

begin_define
define|#
directive|define
name|Rf_PRT1
value|2
end_define

begin_define
define|#
directive|define
name|Rf_PRT0
value|1
end_define

begin_comment
comment|/*  *		CXD1185Q commands  */
end_comment

begin_comment
comment|/*	category 0 */
end_comment

begin_define
define|#
directive|define
name|SCMD_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|SCMD_CHIP_RST
value|0x01
end_define

begin_define
define|#
directive|define
name|SCMD_AST_RST
value|0x02
end_define

begin_define
define|#
directive|define
name|SCMD_FLSH_FIFO
value|0x03
end_define

begin_define
define|#
directive|define
name|SCMD_AST_CTRL
value|0x04
end_define

begin_define
define|#
directive|define
name|SCMD_NGT_CTRL
value|0x05
end_define

begin_define
define|#
directive|define
name|SCMD_AST_DATA
value|0x06
end_define

begin_define
define|#
directive|define
name|SCMD_NGT_DATA
value|0x07
end_define

begin_comment
comment|/*	category 1 */
end_comment

begin_define
define|#
directive|define
name|SCMD_RESEL
value|0x40
end_define

begin_define
define|#
directive|define
name|SCMD_SEL
value|0x41
end_define

begin_define
define|#
directive|define
name|SCMD_SEL_ATN
value|0x42
end_define

begin_define
define|#
directive|define
name|SCMD_ENB_SEL
value|0x43
end_define

begin_define
define|#
directive|define
name|SCMD_DIS_SEL
value|0x44
end_define

begin_comment
comment|/*	category 2 */
end_comment

begin_define
define|#
directive|define
name|SCMD_SEND_MES
value|0x80
end_define

begin_define
define|#
directive|define
name|SCMD_SEND_STAT
value|0x81
end_define

begin_define
define|#
directive|define
name|SCMD_SEND_DATA
value|0x82
end_define

begin_define
define|#
directive|define
name|SCMD_DISCONNECT
value|0x83
end_define

begin_define
define|#
directive|define
name|SCMD_RCV_MOUT
value|0x84
end_define

begin_define
define|#
directive|define
name|SCMD_RCV_CMD
value|0x85
end_define

begin_define
define|#
directive|define
name|SCMD_RCV_DATA
value|0x86
end_define

begin_comment
comment|/*	category 3 */
end_comment

begin_define
define|#
directive|define
name|SCMD_TR_INFO
value|0xc0
end_define

begin_define
define|#
directive|define
name|SCMD_TR_PAD
value|0xc1
end_define

begin_define
define|#
directive|define
name|SCMD_NGT_ACK
value|0xc2
end_define

begin_define
define|#
directive|define
name|SCMD_AST_ATN
value|0xc3
end_define

begin_define
define|#
directive|define
name|SCMD_NGT_ATN
value|0xc4
end_define

begin_comment
comment|/*  *		scsi parameter definition  */
end_comment

begin_comment
comment|/* 	SCSI bus ID */
end_comment

begin_define
define|#
directive|define
name|SC_OWNID
value|0x7
end_define

begin_define
define|#
directive|define
name|SC_TG_SHIFT
value|5
end_define

begin_comment
comment|/*	scsi bus phase */
end_comment

begin_define
define|#
directive|define
name|SC_PMASK
value|(R4_MMSG|R4_MCD|R4_MIO)
end_define

begin_define
define|#
directive|define
name|DAT_OUT
value|0
end_define

begin_define
define|#
directive|define
name|DAT_IN
value|R4_MIO
end_define

begin_define
define|#
directive|define
name|COM_OUT
value|R4_MCD
end_define

begin_define
define|#
directive|define
name|STAT_IN
value|(R4_MCD|R4_MIO)
end_define

begin_define
define|#
directive|define
name|MES_OUT
value|(R4_MMSG|R4_MCD)
end_define

begin_define
define|#
directive|define
name|MES_IN
value|(R4_MMSG|R4_MCD|R4_MIO)
end_define

begin_comment
comment|/*	scsi command types define */
end_comment

begin_define
define|#
directive|define
name|CMD_TYPEMASK
value|0xe0
end_define

begin_define
define|#
directive|define
name|CMD_T0
value|0
end_define

begin_comment
comment|/*  6 byte commands */
end_comment

begin_define
define|#
directive|define
name|CMD_T1
value|0x20
end_define

begin_comment
comment|/* 10 byte commands */
end_comment

begin_define
define|#
directive|define
name|CMD_T5
value|0xa0
end_define

begin_comment
comment|/* 12 byte commands */
end_comment

begin_define
define|#
directive|define
name|CMD_T6
value|0xc0
end_define

begin_define
define|#
directive|define
name|CMD_T7
value|0xe0
end_define

begin_define
define|#
directive|define
name|MAXNSCSI
value|1
end_define

end_unit

