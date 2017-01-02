begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify
end_comment

begin_function_decl
name|void
modifier|*
name|fail1
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{'alloc_size' attribute takes at least 1 argument}}
end_comment

begin_function_decl
name|void
modifier|*
name|fail2
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|()
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{'alloc_size' attribute takes at least 1 argument}}
end_comment

begin_function_decl
name|void
modifier|*
name|fail3
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{'alloc_size' attribute parameter 0 is out of bounds}}
end_comment

begin_function_decl
name|void
modifier|*
name|fail4
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{'alloc_size' attribute parameter 2 is out of bounds}}
end_comment

begin_function_decl
name|void
modifier|*
name|fail5
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|0
operator|,
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{'alloc_size' attribute parameter 0 is out of bounds}}
end_comment

begin_function_decl
name|void
modifier|*
name|fail6
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|3
operator|,
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{'alloc_size' attribute parameter 3 is out of bounds}}
end_comment

begin_function_decl
name|void
modifier|*
name|fail7
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|1
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{'alloc_size' attribute parameter 0 is out of bounds}}
end_comment

begin_function_decl
name|void
modifier|*
name|fail8
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|1
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{'alloc_size' attribute parameter 3 is out of bounds}}
end_comment

begin_function_decl
name|int
name|fail9
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-warning{{'alloc_size' attribute only applies to return values that are pointers}}
end_comment

begin_decl_stmt
name|int
name|fail10
name|__attribute__
argument_list|(
operator|(
name|alloc_size
argument_list|(
literal|1
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//expected-warning{{'alloc_size' attribute only applies to functions}}
end_comment

begin_function_decl
name|void
modifier|*
name|fail11
parameter_list|(
name|void
modifier|*
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{'alloc_size' attribute argument may only refer to a function parameter of integer type}}
end_comment

begin_function_decl
name|void
modifier|*
name|fail12
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|"abc"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{'alloc_size' attribute requires parameter 1 to be an integer constant}}
end_comment

begin_function_decl
name|void
modifier|*
name|fail12
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|1
operator|,
function_decl|"abc"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{'alloc_size' attribute requires parameter 2 to be an integer constant}}
end_comment

begin_function_decl
name|void
modifier|*
name|fail13
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|1U<<31
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error{{integer constant expression evaluates to value 2147483648 that cannot be represented in a 32-bit signed integer type}}
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|PR31453
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-warning{{'alloc_size' attribute only applies to functions}}
end_comment

end_unit

