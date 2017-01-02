begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-gnu -fms-extensions %s -emit-llvm -o - | FileCheck %s
end_comment

begin_function
name|long
name|test1
parameter_list|(
name|long
modifier|*
name|p
parameter_list|)
block|{
return|return
name|_InterlockedIncrement
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-DAG: define i64 @test1(
end_comment

begin_comment
comment|// CHECK:   %[[p_addr:.*]] = alloca i64*, align 8
end_comment

begin_comment
comment|// CHECK:   store i64* %p, i64** %[[p_addr]], align 8
end_comment

begin_comment
comment|// CHECK:   %[[p_load:.*]] = load i64*, i64** %[[p_addr]], align 8
end_comment

begin_comment
comment|// CHECK:   %[[atomic_add:.*]] = atomicrmw add i64* %[[p_load]], i64 1 seq_cst
end_comment

begin_comment
comment|// CHECK:   %[[res:.*]] = add i64 %[[atomic_add]], 1
end_comment

begin_comment
comment|// CHECK:   ret i64 %[[res]]
end_comment

begin_function
name|long
name|test2
parameter_list|(
name|long
modifier|*
name|p
parameter_list|)
block|{
return|return
name|_InterlockedDecrement
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-DAG: define i64 @test2(
end_comment

begin_comment
comment|// CHECK:   %[[p_addr:.*]] = alloca i64*, align 8
end_comment

begin_comment
comment|// CHECK:   store i64* %p, i64** %[[p_addr]], align 8
end_comment

begin_comment
comment|// CHECK:   %[[p_load:.*]] = load i64*, i64** %[[p_addr]], align 8
end_comment

begin_comment
comment|// CHECK:   %[[atomic_sub:.*]] = atomicrmw sub i64* %[[p_load]], i64 1 seq_cst
end_comment

begin_comment
comment|// CHECK:   %[[res:.*]] = sub i64 %[[atomic_sub]], 1
end_comment

begin_comment
comment|// CHECK:   ret i64 %[[res]]
end_comment

end_unit

