begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)mtpr.h	6.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * VAX processor register numbers  */
end_comment

begin_define
define|#
directive|define
name|KSP
value|0x0
end_define

begin_comment
comment|/* kernel stack pointer */
end_comment

begin_define
define|#
directive|define
name|ESP
value|0x1
end_define

begin_comment
comment|/* exec stack pointer */
end_comment

begin_define
define|#
directive|define
name|SSP
value|0x2
end_define

begin_comment
comment|/* supervisor stack pointer */
end_comment

begin_define
define|#
directive|define
name|USP
value|0x3
end_define

begin_comment
comment|/* user stack pointer */
end_comment

begin_define
define|#
directive|define
name|ISP
value|0x4
end_define

begin_comment
comment|/* interrupt stack pointer */
end_comment

begin_define
define|#
directive|define
name|P0BR
value|0x8
end_define

begin_comment
comment|/* p0 base register */
end_comment

begin_define
define|#
directive|define
name|P0LR
value|0x9
end_define

begin_comment
comment|/* p0 length register */
end_comment

begin_define
define|#
directive|define
name|P1BR
value|0xa
end_define

begin_comment
comment|/* p1 base register */
end_comment

begin_define
define|#
directive|define
name|P1LR
value|0xb
end_define

begin_comment
comment|/* p1 length register */
end_comment

begin_define
define|#
directive|define
name|SBR
value|0xc
end_define

begin_comment
comment|/* system segment base register */
end_comment

begin_define
define|#
directive|define
name|SLR
value|0xd
end_define

begin_comment
comment|/* system segment length register */
end_comment

begin_define
define|#
directive|define
name|PCBB
value|0x10
end_define

begin_comment
comment|/* process control block base */
end_comment

begin_define
define|#
directive|define
name|SCBB
value|0x11
end_define

begin_comment
comment|/* system control block base */
end_comment

begin_define
define|#
directive|define
name|IPL
value|0x12
end_define

begin_comment
comment|/* interrupt priority level */
end_comment

begin_define
define|#
directive|define
name|ASTLVL
value|0x13
end_define

begin_comment
comment|/* async. system trap level */
end_comment

begin_define
define|#
directive|define
name|SIRR
value|0x14
end_define

begin_comment
comment|/* software interrupt request */
end_comment

begin_define
define|#
directive|define
name|SISR
value|0x15
end_define

begin_comment
comment|/* software interrupt summary */
end_comment

begin_define
define|#
directive|define
name|ICCS
value|0x18
end_define

begin_comment
comment|/* interval clock control */
end_comment

begin_define
define|#
directive|define
name|NICR
value|0x19
end_define

begin_comment
comment|/* next interval count */
end_comment

begin_define
define|#
directive|define
name|ICR
value|0x1a
end_define

begin_comment
comment|/* interval count */
end_comment

begin_define
define|#
directive|define
name|TODR
value|0x1b
end_define

begin_comment
comment|/* time of year (day) */
end_comment

begin_define
define|#
directive|define
name|RXCS
value|0x20
end_define

begin_comment
comment|/* console receiver control and status */
end_comment

begin_define
define|#
directive|define
name|RXDB
value|0x21
end_define

begin_comment
comment|/* console receiver data buffer */
end_comment

begin_define
define|#
directive|define
name|TXCS
value|0x22
end_define

begin_comment
comment|/* console transmitter control and status */
end_comment

begin_define
define|#
directive|define
name|TXDB
value|0x23
end_define

begin_comment
comment|/* console transmitter data buffer */
end_comment

begin_define
define|#
directive|define
name|MAPEN
value|0x38
end_define

begin_comment
comment|/* memory management enable */
end_comment

begin_define
define|#
directive|define
name|TBIA
value|0x39
end_define

begin_comment
comment|/* translation buffer invalidate all */
end_comment

begin_define
define|#
directive|define
name|TBIS
value|0x3a
end_define

begin_comment
comment|/* translation buffer invalidate single */
end_comment

begin_define
define|#
directive|define
name|PMR
value|0x3d
end_define

begin_comment
comment|/* performance monitor enable */
end_comment

begin_define
define|#
directive|define
name|SID
value|0x3e
end_define

begin_comment
comment|/* system identification */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAX780
argument_list|)
end_if

begin_define
define|#
directive|define
name|ACCS
value|0x28
end_define

begin_comment
comment|/* accelerator control and status */
end_comment

begin_define
define|#
directive|define
name|ACCR
value|0x29
end_define

begin_comment
comment|/* accelerator maintenance */
end_comment

begin_define
define|#
directive|define
name|WCSA
value|0x2c
end_define

begin_comment
comment|/* WCS address */
end_comment

begin_define
define|#
directive|define
name|WCSD
value|0x2d
end_define

begin_comment
comment|/* WCS data */
end_comment

begin_define
define|#
directive|define
name|SBIFS
value|0x30
end_define

begin_comment
comment|/* SBI fault and status */
end_comment

begin_define
define|#
directive|define
name|SBIS
value|0x31
end_define

begin_comment
comment|/* SBI silo */
end_comment

begin_define
define|#
directive|define
name|SBISC
value|0x32
end_define

begin_comment
comment|/* SBI silo comparator */
end_comment

begin_define
define|#
directive|define
name|SBIMT
value|0x33
end_define

begin_comment
comment|/* SBI maintenance */
end_comment

begin_define
define|#
directive|define
name|SBIER
value|0x34
end_define

begin_comment
comment|/* SBI error register */
end_comment

begin_define
define|#
directive|define
name|SBITA
value|0x35
end_define

begin_comment
comment|/* SBI timeout address */
end_comment

begin_define
define|#
directive|define
name|SBIQC
value|0x36
end_define

begin_comment
comment|/* SBI quadword clear */
end_comment

begin_define
define|#
directive|define
name|MBRK
value|0x3c
end_define

begin_comment
comment|/* micro-program breakpoint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAX750
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX730
argument_list|)
end_if

begin_define
define|#
directive|define
name|MCSR
value|0x17
end_define

begin_comment
comment|/* machine check status register */
end_comment

begin_define
define|#
directive|define
name|CSRS
value|0x1c
end_define

begin_comment
comment|/* console storage receive status register */
end_comment

begin_define
define|#
directive|define
name|CSRD
value|0x1d
end_define

begin_comment
comment|/* console storage receive data register */
end_comment

begin_define
define|#
directive|define
name|CSTS
value|0x1e
end_define

begin_comment
comment|/* console storage transmit status register */
end_comment

begin_define
define|#
directive|define
name|CSTD
value|0x1f
end_define

begin_comment
comment|/* console storage transmit data register */
end_comment

begin_define
define|#
directive|define
name|TBDR
value|0x24
end_define

begin_comment
comment|/* translation buffer disable register */
end_comment

begin_define
define|#
directive|define
name|CADR
value|0x25
end_define

begin_comment
comment|/* cache disable register */
end_comment

begin_define
define|#
directive|define
name|MCESR
value|0x26
end_define

begin_comment
comment|/* machine check error summary register */
end_comment

begin_define
define|#
directive|define
name|CAER
value|0x27
end_define

begin_comment
comment|/* cache error */
end_comment

begin_define
define|#
directive|define
name|IUR
value|0x37
end_define

begin_comment
comment|/* init unibus register */
end_comment

begin_define
define|#
directive|define
name|TB
value|0x3b
end_define

begin_comment
comment|/* translation buffer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

