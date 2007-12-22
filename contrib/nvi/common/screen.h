begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)screen.h	10.24 (Berkeley) 7/19/96  */
end_comment

begin_comment
comment|/*  * There are minimum values that vi has to have to display a screen.  The row  * minimum is fixed at 1 (the svi code can share a line between the text line  * and the colon command/message line).  Column calculation is a lot trickier.  * For example, you have to have enough columns to display the line number,  * not to mention guaranteeing that tabstop and shiftwidth values are smaller  * than the current column value.  It's simpler to have a fixed value and not  * worry about it.  *  * XXX  * MINIMUM_SCREEN_COLS is almost certainly wrong.  */
end_comment

begin_define
define|#
directive|define
name|MINIMUM_SCREEN_ROWS
value|1
end_define

begin_define
define|#
directive|define
name|MINIMUM_SCREEN_COLS
value|20
end_define

begin_comment
comment|/*  * SCR --  *	The screen structure.  To the extent possible, all screen information  *	is stored in the various private areas.  The only information here  *	is used by global routines or is shared by too many screens.  */
end_comment

begin_struct
struct|struct
name|_scr
block|{
comment|/* INITIALIZED AT SCREEN CREATE. */
name|CIRCLEQ_ENTRY
argument_list|(
argument|_scr
argument_list|)
name|q
expr_stmt|;
comment|/* Screens. */
name|int
name|id
decl_stmt|;
comment|/* Screen id #. */
name|int
name|refcnt
decl_stmt|;
comment|/* Reference count. */
name|GS
modifier|*
name|gp
decl_stmt|;
comment|/* Pointer to global area. */
name|SCR
modifier|*
name|nextdisp
decl_stmt|;
comment|/* Next display screen. */
name|SCR
modifier|*
name|ccl_parent
decl_stmt|;
comment|/* Colon command-line parent screen. */
name|EXF
modifier|*
name|ep
decl_stmt|;
comment|/* Screen's current EXF structure. */
name|FREF
modifier|*
name|frp
decl_stmt|;
comment|/* FREF being edited. */
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/* NULL terminated file name array. */
name|char
modifier|*
modifier|*
name|cargv
decl_stmt|;
comment|/* Current file name. */
name|u_long
name|ccnt
decl_stmt|;
comment|/* Command count. */
name|u_long
name|q_ccnt
decl_stmt|;
comment|/* Quit or ZZ command count. */
comment|/* Screen's: */
name|size_t
name|rows
decl_stmt|;
comment|/* 1-N: number of rows. */
name|size_t
name|cols
decl_stmt|;
comment|/* 1-N: number of columns. */
name|size_t
name|t_rows
decl_stmt|;
comment|/* 1-N: cur number of text rows. */
name|size_t
name|t_maxrows
decl_stmt|;
comment|/* 1-N: max number of text rows. */
name|size_t
name|t_minrows
decl_stmt|;
comment|/* 1-N: min number of text rows. */
name|size_t
name|woff
decl_stmt|;
comment|/* 0-N: screen offset in frame. */
comment|/* Cursor's: */
name|recno_t
name|lno
decl_stmt|;
comment|/* 1-N: file line. */
name|size_t
name|cno
decl_stmt|;
comment|/* 0-N: file character in line. */
name|size_t
name|rcm
decl_stmt|;
comment|/* Vi: 0-N: Most attractive column. */
define|#
directive|define
name|L_ADDED
value|0
comment|/* Added lines. */
define|#
directive|define
name|L_CHANGED
value|1
comment|/* Changed lines. */
define|#
directive|define
name|L_DELETED
value|2
comment|/* Deleted lines. */
define|#
directive|define
name|L_JOINED
value|3
comment|/* Joined lines. */
define|#
directive|define
name|L_MOVED
value|4
comment|/* Moved lines. */
define|#
directive|define
name|L_SHIFT
value|5
comment|/* Shift lines. */
define|#
directive|define
name|L_YANKED
value|6
comment|/* Yanked lines. */
name|recno_t
name|rptlchange
decl_stmt|;
comment|/* Ex/vi: last L_CHANGED lno. */
name|recno_t
name|rptlines
index|[
name|L_YANKED
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Ex/vi: lines changed by last op. */
name|TEXTH
name|tiq
decl_stmt|;
comment|/* Ex/vi: text input queue. */
name|SCRIPT
modifier|*
name|script
decl_stmt|;
comment|/* Vi: script mode information .*/
name|recno_t
name|defscroll
decl_stmt|;
comment|/* Vi: ^D, ^U scroll information. */
comment|/* Display character. */
name|CHAR_T
name|cname
index|[
name|MAX_CHARACTER_COLUMNS
operator|+
literal|1
index|]
decl_stmt|;
name|size_t
name|clen
decl_stmt|;
comment|/* Length of display character. */
enum|enum
block|{
comment|/* Vi editor mode. */
name|SM_APPEND
init|=
literal|0
block|,
name|SM_CHANGE
block|,
name|SM_COMMAND
block|,
name|SM_INSERT
block|,
name|SM_REPLACE
block|}
name|showmode
enum|;
name|void
modifier|*
name|ex_private
decl_stmt|;
comment|/* Ex private area. */
name|void
modifier|*
name|vi_private
decl_stmt|;
comment|/* Vi private area. */
name|void
modifier|*
name|perl_private
decl_stmt|;
comment|/* Perl private area. */
comment|/* PARTIALLY OR COMPLETELY COPIED FROM PREVIOUS SCREEN. */
name|char
modifier|*
name|alt_name
decl_stmt|;
comment|/* Ex/vi: alternate file name. */
name|CHAR_T
name|at_lbuf
decl_stmt|;
comment|/* Ex/vi: Last executed at buffer. */
comment|/* Ex/vi: re_compile flags. */
define|#
directive|define
name|RE_C_CSCOPE
value|0x0001
comment|/* Compile cscope pattern. */
define|#
directive|define
name|RE_C_SEARCH
value|0x0002
comment|/* Compile search replacement. */
define|#
directive|define
name|RE_C_SILENT
value|0x0004
comment|/* No error messages. */
define|#
directive|define
name|RE_C_SUBST
value|0x0008
comment|/* Compile substitute replacement. */
define|#
directive|define
name|RE_C_TAG
value|0x0010
comment|/* Compile ctag pattern. */
define|#
directive|define
name|RE_WSTART
value|"[[:<:]]"
comment|/* Ex/vi: not-in-word search pattern. */
define|#
directive|define
name|RE_WSTOP
value|"[[:>:]]"
comment|/* Ex/vi: flags to search routines. */
define|#
directive|define
name|SEARCH_CSCOPE
value|0x0001
comment|/* Search for a cscope pattern. */
define|#
directive|define
name|SEARCH_EOL
value|0x0002
comment|/* Offset past EOL is okay. */
define|#
directive|define
name|SEARCH_FILE
value|0x0004
comment|/* Search the entire file. */
define|#
directive|define
name|SEARCH_INCR
value|0x0008
comment|/* Search incrementally. */
define|#
directive|define
name|SEARCH_MSG
value|0x0010
comment|/* Display search messages. */
define|#
directive|define
name|SEARCH_PARSE
value|0x0020
comment|/* Parse the search pattern. */
define|#
directive|define
name|SEARCH_SET
value|0x0040
comment|/* Set search direction. */
define|#
directive|define
name|SEARCH_TAG
value|0x0080
comment|/* Search for a tag pattern. */
define|#
directive|define
name|SEARCH_WMSG
value|0x0100
comment|/* Display search-wrapped messages. */
comment|/* Ex/vi: RE information. */
name|dir_t
name|searchdir
decl_stmt|;
comment|/* Last file search direction. */
name|regex_t
name|re_c
decl_stmt|;
comment|/* Search RE: compiled form. */
name|char
modifier|*
name|re
decl_stmt|;
comment|/* Search RE: uncompiled form. */
name|size_t
name|re_len
decl_stmt|;
comment|/* Search RE: uncompiled length. */
name|regex_t
name|subre_c
decl_stmt|;
comment|/* Substitute RE: compiled form. */
name|char
modifier|*
name|subre
decl_stmt|;
comment|/* Substitute RE: uncompiled form. */
name|size_t
name|subre_len
decl_stmt|;
comment|/* Substitute RE: uncompiled length). */
name|char
modifier|*
name|repl
decl_stmt|;
comment|/* Substitute replacement. */
name|size_t
name|repl_len
decl_stmt|;
comment|/* Substitute replacement length.*/
name|size_t
modifier|*
name|newl
decl_stmt|;
comment|/* Newline offset array. */
name|size_t
name|newl_len
decl_stmt|;
comment|/* Newline array size. */
name|size_t
name|newl_cnt
decl_stmt|;
comment|/* Newlines in replacement. */
name|u_int8_t
name|c_suffix
decl_stmt|;
comment|/* Edcompatible 'c' suffix value. */
name|u_int8_t
name|g_suffix
decl_stmt|;
comment|/* Edcompatible 'g' suffix value. */
name|OPTION
name|opts
index|[
name|O_OPTIONCOUNT
index|]
decl_stmt|;
comment|/* Ex/vi: Options. */
comment|/*  * Screen flags.  *  * Editor screens.  */
define|#
directive|define
name|SC_EX
value|0x00000001
comment|/* Ex editor. */
define|#
directive|define
name|SC_VI
value|0x00000002
comment|/* Vi editor. */
comment|/*  * Screen formatting flags, first major, then minor.  *  * SC_SCR_EX  *	Ex screen, i.e. cooked mode.  * SC_SCR_VI  *	Vi screen, i.e. raw mode.  * SC_SCR_EXWROTE  *	The editor had to write on the screen behind curses' back, and we can't  *	let curses change anything until the user agrees, e.g. entering the  *	commands :!utility followed by :set.  We have to switch back into the  *	vi "editor" to read the user's command input, but we can't touch the  *	rest of the screen because it's known to be wrong.  * SC_SCR_REFORMAT  *	The expected presentation of the lines on the screen have changed,  *	requiring that the intended screen lines be recalculated.  Implies  *	SC_SCR_REDRAW.  * SC_SCR_REDRAW  *	The screen doesn't correctly represent the file; repaint it.  Note,  *	setting SC_SCR_REDRAW in the current window causes *all* windows to  *	be repainted.  * SC_SCR_CENTER  *	If the current line isn't already on the screen, center it.  * SC_SCR_TOP  *	If the current line isn't already on the screen, put it at the to@.  */
define|#
directive|define
name|SC_SCR_EX
value|0x00000004
comment|/* Screen is in ex mode. */
define|#
directive|define
name|SC_SCR_VI
value|0x00000008
comment|/* Screen is in vi mode. */
define|#
directive|define
name|SC_SCR_EXWROTE
value|0x00000010
comment|/* Ex overwrite: see comment above. */
define|#
directive|define
name|SC_SCR_REFORMAT
value|0x00000020
comment|/* Reformat (refresh). */
define|#
directive|define
name|SC_SCR_REDRAW
value|0x00000040
comment|/* Refresh. */
define|#
directive|define
name|SC_SCR_CENTER
value|0x00000080
comment|/* Center the line if not visible. */
define|#
directive|define
name|SC_SCR_TOP
value|0x00000100
comment|/* Top the line if not visible. */
comment|/* Screen/file changes. */
define|#
directive|define
name|SC_EXIT
value|0x00000200
comment|/* Exiting (not forced). */
define|#
directive|define
name|SC_EXIT_FORCE
value|0x00000400
comment|/* Exiting (forced). */
define|#
directive|define
name|SC_FSWITCH
value|0x00000800
comment|/* Switch underlying files. */
define|#
directive|define
name|SC_SSWITCH
value|0x00001000
comment|/* Switch screens. */
define|#
directive|define
name|SC_ARGNOFREE
value|0x00002000
comment|/* Argument list wasn't allocated. */
define|#
directive|define
name|SC_ARGRECOVER
value|0x00004000
comment|/* Argument list is recovery files. */
define|#
directive|define
name|SC_AT_SET
value|0x00008000
comment|/* Last at buffer set. */
define|#
directive|define
name|SC_COMEDIT
value|0x00010000
comment|/* Colon command-line edit window. */
define|#
directive|define
name|SC_EX_GLOBAL
value|0x00020000
comment|/* Ex: executing a global command. */
define|#
directive|define
name|SC_EX_SILENT
value|0x00040000
comment|/* Ex: batch script. */
define|#
directive|define
name|SC_EX_WAIT_NO
value|0x00080000
comment|/* Ex: don't wait for the user. */
define|#
directive|define
name|SC_EX_WAIT_YES
value|0x00100000
comment|/* Ex:    do wait for the user. */
define|#
directive|define
name|SC_READONLY
value|0x00200000
comment|/* Persistent readonly state. */
define|#
directive|define
name|SC_RE_SEARCH
value|0x00400000
comment|/* Search RE has been compiled. */
define|#
directive|define
name|SC_RE_SUBST
value|0x00800000
comment|/* Substitute RE has been compiled. */
define|#
directive|define
name|SC_SCRIPT
value|0x01000000
comment|/* Shell script window. */
define|#
directive|define
name|SC_STATUS
value|0x02000000
comment|/* Welcome message. */
define|#
directive|define
name|SC_STATUS_CNT
value|0x04000000
comment|/* Welcome message plus file count. */
define|#
directive|define
name|SC_TINPUT
value|0x08000000
comment|/* Doing text input. */
define|#
directive|define
name|SC_TINPUT_INFO
value|0x10000000
comment|/* Doing text input on info line. */
name|u_int32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

end_unit

