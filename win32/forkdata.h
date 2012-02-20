begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*$Header: /p/tcsh/cvsroot/tcsh/win32/forkdata.h,v 1.4 2004/05/19 18:22:27 christos Exp $*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FORK_DATA_H
end_ifndef

begin_define
define|#
directive|define
name|FORK_DATA_H
end_define

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/*   * This structure is copied by fork() to the child process. It   * contains variables of national importance  *  * Thanks to Mark Tucker for the idea. tcsh now finally works on  * alphas.  * -amol  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_fork_data
block|{
name|unsigned
name|long
name|_forked
decl_stmt|;
name|void
modifier|*
name|_fork_stack_begin
decl_stmt|;
name|void
modifier|*
name|_fork_stack_end
decl_stmt|;
name|unsigned
name|long
name|_heap_size
decl_stmt|;
name|HANDLE
name|_hforkparent
decl_stmt|,
name|_hforkchild
decl_stmt|;
name|void
modifier|*
name|_heap_base
decl_stmt|;
name|void
modifier|*
name|_heap_top
decl_stmt|;
name|jmp_buf
name|_fork_context
decl_stmt|;
block|}
name|ForkData
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__forked
value|gForkData._forked
end_define

begin_define
define|#
directive|define
name|__fork_stack_begin
value|gForkData._fork_stack_begin
end_define

begin_define
define|#
directive|define
name|__fork_stack_end
value|gForkData._fork_stack_end
end_define

begin_define
define|#
directive|define
name|__hforkparent
value|gForkData._hforkparent
end_define

begin_define
define|#
directive|define
name|__hforkchild
value|gForkData._hforkchild
end_define

begin_define
define|#
directive|define
name|__fork_context
value|gForkData._fork_context
end_define

begin_define
define|#
directive|define
name|__heap_base
value|gForkData._heap_base
end_define

begin_define
define|#
directive|define
name|__heap_size
value|gForkData._heap_size
end_define

begin_define
define|#
directive|define
name|__heap_top
value|gForkData._heap_top
end_define

begin_decl_stmt
specifier|extern
name|ForkData
name|gForkData
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NTDBG
end_ifdef

begin_define
define|#
directive|define
name|FORK_TIMEOUT
value|INFINITE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FORK_TIMEOUT
value|(50000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!NTDBG */
end_comment

begin_endif
endif|#
directive|endif
endif|FORK_DATA_H
end_endif

end_unit

