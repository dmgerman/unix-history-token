begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)hpreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_struct
struct|struct
name|hpdevice
block|{
name|int
name|hpcs1
decl_stmt|;
comment|/* control and status register 1 */
name|int
name|hpds
decl_stmt|;
comment|/* drive status */
name|int
name|hper1
decl_stmt|;
comment|/* error register 1 */
name|int
name|hpmr
decl_stmt|;
comment|/* maintenance */
name|int
name|hpas
decl_stmt|;
comment|/* attention summary */
name|int
name|hpda
decl_stmt|;
comment|/* desired address register */
name|int
name|hpdt
decl_stmt|;
comment|/* drive type */
name|int
name|hpla
decl_stmt|;
comment|/* look ahead */
name|int
name|hpsn
decl_stmt|;
comment|/* serial number */
name|int
name|hpof
decl_stmt|;
comment|/* offset register */
name|int
name|hpdc
decl_stmt|;
comment|/* desired cylinder address register */
name|int
name|hpcc
decl_stmt|;
comment|/* current cylinder */
define|#
directive|define
name|hphr
value|hpcc
comment|/* holding register */
comment|/* on an rp drive, mr2 is called er2 and er2 is called er3 */
comment|/* we use rm terminology here */
name|int
name|hpmr2
decl_stmt|;
comment|/* maintenance register 2 */
name|int
name|hper2
decl_stmt|;
comment|/* error register 2 */
name|int
name|hpec1
decl_stmt|;
comment|/* burst error bit position */
name|int
name|hpec2
decl_stmt|;
comment|/* burst error bit pattern */
block|}
struct|;
end_struct

begin_comment
comment|/* hpcs1 */
end_comment

begin_define
define|#
directive|define
name|HP_SC
value|0100000
end_define

begin_comment
comment|/* special condition */
end_comment

begin_define
define|#
directive|define
name|HP_TRE
value|0040000
end_define

begin_comment
comment|/* transfer error */
end_comment

begin_define
define|#
directive|define
name|HP_DVA
value|0004000
end_define

begin_comment
comment|/* drive available */
end_comment

begin_define
define|#
directive|define
name|HP_RDY
value|0000200
end_define

begin_comment
comment|/* controller ready */
end_comment

begin_define
define|#
directive|define
name|HP_IE
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
name|HP_GO
value|0000001
end_define

begin_comment
comment|/* commands */
end_comment

begin_define
define|#
directive|define
name|HP_NOP
value|000
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|HP_UNLOAD
value|002
end_define

begin_comment
comment|/* offline drive */
end_comment

begin_define
define|#
directive|define
name|HP_SEEK
value|004
end_define

begin_comment
comment|/* seek */
end_comment

begin_define
define|#
directive|define
name|HP_RECAL
value|006
end_define

begin_comment
comment|/* recalibrate */
end_comment

begin_define
define|#
directive|define
name|HP_DCLR
value|010
end_define

begin_comment
comment|/* drive clear */
end_comment

begin_define
define|#
directive|define
name|HP_RELEASE
value|012
end_define

begin_comment
comment|/* release */
end_comment

begin_define
define|#
directive|define
name|HP_OFFSET
value|014
end_define

begin_comment
comment|/* offset */
end_comment

begin_define
define|#
directive|define
name|HP_RTC
value|016
end_define

begin_comment
comment|/* return to centerline */
end_comment

begin_define
define|#
directive|define
name|HP_PRESET
value|020
end_define

begin_comment
comment|/* read-in preset */
end_comment

begin_define
define|#
directive|define
name|HP_PACK
value|022
end_define

begin_comment
comment|/* pack acknowledge */
end_comment

begin_define
define|#
directive|define
name|HP_SEARCH
value|030
end_define

begin_comment
comment|/* search */
end_comment

begin_define
define|#
directive|define
name|HP_DIAGNOSE
value|034
end_define

begin_comment
comment|/* diagnose drive */
end_comment

begin_define
define|#
directive|define
name|HP_WCDATA
value|050
end_define

begin_comment
comment|/* write check data */
end_comment

begin_define
define|#
directive|define
name|HP_WCHDR
value|052
end_define

