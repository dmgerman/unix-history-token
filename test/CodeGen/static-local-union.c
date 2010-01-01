begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s
end_comment

begin_function
name|int
name|a
parameter_list|()
block|{
specifier|static
union|union
block|{
name|int
name|a
decl_stmt|;
block|}
name|r
index|[
literal|2
index|]
init|=
block|{
literal|1
block|,
literal|2
block|}
union|;
return|return
name|r
index|[
literal|1
index|]
operator|.
name|a
return|;
block|}
end_function

end_unit

