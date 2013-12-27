begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	$Id: mem.h,v 10.17 2012/10/07 00:40:29 zy Exp $  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|CHECK_TYPE
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|)
define|\
value|type L__lp __attribute__((unused)) = var;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHECK_TYPE
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|type
parameter_list|,
name|lp
parameter_list|,
name|llen
parameter_list|,
name|nlen
parameter_list|)
value|{				\ 	CHECK_TYPE(type *, lp)						\ 	void *L__bincp;							\ 	if ((nlen)> llen) {						\ 		if ((L__bincp = binc(sp, lp,&(llen), nlen)) == NULL)	\ 			goto alloc_err;					\
comment|/*							\ 		 * !!!							\ 		 * Possible pointer conversion.				\ 		 */
value|\ 		lp = L__bincp;						\ 	}								\ }
end_define

begin_define
define|#
directive|define
name|BINC_GOTOC
parameter_list|(
name|sp
parameter_list|,
name|lp
parameter_list|,
name|llen
parameter_list|,
name|nlen
parameter_list|)
define|\
value|BINC_GOTO(sp, char, lp, llen, nlen)
end_define

begin_define
define|#
directive|define
name|BINC_GOTOW
parameter_list|(
name|sp
parameter_list|,
name|lp
parameter_list|,
name|llen
parameter_list|,
name|nlen
parameter_list|)
define|\
value|BINC_GOTO(sp, CHAR_T, lp, llen, (nlen) * sizeof(CHAR_T))
end_define

begin_define
define|#
directive|define
name|BINC_RET
parameter_list|(
name|sp
parameter_list|,
name|type
parameter_list|,
name|lp
parameter_list|,
name|llen
parameter_list|,
name|nlen
parameter_list|)
value|{				\ 	CHECK_TYPE(type *, lp)						\ 	void *L__bincp;							\ 	if ((nlen)> llen) {						\ 		if ((L__bincp = binc(sp, lp,&(llen), nlen)) == NULL)	\ 			return (1);					\
comment|/*							\ 		 * !!!							\ 		 * Possible pointer conversion.				\ 		 */
value|\ 		lp = L__bincp;						\ 	}								\ }
end_define

begin_define
define|#
directive|define
name|BINC_RETC
parameter_list|(
name|sp
parameter_list|,
name|lp
parameter_list|,
name|llen
parameter_list|,
name|nlen
parameter_list|)
define|\
value|BINC_RET(sp, char, lp, llen, nlen)
end_define

begin_define
define|#
directive|define
name|BINC_RETW
parameter_list|(
name|sp
parameter_list|,
name|lp
parameter_list|,
name|llen
parameter_list|,
name|nlen
parameter_list|)
define|\
value|BINC_RET(sp, CHAR_T, lp, llen, (nlen) * sizeof(CHAR_T))
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
name|type
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
value|{			\ 	CHECK_TYPE(type *, bp)						\ 	GS *L__gp = (sp) == NULL ? NULL : (sp)->gp;			\ 	if (L__gp == NULL || F_ISSET(L__gp, G_TMP_INUSE)) {		\ 		bp = NULL;						\ 		blen = 0;						\ 		BINC_GOTO(sp, type, bp, blen, nlen); 			\ 	} else {							\ 		BINC_GOTOC(sp, L__gp->tmp_bp, L__gp->tmp_blen, nlen);	\ 		bp = (type *) L__gp->tmp_bp;				\ 		blen = L__gp->tmp_blen;					\ 		F_SET(L__gp, G_TMP_INUSE);				\ 	}								\ }
end_define

begin_define
define|#
directive|define
name|GET_SPACE_GOTOC
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
define|\
value|GET_SPACE_GOTO(sp, char, bp, blen, nlen)
end_define

begin_define
define|#
directive|define
name|GET_SPACE_GOTOW
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
define|\
value|GET_SPACE_GOTO(sp, CHAR_T, bp, blen, (nlen) * sizeof(CHAR_T))
end_define

