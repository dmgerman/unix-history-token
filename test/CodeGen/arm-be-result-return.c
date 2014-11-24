begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armebv7-arm-none-eabi -emit-llvm -w -o - %s | FileCheck %s
end_comment

begin_comment
comment|// this tests for AAPCS section 5.4:
end_comment

begin_comment
comment|// A Composite Type not larger than 4 bytes is returned in r0.
end_comment

begin_comment
comment|// The format is as if the result had been stored in memory at a
end_comment

begin_comment
comment|// word-aligned address and then loaded into r0 with an LDR instruction
end_comment

begin_union
specifier|extern
union|union
name|Us
block|{
name|short
name|s
decl_stmt|;
block|}
name|us
union|;
end_union

begin_function
name|union
name|Us
name|callee_us
parameter_list|()
block|{
return|return
name|us
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: callee_us()
end_comment

begin_comment
comment|// CHECK: zext i16
end_comment

begin_comment
comment|// CHECK: shl
end_comment

begin_comment
comment|// CHECK: ret i32
end_comment

begin_function
name|void
name|caller_us
parameter_list|()
block|{
name|us
operator|=
name|callee_us
argument_list|()
expr_stmt|;
comment|// CHECK-LABEL: caller_us()
comment|// CHECK: call i32
comment|// CHECK: lshr i32
comment|// CHECK: trunc i32
block|}
end_function

begin_struct
specifier|extern
struct|struct
name|Ss
block|{
name|short
name|s
decl_stmt|;
block|}
name|ss
struct|;
end_struct

begin_function
name|struct
name|Ss
name|callee_ss
parameter_list|()
block|{
return|return
name|ss
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: callee_ss()
end_comment

begin_comment
comment|// CHECK: zext i16
end_comment

begin_comment
comment|// CHECK: shl
end_comment

begin_comment
comment|// CHECK: ret i32
end_comment

begin_function
name|void
name|caller_ss
parameter_list|()
block|{
name|ss
operator|=
name|callee_ss
argument_list|()
expr_stmt|;
comment|// CHECK-LABEL: caller_ss()
comment|// CHECK: call i32
comment|// CHECK: lshr i32
comment|// CHECK: trunc i32
block|}
end_function

end_unit

