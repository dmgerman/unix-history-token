begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /p/tcsh/cvsroot/tcsh/tc.h,v 3.8 2006/01/12 19:55:38 christos Exp $ */
end_comment

begin_comment
comment|/*  * tc.h: Tcsh includes  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_tc
end_ifndef

begin_define
define|#
directive|define
name|_h_tc
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_h_tc_const
end_ifndef

begin_comment
comment|/* Don't include it while we are making it. */
end_comment

begin_include
include|#
directive|include
file|"tc.const.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_tc_const */
end_comment

begin_include
include|#
directive|include
file|"tc.os.h"
end_include

begin_include
include|#
directive|include
file|"tc.sig.h"
end_include

begin_include
include|#
directive|include
file|"tc.decls.h"
end_include

begin_decl_stmt
specifier|extern
name|size_t
name|tlength
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FMT_PROMPT
value|0
end_define

begin_define
define|#
directive|define
name|FMT_WHO
value|1
end_define

begin_define
define|#
directive|define
name|FMT_HISTORY
value|2
end_define

begin_define
define|#
directive|define
name|FMT_SCHED
value|3
end_define

begin_struct
struct|struct
name|strbuf
block|{
name|char
modifier|*
name|s
decl_stmt|;
name|size_t
name|len
decl_stmt|;
comment|/* Valid characters */
name|size_t
name|size
decl_stmt|;
comment|/* Allocated characters */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Strbuf
block|{
name|Char
modifier|*
name|s
decl_stmt|;
name|size_t
name|len
decl_stmt|;
comment|/* Valid characters */
name|size_t
name|size
decl_stmt|;
comment|/* Allocated characters */
block|}
struct|;
end_struct

begin_comment
comment|/* We don't have explicit initializers for variables with static storage    duration, so these values should be equivalent to default initialization. */
end_comment

begin_define
define|#
directive|define
name|strbuf_INIT
value|{ NULL, 0, 0 }
end_define

begin_define
define|#
directive|define
name|Strbuf_INIT
value|{ NULL, 0, 0 }
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|strbuf
name|strbuf_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|Strbuf
name|Strbuf_init
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A string vector in progress */
end_comment

begin_struct
struct|struct
name|blk_buf
block|{
name|Char
modifier|*
modifier|*
name|vec
decl_stmt|;
name|size_t
name|len
decl_stmt|;
comment|/* Valid strings */
name|size_t
name|size
decl_stmt|;
comment|/* Allocated space for string pointers */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BLK_BUF_INIT
value|{ NULL, 0, 0 }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_tc */
end_comment

end_unit

