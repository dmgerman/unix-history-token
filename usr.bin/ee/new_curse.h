begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  |	new_curse.h  |  |	A subset of curses developed for use with ae.  |  |	written by Hugh Mahon  |  |	THIS MATERIAL IS PROVIDED "AS IS".  THERE ARE  |	NO WARRANTIES OF ANY KIND WITH REGARD TO THIS  |	MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE  |	IMPLIED WARRANTIES OF MERCHANTABILITY AND  |	FITNESS FOR A PARTICULAR PURPOSE.  Neither  |	Hewlett-Packard nor Hugh Mahon shall be liable  |	for errors contained herein, nor for  |	incidental or consequential damages in  |	connection with the furnishing, performance or  |	use of this material.  Neither Hewlett-Packard  |	nor Hugh Mahon assumes any responsibility for  |	the use or reliability of this software or  |	documentation.  This software and  |	documentation is totally UNSUPPORTED.  There  |	is no support contract available.  Hewlett-  |	Packard has done NO Quality Assurance on ANY  |	of the program or documentation.  You may find  |	the quality of the materials inferior to  |	supported materials.  |  |	This software is not a product of Hewlett-Packard, Co., or any   |	other company.  No support is implied or offered with this software.  |	You've got the source, and you're on your own.  |  |	This software may be distributed under the terms of Larry Wall's   |	Artistic license, a copy of which is included in this distribution.   |  |	This notice must be included with this software and any derivatives.  |  |	Copyright (c) 1986, 1987, 1988, 1991, 1995 Hugh Mahon  |	All are rights reserved.  |  | $FreeBSD$  |  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SYS5
end_ifdef

begin_include
include|#
directive|include
file|<termio.h>
end_include

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
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KEY_BREAK
value|0401
end_define

begin_define
define|#
directive|define
name|KEY_DOWN
value|0402
end_define

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

begin_define
define|#
directive|define
name|KEY_HOME
value|0406
end_define

begin_define
define|#
directive|define
name|KEY_BACKSPACE
value|0407
end_define

begin_define
define|#
directive|define
name|KEY_F0
value|0410
end_define

begin_define
define|#
directive|define
name|KEY_F
parameter_list|(
name|n
parameter_list|)
value|(KEY_F0+(n))
end_define

begin_define
define|#
directive|define
name|KEY_DL
value|0510
end_define

begin_define
define|#
directive|define
name|KEY_IL
value|0511
end_define

begin_define
define|#
directive|define
name|KEY_DC
value|0512
end_define

begin_define
define|#
directive|define
name|KEY_IC
value|0513
end_define

begin_define
define|#
directive|define
name|KEY_EIC
value|0514
end_define

begin_define
define|#
directive|define
name|KEY_CLEAR
value|0515
end_define

begin_define
define|#
directive|define
name|KEY_EOS
value|0516
end_define

begin_define
define|#
directive|define
name|KEY_EOL
value|0517
end_define

begin_define
define|#
directive|define
name|KEY_SF
value|0520
end_define

begin_define
define|#
directive|define
name|KEY_SR
value|0521
end_define

begin_define
define|#
directive|define
name|KEY_NPAGE
value|0522
end_define

begin_define
define|#
directive|define
name|KEY_PPAGE
value|0523
end_define

begin_define
define|#
directive|define
name|KEY_STAB
value|0524
end_define

begin_define
define|#
directive|define
name|KEY_CTAB
value|0525
end_define

begin_define
define|#
directive|define
name|KEY_CATAB
value|0526
end_define

begin_define
define|#
directive|define
name|KEY_ENTER
value|0527
end_define

begin_define
define|#
directive|define
name|KEY_SRESET
value|0530
end_define

begin_define
define|#
directive|define
name|KEY_RESET
value|0531
end_define

begin_define
define|#
directive|define
name|KEY_PRINT
value|0532
end_define

begin_define
define|#
directive|define
name|KEY_LL
value|0533
end_define

