begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ex_vis.h	7.5 (Berkeley) 3/9/87  */
end_comment

begin_comment
comment|/*  * Ex version 3  * Mark Horton, UCB  * Bill Joy UCB  *  * Open and visual mode definitions.  *   * There are actually 4 major states in open/visual modes.  These  * are visual, crt open (where the cursor can move about the screen and  * the screen can scroll and be erased), one line open (on dumb glass-crt's  * like the adm3), and hardcopy open (for everything else).  *  * The basic state is given by bastate, and the current state by state,  * since we can be in pseudo-hardcopy mode if we are on an adm3 and the  * line is longer than 80.  */
end_comment

begin_decl_stmt
name|var
name|short
name|bastate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|short
name|state
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VISUAL
value|0
end_define

begin_define
define|#
directive|define
name|CRTOPEN
value|1
end_define

begin_define
define|#
directive|define
name|ONEOPEN
value|2
end_define

begin_define
define|#
directive|define
name|HARDOPEN
value|3
end_define

begin_comment
comment|/*  * The screen in visual and crtopen is of varying size; the basic  * window has top basWTOP and basWLINES lines are thereby implied.  * The current window (which may have grown from the basic size)  * has top WTOP and WLINES lines.  The top line of the window is WTOP,  * and the bottom line WBOT.  The line WECHO is used for messages,  * search strings and the like.  If WBOT==WECHO then we are in ONEOPEN  * or HARDOPEN and there is no way back to the line we were on if we  * go to WECHO (i.e. we will have to scroll before we go there, and  * we can't get back).  There are WCOLS columns per line.  * If WBOT!=WECHO then WECHO will be the last line on the screen  * and WBOT is the line before it.  */
end_comment

begin_decl_stmt
name|var
name|short
name|basWTOP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|short
name|basWLINES
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|short
name|WTOP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|short
name|WBOT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|short
name|WLINES
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|short
name|WCOLS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|short
name|WECHO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * When we are dealing with the echo area we consider the window  * to be "split" and set the variable splitw.  Otherwise, moving  * off the bottom of the screen into WECHO causes a screen rollup.  */
end_comment

begin_decl_stmt
name|var
name|bool
name|splitw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Information about each line currently on the screen includes  * the y coordinate associated with the line, the printing depth  * of the line (0 indicates unknown), and a mask which indicates  * whether the line is "unclean", i.e. whether we should check  * to make sure the line is displayed correctly at the next  * appropriate juncture.  */
end_comment

begin_struct
struct|struct
name|vlinfo
block|{
name|short
name|vliny
decl_stmt|;
comment|/* Y coordinate */
comment|/* mjm: was char */
name|short
name|vdepth
decl_stmt|;
comment|/* Depth of displayed line */
comment|/*mjm: was char */
name|short
name|vflags
decl_stmt|;
comment|/* Is line potentially dirty ? */
block|}
struct|;
end_struct

