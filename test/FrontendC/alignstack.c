begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -fasm-blocks -S -o - | FileCheck %s
end_comment

begin_comment
comment|// Complicated expression as jump target
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// XTARGET: x86,i386,i686,darwin
end_comment

begin_function
name|void
name|Method3
parameter_list|()
block|{
comment|// CHECK: Method3
comment|// CHECK-NOT: alignstack
asm|asm("foo:");
comment|// CHECK: return
block|}
end_function

begin_function
name|void
name|Method4
parameter_list|()
block|{
comment|// CHECK: Method4
comment|// CHECK: alignstack
name|asm
block|{
name|bar
label|:
block|}
comment|// CHECK: return
block|}
end_function

end_unit

