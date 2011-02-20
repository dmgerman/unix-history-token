begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|==
name|x
return|;
comment|// expected-warning {{self-comparison always evaluates to true}}
block|}
end_function

begin_function
name|int
name|foo2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
operator|(
name|x
operator|)
operator|!=
operator|(
operator|(
operator|(
name|x
operator|)
operator|)
operator|)
return|;
comment|// expected-warning {{self-comparison always evaluates to false}}
block|}
end_function

begin_function
name|void
name|foo3
parameter_list|(
name|short
name|s
parameter_list|,
name|short
name|t
parameter_list|)
block|{
if|if
condition|(
name|s
operator|==
name|s
condition|)
block|{}
comment|// expected-warning {{self-comparison always evaluates to true}}
if|if
condition|(
name|s
operator|==
name|t
condition|)
block|{}
comment|// no-warning
block|}
end_function

begin_function
name|void
name|foo4
parameter_list|(
name|void
modifier|*
name|v
parameter_list|,
name|void
modifier|*
name|w
parameter_list|)
block|{
if|if
condition|(
name|v
operator|==
name|v
condition|)
block|{}
comment|// expected-warning {{self-comparison always evaluates to true}}
if|if
condition|(
name|v
operator|==
name|w
condition|)
block|{}
comment|// no-warning
block|}
end_function

begin_function
name|int
name|qux
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|<
name|x
return|;
comment|// expected-warning {{self-comparison}}
block|}
end_function

begin_function
name|int
name|qux2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|>
name|x
return|;
comment|// expected-warning {{self-comparison}}
block|}
end_function

begin_function
name|int
name|bar
parameter_list|(
name|float
name|x
parameter_list|)
block|{
return|return
name|x
operator|==
name|x
return|;
comment|// no-warning
block|}
end_function

begin_function
name|int
name|bar2
parameter_list|(
name|float
name|x
parameter_list|)
block|{
return|return
name|x
operator|!=
name|x
return|;
comment|// no-warning
block|}
end_function

begin_define
define|#
directive|define
name|IS_THE_ANSWER
parameter_list|(
name|x
parameter_list|)
value|(x == 42)
end_define

begin_function
name|int
name|macro_comparison
parameter_list|()
block|{
return|return
name|IS_THE_ANSWER
argument_list|(
literal|42
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Don't complain in unevaluated contexts.
end_comment

begin_function
name|int
name|compare_sizeof
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
sizeof|sizeof
argument_list|(
name|x
operator|==
name|x
argument_list|)
return|;
comment|// no-warning
block|}
end_function

begin_function
name|int
name|array_comparisons
parameter_list|()
block|{
name|int
name|array1
index|[
literal|2
index|]
decl_stmt|;
name|int
name|array2
index|[
literal|2
index|]
decl_stmt|;
comment|//
comment|// compare same array
comment|//
return|return
name|array1
operator|==
name|array1
return|;
comment|// expected-warning{{self-comparison always evaluates to true}}
return|return
name|array1
operator|!=
name|array1
return|;
comment|// expected-warning{{self-comparison always evaluates to false}}
return|return
name|array1
operator|<
name|array1
return|;
comment|// expected-warning{{self-comparison always evaluates to false}}
return|return
name|array1
operator|<=
name|array1
return|;
comment|// expected-warning{{self-comparison always evaluates to true}}
return|return
name|array1
operator|>
name|array1
return|;
comment|// expected-warning{{self-comparison always evaluates to false}}
return|return
name|array1
operator|>=
name|array1
return|;
comment|// expected-warning{{self-comparison always evaluates to true}}
comment|//
comment|// compare differrent arrays
comment|//
return|return
name|array1
operator|==
name|array2
return|;
comment|// expected-warning{{array comparison always evaluates to false}}
return|return
name|array1
operator|!=
name|array2
return|;
comment|// expected-warning{{array comparison always evaluates to true}}
comment|//
comment|// we don't know what these are going to be
comment|//
return|return
name|array1
operator|<
name|array2
return|;
comment|// expected-warning{{array comparison always evaluates to a constant}}
return|return
name|array1
operator|<=
name|array2
return|;
comment|// expected-warning{{array comparison always evaluates to a constant}}
return|return
name|array1
operator|>
name|array2
return|;
comment|// expected-warning{{array comparison always evaluates to a constant}}
return|return
name|array1
operator|>=
name|array2
return|;
comment|// expected-warning{{array comparison always evaluates to a constant}}
block|}
end_function

begin_comment
comment|// Don't issue a warning when either the left or right side of the comparison
end_comment

begin_comment
comment|// results from a macro expansion.<rdar://problem/8435950>
end_comment

begin_define
define|#
directive|define
name|R8435950_A
value|i
end_define

begin_define
define|#
directive|define
name|R8435950_B
value|i
end_define

begin_function
name|int
name|R8435950
parameter_list|(
name|int
name|i
parameter_list|)
block|{
if|if
condition|(
name|R8435950_A
operator|==
name|R8435950_B
condition|)
comment|// no-warning
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
end_function

end_unit

