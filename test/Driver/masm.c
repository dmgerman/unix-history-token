begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i386-unknown-linux -masm=intel -S %s -### 2>&1 | FileCheck --check-prefix=CHECK-INTEL %s
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-linux -masm=att -S %s -### 2>&1 | FileCheck --check-prefix=CHECK-ATT %s
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-linux -S -masm=somerequired %s -### 2>&1 | FileCheck --check-prefix=CHECK-SOMEREQUIRED %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-unknown-eabi -S -masm=intel %s -### 2>&1 | FileCheck --check-prefix=CHECK-ARM %s
end_comment

begin_function
name|int
name|f
parameter_list|()
block|{
comment|// CHECK-INTEL: -x86-asm-syntax=intel
comment|// CHECK-ATT: -x86-asm-syntax=att
comment|// CHECK-SOMEREQUIRED: error: unsupported argument 'somerequired' to option 'masm='
comment|// CHECK-ARM: warning: argument unused during compilation: '-masm=intel'
return|return
literal|0
return|;
block|}
end_function

end_unit

