begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)rkreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_define
define|#
directive|define
name|NRK7CYL
value|815
end_define

begin_define
define|#
directive|define
name|NRK6CYL
value|411
end_define

begin_define
define|#
directive|define
name|NRKSECT
value|22
end_define

begin_define
define|#
directive|define
name|NRKTRK
value|3
end_define

begin_struct
struct|struct
name|rkdevice
block|{
name|short
name|rkcs1
decl_stmt|;
comment|/* control status reg 1 */
name|short
name|rkwc
decl_stmt|;
comment|/* word count */
name|u_short
name|rkba
decl_stmt|;
comment|/* bus address */
name|short
name|rkda
decl_stmt|;
comment|/* disk address */
name|short
name|rkcs2
decl_stmt|;
comment|/* control status reg 2 */
name|short
name|rkds
decl_stmt|;
comment|/* drive status */
name|short
name|rker
decl_stmt|;
comment|/* driver error register */
name|short
name|rkatt
decl_stmt|;
comment|/* attention status/offset register */
name|short
name|rkcyl
decl_stmt|;
comment|/* current cylinder register */
name|short
name|rkxxx
decl_stmt|;
name|short
name|rkdb
decl_stmt|;
comment|/* data buffer register */
name|short
name|rkmr1
decl_stmt|;
comment|/* maint reg 1 */
name|short
name|rkec1
decl_stmt|;
comment|/* burst error bit position */
name|short
name|rkec2
decl_stmt|;
comment|/* burst error bit pattern */
name|short
name|rkmr2
decl_stmt|;
comment|/* maint reg 2 */
name|short
name|rkmr3
decl_stmt|;
comment|/* maint reg 3 */
block|}
struct|;
end_struct

begin_comment
comment|/* rkcs1 */
end_comment

begin_define
define|#
directive|define
name|RK_CCLR
value|0100000
end_define

begin_comment
comment|/* controller clear (also error) */
end_comment

begin_define
define|#
directive|define
name|RK_CERR
value|RK_CCLR
end_define

begin_define
define|#
directive|define
name|RK_DI
value|0040000
end_define

begin_comment
comment|/* drive interrupt */
end_comment

begin_define
define|#
directive|define
name|RK_DTCPAR
value|0020000
end_define

begin_comment
comment|/* drive to controller parity */
end_comment

begin_define
define|#
directive|define
name|RK_CFMT
value|0010000
end_define

begin_comment
comment|/* 18 bit word format */
end_comment

begin_define
define|#
directive|define
name|RK_CTO
value|0004000
end_define

begin_comment
comment|/* controller timeout */
end_comment

begin_define
define|#
directive|define
name|RK_CDT
value|0002000
end_define

begin_comment
comment|/* drive type (rk07/rk06) */
end_comment

begin_comment
comment|/* bits 8 and 9 are the extended bus address */
end_comment

begin_define
define|#
directive|define
name|RK_CRDY
value|0000200
end_define

begin_comment
comment|/* controller ready */
end_comment

begin_define
define|#
directive|define
name|RK_IE
value|0000100
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_comment
comment|/* bits 1 to 4 are the function code */
end_comment

begin_define
define|#
directive|define
name|RK_GO
value|0000001
end_define

begin_comment
comment|/* commands */
end_comment

begin_define
define|#
directive|define
name|RK_SELECT
value|000
end_define

begin_comment
comment|/* select drive */
end_comment

begin_define
define|#
directive|define
name|RK_PACK
value|002
end_define

begin_comment
comment|/* pack acknowledge */
end_comment

begin_define
define|#
directive|define
name|RK_DCLR
value|004
end_define

begin_comment
comment|/* drive clear */
end_comment

begin_define
define|#
directive|define
name|RK_UNLOAD
value|006
end_define

begin_comment
comment|/* unload */
end_comment

begin_define
define|#
directive|define
name|RK_START
value|010
end_define

begin_comment
comment|/* start spindle */
end_comment

begin_define
define|#
directive|define
name|RK_RECAL
value|012
end_define

begin_comment
comment|/* recalibrate */
end_comment

begin_define
define|#
directive|define
name|RK_OFFSET
value|014
end_define

begin_comment
comment|/* offset */
end_comment

begin_define
define|#
directive|define
name|RK_SEEK
value|016
end_define

begin_comment
comment|/* seek */
end_comment

begin_define
define|#
directive|define
name|RK_READ
value|020
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|RK_WRITE
value|022
end_define

begin_comment
comment|/* write data */
end_comment

