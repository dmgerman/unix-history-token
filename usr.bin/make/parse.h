begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|parse_h_470eeb9a
end_ifndef

begin_define
define|#
directive|define
name|parse_h_470eeb9a
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_struct_decl
struct_decl|struct
name|GNode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|Lst
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Error levels for parsing. PARSE_FATAL means the process cannot continue  * once the makefile has been parsed. PARSE_WARNING means it can. Passed  * as the first argument to Parse_Error.  */
end_comment

begin_define
define|#
directive|define
name|PARSE_WARNING
value|2
end_define

begin_define
define|#
directive|define
name|PARSE_FATAL
value|1
end_define

begin_comment
comment|/*  * Definitions for the "local" variables. Used only for clarity.  */
end_comment

begin_define
define|#
directive|define
name|TARGET
value|"@"
end_define

begin_comment
comment|/* Target of dependency */
end_comment

begin_define
define|#
directive|define
name|OODATE
value|"?"
end_define

begin_comment
comment|/* All out-of-date sources */
end_comment

begin_define
define|#
directive|define
name|ALLSRC
value|">"
end_define

begin_comment
comment|/* All sources */
end_comment

begin_define
define|#
directive|define
name|IMPSRC
value|"<"
end_define

begin_comment
comment|/* Source implied by transformation */
end_comment

begin_define
define|#
directive|define
name|PREFIX
value|"*"
end_define

begin_comment
comment|/* Common prefix */
end_comment

begin_define
define|#
directive|define
name|ARCHIVE
value|"!"
end_define

begin_comment
comment|/* Archive in "archive(member)" syntax */
end_comment

begin_define
define|#
directive|define
name|MEMBER
value|"%"
end_define

begin_comment
comment|/* Member in "archive(member)" syntax */
end_comment

begin_define
define|#
directive|define
name|FTARGET
value|"@F"
end_define

begin_comment
comment|/* file part of TARGET */
end_comment

begin_define
define|#
directive|define
name|DTARGET
value|"@D"
end_define

begin_comment
comment|/* directory part of TARGET */
end_comment

begin_define
define|#
directive|define
name|FIMPSRC
value|"<F"
end_define

begin_comment
comment|/* file part of IMPSRC */
end_comment

begin_define
define|#
directive|define
name|DIMPSRC
value|"<D"
end_define

begin_comment
comment|/* directory part of IMPSRC */
end_comment

begin_define
define|#
directive|define
name|FPREFIX
value|"*F"
end_define

begin_comment
comment|/* file part of PREFIX */
end_comment

begin_define
define|#
directive|define
name|DPREFIX
value|"*D"
end_define

begin_comment
comment|/* directory part of PREFIX */
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
function_decl|;
end_function_decl

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
name|struct
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
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Parse_FromString
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
name|Parse_MainName
parameter_list|(
name|struct
name|Lst
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* parse_h_470eeb9a */
end_comment

end_unit

