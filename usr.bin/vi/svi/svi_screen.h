begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)svi_screen.h	8.38 (Berkeley) 3/15/94  */
end_comment

begin_comment
comment|/*  * Structure for mapping lines to the screen.  An SMAP is an array, with one  * structure element per screen line, which holds information describing the  * physical line which is displayed in the screen line.  The first two fields  * (lno and off) are all that are necessary to describe a line.  The rest of  * the information is useful to keep information from being re-calculated.  *  * Lno is the line number.  Off is the screen offset into the line.  For  * example, the pair 2:1 would be the first screen of line 2, and 2:2 would  * be the second.  If doing left-right scrolling, all of the offsets will be  * the same, i.e. for the second screen, 1:2, 2:2, 3:2, etc.  If doing the  * standard vi scrolling, it will be staggered, i.e. 1:1, 1:2, 1:3, 2:1, 3:1,  * etc.  *  * The SMAP is always as large as the physical screen, plus a slot for the  * info line, so that there is room to add any screen into another one at  * screen exit.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_smap
block|{
name|recno_t
name|lno
decl_stmt|;
comment|/* 1-N: Physical file line number. */
name|size_t
name|off
decl_stmt|;
comment|/* 1-N: Screen offset in the line. */
comment|/* svi_line() cache information. */
name|size_t
name|c_sboff
decl_stmt|;
comment|/* 0-N: offset of first character byte. */
name|size_t
name|c_eboff
decl_stmt|;
comment|/* 0-N: offset of  last character byte. */
name|u_char
name|c_scoff
decl_stmt|;
comment|/* 0-N: offset into the first character. */
name|u_char
name|c_eclen
decl_stmt|;
comment|/* 1-N: columns from the last character. */
name|u_char
name|c_ecsize
decl_stmt|;
comment|/* 1-N: size of the  last character. */
block|}
name|SMAP
typedef|;
end_typedef

begin_comment
comment|/* Macros to flush/test cached information. */
end_comment

begin_define
define|#
directive|define
name|SMAP_CACHE
parameter_list|(
name|smp
parameter_list|)
value|((smp)->c_ecsize != 0)
end_define

begin_define
define|#
directive|define
name|SMAP_FLUSH
parameter_list|(
name|smp
parameter_list|)
value|((smp)->c_ecsize = 0)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_svi_private
block|{
comment|/* INITIALIZED AT SCREEN CREATE. */
name|SMAP
modifier|*
name|h_smap
decl_stmt|;
comment|/* First slot of the line map. */
name|SMAP
modifier|*
name|t_smap
decl_stmt|;
comment|/*  Last slot of the line map. */
name|size_t
name|exlinecount
decl_stmt|;
comment|/* Ex overwrite count. */
name|size_t
name|extotalcount
decl_stmt|;
comment|/* Ex overwrite count. */
name|size_t
name|exlcontinue
decl_stmt|;
comment|/* Ex line continue value. */
comment|/* svi_opt_screens() cache information. */
define|#
directive|define
name|SVI_SCR_CFLUSH
parameter_list|(
name|svp
parameter_list|)
value|svp->ss_lno = OOBLNO
name|recno_t
name|ss_lno
decl_stmt|;
comment|/* 1-N: Line number. */
name|size_t
name|ss_screens
decl_stmt|;
comment|/* Return value. */
name|recno_t
name|olno
decl_stmt|;
comment|/* 1-N: old cursor file line. */
name|size_t
name|ocno
decl_stmt|;
comment|/* 0-N: old file cursor column. */
name|size_t
name|sc_col
decl_stmt|;
comment|/* 0-N: LOGICAL screen column. */
comment|/* PARTIALLY OR COMPLETELY COPIED FROM PREVIOUS SCREEN. */
name|size_t
name|srows
decl_stmt|;
comment|/* 1-N: Rows in the terminal/window. */
name|char
modifier|*
name|VB
decl_stmt|;
comment|/* Visual bell termcap string. */
define|#
directive|define
name|SVI_CUR_INVALID
value|0x001
comment|/* Cursor position is unknown. */
define|#
directive|define
name|SVI_DIVIDER
value|0x002
comment|/* Screen divider is displayed. */
define|#
directive|define
name|SVI_INFOLINE
value|0x004
comment|/* The infoline is being used by v_ntext(). */
define|#
directive|define
name|SVI_NO_VBELL
value|0x008
comment|/* No visual bell available. */
define|#
directive|define
name|SVI_SCREENDIRTY
value|0x010
comment|/* Screen needs refreshing. */
name|u_int
name|flags
decl_stmt|;
block|}
name|SVI_PRIVATE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SVP
parameter_list|(
name|sp
parameter_list|)
value|((SVI_PRIVATE *)((sp)->svi_private))
end_define

begin_define
define|#
directive|define
name|HMAP
value|(SVP(sp)->h_smap)
end_define

begin_define
define|#
directive|define
name|TMAP
value|(SVP(sp)->t_smap)
end_define

begin_define
define|#
directive|define
name|_HMAP
parameter_list|(
name|sp
parameter_list|)
value|(SVP(sp)->h_smap)
end_define

