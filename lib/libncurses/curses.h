begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************** *                            COPYRIGHT NOTICE                              * **************************************************************************** *                ncurses is copyright (C) 1992, 1993, 1994                 * *                          by Zeyd M. Ben-Halim                            * *                          zmbenhal@netcom.com                             * *                                                                          * *        Permission is hereby granted to reproduce and distribute ncurses  * *        by any means and for any fee, whether alone or as part of a       * *        larger distribution, in source or in binary form, PROVIDED        * *        this notice is included with any such distribution, not removed   * *        from header files, and is reproduced in any documentation         * *        accompanying it or the applications linked with it.               * *                                                                          * *        ncurses comes AS IS with no warranty, implied or expressed.       * *                                                                          * ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NCURSES_H
end_ifndef

begin_define
define|#
directive|define
name|__NCURSES_H
end_define

begin_define
define|#
directive|define
name|CURSES
value|1
end_define

begin_define
define|#
directive|define
name|CURSES_H
value|1
end_define

begin_comment
comment|/* This is defined in more than one ncurses header, for identification */
end_comment

begin_undef
undef|#
directive|undef
name|NCURSES_VERSION
end_undef

begin_define
define|#
directive|define
name|NCURSES_VERSION
value|"1.8.6/ache"
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|chtype
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NOTERMIOS
end_ifndef

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TERMIOS
end_ifndef

begin_define
define|#
directive|define
name|TERMIOS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<unctrl.h>
end_include

begin_define
define|#
directive|define
name|bool
value|char
end_define

begin_comment
comment|/* attributes */
end_comment

begin_define
define|#
directive|define
name|A_ATTRIBUTES
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|A_NORMAL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|A_STANDOUT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|A_UNDERLINE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|A_REVERSE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|A_BLINK
value|0x00080000
end_define

begin_define
define|#
directive|define
name|A_DIM
value|0x00100000
end_define

begin_define
define|#
directive|define
name|A_BOLD
value|0x00200000
end_define

begin_define
define|#
directive|define
name|A_ALTCHARSET
value|0x00400000
end_define

begin_define
define|#
directive|define
name|A_INVIS
value|0x00800000
end_define

begin_define
define|#
directive|define
name|A_PROTECT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|A_CHARTEXT
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|A_COLOR
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|COLOR_PAIR
parameter_list|(
name|n
parameter_list|)
value|(n<< 8)
end_define

begin_define
define|#
directive|define
name|PAIR_NUMBER
parameter_list|(
name|a
parameter_list|)
value|((a& A_COLOR)>> 8)
end_define

begin_comment
comment|/* colors */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|COLORS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|COLOR_PAIRS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|color_pairs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|COLOR_BLACK
value|0
end_define

begin_define
define|#
directive|define
name|COLOR_RED
value|1
end_define

begin_define
define|#
directive|define
name|COLOR_GREEN
value|2
end_define

begin_define
define|#
directive|define
name|COLOR_YELLOW
value|3
end_define

begin_define
define|#
directive|define
name|COLOR_BLUE
value|4
end_define

begin_define
define|#
directive|define
name|COLOR_MAGENTA
value|5
end_define

begin_define
define|#
directive|define
name|COLOR_CYAN
value|6
end_define

begin_define
define|#
directive|define
name|COLOR_WHITE
value|7
end_define

begin_comment
comment|/* line graphics */
end_comment

begin_decl_stmt
specifier|extern
name|chtype
name|acs_map
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ACS_ULCORNER
value|(acs_map['l'])
end_define

begin_define
define|#
directive|define
name|ACS_LLCORNER
value|(acs_map['m'])
end_define

begin_define
define|#
directive|define
name|ACS_URCORNER
value|(acs_map['k'])
end_define

begin_define
define|#
directive|define
name|ACS_LRCORNER
value|(acs_map['j'])
end_define

begin_define
define|#
directive|define
name|ACS_RTEE
value|(acs_map['u'])
end_define

begin_define
define|#
directive|define
name|ACS_LTEE
value|(acs_map['t'])
end_define

begin_define
define|#
directive|define
name|ACS_BTEE
value|(acs_map['v'])
end_define

begin_define
define|#
directive|define
name|ACS_TTEE
value|(acs_map['w'])
end_define

begin_define
define|#
directive|define
name|ACS_HLINE
value|(acs_map['q'])
end_define

begin_define
define|#
directive|define
name|ACS_VLINE
value|(acs_map['x'])
end_define

begin_define
define|#
directive|define
name|ACS_PLUS
value|(acs_map['n'])
end_define

begin_define
define|#
directive|define
name|ACS_S1
value|(acs_map['o'])
end_define

begin_comment
comment|/* scan line 1 */
end_comment

begin_define
define|#
directive|define
name|ACS_S9
value|(acs_map['s'])
end_define

begin_comment
comment|/* scan line 9 */
end_comment

begin_define
define|#
directive|define
name|ACS_DIAMOND
value|(acs_map['`'])
end_define

begin_comment
comment|/* diamond */
end_comment

begin_define
define|#
directive|define
name|ACS_CKBOARD
value|(acs_map['a'])
end_define

begin_comment
comment|/* checker board (stipple) */
end_comment

