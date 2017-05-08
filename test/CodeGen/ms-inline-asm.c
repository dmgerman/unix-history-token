begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-apple-darwin10 -fasm-blocks -emit-llvm -o - | FileCheck %s
end_comment

begin_function
name|void
name|t1
parameter_list|()
block|{
comment|// CHECK: @t1
comment|// CHECK: call void asm sideeffect inteldialect "", "~{dirflag},~{fpsr},~{flags}"()
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
comment|// CHECK: call void asm sideeffect inteldialect "nop\0A\09nop\0A\09nop", "~{dirflag},~{fpsr},~{flags}"()
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
comment|// CHECK: call void asm sideeffect inteldialect "nop\0A\09nop\0A\09nop", "~{dirflag},~{fpsr},~{flags}"()
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
comment|// CHECK: call void asm sideeffect inteldialect "mov ebx, eax\0A\09mov ecx, ebx", "~{ebx},~{ecx},~{dirflag},~{fpsr},~{flags}"()
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
comment|// CHECK: call void asm sideeffect inteldialect "mov ebx, eax\0A\09mov ecx, ebx", "~{ebx},~{ecx},~{dirflag},~{fpsr},~{flags}"()
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
comment|// CHECK: call void asm sideeffect inteldialect "int $$0x2c", "~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t7
parameter_list|()
block|{
asm|__asm {
asm|int 0x2cU ;
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
asm|__asm {
asm|{
asm|int 0x2c ;
asm|}
asm|asm comments are fun!
asm|}
end_asm

begin_block
block|{     }
end_block

begin_asm
unit|}
asm|__asm {}
end_asm

begin_asm
asm|__asm {     ;     ;
asm|label
asm|mov eax, ebx
asm|}
end_asm

begin_comment
comment|// CHECK: t7
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "int $$0x2cU", "~{dirflag},~{fpsr},~{flags}"()
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "", "~{dirflag},~{fpsr},~{flags}"()
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, ebx", "~{eax},~{dirflag},~{fpsr},~{flags}"()
end_comment

begin_function
unit|}
name|int
name|t8
parameter_list|()
block|{
asm|__asm int 4 ;
block|}
end_function

begin_macro
name|comments
end_macro

begin_for
for|for single-line asm
asm|__asm {}
asm|__asm {
asm|int 5
asm|}
asm|__asm int 6
asm|__asm int 7
asm|__asm {
asm|int 8
asm|}
for|return 10
empty_stmt|;
end_for

begin_comment
comment|// CHECK: t8
end_comment

begin_comment
comment|// CHECK: call i32 asm sideeffect inteldialect "int $$4", "={eax},~{dirflag},~{fpsr},~{flags}"()
end_comment

begin_comment
comment|// CHECK: call i32 asm sideeffect inteldialect "", "={eax},~{dirflag},~{fpsr},~{flags}"()
end_comment

begin_comment
comment|// CHECK: call i32 asm sideeffect inteldialect "int $$5", "={eax},~{dirflag},~{fpsr},~{flags}"()
end_comment

begin_comment
comment|// CHECK: call i32 asm sideeffect inteldialect "int $$6\0A\09int $$7", "={eax},~{dirflag},~{fpsr},~{flags}"()
end_comment

begin_comment
comment|// CHECK: call i32 asm sideeffect inteldialect "int $$8", "={eax},~{dirflag},~{fpsr},~{flags}"()
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
asm|{
asm|mov ebx, 0x07
asm|}
asm|__asm {
asm|pop ebx
asm|}
asm|}
comment|// CHECK: t9
comment|// CHECK: call void asm sideeffect inteldialect
comment|// CHECK-SAME: push ebx
comment|// CHECK-SAME: mov ebx, $$0x07
comment|// CHECK-SAME: pop ebx
comment|// CHECK-SAME: "~{ebx},~{esp},~{dirflag},~{fpsr},~{flags}"()
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
comment|// CHECK: [[r:%[a-zA-Z0-9]+]] = alloca i32, align 4
comment|// CHECK: [[I:%[a-zA-Z0-9]+]] = alloca i32, align 4
comment|// CHECK: [[J:%[a-zA-Z0-9]+]] = alloca i32, align 4
comment|// CHECK: store i32 1, i32* [[I]], align 4
comment|// CHECK: call i32 asm sideeffect inteldialect
comment|// CHECK-SAME: mov eax, $2
comment|// CHECK-SAME: mov $0, eax
comment|// CHECK-SAME: "=*m,={eax},*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}, i32* %{{.*}})
comment|// CHECK: [[RET:%[a-zA-Z0-9]+]] = load i32, i32* [[J]], align 4
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
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$1", "~{eax},~{dirflag},~{fpsr},~{flags}"()
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
comment|// CHECK: call i32 asm sideeffect inteldialect
comment|// CHECK-SAME: mov eax, $3
comment|// CHECK-SAME: mov $0, eax
comment|// CHECK-SAME: mov eax, $4
comment|// CHECK-SAME: mov $1, eax
comment|// CHECK-SAME: "=*m,=*m,={eax},*m,*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}, i32* %{{.*}}, i32* %{{.*}}, i32* %{{.*}})
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
comment|// CHECK-LABEL: define void @t13()
comment|// CHECK: call void asm sideeffect inteldialect
comment|// CHECK-SAME: movzx eax, byte ptr $0
comment|// CHECK-SAME: movzx eax, word ptr $1
comment|// CHECK-SAME: "*m,*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i8* %{{.*}}i, i16* %{{.*}}j)
block|}
end_function

