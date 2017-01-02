begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_function_decl
name|void
name|firstThingInTheFileThatNeedsNullabilityIsAnArray
parameter_list|(
name|int
name|ints
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|ARRAYS_CHECKED
end_if

begin_comment
comment|// expected-warning@-2 {{array parameter is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-3 {{insert '_Nullable' if the array parameter may be null}}
end_comment

begin_comment
comment|// expected-note@-4 {{insert '_Nonnull' if the array parameter should never be null}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
modifier|*
name|secondThingInTheFileThatNeedsNullabilityIsAPointer
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|ARRAYS_CHECKED
end_if

begin_comment
comment|// expected-warning@-2 {{pointer is missing a nullability type specifier (_Nonnull, _Nullable, or _Null_unspecified)}}
end_comment

begin_comment
comment|// expected-note@-3 {{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-4 {{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
modifier|*
name|_Nonnull
name|triggerConsistencyWarnings
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|test
parameter_list|(
name|int
name|ints
index|[]
parameter_list|,
if|#
directive|if
name|ARRAYS_CHECKED
comment|// expected-warning@-2 {{array parameter is missing a nullability type specifier}}
comment|// expected-note@-3 {{insert '_Nullable' if the array parameter may be null}}
comment|// expected-note@-4 {{insert '_Nonnull' if the array parameter should never be null}}
endif|#
directive|endif
name|void
modifier|*
name|ptrs
index|[]
parameter_list|,
comment|// expected-warning {{pointer is missing a nullability type specifier}}
comment|// expected-note@-1 {{insert '_Nullable' if the pointer may be null}}
comment|// expected-note@-2 {{insert '_Nonnull' if the pointer should never be null}}
if|#
directive|if
name|ARRAYS_CHECKED
comment|// expected-warning@-4 {{array parameter is missing a nullability type specifier}}
comment|// expected-note@-5 {{insert '_Nullable' if the array parameter may be null}}
comment|// expected-note@-6 {{insert '_Nonnull' if the array parameter should never be null}}
endif|#
directive|endif
name|void
modifier|*
modifier|*
name|nestedPtrs
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning 2 {{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 2 {{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2 2 {{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_if
if|#
directive|if
name|ARRAYS_CHECKED
end_if

begin_comment
comment|// expected-warning@-4 {{array parameter is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-5 {{insert '_Nullable' if the array parameter may be null}}
end_comment

begin_comment
comment|// expected-note@-6 {{insert '_Nonnull' if the array parameter should never be null}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|testArraysOK
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
name|_Nonnull
index|]
parameter_list|,
comment|// expected-warning {{pointer is missing a nullability type specifier}}
comment|// expected-note@-1 {{insert '_Nullable' if the pointer may be null}}
comment|// expected-note@-2 {{insert '_Nonnull' if the pointer should never be null}}
name|void
modifier|*
modifier|*
name|nestedPtrs
index|[
name|_Nonnull
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning 2 {{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 2 {{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2 2 {{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_function_decl
name|void
name|testAllOK
parameter_list|(
name|int
name|ints
index|[
name|_Nonnull
index|]
parameter_list|,
name|void
modifier|*
name|_Nullable
name|ptrs
index|[
name|_Nonnull
index|]
parameter_list|,
name|void
modifier|*
name|_Nullable
modifier|*
name|_Nullable
name|nestedPtrs
index|[
name|_Nonnull
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|testVAList
parameter_list|(
name|va_list
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// no warning
end_comment

begin_if
if|#
directive|if
name|__cplusplus
end_if

begin_comment
comment|// Carefully construct a test case such that if a platform's va_list is an array
end_comment

begin_comment
comment|// or pointer type, it gets tested, but otherwise it does not.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
name|F
operator|>
expr|struct
name|pointer_like_or
block|{
typedef|typedef
name|F
name|type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
name|F
operator|>
expr|struct
name|pointer_like_or
operator|<
name|T
operator|*
operator|,
name|F
operator|>
block|{
typedef|typedef
name|T
modifier|*
name|type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
name|F
operator|>
expr|struct
name|pointer_like_or
operator|<
name|T
operator|*
specifier|const
operator|,
name|F
operator|>
block|{
typedef|typedef
name|T
modifier|*
specifier|const
name|type
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
name|F
operator|>
expr|struct
name|pointer_like_or
operator|<
name|T
index|[]
operator|,
name|F
operator|>
block|{
typedef|typedef
name|T
name|type
index|[]
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
name|F
operator|,
name|unsigned
name|size
operator|>
expr|struct
name|pointer_like_or
operator|<
name|T
index|[
name|size
index|]
operator|,
name|F
operator|>
block|{
typedef|typedef
name|T
name|type
index|[
name|size
index|]
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|testVAListWithNullability
argument_list|(
name|pointer_like_or
operator|<
name|va_list
argument_list|,
name|void
operator|*
operator|>
operator|::
name|type
name|_Nonnull
name|x
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no errors
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
literal|1
index|]
parameter_list|)
block|{}
end_function

begin_if
if|#
directive|if
name|ARRAYS_CHECKED
end_if

begin_comment
comment|// expected-warning@-2 {{array parameter is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-3 {{insert '_Nullable' if the array parameter may be null}}
end_comment

begin_comment
comment|// expected-note@-4 {{insert '_Nonnull' if the array parameter should never be null}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
operator|!
name|__cplusplus
end_if

begin_function
name|void
name|staticOK
parameter_list|(
name|int
name|x
index|[
specifier|static
literal|5
index|]
index|[
literal|1
index|]
parameter_list|)
block|{}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|globalArraysDoNotNeedNullability
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|INTS
index|[
literal|4
index|]
typedef|;
end_typedef

begin_function_decl
name|void
name|typedefTest
parameter_list|(
name|INTS
name|x
parameter_list|,
if|#
directive|if
name|ARRAYS_CHECKED
comment|// expected-warning@-2 {{array parameter is missing a nullability type specifier}}
comment|// expected-note@-3 {{insert '_Nullable' if the array parameter may be null}}
comment|// expected-note@-4 {{insert '_Nonnull' if the array parameter should never be null}}
endif|#
directive|endif
name|INTS
name|_Nonnull
name|x2
parameter_list|,
name|_Nonnull
name|INTS
name|x3
parameter_list|,
name|INTS
name|y
index|[
literal|2
index|]
parameter_list|,
if|#
directive|if
name|ARRAYS_CHECKED
comment|// expected-warning@-2 {{array parameter is missing a nullability type specifier}}
comment|// expected-note@-3 {{insert '_Nullable' if the array parameter may be null}}
comment|// expected-note@-4 {{insert '_Nonnull' if the array parameter should never be null}}
endif|#
directive|endif
name|INTS
name|y2
index|[
name|_Nonnull
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_pragma
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|begin
end_pragma

begin_function_decl
name|void
name|testAssumeNonnull
parameter_list|(
name|int
name|ints
index|[]
parameter_list|,
if|#
directive|if
name|ARRAYS_CHECKED
comment|// expected-warning@-2 {{array parameter is missing a nullability type specifier}}
comment|// expected-note@-3 {{insert '_Nullable' if the array parameter may be null}}
comment|// expected-note@-4 {{insert '_Nonnull' if the array parameter should never be null}}
endif|#
directive|endif
name|void
modifier|*
name|ptrs
index|[]
parameter_list|,
if|#
directive|if
name|ARRAYS_CHECKED
comment|// expected-warning@-2 {{array parameter is missing a nullability type specifier}}
comment|// expected-note@-3 {{insert '_Nullable' if the array parameter may be null}}
comment|// expected-note@-4 {{insert '_Nonnull' if the array parameter should never be null}}
endif|#
directive|endif
name|void
modifier|*
modifier|*
name|nestedPtrs
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning 2 {{pointer is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-1 2 {{insert '_Nullable' if the pointer may be null}}
end_comment

begin_comment
comment|// expected-note@-2 2 {{insert '_Nonnull' if the pointer should never be null}}
end_comment

begin_if
if|#
directive|if
name|ARRAYS_CHECKED
end_if

begin_comment
comment|// expected-warning@-4 {{array parameter is missing a nullability type specifier}}
end_comment

begin_comment
comment|// expected-note@-5 {{insert '_Nullable' if the array parameter may be null}}
end_comment

begin_comment
comment|// expected-note@-6 {{insert '_Nonnull' if the array parameter should never be null}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|testAssumeNonnullAllOK
parameter_list|(
name|int
name|ints
index|[
name|_Nonnull
index|]
parameter_list|,
name|void
modifier|*
name|_Nullable
name|ptrs
index|[
name|_Nonnull
index|]
parameter_list|,
name|void
modifier|*
name|_Nullable
modifier|*
name|_Nullable
name|nestedPtrs
index|[
name|_Nonnull
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|testAssumeNonnullAllOK2
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
name|_Nonnull
index|]
parameter_list|,
comment|// backwards-compatibility
name|void
modifier|*
name|_Nullable
modifier|*
name|_Nullable
name|nestedPtrs
index|[
name|_Nonnull
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_pragma
pragma|#
directive|pragma
name|clang
name|assume_nonnull
name|end
end_pragma

end_unit

