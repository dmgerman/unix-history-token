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
comment|// expected-warning {{self-comparison always results}}
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
comment|// expected-warning {{self-comparison always results}}
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

begin_comment
comment|// Motivated by<rdar://problem/6703892>, self-comparisons of enum constants
end_comment

begin_comment
comment|// should not be warned about.  These can be expanded from macros, and thus
end_comment

begin_comment
comment|// are usually deliberate.
end_comment

begin_function
name|int
name|compare_enum
parameter_list|()
block|{
enum|enum
block|{
name|A
block|}
enum|;
return|return
name|A
operator|==
name|A
return|;
comment|// no-warning
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

end_unit

