begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-html -o - | grep ">&lt; 10; }"
end_comment

begin_function
name|int
name|a
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|<
literal|10
return|;
block|}
end_function

end_unit

