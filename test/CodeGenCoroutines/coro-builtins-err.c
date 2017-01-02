begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-windows-msvc18.0.0 -fcoroutines-ts -emit-llvm %s -o - -verify
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|__builtin_coro_alloc
argument_list|()
expr_stmt|;
comment|// expected-error {{this builtin expect that __builtin_coro_id}}
name|__builtin_coro_begin
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{this builtin expect that __builtin_coro_id}}
name|__builtin_coro_free
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{this builtin expect that __builtin_coro_id}}
name|__builtin_coro_id
argument_list|(
literal|32
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|__builtin_coro_id
argument_list|(
literal|32
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{only one __builtin_coro_id}}
block|}
end_function

end_unit