begin_define
define|#
directive|define
name|RK_RHDR
value|026
end_define

begin_comment
comment|/* read header */
end_comment

begin_define
define|#
directive|define
name|RK_WHDR
value|030
end_define

begin_comment
comment|/* write header */
end_comment

begin_comment
comment|/* rkcs2 */
end_comment

begin_define
define|#
directive|define
name|RKCS2_DLT
value|0100000
end_define

begin_comment
comment|/* data late */
end_comment

begin_define
define|#
directive|define
name|RKCS2_WCE
value|0040000
end_define

begin_comment
comment|/* write check */
end_comment

begin_define
define|#
directive|define
name|RKCS2_UPE
value|0020000
end_define

begin_comment
comment|/* unibus parity */
end_comment

begin_define
define|#
directive|define
name|RKCS2_NED
value|0010000
end_define

begin_comment
comment|/* non-existant drive */
end_comment

begin_define
define|#
directive|define
name|RKCS2_NEM
value|0004000
end_define

begin_comment
comment|/* non-existant memory */
end_comment

begin_define
define|#
directive|define
name|RKCS2_PGE
value|0002000
end_define

begin_comment
comment|/* programming error */
end_comment

begin_define
define|#
directive|define
name|RKCS2_MDS
value|0001000
end_define

begin_comment
comment|/* multiple drive select */
end_comment

begin_define
define|#
directive|define
name|RKCS2_UFE
value|0000400
end_define

begin_comment
comment|/* unit field error */
end_comment

begin_define
define|#
directive|define
name|RKCS2_OR
value|0000200
end_define

begin_comment
comment|/* output ready */
end_comment

begin_define
define|#
directive|define
name|RKCS2_IR
value|0000100
end_define

begin_comment
comment|/* input ready */
end_comment

begin_define
define|#
directive|define
name|RKCS2_SCLR
value|0000040
end_define

begin_comment
comment|/* subsystem clear */
end_comment

begin_define
define|#
directive|define
name|RKCS2_BAI
value|0000020
end_define

begin_comment
comment|/* bus address increment inhibit */
end_comment

begin_define
define|#
directive|define
name|RKCS2_RLS
value|0000010
end_define

begin_comment
comment|/* release */
end_comment

begin_comment
comment|/* bits 0-2 are drive select */
end_comment

begin_define
define|#
directive|define
name|RKCS2_BITS
define|\
value|"\10\20DLT\17WCE\16UPE\15NED\14NEM\13PGE\12MDS\11UFE\ \10OR\7IR\6SCLR\5BAI\4RLS"
end_define

begin_define
define|#
directive|define
name|RKCS2_HARD
value|(RKCS2_NED|RKCS2_PGE)
end_define

begin_comment
comment|/* rkds */
end_comment

begin_define
define|#
directive|define
name|RKDS_SVAL
value|0100000
end_define

begin_comment
comment|/* status valid */
end_comment

begin_define
define|#
directive|define
name|RKDS_CDA
value|0040000
end_define

begin_comment
comment|/* current drive attention */
end_comment

begin_define
define|#
directive|define
name|RKDS_PIP
value|0020000
end_define

begin_comment
comment|/* positioning in progress */
end_comment

begin_comment
comment|/* bit 12 is spare */
end_comment

begin_define
define|#
directive|define
name|RKDS_WRL
value|0004000
end_define

begin_comment
comment|/* write lock */
end_comment

begin_comment
comment|/* bits 9 and 10 are spare */
end_comment

begin_define
define|#
directive|define
name|RKDS_DDT
value|0000400
end_define

begin_comment
comment|/* disk drive type */
end_comment

begin_define
define|#
directive|define
name|RKDS_DRDY
value|0000200
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|RKDS_VV
value|0000100
end_define

begin_comment
comment|/* volume valid */
end_comment

begin_define
define|#
directive|define
name|RKDS_DROT
value|0000040
end_define

begin_comment
comment|/* drive off track */
end_comment

begin_define
define|#
directive|define
name|RKDS_SPLS
value|0000020
end_define

begin_comment
comment|/* speed loss */
end_comment

begin_define
define|#
directive|define
name|RKDS_ACLO
value|0000010
end_define

begin_comment
comment|/* ac low */
end_comment

begin_define
define|#
directive|define
name|RKDS_OFF
value|0000004
end_define

begin_comment
comment|/* offset mode */
end_comment

begin_define
define|#
directive|define
name|RKDS_DRA
value|0000001
end_define

begin_comment
comment|/* drive available */
end_comment

