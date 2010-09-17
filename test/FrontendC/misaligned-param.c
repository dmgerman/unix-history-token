begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -m32 -S -o - | FileCheck %s
end_comment

begin_comment
comment|// Misaligned parameter must be memcpy'd to correctly aligned temporary.
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// XTARGET: i386-apple-darwin,i686-apple-darwin,x86_64-apple-darwin
end_comment

begin_struct
struct|struct
name|s
block|{
name|int
name|x
decl_stmt|;
name|long
name|double
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|long
name|double
name|foo
parameter_list|(
name|struct
name|s
name|x
parameter_list|,
name|int
name|i
parameter_list|,
name|struct
name|s
name|y
parameter_list|)
block|{
comment|// CHECK: foo
comment|// CHECK: %x_addr = alloca %struct.s, align 16
comment|// CHECK: %y_addr = alloca %struct.s, align 16
comment|// CHECK: memcpy
comment|// CHECK: memcpy
comment|// CHECK: bar
return|return
name|bar
argument_list|(
operator|&
name|x
argument_list|,
operator|&
name|y
argument_list|)
return|;
block|}
end_function

end_unit

