begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)svi_screen.h	8.1 (Berkeley) 6/9/93  */
end_comment

begin_comment
comment|/*  * Macros for the O_NUMBER format and length, plus macro for the number  * of columns on a screen.  */
end_comment

begin_define
define|#
directive|define
name|O_NUMBER_FMT
value|"%7lu "
end_define

begin_define
define|#
directive|define
name|O_NUMBER_LENGTH
value|8
end_define

begin_define
define|#
directive|define
name|SCREEN_COLS
parameter_list|(
name|sp
parameter_list|)
define|\
value|((O_ISSET(sp, O_NUMBER) ? (sp)->cols - O_NUMBER_LENGTH : (sp)->cols))
end_define

begin_define
define|#
directive|define
name|HALFSCREEN
parameter_list|(
name|sp
parameter_list|)
value|((sp)->t_rows / 2)
end_define

begin_comment
comment|/* Half a screen. */
end_comment

begin_define
define|#
directive|define
name|INFOLINE
parameter_list|(
name|sp
parameter_list|)
value|((sp)->rows - 1)
end_define

begin_comment
comment|/* Info line offset. */
end_comment

begin_comment
comment|/* Info line test. */
end_comment

begin_define
define|#
directive|define
name|ISINFOLINE
parameter_list|(
name|sp
parameter_list|,
name|smp
parameter_list|)
value|(((smp) - (sp)->h_smap) == (sp)->rows - 1)
end_define

begin_define
define|#
directive|define
name|TAB_OFF
parameter_list|(
name|sp
parameter_list|,
name|c
parameter_list|)
value|(O_VAL(sp, O_TABSTOP) - (c) % O_VAL(sp, O_TABSTOP))
end_define

begin_define
define|#
directive|define
name|HMAP
value|(sp->h_smap)
end_define

begin_comment
comment|/* Head of line map. */
end_comment

begin_define
define|#
directive|define
name|TMAP
value|(sp->t_smap)
end_define

begin_comment
comment|/* Tail of line map. */
end_comment

begin_comment
comment|/* Absolute move, and fail if it doesn't work. */
end_comment

begin_define
define|#
directive|define
name|MOVEA
parameter_list|(
name|sp
parameter_list|,
name|lno
parameter_list|,
name|cno
parameter_list|)
value|{						\ 	if (move(lno, cno) == ERR) {					\ 		msgq(sp, M_ERR, "Error: %s/%d: move(%u, %u).",		\ 		    tail(__FILE__), __LINE__, lno, cno);		\ 		return (1);						\ 	}								\ }
end_define

begin_comment
comment|/* Move, and fail if it doesn't work. */
end_comment

begin_define
define|#
directive|define
name|MOVE
parameter_list|(
name|sp
parameter_list|,
name|lno
parameter_list|,
name|cno
parameter_list|)
value|{						\ 	size_t __lno = sp->s_off + lno;					\ 	if (move(__lno, cno) == ERR) {					\ 		msgq(sp, M_ERR, "Error: %s/%d: move(%u/%u, %u).",	\ 		    tail(__FILE__), __LINE__, sp->s_off, lno, cno);	\ 		return (1);						\ 	}								\ }
end_define

begin_comment
comment|/* Add a character. */
end_comment

begin_define
define|#
directive|define
name|ADDCH
parameter_list|(
name|ch
parameter_list|)
value|{							\ 	int __ch = (ch);						\ 	ADDNSTR(cname[__ch].name, cname[__ch].len);			\ }
end_define

begin_comment
comment|/* Add a string len bytes long. */
end_comment

begin_define
define|#
directive|define
name|ADDNSTR
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|)
value|{						\ 	if (addnstr(s, len) == ERR) {					\ 		int __x, __y;						\ 		getyx(stdscr, __y, __x);				\ 		msgq(sp, M_ERR, "Error: %s/%d: addnstr: (%d/%u).",	\ 		    tail(__FILE__), __LINE__, __y, __x);		\ 		return (1);						\ 	}								\ }
end_define

begin_comment
comment|/* Add a string. */
end_comment

begin_define
define|#
directive|define
name|ADDSTR
parameter_list|(
name|s
parameter_list|)
value|{							\ 	if (addstr(s) == ERR) {						\ 		int __x, __y;						\ 		getyx(stdscr, __y, __x);				\ 		msgq(sp, M_ERR, "Error: %s/%d: addstr: (%d/%u).",	\ 		    tail(__FILE__), __LINE__, __y, __x);		\ 		return (1);						\ 	}								\ }
end_define

begin_comment
comment|/* Public routines. */
end_comment

begin_decl_stmt
name|void
name|svi_bell
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
name|svi_busy_cursor
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
name|svi_change
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
expr|enum
name|operation
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|svi_chposition
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|confirmation
name|svi_confirm
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_ex_cmd
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
expr|struct
name|_excmdarg
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
name|svi_ex_run
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_ex_write
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_get
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|HDR
operator|*
operator|,
name|int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_split
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
name|size_t
name|svi_relative
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_sm_down
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
name|recno_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_sm_fill
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
expr|enum
name|position
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_sm_position
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
operator|*
operator|,
name|u_long
operator|,
expr|enum
name|position
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_sm_up
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
name|recno_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_refresh
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
name|svi_suspend
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Private routines. */
end_comment

begin_decl_stmt
name|int
name|svi_deleteln
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
name|svi_divider
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
name|svi_init
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
name|svi_insertln
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
name|svi_line
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|SMAP
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|,
name|size_t
operator|*
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|svi_lrelative
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|svi_ncols
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|u_char
operator|*
operator|,
name|size_t
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|svi_screens
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
name|svi_sm_1down
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
name|svi_sm_1up
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
name|svi_sm_delete
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_sm_insert
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_sm_next
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|SMAP
operator|*
operator|,
name|SMAP
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|recno_t
name|svi_sm_nlines
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|SMAP
operator|*
operator|,
name|recno_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_sm_prev
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|SMAP
operator|*
operator|,
name|SMAP
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_sm_reset
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Private debugging routines. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|void
name|svi_gdbmap
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
name|svi_gdbrefresh
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|svi_sm_dmap
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

