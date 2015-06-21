begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fblocks -Wnullable-to-nonnull-conversion -Wno-nullability-declspec %s -verify
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|nullability
argument_list|)
end_if

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|nullability feature should be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
modifier|*
name|int_ptr
typedef|;
end_typedef

begin_comment
comment|// Parse nullability type specifiers.
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|__nonnull
name|nonnull_int_ptr
typedef|;
end_typedef

begin_comment
comment|// expected-note{{'__nonnull' specified here}}
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|__nullable
name|nullable_int_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
modifier|*
name|__null_unspecified
name|null_unspecified_int_ptr
typedef|;
end_typedef

begin_comment
comment|// Redundant nullability type specifiers.
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|__nonnull
name|__nonnull
name|redundant_1
typedef|;
end_typedef

begin_comment
comment|// expected-warning{{duplicate nullability specifier '__nonnull'}}
end_comment

begin_comment
comment|// Conflicting nullability type specifiers.
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|__nonnull
name|__nullable
name|conflicting_1
typedef|;
end_typedef

begin_comment
comment|// expected-error{{nullability specifier '__nonnull' conflicts with existing specifier '__nullable'}}
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|__null_unspecified
name|__nonnull
name|conflicting_2
typedef|;
end_typedef

begin_comment
comment|// expected-error{{nullability specifier '__null_unspecified' conflicts with existing specifier '__nonnull'}}
end_comment

begin_comment
comment|// Redundant nullability specifiers via a typedef are okay.
end_comment

begin_typedef
typedef|typedef
name|nonnull_int_ptr
name|__nonnull
name|redundant_okay_1
typedef|;
end_typedef

begin_comment
comment|// Conflicting nullability specifiers via a typedef are not.
end_comment

begin_typedef
typedef|typedef
name|nonnull_int_ptr
name|__nullable
name|conflicting_2
typedef|;
end_typedef

begin_comment
comment|// expected-error{{nullability specifier '__nullable' conflicts with existing specifier '__nonnull'}}
end_comment

begin_typedef
typedef|typedef
name|nonnull_int_ptr
name|nonnull_int_ptr_typedef
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|nonnull_int_ptr_typedef
name|__nullable
name|conflicting_2
typedef|;
end_typedef

begin_comment
comment|// expected-error{{nullability specifier '__nullable' conflicts with existing specifier '__nonnull'}}
end_comment

begin_typedef
typedef|typedef
name|nonnull_int_ptr_typedef
name|nonnull_int_ptr_typedef_typedef
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|nonnull_int_ptr_typedef_typedef
name|__null_unspecified
name|conflicting_3
typedef|;
end_typedef

begin_comment
comment|// expected-error{{nullability specifier '__null_unspecified' conflicts with existing specifier '__nonnull'}}
end_comment

begin_comment
comment|// Nullability applies to all pointer types.
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|__nonnull
name|function_pointer_type_1
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|^
name|__nonnull
name|block_type_1
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Nullability must be on a pointer type.
end_comment

begin_typedef
typedef|typedef
name|int
name|__nonnull
name|int_type_1
typedef|;
end_typedef

begin_comment
comment|// expected-error{{nullability specifier '__nonnull' cannot be applied to non-pointer type 'int'}}
end_comment

begin_comment
comment|// Nullability can move out to a pointer/block pointer declarator
end_comment

begin_comment
comment|// (with a suppressed warning).
end_comment