begin_define
define|#
directive|define
name|RKDS_DREADY
value|(RKDS_DRA|RKDS_VV|RKDS_DRDY)
end_define

begin_define
define|#
directive|define
name|RKDS_BITS
define|\
value|"\10\20SVAL\17CDA\16PIP\14WRL\11DDT\ \10DRDY\7VV\6DROT\5SPLS\4ACLO\3OFF\1DRA"
end_define

begin_define
define|#
directive|define
name|RKDS_HARD
value|(RKDS_ACLO|RKDS_SPLS)
end_define

begin_comment
comment|/* rker */
end_comment

begin_define
define|#
directive|define
name|RKER_DCK
value|0100000
end_define

begin_comment
comment|/* data check */
end_comment

begin_define
define|#
directive|define
name|RKER_UNS
value|0040000
end_define

begin_comment
comment|/* drive unsafe */
end_comment

begin_define
define|#
directive|define
name|RKER_OPI
value|0020000
end_define

begin_comment
comment|/* operation incomplete */
end_comment

begin_define
define|#
directive|define
name|RKER_DTE
value|0010000
end_define

begin_comment
comment|/* drive timing error */
end_comment

begin_define
define|#
directive|define
name|RKER_WLE
value|0004000
end_define

begin_comment
comment|/* write lock error */
end_comment

begin_define
define|#
directive|define
name|RKER_IDAE
value|0002000
end_define

begin_comment
comment|/* invalid disk address error */
end_comment

begin_define
define|#
directive|define
name|RKER_COE
value|0001000
end_define

begin_comment
comment|/* cylinder overflow error */
end_comment

begin_define
define|#
directive|define
name|RKER_HRVC
value|0000400
end_define

begin_comment
comment|/* header vertical redundancy check */
end_comment

begin_define
define|#
directive|define
name|RKER_BSE
value|0000200
end_define

begin_comment
comment|/* bad sector error */
end_comment

begin_define
define|#
directive|define
name|RKER_ECH
value|0000100
end_define

begin_comment
comment|/* hard ecc error */
end_comment

begin_define
define|#
directive|define
name|RKER_DTYE
value|0000040
end_define

begin_comment
comment|/* drive type error */
end_comment

begin_define
define|#
directive|define
name|RKER_FMTE
value|0000020
end_define

begin_comment
comment|/* format error */
end_comment

begin_define
define|#
directive|define
name|RKER_DRPAR
value|0000010
end_define

begin_comment
comment|/* control-to-drive parity error */
end_comment

begin_define
define|#
directive|define
name|RKER_NXF
value|0000004
end_define

begin_comment
comment|/* non-executable function */
end_comment

begin_define
define|#
directive|define
name|RKER_SKI
value|0000002
end_define

begin_comment
comment|/* seek incomplete */
end_comment

begin_define
define|#
directive|define
name|RKER_ILF
value|0000001
end_define

begin_comment
comment|/* illegal function */
end_comment

begin_define
define|#
directive|define
name|RKER_BITS
define|\
value|"\10\20DCK\17UNS\16OPI\15DTE\14WLE\13IDAE\12COE\11HRVC\ \10BSE\7ECH\6DTYE\5FMTE\4DRPAR\3NXF\2SKI\1ILF"
end_define

begin_define
define|#
directive|define
name|RKER_HARD
define|\
value|(RKER_WLE|RKER_IDAE|RKER_COE|RKER_DTYE|RKER_FMTE|RKER_ILF)
end_define

begin_comment
comment|/* offset bits in rkas */
end_comment

begin_define
define|#
directive|define
name|RKAS_P400
value|0020
end_define

begin_comment
comment|/*  +400 RK06,  +200 RK07 */
end_comment

begin_define
define|#
directive|define
name|RKAS_M400
value|0220
end_define

begin_comment
comment|/*  -400 RK06,  -200 RK07 */
end_comment

begin_define
define|#
directive|define
name|RKAS_P800
value|0040
end_define

begin_comment
comment|/*  +800 RK06,  +400 RK07 */
end_comment

begin_define
define|#
directive|define
name|RKAS_M800
value|0240
end_define

begin_comment
comment|/*  -800 RK06,  -400 RK07 */
end_comment

begin_define
define|#
directive|define
name|RKAS_P1200
value|0060
end_define

begin_comment
comment|/*  +800 RK06,  +400 RK07 */
end_comment

begin_define
define|#
directive|define
name|RKAS_M1200
value|0260
end_define

begin_comment
comment|/* -1200 RK06, -1200 RK07 */
end_comment

end_unit