begin_define
define|#
directive|define
name|GET_SPACE_RET
parameter_list|(
name|sp
parameter_list|,
name|type
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
value|{			\ 	CHECK_TYPE(type *, bp)						\ 	GS *L__gp = (sp) == NULL ? NULL : (sp)->gp;			\ 	if (L__gp == NULL || F_ISSET(L__gp, G_TMP_INUSE)) {		\ 		bp = NULL;						\ 		blen = 0;						\ 		BINC_RET(sp, type, bp, blen, nlen);			\ 	} else {							\ 		BINC_RETC(sp, L__gp->tmp_bp, L__gp->tmp_blen, nlen);	\ 		bp = (type *) L__gp->tmp_bp;				\ 		blen = L__gp->tmp_blen;					\ 		F_SET(L__gp, G_TMP_INUSE);				\ 	}								\ }
end_define

begin_define
define|#
directive|define
name|GET_SPACE_RETC
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
define|\
value|GET_SPACE_RET(sp, char, bp, blen, nlen)
end_define

begin_define
define|#
directive|define
name|GET_SPACE_RETW
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
define|\
value|GET_SPACE_RET(sp, CHAR_T, bp, blen, (nlen) * sizeof(CHAR_T))
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
name|type
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
value|{			\ 	CHECK_TYPE(type *, bp)						\ 	GS *L__gp = (sp) == NULL ? NULL : (sp)->gp;			\ 	if (L__gp == NULL || bp == (type *)L__gp->tmp_bp) {		\ 		F_CLR(L__gp, G_TMP_INUSE);				\ 		BINC_GOTOC(sp, L__gp->tmp_bp, L__gp->tmp_blen, nlen);	\ 		bp = (type *) L__gp->tmp_bp;				\ 		blen = L__gp->tmp_blen;					\ 		F_SET(L__gp, G_TMP_INUSE);				\ 	} else								\ 		BINC_GOTO(sp, type, bp, blen, nlen);			\ }
end_define

begin_define
define|#
directive|define
name|ADD_SPACE_GOTOC
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
define|\
value|ADD_SPACE_GOTO(sp, char, bp, blen, nlen)
end_define

begin_define
define|#
directive|define
name|ADD_SPACE_GOTOW
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
define|\
value|ADD_SPACE_GOTO(sp, CHAR_T, bp, blen, (nlen) * sizeof(CHAR_T))
end_define

begin_define
define|#
directive|define
name|ADD_SPACE_RET
parameter_list|(
name|sp
parameter_list|,
name|type
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
value|{			\ 	CHECK_TYPE(type *, bp)						\ 	GS *L__gp = (sp) == NULL ? NULL : (sp)->gp;			\ 	if (L__gp == NULL || bp == (type *)L__gp->tmp_bp) {		\ 		F_CLR(L__gp, G_TMP_INUSE);				\ 		BINC_RETC(sp, L__gp->tmp_bp, L__gp->tmp_blen, nlen);	\ 		bp = (type *) L__gp->tmp_bp;				\ 		blen = L__gp->tmp_blen;					\ 		F_SET(L__gp, G_TMP_INUSE);				\ 	} else								\ 		BINC_RET(sp, type, bp, blen, nlen);			\ }
end_define

begin_define
define|#
directive|define
name|ADD_SPACE_RETC
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
define|\
value|ADD_SPACE_RET(sp, char, bp, blen, nlen)
end_define

begin_define
define|#
directive|define
name|ADD_SPACE_RETW
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|,
name|nlen
parameter_list|)
define|\
value|ADD_SPACE_RET(sp, CHAR_T, bp, blen, (nlen) * sizeof(CHAR_T))
end_define

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
value|{					\ 	GS *L__gp = (sp) == NULL ? NULL : (sp)->gp;			\ 	if (L__gp != NULL&& bp == L__gp->tmp_bp)			\ 		F_CLR(L__gp, G_TMP_INUSE);				\ 	else								\ 		free(bp);						\ }
end_define

begin_define
define|#
directive|define
name|FREE_SPACEW
parameter_list|(
name|sp
parameter_list|,
name|bp
parameter_list|,
name|blen
parameter_list|)
value|{					\ 	CHECK_TYPE(CHAR_T *, bp)					\ 	FREE_SPACE(sp, (char *)bp, blen);				\ }
end_define

begin_comment
comment|/*  * Malloc a buffer, casting the return pointer.  Various versions.  *  * !!!  * The cast should be unnecessary, malloc(3) and friends return void *'s,  * which is all we need.  However, some systems that nvi needs to run on  * don't do it right yet, resulting in the compiler printing out roughly  * a million warnings.  After awhile, it seemed easier to put the casts  * in instead of explaining it all the time.  */
end_comment

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
name|CALLOC_GOTO
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
value|{				\ 	if ((p = (cast)calloc(nmemb, size)) == NULL)			\ 		goto alloc_err;						\ }
end_define

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
name|MALLOC_GOTO
parameter_list|(
name|sp
parameter_list|,
name|p
parameter_list|,
name|cast
parameter_list|,
name|size
parameter_list|)
value|{				\ 	if ((p = (cast)malloc(size)) == NULL)				\ 		goto alloc_err;						\ }
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

begin_comment
comment|/*  * Resize a buffer, free any already held memory if we can't get more.  * FreeBSD's reallocf(3) does the same thing, but it's not portable yet.  */
end_comment

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
value|{					\ 	cast newp;							\ 	if ((newp = (cast)realloc(p, size)) == NULL) {			\ 		if (p != NULL)						\ 			free(p);					\ 		msgq(sp, M_SYSERR, NULL);				\ 	}								\ 	p = newp;							\ }
end_define

begin_comment
comment|/*  * Versions of bcopy(3) and bzero(3) that use the size of the  * initial pointer to figure out how much memory to manipulate.  */
end_comment

begin_define
define|#
directive|define
name|BCOPY
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|,
name|len
parameter_list|)
value|bcopy(p, t, (len) * sizeof(*(p)))
end_define

begin_define
define|#
directive|define
name|BZERO
parameter_list|(
name|p
parameter_list|,
name|len
parameter_list|)
value|bzero(p, (len) * sizeof(*(p)))
end_define

begin_comment
comment|/*   * p2roundup --  *	Get next power of 2; convenient for realloc.  *  * Reference: FreeBSD /usr/src/lib/libc/stdio/getdelim.c  */
end_comment

begin_function
specifier|static
name|__inline
name|size_t
name|p2roundup
parameter_list|(
name|size_t
name|n
parameter_list|)
block|{
name|n
operator|--
expr_stmt|;
name|n
operator||=
name|n
operator|>>
literal|1
expr_stmt|;
name|n
operator||=
name|n
operator|>>
literal|2
expr_stmt|;
name|n
operator||=
name|n
operator|>>
literal|4
expr_stmt|;
name|n
operator||=
name|n
operator|>>
literal|8
expr_stmt|;
name|n
operator||=
name|n
operator|>>
literal|16
expr_stmt|;
if|#
directive|if
name|SIZE_T_MAX
operator|>
literal|0xffffffffU
name|n
operator||=
name|n
operator|>>
literal|32
expr_stmt|;
endif|#
directive|endif
name|n
operator|++
expr_stmt|;
return|return
operator|(
name|n
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Additional TAILQ helper. */
end_comment

begin_define
define|#
directive|define
name|TAILQ_ENTRY_ISVALID
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|((elm)->field.tqe_prev != NULL)
end_define

end_unit

