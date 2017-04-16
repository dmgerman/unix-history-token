begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin10 -analyze -analyzer-checker=core.builtin -fopenmp -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_function
name|void
name|openmp_parallel_crash_test
parameter_list|()
block|{
pragma|#
directive|pragma
name|omp
name|parallel
empty_stmt|;
block|}
end_function

end_unit

