begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mem.h	8.5 (Berkeley) 3/16/94  */
end_comment

begin_comment
comment|/* Increase the size of a malloc'd buffer.  Two versions, one that  * returns, one that jumps to an error label.  */
end_comment

begin_define
define|#
directive|define
name|BINC_GOTO
parameter_list|(
name|sp
parameter_list|,
name|lp
parameter_list|,
name|llen
parameter_list|,
name|nlen
parameter_list|)
value|{					\ 	if ((nlen)> llen&& binc(sp,&(lp),&(llen), nlen))		\ 		goto binc_err;						\ }
end_define

begin_define
define|#
directive|define
name|BINC_RET
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

begin_comment
comment|/*  * Get some temporary space, preferably from the global temporary buffer,  * from a malloc'd buffer otherwise.  Two versions, one that returns, one  * that jumps to an error label.  */
end_comment

begin_define
define|#
directive|define
name|GET_SPACE_GOTO
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
value|{				\ 	GS *__gp = (sp)->gp;						\ 	if (F_ISSET(__gp, G_TMP_INUSE)) {				\ 		bp = NULL;						\ 		blen = 0;						\ 		BINC_GOTO(sp, bp, blen, nlen); 				\ 	} else {							\ 		BINC_GOTO(sp, __gp->tmp_bp, __gp->tmp_blen, nlen);	\ 		bp = __gp->tmp_bp;					\ 		blen = __gp->tmp_blen;					\ 		F_SET(__gp, G_TMP_INUSE);				\ 	}								\ }
end_define

begin_define
define|#
directive|define
name|GET_SPACE_RET
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
value|{				\ 	GS *__gp = (sp)->gp;						\ 	if (F_ISSET(__gp, G_TMP_INUSE)) {				\ 		bp = NULL;						\ 		blen = 0;						\ 		BINC_RET(sp, bp, blen, nlen);				\ 	} else {							\ 		BINC_RET(sp, __gp->tmp_bp, __gp->tmp_blen, nlen);	\ 		bp = __gp->tmp_bp;					\ 		blen = __gp->tmp_blen;					\ 		F_SET(__gp, G_TMP_INUSE);				\ 	}								\ }
end_define

begin_comment
comment|/*  * Add space to a GET_SPACE returned buffer.  Two versions, one that  * returns, one that jumps to an error label.  */
end_comment

begin_define
define|#
directive|define
name|ADD_SPACE_GOTO
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
value|{				\ 	GS *__gp = (sp)->gp;						\ 	if (bp == __gp->tmp_bp) {					\ 		F_CLR(__gp, G_TMP_INUSE);				\ 		BINC_GOTO(sp, __gp->tmp_bp, __gp->tmp_blen, nlen);	\ 		bp = __gp->tmp_bp;					\ 		blen = __gp->tmp_blen;					\ 		F_SET(__gp, G_TMP_INUSE);				\ 	} else								\ 		BINC_GOTO(sp, bp, blen, nlen);				\ }
end_define

begin_define
define|#
directive|define
name|ADD_SPACE_RET
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
value|{				\ 	GS *__gp = (sp)->gp;						\ 	if (bp == __gp->tmp_bp) {					\ 		F_CLR(__gp, G_TMP_INUSE);				\ 		BINC_RET(sp, __gp->tmp_bp, __gp->tmp_blen, nlen);	\ 		bp = __gp->tmp_bp;					\ 		blen = __gp->tmp_blen;					\ 		F_SET(__gp, G_TMP_INUSE);				\ 	} else								\ 		BINC_RET(sp, bp, blen, nlen);				\ }
end_define

begin_comment
comment|/* Free memory, optionally making pointers unusable. */
end_comment

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
comment|/* Free a GET_SPACE returned buffer. */
end_comment

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

begin_comment
comment|/*  * Malloc a buffer, casting the return pointer.  Various versions.  *  * !!!  * The cast should be unnecessary, malloc(3) and friends return void *'s,  * which is all we need.  However, some systems that nvi needs to run on  * don't do it right yet, resulting in the compiler printing out roughly  * a million warnings.  After awhile, it seemed easier to put the casts  * in instead of explaining it all the time.  */
end_comment

begin_define
define|#
directive|define
name|CALLOC_NOMSG
parameter_list|(
name|sp
parameter_list|,
name|p
parameter_list|,
name|cast
parameter_list|,
name|nmemb
parameter_list|,
name|size
parameter_list|)
value|{			\ 	p = (cast)calloc(nmemb, size);					\ }
end_define

begin_define
define|#
directive|define
name|CALLOC
parameter_list|(
name|sp
parameter_list|,
name|p
parameter_list|,
name|cast
parameter_list|,
name|nmemb
parameter_list|,
name|size
parameter_list|)
value|{				\ 	if ((p = (cast)calloc(nmemb, size)) == NULL)			\ 		msgq(sp, M_SYSERR, NULL);				\ }
end_define

begin_define
define|#
directive|define
name|CALLOC_RET
parameter_list|(
name|sp
parameter_list|,
name|p
parameter_list|,
name|cast
parameter_list|,
name|nmemb
parameter_list|,
name|size
parameter_list|)
value|{				\ 	if ((p = (cast)calloc(nmemb, size)) == NULL) {			\ 		msgq(sp, M_SYSERR, NULL);				\ 		return (1);						\ 	}								\ }
end_define

begin_define
define|#
directive|define
name|MALLOC_NOMSG
parameter_list|(
name|sp
parameter_list|,
name|p
parameter_list|,
name|cast
parameter_list|,
name|size
parameter_list|)
value|{				\ 	p = (cast)malloc(size);						\ }
end_define

begin_define
define|#
directive|define
name|MALLOC
parameter_list|(
name|sp
parameter_list|,
name|p
parameter_list|,
name|cast
parameter_list|,
name|size
parameter_list|)
value|{					\ 	if ((p = (cast)malloc(size)) == NULL)				\ 		msgq(sp, M_SYSERR, NULL);				\ }
end_define

begin_define
define|#
directive|define
name|MALLOC_RET
parameter_list|(
name|sp
parameter_list|,
name|p
parameter_list|,
name|cast
parameter_list|,
name|size
parameter_list|)
value|{					\ 	if ((p = (cast)malloc(size)) == NULL) {				\ 		msgq(sp, M_SYSERR, NULL);				\ 		return (1);						\ 	}								\ }
end_define

begin_define
define|#
directive|define
name|REALLOC
parameter_list|(
name|sp
parameter_list|,
name|p
parameter_list|,
name|cast
parameter_list|,
name|size
parameter_list|)
value|{					\ 	if ((p = (cast)realloc(p, size)) == NULL)			\ 		msgq(sp, M_SYSERR, NULL);				\ }
end_define

begin_comment
comment|/*  * Versions of memmove(3) and memset(3) that use the size of the  * initial pointer to figure out how much memory to manipulate.  */
end_comment

begin_define
define|#
directive|define
name|MEMMOVE
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|,
name|len
parameter_list|)
value|memmove(p, t, (len) * sizeof(*(p)))
end_define

begin_define
define|#
directive|define
name|MEMSET
parameter_list|(
name|p
parameter_list|,
name|value
parameter_list|,
name|len
parameter_list|)
value|memset(p, value, (len) * sizeof(*(p)))
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

end_unit

