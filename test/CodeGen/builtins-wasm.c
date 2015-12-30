begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple wasm32-unknown-unknown -O3 -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=WEBASSEMBLY32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple wasm64-unknown-unknown -O3 -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix=WEBASSEMBLY64
end_comment

begin_function
name|__SIZE_TYPE__
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|__builtin_wasm_memory_size
argument_list|()
return|;
comment|// WEBASSEMBLY32: call {{i.*}} @llvm.wasm.memory.size.i32()
comment|// WEBASSEMBLY64: call {{i.*}} @llvm.wasm.memory.size.i64()
block|}
end_function

begin_function
name|void
name|f2
parameter_list|(
name|long
name|delta
parameter_list|)
block|{
name|__builtin_wasm_grow_memory
argument_list|(
name|delta
argument_list|)
expr_stmt|;
comment|// WEBASSEMBLY32: call void @llvm.wasm.grow.memory.i32(i32 %{{.*}})
comment|// WEBASSEMBLY64: call void @llvm.wasm.grow.memory.i64(i64 %{{.*}})
block|}
end_function

end_unit