begin_typedef
typedef|typedef
name|__nonnull
name|int
modifier|*
name|nonnull_int_ptr_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__nullable
modifier|*
name|nullable_int_ptr_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__nonnull
name|int
function_decl|(
modifier|*
name|function_pointer_type_2
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|__nonnull
name|int
function_decl|(
modifier|^
name|block_type_2
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|__nonnull
name|int
modifier|*
modifier|*
name|__nullable
name|nonnull_int_ptr_ptr_1
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__nonnull
name|int
modifier|*
function_decl|(
modifier|^
name|block_type_3
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|__nonnull
name|int
modifier|*
function_decl|(
modifier|*
name|function_pointer_type_3
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|__nonnull
name|int_ptr
function_decl|(
modifier|^
name|block_type_4
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|__nonnull
name|int_ptr
function_decl|(
modifier|*
name|function_pointer_type_4
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|void
name|acceptFunctionPtr
argument_list|(
name|__nonnull
name|int
operator|*
call|(
modifier|*
call|)
argument_list|(
name|void
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|acceptBlockPtr
argument_list|(
name|__nonnull
name|int
operator|*
call|(
modifier|^
call|)
argument_list|(
name|void
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|testBlockFunctionPtrNullability
parameter_list|()
block|{
name|float
modifier|*
name|fp
decl_stmt|;
name|fp
operator|=
operator|(
name|function_pointer_type_3
operator|)
literal|0
expr_stmt|;
comment|// expected-warning{{from 'function_pointer_type_3' (aka 'int * __nonnull (*)(int, int)')}}
name|fp
operator|=
operator|(
name|block_type_3
operator|)
literal|0
expr_stmt|;
comment|// expected-error{{from incompatible type 'block_type_3' (aka 'int * __nonnull (^)(int, int)')}}
name|fp
operator|=
operator|(
name|function_pointer_type_4
operator|)
literal|0
expr_stmt|;
comment|// expected-warning{{from 'function_pointer_type_4' (aka 'int_ptr  __nonnull (*)(int, int)')}}
name|fp
operator|=
operator|(
name|block_type_4
operator|)
literal|0
expr_stmt|;
comment|// expected-error{{from incompatible type 'block_type_4' (aka 'int_ptr  __nonnull (^)(int, int)')}}
name|acceptFunctionPtr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
name|acceptBlockPtr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Moving nullability where it creates a conflict.
end_comment

begin_typedef
typedef|typedef
name|__nonnull
name|int
modifier|*
name|__nullable
modifier|*
name|conflict_int_ptr_ptr_2
typedef|;
end_typedef

begin_comment
comment|// expected-error{{nullability specifier '__nonnull' cannot be applied to non-pointer type 'int'}}
end_comment

begin_comment
comment|// Nullability is not part of the canonical type.
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|__nonnull
name|ambiguous_int_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
modifier|*
name|ambiguous_int_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
modifier|*
name|__nullable
name|ambiguous_int_ptr
typedef|;
end_typedef

begin_comment
comment|// Printing of nullability.
end_comment

begin_decl_stmt
name|float
name|f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|__nonnull
name|ip_1
init|=
operator|&
name|f
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{incompatible pointer types initializing 'int * __nonnull' with an expression of type 'float *'}}
end_comment

begin_comment
comment|// Check printing of nullability specifiers.
end_comment

begin_function
name|void
name|printing_nullability
parameter_list|(
name|void
parameter_list|)
block|{
name|int
modifier|*
name|__nonnull
name|iptr
decl_stmt|;
name|float
modifier|*
name|fptr
init|=
name|iptr
decl_stmt|;
comment|// expected-warning{{incompatible pointer types initializing 'float *' with an expression of type 'int * __nonnull'}}
name|int
modifier|*
modifier|*
name|__nonnull
name|iptrptr
decl_stmt|;
name|float
modifier|*
modifier|*
name|fptrptr
init|=
name|iptrptr
decl_stmt|;
comment|// expected-warning{{incompatible pointer types initializing 'float **' with an expression of type 'int ** __nonnull'}}
name|int
modifier|*
name|__nullable
modifier|*
name|__nonnull
name|iptrptr2
decl_stmt|;
name|float
modifier|*
modifier|*
name|fptrptr2
init|=
name|iptrptr2
decl_stmt|;
comment|// expected-warning{{incompatible pointer types initializing 'float **' with an expression of type 'int * __nullable * __nonnull'}}
block|}
end_function

begin_comment
comment|// Check passing null to a __nonnull argument.
end_comment

begin_function_decl
name|void
name|accepts_nonnull_1
parameter_list|(
name|__nonnull
name|int
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
modifier|*
name|accepts_nonnull_2
function_decl|)
parameter_list|(
name|__nonnull
name|int
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
modifier|^
name|accepts_nonnull_3
function_decl|)
parameter_list|(
name|__nonnull
name|int
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_accepts_nonnull_null_pointer_literal
parameter_list|()
block|{
name|accepts_nonnull_1
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{null passed to a callee that requires a non-null argument}}
name|accepts_nonnull_2
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{null passed to a callee that requires a non-null argument}}
name|accepts_nonnull_3
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{null passed to a callee that requires a non-null argument}}
block|}
end_function

begin_comment
comment|// Check returning nil from a __nonnull-returning function.
end_comment

begin_function
name|__nonnull
name|int
modifier|*
name|returns_int_ptr
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
condition|)
block|{
return|return
literal|0
return|;
comment|// expected-warning{{null returned from function that requires a non-null return value}}
block|}
return|return
operator|(
name|__nonnull
name|int
operator|*
operator|)
literal|0
return|;
block|}
end_function

begin_comment
comment|// Check nullable-to-nonnull conversions.
end_comment

begin_function
name|void
name|nullable_to_nonnull
parameter_list|(
name|__nullable
name|int
modifier|*
name|ptr
parameter_list|)
block|{
name|int
modifier|*
name|a
init|=
name|ptr
decl_stmt|;
comment|// okay
name|__nonnull
name|int
modifier|*
name|b
init|=
name|ptr
decl_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'int * __nullable' to non-nullable pointer type 'int * __nonnull'}}
block|}
end_function

end_unit

