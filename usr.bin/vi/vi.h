begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vi.h	8.33 (Berkeley) 1/9/94  */
end_comment

begin_comment
comment|/* System includes. */
end_comment

begin_include
include|#
directive|include
file|<queue.h>
end_include

begin_comment
comment|/* Required by screen.h. */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* Required by screen.h. */
end_comment

begin_include
include|#
directive|include
file|<bitstring.h>
end_include

begin_comment
comment|/* Required by screen.h. */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|/* Required by screen.h. */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/* Required by screen.h. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Required by screen.h. */
end_comment

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_comment
comment|/* Required by gs.h. */
end_comment

begin_comment
comment|/*  * Required by screen.h.  This is the first include that can pull  * in "compat.h".  Should be after every other system include.  */
end_comment

begin_include
include|#
directive|include
file|<regex.h>
end_include

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
name|_chname
name|CHNAME
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
name|_ibuf
name|IBUF
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
comment|/*  * Fundamental character types.  *  * CHAR_T	An integral type that can hold any character.  * ARG_CHAR_T	The type of a CHAR_T when passed as an argument using  *		traditional promotion rules.  It should also be able  *		to be compared against any CHAR_T for equality without  *		problems.  * MAX_CHAR_T	The maximum value of any character.  *  * If no integral type can hold a character, don't even try the port.  */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|CHAR_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int
name|ARG_CHAR_T
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_CHAR_T
value|0xff
end_define

begin_comment
comment|/* The maximum number of columns any character can take up on a screen. */
end_comment

begin_define
define|#
directive|define
name|MAX_CHARACTER_COLUMNS
value|4
end_define

begin_comment
comment|/*  * Local includes.  */
end_comment

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_comment
comment|/* Required by exf.h; includes compat.h. */
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
file|"term.h"
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

begin_if
if|#
directive|if
name|FWOPEN_NOT_AVAILABLE
end_if

begin_comment
comment|/* See PORT/clib/fwopen.c. */
end_comment

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
comment|/*  * XXX  * MIN/MAX have traditionally been in<sys/param.h>.  Don't  * try to get them from there, it's just not worth the effort.  */
end_comment

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
name|_a
parameter_list|,
name|_b
parameter_list|)
value|((_a)<(_b)?(_b):(_a))
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
name|_a
parameter_list|,
name|_b
parameter_list|)
value|((_a)<(_b)?(_a):(_b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Function prototypes that don't seem to belong anywhere else. */
end_comment

begin_decl_stmt
name|u_long
name|baud_from_bval
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
name|char
modifier|*
name|charname
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|ARG_CHAR_T
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|busy_off
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
name|void
name|busy_on
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nonblank
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|recno_t
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_alt_name
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|set_window_size
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|u_int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|status
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|recno_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tail
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CHAR_T
modifier|*
name|v_strdup
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|CHAR_T
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|void
name|TRACE
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Digraphs (not currently real). */
end_comment

begin_decl_stmt
name|int
name|digraph
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|digraph_init
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
name|void
name|digraph_save
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

