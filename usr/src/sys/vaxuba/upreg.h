begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)upreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * Unibus rm emulation via sc21:  * registers and bits.  */
end_comment

begin_struct
struct|struct
name|updevice
block|{
name|u_short
name|upcs1
decl_stmt|;
comment|/* control and status register 1 */
name|short
name|upwc
decl_stmt|;
comment|/* word count register */
name|u_short
name|upba
decl_stmt|;
comment|/* UNIBUS address register */
name|u_short
name|upda
decl_stmt|;
comment|/* desired address register */
name|u_short
name|upcs2
decl_stmt|;
comment|/* control and status register 2 */
name|u_short
name|upds
decl_stmt|;
comment|/* drive Status */
name|u_short
name|uper1
decl_stmt|;
comment|/* error register 1 */
name|u_short
name|upas
decl_stmt|;
comment|/* attention summary */
name|u_short
name|upla
decl_stmt|;
comment|/* look ahead */
name|u_short
name|updb
decl_stmt|;
comment|/* data buffer */
name|u_short
name|upmr
decl_stmt|;
comment|/* maintenance */
name|u_short
name|updt
decl_stmt|;
comment|/* drive type */
name|u_short
name|upsn
decl_stmt|;
comment|/* serial number */
name|u_short
name|upof
decl_stmt|;
comment|/* offset register */
name|u_short
name|updc
decl_stmt|;
comment|/* desired cylinder address register */
name|u_short
name|uphr
decl_stmt|;
comment|/* holding register */
name|u_short
name|upmr2
decl_stmt|;
comment|/* maintenance register 2 */
name|u_short
name|uper2
decl_stmt|;
comment|/* error register 2 */
name|u_short
name|upec1
decl_stmt|;
comment|/* burst error bit position */
name|u_short
name|upec2
decl_stmt|;
comment|/* burst error bit pattern */
block|}
struct|;
end_struct

begin_comment
comment|/* Other bits of upcs1 */
end_comment

begin_define
define|#
directive|define
name|UP_SC
value|0100000
end_define

begin_comment
comment|/* special condition */
end_comment

begin_define
define|#
directive|define
name|UP_TRE
value|0040000
end_define

begin_comment
comment|/* transfer error */
end_comment

begin_define
define|#
directive|define
name|UP_PSEL
value|0010000
end_define

begin_comment
comment|/* port select */
end_comment

begin_define
define|#
directive|define
name|UP_DVA
value|0004000
end_define

begin_comment
comment|/* drive available */
end_comment

begin_comment
comment|/* bits 8 and 9 are the extended address bits */
end_comment

begin_define
define|#
directive|define
name|UP_RDY
value|0000200
end_define

begin_comment
comment|/* controller ready */
end_comment

begin_define
define|#
directive|define
name|UP_IE
value|0000100
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_comment
comment|/* bits 5-1 are the command */
end_comment

begin_define
define|#
directive|define
name|UP_GO
value|0000001
end_define

begin_comment
comment|/* commands */
end_comment

begin_define
define|#
directive|define
name|UP_NOP
value|000
end_define

begin_define
define|#
directive|define
name|UP_SEEK
value|004
end_define

begin_comment
comment|/* seek */
end_comment

begin_define
define|#
directive|define
name|UP_RECAL
value|006
end_define

begin_comment
comment|/* recalibrate */
end_comment

begin_define
define|#
directive|define
name|UP_DCLR
value|010
end_define

begin_comment
comment|/* drive clear */
end_comment

begin_define
define|#
directive|define
name|UP_RELEASE
value|012
end_define

begin_comment
comment|/* release */
end_comment

begin_define
define|#
directive|define
name|UP_OFFSET
value|014
end_define

begin_comment
comment|/* offset */
end_comment

begin_define
define|#
directive|define
name|UP_RTC
value|016
end_define

begin_comment
comment|/* return to center-line */
end_comment

begin_define
define|#
directive|define
name|UP_PRESET
value|020
end_define

begin_comment
comment|/* read-in preset */
end_comment

begin_define
define|#
directive|define
name|UP_PACK
value|022
end_define