begin_define
define|#
directive|define
name|_TMAP
parameter_list|(
name|sp
parameter_list|)
value|(SVP(sp)->t_smap)
end_define

begin_comment
comment|/*  * One extra slot is always allocated for the map so that we can use  * it to do vi :colon command input; see svi_get().  */
end_comment

begin_define
define|#
directive|define
name|SIZE_HMAP
parameter_list|(
name|sp
parameter_list|)
value|(SVP(sp)->srows + 1)
end_define

begin_define
define|#
directive|define
name|O_NUMBER_FMT
value|"%7lu "
end_define

begin_comment
comment|/* O_NUMBER format, length. */
end_comment

begin_define
define|#
directive|define
name|O_NUMBER_LENGTH
value|8
end_define

begin_comment
comment|/* Columns on a screen. */
end_comment

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
value|((sp)->t_maxrows / 2)
end_define

begin_comment
comment|/* Half the screen. */
end_comment

begin_define
define|#
directive|define
name|HALFTEXT
parameter_list|(
name|sp
parameter_list|)
value|((sp)->t_rows / 2)
end_define

begin_comment
comment|/* Half the text. */
end_comment

begin_define
define|#
directive|define
name|INFOLINE
parameter_list|(
name|sp
parameter_list|)
value|((sp)->t_maxrows)
end_define

begin_comment
comment|/* Info line test, offset. */
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
value|(((smp) - HMAP) == INFOLINE(sp))
end_define

begin_comment
comment|/* Small screen test. */
end_comment

begin_define
define|#
directive|define
name|ISSMALLSCREEN
parameter_list|(
name|sp
parameter_list|)
value|((sp)->t_minrows != (sp)->t_maxrows)
end_define

begin_comment
comment|/*  * Next tab offset.  *  * !!!  * There are problems with how the historical vi handled tabs.  For example,  * by doing "set ts=3" and building lines that fold, you can get it to step  * through tabs as if they were spaces and move inserted characters to new  * positions when<esc> is entered.  I think that nvi does tabs correctly,  * but there may be some historical incompatibilities.  */
end_comment

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

begin_comment
comment|/* Move in a screen (absolute), and fail if it doesn't work. */
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
value|{						\ 	if (move(lno, cno) == ERR) {					\ 		msgq(sp, M_ERR,						\ 		    "Error: %s/%d: move:l(%u), c(%u), abs.",		\ 		    tail(__FILE__), __LINE__, lno, cno);		\ 		return (1);						\ 	}								\ }
end_define

begin_comment
comment|/* Move in a window, and fail if it doesn't work. */
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
value|{						\ 	size_t __lno = (sp)->woff + (lno);				\ 	if (move(__lno, cno) == ERR) {					\ 		msgq(sp, M_ERR,						\ 		    "Error: %s/%d: move:l(%u), c(%u), o(%u).",		\ 		    tail(__FILE__), __LINE__, lno, cno, sp->woff);	\ 		return (1);						\ 	}								\ }
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
name|str
parameter_list|,
name|len
parameter_list|)
value|{						\ 	if (addnstr(str, len) == ERR) {					\ 		int __x, __y;						\ 		getyx(stdscr, __y, __x);				\ 		msgq(sp, M_ERR, "Error: %s/%d: addnstr: (%d/%u).",	\ 		    tail(__FILE__), __LINE__, __y, __x);		\ 		return (1);						\ 	}								\ }
end_define

begin_comment
comment|/* Add a string. */
end_comment

begin_define
define|#
directive|define
name|ADDSTR
parameter_list|(
name|str
parameter_list|)
value|{							\ 	if (addstr(str) == ERR) {					\ 		int __x, __y;						\ 		getyx(stdscr, __y, __x);				\ 		msgq(sp, M_ERR, "Error: %s/%d: addstr: (%d/%u).",	\ 		    tail(__FILE__), __LINE__, __y, __x);		\ 		return (1);						\ 	}								\ }
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
name|svi_bg
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
name|svi_busy
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|char
specifier|const
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
name|svi_cm_public
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
name|int
name|svi_column
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|confirm
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
name|svi_clear
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
name|svi_crel
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|long
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
name|svi_fg
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|CHAR_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|input
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
name|TEXTH
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
name|svi_optchange
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
name|svi_rabs
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|long
operator|,
expr|enum
name|adjust
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|svi_rcm
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
name|svi_screen_copy
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_screen_edit
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
name|svi_screen_end
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
name|MARK
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
name|svi_split
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|ARGS
operator|*
index|[]
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

begin_decl_stmt
name|int
name|svi_swap
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|SCR
operator|*
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Private routines. */
end_comment

begin_decl_stmt
name|size_t
name|svi_cm_private
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
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svi_curses_end
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
name|svi_curses_init
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
name|svi_join
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|SCR
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|svi_keypad
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
name|int
name|svi_number
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
name|svi_opt_screens
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
name|svi_paint
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
name|svi_putchar
name|__P
argument_list|(
operator|(
name|int
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
name|char
operator|*
operator|,
name|size_t
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
name|svi_sm_cursor
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
operator|*
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

begin_comment
comment|/* Private debugging routines. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