begin_comment
comment|/* write check header and data */
end_comment

begin_define
define|#
directive|define
name|HP_WCOM
value|060
end_define

begin_comment
comment|/* write data */
end_comment

begin_define
define|#
directive|define
name|HP_WHDR
value|062
end_define

begin_comment
comment|/* write header */
end_comment

begin_define
define|#
directive|define
name|HP_WTRACKD
value|064
end_define

begin_comment
comment|/* write track descriptor */
end_comment

begin_define
define|#
directive|define
name|HP_RCOM
value|070
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|HP_RHDR
value|072
end_define

begin_comment
comment|/* read header and data */
end_comment

begin_define
define|#
directive|define
name|HP_RTRACKD
value|074
end_define

begin_comment
comment|/* read track descriptor */
end_comment

begin_comment
comment|/* hpds */
end_comment

begin_define
define|#
directive|define
name|HPDS_ATA
value|0100000
end_define

begin_comment
comment|/* attention active */
end_comment

begin_define
define|#
directive|define
name|HPDS_ERR
value|0040000
end_define

begin_comment
comment|/* composite drive error */
end_comment

begin_define
define|#
directive|define
name|HPDS_PIP
value|0020000
end_define

begin_comment
comment|/* positioning in progress */
end_comment

begin_define
define|#
directive|define
name|HPDS_MOL
value|0010000
end_define

begin_comment
comment|/* medium on line */
end_comment

begin_define
define|#
directive|define
name|HPDS_WRL
value|0004000
end_define

begin_comment
comment|/* write locked */
end_comment

begin_define
define|#
directive|define
name|HPDS_LST
value|0002000
end_define

begin_comment
comment|/* last sector transferred */
end_comment

begin_define
define|#
directive|define
name|HPDS_PGM
value|0001000
end_define

begin_comment
comment|/* programmable */
end_comment

begin_define
define|#
directive|define
name|HPDS_DPR
value|0000400
end_define

begin_comment
comment|/* drive present */
end_comment

begin_define
define|#
directive|define
name|HPDS_DRY
value|0000200
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|HPDS_VV
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
name|HPDS_OM
value|0000001
end_define

begin_comment
comment|/* offset mode */
end_comment

begin_define
define|#
directive|define
name|HPDS_DREADY
value|(HPDS_DPR|HPDS_DRY|HPDS_MOL|HPDS_VV)
end_define

begin_define
define|#
directive|define
name|HPDS_BITS
define|\
value|"\10\20ATA\17ERR\16PIP\15MOL\14WRL\13LST\12PGM\11DPR\10DRY\7VV\1OM"
end_define

begin_comment
comment|/* hper1 */
end_comment

begin_define
define|#
directive|define
name|HPER1_DCK
value|0100000
end_define

begin_comment
comment|/* data check */
end_comment

begin_define
define|#
directive|define
name|HPER1_UNS
value|0040000
end_define

begin_comment
comment|/* drive unsafe */
end_comment

begin_define
define|#
directive|define
name|HPER1_OPI
value|0020000
end_define

begin_comment
comment|/* operation incomplete */
end_comment

begin_define
define|#
directive|define
name|HPER1_DTE
value|0010000
end_define

begin_comment
comment|/* drive timing error */
end_comment

begin_define
define|#
directive|define
name|HPER1_WLE
value|0004000
end_define

begin_comment
comment|/* write lock error */
end_comment

begin_define
define|#
directive|define
name|HPER1_IAE
value|0002000
end_define

begin_comment
comment|/* invalid address error */
end_comment

begin_define
define|#
directive|define
name|HPER1_AOE
value|0001000
end_define

begin_comment
comment|/* address overflow error */
end_comment

begin_define
define|#
directive|define
name|HPER1_HCRC
value|0000400
end_define

begin_comment
comment|/* header crc error */
end_comment

begin_define
define|#
directive|define
name|HPER1_HCE
value|0000200
end_define

begin_comment
comment|/* header compare error */
end_comment

begin_define
define|#
directive|define
name|HPER1_ECH
value|0000100
end_define

begin_comment
comment|/* ecc hard error */
end_comment

