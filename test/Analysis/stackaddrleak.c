begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-check-objc-mem -analyzer-checker=core.StackAddrLeak -analyzer-store region -verify %s
end_comment

begin_decl_stmt
name|char
specifier|const
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f0
parameter_list|()
block|{
name|char
specifier|const
name|str
index|[]
init|=
literal|"This will change"
decl_stmt|;
name|p
operator|=
name|str
expr_stmt|;
comment|// expected-warning{{Address of stack memory associated with local variable 'str' is still referred to by the global variable 'p' upon returning to the caller.  This will be a dangling reference}}
block|}
end_function

begin_function
name|void
name|f1
parameter_list|()
block|{
name|char
specifier|const
name|str
index|[]
init|=
literal|"This will change"
decl_stmt|;
name|p
operator|=
name|str
expr_stmt|;
name|p
operator|=
literal|0
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|f2
parameter_list|()
block|{
name|p
operator|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|__builtin_alloca
argument_list|(
literal|12
argument_list|)
expr_stmt|;
comment|// expected-warning{{Address of stack memory allocated by call to alloca() on line 17 is still referred to by the global variable 'p' upon returning to the caller.  This will be a dangling reference}}
block|}
end_function

begin_comment
comment|// PR 7383 - previosly the stack address checker would crash on this example
end_comment

begin_comment
comment|//  because it would attempt to do a direct load from 'pr7383_list'.
end_comment

begin_function
specifier|static
name|int
name|pr7383
parameter_list|(
name|__const
name|char
modifier|*
name|__
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|__const
name|char
modifier|*
name|__const
name|pr7383_list
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Test that we catch multiple returns via globals when analyzing a function.
end_comment

begin_function
name|void
name|test_multi_return
parameter_list|()
block|{
specifier|static
name|int
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
name|int
name|x
decl_stmt|;
name|a
operator|=
operator|&
name|x
expr_stmt|;
name|b
operator|=
operator|&
name|x
expr_stmt|;
comment|// expected-warning{{Address of stack memory associated with local variable 'x' is still referred to by the global variable 'a' upon returning}} expected-warning{{Address of stack memory associated with local variable 'x' is still referred to by the global variable 'b' upon returning}}
block|}
end_function

end_unit

