begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fopenmp=libiomp5 -ferror-limit 100 -o - %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
end_pragma

begin_comment
comment|// expected-error {{expected an OpenMP directive}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|unknown_directive
end_pragma

begin_comment
comment|// expected-error {{expected an OpenMP directive}}
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
pragma|#
directive|pragma
name|omp
comment|// expected-error {{expected an OpenMP directive}}
pragma|#
directive|pragma
name|omp
name|unknown_directive
comment|// expected-error {{expected an OpenMP directive}}
block|}
end_function

end_unit

