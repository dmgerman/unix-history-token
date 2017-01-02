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

begin_comment
comment|// This note requires C11.
end_comment

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>
literal|199901L
end_if

begin_comment
comment|// expected-note@+2{{'_Nonnull' specified here}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
modifier|*
name|_Nonnull
name|nonnull_int_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
modifier|*
name|_Nullable
name|nullable_int_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
modifier|*
name|_Null_unspecified
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
name|_Nonnull
name|_Nonnull
name|redundant_1
typedef|;
end_typedef

begin_comment
comment|// expected-warning{{duplicate nullability specifier '_Nonnull'}}
end_comment

begin_comment
comment|// Conflicting nullability type specifiers.
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|_Nonnull
name|_Nullable
name|conflicting_1
typedef|;
end_typedef

begin_comment
comment|// expected-error{{nullability specifier '_Nonnull' conflicts with existing specifier '_Nullable'}}
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|_Null_unspecified
name|_Nonnull
name|conflicting_2
typedef|;
end_typedef

begin_comment
comment|// expected-error{{nullability specifier '_Null_unspecified' conflicts with existing specifier '_Nonnull'}}
end_comment

begin_comment
comment|// Redundant nullability specifiers via a typedef are okay.
end_comment

begin_typedef
typedef|typedef
name|nonnull_int_ptr
name|_Nonnull
name|redundant_okay_1
typedef|;
end_typedef

begin_comment
comment|// Conflicting nullability specifiers via a typedef are not.
end_comment

begin_comment
comment|// Some of these errors require C11.
end_comment

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>
literal|199901L
end_if

begin_typedef
typedef|typedef
name|nonnull_int_ptr
name|_Nullable
name|conflicting_2
typedef|;
end_typedef

begin_comment
comment|// expected-error{{nullability specifier '_Nullable' conflicts with existing specifier '_Nonnull'}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|nonnull_int_ptr
name|nonnull_int_ptr_typedef
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>
literal|199901L
end_if

begin_typedef
typedef|typedef
name|nonnull_int_ptr_typedef
name|_Nullable
name|conflicting_2
typedef|;
end_typedef

begin_comment
comment|// expected-error{{nullability specifier '_Nullable' conflicts with existing specifier '_Nonnull'}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|nonnull_int_ptr_typedef
name|nonnull_int_ptr_typedef_typedef
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|nonnull_int_ptr_typedef_typedef
name|_Null_unspecified
name|conflicting_3
typedef|;
end_typedef

begin_comment
comment|// expected-error{{nullability specifier '_Null_unspecified' conflicts with existing specifier '_Nonnull'}}
end_comment

begin_comment
comment|// Nullability applies to all pointer types.
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|_Nonnull
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
name|_Nonnull
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
name|_Nonnull
name|int_type_1
typedef|;
end_typedef

begin_comment
comment|// expected-error{{nullability specifier '_Nonnull' cannot be applied to non-pointer type 'int'}}
end_comment

begin_comment
comment|// Nullability can move out to a pointer/block pointer declarator
end_comment

begin_comment
comment|// (with a suppressed warning).
end_comment

