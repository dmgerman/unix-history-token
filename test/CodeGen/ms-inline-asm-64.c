begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple x86_64-apple-darwin10 -fasm-blocks -emit-llvm -o - | FileCheck %s
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
comment|// CHECK: call void asm sideeffect inteldialect
comment|// CHECK-SAME: mov rax, $0
comment|// CHECK-SAME: "r,~{rax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
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
comment|// CHECK: call void asm sideeffect inteldialect
comment|// CHECK-SAME: mov [eax], $0
comment|// CHECK-SAME: "r,~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
block|}
end_function

begin_struct
struct|struct
name|t3_type
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|t3
parameter_list|()
block|{
name|struct
name|t3_type
name|foo
decl_stmt|;
name|foo
operator|.
name|a
operator|=
literal|1
expr_stmt|;
name|foo
operator|.
name|b
operator|=
literal|2
expr_stmt|;
asm|__asm {
asm|lea ebx, foo
asm|mov eax, [ebx].0
asm|mov [ebx].4, ecx
asm|}
return|return
name|foo
operator|.
name|b
return|;
comment|// CHECK: t3
comment|// CHECK: call void asm sideeffect inteldialect
comment|// CHECK-SAME: lea ebx, $0
comment|// CHECK-SAME: mov eax, [ebx].0
comment|// CHECK-SAME: mov [ebx].4, ecx
comment|// CHECK-SAME: "*m,~{eax},~{ebx},~{dirflag},~{fpsr},~{flags}"(%struct.t3_type* %{{.*}})
block|}
end_function

begin_function
name|int
name|t4
parameter_list|()
block|{
name|struct
name|t3_type
name|foo
decl_stmt|;
name|foo
operator|.
name|a
operator|=
literal|1
expr_stmt|;
name|foo
operator|.
name|b
operator|=
literal|2
expr_stmt|;
asm|__asm {
asm|lea ebx, foo
asm|{
asm|mov eax, [ebx].foo.a
asm|}
asm|mov [ebx].foo.b, ecx
asm|}
return|return
name|foo
operator|.
name|b
return|;
comment|// CHECK: t4
comment|// CHECK: call void asm sideeffect inteldialect
comment|// CHECK-SAME: lea ebx, $0
comment|// CHECK-SAME: mov eax, [ebx].0
comment|// CHECK-SAME: mov [ebx].4, ecx
comment|// CHECK-SAME: "*m,~{eax},~{ebx},~{dirflag},~{fpsr},~{flags}"(%struct.t3_type* %{{.*}})
block|}
end_function

end_unit

