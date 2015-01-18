begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7 -target-abi apcs-gnu \
end_comment

begin_comment
comment|// RUN:   -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|f
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|void
modifier|*
name|b
parameter_list|)
block|{
name|__clear_cache
argument_list|()
expr_stmt|;
comment|// expected-error {{too few arguments to function call, expected 2, have 0}} // expected-note {{'__clear_cache' is a builtin with type 'void (void *, void *)}}
name|__clear_cache
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// expected-error {{too few arguments to function call, expected 2, have 1}}
name|__clear_cache
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|__clear_cache
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{conflicting types for '__clear_cache'}}
end_comment

begin_function_decl
name|void
name|__clear_cache
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_PCS
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_EABI__
argument_list|)
end_if

begin_comment
comment|// va_list on ARM AAPCS is struct { void* __ap }.
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
name|__builtin_va_list
name|ptr
decl_stmt|;
name|ptr
operator|.
name|__ap
operator|=
literal|"x"
expr_stmt|;
operator|*
operator|(
name|ptr
operator|.
name|__ap
operator|)
operator|=
literal|'0'
expr_stmt|;
comment|// expected-error {{incomplete type 'void' is not assignable}}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|// va_list on ARM apcs-gnu is void*.
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
name|__builtin_va_list
name|ptr
decl_stmt|;
name|ptr
operator|.
name|__ap
operator|=
literal|"x"
expr_stmt|;
comment|// expected-error {{member reference base type '__builtin_va_list' is not a structure or union}}
operator|*
operator|(
name|ptr
operator|.
name|__ap
operator|)
operator|=
literal|'0'
expr_stmt|;
comment|// expected-error {{member reference base type '__builtin_va_list' is not a structure or union}}
block|}
end_function

begin_function
name|void
name|test2
parameter_list|()
block|{
name|__builtin_va_list
name|ptr
init|=
literal|"x"
decl_stmt|;
operator|*
name|ptr
operator|=
literal|'0'
expr_stmt|;
comment|// expected-error {{incomplete type 'void' is not assignable}}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|test3
parameter_list|()
block|{
name|__builtin_arm_dsb
argument_list|(
literal|16
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_arm_dmb
argument_list|(
literal|17
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
name|__builtin_arm_isb
argument_list|(
literal|18
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
block|}
end_function

begin_function
name|void
name|test4
parameter_list|()
block|{
name|__builtin_arm_prefetch
argument_list|(
literal|0
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 1}}
name|__builtin_arm_prefetch
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 1}}
block|}
end_function

begin_function
name|void
name|test5
parameter_list|()
block|{
name|__builtin_arm_dbg
argument_list|(
literal|16
argument_list|)
expr_stmt|;
comment|// expected-error {{argument should be a value from 0 to 15}}
block|}
end_function

end_unit

