begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-apple-darwin10 -fasm-blocks -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: .byte 64
end_comment

begin_comment
comment|// CHECK: .byte 64
end_comment

begin_comment
comment|// CHECK: .byte 64
end_comment

begin_comment
comment|// CHECK:  .even
end_comment

begin_function
name|void
name|t1
parameter_list|()
block|{
asm|__asm {
asm|.byte 64
asm|.byte 64
asm|.byte 64
asm|EVEN
asm|mov eax, ebx
asm|}
block|}
end_function

end_unit

