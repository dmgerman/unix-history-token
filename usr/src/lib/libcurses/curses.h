begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_define
define|#
directive|define
name|bool
value|char
end_define

begin_comment
comment|/* boolean variable		*/
end_comment

begin_define
define|#
directive|define
name|reg
value|register
end_define

begin_comment
comment|/* register varaible abbr.	*/
end_comment

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

begin_comment
comment|/* default return on error	*/
end_comment

begin_define
define|#
directive|define
name|OK
value|(1)
end_define

begin_comment
comment|/* default return on good run	*/
end_comment

begin_define
define|#
directive|define
name|_SUBWIN
value|01
end_define

begin_comment
comment|/* window is a subindow		*/
end_comment

begin_define
define|#
directive|define
name|_ENDLINE
value|02
end_define

begin_comment
comment|/* lines go to end of screen	*/
end_comment

begin_define
define|#
directive|define
name|_FULLWIN
value|04
end_define

begin_comment
comment|/* window is entire screen	*/
end_comment

begin_define
define|#
directive|define
name|_SCROLLWIN
value|010
end_define

begin_comment
comment|/* window could cause scroll	*/
end_comment

begin_define
define|#
directive|define
name|_STANDOUT
value|0200
end_define

begin_comment
comment|/* standout mode in effect	*/
end_comment

begin_define
define|#
directive|define
name|_NOCHANGE
value|-1
end_define

begin_comment
comment|/* no change on this line	*/
end_comment

begin_define
define|#
directive|define
name|_puts
parameter_list|(
name|s
parameter_list|)
value|tputs(s, 0, _putchar);
end_define

begin_typedef
typedef|typedef
name|struct
name|sgttyb
name|SGTTY
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|WINDOW
end_ifndef

begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/*  * Capabilities from termcap  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|AL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Add new blank line		*/
end_comment

begin_decl_stmt
name|bool
name|AM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Automatic margins			*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|BC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Back cursor			*/
end_comment

begin_decl_stmt
name|bool
name|BS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Backspace works			*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|BT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Back tab				*/
end_comment

begin_decl_stmt
name|bool
name|CA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Cursor addressible		*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|CD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Clear to end of display		*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|CE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Clear to end of line		*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|CL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Clear screen			*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|CM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Cursor motion			*/
end_comment

begin_decl_stmt
name|bool
name|DA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Display may be retained above	*/
end_comment

begin_decl_stmt
name|bool
name|DB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Display may be retained below	*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|DC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Delete character			*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|DL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Delete line sequence		*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|DM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Delete mode (enter)		*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|DO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Down line sequence		*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|ED
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    End delete mode			*/
end_comment

begin_decl_stmt
name|bool
name|EO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Can erase overstrikes with ' '	*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|EI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    End insert mode			*/
end_comment

begin_decl_stmt
name|bool
name|GT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Gtty indicates tabs		*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|HO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Home cursor			*/
end_comment

begin_decl_stmt
name|bool
name|HZ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Hazeltine ~ braindamage		*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|IC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Insert character			*/
end_comment

begin_decl_stmt
name|bool
name|IN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Insert-null blessing		*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|IM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Insrt mode (as ':im=:' if 'ic')	*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|IP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* pad after char ins'd using IM+IE	*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|LL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Quick to last line, column 0	*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|MA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Ctrl character map for cmd mode	*/
end_comment

begin_decl_stmt
name|bool
name|MI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    can move in insert mode		*/
end_comment

begin_decl_stmt
name|bool
name|NC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    No Cr: \r sends \r\n then eats \n	*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|ND
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Non-destructive space		*/
end_comment

begin_decl_stmt
name|bool
name|OS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Overstrike works			*/
end_comment

begin_decl_stmt
name|char
name|PC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Pad character			*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|SE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Standout end (may leave space)	*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|SF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Scroll forwards			*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|SO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Stand out begin (may leave space)	*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|SR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Scroll backwards			*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|TA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Tab (not ^I or with padding)	*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|TE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    End sequence after TI		*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|TI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Terminal Initialize		*/
end_comment

begin_decl_stmt
name|bool
name|UL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Underlining works even though !os	*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|UE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Underline End sequence		*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|UP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Upline				*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|US
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Underline Start sequence		*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|VB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Visible bell			*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|VE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Visual end sequence		*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|VS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Visual start sequence		*/
end_comment

begin_decl_stmt
name|bool
name|XN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    A newline gets eaten after wrap	*/
end_comment

begin_comment
comment|/* X? is reserved for severely nauseous glitches		*/
end_comment

begin_comment
comment|/* If there are enough of these we may need bit masks!		*/
end_comment

begin_comment
comment|/*  * From the tty modes...  */
end_comment

