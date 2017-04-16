begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -std=c99 -Dbool=_Bool -analyzer-checker=core,alpha.core.TestAfterDivZero -analyzer-output=text -verify %s
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -x c++ -analyzer-checker=core,alpha.core.TestAfterDivZero -analyzer-output=text -verify %s
end_comment

begin_decl_stmt
name|int
name|var
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|err_eq
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{ }
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

begin_function
name|void
name|err_eq2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
if|if
condition|(
literal|0
operator|==
name|x
condition|)
block|{ }
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

begin_function
name|void
name|err_ne
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
if|if
condition|(
name|x
operator|!=
literal|0
condition|)
block|{ }
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

begin_function
name|void
name|err_ge
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
if|if
condition|(
name|x
operator|>=
literal|0
condition|)
block|{ }
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

begin_function
name|void
name|err_le
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
if|if
condition|(
name|x
operator|<=
literal|0
condition|)
block|{}
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

begin_function
name|void
name|err_yes
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
if|if
condition|(
name|x
condition|)
block|{}
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

begin_function
name|void
name|err_not
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
if|if
condition|(
operator|!
name|x
condition|)
block|{}
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

begin_function
name|void
name|err_pnot
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
modifier|*
name|y
init|=
operator|&
name|x
decl_stmt|;
name|var
operator|=
literal|77
operator|/
operator|*
name|y
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
if|if
condition|(
operator|!
name|x
condition|)
block|{}
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

begin_function
name|void
name|err_pnot2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
modifier|*
name|y
init|=
operator|&
name|x
decl_stmt|;
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
if|if
condition|(
operator|!
operator|*
name|y
condition|)
block|{}
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

begin_function
name|void
name|err_ppnot
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
modifier|*
name|y
init|=
operator|&
name|x
decl_stmt|;
name|int
modifier|*
modifier|*
name|z
init|=
operator|&
name|y
decl_stmt|;
name|var
operator|=
literal|77
operator|/
operator|*
operator|*
name|z
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
if|if
condition|(
operator|!
name|x
condition|)
block|{}
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

begin_function
name|void
name|err_orig_checker
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|!=
literal|0
condition|)
comment|// expected-note {{Assuming 'x' is equal to 0}} expected-note {{Taking false branch}}
return|return;
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
comment|// expected-warning {{Division by zero}} expected-note {{Division by zero}}
if|if
condition|(
operator|!
name|x
condition|)
block|{}
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok_other
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|y
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{   }
block|}
end_function

begin_function
name|void
name|ok_assign
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
name|x
operator|=
name|var
operator|/
literal|77
expr_stmt|;
comment|//<- assignment => don't warn
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{   }
block|}
end_function

begin_function
name|void
name|ok_assign2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
name|x
operator|=
name|var
operator|/
literal|77
expr_stmt|;
comment|//<- assignment => don't warn
if|if
condition|(
literal|0
operator|==
name|x
condition|)
block|{   }
block|}
end_function

begin_function
name|void
name|ok_dec
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
name|x
operator|--
expr_stmt|;
comment|//<- assignment => don't warn
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{   }
block|}
end_function

begin_function
name|void
name|ok_inc
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
name|x
operator|++
expr_stmt|;
comment|//<- assignment => don't warn
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{   }
block|}
end_function

begin_function_decl
name|void
name|do_something_ptr
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|ok_callfunc_ptr
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
name|do_something_ptr
argument_list|(
operator|&
name|x
argument_list|)
expr_stmt|;
comment|//<- pass address of x to function => don't warn
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{   }
block|}
end_function

begin_function_decl
name|void
name|do_something
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|nok_callfunc
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
name|do_something
argument_list|(
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{}
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

begin_function
name|void
name|ok_if
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|>
literal|3
condition|)
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{   }
block|}
end_function

begin_function
name|void
name|ok_if2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|<
literal|3
condition|)
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{   }
comment|// TODO warn here
block|}
end_function

begin_function
name|void
name|ok_pif
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
modifier|*
name|y
init|=
operator|&
name|x
decl_stmt|;
if|if
condition|(
name|x
operator|<
literal|3
condition|)
name|var
operator|=
literal|77
operator|/
operator|*
name|y
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{   }
comment|// TODO warn here
block|}
end_function

begin_function_decl
name|int
name|getValue
parameter_list|(
name|bool
modifier|*
name|isPositive
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|use
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|()
block|{
name|bool
name|isPositive
decl_stmt|;
name|int
name|x
init|=
name|getValue
argument_list|(
operator|&
name|isPositive
argument_list|)
decl_stmt|;
if|if
condition|(
name|isPositive
condition|)
block|{
name|use
argument_list|(
literal|5
operator|/
name|x
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{   }
block|}
end_function

begin_function_decl
name|int
name|getValue2
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|foo2
parameter_list|()
block|{
name|int
name|x
init|=
name|getValue2
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|x
decl_stmt|;
name|use
argument_list|(
literal|5
operator|/
name|x
argument_list|)
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
if|if
condition|(
name|y
operator|==
literal|0
condition|)
block|{}
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

begin_function
name|void
name|ok_while
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|n
init|=
literal|100
operator|/
name|x
decl_stmt|;
while|while
condition|(
name|x
operator|!=
literal|0
condition|)
block|{
comment|//<- do not warn
name|x
operator|--
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|err_not2
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|int
name|v
decl_stmt|;
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
if|if
condition|(
name|y
condition|)
name|v
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|x
condition|)
block|{   }
comment|// TODO warn here
block|}
end_function

begin_function
specifier|inline
name|void
name|inline_func
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{}
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

begin_function
name|void
name|err_inline
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
name|inline_func
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-note {{Calling 'inline_func'}}
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{   }
block|}
end_function

begin_function
specifier|inline
name|void
name|inline_func2
parameter_list|(
name|int
name|x
parameter_list|)
block|{}
end_function

begin_function
name|void
name|err_inline2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
name|inline_func2
argument_list|(
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{}
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

begin_function
specifier|inline
name|void
name|inline_func3
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
name|ok_inline
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|var
operator|=
literal|77
operator|/
name|x
expr_stmt|;
comment|// expected-note {{Division with compared value made here}}
name|inline_func3
argument_list|(
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{}
comment|// expected-warning {{Value being compared against zero has already been used for division}}
block|}
end_function

begin_comment
comment|// expected-note@-1 {{Value being compared against zero has already been used for division}}
end_comment

end_unit

