begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: intrcnt.h,v 1.17 1998/11/19 01:48:04 ross Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_define
define|#
directive|define
name|INTRCNT_CLOCK
value|0
end_define

begin_define
define|#
directive|define
name|INTRCNT_ISA_IRQ
value|(INTRCNT_CLOCK + 1)
end_define

begin_define
define|#
directive|define
name|INTRCNT_ISA_IRQ_LEN
value|16
end_define

begin_define
define|#
directive|define
name|INTRCNT_OTHER_BASE
value|(INTRCNT_ISA_IRQ + INTRCNT_ISA_IRQ_LEN)
end_define

begin_define
define|#
directive|define
name|INTRCNT_OTHER_LEN
value|48
end_define

begin_define
define|#
directive|define
name|INTRCNT_COUNT
value|(INTRCNT_OTHER_BASE + INTRCNT_OTHER_LEN)
end_define

begin_define
define|#
directive|define
name|INTRCNT_A12_IRQ
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_DEC_1000A_IRQ
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_DEC_1000_IRQ
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_DEC_2100_A500_IRQ
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_DEC_550_IRQ
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_EB164_IRQ
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_EB64PLUS_IRQ
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_EB66_IRQ
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_IOASIC
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_KN15
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_KN16
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_KN20AA_IRQ
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_KN300_IRQ
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_KN8AE_IRQ
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_TCDS
value|INTRCNT_OTHER_BASE
end_define

begin_define
define|#
directive|define
name|INTRCNT_A12_IRQ_LEN
value|10
end_define

begin_define
define|#
directive|define
name|INTRCNT_DEC_1000A_IRQ_LEN
value|32
end_define

begin_define
define|#
directive|define
name|INTRCNT_DEC_1000_IRQ_LEN
value|16
end_define

begin_define
define|#
directive|define
name|INTRCNT_DEC_2100_A500_IRQ_LEN
value|16
end_define

begin_define
define|#
directive|define
name|INTRCNT_DEC_550_IRQ_LEN
value|48
end_define

begin_define
define|#
directive|define
name|INTRCNT_EB164_IRQ_LEN
value|24
end_define

begin_define
define|#
directive|define
name|INTRCNT_EB64PLUS_IRQ_LEN
value|32
end_define

begin_define
define|#
directive|define
name|INTRCNT_EB66_IRQ_LEN
value|32
end_define

begin_define
define|#
directive|define
name|INTRCNT_IOASIC_LEN
value|4
end_define

begin_define
define|#
directive|define
name|INTRCNT_ISA_IRQ_LEN
value|16
end_define

begin_define
define|#
directive|define
name|INTRCNT_KN15_LEN
value|9
end_define

begin_define
define|#
directive|define
name|INTRCNT_KN16_LEN
value|5
end_define

begin_define
define|#
directive|define
name|INTRCNT_KN20AA_IRQ_LEN
value|32
end_define

begin_define
define|#
directive|define
name|INTRCNT_KN300_LEN
value|19
end_define

begin_define
define|#
directive|define
name|INTRCNT_KN8AE_IRQ_LEN
value|2
end_define

begin_define
define|#
directive|define
name|INTRCNT_TCDS_LEN
value|2
end_define

begin_define
define|#
directive|define
name|INTRCNT_KN300_NCR810
value|INTRCNT_KN300_IRQ + 16
end_define

begin_define
define|#
directive|define
name|INTRCNT_KN300_I2C_CTRL
value|INTRCNT_KN300_IRQ + 17
end_define

begin_define
define|#
directive|define
name|INTRCNT_KN300_I2C_BUS
value|INTRCNT_KN300_IRQ + 18
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_decl_stmt
specifier|extern
specifier|volatile
name|long
name|intrcnt
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

