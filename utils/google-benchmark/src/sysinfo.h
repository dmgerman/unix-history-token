begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|BENCHMARK_SYSINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|BENCHMARK_SYSINFO_H_
end_define

begin_decl_stmt
name|namespace
name|benchmark
block|{
name|int
name|NumCPUs
parameter_list|()
function_decl|;
name|double
name|CyclesPerSecond
parameter_list|()
function_decl|;
name|bool
name|CpuScalingEnabled
parameter_list|()
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
comment|// BENCHMARK_SYSINFO_H_
end_comment

end_unit

