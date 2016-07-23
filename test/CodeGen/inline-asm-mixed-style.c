begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -fasm-blocks -fsyntax-only -verify %s -DCHECK_ASM_GOTO
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -fasm-blocks -O0 -emit-llvm -S %s -o - | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
asm|__asm mov eax, ebx
asm|__asm mov ebx, ecx
asm|__asm__("movl %ecx, %edx");
comment|// CHECK: movl    %ebx, %eax
comment|// CHECK: movl    %ecx, %ebx
comment|// CHECK: movl    %ecx, %edx
asm|__asm mov eax, ebx
asm|__asm volatile ("movl %ecx, %edx");
comment|// CHECK: movl    %ebx, %eax
comment|// CHECK: movl    %ecx, %edx
asm|__asm mov eax, ebx
asm|__asm const ("movl %ecx, %edx");
comment|// expected-warning {{ignored const qualifier on asm}}
comment|// CHECK: movl    %ebx, %eax
comment|// CHECK: movl    %ecx, %edx
ifdef|#
directive|ifdef
name|CHECK_ASM_GOTO
asm|__asm volatile goto ("movl %ecx, %edx");
comment|// expected-error {{'asm goto' constructs are not supported yet}}
asm|__asm mov eax, ebx
asm|__asm goto ("movl %ecx, %edx");
comment|// expected-error {{'asm goto' constructs are not supported yet}}
endif|#
directive|endif
block|}
end_function

end_unit

