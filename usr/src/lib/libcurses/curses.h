begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)curses.h	5.12 (Berkeley) %G%  */
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
file|<stdio.h>
end_include

begin_comment
comment|/*  * The following #defines and #includes are present for backward  * compatibility only.  They should not be used in future code.  *  * START BACKWARD COMPATIBILITY ONLY.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CURSES_PRIVATE
end_ifndef

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

begin_define
define|#
directive|define
name|_putchar
parameter_list|(
name|c
parameter_list|)
value|__cputchar(c)
end_define

begin_comment
comment|/* Old-style terminal modes access. */
end_comment

begin_define
define|#
directive|define
name|baudrate
parameter_list|()
value|(cfgetospeed(&origtermio))
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
value|(origtermio.c_cc[VERASE])
end_define

begin_define
define|#
directive|define
name|killchar
parameter_list|()
value|(origtermio.c_cc[VKILL])
end_define

begin_define
define|#
directive|define
name|nocrmode
parameter_list|()
value|nocbreak()
end_define

begin_define
define|#
directive|define
name|ospeed
value|(cfgetospeed(&origtermio))
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
comment|/* END BACKWARD COMPATIBILITY ONLY. */
end_comment

begin_comment
comment|/* 7-bit ASCII characters. */
end_comment

begin_define
define|#
directive|define
name|unctrl
parameter_list|(
name|c
parameter_list|)
value|__unctrl[(c)& 0x7f]
end_define

begin_define
define|#
directive|define
name|unctrllen
parameter_list|(
name|ch
parameter_list|)
value|__unctrllen[(ch)& 0x7f]
end_define

begin_typedef
typedef|typedef
struct|struct
name|_win_st
block|{
comment|/* Window structure. */
name|short
name|_cury
decl_stmt|,
name|_curx
decl_stmt|;
comment|/* Current x, y coordinates. */
name|short
name|_maxy
decl_stmt|,
name|_maxx
decl_stmt|;
comment|/* Maximum values for curx, cury. */
name|short
name|_begy
decl_stmt|,
name|_begx
decl_stmt|;
comment|/* Window home. */
define|#
directive|define
name|_ENDLINE
value|0x001
comment|/* End of screen. */
define|#
directive|define
name|_FLUSH
value|0x002
comment|/* fflush(stdout) after refresh. */
define|#
directive|define
name|_FULLLINE
value|0x004
comment|/* Line width = terminal width. */
define|#
directive|define
name|_FULLWIN
value|0x008
comment|/* Window is a screen. */
define|#
directive|define
name|_IDLINE
value|0x010
comment|/* Insert/delete sequences. */
define|#
directive|define
name|_SCROLLWIN
value|0x020
comment|/* Last char will scroll window. */
comment|/*   * XXX  * _STANDOUT is the 8th bit, characters themselves are encoded.  */
define|#
directive|define
name|_STANDOUT
value|0x080
comment|/* Added characters are standout. */
name|unsigned
name|short
name|_flags
decl_stmt|;
name|short
name|_ch_off
decl_stmt|;
comment|/* x offset for firstch/lastch. */
name|char
name|_clear
decl_stmt|;
comment|/* If clear on next refresh. */
name|char
name|_leave
decl_stmt|;
comment|/* If cursor left. */
name|char
name|_scroll
decl_stmt|;
comment|/* If scrolling permitted. */
name|char
modifier|*
modifier|*
name|_y
decl_stmt|;
comment|/* Line describing the window. */
define|#
directive|define
name|_NOCHANGE
value|-1
comment|/* No change since last refresh. */
name|short
modifier|*
name|_firstch
decl_stmt|;
comment|/* First and last changed in line. */
name|short
modifier|*
name|_lastch
decl_stmt|;
name|struct
name|_win_st
modifier|*
name|_nextp
decl_stmt|,
modifier|*
name|_orig
decl_stmt|;
comment|/* Subwindows list and parent. */
block|}
name|WINDOW
typedef|;
end_typedef

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
name|HZ
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

