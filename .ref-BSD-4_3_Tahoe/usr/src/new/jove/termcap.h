begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MAXCOLS
value|256
end_define

begin_comment
comment|/* maximum number of columns */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_TERM
end_ifndef

begin_comment
comment|/* termcap definitions */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|UP
decl_stmt|,
comment|/* Scroll reverse, or up */
modifier|*
name|CS
decl_stmt|,
comment|/* If on vt100 */
modifier|*
name|SO
decl_stmt|,
comment|/* Start standout */
modifier|*
name|SE
decl_stmt|,
comment|/* End standout */
modifier|*
name|CM
decl_stmt|,
comment|/* The cursor motion string */
modifier|*
name|CL
decl_stmt|,
comment|/* Clear screen */
modifier|*
name|CE
decl_stmt|,
comment|/* Clear to end of line */
modifier|*
name|HO
decl_stmt|,
comment|/* Home cursor */
modifier|*
name|AL
decl_stmt|,
comment|/* Addline (insert line) */
modifier|*
name|DL
decl_stmt|,
comment|/* Delete line */
modifier|*
name|VS
decl_stmt|,
comment|/* Visual start */
modifier|*
name|VE
decl_stmt|,
comment|/* Visual end */
modifier|*
name|KS
decl_stmt|,
comment|/* Keypad mode start */
modifier|*
name|KE
decl_stmt|,
comment|/* Keypad mode end */
modifier|*
name|TI
decl_stmt|,
comment|/* Cursor addressing start */
modifier|*
name|TE
decl_stmt|,
comment|/* Cursor addressing end */
modifier|*
name|IC
decl_stmt|,
comment|/* Insert char */
modifier|*
name|DC
decl_stmt|,
comment|/* Delete char */
modifier|*
name|IM
decl_stmt|,
comment|/* Insert mode */
modifier|*
name|EI
decl_stmt|,
comment|/* End insert mode */
modifier|*
name|LL
decl_stmt|,
comment|/* Last line, first column */
modifier|*
name|M_IC
decl_stmt|,
comment|/* Insert char with arg */
modifier|*
name|M_DC
decl_stmt|,
comment|/* Delete char with arg */
modifier|*
name|M_AL
decl_stmt|,
comment|/* Insert line with arg */
modifier|*
name|M_DL
decl_stmt|,
comment|/* Delete line with arg */
modifier|*
name|SF
decl_stmt|,
comment|/* Scroll forward */
modifier|*
name|SR
decl_stmt|,
comment|/* Scroll reverse */
modifier|*
name|SP
decl_stmt|,
comment|/* Send cursor position */
modifier|*
name|VB
decl_stmt|,
comment|/* visible bell */
modifier|*
name|BL
decl_stmt|,
comment|/* audible bell */
modifier|*
name|IP
decl_stmt|,
comment|/* insert pad after character inserted */
modifier|*
name|lPC
decl_stmt|,
modifier|*
name|NL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* newline character (usually \n) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|LI
decl_stmt|,
comment|/* number of lines */
name|ILI
decl_stmt|,
comment|/* number of internal lines */
name|CO
decl_stmt|,
comment|/* number of columns */
name|UL
decl_stmt|,
comment|/* underscores don't replace chars already on screen */
name|MI
decl_stmt|,
comment|/* okay to move while in insert mode */
name|SG
decl_stmt|,
comment|/* number of magic cookies left by SO and SE */
name|TABS
decl_stmt|,
comment|/* whether we are in tabs mode */
name|UPlen
decl_stmt|,
comment|/* length of the UP string */
name|HOlen
decl_stmt|,
comment|/* length of Home string */
name|LLlen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of lower string */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|PC
decl_stmt|,
modifier|*
name|BC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* back space */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|ospeed
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TERM */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MAC */
end_comment

begin_decl_stmt
specifier|extern
name|int
comment|/* probably should clean this up */
name|LI
decl_stmt|,
comment|/* number of lines */
name|ILI
decl_stmt|,
comment|/* number of internal lines */
name|CO
decl_stmt|,
comment|/* number of columns */
name|TABS
decl_stmt|,
name|SG
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

end_unit

