begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -triple i686-pc-linux-gnu -analyzer-checker=security.insecureAPI,security.FloatLoopCounter %s -verify
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// This file complements 'security-syntax-checks.m', but tests that we omit
end_comment

begin_comment
comment|// specific checks on platforms where they don't make sense.
end_comment

begin_comment
comment|// Omit the 'rand' check since 'arc4random' is not available on Linux.
end_comment

begin_function_decl
name|int
name|rand
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|drand48
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|erand48
parameter_list|(
name|unsigned
name|short
index|[
literal|3
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|jrand48
parameter_list|(
name|unsigned
name|short
index|[
literal|3
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lcong48
parameter_list|(
name|unsigned
name|short
index|[
literal|7
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|lrand48
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|mrand48
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|nrand48
parameter_list|(
name|unsigned
name|short
index|[
literal|3
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|random
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rand_r
parameter_list|(
name|unsigned
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_rand
parameter_list|()
block|{
name|unsigned
name|short
name|a
index|[
literal|7
index|]
decl_stmt|;
name|unsigned
name|b
decl_stmt|;
name|rand
argument_list|()
expr_stmt|;
comment|// no-warning
name|drand48
argument_list|()
expr_stmt|;
comment|// no-warning
name|erand48
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// no-warning
name|jrand48
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// no-warning
name|lcong48
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// no-warning
name|lrand48
argument_list|()
expr_stmt|;
comment|// no-warning
name|mrand48
argument_list|()
expr_stmt|;
comment|// no-warning
name|nrand48
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// no-warning
name|rand_r
argument_list|(
operator|&
name|b
argument_list|)
expr_stmt|;
comment|// no-warning
name|random
argument_list|()
expr_stmt|;
comment|// no-warning
block|}
end_function

end_unit

