begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -verify -std=c99 -Dbool=_Bool -Wno-bool-conversion %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -verify -x c++ -Wno-bool-conversion %s
end_comment

begin_typedef
typedef|typedef
name|__INTPTR_TYPE__
name|intptr_t
typedef|;
end_typedef

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
block|}
end_function

begin_comment
comment|// expected-warning{{Address of stack memory associated with local variable 'str' is still referred to by the global variable 'p' upon returning to the caller.  This will be a dangling reference}}
end_comment

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
block|}
end_function

begin_comment
comment|// expected-warning{{Address of stack memory allocated by call to alloca() on line 19 is still referred to by the global variable 'p' upon returning to the caller.  This will be a dangling reference}}
end_comment

begin_comment
comment|// PR 7383 - previously the stack address checker would crash on this example
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
block|}
end_function

begin_comment
comment|// expected-warning{{Address of stack memory associated with local variable 'x' is still referred to by the static variable 'a' upon returning}} expected-warning{{Address of stack memory associated with local variable 'x' is still referred to by the static variable 'b' upon returning}}
end_comment

begin_function
name|intptr_t
name|returnAsNonLoc
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
return|return
operator|(
name|intptr_t
operator|)
operator|&
name|x
return|;
comment|// expected-warning{{Address of stack memory associated with local variable 'x' returned to caller}}
block|}
end_function

begin_function
name|bool
name|returnAsBool
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
return|return
operator|&
name|x
return|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|assignAsNonLoc
parameter_list|()
block|{
specifier|extern
name|intptr_t
name|ip
decl_stmt|;
name|int
name|x
decl_stmt|;
name|ip
operator|=
operator|(
name|intptr_t
operator|)
operator|&
name|x
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-warning{{Address of stack memory associated with local variable 'x' is still referred to by the global variable 'ip' upon returning}}
end_comment

begin_function
name|void
name|assignAsBool
parameter_list|()
block|{
specifier|extern
name|bool
name|b
decl_stmt|;
name|int
name|x
decl_stmt|;
name|b
operator|=
operator|&
name|x
expr_stmt|;
block|}
end_function

begin_comment
comment|// no-warning
end_comment

end_unit

