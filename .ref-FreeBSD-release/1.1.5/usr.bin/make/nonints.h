begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nonints.h	5.6 (Berkeley) 4/18/91  */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|brk_string
argument_list|()
decl_stmt|,
modifier|*
name|emalloc
argument_list|()
decl_stmt|,
modifier|*
name|str_concat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ReturnStatus
name|Arch_ParseArchive
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Arch_Touch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Arch_TouchLib
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Arch_MTime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Arch_MemMTime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Arch_FindLib
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Arch_LibOODate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Arch_Init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Compat_Run
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Dir_Init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Dir_HasWildcards
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Dir_Expand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Dir_FindFile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Dir_MTime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Dir_AddDir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ClientData
name|Dir_CopyDir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Dir_MakeFlags
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Dir_Destroy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Dir_ClearPath
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Dir_Concat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Make_TimeStamp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Make_OODate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Make_HandleUse
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Make_Update
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Make_DoAllVar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Make_Run
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_Touch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Job_CheckCommands
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_CatchChildren
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_CatchOutput
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_Make
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_Init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Job_Full
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Job_Empty
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ReturnStatus
name|Job_ParseShell
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Job_End
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_Wait
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Job_AbortAll
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Main_ParseArgLine
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Fatal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Punt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DieHorribly
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Finish
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Parse_Error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Parse_IsVar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Parse_DoVar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Parse_AddIncludeDir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Parse_File
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Lst
name|Parse_MainName
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_ClearSuffixes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Suff_IsTransform
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|GNode
modifier|*
name|Suff_AddTransform
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_AddSuffix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Suff_EndTransform
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Lst
name|Suff_GetPath
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_DoPaths
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_AddInclude
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_AddLib
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_FindDeps
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_SetNull
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Suff_Init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Targ_Init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|GNode
modifier|*
name|Targ_NewGN
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|GNode
modifier|*
name|Targ_FindNode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Lst
name|Targ_FindList
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Targ_Ignore
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Targ_Silent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Targ_Precious
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Targ_SetMain
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Targ_PrintCmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Targ_FmtTime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Targ_PrintType
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Str_Concat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Str_Match
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_Delete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_Set
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_Append
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Var_Exists
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Var_Value
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Var_Parse
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Var_Subst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Var_GetTail
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Var_GetHead
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Var_Init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Str_FindSubstring
parameter_list|()
function_decl|;
end_function_decl

end_unit

