begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1991, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)cut.h	10.5 (Berkeley) 4/3/96  */
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
name|u_int8_t
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
comment|/* 1-N: file line. */
name|size_t
name|cno
decl_stmt|;
comment|/* 0-N: file character in line. */
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
comment|/* 0-N: initial, unerasable chars. */
name|size_t
name|owrite
decl_stmt|;
comment|/* 0-N: chars to overwrite. */
name|size_t
name|R_erase
decl_stmt|;
comment|/* 0-N: 'R' erase count. */
name|size_t
name|sv_cno
decl_stmt|;
comment|/* 0-N: Saved line cursor. */
name|size_t
name|sv_len
decl_stmt|;
comment|/* 0-N: Saved line length. */
comment|/* 	 * These fields returns information from the vi text input routine. 	 * 	 * The termination condition.  Note, this field is only valid if the 	 * text input routine returns success. 	 *	TERM_BS:	User backspaced over the prompt. 	 *	TERM_CEDIT:	User entered<edit-char>. 	 *	TERM_CR:	User entered<carriage-return>; no data. 	 *	TERM_ESC:	User entered<escape>; no data. 	 *	TERM_OK:	Data available. 	 *	TERM_SEARCH:	Incremental search. 	 */
enum|enum
block|{
name|TERM_BS
block|,
name|TERM_CEDIT
block|,
name|TERM_CR
block|,
name|TERM_ESC
block|,
name|TERM_OK
block|,
name|TERM_SEARCH
block|}
name|term
enum|;
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
name|nch
parameter_list|)
value|{						\ 	CHAR_T L__name;							\ 	L__name = isupper(nch) ? tolower(nch) : (nch);			\ 	for (cbp = sp->gp->cutq.lh_first;				\ 	    cbp != NULL; cbp = cbp->q.le_next)				\ 		if (cbp->name == L__name)				\ 			break;						\ }
end_define

begin_comment
comment|/* Flags to the cut() routine. */
end_comment

begin_define
define|#
directive|define
name|CUT_LINEMODE
value|0x01
end_define

begin_comment
comment|/* Cut in line mode. */
end_comment

begin_define
define|#
directive|define
name|CUT_NUMOPT
value|0x02
end_define

begin_comment
comment|/* Numeric buffer: optional. */
end_comment

begin_define
define|#
directive|define
name|CUT_NUMREQ
value|0x04
end_define

begin_comment
comment|/* Numeric buffer: required. */
end_comment

end_unit