begin_define
define|#
directive|define
name|ACS_DEGREE
value|(acs_map['f'])
end_define

begin_comment
comment|/* degree symbol */
end_comment

begin_define
define|#
directive|define
name|ACS_PLMINUS
value|(acs_map['g'])
end_define

begin_comment
comment|/* plus/minus */
end_comment

begin_define
define|#
directive|define
name|ACS_BULLET
value|(acs_map['~'])
end_define

begin_comment
comment|/* bullet */
end_comment

begin_define
define|#
directive|define
name|ACS_LARROW
value|(acs_map[','])
end_define

begin_comment
comment|/* arrow pointing left */
end_comment

begin_define
define|#
directive|define
name|ACS_RARROW
value|(acs_map['+'])
end_define

begin_comment
comment|/* arrow pointing right */
end_comment

begin_define
define|#
directive|define
name|ACS_DARROW
value|(acs_map['.'])
end_define

begin_comment
comment|/* arrow pointing down */
end_comment

begin_define
define|#
directive|define
name|ACS_UARROW
value|(acs_map['-'])
end_define

begin_comment
comment|/* arrow pointing up */
end_comment

begin_define
define|#
directive|define
name|ACS_BOARD
value|(acs_map['h'])
end_define

begin_comment
comment|/* board of squares */
end_comment

begin_define
define|#
directive|define
name|ACS_LANTERN
value|(acs_map['I'])
end_define

begin_comment
comment|/* lantern symbol */
end_comment

begin_define
define|#
directive|define
name|ACS_BLOCK
value|(acs_map['0'])
end_define

begin_comment
comment|/* solid square block */
end_comment

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
name|ERR
value|(-1)
end_define

begin_define
define|#
directive|define
name|OK
value|(0)
end_define

begin_define
define|#
directive|define
name|_SUBWIN
value|0x01
end_define

begin_define
define|#
directive|define
name|_ENDLINE
value|0x02
end_define

begin_define
define|#
directive|define
name|_FULLWIN
value|0x04
end_define

begin_define
define|#
directive|define
name|_SCROLLWIN
value|0x08
end_define

begin_define
define|#
directive|define
name|_ISPAD
value|0x10
end_define

begin_define
define|#
directive|define
name|_HASMOVED
value|0x20
end_define

begin_define
define|#
directive|define
name|_NOCHANGE
value|-1
end_define

begin_typedef
typedef|typedef
name|struct
name|screen
name|SCREEN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_win_st
name|WINDOW
typedef|;
end_typedef

