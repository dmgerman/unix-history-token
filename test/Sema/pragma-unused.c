begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
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
comment|// FIXME: We should emit a warning that 'w' is unused.
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
comment|// FIXME: We should emit a warning that 'w' is unused.
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

begin_decl_stmt
name|int
name|k
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f5
parameter_list|(
name|void
parameter_list|)
block|{
pragma|#
directive|pragma
name|unused
name|(
name|k
name|)
comment|// expected-warning{{only local variables can be arguments to '#pragma unused'}}
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

end_unit