begin_typedef
typedef|typedef
name|_Nonnull
name|int
modifier|*
name|nonnull_int_ptr_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|_Nullable
modifier|*
name|nullable_int_ptr_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Nonnull
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
name|_Nonnull
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
name|_Nonnull
name|int
modifier|*
modifier|*
name|_Nullable
name|nonnull_int_ptr_ptr_1
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Nonnull
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
name|_Nonnull
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
name|_Nonnull
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
name|_Nonnull
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

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|function_pointer_type_5
function_decl|)
parameter_list|(
name|int_ptr
name|_Nonnull
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|void
name|acceptFunctionPtr
argument_list|(
name|_Nonnull
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
name|_Nonnull
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
comment|// expected-warning{{from 'function_pointer_type_3' (aka 'int * _Nonnull (*)(int, int)')}}
name|fp
operator|=
operator|(
name|block_type_3
operator|)
literal|0
expr_stmt|;
comment|// expected-error{{from incompatible type 'block_type_3' (aka 'int * _Nonnull (^)(int, int)')}}
name|fp
operator|=
operator|(
name|function_pointer_type_4
operator|)
literal|0
expr_stmt|;
comment|// expected-warning{{from 'function_pointer_type_4' (aka 'int * _Nonnull (*)(int, int)')}}
name|fp
operator|=
operator|(
name|function_pointer_type_5
operator|)
literal|0
expr_stmt|;
comment|// expected-warning{{from 'function_pointer_type_5' (aka 'void (*)(int * _Nonnull)')}}
name|fp
operator|=
operator|(
name|block_type_4
operator|)
literal|0
expr_stmt|;
comment|// expected-error{{from incompatible type 'block_type_4' (aka 'int_ptr  _Nonnull (^)(int, int)')}}
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
name|_Nonnull
name|int
modifier|*
name|_Nullable
modifier|*
name|conflict_int_ptr_ptr_2
typedef|;
end_typedef

begin_comment
comment|// expected-error{{nullability specifier '_Nonnull' cannot be applied to non-pointer type 'int'}}
end_comment

begin_comment
comment|// Nullability is not part of the canonical type.
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|_Nonnull
name|ambiguous_int_ptr
typedef|;
end_typedef

begin_comment
comment|// Redefining a typedef is a C11 feature.
end_comment

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>
literal|199901L
end_if

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
name|_Nullable
name|ambiguous_int_ptr
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

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
name|_Nonnull
name|ip_1
init|=
operator|&
name|f
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{incompatible pointer types initializing 'int * _Nonnull' with an expression of type 'float *'}}
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
name|_Nonnull
name|iptr
decl_stmt|;
name|float
modifier|*
name|fptr
init|=
name|iptr
decl_stmt|;
comment|// expected-warning{{incompatible pointer types initializing 'float *' with an expression of type 'int * _Nonnull'}}
name|int
modifier|*
modifier|*
name|_Nonnull
name|iptrptr
decl_stmt|;
name|float
modifier|*
modifier|*
name|fptrptr
init|=
name|iptrptr
decl_stmt|;
comment|// expected-warning{{incompatible pointer types initializing 'float **' with an expression of type 'int ** _Nonnull'}}
name|int
modifier|*
name|_Nullable
modifier|*
name|_Nonnull
name|iptrptr2
decl_stmt|;
name|float
modifier|*
modifier|*
name|fptrptr2
init|=
name|iptrptr2
decl_stmt|;
comment|// expected-warning{{incompatible pointer types initializing 'float **' with an expression of type 'int * _Nullable * _Nonnull'}}
block|}
end_function

begin_comment
comment|// Check passing null to a _Nonnull argument.
end_comment

begin_function_decl
name|void
name|accepts_nonnull_1
parameter_list|(
name|_Nonnull
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
name|_Nonnull
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
name|_Nonnull
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
comment|// Check returning nil from a _Nonnull-returning function.
end_comment

begin_function
name|_Nonnull
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
name|_Nonnull
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
name|_Nullable
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
name|_Nonnull
name|int
modifier|*
name|b
init|=
name|ptr
decl_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'int * _Nullable' to non-nullable pointer type 'int * _Nonnull'}}
name|b
operator|=
name|ptr
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'int * _Nullable' to non-nullable pointer type 'int * _Nonnull'}}
name|accepts_nonnull_1
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'int * _Nullable' to non-nullable pointer type 'int * _Nonnull'}}
block|}
end_function

begin_comment
comment|// Check nullability of conditional expressions.
end_comment

