begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-pc-windows-msvc -target-cpu knl -fasm-blocks -emit-llvm -o - | FileCheck %s
end_comment

begin_function
name|void
name|t1
parameter_list|()
block|{
comment|// CHECK: @t1
comment|// CHECK: call void asm sideeffect inteldialect "vaddpd zmm8, zmm27, zmm6", "~{zmm8},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: ret void
asm|__asm {
asm|vaddpd zmm8, zmm27, zmm6
asm|}
block|}
end_function

begin_function
name|void
name|t2
parameter_list|()
block|{
comment|// CHECK: @t2
comment|// CHECK: call void asm sideeffect inteldialect "vaddpd zmm8 {k1}, zmm27, zmm6", "~{zmm8},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: ret void
asm|__asm {
asm|vaddpd zmm8 {k1
asm|}
operator|,
name|zmm27
operator|,
name|zmm6
block|}
end_function

unit|}
end_unit