begin_define
define|#
directive|define
name|HPER1_WCF
value|0000040
end_define

begin_comment
comment|/* write clock fail */
end_comment

begin_define
define|#
directive|define
name|HPER1_FER
value|0000020
end_define

begin_comment
comment|/* format error */
end_comment

begin_define
define|#
directive|define
name|HPER1_PAR
value|0000010
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|HPER1_RMR
value|0000004
end_define

begin_comment
comment|/* register modification refused */
end_comment

begin_define
define|#
directive|define
name|HPER1_ILR
value|0000002
end_define

begin_comment
comment|/* illegal register */
end_comment

begin_define
define|#
directive|define
name|HPER1_ILF
value|0000001
end_define

begin_comment
comment|/* illegal function */
end_comment

begin_define
define|#
directive|define
name|HPER1_BITS
define|\
value|"\10\20DCK\17UNS\16OPI\15DTE\14WLE\13IAE\12AOE\11HCRC\10HCE\ \7ECH\6WCF\5FER\4PAR\3RMR\2ILR\1ILF"
end_define

begin_define
define|#
directive|define
name|HPER1_HARD
define|\
value|(HPER1_WLE|HPER1_IAE|HPER1_AOE|\ 	 HPER1_FER|HPER1_RMR|HPER1_ILR|HPER1_ILF)
end_define

begin_comment
comment|/* hper2 */
end_comment

begin_define
define|#
directive|define
name|HPER2_BSE
value|0100000
end_define

begin_comment
comment|/* bad sector error */
end_comment

begin_define
define|#
directive|define
name|HPER2_SKI
value|0040000
end_define

begin_comment
comment|/* seek incomplete */
end_comment

begin_define
define|#
directive|define
name|HPER2_OPE
value|0020000
end_define

begin_comment
comment|/* operator plug error */
end_comment

begin_define
define|#
directive|define
name|HPER2_IVC
value|0010000
end_define

begin_comment
comment|/* invalid command */
end_comment

begin_define
define|#
directive|define
name|HPER2_LSC
value|0004000
end_define

begin_comment
comment|/* loss of system clock */
end_comment

begin_define
define|#
directive|define
name|HPER2_LBC
value|0002000
end_define

begin_comment
comment|/* loss of bit check */
end_comment

begin_define
define|#
directive|define
name|HPER2_DVC
value|0000200
end_define

begin_comment
comment|/* device check */
end_comment

begin_define
define|#
directive|define
name|HPER2_SSE
value|0000040
end_define

begin_comment
comment|/* skip sector error (rm80) */
end_comment

begin_define
define|#
directive|define
name|HPER2_DPE
value|0000010
end_define

begin_comment
comment|/* data parity error */
end_comment

begin_define
define|#
directive|define
name|HPER2_BITS
define|\
value|"\10\20BSE\17SKI\16OPE\15IVC\14LSC\13LBC\10DVC\6SSE\4DPE"
end_define

begin_define
define|#
directive|define
name|HPER2_HARD
value|(HPER2_OPE)
end_define

begin_comment
comment|/* hpof */
end_comment

begin_define
define|#
directive|define
name|HPOF_CMO
value|0100000
end_define

begin_comment
comment|/* command modifier */
end_comment

begin_define
define|#
directive|define
name|HPOF_MTD
value|0040000
end_define

begin_comment
comment|/* move track descriptor */
end_comment

begin_define
define|#
directive|define
name|HPOF_FMT22
value|0010000
end_define

begin_comment
comment|/* 16 bit format */
end_comment

begin_define
define|#
directive|define
name|HPOF_ECI
value|0004000
end_define

begin_comment
comment|/* ecc inhibit */
end_comment

begin_define
define|#
directive|define
name|HPOF_HCI
value|0002000
end_define

begin_comment
comment|/* header compare inhibit */
end_comment

begin_define
define|#
directive|define
name|HPOF_SSEI
value|0001000
end_define

begin_comment
comment|/* skip sector inhibit */
end_comment

begin_define
define|#
directive|define
name|HPOF_P400
value|020
end_define

begin_comment
comment|/*  +400 uinches */
end_comment

