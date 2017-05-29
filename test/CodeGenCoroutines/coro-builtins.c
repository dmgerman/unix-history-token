begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-windows-msvc18.0.0 -fcoroutines-ts -emit-llvm %s -o - -disable-llvm-passes | FileCheck %s
end_comment

begin_function_decl
name|void
modifier|*
name|myAlloc
parameter_list|(
name|long
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: f(
end_comment

begin_function
name|void
name|f
parameter_list|(
name|int
name|n
parameter_list|)
block|{
comment|// CHECK: %n.addr = alloca i32
comment|// CHECK: %n_copy = alloca i32
comment|// CHECK: %promise = alloca i32
name|int
name|n_copy
decl_stmt|;
name|int
name|promise
decl_stmt|;
comment|// CHECK: %[[PROM_ADDR:.+]] = bitcast i32* %promise to i8*
comment|// CHECK-NEXT: %[[COROID:.+]] = call token @llvm.coro.id(i32 32, i8* %[[PROM_ADDR]], i8* null, i8* null)
name|__builtin_coro_id
argument_list|(
literal|32
argument_list|,
operator|&
name|promise
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: call i1 @llvm.coro.alloc(token %[[COROID]])
name|__builtin_coro_alloc
argument_list|()
expr_stmt|;
comment|// CHECK-NEXT: %[[SIZE:.+]] = call i64 @llvm.coro.size.i64()
comment|// CHECK-NEXT: %[[MEM:.+]] = call i8* @myAlloc(i64 %[[SIZE]])
comment|// CHECK-NEXT: %[[FRAME:.+]] = call i8* @llvm.coro.begin(token %[[COROID]], i8* %[[MEM]])
name|__builtin_coro_begin
argument_list|(
name|myAlloc
argument_list|(
name|__builtin_coro_size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: call void @llvm.coro.resume(i8* %[[FRAME]])
name|__builtin_coro_resume
argument_list|(
name|__builtin_coro_frame
argument_list|()
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: call void @llvm.coro.destroy(i8* %[[FRAME]])
name|__builtin_coro_destroy
argument_list|(
name|__builtin_coro_frame
argument_list|()
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: call i1 @llvm.coro.done(i8* %[[FRAME]])
name|__builtin_coro_done
argument_list|(
name|__builtin_coro_frame
argument_list|()
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: call i8* @llvm.coro.promise(i8* %[[FRAME]], i32 48, i1 false)
name|__builtin_coro_promise
argument_list|(
name|__builtin_coro_frame
argument_list|()
argument_list|,
literal|48
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: call i8* @llvm.coro.free(token %[[COROID]], i8* %[[FRAME]])
name|__builtin_coro_free
argument_list|(
name|__builtin_coro_frame
argument_list|()
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: call i1 @llvm.coro.end(i8* %[[FRAME]], i1 false)
name|__builtin_coro_end
argument_list|(
name|__builtin_coro_frame
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: call i8 @llvm.coro.suspend(token none, i1 true)
name|__builtin_coro_suspend
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: %[[N_ADDR:.+]] = bitcast i32* %n.addr to i8*
comment|// CHECK-NEXT: %[[N_COPY_ADDR:.+]] = bitcast i32* %n_copy to i8*
comment|// CHECK-NEXT: call i1 @llvm.coro.param(i8* %[[N_ADDR]], i8* %[[N_COPY_ADDR]])
name|__builtin_coro_param
argument_list|(
operator|&
name|n
argument_list|,
operator|&
name|n_copy
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

