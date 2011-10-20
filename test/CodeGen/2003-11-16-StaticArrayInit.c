begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s  -o /dev/null
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{
specifier|static
name|char
name|x
index|[
literal|10
index|]
decl_stmt|;
specifier|static
name|char
modifier|*
name|xend
init|=
name|x
operator|+
literal|10
decl_stmt|;
block|}
end_function

end_unit

