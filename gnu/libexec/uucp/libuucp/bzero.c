begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bzero.c    Zero out a buffer.  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_function
name|void
name|bzero
parameter_list|(
name|parg
parameter_list|,
name|c
parameter_list|)
name|pointer
name|parg
decl_stmt|;
name|int
name|c
decl_stmt|;
block|{
name|char
modifier|*
name|p
init|=
operator|(
name|char
operator|*
operator|)
name|parg
decl_stmt|;
while|while
condition|(
name|c
operator|--
operator|!=
literal|0
condition|)
operator|*
name|p
operator|++
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

