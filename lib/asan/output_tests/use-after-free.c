begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|char
modifier|*
name|x
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|10
operator|*
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return
name|x
index|[
literal|5
index|]
return|;
block|}
end_function

begin_comment
comment|// CHECK: heap-use-after-free
end_comment

begin_comment
comment|// CHECKSLEEP: Sleeping for 1 second
end_comment

end_unit

