begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cut.h	8.1 (Berkeley) 6/9/93  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cb
block|{
comment|/* Cut buffer. */
name|struct
name|_hdr
name|txthdr
decl_stmt|;
comment|/* Linked list of TEXT structures. */
name|u_long
name|len
decl_stmt|;
comment|/* Total length of cut text. */
define|#
directive|define
name|CB_LMODE
value|0x01
comment|/* Line mode. */
name|u_char
name|flags
decl_stmt|;
block|}
name|CB
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_text
block|{
comment|/* Text: a linked list of lines. */
name|struct
name|_text
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
comment|/* Linked list of text structures. */
name|char
modifier|*
name|lb
decl_stmt|;
comment|/* Line buffer. */
name|size_t
name|lb_len
decl_stmt|;
comment|/* Line buffer length. */
name|size_t
name|len
decl_stmt|;
comment|/* Line length. */
comment|/* These fields are used by the vi text input routine. */
name|recno_t
name|lno
decl_stmt|;
comment|/* 1-N: line number. */
name|size_t
name|ai
decl_stmt|;
comment|/* 0-N: autoindent bytes. */
name|size_t
name|insert
decl_stmt|;
comment|/* 0-N: bytes to insert (push). */
name|size_t
name|offset
decl_stmt|;
comment|/* 0-N: initial, unerasable bytes. */
name|size_t
name|overwrite
decl_stmt|;
comment|/* 0-N: bytes to overwrite. */
comment|/* These fields are used by the ex text input routine. */
name|u_char
modifier|*
name|wd
decl_stmt|;
comment|/* Width buffer. */
name|size_t
name|wd_len
decl_stmt|;
comment|/* Width buffer length. */
block|}
name|TEXT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OOBCB
value|-1
end_define

begin_comment
comment|/* Out-of-band cut buffer name. */
end_comment

begin_define
define|#
directive|define
name|DEFCB
value|UCHAR_MAX + 1
end_define

begin_comment
comment|/* Default cut buffer. */
end_comment

begin_comment
comment|/* Vi: cut buffer to use. */
end_comment

begin_define
define|#
directive|define
name|VICB
parameter_list|(
name|vp
parameter_list|)
value|((vp)->buffer == OOBCB ? DEFCB : (vp)->buffer)
end_define

begin_comment
comment|/* Check to see if a cut buffer has contents. */
end_comment

begin_define
define|#
directive|define
name|CBEMPTY
parameter_list|(
name|sp
parameter_list|,
name|buf
parameter_list|,
name|cb
parameter_list|)
value|{						\ 	if ((cb)->txthdr.next == NULL ||				\ 	    (cb)->txthdr.next ==&(cb)->txthdr) {			\ 		if (buf == DEFCB)					\ 			msgq(sp, M_ERR,					\ 			    "The default buffer is empty.");		\ 		else							\ 			msgq(sp, M_ERR,					\ 			    "Buffer %s is empty.", charname(sp, buf));	\ 		return (1);						\ 	}								\ }
end_define

begin_comment
comment|/*  * Check a buffer name for validity.  * Translate upper-case buffer names to lower-case buffer names.  */
end_comment

begin_define
define|#
directive|define
name|CBNAME
parameter_list|(
name|sp
parameter_list|,
name|bname
parameter_list|,
name|cb
parameter_list|)
value|{						\ 	if ((bname)> sizeof(sp->cuts) - 1) {				\ 		msgq(sp, M_ERR, "Invalid cut buffer name.");		\ 		return (1);						\ 	}								\ 	if (isupper(bname))						\ 		(bname) = tolower(bname);				\ 	cb =&sp->cuts[bname];						\ }
end_define

begin_comment
comment|/* Cut routines. */
end_comment

begin_decl_stmt
name|int
name|cut
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
name|int
operator|,
expr|struct
name|_mark
operator|*
operator|,
expr|struct
name|_mark
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|delete
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
expr|struct
name|_mark
operator|*
operator|,
expr|struct
name|_mark
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|put
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|,
name|int
operator|,
expr|struct
name|_mark
operator|*
operator|,
expr|struct
name|_mark
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|text_free
name|__P
argument_list|(
operator|(
name|TEXT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|hdr_text_free
name|__P
argument_list|(
operator|(
expr|struct
name|_hdr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TEXT
modifier|*
name|text_init
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