begin_decl_stmt
specifier|extern
name|struct
name|termios
name|origtermio
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Original terminal modes. */
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
name|char
modifier|*
name|ttytype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Full name of current terminal. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__unctrl
index|[
literal|0x80
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
literal|0x80
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Control strings length. */
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
name|da
parameter_list|,
name|co
parameter_list|)
value|waddbytes(stdscr, da, co)
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
name|addstr
parameter_list|(
name|str
parameter_list|)
value|waddbytes(stdscr, str, strlen(str))
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
name|str
parameter_list|)
value|wgetstr(stdscr, str)
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
value|)		winsch(stdscr, ch)
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
name|da
parameter_list|,
name|co
parameter_list|)
define|\
value|mvwaddbytes(stdscr, y, x, da, co)
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
name|mvaddstr
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|str
parameter_list|)
value|mvwaddstr(stdscr, y, x, str)
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
name|str
parameter_list|)
value|mvwgetstr(stdscr, y, x, str)
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
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|da
parameter_list|,
name|co
parameter_list|)
define|\
value|(wmove(win, y, x) == ERR ? \ 				    ERR : waddbytes(win, da, co))
end_define

begin_define
define|#
directive|define
name|mvwaddch
parameter_list|(
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|ch
parameter_list|)
value|(wmove(win, y, x) == ERR ? \ 				    ERR : waddch(win, ch))
end_define

begin_define
define|#
directive|define
name|mvwaddstr
parameter_list|(
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|str
parameter_list|)
define|\
value|(wmove(win, y, x) == ERR ? \ 				    ERR : waddbytes(win, str, strlen(str)))
end_define

begin_define
define|#
directive|define
name|mvwdelch
parameter_list|(
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|)
value|(wmove(win, y, x) == ERR ? ERR : wdelch(win))
end_define

begin_define
define|#
directive|define
name|mvwgetch
parameter_list|(
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|)
value|(wmove(win, y, x) == ERR ? ERR : wgetch(win))
end_define

begin_define
define|#
directive|define
name|mvwgetstr
parameter_list|(
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|str
parameter_list|)
define|\
value|(wmove(win, y, x) == ERR ? \ 				    ERR : wgetstr(win, str))
end_define

begin_define
define|#
directive|define
name|mvwinch
parameter_list|(
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|)
value|(wmove(win, y, x) == ERR ? ERR : winch(win))
end_define

begin_define
define|#
directive|define
name|mvwinsch
parameter_list|(
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|c
parameter_list|)
value|(wmove(win, y, x) == ERR ? ERR : winsch(win, c))
end_define

begin_comment
comment|/* Random psuedo functions. */
end_comment

begin_define
define|#
directive|define
name|clearok
parameter_list|(
name|win
parameter_list|,
name|bf
parameter_list|)
value|(win->_clear = (bf))
end_define

begin_define
define|#
directive|define
name|flushok
parameter_list|(
name|win
parameter_list|,
name|bf
parameter_list|)
value|((bf) ? (win->_flags |= _FLUSH) : \ 				    (win->_flags&= ~_FLUSH))
end_define

begin_define
define|#
directive|define
name|getyx
parameter_list|(
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|)
value|(y) = win->_cury, (x) = win->_curx
end_define

begin_define
define|#
directive|define
name|leaveok
parameter_list|(
name|win
parameter_list|,
name|bf
parameter_list|)
value|(win->_leave = (bf))
end_define

begin_define
define|#
directive|define
name|scrollok
parameter_list|(
name|win
parameter_list|,
name|bf
parameter_list|)
value|(win->_scroll = (bf))
end_define

begin_define
define|#
directive|define
name|winch
parameter_list|(
name|win
parameter_list|)
value|(win->_y[win->_cury][win->_curx]& 0177)
end_define

begin_comment
comment|/* Public function prototypes. */
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
name|_sprintw
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
name|_BSD_VA_LIST_
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
name|void
name|tstp
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
name|waddstr
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
name|char
modifier|*
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
name|char
modifier|*
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

begin_ifdef
ifdef|#
directive|ifdef
name|_CURSES_PRIVATE
end_ifdef

begin_comment
comment|/* Private function prototypes. */
end_comment

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
name|void
name|__TRACE
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
name|waddbytes
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
operator|,
name|char
operator|*
operator|,
name|int
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
name|tputs
name|__P
argument_list|(
operator|(
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CURSES_H_ */
end_comment

end_unit

