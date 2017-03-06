begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: nonints.h,v 1.74 2016/09/05 00:40:29 sevan Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)nonints.h	8.3 (Berkeley) 3/19/94  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)nonints.h	8.3 (Berkeley) 3/19/94  */
end_comment

begin_comment
comment|/* arch.c */
end_comment

begin_function_decl
name|ReturnStatus
name|Arch_ParseArchive
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|Lst
parameter_list|,
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Arch_Touch
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Arch_TouchLib
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|Arch_MTime
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|Arch_MemMTime
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Arch_FindLib
parameter_list|(
name|GNode
modifier|*
parameter_list|,
name|Lst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Arch_LibOODate
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Arch_Init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Arch_End
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Arch_IsLib
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* compat.c */
end_comment

begin_function_decl
name|int
name|CompatRunCommand
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Compat_Run
parameter_list|(
name|Lst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Compat_Make
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cond.c */
end_comment

begin_struct_decl
struct_decl|struct
name|If
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|Cond_EvalExpression
parameter_list|(
specifier|const
name|struct
name|If
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|Boolean
modifier|*
parameter_list|,
name|int
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Cond_Eval
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Cond_restore_depth
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|Cond_save_depth
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* for.c */
end_comment

begin_function_decl
name|int
name|For_Eval
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|For_Accum
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|For_Run
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* job.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WAIT_T
end_ifdef

begin_function_decl
name|void
name|JobReapChild
parameter_list|(
name|pid_t
parameter_list|,
name|WAIT_T
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* main.c */
end_comment

begin_function_decl
name|void
name|Main_ParseArgLine
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MakeMode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Cmd_Exec
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|MAKE_ATTR_PRINTFLIKE
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|Fatal
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|MAKE_ATTR_PRINTFLIKE
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
name|MAKE_ATTR_DEAD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Punt
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|MAKE_ATTR_PRINTFLIKE
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
name|MAKE_ATTR_DEAD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DieHorribly
argument_list|(
name|void
argument_list|)
name|MAKE_ATTR_DEAD
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|PrintAddr
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|Finish
argument_list|(
name|int
argument_list|)
name|MAKE_ATTR_DEAD
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|eunlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|execError
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
name|char
modifier|*
name|getTmpdir
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|s2Boolean
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|getBoolean
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cached_realpath
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* parse.c */
end_comment

begin_function_decl
name|void
name|Parse_Error
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|MAKE_ATTR_PRINTFLIKE
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
name|Boolean
name|Parse_AnyExport
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Parse_IsVar
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Parse_DoVar
parameter_list|(
name|char
modifier|*
parameter_list|,
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Parse_AddIncludeDir
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Parse_File
parameter_list|(
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
name|Parse_Init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Parse_End
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Parse_SetInput
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Lst
name|Parse_MainName
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* str.c */
end_comment

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
name|char
modifier|*
modifier|*
name|brk_string
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|Boolean
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Str_FindSubstring
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
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Str_SYSVSubst
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* suff.c */
end_comment

begin_function_decl
name|void
name|Suff_ClearSuffixes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Suff_IsTransform
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GNode
modifier|*
name|Suff_AddTransform
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Suff_EndTransform
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_AddSuffix
parameter_list|(
name|char
modifier|*
parameter_list|,
name|GNode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Lst
name|Suff_GetPath
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_DoPaths
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_AddInclude
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_AddLib
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_FindDeps
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Lst
name|Suff_FindPath
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_SetNull
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_Init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_End
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_PrintAll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* targ.c */
end_comment

begin_function_decl
name|void
name|Targ_Init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Targ_End
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Lst
name|Targ_List
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GNode
modifier|*
name|Targ_NewGN
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GNode
modifier|*
name|Targ_FindNode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Lst
name|Targ_FindList
parameter_list|(
name|Lst
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Targ_Ignore
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Targ_Silent
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Targ_Precious
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Targ_SetMain
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Targ_PrintCmd
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Targ_PrintNode
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Targ_FmtTime
parameter_list|(
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Targ_PrintType
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Targ_PrintGraph
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Targ_Propagate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Targ_Propagate_Wait
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* var.c */
end_comment

begin_function_decl
name|void
name|Var_Delete
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|GNode
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
name|GNode
modifier|*
parameter_list|,
name|int
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
name|GNode
modifier|*
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
name|GNode
modifier|*
parameter_list|,
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
name|GNode
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
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
name|GNode
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Var_GetTail
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Var_GetHead
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_Init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_End
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_Dump
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_ExportVars
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_Export
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_UnExport
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* util.c */
end_comment

begin_expr_stmt
name|void
argument_list|(
operator|*
name|bmake_signal
argument_list|(
name|int
argument_list|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

