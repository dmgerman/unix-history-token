begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|BENCHMARK_SLEEP_H_
end_ifndef

begin_define
define|#
directive|define
name|BENCHMARK_SLEEP_H_
end_define

begin_decl_stmt
name|namespace
name|benchmark
block|{
specifier|const
name|int
name|kNumMillisPerSecond
init|=
literal|1000
decl_stmt|;
specifier|const
name|int
name|kNumMicrosPerMilli
init|=
literal|1000
decl_stmt|;
specifier|const
name|int
name|kNumMicrosPerSecond
init|=
name|kNumMillisPerSecond
operator|*
literal|1000
decl_stmt|;
specifier|const
name|int
name|kNumNanosPerMicro
init|=
literal|1000
decl_stmt|;
specifier|const
name|int
name|kNumNanosPerSecond
init|=
name|kNumNanosPerMicro
operator|*
name|kNumMicrosPerSecond
decl_stmt|;
name|void
name|SleepForMilliseconds
parameter_list|(
name|int
name|milliseconds
parameter_list|)
function_decl|;
name|void
name|SleepForSeconds
parameter_list|(
name|double
name|seconds
parameter_list|)
function_decl|;
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
comment|// BENCHMARK_SLEEP_H_
end_comment

end_unit

