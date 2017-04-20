begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2015 Google Inc. All rights reserved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Licensed under the Apache License, Version 2.0 (the "License");
end_comment

begin_comment
comment|// you may not use this file except in compliance with the License.
end_comment

begin_comment
comment|// You may obtain a copy of the License at
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     http://www.apache.org/licenses/LICENSE-2.0
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Unless required by applicable law or agreed to in writing, software
end_comment

begin_comment
comment|// distributed under the License is distributed on an "AS IS" BASIS,
end_comment

begin_comment
comment|// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
end_comment

begin_comment
comment|// See the License for the specific language governing permissions and
end_comment

begin_comment
comment|// limitations under the License.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BENCHMARK_REPORTER_H_
end_ifndef

begin_define
define|#
directive|define
name|BENCHMARK_REPORTER_H_
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<iosfwd>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|"benchmark_api.h"
end_include

begin_comment
comment|// For forward declaration of BenchmarkReporter
end_comment

begin_decl_stmt
name|namespace
name|benchmark
block|{
comment|// Interface for custom benchmark result printers.
comment|// By default, benchmark reports are printed to stdout. However an application
comment|// can control the destination of the reports by calling
comment|// RunSpecifiedBenchmarks and passing it a custom reporter object.
comment|// The reporter object must implement the following interface.
name|class
name|BenchmarkReporter
block|{
name|public
label|:
struct|struct
name|Context
block|{
name|int
name|num_cpus
decl_stmt|;
name|double
name|mhz_per_cpu
decl_stmt|;
name|bool
name|cpu_scaling_enabled
decl_stmt|;
comment|// The number of chars in the longest benchmark name.
name|size_t
name|name_field_width
decl_stmt|;
block|}
struct|;
struct|struct
name|Run
block|{
name|Run
argument_list|()
operator|:
name|error_occurred
argument_list|(
name|false
argument_list|)
operator|,
name|iterations
argument_list|(
literal|1
argument_list|)
operator|,
name|time_unit
argument_list|(
name|kNanosecond
argument_list|)
operator|,
name|real_accumulated_time
argument_list|(
literal|0
argument_list|)
operator|,
name|cpu_accumulated_time
argument_list|(
literal|0
argument_list|)
operator|,
name|bytes_per_second
argument_list|(
literal|0
argument_list|)
operator|,
name|items_per_second
argument_list|(
literal|0
argument_list|)
operator|,
name|max_heapbytes_used
argument_list|(
literal|0
argument_list|)
operator|,
name|complexity
argument_list|(
name|oNone
argument_list|)
operator|,
name|complexity_lambda
argument_list|()
operator|,
name|complexity_n
argument_list|(
literal|0
argument_list|)
operator|,
name|report_big_o
argument_list|(
name|false
argument_list|)
operator|,
name|report_rms
argument_list|(
name|false
argument_list|)
operator|,
name|counters
argument_list|()
block|{}
name|std
operator|::
name|string
name|benchmark_name
expr_stmt|;
name|std
operator|::
name|string
name|report_label
expr_stmt|;
comment|// Empty if not set by benchmark.
name|bool
name|error_occurred
decl_stmt|;
name|std
operator|::
name|string
name|error_message
expr_stmt|;
name|int64_t
name|iterations
decl_stmt|;
name|TimeUnit
name|time_unit
decl_stmt|;
name|double
name|real_accumulated_time
decl_stmt|;
name|double
name|cpu_accumulated_time
decl_stmt|;
comment|// Return a value representing the real time per iteration in the unit
comment|// specified by 'time_unit'.
comment|// NOTE: If 'iterations' is zero the returned value represents the
comment|// accumulated time.
name|double
name|GetAdjustedRealTime
argument_list|()
specifier|const
expr_stmt|;
comment|// Return a value representing the cpu time per iteration in the unit
comment|// specified by 'time_unit'.
comment|// NOTE: If 'iterations' is zero the returned value represents the
comment|// accumulated time.
name|double
name|GetAdjustedCPUTime
argument_list|()
specifier|const
expr_stmt|;
comment|// Zero if not set by benchmark.
name|double
name|bytes_per_second
decl_stmt|;
name|double
name|items_per_second
decl_stmt|;
comment|// This is set to 0.0 if memory tracing is not enabled.
name|double
name|max_heapbytes_used
decl_stmt|;
comment|// Keep track of arguments to compute asymptotic complexity
name|BigO
name|complexity
decl_stmt|;
name|BigOFunc
modifier|*
name|complexity_lambda
decl_stmt|;
name|int
name|complexity_n
decl_stmt|;
comment|// Inform print function whether the current run is a complexity report
name|bool
name|report_big_o
decl_stmt|;
name|bool
name|report_rms
decl_stmt|;
name|UserCounters
name|counters
decl_stmt|;
block|}
struct|;
comment|// Construct a BenchmarkReporter with the output stream set to 'std::cout'
comment|// and the error stream set to 'std::cerr'
name|BenchmarkReporter
argument_list|()
expr_stmt|;
comment|// Called once for every suite of benchmarks run.
comment|// The parameter "context" contains information that the
comment|// reporter may wish to use when generating its report, for example the
comment|// platform under which the benchmarks are running. The benchmark run is
comment|// never started if this function returns false, allowing the reporter
comment|// to skip runs based on the context information.
name|virtual
name|bool
name|ReportContext
parameter_list|(
specifier|const
name|Context
modifier|&
name|context
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Called once for each group of benchmark runs, gives information about
comment|// cpu-time and heap memory usage during the benchmark run. If the group
comment|// of runs contained more than two entries then 'report' contains additional
comment|// elements representing the mean and standard deviation of those runs.
comment|// Additionally if this group of runs was the last in a family of benchmarks
comment|// 'reports' contains additional entries representing the asymptotic
comment|// complexity and RMS of that benchmark family.
name|virtual
name|void
name|ReportRuns
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|Run
operator|>
operator|&
name|report
argument_list|)
init|=
literal|0
decl_stmt|;
comment|// Called once and only once after ever group of benchmarks is run and
comment|// reported.
name|virtual
name|void
name|Finalize
parameter_list|()
block|{}
comment|// REQUIRES: The object referenced by 'out' is valid for the lifetime
comment|// of the reporter.
name|void
name|SetOutputStream
argument_list|(
name|std
operator|::
name|ostream
operator|*
name|out
argument_list|)
block|{
name|assert
argument_list|(
name|out
argument_list|)
expr_stmt|;
name|output_stream_
operator|=
name|out
expr_stmt|;
block|}
comment|// REQUIRES: The object referenced by 'err' is valid for the lifetime
comment|// of the reporter.
name|void
name|SetErrorStream
argument_list|(
name|std
operator|::
name|ostream
operator|*
name|err
argument_list|)
block|{
name|assert
argument_list|(
name|err
argument_list|)
expr_stmt|;
name|error_stream_
operator|=
name|err
expr_stmt|;
block|}
name|std
operator|::
name|ostream
operator|&
name|GetOutputStream
argument_list|()
specifier|const
block|{
return|return
operator|*
name|output_stream_
return|;
block|}
name|std
operator|::
name|ostream
operator|&
name|GetErrorStream
argument_list|()
specifier|const
block|{
return|return
operator|*
name|error_stream_
return|;
block|}
name|virtual
operator|~
name|BenchmarkReporter
argument_list|()
expr_stmt|;
comment|// Write a human readable string to 'out' representing the specified
comment|// 'context'.
comment|// REQUIRES: 'out' is non-null.
specifier|static
name|void
name|PrintBasicContext
argument_list|(
name|std
operator|::
name|ostream
operator|*
name|out
argument_list|,
name|Context
specifier|const
operator|&
name|context
argument_list|)
decl_stmt|;
name|private
label|:
name|std
operator|::
name|ostream
operator|*
name|output_stream_
expr_stmt|;
name|std
operator|::
name|ostream
operator|*
name|error_stream_
expr_stmt|;
block|}
empty_stmt|;
comment|// Simple reporter that outputs benchmark data to the console. This is the
comment|// default reporter used by RunSpecifiedBenchmarks().
name|class
name|ConsoleReporter
range|:
name|public
name|BenchmarkReporter
block|{
name|public
operator|:
expr|enum
name|OutputOptions
block|{
name|OO_None
block|,
name|OO_Color
block|}
block|;
name|explicit
name|ConsoleReporter
argument_list|(
argument|OutputOptions color_output = OO_Color
argument_list|)
operator|:
name|name_field_width_
argument_list|(
literal|0
argument_list|)
block|,
name|color_output_
argument_list|(
argument|color_output == OO_Color
argument_list|)
block|{}
name|virtual
name|bool
name|ReportContext
argument_list|(
specifier|const
name|Context
operator|&
name|context
argument_list|)
block|;
name|virtual
name|void
name|ReportRuns
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|Run
operator|>
operator|&
name|reports
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|PrintRunData
argument_list|(
specifier|const
name|Run
operator|&
name|report
argument_list|)
block|;
name|virtual
name|void
name|PrintHeader
argument_list|(
specifier|const
name|Run
operator|&
name|report
argument_list|)
block|;
name|size_t
name|name_field_width_
block|;
name|bool
name|printed_header_
block|;
name|private
operator|:
name|bool
name|color_output_
block|; }
decl_stmt|;
name|class
name|JSONReporter
range|:
name|public
name|BenchmarkReporter
block|{
name|public
operator|:
name|JSONReporter
argument_list|()
operator|:
name|first_report_
argument_list|(
argument|true
argument_list|)
block|{}
name|virtual
name|bool
name|ReportContext
argument_list|(
specifier|const
name|Context
operator|&
name|context
argument_list|)
block|;
name|virtual
name|void
name|ReportRuns
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|Run
operator|>
operator|&
name|reports
argument_list|)
block|;
name|virtual
name|void
name|Finalize
argument_list|()
block|;
name|private
operator|:
name|void
name|PrintRunData
argument_list|(
specifier|const
name|Run
operator|&
name|report
argument_list|)
block|;
name|bool
name|first_report_
block|; }
decl_stmt|;
name|class
name|CSVReporter
range|:
name|public
name|BenchmarkReporter
block|{
name|public
operator|:
name|CSVReporter
argument_list|()
operator|:
name|printed_header_
argument_list|(
argument|false
argument_list|)
block|{}
name|virtual
name|bool
name|ReportContext
argument_list|(
specifier|const
name|Context
operator|&
name|context
argument_list|)
block|;
name|virtual
name|void
name|ReportRuns
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|Run
operator|>
operator|&
name|reports
argument_list|)
block|;
name|private
operator|:
name|void
name|PrintRunData
argument_list|(
specifier|const
name|Run
operator|&
name|report
argument_list|)
block|;
name|bool
name|printed_header_
block|;
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>
name|user_counter_names_
block|; }
decl_stmt|;
specifier|inline
specifier|const
name|char
modifier|*
name|GetTimeUnitString
parameter_list|(
name|TimeUnit
name|unit
parameter_list|)
block|{
switch|switch
condition|(
name|unit
condition|)
block|{
case|case
name|kMillisecond
case|:
return|return
literal|"ms"
return|;
case|case
name|kMicrosecond
case|:
return|return
literal|"us"
return|;
case|case
name|kNanosecond
case|:
default|default:
return|return
literal|"ns"
return|;
block|}
block|}
specifier|inline
name|double
name|GetTimeUnitMultiplier
parameter_list|(
name|TimeUnit
name|unit
parameter_list|)
block|{
switch|switch
condition|(
name|unit
condition|)
block|{
case|case
name|kMillisecond
case|:
return|return
literal|1e3
return|;
case|case
name|kMicrosecond
case|:
return|return
literal|1e6
return|;
case|case
name|kNanosecond
case|:
default|default:
return|return
literal|1e9
return|;
block|}
block|}
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
comment|// BENCHMARK_REPORTER_H_
end_comment

end_unit

