begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -triple powerpc64le-unknown-linux-gnu -fopenmp -x c -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: foo
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
argument_list|(
operator|*
name|b
argument_list|)
index|[
name|a
index|]
expr_stmt|;
name|int
argument_list|*
operator|(
operator|*
operator|*
name|c
operator|)
index|[
name|a
index|]
argument_list|;
comment|// CHECK: [[B:%.+]] = alloca i32*,
comment|// CHECK: [[C:%.+]] = alloca i32***,
comment|// CHECK: @__kmpc_global_thread_num
comment|// CHECK: call void @__kmpc_serialized_parallel
comment|// CHECK: call void [[OUTLINED:@[^(]+]](i32* %{{[^,]+}}, i32* %{{[^,]+}}, i64 %{{[^,]+}}, i32** [[B]], i64 %{{[^,]+}}, i32**** [[C]])
comment|// CHECK: call void @__kmpc_end_serialized_parallel
comment|// CHECK: ret void
pragma|#
directive|pragma
name|omp
name|parallel
name|if
name|(
name|0
name|)
name|b
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|=
name|c
index|[
literal|0
index|]
index|[
name|a
index|]
index|[
literal|0
index|]
index|[
name|a
index|]
argument_list|;
block|}
end_function

begin_comment
comment|// CHECK: define internal void [[OUTLINED]](i32* {{[^,]+}}, i32* {{[^,]+}}, i64 {{[^,]+}}, i32** {{[^,]+}}, i64 {{[^,]+}}, i32**** {{[^,]+}})
end_comment

end_unit