begin_define
define|#
directive|define
name|KEY_A1
value|0534
end_define

begin_define
define|#
directive|define
name|KEY_A3
value|0535
end_define

begin_define
define|#
directive|define
name|KEY_B2
value|0536
end_define

begin_define
define|#
directive|define
name|KEY_C1
value|0537
end_define

begin_define
define|#
directive|define
name|KEY_C3
value|0540
end_define

begin_define
define|#
directive|define
name|KEY_BTAB
value|0541
end_define

begin_define
define|#
directive|define
name|KEY_BEG
value|0542
end_define

begin_define
define|#
directive|define
name|KEY_CANCEL
value|0543
end_define

begin_define
define|#
directive|define
name|KEY_CLOSE
value|0544
end_define

begin_define
define|#
directive|define
name|KEY_COMMAND
value|0545
end_define

begin_define
define|#
directive|define
name|KEY_COPY
value|0546
end_define

begin_define
define|#
directive|define
name|KEY_CREATE
value|0547
end_define

begin_define
define|#
directive|define
name|KEY_END
value|0550
end_define

begin_define
define|#
directive|define
name|KEY_EXIT
value|0551
end_define

begin_define
define|#
directive|define
name|KEY_FIND
value|0552
end_define

begin_define
define|#
directive|define
name|KEY_HELP
value|0553
end_define

begin_define
define|#
directive|define
name|KEY_MARK
value|0554
end_define

begin_define
define|#
directive|define
name|KEY_MESSAGE
value|0555
end_define

begin_define
define|#
directive|define
name|KEY_MOVE
value|0556
end_define

begin_define
define|#
directive|define
name|KEY_NEXT
value|0557
end_define

begin_define
define|#
directive|define
name|KEY_OPEN
value|0560
end_define

begin_define
define|#
directive|define
name|KEY_OPTIONS
value|0561
end_define

begin_define
define|#
directive|define
name|KEY_PREVIOUS
value|0562
end_define

begin_define
define|#
directive|define
name|KEY_REDO
value|0563
end_define

begin_define
define|#
directive|define
name|KEY_REFERENCE
value|0564
end_define

begin_define
define|#
directive|define
name|KEY_REFRESH
value|0565
end_define

begin_define
define|#
directive|define
name|KEY_REPLACE
value|0566
end_define

begin_define
define|#
directive|define
name|KEY_RESTART
value|0567
end_define

begin_define
define|#
directive|define
name|KEY_RESUME
value|0570
end_define

begin_define
define|#
directive|define
name|KEY_SAVE
value|0571
end_define

begin_define
define|#
directive|define
name|KEY_SBEG
value|0572
end_define

begin_define
define|#
directive|define
name|KEY_SCANCEL
value|0573
end_define

begin_define
define|#
directive|define
name|KEY_SCOMMAND
value|0574
end_define

begin_define
define|#
directive|define
name|KEY_SCOPY
value|0575
end_define

begin_define
define|#
directive|define
name|KEY_SCREATE
value|0576
end_define

begin_define
define|#
directive|define
name|KEY_SDC
value|0577
end_define

begin_define
define|#
directive|define
name|KEY_SDL
value|0600
end_define

begin_define
define|#
directive|define
name|KEY_SELECT
value|0601
end_define

begin_define
define|#
directive|define
name|KEY_SEND
value|0602
end_define

begin_define
define|#
directive|define
name|KEY_SEOL
value|0603
end_define

begin_define
define|#
directive|define
name|KEY_SEXIT
value|0604
end_define

begin_define
define|#
directive|define
name|KEY_SFIND
value|0605
end_define

begin_define
define|#
directive|define
name|KEY_SHELP
value|0606
end_define

begin_define
define|#
directive|define
name|KEY_SHOME
value|0607
end_define

begin_define
define|#
directive|define
name|KEY_SIC
value|0610
end_define

begin_define
define|#
directive|define
name|KEY_SLEFT
value|0611
end_define

begin_define
define|#
directive|define
name|KEY_SMESSAGE
value|0612
end_define

