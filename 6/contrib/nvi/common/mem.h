begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)mem.h	10.7 (Berkeley) 3/30/96  */
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
value|{					\ 	void *L__bincp;							\ 	if ((nlen)> llen) {						\ 		if ((L__bincp = binc(sp, lp,&(llen), nlen)) == NULL)	\ 			goto alloc_err;					\
comment|/*							\ 		 * !!!							\ 		 * Possible pointer conversion.				\ 		 */
value|\ 		lp = L__bincp;						\ 	}								\ }
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
value|{					\ 	void *L__bincp;							\ 	if ((nlen)> llen) {						\ 		if ((L__bincp = binc(sp, lp,&(llen), nlen)) == NULL)	\ 			return (1);					\
comment|/*							\ 		 * !!!							\ 		 * Possible pointer conversion.				\ 		 */
value|\ 		lp = L__bincp;						\ 	}								\ }
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
value|{				\ 	GS *L__gp = (sp) == NULL ? NULL : (sp)->gp;			\ 	if (L__gp == NULL || F_ISSET(L__gp, G_TMP_INUSE)) {		\ 		bp = NULL;						\ 		blen = 0;						\ 		BINC_GOTO(sp, bp, blen, nlen); 				\ 	} else {							\ 		BINC_GOTO(sp, L__gp->tmp_bp, L__gp->tmp_blen, nlen);	\ 		bp = L__gp->tmp_bp;					\ 		blen = L__gp->tmp_blen;					\ 		F_SET(L__gp, G_TMP_INUSE);				\ 	}								\ }
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
value|{				\ 	GS *L__gp = (sp) == NULL ? NULL : (sp)->gp;			\ 	if (L__gp == NULL || F_ISSET(L__gp, G_TMP_INUSE)) {		\ 		bp = NULL;						\ 		blen = 0;						\ 		BINC_RET(sp, bp, blen, nlen);				\ 	} else {							\ 		BINC_RET(sp, L__gp->tmp_bp, L__gp->tmp_blen, nlen);	\ 		bp = L__gp->tmp_bp;					\ 		blen = L__gp->tmp_blen;					\ 		F_SET(L__gp, G_TMP_INUSE);				\ 	}								\ }
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
value|{				\ 	GS *L__gp = (sp) == NULL ? NULL : (sp)->gp;			\ 	if (L__gp == NULL || bp == L__gp->tmp_bp) {			\ 		F_CLR(L__gp, G_TMP_INUSE);				\ 		BINC_GOTO(sp, L__gp->tmp_bp, L__gp->tmp_blen, nlen);	\ 		bp = L__gp->tmp_bp;					\ 		blen = L__gp->tmp_blen;					\ 		F_SET(L__gp, G_TMP_INUSE);				\ 	} else								\ 		BINC_GOTO(sp, bp, blen, nlen);				\ }
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
value|{				\ 	GS *L__gp = (sp) == NULL ? NULL : (sp)->gp;			\ 	if (L__gp == NULL || bp == L__gp->tmp_bp) {			\ 		F_CLR(L__gp, G_TMP_INUSE);				\ 		BINC_RET(sp, L__gp->tmp_bp, L__gp->tmp_blen, nlen);	\ 		bp = L__gp->tmp_bp;					\ 		blen = L__gp->tmp_blen;					\ 		F_SET(L__gp, G_TMP_INUSE);				\ 	} else								\ 		BINC_RET(sp, bp, blen, nlen);				\ }
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
comment|/*  * XXX  * Don't depend on realloc(NULL, size) working.  */
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
value|{					\ 	if ((p = (cast)(p == NULL ?					\ 	    malloc(size) : realloc(p, size))) == NULL)			\ 		msgq(sp, M_SYSERR, NULL);				\ }
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

end_unit

