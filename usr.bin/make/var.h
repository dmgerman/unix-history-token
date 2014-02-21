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

begin_struct_decl
struct_decl|struct
name|Buffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|GNode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|List
struct_decl|;
end_struct_decl

begin_comment
comment|/* Variables defined in a global context, e.g in the Makefile itself */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|GNode
modifier|*
name|VAR_GLOBAL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables defined on the command line */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|GNode
modifier|*
name|VAR_CMD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Value returned by Var_Parse when an error is encountered.  It actually  * points to an empty string, so naive callers needn't worry about it.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|var_Error
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * TRUE if environment should be searched for all variables before  * the global context  */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|checkEnvFirst
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do old-style variable substitution */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|oldVars
decl_stmt|;
end_decl_stmt

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
name|void
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
name|size_t
name|Var_Match
parameter_list|(
specifier|const
name|char
index|[]
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
name|void
name|Var_Print
parameter_list|(
name|struct
name|Lst
modifier|*
parameter_list|,
name|Boolean
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
name|Var_SetGlobal
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
name|struct
name|GNode
modifier|*
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|Buffer
modifier|*
name|Var_SubstOnly
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|Var_Value
parameter_list|(
specifier|const
name|char
index|[]
parameter_list|,
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* var_h_9cccafce */
end_comment

end_unit

