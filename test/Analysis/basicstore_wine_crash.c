begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -checker-cfref -analyze -analyzer-store=basic %s
end_comment

begin_comment
comment|// Once xfail_regionstore_wine_crash.c passes, move this test case
end_comment

begin_comment
comment|// into misc-ps.m.
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|long
name|x
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|y
init|=
operator|(
name|char
operator|*
operator|)
operator|&
name|x
decl_stmt|;
if|if
condition|(
operator|!
operator|*
name|y
condition|)
return|return;
block|}
end_function

end_unit

