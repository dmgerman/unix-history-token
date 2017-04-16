begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -fblocks -analyzer-checker=core,nullability -verify %s
end_comment

begin_function_decl
name|void
name|it_takes_two
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
name|function_pointer_arity_mismatch
parameter_list|()
block|{
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|()
init|=
name|it_takes_two
function_decl|;
name|fptr
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// no-crash expected-warning {{Function taking 2 arguments is called with fewer (1)}}
block|}
end_function

begin_function
name|void
name|block_arity_mismatch
parameter_list|()
block|{
name|void
function_decl|(
modifier|^
name|b
function_decl|)
parameter_list|()
init|=
lambda|^
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{ }
function_decl|;
name|b
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// no-crash expected-warning {{Block taking 2 arguments is called with fewer (1)}}
block|}
end_function

end_unit

