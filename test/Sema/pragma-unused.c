begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wunused-parameter -Wused-but-marked-unused -Wunused -verify %s
end_comment

begin_function
name|void
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
pragma|#
directive|pragma
name|unused
name|(
name|x
name|)
pragma|#
directive|pragma
name|unused
name|(
name|y
name|,
name|z
name|)
name|int
name|w
decl_stmt|;
comment|// expected-warning {{unused}}
pragma|#
directive|pragma
name|unused
name|w
comment|// expected-warning{{missing '(' after '#pragma unused' - ignoring}}
block|}
end_function

begin_function
name|void
name|f2
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|// expected-warning {{unused}} expected-warning {{unused}}
pragma|#
directive|pragma
name|unused
name|(
name|x
name|,
name|)
comment|// expected-warning{{expected '#pragma unused' argument to be a variable name}}
pragma|#
directive|pragma
name|unused
name|(
name|)
comment|// expected-warning{{expected '#pragma unused' argument to be a variable name}}
block|}
end_function

begin_function
name|void
name|f3
parameter_list|(
name|void
parameter_list|)
block|{
pragma|#
directive|pragma
name|unused
name|(
name|x
name|)
comment|// expected-warning{{undeclared variable 'x' used as an argument for '#pragma unused'}}
block|}
end_function

begin_function
name|void
name|f4
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|w
decl_stmt|;
comment|// expected-warning {{unused}}
pragma|#
directive|pragma
name|unused
name|(
name|(
name|w
name|)
name|)
comment|// expected-warning{{expected '#pragma unused' argument to be a variable name}}
block|}
end_function

begin_function
name|void
name|f6
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|z
decl_stmt|;
comment|// no-warning
block|{
pragma|#
directive|pragma
name|unused
name|(
name|z
name|)
comment|// no-warning
block|}
block|}
end_function

begin_function
name|void
name|f7
parameter_list|()
block|{
name|int
name|y
decl_stmt|;
pragma|#
directive|pragma
name|unused
name|(
name|undeclared
name|,
name|undefined
name|,
name|y
name|)
comment|// expected-warning{{undeclared variable 'undeclared' used as an argument for '#pragma unused'}} expected-warning{{undeclared variable 'undefined' used as an argument for '#pragma unused'}}
block|}
end_function

begin_function
name|int
name|f8
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// expected-warning{{unused parameter 'x'}}
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|f9
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_function
name|int
name|f10
parameter_list|(
name|int
name|x
parameter_list|)
block|{
pragma|#
directive|pragma
name|unused
name|(
name|x
name|)
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|f11
parameter_list|(
name|int
name|x
parameter_list|)
block|{
pragma|#
directive|pragma
name|unused
name|(
name|x
name|)
return|return
name|x
return|;
comment|// expected-warning{{'x' was marked unused but was used}}
block|}
end_function

begin_function
name|int
name|f12
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|y
init|=
name|x
decl_stmt|;
pragma|#
directive|pragma
name|unused
name|(
name|x
name|)
comment|// expected-warning{{'x' was marked unused but was used}}
return|return
name|y
return|;
block|}
end_function

begin_comment
comment|// rdar://8793832
end_comment

begin_decl_stmt
specifier|static
name|int
name|glob_var
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|unused
name|(
name|glob_var
name|)
end_pragma

end_unit