begin_comment
comment|/* pack acknowledge */
end_comment

begin_define
define|#
directive|define
name|UP_DMABAND
value|024
end_define

begin_comment
comment|/* dma bandwidth set */
end_comment

begin_define
define|#
directive|define
name|UP_SEARCH
value|030
end_define

begin_comment
comment|/* search */
end_comment

begin_define
define|#
directive|define
name|UP_WCDATA
value|050
end_define

begin_comment
comment|/* write check data */
end_comment

begin_define
define|#
directive|define
name|UP_WCHDR
value|052
end_define

begin_comment
comment|/* write check header and data */
end_comment

begin_define
define|#
directive|define
name|UP_WCOM
value|060
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|UP_WHDR
value|062
end_define

begin_comment
comment|/* write header and data */
end_comment

begin_define
define|#
directive|define
name|UP_RCOM
value|070
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|UP_RHDR
value|072
end_define

begin_comment
comment|/* read header and data */
end_comment

begin_define
define|#
directive|define
name|UP_BOOT
value|074
end_define

begin_comment
comment|/* boot */
end_comment

begin_define
define|#
directive|define
name|UP_FORMAT
value|076
end_define

begin_comment
comment|/* format */
end_comment

begin_comment
comment|/* upcs2 */
end_comment

begin_define
define|#
directive|define
name|UPCS2_DLT
value|0100000
end_define

begin_comment
comment|/* data late */
end_comment

begin_define
define|#
directive|define
name|UPCS2_WCE
value|0040000
end_define

begin_comment
comment|/* write check error */
end_comment

begin_define
define|#
directive|define
name|UPCS2_UPE
value|0020000
end_define

begin_comment
comment|/* UNIBUS parity error */
end_comment

begin_define
define|#
directive|define
name|UPCS2_NED
value|0010000
end_define

begin_comment
comment|/* nonexistent drive */
end_comment

begin_define
define|#
directive|define
name|UPCS2_NEM
value|0004000
end_define

begin_comment
comment|/* nonexistent memory */
end_comment

begin_define
define|#
directive|define
name|UPCS2_PGE
value|0002000
end_define

begin_comment
comment|/* programming error */
end_comment

begin_define
define|#
directive|define
name|UPCS2_MXF
value|0001000
end_define

begin_comment
comment|/* missed transfer */
end_comment

begin_define
define|#
directive|define
name|UPCS2_MDPE
value|0000400
end_define

begin_comment
comment|/* massbus data parity error (0) */
end_comment

begin_define
define|#
directive|define
name|UPCS2_OR
value|0000200
end_define

begin_comment
comment|/* output ready */
end_comment

begin_define
define|#
directive|define
name|UPCS2_IR
value|0000100
end_define

begin_comment
comment|/* input ready */
end_comment

begin_define
define|#
directive|define
name|UPCS2_CLR
value|0000040
end_define

begin_comment
comment|/* controller clear */
end_comment

begin_define
define|#
directive|define
name|UPCS2_PAT
value|0000020
end_define

begin_comment
comment|/* parity test */
end_comment

begin_define
define|#
directive|define
name|UPCS2_BAI
value|0000010
end_define

begin_comment
comment|/* address increment inhibit */
end_comment

begin_comment
comment|/* bits 0-2 are drive select */
end_comment

begin_define
define|#
directive|define
name|UPCS2_BITS
define|\
value|"\10\20DLT\17WCE\16UPE\15NED\14NEM\13PGE\12MXF\11MDPE\ \10OR\7IR\6CLR\5PAT\4BAI"
end_define

begin_comment
comment|/* upds */
end_comment

begin_define
define|#
directive|define
name|UPDS_ATA
value|0100000
end_define

begin_comment
comment|/* attention active */
end_comment

begin_define
define|#
directive|define
name|UPDS_ERR
value|0040000
end_define

begin_comment
comment|/* composite drive error */
end_comment

begin_define
define|#
directive|define
name|UPDS_PIP
value|0020000
end_define

begin_comment
comment|/* positioning in progress */
end_comment

begin_define
define|#
directive|define
name|UPDS_MOL
value|0010000
end_define

