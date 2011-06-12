begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7 -fsyntax-only -verify -DTEST0 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7 -fsyntax-only -verify -DTEST1 %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST0
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TEST1
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// va_list on ARM is void*.
end_comment

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

end_unit

