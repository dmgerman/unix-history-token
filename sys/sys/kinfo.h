begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)kinfo.h	7.9 (Berkeley) 6/26/91  *	$Id: kinfo.h,v 1.2 1993/10/16 17:16:57 rgrimes Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_KINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_KINFO_H_
value|1
end_define

begin_comment
comment|/*  * Get kernel info  */
end_comment

begin_define
define|#
directive|define
name|ki_op
parameter_list|(
name|x
parameter_list|)
value|((x)&0x0000ffff)
end_define

begin_define
define|#
directive|define
name|ki_type
parameter_list|(
name|x
parameter_list|)
value|((x)&0x0000ff00)
end_define

begin_comment
comment|/*   * proc info   */
end_comment

begin_define
define|#
directive|define
name|KINFO_PROC
value|(0<<8)
end_define

begin_define
define|#
directive|define
name|KINFO_PROC_ALL
value|(KINFO_PROC|0)
end_define

begin_comment
comment|/* everything */
end_comment

begin_define
define|#
directive|define
name|KINFO_PROC_PID
value|(KINFO_PROC|1)
end_define

begin_comment
comment|/* by process id */
end_comment

begin_define
define|#
directive|define
name|KINFO_PROC_PGRP
value|(KINFO_PROC|2)
end_define

begin_comment
comment|/* by process group id */
end_comment

begin_define
define|#
directive|define
name|KINFO_PROC_SESSION
value|(KINFO_PROC|3)
end_define

begin_comment
comment|/* by session of pid */
end_comment

begin_define
define|#
directive|define
name|KINFO_PROC_TTY
value|(KINFO_PROC|4)
end_define

begin_comment
comment|/* by controlling tty */
end_comment

begin_define
define|#
directive|define
name|KINFO_PROC_UID
value|(KINFO_PROC|5)
end_define

begin_comment
comment|/* by effective uid */
end_comment

begin_define
define|#
directive|define
name|KINFO_PROC_RUID
value|(KINFO_PROC|6)
end_define

begin_comment
comment|/* by real uid */
end_comment

begin_comment
comment|/*  * Routing table  */
end_comment

begin_define
define|#
directive|define
name|ki_af
parameter_list|(
name|x
parameter_list|)
value|(((x)&0x00ff0000)>> 16)
end_define

begin_define
define|#
directive|define
name|KINFO_RT
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|KINFO_RT_DUMP
value|(KINFO_RT|1)
end_define

begin_comment
comment|/* dump; may limit to a.f. */
end_comment

begin_define
define|#
directive|define
name|KINFO_RT_FLAGS
value|(KINFO_RT|2)
end_define

begin_comment
comment|/* by flags, e.g. RESOLVING */
end_comment

begin_comment
comment|/*  * vnodes  */
end_comment

begin_define
define|#
directive|define
name|KINFO_VNODE
value|(2<<8)
end_define

begin_comment
comment|/*  * file structures  */
end_comment

begin_define
define|#
directive|define
name|KINFO_FILE
value|(3<<8)
end_define

begin_comment
comment|/*  * Locking and stats  */
end_comment

begin_struct
struct|struct
name|kinfo_lock
block|{
name|int
name|kl_lock
decl_stmt|;
name|int
name|kl_want
decl_stmt|;
name|int
name|kl_locked
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|kinfo_lock
name|kinfo_lock
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|getkerninfo
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_KINFO_H_ */
end_comment

end_unit

