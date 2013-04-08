begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|intel_ocl_bicc
operator|)
argument_list|)
name|f1
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f2
parameter_list|(
name|void
parameter_list|)
block|{
name|f1
argument_list|()
expr_stmt|;
comment|// CHECK: call intel_ocl_bicc void @f1()
block|}
end_function

begin_comment
comment|// CHECK: declare intel_ocl_bicc void @f1()
end_comment

end_unit

