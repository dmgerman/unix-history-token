begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffinite-math-only -emit-llvm -o - %s | FileCheck %s
end_comment

begin_decl_stmt
name|float
name|f0
decl_stmt|,
name|f1
decl_stmt|,
name|f2
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @foo()
comment|// CHECK: fadd nnan ninf
name|f0
operator|=
name|f1
operator|+
name|f2
expr_stmt|;
comment|// CHECK: ret
block|}
end_function

end_unit

