begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|cond_h_6e96ad7c
end_ifndef

begin_define
define|#
directive|define
name|cond_h_6e96ad7c
end_define

begin_comment
comment|/*  * Values returned by Cond_Eval.  */
end_comment

begin_define
define|#
directive|define
name|COND_PARSE
value|0
end_define

begin_comment
comment|/* Parse the next lines */
end_comment

begin_define
define|#
directive|define
name|COND_SKIP
value|1
end_define

begin_comment
comment|/* Skip the next lines */
end_comment

begin_define
define|#
directive|define
name|COND_INVALID
value|2
end_define

begin_comment
comment|/* Not a conditional statement */
end_comment

begin_enum
enum|enum
block|{
name|COND_IF
block|,
name|COND_IFDEF
block|,
name|COND_IFNDEF
block|,
name|COND_IFMAKE
block|,
name|COND_IFNMAKE
block|,
name|COND_ELSE
block|,
name|COND_ELIF
block|,
name|COND_ELIFDEF
block|,
name|COND_ELIFNDEF
block|,
name|COND_ELIFMAKE
block|,
name|COND_ELIFNMAKE
block|,
name|COND_ENDIF
block|, }
enum|;
end_enum

begin_function_decl
name|void
name|Cond_If
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Cond_Else
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Cond_Endif
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Cond_End
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|Boolean
name|skipLine
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* cond_h_6e96ad7c */
end_comment

end_unit

