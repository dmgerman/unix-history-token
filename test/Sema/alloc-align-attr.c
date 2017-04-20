begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// return values
end_comment

begin_function_decl
name|void
name|test_void_alloc_align
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_align
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{'alloc_align' attribute only applies to return values that are pointers}}
end_comment

begin_function_decl
name|void
modifier|*
name|test_ptr_alloc_align
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_align
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-warning
end_comment

begin_decl_stmt
name|int
name|j
name|__attribute__
argument_list|(
operator|(
name|alloc_align
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'alloc_align' attribute only applies to non-K&R-style functions}}
end_comment

begin_function_decl
name|void
modifier|*
name|test_no_params_zero
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_align
parameter_list|(
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'alloc_align' attribute parameter 1 is out of bounds}}
end_comment

begin_function_decl
name|void
modifier|*
name|test_no_params
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_align
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'alloc_align' attribute parameter 1 is out of bounds}}
end_comment

begin_function_decl
name|void
modifier|*
name|test_incorrect_param_type
parameter_list|(
name|float
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_align
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'alloc_align' attribute argument may only refer to a function parameter of integer type}}
end_comment

begin_comment
comment|// argument type
end_comment

begin_function_decl
name|void
modifier|*
name|test_bad_param_type
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alloc_align
parameter_list|(
function_decl|1.1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'alloc_align' attribute requires parameter 1 to be an integer constant}}
end_comment

begin_comment
comment|// argument count
end_comment

begin_function_decl
name|void
modifier|*
name|test_no_fn_proto
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_align
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'alloc_align' attribute takes one argument}}
end_comment

begin_function_decl
name|void
modifier|*
name|test_no_fn_proto
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_align
parameter_list|()
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'alloc_align' attribute takes one argument}}
end_comment

begin_function_decl
name|void
modifier|*
name|test_no_fn_proto
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_align
parameter_list|(
function_decl|32
operator|,
function_decl|45
operator|,
function_decl|37
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'alloc_align' attribute takes one argument}}
end_comment

end_unit

