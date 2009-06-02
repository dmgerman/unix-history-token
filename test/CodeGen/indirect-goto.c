begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -emit-llvm-bc -o - %s | opt -std-compile-opts | llvm-dis> %t&&
end_comment

begin_comment
comment|// RUN: grep "ret i32" %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep "ret i32 210" %t | count 1
end_comment

begin_function
specifier|static
name|int
name|foo
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
specifier|const
name|void
modifier|*
name|addrs
index|[]
init|=
block|{
operator|&&
name|L1
block|,
operator|&&
name|L2
block|,
operator|&&
name|L3
block|,
operator|&&
name|L4
block|,
operator|&&
name|L5
block|}
decl_stmt|;
name|int
name|res
init|=
literal|1
decl_stmt|;
goto|goto *
name|addrs
index|[
name|i
index|]
goto|;
name|L5
label|:
name|res
operator|*=
literal|11
expr_stmt|;
name|L4
label|:
name|res
operator|*=
literal|7
expr_stmt|;
name|L3
label|:
name|res
operator|*=
literal|5
expr_stmt|;
name|L2
label|:
name|res
operator|*=
literal|3
expr_stmt|;
name|L1
label|:
name|res
operator|*=
literal|2
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_function
name|int
name|bar
parameter_list|()
block|{
return|return
name|foo
argument_list|(
literal|3
argument_list|)
return|;
block|}
end_function

end_unit

