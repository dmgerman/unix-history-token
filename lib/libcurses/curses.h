begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)curses.h	8.3 (Berkeley) 7/27/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CURSES_H_
end_ifndef

begin_define
define|#
directive|define
name|_CURSES_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_VA_LIST_
end_ifndef

begin_define
define|#
directive|define
name|_BSD_VA_LIST_
value|char *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following #defines and #includes are present for backward  * compatibility only.  They should not be used in future code.  *  * START BACKWARD COMPATIBILITY ONLY.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CURSES_PRIVATE
end_ifndef

begin_comment
comment|/* This stuff needed for those pgms which include<sgtty.h> */
end_comment

begin_comment
comment|/* Undef things manually to avoid redefinition              */
end_comment

begin_undef
undef|#
directive|undef
name|USE_OLD_TTY
end_undef

begin_undef
undef|#
directive|undef
name|B0
end_undef

begin_undef
undef|#
directive|undef
name|B50
end_undef

begin_undef
undef|#
directive|undef
name|B75
end_undef

begin_undef
undef|#
directive|undef
name|B110
end_undef

begin_undef
undef|#
directive|undef
name|B134
end_undef

begin_undef
undef|#
directive|undef
name|B150
end_undef

begin_undef
undef|#
directive|undef
name|B200
end_undef

begin_undef
undef|#
directive|undef
name|B300
end_undef

begin_undef
undef|#
directive|undef
name|B600
end_undef

begin_undef
undef|#
directive|undef
name|B1200
end_undef

begin_undef
undef|#
directive|undef
name|B1800
end_undef

begin_undef
undef|#
directive|undef
name|B2400
end_undef

begin_undef
undef|#
directive|undef
name|B4800
end_undef

begin_undef
undef|#
directive|undef
name|B9600
end_undef

begin_undef
undef|#
directive|undef
name|EXTA
end_undef

begin_undef
undef|#
directive|undef
name|EXTB
end_undef

begin_undef
undef|#
directive|undef
name|B57600
end_undef

begin_undef
undef|#
directive|undef
name|B115200
end_undef

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl_compat.h>
end_include

begin_comment
comment|/* For sgttyb and related */
end_comment

begin_define
define|#
directive|define
name|bool
value|char
end_define

begin_define
define|#
directive|define
name|reg
value|register
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_puts
parameter_list|(
name|s
parameter_list|)
value|tputs(s, 0, __cputchar)
end_define

begin_comment
comment|/* Old-style terminal modes access. */
end_comment

begin_define
define|#
directive|define
name|baudrate
parameter_list|()
value|(cfgetospeed(&__baset))
end_define

begin_define
define|#
directive|define
name|crmode
parameter_list|()
value|cbreak()
end_define

begin_define
define|#
directive|define
name|erasechar
parameter_list|()
value|(__baset.c_cc[VERASE])
end_define

begin_define
define|#
directive|define
name|killchar
parameter_list|()
value|(__baset.c_cc[VKILL])
end_define

begin_define
define|#
directive|define
name|nocrmode
parameter_list|()
value|nocbreak()
end_define

begin_comment
comment|/* WINDOW structure members name compatibility */
end_comment

begin_define
define|#
directive|define
name|_curx
value|curx
end_define

begin_define
define|#
directive|define
name|_cury
value|cury
end_define

begin_define
define|#
directive|define
name|_begx
value|begx
end_define

begin_define
define|#
directive|define
name|_begy
value|begy
end_define

begin_define
define|#
directive|define
name|_maxx
value|maxx
end_define

begin_define
define|#
directive|define
name|_maxy
value|maxy
end_define

begin_define
define|#
directive|define
name|_tty
value|__baset
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CURSES_PRIVATE */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|GT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Gtty indicates tabs. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|NONL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Term can't hack LF doing a CR. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|UPPERCASE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal is uppercase only. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|My_term
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use Def_term regardless. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Def_term
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default terminal type. */
end_comment