begin_function
name|void
name|t13_brac
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
asm|__asm movzx eax, [i]
asm|__asm movzx eax, [j]
comment|// CHECK-LABEL: define void @t13_brac()
comment|// CHECK: call void asm sideeffect inteldialect
comment|// CHECK-SAME: movzx eax, byte ptr $0
comment|// CHECK-SAME: movzx eax, word ptr $1
comment|// CHECK-SAME: "*m,*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i8* %{{.*}}i, i16* %{{.*}}j)
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
asm|{
asm|mov eax, i
asm|}
asm|.else
asm|mov ebx, j
asm|.endif
asm|}
comment|// CHECK: t14
comment|// CHECK: call void asm sideeffect inteldialect ".if 1\0A\09mov eax, $0\0A\09.else\0A\09mov ebx, j\0A\09.endif", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
block|}
end_function

begin_decl_stmt
name|int
name|gvar
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|t15
parameter_list|()
block|{
comment|// CHECK: t15
name|int
name|lvar
init|=
literal|10
decl_stmt|;
asm|__asm mov eax, lvar        ;
name|eax
operator|=
literal|10
comment|// CHECK: mov eax, $0
asm|__asm mov eax, offset lvar ;
name|eax
operator|=
name|address
name|of
name|lvar
comment|// CHECK: mov eax, $1
asm|__asm mov eax, offset gvar ;
name|eax
operator|=
name|address
name|of
name|gvar
comment|// CHECK: mov eax, $2
comment|// CHECK: "*m,r,r,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}, i32* %{{.*}}, i32* @{{.*}})
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
comment|// CHECK: call void asm sideeffect inteldialect "mov [eax], $0", "r,~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
block|}
end_function

