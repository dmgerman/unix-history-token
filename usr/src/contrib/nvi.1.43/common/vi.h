begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vi.h	9.1 (Berkeley) 11/9/94  */
end_comment

begin_comment
comment|/*  * Forward structure declarations.  Not pretty, but the include files  * are far too interrelated for a clean solution.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_cb
name|CB
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ch
name|CH
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_excmdarg
name|EXCMDARG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_exf
name|EXF
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_fref
name|FREF
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_gs
name|GS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_lmark
name|LMARK
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_mark
name|MARK
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_msg
name|MSG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_option
name|OPTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_optlist
name|OPTLIST
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_scr
name|SCR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_script
name|SCRIPT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_seq
name|SEQ
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_tag
name|TAG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_tagf
name|TAGF
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_text
name|TEXT
typedef|;
end_typedef

begin_comment
comment|/*  * Local includes.  */
end_comment

begin_include
include|#
directive|include
file|"term.h"
end_include

begin_comment
comment|/* Required by args.h. */
end_comment

begin_include
include|#
directive|include
file|"args.h"
end_include

begin_comment
comment|/* Required by options.h. */
end_comment

begin_include
include|#
directive|include
file|"options.h"
end_include

begin_comment
comment|/* Required by screen.h. */
end_comment

begin_include
include|#
directive|include
file|"search.h"
end_include

begin_comment
comment|/* Required by screen.h. */
end_comment

begin_include
include|#
directive|include
file|"msg.h"
end_include

begin_comment
comment|/* Required by gs.h. */
end_comment

begin_include
include|#
directive|include
file|"cut.h"
end_include

begin_comment
comment|/* Required by gs.h. */
end_comment

begin_include
include|#
directive|include
file|"seq.h"
end_include

begin_comment
comment|/* Required by screen.h. */
end_comment

begin_include
include|#
directive|include
file|"gs.h"
end_include

begin_comment
comment|/* Required by screen.h. */
end_comment

begin_include
include|#
directive|include
file|"screen.h"
end_include

begin_comment
comment|/* Required by exf.h. */
end_comment

begin_include
include|#
directive|include
file|"mark.h"
end_include

begin_comment
comment|/* Required by exf.h. */
end_comment

begin_include
include|#
directive|include
file|"exf.h"
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_include
include|#
directive|include
file|"mem.h"
end_include

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_comment
comment|/* Macros to set/clear/test flags. */
end_comment

begin_define
define|#
directive|define
name|F_SET
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
value|(p)->flags |= (f)
end_define

begin_define
define|#
directive|define
name|F_CLR
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
value|(p)->flags&= ~(f)
end_define

begin_define
define|#
directive|define
name|F_ISSET
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
value|((p)->flags& (f))
end_define

begin_define
define|#
directive|define
name|LF_INIT
parameter_list|(
name|f
parameter_list|)
value|flags = (f)
end_define

begin_define
define|#
directive|define
name|LF_SET
parameter_list|(
name|f
parameter_list|)
value|flags |= (f)
end_define

begin_define
define|#
directive|define
name|LF_CLR
parameter_list|(
name|f
parameter_list|)
value|flags&= ~(f)
end_define

begin_define
define|#
directive|define
name|LF_ISSET
parameter_list|(
name|f
parameter_list|)
value|(flags& (f))
end_define

begin_comment
comment|/*  * !!!  * Fake the 4.4BSD fwopen(3) routines.  See PORT/clib/fwopen.c.  */
end_comment

begin_if
if|#
directive|if
name|FWOPEN_NOT_AVAILABLE
end_if

begin_define
define|#
directive|define
name|EXCOOKIE
value|sp
end_define

begin_decl_stmt
name|int
name|ex_fflush
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ex_printf
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|fwopen
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXCOOKIE
value|sp->stdfp
end_define

begin_define
define|#
directive|define
name|ex_fflush
value|fflush
end_define

begin_define
define|#
directive|define
name|ex_printf
value|fprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

