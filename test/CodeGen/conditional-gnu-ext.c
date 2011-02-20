begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o %t
end_comment

begin_comment
comment|// PR1824
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|short
name|y
parameter_list|)
block|{
return|return
name|x
condition|?
else|:
name|y
return|;
block|}
end_function

begin_comment
comment|// rdar://6586493
end_comment

begin_function
name|float
name|test
parameter_list|(
name|float
name|x
parameter_list|,
name|int
name|Y
parameter_list|)
block|{
return|return
name|Y
operator|!=
literal|0
condition|?
else|:
name|x
return|;
block|}
end_function

begin_comment
comment|// rdar://8446940
end_comment

begin_function_decl
specifier|extern
name|void
name|abort
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test1
parameter_list|()
block|{
name|char
name|x
index|[
literal|1
index|]
decl_stmt|;
name|char
modifier|*
name|y
init|=
name|x
condition|?
else|:
literal|0
decl_stmt|;
if|if
condition|(
name|x
operator|!=
name|y
condition|)
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://8453812
end_comment

begin_function
specifier|_Complex
name|int
name|getComplex
parameter_list|(
specifier|_Complex
name|int
name|val
parameter_list|)
block|{
specifier|static
name|int
name|count
decl_stmt|;
if|if
condition|(
name|count
operator|++
condition|)
name|abort
argument_list|()
expr_stmt|;
return|return
name|val
return|;
block|}
end_function

begin_function
specifier|_Complex
name|int
name|complx
parameter_list|()
block|{
specifier|_Complex
name|int
name|cond
decl_stmt|;
specifier|_Complex
name|int
name|rhs
decl_stmt|;
return|return
name|getComplex
argument_list|(
literal|1+2i
argument_list|)
condition|?
else|:
name|rhs
return|;
block|}
end_function

end_unit

