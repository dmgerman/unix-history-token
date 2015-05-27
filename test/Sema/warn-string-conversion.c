begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only -Wstring-conversion %s
end_comment

begin_function_decl
name|void
name|do_nothing
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_error
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|assert1
parameter_list|(
name|expr
parameter_list|)
define|\
value|if (expr)           \     do_nothing();     \   else                \   assert_error()
end_define

begin_define
define|#
directive|define
name|assert2
parameter_list|(
name|expr
parameter_list|)
define|\
value|((expr) ? do_nothing() : assert_error())
end_define

begin_comment
comment|// Expection for common assert form.
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
name|assert1
argument_list|(
literal|0
operator|&&
literal|"foo"
argument_list|)
expr_stmt|;
name|assert1
argument_list|(
literal|"foo"
operator|&&
literal|0
argument_list|)
expr_stmt|;
name|assert1
argument_list|(
literal|0
operator|||
literal|"foo"
argument_list|)
expr_stmt|;
comment|// expected-warning {{string literal}}
name|assert1
argument_list|(
literal|"foo"
argument_list|)
expr_stmt|;
comment|// expected-warning {{string literal}}
name|assert2
argument_list|(
literal|0
operator|&&
literal|"foo"
argument_list|)
expr_stmt|;
name|assert2
argument_list|(
literal|"foo"
operator|&&
literal|0
argument_list|)
expr_stmt|;
name|assert2
argument_list|(
literal|0
operator|||
literal|"foo"
argument_list|)
expr_stmt|;
comment|// expected-warning {{string literal}}
name|assert2
argument_list|(
literal|"foo"
argument_list|)
expr_stmt|;
comment|// expected-warning {{string literal}}
block|}
end_function

begin_function
name|void
name|test2
parameter_list|()
block|{
if|if
condition|(
literal|"hi"
condition|)
block|{}
comment|// expected-warning {{string literal}}
while|while
condition|(
literal|"hello"
condition|)
block|{}
comment|// expected-warning {{string literal}}
for|for
control|(
init|;
literal|"howdy"
condition|;
control|)
block|{}
comment|// expected-warning {{string literal}}
do|do
block|{ }
do|while
condition|(
literal|"hey"
condition|)
do|;
comment|// expected-warning {{string literal}}
name|int
name|x
init|=
literal|"hey"
condition|?
literal|1
else|:
literal|2
decl_stmt|;
comment|// expected-warning {{string literal}}
block|}
end_function

end_unit

