begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2005 Max Okumoto.  *	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|proc_h_458845848
end_ifndef

begin_define
define|#
directive|define
name|proc_h_458845848
end_define

begin_comment
comment|/**  * Information used to create a new process.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ProcStuff
block|{
name|int
name|in
decl_stmt|;
comment|/* stdin for new process */
name|int
name|out
decl_stmt|;
comment|/* stdout for new process */
name|int
name|err
decl_stmt|;
comment|/* stderr for new process */
name|int
name|merge_errors
decl_stmt|;
comment|/* true if stderr is redirected to stdin */
name|int
name|pgroup
decl_stmt|;
comment|/* true if new process a process leader */
name|int
name|searchpath
decl_stmt|;
comment|/* true if binary should be found via $PATH */
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|int
name|argv_free
decl_stmt|;
comment|/* release argv after use */
name|int
name|errCheck
decl_stmt|;
name|pid_t
name|child_pid
decl_stmt|;
block|}
name|ProcStuff
typedef|;
end_typedef

begin_decl_stmt
name|void
name|Proc_Exec
argument_list|(
specifier|const
name|ProcStuff
operator|*
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* proc_h_458845848 */
end_comment

end_unit

