begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)screen.h	8.127 (Berkeley) 8/8/94  */
end_comment

begin_comment
comment|/*  * There are minimum values that vi has to have to display a screen.  The  * row minimum is fixed at 1 line for the text, and 1 line for any error  * messages.  The column calculation is a lot trickier.  For example, you  * have to have enough columns to display the line number, not to mention  * guaranteeing that tabstop and shiftwidth values are smaller than the  * current column value.  It's a lot simpler to have a fixed value and not  * worry about it.  *  * XXX  * MINIMUM_SCREEN_COLS is probably wrong.  */
end_comment

begin_define
define|#
directive|define
name|MINIMUM_SCREEN_ROWS
value|2
end_define

begin_define
define|#
directive|define
name|MINIMUM_SCREEN_COLS
value|20
end_define

begin_enum
enum|enum
name|adjust
block|{
comment|/* Screen adjustment operations. */
name|A_DECREASE
block|,
name|A_INCREASE
block|,
name|A_SET
block|}
enum|;
end_enum

begin_enum
enum|enum
name|operation
block|{
comment|/* Line operations. */
name|LINE_APPEND
block|,
name|LINE_DELETE
block|,
name|LINE_INSERT
block|,
name|LINE_RESET
block|}
enum|;
end_enum

begin_enum
enum|enum
name|position
block|{
comment|/* Position operations. */
name|P_BOTTOM
block|,
name|P_FILL
block|,
name|P_MIDDLE
block|,
name|P_TOP
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sctype
block|{
comment|/* Scroll operations. */
name|CNTRL_B
block|,
name|CNTRL_D
block|,
name|CNTRL_E
block|,
name|CNTRL_F
block|,
name|CNTRL_U
block|,
name|CNTRL_Y
block|,
name|Z_CARAT
block|,
name|Z_PLUS
block|}
enum|;
end_enum

begin_comment
comment|/*  * Structure for holding file references.  Each SCR structure contains a  * linked list of these.  The structure contains the name of the file,  * along with the information that follows the name.  *  * !!!  * The read-only bit follows the file name, not the file itself.  *  * XXX  * The mtime field should be a struct timespec, but time_t is more portable.  */
end_comment

begin_struct
struct|struct
name|_fref
block|{
name|CIRCLEQ_ENTRY
argument_list|(
argument|_fref
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of file references. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* File name. */
name|char
modifier|*
name|tname
decl_stmt|;
comment|/* Backing temporary file name. */
name|recno_t
name|lno
decl_stmt|;
comment|/* 1-N: file cursor line. */
name|size_t
name|cno
decl_stmt|;
comment|/* 0-N: file cursor column. */
define|#
directive|define
name|FR_CURSORSET
value|0x001
comment|/* If lno/cno values valid. */
define|#
directive|define
name|FR_DONTDELETE
value|0x002
comment|/* Don't delete the temporary file. */
define|#
directive|define
name|FR_FNONBLANK
value|0x004
comment|/* Move to the first non-<blank>. */
define|#
directive|define
name|FR_NAMECHANGE
value|0x008
comment|/* If the name changed. */
define|#
directive|define
name|FR_NEWFILE
value|0x010
comment|/* File doesn't really exist yet. */
define|#
directive|define
name|FR_RDONLY
value|0x020
comment|/* File is read-only. */
define|#
directive|define
name|FR_READNAMED
value|0x040
comment|/* Read renamed the file. */
define|#
directive|define
name|FR_RECOVER
value|0x080
comment|/* File is being recovered. */
define|#
directive|define
name|FR_TMPEXIT
value|0x100
comment|/* Modified temporary file, no exit. */
define|#
directive|define
name|FR_TMPFILE
value|0x200
comment|/* If file has no name. */
define|#
directive|define
name|FR_UNLOCKED
value|0x400
comment|/* File couldn't be locked. */
name|u_int16_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TEMPORARY_FILE_STRING
value|"/tmp"
end_define

begin_comment
comment|/* Default temporary file name. */
end_comment

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
name|EXF
modifier|*
name|ep
decl_stmt|;
comment|/* Screen's current EXF structure. */
name|MSGH
name|msgq
decl_stmt|;
comment|/* Message list. */
comment|/* FREF list. */
name|CIRCLEQ_HEAD
argument_list|(
argument|_frefh
argument_list|,
argument|_fref
argument_list|)
name|frefq
expr_stmt|;
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
name|woff
decl_stmt|;
comment|/* 0-N: row offset in screen. */
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
name|int
name|rcm_last
decl_stmt|;
comment|/* Cursor drawn to the last column. */
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
name|L_LSHIFT
value|5
comment|/* Left shift lines. */
define|#
directive|define
name|L_RSHIFT
value|6
comment|/* Right shift lines. */
define|#
directive|define
name|L_YANKED
value|7
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
name|FILE
modifier|*
name|stdfp
decl_stmt|;
comment|/* Ex output file pointer. */
name|char
modifier|*
name|if_name
decl_stmt|;
comment|/* Ex input file name, for messages. */
name|recno_t
name|if_lno
decl_stmt|;
comment|/* Ex input file line, for messages. */
name|fd_set
name|rdfd
decl_stmt|;
comment|/* Ex/vi: read fd select mask. */
name|TEXTH
name|__tiq
decl_stmt|;
comment|/* Ex/vi: text input queue. */
name|TEXTH
modifier|*
name|tiqp
decl_stmt|;
comment|/* Ex/vi: text input queue reference. */
name|SCRIPT
modifier|*
name|script
decl_stmt|;
comment|/* Vi: script mode information .*/
name|recno_t
name|defscroll
decl_stmt|;
comment|/* Vi: ^D, ^U scroll information. */
name|struct
name|timeval
name|busy_tod
decl_stmt|;
comment|/* ITIMER_REAL: busy time-of-day. */
name|char
specifier|const
modifier|*
name|busy_msg
decl_stmt|;
comment|/* ITIMER_REAL: busy message. */
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
define|#
directive|define
name|MAX_MODE_NAME
value|12
name|char
modifier|*
name|showmode
decl_stmt|;
comment|/* Mode. */
name|void
modifier|*
name|ex_private
decl_stmt|;
comment|/* Ex private area. */
name|void
modifier|*
name|sex_private
decl_stmt|;
comment|/* Ex screen private area. */
name|void
modifier|*
name|vi_private
decl_stmt|;
comment|/* Vi private area. */
name|void
modifier|*
name|svi_private
decl_stmt|;
comment|/* Vi curses screen private area. */
name|void
modifier|*
name|xaw_private
decl_stmt|;
comment|/* Vi XAW screen private area. */
comment|/* PARTIALLY OR COMPLETELY COPIED FROM PREVIOUS SCREEN. */
name|char
modifier|*
name|alt_name
decl_stmt|;
comment|/* Ex/vi: alternate file name. */
comment|/* Ex/vi: search/substitute info. */
name|regex_t
name|sre
decl_stmt|;
comment|/* Last search RE. */
name|regex_t
name|subre
decl_stmt|;
comment|/* Last substitute RE. */
name|enum
name|direction
name|searchdir
decl_stmt|;
comment|/* File search direction. */
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
name|u_char
name|c_suffix
decl_stmt|;
comment|/* Edcompatible 'c' suffix value. */
name|u_char
name|g_suffix
decl_stmt|;
comment|/* Edcompatible 'g' suffix value. */
name|u_int
name|saved_vi_mode
decl_stmt|;
comment|/* Saved vi display type. */
name|OPTION
name|opts
index|[
name|O_OPTIONCOUNT
index|]
decl_stmt|;
comment|/* Options. */
comment|/*  * SCREEN SUPPORT ROUTINES.  *  * A SCR * MUST be the first argument to these routines.  */
comment|/* Ring the screen bell. */
name|void
argument_list|(
argument|*s_bell
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Background the screen. */
name|int
argument_list|(
argument|*s_bg
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Put up a busy message. */
name|int
argument_list|(
argument|*s_busy
argument_list|)
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
expr_stmt|;
comment|/* Change a screen line. */
name|int
argument_list|(
argument|*s_change
argument_list|)
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
expr_stmt|;
comment|/* Clear the screen. */
name|int
argument_list|(
argument|*s_clear
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Return column close to specified. */
name|size_t
argument_list|(
argument|*s_colpos
argument_list|)
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
expr_stmt|;
comment|/* Return the logical cursor column. */
name|int
argument_list|(
argument|*s_column
argument_list|)
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
expr_stmt|;
name|enum
name|confirm
comment|/* Confirm an action with the user. */
argument_list|(
operator|*
name|s_confirm
argument_list|)
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
comment|/* Change the relative screen size. */
name|int
argument_list|(
argument|*s_crel
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|long
operator|)
argument_list|)
expr_stmt|;
comment|/* Edit a file. */
name|int
argument_list|(
argument|*s_edit
argument_list|)
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
expr_stmt|;
comment|/* End a screen. */
name|int
argument_list|(
argument|*s_end
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Run a single ex command. */
name|int
argument_list|(
argument|*s_ex_cmd
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|EXCMDARG
operator|*
operator|,
name|MARK
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Run user's ex commands. */
name|int
argument_list|(
argument|*s_ex_run
argument_list|)
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
expr_stmt|;
comment|/* Screen's ex write function. */
name|int
argument_list|(
argument|*s_ex_write
argument_list|)
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
expr_stmt|;
comment|/* Foreground the screen. */
name|int
argument_list|(
argument|*s_fg
argument_list|)
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
expr_stmt|;
comment|/* Fill the screen's map. */
name|int
argument_list|(
argument|*s_fill
argument_list|)
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
expr_stmt|;
name|enum
name|input
comment|/* Get a line from the user. */
argument_list|(
operator|*
name|s_get
argument_list|)
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
name|ARG_CHAR_T
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
name|enum
name|input
comment|/* Get a key from the user. */
argument_list|(
operator|*
name|s_key_read
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|*
operator|,
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* Map a function key. */
name|int
argument_list|(
argument|*s_fmap
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
expr|enum
name|seqtype
operator|,
name|CHAR_T
operator|*
operator|,
name|size_t
operator|,
name|CHAR_T
operator|*
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Tell the screen an option changed. */
name|int
argument_list|(
argument|*s_optchange
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Return column at screen position. */
name|int
argument_list|(
argument|*s_position
argument_list|)
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
expr_stmt|;
comment|/* Change the absolute screen size. */
name|int
argument_list|(
argument|*s_rabs
argument_list|)
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
expr_stmt|;
comment|/* Return column close to selection. */
name|size_t
argument_list|(
argument|*s_rcm
argument_list|)
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
expr_stmt|;
comment|/* Refresh the screen. */
name|int
argument_list|(
argument|*s_refresh
argument_list|)
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
expr_stmt|;
comment|/* Move down the screen. */
name|int
argument_list|(
argument|*s_scroll
argument_list|)
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
expr|enum
name|sctype
operator|)
argument_list|)
expr_stmt|;
comment|/* Split the screen. */
name|int
argument_list|(
argument|*s_split
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|ARGS
operator|*
index|[]
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Suspend the screen. */
name|int
argument_list|(
argument|*s_suspend
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Set the window size. */
name|int
argument_list|(
argument|*s_window
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Editor screens. */
define|#
directive|define
name|S_EX
value|0x0000001
comment|/* Ex screen. */
define|#
directive|define
name|S_VI_CURSES
value|0x0000002
comment|/* Vi: curses screen. */
define|#
directive|define
name|S_VI_XAW
value|0x0000004
comment|/* Vi: Athena widgets screen. */
define|#
directive|define
name|IN_EX_MODE
parameter_list|(
name|sp
parameter_list|)
comment|/* If in ex mode. */
define|\
value|(F_ISSET(sp, S_EX))
define|#
directive|define
name|IN_VI_MODE
parameter_list|(
name|sp
parameter_list|)
comment|/* If in vi mode. */
define|\
value|(F_ISSET(sp, S_VI_CURSES | S_VI_XAW))
define|#
directive|define
name|S_SCREENS
comment|/* Screens. */
define|\
value|(S_EX | S_VI_CURSES | S_VI_XAW)
comment|/* Major screen/file changes. */
define|#
directive|define
name|S_EXIT
value|0x0000008
comment|/* Exiting (not forced). */
define|#
directive|define
name|S_EXIT_FORCE
value|0x0000010
comment|/* Exiting (forced). */
define|#
directive|define
name|S_FSWITCH
value|0x0000020
comment|/* Switch files. */
define|#
directive|define
name|S_SSWITCH
value|0x0000040
comment|/* Switch screens. */
define|#
directive|define
name|S_MAJOR_CHANGE
comment|/* Screen or file changes. */
define|\
value|(S_EXIT | S_EXIT_FORCE | S_FSWITCH | S_SSWITCH)
define|#
directive|define
name|S_ARGNOFREE
value|0x0000080
comment|/* Argument list wasn't allocated. */
define|#
directive|define
name|S_ARGRECOVER
value|0x0000100
comment|/* Argument list is recovery files. */
define|#
directive|define
name|S_BELLSCHED
value|0x0000200
comment|/* Bell scheduled. */
define|#
directive|define
name|S_CONTINUE
value|0x0000400
comment|/* Need to ask the user to continue. */
define|#
directive|define
name|S_EXSILENT
value|0x0000800
comment|/* Ex batch script. */
define|#
directive|define
name|S_GLOBAL
value|0x0001000
comment|/* Doing a global command. */
define|#
directive|define
name|S_INPUT
value|0x0002000
comment|/* Doing text input. */
define|#
directive|define
name|S_INTERRUPTED
value|0x0004000
comment|/* If have been interrupted. */
define|#
directive|define
name|S_INTERRUPTIBLE
value|0x0008000
comment|/* If can be interrupted. */
define|#
directive|define
name|S_IVIDEO
value|0x0010000
comment|/* Display in inverse video. */
define|#
directive|define
name|S_REDRAW
value|0x0020000
comment|/* Redraw the screen. */
define|#
directive|define
name|S_REFORMAT
value|0x0040000
comment|/* Reformat the screen. */
define|#
directive|define
name|S_REFRESH
value|0x0080000
comment|/* Refresh the screen. */
define|#
directive|define
name|S_RENUMBER
value|0x0100000
comment|/* Renumber the screen. */
define|#
directive|define
name|S_RESIZE
value|0x0200000
comment|/* Resize the screen. */
define|#
directive|define
name|S_SCRIPT
value|0x0400000
comment|/* Window is a shell script. */
define|#
directive|define
name|S_SRE_SET
value|0x0800000
comment|/* The search RE has been set. */
define|#
directive|define
name|S_SUBRE_SET
value|0x1000000
comment|/* The substitute RE has been set. */
define|#
directive|define
name|S_UPDATE_MODE
value|0x2000000
comment|/* Don't repaint modeline. */
define|#
directive|define
name|S_VLITONLY
value|0x4000000
comment|/* ^V literal next only. */
name|u_int32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Signals/timers have no structure, so it's all here.  *  * Block all signals that are being handled.  Used to keep the underlying DB  * system calls from being interrupted and not restarted, as it could cause  * consistency problems.  Also used when vi forks child processes, to avoid  * a signal arriving after the fork and before the exec, causing both parent  * and child to attempt recovery processing.  */
end_comment

begin_define
define|#
directive|define
name|SIGBLOCK
parameter_list|(
name|gp
parameter_list|)
define|\
value|(void)sigprocmask(SIG_BLOCK,&(gp)->blockset, NULL);
end_define

begin_define
define|#
directive|define
name|SIGUNBLOCK
parameter_list|(
name|gp
parameter_list|)
define|\
value|(void)sigprocmask(SIG_UNBLOCK,&(gp)->blockset, NULL);
end_define

begin_decl_stmt
name|void
name|busy_off
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
name|busy_on
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
name|void
name|sig_end
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
name|sig_init
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
comment|/* Generic routines to start/stop a screen. */
end_comment

begin_decl_stmt
name|int
name|screen_end
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
name|screen_init
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
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Public interfaces to the underlying screens. */
end_comment

begin_decl_stmt
name|int
name|ex_screen_copy
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
name|ex_screen_end
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
name|ex_screen_init
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
name|sex_screen_copy
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
name|sex_screen_end
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
name|sex_screen_init
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
name|svi_screen_init
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
name|v_screen_copy
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
name|v_screen_end
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
name|v_screen_init
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
name|xaw_screen_copy
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
name|xaw_screen_end
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
name|xaw_screen_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

