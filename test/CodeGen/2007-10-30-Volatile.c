begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o /dev/null -Wall -Werror
end_comment

begin_function
name|void
name|bork
parameter_list|()
block|{
name|char
modifier|*
specifier|volatile
name|p
init|=
literal|0
decl_stmt|;
specifier|volatile
name|int
name|cc
init|=
literal|0
decl_stmt|;
name|p
operator|+=
name|cc
expr_stmt|;
block|}
end_function

end_unit

