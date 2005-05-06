begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Juli Mallett.  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|var_h_9cccafce
end_ifndef

begin_define
define|#
directive|define
name|var_h_9cccafce
end_define

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_struct_decl
struct_decl|struct
name|GNode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|Buffer
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|Var
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* the variable's name */
name|struct
name|Buffer
modifier|*
name|val
decl_stmt|;
comment|/* its value */
name|int
name|flags
decl_stmt|;
comment|/* miscellaneous status flags */
define|#
directive|define
name|VAR_IN_USE
value|1
comment|/* Variable's value currently being used. 				 * Used to avoid recursion */
define|#
directive|define
name|VAR_JUNK
value|4
comment|/* Variable is a junk variable that 				 * should be destroyed when done with 				 * it. Used by Var_Parse for undefined, 				 * modified variables */
define|#
directive|define
name|VAR_TO_ENV
value|8
comment|/* Place variable in environment */
block|}
name|Var
typedef|;
end_typedef

begin_comment
comment|/* Var*Pattern flags */
end_comment

begin_define
define|#
directive|define
name|VAR_SUB_GLOBAL
value|0x01
end_define

begin_comment
comment|/* Apply substitution globally */
end_comment

begin_define
define|#
directive|define
name|VAR_SUB_ONE
value|0x02
end_define

begin_comment
comment|/* Apply substitution to one word */
end_comment

begin_define
define|#
directive|define
name|VAR_SUB_MATCHED
value|0x04
end_define

begin_comment
comment|/* There was a match */
end_comment

begin_define
define|#
directive|define
name|VAR_MATCH_START
value|0x08
end_define

begin_comment
comment|/* Match at start of word */
end_comment

begin_define
define|#
directive|define
name|VAR_MATCH_END
value|0x10
end_define

begin_comment
comment|/* Match at end of word */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|Buffer
modifier|*
name|lhs
decl_stmt|;
comment|/* String to match */
name|struct
name|Buffer
modifier|*
name|rhs
decl_stmt|;
comment|/* Replacement string (w/&'s removed) */
name|regex_t
name|re
decl_stmt|;
name|int
name|nsub
decl_stmt|;
name|regmatch_t
modifier|*
name|matches
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
name|VarPattern
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Boolean
name|VarModifyProc
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|Boolean
parameter_list|,
name|struct
name|Buffer
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * var.c  */
end_comment

begin_function_decl
name|void
name|VarREError
parameter_list|(
name|int
parameter_list|,
name|regex_t
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
name|Var_Append
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_Delete
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_Dump
parameter_list|(
specifier|const
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Var_Exists
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Var_GetHead
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Var_GetTail
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_Init
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Var_Parse
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|GNode
modifier|*
parameter_list|,
name|Boolean
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|Boolean
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Var_Quote
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_Set
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_SetEnv
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|Buffer
modifier|*
name|Var_Subst
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|GNode
modifier|*
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Var_Value
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|GNode
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * var_modify.c  */
end_comment

begin_decl_stmt
name|VarModifyProc
name|VarHead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VarModifyProc
name|VarMatch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VarModifyProc
name|VarNoMatch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VarModifyProc
name|VarRESubstitute
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VarModifyProc
name|VarRoot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VarModifyProc
name|VarSubstitute
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VarModifyProc
name|VarSuffix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VarModifyProc
name|VarTail
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVVARSUB
end_ifdef

begin_decl_stmt
name|VarModifyProc
name|VarSYSVMatch
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
comment|/* var_h_9cccafce */
end_comment

end_unit

