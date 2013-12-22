begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function_decl
name|void
modifier|*
name|my_malloc
parameter_list|(
name|unsigned
name|char
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

begin_function_decl
name|void
modifier|*
name|my_calloc
parameter_list|(
name|unsigned
name|char
parameter_list|,
name|short
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
modifier|*
name|my_realloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unsigned
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

begin_function_decl
name|void
modifier|*
name|fn1
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|"xpto"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{'alloc_size' attribute requires parameter 1 to be an integer constant}}
end_comment

begin_function_decl
name|void
modifier|*
name|fn2
parameter_list|(
name|void
modifier|*
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
comment|// expected-error{{'alloc_size' attribute requires an integer constant}}
end_comment

begin_function_decl
name|void
modifier|*
name|fn3
parameter_list|(
name|unsigned
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
comment|// expected-error{{attribute parameter 1 is out of bounds}}
end_comment

begin_function_decl
name|void
modifier|*
name|fn4
parameter_list|(
name|unsigned
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
comment|// expected-error{{attribute parameter 1 is out of bounds}}
end_comment

begin_function_decl
name|void
name|fn5
parameter_list|(
name|unsigned
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
comment|// expected-warning{{only applies to functions that return a pointer}}
end_comment

begin_function_decl
name|char
name|fn6
parameter_list|(
name|unsigned
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
comment|// expected-warning{{only applies to functions that return a pointer}}
end_comment

begin_function_decl
name|void
modifier|*
name|fn7
parameter_list|(
name|unsigned
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
comment|// expected-error {{attribute takes at least 1 argument}}
end_comment

begin_function_decl
name|void
modifier|*
name|fn8
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|1
operator|,
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// OK
end_comment

begin_function_decl
name|void
modifier|*
name|fn9
parameter_list|(
name|unsigned
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|12345678901234567890123
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{integer constant is larger than the largest unsigned integer type}} // expected-error {{attribute parameter 1 is out of bounds}}
end_comment

begin_function_decl
name|void
modifier|*
name|fn10
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(alloc_size
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{redefinition of parameter}} \
end_comment

begin_comment
comment|// expected-error{{a parameter list without types is only allowed in a function definition}} \
end_comment

begin_comment
comment|// expected-error{{attribute parameter 1 is out of bounds}}
end_comment

begin_function_decl
name|void
modifier|*
name|fn11
parameter_list|()
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
comment|// expected-error{{attribute parameter 1 is out of bounds}}
end_comment

end_unit

