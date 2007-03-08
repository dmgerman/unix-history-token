begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|globals_h_1c1edb96
end_ifndef

begin_define
define|#
directive|define
name|globals_h_1c1edb96
end_define

begin_comment
comment|/*  * Global Variables  */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|"lst.h"
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
name|Path
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The list of target names specified on the command line.  * Used to resolve #if make(...) statements  */
end_comment

begin_decl_stmt
specifier|extern
name|Lst
name|create
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The list of directories to search when looking for targets */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Path
name|dirSearchPath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The list of directories to search when looking for includes */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Path
name|parseIncPath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The system include path. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Path
name|sysIncPath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|jobLimit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -j argument: maximum number of jobs */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|jobsRunning
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if jobs are running */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|compatMake
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if we are make compatible */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|ignoreErrors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if should ignore all errors */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|beSilent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if should print no commands */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|beVerbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if should print extra cruft */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|noExecute
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if should execute nothing */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|allPrecious
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if every target is precious */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|is_posix
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* .POSIX target seen */
end_comment

begin_comment
comment|/* True if should continue on unaffected portions of the graph  * when have an error in one portion */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|keepgoing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if targets should just be 'touched'if out of date. Set by the -t flag */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|touchFlag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if should capture the output of subshells by means of pipes.  * Otherwise it is routed to temporary files from which it is retrieved  * when the shell exits */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|usePipes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if we aren't supposed to really make anything, just see if the  * targets are out-of-date */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|queryFlag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of specific variables for which the environment should be  * searched before the global context */
end_comment

begin_decl_stmt
specifier|extern
name|Lst
name|envFirstVars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|GNode
modifier|*
name|DEFAULT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* .DEFAULT rule */
end_comment

begin_comment
comment|/* The time at the start of this whole process */
end_comment

begin_decl_stmt
specifier|extern
name|time_t
name|now
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* warning flags */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|warn_cmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* positive warning flags on command line */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|warn_nocmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* negative warning flags on command line */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|warn_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current warning flags */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* globals_h_1c1edb96 */
end_comment

end_unit

