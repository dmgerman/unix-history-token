begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************  * This program is copyright (C) 1985, 1986 by Jonathan Payne.  It is    *  * provided to you without charge for use only on a licensed Unix        *  * system.  You may copy JOVE provided that this notice is included with *  * the copy.  You may not sell copies of this program or versions        *  * modified for use on microcomputer systems, unless the copies are      *  * included with a Unix system distribution and the source is provided.  *  *************************************************************************/
end_comment

begin_comment
comment|/* Termcap definitions */
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
ifdef|#
directive|ifdef
name|LSRHS
modifier|*
name|RS
decl_stmt|,
comment|/* reverse video start */
modifier|*
name|RE
decl_stmt|,
comment|/* reverse video end */
endif|#
directive|endif
modifier|*
name|VB
decl_stmt|,
comment|/* visible bell */
modifier|*
name|IP
decl_stmt|,
comment|/* insert pad after character inserted */
modifier|*
name|lPC
decl_stmt|;
end_decl_stmt

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
name|int
name|ospeed
decl_stmt|;
end_decl_stmt

end_unit

