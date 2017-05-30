begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macos10.7.0 -verify -fopenmp -ferror-limit 100 -o - %s
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{ }
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|a
decl_stmt|;
pragma|#
directive|pragma
name|omp
name|target
name|data
comment|// expected-error {{expected at least one 'map' or 'use_device_ptr' clause for '#pragma omp target data'}}
block|{}
name|L1
label|:
name|foo
argument_list|()
expr_stmt|;
pragma|#
directive|pragma
name|omp
name|target
name|data
name|map
name|(
name|a
name|)
block|{
name|foo
argument_list|()
expr_stmt|;
goto|goto
name|L1
goto|;
comment|// expected-error {{use of undeclared label 'L1'}}
block|}
goto|goto
name|L2
goto|;
comment|// expected-error {{use of undeclared label 'L2'}}
pragma|#
directive|pragma
name|omp
name|target
name|data
name|map
name|(
name|a
name|)
name|L2
label|:
name|foo
argument_list|()
expr_stmt|;
pragma|#
directive|pragma
name|omp
name|target
name|data
name|map
name|(
name|a
name|)
name|(
name|i
name|)
comment|// expected-warning {{extra tokens at the end of '#pragma omp target data' are ignored}}
block|{
name|foo
argument_list|()
expr_stmt|;
block|}
pragma|#
directive|pragma
name|omp
name|target
name|unknown
comment|// expected-warning {{extra tokens at the end of '#pragma omp target' are ignored}}
block|{
name|foo
argument_list|()
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

