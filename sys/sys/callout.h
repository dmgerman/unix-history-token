begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)callout.h	8.2 (Berkeley) 1/21/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CALLOUT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CALLOUT_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|callout_list
argument_list|,
name|callout
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|callout_tailq
argument_list|,
name|callout
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|callout
block|{
union|union
block|{
name|SLIST_ENTRY
argument_list|(
argument|callout
argument_list|)
name|sle
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|callout
argument_list|)
name|tqe
expr_stmt|;
block|}
name|c_links
union|;
name|int
name|c_time
decl_stmt|;
comment|/* ticks to the event */
name|void
modifier|*
name|c_arg
decl_stmt|;
comment|/* function argument */
name|void
argument_list|(
argument|*c_func
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* function to call */
name|int
name|c_flags
decl_stmt|;
comment|/* state of this entry */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CALLOUT_LOCAL_ALLOC
value|0x0001
end_define

begin_comment
comment|/* was allocated from callfree */
end_comment

begin_define
define|#
directive|define
name|CALLOUT_ACTIVE
value|0x0002
end_define

begin_comment
comment|/* callout is currently active */
end_comment

begin_define
define|#
directive|define
name|CALLOUT_PENDING
value|0x0004
end_define

begin_comment
comment|/* callout is waiting for timeout */
end_comment

begin_struct
struct|struct
name|callout_handle
block|{
name|struct
name|callout
modifier|*
name|callout
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|callout_list
name|callfree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|callout
modifier|*
name|callout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ncallout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|callout_tailq
modifier|*
name|callwheel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|callwheelsize
decl_stmt|,
name|callwheelbits
decl_stmt|,
name|callwheelmask
decl_stmt|,
name|softticks
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|callout_active
parameter_list|(
name|c
parameter_list|)
value|((c)->c_flags& CALLOUT_ACTIVE)
end_define

begin_define
define|#
directive|define
name|callout_deactivate
parameter_list|(
name|c
parameter_list|)
value|((c)->c_flags&= ~CALLOUT_ACTIVE)
end_define

begin_decl_stmt
name|void
name|callout_init
name|__P
argument_list|(
operator|(
expr|struct
name|callout
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|callout_pending
parameter_list|(
name|c
parameter_list|)
value|((c)->c_flags& CALLOUT_PENDING)
end_define

begin_decl_stmt
name|void
name|callout_reset
name|__P
argument_list|(
operator|(
expr|struct
name|callout
operator|*
operator|,
name|int
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|callout_stop
name|__P
argument_list|(
operator|(
expr|struct
name|callout
operator|*
operator|)
argument_list|)
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

begin_comment
comment|/* _SYS_CALLOUT_H_ */
end_comment

end_unit

