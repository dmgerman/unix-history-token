begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/*  * Capabilities from termcap  *  * The description of terminals is a difficult business, and we only  * attempt to summarize the capabilities here;  for a full description  * see the paper describing termcap.  *  * Capabilities from termcap are of three kinds - string valued options,  * numeric valued options, and boolean options.  The string valued options  * are the most complicated, since they may include padding information,  * which we describe now.  *  * Intelligent terminals often require padding on intelligent operations  * at high (and sometimes even low) speed.  This is specified by  * a number before the string in the capability, and has meaning for the  * capabilities which have a P at the front of their comment.  * This normally is a number of milliseconds to pad the operation.  * In the current system which has no true programmible delays, we  * do this by sending a sequence of pad characters (normally nulls, but  * specifiable as "pc").  In some cases, the pad is better computed  * as some number of milliseconds times the number of affected lines  * (to bottom of screen usually, except when terminals have insert modes  * which will shift several lines.)  This is specified as '12*' e.g.  * before the capability to say 12 milliseconds per affected whatever  * (currently always line).  Capabilities where this makes sense say P*.  */
end_comment

begin_decl_stmt
name|char
name|tspace
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Space for capability strings */
end_comment

begin_decl_stmt
name|char
modifier|*
name|aoftspace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Address of tspace for relocation */
end_comment

begin_decl_stmt
name|char
modifier|*
name|AL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Add new blank line */
end_comment

begin_decl_stmt
name|char
modifier|*
name|BC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Back cursor */
end_comment

begin_decl_stmt
name|char
modifier|*
name|CD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Clear to end of display */
end_comment

begin_decl_stmt
name|char
modifier|*
name|CE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Clear to end of line */
end_comment

begin_decl_stmt
name|char
modifier|*
name|CL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Clear screen */
end_comment

begin_decl_stmt
name|char
modifier|*
name|CM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Cursor motion */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Delete character */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Delete line sequence */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Delete mode (enter)  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Down line sequence */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ED
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    End delete mode */
end_comment

begin_decl_stmt
name|char
modifier|*
name|EI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    End insert mode */
end_comment

begin_decl_stmt
name|char
modifier|*
name|HO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Home cursor */
end_comment

begin_decl_stmt
name|char
modifier|*
name|IC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Insert character */
end_comment

begin_decl_stmt
name|char
modifier|*
name|IM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Insert mode (give as ':im=:' if 'ic' */
end_comment

begin_decl_stmt
name|char
modifier|*
name|IP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P* Insert pad after char ins'd using IM+IE */
end_comment

begin_decl_stmt
name|char
modifier|*
name|LL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Quick to last line, column 0 */
end_comment

begin_decl_stmt
name|char
modifier|*
name|MA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Control character map for cmd mode */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ND
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Non-destructive space */
end_comment

begin_decl_stmt
name|char
name|PC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Pad character */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Standout end (may leave space) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Scroll forwards */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Stand out begin (may leave space) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Scroll backwards */
end_comment

begin_decl_stmt
name|char
modifier|*
name|TA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* P  Tab (other than ^I or with padding) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|UP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Upline */
end_comment

begin_decl_stmt
name|char
modifier|*
name|VB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Visible bell */
end_comment

begin_decl_stmt
name|char
modifier|*
name|VE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Visual end sequence */
end_comment

begin_decl_stmt
name|char
modifier|*
name|VS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    Visual start sequence */
end_comment

begin_decl_stmt
name|bool
name|AM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Automatic margins */
end_comment

begin_decl_stmt
name|bool
name|BS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Backspace works */
end_comment

begin_decl_stmt
name|bool
name|CA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cursor addressible */
end_comment

begin_decl_stmt
name|bool
name|DA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Display may be retained above */
end_comment

begin_decl_stmt
name|bool
name|DB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Display may be retained below */
end_comment

begin_decl_stmt
name|bool
name|EO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Can erase overstrikes with ' ' */
end_comment

begin_decl_stmt
name|bool
name|GT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Gtty indicates tabs */
end_comment

begin_decl_stmt
name|bool
name|HZ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hazeltine ~ braindamage */
end_comment

begin_decl_stmt
name|bool
name|IN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Insert-null blessing */
end_comment

begin_decl_stmt
name|bool
name|MI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* can move in insert mode */
end_comment

begin_decl_stmt
name|bool
name|NC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* No Cr - \r snds \r\n then eats \n (dm2500) */
end_comment

begin_decl_stmt
name|bool
name|OS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Overstrike works */
end_comment

begin_decl_stmt
name|bool
name|UL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Underlining works even though !os */
end_comment

begin_decl_stmt
name|bool
name|XN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A newline gets eaten after wrap (concept) */
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
name|bool
name|NONL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal can't hack linefeeds doing a CR */
end_comment

begin_decl_stmt
name|bool
name|UPPERCASE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ick! */
end_comment

begin_decl_stmt
name|short
name|LINES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of lines on screen */
end_comment

begin_decl_stmt
name|short
name|COLUMNS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|OCOLUMNS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save COLUMNS for a hack in open mode */
end_comment

begin_decl_stmt
name|short
name|outcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where the cursor is */
end_comment

begin_decl_stmt
name|short
name|outline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|destcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where the cursor should be */
end_comment

begin_decl_stmt
name|short
name|destline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sgttyb
name|tty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Always stty/gtty using this one structure */
end_comment

begin_decl_stmt
name|bool
name|normtty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Have to restor normal mode from normf */
end_comment

begin_decl_stmt
name|int
name|normf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Restore tty flags to this (someday) */
end_comment

begin_decl_stmt
name|short
name|WBOT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|WECHO
decl_stmt|;
end_decl_stmt

end_unit

