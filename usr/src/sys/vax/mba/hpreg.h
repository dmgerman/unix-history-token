begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	hpreg.h	4.4	81/02/25	*/
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
name|int
name|hper2
decl_stmt|;
comment|/* error register 2 */
name|int
name|hper3
decl_stmt|;
comment|/* error register 3 */
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
name|HP_ATA
value|0100000
end_define

begin_comment
comment|/* attention active */
end_comment

begin_define
define|#
directive|define
name|HP_ERR
value|0040000
end_define

begin_comment
comment|/* composite drive error */
end_comment

begin_define
define|#
directive|define
name|HP_PIP
value|0020000
end_define

begin_comment
comment|/* positioning in progress */
end_comment

begin_define
define|#
directive|define
name|HP_MOL
value|0010000
end_define

begin_comment
comment|/* medium on line */
end_comment

begin_define
define|#
directive|define
name|HP_WRL
value|0004000
end_define

begin_comment
comment|/* write locked */
end_comment

begin_define
define|#
directive|define
name|HP_LST
value|0002000
end_define

begin_comment
comment|/* last sector transferred */
end_comment

begin_define
define|#
directive|define
name|HP_PGM
value|0001000
end_define

begin_comment
comment|/* programmable */
end_comment

begin_define
define|#
directive|define
name|HP_DPR
value|0000400
end_define

begin_comment
comment|/* drive present */
end_comment

begin_define
define|#
directive|define
name|HP_DRY
value|0000200
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|HP_VV
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
name|HP_OM
value|0000001
end_define

begin_comment
comment|/* offset mode */
end_comment

begin_define
define|#
directive|define
name|HP_DREADY
value|(HP_DPR|HP_DRY|HP_MOL|HP_VV)
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
name|HP_DCK
value|0100000
end_define

begin_comment
comment|/* data check */
end_comment

begin_define
define|#
directive|define
name|HP_UNS
value|0040000
end_define

begin_comment
comment|/* drive unsafe */
end_comment

begin_define
define|#
directive|define
name|HP_OPI
value|0020000
end_define

begin_comment
comment|/* operation incomplete */
end_comment

begin_define
define|#
directive|define
name|HP_DTE
value|0010000
end_define

begin_comment
comment|/* drive timing error */
end_comment

begin_define
define|#
directive|define
name|HP_WLE
value|0004000
end_define

begin_comment
comment|/* write lock error */
end_comment

begin_define
define|#
directive|define
name|HP_IAE
value|0002000
end_define

begin_comment
comment|/* invalid address error */
end_comment

begin_define
define|#
directive|define
name|HP_AOE
value|0001000
end_define

begin_comment
comment|/* address overflow error */
end_comment

begin_define
define|#
directive|define
name|HP_HCRC
value|0000400
end_define

begin_comment
comment|/* header crc error */
end_comment

begin_define
define|#
directive|define
name|HP_HCE
value|0000200
end_define

begin_comment
comment|/* header compare error */
end_comment

begin_define
define|#
directive|define
name|HP_ECH
value|0000100
end_define

begin_comment
comment|/* ecc hard error */
end_comment

begin_define
define|#
directive|define
name|HP_WCF
value|0000040
end_define

begin_comment
comment|/* write clock fail */
end_comment

begin_define
define|#
directive|define
name|HP_FER
value|0000020
end_define

begin_comment
comment|/* format error */
end_comment

begin_define
define|#
directive|define
name|HP_PAR
value|0000010
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|HP_RMR
value|0000004
end_define

begin_comment
comment|/* register modification refused */
end_comment

begin_define
define|#
directive|define
name|HP_ILR
value|0000002
end_define

begin_comment
comment|/* illegal register */
end_comment

begin_define
define|#
directive|define
name|HP_ILF
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

begin_comment
comment|/* THIS NEEDS TO BE DOUBLE CHECKED... */
end_comment

begin_define
define|#
directive|define
name|HPER1_HARD
value|(HP_UNS|HP_WLE|HP_IAE|HP_AOE|HP_FER|HP_RMR|HP_ILR|HP_ILF)
end_define

begin_comment
comment|/* hper2 */
end_comment

begin_define
define|#
directive|define
name|HP_BSE
value|0100000
end_define

begin_comment
comment|/* bad sector error */
end_comment

begin_define
define|#
directive|define
name|HP_SKI
value|0040000
end_define

begin_comment
comment|/* seek incomplete */
end_comment

begin_define
define|#
directive|define
name|HP_OPE
value|0020000
end_define

begin_comment
comment|/* operator plug error */
end_comment

begin_define
define|#
directive|define
name|HP_IVC
value|0010000
end_define

begin_comment
comment|/* invalid command */
end_comment

begin_define
define|#
directive|define
name|HP_LSC
value|0004000
end_define

begin_comment
comment|/* loss of system clock */
end_comment

begin_define
define|#
directive|define
name|HP_LBC
value|0002000
end_define

begin_comment
comment|/* loss of bit check */
end_comment

begin_define
define|#
directive|define
name|HP_DVC
value|0000200
end_define

begin_comment
comment|/* device check */
end_comment

begin_define
define|#
directive|define
name|HP_DPE
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
value|"\10\20BSE\17SKI\16OPE\15IVC\14LSC\13LBC\10DVC\4DPE"
end_define

begin_define
define|#
directive|define
name|HPER2_HARD
value|(HP_BSE|HP_OPE)
end_define

begin_comment
comment|/* hpof */
end_comment

begin_define
define|#
directive|define
name|HP_CMO
value|0100000
end_define

begin_comment
comment|/* command modifier */
end_comment

begin_define
define|#
directive|define
name|HP_MTD
value|0040000
end_define

begin_comment
comment|/* move track descriptor */
end_comment

begin_define
define|#
directive|define
name|HP_FMT22
value|0010000
end_define

begin_comment
comment|/* 16 bit format */
end_comment

begin_define
define|#
directive|define
name|HP_ECI
value|0004000
end_define

begin_comment
comment|/* ecc inhibit */
end_comment

begin_define
define|#
directive|define
name|HP_HCI
value|0002000
end_define

begin_comment
comment|/* header compare inhibit */
end_comment

begin_define
define|#
directive|define
name|HP_SSEI
value|0001000
end_define

begin_comment
comment|/* skip sector inhibit */
end_comment

begin_define
define|#
directive|define
name|HP_P400
value|020
end_define

begin_comment
comment|/*  +400 uinches */
end_comment

begin_define
define|#
directive|define
name|HP_M400
value|0220
end_define

begin_comment
comment|/*  -400 uinches */
end_comment

begin_define
define|#
directive|define
name|HP_P800
value|040
end_define

begin_comment
comment|/*  +800 uinches */
end_comment

begin_define
define|#
directive|define
name|HP_M800
value|0240
end_define

begin_comment
comment|/*  -800 uinches */
end_comment

begin_define
define|#
directive|define
name|HP_P1200
value|060
end_define

begin_comment
comment|/* +1200 uinches */
end_comment

begin_define
define|#
directive|define
name|HP_M1200
value|0260
end_define

begin_comment
comment|/* -1200 uinches */
end_comment

end_unit