begin_define
define|#
directive|define
name|KEY_SMOVE
value|0613
end_define

begin_define
define|#
directive|define
name|KEY_SNEXT
value|0614
end_define

begin_define
define|#
directive|define
name|KEY_SOPTIONS
value|0615
end_define

begin_define
define|#
directive|define
name|KEY_SPREVIOUS
value|0616
end_define

begin_define
define|#
directive|define
name|KEY_SPRINT
value|0617
end_define

begin_define
define|#
directive|define
name|KEY_SREDO
value|0620
end_define

begin_define
define|#
directive|define
name|KEY_SREPLACE
value|0621
end_define

begin_define
define|#
directive|define
name|KEY_SRIGHT
value|0622
end_define

begin_define
define|#
directive|define
name|KEY_SRSUME
value|0623
end_define

begin_define
define|#
directive|define
name|KEY_SSAVE
value|0624
end_define

begin_define
define|#
directive|define
name|KEY_SSUSPEND
value|0625
end_define

begin_define
define|#
directive|define
name|KEY_SUNDO
value|0626
end_define

begin_define
define|#
directive|define
name|KEY_SUSPEND
value|0627
end_define

begin_define
define|#
directive|define
name|KEY_UNDO
value|0630
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|A_STANDOUT
value|0001
end_define

begin_comment
comment|/* standout mode		*/
end_comment

begin_define
define|#
directive|define
name|A_NC_BIG5
value|0x0100
end_define

begin_comment
comment|/* Handle Chinese Big5 characters	*/
end_comment

begin_define
define|#
directive|define
name|SCROLL
value|1
end_define

begin_comment
comment|/* text has been scrolled	*/
end_comment

begin_define
define|#
directive|define
name|CLEAR
value|2
end_define

begin_comment
comment|/* window has been cleared	*/
end_comment

begin_define
define|#
directive|define
name|CHANGE
value|3
end_define

begin_comment
comment|/* window has been changed	*/
end_comment

begin_define
define|#
directive|define
name|UP
value|1
end_define

begin_comment
comment|/* direction of scroll		*/
end_comment

begin_define
define|#
directive|define
name|DOWN
value|2
end_define

