begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)curses.h	5.6 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WINDOW
end_ifndef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

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

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_define
define|#
directive|define
name|ERR
value|(0)
end_define

begin_define
define|#
directive|define
name|OK
value|(1)
end_define

begin_define
define|#
directive|define
name|_ENDLINE
value|001
end_define

begin_define
define|#
directive|define
name|_FULLWIN
value|002
end_define

begin_define
define|#
directive|define
name|_SCROLLWIN
value|004
end_define

begin_define
define|#
directive|define
name|_FLUSH
value|010
end_define

begin_define
define|#
directive|define
name|_FULLLINE
value|020
end_define

begin_define
define|#
directive|define
name|_IDLINE
value|040
end_define

begin_define
define|#
directive|define
name|_STANDOUT
value|0200
end_define

begin_define
define|#
directive|define
name|_NOCHANGE
value|-1
end_define

begin_define
define|#
directive|define
name|_puts
parameter_list|(
name|s
parameter_list|)
value|tputs(s, 0, _putchar)
end_define

begin_typedef
typedef|typedef
name|struct
name|sgttyb
name|SGTTY
typedef|;
end_typedef

begin_comment
comment|/*  * Capabilities from termcap  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|AM
decl_stmt|,
name|BS
decl_stmt|,
name|CA
decl_stmt|,
name|DA
decl_stmt|,
name|DB
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

begin_decl_stmt
specifier|extern
name|char
name|PC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * From the tty modes...  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|GT
decl_stmt|,
name|NONL
decl_stmt|,
name|UPPERCASE
decl_stmt|,
name|normtty
decl_stmt|,
name|_pfast
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|_win_st
block|{
name|short
name|_cury
decl_stmt|,
name|_curx
decl_stmt|;
name|short
name|_maxy
decl_stmt|,
name|_maxx
decl_stmt|;
name|short
name|_begy
decl_stmt|,
name|_begx
decl_stmt|;
name|short
name|_flags
decl_stmt|;
name|short
name|_ch_off
decl_stmt|;
name|bool
name|_clear
decl_stmt|;
name|bool
name|_leave
decl_stmt|;
name|bool
name|_scroll
decl_stmt|;
name|char
modifier|*
modifier|*
name|_y
decl_stmt|;
name|short
modifier|*
name|_firstch
decl_stmt|;
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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WINDOW
value|struct _win_st
end_define

begin_decl_stmt
specifier|extern
name|bool
name|My_term
decl_stmt|,
name|_echoit
decl_stmt|,
name|_rawmode
decl_stmt|,
name|_endwin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Def_term
decl_stmt|,
name|ttytype
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|LINES
decl_stmt|,
name|COLS
decl_stmt|,
name|_tty_ch
decl_stmt|,
name|_res_flg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SGTTY
name|_tty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|stdscr
decl_stmt|,
modifier|*
name|curscr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Define VOID to stop lint from generating "null effect"  * comments.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_decl_stmt
name|int
name|__void__
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VOID
parameter_list|(
name|x
parameter_list|)
value|(__void__ = (int) (x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOID
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * psuedo functions for standard screen  */
end_comment

begin_define
define|#
directive|define
name|addch
parameter_list|(
name|ch
parameter_list|)
value|VOID(waddch(stdscr, ch))
end_define

begin_define
define|#
directive|define
name|getch
parameter_list|()
value|VOID(wgetch(stdscr))
end_define

begin_define
define|#
directive|define
name|addbytes
parameter_list|(
name|da
parameter_list|,
name|co
parameter_list|)
value|VOID(waddbytes(stdscr, da,co))
end_define

begin_define
define|#
directive|define
name|addstr
parameter_list|(
name|str
parameter_list|)
value|VOID(waddbytes(stdscr, str, strlen(str)))
end_define

begin_define
define|#
directive|define
name|getstr
parameter_list|(
name|str
parameter_list|)
value|VOID(wgetstr(stdscr, str))
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
value|VOID(wmove(stdscr, y, x))
end_define

begin_define
define|#
directive|define
name|clear
parameter_list|()
value|VOID(wclear(stdscr))
end_define

begin_define
define|#
directive|define
name|erase
parameter_list|()
value|VOID(werase(stdscr))
end_define

begin_define
define|#
directive|define
name|clrtobot
parameter_list|()
value|VOID(wclrtobot(stdscr))
end_define

begin_define
define|#
directive|define
name|clrtoeol
parameter_list|()
value|VOID(wclrtoeol(stdscr))
end_define

begin_define
define|#
directive|define
name|insertln
parameter_list|()
value|VOID(winsertln(stdscr))
end_define

begin_define
define|#
directive|define
name|deleteln
parameter_list|()
value|VOID(wdeleteln(stdscr))
end_define

begin_define
define|#
directive|define
name|refresh
parameter_list|()
value|VOID(wrefresh(stdscr))
end_define

begin_define
define|#
directive|define
name|inch
parameter_list|()
value|VOID(winch(stdscr))
end_define

begin_define
define|#
directive|define
name|insch
parameter_list|(
name|c
parameter_list|)
value|VOID(winsch(stdscr,c))
end_define

begin_define
define|#
directive|define
name|delch
parameter_list|()
value|VOID(wdelch(stdscr))
end_define

begin_define
define|#
directive|define
name|standout
parameter_list|()
value|VOID(wstandout(stdscr))
end_define

