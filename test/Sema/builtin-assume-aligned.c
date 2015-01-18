begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|int
name|test1
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
name|a
operator|=
name|__builtin_assume_aligned
argument_list|(
name|a
argument_list|,
literal|32
argument_list|,
literal|0ull
argument_list|)
expr_stmt|;
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_function
name|int
name|test2
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
name|a
operator|=
name|__builtin_assume_aligned
argument_list|(
name|a
argument_list|,
literal|32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_function
name|int
name|test3
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
name|a
operator|=
name|__builtin_assume_aligned
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
expr_stmt|;
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_function
name|int
name|test4
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
name|a
operator|=
name|__builtin_assume_aligned
argument_list|(
name|a
argument_list|,
operator|-
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error {{requested alignment is not a power of 2}}
comment|// FIXME: The line below produces {{requested alignment is not a power of 2}}
comment|// on i386-freebsd, but not on x86_64-linux (for example).
comment|// a = __builtin_assume_aligned(a, 1ULL<< 63);
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_function
name|int
name|test5
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|unsigned
modifier|*
name|b
parameter_list|)
block|{
name|a
operator|=
name|__builtin_assume_aligned
argument_list|(
name|a
argument_list|,
literal|32
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// expected-warning {{incompatible pointer to integer conversion passing 'unsigned int *' to parameter of type}}
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_function
name|int
name|test6
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
name|a
operator|=
name|__builtin_assume_aligned
argument_list|(
name|a
argument_list|,
literal|32
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{too many arguments to function call, expected at most 3, have 4}}
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_function
name|int
name|test7
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
name|a
operator|=
name|__builtin_assume_aligned
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
expr_stmt|;
comment|// expected-error {{requested alignment is not a power of 2}}
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_function
name|int
name|test8
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|int
name|j
parameter_list|)
block|{
name|a
operator|=
name|__builtin_assume_aligned
argument_list|(
name|a
argument_list|,
name|j
argument_list|)
expr_stmt|;
comment|// expected-error {{must be a constant integer}}
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_function_decl
name|void
name|test_void_assume_aligned
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(assume_aligned
parameter_list|(
function_decl|32
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{'assume_aligned' attribute only applies to return values that are pointers}}
end_comment

begin_function_decl
name|int
name|test_int_assume_aligned
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(assume_aligned
parameter_list|(
function_decl|16
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{'assume_aligned' attribute only applies to return values that are pointers}}
end_comment

begin_function_decl
name|void
modifier|*
name|test_ptr_assume_aligned
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(assume_aligned
parameter_list|(
function_decl|64
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
name|assume_aligned
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'assume_aligned' attribute only applies to functions and methods}}
end_comment

begin_function_decl
name|void
modifier|*
name|test_no_fn_proto
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(assume_aligned
parameter_list|(
function_decl|32
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-warning
end_comment

begin_function_decl
name|void
modifier|*
name|test_with_fn_proto
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(assume_aligned
parameter_list|(
function_decl|128
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-warning
end_comment

begin_function_decl
name|void
modifier|*
name|test_no_fn_proto
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(assume_aligned
parameter_list|(
function_decl|31
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{requested alignment is not a power of 2}}
end_comment

begin_function_decl
name|void
modifier|*
name|test_no_fn_proto
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(assume_aligned
parameter_list|(
function_decl|32
operator|,
function_decl|73
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// no-warning
end_comment

begin_function_decl
name|void
modifier|*
name|test_no_fn_proto
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(assume_aligned
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'assume_aligned' attribute takes at least 1 argument}}
end_comment

begin_function_decl
name|void
modifier|*
name|test_no_fn_proto
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(assume_aligned
parameter_list|()
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'assume_aligned' attribute takes at least 1 argument}}
end_comment

begin_function_decl
name|void
modifier|*
name|test_no_fn_proto
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(assume_aligned
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
comment|// expected-error {{'assume_aligned' attribute takes no more than 2 arguments}}
end_comment

end_unit

