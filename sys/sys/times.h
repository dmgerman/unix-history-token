begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) UNIX System Laboratories, Inc.  All or some portions  * of this file are derived from material licensed to the  * University of California by American Telephone and Telegraph Co.  * or UNIX System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)times.h	7.6 (Berkeley) 3/9/91  *	$Id: times.h,v 1.3 1993/11/07 17:53:09 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TIMES_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TIMES_H_
value|1
end_define

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_CLOCK_T_
end_ifdef

begin_typedef
typedef|typedef
name|_CLOCK_T_
name|clock_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_CLOCK_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|tms
block|{
name|clock_t
name|tms_utime
decl_stmt|;
comment|/* User CPU time */
name|clock_t
name|tms_stime
decl_stmt|;
comment|/* System CPU time */
name|clock_t
name|tms_cutime
decl_stmt|;
comment|/* User CPU time of terminated child procs */
name|clock_t
name|tms_cstime
decl_stmt|;
comment|/* System CPU time of terminated child procs */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|clock_t
name|times
name|__P
argument_list|(
operator|(
expr|struct
name|tms
operator|*
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
comment|/* _SYS_TIMES_H_ */
end_comment

end_unit

