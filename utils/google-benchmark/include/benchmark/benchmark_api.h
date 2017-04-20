begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Support for registering benchmarks for functions.
end_comment

begin_comment
comment|/* Example usage: // Define a function that executes the code to be measured a // specified number of times: static void BM_StringCreation(benchmark::State& state) {   while (state.KeepRunning())     std::string empty_string; }  // Register the function as a benchmark BENCHMARK(BM_StringCreation);  // Define another benchmark static void BM_StringCopy(benchmark::State& state) {   std::string x = "hello";   while (state.KeepRunning())     std::string copy(x); } BENCHMARK(BM_StringCopy);  // Augment the main() program to invoke benchmarks if specified // via the --benchmarks command line flag.  E.g., //       my_unittest --benchmark_filter=all //       my_unittest --benchmark_filter=BM_StringCreation //       my_unittest --benchmark_filter=String //       my_unittest --benchmark_filter='Copy|Creation' int main(int argc, char** argv) {   benchmark::Initialize(&argc, argv);   benchmark::RunSpecifiedBenchmarks();   return 0; }  // Sometimes a family of microbenchmarks can be implemented with // just one routine that takes an extra argument to specify which // one of the family of benchmarks to run.  For example, the following // code defines a family of microbenchmarks for measuring the speed // of memcpy() calls of different lengths:  static void BM_memcpy(benchmark::State& state) {   char* src = new char[state.range(0)]; char* dst = new char[state.range(0)];   memset(src, 'x', state.range(0));   while (state.KeepRunning())     memcpy(dst, src, state.range(0));   state.SetBytesProcessed(int64_t(state.iterations()) *                           int64_t(state.range(0)));   delete[] src; delete[] dst; } BENCHMARK(BM_memcpy)->Arg(8)->Arg(64)->Arg(512)->Arg(1<<10)->Arg(8<<10);  // The preceding code is quite repetitive, and can be replaced with the // following short-hand.  The following invocation will pick a few // appropriate arguments in the specified range and will generate a // microbenchmark for each such argument. BENCHMARK(BM_memcpy)->Range(8, 8<<10);  // You might have a microbenchmark that depends on two inputs.  For // example, the following code defines a family of microbenchmarks for // measuring the speed of set insertion. static void BM_SetInsert(benchmark::State& state) {   while (state.KeepRunning()) {     state.PauseTiming();     set<int> data = ConstructRandomSet(state.range(0));     state.ResumeTiming();     for (int j = 0; j< state.range(1); ++j)       data.insert(RandomNumber());   } } BENCHMARK(BM_SetInsert)    ->Args({1<<10, 1})    ->Args({1<<10, 8})    ->Args({1<<10, 64})    ->Args({1<<10, 512})    ->Args({8<<10, 1})    ->Args({8<<10, 8})    ->Args({8<<10, 64})    ->Args({8<<10, 512});  // The preceding code is quite repetitive, and can be replaced with // the following short-hand.  The following macro will pick a few // appropriate arguments in the product of the two specified ranges // and will generate a microbenchmark for each such pair. BENCHMARK(BM_SetInsert)->Ranges({{1<<10, 8<<10}, {1, 512}});  // For more complex patterns of inputs, passing a custom function // to Apply allows programmatic specification of an // arbitrary set of arguments to run the microbenchmark on. // The following example enumerates a dense range on // one parameter, and a sparse range on the second. static void CustomArguments(benchmark::internal::Benchmark* b) {   for (int i = 0; i<= 10; ++i)     for (int j = 32; j<= 1024*1024; j *= 8)       b->Args({i, j}); } BENCHMARK(BM_SetInsert)->Apply(CustomArguments);  // Templated microbenchmarks work the same way: // Produce then consume 'size' messages 'iters' times // Measures throughput in the absence of multiprogramming. template<class Q> int BM_Sequential(benchmark::State& state) {   Q q;   typename Q::value_type v;   while (state.KeepRunning()) {     for (int i = state.range(0); i--; )       q.push(v);     for (int e = state.range(0); e--; )       q.Wait(&v);   }   // actually messages, not bytes:   state.SetBytesProcessed(       static_cast<int64_t>(state.iterations())*state.range(0)); } BENCHMARK_TEMPLATE(BM_Sequential, WaitQueue<int>)->Range(1<<0, 1<<10);  Use `Benchmark::MinTime(double t)` to set the minimum time used to run the benchmark. This option overrides the `benchmark_min_time` flag.  void BM_test(benchmark::State& state) {  ... body ... } BENCHMARK(BM_test)->MinTime(2.0); // Run for at least 2 seconds.  In a multithreaded test, it is guaranteed that none of the threads will start until all have called KeepRunning, and all will have finished before KeepRunning returns false. As such, any global setup or teardown you want to do can be wrapped in a check against the thread index:  static void BM_MultiThreaded(benchmark::State& state) {   if (state.thread_index == 0) {     // Setup code here.   }   while (state.KeepRunning()) {     // Run the test as normal.   }   if (state.thread_index == 0) {     // Teardown code here.   } } BENCHMARK(BM_MultiThreaded)->Threads(4);   If a benchmark runs a few milliseconds it may be hard to visually compare the measured times, since the output data is given in nanoseconds per default. In order to manually set the time unit, you can specify it manually:  BENCHMARK(BM_test)->Unit(benchmark::kMillisecond); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BENCHMARK_BENCHMARK_API_H_
end_ifndef

begin_define
define|#
directive|define
name|BENCHMARK_BENCHMARK_API_H_
end_define

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
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

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|"macros.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BENCHMARK_HAS_CXX11
argument_list|)
end_if

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_include
include|#
directive|include
file|<initializer_list>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_include
include|#
directive|include
file|<intrin.h>
end_include

begin_comment
comment|// for _ReadWriteBarrier
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|benchmark
block|{
name|class
name|BenchmarkReporter
decl_stmt|;
name|void
name|Initialize
parameter_list|(
name|int
modifier|*
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
comment|// Report to stdout all arguments in 'argv' as unrecognized except the first.
comment|// Returns true there is at least on unrecognized argument (i.e. 'argc'> 1).
name|bool
name|ReportUnrecognizedArguments
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
comment|// Generate a list of benchmarks matching the specified --benchmark_filter flag
comment|// and if --benchmark_list_tests is specified return after printing the name
comment|// of each matching benchmark. Otherwise run each matching benchmark and
comment|// report the results.
comment|//
comment|// The second and third overload use the specified 'console_reporter' and
comment|//  'file_reporter' respectively. 'file_reporter' will write to the file
comment|//  specified
comment|//   by '--benchmark_output'. If '--benchmark_output' is not given the
comment|//  'file_reporter' is ignored.
comment|//
comment|// RETURNS: The number of matching benchmarks.
name|size_t
name|RunSpecifiedBenchmarks
parameter_list|()
function_decl|;
name|size_t
name|RunSpecifiedBenchmarks
parameter_list|(
name|BenchmarkReporter
modifier|*
name|console_reporter
parameter_list|)
function_decl|;
name|size_t
name|RunSpecifiedBenchmarks
parameter_list|(
name|BenchmarkReporter
modifier|*
name|console_reporter
parameter_list|,
name|BenchmarkReporter
modifier|*
name|file_reporter
parameter_list|)
function_decl|;
comment|// If this routine is called, peak memory allocation past this point in the
comment|// benchmark is reported at the end of the benchmark report line. (It is
comment|// computed by running the benchmark once with a single iteration and a memory
comment|// tracer.)
comment|// TODO(dominic)
comment|// void MemoryUsage();
name|namespace
name|internal
block|{
name|class
name|Benchmark
decl_stmt|;
name|class
name|BenchmarkImp
decl_stmt|;
name|class
name|BenchmarkFamilies
decl_stmt|;
name|void
name|UseCharPointer
parameter_list|(
name|char
specifier|const
specifier|volatile
modifier|*
parameter_list|)
function_decl|;
comment|// Take ownership of the pointer and register the benchmark. Return the
comment|// registered benchmark.
name|Benchmark
modifier|*
name|RegisterBenchmarkInternal
parameter_list|(
name|Benchmark
modifier|*
parameter_list|)
function_decl|;
comment|// Ensure that the standard streams are properly initialized in every TU.
name|int
name|InitializeStreams
parameter_list|()
function_decl|;
name|BENCHMARK_UNUSED
specifier|static
name|int
name|stream_init_anchor
init|=
name|InitializeStreams
argument_list|()
decl_stmt|;
block|}
comment|// end namespace internal
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__pnacl__
argument_list|)
operator|||
name|defined
argument_list|(
name|EMSCRIPTN
argument_list|)
define|#
directive|define
name|BENCHMARK_HAS_NO_INLINE_ASSEMBLY
endif|#
directive|endif
comment|// The DoNotOptimize(...) function can be used to prevent a value or
comment|// expression from being optimized away by the compiler. This function is
comment|// intended to add little to no overhead.
comment|// See: https://youtu.be/nXaxk27zwlk?t=2441
ifndef|#
directive|ifndef
name|BENCHMARK_HAS_NO_INLINE_ASSEMBLY
name|template
operator|<
name|class
name|Tp
operator|>
specifier|inline
name|BENCHMARK_ALWAYS_INLINE
name|void
name|DoNotOptimize
argument_list|(
argument|Tp const& value
argument_list|)
block|{
name|asm
specifier|volatile
operator|(
literal|""
operator|:
operator|:
literal|"g"
operator|(
name|value
operator|)
operator|:
literal|"memory"
operator|)
block|; }
comment|// Force the compiler to flush pending writes to global memory. Acts as an
comment|// effective read/write barrier
specifier|inline
name|BENCHMARK_ALWAYS_INLINE
name|void
name|ClobberMemory
argument_list|()
block|{
name|asm
specifier|volatile
operator|(
literal|""
operator|:
operator|:
operator|:
literal|"memory"
operator|)
block|; }
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
name|template
operator|<
name|class
name|Tp
operator|>
specifier|inline
name|BENCHMARK_ALWAYS_INLINE
name|void
name|DoNotOptimize
argument_list|(
argument|Tp const& value
argument_list|)
block|{
name|internal
operator|::
name|UseCharPointer
argument_list|(
operator|&
name|reinterpret_cast
operator|<
name|char
specifier|const
specifier|volatile
operator|&
operator|>
operator|(
name|value
operator|)
argument_list|)
block|;
name|_ReadWriteBarrier
argument_list|()
block|; }
specifier|inline
name|BENCHMARK_ALWAYS_INLINE
name|void
name|ClobberMemory
argument_list|()
block|{
name|_ReadWriteBarrier
argument_list|()
block|; }
else|#
directive|else
name|template
operator|<
name|class
name|Tp
operator|>
specifier|inline
name|BENCHMARK_ALWAYS_INLINE
name|void
name|DoNotOptimize
argument_list|(
argument|Tp const& value
argument_list|)
block|{
name|internal
operator|::
name|UseCharPointer
argument_list|(
operator|&
name|reinterpret_cast
operator|<
name|char
specifier|const
specifier|volatile
operator|&
operator|>
operator|(
name|value
operator|)
argument_list|)
block|; }
comment|// FIXME Add ClobberMemory() for non-gnu and non-msvc compilers
endif|#
directive|endif
comment|// This class is used for user-defined counters.
name|class
name|Counter
block|{
name|public
operator|:
expr|enum
name|Flags
block|{
name|kDefaults
operator|=
literal|0
block|,
comment|// Mark the counter as a rate. It will be presented divided
comment|// by the duration of the benchmark.
name|kIsRate
operator|=
literal|1
block|,
comment|// Mark the counter as a thread-average quantity. It will be
comment|// presented divided by the number of threads.
name|kAvgThreads
operator|=
literal|2
block|,
comment|// Mark the counter as a thread-average rate. See above.
name|kAvgThreadsRate
operator|=
name|kIsRate
operator||
name|kAvgThreads
block|}
block|;
name|double
name|value
block|;
name|Flags
name|flags
block|;
name|BENCHMARK_ALWAYS_INLINE
name|Counter
argument_list|(
argument|double v =
literal|0.
argument_list|,
argument|Flags f = kDefaults
argument_list|)
operator|:
name|value
argument_list|(
name|v
argument_list|)
block|,
name|flags
argument_list|(
argument|f
argument_list|)
block|{}
name|BENCHMARK_ALWAYS_INLINE
name|operator
name|double
specifier|const
operator|&
operator|(
operator|)
specifier|const
block|{
return|return
name|value
return|;
block|}
name|BENCHMARK_ALWAYS_INLINE
name|operator
name|double
operator|&
operator|(
operator|)
block|{
return|return
name|value
return|;
block|}
expr|}
block|;
comment|// This is the container for the user-defined counters.
typedef|typedef
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|Counter
operator|>
name|UserCounters
expr_stmt|;
comment|// TimeUnit is passed to a benchmark in order to specify the order of magnitude
comment|// for the measured time.
block|enum
name|TimeUnit
block|{
name|kNanosecond
block|,
name|kMicrosecond
block|,
name|kMillisecond
block|}
expr_stmt|;
comment|// BigO is passed to a benchmark in order to specify the asymptotic
comment|// computational
comment|// complexity for the benchmark. In case oAuto is selected, complexity will be
comment|// calculated automatically to the best fit.
enum|enum
name|BigO
block|{
name|oNone
block|,
name|o1
block|,
name|oN
block|,
name|oNSquared
block|,
name|oNCubed
block|,
name|oLogN
block|,
name|oNLogN
block|,
name|oAuto
block|,
name|oLambda
block|}
enum|;
comment|// BigOFunc is passed to a benchmark in order to specify the asymptotic
comment|// computational complexity for the benchmark.
typedef|typedef
name|double
function_decl|(
name|BigOFunc
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|namespace
name|internal
block|{
name|class
name|ThreadTimer
decl_stmt|;
name|class
name|ThreadManager
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|BENCHMARK_HAS_CXX11
argument_list|)
enum|enum
name|ReportMode
enum|:
name|unsigned
block|{
else|#
directive|else
enum|enum
name|ReportMode
block|{
endif|#
directive|endif
name|RM_Unspecified
block|,
comment|// The mode has not been manually specified
name|RM_Default
block|,
comment|// The mode is user-specified as default.
name|RM_ReportAggregatesOnly
block|}
enum|;
block|}
comment|// State is passed to a running Benchmark and contains state for the
comment|// benchmark to use.
name|class
name|State
block|{
name|public
label|:
comment|// Returns true if the benchmark should continue through another iteration.
comment|// NOTE: A benchmark may not return from the test until KeepRunning() has
comment|// returned false.
name|bool
name|KeepRunning
parameter_list|()
block|{
if|if
condition|(
name|BENCHMARK_BUILTIN_EXPECT
argument_list|(
operator|!
name|started_
argument_list|,
name|false
argument_list|)
condition|)
block|{
name|StartKeepRunning
argument_list|()
expr_stmt|;
block|}
name|bool
specifier|const
name|res
init|=
name|total_iterations_
operator|++
operator|<
name|max_iterations
decl_stmt|;
if|if
condition|(
name|BENCHMARK_BUILTIN_EXPECT
argument_list|(
operator|!
name|res
argument_list|,
name|false
argument_list|)
condition|)
block|{
name|FinishKeepRunning
argument_list|()
expr_stmt|;
block|}
return|return
name|res
return|;
block|}
comment|// REQUIRES: timer is running and 'SkipWithError(...)' has not been called
comment|//           by the current thread.
comment|// Stop the benchmark timer.  If not called, the timer will be
comment|// automatically stopped after KeepRunning() returns false for the first time.
comment|//
comment|// For threaded benchmarks the PauseTiming() function only pauses the timing
comment|// for the current thread.
comment|//
comment|// NOTE: The "real time" measurement is per-thread. If different threads
comment|// report different measurements the largest one is reported.
comment|//
comment|// NOTE: PauseTiming()/ResumeTiming() are relatively
comment|// heavyweight, and so their use should generally be avoided
comment|// within each benchmark iteration, if possible.
name|void
name|PauseTiming
parameter_list|()
function_decl|;
comment|// REQUIRES: timer is not running and 'SkipWithError(...)' has not been called
comment|//           by the current thread.
comment|// Start the benchmark timer.  The timer is NOT running on entrance to the
comment|// benchmark function. It begins running after the first call to KeepRunning()
comment|//
comment|// NOTE: PauseTiming()/ResumeTiming() are relatively
comment|// heavyweight, and so their use should generally be avoided
comment|// within each benchmark iteration, if possible.
name|void
name|ResumeTiming
parameter_list|()
function_decl|;
comment|// REQUIRES: 'SkipWithError(...)' has not been called previously by the
comment|//            current thread.
comment|// Skip any future iterations of the 'KeepRunning()' loop in the current
comment|// thread and report an error with the specified 'msg'. After this call
comment|// the user may explicitly 'return' from the benchmark.
comment|//
comment|// For threaded benchmarks only the current thread stops executing and future
comment|// calls to `KeepRunning()` will block until all threads have completed
comment|// the `KeepRunning()` loop. If multiple threads report an error only the
comment|// first error message is used.
comment|//
comment|// NOTE: Calling 'SkipWithError(...)' does not cause the benchmark to exit
comment|// the current scope immediately. If the function is called from within
comment|// the 'KeepRunning()' loop the current iteration will finish. It is the users
comment|// responsibility to exit the scope as needed.
name|void
name|SkipWithError
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
comment|// REQUIRES: called exactly once per iteration of the KeepRunning loop.
comment|// Set the manually measured time for this benchmark iteration, which
comment|// is used instead of automatically measured time if UseManualTime() was
comment|// specified.
comment|//
comment|// For threaded benchmarks the final value will be set to the largest
comment|// reported values.
name|void
name|SetIterationTime
parameter_list|(
name|double
name|seconds
parameter_list|)
function_decl|;
comment|// Set the number of bytes processed by the current benchmark
comment|// execution.  This routine is typically called once at the end of a
comment|// throughput oriented benchmark.  If this routine is called with a
comment|// value> 0, the report is printed in MB/sec instead of nanoseconds
comment|// per iteration.
comment|//
comment|// REQUIRES: a benchmark has exited its KeepRunning loop.
name|BENCHMARK_ALWAYS_INLINE
name|void
name|SetBytesProcessed
parameter_list|(
name|size_t
name|bytes
parameter_list|)
block|{
name|bytes_processed_
operator|=
name|bytes
expr_stmt|;
block|}
name|BENCHMARK_ALWAYS_INLINE
name|size_t
name|bytes_processed
argument_list|()
specifier|const
block|{
return|return
name|bytes_processed_
return|;
block|}
comment|// If this routine is called with complexity_n> 0 and complexity report is
comment|// requested for the
comment|// family benchmark, then current benchmark will be part of the computation
comment|// and complexity_n will
comment|// represent the length of N.
name|BENCHMARK_ALWAYS_INLINE
name|void
name|SetComplexityN
parameter_list|(
name|int
name|complexity_n
parameter_list|)
block|{
name|complexity_n_
operator|=
name|complexity_n
expr_stmt|;
block|}
name|BENCHMARK_ALWAYS_INLINE
name|int
name|complexity_length_n
parameter_list|()
block|{
return|return
name|complexity_n_
return|;
block|}
comment|// If this routine is called with items> 0, then an items/s
comment|// label is printed on the benchmark report line for the currently
comment|// executing benchmark. It is typically called at the end of a processing
comment|// benchmark where a processing items/second output is desired.
comment|//
comment|// REQUIRES: a benchmark has exited its KeepRunning loop.
name|BENCHMARK_ALWAYS_INLINE
name|void
name|SetItemsProcessed
parameter_list|(
name|size_t
name|items
parameter_list|)
block|{
name|items_processed_
operator|=
name|items
expr_stmt|;
block|}
name|BENCHMARK_ALWAYS_INLINE
name|size_t
name|items_processed
argument_list|()
specifier|const
block|{
return|return
name|items_processed_
return|;
block|}
comment|// If this routine is called, the specified label is printed at the
comment|// end of the benchmark report line for the currently executing
comment|// benchmark.  Example:
comment|//  static void BM_Compress(benchmark::State& state) {
comment|//    ...
comment|//    double compress = input_size / output_size;
comment|//    state.SetLabel(StringPrintf("compress:%.1f%%", 100.0*compression));
comment|//  }
comment|// Produces output that looks like:
comment|//  BM_Compress   50         50   14115038  compress:27.3%
comment|//
comment|// REQUIRES: a benchmark has exited its KeepRunning loop.
name|void
name|SetLabel
parameter_list|(
specifier|const
name|char
modifier|*
name|label
parameter_list|)
function_decl|;
name|void
name|BENCHMARK_ALWAYS_INLINE
name|SetLabel
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|str
argument_list|)
block|{
name|this
operator|->
name|SetLabel
argument_list|(
name|str
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Range arguments for this run. CHECKs if the argument has been set.
name|BENCHMARK_ALWAYS_INLINE
name|int
name|range
argument_list|(
name|std
operator|::
name|size_t
name|pos
operator|=
literal|0
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|range_
operator|.
name|size
argument_list|()
operator|>
name|pos
argument_list|)
expr_stmt|;
return|return
name|range_
index|[
name|pos
index|]
return|;
block|}
name|BENCHMARK_DEPRECATED_MSG
argument_list|(
literal|"use 'range(0)' instead"
argument_list|)
name|int
name|range_x
argument_list|()
specifier|const
block|{
return|return
name|range
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|BENCHMARK_DEPRECATED_MSG
argument_list|(
literal|"use 'range(1)' instead"
argument_list|)
name|int
name|range_y
argument_list|()
specifier|const
block|{
return|return
name|range
argument_list|(
literal|1
argument_list|)
return|;
block|}
name|BENCHMARK_ALWAYS_INLINE
name|size_t
name|iterations
argument_list|()
specifier|const
block|{
return|return
name|total_iterations_
return|;
block|}
name|private
label|:
name|bool
name|started_
decl_stmt|;
name|bool
name|finished_
decl_stmt|;
name|size_t
name|total_iterations_
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|int
operator|>
name|range_
expr_stmt|;
name|size_t
name|bytes_processed_
decl_stmt|;
name|size_t
name|items_processed_
decl_stmt|;
name|int
name|complexity_n_
decl_stmt|;
name|bool
name|error_occurred_
decl_stmt|;
name|public
label|:
comment|// Container for user-defined counters.
name|UserCounters
name|counters
decl_stmt|;
comment|// Index of the executing thread. Values from [0, threads).
specifier|const
name|int
name|thread_index
decl_stmt|;
comment|// Number of threads concurrently executing the benchmark.
specifier|const
name|int
name|threads
decl_stmt|;
specifier|const
name|size_t
name|max_iterations
decl_stmt|;
comment|// TODO make me private
name|State
argument_list|(
argument|size_t max_iters
argument_list|,
argument|const std::vector<int>& ranges
argument_list|,
argument|int thread_i
argument_list|,
argument|int n_threads
argument_list|,
argument|internal::ThreadTimer* timer
argument_list|,
argument|internal::ThreadManager* manager
argument_list|)
empty_stmt|;
name|private
label|:
name|void
name|StartKeepRunning
parameter_list|()
function_decl|;
name|void
name|FinishKeepRunning
parameter_list|()
function_decl|;
name|internal
operator|::
name|ThreadTimer
operator|*
name|timer_
expr_stmt|;
name|internal
operator|::
name|ThreadManager
operator|*
name|manager_
expr_stmt|;
name|BENCHMARK_DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|State
argument_list|)
expr_stmt|;
block|}
enum|;
name|namespace
name|internal
block|{
typedef|typedef
name|void
function_decl|(
name|Function
function_decl|)
parameter_list|(
name|State
modifier|&
parameter_list|)
function_decl|;
comment|// ------------------------------------------------------
comment|// Benchmark registration object.  The BENCHMARK() macro expands
comment|// into an internal::Benchmark* object.  Various methods can
comment|// be called on this object to change the properties of the benchmark.
comment|// Each method returns "this" so that multiple method calls can
comment|// chained into one expression.
name|class
name|Benchmark
block|{
name|public
label|:
name|virtual
operator|~
name|Benchmark
argument_list|()
expr_stmt|;
comment|// Note: the following methods all return "this" so that multiple
comment|// method calls can be chained together in one expression.
comment|// Run this benchmark once with "x" as the extra argument passed
comment|// to the function.
comment|// REQUIRES: The function passed to the constructor must accept an arg1.
name|Benchmark
modifier|*
name|Arg
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
comment|// Run this benchmark with the given time unit for the generated output report
name|Benchmark
modifier|*
name|Unit
parameter_list|(
name|TimeUnit
name|unit
parameter_list|)
function_decl|;
comment|// Run this benchmark once for a number of values picked from the
comment|// range [start..limit].  (start and limit are always picked.)
comment|// REQUIRES: The function passed to the constructor must accept an arg1.
name|Benchmark
modifier|*
name|Range
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|limit
parameter_list|)
function_decl|;
comment|// Run this benchmark once for all values in the range [start..limit] with
comment|// specific step
comment|// REQUIRES: The function passed to the constructor must accept an arg1.
name|Benchmark
modifier|*
name|DenseRange
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|limit
parameter_list|,
name|int
name|step
init|=
literal|1
parameter_list|)
function_decl|;
comment|// Run this benchmark once with "args" as the extra arguments passed
comment|// to the function.
comment|// REQUIRES: The function passed to the constructor must accept arg1, arg2 ...
name|Benchmark
modifier|*
name|Args
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|int
operator|>
operator|&
name|args
argument_list|)
decl_stmt|;
comment|// Equivalent to Args({x, y})
comment|// NOTE: This is a legacy C++03 interface provided for compatibility only.
comment|//   New code should use 'Args'.
name|Benchmark
modifier|*
name|ArgPair
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|std
operator|::
name|vector
operator|<
name|int
operator|>
name|args
expr_stmt|;
name|args
operator|.
name|push_back
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|args
operator|.
name|push_back
argument_list|(
name|y
argument_list|)
expr_stmt|;
return|return
name|Args
argument_list|(
name|args
argument_list|)
return|;
block|}
comment|// Run this benchmark once for a number of values picked from the
comment|// ranges [start..limit].  (starts and limits are always picked.)
comment|// REQUIRES: The function passed to the constructor must accept arg1, arg2 ...
name|Benchmark
modifier|*
name|Ranges
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|int
argument_list|,
name|int
operator|>
expr|>
operator|&
name|ranges
argument_list|)
decl_stmt|;
comment|// Equivalent to ArgNames({name})
name|Benchmark
modifier|*
name|ArgName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
decl_stmt|;
comment|// Set the argument names to display in the benchmark name. If not called,
comment|// only argument values will be shown.
name|Benchmark
modifier|*
name|ArgNames
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|names
argument_list|)
decl_stmt|;
comment|// Equivalent to Ranges({{lo1, hi1}, {lo2, hi2}}).
comment|// NOTE: This is a legacy C++03 interface provided for compatibility only.
comment|//   New code should use 'Ranges'.
name|Benchmark
modifier|*
name|RangePair
parameter_list|(
name|int
name|lo1
parameter_list|,
name|int
name|hi1
parameter_list|,
name|int
name|lo2
parameter_list|,
name|int
name|hi2
parameter_list|)
block|{
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|int
operator|>
expr|>
name|ranges
expr_stmt|;
name|ranges
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|lo1
argument_list|,
name|hi1
argument_list|)
argument_list|)
expr_stmt|;
name|ranges
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|lo2
argument_list|,
name|hi2
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Ranges
argument_list|(
name|ranges
argument_list|)
return|;
block|}
comment|// Pass this benchmark object to *func, which can customize
comment|// the benchmark by calling various methods like Arg, Args,
comment|// Threads, etc.
name|Benchmark
modifier|*
name|Apply
parameter_list|(
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|Benchmark
modifier|*
name|benchmark
parameter_list|)
parameter_list|)
function_decl|;
comment|// Set the range multiplier for non-dense range. If not called, the range
comment|// multiplier kRangeMultiplier will be used.
name|Benchmark
modifier|*
name|RangeMultiplier
parameter_list|(
name|int
name|multiplier
parameter_list|)
function_decl|;
comment|// Set the minimum amount of time to use when running this benchmark. This
comment|// option overrides the `benchmark_min_time` flag.
comment|// REQUIRES: `t> 0` and `Iterations` has not been called on this benchmark.
name|Benchmark
modifier|*
name|MinTime
parameter_list|(
name|double
name|t
parameter_list|)
function_decl|;
comment|// Specify the amount of iterations that should be run by this benchmark.
comment|// REQUIRES: 'n> 0' and `MinTime` has not been called on this benchmark.
comment|//
comment|// NOTE: This function should only be used when *exact* iteration control is
comment|//   needed and never to control or limit how long a benchmark runs, where
comment|// `--benchmark_min_time=N` or `MinTime(...)` should be used instead.
name|Benchmark
modifier|*
name|Iterations
parameter_list|(
name|size_t
name|n
parameter_list|)
function_decl|;
comment|// Specify the amount of times to repeat this benchmark. This option overrides
comment|// the `benchmark_repetitions` flag.
comment|// REQUIRES: `n> 0`
name|Benchmark
modifier|*
name|Repetitions
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
comment|// Specify if each repetition of the benchmark should be reported separately
comment|// or if only the final statistics should be reported. If the benchmark
comment|// is not repeated then the single result is always reported.
name|Benchmark
modifier|*
name|ReportAggregatesOnly
parameter_list|(
name|bool
name|v
init|=
name|true
parameter_list|)
function_decl|;
comment|// If a particular benchmark is I/O bound, runs multiple threads internally or
comment|// if for some reason CPU timings are not representative, call this method. If
comment|// called, the elapsed time will be used to control how many iterations are
comment|// run, and in the printing of items/second or MB/seconds values.  If not
comment|// called, the cpu time used by the benchmark will be used.
name|Benchmark
modifier|*
name|UseRealTime
parameter_list|()
function_decl|;
comment|// If a benchmark must measure time manually (e.g. if GPU execution time is
comment|// being
comment|// measured), call this method. If called, each benchmark iteration should
comment|// call
comment|// SetIterationTime(seconds) to report the measured time, which will be used
comment|// to control how many iterations are run, and in the printing of items/second
comment|// or MB/second values.
name|Benchmark
modifier|*
name|UseManualTime
parameter_list|()
function_decl|;
comment|// Set the asymptotic computational complexity for the benchmark. If called
comment|// the asymptotic computational complexity will be shown on the output.
name|Benchmark
modifier|*
name|Complexity
parameter_list|(
name|BigO
name|complexity
init|=
name|benchmark
operator|::
name|oAuto
parameter_list|)
function_decl|;
comment|// Set the asymptotic computational complexity for the benchmark. If called
comment|// the asymptotic computational complexity will be shown on the output.
name|Benchmark
modifier|*
name|Complexity
parameter_list|(
name|BigOFunc
modifier|*
name|complexity
parameter_list|)
function_decl|;
comment|// Support for running multiple copies of the same benchmark concurrently
comment|// in multiple threads.  This may be useful when measuring the scaling
comment|// of some piece of code.
comment|// Run one instance of this benchmark concurrently in t threads.
name|Benchmark
modifier|*
name|Threads
parameter_list|(
name|int
name|t
parameter_list|)
function_decl|;
comment|// Pick a set of values T from [min_threads,max_threads].
comment|// min_threads and max_threads are always included in T.  Run this
comment|// benchmark once for each value in T.  The benchmark run for a
comment|// particular value t consists of t threads running the benchmark
comment|// function concurrently.  For example, consider:
comment|//    BENCHMARK(Foo)->ThreadRange(1,16);
comment|// This will run the following benchmarks:
comment|//    Foo in 1 thread
comment|//    Foo in 2 threads
comment|//    Foo in 4 threads
comment|//    Foo in 8 threads
comment|//    Foo in 16 threads
name|Benchmark
modifier|*
name|ThreadRange
parameter_list|(
name|int
name|min_threads
parameter_list|,
name|int
name|max_threads
parameter_list|)
function_decl|;
comment|// For each value n in the range, run this benchmark once using n threads.
comment|// min_threads and max_threads are always included in the range.
comment|// stride specifies the increment. E.g. DenseThreadRange(1, 8, 3) starts
comment|// a benchmark with 1, 4, 7 and 8 threads.
name|Benchmark
modifier|*
name|DenseThreadRange
parameter_list|(
name|int
name|min_threads
parameter_list|,
name|int
name|max_threads
parameter_list|,
name|int
name|stride
init|=
literal|1
parameter_list|)
function_decl|;
comment|// Equivalent to ThreadRange(NumCPUs(), NumCPUs())
name|Benchmark
modifier|*
name|ThreadPerCpu
parameter_list|()
function_decl|;
name|virtual
name|void
name|Run
parameter_list|(
name|State
modifier|&
name|state
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Used inside the benchmark implementation
struct_decl|struct
name|Instance
struct_decl|;
name|protected
label|:
name|explicit
name|Benchmark
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|Benchmark
argument_list|(
name|Benchmark
specifier|const
operator|&
argument_list|)
expr_stmt|;
name|void
name|SetName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|int
name|ArgsCnt
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|void
name|AddRange
argument_list|(
name|std
operator|::
name|vector
operator|<
name|int
operator|>
operator|*
name|dst
argument_list|,
name|int
name|lo
argument_list|,
name|int
name|hi
argument_list|,
name|int
name|mult
argument_list|)
decl_stmt|;
name|private
label|:
name|friend
name|class
name|BenchmarkFamilies
decl_stmt|;
name|std
operator|::
name|string
name|name_
expr_stmt|;
name|ReportMode
name|report_mode_
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|arg_names_
expr_stmt|;
comment|// Args for all benchmark runs
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|vector
operator|<
name|int
operator|>
expr|>
name|args_
expr_stmt|;
comment|// Args for all benchmark runs
name|TimeUnit
name|time_unit_
decl_stmt|;
name|int
name|range_multiplier_
decl_stmt|;
name|double
name|min_time_
decl_stmt|;
name|size_t
name|iterations_
decl_stmt|;
name|int
name|repetitions_
decl_stmt|;
name|bool
name|use_real_time_
decl_stmt|;
name|bool
name|use_manual_time_
decl_stmt|;
name|BigO
name|complexity_
decl_stmt|;
name|BigOFunc
modifier|*
name|complexity_lambda_
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|int
operator|>
name|thread_counts_
expr_stmt|;
name|Benchmark
modifier|&
name|operator
init|=
operator|(
name|Benchmark
specifier|const
operator|&
operator|)
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace internal
comment|// Create and register a benchmark with the specified 'name' that invokes
comment|// the specified functor 'fn'.
comment|//
comment|// RETURNS: A pointer to the registered benchmark.
name|internal
operator|::
name|Benchmark
operator|*
name|RegisterBenchmark
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|internal
operator|::
name|Function
operator|*
name|fn
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|BENCHMARK_HAS_CXX11
argument_list|)
name|template
operator|<
name|class
name|Lambda
operator|>
name|internal
operator|::
name|Benchmark
operator|*
name|RegisterBenchmark
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|Lambda
operator|&&
name|fn
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|namespace
name|internal
block|{
comment|// The class used to hold all Benchmarks created from static function.
comment|// (ie those created using the BENCHMARK(...) macros.
name|class
name|FunctionBenchmark
range|:
name|public
name|Benchmark
block|{
name|public
operator|:
name|FunctionBenchmark
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|Function
operator|*
name|func
argument_list|)
operator|:
name|Benchmark
argument_list|(
name|name
argument_list|)
block|,
name|func_
argument_list|(
argument|func
argument_list|)
block|{}
name|virtual
name|void
name|Run
argument_list|(
name|State
operator|&
name|st
argument_list|)
block|;
name|private
operator|:
name|Function
operator|*
name|func_
block|; }
decl_stmt|;
ifdef|#
directive|ifdef
name|BENCHMARK_HAS_CXX11
name|template
operator|<
name|class
name|Lambda
operator|>
name|class
name|LambdaBenchmark
operator|:
name|public
name|Benchmark
block|{
name|public
operator|:
name|virtual
name|void
name|Run
argument_list|(
argument|State& st
argument_list|)
block|{
name|lambda_
argument_list|(
name|st
argument_list|)
block|; }
name|private
operator|:
name|template
operator|<
name|class
name|OLambda
operator|>
name|LambdaBenchmark
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|OLambda
operator|&&
name|lam
argument_list|)
operator|:
name|Benchmark
argument_list|(
name|name
argument_list|)
block|,
name|lambda_
argument_list|(
argument|std::forward<OLambda>(lam)
argument_list|)
block|{}
name|LambdaBenchmark
argument_list|(
name|LambdaBenchmark
specifier|const
operator|&
argument_list|)
operator|=
name|delete
block|;
name|private
operator|:
name|template
operator|<
name|class
name|Lam
operator|>
name|friend
name|Benchmark
operator|*
operator|::
name|benchmark
operator|::
name|RegisterBenchmark
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|Lam
operator|&&
argument_list|)
block|;
name|Lambda
name|lambda_
block|; }
expr_stmt|;
endif|#
directive|endif
block|}
comment|// end namespace internal
specifier|inline
name|internal
operator|::
name|Benchmark
operator|*
name|RegisterBenchmark
argument_list|(
argument|const char* name
argument_list|,
argument|internal::Function* fn
argument_list|)
block|{
return|return
name|internal
operator|::
name|RegisterBenchmarkInternal
argument_list|(
argument|::new internal::FunctionBenchmark(name, fn)
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|BENCHMARK_HAS_CXX11
name|template
operator|<
name|class
name|Lambda
operator|>
name|internal
operator|::
name|Benchmark
operator|*
name|RegisterBenchmark
argument_list|(
argument|const char* name
argument_list|,
argument|Lambda&& fn
argument_list|)
block|{
name|using
name|BenchType
operator|=
name|internal
operator|::
name|LambdaBenchmark
operator|<
name|typename
name|std
operator|::
name|decay
operator|<
name|Lambda
operator|>
operator|::
name|type
operator|>
block|;
return|return
name|internal
operator|::
name|RegisterBenchmarkInternal
argument_list|(
argument|::new BenchType(name, std::forward<Lambda>(fn))
argument_list|)
return|;
block|}
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|BENCHMARK_HAS_CXX11
argument_list|)
operator|&&
expr|\
operator|(
operator|!
name|defined
argument_list|(
name|BENCHMARK_GCC_VERSION
argument_list|)
operator|||
name|BENCHMARK_GCC_VERSION
operator|>=
literal|409
operator|)
name|template
operator|<
name|class
name|Lambda
operator|,
name|class
operator|...
name|Args
operator|>
name|internal
operator|::
name|Benchmark
operator|*
name|RegisterBenchmark
argument_list|(
argument|const char* name
argument_list|,
argument|Lambda&& fn
argument_list|,
argument|Args&&... args
argument_list|)
block|{
return|return
name|benchmark
operator|::
name|RegisterBenchmark
argument_list|(
name|name
argument_list|,
index|[
operator|=
index|]
operator|(
name|benchmark
operator|::
name|State
operator|&
name|st
operator|)
block|{
name|fn
argument_list|(
name|st
argument_list|,
name|args
operator|...
argument_list|)
block|; }
argument_list|)
return|;
block|}
else|#
directive|else
define|#
directive|define
name|BENCHMARK_HAS_NO_VARIADIC_REGISTER_BENCHMARK
endif|#
directive|endif
comment|// The base class for all fixture tests.
name|class
name|Fixture
range|:
name|public
name|internal
operator|::
name|Benchmark
block|{
name|public
operator|:
name|Fixture
argument_list|()
operator|:
name|internal
operator|::
name|Benchmark
argument_list|(
literal|""
argument_list|)
block|{}
name|virtual
name|void
name|Run
argument_list|(
argument|State& st
argument_list|)
block|{
name|this
operator|->
name|SetUp
argument_list|(
name|st
argument_list|)
block|;
name|this
operator|->
name|BenchmarkCase
argument_list|(
name|st
argument_list|)
block|;
name|this
operator|->
name|TearDown
argument_list|(
name|st
argument_list|)
block|;   }
comment|// These will be deprecated ...
name|virtual
name|void
name|SetUp
argument_list|(
argument|const State&
argument_list|)
block|{}
name|virtual
name|void
name|TearDown
argument_list|(
argument|const State&
argument_list|)
block|{}
comment|// ... In favor of these.
name|virtual
name|void
name|SetUp
argument_list|(
argument|State& st
argument_list|)
block|{
name|SetUp
argument_list|(
name|const_cast
operator|<
specifier|const
name|State
operator|&
operator|>
operator|(
name|st
operator|)
argument_list|)
block|; }
name|virtual
name|void
name|TearDown
argument_list|(
argument|State& st
argument_list|)
block|{
name|TearDown
argument_list|(
name|const_cast
operator|<
specifier|const
name|State
operator|&
operator|>
operator|(
name|st
operator|)
argument_list|)
block|; }
name|protected
operator|:
name|virtual
name|void
name|BenchmarkCase
argument_list|(
name|State
operator|&
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace benchmark
end_comment

begin_comment
comment|// ------------------------------------------------------
end_comment

begin_comment
comment|// Macro to register benchmarks
end_comment

begin_comment
comment|// Check that __COUNTER__ is defined and that __COUNTER__ increases by 1
end_comment

begin_comment
comment|// every time it is expanded. X + 1 == X + 0 is used in case X is defined to be
end_comment

begin_comment
comment|// empty. If X is empty the expression becomes (+1 == +0).
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__COUNTER__
argument_list|)
operator|&&
operator|(
name|__COUNTER__
operator|+
literal|1
operator|==
name|__COUNTER__
operator|+
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|BENCHMARK_PRIVATE_UNIQUE_ID
value|__COUNTER__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BENCHMARK_PRIVATE_UNIQUE_ID
value|__LINE__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Helpers for generating unique variable names
end_comment

begin_define
define|#
directive|define
name|BENCHMARK_PRIVATE_NAME
parameter_list|(
name|n
parameter_list|)
define|\
value|BENCHMARK_PRIVATE_CONCAT(_benchmark_, BENCHMARK_PRIVATE_UNIQUE_ID, n)
end_define

begin_define
define|#
directive|define
name|BENCHMARK_PRIVATE_CONCAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|BENCHMARK_PRIVATE_CONCAT2(a, b, c)
end_define

begin_define
define|#
directive|define
name|BENCHMARK_PRIVATE_CONCAT2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a##b##c
end_define

begin_define
define|#
directive|define
name|BENCHMARK_PRIVATE_DECLARE
parameter_list|(
name|n
parameter_list|)
define|\
value|static ::benchmark::internal::Benchmark* BENCHMARK_PRIVATE_NAME(n) \       BENCHMARK_UNUSED
end_define

begin_define
define|#
directive|define
name|BENCHMARK
parameter_list|(
name|n
parameter_list|)
define|\
value|BENCHMARK_PRIVATE_DECLARE(n) =                         \       (::benchmark::internal::RegisterBenchmarkInternal( \           new ::benchmark::internal::FunctionBenchmark(#n, n)))
end_define

begin_comment
comment|// Old-style macros
end_comment

begin_define
define|#
directive|define
name|BENCHMARK_WITH_ARG
parameter_list|(
name|n
parameter_list|,
name|a
parameter_list|)
value|BENCHMARK(n)->Arg((a))
end_define

begin_define
define|#
directive|define
name|BENCHMARK_WITH_ARG2
parameter_list|(
name|n
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
value|BENCHMARK(n)->Args({(a1), (a2)})
end_define

begin_define
define|#
directive|define
name|BENCHMARK_WITH_UNIT
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|)
value|BENCHMARK(n)->Unit((t))
end_define

begin_define
define|#
directive|define
name|BENCHMARK_RANGE
parameter_list|(
name|n
parameter_list|,
name|lo
parameter_list|,
name|hi
parameter_list|)
value|BENCHMARK(n)->Range((lo), (hi))
end_define

begin_define
define|#
directive|define
name|BENCHMARK_RANGE2
parameter_list|(
name|n
parameter_list|,
name|l1
parameter_list|,
name|h1
parameter_list|,
name|l2
parameter_list|,
name|h2
parameter_list|)
define|\
value|BENCHMARK(n)->RangePair({{(l1), (h1)}, {(l2), (h2)}})
end_define

begin_if
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
end_if

begin_comment
comment|// Register a benchmark which invokes the function specified by `func`
end_comment

begin_comment
comment|// with the additional arguments specified by `...`.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// template<class ...ExtraArgs>`
end_comment

begin_comment
comment|// void BM_takes_args(benchmark::State& state, ExtraArgs&&... extra_args) {
end_comment

begin_comment
comment|//  [...]
end_comment

begin_comment
comment|//}
end_comment

begin_comment
comment|// /* Registers a benchmark named "BM_takes_args/int_string_test` */
end_comment