begin_function
name|void
name|t17
parameter_list|()
block|{
comment|// CHECK: t17
asm|__asm _emit 0x4A
comment|// CHECK: .byte 0x4A
asm|__asm _emit 0x43L
comment|// CHECK: .byte 0x43L
asm|__asm _emit 0x4B
comment|// CHECK: .byte 0x4B
asm|__asm _EMIT 0x4B
comment|// CHECK: .byte 0x4B
comment|// CHECK:  "~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t20
parameter_list|()
block|{
comment|// CHECK: t20
name|char
name|bar
decl_stmt|;
name|int
name|foo
decl_stmt|;
name|char
name|_bar
index|[
literal|2
index|]
decl_stmt|;
name|int
name|_foo
index|[
literal|4
index|]
decl_stmt|;
asm|__asm mov eax, LENGTH foo
comment|// CHECK: mov eax, $$1
asm|__asm mov eax, LENGTH bar
comment|// CHECK: mov eax, $$1
asm|__asm mov eax, LENGTH _foo
comment|// CHECK: mov eax, $$4
asm|__asm mov eax, LENGTH _bar
comment|// CHECK: mov eax, $$2
asm|__asm mov eax, [eax + LENGTH foo * 4]
comment|// CHECK: mov eax, [eax + $$1 * $$4]
asm|__asm mov eax, TYPE foo
comment|// CHECK: mov eax, $$4
asm|__asm mov eax, TYPE bar
comment|// CHECK: mov eax, $$1
asm|__asm mov eax, TYPE _foo
comment|// CHECK: mov eax, $$4
asm|__asm mov eax, TYPE _bar
comment|// CHECK: mov eax, $$1
asm|__asm mov eax, [eax + TYPE foo * 4]
comment|// CHECK: mov eax, [eax + $$4 * $$4]
asm|__asm mov eax, SIZE foo
comment|// CHECK: mov eax, $$4
asm|__asm mov eax, SIZE bar
comment|// CHECK: mov eax, $$1
asm|__asm mov eax, SIZE _foo
comment|// CHECK: mov eax, $$16
asm|__asm mov eax, [eax + SIZE _foo * 4]
comment|// CHECK: mov eax, [eax + $$16 * $$4]
asm|__asm mov eax, SIZE _bar
comment|// CHECK: mov eax, $$2
comment|// CHECK: "~{eax},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t21
parameter_list|()
block|{
asm|__asm {
asm|__asm push ebx
asm|__asm mov ebx, 07H
asm|__asm pop ebx
asm|}
comment|// CHECK: t21
comment|// CHECK: call void asm sideeffect inteldialect
comment|// CHECK-SAME: push ebx
comment|// CHECK-SAME: mov ebx, $$07H
comment|// CHECK-SAME: pop ebx
comment|// CHECK-SAME: "~{ebx},~{esp},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|t22_helper
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|t22
parameter_list|()
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
asm|__asm {
asm|__asm push ebx
asm|__asm mov ebx, esp
asm|}
name|t22_helper
argument_list|(
name|x
argument_list|)
expr_stmt|;
asm|__asm {
asm|__asm mov esp, ebx
asm|__asm pop ebx
asm|}
comment|// CHECK: t22
comment|// CHECK: call void asm sideeffect inteldialect
comment|// CHECK-SAME: push ebx
comment|// CHECK-SAME: mov ebx, esp
comment|// CHECK-SAME: "~{ebx},~{esp},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void @t22_helper
comment|// CHECK: call void asm sideeffect inteldialect
comment|// CHECK-SAME: mov esp, ebx
comment|// CHECK-SAME: pop ebx
comment|// CHECK-SAME: "~{ebx},~{esp},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t23
parameter_list|()
block|{
asm|__asm {
asm|the_label:
asm|}
comment|// CHECK: t23
comment|// CHECK: call void asm sideeffect inteldialect "{{.*}}__MSASMLABEL_.${:uid}__the_label:", "~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t24_helper
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function
name|void
name|t24
parameter_list|()
block|{
asm|__asm call t24_helper
comment|// CHECK: t24
comment|// CHECK: call void asm sideeffect inteldialect "call dword ptr $0", "*m,~{dirflag},~{fpsr},~{flags}"(void ()* @t24_helper)
block|}
end_function

begin_function
name|void
name|t25
parameter_list|()
block|{
comment|// CHECK: t25
asm|__asm mov eax, 0ffffffffh
comment|// CHECK: mov eax, $$0ffffffffh
asm|__asm mov eax, 0fhU
comment|// CHECK: mov eax, $$15
asm|__asm mov eax, 0a2h
comment|// CHECK: mov eax, $$0a2h
asm|__asm mov eax, 10100010b
comment|// CHECK: mov eax, $$10100010b
asm|__asm mov eax, 10100010BU
comment|// CHECK: mov eax, $$162
comment|// CHECK: "~{eax},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t26
parameter_list|()
block|{
comment|// CHECK: t26
asm|__asm pushad
comment|// CHECK: pushad
asm|__asm mov eax, 0
comment|// CHECK: mov eax, $$0
asm|__asm __emit 0fh
comment|// CHECK: .byte 0fh
asm|__asm __emit 0a2h
comment|// CHECK: .byte 0a2h
asm|__asm __EMIT 0a2h
comment|// CHECK: .byte 0a2h
asm|__asm popad
comment|// CHECK: popad
comment|// CHECK: "~{eax},~{ebp},~{ebx},~{ecx},~{edi},~{edx},~{esi},~{esp},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t27
parameter_list|()
block|{
asm|__asm mov eax, fs:[0h]
comment|// CHECK: t27
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, fs:[$$0h]", "~{eax},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t28
parameter_list|()
block|{
comment|// CHECK: t28
asm|__asm align 8
comment|// CHECK: .align 3
asm|__asm align 16;
comment|// CHECK: .align 4
asm|__asm align 128;
comment|// CHECK: .align 7
asm|__asm ALIGN 256;
comment|// CHECK: .align 8
comment|// CHECK: "~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t29
parameter_list|()
block|{
comment|// CHECK: t29
name|int
name|arr
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|int
name|olen
init|=
literal|0
decl_stmt|,
name|osize
init|=
literal|0
decl_stmt|,
name|otype
init|=
literal|0
decl_stmt|;
asm|__asm mov olen, LENGTH arr
comment|// CHECK: mov dword ptr $0, $$2
asm|__asm mov osize, SIZE arr
comment|// CHECK: mov dword ptr $1, $$8
asm|__asm mov otype, TYPE arr
comment|// CHECK: mov dword ptr $2, $$4
comment|// CHECK: "=*m,=*m,=*m,~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}, i32* %{{.*}}, i32* %{{.*}})
block|}
end_function

begin_decl_stmt
name|int
name|results
index|[
literal|2
index|]
init|=
block|{
literal|13
block|,
literal|37
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
modifier|*
name|t30
parameter_list|()
comment|// CHECK: t30
block|{
name|int
modifier|*
name|res
decl_stmt|;
asm|__asm lea edi, results
comment|// CHECK: lea edi, $2
asm|__asm mov res, edi
comment|// CHECK: mov $0, edi
return|return
name|res
return|;
comment|// CHECK: "=*m,={eax},*m,~{edi},~{dirflag},~{fpsr},~{flags}"(i32** %{{.*}}, [2 x i32]* @{{.*}})
block|}
end_function

begin_function
name|void
name|t31
parameter_list|()
block|{
comment|// CHECK: t31
asm|__asm pushad
comment|// CHECK: pushad
asm|__asm popad
comment|// CHECK: popad
comment|// CHECK: "~{eax},~{ebp},~{ebx},~{ecx},~{edi},~{edx},~{esi},~{esp},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t32
parameter_list|()
block|{
comment|// CHECK: t32
name|int
name|i
decl_stmt|;
asm|__asm mov eax, i
comment|// CHECK: mov eax, $0
asm|__asm mov eax, dword ptr i
comment|// CHECK: mov eax, dword ptr $1
asm|__asm mov ax, word ptr i
comment|// CHECK: mov ax, word ptr $2
asm|__asm mov al, byte ptr i
comment|// CHECK: mov al, byte ptr $3
comment|// CHECK: "*m,*m,*m,*m,~{al},~{ax},~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}, i32* %{{.*}}, i32* %{{.*}}, i32* %{{.*}})
block|}
end_function

begin_function
name|void
name|t33
parameter_list|()
block|{
comment|// CHECK: t33
name|int
name|i
decl_stmt|;
asm|__asm mov eax, [i]
comment|// CHECK: mov eax, $0
asm|__asm mov eax, dword ptr [i]
comment|// CHECK: mov eax, dword ptr $1
asm|__asm mov ax, word ptr [i]
comment|// CHECK: mov ax, word ptr $2
asm|__asm mov al, byte ptr [i]
comment|// CHECK: mov al, byte ptr $3
comment|// CHECK: "*m,*m,*m,*m,~{al},~{ax},~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}, i32* %{{.*}}, i32* %{{.*}}, i32* %{{.*}})
block|}
end_function

begin_function
name|void
name|t34
parameter_list|()
block|{
comment|// CHECK: t34
asm|__asm prefetchnta 64[eax]
comment|// CHECK: prefetchnta $$64[eax]
asm|__asm mov eax, dword ptr 4[eax]
comment|// CHECK: mov eax, dword ptr $$4[eax]
comment|// CHECK: "~{eax},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t35
parameter_list|()
block|{
comment|// CHECK: t35
asm|__asm prefetchnta [eax + (200*64)]
comment|// CHECK: prefetchnta [eax + ($$200*$$64)]
asm|__asm mov eax, dword ptr [eax + (200*64)]
comment|// CHECK: mov eax, dword ptr [eax + ($$200*$$64)]
comment|// CHECK: "~{eax},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t36
parameter_list|()
block|{
comment|// CHECK: t36
name|int
name|arr
index|[
literal|4
index|]
decl_stmt|;
comment|// Work around PR20368: These should be single line blocks
asm|__asm {
asm|mov eax, 4[arr]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, 4[arr + 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$8$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, 8[arr + 4 + 32*2 - 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$72$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, 12[4 + arr]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$16$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, 4[4 + arr + 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$12$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, 4[64 + arr + (2*32)]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$132$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, 4[64 + arr - 2*32]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, [arr + 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, [arr + 4 + 32*2 - 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$64$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, [4 + arr]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, [4 + arr + 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$8$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, [64 + arr + (2*32)]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$128$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, [64 + arr - 2*32]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
block|}
end_function

begin_function
name|void
name|t37
parameter_list|()
block|{
comment|// CHECK: t37
asm|__asm mov eax, 4 + 8
comment|// CHECK: mov eax, $$12
asm|__asm mov eax, 4 + 8 * 16
comment|// CHECK: mov eax, $$132
asm|__asm mov eax, -4 + 8 * 16
comment|// CHECK: mov eax, $$124
asm|__asm mov eax, (4 + 4) * 16
comment|// CHECK: mov eax, $$128
asm|__asm mov eax, 4 + 8 * -16
comment|// CHECK: mov eax, $$4294967172
asm|__asm mov eax, 4 + 16 / -8
comment|// CHECK: mov eax, $$2
asm|__asm mov eax, (16 + 16) / -8
comment|// CHECK: mov eax, $$4294967292
asm|__asm mov eax, ~15
comment|// CHECK: mov eax, $$4294967280
asm|__asm mov eax, 6 ^ 3
comment|// CHECK: mov eax, $$5
comment|// CHECK: "~{eax},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t38
parameter_list|()
block|{
comment|// CHECK: t38
name|int
name|arr
index|[
literal|4
index|]
decl_stmt|;
comment|// Work around PR20368: These should be single line blocks
asm|__asm {
asm|mov eax, 4+4[arr]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$8$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, (4+4)[arr + 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$12$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, 8*2[arr + 4 + 32*2 - 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$80$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, 12+20[4 + arr]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$36$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, 4*16+4[4 + arr + 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$76$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, 4*4[64 + arr + (2*32)]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$144$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, 4*(4-2)[64 + arr - 2*32]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$8$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
asm|__asm {
asm|mov eax, 32*(4-2)[arr - 2*32]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$0$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
block|}
end_function

begin_function
name|void
name|cpuid
parameter_list|()
block|{
asm|__asm cpuid
comment|// CHECK-LABEL: define void @cpuid
comment|// CHECK: call void asm sideeffect inteldialect "cpuid", "~{eax},~{ebx},~{ecx},~{edx},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
name|A
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|b1
decl_stmt|;
name|A
name|b2
decl_stmt|;
block|}
name|B
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|c1
decl_stmt|;
name|A
name|c2
decl_stmt|;
name|int
name|c3
decl_stmt|;
name|B
name|c4
decl_stmt|;
block|}
name|C
typedef|;
end_typedef

begin_function
name|void
name|t39
parameter_list|()
block|{
comment|// CHECK-LABEL: define void @t39
asm|__asm mov eax, [eax].A.b
comment|// CHECK: mov eax, [eax].4
asm|__asm mov eax, [eax] A.b
comment|// CHECK: mov eax, [eax] .4
asm|__asm mov eax, fs:[0] A.b
comment|// CHECK: mov eax, fs:[$$0] .4
asm|__asm mov eax, [eax].B.b2.a
comment|// CHECK: mov eax, [eax].4
asm|__asm mov eax, [eax] B.b2.b
comment|// CHECK: mov eax, [eax] .8
asm|__asm mov eax, fs:[0] C.c2.b
comment|// CHECK: mov eax, fs:[$$0] .8
asm|__asm mov eax, [eax]C.c4.b2.b
comment|// CHECK: mov eax, [eax].24
comment|// CHECK: "~{eax},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t40
parameter_list|(
name|float
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @t40
name|int
name|i
decl_stmt|;
asm|__asm fld a
comment|// CHECK: fld dword ptr $1
asm|__asm fistp i
comment|// CHECK: fistp dword ptr $0
comment|// CHECK: "=*m,*m,~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}, float* %{{.*}})
block|}
end_function

begin_function
name|void
name|t41
parameter_list|(
name|unsigned
name|short
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @t41(i16 zeroext %a)
asm|__asm mov cs, a;
comment|// CHECK: mov cs, word ptr $0
asm|__asm mov ds, a;
comment|// CHECK: mov ds, word ptr $1
asm|__asm mov es, a;
comment|// CHECK: mov es, word ptr $2
asm|__asm mov fs, a;
comment|// CHECK: mov fs, word ptr $3
asm|__asm mov gs, a;
comment|// CHECK: mov gs, word ptr $4
asm|__asm mov ss, a;
comment|// CHECK: mov ss, word ptr $5
comment|// CHECK: "*m,*m,*m,*m,*m,*m,~{dirflag},~{fpsr},~{flags}"(i16* {{.*}}, i16* {{.*}}, i16* {{.*}}, i16* {{.*}}, i16* {{.*}}, i16* {{.*}})
block|}
end_function

begin_function
name|void
name|t42
parameter_list|()
block|{
comment|// CHECK-LABEL: define void @t42
name|int
name|flags
decl_stmt|;
asm|__asm mov flags, eax
comment|// CHECK: mov $0, eax
comment|// CHECK: "=*m,~{dirflag},~{fpsr},~{flags}"(i32* %flags)
block|}
end_function

begin_function
name|void
name|t43
parameter_list|()
block|{
comment|// CHECK-LABEL: define void @t43
name|C
name|strct
decl_stmt|;
comment|// Work around PR20368: These should be single line blocks
asm|__asm {
asm|mov eax, 4[strct.c1]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
asm|__asm {
asm|mov eax, 4[strct.c3 + 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$8$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
asm|__asm {
asm|mov eax, 8[strct.c2.a + 4 + 32*2 - 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$72$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
asm|__asm {
asm|mov eax, 12[4 + strct.c2.b]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$16$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
asm|__asm {
asm|mov eax, 4[4 + strct.c4.b2.b + 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$12$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
asm|__asm {
asm|mov eax, 4[64 + strct.c1 + (2*32)]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$132$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
asm|__asm {
asm|mov eax, 4[64 + strct.c2.a - 2*32]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
asm|__asm {
asm|mov eax, [strct.c4.b1 + 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
asm|__asm {
asm|mov eax, [strct.c4.b2.a + 4 + 32*2 - 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$64$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
asm|__asm {
asm|mov eax, [4 + strct.c1]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
asm|__asm {
asm|mov eax, [4 + strct.c2.b + 4]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$8$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
asm|__asm {
asm|mov eax, [64 + strct.c3 + (2*32)]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$128$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
asm|__asm {
asm|mov eax, [64 + strct.c4.b2.b - 2*32]
asm|}
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
block|}
end_function

begin_function
name|void
name|call_clobber
parameter_list|()
block|{
asm|__asm call t41
comment|// CHECK-LABEL: define void @call_clobber
comment|// CHECK: call void asm sideeffect inteldialect "call dword ptr $0", "*m,~{dirflag},~{fpsr},~{flags}"(void (i16)* @t41)
block|}
end_function

begin_function
name|void
name|xgetbv
parameter_list|()
block|{
asm|__asm xgetbv
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @xgetbv()
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "xgetbv", "~{eax},~{edx},~{dirflag},~{fpsr},~{flags}"()
end_comment

begin_function
name|void
name|label1
parameter_list|()
block|{
asm|__asm {
asm|label:
asm|jmp label
asm|}
comment|// CHECK-LABEL: define void @label1()
comment|// CHECK: call void asm sideeffect inteldialect "{{.*}}__MSASMLABEL_.${:uid}__label:\0A\09jmp {{.*}}__MSASMLABEL_.${:uid}__label", "~{dirflag},~{fpsr},~{flags}"() [[ATTR1:#[0-9]+]]
block|}
end_function

begin_function
name|void
name|label2
parameter_list|()
block|{
asm|__asm {
asm|jmp label
asm|label:
asm|}
comment|// CHECK-LABEL: define void @label2
comment|// CHECK: call void asm sideeffect inteldialect "jmp {{.*}}__MSASMLABEL_.${:uid}__label\0A\09{{.*}}__MSASMLABEL_.${:uid}__label:", "~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|label3
parameter_list|()
block|{
asm|__asm {
asm|label:
asm|mov eax, label
asm|}
comment|// CHECK-LABEL: define void @label3
comment|// CHECK: call void asm sideeffect inteldialect "{{.*}}__MSASMLABEL_.${:uid}__label:\0A\09mov eax, {{.*}}__MSASMLABEL_.${:uid}__label", "~{eax},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|label4
parameter_list|()
block|{
asm|__asm {
asm|label:
asm|mov eax, [label]
asm|}
comment|// CHECK-LABEL: define void @label4
comment|// CHECK: call void asm sideeffect inteldialect "{{.*}}__MSASMLABEL_.${:uid}__label:\0A\09mov eax, {{.*}}__MSASMLABEL_.${:uid}__label", "~{eax},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|label5
parameter_list|()
block|{
asm|__asm {
asm|jmp dollar_label$
asm|dollar_label$:
asm|}
comment|// CHECK-LABEL: define void @label5
comment|// CHECK: call void asm sideeffect inteldialect "jmp {{.*}}__MSASMLABEL_.${:uid}__dollar_label$$\0A\09{{.*}}__MSASMLABEL_.${:uid}__dollar_label$$:", "~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|label6
parameter_list|()
block|{
asm|__asm {
asm|jmp short label
asm|label:
asm|}
comment|// CHECK-LABEL: define void @label6
comment|// CHECK: call void asm sideeffect inteldialect "jmp {{.*}}__MSASMLABEL_.${:uid}__label\0A\09{{.*}}__MSASMLABEL_.${:uid}__label:", "~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_comment
comment|// Don't include mxcsr in the clobber list.
end_comment

begin_function
name|void
name|mxcsr
parameter_list|()
block|{
name|char
name|buf
index|[
literal|4096
index|]
decl_stmt|;
asm|__asm fxrstor buf
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @mxcsr
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "fxrstor $0", "=*m,~{dirflag},~{fpsr},~{flags}"
end_comment

begin_typedef
typedef|typedef
union|union
name|_LARGE_INTEGER
block|{
struct|struct
block|{
name|unsigned
name|int
name|LowPart
decl_stmt|;
name|unsigned
name|int
name|HighPart
decl_stmt|;
block|}
struct|;
struct|struct
block|{
name|unsigned
name|int
name|LowPart
decl_stmt|;
name|unsigned
name|int
name|HighPart
decl_stmt|;
block|}
name|u
struct|;
name|unsigned
name|long
name|long
name|QuadPart
decl_stmt|;
block|}
name|LARGE_INTEGER
operator|,
typedef|*
name|PLARGE_INTEGER
typedef|;
end_typedef

begin_function
name|int
name|test_indirect_field
parameter_list|(
name|LARGE_INTEGER
name|LargeInteger
parameter_list|)
block|{
asm|__asm mov     eax, LargeInteger.LowPart
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_indirect_field(
end_comment

begin_comment
comment|// CHECK: call i32 asm sideeffect inteldialect "mov eax, $1",
end_comment

begin_comment
comment|// MS ASM containing labels must not be duplicated (PR23715).
end_comment

begin_comment
comment|// CHECK: attributes [[ATTR1]] = {
end_comment

begin_comment
comment|// CHECK-NOT: noduplicate
end_comment

begin_comment
comment|// CHECK-SAME: }{{$}}
end_comment

end_unit