begin_comment
comment|/* Termcap capabilities. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|AM
decl_stmt|,
name|BS
decl_stmt|,
name|CA
decl_stmt|,
name|DA
decl_stmt|,
name|EO
decl_stmt|,
name|HC
decl_stmt|,
name|IN
decl_stmt|,
name|MI
decl_stmt|,
name|MS
decl_stmt|,
name|NC
decl_stmt|,
name|NS
decl_stmt|,
name|OS
decl_stmt|,
name|PC
decl_stmt|,
name|UL
decl_stmt|,
name|XB
decl_stmt|,
name|XN
decl_stmt|,
name|XT
decl_stmt|,
name|XS
decl_stmt|,
name|XX
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|AL
decl_stmt|,
modifier|*
name|BC
decl_stmt|,
modifier|*
name|BT
decl_stmt|,
modifier|*
name|CD
decl_stmt|,
modifier|*
name|CE
decl_stmt|,
modifier|*
name|CL
decl_stmt|,
modifier|*
name|CM
decl_stmt|,
modifier|*
name|CR
decl_stmt|,
modifier|*
name|CS
decl_stmt|,
modifier|*
name|DC
decl_stmt|,
modifier|*
name|DL
decl_stmt|,
modifier|*
name|DM
decl_stmt|,
modifier|*
name|DO
decl_stmt|,
modifier|*
name|ED
decl_stmt|,
modifier|*
name|EI
decl_stmt|,
modifier|*
name|K0
decl_stmt|,
modifier|*
name|K1
decl_stmt|,
modifier|*
name|K2
decl_stmt|,
modifier|*
name|K3
decl_stmt|,
modifier|*
name|K4
decl_stmt|,
modifier|*
name|K5
decl_stmt|,
modifier|*
name|K6
decl_stmt|,
modifier|*
name|K7
decl_stmt|,
modifier|*
name|K8
decl_stmt|,
modifier|*
name|K9
decl_stmt|,
modifier|*
name|HO
decl_stmt|,
modifier|*
name|IC
decl_stmt|,
modifier|*
name|IM
decl_stmt|,
modifier|*
name|IP
decl_stmt|,
modifier|*
name|KD
decl_stmt|,
modifier|*
name|KE
decl_stmt|,
modifier|*
name|KH
decl_stmt|,
modifier|*
name|KL
decl_stmt|,
modifier|*
name|KR
decl_stmt|,
modifier|*
name|KS
decl_stmt|,
modifier|*
name|KU
decl_stmt|,
modifier|*
name|LL
decl_stmt|,
modifier|*
name|MA
decl_stmt|,
modifier|*
name|ND
decl_stmt|,
modifier|*
name|NL
decl_stmt|,
modifier|*
name|RC
decl_stmt|,
modifier|*
name|SC
decl_stmt|,
modifier|*
name|SE
decl_stmt|,
modifier|*
name|SF
decl_stmt|,
modifier|*
name|SO
decl_stmt|,
modifier|*
name|SR
decl_stmt|,
modifier|*
name|TA
decl_stmt|,
modifier|*
name|TE
decl_stmt|,
modifier|*
name|TI
decl_stmt|,
modifier|*
name|UC
decl_stmt|,
modifier|*
name|UE
decl_stmt|,
modifier|*
name|UP
decl_stmt|,
modifier|*
name|US
decl_stmt|,
modifier|*
name|VB
decl_stmt|,
modifier|*
name|VS
decl_stmt|,
modifier|*
name|VE
decl_stmt|,
modifier|*
name|al
decl_stmt|,
modifier|*
name|dl
decl_stmt|,
modifier|*
name|sf
decl_stmt|,
modifier|*
name|sr
decl_stmt|,
modifier|*
name|AL_PARM
decl_stmt|,
modifier|*
name|DL_PARM
decl_stmt|,
modifier|*
name|UP_PARM
decl_stmt|,
modifier|*
name|DOWN_PARM
decl_stmt|,
modifier|*
name|LEFT_PARM
decl_stmt|,
modifier|*
name|RIGHT_PARM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* END BACKWARD COMPATIBILITY ONLY. */
end_comment

begin_comment
comment|/* 8-bit ASCII characters. */
end_comment

begin_define
define|#
directive|define
name|unctrl
parameter_list|(
name|c
parameter_list|)
value|__unctrl[(c)& 0xff]
end_define

begin_define
define|#
directive|define
name|unctrllen
parameter_list|(
name|ch
parameter_list|)
value|__unctrllen[(ch)& 0xff]
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__unctrl
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Control strings. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|__unctrllen
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Control strings length. */
end_comment

