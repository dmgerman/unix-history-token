begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that using the preamble option actually skips the preamble.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t %S/Inputs/preamble.h -DFOO=f
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -include-pch %t -preamble-bytes=317,1 -DFOO=f -verify %s -emit-llvm -o - | FileCheck %s
end_comment

begin_function_decl
name|float
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Not an error, because we skip this via the preamble!
end_comment

begin_function
name|int
name|g
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|FOO
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call {{.*}} @f(
end_comment

end_unit