begin_decl_stmt
name|bool
name|NONL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Term can't hack linefeeds doing a CR	*/
end_comment

begin_decl_stmt
name|bool
name|UPPERCASE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ick!					*/
end_comment

begin_decl_stmt
name|bool
name|normtty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if must normal mode from normf	*/
end_comment

begin_decl_stmt
name|bool
name|pfast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Have stty -nl'ed to go faster	*/
end_comment

begin_define
define|#
directive|define
name|WINDOW
value|struct _win_st
end_define

begin_struct
struct|struct
name|_win_st
block|{
comment|/* window description structure		*/
name|short
name|_cury
decl_stmt|,
name|_curx
decl_stmt|;
comment|/* current y,x positions	*/
name|short
name|_maxy
decl_stmt|,
name|_maxx
decl_stmt|;
comment|/* maximum y,x positions	*/
name|short
name|_begy
decl_stmt|,
name|_begx
decl_stmt|;
comment|/* start y,x positions		*/
name|short
name|_flags
decl_stmt|;
comment|/* various window flags		*/
name|bool
name|_clear
decl_stmt|;
comment|/* need to clear		*/
name|bool
name|_leave
decl_stmt|;
comment|/* leave curx,y at last update	*/
name|bool
name|_scroll
decl_stmt|;
comment|/* scrolls allowed		*/
name|char
modifier|*
modifier|*
name|_y
decl_stmt|;
comment|/* actual window		*/
name|short
modifier|*
name|_firstch
decl_stmt|;
comment|/* first change on line		*/
name|short
modifier|*
name|_lastch
decl_stmt|;
comment|/* last change on line		*/
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|bool
name|My_term
decl_stmt|,
comment|/* set if user species terminal		*/
name|_echoit
decl_stmt|,
comment|/* set if echoing characters		*/
name|_rawmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if terminal in raw mode		*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Def_term
decl_stmt|,
comment|/* default terminal type		*/
name|ttytype
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* long name of current terminal	*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|LINES
decl_stmt|,
name|COLS
decl_stmt|,
comment|/* number of lines and columns		*/
name|_tty_ch
decl_stmt|,
comment|/* channel with tty on it		*/
name|_res_flg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sgtty flags stored for reset		*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|FILE
modifier|*
name|outf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error outfile			*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|SGTTY
name|_tty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tty structure			*/
end_comment

begin_decl_stmt
name|WINDOW
modifier|*
name|stdscr
decl_stmt|,
comment|/* standard screen			*/
modifier|*
name|curscr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current screen			*/
end_comment

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

begin_comment
comment|/* place to assign to			*/
end_comment

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
name|addstr
parameter_list|(
name|str
parameter_list|)
value|VOID(waddstr(stdscr, str))
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

begin_ifdef
ifdef|#
directive|ifdef
name|STANDOUT
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

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
parameter_list|,
name|ch
parameter_list|)
value|VOID(wmove(win,y,x)==ERR?ERR:wgetch(win,ch))
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
value|VOID(wmove(win,y,x)==ERR?ERR:waddstr(win,str))
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
parameter_list|,
name|ch
parameter_list|)
value|mvwgetch(stdscr,y,x,ch)
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
value|mvwinch(win,y,x)
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
value|(win->_y[win->_cury][win->_curx])
end_define

begin_define
define|#
directive|define
name|raw
parameter_list|()
value|(_tty.sg_flags |= RAW, _rawmode = TRUE, stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|noraw
parameter_list|()
value|(_tty.sg_flags&= ~RAW, _rawmode = FALSE, stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|crmode
parameter_list|()
value|(_tty.sg_flags |= CBREAK, _rawmode = TRUE, stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|nocrmode
parameter_list|()
value|(_tty.sg_flags&= ~CBREAK,_rawmode=FALSE,stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|echo
parameter_list|()
value|(_tty.sg_flags |= ECHO, _echoit = TRUE, stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|noecho
parameter_list|()
value|(_tty.sg_flags&= ~ECHO, _echoit = FALSE, stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|nl
parameter_list|()
value|(_tty.sg_flags |= CRMOD, NONL = TRUE, stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|nonl
parameter_list|()
value|(_tty.sg_flags&= ~CRMOD, NONL = FALSE, stty(_tty_ch,&_tty))
end_define

begin_define
define|#
directive|define
name|savetty
parameter_list|()
value|(gtty(_tty_ch,&_tty), _res_flg = _tty.sg_flags)
end_define

begin_define
define|#
directive|define
name|resetty
parameter_list|()
value|(_tty.sg_flags = _res_flg, stty(_tty_ch,&_tty))
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
decl_stmt|;
end_decl_stmt

end_unit