begin_comment
comment|/* medium on line */
end_comment

begin_define
define|#
directive|define
name|UPDS_WRL
value|0004000
end_define

begin_comment
comment|/* write locked */
end_comment

begin_define
define|#
directive|define
name|UPDS_LST
value|0002000
end_define

begin_comment
comment|/* last sector transferred */
end_comment

begin_define
define|#
directive|define
name|UPDS_PGM
value|0001000
end_define

begin_comment
comment|/* programmable */
end_comment

begin_define
define|#
directive|define
name|UPDS_DPR
value|0000400
end_define

begin_comment
comment|/* drive present */
end_comment

begin_define
define|#
directive|define
name|UPDS_DRY
value|0000200
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|UPDS_VV
value|0000100
end_define

begin_comment
comment|/* volume valid */
end_comment

begin_comment
comment|/* bits 1-5 are spare */
end_comment

begin_define
define|#
directive|define
name|UPDS_OM
value|0000001
end_define

begin_comment
comment|/* offset mode */
end_comment

begin_define
define|#
directive|define
name|UPDS_DREADY
value|(UPDS_DPR|UPDS_DRY|UPDS_MOL|UPDS_VV)
end_define

begin_define
define|#
directive|define
name|UPDS_BITS
define|\
value|"\10\20ATA\17ERR\16PIP\15MOL\14WRL\13LST\12PGM\11DPR\10DRY\7VV\1OM"
end_define

begin_comment
comment|/* uper1 */
end_comment

begin_define
define|#
directive|define
name|UPER1_DCK
value|0100000
end_define

begin_comment
comment|/* data check */
end_comment

begin_define
define|#
directive|define
name|UPER1_UNS
value|0040000
end_define

begin_comment
comment|/* drive unsafe */
end_comment

begin_define
define|#
directive|define
name|UPER1_OPI
value|0020000
end_define

begin_comment
comment|/* operation incomplete */
end_comment

begin_define
define|#
directive|define
name|UPER1_DTE
value|0010000
end_define

begin_comment
comment|/* drive timing error */
end_comment

begin_define
define|#
directive|define
name|UPER1_WLE
value|0004000
end_define

begin_comment
comment|/* write lock error */
end_comment

begin_define
define|#
directive|define
name|UPER1_IAE
value|0002000
end_define

begin_comment
comment|/* invalid address error */
end_comment

begin_define
define|#
directive|define
name|UPER1_AOE
value|0001000
end_define

begin_comment
comment|/* address overflow error */
end_comment

begin_define
define|#
directive|define
name|UPER1_HCRC
value|0000400
end_define

begin_comment
comment|/* header crc error */
end_comment

begin_define
define|#
directive|define
name|UPER1_HCE
value|0000200
end_define

begin_comment
comment|/* header compare error */
end_comment

begin_define
define|#
directive|define
name|UPER1_ECH
value|0000100
end_define

begin_comment
comment|/* ecc hard error */
end_comment

begin_define
define|#
directive|define
name|UPER1_WCF
value|0000040
end_define

begin_comment
comment|/* write clock fail (0) */
end_comment

begin_define
define|#
directive|define
name|UPER1_FER
value|0000020
end_define

begin_comment
comment|/* format error */
end_comment

begin_define
define|#
directive|define
name|UPER1_PAR
value|0000010
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|UPER1_RMR
value|0000004
end_define

begin_comment
comment|/* register modification refused */
end_comment

begin_define
define|#
directive|define
name|UPER1_ILR
value|0000002
end_define

begin_comment
comment|/* illegal register */
end_comment

begin_define
define|#
directive|define
name|UPER1_ILF
value|0000001
end_define

begin_comment
comment|/* illegal function */
end_comment

begin_define
define|#
directive|define
name|UPER1_BITS
define|\
value|"\10\20DCK\17UNS\16OPI\15DTE\14WLE\13IAE\12AOE\11HCRC\10HCE\ \7ECH\6WCF\5FER\4PAR\3RMR\2ILR\1ILF"
end_define

begin_comment
comment|/* uphr */
end_comment

