begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)make.h	8.3 (Berkeley) 6/13/95  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAKE_BOOTSTRAP
argument_list|)
operator|&&
name|defined
argument_list|(
name|BSD4_4
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|protos
end_define

begin_comment
comment|/* full-blown ANSI C */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|()
end_define

begin_comment
comment|/* traditional C preprocessor */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|const
end_ifndef

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|volatile
end_ifndef

begin_define
define|#
directive|define
name|volatile
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

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
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_comment
comment|/*-  * The structure for an individual graph node. Each node has several  * pieces of data associated with it.  *	1) the name of the target it describes  *	2) the location of the target file in the file system.  *	3) the type of operator used to define its sources (qv. parse.c)  *	4) whether it is involved in this invocation of make  *	5) whether the target has been remade  *	6) whether any of its children has been remade  *	7) the number of its children that are, as yet, unmade  *	8) its modification time  *	9) the modification time of its youngest child (qv. make.c)  *	10) a list of nodes for which this is a source  *	11) a list of nodes on which this depends  *	12) a list of nodes that depend on this, as gleaned from the  *	    transformation rules.  *	13) a list of nodes of the same name created by the :: operator  *	14) a list of nodes that must be made (if they're made) before  *	    this node can be, but that do no enter into the datedness of  *	    this node.  *	15) a list of nodes that must be made (if they're made) after  *	    this node is, but that do not depend on this node, in the  *	    normal sense.  *	16) a Lst of ``local'' variables that are specific to this target  *	   and this target only (qv. var.c [$@ $< $?, etc.])  *	17) a Lst of strings that are commands to be given to a shell  *	   to create this target.  */
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
name|path
decl_stmt|;
comment|/* The full pathname of the file */
name|int
name|type
decl_stmt|;
comment|/* Its type (see the OP flags, below) */
name|int
name|order
decl_stmt|;
comment|/* Its wait weight */
name|Boolean
name|make
decl_stmt|;
comment|/* TRUE if this target needs to be remade */
enum|enum
block|{
name|UNMADE
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
block|,
name|CYCLE
block|,
name|ENDCYCLE
block|}
name|made
enum|;
comment|/* Set to reflect the state of processing 				 * on this node: 				 *  UNMADE - Not examined yet 				 *  BEINGMADE - Target is already being made. 				 *  	Indicates a cycle in the graph. (compat 				 *  	mode only) 				 *  MADE - Was out-of-date and has been made 				 *  UPTODATE - Was already up-to-date 				 *  ERROR - An error occured while it was being 				 *  	made (used only in compat mode) 				 *  ABORTED - The target was aborted due to 				 *  	an error making an inferior (compat). 				 *  CYCLE - Marked as potentially being part of 				 *  	a graph cycle. If we come back to a 				 *  	node marked this way, it is printed 				 *  	and 'made' is changed to ENDCYCLE. 				 *  ENDCYCLE - the cycle has been completely 				 *  	printed. Go back and unmark all its 				 *  	members. 				 */
name|Boolean
name|childMade
decl_stmt|;
comment|/* TRUE if one of this target's children was 				 * made */
name|int
name|unmade
decl_stmt|;
comment|/* The number of unmade children */
name|int
name|mtime
decl_stmt|;
comment|/* Its modification time */
name|int
name|cmtime
decl_stmt|;
comment|/* The modification time of its youngest 				 * child */
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
name|successors
decl_stmt|;
comment|/* Nodes that must be made after this one */
name|Lst
name|preds
decl_stmt|;
comment|/* Nodes that must be made before this one */
name|Lst
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
block|}
name|GNode
typedef|;
end_typedef

begin_comment
comment|/*  * Manifest constants  */
end_comment

begin_define
define|#
directive|define
name|NILGNODE
value|((GNode *) NIL)
end_define

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
comment|/*  * The TARG_ constants are used when calling the Targ_FindNode and  * Targ_FindList functions in targ.c. They simply tell the functions what to  * do if the desired node(s) is (are) not found. If the TARG_CREATE constant  * is given, a new, empty node will be created for the target, placed in the  * table of all targets and its address returned. If TARG_NOCREATE is given,  * a NIL pointer will be returned.  */
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
name|TARG_NOCREATE
value|0x00
end_define