begin_struct
struct|struct
name|_line
block|{
name|struct
name|_line
modifier|*
name|next_screen
decl_stmt|;
name|struct
name|_line
modifier|*
name|prev_screen
decl_stmt|;
name|char
modifier|*
name|row
decl_stmt|;
name|char
modifier|*
name|attributes
decl_stmt|;
name|int
name|last_char
decl_stmt|;
name|int
name|changed
decl_stmt|;
name|int
name|scroll
decl_stmt|;
name|int
name|number
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|_line
modifier|*
name|top_of_win
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|WIND
block|{
name|int
name|SR
decl_stmt|;
comment|/* starting row		*/
name|int
name|SC
decl_stmt|;
comment|/* starting column	*/
name|int
name|LC
decl_stmt|;
comment|/* last column		*/
name|int
name|LX
decl_stmt|;
comment|/* last cursor column position	*/
name|int
name|LY
decl_stmt|;
comment|/* last cursor row position	*/
name|int
name|Attrib
decl_stmt|;
comment|/* attributes active in window	*/
name|int
name|Num_lines
decl_stmt|;
comment|/* number of lines		*/
name|int
name|Num_cols
decl_stmt|;
comment|/* number of columns		*/
name|int
name|scroll_up
decl_stmt|;
comment|/* number of lines moved	*/
name|int
name|scroll_down
decl_stmt|;
name|int
name|SCROLL_CLEAR
decl_stmt|;
comment|/* indicates that window has been scrolled or cleared	*/
name|struct
name|_line
modifier|*
name|first_line
decl_stmt|;
block|}
name|WINDOW
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|curscr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|stdscr
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

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|P_
parameter_list|(
name|s
parameter_list|)
value|s
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P_
parameter_list|(
name|s
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|copy_window
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|origin
operator|,
name|WINDOW
operator|*
name|destination
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reinitscr
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|initscr
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Get_int
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|INFO_PARSE
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|AtoI
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|Key_Get
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|keys_vt100
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_line
modifier|*
name|Screenalloc
name|P_
argument_list|(
operator|(
name|int
name|columns
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|newwin
name|P_
argument_list|(
operator|(
name|int
name|lines
operator|,
name|int
name|cols
operator|,
name|int
name|start_l
operator|,
name|int
name|start_c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Operation
name|P_
argument_list|(
operator|(
name|int
name|Temp_Stack
index|[]
operator|,
name|int
name|place
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|Info_Out
name|P_
argument_list|(
operator|(
name|char
operator|*
name|string
operator|,
name|int
name|p_list
index|[]
operator|,
name|int
name|place
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|wmove
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|,
name|int
name|row
operator|,
name|int
name|column
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_line
name|P_
argument_list|(
operator|(
expr|struct
name|_line
operator|*
name|line
operator|,
name|int
name|column
operator|,
name|int
name|cols
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|werase
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|wclrtoeol
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|wrefresh
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|touchwin
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|wnoutrefresh
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flushinp
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ungetch
name|P_
argument_list|(
operator|(
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wgetch
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|Clear
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Get_key
name|P_
argument_list|(
operator|(
name|int
name|first_char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|waddch
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|,
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|winsertln
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|wdeleteln
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|wclrtobot
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|wstandout
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|wstandend
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|waddstr
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|,
name|char
operator|*
name|string
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clearok
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|echo
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|noecho
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|raw
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|noraw
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|nl
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|nonl
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|saveterm
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fixterm
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|resetterm
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|nodelay
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|idlok
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|keypad
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|savetty
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|resetty
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|endwin
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delwin
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|wprintw
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|,
specifier|const
name|char
operator|*
name|format
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|iout
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|,
name|int
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Comp_line
name|P_
argument_list|(
operator|(
expr|struct
name|_line
operator|*
name|line1
operator|,
expr|struct
name|_line
operator|*
name|line2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_line
modifier|*
name|Insert_line
name|P_
argument_list|(
operator|(
name|int
name|row
operator|,
name|int
name|end_row
operator|,
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_line
modifier|*
name|Delete_line
name|P_
argument_list|(
operator|(
name|int
name|row
operator|,
name|int
name|end_row
operator|,
name|WINDOW
operator|*
name|window
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|CLEAR_TO_EOL
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|,
name|int
name|row
operator|,
name|int
name|column
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|check_delete
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|,
name|int
name|line
operator|,
name|int
name|offset
operator|,
expr|struct
name|_line
operator|*
name|pointer_new
operator|,
expr|struct
name|_line
operator|*
name|pointer_old
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|check_insert
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|,
name|int
name|line
operator|,
name|int
name|offset
operator|,
expr|struct
name|_line
operator|*
name|pointer_new
operator|,
expr|struct
name|_line
operator|*
name|pointer_old
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|doupdate
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|Position
name|P_
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|,
name|int
name|row
operator|,
name|int
name|col
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|Char_del
name|P_
argument_list|(
operator|(
name|char
operator|*
name|line
operator|,
name|char
operator|*
name|attrib
operator|,
name|int
name|offset
operator|,
name|int
name|maxlen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|Char_ins
name|P_
argument_list|(
operator|(
name|char
operator|*
name|line
operator|,
name|char
operator|*
name|attrib
operator|,
name|int
name|newc
operator|,
name|int
name|newatt
operator|,
name|int
name|offset
operator|,
name|int
name|maxlen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|attribute_on
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|attribute_off
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|Char_out
name|P_
argument_list|(
operator|(
name|int
name|newc
operator|,
name|int
name|newatt
operator|,
name|char
operator|*
name|line
operator|,
name|char
operator|*
name|attrib
operator|,
name|int
name|offset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|nc_setattrib
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|nc_clearattrib
name|P_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|P_
end_undef

end_unit

