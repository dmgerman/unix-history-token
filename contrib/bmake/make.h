begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: make.h,v 1.102 2016/12/07 15:00:46 christos Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)make.h	8.3 (Berkeley) 6/13/95  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)make.h	8.3 (Berkeley) 6/13/95  */
end_comment

begin_comment
comment|/*-  * make.h --  *	The global definitions for pmake  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MAKE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MAKE_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|FD_CLOEXEC
end_ifndef

begin_define
define|#
directive|define
name|FD_CLOEXEC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAKE_GNUC_PREREQ
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((__GNUC__ == (x)&& __GNUC_MINOR__>= (y)) ||			\ 	 (__GNUC__> (x)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(__GNUC__) */
end_comment

begin_define
define|#
directive|define
name|MAKE_GNUC_PREREQ
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__GNUC__) */
end_comment

begin_if
if|#
directive|if
name|MAKE_GNUC_PREREQ
argument_list|(
literal|2
operator|,
literal|7
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAKE_ATTR_UNUSED
value|__attribute__((__unused__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAKE_ATTR_UNUSED
end_define

begin_comment
comment|/* delete */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MAKE_GNUC_PREREQ
argument_list|(
literal|2
operator|,
literal|5
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAKE_ATTR_DEAD
value|__attribute__((__noreturn__))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MAKE_ATTR_DEAD
value|__volatile
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAKE_ATTR_DEAD
end_define

begin_comment
comment|/* delete */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MAKE_GNUC_PREREQ
argument_list|(
literal|2
operator|,
literal|7
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAKE_ATTR_PRINTFLIKE
parameter_list|(
name|fmtarg
parameter_list|,
name|firstvararg
parameter_list|)
define|\
value|__attribute__((__format__ (__printf__, fmtarg, firstvararg)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAKE_ATTR_PRINTFLIKE
parameter_list|(
name|fmtarg
parameter_list|,
name|firstvararg
parameter_list|)
end_define

begin_comment
comment|/* delete */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sprite.h"
end_include

begin_include
include|#
directive|include
file|"lst.h"
end_include

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_include
include|#
directive|include
file|"make-conf.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"make_malloc.h"
end_include

begin_comment
comment|/*  * some vendors don't have this --sjg  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|S_IFDIR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|S_ISDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|POSIX_SIGNALS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-  * The structure for an individual graph node. Each node has several  * pieces of data associated with it.  *	1) the name of the target it describes  *	2) the location of the target file in the file system.  *	3) the type of operator used to define its sources (qv. parse.c)  *	4) whether it is involved in this invocation of make  *	5) whether the target has been remade  *	6) whether any of its children has been remade  *	7) the number of its children that are, as yet, unmade  *	8) its modification time  *	9) the modification time of its youngest child (qv. make.c)  *	10) a list of nodes for which this is a source (parents)  *	11) a list of nodes on which this depends (children)  *	12) a list of nodes that depend on this, as gleaned from the  *	    transformation rules (iParents)  *	13) a list of ancestor nodes, which includes parents, iParents,  *	    and recursive parents of parents  *	14) a list of nodes of the same name created by the :: operator  *	15) a list of nodes that must be made (if they're made) before  *	    this node can be, but that do not enter into the datedness of  *	    this node.  *	16) a list of nodes that must be made (if they're made) before  *	    this node or any child of this node can be, but that do not  *	    enter into the datedness of this node.  *	17) a list of nodes that must be made (if they're made) after  *	    this node is, but that do not depend on this node, in the  *	    normal sense.  *	18) a Lst of ``local'' variables that are specific to this target  *	   and this target only (qv. var.c [$@ $< $?, etc.])  *	19) a Lst of strings that are commands to be given to a shell  *	   to create this target.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|GNode
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The target's name */
name|char
modifier|*
name|uname
decl_stmt|;
comment|/* The unexpanded name of a .USE node */
name|char
modifier|*
name|path
decl_stmt|;
comment|/* The full pathname of the file */
name|int
name|type
decl_stmt|;
comment|/* Its type (see the OP flags, below) */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|REMAKE
value|0x1
comment|/* this target needs to be (re)made */
define|#
directive|define
name|CHILDMADE
value|0x2
comment|/* children of this target were made */
define|#
directive|define
name|FORCE
value|0x4
comment|/* children don't exist, and we pretend made */
define|#
directive|define
name|DONE_WAIT
value|0x8
comment|/* Set by Make_ProcessWait() */
define|#
directive|define
name|DONE_ORDER
value|0x10
comment|/* Build requested by .ORDER processing */
define|#
directive|define
name|FROM_DEPEND
value|0x20
comment|/* Node created from .depend */
define|#
directive|define
name|DONE_ALLSRC
value|0x40
comment|/* We do it once only */
define|#
directive|define
name|CYCLE
value|0x1000
comment|/* Used by MakePrintStatus */
define|#
directive|define
name|DONECYCLE
value|0x2000
comment|/* Used by MakePrintStatus */
define|#
directive|define
name|INTERNAL
value|0x4000
comment|/* Internal use only */
enum|enum
name|enum_made
block|{
name|UNMADE
block|,
name|DEFERRED
block|,
name|REQUESTED
block|,
name|BEINGMADE
block|,
name|MADE
block|,
name|UPTODATE
block|,
name|ERROR
block|,
name|ABORTED
block|}
name|made
enum|;
comment|/* Set to reflect the state of processing 				 * on this node: 				 *  UNMADE - Not examined yet 				 *  DEFERRED - Examined once (building child) 				 *  REQUESTED - on toBeMade list 				 *  BEINGMADE - Target is already being made. 				 *  	Indicates a cycle in the graph. 				 *  MADE - Was out-of-date and has been made 				 *  UPTODATE - Was already up-to-date 				 *  ERROR - An error occurred while it was being 				 *  	made (used only in compat mode) 				 *  ABORTED - The target was aborted due to 				 *  	an error making an inferior (compat). 				 */
name|int
name|unmade
decl_stmt|;
comment|/* The number of unmade children */
name|time_t
name|mtime
decl_stmt|;
comment|/* Its modification time */
name|struct
name|GNode
modifier|*
name|cmgn
decl_stmt|;
comment|/* The youngest child */
name|Lst
name|iParents
decl_stmt|;
comment|/* Links to parents for which this is an 				 * implied source, if any */
name|Lst
name|cohorts
decl_stmt|;
comment|/* Other nodes for the :: operator */
name|Lst
name|parents
decl_stmt|;
comment|/* Nodes that depend on this one */
name|Lst
name|children
decl_stmt|;
comment|/* Nodes on which this one depends */
name|Lst
name|order_pred
decl_stmt|;
comment|/* .ORDER nodes we need made */
name|Lst
name|order_succ
decl_stmt|;
comment|/* .ORDER nodes who need us */
name|char
name|cohort_num
index|[
literal|8
index|]
decl_stmt|;
comment|/* #n for this cohort */
name|int
name|unmade_cohorts
decl_stmt|;
comment|/* # of unmade instances on the 				      cohorts list */
name|struct
name|GNode
modifier|*
name|centurion
decl_stmt|;
comment|/* Pointer to the first instance of a :: 				   node; only set when on a cohorts list */
name|unsigned
name|int
name|checked
decl_stmt|;
comment|/* Last time we tried to makle this node */
name|Hash_Table
name|context
decl_stmt|;
comment|/* The local variables */
name|Lst
name|commands
decl_stmt|;
comment|/* Creation commands */
name|struct
name|_Suff
modifier|*
name|suffix
decl_stmt|;
comment|/* Suffix for the node (determined by 				 * Suff_FindDeps and opaque to everyone 				 * but the Suff module) */
specifier|const
name|char
modifier|*
name|fname
decl_stmt|;
comment|/* filename where the GNode got defined */
name|int
name|lineno
decl_stmt|;
comment|/* line number where the GNode got defined */
block|}
name|GNode
typedef|;
end_typedef

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
comment|/* Target is a recursive make so its 				     * commands should always be executed when 				     * it is out of date, regardless of the 				     * state of the -n or -t flags */
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
name|OP_MADE
value|0x00000800
end_define

begin_comment
comment|/* Assume the children of the node have 				     * been already made */
end_comment

begin_define
define|#
directive|define
name|OP_SPECIAL
value|0x00001000
end_define

begin_comment
comment|/* Special .BEGIN, .END, .INTERRUPT */
end_comment

begin_define
define|#
directive|define
name|OP_USEBEFORE
value|0x00002000
end_define

begin_comment
comment|/* Like .USE, only prepend commands */
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

begin_define
define|#
directive|define
name|OP_NOPATH
value|0x00020000
end_define

begin_comment
comment|/* Don't search for file in the path */
end_comment

begin_define
define|#
directive|define
name|OP_WAIT
value|0x00040000
end_define

begin_comment
comment|/* .WAIT phony node */
end_comment

begin_define
define|#
directive|define
name|OP_NOMETA
value|0x00080000
end_define

begin_comment
comment|/* .NOMETA do not create a .meta file */
end_comment

begin_define
define|#
directive|define
name|OP_META
value|0x00100000
end_define

begin_comment
comment|/* .META we _do_ want a .meta file */
end_comment

begin_define
define|#
directive|define
name|OP_NOMETA_CMP
value|0x00200000
end_define

begin_comment
comment|/* Do not compare commands in .meta file */
end_comment

begin_define
define|#
directive|define
name|OP_SUBMAKE
value|0x00400000
end_define

begin_comment
comment|/* Possibly a submake node */
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

begin_define
define|#
directive|define
name|OP_MARK
value|0x01000000
end_define

begin_comment
comment|/* Node found while expanding .ALLSRC */
end_comment

begin_define
define|#
directive|define
name|NoExecute
parameter_list|(
name|gn
parameter_list|)
value|((gn->type& OP_MAKE) ? noRecursiveExecute : noExecute)
end_define

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

begin_define
define|#
directive|define
name|OP_NOTARGET
value|(OP_NOTMAIN|OP_USE|OP_EXEC|OP_TRANSFORM)
end_define

begin_comment
comment|/*  * The TARG_ constants are used when calling the Targ_FindNode and  * Targ_FindList functions in targ.c. They simply tell the functions what to  * do if the desired node(s) is (are) not found. If the TARG_CREATE constant  * is given, a new, empty node will be created for the target, placed in the  * table of all targets and its address returned. If TARG_NOCREATE is given,  * a NULL pointer will be returned.  */
end_comment

begin_define
define|#
directive|define
name|TARG_NOCREATE
value|0x00
end_define

begin_comment
comment|/* don't create it */
end_comment

begin_define
define|#
directive|define
name|TARG_CREATE
value|0x01
end_define

begin_comment
comment|/* create node if not found */
end_comment

begin_define
define|#
directive|define
name|TARG_NOHASH
value|0x02
end_define

begin_comment
comment|/* don't look in/add to hash table */
end_comment

begin_comment
comment|/*  * These constants are all used by the Str_Concat function to decide how the  * final string should look. If STR_ADDSPACE is given, a space will be  * placed between the two strings. If STR_ADDSLASH is given, a '/' will  * be used instead of a space. If neither is given, no intervening characters  * will be placed between the two strings in the final output. If the  * STR_DOFREE bit is set, the two input strings will be freed before  * Str_Concat returns.  */
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
value|0x02
end_define

begin_comment
comment|/* add a slash when Str_Concat'ing */
end_comment

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
comment|/*  * Global Variables  */
end_comment

begin_decl_stmt
specifier|extern
name|Lst
name|create
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The list of target names specified on the 				 * command line. used to resolve #if 				 * make(...) statements */
end_comment

begin_decl_stmt
specifier|extern
name|Lst
name|dirSearchPath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The list of directories to search when 				 * looking for targets */
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
name|noExecute
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if should execute nothing */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|noRecursiveExecute
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
name|deleteOnError
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if failed targets should be deleted */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|keepgoing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if should continue on unaffected 				 * portions of the graph when have an error 				 * in one portion */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|touchFlag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if targets should just be 'touched' 				 * if out of date. Set by the -t flag */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|queryFlag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if we aren't supposed to really make 				 * anything, just see if the targets are out- 				 * of-date */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|doing_depend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if processing .depend */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|checkEnvFirst
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if environment should be searched for 				 * variables before the global context */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|jobServer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a jobServer already exists */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|parseWarnFatal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if makefile parsing warnings are 				 * treated as errors */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|varNoExportEnv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if we should not export variables 				 * set on the command line to the env. */
end_comment

begin_decl_stmt
specifier|extern
name|GNode
modifier|*
name|DEFAULT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* .DEFAULT rule */
end_comment

begin_decl_stmt
specifier|extern
name|GNode
modifier|*
name|VAR_INTERNAL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables defined internally by make 				 * which should not override those set by 				 * makefiles. 				 */
end_comment

begin_decl_stmt
specifier|extern
name|GNode
modifier|*
name|VAR_GLOBAL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables defined in a global context, e.g 				 * in the Makefile itself */
end_comment

begin_decl_stmt
specifier|extern
name|GNode
modifier|*
name|VAR_CMD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables defined on the command line */
end_comment

begin_decl_stmt
specifier|extern
name|GNode
modifier|*
name|VAR_FOR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Iteration variables */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|var_Error
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Value returned by Var_Parse when an error 				 * is encountered. It actually points to 				 * an empty string, so naive callers needn't 				 * worry about it. */
end_comment

begin_decl_stmt
specifier|extern
name|time_t
name|now
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The time at the start of this whole 				 * process */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|oldVars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do old-style variable substitution */
end_comment

begin_decl_stmt
specifier|extern
name|Lst
name|sysIncPath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The system include path. */
end_comment

begin_decl_stmt
specifier|extern
name|Lst
name|defIncPath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The default include path. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|curdir
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Startup directory */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The program name */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|makeDependfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* .depend */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|savedEnv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if we replaced environ this will be non-NULL */
end_comment

begin_comment
comment|/*  * We cannot vfork() in a child of vfork().  * Most systems do not enforce this but some do.  */
end_comment

begin_define
define|#
directive|define
name|vFork
parameter_list|()
value|((getpid() == myPid) ? vfork() : fork())
end_define

begin_decl_stmt
specifier|extern
name|pid_t
name|myPid
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAKEFLAGS
value|".MAKEFLAGS"
end_define

begin_define
define|#
directive|define
name|MAKEOVERRIDES
value|".MAKEOVERRIDES"
end_define

begin_define
define|#
directive|define
name|MAKE_JOB_PREFIX
value|".MAKE.JOB.PREFIX"
end_define

begin_comment
comment|/* prefix for job target output */
end_comment

begin_define
define|#
directive|define
name|MAKE_EXPORTED
value|".MAKE.EXPORTED"
end_define

begin_comment
comment|/* variables we export */
end_comment

begin_define
define|#
directive|define
name|MAKE_MAKEFILES
value|".MAKE.MAKEFILES"
end_define

begin_comment
comment|/* all the makefiles we read */
end_comment

begin_define
define|#
directive|define
name|MAKE_LEVEL
value|".MAKE.LEVEL"
end_define

begin_comment
comment|/* recursion level */
end_comment

begin_define
define|#
directive|define
name|MAKEFILE_PREFERENCE
value|".MAKE.MAKEFILE_PREFERENCE"
end_define

begin_define
define|#
directive|define
name|MAKE_DEPENDFILE
value|".MAKE.DEPENDFILE"
end_define

begin_comment
comment|/* .depend */
end_comment

begin_define
define|#
directive|define
name|MAKE_MODE
value|".MAKE.MODE"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAKE_LEVEL_ENV
end_ifndef

begin_define
define|#
directive|define
name|MAKE_LEVEL_ENV
value|"MAKELEVEL"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * debug control:  *	There is one bit per module.  It is up to the module what debug  *	information to print.  */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|debug_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output written here - default stdout */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEBUG_ARCH
value|0x00001
end_define

begin_define
define|#
directive|define
name|DEBUG_COND
value|0x00002
end_define

begin_define
define|#
directive|define
name|DEBUG_DIR
value|0x00004
end_define

begin_define
define|#
directive|define
name|DEBUG_GRAPH1
value|0x00008
end_define

begin_define
define|#
directive|define
name|DEBUG_GRAPH2
value|0x00010
end_define

begin_define
define|#
directive|define
name|DEBUG_JOB
value|0x00020
end_define

begin_define
define|#
directive|define
name|DEBUG_MAKE
value|0x00040
end_define

begin_define
define|#
directive|define
name|DEBUG_SUFF
value|0x00080
end_define

begin_define
define|#
directive|define
name|DEBUG_TARG
value|0x00100
end_define

begin_define
define|#
directive|define
name|DEBUG_VAR
value|0x00200
end_define

begin_define
define|#
directive|define
name|DEBUG_FOR
value|0x00400
end_define

begin_define
define|#
directive|define
name|DEBUG_SHELL
value|0x00800
end_define

begin_define
define|#
directive|define
name|DEBUG_ERROR
value|0x01000
end_define

begin_define
define|#
directive|define
name|DEBUG_LOUD
value|0x02000
end_define

begin_define
define|#
directive|define
name|DEBUG_META
value|0x04000
end_define

begin_define
define|#
directive|define
name|DEBUG_GRAPH3
value|0x10000
end_define

begin_define
define|#
directive|define
name|DEBUG_SCRIPT
value|0x20000
end_define

begin_define
define|#
directive|define
name|DEBUG_PARSE
value|0x40000
end_define

begin_define
define|#
directive|define
name|DEBUG_CWD
value|0x80000
end_define

begin_define
define|#
directive|define
name|CONCAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a##b
end_define

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|module
parameter_list|)
value|(debug& CONCAT(DEBUG_,module))
end_define

begin_include
include|#
directive|include
file|"nonints.h"
end_include

begin_function_decl
name|int
name|Make_TimeStamp
parameter_list|(
name|GNode
modifier|*
parameter_list|,
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Make_OODate
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Make_ExpandUse
parameter_list|(
name|Lst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|Make_Recheck
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Make_HandleUse
parameter_list|(
name|GNode
modifier|*
parameter_list|,
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Make_Update
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Make_DoAllVar
parameter_list|(
name|GNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Make_Run
parameter_list|(
name|Lst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|Check_Cwd_Cmd
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Check_Cwd
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrintOnError
parameter_list|(
name|GNode
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
name|Main_ExportMAKEFLAGS
parameter_list|(
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Main_SetObjdir
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

begin_function_decl
name|int
name|mkTempFile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|str2Lst_Append
parameter_list|(
name|Lst
parameter_list|,
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
name|cached_lstat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cached_stat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VARF_UNDEFERR
value|1
end_define

begin_define
define|#
directive|define
name|VARF_WANTRES
value|2
end_define

begin_define
define|#
directive|define
name|VARF_ASSIGN
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|UNCONST
parameter_list|(
name|ptr
parameter_list|)
value|({ 		\     union __unconst {			\ 	const void *__cp;		\ 	void *__p;			\     } __d;				\     __d.__cp = ptr, __d.__p; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNCONST
parameter_list|(
name|ptr
parameter_list|)
value|(void *)(ptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a< b) ? a : b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a> b) ? a : b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* At least GNU/Hurd systems lack hardcoded MAXPATHLEN/PATH_MAX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|BMAKE_PATH_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_define
define|#
directive|define
name|PATH_MAX
value|MAXPATHLEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAKE_H_ */
end_comment

end_unit

