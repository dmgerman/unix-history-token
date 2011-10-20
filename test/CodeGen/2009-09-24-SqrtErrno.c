begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -fmath-errno | FileCheck %s
end_comment

begin_comment
comment|// llvm.sqrt has undefined behavior on negative inputs, so it is
end_comment

begin_comment
comment|// inappropriate to translate C/C++ sqrt to this.
end_comment

begin_function_decl
name|float
name|sqrtf
parameter_list|(
name|float
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|float
name|foo
parameter_list|(
name|float
name|X
parameter_list|)
block|{
comment|// CHECK: foo
comment|// CHECK-NOT: readonly
comment|// CHECK: call float @sqrtf
comment|// Check that this is not marked readonly when errno is used.
return|return
name|sqrtf
argument_list|(
name|X
argument_list|)
return|;
block|}
end_function

end_unit

