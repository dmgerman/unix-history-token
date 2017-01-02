begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|BENCHMARK_ARRAYSIZE_H_
end_ifndef

begin_define
define|#
directive|define
name|BENCHMARK_ARRAYSIZE_H_
end_define

begin_include
include|#
directive|include
file|"internal_macros.h"
end_include

begin_decl_stmt
name|namespace
name|benchmark
block|{
name|namespace
name|internal
block|{
comment|// The arraysize(arr) macro returns the # of elements in an array arr.
comment|// The expression is a compile-time constant, and therefore can be
comment|// used in defining new arrays, for example.  If you use arraysize on
comment|// a pointer by mistake, you will get a compile-time error.
comment|//
comment|// This template function declaration is used in defining arraysize.
comment|// Note that the function doesn't need an implementation, as we only
comment|// use its type.
name|template
operator|<
name|typename
name|T
operator|,
name|size_t
name|N
operator|>
name|char
argument_list|(
operator|&
name|ArraySizeHelper
argument_list|(
name|T
argument_list|(
operator|&
name|array
argument_list|)
index|[
name|N
index|]
argument_list|)
argument_list|)
index|[
name|N
index|]
expr_stmt|;
comment|// That gcc wants both of these prototypes seems mysterious. VC, for
comment|// its part, can't decide which to use (another mystery). Matching of
comment|// template overloads: the final frontier.
ifndef|#
directive|ifndef
name|COMPILER_MSVC
name|template
operator|<
name|typename
name|T
operator|,
name|size_t
name|N
operator|>
name|char
argument_list|(
operator|&
name|ArraySizeHelper
argument_list|(
specifier|const
name|T
argument_list|(
operator|&
name|array
argument_list|)
index|[
name|N
index|]
argument_list|)
argument_list|)
index|[
name|N
index|]
expr_stmt|;
endif|#
directive|endif
define|#
directive|define
name|arraysize
parameter_list|(
name|array
parameter_list|)
value|(sizeof(::benchmark::internal::ArraySizeHelper(array)))
block|}
comment|// end namespace internal
block|}
end_decl_stmt

begin_comment
comment|// end namespace benchmark
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// BENCHMARK_ARRAYSIZE_H_
end_comment

end_unit

