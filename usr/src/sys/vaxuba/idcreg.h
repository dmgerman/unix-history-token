begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)idcreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_define
define|#
directive|define
name|NRB02SECT
value|40
end_define

begin_comment
comment|/* RB02 sectors/track */
end_comment

begin_define
define|#
directive|define
name|NRB02TRK
value|2
end_define

begin_comment
comment|/* RB02 tracks/cylinder */
end_comment

begin_define
define|#
directive|define
name|NRB02CYL
value|512
end_define

begin_comment
comment|/* RB02 cylinders/disk */
end_comment

begin_define
define|#
directive|define
name|NRB80SECT
value|31
end_define

begin_comment
comment|/* RB80 sectors/track */
end_comment

begin_define
define|#
directive|define
name|NRB80TRK
value|14
end_define

begin_comment
comment|/* RB80 tracks/cylinder */
end_comment

begin_define
define|#
directive|define
name|NRB80CYL
value|559
end_define

begin_comment
comment|/* RB80 cylinders/disk */
end_comment

begin_struct
struct|struct
name|idcdevice
block|{
name|int
name|idccsr
decl_stmt|;
comment|/* control status register */
name|int
name|idcbar
decl_stmt|;
comment|/* bus address register */
name|int
name|idcbcr
decl_stmt|;
comment|/* byte count register */
name|int
name|idcdar
decl_stmt|;
comment|/* disk address register */
name|int
name|idcmpr
decl_stmt|;
comment|/* multi-purpose register */
name|int
name|idceccpos
decl_stmt|;
comment|/* ecc position register */
name|int
name|idceccpat
decl_stmt|;
comment|/* ecc pattern register */
name|int
name|idcreset
decl_stmt|;
comment|/* master reset register */
block|}
struct|;
end_struct

begin_comment
comment|/* idccsr */
end_comment

begin_define
define|#
directive|define
name|IDC_TOI
value|0x10000000
end_define

begin_comment
comment|/* time out inhibit */
end_comment

begin_define
define|#
directive|define
name|IDC_ASSI
value|0x08000000
end_define

begin_comment
comment|/* automatic skip sector inhibit */
end_comment

begin_define
define|#
directive|define
name|IDC_R80
value|0x04000000
end_define

begin_comment
comment|/* selected disk is R80 */
end_comment

begin_define
define|#
directive|define
name|IDC_MTN
value|0x02000000
end_define

begin_comment
comment|/* maintenance */
end_comment

begin_define
define|#
directive|define
name|IDC_IR
value|0x01000000
end_define

begin_comment
comment|/* interrupt request */
end_comment

begin_define
define|#
directive|define
name|IDC_SSE
value|0x00800000
end_define

begin_comment
comment|/* R80 skip sector error */
end_comment

begin_define
define|#
directive|define
name|IDC_SSEI
value|0x00400000
end_define

begin_comment
comment|/* R80 skip sector error inhibit */
end_comment

begin_define
define|#
directive|define
name|IDC_ECS
value|0x00300000
end_define

begin_comment
comment|/* R80 ecc status */
end_comment

begin_define
define|#
directive|define
name|IDC_ECS_NONE
value|0x00000000
end_define

begin_comment
comment|/*   no data error */
end_comment

begin_define
define|#
directive|define
name|IDC_ECS_HARD
value|0x00200000
end_define

begin_comment
comment|/*   hard ecc error */
end_comment

begin_define
define|#
directive|define
name|IDC_ECS_SOFT
value|0x00300000
end_define

begin_comment
comment|/*   soft ecc error */
end_comment

begin_define
define|#
directive|define
name|IDC_ATTN
value|0x000f0000
end_define

begin_comment
comment|/* attention bits */
end_comment

begin_define
define|#
directive|define
name|IDC_ERR
value|0x00008000
end_define

begin_comment
comment|/* composite error */
end_comment

begin_define
define|#
directive|define
name|IDC_DE
value|0x00004000
end_define

begin_comment
comment|/* drive error */
end_comment

begin_define
define|#
directive|define
name|IDC_NXM
value|0x00002000
end_define

begin_comment
comment|/* non-existant memory */
end_comment

begin_define
define|#
directive|define
name|IDC_DLT
value|0x00001000
end_define

begin_comment
comment|/* data late */
end_comment

begin_define
define|#
directive|define
name|IDC_HNF
value|IDC_DLT
end_define

begin_comment
comment|/* header not found */
end_comment

begin_define
define|#
directive|define
name|IDC_DCK
value|0x00000800
end_define

begin_comment
comment|/* data check */
end_comment

begin_define
define|#
directive|define
name|IDC_OPI
value|0x00000400
end_define

begin_comment
comment|/* operation incomplete */
end_comment

begin_define
define|#
directive|define
name|IDC_DS
value|0x00000300
end_define

begin_comment
comment|/* drive select bits */
end_comment

begin_define
define|#
directive|define
name|IDC_CRDY
value|0x00000080
end_define

begin_comment
comment|/* controller ready */
end_comment

begin_define
define|#
directive|define
name|IDC_IE
value|0x00000040
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IDC_FUNC
value|0x0000000e
end_define

begin_comment
comment|/* function code */
end_comment

begin_define
define|#
directive|define
name|IDC_DRDY
value|0x00000001
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|IDC_HARD
value|(IDC_NXM|IDC_DE)
end_define

