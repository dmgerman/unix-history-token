begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN:  %clang_cc1 -triple arm64_be-linux-gnu -ffreestanding -emit-llvm -O0 -o - %s | FileCheck %s
end_comment

begin_struct
struct|struct
name|bt3
block|{
name|signed
name|b2
range|:
literal|10
decl_stmt|;
name|signed
name|b3
range|:
literal|10
decl_stmt|;
block|}
name|b16
struct|;
end_struct

begin_comment
comment|// The correct right-shift amount is 40 bits for big endian.
end_comment

begin_function
name|signed
name|callee_b0f
parameter_list|(
name|struct
name|bt3
name|bp11
parameter_list|)
block|{
comment|// CHECK: = lshr i64 %{{.*}}, 40
return|return
name|bp11
operator|.
name|b2
return|;
block|}
end_function

end_unit

