begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Routines dealing with getting input from the keyboard (i.e. from the user).  */
end_comment

begin_include
include|#
directive|include
file|"less.h"
end_include

begin_if
if|#
directive|if
name|__MSDOS__
end_if

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int
name|tty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Open keyboard for input.  */
end_comment

begin_function
name|public
name|void
name|open_getchr
parameter_list|()
block|{
if|#
directive|if
name|__MDDOS__
comment|/* 	 * Open a new handle to CON: in binary mode  	 * for unbuffered keyboard read. 	 */
name|tty
operator|=
name|open
argument_list|(
literal|"CON"
argument_list|,
name|O_RDONLY
operator||
name|O_BINARY
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* 	 * Try /dev/tty. 	 * If that doesn't work, use file descriptor 2, 	 * which in Unix is usually attached to the screen, 	 * but also usually lets you read from the keyboard. 	 */
name|tty
operator|=
name|open
argument_list|(
literal|"/dev/tty"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|tty
operator|<
literal|0
condition|)
name|tty
operator|=
literal|2
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Get a character from the keyboard.  */
end_comment

begin_function
name|public
name|int
name|getchr
parameter_list|()
block|{
name|char
name|c
decl_stmt|;
name|int
name|result
decl_stmt|;
do|do
block|{
name|result
operator|=
name|iread
argument_list|(
name|tty
argument_list|,
operator|&
name|c
argument_list|,
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|==
name|READ_INTR
condition|)
return|return
operator|(
name|READ_INTR
operator|)
return|;
if|if
condition|(
name|result
operator|<
literal|0
condition|)
block|{
comment|/* 			 * Don't call error() here, 			 * because error calls getchr! 			 */
name|quit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
name|__MSDOS__
comment|/* 		 * In raw read, we don't see ^C so look here for it. 		 */
if|if
condition|(
name|c
operator|==
literal|'\003'
condition|)
name|raise
argument_list|(
name|SIGINT
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 		 * Various parts of the program cannot handle 		 * an input character of '\0'. 		 * If a '\0' was actually typed, convert it to '\200' here. 		 */
if|if
condition|(
name|c
operator|==
literal|'\0'
condition|)
name|c
operator|=
literal|'\200'
expr_stmt|;
block|}
do|while
condition|(
name|result
operator|!=
literal|1
condition|)
do|;
return|return
operator|(
name|c
operator|)
return|;
block|}
end_function

end_unit