begin_function
name|void
name|conditional_expr
parameter_list|(
name|int
name|c
parameter_list|)
block|{
name|int
modifier|*
name|_Nonnull
name|p
decl_stmt|;
name|int
modifier|*
name|_Nonnull
name|nonnullP
decl_stmt|;
name|int
modifier|*
name|_Nullable
name|nullableP
decl_stmt|;
name|int
modifier|*
name|_Null_unspecified
name|unspecifiedP
decl_stmt|;
name|int
modifier|*
name|noneP
decl_stmt|;
name|p
operator|=
name|c
condition|?
name|nonnullP
else|:
name|nonnullP
expr_stmt|;
name|p
operator|=
name|c
condition|?
name|nonnullP
else|:
name|nullableP
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'int * _Nullable' to non-nullable pointer type 'int * _Nonnull'}}
name|p
operator|=
name|c
condition|?
name|nonnullP
else|:
name|unspecifiedP
expr_stmt|;
name|p
operator|=
name|c
condition|?
name|nonnullP
else|:
name|noneP
expr_stmt|;
name|p
operator|=
name|c
condition|?
name|nullableP
else|:
name|nonnullP
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'int * _Nullable' to non-nullable pointer type 'int * _Nonnull'}}
name|p
operator|=
name|c
condition|?
name|nullableP
else|:
name|nullableP
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'int * _Nullable' to non-nullable pointer type 'int * _Nonnull'}}
name|p
operator|=
name|c
condition|?
name|nullableP
else|:
name|unspecifiedP
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'int * _Nullable' to non-nullable pointer type 'int * _Nonnull'}}
name|p
operator|=
name|c
condition|?
name|nullableP
else|:
name|noneP
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'int * _Nullable' to non-nullable pointer type 'int * _Nonnull'}}
name|p
operator|=
name|c
condition|?
name|unspecifiedP
else|:
name|nonnullP
expr_stmt|;
name|p
operator|=
name|c
condition|?
name|unspecifiedP
else|:
name|nullableP
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'int * _Nullable' to non-nullable pointer type 'int * _Nonnull'}}
name|p
operator|=
name|c
condition|?
name|unspecifiedP
else|:
name|unspecifiedP
expr_stmt|;
name|p
operator|=
name|c
condition|?
name|unspecifiedP
else|:
name|noneP
expr_stmt|;
name|p
operator|=
name|c
condition|?
name|noneP
else|:
name|nonnullP
expr_stmt|;
name|p
operator|=
name|c
condition|?
name|noneP
else|:
name|nullableP
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'int * _Nullable' to non-nullable pointer type 'int * _Nonnull'}}
name|p
operator|=
name|c
condition|?
name|noneP
else|:
name|unspecifiedP
expr_stmt|;
name|p
operator|=
name|c
condition|?
name|noneP
else|:
name|noneP
expr_stmt|;
comment|// Check that we don't remove all sugar when creating a new QualType for the
comment|// conditional expression.
typedef|typedef
name|int
modifier|*
name|IntP
typedef|;
typedef|typedef
name|IntP
name|_Nonnull
name|NonnullIntP0
typedef|;
typedef|typedef
name|NonnullIntP0
name|_Nonnull
name|NonnullIntP1
typedef|;
typedef|typedef
name|IntP
name|_Nullable
name|NullableIntP0
typedef|;
typedef|typedef
name|NullableIntP0
name|_Nullable
name|NullableIntP1
typedef|;
name|NonnullIntP1
name|nonnullP2
decl_stmt|;
name|NullableIntP1
name|nullableP2
decl_stmt|;
name|p
operator|=
name|c
condition|?
name|nonnullP2
else|:
name|nonnullP2
expr_stmt|;
name|p
operator|=
name|c
condition|?
name|nonnullP2
else|:
name|nullableP2
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'IntP _Nullable' (aka 'int *') to non-nullable pointer type 'int * _Nonnull'}}
name|p
operator|=
name|c
condition|?
name|nullableP2
else|:
name|nonnullP2
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'NullableIntP1' (aka 'int *') to non-nullable pointer type 'int * _Nonnull'}}
name|p
operator|=
name|c
condition|?
name|nullableP2
else|:
name|nullableP2
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'NullableIntP1' (aka 'int *') to non-nullable pointer type 'int * _Nonnull'}}
block|}
end_function

begin_comment
comment|// Check nullability of binary conditional expressions.
end_comment