begin_comment
comment|/* write these int uphr and then read back values */
end_comment

begin_define
define|#
directive|define
name|UPHR_MAXCYL
value|0100027
end_define

begin_comment
comment|/* max cyl address */
end_comment

begin_define
define|#
directive|define
name|UPHR_MAXTRAK
value|0100030
end_define

begin_comment
comment|/* max track address */
end_comment

begin_define
define|#
directive|define
name|UPHR_MAXSECT
value|0100031
end_define

begin_comment
comment|/* max sector address */
end_comment

begin_comment
comment|/* uper2 */
end_comment

begin_define
define|#
directive|define
name|UPER2_BSE
value|0100000
end_define

begin_comment
comment|/* bad sector error */
end_comment

begin_define
define|#
directive|define
name|UPER2_SKI
value|0040000
end_define

begin_comment
comment|/* seek incomplete */
end_comment

begin_define
define|#
directive|define
name|UPER2_OPE
value|0020000
end_define

begin_comment
comment|/* operator plug error */
end_comment

begin_define
define|#
directive|define
name|UPER2_IVC
value|0010000
end_define

begin_comment
comment|/* invalid command */
end_comment

begin_define
define|#
directive|define
name|UPER2_LSC
value|0004000
end_define

begin_comment
comment|/* loss of sector clock */
end_comment

begin_define
define|#
directive|define
name|UPER2_LBC
value|0002000
end_define

begin_comment
comment|/* loss of bit clock */
end_comment

begin_define
define|#
directive|define
name|UPER2_MDS
value|0001000
end_define

begin_comment
comment|/* multiple drive select */
end_comment

begin_define
define|#
directive|define
name|UPER2_DCU
value|0000400
end_define

begin_comment
comment|/* dc power unsafe */
end_comment

begin_define
define|#
directive|define
name|UPER2_DVC
value|0000200
end_define

begin_comment
comment|/* device check */
end_comment

begin_define
define|#
directive|define
name|UPER2_ACU
value|0000100
end_define

begin_comment
comment|/* ac power unsafe */
end_comment

begin_comment
comment|/* bits 5 and 4 are spare */
end_comment

begin_define
define|#
directive|define
name|UPER2_DPE
value|0000010
end_define

begin_comment
comment|/* data parity error (0) */
end_comment

begin_comment
comment|/* bits 2-0 are spare */
end_comment

begin_define
define|#
directive|define
name|UPER2_BITS
define|\
value|"\10\20BSE\17SKI\16OPE\15IVC\14LSC\13LBC\12MDS\11DCU\10DVC\7ACU\4DPE"
end_define

begin_comment
comment|/* upof */
end_comment

begin_define
define|#
directive|define
name|UPOF_FMT22
value|0010000
end_define

begin_comment
comment|/* 16 bit format */
end_comment

begin_define
define|#
directive|define
name|UPOF_ECI
value|0004000
end_define

begin_comment
comment|/* ecc inhibit */
end_comment

begin_define
define|#
directive|define
name|UPOF_HCI
value|0002000
end_define

begin_comment
comment|/* header compare inhibit */
end_comment

begin_comment
comment|/* THE SC21 ACTUALLY JUST IMPLEMENTS ADVANCE/RETARD... */
end_comment

begin_define
define|#
directive|define
name|UPOF_P400
value|0020
end_define

begin_comment
comment|/*  +400 uinches */
end_comment

begin_define
define|#
directive|define
name|UPOF_M400
value|0220
end_define

begin_comment
comment|/*  -400 uinches */
end_comment

begin_define
define|#
directive|define
name|UPOF_P800
value|0040
end_define

begin_comment
comment|/*  +800 uinches */
end_comment

begin_define
define|#
directive|define
name|UPOF_M800
value|0240
end_define

begin_comment
comment|/*  -800 uinches */
end_comment

begin_define
define|#
directive|define
name|UPOF_P1200
value|0060
end_define

begin_comment
comment|/* +1200 uinches */
end_comment

begin_define
define|#
directive|define
name|UPOF_M1200
value|0260
end_define

begin_comment
comment|/* -1200 uinches */
end_comment

end_unit

