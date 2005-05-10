begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)make.h	8.3 (Berkeley) 6/13/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|make_h_a91074b9
end_ifndef

begin_define
define|#
directive|define
name|make_h_a91074b9
end_define

begin_comment
comment|/*-  * make.h --  *	The global definitions for pmake  */
end_comment

begin_include
include|#
directive|include
file|"sprite.h"
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

begin_struct_decl
struct_decl|struct
name|Buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The OP_ constants are used when parsing a dependency line as a way of  * communicating to other parts of the program the way in which a target  * should be made. These constants are bitwise-OR'ed together and  * placed in the 'type' field of each node. Any node that has  * a 'type' field which satisfies the OP_NOP function was never never on  * the lefthand side of an operator, though it may have been on the  * righthand side...  */
end_comment

begin_define
define|#
directive|define
name|OP_DEPENDS
value|0x00000001
end_define

begin_comment
comment|/* Execution of commands depends on 				     * kids (:) */
end_comment

begin_define
define|#
directive|define
name|OP_FORCE
value|0x00000002
end_define

begin_comment
comment|/* Always execute commands (!) */
end_comment

begin_define
define|#
directive|define
name|OP_DOUBLEDEP
value|0x00000004
end_define

begin_comment
comment|/* Execution of commands depends on kids 				     * per line (::) */
end_comment

begin_define
define|#
directive|define
name|OP_OPMASK
value|(OP_DEPENDS|OP_FORCE|OP_DOUBLEDEP)
end_define

begin_define
define|#
directive|define
name|OP_OPTIONAL
value|0x00000008
end_define

begin_comment
comment|/* Don't care if the target doesn't 				     * exist and can't be created */
end_comment

begin_define
define|#
directive|define
name|OP_USE
value|0x00000010
end_define

begin_comment
comment|/* Use associated commands for parents */
end_comment

begin_define
define|#
directive|define
name|OP_EXEC
value|0x00000020
end_define

begin_comment
comment|/* Target is never out of date, but always 				     * execute commands anyway. Its time 				     * doesn't matter, so it has none...sort 				     * of */
end_comment

begin_define
define|#
directive|define
name|OP_IGNORE
value|0x00000040
end_define

begin_comment
comment|/* Ignore errors when creating the node */
end_comment

begin_define
define|#
directive|define
name|OP_PRECIOUS
value|0x00000080
end_define

begin_comment
comment|/* Don't remove the target when 				     * interrupted */
end_comment

begin_define
define|#
directive|define
name|OP_SILENT
value|0x00000100
end_define

begin_comment
comment|/* Don't echo commands when executed */
end_comment

begin_define
define|#
directive|define
name|OP_MAKE
value|0x00000200
end_define

begin_comment
comment|/* Target is a recurrsive make so its 				     * commands should always be executed when 				     * it is out of date, regardless of the 				     * state of the -n or -t flags */
end_comment

begin_define
define|#
directive|define
name|OP_JOIN
value|0x00000400
end_define

begin_comment
comment|/* Target is out-of-date only if any of its 				     * children was out-of-date */
end_comment

begin_define
define|#
directive|define
name|OP_INVISIBLE
value|0x00004000
end_define

begin_comment
comment|/* The node is invisible to its parents. 				     * I.e. it doesn't show up in the parents's 				     * local variables. */
end_comment

begin_define
define|#
directive|define
name|OP_NOTMAIN
value|0x00008000
end_define

begin_comment
comment|/* The node is exempt from normal 'main 				     * target' processing in parse.c */
end_comment

begin_define
define|#
directive|define
name|OP_PHONY
value|0x00010000
end_define

begin_comment
comment|/* Not a file target; run always */
end_comment

begin_comment
comment|/* Attributes applied by PMake */
end_comment

begin_define
define|#
directive|define
name|OP_TRANSFORM
value|0x80000000
end_define

begin_comment
comment|/* The node is a transformation rule */
end_comment

begin_define
define|#
directive|define
name|OP_MEMBER
value|0x40000000
end_define

begin_comment
comment|/* Target is a member of an archive */
end_comment

begin_define
define|#
directive|define
name|OP_LIB
value|0x20000000
end_define

begin_comment
comment|/* Target is a library */
end_comment

begin_define
define|#
directive|define
name|OP_ARCHV
value|0x10000000
end_define

begin_comment
comment|/* Target is an archive construct */
end_comment

begin_define
define|#
directive|define
name|OP_HAS_COMMANDS
value|0x08000000
end_define

begin_comment
comment|/* Target has all the commands it should. 				     * Used when parsing to catch multiple 				     * commands for a target */
end_comment

begin_define
define|#
directive|define
name|OP_SAVE_CMDS
value|0x04000000
end_define

begin_comment
comment|/* Saving commands on .END (Compat) */
end_comment

begin_define
define|#
directive|define
name|OP_DEPS_FOUND
value|0x02000000
end_define

begin_comment
comment|/* Already processed by Suff_FindDeps */
end_comment

begin_comment
comment|/*  * OP_NOP will return TRUE if the node with the given type was not the  * object of a dependency operator  */
end_comment

begin_define
define|#
directive|define
name|OP_NOP
parameter_list|(
name|t
parameter_list|)
value|(((t)& OP_OPMASK) == 0x00000000)
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

begin_comment
comment|/*  * Warning flags  */
end_comment

begin_enum
enum|enum
block|{
name|WARN_DIRSYNTAX
init|=
literal|0x0001
block|,
comment|/* syntax errors in directives */
block|}
enum|;
end_enum

begin_function_decl
name|int
name|Make_TimeStamp
parameter_list|(
name|struct
name|GNode
modifier|*
parameter_list|,
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Make_OODate
parameter_list|(
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Make_HandleUse
parameter_list|(
name|struct
name|GNode
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
name|Make_Update
parameter_list|(
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Make_DoAllVar
parameter_list|(
name|struct
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Make_Run
parameter_list|(
name|struct
name|Lst
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Main_ParseArgLine
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Main_ParseWarn
parameter_list|(
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
comment|/* make_h_a91074b9 */
end_comment

end_unit

