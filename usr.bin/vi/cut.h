begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cut.h	8.13 (Berkeley) 3/16/94  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_texth
name|TEXTH
typedef|;
end_typedef

begin_comment
comment|/* TEXT list head structure. */
end_comment

begin_expr_stmt
name|CIRCLEQ_HEAD
argument_list|(
name|_texth
argument_list|,
name|_text
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Cut buffers. */
end_comment

begin_struct
struct|struct
name|_cb
block|{
name|LIST_ENTRY
argument_list|(
argument|_cb
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of cut buffers. */
name|TEXTH
name|textq
decl_stmt|;
comment|/* Linked list of TEXT structures. */
name|CHAR_T
name|name
decl_stmt|;
comment|/* Cut buffer name. */
name|size_t
name|len
decl_stmt|;
comment|/* Total length of cut text. */
define|#
directive|define
name|CB_LMODE
value|0x01
comment|/* Cut was in line mode. */
name|u_char
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Lines/blocks of text. */
end_comment

begin_struct
struct|struct
name|_text
block|{
comment|/* Text: a linked list of lines. */
name|CIRCLEQ_ENTRY
argument_list|(
argument|_text
argument_list|)
name|q
expr_stmt|;
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
name|owrite
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
struct|;
end_struct

begin_comment
comment|/*  * Get named buffer 'name'.  * Translate upper-case buffer names to lower-case buffer names.  */
end_comment

begin_define
define|#
directive|define
name|CBNAME
parameter_list|(
name|sp
parameter_list|,
name|cbp
parameter_list|,
name|name
parameter_list|)
value|{						\ 	CHAR_T __name;							\ 	__name = isupper(name) ? tolower(name) : (name);		\ 	for (cbp = sp->gp->cutq.lh_first;				\ 	    cbp != NULL; cbp = cbp->q.le_next)				\ 		if (cbp->name == __name)				\ 			break;						\ }
end_define

begin_define
define|#
directive|define
name|CUT_DELETE
value|0x01
end_define

begin_comment
comment|/* Delete (rotate numeric buffers). */
end_comment

begin_define
define|#
directive|define
name|CUT_LINEMODE
value|0x02
end_define

begin_comment
comment|/* Cut in line mode. */
end_comment

begin_decl_stmt
name|int
name|cut
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|CB
operator|*
operator|,
name|CHAR_T
operator|*
operator|,
name|MARK
operator|*
operator|,
name|MARK
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
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|CB
operator|*
operator|,
name|CHAR_T
operator|*
operator|,
name|MARK
operator|*
operator|,
name|MARK
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
name|TEXT
modifier|*
name|text_init
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
name|size_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|text_lfree
name|__P
argument_list|(
operator|(
name|TEXTH
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

