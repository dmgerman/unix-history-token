begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"monitor.h"
end_include

begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)clrline.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  Clear Input Line ** **	This routine removes the newline following a monitor command **	(such as \t, \g,  etc.)  Any other characters are processed. **	Hence, \t\g\t will work.  It also maintains the **	Newline flag on command lines.  It will make certain that **	the current line in the query buffer ends with a newline. ** **	The flag 'noprompt' if will disable the prompt character if set. **	Otherwise, it is automatically printed out. ** **	Uses trace flag 8 */
end_comment

begin_macro
name|clrline
argument_list|(
argument|noprompt
argument_list|)
end_macro

begin_decl_stmt
name|int
name|noprompt
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
name|c
decl_stmt|;
if|if
condition|(
operator|!
name|Newline
condition|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|Qryiop
argument_list|)
expr_stmt|;
name|Newline
operator|=
name|TRUE
expr_stmt|;
comment|/* if char following is a newline, throw it away */
name|c
operator|=
name|getch
argument_list|()
expr_stmt|;
name|Prompt
operator|=
name|c
operator|==
literal|'\n'
expr_stmt|;
if|if
condition|(
operator|!
name|Prompt
condition|)
block|{
name|ungetc
argument_list|(
name|c
argument_list|,
name|Input
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|noprompt
condition|)
name|prompt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
end_block

end_unit

