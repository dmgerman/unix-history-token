begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)extern.h	8.2 (Berkeley) 4/28/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EXTERN_H_
end_ifndef

begin_define
define|#
directive|define
name|_EXTERN_H_
end_define

begin_decl_stmt
specifier|extern
name|char
name|tbuf
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temp buffer for anybody. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|entries
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of people. */
end_comment

begin_decl_stmt
specifier|extern
name|DB
modifier|*
name|db
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Database. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|d_first
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sa_family_t
name|family
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|now
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|oflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pplan
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't show .plan/.project */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|invoker_root
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Invoked by root */
end_comment

begin_function_decl
name|void
name|enter_lastlog
parameter_list|(
name|PERSON
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PERSON
modifier|*
name|enter_person
parameter_list|(
name|struct
name|passwd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|enter_where
parameter_list|(
name|struct
name|utmp
modifier|*
parameter_list|,
name|PERSON
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PERSON
modifier|*
name|find_person
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hide
parameter_list|(
name|struct
name|passwd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lflag_print
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|match
parameter_list|(
name|struct
name|passwd
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netfinger
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PERSON
modifier|*
name|palloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|prphone
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sflag_print
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|show_text
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_EXTERN_H_ */
end_comment

end_unit

