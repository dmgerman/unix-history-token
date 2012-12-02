begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-apple-darwin10 -O0 -fms-extensions -fenable-experimental-ms-inline-asm -w -emit-llvm -o - | FileCheck %s
end_comment

begin_function
name|void
name|t1
parameter_list|()
block|{
name|int
name|var
init|=
literal|10
decl_stmt|;
asm|__asm mov rax, offset var ;
name|rax
operator|=
name|address
name|of
name|myvar
comment|// CHECK: t1
comment|// CHECK: call void asm sideeffect inteldialect "mov rax, $0", "r,~{rax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}) nounwind
block|}
end_function

begin_function
name|void
name|t2
parameter_list|()
block|{
name|int
name|var
init|=
literal|10
decl_stmt|;
asm|__asm mov [eax], offset var
comment|// CHECK: t2
comment|// CHECK: call void asm sideeffect inteldialect "mov [eax], $0", "r,~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}) nounwind
block|}
end_function

end_unit

