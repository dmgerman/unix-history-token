begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: cdefs.h,v 1.12 2006/08/27 19:04:30 matt Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_CDEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_CDEFS_H_
end_define

begin_comment
comment|/*      MIPS Subprogram Interface Model */
end_comment

begin_define
define|#
directive|define
name|_MIPS_SIM_ABIX32
value|4
end_define

begin_comment
comment|/* 64 bit safe, ILP32 o32 model */
end_comment

begin_define
define|#
directive|define
name|_MIPS_SIM_ABI64
value|3
end_define

begin_define
define|#
directive|define
name|_MIPS_SIM_NABI32
value|2
end_define

begin_comment
comment|/* 64bit safe, ILP32 n32 model */
end_comment

begin_define
define|#
directive|define
name|_MIPS_SIM_ABI32
value|1
end_define

begin_define
define|#
directive|define
name|_MIPS_BSD_API_LP32
value|_MIPS_SIM_ABI32
end_define

begin_define
define|#
directive|define
name|_MIPS_BSD_API_LP32_64CLEAN
value|_MIPS_SIM_ABIX32
end_define

begin_define
define|#
directive|define
name|_MIPS_BSD_API_N32
value|_MIPS_SIM_NABI32
end_define

begin_define
define|#
directive|define
name|_MIPS_BSD_API_LP64
value|_MIPS_SIM_ABI64
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_define
define|#
directive|define
name|_MIPS_BSD_API
value|_MIPS_BSD_API_LP64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_MIPS_BSD_API
value|_MIPS_BSD_API_N32
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips_o64
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_MIPS_BSD_API
value|_MIPS_BSD_API_LP32_64CLEAN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_MIPS_BSD_API
value|_MIPS_BSD_API_LP32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MIPS_CDEFS_H_ */
end_comment

end_unit

