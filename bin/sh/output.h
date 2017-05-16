begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)output.h	8.2 (Berkeley) 5/4/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OUTPUT_INCL
end_ifndef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_struct
struct|struct
name|output
block|{
name|char
modifier|*
name|nextc
decl_stmt|;
name|char
modifier|*
name|bufend
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|bufsize
decl_stmt|;
name|short
name|fd
decl_stmt|;
name|short
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|output
name|output
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* to fd 1 */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|output
name|errout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* to fd 2 */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|output
name|memout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|output
modifier|*
name|out1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*&memout if backquote, otherwise&output */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|output
modifier|*
name|out2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*&memout if backquote with 2>&1, otherwise&errout */
end_comment

begin_function_decl
name|void
name|outcslow
parameter_list|(
name|int
parameter_list|,
name|struct
name|output
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|out1str
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|out1qstr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|out2str
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|out2qstr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outstr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|output
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outqstr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|output
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outbin
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|output
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emptyoutbuf
parameter_list|(
name|struct
name|output
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flushall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flushout
parameter_list|(
name|struct
name|output
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freestdout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|outiserror
parameter_list|(
name|struct
name|output
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outclearerror
parameter_list|(
name|struct
name|output
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|outfmt
parameter_list|(
name|struct
name|output
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|out1fmt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|out2fmt_flush
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|fmtstr
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|doformat
parameter_list|(
name|struct
name|output
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|xwrite
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|outc
parameter_list|(
name|c
parameter_list|,
name|file
parameter_list|)
value|((file)->nextc == (file)->bufend ? (emptyoutbuf(file), *(file)->nextc++ = (c)) : (*(file)->nextc++ = (c)))
end_define

begin_define
define|#
directive|define
name|out1c
parameter_list|(
name|c
parameter_list|)
value|outc(c, out1);
end_define

begin_define
define|#
directive|define
name|out2c
parameter_list|(
name|c
parameter_list|)
value|outcslow(c, out2);
end_define

begin_define
define|#
directive|define
name|OUTPUT_INCL
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