begin_comment
comment|/* don't create it */
end_comment

begin_comment
comment|/*  * There are several places where expandable buffers are used (parse.c and  * var.c). This constant is merely the starting point for those buffers. If  * lines tend to be much shorter than this, it would be best to reduce BSIZE.  * If longer, it should be increased. Reducing it will cause more copying to  * be done for longer lines, but will save space for shorter ones. In any  * case, it ought to be a power of two simply because most storage allocation  * schemes allocate in powers of two.  */
end_comment

begin_define
define|#
directive|define
name|MAKE_BSIZE
value|256
end_define

begin_comment
comment|/* starting size for expandable buffers */
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
name|STR_DOFREE
value|0x02
end_define

begin_comment
comment|/* free source strings after concatenation */
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
name|usePipes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if should capture the output of 				 * subshells by means of pipes. Otherwise it 				 * is routed to temporary files from which it 				 * is retrieved when the shell exits */
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
name|checkEnvFirst
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if environment should be searched for 				 * all variables before the global context */
end_comment

begin_decl_stmt
specifier|extern
name|Lst
name|envFirstVars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of specific variables for which the 				 * environment should be searched before the 				 * global context */
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

begin_comment
comment|/*  * debug control:  *	There is one bit per module.  It is up to the module what debug  *	information to print.  */
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
value|0x0001
end_define

begin_define
define|#
directive|define
name|DEBUG_COND
value|0x0002
end_define

begin_define
define|#
directive|define
name|DEBUG_DIR
value|0x0004
end_define

begin_define
define|#
directive|define
name|DEBUG_GRAPH1
value|0x0008
end_define

begin_define
define|#
directive|define
name|DEBUG_GRAPH2
value|0x0010
end_define

begin_define
define|#
directive|define
name|DEBUG_JOB
value|0x0020
end_define

begin_define
define|#
directive|define
name|DEBUG_MAKE
value|0x0040
end_define

begin_define
define|#
directive|define
name|DEBUG_SUFF
value|0x0080
end_define

begin_define
define|#
directive|define
name|DEBUG_TARG
value|0x0100
end_define

begin_define
define|#
directive|define
name|DEBUG_VAR
value|0x0200
end_define

begin_define
define|#
directive|define
name|DEBUG_FOR
value|0x0400
end_define

begin_define
define|#
directive|define
name|DEBUG_LOUD
value|0x0800
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|I
parameter_list|(
name|a
parameter_list|)
value|a
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
value|I(a)b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|module
parameter_list|)
value|(debug& CONCAT(DEBUG_,module))
end_define

begin_define
define|#
directive|define
name|ISDOT
parameter_list|(
name|c
parameter_list|)
value|((c)[0] == '.'&& (((c)[1] == '\0') || ((c)[1] == '/')))
end_define

begin_define
define|#
directive|define
name|ISDOTDOT
parameter_list|(
name|c
parameter_list|)
value|((c)[0] == '.'&& ISDOT(&((c)[1])))
end_define

begin_comment
comment|/*  * Since there are so many, all functions that return non-integer values are  * extracted by means of a sed script or two and stuck in the file "nonints.h"  */
end_comment

begin_include
include|#
directive|include
file|"nonints.h"
end_include

begin_decl_stmt
name|int
name|Make_TimeStamp
name|__P
argument_list|(
operator|(
name|GNode
operator|*
operator|,
name|GNode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Boolean
name|Make_OODate
name|__P
argument_list|(
operator|(
name|GNode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Make_HandleUse
name|__P
argument_list|(
operator|(
name|GNode
operator|*
operator|,
name|GNode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Make_Update
name|__P
argument_list|(
operator|(
name|GNode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Make_DoAllVar
name|__P
argument_list|(
operator|(
name|GNode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Boolean
name|Make_Run
name|__P
argument_list|(
operator|(
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAKE_H_ */
end_comment

end_unit

