begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_decl_stmt
specifier|static
name|uint32_t
name|buf
index|[
literal|512
operator|/
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|()
block|{
name|u_int
name|u
init|=
literal|0
decl_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
if|if
condition|(
literal|512
operator|!=
name|read
argument_list|(
literal|0
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|)
condition|)
break|break;
name|printf
argument_list|(
literal|"%u %u\n"
argument_list|,
name|u
operator|++
argument_list|,
name|buf
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

