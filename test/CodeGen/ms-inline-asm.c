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
comment|// CHECK: call void asm sideeffect "nop", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
comment|// CHECK: call void asm sideeffect "nop", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
comment|// CHECK: call void asm sideeffect "nop", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
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
comment|// CHECK: call void asm sideeffect "mov ebx, eax", "~{ebx},~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
comment|// CHECK: call void asm sideeffect "mov ecx, ebx", "~{ecx},~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
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
comment|// CHECK: call void asm sideeffect "mov ebx, eax\0Amov ecx, ebx", "~{ebx},~{ecx},~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
comment|// CHECK: ret void
asm|__asm mov ebx, eax
asm|__asm mov ecx, ebx
block|}
end_function

begin_function
name|void
name|t6
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm int 0x2c
comment|// CHECK: t6
comment|// CHECK: call void asm sideeffect "int 0x2c", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
block|}
end_function

begin_function
name|void
modifier|*
name|t7
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm mov eax, fs:[0x10]
comment|// CHECK: t7
comment|// CHECK: call void asm sideeffect "mov eax, fs:[0x10]", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
block|}
end_function

begin_function
name|void
name|t8
parameter_list|()
block|{
asm|__asm {
asm|int 0x2c ;
asm|}
name|asm
name|comments
name|are
name|fun
operator|!
block|}
end_function

begin_block
block|{   }
end_block

begin_asm
asm|__asm {}
end_asm

begin_comment
comment|// CHECK: t8
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect "int 0x2c", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect "", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
end_comment

begin_macro
unit|} int
name|t9
argument_list|()
end_macro

begin_block
block|{
asm|__asm int 3 ;
block|}
end_block

begin_macro
name|comments
end_macro

begin_for
for|for single-line asm
asm|__asm {}
asm|__asm int 4
for|return 10
empty_stmt|;
end_for

begin_comment
comment|// CHECK: t9
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect "int 3", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect "", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect "int 4", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
end_comment

begin_comment
comment|// CHECK: ret i32 10
end_comment

begin_macro
unit|} void
name|t10
argument_list|()
end_macro

begin_block
block|{
asm|__asm {
asm|push ebx
asm|mov ebx, 0x07
asm|pop ebx
asm|}
comment|// CHECK: t10
comment|// CHECK: call void asm sideeffect "push ebx\0Amov ebx, 0x07\0Apop ebx", "~{ebx},~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
block|}
end_block

begin_function
name|unsigned
name|t11
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|i
init|=
literal|1
decl_stmt|,
name|j
decl_stmt|;
asm|__asm {
asm|mov eax, i
asm|mov j, eax
asm|}
return|return
name|j
return|;
comment|// CHECK: t11
comment|// CHECK: [[I:%[a-zA-Z0-9]+]] = alloca i32, align 4
comment|// CHECK: [[J:%[a-zA-Z0-9]+]] = alloca i32, align 4
comment|// CHECK: store i32 1, i32* [[I]], align 4
comment|// CHECK: call void asm sideeffect "mov eax, i\0Amov j, eax", "~{dirflag},~{fpsr},~{flags}"() nounwind ia_nsdialect
comment|// CHECK: [[RET:%[a-zA-Z0-9]+]] = load i32* [[J]], align 4
comment|// CHECK: ret i32 [[RET]]
block|}
end_function

begin_function
name|void
name|t12
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm EVEN
asm|__asm ALIGN
block|}
end_function

begin_function
name|void
name|t13
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm {
asm|_emit 0x4A
asm|_emit 0x43
asm|_emit 0x4B
asm|}
block|}
end_function

begin_function
name|void
name|t14
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|arr
index|[
literal|10
index|]
decl_stmt|;
asm|__asm LENGTH arr ;
sizeof|sizeof
argument_list|(
name|arr
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|arr
index|[
literal|0
index|]
argument_list|)
asm|__asm SIZE arr   ;
sizeof|sizeof
argument_list|(
name|arr
argument_list|)
asm|__asm TYPE arr   ;
expr|sizeof
operator|(
name|arr
index|[
literal|0
index|]
operator|)
block|}
end_function

end_unit

