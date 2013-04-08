begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -Wsource-uses-openmp -o - %s
end_comment

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|omp
name|threadprivate
name|(
name|a
name|,
name|b
name|)
end_pragma

begin_comment
comment|// expected-warning {{unexpected '#pragma omp ...' in program}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|parallel
end_pragma

end_unit