begin_comment
comment|// BENCHMARK_CAPTURE(BM_takes_args, int_string_test, 42, std::string("abc"));
end_comment

begin_define
define|#
directive|define
name|BENCHMARK_CAPTURE
parameter_list|(
name|func
parameter_list|,
name|test_case_name
parameter_list|,
modifier|...
parameter_list|)
define|\
value|BENCHMARK_PRIVATE_DECLARE(func) =                      \       (::benchmark::internal::RegisterBenchmarkInternal( \           new ::benchmark::internal::FunctionBenchmark(  \               #func "/" #test_case_name,                 \               [](::benchmark::State& st) { func(st, __VA_ARGS__); })))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __cplusplus>= 11
end_comment

begin_comment
comment|// This will register a benchmark for a templatized function.  For example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// template<int arg>
end_comment

begin_comment
comment|// void BM_Foo(int iters);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// BENCHMARK_TEMPLATE(BM_Foo, 1);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// will register BM_Foo<1> as a benchmark.
end_comment

begin_define
define|#
directive|define
name|BENCHMARK_TEMPLATE1
parameter_list|(
name|n
parameter_list|,
name|a
parameter_list|)
define|\
value|BENCHMARK_PRIVATE_DECLARE(n) =                         \       (::benchmark::internal::RegisterBenchmarkInternal( \           new ::benchmark::internal::FunctionBenchmark(#n "<" #a ">", n<a>)))
end_define

begin_define
define|#
directive|define
name|BENCHMARK_TEMPLATE2
parameter_list|(
name|n
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|BENCHMARK_PRIVATE_DECLARE(n) =                                             \       (::benchmark::internal::RegisterBenchmarkInternal(                     \           new ::benchmark::internal::FunctionBenchmark(#n "<" #a "," #b ">", \                                                        n<a, b>)))
end_define

begin_if
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
end_if

begin_define
define|#
directive|define
name|BENCHMARK_TEMPLATE
parameter_list|(
name|n
parameter_list|,
modifier|...
parameter_list|)
define|\
value|BENCHMARK_PRIVATE_DECLARE(n) =                         \       (::benchmark::internal::RegisterBenchmarkInternal( \           new ::benchmark::internal::FunctionBenchmark(  \               #n "<" #__VA_ARGS__ ">", n<__VA_ARGS__>)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BENCHMARK_TEMPLATE
parameter_list|(
name|n
parameter_list|,
name|a
parameter_list|)
value|BENCHMARK_TEMPLATE1(n, a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BENCHMARK_PRIVATE_DECLARE_F
parameter_list|(
name|BaseClass
parameter_list|,
name|Method
parameter_list|)
define|\
value|class BaseClass##_##Method##_Benchmark : public BaseClass { \    public:                                                    \     BaseClass##_##Method##_Benchmark() : BaseClass() {        \       this->SetName(#BaseClass "/" #Method);                  \     }                                                         \                                                               \    protected:                                                 \     virtual void BenchmarkCase(::benchmark::State&);          \   };
end_define

begin_define
define|#
directive|define
name|BENCHMARK_DEFINE_F
parameter_list|(
name|BaseClass
parameter_list|,
name|Method
parameter_list|)
define|\
value|BENCHMARK_PRIVATE_DECLARE_F(BaseClass, Method) \   void BaseClass##_##Method##_Benchmark::BenchmarkCase
end_define

begin_define
define|#
directive|define
name|BENCHMARK_REGISTER_F
parameter_list|(
name|BaseClass
parameter_list|,
name|Method
parameter_list|)
define|\
value|BENCHMARK_PRIVATE_REGISTER_F(BaseClass##_##Method##_Benchmark)
end_define

begin_define
define|#
directive|define
name|BENCHMARK_PRIVATE_REGISTER_F
parameter_list|(
name|TestName
parameter_list|)
define|\
value|BENCHMARK_PRIVATE_DECLARE(TestName) =        \       (::benchmark::internal::RegisterBenchmarkInternal(new TestName()))
end_define

begin_comment
comment|// This macro will define and register a benchmark within a fixture class.
end_comment

begin_define
define|#
directive|define
name|BENCHMARK_F
parameter_list|(
name|BaseClass
parameter_list|,
name|Method
parameter_list|)
define|\
value|BENCHMARK_PRIVATE_DECLARE_F(BaseClass, Method) \   BENCHMARK_REGISTER_F(BaseClass, Method);       \   void BaseClass##_##Method##_Benchmark::BenchmarkCase
end_define

begin_comment
comment|// Helper macro to create a main routine in a test that runs the benchmarks
end_comment

begin_define
define|#
directive|define
name|BENCHMARK_MAIN
parameter_list|()
define|\
value|int main(int argc, char** argv) {        \     ::benchmark::Initialize(&argc, argv);  \     if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1; \     ::benchmark::RunSpecifiedBenchmarks(); \   }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// BENCHMARK_BENCHMARK_API_H_
end_comment

end_unit

