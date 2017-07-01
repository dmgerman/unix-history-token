begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include %s -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t -fsyntax-only -verify %s
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER
end_ifndef

begin_define
define|#
directive|define
name|HEADER
end_define

begin_function_decl
name|int
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"default"
end_function_decl

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|overloadable
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|g
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(abi_tag
parameter_list|(
function_decl|"foo"
operator|,
function_decl|"bar"
operator|,
function_decl|"baz"
end_function_decl

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|no_sanitize
argument_list|(
literal|"address"
argument_list|,
literal|"memory"
argument_list|)
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
name|float
name|f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|f
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{overloadable}}
end_comment

begin_comment
comment|// expected-note@-2{{previous unmarked overload}}
end_comment

begin_function
name|void
name|h
parameter_list|()
block|{
name|g
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

