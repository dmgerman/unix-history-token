begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|()
block|{
name|char
name|buffer
index|[
literal|512
index|]
decl_stmt|;
while|while
condition|(
name|gets
argument_list|(
name|buffer
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"#define %s zz%4.4dzz\n"
argument_list|,
name|buffer
argument_list|,
name|count
operator|++
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

