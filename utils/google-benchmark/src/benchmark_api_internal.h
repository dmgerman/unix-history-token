begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|BENCHMARK_API_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|BENCHMARK_API_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"benchmark/benchmark_api.h"
end_include

begin_include
include|#
directive|include
file|<cmath>
end_include

begin_include
include|#
directive|include
file|<iosfwd>
end_include

begin_include
include|#
directive|include
file|<limits>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|benchmark
block|{
name|namespace
name|internal
block|{
comment|// Information kept per benchmark we may want to run
block|struct
name|Benchmark
operator|::
name|Instance
block|{
name|std
operator|::
name|string
name|name
block|;
name|Benchmark
operator|*
name|benchmark
block|;
name|ReportMode
name|report_mode
block|;
name|std
operator|::
name|vector
operator|<
name|int
operator|>
name|arg
block|;
name|TimeUnit
name|time_unit
block|;
name|int
name|range_multiplier
block|;
name|bool
name|use_real_time
block|;
name|bool
name|use_manual_time
block|;
name|BigO
name|complexity
block|;
name|BigOFunc
operator|*
name|complexity_lambda
block|;
name|bool
name|last_benchmark_instance
block|;
name|int
name|repetitions
block|;
name|double
name|min_time
block|;
name|int
name|threads
block|;
comment|// Number of concurrent threads to us
block|}
expr_stmt|;
name|bool
name|FindBenchmarksInternal
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|re
argument_list|,
name|std
operator|::
name|vector
operator|<
name|Benchmark
operator|::
name|Instance
operator|>
operator|*
name|benchmarks
argument_list|,
name|std
operator|::
name|ostream
operator|*
name|Err
argument_list|)
decl_stmt|;
name|namespace
block|{
name|bool
name|IsZero
parameter_list|(
name|double
name|n
parameter_list|)
block|{
return|return
name|std
operator|::
name|abs
argument_list|(
name|n
argument_list|)
operator|<
name|std
operator|::
name|numeric_limits
operator|<
name|double
operator|>
operator|::
name|epsilon
argument_list|()
return|;
block|}
block|}
comment|// end namespace
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
comment|// BENCHMARK_API_INTERNAL_H
end_comment

end_unit