begin_comment
comment|/*  * A window an array of __LINE structures pointed to by the 'lines' pointer.  * A line is an array of __LDATA structures pointed to by the 'line' pointer.  *  * IMPORTANT: the __LDATA structure must NOT induce any padding, so if new  * fields are added -- padding fields with *constant values* should ensure  * that the compiler will not generate any padding when storing an array of  *  __LDATA structures.  This is to enable consistent use of memcmp, and memcpy  * for comparing and copying arrays.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|ch
decl_stmt|;
comment|/* the actual character */
define|#
directive|define
name|__STANDOUT
value|0x01
comment|/* Added characters are standout. */
name|char
name|attr
decl_stmt|;
comment|/* attributes of character */
block|}
name|__LDATA
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__LDATASIZE
value|(sizeof(__LDATA))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
define|#
directive|define
name|__ISDIRTY
value|0x01
comment|/* Line is dirty. */
define|#
directive|define
name|__ISPASTEOL
value|0x02
comment|/* Cursor is past end of line */
define|#
directive|define
name|__FORCEPAINT
value|0x04
comment|/* Force a repaint of the line */
name|u_int
name|flags
decl_stmt|;
name|u_int
name|hash
decl_stmt|;
comment|/* Hash value for the line. */
name|size_t
modifier|*
name|firstchp
decl_stmt|,
modifier|*
name|lastchp
decl_stmt|;
comment|/* First and last chngd columns ptrs */
name|size_t
name|firstch
decl_stmt|,
name|lastch
decl_stmt|;
comment|/* First and last changed columns. */
name|__LDATA
modifier|*
name|line
decl_stmt|;
comment|/* Pointer to the line text. */
block|}
name|__LINE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|__window
block|{
comment|/* Window structure. */
name|struct
name|__window
modifier|*
name|nextp
decl_stmt|,
modifier|*
name|orig
decl_stmt|;
comment|/* Subwindows list and parent. */
name|size_t
name|begy
decl_stmt|,
name|begx
decl_stmt|;
comment|/* Window home. */
name|size_t
name|cury
decl_stmt|,
name|curx
decl_stmt|;
comment|/* Current x, y coordinates. */
name|size_t
name|maxy
decl_stmt|,
name|maxx
decl_stmt|;
comment|/* Maximum values for curx, cury. */
name|short
name|ch_off
decl_stmt|;
comment|/* x offset for firstch/lastch. */
name|__LINE
modifier|*
modifier|*
name|lines
decl_stmt|;
comment|/* Array of pointers to the lines */
name|__LINE
modifier|*
name|lspace
decl_stmt|;
comment|/* line space (for cleanup) */
name|__LDATA
modifier|*
name|wspace
decl_stmt|;
comment|/* window space (for cleanup) */
define|#
directive|define
name|__ENDLINE
value|0x001
comment|/* End of screen. */
define|#
directive|define
name|__FLUSH
value|0x002
comment|/* Fflush(stdout) after refresh. */
define|#
directive|define
name|__FULLWIN
value|0x004
comment|/* Window is a screen. */
define|#
directive|define
name|__IDLINE
value|0x008
comment|/* Insert/delete sequences. */
define|#
directive|define
name|__SCROLLWIN
value|0x010
comment|/* Last char will scroll window. */
define|#
directive|define
name|__SCROLLOK
value|0x020
comment|/* Scrolling ok. */
define|#
directive|define
name|__CLEAROK
value|0x040
comment|/* Clear on next refresh. */
define|#
directive|define
name|__WSTANDOUT
value|0x080
comment|/* Standout window */
define|#
directive|define
name|__LEAVEOK
value|0x100
comment|/* If curser left */
define|#
directive|define
name|__FULLLINE
value|0x200
comment|/* Line width = terminal width. */
name|u_int
name|flags
decl_stmt|;
block|}
name|WINDOW
typedef|;
end_typedef

begin_comment
comment|/* Curses external declarations. */
end_comment

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|curscr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current screen. */
end_comment

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|stdscr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Standard screen. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|termios
name|SGTTY
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|SGTTY
name|__orig_termios
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal state before curses */
end_comment

begin_decl_stmt
specifier|extern
name|SGTTY
name|__baset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Our base terminal state */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__tcaction
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If terminal hardware set. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__tty_fileno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal file descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|COLS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Columns on the screen. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|LINES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lines on the screen. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ttytype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Full name of current terminal. */
end_comment

begin_define
define|#
directive|define
name|ERR
value|(0)
end_define

begin_comment
comment|/* Error return. */
end_comment

begin_define
define|#
directive|define
name|OK
value|(1)
end_define

begin_comment
comment|/* Success return. */
end_comment

begin_comment
comment|/* Standard screen pseudo functions. */
end_comment

begin_define
define|#
directive|define
name|addbytes
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|__waddbytes(stdscr, s, n, 0)
end_define

begin_define
define|#
directive|define
name|addch
parameter_list|(
name|ch
parameter_list|)
value|waddch(stdscr, ch)
end_define

begin_define
define|#
directive|define
name|addnstr
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|waddnstr(stdscr, s, n)
end_define

begin_define
define|#
directive|define
name|addstr
parameter_list|(
name|s
parameter_list|)
value|__waddbytes(stdscr, s, strlen(s), 0)
end_define

