begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// The only part clang really deals with is the lvalue/rvalue
end_comment

begin_comment
comment|// distinction on constraints. It's sufficient to emit llvm and make
end_comment

begin_comment
comment|// sure that's sane.
end_comment

begin_decl_stmt
name|long
name|var
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_generic_constraints
parameter_list|(
name|int
name|var32
parameter_list|,
name|long
name|var64
parameter_list|)
block|{
asm|asm("add %0, %1, %1" : "=r"(var32) : "0"(var32));
comment|// CHECK: [[R32_ARG:%[a-zA-Z0-9]+]] = load i32*
comment|// CHECK: call i32 asm "add $0, $1, $1", "=r,0"(i32 [[R32_ARG]])
asm|asm("add %0, %1, %1" : "=r"(var64) : "0"(var64));
comment|// CHECK: [[R32_ARG:%[a-zA-Z0-9]+]] = load i64*
comment|// CHECK: call i64 asm "add $0, $1, $1", "=r,0"(i64 [[R32_ARG]])
asm|asm("ldr %0, %1" : "=r"(var32) : "m"(var));
asm|asm("ldr %0, [%1]" : "=r"(var64) : "r"(&var));
comment|// CHECK: call i32 asm "ldr $0, $1", "=r,*m"(i64* @var)
comment|// CHECK: call i64 asm "ldr $0, [$1]", "=r,r"(i64* @var)
block|}
end_function

begin_decl_stmt
name|float
name|f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|d
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_constraint_w
parameter_list|()
block|{
asm|asm("fadd %s0, %s1, %s1" : "=w"(f) : "w"(f));
comment|// CHECK: [[FLT_ARG:%[a-zA-Z_0-9]+]] = load float* @f
comment|// CHECK: call float asm "fadd ${0:s}, ${1:s}, ${1:s}", "=w,w"(float [[FLT_ARG]])
asm|asm("fadd %d0, %d1, %d1" : "=w"(d) : "w"(d));
comment|// CHECK: [[DBL_ARG:%[a-zA-Z_0-9]+]] = load double* @d
comment|// CHECK: call double asm "fadd ${0:d}, ${1:d}, ${1:d}", "=w,w"(double [[DBL_ARG]])
block|}
end_function

begin_function
name|void
name|test_constraints_immed
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm("add x0, x0, %0" : : "I"(4095) : "x0");
asm|asm("and w0, w0, %0" : : "K"(0xaaaaaaaa) : "w0");
asm|asm("and x0, x0, %0" : : "L"(0xaaaaaaaaaaaaaaaa) : "x0");
comment|// CHECK: call void asm sideeffect "add x0, x0, $0", "I,~{x0}"(i32 4095)
comment|// CHECK: call void asm sideeffect "and w0, w0, $0", "K,~{w0}"(i32 -1431655766)
comment|// CHECK: call void asm sideeffect "and x0, x0, $0", "L,~{x0}"(i64 -6148914691236517206)
block|}
end_function

begin_function
name|void
name|test_constraint_S
parameter_list|(
name|void
parameter_list|)
block|{
name|int
modifier|*
name|addr
decl_stmt|;
asm|asm("adrp %0, %A1\n\t"         "add %0, %0, %L1" : "=r"(addr) : "S"(&var));
comment|// CHECK: call i32* asm "adrp $0, ${1:A}\0A\09add $0, $0, ${1:L}", "=r,S"(i64* @var)
block|}
end_function

begin_function
name|void
name|test_constraint_Q
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|val
decl_stmt|;
asm|asm("ldxr %0, %1" : "=r"(val) : "Q"(var));
comment|// CHECK: call i32 asm "ldxr $0, $1", "=r,*Q"(i64* @var)
block|}
end_function

end_unit

