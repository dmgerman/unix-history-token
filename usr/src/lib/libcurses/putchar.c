begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_comment
comment|/*  * @(#)putchar.c	1.1 (Berkeley) %G%  */
end_comment

begin_function
name|char
name|_putchar
parameter_list|(
name|c
parameter_list|)
name|reg
name|char
name|c
decl_stmt|;
block|{
name|putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|outf
argument_list|,
literal|"_PUTCHAR(%s)\n"
argument_list|,
name|unctrl
argument_list|(
name|c
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

