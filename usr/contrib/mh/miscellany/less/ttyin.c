begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Routines dealing with getting input from the keyboard (i.e. from the user).  */
end_comment

begin_include
include|#
directive|include
file|"less.h"
end_include

begin_comment
comment|/*  * The boolean "reading" is set true or false according to whether  * we are currently reading from the keyboard.  * This information is used by the signal handling stuff in signal.c.  * {{ There are probably some race conditions here  *    involving the variable "reading". }}  */
end_comment

begin_decl_stmt
name|public
name|int
name|reading
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|tty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Open keyboard for input.  * (Just use file descriptor 2.)  */
end_comment

begin_function
name|public
name|void
name|open_getc
parameter_list|()
block|{
name|tty
operator|=
literal|2
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Get a character from the keyboard.  */
end_comment

begin_function
name|public
name|int
name|getc
parameter_list|()
block|{
name|char
name|c
decl_stmt|;
name|int
name|result
decl_stmt|;
name|reading
operator|=
literal|1
expr_stmt|;
do|do
block|{
name|flush
argument_list|()
expr_stmt|;
name|result
operator|=
name|read
argument_list|(
name|tty
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|result
operator|!=
literal|1
condition|)
do|;
name|reading
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|c
operator|&
literal|0177
operator|)
return|;
block|}
end_function

end_unit

