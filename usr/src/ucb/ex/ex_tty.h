begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ex_tty.h	7.7 (Berkeley) 3/9/87  */
end_comment

begin_comment
comment|/*  * Capabilities from termcap  *  * The description of terminals is a difficult business, and we only  * attempt to summarize the capabilities here;  for a full description  * see the paper describing termcap.  *  * Capabilities from termcap are of three kinds - string valued options,  * numeric valued options, and boolean options.  The string valued options  * are the most complicated, since they may include padding information,  * which we describe now.  *  * Intelligent terminals often require padding on intelligent operations  * at high (and sometimes even low) speed.  This is specified by  * a number before the string in the capability, and has meaning for the  * capabilities which have a P at the front of their comment.  * This normally is a number of milliseconds to pad the operation.  * In the current system which has no true programmible delays, we  * do this by sending a sequence of pad characters (normally nulls, but  * specifiable as "pc").  In some cases, the pad is better computed  * as some number of milliseconds times the number of affected lines  * (to bottom of screen usually, except when terminals have insert modes  * which will shift several lines.)  This is specified as '12*' e.g.  * before the capability to say 12 milliseconds per affected whatever  * (currently always line).  Capabilities where this makes sense say P*.  */
end_comment

begin_decl_stmt
name|var
name|char
name|tspace
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Space for capability strings */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|aoftspace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Address of tspace for relocation */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|AL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Add new blank line */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|AL_PARM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Add n new blank lines */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|BC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Back cursor */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|BT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Back tab */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|CD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Clear to end of display */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|CE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Clear to end of line */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|CL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Clear screen */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|CM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PG Cursor motion */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|CS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PG Change scrolling region (vt100) */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|xCR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Carriage return */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|DC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Delete character */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|DL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Delete line sequence */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|DL_PARM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Delete n lines */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|DM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Delete mode (enter)  */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|DO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Down line sequence */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|DOWN_PARM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Down n lines */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|ED
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    End delete mode */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|EI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    End insert mode */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|F0
decl_stmt|,
modifier|*
name|F1
decl_stmt|,
modifier|*
name|F2
decl_stmt|,
modifier|*
name|F3
decl_stmt|,
modifier|*
name|F4
decl_stmt|,
modifier|*
name|F5
decl_stmt|,
modifier|*
name|F6
decl_stmt|,
modifier|*
name|F7
decl_stmt|,
modifier|*
name|F8
decl_stmt|,
modifier|*
name|F9
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Strings sent by various function keys */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|HO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Home cursor */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|IC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Insert character */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|IM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Insert mode (give as ':im=:' if 'ic' */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|IP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Insert pad after char ins'd using IM+IE */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|KD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Keypad down arrow */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|KE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Keypad don't xmit */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|KH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Keypad home key */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|KL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Keypad left arrow */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|KR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Keypad right arrow */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|KS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Keypad start xmitting */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|KU
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Keypad up arrow */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|LEFT_PARM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Left n chars */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|LL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Quick to last line, column 0 */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|ND
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Non-destructive space */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|RIGHT_PARM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Right n spaces */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|xNL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Line feed (new line) */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|PC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Pad character */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|RC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Restore cursor from last SC */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|SC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Save cursor */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|SE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Standout end (may leave space) */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|SF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Scroll forwards */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|SO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Stand out begin (may leave space) */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|SR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Scroll backwards */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|TA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Tab (other than ^I or with padding) */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|TE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Terminal end sequence */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|TI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Terminal initial sequence */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|UP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Upline */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|UP_PARM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Up n lines */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|VB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Visible bell */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|VE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Visual end sequence */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|VS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Visual start sequence */
end_comment

begin_decl_stmt
name|var
name|bool
name|AM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Automatic margins */
end_comment

begin_decl_stmt
name|var
name|bool
name|BS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Backspace works */
end_comment

begin_decl_stmt
name|var
name|bool
name|CA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cursor addressible */
end_comment

begin_decl_stmt
name|var
name|bool
name|DA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Display may be retained above */
end_comment

begin_decl_stmt
name|var
name|bool
name|DB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Display may be retained below */
end_comment

begin_decl_stmt
name|var
name|bool
name|EO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Can erase overstrikes with ' ' */
end_comment

begin_decl_stmt
name|var
name|bool
name|GT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Gtty indicates tabs */
end_comment

begin_decl_stmt
name|var
name|bool
name|HC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hard copy terminal */
end_comment

begin_decl_stmt
name|var
name|bool
name|HZ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hazeltine ~ braindamage */
end_comment

begin_decl_stmt
name|var
name|bool
name|IN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Insert-null blessing */
end_comment

begin_decl_stmt
name|var
name|bool
name|MI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* can move in insert mode */
end_comment

begin_decl_stmt
name|var
name|bool
name|NC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* No Cr - \r snds \r\n then eats \n (dm2500) */
end_comment

begin_decl_stmt
name|var
name|bool
name|NS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* No scroll - linefeed at bottom won't scroll */
end_comment

begin_decl_stmt
name|var
name|bool
name|OS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Overstrike works */
end_comment

begin_decl_stmt
name|var
name|bool
name|UL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Underlining works even though !os */
end_comment

begin_decl_stmt
name|var
name|bool
name|XB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Beehive (no escape key, simulate with f1) */
end_comment

begin_decl_stmt
name|var
name|bool
name|XN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A newline gets eaten after wrap (concept) */
end_comment

begin_decl_stmt
name|var
name|bool
name|XT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tabs are destructive */
end_comment

begin_decl_stmt
name|var
name|bool
name|XX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tektronix 4025 insert line */
end_comment

begin_comment
comment|/* X? is reserved for severely nauseous glitches */
end_comment

begin_comment
comment|/* If there are enough of these we may need bit masks! */
end_comment

begin_comment
comment|/*  * From the tty modes...  */
end_comment

begin_decl_stmt
name|var
name|bool
name|NONL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal can't hack linefeeds doing a CR */
end_comment

begin_decl_stmt
name|var
name|bool
name|UPPERCASE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ick! */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|LINES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of lines on screen */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|COLUMNS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|short
name|OCOLUMNS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save COLUMNS for a hack in open mode */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCGWINSZ
end_ifdef

begin_decl_stmt
name|var
name|struct
name|winsize
name|winsz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save window size for stopping comparisons */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|var
name|short
name|outcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where the cursor is */
end_comment

begin_decl_stmt
name|var
name|short
name|outline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|short
name|destcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where the cursor should be */
end_comment

begin_decl_stmt
name|var
name|short
name|destline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * There are several kinds of tty drivers to contend with.  These include:  * (1)	V6:		no CBREAK, no ioctl.  (Include PWB V1 here).  * (2)	V7 research:	has CBREAK, has ioctl, and has the tchars (TIOCSETC)  *			business to change start, stop, etc. chars.  * (3)	USG V2:		Basically like V6 but RAW mode is like V7 RAW.  *			(We treat it as V6.)  * (4)	USG V3:		equivalent to V7 but totally incompatible.  * (5)  Berkeley:	has ltchars in addition to all of V7.  *  * The following attempts to decide what we are on, and declare  * some variables in the appropriate format.  The wierd looking one (ttymode)  * is the thing we pass to ex_sTTY and family to turn "RAW" mode on or off  * when we go into or out of visual mode.  In V7/V6 it's just the flags word  * to stty.  In USG V3 it's the whole tty structure.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG3TTY
end_ifdef

begin_comment
comment|/* USG V3 */
end_comment

begin_decl_stmt
name|var
name|struct
name|termio
name|tty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use this one structure to change modes */
end_comment

begin_typedef
typedef|typedef
name|struct
name|termio
name|ttymode
typedef|;
end_typedef

begin_comment
comment|/* Mode to contain tty flags */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* All others */
end_comment

begin_decl_stmt
name|var
name|struct
name|sgttyb
name|tty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Always stty/gtty using this one structure */
end_comment

begin_typedef
typedef|typedef
name|int
name|ttymode
typedef|;
end_typedef

begin_comment
comment|/* Mode to contain tty flags */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCSETC
end_ifdef

begin_comment
comment|/* V7 */
end_comment

begin_decl_stmt
name|var
name|struct
name|tchars
name|ottyc
decl_stmt|,
name|nttyc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For V7 character masking */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCLGET
end_ifdef

begin_comment
comment|/* Berkeley */
end_comment

begin_decl_stmt
name|var
name|struct
name|ltchars
name|olttyc
decl_stmt|,
name|nlttyc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* More of tchars style stuff */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|var
name|ttymode
name|normf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Restore tty flags to this (someday) */
end_comment

begin_decl_stmt
name|var
name|bool
name|normtty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Have to restore normal mode from normf */
end_comment

begin_decl_stmt
name|ttymode
name|ostart
argument_list|()
decl_stmt|,
name|setty
argument_list|()
decl_stmt|,
name|unixex
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|short
name|costCM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # chars to output a typical CM, with padding etc. */
end_comment

begin_decl_stmt
name|var
name|short
name|costSR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* likewise for scroll reverse */
end_comment

begin_decl_stmt
name|var
name|short
name|costAL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* likewise for insert line */
end_comment

begin_decl_stmt
name|var
name|short
name|costDP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* likewise for DOWN_PARM */
end_comment

begin_decl_stmt
name|var
name|short
name|costLP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* likewise for LEFT_PARM */
end_comment

begin_decl_stmt
name|var
name|short
name|costRP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* likewise for RIGHT_PARM */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

begin_define
define|#
directive|define
name|MAXNOMACS
value|128
end_define

begin_comment
comment|/* max number of macros of each kind */
end_comment

begin_define
define|#
directive|define
name|MAXCHARMACS
value|2048
end_define

begin_comment
comment|/* max # of chars total in macros */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXNOMACS
value|32
end_define

begin_comment
comment|/* max number of macros of each kind */
end_comment

begin_define
define|#
directive|define
name|MAXCHARMACS
value|512
end_define

begin_comment
comment|/* max # of chars total in macros */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|maps
block|{
name|char
modifier|*
name|cap
decl_stmt|;
comment|/* pressing button that sends this.. */
name|char
modifier|*
name|mapto
decl_stmt|;
comment|/* .. maps to this string */
name|char
modifier|*
name|descr
decl_stmt|;
comment|/* legible description of key */
block|}
struct|;
end_struct

begin_decl_stmt
name|var
name|struct
name|maps
name|arrows
index|[
name|MAXNOMACS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* macro defs - 1st 5 built in */
end_comment

begin_decl_stmt
name|var
name|struct
name|maps
name|immacs
index|[
name|MAXNOMACS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for while in insert mode */
end_comment

begin_decl_stmt
name|var
name|struct
name|maps
name|abbrevs
index|[
name|MAXNOMACS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for word abbreviations */
end_comment

begin_decl_stmt
name|var
name|int
name|ldisc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line discipline for ucb tty driver */
end_comment

begin_decl_stmt
name|var
name|char
name|mapspace
index|[
name|MAXCHARMACS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|char
modifier|*
name|msnext
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next free location in mapspace */
end_comment

begin_decl_stmt
name|var
name|int
name|maphopcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* check for infinite mapping loops */
end_comment

begin_decl_stmt
name|var
name|bool
name|anyabbrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if abbr or unabbr has been done */
end_comment

begin_decl_stmt
name|var
name|char
name|ttynbuf
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* result of ttyname() */
end_comment

begin_decl_stmt
name|var
name|int
name|ttymesg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* original mode of users tty */
end_comment

end_unit

