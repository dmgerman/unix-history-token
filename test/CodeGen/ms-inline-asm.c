begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-apple-darwin10 -O0 -fms-extensions -fenable-experimental-ms-inline-asm -w -emit-llvm -o - | FileCheck %s
end_comment

begin_function
name|void
name|t1
parameter_list|()
block|{
comment|// CHECK: @t1
comment|// CHECK: call void asm sideeffect "", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
comment|// CHECK: ret void
asm|__asm {}
block|}
end_function

begin_function
name|void
name|t2
parameter_list|()
block|{
comment|// CHECK: @t2
comment|// CHECK: call void asm sideeffect "nop\0Anop\0Anop", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
comment|// CHECK: ret void
asm|__asm nop
asm|__asm nop
asm|__asm nop
block|}
end_function

begin_function
name|void
name|t3
parameter_list|()
block|{
comment|// CHECK: @t3
comment|// CHECK: call void asm sideeffect "nop\0Anop\0Anop", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
comment|// CHECK: ret void
asm|__asm nop
asm|__asm nop
asm|__asm nop
block|}
end_function

begin_function
name|void
name|t4
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: @t4
comment|// CHECK: call void asm sideeffect "mov ebx, eax\0Amov ecx, ebx", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
comment|// CHECK: ret void
asm|__asm mov ebx, eax
asm|__asm mov ecx, ebx
block|}
end_function

begin_function
name|void
name|t5
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: @t5
comment|// CHECK: call void asm sideeffect "mov ebx, eax\0Amov ecx, ebx", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
comment|// CHECK: ret void
asm|__asm mov ebx, eax
asm|__asm mov ecx, ebx
block|}
end_function

end_unit

