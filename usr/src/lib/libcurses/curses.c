begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)curses.c	5.6 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * Define global variables  *  */
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
literal|50
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
literal|0
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
name|char
name|PC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * From the tty modes...  */
end_comment

begin_decl_stmt
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

end_unit