begin_define
define|#
directive|define
name|clear
parameter_list|()
value|wclear(stdscr)
end_define

begin_define
define|#
directive|define
name|clrtobot
parameter_list|()
value|wclrtobot(stdscr)
end_define

begin_define
define|#
directive|define
name|clrtoeol
parameter_list|()
value|wclrtoeol(stdscr)
end_define

begin_define
define|#
directive|define
name|delch
parameter_list|()
value|wdelch(stdscr)
end_define

begin_define
define|#
directive|define
name|deleteln
parameter_list|()
value|wdeleteln(stdscr)
end_define

begin_define
define|#
directive|define
name|erase
parameter_list|()
value|werase(stdscr)
end_define

begin_define
define|#
directive|define
name|getch
parameter_list|()
value|wgetch(stdscr)
end_define

begin_define
define|#
directive|define
name|getstr
parameter_list|(
name|s
parameter_list|)
value|wgetstr(stdscr, s)
end_define

begin_define
define|#
directive|define
name|inch
parameter_list|()
value|winch(stdscr)
end_define

begin_define
define|#
directive|define
name|insch
parameter_list|(
name|ch
parameter_list|)
value|winsch(stdscr, ch)
end_define

begin_define
define|#
directive|define
name|insertln
parameter_list|()
value|winsertln(stdscr)
end_define

begin_define
define|#
directive|define
name|move
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
value|wmove(stdscr, y, x)
end_define

begin_define
define|#
directive|define
name|refresh
parameter_list|()
value|wrefresh(stdscr)
end_define

begin_define
define|#
directive|define
name|standend
parameter_list|()
value|wstandend(stdscr)
end_define

begin_define
define|#
directive|define
name|standout
parameter_list|()
value|wstandout(stdscr)
end_define

begin_define
define|#
directive|define
name|waddbytes
parameter_list|(
name|w
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|__waddbytes(w, s, n, 0)
end_define

begin_define
define|#
directive|define
name|waddstr
parameter_list|(
name|w
parameter_list|,
name|s
parameter_list|)
value|__waddbytes(w, s, strlen(s), 0)
end_define

begin_comment
comment|/* Standard screen plus movement pseudo functions. */
end_comment

begin_define
define|#
directive|define
name|mvaddbytes
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|mvwaddbytes(stdscr, y, x, s, n)
end_define

begin_define
define|#
directive|define
name|mvaddch
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|ch
parameter_list|)
value|mvwaddch(stdscr, y, x, ch)
end_define

begin_define
define|#
directive|define
name|mvaddnstr
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|mvwaddnstr(stdscr, y, x, s, n)
end_define

begin_define
define|#
directive|define
name|mvaddstr
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
value|mvwaddstr(stdscr, y, x, s)
end_define

begin_define
define|#
directive|define
name|mvdelch
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
value|mvwdelch(stdscr, y, x)
end_define

begin_define
define|#
directive|define
name|mvgetch
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
value|mvwgetch(stdscr, y, x)
end_define

begin_define
define|#
directive|define
name|mvgetstr
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
value|mvwgetstr(stdscr, y, x, s)
end_define

begin_define
define|#
directive|define
name|mvinch
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
value|mvwinch(stdscr, y, x)
end_define

begin_define
define|#
directive|define
name|mvinsch
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|c
parameter_list|)
value|mvwinsch(stdscr, y, x, c)
end_define

