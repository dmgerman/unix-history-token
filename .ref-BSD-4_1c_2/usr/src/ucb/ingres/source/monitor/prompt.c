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
argument|@(#)prompt.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  OUTPUT PROMPT CHARACTER ** **	The prompt is output to the standard output.  It will not be **	output if -ss mode is set or if we are not at a newline. ** **	The parameter is printed out if non-zero. ** **	Uses trace flag 14 */
end_comment

begin_macro
name|prompt
argument_list|(
argument|msg
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|msg
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|Prompt
operator|||
name|GiveEof
condition|)
return|return;
if|if
condition|(
name|Nodayfile
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|msg
condition|)
name|printf
argument_list|(
literal|"\07%s\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"* "
argument_list|)
expr_stmt|;
block|}
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* **  PROMPT WITH CONTINUE OR GO */
end_comment

begin_macro
name|cgprompt
argument_list|()
end_macro

begin_block
block|{
name|prompt
argument_list|(
name|Notnull
condition|?
literal|"continue"
else|:
literal|"go"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

