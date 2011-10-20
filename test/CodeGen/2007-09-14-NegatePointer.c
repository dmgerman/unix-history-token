begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o -
end_comment

begin_comment
comment|// PR1662
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|unsigned
name|char
modifier|*
name|test
parameter_list|)
block|{
return|return
literal|0U
operator|-
operator|(
name|unsigned
name|int
operator|)
name|test
return|;
block|}
end_function

end_unit