begin_define
define|#
directive|define
name|HPOF_M400
value|0220
end_define

begin_comment
comment|/*  -400 uinches */
end_comment

begin_define
define|#
directive|define
name|HPOF_P800
value|040
end_define

begin_comment
comment|/*  +800 uinches */
end_comment

begin_define
define|#
directive|define
name|HPOF_M800
value|0240
end_define

begin_comment
comment|/*  -800 uinches */
end_comment

begin_define
define|#
directive|define
name|HPOF_P1200
value|060
end_define

begin_comment
comment|/* +1200 uinches */
end_comment

begin_define
define|#
directive|define
name|HPOF_M1200
value|0260
end_define

begin_comment
comment|/* -1200 uinches */
end_comment

begin_comment
comment|/* hphr (alias hpcc) commands */
end_comment

begin_define
define|#
directive|define
name|HPHR_MAXCYL
value|0x8017
end_define

begin_comment
comment|/* maximum cylinder address */
end_comment

begin_define
define|#
directive|define
name|HPHR_MAXTRAK
value|0x8018
end_define

begin_comment
comment|/* maximum track address */
end_comment

begin_define
define|#
directive|define
name|HPHR_MAXSECT
value|0x8019
end_define

begin_comment
comment|/* maximum sector address */
end_comment

begin_define
define|#
directive|define
name|HPHR_FMTENABLE
value|0xffff
end_define

begin_comment
comment|/* enable format command in cs1 */
end_comment

begin_comment
comment|/* hpmr */
end_comment

begin_define
define|#
directive|define
name|HPMR_SZ
value|0174000
end_define

begin_comment
comment|/* ML11 system size */
end_comment

begin_define
define|#
directive|define
name|HPMR_ARRTYP
value|0002000
end_define

begin_comment
comment|/* ML11 array type */
end_comment

begin_define
define|#
directive|define
name|HPMR_TRT
value|0001400
end_define

begin_comment
comment|/* ML11 transfer rate */
end_comment

begin_comment
comment|/*  * Systems Industries kludge: use value in  * the serial # register to figure out real drive type.  */
end_comment

begin_define
define|#
directive|define
name|SIMB_MB
value|0xff00
end_define

begin_comment
comment|/* model byte value */
end_comment

begin_define
define|#
directive|define
name|SIMB_S6
value|0x2000
end_define

begin_comment
comment|/* switch s6 */
end_comment

begin_define
define|#
directive|define
name|SIMB_LU
value|0x0007
end_define

begin_comment
comment|/* logical unit (should = drive #) */
end_comment

begin_define
define|#
directive|define
name|SI9775D
value|0x0700
end_define

begin_comment
comment|/* 9775 direct */
end_comment

begin_define
define|#
directive|define
name|SI9775M
value|0x0e00
end_define

begin_comment
comment|/* 9775 mapped */
end_comment

begin_define
define|#
directive|define
name|SI9730D
value|0x0b00
end_define

begin_comment
comment|/* 9730 direct */
end_comment

begin_define
define|#
directive|define
name|SI9730M
value|0x0d00
end_define

begin_comment
comment|/* 9730 mapped */
end_comment

begin_define
define|#
directive|define
name|SI9766
value|0x0300
end_define

begin_comment
comment|/* 9766 */
end_comment

begin_define
define|#
directive|define
name|SI9762
value|0x0100
end_define

begin_comment
comment|/* 9762 */
end_comment

begin_define
define|#
directive|define
name|SICAPD
value|0x0500
end_define

begin_comment
comment|/* Capricorn direct */
end_comment

begin_define
define|#
directive|define
name|SICAPN
value|0x0400
end_define

begin_comment
comment|/* Capricorn mapped */
end_comment

begin_define
define|#
directive|define
name|SI9751D
value|0x0f00
end_define

begin_comment
comment|/* Eagle direct */
end_comment

begin_define
define|#
directive|define
name|SIRM03
value|0x8000
end_define

begin_comment
comment|/* RM03 indication */
end_comment

begin_define
define|#
directive|define
name|SIRM05
value|0x0000
end_define

begin_comment
comment|/* RM05 pseudo-indication */
end_comment

end_unit

