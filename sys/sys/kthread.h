begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Peter Wemm<peter@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_KTHREAD_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_KTHREAD_H_
end_define

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_comment
comment|/*   * A kernel process descriptor; used to start "internal" daemons  *   * Note: global_procpp may be NULL for no global save area  */
end_comment

begin_struct
struct|struct
name|kproc_desc
block|{
name|char
modifier|*
name|arg0
decl_stmt|;
comment|/* arg 0 (for 'ps' listing) */
name|void
argument_list|(
argument|*func
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* "main" for kernel process */
name|struct
name|proc
modifier|*
modifier|*
name|global_procpp
decl_stmt|;
comment|/* ptr to proc ptr save area */
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|kproc_start
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kthread_create
name|__P
argument_list|(
operator|(
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
operator|,
expr|struct
name|proc
operator|*
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|__printflike
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kthread_exit
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|suspend_kproc
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|resume_kproc
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kproc_suspend_loop
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|shutdown_kproc
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

