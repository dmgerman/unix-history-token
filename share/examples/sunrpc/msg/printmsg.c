begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)printmsg.c	2.1 88/08/11 4.0 RPCSRC */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * printmsg.c: print a message on the console  */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|char
modifier|*
name|message
decl_stmt|;
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: %s<message>\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|message
operator|=
name|argv
index|[
literal|1
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|printmessage
argument_list|(
name|message
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: sorry, couldn't print your message\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"Message delivered!\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Print a message to the console.  * Return a boolean indicating whether the message was actually printed.  */
end_comment

begin_macro
name|printmessage
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
name|FILE
modifier|*
name|f
decl_stmt|;
name|f
operator|=
name|fopen
argument_list|(
name|_PATH_CONSOLE
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
name|f
operator|==
name|NULL
condition|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|fprintf
argument_list|(
name|f
argument_list|,
literal|"%s\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|f
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

end_unit

