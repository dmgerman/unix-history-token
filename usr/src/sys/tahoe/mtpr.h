begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)mtpr.h	7.1 (Berkeley) 5/21/88  *	from mtpr.h	4.5	82/11/05  */
end_comment

begin_comment
comment|/*  * TAHOE processor register numbers  */
end_comment

begin_define
define|#
directive|define
name|SBR
value|0x0
end_define

begin_comment
comment|/* system base register */
end_comment

begin_define
define|#
directive|define
name|SLR
value|0x1
end_define

begin_comment
comment|/* system length register */
end_comment

begin_define
define|#
directive|define
name|P0BR
value|0x2
end_define

begin_comment
comment|/* p0 base register */
end_comment

begin_define
define|#
directive|define
name|P0LR
value|0x3
end_define

begin_comment
comment|/* p0 length register */
end_comment

begin_define
define|#
directive|define
name|P1BR
value|0x4
end_define

begin_comment
comment|/* p1 base register */
end_comment

begin_define
define|#
directive|define
name|P1LR
value|0x5
end_define

begin_comment
comment|/* p1 length register */
end_comment

begin_define
define|#
directive|define
name|P2BR
value|0x6
end_define

begin_comment
comment|/* p2 base register */
end_comment

begin_define
define|#
directive|define
name|P2LR
value|0x7
end_define

begin_comment
comment|/* p2 length register */
end_comment

begin_define
define|#
directive|define
name|IPL
value|0x8
end_define

begin_comment
comment|/* interrupt priority level */
end_comment

begin_define
define|#
directive|define
name|MME
value|0x9
end_define

begin_comment
comment|/* memory management enable */
end_comment

begin_define
define|#
directive|define
name|TBIA
value|0xa
end_define

begin_comment
comment|/* translation buffer invalidate all */
end_comment

begin_define
define|#
directive|define
name|TBIS
value|0xb
end_define

begin_comment
comment|/* translation buffer invalidate single */
end_comment

begin_define
define|#
directive|define
name|DCK
value|0xc
end_define

begin_comment
comment|/* data cache key */
end_comment

begin_define
define|#
directive|define
name|CCK
value|0xd
end_define

begin_comment
comment|/* code cache key */
end_comment

begin_define
define|#
directive|define
name|PCBB
value|0xe
end_define

begin_comment
comment|/* process control block base */
end_comment

begin_define
define|#
directive|define
name|ISP
value|0xf
end_define

begin_comment
comment|/* interrupt stack pointer */
end_comment

begin_define
define|#
directive|define
name|SIRR
value|0x10
end_define

begin_comment
comment|/* software interrupt request */
end_comment

begin_define
define|#
directive|define
name|SISR
value|0x11
end_define

begin_comment
comment|/* software interrupt summary */
end_comment

begin_define
define|#
directive|define
name|SCBB
value|0x12
end_define

begin_comment
comment|/* system control block base */
end_comment

begin_define
define|#
directive|define
name|KSP
value|0x13
end_define

begin_comment
comment|/* kernelack pointer */
end_comment

begin_define
define|#
directive|define
name|USP
value|0x14
end_define

begin_comment
comment|/* user stack pointer */
end_comment

begin_define
define|#
directive|define
name|CPMDCB
value|0x15
end_define

begin_comment
comment|/* CP master DCM pointer */
end_comment

begin_define
define|#
directive|define
name|PACC
value|0x17
end_define

begin_comment
comment|/* purge all code cache */
end_comment

begin_define
define|#
directive|define
name|P1DC
value|0x18
end_define

begin_comment
comment|/* purge one data cache */
end_comment

begin_define
define|#
directive|define
name|PADC
value|0x19
end_define

begin_comment
comment|/* purge all data cache */
end_comment

begin_define
define|#
directive|define
name|HISR
value|0x1a
end_define

begin_comment
comment|/* hardware interrupt summery register */
end_comment

begin_define
define|#
directive|define
name|DCR
value|0x1b
end_define

begin_comment
comment|/* diagnostic control register */
end_comment

begin_define
define|#
directive|define
name|PDCS
value|0x1c
end_define

begin_comment
comment|/* purge data cache slot */
end_comment

end_unit

