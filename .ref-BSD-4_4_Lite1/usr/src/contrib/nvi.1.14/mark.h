begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mark.h	8.8 (Berkeley) 3/16/94  */
end_comment

begin_comment
comment|/*  * The MARK and LMARK structures define positions in the file.  There are  * two structures because the mark subroutines are the only places where  * anything cares about something other than line and column.  *  * Because of the different interfaces used by the db(3) package, curses,  * and users, the line number is 1 based and the column number is 0 based.  * Additionally, it is known that the out-of-band line number is less than  * any legal line number.  The line number is of type recno_t, as that's  * the underlying type of the database.  The column number is of type size_t,  * guaranteeing that we can malloc a line.  */
end_comment

begin_struct
struct|struct
name|_mark
block|{
define|#
directive|define
name|OOBLNO
value|0
comment|/* Out-of-band line number. */
name|recno_t
name|lno
decl_stmt|;
comment|/* Line number. */
name|size_t
name|cno
decl_stmt|;
comment|/* Column number. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_lmark
block|{
name|LIST_ENTRY
argument_list|(
argument|_lmark
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of marks. */
name|recno_t
name|lno
decl_stmt|;
comment|/* Line number. */
name|size_t
name|cno
decl_stmt|;
comment|/* Column number. */
name|CHAR_T
name|name
decl_stmt|;
comment|/* Mark name. */
define|#
directive|define
name|MARK_DELETED
value|0x01
comment|/* Mark was deleted. */
define|#
directive|define
name|MARK_USERSET
value|0x02
comment|/* User set this mark. */
name|u_char
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ABSMARK1
value|'\''
end_define

begin_comment
comment|/* Absolute mark name. */
end_comment

begin_define
define|#
directive|define
name|ABSMARK2
value|'`'
end_define

begin_comment
comment|/* Absolute mark name. */
end_comment

begin_comment
comment|/* Mark routines. */
end_comment

begin_decl_stmt
name|int
name|mark_end
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mark_get
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|ARG_CHAR_T
operator|,
name|MARK
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mark_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mark_insdel
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
expr|enum
name|operation
operator|,
name|recno_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mark_set
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|ARG_CHAR_T
operator|,
name|MARK
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