begin_function
name|void
name|binary_conditional_expr
parameter_list|()
block|{
name|int
modifier|*
name|_Nonnull
name|p
decl_stmt|;
name|int
modifier|*
name|_Nonnull
name|nonnullP
decl_stmt|;
name|int
modifier|*
name|_Nullable
name|nullableP
decl_stmt|;
name|int
modifier|*
name|_Null_unspecified
name|unspecifiedP
decl_stmt|;
name|int
modifier|*
name|noneP
decl_stmt|;
name|p
operator|=
name|nonnullP
condition|?
else|:
name|nonnullP
expr_stmt|;
name|p
operator|=
name|nonnullP
condition|?
else|:
name|nullableP
expr_stmt|;
name|p
operator|=
name|nonnullP
condition|?
else|:
name|unspecifiedP
expr_stmt|;
name|p
operator|=
name|nonnullP
condition|?
else|:
name|noneP
expr_stmt|;
name|p
operator|=
name|nullableP
condition|?
else|:
name|nonnullP
expr_stmt|;
name|p
operator|=
name|nullableP
condition|?
else|:
name|nullableP
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'int * _Nullable' to non-nullable pointer type 'int * _Nonnull'}}
name|p
operator|=
name|nullableP
condition|?
else|:
name|unspecifiedP
expr_stmt|;
name|p
operator|=
name|nullableP
condition|?
else|:
name|noneP
expr_stmt|;
name|p
operator|=
name|unspecifiedP
condition|?
else|:
name|nonnullP
expr_stmt|;
name|p
operator|=
name|unspecifiedP
condition|?
else|:
name|nullableP
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'int * _Nullable' to non-nullable pointer type 'int * _Nonnull'}}
name|p
operator|=
name|unspecifiedP
condition|?
else|:
name|unspecifiedP
expr_stmt|;
name|p
operator|=
name|unspecifiedP
condition|?
else|:
name|noneP
expr_stmt|;
name|p
operator|=
name|noneP
condition|?
else|:
name|nonnullP
expr_stmt|;
name|p
operator|=
name|noneP
condition|?
else|:
name|nullableP
expr_stmt|;
comment|// expected-warning{{implicit conversion from nullable pointer 'int * _Nullable' to non-nullable pointer type 'int * _Nonnull'}}
name|p
operator|=
name|noneP
condition|?
else|:
name|unspecifiedP
expr_stmt|;
name|p
operator|=
name|noneP
condition|?
else|:
name|noneP
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|int
name|GLOBAL_LENGTH
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Nullability can appear on arrays when the arrays are in parameter lists.
end_comment

