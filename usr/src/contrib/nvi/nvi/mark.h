begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mark.h	8.1 (Berkeley) 6/9/93  */
end_comment

begin_comment
comment|/*  * The MARK structure defines a position in the file.  Because of the different  * interfaces used by the db(3) package, curses, and users, the line number is  * 1 based, while the column number is 0 based.  Additionally, it is known that  * the out-of-band line number is less than any legal line number.  The line  * number is of type recno_t, as that's the underlying type of the database.  * The column number is of type size_t so that we can malloc a line.  */
end_comment

begin_typedef
typedef|typedef
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
name|MARK
typedef|;
end_typedef

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
name|void
name|mark_delete
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
name|MARK
modifier|*
name|mark_get
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
expr|struct
name|_scr
operator|*
operator|,
expr|struct
name|_exf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mark_insert
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
name|MARK
operator|*
operator|,
name|MARK
operator|*
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
name|MARK
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

