begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c99 -analyze -analyzer-checker=core,experimental.core.BoolAssignment -analyzer-store=region -verify %s
end_comment

begin_comment
comment|// Test stdbool.h's _Bool
end_comment

begin_comment
comment|// Prior to C99, stdbool.h uses this typedef, but even in ANSI C mode, _Bool
end_comment

begin_comment
comment|// appears to be defined.
end_comment

begin_comment
comment|// #if __STDC_VERSION__< 199901L
end_comment

begin_comment
comment|// typedef int _Bool;
end_comment

begin_comment
comment|// #endif
end_comment

begin_function
name|void
name|test_stdbool_initialization
parameter_list|(
name|int
name|y
parameter_list|)
block|{
if|if
condition|(
name|y
operator|<
literal|0
condition|)
block|{
name|_Bool
name|x
init|=
name|y
decl_stmt|;
comment|// expected-warning {{Assignment of a non-Boolean value}}
return|return;
block|}
if|if
condition|(
name|y
operator|>
literal|1
condition|)
block|{
name|_Bool
name|x
init|=
name|y
decl_stmt|;
comment|// expected-warning {{Assignment of a non-Boolean value}}
return|return;
block|}
name|_Bool
name|x
init|=
name|y
decl_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|test_stdbool_assignment
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|_Bool
name|x
init|=
literal|0
decl_stmt|;
comment|// no-warning
if|if
condition|(
name|y
operator|<
literal|0
condition|)
block|{
name|x
operator|=
name|y
expr_stmt|;
comment|// expected-warning {{Assignment of a non-Boolean value}}
return|return;
block|}
if|if
condition|(
name|y
operator|>
literal|1
condition|)
block|{
name|x
operator|=
name|y
expr_stmt|;
comment|// expected-warning {{Assignment of a non-Boolean value}}
return|return;
block|}
name|x
operator|=
name|y
expr_stmt|;
comment|// no-warning
block|}
end_function

end_unit

