begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10.0.0 -fsyntax-only -Wuninitialized -fsyntax-only %s -verify
end_comment

begin_typedef
typedef|typedef
name|int
name|__v4si
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|__m128
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_function_decl
name|__m128
name|_mm_xor_ps
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__m128
name|_mm_loadu_ps
parameter_list|(
specifier|const
name|float
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test1
parameter_list|(
name|float
modifier|*
name|input
parameter_list|)
block|{
name|__m128
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|,
name|w
decl_stmt|,
name|X
decl_stmt|;
comment|// expected-note {{variable 'x' is declared here}} expected-note {{variable 'y' is declared here}} expected-note {{variable 'w' is declared here}}  expected-note {{variable 'z' is declared here}}
name|x
operator|=
name|_mm_xor_ps
argument_list|(
name|x
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{variable 'x' is uninitialized when used here}}
name|y
operator|=
name|_mm_xor_ps
argument_list|(
name|y
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// expected-warning {{variable 'y' is uninitialized when used here}}
name|z
operator|=
name|_mm_xor_ps
argument_list|(
name|z
argument_list|,
name|z
argument_list|)
expr_stmt|;
comment|// expected-warning {{variable 'z' is uninitialized when used here}}
name|w
operator|=
name|_mm_xor_ps
argument_list|(
name|w
argument_list|,
name|w
argument_list|)
expr_stmt|;
comment|// expected-warning {{variable 'w' is uninitialized when used here}}
name|X
operator|=
name|_mm_loadu_ps
argument_list|(
operator|&
name|input
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|X
operator|=
name|_mm_xor_ps
argument_list|(
name|X
argument_list|,
name|X
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

end_unit

