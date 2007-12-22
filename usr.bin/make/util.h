begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|util_h_b7020fdb
end_ifndef

begin_define
define|#
directive|define
name|util_h_b7020fdb
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

begin_comment
comment|/*  * A boolean type is defined as an integer, not an enum. This allows a  * boolean argument to be an expression that isn't strictly 0 or 1 valued.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|Boolean
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TRUE */
end_comment

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

begin_struct
struct|struct
name|flag2str
block|{
name|u_int
name|flag
decl_stmt|;
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * debug control:  *	There is one bit per module.  It is up to the module what debug  *	information to print.  */
end_comment

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
name|DEBUGF
parameter_list|(
name|module
parameter_list|,
name|args
parameter_list|)
define|\
value|do {						\ 	if (DEBUG(module)) {			\ 		Debug args ;			\ 	}					\ } while (0)
end_define

begin_define
define|#
directive|define
name|DEBUGM
parameter_list|(
name|module
parameter_list|,
name|args
parameter_list|)
value|do {		\ 	if (DEBUG(module)) {			\ 		DebugM args;			\ 	}					\     } while (0)
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
value|((a)> (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|Debug
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DebugM
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
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
function_decl|;
end_function_decl

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
name|__dead2
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
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DieHorribly
argument_list|(
name|void
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Finish
argument_list|(
name|int
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|estrdup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|emalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|erealloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

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
name|print_flags
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|struct
name|flag2str
modifier|*
parameter_list|,
name|u_int
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
comment|/* util_h_b7020fdb */
end_comment

end_unit