begin_struct
struct|struct
name|_win_st
block|{
name|short
name|_cury
decl_stmt|,
name|_curx
decl_stmt|;
comment|/* current cursor position */
name|short
name|_maxy
decl_stmt|,
name|_maxx
decl_stmt|;
comment|/* maximum values of x and y NOT the screen dimensions */
name|short
name|_begy
decl_stmt|,
name|_begx
decl_stmt|;
name|short
name|_flags
decl_stmt|;
name|chtype
name|_attrs
decl_stmt|;
name|chtype
name|_bkgd
decl_stmt|;
comment|/* The following should be consolidated into one bitset */
name|bool
name|_notimeout
decl_stmt|;
name|bool
name|_use_idc
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
name|bool
name|_idlok
decl_stmt|;
name|bool
name|_immed
decl_stmt|;
name|bool
name|_sync
decl_stmt|;
name|bool
name|_use_keypad
decl_stmt|;
comment|/* 0=no, 1=yes */
name|bool
name|_use_meta
decl_stmt|;
comment|/* T=use the meta key */
name|int
name|_delay
decl_stmt|;
comment|/* 0 = nodelay<0 = blocking>0 = delay */
name|chtype
modifier|*
modifier|*
name|_line
decl_stmt|;
name|short
modifier|*
name|_firstchar
decl_stmt|;
comment|/* First changed character in the line */
name|short
modifier|*
name|_lastchar
decl_stmt|;
comment|/* Last changed character in the line */
name|short
name|_regtop
decl_stmt|;
comment|/* Top and bottom of scrolling region */
name|short
name|_regbottom
decl_stmt|;
name|int
name|_parx
decl_stmt|;
name|int
name|_pary
decl_stmt|;
name|WINDOW
modifier|*
name|_parent
decl_stmt|;
comment|/* parent if a sub-window */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|stdscr
decl_stmt|,
modifier|*
name|curscr
decl_stmt|,
modifier|*
name|newscr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|LINES
decl_stmt|,
name|COLS
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
name|int
name|resizeterm
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
if|#
directive|if
literal|0
comment|/* MYTINFO not have it */
block|extern char ttytype[];
comment|/* needed for backward compatibility */
endif|#
directive|endif
specifier|extern
name|int
name|tigetflag
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|tigetnum
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|tigetstr
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* Debugging : use with libdcurses.a */
specifier|extern
name|void
name|_init_trace
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|_tracef
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|_traceattr
parameter_list|(
name|int
name|mode
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|_tracechar
parameter_list|(
specifier|const
name|unsigned
name|char
name|mode
parameter_list|)
function_decl|;
specifier|extern
name|void
name|trace
parameter_list|(
specifier|const
name|unsigned
name|int
name|tracelevel
parameter_list|)
function_decl|;
comment|/* trace masks */
define|#
directive|define
name|TRACE_DISABLE
value|0x00
comment|/* turn off tracing */
define|#
directive|define
name|TRACE_ORDINARY
value|0x01
comment|/* ordinary trace mode */
define|#
directive|define
name|TRACE_CHARPUT
value|0x02
comment|/* also trace all character outputs */
define|#
directive|define
name|TRACE_MAXIMUM
value|0x0f
comment|/* maximum trace level */
comment|/* function prototypes */
specifier|extern
name|int
name|baudrate
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|beep
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|cbreak
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|clearok
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|copywin
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|curs_set
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|def_prog_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|def_shell_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|delwin
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|WINDOW
modifier|*
name|derwin
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|doupdate
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|WINDOW
modifier|*
name|dupwin
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|echo
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|endwin
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|char
name|erasechar
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|flash
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|flushinp
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|halfdelay
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|idlok
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|intrflush
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
specifier|extern
name|int
name|is_linetouched
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|is_wintouched
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|WINDOW
modifier|*
name|initscr
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|isendwin
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|keyname
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|keypad
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|char
name|killchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|leaveok
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|longname
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|meta
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|mvcur
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|mvprintw
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|int
name|mvscanw
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|int
name|mvwin
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|mvwprintw
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|int
name|mvwscanw
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|WINDOW
modifier|*
name|newpad
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|SCREEN
modifier|*
name|newterm
parameter_list|(
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|WINDOW
modifier|*
name|newwin
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|nl
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|nocbreak
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|nodelay
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|noecho
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|nonl
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|noraw
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|notimeout
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
specifier|extern
name|int
name|overlay
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|overwrite
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|pnoutrefresh
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|prefresh
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|printw
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|int
name|putp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|raw
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|reset_prog_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|reset_shell_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|resetty
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|ripoffline
parameter_list|(
name|int
name|line
parameter_list|,
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
specifier|extern
name|int
name|savetty
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|scanw
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|int
name|scrollok
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|SCREEN
modifier|*
name|set_term
parameter_list|(
name|SCREEN
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|setupterm
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|WINDOW
modifier|*
name|subwin
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|timeout
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|tparm
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|int
name|tputs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
function_decl|;
specifier|extern
name|int
name|typeahead
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|ungetch
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|vidattr
parameter_list|(
name|chtype
parameter_list|)
function_decl|;
specifier|extern
name|int
name|vidputs
parameter_list|(
name|chtype
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
function_decl|;
specifier|extern
name|int
name|vwscanw
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
specifier|extern
name|int
name|vwprintw
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
specifier|extern
name|int
name|waddch
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|chtype
parameter_list|)
function_decl|;
specifier|extern
name|int
name|waddchnstr
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|chtype
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|waddnstr
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wattron
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|chtype
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wattroff
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|chtype
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wbkgd
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|chtype
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wborder
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|chtype
parameter_list|,
name|chtype
parameter_list|,
name|chtype
parameter_list|,
name|chtype
parameter_list|,
name|chtype
parameter_list|,
name|chtype
parameter_list|,
name|chtype
parameter_list|,
name|chtype
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wclear
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wclrtobot
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wclrtoeol
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wdelch
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wechochar
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|chtype
parameter_list|)
function_decl|;
specifier|extern
name|int
name|werase
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wgetch
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wgetnstr
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
name|maxlen
parameter_list|)
function_decl|;
specifier|extern
name|int
name|whline
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|chtype
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|winnstr
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|winsch
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|chtype
parameter_list|)
function_decl|;
specifier|extern
name|int
name|winsdelln
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|winsnstr
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wmove
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wnoutrefresh
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wprintw
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wredrawln
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wrefresh
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wscanw
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wscrl
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wsetscrreg
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wtimeout
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wtouchln
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|wvline
parameter_list|(
name|WINDOW
modifier|*
parameter_list|,
name|chtype
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|bool
name|can_change_color
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|color_content
parameter_list|(
name|short
parameter_list|,
name|short
modifier|*
parameter_list|,
name|short
modifier|*
parameter_list|,
name|short
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|has_colors
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|init_color
parameter_list|(
name|short
parameter_list|,
name|short
parameter_list|,
name|short
parameter_list|,
name|short
parameter_list|)
function_decl|;
specifier|extern
name|int
name|init_pair
parameter_list|(
name|short
parameter_list|,
name|short
parameter_list|,
name|short
parameter_list|)
function_decl|;
specifier|extern
name|int
name|pair_content
parameter_list|(
name|short
parameter_list|,
name|short
modifier|*
parameter_list|,
name|short
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|start_color
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|slk_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|slk_set
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|slk_refresh
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|slk_noutrefresh
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|slk_label
parameter_list|(
name|int
parameter_list|)
function_decl|;
specifier|extern
name|int
name|slk_clear
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|slk_restore
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|slk_touch
parameter_list|(
name|void
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * pseudo functions  */
end_comment

begin_define
define|#
directive|define
name|wgetstr
parameter_list|(
name|w
parameter_list|,
name|s
parameter_list|)
value|wgetnstr(w, s, -1)
end_define

begin_define
define|#
directive|define
name|napms
parameter_list|(
name|x
parameter_list|)
value|usleep(1000*x)
end_define

begin_define
define|#
directive|define
name|setterm
parameter_list|(
name|term
parameter_list|)
value|setupterm(term, 1, (int *)0)
end_define

begin_define
define|#
directive|define
name|fixterm
parameter_list|()
value|reset_prog_mode()
end_define

begin_define
define|#
directive|define
name|resetterm
parameter_list|()
value|reset_shell_mode()
end_define

begin_define
define|#
directive|define
name|saveterm
parameter_list|()
value|def_prog_mode()
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
name|nocrmode
parameter_list|()
value|nocbreak()
end_define

begin_define
define|#
directive|define
name|gettmode
parameter_list|()
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
value|(y = (win)->_cury, x = (win)->_curx)
end_define

begin_define
define|#
directive|define
name|getbegyx
parameter_list|(
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|)
value|(y = (win)->_begy, x = (win)->_begx)
end_define

begin_define
define|#
directive|define
name|getmaxyx
parameter_list|(
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|)
value|(y = (win)->_maxy + 1, x = (win)->_maxx + 1)
end_define

begin_define
define|#
directive|define
name|getsyx
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
value|getyx(stdscr, y, x)
end_define

begin_define
define|#
directive|define
name|setsyx
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
value|(stdscr->_cury = y, stdscr->_curx = x)
end_define

begin_define
define|#
directive|define
name|wbkgdset
parameter_list|(
name|win
parameter_list|,
name|ch
parameter_list|)
value|((win)->_bkgd = ch)
end_define

begin_comment
comment|/* It seems older SYSV curses define these */
end_comment

begin_define
define|#
directive|define
name|getattrs
parameter_list|(
name|win
parameter_list|)
value|(win->_attrs)
end_define

begin_define
define|#
directive|define
name|getmaxx
parameter_list|(
name|win
parameter_list|)
value|((win)->_maxx + 1)
end_define

begin_define
define|#
directive|define
name|getmaxy
parameter_list|(
name|win
parameter_list|)
value|((win)->_maxy + 1)
end_define

begin_define
define|#
directive|define
name|winch
parameter_list|(
name|win
parameter_list|)
value|((win)->_line[(win)->_cury][(win)->_curx])
end_define

begin_define
define|#
directive|define
name|wstandout
parameter_list|(
name|win
parameter_list|)
value|(wattrset(win,A_STANDOUT))
end_define

begin_define
define|#
directive|define
name|wstandend
parameter_list|(
name|win
parameter_list|)
value|(wattrset(win,A_NORMAL))
end_define

begin_define
define|#
directive|define
name|wattrset
parameter_list|(
name|win
parameter_list|,
name|at
parameter_list|)
value|((win)->_attrs = (at))
end_define

begin_define
define|#
directive|define
name|subpad
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|,
name|c
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|)
value|derwin(p,l,c,y,x)
end_define

begin_define
define|#
directive|define
name|scroll
parameter_list|(
name|win
parameter_list|)
value|wscrl(win,1)
end_define

begin_define
define|#
directive|define
name|touchwin
parameter_list|(
name|win
parameter_list|)
value|wtouchln((win), 0, (win)->_maxy + 1, 1)
end_define

begin_define
define|#
directive|define
name|touchline
parameter_list|(
name|win
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|wtouchln((win), s, c, 1)
end_define

begin_define
define|#
directive|define
name|untouchwin
parameter_list|(
name|win
parameter_list|)
value|wtouchln((win), 0, (win)->_maxy + 1, 0)
end_define

begin_define
define|#
directive|define
name|box
parameter_list|(
name|win
parameter_list|,
name|v
parameter_list|,
name|h
parameter_list|)
value|wborder(win, v, v, h, h, 0, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|border
parameter_list|(
name|ls
parameter_list|,
name|rs
parameter_list|,
name|ts
parameter_list|,
name|bs
parameter_list|,
name|tl
parameter_list|,
name|tr
parameter_list|,
name|bl
parameter_list|,
name|br
parameter_list|)
value|wborder(stdscr, ls, rs, ts, bs, tl, tr, bl, br)
end_define

begin_define
define|#
directive|define
name|hline
parameter_list|(
name|ch
parameter_list|,
name|n
parameter_list|)
value|whline(stdscr, ch, n)
end_define

begin_define
define|#
directive|define
name|vline
parameter_list|(
name|ch
parameter_list|,
name|n
parameter_list|)
value|wvline(stdscr, ch, n)
end_define

begin_define
define|#
directive|define
name|winsstr
parameter_list|(
name|w
parameter_list|,
name|s
parameter_list|)
value|winsnstr(w, s, 0)
end_define

begin_define
define|#
directive|define
name|winstr
parameter_list|(
name|w
parameter_list|,
name|s
parameter_list|)
value|winnstr(w, s, -1)
end_define

begin_define
define|#
directive|define
name|redrawwin
parameter_list|(
name|w
parameter_list|)
value|wredrawln(w, 0, w->_maxy+1)
end_define

begin_define
define|#
directive|define
name|waddstr
parameter_list|(
name|win
parameter_list|,
name|str
parameter_list|)
value|waddnstr(win,str,-1)
end_define

begin_define
define|#
directive|define
name|waddchstr
parameter_list|(
name|win
parameter_list|,
name|str
parameter_list|)
value|waddchnstr(win,str,-1)
end_define

begin_comment
comment|/*  * pseudo functions for standard screen  */
end_comment

begin_define
define|#
directive|define
name|bkgdset
parameter_list|(
name|ch
parameter_list|)
value|wbkgdset(stdscr,ch)
end_define

begin_define
define|#
directive|define
name|bkgd
parameter_list|(
name|ch
parameter_list|)
value|wbkgd(stdscr,ch)
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
name|standout
parameter_list|()
value|wstandout(stdscr)
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
name|attron
parameter_list|(
name|at
parameter_list|)
value|wattron(stdscr,at)
end_define

begin_define
define|#
directive|define
name|attroff
parameter_list|(
name|at
parameter_list|)
value|wattroff(stdscr,at)
end_define

begin_define
define|#
directive|define
name|attrset
parameter_list|(
name|at
parameter_list|)
value|wattrset(stdscr,at)
end_define

begin_define
define|#
directive|define
name|addch
parameter_list|(
name|ch
parameter_list|)
value|waddch(stdscr,ch)
end_define

begin_define
define|#
directive|define
name|echochar
parameter_list|(
name|c
parameter_list|)
value|wechochar(stdscr, c)
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
name|addstr
parameter_list|(
name|str
parameter_list|)
value|waddnstr(stdscr,str,-1)
end_define

begin_define
define|#
directive|define
name|getstr
parameter_list|(
name|str
parameter_list|)
value|wgetstr(stdscr,str)
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
value|wmove(stdscr,y,x)
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
name|erase
parameter_list|()
value|werase(stdscr)
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
name|insertln
parameter_list|()
value|winsdelln(stdscr, 1)
end_define

begin_define
define|#
directive|define
name|winsertln
parameter_list|(
name|w
parameter_list|)
value|winsdelln(w, 1)
end_define

begin_define
define|#
directive|define
name|deleteln
parameter_list|()
value|winsdelln(stdscr, -1)
end_define

begin_define
define|#
directive|define
name|wdeleteln
parameter_list|(
name|w
parameter_list|)
value|winsdelln(w, -1)
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
name|innstr
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|winnstr(stdscr,s,n)
end_define

begin_define
define|#
directive|define
name|insch
parameter_list|(
name|c
parameter_list|)
value|winsch(stdscr,c)
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
name|setscrreg
parameter_list|(
name|t
parameter_list|,
name|b
parameter_list|)
value|wsetscrreg(stdscr,t,b)
end_define

begin_define
define|#
directive|define
name|scrl
parameter_list|(
name|n
parameter_list|)
value|wscrl(stdscr,n)
end_define

begin_define
define|#
directive|define
name|timeout
parameter_list|(
name|delay
parameter_list|)
value|wtimeout(stdscr, delay)
end_define

begin_define
define|#
directive|define
name|addnstr
parameter_list|(
name|str
parameter_list|,
name|n
parameter_list|)
value|waddnstr(stdscr,str,n)
end_define

begin_define
define|#
directive|define
name|addchstr
parameter_list|(
name|str
parameter_list|)
value|waddchstr(stdscr,str)
end_define

begin_define
define|#
directive|define
name|addchnstr
parameter_list|(
name|str
parameter_list|,
name|n
parameter_list|)
value|waddchnstr(stdscr,str, n)
end_define

begin_define
define|#
directive|define
name|insdelln
parameter_list|(
name|n
parameter_list|)
value|winsdelln(stdscr, n)
end_define

begin_define
define|#
directive|define
name|insstr
parameter_list|(
name|s
parameter_list|)
value|winsstr(stdscr, s)
end_define

begin_define
define|#
directive|define
name|insnstr
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|winsnstr(stdscr, s, n)
end_define

begin_comment
comment|/*  * mv functions */
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
value|(wmove(win,y,x) == ERR ? ERR : waddch(win,ch))
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
value|(wmove(win,y,x) == ERR ? ERR : wgetch(win))
end_define

begin_define
define|#
directive|define
name|mvwaddchnstr
parameter_list|(
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|str
parameter_list|,
name|n
parameter_list|)
value|(wmove(win,y,x) == ERR ? ERR : waddchnstr(win,str,n))
end_define

begin_define
define|#
directive|define
name|mvwaddchstr
parameter_list|(
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|str
parameter_list|)
value|(wmove(win,y,x) == ERR ? ERR : waddchnstr(win,str,-1))
end_define

begin_define
define|#
directive|define
name|mvwaddnstr
parameter_list|(
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|str
parameter_list|,
name|n
parameter_list|)
value|(wmove(win,y,x) == ERR ? ERR : waddnstr(win,str,n))
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
value|(wmove(win,y,x) == ERR ? ERR : waddnstr(win,str,-1))
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
value|(wmove(win,y,x) == ERR ? ERR : wgetstr(win,str))
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
value|(wmove(win,y,x) == ERR ? ERR : winch(win))
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
value|(wmove(win,y,x) == ERR ? ERR : wdelch(win))
end_define

begin_define
define|#
directive|define
name|mvwinnstr
parameter_list|(
name|win
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|(wmove(win,y,x) == ERR ? ERR : winnstr(win,s,n))
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
value|(wmove(win,y,x) == ERR ? ERR : winsch(win,c))
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
name|mvaddnstr
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|str
parameter_list|,
name|n
parameter_list|)
value|mvwaddnstr(stdscr,y,x,str,n)
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
name|mvinnstr
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|mvwinnstr(stdscr,y,x,s,n)
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

begin_define
define|#
directive|define
name|mvwinsstr
parameter_list|(
name|w
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
value|(wmove(w,y,x) == ERR ? ERR : winsstr(w,s))
end_define

begin_define
define|#
directive|define
name|mvwinsnstr
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
value|(wmove(w,y,x) == ERR ? ERR : winsnstr(w,s,n))
end_define

begin_define
define|#
directive|define
name|mvinsstr
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
value|mvwinsstr(stdscr,y,x,s)
end_define

begin_define
define|#
directive|define
name|mvinsnstr
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|mvwinsnstr(stdscr,y,x,s,n)
end_define

begin_comment
comment|/*  * XSI curses macros for XPG4 conformance.  */
end_comment

begin_define
define|#
directive|define
name|attr_get
parameter_list|()
value|wattr_get(stdscr)
end_define

begin_define
define|#
directive|define
name|getbkgd
parameter_list|(
name|win
parameter_list|)
value|((win)->_bkgd)
end_define

begin_define
define|#
directive|define
name|vid_attr
parameter_list|(
name|a
parameter_list|)
value|vidattr(a)
end_define

begin_define
define|#
directive|define
name|wattr_get
parameter_list|(
name|win
parameter_list|)
value|((win)->_attrs)
end_define

begin_comment
comment|/* Funny "characters" enabled for various special function keys for input */
end_comment

begin_comment
comment|/* Whether such a key exists depend if its definition is in the terminfo entry */
end_comment

begin_define
define|#
directive|define
name|KEY_MIN
value|0401
end_define

begin_comment
comment|/* Minimum curses key */
end_comment

begin_define
define|#
directive|define
name|KEY_BREAK
value|0401
end_define

begin_comment
comment|/* break key (unreliable) */
end_comment

begin_define
define|#
directive|define
name|KEY_DOWN
value|0402
end_define

begin_comment
comment|/* The four arrow keys ... */
end_comment

begin_define
define|#
directive|define
name|KEY_UP
value|0403
end_define

begin_define
define|#
directive|define
name|KEY_LEFT
value|0404
end_define

begin_define
define|#
directive|define
name|KEY_RIGHT
value|0405
end_define

begin_comment
comment|/* ... */
end_comment

begin_define
define|#
directive|define
name|KEY_HOME
value|0406
end_define

begin_comment
comment|/* Home key (upward+left arrow) */
end_comment

begin_define
define|#
directive|define
name|KEY_BACKSPACE
value|0407
end_define

begin_comment
comment|/* backspace (unreliable) */
end_comment

begin_define
define|#
directive|define
name|KEY_F0
value|0410
end_define

begin_comment
comment|/* Function keys.  Space for 64 */
end_comment

begin_define
define|#
directive|define
name|KEY_F
parameter_list|(
name|n
parameter_list|)
value|(KEY_F0+(n))
end_define

begin_comment
comment|/* keys is reserved. */
end_comment

begin_define
define|#
directive|define
name|KEY_DL
value|0510
end_define

begin_comment
comment|/* Delete line */
end_comment

begin_define
define|#
directive|define
name|KEY_IL
value|0511
end_define

begin_comment
comment|/* Insert line */
end_comment

begin_define
define|#
directive|define
name|KEY_DC
value|0512
end_define

begin_comment
comment|/* Delete character */
end_comment

begin_define
define|#
directive|define
name|KEY_IC
value|0513
end_define

begin_comment
comment|/* Insert char or enter insert mode */
end_comment

begin_define
define|#
directive|define
name|KEY_EIC
value|0514
end_define

begin_comment
comment|/* Exit insert char mode */
end_comment

begin_define
define|#
directive|define
name|KEY_CLEAR
value|0515
end_define

begin_comment
comment|/* Clear screen */
end_comment

begin_define
define|#
directive|define
name|KEY_EOS
value|0516
end_define

begin_comment
comment|/* Clear to end of screen */
end_comment

begin_define
define|#
directive|define
name|KEY_EOL
value|0517
end_define

begin_comment
comment|/* Clear to end of line */
end_comment

begin_define
define|#
directive|define
name|KEY_SF
value|0520
end_define

begin_comment
comment|/* Scroll 1 line forward */
end_comment

begin_define
define|#
directive|define
name|KEY_SR
value|0521
end_define

begin_comment
comment|/* Scroll 1 line backwards (reverse) */
end_comment

begin_define
define|#
directive|define
name|KEY_NPAGE
value|0522
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|KEY_PPAGE
value|0523
end_define

begin_comment
comment|/* Previous page */
end_comment

begin_define
define|#
directive|define
name|KEY_STAB
value|0524
end_define

begin_comment
comment|/* Set tab */
end_comment

begin_define
define|#
directive|define
name|KEY_CTAB
value|0525
end_define

begin_comment
comment|/* Clear tab */
end_comment

begin_define
define|#
directive|define
name|KEY_CATAB
value|0526
end_define

begin_comment
comment|/* Clear all tabs */
end_comment

begin_define
define|#
directive|define
name|KEY_ENTER
value|0527
end_define

begin_comment
comment|/* Enter or send (unreliable) */
end_comment

begin_define
define|#
directive|define
name|KEY_SRESET
value|0530
end_define

begin_comment
comment|/* soft (partial) reset (unreliable) */
end_comment

begin_define
define|#
directive|define
name|KEY_RESET
value|0531
end_define

begin_comment
comment|/* reset or hard reset (unreliable) */
end_comment

begin_define
define|#
directive|define
name|KEY_PRINT
value|0532
end_define

begin_comment
comment|/* print or copy */
end_comment

begin_define
define|#
directive|define
name|KEY_LL
value|0533
end_define

begin_comment
comment|/* home down or bottom (lower left) */
end_comment

begin_comment
comment|/* The keypad is arranged like this: */
end_comment

begin_comment
comment|/* a1    up    a3   */
end_comment

begin_comment
comment|/* left   b2  right  */
end_comment

begin_comment
comment|/* c1   down   c3   */
end_comment

begin_define
define|#
directive|define
name|KEY_A1
value|0534
end_define

begin_comment
comment|/* Upper left of keypad */
end_comment

begin_define
define|#
directive|define
name|KEY_A3
value|0535
end_define

begin_comment
comment|/* Upper right of keypad */
end_comment

begin_define
define|#
directive|define
name|KEY_B2
value|0536
end_define

begin_comment
comment|/* Center of keypad */
end_comment

begin_define
define|#
directive|define
name|KEY_C1
value|0537
end_define

begin_comment
comment|/* Lower left of keypad */
end_comment

begin_define
define|#
directive|define
name|KEY_C3
value|0540
end_define

begin_comment
comment|/* Lower right of keypad */
end_comment

begin_define
define|#
directive|define
name|KEY_BTAB
value|0541
end_define

begin_comment
comment|/* Back tab key */
end_comment

begin_define
define|#
directive|define
name|KEY_BEG
value|0542
end_define

begin_comment
comment|/* beg(inning) key */
end_comment

begin_define
define|#
directive|define
name|KEY_CANCEL
value|0543
end_define

begin_comment
comment|/* cancel key */
end_comment

begin_define
define|#
directive|define
name|KEY_CLOSE
value|0544
end_define

begin_comment
comment|/* close key */
end_comment

begin_define
define|#
directive|define
name|KEY_COMMAND
value|0545
end_define

begin_comment
comment|/* cmd (command) key */
end_comment

begin_define
define|#
directive|define
name|KEY_COPY
value|0546
end_define

begin_comment
comment|/* copy key */
end_comment

begin_define
define|#
directive|define
name|KEY_CREATE
value|0547
end_define

begin_comment
comment|/* create key */
end_comment

begin_define
define|#
directive|define
name|KEY_END
value|0550
end_define

begin_comment
comment|/* end key */
end_comment

begin_define
define|#
directive|define
name|KEY_EXIT
value|0551
end_define

begin_comment
comment|/* exit key */
end_comment

begin_define
define|#
directive|define
name|KEY_FIND
value|0552
end_define

begin_comment
comment|/* find key */
end_comment

begin_define
define|#
directive|define
name|KEY_HELP
value|0553
end_define

begin_comment
comment|/* help key */
end_comment

begin_define
define|#
directive|define
name|KEY_MARK
value|0554
end_define

begin_comment
comment|/* mark key */
end_comment

begin_define
define|#
directive|define
name|KEY_MESSAGE
value|0555
end_define

begin_comment
comment|/* message key */
end_comment

begin_define
define|#
directive|define
name|KEY_MOVE
value|0556
end_define

begin_comment
comment|/* move key */
end_comment

begin_define
define|#
directive|define
name|KEY_NEXT
value|0557
end_define

begin_comment
comment|/* next object key */
end_comment

begin_define
define|#
directive|define
name|KEY_OPEN
value|0560
end_define

begin_comment
comment|/* open key */
end_comment

begin_define
define|#
directive|define
name|KEY_OPTIONS
value|0561
end_define

begin_comment
comment|/* options key */
end_comment

begin_define
define|#
directive|define
name|KEY_PREVIOUS
value|0562
end_define

begin_comment
comment|/* previous object key */
end_comment

begin_define
define|#
directive|define
name|KEY_REDO
value|0563
end_define

begin_comment
comment|/* redo key */
end_comment

begin_define
define|#
directive|define
name|KEY_REFERENCE
value|0564
end_define

begin_comment
comment|/* ref(erence) key */
end_comment

begin_define
define|#
directive|define
name|KEY_REFRESH
value|0565
end_define

begin_comment
comment|/* refresh key */
end_comment

begin_define
define|#
directive|define
name|KEY_REPLACE
value|0566
end_define

begin_comment
comment|/* replace key */
end_comment

begin_define
define|#
directive|define
name|KEY_RESTART
value|0567
end_define

begin_comment
comment|/* restart key */
end_comment

begin_define
define|#
directive|define
name|KEY_RESUME
value|0570
end_define

begin_comment
comment|/* resume key */
end_comment

begin_define
define|#
directive|define
name|KEY_SAVE
value|0571
end_define

begin_comment
comment|/* save key */
end_comment

begin_define
define|#
directive|define
name|KEY_SBEG
value|0572
end_define

begin_comment
comment|/* shifted beginning key */
end_comment

begin_define
define|#
directive|define
name|KEY_SCANCEL
value|0573
end_define

begin_comment
comment|/* shifted cancel key */
end_comment

begin_define
define|#
directive|define
name|KEY_SCOMMAND
value|0574
end_define

begin_comment
comment|/* shifted command key */
end_comment

begin_define
define|#
directive|define
name|KEY_SCOPY
value|0575
end_define

begin_comment
comment|/* shifted copy key */
end_comment

begin_define
define|#
directive|define
name|KEY_SCREATE
value|0576
end_define

begin_comment
comment|/* shifted create key */
end_comment

begin_define
define|#
directive|define
name|KEY_SDC
value|0577
end_define

begin_comment
comment|/* shifted delete char key */
end_comment

begin_define
define|#
directive|define
name|KEY_SDL
value|0600
end_define

begin_comment
comment|/* shifted delete line key */
end_comment

begin_define
define|#
directive|define
name|KEY_SELECT
value|0601
end_define

begin_comment
comment|/* select key */
end_comment

begin_define
define|#
directive|define
name|KEY_SEND
value|0602
end_define

begin_comment
comment|/* shifted end key */
end_comment

begin_define
define|#
directive|define
name|KEY_SEOL
value|0603
end_define

begin_comment
comment|/* shifted clear line key */
end_comment

begin_define
define|#
directive|define
name|KEY_SEXIT
value|0604
end_define

begin_comment
comment|/* shifted exit key */
end_comment

begin_define
define|#
directive|define
name|KEY_SFIND
value|0605
end_define

begin_comment
comment|/* shifted find key */
end_comment

begin_define
define|#
directive|define
name|KEY_SHELP
value|0606
end_define

begin_comment
comment|/* shifted help key */
end_comment

begin_define
define|#
directive|define
name|KEY_SHOME
value|0607
end_define

begin_comment
comment|/* shifted home key */
end_comment

begin_define
define|#
directive|define
name|KEY_SIC
value|0610
end_define

begin_comment
comment|/* shifted input key */
end_comment

begin_define
define|#
directive|define
name|KEY_SLEFT
value|0611
end_define

begin_comment
comment|/* shifted left arrow key */
end_comment

begin_define
define|#
directive|define
name|KEY_SMESSAGE
value|0612
end_define

begin_comment
comment|/* shifted message key */
end_comment

begin_define
define|#
directive|define
name|KEY_SMOVE
value|0613
end_define

begin_comment
comment|/* shifted move key */
end_comment

begin_define
define|#
directive|define
name|KEY_SNEXT
value|0614
end_define

begin_comment
comment|/* shifted next key */
end_comment

begin_define
define|#
directive|define
name|KEY_SOPTIONS
value|0615
end_define

begin_comment
comment|/* shifted options key */
end_comment

begin_define
define|#
directive|define
name|KEY_SPREVIOUS
value|0616
end_define

begin_comment
comment|/* shifted prev key */
end_comment

begin_define
define|#
directive|define
name|KEY_SPRINT
value|0617
end_define

begin_comment
comment|/* shifted print key */
end_comment

begin_define
define|#
directive|define
name|KEY_SREDO
value|0620
end_define

begin_comment
comment|/* shifted redo key */
end_comment

begin_define
define|#
directive|define
name|KEY_SREPLACE
value|0621
end_define

begin_comment
comment|/* shifted replace key */
end_comment

begin_define
define|#
directive|define
name|KEY_SRIGHT
value|0622
end_define

begin_comment
comment|/* shifted right arrow */
end_comment

begin_define
define|#
directive|define
name|KEY_SRSUME
value|0623
end_define

begin_comment
comment|/* shifted resume key */
end_comment

begin_define
define|#
directive|define
name|KEY_SSAVE
value|0624
end_define

begin_comment
comment|/* shifted save key */
end_comment

begin_define
define|#
directive|define
name|KEY_SSUSPEND
value|0625
end_define

begin_comment
comment|/* shifted suspend key */
end_comment

begin_define
define|#
directive|define
name|KEY_SUNDO
value|0626
end_define

begin_comment
comment|/* shifted undo key */
end_comment

begin_define
define|#
directive|define
name|KEY_SUSPEND
value|0627
end_define

begin_comment
comment|/* suspend key */
end_comment

begin_define
define|#
directive|define
name|KEY_UNDO
value|0630
end_define

begin_comment
comment|/* undo key */
end_comment

begin_define
define|#
directive|define
name|KEY_MAX
value|0777
end_define

begin_comment
comment|/* Maximum curses key */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

