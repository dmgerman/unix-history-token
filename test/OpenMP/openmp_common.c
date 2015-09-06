begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fopenmp -ferror-limit 100 -o - %s
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

begin_typedef
typedef|typedef
struct|struct
name|S
block|{
pragma|#
directive|pragma
name|omp
name|parallel
name|for
name|private
name|(
name|j
name|)
name|schedule
name|(
name|static
name|)
name|if
name|(
name|tree1
name|->
name|totleaf
name|>
name|1024
name|)
comment|// expected-error {{unexpected OpenMP directive '#pragma omp parallel for'}}
block|}
name|St
typedef|;
end_typedef

end_unit

