begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -Wunused-variable -verify %s
end_comment

begin_struct
struct|struct
name|s0
block|{
name|unsigned
name|int
name|i
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|proto
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f0
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|a
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
decl_stmt|,
name|b
decl_stmt|;
comment|// expected-warning{{unused}}
return|return;
block|}
end_function

begin_function
name|void
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

