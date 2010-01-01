begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|int
modifier|*
name|test1
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|+
literal|1
return|;
block|}
end_function

begin_function
name|int
modifier|*
name|test2
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
return|return
literal|1
operator|+
name|a
return|;
block|}
end_function

begin_function
name|int
modifier|*
name|test3
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|-
literal|1
return|;
block|}
end_function

begin_function
name|int
name|test4
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|int
modifier|*
name|b
parameter_list|)
block|{
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

begin_function
name|int
name|test5
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|int
modifier|*
name|b
parameter_list|)
block|{
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_comment
comment|/* expected-error {{invalid operands}} */
end_comment

begin_function
name|int
modifier|*
name|test6
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
return|return
literal|1
operator|-
name|a
return|;
block|}
end_function

begin_comment
comment|/* expected-error {{invalid operands}} */
end_comment

end_unit

