begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Define global variables  *  * @(#)curses.c	1.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"curses.h"
end_include

begin_decl_stmt
name|bool
name|_echoit
init|=
name|TRUE
decl_stmt|,
comment|/* set if stty indicates ECHO		*/
name|_rawmode
init|=
name|FALSE
decl_stmt|,
comment|/* set if stty indicates RAW mode	*/
name|My_term
init|=
name|FALSE
decl_stmt|,
comment|/* set if user specifies terminal type	*/
name|_endwin
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if endwin has been called	*/
end_comment

begin_decl_stmt
name|char
name|ttytype
index|[
literal|10
index|]
decl_stmt|,
comment|/* long name of tty			*/
modifier|*
name|Def_term
init|=
literal|"unknown"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default terminal type	*/
end_comment

begin_decl_stmt
name|int
name|_tty_ch
init|=
literal|1
decl_stmt|,
comment|/* file channel which is a tty		*/
name|LINES
decl_stmt|,
comment|/* number of lines allowed on screen	*/
name|COLS
decl_stmt|,
comment|/* number of columns allowed on screen	*/
name|_res_flg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sgtty flags for reseting later	*/
end_comment

begin_decl_stmt
name|WINDOW
modifier|*
name|stdscr
init|=
name|NULL
decl_stmt|,
modifier|*
name|curscr
init|=
name|NULL
decl_stmt|;
end_decl_stmt

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
comment|/* debug output file			*/
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
comment|/* tty modes				*/
end_comment

begin_decl_stmt
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
name|GT
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
name|OS
decl_stmt|,
name|UL
decl_stmt|,
name|XN
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

begin_decl_stmt
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
name|VE
decl_stmt|,
modifier|*
name|VS
decl_stmt|,
name|PC
decl_stmt|;
end_decl_stmt

end_unit

