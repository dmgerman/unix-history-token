begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: psl.h,v 1.6 2003/06/16 20:00:58 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1995 Mark Brinicombe.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Mark Brinicombe  *	for the NetBSD Project.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RiscBSD kernel project  *  * psl.h  *  * spl prototypes.  * Eventually this will become a set of defines.  *  * Created      : 21/07/95  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PSL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PSL_H_
end_define

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_comment
comment|/*  * These are the different SPL states  *  * Each state has an interrupt mask associated with it which  * indicate which interrupts are allowed.  */
end_comment

begin_define
define|#
directive|define
name|_SPL_0
value|0
end_define

begin_define
define|#
directive|define
name|_SPL_SOFTCLOCK
value|1
end_define

begin_define
define|#
directive|define
name|_SPL_SOFTNET
value|2
end_define

begin_define
define|#
directive|define
name|_SPL_BIO
value|3
end_define

begin_define
define|#
directive|define
name|_SPL_NET
value|4
end_define

begin_define
define|#
directive|define
name|_SPL_SOFTSERIAL
value|5
end_define

begin_define
define|#
directive|define
name|_SPL_TTY
value|6
end_define

begin_define
define|#
directive|define
name|_SPL_VM
value|7
end_define

begin_define
define|#
directive|define
name|_SPL_AUDIO
value|8
end_define

begin_define
define|#
directive|define
name|_SPL_CLOCK
value|9
end_define

begin_define
define|#
directive|define
name|_SPL_STATCLOCK
value|10
end_define

begin_define
define|#
directive|define
name|_SPL_HIGH
value|11
end_define

begin_define
define|#
directive|define
name|_SPL_SERIAL
value|12
end_define

begin_define
define|#
directive|define
name|_SPL_LEVELS
value|13
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
name|int
name|current_spl_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|spl_masks
index|[
name|_SPL_LEVELS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|spl_smasks
index|[
name|_SPL_LEVELS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_PSL_H_ */
end_comment

begin_comment
comment|/* End of psl.h */
end_comment

end_unit

