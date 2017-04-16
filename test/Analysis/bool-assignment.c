begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,alpha.core.BoolAssignment -analyzer-store=region -verify -std=c99 -Dbool=_Bool %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,alpha.core.BoolAssignment -analyzer-store=region -verify -x c++ %s
end_comment

begin_comment
comment|// Test C++'s bool and C's _Bool.
end_comment

begin_comment
comment|// FIXME: We stopped warning on these when SValBuilder got smarter about
end_comment

begin_comment
comment|// casts to bool. Arguably, however, these conversions are okay; the result
end_comment

begin_comment
comment|// is always 'true' or 'false'.
end_comment

begin_function
name|void
name|test_stdbool_initialization
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|bool
name|constant
init|=
literal|2
decl_stmt|;
comment|// no-warning
if|if
condition|(
name|y
operator|<
literal|0
condition|)
block|{
name|bool
name|x
init|=
name|y
decl_stmt|;
comment|// no-warning
return|return;
block|}
if|if
condition|(
name|y
operator|>
literal|1
condition|)
block|{
name|bool
name|x
init|=
name|y
decl_stmt|;
comment|// no-warning
return|return;
block|}
name|bool
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
name|bool
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
comment|// no-warning
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
comment|// no-warning
return|return;
block|}
name|x
operator|=
name|y
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Test Objective-C's BOOL
end_comment

begin_typedef
typedef|typedef
name|signed
name|char
name|BOOL
typedef|;
end_typedef

begin_function
name|void
name|test_BOOL_initialization
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|BOOL
name|constant
init|=
literal|2
decl_stmt|;
comment|// expected-warning {{Assignment of a non-Boolean value}}
if|if
condition|(
name|y
operator|<
literal|0
condition|)
block|{
name|BOOL
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
literal|200
operator|&&
name|y
operator|<
literal|250
condition|)
block|{
ifdef|#
directive|ifdef
name|ANALYZER_CM_Z3
name|BOOL
name|x
init|=
name|y
decl_stmt|;
comment|// expected-warning {{Assignment of a non-Boolean value}}
else|#
directive|else
name|BOOL
name|x
init|=
name|y
decl_stmt|;
comment|// no-warning
endif|#
directive|endif
return|return;
block|}
if|if
condition|(
name|y
operator|>=
literal|127
operator|&&
name|y
operator|<
literal|150
condition|)
block|{
name|BOOL
name|x
init|=
name|y
decl_stmt|;
comment|// expected-warning{{Assignment of a non-Boolean value}}
return|return;
block|}
if|if
condition|(
name|y
operator|>
literal|1
condition|)
block|{
name|BOOL
name|x
init|=
name|y
decl_stmt|;
comment|// expected-warning {{Assignment of a non-Boolean value}}
return|return;
block|}
name|BOOL
name|x
init|=
name|y
decl_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|test_BOOL_assignment
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|BOOL
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

begin_comment
comment|// Test MacTypes.h's Boolean
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Boolean
typedef|;
end_typedef

begin_function
name|void
name|test_Boolean_initialization
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|Boolean
name|constant
init|=
literal|2
decl_stmt|;
comment|// expected-warning {{Assignment of a non-Boolean value}}
if|if
condition|(
name|y
operator|<
literal|0
condition|)
block|{
name|Boolean
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
name|Boolean
name|x
init|=
name|y
decl_stmt|;
comment|// expected-warning {{Assignment of a non-Boolean value}}
return|return;
block|}
name|Boolean
name|x
init|=
name|y
decl_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|test_Boolean_assignment
parameter_list|(
name|int
name|y
parameter_list|)
block|{
name|Boolean
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

