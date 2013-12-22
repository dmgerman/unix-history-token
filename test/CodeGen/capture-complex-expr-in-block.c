begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -fblocks -triple x86_64-apple-darwin10 | FileCheck %s
end_comment

begin_comment
comment|// rdar://10033986
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|^
name|BLOCK
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function
name|int
name|main
parameter_list|()
block|{
specifier|_Complex
name|double
name|c
decl_stmt|;
name|BLOCK
name|b
init|=
lambda|^
parameter_list|()
block|{
specifier|_Complex
name|double
name|z
decl_stmt|;
name|z
operator|=
name|z
operator|+
name|c
expr_stmt|;
block|}
decl_stmt|;
name|b
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define internal void @__main_block_invoke
end_comment

begin_comment
comment|// CHECK:  [[C1:%.*]] = alloca { double, double }, align 8
end_comment

begin_comment
comment|// CHECK:  [[RP:%.*]] = getelementptr inbounds { double, double }* [[C1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK-NEXT:  [[R:%.*]] = load double* [[RP]]
end_comment

begin_comment
comment|// CHECK-NEXT:  [[IP:%.*]] = getelementptr inbounds { double, double }* [[C1]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK-NEXT:  [[I:%.*]] = load double* [[IP]]
end_comment

end_unit

