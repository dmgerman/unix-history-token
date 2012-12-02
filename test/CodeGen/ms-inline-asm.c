begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-apple-darwin10 -O0 -fms-extensions -fenable-experimental-ms-inline-asm -w -emit-llvm -o - | FileCheck %s
end_comment

begin_function
name|void
name|t1
parameter_list|()
block|{
comment|// CHECK: @t1
comment|// CHECK: call void asm sideeffect inteldialect "", "~{dirflag},~{fpsr},~{flags}"() nounwind
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
comment|// CHECK: call void asm sideeffect inteldialect "nop", "~{dirflag},~{fpsr},~{flags}"() nounwind
comment|// CHECK: call void asm sideeffect inteldialect "nop", "~{dirflag},~{fpsr},~{flags}"() nounwind
comment|// CHECK: call void asm sideeffect inteldialect "nop", "~{dirflag},~{fpsr},~{flags}"() nounwind
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
comment|// CHECK: call void asm sideeffect inteldialect "nop\0A\09nop\0A\09nop", "~{dirflag},~{fpsr},~{flags}"() nounwind
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
comment|// CHECK: call void asm sideeffect inteldialect "mov ebx, eax", "~{ebx},~{dirflag},~{fpsr},~{flags}"() nounwind
comment|// CHECK: call void asm sideeffect inteldialect "mov ecx, ebx", "~{ecx},~{dirflag},~{fpsr},~{flags}"() nounwind
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
comment|// CHECK: call void asm sideeffect inteldialect "mov ebx, eax\0A\09mov ecx, ebx", "~{ebx},~{ecx},~{dirflag},~{fpsr},~{flags}"() nounwind
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
comment|// CHECK: call void asm sideeffect inteldialect "int $$0x2c", "~{dirflag},~{fpsr},~{flags}"() nounwind
block|}
end_function

begin_function
name|void
name|t7
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
comment|// CHECK: t7
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "int $$0x2c", "~{dirflag},~{fpsr},~{flags}"() nounwind
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "", "~{dirflag},~{fpsr},~{flags}"() nounwind
end_comment

begin_macro
unit|}  int
name|t8
argument_list|()
end_macro

begin_block
block|{
asm|__asm int 4 ;
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
comment|// CHECK: t8
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "int $$4", "~{dirflag},~{fpsr},~{flags}"() nounwind
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "", "~{dirflag},~{fpsr},~{flags}"() nounwind
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "int $$4", "~{dirflag},~{fpsr},~{flags}"() nounwind
end_comment

begin_comment
comment|// CHECK: ret i32 10
end_comment

begin_macro
unit|}  void
name|t9
argument_list|()
end_macro

begin_block
block|{
asm|__asm {
asm|push ebx
asm|mov ebx, 0x07
asm|pop ebx
asm|}
comment|// CHECK: t9
comment|// CHECK: call void asm sideeffect inteldialect "push ebx\0A\09mov ebx, $$0x07\0A\09pop ebx", "~{ebx},~{dirflag},~{fpsr},~{flags}"() nounwind
block|}
end_block

begin_function
name|unsigned
name|t10
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
comment|// CHECK: t10
comment|// CHECK: [[I:%[a-zA-Z0-9]+]] = alloca i32, align 4
comment|// CHECK: [[J:%[a-zA-Z0-9]+]] = alloca i32, align 4
comment|// CHECK: store i32 1, i32* [[I]], align 4
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $1\0A\09mov dword ptr $0, eax", "=*m,*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}, i32* %{{.*}}) nounwind
comment|// CHECK: [[RET:%[a-zA-Z0-9]+]] = load i32* [[J]], align 4
comment|// CHECK: ret i32 [[RET]]
block|}
end_function

begin_function
name|void
name|t11
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm mov eax, 1
comment|// CHECK: t11
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$1", "~{eax},~{dirflag},~{fpsr},~{flags}"() nounwind
block|}
end_function

