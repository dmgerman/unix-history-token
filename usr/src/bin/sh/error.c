begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)error.c	4.2 8/11/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#
end_empty

begin_comment
comment|/*  * UNIX shell  *  * S. R. Bourne  * Bell Telephone Laboratories  *  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/* ========	error handling	======== */
end_comment

begin_macro
name|exitset
argument_list|()
end_macro

begin_block
block|{
name|assnum
argument_list|(
operator|&
name|exitadr
argument_list|,
name|exitval
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|sigchk
argument_list|()
end_macro

begin_block
block|{
comment|/* Find out if it is time to go away. 	 * `trapnote' is set to SIGSET when fault is seen and 	 * no trap has been set. 	 */
name|IF
name|trapnote
modifier|&
name|SIGSET
name|THEN
name|exitsh
parameter_list|(
name|SIGFAIL
parameter_list|)
function_decl|;
name|FI
block|}
end_block

begin_macro
name|failed
argument_list|(
argument|s1
argument_list|,
argument|s2
argument_list|)
end_macro

begin_decl_stmt
name|STRING
name|s1
decl_stmt|,
name|s2
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|prp
argument_list|()
expr_stmt|;
name|prs
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|IF
name|s2
name|THEN
name|prs
parameter_list|(
name|colon
parameter_list|)
function_decl|;
name|prs
argument_list|(
name|s2
argument_list|)
expr_stmt|;
name|FI
name|newline
parameter_list|()
function_decl|;
name|exitsh
argument_list|(
name|ERROR
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|error
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|STRING
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|failed
argument_list|(
name|s
argument_list|,
name|NIL
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|exitsh
argument_list|(
argument|xno
argument_list|)
end_macro

begin_decl_stmt
name|INT
name|xno
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Arrive here from `FATAL' errors 	 *  a) exit command, 	 *  b) default trap, 	 *  c) fault with no trap set. 	 * 	 * Action is to return to command level or exit. 	 */
name|exitval
operator|=
name|xno
expr_stmt|;
name|IF
argument_list|(
name|flags
operator|&
operator|(
name|forked
operator||
name|errflg
operator||
name|ttyflg
operator|)
argument_list|)
operator|!=
name|ttyflg
name|THEN
name|done
argument_list|()
expr_stmt|;
name|ELSE
name|clearup
parameter_list|()
function_decl|;
name|longjmp
argument_list|(
name|errshell
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|FI
block|}
end_block

begin_macro
name|done
argument_list|()
end_macro

begin_block
block|{
name|REG
name|STRING
name|t
decl_stmt|;
name|IF
name|t
init|=
name|trapcom
index|[
literal|0
index|]
name|THEN
name|trapcom
index|[
literal|0
index|]
operator|=
literal|0
decl_stmt|;
comment|/*should free but not long */
name|execexp
argument_list|(
name|t
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|FI
name|rmtemp
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|exit
argument_list|(
name|exitval
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|rmtemp
argument_list|(
argument|base
argument_list|)
end_macro

begin_decl_stmt
name|IOPTR
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|WHILE
name|iotemp
operator|>
name|base
name|DO
name|unlink
argument_list|(
name|iotemp
operator|->
name|ioname
argument_list|)
expr_stmt|;
name|iotemp
operator|=
name|iotemp
operator|->
name|iolst
expr_stmt|;
name|OD
block|}
end_block

end_unit