begin_function_decl
name|void
name|arrays
parameter_list|(
name|int
name|ints
index|[
name|_Nonnull
index|]
parameter_list|,
name|void
modifier|*
name|ptrs
index|[
name|_Nullable
index|]
parameter_list|,
name|void
modifier|*
modifier|*
name|nestedPtrs
index|[
name|_Nullable
index|]
parameter_list|,
name|void
modifier|*
name|_Null_unspecified
modifier|*
name|_Nonnull
name|nestedPtrs2
index|[
name|_Nullable
index|]
parameter_list|,
name|int
name|fixedSize
index|[
name|_Nonnull
literal|2
index|]
parameter_list|,
name|int
name|staticSize
index|[
name|_Nonnull
specifier|static
literal|2
index|]
parameter_list|,
name|int
name|staticSize2
index|[
specifier|static
name|_Nonnull
literal|2
index|]
parameter_list|,
name|int
name|starSize
index|[
name|_Nonnull
operator|*
index|]
parameter_list|,
name|int
name|vla
index|[
name|_Nonnull
name|GLOBAL_LENGTH
index|]
parameter_list|,
name|void
modifier|*
modifier|*
name|_Nullable
name|reference
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|testDecayedType
parameter_list|()
block|{
name|int
name|produceAnErrorMessage
init|=
name|arrays
decl_stmt|;
comment|// expected-warning {{incompatible pointer to integer conversion initializing 'int' with an expression of type 'void (int * _Nonnull, void ** _Nullable, void *** _Nullable, void * _Null_unspecified * _Nonnull * _Nullable, int * _Nonnull, int * _Nonnull, int * _Nonnull, int * _Nonnull, int * _Nonnull, void ** _Nullable)'}}
block|}
end_function

begin_decl_stmt
name|int
name|notInFunction
index|[
name|_Nullable
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{nullability specifier '_Nullable' cannot be applied to non-pointer type 'int [3]'}}
end_comment

begin_function
name|void
name|nestedArrays
parameter_list|(
name|int
name|x
index|[
literal|5
index|]
index|[
name|_Nonnull
literal|1
index|]
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error {{nullability specifier '_Nonnull' cannot be applied to non-pointer type 'int [1]'}}
end_comment

begin_function
name|void
name|nestedArrays2
parameter_list|(
name|int
name|x
index|[
literal|5
index|]
index|[
name|_Nonnull
literal|1
index|]
index|[
literal|2
index|]
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-error {{nullability specifier '_Nonnull' cannot be applied to non-pointer type 'int [1][2]'}}
end_comment

begin_function
name|void
name|nestedArraysOK
parameter_list|(
name|int
name|x
index|[
name|_Nonnull
literal|5
index|]
index|[
literal|1
index|]
parameter_list|)
block|{}
end_function

begin_comment
comment|// ok
end_comment

begin_function_decl
name|void
name|nullabilityOnBase
parameter_list|(
name|_Nonnull
name|int
name|x
index|[
literal|1
index|]
parameter_list|,
comment|// expected-error {{nullability specifier '_Nonnull' cannot be applied to non-pointer type 'int'}}
name|int
name|_Nonnull
name|y
index|[
literal|1
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{nullability specifier '_Nonnull' cannot be applied to non-pointer type 'int'}}
end_comment

begin_typedef
typedef|typedef
name|int
name|INTS
index|[
literal|4
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|BAD_INTS
index|[
name|_Nonnull
literal|4
index|]
typedef|;
end_typedef

begin_comment
comment|// expected-error {{nullability specifier '_Nonnull' cannot be applied to non-pointer type 'int [4]'}}
end_comment

begin_function_decl
name|void
name|typedefTest
parameter_list|(
name|INTS
name|_Nonnull
name|x
parameter_list|,
name|_Nonnull
name|INTS
name|xx
parameter_list|,
name|INTS
name|_Nonnull
name|y
index|[
literal|2
index|]
parameter_list|,
comment|// expected-error {{nullability specifier '_Nonnull' cannot be applied to non-pointer type 'INTS' (aka 'int [4]')}}
name|INTS
name|z
index|[
name|_Nonnull
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|INTS
name|_Nonnull
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{nullability specifier '_Nonnull' cannot be applied to non-pointer type 'INTS' (aka 'int [4]')}}
end_comment

begin_decl_stmt
name|_Nonnull
name|INTS
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{nullability specifier '_Nonnull' cannot be applied to non-pointer type 'INTS' (aka 'int [4]')}}
end_comment

begin_function
name|void
name|arraysInBlocks
parameter_list|()
block|{
typedef|typedef
name|int
name|INTS
index|[
literal|4
index|]
typedef|;
name|void
function_decl|(
modifier|^
name|simple
function_decl|)
parameter_list|(
name|int
index|[
name|_Nonnull
literal|2
index|]
parameter_list|)
init|=
lambda|^
parameter_list|(
name|int
name|x
index|[
name|_Nonnull
literal|2
index|]
parameter_list|)
block|{}
function_decl|;
name|simple
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{null passed to a callee that requires a non-null argument}}
name|void
function_decl|(
modifier|^
name|nested
function_decl|)
parameter_list|(
name|void
modifier|*
name|_Nullable
name|x
index|[
name|_Nonnull
literal|2
index|]
parameter_list|)
init|=
lambda|^
parameter_list|(
name|void
modifier|*
name|_Nullable
name|x
index|[
name|_Nonnull
literal|2
index|]
parameter_list|)
block|{}
function_decl|;
name|nested
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{null passed to a callee that requires a non-null argument}}
name|void
function_decl|(
modifier|^
name|nestedBad
function_decl|)
parameter_list|(
name|int
name|x
index|[
literal|2
index|]
index|[
name|_Nonnull
literal|2
index|]
parameter_list|)
init|=
comment|// expected-error {{nullability specifier '_Nonnull' cannot be applied to non-pointer type 'int [2]'}}
lambda|^
parameter_list|(
name|int
name|x
index|[
literal|2
index|]
index|[
name|_Nonnull
literal|2
index|]
parameter_list|)
block|{}
function_decl|;
comment|// expected-error {{nullability specifier '_Nonnull' cannot be applied to non-pointer type 'int [2]'}}
name|void
function_decl|(
modifier|^
name|withTypedef
function_decl|)
parameter_list|(
name|INTS
name|_Nonnull
parameter_list|)
init|=
lambda|^
parameter_list|(
name|INTS
name|_Nonnull
name|x
parameter_list|)
block|{}
function_decl|;
name|withTypedef
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{null passed to a callee that requires a non-null argument}}
name|void
function_decl|(
modifier|^
name|withTypedefBad
function_decl|)
parameter_list|(
name|INTS
name|_Nonnull
index|[
literal|2
index|]
parameter_list|)
init|=
comment|// expected-error {{nullability specifier '_Nonnull' cannot be applied to non-pointer type 'INTS' (aka 'int [4]')}}
lambda|^
parameter_list|(
name|INTS
name|_Nonnull
name|x
index|[
literal|2
index|]
parameter_list|)
block|{}
function_decl|;
comment|// expected-error {{nullability specifier '_Nonnull' cannot be applied to non-pointer type 'INTS' (aka 'int [4]')}}
block|}
end_function

end_unit

