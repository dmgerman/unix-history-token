begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mtpr.h	2.1	1/5/80 */
end_comment

begin_comment
comment|/*  * VAX processor register numbers  */
end_comment

begin_define
define|#
directive|define
name|KSP
value|0
end_define

begin_comment
comment|/* kernel stack pointer */
end_comment

begin_define
define|#
directive|define
name|ESP
value|1
end_define

begin_comment
comment|/* exec stack pointer */
end_comment

begin_define
define|#
directive|define
name|SSP
value|2
end_define

begin_comment
comment|/* supervisor stack pointer */
end_comment

begin_define
define|#
directive|define
name|USP
value|3
end_define

begin_comment
comment|/* user stack pointer */
end_comment

begin_define
define|#
directive|define
name|ISP
value|4
end_define

begin_comment
comment|/* interrupt stack pointer */
end_comment

begin_define
define|#
directive|define
name|P0BR
value|8
end_define

begin_comment
comment|/* p0 base register */
end_comment

begin_define
define|#
directive|define
name|P0LR
value|9
end_define

begin_comment
comment|/* p0 length register */
end_comment

begin_define
define|#
directive|define
name|P1BR
value|10
end_define

begin_comment
comment|/* p1 base register */
end_comment

begin_define
define|#
directive|define
name|P1LR
value|11
end_define

begin_comment
comment|/* p1 length register */
end_comment

begin_define
define|#
directive|define
name|SBR
value|12
end_define

begin_comment
comment|/* system segment base register */
end_comment

begin_define
define|#
directive|define
name|SLR
value|13
end_define

begin_comment
comment|/* system segment length register */
end_comment

begin_define
define|#
directive|define
name|PCBB
value|16
end_define

begin_comment
comment|/* process control block base */
end_comment

begin_define
define|#
directive|define
name|SCBB
value|17
end_define

begin_comment
comment|/* system control block base */
end_comment

begin_define
define|#
directive|define
name|IPL
value|18
end_define

begin_comment
comment|/* interrupt priority level */
end_comment

begin_define
define|#
directive|define
name|ASTLVL
value|19
end_define

begin_comment
comment|/* async. system trap level */
end_comment

begin_define
define|#
directive|define
name|SIRR
value|20
end_define

begin_comment
comment|/* software interrupt request */
end_comment

begin_define
define|#
directive|define
name|SISR
value|21
end_define

begin_comment
comment|/* software interrupt summary */
end_comment

begin_define
define|#
directive|define
name|ICCS
value|24
end_define

begin_comment
comment|/* interval clock control */
end_comment

begin_define
define|#
directive|define
name|NICR
value|25
end_define

begin_comment
comment|/* next interval count */
end_comment

begin_define
define|#
directive|define
name|ICR
value|26
end_define

begin_comment
comment|/* interval count */
end_comment

begin_define
define|#
directive|define
name|TODR
value|27
end_define

begin_comment
comment|/* time of year (day) */
end_comment

begin_define
define|#
directive|define
name|RXCS
value|32
end_define

begin_comment
comment|/* console receiver control and status */
end_comment

begin_define
define|#
directive|define
name|RXDB
value|33
end_define

begin_comment
comment|/* console receiver data buffer */
end_comment

begin_define
define|#
directive|define
name|TXCS
value|34
end_define

begin_comment
comment|/* console transmitter control and status */
end_comment

begin_define
define|#
directive|define
name|TXDB
value|35
end_define

begin_comment
comment|/* console transmitter data buffer */
end_comment

begin_define
define|#
directive|define
name|MAPEN
value|56
end_define

begin_comment
comment|/* memory management enable */
end_comment

begin_define
define|#
directive|define
name|TBIA
value|57
end_define

begin_comment
comment|/* translation buffer invalidate all */
end_comment

begin_define
define|#
directive|define
name|TBIS
value|58
end_define

begin_comment
comment|/* translation buffer invalidate single */
end_comment

begin_define
define|#
directive|define
name|PMR
value|61
end_define

begin_comment
comment|/* performance monitor enable */
end_comment

begin_define
define|#
directive|define
name|SID
value|62
end_define

begin_comment
comment|/* system identification */
end_comment

begin_comment
comment|/*  * VAX-11/780 specific registers  */
end_comment

begin_define
define|#
directive|define
name|ACCS
value|40
end_define

begin_comment
comment|/* accelerator control and status */
end_comment

begin_define
define|#
directive|define
name|ACCR
value|41
end_define

begin_comment
comment|/* accelerator maintenance */
end_comment

begin_define
define|#
directive|define
name|WCSA
value|44
end_define

begin_comment
comment|/* WCS address */
end_comment

begin_define
define|#
directive|define
name|WCSD
value|45
end_define

begin_comment
comment|/* WCS data */
end_comment

begin_define
define|#
directive|define
name|SBIFS
value|48
end_define

begin_comment
comment|/* SBI fault and status */
end_comment

begin_define
define|#
directive|define
name|SBIS
value|49
end_define

begin_comment
comment|/* SBI silo */
end_comment

begin_define
define|#
directive|define
name|SBISC
value|50
end_define

begin_comment
comment|/* SBI silo comparator */
end_comment

begin_define
define|#
directive|define
name|SBIMT
value|51
end_define

begin_comment
comment|/* SBI maintenance */
end_comment

begin_define
define|#
directive|define
name|SBIER
value|52
end_define

begin_comment
comment|/* SBI error register */
end_comment

begin_define
define|#
directive|define
name|SBITA
value|53
end_define

begin_comment
comment|/* SBI timeout address */
end_comment

begin_define
define|#
directive|define
name|SBIQC
value|54
end_define

begin_comment
comment|/* SBI quadword clear */
end_comment

begin_define
define|#
directive|define
name|MBRK
value|60
end_define

begin_comment
comment|/* micro-program breakpoint */
end_comment

end_unit

