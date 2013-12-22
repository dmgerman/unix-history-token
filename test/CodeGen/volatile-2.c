begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function
name|void
name|test0
parameter_list|()
block|{
comment|// CHECK-LABEL: define void @test0()
comment|// CHECK:      [[F:%.*]] = alloca float
comment|// CHECK-NEXT: [[REAL:%.*]] = load volatile float* getelementptr inbounds ({ float, float }* @test0_v, i32 0, i32 0), align 4
comment|// CHECK-NEXT: load volatile float* getelementptr inbounds ({{.*}} @test0_v, i32 0, i32 1), align 4
comment|// CHECK-NEXT: store float [[REAL]], float* [[F]], align 4
comment|// CHECK-NEXT: ret void
specifier|extern
specifier|volatile
specifier|_Complex
name|float
name|test0_v
decl_stmt|;
name|float
name|f
init|=
operator|(
name|float
operator|)
name|test0_v
decl_stmt|;
block|}
end_function

begin_function
name|void
name|test1
parameter_list|()
block|{
comment|// CHECK-LABEL: define void @test1()
comment|// CHECK:      [[REAL:%.*]] = load volatile float* getelementptr inbounds ({{.*}} @test1_v, i32 0, i32 0), align 4
comment|// CHECK-NEXT: [[IMAG:%.*]] = load volatile float* getelementptr inbounds ({{.*}} @test1_v, i32 0, i32 1), align 4
comment|// CHECK-NEXT: store volatile float [[REAL]], float* getelementptr inbounds ({{.*}} @test1_v, i32 0, i32 0), align 4
comment|// CHECK-NEXT: store volatile float [[IMAG]], float* getelementptr inbounds ({{.*}} @test1_v, i32 0, i32 1), align 4
comment|// CHECK-NEXT: ret void
specifier|extern
specifier|volatile
specifier|_Complex
name|float
name|test1_v
decl_stmt|;
name|test1_v
operator|=
name|test1_v
expr_stmt|;
block|}
end_function

end_unit