begin_function
name|unsigned
name|t12
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
decl_stmt|,
name|l
init|=
literal|1
decl_stmt|,
name|m
decl_stmt|;
asm|__asm {
asm|mov eax, i
asm|mov j, eax
asm|mov eax, l
asm|mov m, eax
asm|}
return|return
name|j
operator|+
name|m
return|;
comment|// CHECK: t12
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $2\0A\09mov dword ptr $0, eax\0A\09mov eax, dword ptr $3\0A\09mov dword ptr $1, eax", "=*m,=*m,*m,*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}, i32* %{{.*}}, i32* %{{.*}}, i32* %{{.*}}) nounwind
block|}
end_function

begin_function
name|void
name|t13
parameter_list|()
block|{
name|char
name|i
init|=
literal|1
decl_stmt|;
name|short
name|j
init|=
literal|2
decl_stmt|;
asm|__asm movzx eax, i
asm|__asm movzx eax, j
comment|// CHECK: t13
comment|// CHECK: call void asm sideeffect inteldialect "movzx eax, byte ptr $0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i8* %{{.*}}) nounwind
comment|// CHECK: call void asm sideeffect inteldialect "movzx eax, word ptr $0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i16* %{{.*}}) nounwind
block|}
end_function

begin_function
name|void
name|t14
parameter_list|()
block|{
name|unsigned
name|i
init|=
literal|1
decl_stmt|,
name|j
init|=
literal|2
decl_stmt|;
asm|__asm {
asm|.if 1
asm|mov eax, i
asm|.else
asm|mov ebx, j
asm|.endif
asm|}
comment|// CHECK: t14
comment|// CHECK: call void asm sideeffect inteldialect ".if 1\0A\09mov eax, dword ptr $0\0A\09.else\0A\09mov ebx, j\0A\09.endif", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}) nounwind
block|}
end_function

begin_function
name|void
name|t15
parameter_list|()
block|{
name|int
name|var
init|=
literal|10
decl_stmt|;
asm|__asm mov eax, var        ;
name|eax
operator|=
literal|10
asm|__asm mov eax, offset var ;
name|eax
operator|=
name|address
name|of
name|myvar
comment|// CHECK: t15
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}) nounwind
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $0", "r,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}) nounwind
block|}
end_function

begin_function
name|void
name|t16
parameter_list|()
block|{
name|int
name|var
init|=
literal|10
decl_stmt|;
asm|__asm mov [eax], offset var
comment|// CHECK: t16
comment|// CHECK: call void asm sideeffect inteldialect "mov [eax], $0", "r,~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}) nounwind
block|}
end_function

begin_function
name|void
name|t17
parameter_list|()
block|{
asm|__asm _emit 0x4A
asm|__asm _emit 0x43
asm|__asm _emit 0x4B
comment|// CHECK: t17
comment|// CHECK:  call void asm sideeffect inteldialect ".byte 0x4A", "~{dirflag},~{fpsr},~{flags}"() nounwind
comment|// CHECK:  call void asm sideeffect inteldialect ".byte 0x43", "~{dirflag},~{fpsr},~{flags}"() nounwind
comment|// CHECK:  call void asm sideeffect inteldialect ".byte 0x4B", "~{dirflag},~{fpsr},~{flags}"() nounwind
block|}
end_function

begin_struct
struct|struct
name|t18_type
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
name|t18
parameter_list|()
block|{
name|struct
name|t18_type
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
comment|// CHECK: t18
comment|// CHECK: call void asm sideeffect inteldialect "lea ebx, foo\0A\09mov eax, [ebx].0\0A\09mov [ebx].4, ecx", "~{eax},~{dirflag},~{fpsr},~{flags}"() nounwind
block|}
end_function

begin_function
name|int
name|t19
parameter_list|()
block|{
name|struct
name|t18_type
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
asm|mov eax, [ebx].foo.a
asm|mov [ebx].foo.b, ecx
asm|}
return|return
name|foo
operator|.
name|b
return|;
comment|// CHECK: t19
comment|// CHECK: call void asm sideeffect inteldialect "lea ebx, foo\0A\09mov eax, [ebx].0\0A\09mov [ebx].4, ecx", "~{eax},~{dirflag},~{fpsr},~{flags}"() nounwind
block|}
end_function

begin_function
name|void
name|t20
parameter_list|()
block|{
name|int
name|foo
decl_stmt|;
asm|__asm mov eax, TYPE foo
comment|// CHECK: t20
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4", "~{eax},~{dirflag},~{fpsr},~{flags}"() nounwind
block|}
end_function

end_unit