begin_define
define|#
directive|define
name|mvwaddbytes
parameter_list|(
name|w
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
define|\
value|(wmove(w, y, x) == ERR ? ERR : __waddbytes(w, s, n, 0))
end_define

begin_define
define|#
directive|define
name|mvwaddch
parameter_list|(
name|w
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|ch
parameter_list|)
define|\
value|(wmove(w, y, x) == ERR ? ERR : waddch(w, ch))
end_define

begin_define
define|#
directive|define
name|mvwaddnstr
parameter_list|(
name|w
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
define|\
value|(wmove(w, y, x) == ERR ? ERR : waddnstr(w, s, n))
end_define

begin_define
define|#
directive|define
name|mvwaddstr
parameter_list|(
name|w
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
define|\
value|(wmove(w, y, x) == ERR ? ERR : __waddbytes(w, s, strlen(s), 0))
end_define

begin_define
define|#
directive|define
name|mvwdelch
parameter_list|(
name|w
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|)
define|\
value|(wmove(w, y, x) == ERR ? ERR : wdelch(w))
end_define

begin_define
define|#
directive|define
name|mvwgetch
parameter_list|(
name|w
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|)
define|\
value|(wmove(w, y, x) == ERR ? ERR : wgetch(w))
end_define

begin_define
define|#
directive|define
name|mvwgetstr
parameter_list|(
name|w
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
define|\
value|(wmove(w, y, x) == ERR ? ERR : wgetstr(w, s))
end_define

begin_define
define|#
directive|define
name|mvwinch
parameter_list|(
name|w
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|)
define|\
value|(wmove(w, y, x) == ERR ? ERR : winch(w))
end_define

begin_define
define|#
directive|define
name|mvwinsch
parameter_list|(
name|w
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|c
parameter_list|)
define|\
value|(wmove(w, y, x) == ERR ? ERR : winsch(w, c))
end_define

begin_comment
comment|/* Psuedo functions. */
end_comment

begin_define
define|#
directive|define
name|clearok
parameter_list|(
name|w
parameter_list|,
name|bf
parameter_list|)
define|\
value|((bf) ? ((w)->flags |= __CLEAROK) : ((w)->flags&= ~__CLEAROK))
end_define

begin_define
define|#
directive|define
name|flushok
parameter_list|(
name|w
parameter_list|,
name|bf
parameter_list|)
define|\
value|((bf) ? ((w)->flags |= __FLUSH) : ((w)->flags&= ~__FLUSH))
end_define

begin_define
define|#
directive|define
name|getyx
parameter_list|(
name|w
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|)
define|\
value|(y) = (w)->cury, (x) = (w)->curx
end_define

begin_define
define|#
directive|define
name|leaveok
parameter_list|(
name|w
parameter_list|,
name|bf
parameter_list|)
define|\
value|((bf) ? ((w)->flags |= __LEAVEOK) : ((w)->flags&= ~__LEAVEOK))
end_define

begin_define
define|#
directive|define
name|scrollok
parameter_list|(
name|w
parameter_list|,
name|bf
parameter_list|)
define|\
value|((bf) ? ((w)->flags |= __SCROLLOK) : ((w)->flags&= ~__SCROLLOK))
end_define

begin_define
define|#
directive|define
name|winch
parameter_list|(
name|w
parameter_list|)
define|\
value|((w)->lines[(w)->cury]->line[(w)->curx].ch& 0377)
end_define

begin_decl_stmt
name|__BEGIN_DECLS
comment|/* Public function prototypes. */
name|int
name|box
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cbreak
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|delwin
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|echo
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|endwin
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fullname
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getcap
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gettmode
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
name|idlok
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|initscr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|longname
name|__P
argument_list|(
operator|(
name|char
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
name|mvcur
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mvprintw
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mvscanw
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mvwin
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mvwprintw
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|int
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mvwscanw
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|int
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|newwin
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nl
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nocbreak
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|noecho
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nonl
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|noraw
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|overlay
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|overwrite
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|printw
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|raw
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|resetty
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|savetty
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scanw
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scroll
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setterm
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sscans
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|subwin
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|suspendwin
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|touchline
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|touchoverlap
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|touchwin
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vwprintw
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|_BSD_VA_LIST_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vwscanw
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|_BSD_VA_LIST_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|waddch
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|waddnstr
name|__P
argument_list|(
operator|(
name|WINDOW
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
name|wclear
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wclrtobot
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wclrtoeol
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wdelch
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wdeleteln
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|werase
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wgetch
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wgetstr
name|__P
argument_list|(
operator|(
name|WINDOW
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
name|winsch
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|winsertln
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wmove
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wprintw
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wrefresh
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wscanw
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wstandend
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wstandout
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Private functions that are needed for user programs prototypes. */
end_comment

begin_decl_stmt
name|void
name|__cputchar
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_putchar
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__waddbytes
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Private functions. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_CURSES_PRIVATE
end_ifdef

begin_decl_stmt
name|void
name|__CTRACE
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|__hash
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__id_subwins
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__mvcur
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__restore_stophandler
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
name|__set_stophandler
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
name|__set_subwin
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__set_scroll_region
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__startwin
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
name|__stop_signal_handler
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__swflags
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__touchline
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__touchwin
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|__tscroll
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__waddch
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|__LDATA
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Private #defines. */
end_comment

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a< b ? a : b)
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a> b ? a : b)
end_define

begin_comment
comment|/* Private externs. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|DB
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__echoit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__endwin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__pfast
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__rawmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__noqch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__usecs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tputs
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|tputs
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Termcap functions. */
end_comment

begin_decl_stmt
name|int
name|tgetent
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tgetnum
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tgetflag
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tgetstr
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tgoto
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CURSES_H_ */
end_comment

end_unit

