begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GNode_h_39503bf2
end_ifndef

begin_define
define|#
directive|define
name|GNode_h_39503bf2
end_define

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

begin_struct_decl
struct_decl|struct
name|Suff
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The structure for an individual graph node. Each node has several  * pieces of data associated with it.  */
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
comment|/* The full pathname of the target file */
comment|/* 	 * The type of operator used to define the sources (qv. parse.c) 	 * See OP_ flags in make.h 	 */
name|int
name|type
decl_stmt|;
name|int
name|order
decl_stmt|;
comment|/* Its wait weight */
name|Boolean
name|make
decl_stmt|;
comment|/* TRUE if this target needs to be remade */
comment|/* Set to reflect the state of processing on this node */
enum|enum
block|{
name|UNMADE
block|,
comment|/* Not examined yet */
comment|/* 		 * Target is already being made. Indicates a cycle in the graph. 		 * (compat mode only) 		 */
name|BEINGMADE
block|,
name|MADE
block|,
comment|/* Was out-of-date and has been made */
name|UPTODATE
block|,
comment|/* Was already up-to-date */
comment|/* 		 * An error occured while it was being 		 * made (used only in compat mode) 		 */
name|ERROR
block|,
comment|/* 		 * The target was aborted due to an 		 * error making an inferior (compat). 		 */
name|ABORTED
block|,
comment|/* 		 * Marked as potentially being part of a graph cycle.  If we 		 * come back to a node marked this way, it is printed and 		 * 'made' is changed to ENDCYCLE. 		 */
name|CYCLE
block|,
comment|/* 		 * The cycle has been completely printed.  Go back and 		 * unmark all its members. 		 */
name|ENDCYCLE
block|}
name|made
enum|;
comment|/* TRUE if one of this target's children was made */
name|Boolean
name|childMade
decl_stmt|;
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
comment|/* Modification time of its youngest child */
comment|/* 	 * Links to parents for which this is an implied source, if any. (nodes 	 * that depend on this, as gleaned from the transformation rules. 	 */
name|Lst
name|iParents
decl_stmt|;
comment|/* List of nodes of the same name created by the :: operator */
name|Lst
name|cohorts
decl_stmt|;
comment|/* Lst of nodes for which this is a source (that depend on this one) */
name|Lst
name|parents
decl_stmt|;
comment|/* List of nodes on which this depends */
name|Lst
name|children
decl_stmt|;
comment|/* 	 * List of nodes that must be made (if they're made) after this node is, 	 * but that do not depend on this node, in the normal sense. 	 */
name|Lst
name|successors
decl_stmt|;
comment|/* 	 * List of nodes that must be made (if they're made) before this node 	 * can be, but that do no enter into the datedness of this node. 	 */
name|Lst
name|preds
decl_stmt|;
comment|/* 	 * List of ``local'' variables that are specific to this target 	 * and this target only (qv. var.c [$@ $< $?, etc.]) 	 */
name|Lst
name|context
decl_stmt|;
comment|/* 	 * List of strings that are commands to be given to a shell 	 * to create this target. 	 */
name|Lst
name|commands
decl_stmt|;
comment|/* current command executing in compat mode */
name|LstNode
modifier|*
name|compat_command
decl_stmt|;
comment|/* 	 * Suffix for the node (determined by Suff_FindDeps and opaque to 	 * everyone but the Suff module) 	 */
name|struct
name|Suff
modifier|*
name|suffix
decl_stmt|;
block|}
name|GNode
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNode_h_39503bf2 */
end_comment

end_unit