begin_define
define|#
directive|define
name|standend
parameter_list|()
value|VOID(wstandend(stdscr))
end_define

begin_comment
comment|/*  * mv functions  */
end_comment

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
value|VOID(wmove(win,y,x)==ERR?ERR:waddch(win,ch))
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
value|VOID(wmove(win,y,x)==ERR?ERR:wgetch(win))
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
value|VOID(wmove(win,y,x)==ERR?ERR:waddbytes(win,da,co))
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
value|VOID(wmove(win,y,x)==ERR?ERR:waddbytes(win,str,strlen(str)))
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
value|VOID(wmove(win,y,x)==ERR?ERR:wgetstr(win,str))
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
value|VOID(wmove(win,y,x) == ERR ? ERR : winch(win))
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
value|VOID(wmove(win,y,x) == ERR ? ERR : wdelch(win))
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
value|VOID(wmove(win,y,x) == ERR ? ERR:winsch(win,c))
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
value|mvwaddch(stdscr,y,x,ch)
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
value|mvwgetch(stdscr,y,x)
end_define

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
value|mvwaddbytes(stdscr,y,x,da,co)
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
value|mvwaddstr(stdscr,y,x,str)
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
value|mvwgetstr(stdscr,y,x,str)
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
value|mvwinch(stdscr,y,x)
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
value|mvwdelch(stdscr,y,x)
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
value|mvwinsch(stdscr,y,x,c)
end_define

begin_comment
comment|/*  * psuedo functions  */
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
value|(win->_clear = bf)
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
value|(win->_leave = bf)
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
value|(win->_scroll = bf)
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
value|(bf ? (win->_flags |= _FLUSH):(win->_flags&= ~_FLUSH))
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
value|y = win->_cury, x = win->_curx
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

begin_define
define|#
directive|define
name|raw
parameter_list|()
value|(_tty.sg_flags|=RAW, _pfast=_rawmode=TRUE, \ 	ioctl(_tty_ch, TIOCSETP,&_tty))
end_define

begin_define
define|#
directive|define
name|noraw
parameter_list|()
value|(_tty.sg_flags&=~RAW,_rawmode=FALSE,\ 	_pfast=!(_tty.sg_flags&CRMOD),ioctl(_tty_ch, TIOCSETP,&_tty))
end_define

begin_define
define|#
directive|define
name|cbreak
parameter_list|()
value|(_tty.sg_flags |= CBREAK, _rawmode = TRUE, \ 	ioctl(_tty_ch, TIOCSETP,&_tty))
end_define

begin_define
define|#
directive|define
name|nocbreak
parameter_list|()
value|(_tty.sg_flags&= ~CBREAK,_rawmode=FALSE, \ 	ioctl(_tty_ch, TIOCSETP,&_tty))
end_define

begin_define
define|#
directive|define
name|crmode
parameter_list|()
value|cbreak()
end_define

begin_comment
comment|/* backwards compatability */
end_comment

begin_define
define|#
directive|define
name|nocrmode
parameter_list|()
value|nocbreak()
end_define

begin_comment
comment|/* backwards compatability */
end_comment

begin_define
define|#
directive|define
name|echo
parameter_list|()
value|(_tty.sg_flags |= ECHO, _echoit = TRUE, \ 	ioctl(_tty_ch, TIOCSETP,&_tty))
end_define

begin_define
define|#
directive|define
name|noecho
parameter_list|()
value|(_tty.sg_flags&= ~ECHO, _echoit = FALSE, \ 	ioctl(_tty_ch, TIOCSETP,&_tty))
end_define

begin_define
define|#
directive|define
name|nl
parameter_list|()
value|(_tty.sg_flags |= CRMOD,_pfast = _rawmode, \ 	ioctl(_tty_ch, TIOCSETP,&_tty))
end_define

begin_define
define|#
directive|define
name|nonl
parameter_list|()
value|(_tty.sg_flags&= ~CRMOD, _pfast = TRUE, \ 	ioctl(_tty_ch, TIOCSETP,&_tty))
end_define

begin_define
define|#
directive|define
name|savetty
parameter_list|()
value|((void) ioctl(_tty_ch, TIOCGETP,&_tty), \ 	_res_flg = _tty.sg_flags)
end_define

begin_define
define|#
directive|define
name|resetty
parameter_list|()
value|(_tty.sg_flags = _res_flg, \ 	(void) ioctl(_tty_ch, TIOCSETP,&_tty))
end_define

begin_define
define|#
directive|define
name|erasechar
parameter_list|()
value|(_tty.sg_erase)
end_define

begin_define
define|#
directive|define
name|killchar
parameter_list|()
value|(_tty.sg_kill)
end_define

begin_define
define|#
directive|define
name|baudrate
parameter_list|()
value|(_tty.sg_ospeed)
end_define

begin_decl_stmt
name|WINDOW
modifier|*
name|initscr
argument_list|()
decl_stmt|,
modifier|*
name|newwin
argument_list|()
decl_stmt|,
modifier|*
name|subwin
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|longname
argument_list|()
decl_stmt|,
modifier|*
name|getcap
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Used to be in unctrl.h.  */
end_comment

begin_define
define|#
directive|define
name|unctrl
parameter_list|(
name|c
parameter_list|)
value|_unctrl[(c)& 0177]
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_unctrl
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

