begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)curses.c	8.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_comment
comment|/* Private. */
end_comment

begin_decl_stmt
name|int
name|__echoit
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If stty indicates ECHO. */
end_comment

begin_decl_stmt
name|int
name|__pfast
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__rawmode
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If stty indicates RAW mode. */
end_comment

begin_decl_stmt
name|int
name|__noqch
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  					 * If terminal doesn't have  					 * insert/delete line capabilities  					 * for quick change on refresh. 					 */
end_comment

begin_decl_stmt
name|char
name|AM
decl_stmt|,
name|BS
decl_stmt|,
name|CA
decl_stmt|,
name|DA
decl_stmt|,
name|EO
decl_stmt|,
name|HC
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
name|PC
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
name|al
decl_stmt|,
modifier|*
name|dl
decl_stmt|,
modifier|*
name|sf
decl_stmt|,
modifier|*
name|sr
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

begin_comment
comment|/*  * Public.  *  * XXX  * UPPERCASE isn't used by libcurses, and is left for backward  * compatibility only.  */
end_comment

begin_decl_stmt
name|WINDOW
modifier|*
name|curscr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current screen. */
end_comment

begin_decl_stmt
name|WINDOW
modifier|*
name|stdscr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Standard screen. */
end_comment

begin_decl_stmt
name|int
name|COLS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Columns on the screen. */
end_comment

begin_decl_stmt
name|int
name|LINES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lines on the screen. */
end_comment

begin_decl_stmt
name|int
name|My_term
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use Def_term regardless. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Def_term
init|=
literal|"unknown"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default terminal type. */
end_comment

begin_decl_stmt
name|char
name|GT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Gtty indicates tabs. */
end_comment

begin_decl_stmt
name|char
name|NONL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Term can't hack LF doing a CR. */
end_comment

begin_decl_stmt
name|char
name|UPPERCASE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal is uppercase only. */
end_comment

end_unit

