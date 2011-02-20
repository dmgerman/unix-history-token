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

begin_comment
comment|// expected-note{{previous overload}}
end_comment

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

