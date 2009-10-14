begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o - -fmath-errno | FileCheck %s
end_comment

begin_comment
comment|// llvm.sqrt has undefined behavior on negative inputs, so it is
end_comment

begin_comment
comment|// inappropriate to translate C/C++ sqrt to this.
end_comment

begin_include
include|#
directive|include
file|<math.h>
end_include

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
comment|// CHECK: return
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

