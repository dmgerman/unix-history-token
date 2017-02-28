begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)select.h	8.2 (Berkeley) 1/4/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SELINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SELINFO_H_
end_define

begin_include
include|#
directive|include
file|<sys/event.h>
end_include

begin_comment
comment|/* for struct klist */
end_comment

begin_struct_decl
struct_decl|struct
name|selfd
struct_decl|;
end_struct_decl

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|selfdlist
argument_list|,
name|selfd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Used to maintain information about processes that wish to be  * notified when I/O becomes possible.  */
end_comment

begin_struct
struct|struct
name|selinfo
block|{
name|struct
name|selfdlist
name|si_tdlist
decl_stmt|;
comment|/* List of sleeping threads. */
name|struct
name|knlist
name|si_note
decl_stmt|;
comment|/* kernel note list */
name|struct
name|mtx
modifier|*
name|si_mtx
decl_stmt|;
comment|/* Lock for tdlist. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SEL_WAITING
parameter_list|(
name|si
parameter_list|)
value|(!TAILQ_EMPTY(&(si)->si_tdlist))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|seldrain
parameter_list|(
name|struct
name|selinfo
modifier|*
name|sip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|selrecord
parameter_list|(
name|struct
name|thread
modifier|*
name|selector
parameter_list|,
name|struct
name|selinfo
modifier|*
name|sip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|selwakeup
parameter_list|(
name|struct
name|selinfo
modifier|*
name|sip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|selwakeuppri
parameter_list|(
name|struct
name|selinfo
modifier|*
name|sip
parameter_list|,
name|int
name|pri
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|seltdfini
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SELINFO_H_ */
end_comment

end_unit

