begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-windows -fsyntax-only -verify %s
end_comment

begin_define
define|#
directive|define
name|SWIFTCALL
value|__attribute__((swiftcall))
end_define

begin_define
define|#
directive|define
name|INDIRECT_RESULT
value|__attribute__((swift_indirect_result))
end_define

begin_define
define|#
directive|define
name|ERROR_RESULT
value|__attribute__((swift_error_result))
end_define

begin_define
define|#
directive|define
name|CONTEXT
value|__attribute__((swift_context))
end_define

begin_decl_stmt
name|int
name|notAFunction
name|SWIFTCALL
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'swiftcall' only applies to function types; type here is 'int'}}
end_comment

begin_decl_stmt
name|void
name|variadic
argument_list|(
name|int
name|x
argument_list|,
operator|...
argument_list|)
name|SWIFTCALL
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{variadic function cannot use swiftcall calling convention}}
end_comment

begin_expr_stmt
name|void
name|unprototyped
argument_list|()
name|SWIFTCALL
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{function with no prototype cannot use the swiftcall calling convention}}
end_comment

begin_decl_stmt
name|void
name|multiple_ccs
argument_list|(
name|int
name|x
argument_list|)
name|SWIFTCALL
name|__attribute__
argument_list|(
operator|(
name|vectorcall
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{vectorcall and swiftcall attributes are not compatible}}
end_comment

begin_macro
name|void
argument_list|(
argument|*functionPointer
argument_list|)
end_macro

begin_expr_stmt
operator|(
name|void
operator|)
name|SWIFTCALL
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|indirect_result_nonswift
parameter_list|(
name|INDIRECT_RESULT
name|void
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{'swift_indirect_result' parameter can only be used with swiftcall calling convention}}
end_comment

begin_decl_stmt
name|void
name|indirect_result_bad_position
argument_list|(
name|int
name|first
argument_list|,
name|INDIRECT_RESULT
name|void
operator|*
name|out
argument_list|)
name|SWIFTCALL
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'swift_indirect_result' parameters must be first parameters of function}}
end_comment

begin_decl_stmt
name|void
name|indirect_result_bad_type
argument_list|(
name|INDIRECT_RESULT
name|int
name|out
argument_list|)
name|SWIFTCALL
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'swift_indirect_result' parameter must have pointer type; type here is 'int'}}
end_comment

begin_decl_stmt
name|void
name|indirect_result_single
argument_list|(
name|INDIRECT_RESULT
name|void
operator|*
name|out
argument_list|)
name|SWIFTCALL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|indirect_result_multiple
argument_list|(
name|INDIRECT_RESULT
name|void
operator|*
name|out1
argument_list|,
name|INDIRECT_RESULT
name|void
operator|*
name|out2
argument_list|)
name|SWIFTCALL
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|error_result_nonswift
parameter_list|(
name|ERROR_RESULT
name|void
modifier|*
modifier|*
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{'swift_error_result' parameter can only be used with swiftcall calling convention}} expected-error{{'swift_error_result' parameter must follow 'swift_context' parameter}}
end_comment

begin_decl_stmt
name|void
name|error_result_bad_position2
argument_list|(
name|int
name|first
argument_list|,
name|ERROR_RESULT
name|void
operator|*
operator|*
name|error
argument_list|)
name|SWIFTCALL
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'swift_error_result' parameter must follow 'swift_context' parameter}}
end_comment

begin_decl_stmt
name|void
name|error_result_bad_type
argument_list|(
name|CONTEXT
name|void
operator|*
name|context
argument_list|,
name|ERROR_RESULT
name|int
name|error
argument_list|)
name|SWIFTCALL
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'swift_error_result' parameter must have pointer to unqualified pointer type; type here is 'int'}}
end_comment

begin_decl_stmt
name|void
name|error_result_bad_type2
argument_list|(
name|CONTEXT
name|void
operator|*
name|context
argument_list|,
name|ERROR_RESULT
name|int
operator|*
name|error
argument_list|)
name|SWIFTCALL
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'swift_error_result' parameter must have pointer to unqualified pointer type; type here is 'int *'}}
end_comment

begin_decl_stmt
name|void
name|error_result_okay
argument_list|(
name|int
name|a
argument_list|,
name|int
name|b
argument_list|,
name|CONTEXT
name|void
operator|*
name|context
argument_list|,
name|ERROR_RESULT
name|void
operator|*
operator|*
name|error
argument_list|)
name|SWIFTCALL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|error_result_okay2
argument_list|(
name|CONTEXT
name|void
operator|*
name|context
argument_list|,
name|ERROR_RESULT
name|void
operator|*
operator|*
name|error
argument_list|,
name|void
operator|*
name|selfType
argument_list|,
name|char
operator|*
operator|*
name|selfWitnessTable
argument_list|)
name|SWIFTCALL
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|context_nonswift
parameter_list|(
name|CONTEXT
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{'swift_context' parameter can only be used with swiftcall calling convention}}
end_comment

begin_decl_stmt
name|void
name|context_bad_type
argument_list|(
name|CONTEXT
name|int
name|context
argument_list|)
name|SWIFTCALL
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'swift_context' parameter must have pointer type; type here is 'int'}}
end_comment

begin_decl_stmt
name|void
name|context_okay
argument_list|(
name|CONTEXT
name|void
operator|*
name|context
argument_list|)
name|SWIFTCALL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|context_okay2
argument_list|(
name|CONTEXT
name|void
operator|*
name|context
argument_list|,
name|void
operator|*
name|selfType
argument_list|,
name|char
operator|*
operator|*
name|selfWitnessTable
argument_list|)
name|SWIFTCALL
decl_stmt|;
end_decl_stmt

end_unit