begin_define
define|#
directive|define
name|IDCCSR_BITS
define|\
value|"\20\35TOI\34ASSI\33R80\32MTN\31IR\30SSE\27SSEI\26ECS1\25ECS0\24ATN3\ \23ATN2\22ATN1\21ATN0\20ERR\17DE\16NXM\15DLT\14DCK\13OPI\12DS1\11DS0\ \10CRDY\7IE\4F2\3F1\2F0\1DRDY"
end_define

begin_comment
comment|/* function codes */
end_comment

begin_define
define|#
directive|define
name|IDC_NOP
value|000
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|IDC_WCHK
value|002
end_define

begin_comment
comment|/* write check data */
end_comment

begin_define
define|#
directive|define
name|IDC_GETSTAT
value|004
end_define

begin_comment
comment|/* get status */
end_comment

begin_define
define|#
directive|define
name|IDC_SEEK
value|006
end_define

begin_comment
comment|/* seek */
end_comment

begin_define
define|#
directive|define
name|IDC_RHDR
value|010
end_define

begin_comment
comment|/* read header */
end_comment

begin_define
define|#
directive|define
name|IDC_WRITE
value|012
end_define

begin_comment
comment|/* write data */
end_comment

begin_define
define|#
directive|define
name|IDC_READ
value|014
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|IDC_RNOHCHK
value|016
end_define

begin_comment
comment|/* read data w/o header check */
end_comment

begin_comment
comment|/* idcmpr for RL02 get status command */
end_comment

begin_define
define|#
directive|define
name|IDCGS_RST
value|010
end_define

begin_comment
comment|/* reset */
end_comment

begin_define
define|#
directive|define
name|IDCGS_GS
value|002
end_define

begin_comment
comment|/* get status, must be 1 */
end_comment

begin_define
define|#
directive|define
name|IDCGS_M
value|001
end_define

begin_comment
comment|/* mark, must be 1 */
end_comment

begin_define
define|#
directive|define
name|IDCGS_GETSTAT
value|(IDCGS_RST|IDCGS_GS|IDCGS_M)
end_define

begin_comment
comment|/* RL02 status word */
end_comment

begin_define
define|#
directive|define
name|IDCDS_WDE
value|0100000
end_define

begin_comment
comment|/* write data error */
end_comment

begin_define
define|#
directive|define
name|IDCDS_HCE
value|0040000
end_define

begin_comment
comment|/* head current error */
end_comment

begin_define
define|#
directive|define
name|IDCDS_WL
value|0020000
end_define

begin_comment
comment|/* write lock */
end_comment

begin_define
define|#
directive|define
name|IDCDS_SKTO
value|0010000
end_define

begin_comment
comment|/* seek timeout */
end_comment

begin_define
define|#
directive|define
name|IDCDS_SPD
value|0004000
end_define

begin_comment
comment|/* spindle error */
end_comment

begin_define
define|#
directive|define
name|IDCDS_WGE
value|0002000
end_define

begin_comment
comment|/* write gate error */
end_comment

begin_define
define|#
directive|define
name|IDCDS_VC
value|0001000
end_define

begin_comment
comment|/* volume check */
end_comment

begin_define
define|#
directive|define
name|IDCDS_DSE
value|0000400
end_define

begin_comment
comment|/* drive select error */
end_comment

begin_define
define|#
directive|define
name|IDCDS_HS
value|0000100
end_define

begin_comment
comment|/* head select */
end_comment

begin_define
define|#
directive|define
name|IDCDS_CO
value|0000040
end_define

begin_comment
comment|/* cover open */
end_comment

begin_define
define|#
directive|define
name|IDCDS_HO
value|0000020
end_define

begin_comment
comment|/* heads out */
end_comment

begin_define
define|#
directive|define
name|IDCDS_BH
value|0000010
end_define

begin_comment
comment|/* brush home */
end_comment

begin_define
define|#
directive|define
name|IDCDS_STATE
value|0000007
end_define

begin_comment
comment|/* drive state */
end_comment

begin_define
define|#
directive|define
name|IDCRB02DS_BITS
define|\
value|"\10\20WDE\17HCE\16WL\15SKTO\14SPD\13WBE\12VC\11DSE\ \7HS\6CO\5HO\4BH\3STC\2STB\1STA"
end_define

begin_comment
comment|/* R80 status word */
end_comment

begin_define
define|#
directive|define
name|IDCDS_WTP
value|0020000
end_define

begin_comment
comment|/* write protect */
end_comment

begin_define
define|#
directive|define
name|IDCDS_DRDY
value|0010000
end_define

begin_comment
comment|/* driver ready */
end_comment

begin_define
define|#
directive|define
name|IDCDS_ONCY
value|0004000
end_define

begin_comment
comment|/* on cylinder */
end_comment

begin_define
define|#
directive|define
name|IDCDS_SKE
value|0002000
end_define

begin_comment
comment|/* seek error */
end_comment

begin_define
define|#
directive|define
name|IDCDS_PLGV
value|0001000
end_define

begin_comment
comment|/* plug valid */
end_comment

begin_define
define|#
directive|define
name|IDCDS_FLT
value|0000400
end_define

begin_comment
comment|/* fault */
end_comment

begin_define
define|#
directive|define
name|IDCRB80DS_BITS
define|\
value|"\10\16WTP\15DRDY\14ONCY\13SKE\12PLGV\11FLT\5SEC4\4SEC3\3SEC2\2SEC1\1SEC0"
end_define

end_unit

