begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)utreg.h	7.2 (Berkeley) 5/26/88  */
end_comment

begin_comment
comment|/*  * System Industries Model 9700 Tape Drive  *   emulates TU45 on the UNIBUS  */
end_comment

begin_struct
struct|struct
name|utdevice
block|{
name|u_short
name|utcs1
decl_stmt|;
comment|/* control status register 1 */
name|short
name|utwc
decl_stmt|;
comment|/* word count register */
name|u_short
name|utba
decl_stmt|;
comment|/* low 16-bits of bus address */
name|short
name|utfc
decl_stmt|;
comment|/* frame counter */
name|u_short
name|utcs2
decl_stmt|;
comment|/* control status register 2 */
name|u_short
name|utds
decl_stmt|;
comment|/* drive status register */
name|u_short
name|uter
decl_stmt|;
comment|/* error register */
name|u_short
name|utas
decl_stmt|;
comment|/* attention status register */
name|u_short
name|utcc
decl_stmt|;
comment|/* NRZI CRC character for validation */
name|u_short
name|utdb
decl_stmt|;
comment|/* data buffer reg (not emulated) */
name|u_short
name|utmr
decl_stmt|;
comment|/* maintenance reg (not emulated) */
name|u_short
name|utdt
decl_stmt|;
comment|/* drive type register (not emulated) */
name|u_short
name|utsn
decl_stmt|;
comment|/* serial number reg (not emulated) */
name|u_short
name|uttc
decl_stmt|;
comment|/* tape control register */
name|u_short
name|utbae
decl_stmt|;
comment|/* buffer address extension register */
name|u_short
name|utcs3
decl_stmt|;
comment|/* control and status register 3 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * utcs1 --  *   cmds, interrupt enable, extended address bits, and status  */
end_comment

begin_define
define|#
directive|define
name|UT_GO
value|0x0001
end_define

begin_comment
comment|/* go bit */
end_comment

begin_comment
comment|/* function codes reside in bits 5-1 */
end_comment

begin_define
define|#
directive|define
name|UT_NOP
value|0x0000
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|UT_REWOFFL
value|0x0002
end_define

begin_comment
comment|/* rewind offline */
end_comment

begin_define
define|#
directive|define
name|UT_LOOP
value|0x0004
end_define

begin_comment
comment|/* loop read/write */
end_comment

begin_define
define|#
directive|define
name|UT_REW
value|0x0006
end_define

begin_comment
comment|/* rewind */
end_comment

begin_define
define|#
directive|define
name|UT_CLEAR
value|0x0008
end_define

begin_comment
comment|/* drive clear */
end_comment

begin_define
define|#
directive|define
name|UT_SENSE
value|0x000a
end_define

begin_comment
comment|/* drive sense */
end_comment

begin_define
define|#
directive|define
name|UT_PRESET
value|0x0010
end_define

begin_comment
comment|/* read in preset */
end_comment

begin_define
define|#
directive|define
name|UT_DIAGN
value|0x0012
end_define

begin_comment
comment|/* diagnostic mode set */
end_comment

begin_define
define|#
directive|define
name|UT_ERASE
value|0x0014
end_define

begin_comment
comment|/* erase */
end_comment

begin_define
define|#
directive|define
name|UT_WEOF
value|0x0016
end_define

begin_comment
comment|/* write tape mark */
end_comment

begin_define
define|#
directive|define
name|UT_SFORW
value|0x0018
end_define

begin_comment
comment|/* forward space block */
end_comment

begin_define
define|#
directive|define
name|UT_SREV
value|0x001a
end_define

begin_comment
comment|/* reverse space block */
end_comment

begin_define
define|#
directive|define
name|UT_SFORWF
value|0x001c
end_define

begin_comment
comment|/* forward space file */
end_comment

begin_define
define|#
directive|define
name|UT_SREVF
value|0x001e
end_define

begin_comment
comment|/* reverse space file */
end_comment

begin_define
define|#
directive|define
name|UT_WCHFORW
value|0x0028
end_define

begin_comment
comment|/* write check forward */
end_comment

begin_define
define|#
directive|define
name|UT_WCHREV
value|0x002e
end_define

begin_comment
comment|/* write check reverse */
end_comment

begin_define
define|#
directive|define
name|UT_WCOM
value|0x0030
end_define

begin_comment
comment|/* write forward */
end_comment

begin_define
define|#
directive|define
name|UT_RCOM
value|0x0038
end_define

begin_comment
comment|/* read forward */
end_comment

begin_define
define|#
directive|define
name|UT_RREV
value|0x003e
end_define

begin_comment
comment|/* read reverse */
end_comment

begin_comment
comment|/* the remainder are control and status bits */
end_comment

begin_define
define|#
directive|define
name|UT_IE
value|0x0040
end_define

begin_comment
comment|/* interrupt-enable */
end_comment

begin_define
define|#
directive|define
name|UT_RDY
value|0x0080
end_define

begin_comment
comment|/* controller ready */
end_comment

begin_define
define|#
directive|define
name|UT_EADDR
value|0x0300
end_define

begin_comment
comment|/* extended address bits */
end_comment

begin_comment
comment|/* bit 10 unused */
end_comment

begin_define
define|#
directive|define
name|UT_DVA
value|0x0800
end_define

begin_comment
comment|/* drive available */
end_comment

begin_comment
comment|/* bit 12 unused */
end_comment

begin_comment
comment|/* bit 13 - massbus control parity error not emulated */
end_comment

begin_define
define|#
directive|define
name|UT_TRE
value|0x4000
end_define

begin_comment
comment|/* transfer error */
end_comment

begin_define
define|#
directive|define
name|UT_SC
value|0x8000
end_define

begin_comment
comment|/* special condition */
end_comment

begin_define
define|#
directive|define
name|UT_BITS
define|\
value|"\10\20SC\17TRE\14DVA\10RDY\7IE\1GO"
end_define

begin_comment
comment|/*  * utcs2 --  *   controller clear, error flags, and unit select  */
end_comment

begin_comment
comment|/* bits 0-2 are unit select */
end_comment

begin_define
define|#
directive|define
name|UTCS2_BAI
value|0x0008
end_define

begin_comment
comment|/* UNIBUS address increment inhibit */
end_comment

begin_define
define|#
directive|define
name|UTCS2_PAT
value|0x0010
end_define

begin_comment
comment|/* parity test */
end_comment

begin_define
define|#
directive|define
name|UTCS2_CLR
value|0x0020
end_define

begin_comment
comment|/* controller clear */
end_comment

begin_define
define|#
directive|define
name|UTCS2_IR
value|0x0040
end_define

begin_comment
comment|/* input ready (not emulated) */
end_comment

begin_define
define|#
directive|define
name|UTCS2_OR
value|0x0080
end_define

begin_comment
comment|/* output ready (not emulated) */
end_comment

begin_define
define|#
directive|define
name|UTCS2_RPE
value|0x0100
end_define

begin_comment
comment|/* rom parity error */
end_comment

begin_define
define|#
directive|define
name|UTCS2_MXF
value|0x0200
end_define

begin_comment
comment|/* missed transfer */
end_comment

begin_define
define|#
directive|define
name|UTCS2_NEM
value|0x0400
end_define

begin_comment
comment|/* non existant memory */
end_comment

begin_define
define|#
directive|define
name|UTCS2_PGE
value|0x0800
end_define

begin_comment
comment|/* program error */
end_comment

begin_define
define|#
directive|define
name|UTCS2_NED
value|0x1000
end_define

begin_comment
comment|/* non existent drive */
end_comment

begin_define
define|#
directive|define
name|UTCS2_PE
value|0x2000
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|UTCS2_WCE
value|0x4000
end_define

begin_comment
comment|/* write check error */
end_comment

begin_define
define|#
directive|define
name|UTCS2_DLT
value|0x8000
end_define

begin_comment
comment|/* data late */
end_comment

begin_define
define|#
directive|define
name|UTCS2_BITS
define|\
value|"\10\20DLT\17WCE\16PE\15NED\14NEM\13PGE\12MXF\11RPE\10OR\7IR\6CLR\5PAT\4BAI"
end_define

begin_comment
comment|/*  * utds --  *   beginning of tape, end of tape, error summary bit, plus lots more  */
end_comment

begin_define
define|#
directive|define
name|UTDS_SLA
value|0x0001
end_define

begin_comment
comment|/* slave attention */
end_comment

begin_define
define|#
directive|define
name|UTDS_BOT
value|0x0002
end_define

begin_comment
comment|/* beginning of tape */
end_comment

begin_define
define|#
directive|define
name|UTDS_TM
value|0x0004
end_define

begin_comment
comment|/* tape mark */
end_comment

begin_define
define|#
directive|define
name|UTDS_IDB
value|0x0008
end_define

begin_comment
comment|/* identification burst */
end_comment

begin_define
define|#
directive|define
name|UTDS_SDWN
value|0x0010
end_define

begin_comment
comment|/* slowing down */
end_comment

begin_define
define|#
directive|define
name|UTDS_PES
value|0x0020
end_define

begin_comment
comment|/* phase encode status */
end_comment

begin_define
define|#
directive|define
name|UTDS_SSC
value|0x0040
end_define

begin_comment
comment|/* slave status change */
end_comment

begin_define
define|#
directive|define
name|UTDS_DRY
value|0x0080
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|UTDS_DPR
value|0x0100
end_define

begin_comment
comment|/* drive present (always 1) */
end_comment

begin_define
define|#
directive|define
name|UTDS_GCR
value|0x0200
end_define

begin_comment
comment|/* GCR status */
end_comment

begin_define
define|#
directive|define
name|UTDS_EOT
value|0x0400
end_define

begin_comment
comment|/* end of tape */
end_comment

begin_define
define|#
directive|define
name|UTDS_WRL
value|0x0800
end_define

begin_comment
comment|/* write lock */
end_comment

begin_define
define|#
directive|define
name|UTDS_MOL
value|0x1000
end_define

begin_comment
comment|/* medium on line */
end_comment

begin_define
define|#
directive|define
name|UTDS_PIP
value|0x2000
end_define

begin_comment
comment|/* positioning in progress */
end_comment

begin_define
define|#
directive|define
name|UTDS_ERR
value|0x4000
end_define

begin_comment
comment|/* composite error */
end_comment

begin_define
define|#
directive|define
name|UTDS_ATA
value|0x8000
end_define

begin_comment
comment|/* attention active */
end_comment

begin_define
define|#
directive|define
name|UTDS_BITS
define|\
value|"\10\20ATA\17ERR\16PIP\15MOL\14WRL\13EOT\12GCR\11DPR\10DRY\7SSC\6PES\5SDWN\4IDB\3TM\2BOT\1SLA"
end_define

begin_comment
comment|/*  * uter --  *   detailed breakdown of error summary bit from cs2  */
end_comment

begin_define
define|#
directive|define
name|UTER_ILF
value|0x0001
end_define

begin_comment
comment|/* illegal function */
end_comment

begin_define
define|#
directive|define
name|UTER_ILR
value|0x0002
end_define

begin_comment
comment|/* illegal register (always 0) */
end_comment

begin_define
define|#
directive|define
name|UTER_RMR
value|0x0004
end_define

begin_comment
comment|/* register modification refused */
end_comment

begin_define
define|#
directive|define
name|UTER_RPE
value|0x0008
end_define

begin_comment
comment|/* read data parity error */
end_comment

begin_define
define|#
directive|define
name|UTER_FMT
value|0x0010
end_define

begin_comment
comment|/* format error */
end_comment

begin_define
define|#
directive|define
name|UTER_DPAR
value|0x0020
end_define

begin_comment
comment|/* data bus parity error */
end_comment

begin_define
define|#
directive|define
name|UTER_INC
value|0x0040
end_define

begin_comment
comment|/* incorrectable data */
end_comment

begin_define
define|#
directive|define
name|UTER_PEF
value|0x0080
end_define

begin_comment
comment|/* PE format error */
end_comment

begin_define
define|#
directive|define
name|UTER_NSG
value|0x0100
end_define

begin_comment
comment|/* non standard gap */
end_comment

begin_define
define|#
directive|define
name|UTER_FCE
value|0x0200
end_define

begin_comment
comment|/* frame count error */
end_comment

begin_define
define|#
directive|define
name|UTER_CS
value|0x0400
end_define

begin_comment
comment|/* correctable skew */
end_comment

begin_define
define|#
directive|define
name|UTER_NEF
value|0x0800
end_define

begin_comment
comment|/* non executable function */
end_comment

begin_define
define|#
directive|define
name|UTER_DTE
value|0x1000
end_define

begin_comment
comment|/* drive timing error */
end_comment

begin_define
define|#
directive|define
name|UTER_OPI
value|0x2000
end_define

begin_comment
comment|/* operation incomplete */
end_comment

begin_define
define|#
directive|define
name|UTER_UNS
value|0x4000
end_define

begin_comment
comment|/* unsafe */
end_comment

begin_define
define|#
directive|define
name|UTER_COR
value|0x8000
end_define

begin_comment
comment|/* correctible data error */
end_comment

begin_comment
comment|/*  * These errors we consider "hard"; UTER_OPI and UTER_RPE  * are considered "soft", at least for the moment.  */
end_comment

begin_define
define|#
directive|define
name|UTER_HARD
value|(UTER_UNS|UTER_NEF|UTER_DPAR|UTER_FMT|UTER_RMR|\ 			 UTER_ILR|UTER_ILF)
end_define

begin_define
define|#
directive|define
name|UTER_BITS
define|\
value|"\10\20COR\17UNS\16OPI\15DTE\14NEF\13CS\12FCE\11NSG\10PEF\7INC\6DPAR\5FMT\4RPE\3RMR\2ILR\1ILF"
end_define

begin_comment
comment|/*  * uttc --  *   tape format and density  */
end_comment

begin_comment
comment|/* bits 0-2 are slave select */
end_comment

begin_define
define|#
directive|define
name|UTTC_EVPAR
value|0x0008
end_define

begin_comment
comment|/* even parity */
end_comment

begin_define
define|#
directive|define
name|UTTC_FMT
value|0x00f0
end_define

begin_comment
comment|/* format select (see below) */
end_comment

begin_define
define|#
directive|define
name|UTTC_DEN
value|0x0700
end_define

begin_comment
comment|/* density select (see below) */
end_comment

begin_comment
comment|/* bit 11 not used */
end_comment

begin_define
define|#
directive|define
name|UTTC_EAODTE
value|0x1000
end_define

begin_comment
comment|/* (not emulated) */
end_comment

begin_define
define|#
directive|define
name|UTTC_TCW
value|0x2000
end_define

begin_comment
comment|/* tape control write */
end_comment

begin_define
define|#
directive|define
name|UTTC_FCS
value|0x4000
end_define

begin_comment
comment|/* frame count status */
end_comment

begin_define
define|#
directive|define
name|UTTC_ACCL
value|0x8000
end_define

begin_comment
comment|/* acceleration */
end_comment

begin_comment
comment|/* the bits to stuff in UTTC_DEN */
end_comment

begin_define
define|#
directive|define
name|UT_NRZI
value|0x0000
end_define

begin_comment
comment|/* 800 bpi code */
end_comment

begin_define
define|#
directive|define
name|UT_PE
value|0x0400
end_define

begin_comment
comment|/* 1600 bpi code */
end_comment

begin_define
define|#
directive|define
name|UT_GCR
value|0x0500
end_define

begin_comment
comment|/* 6250 bpi code */
end_comment

begin_comment
comment|/* tape formats - only PDP-11 standard is supported */
end_comment

begin_define
define|#
directive|define
name|PDP11FMT
value|0x00c0
end_define

begin_comment
comment|/* PDP-11 standard */
end_comment

begin_define
define|#
directive|define
name|b_repcnt
value|b_bcount
end_define

begin_define
define|#
directive|define
name|b_command
value|b_resid
end_define

begin_define
define|#
directive|define
name|b_state
value|b_active
end_define

end_unit

