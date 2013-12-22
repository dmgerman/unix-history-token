begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wno-error=return-type %s -emit-llvm-only
end_comment

begin_comment
comment|// REQUIRES: LP64
end_comment

begin_comment
comment|// Mismatched type between return and function result.
end_comment

begin_function
name|int
name|test2
parameter_list|()
block|{
return|return;
block|}
end_function

begin_function
name|void
name|test3
parameter_list|()
block|{
return|return
literal|4
return|;
block|}
end_function

begin_function
name|void
name|test4
parameter_list|()
block|{
name|bar
label|:
name|baz
label|:
name|blong
label|:
name|bing
label|:
empty_stmt|;
comment|// PR5131
specifier|static
name|long
name|x
init|=
operator|&&
name|bar
operator|-
operator|&&
name|baz
decl_stmt|;
specifier|static
name|long
name|y
init|=
operator|&&
name|baz
decl_stmt|;
operator|&&
name|bing
expr_stmt|;
operator|&&
name|blong
expr_stmt|;
if|if
condition|(
name|y
condition|)
goto|goto *
name|y
goto|;
goto|goto *
name|x
goto|;
block|}
end_function

begin_comment
comment|// PR3869
end_comment

begin_function
name|int
name|test5
parameter_list|(
name|long
name|long
name|b
parameter_list|)
block|{
specifier|static
name|void
modifier|*
name|lbls
index|[]
init|=
block|{
operator|&&
name|lbl
block|}
decl_stmt|;
goto|goto *
name|b
goto|;
name|lbl
label|:
return|return
literal|0
return|;
block|}
end_function

end_unit

