begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This program is in the public domain.  I couldn't bring myself to  * declare Copyright on a variant of Hello World.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_define
define|#
directive|define
name|MESSAGE
value|"This account is currently not available.\n"
end_define

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|write
argument_list|(
name|STDOUT_FILENO
argument_list|,
name|MESSAGE
argument_list|,
sizeof|sizeof
argument_list|(
name|MESSAGE
argument_list|)
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

