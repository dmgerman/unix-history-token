begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vi.h	8.1 (Berkeley) 6/9/93  */
end_comment

begin_comment
comment|/* Ordered before local includes. */
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
file|<regex.h>
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

begin_comment
comment|/* Last, includes compat.h. */
end_comment

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_comment
comment|/* Required by exf.h. */
end_comment

begin_comment
comment|/*  * Forward structure declarations.  Not pretty, but the include files  * are far too interrelated for a clean solution.  */
end_comment

begin_struct_decl
struct_decl|struct
name|_cb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_excmdarg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_excmdlist
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_exf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_gs
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_hdr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_ib
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_mark
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_msg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_option
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_scr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_seq
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_tag
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_tagf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_text
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"hdr.h"
end_include

begin_comment
comment|/* Include before any local includes. */
end_comment

begin_include
include|#
directive|include
file|"mark.h"
end_include

begin_comment
comment|/* Include before cut.h. */
end_comment

begin_include
include|#
directive|include
file|"cut.h"
end_include

begin_include
include|#
directive|include
file|"search.h"
end_include

begin_comment
comment|/* Include before screen.h. */
end_comment

begin_include
include|#
directive|include
file|"options.h"
end_include

begin_comment
comment|/* Include before screen.h. */
end_comment

begin_include
include|#
directive|include
file|"screen.h"
end_include

begin_include
include|#
directive|include
file|"char.h"
end_include

begin_include
include|#
directive|include
file|"exf.h"
end_include

begin_include
include|#
directive|include
file|"gs.h"
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_include
include|#
directive|include
file|"msg.h"
end_include

begin_include
include|#
directive|include
file|"seq.h"
end_include

begin_include
include|#
directive|include
file|"term.h"
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
comment|/* Memory allocation macros. */
end_comment

begin_define
define|#
directive|define
name|BINC
parameter_list|(
name|sp
parameter_list|,
name|lp
parameter_list|,
name|llen
parameter_list|,
name|nlen
parameter_list|)
value|{					\ 	if ((nlen)> llen&& binc(sp,&(lp),&(llen), nlen))		\ 		return (1);						\ }
end_define

begin_decl_stmt
name|int
name|binc
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GET_SPACE
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
value|{					\ 	GS *__gp = (sp)->gp;						\ 	if (F_ISSET(__gp, G_TMP_INUSE)) {				\ 		bp = NULL;						\ 		blen = 0;						\ 		BINC(sp, bp, blen, nlen); 				\ 	} else {							\ 		BINC(sp, __gp->tmp_bp, __gp->tmp_blen, nlen);		\ 		bp = __gp->tmp_bp;					\ 		blen = __gp->tmp_blen;					\ 		F_SET(__gp, G_TMP_INUSE);				\ 	}								\ }
end_define

begin_define
define|#
directive|define
name|ADD_SPACE
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
value|{					\ 	GS *__gp = (sp)->gp;						\ 	if (bp == __gp->tmp_bp) {					\ 		F_CLR(__gp, G_TMP_INUSE);				\ 		BINC(sp, __gp->tmp_bp, __gp->tmp_blen, nlen);		\ 		bp = __gp->tmp_bp;					\ 		blen = __gp->tmp_blen;					\ 		F_SET(__gp, G_TMP_INUSE);				\ 	} else								\ 		BINC(sp, bp, blen, nlen);				\ }
end_define

begin_define
define|#
directive|define
name|FREE_SPACE
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|)
value|{					\ 	if (bp == sp->gp->tmp_bp)					\ 		F_CLR(sp->gp, G_TMP_INUSE);				\ 	else								\ 		FREE(bp, blen);						\ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|p
parameter_list|,
name|sz
parameter_list|)
value|{							\ 	memset(p, 0xff, sz);						\ 	free(p);							\ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|p
parameter_list|,
name|sz
parameter_list|)
value|free(p);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Filter type. */
end_comment

begin_enum
enum|enum
name|filtertype
block|{
name|STANDARD
block|,
name|NOINPUT
block|,
name|NOOUTPUT
block|}
enum|;
end_enum

begin_decl_stmt
name|int
name|filtercmd
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|MARK
operator|*
operator|,
name|MARK
operator|*
operator|,
name|MARK
operator|*
operator|,
name|char
operator|*
operator|,
expr|enum
name|filtertype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Portability stuff. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFFILEMODE
end_ifndef

begin_comment
comment|/* Default file permissions. */
end_comment

begin_define
define|#
directive|define
name|DEFFILEMODE
value|(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*sig_ret_t
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* Type of signal function. */
end_comment

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
value|(((a)< (b)) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Function prototypes that don't seem to belong anywhere else. */
end_comment

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
name|int
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
name|int
name|set_window_size
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|u_int
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

