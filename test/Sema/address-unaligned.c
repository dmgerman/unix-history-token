begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fms-extensions -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__attribute__
argument_list|(
argument|(packed)
argument_list|)
name|S1
block|{
name|char
name|c0
decl_stmt|;
name|int
name|x
decl_stmt|;
name|char
name|c1
decl_stmt|;
block|}
name|S1
typedef|;
end_typedef

begin_function_decl
name|void
name|bar
parameter_list|(
name|__unaligned
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|__unaligned
name|S1
modifier|*
name|s1
parameter_list|)
block|{
name|bar
argument_list|(
operator|&
name|s1
operator|->
name|x
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

