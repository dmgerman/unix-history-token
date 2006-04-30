begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|str_h_44db59e6
end_ifndef

begin_define
define|#
directive|define
name|str_h_44db59e6
end_define

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_struct_decl
struct_decl|struct
name|Buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * An array of c-strings.  The pointers stored in argv, point to  * strings stored in buffer.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ArgArray
block|{
name|int
name|size
decl_stmt|;
comment|/* size of argv array */
name|int
name|argc
decl_stmt|;
comment|/* strings referenced in argv */
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/* array of string pointers */
name|size_t
name|len
decl_stmt|;
comment|/* size of buffer */
name|char
modifier|*
name|buffer
decl_stmt|;
comment|/* data buffer */
block|}
name|ArgArray
typedef|;
end_typedef

begin_comment
comment|/*  * These constants are all used by the Str_Concat function to decide how the  * final string should look. If STR_ADDSPACE is given, a space will be  * placed between the two strings. If STR_ADDSLASH is given, a '/' will  * be used instead of a space. If neither is given, no intervening characters  * will be placed between the two strings in the final output.  */
end_comment

begin_define
define|#
directive|define
name|STR_ADDSPACE
value|0x01
end_define

begin_comment
comment|/* add a space when Str_Concat'ing */
end_comment

begin_define
define|#
directive|define
name|STR_ADDSLASH
value|0x04
end_define

begin_comment
comment|/* add a slash when Str_Concat'ing */
end_comment

begin_function_decl
name|void
name|ArgArray_Init
parameter_list|(
name|ArgArray
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ArgArray_Done
parameter_list|(
name|ArgArray
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_concat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|brk_string
parameter_list|(
name|ArgArray
modifier|*
parameter_list|,
specifier|const
name|char
index|[]
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|MAKEFLAGS_quote
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MAKEFLAGS_break
parameter_list|(
name|ArgArray
modifier|*
parameter_list|,
specifier|const
name|char
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Str_Match
parameter_list|(
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

begin_function_decl
specifier|const
name|char
modifier|*
name|Str_SYSVMatch
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Str_SYSVSubst
parameter_list|(
name|struct
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* str_h_44db59e6 */
end_comment

end_unit