begin_decl_stmt
name|var
name|struct
name|vlinfo
name|vlinfo
index|[
name|TUBELINES
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEPTH
parameter_list|(
name|c
parameter_list|)
value|(vlinfo[c].vdepth)
end_define

begin_define
define|#
directive|define
name|LINE
parameter_list|(
name|c
parameter_list|)
value|(vlinfo[c].vliny)
end_define

begin_define
define|#
directive|define
name|FLAGS
parameter_list|(
name|c
parameter_list|)
value|(vlinfo[c].vflags)
end_define

begin_define
define|#
directive|define
name|VDIRT
value|1
end_define

begin_comment
comment|/*  * Hacks to copy vlinfo structures around  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V6
end_ifdef

begin_comment
comment|/* Kludge to make up for no structure assignment */
end_comment

begin_struct
struct|struct
block|{
name|long
name|longi
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|vlcopy
parameter_list|(
name|i
parameter_list|,
name|j
parameter_list|)
value|i.longi = j.longi
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vlcopy
parameter_list|(
name|i
parameter_list|,
name|j
parameter_list|)
value|i = j;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The current line on the screen is represented by vcline.  * There are vcnt lines on the screen, the last being "vcnt - 1".  * Vcline is intimately tied to the current value of dot,  * and when command mode is used as a subroutine fancy footwork occurs.  */
end_comment

begin_decl_stmt
name|var
name|short
name|vcline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|short
name|vcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * To allow many optimizations on output, an exact image of the terminal  * screen is maintained in the space addressed by vtube0.  The vtube  * array indexes this space as lines, and is shuffled on scrolls, insert+delete  * lines and the like rather than (more expensively) shuffling the screen  * data itself.  It is also rearranged during insert mode across line  * boundaries to make incore work easier.  */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|vtube
index|[
name|TUBELINES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|char
modifier|*
name|vtube0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The current cursor position within the current line is kept in  * cursor.  The current line is kept in linebuf.  During insertions  * we use the auxiliary array genbuf as scratch area.  * The cursor wcursor and wdot are used in operations within/spanning  * lines to mark the other end of the affected area, or the target  * for a motion.  */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|cursor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|char
modifier|*
name|wcursor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|line
modifier|*
name|wdot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Undo information is saved in a LBSIZE buffer at "vutmp" for changes  * within the current line, or as for command mode for multi-line changes  * or changes on lines no longer the current line.  * The change kind "VCAPU" is used immediately after a U undo to prevent  * two successive U undo's from destroying the previous state.  */
end_comment

begin_define
define|#
directive|define
name|VNONE
value|0
end_define

begin_define
define|#
directive|define
name|VCHNG
value|1
end_define

begin_define
define|#
directive|define
name|VMANY
value|2
end_define

begin_define
define|#
directive|define
name|VCAPU
value|3
end_define

begin_define
define|#
directive|define
name|VMCHNG
value|4
end_define

begin_define
define|#
directive|define
name|VMANYINS
value|5
end_define

begin_decl_stmt
name|var
name|short
name|vundkind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Which kind of undo - from above */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|vutmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prev line image when "VCHNG" */
end_comment

begin_comment
comment|/*  * State information for undoing of macros.  The basic idea is that  * if the macro does only 1 change or even none, we don't treat it  * specially.  If it does 2 or more changes we want to be able to  * undo it as a unit.  We remember how many changes have been made  * within the current macro.  (Remember macros can be nested.)  */
end_comment

begin_define
define|#
directive|define
name|VC_NOTINMAC
value|0
end_define

begin_comment
comment|/* Not in a macro */
end_comment

begin_define
define|#
directive|define
name|VC_NOCHANGE
value|1
end_define

begin_comment
comment|/* In a macro, no changes so far */
end_comment

begin_define
define|#
directive|define
name|VC_ONECHANGE
value|2
end_define

begin_comment
comment|/* In a macro, one change so far */
end_comment

begin_define
define|#
directive|define
name|VC_MANYCHANGE
value|3
end_define

begin_comment
comment|/* In a macro, at least 2 changes so far */
end_comment

begin_decl_stmt
name|var
name|short
name|vch_mac
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Change state - one of the above */
end_comment

begin_comment
comment|/*  * For U undo's the line is grabbed by "vmove" after it first appears  * on that line.  The "vUNDdot" which specifies which line has been  * saved is selectively cleared when changes involving other lines  * are made, i.e. after a 'J' join.  This is because a 'JU' would  * lose completely the text of the line just joined on.  */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|vUNDcurs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cursor just before 'U' */
end_comment

begin_decl_stmt
name|var
name|line
modifier|*
name|vUNDdot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The line address of line saved in vUNDsav */
end_comment

begin_decl_stmt
name|var
name|line
name|vUNDsav
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Grabbed initial "*dot" */
end_comment

begin_define
define|#
directive|define
name|killU
parameter_list|()
value|vUNDdot = NOLINE
end_define

begin_comment
comment|/*  * There are a number of cases where special behaviour is needed  * from deeply nested routines.  This is accomplished by setting  * the bits of hold, which acts to change the state of the general  * visual editing behaviour in specific ways.  *  * HOLDAT prevents the clreol (clear to end of line) routines from  * putting out @'s or ~'s on empty lines.  *  * HOLDDOL prevents the reopen routine from putting a '$' at the  * end of a reopened line in list mode (for hardcopy mode, e.g.).  *  * HOLDROL prevents spurious blank lines when scrolling in hardcopy  * open mode.  *  * HOLDQIK prevents the fake insert mode during repeated commands.  *  * HOLDPUPD prevents updating of the physical screen image when  * mucking around while in insert mode.  *  * HOLDECH prevents clearing of the echo area while rolling the screen  * backwards (e.g.) in deference to the clearing of the area at the  * end of the scroll (1 time instead of n times).  The fact that this  * is actually needed is recorded in heldech, which says that a clear  * of the echo area was actually held off.  */
end_comment

begin_decl_stmt
name|var
name|short
name|hold
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|short
name|holdupd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hold off update when echo line is too long */
end_comment

begin_define
define|#
directive|define
name|HOLDAT
value|1
end_define

begin_define
define|#
directive|define
name|HOLDDOL
value|2
end_define

begin_define
define|#
directive|define
name|HOLDROL
value|4
end_define

begin_define
define|#
directive|define
name|HOLDQIK
value|8
end_define

begin_define
define|#
directive|define
name|HOLDPUPD
value|16
end_define

begin_define
define|#
directive|define
name|HOLDECH
value|32
end_define

begin_define
define|#
directive|define
name|HOLDWIG
value|64
end_define

begin_comment
comment|/*  * Miscellaneous variables  */
end_comment

begin_decl_stmt
name|var
name|short
name|CDCNT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Count of ^D's in insert on this line */
end_comment

begin_decl_stmt
name|var
name|char
name|DEL
index|[
name|VBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last deleted text */
end_comment

begin_decl_stmt
name|var
name|bool
name|HADUP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This insert line started with ^ then ^D */
end_comment

begin_decl_stmt
name|var
name|bool
name|HADZERO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This insert line started with 0 then ^D */
end_comment

begin_decl_stmt
name|var
name|char
name|INS
index|[
name|VBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last inserted text */
end_comment

begin_decl_stmt
name|var
name|int
name|Vlines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of file lines "before" vi command */
end_comment

begin_decl_stmt
name|var
name|int
name|Xcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* External variable holding last cmd's count */
end_comment

begin_decl_stmt
name|var
name|bool
name|Xhadcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last command had explicit count? */
end_comment

begin_decl_stmt
name|var
name|short
name|ex_ZERO
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|short
name|dir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Direction for search (+1 or -1) */
end_comment

begin_decl_stmt
name|var
name|short
name|doomed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Disply chars right of cursor to be killed */
end_comment

begin_decl_stmt
name|var
name|bool
name|gobblebl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Wrapmargin space generated nl, eat a space */
end_comment

begin_decl_stmt
name|var
name|bool
name|hadcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* (Almost) internal to vmain() */
end_comment

begin_decl_stmt
name|var
name|bool
name|heldech
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We owe a clear of echo area */
end_comment

begin_decl_stmt
name|var
name|bool
name|insmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are in character insert mode */
end_comment

begin_decl_stmt
name|var
name|char
name|lastcmd
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chars in last command */
end_comment

begin_decl_stmt
name|var
name|int
name|lastcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Count for last command */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|lastcp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save current command here to repeat */
end_comment

begin_decl_stmt
name|var
name|bool
name|lasthad
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last command had a count? */
end_comment

begin_decl_stmt
name|var
name|short
name|lastvgk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Previous input key, if not from keyboard */
end_comment

begin_decl_stmt
name|var
name|short
name|lastreg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Register with last command */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|ncols
index|[
literal|'z'
operator|-
literal|'a'
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cursor positions of marks */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|notenam
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name to be noted with change count */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|notesgn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Change count from last command */
end_comment

begin_decl_stmt
name|var
name|char
name|op
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Operation of current command */
end_comment

begin_decl_stmt
name|var
name|short
name|Peek_key
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Peek ahead key */
end_comment

begin_decl_stmt
name|var
name|bool
name|rubble
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Line is filthy (in hardcopy open), redraw! */
end_comment

begin_decl_stmt
name|var
name|int
name|ex_vSCROLL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number lines to scroll on ^D/^U */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|vglobp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Untyped input (e.g. repeat insert text) */
end_comment

begin_decl_stmt
name|var
name|char
name|vmacbuf
index|[
name|VBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Text of visual macro, hence nonnestable */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|vmacp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like vglobp but for visual macros */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|vmcurs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cursor for restore after undo d), e.g. */
end_comment

begin_decl_stmt
name|var
name|short
name|vmovcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Column to try to keep on arrow keys */
end_comment

begin_decl_stmt
name|var
name|bool
name|vmoving
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are trying to keep vmovcol */
end_comment

begin_decl_stmt
name|var
name|short
name|vreg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reg for this command */
end_comment

begin_comment
comment|/* mjm: was char */
end_comment

begin_decl_stmt
name|var
name|short
name|wdkind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Liberal/conservative words? */
end_comment

begin_decl_stmt
name|var
name|char
name|workcmd
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temporary for lastcmd */
end_comment

begin_comment
comment|/*  * Macros  */
end_comment

begin_define
define|#
directive|define
name|INF
value|30000
end_define

begin_define
define|#
directive|define
name|LASTLINE
value|LINE(vcnt)
end_define

begin_define
define|#
directive|define
name|OVERBUF
value|QUOTE
end_define

begin_define
define|#
directive|define
name|beep
value|obeep
end_define

begin_define
define|#
directive|define
name|cindent
parameter_list|()
value|((outline - vlinfo[vcline].vliny) * WCOLS + outcol)
end_define

begin_define
define|#
directive|define
name|vputp
parameter_list|(
name|cp
parameter_list|,
name|cnt
parameter_list|)
value|tputs(cp, cnt, vputch)
end_define

begin_define
define|#
directive|define
name|vputc
parameter_list|(
name|c
parameter_list|)
value|putch(c)
end_define

begin_comment
comment|/*  * Function types  */
end_comment

begin_function_decl
name|int
name|beep
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|qcount
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vchange
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vdelete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vgrabit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vinschar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vputchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vshift
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vyankit
parameter_list|()
function_decl|;
end_function_decl

end_unit

