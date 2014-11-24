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
comment|// CHECK: call void asm sideeffect inteldialect "nop", "~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "nop", "~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "nop", "~{dirflag},~{fpsr},~{flags}"()
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
comment|// CHECK: call void asm sideeffect inteldialect "mov ebx, eax", "~{ebx},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov ecx, ebx", "~{ecx},~{dirflag},~{fpsr},~{flags}"()
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

begin_comment
comment|// CHECK: t7
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "int $$0x2c", "~{dirflag},~{fpsr},~{flags}"()
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "", "~{dirflag},~{fpsr},~{flags}"()
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
asm|__asm int 4
for|return 10
empty_stmt|;
end_for

begin_comment
comment|// CHECK: t8
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "int $$4", "~{dirflag},~{fpsr},~{flags}"()
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "", "~{dirflag},~{fpsr},~{flags}"()
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect inteldialect "int $$4", "~{dirflag},~{fpsr},~{flags}"()
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
comment|// CHECK: call void asm sideeffect inteldialect "push ebx\0A\09mov ebx, $$0x07\0A\09pop ebx", "~{ebx},~{esp},~{dirflag},~{fpsr},~{flags}"()
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
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $1\0A\09mov dword ptr $0, eax", "=*m,*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}, i32* %{{.*}})
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
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $2\0A\09mov dword ptr $0, eax\0A\09mov eax, dword ptr $3\0A\09mov dword ptr $1, eax", "=*m,=*m,*m,*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}}, i32* %{{.*}}, i32* %{{.*}}, i32* %{{.*}})
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
comment|// CHECK: call void asm sideeffect inteldialect "movzx eax, byte ptr $0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i8* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "movzx eax, word ptr $0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i16* %{{.*}})
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
comment|// CHECK: call void asm sideeffect inteldialect ".if 1\0A\09mov eax, dword ptr $0\0A\09.else\0A\09mov ebx, j\0A\09.endif", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
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
name|int
name|lvar
init|=
literal|10
decl_stmt|;
asm|__asm mov eax, lvar        ;
name|eax
operator|=
literal|10
asm|__asm mov eax, offset lvar ;
name|eax
operator|=
name|address
name|of
name|lvar
asm|__asm mov eax, offset gvar ;
name|eax
operator|=
name|address
name|of
name|gvar
comment|// CHECK: t15
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $0", "r,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $0", "r,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* @{{.*}})
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
asm|__asm _emit 0x4A
asm|__asm _emit 0x43
asm|__asm _emit 0x4B
asm|__asm _EMIT 0x4B
comment|// CHECK: t17
comment|// CHECK:  call void asm sideeffect inteldialect ".byte 0x4A", "~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK:  call void asm sideeffect inteldialect ".byte 0x43", "~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK:  call void asm sideeffect inteldialect ".byte 0x4B", "~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK:  call void asm sideeffect inteldialect ".byte 0x4B", "~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t20
parameter_list|()
block|{
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
asm|__asm mov eax, LENGTH bar
asm|__asm mov eax, LENGTH _foo
asm|__asm mov eax, LENGTH _bar
comment|// CHECK: t20
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$1", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$1", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$2", "~{eax},~{dirflag},~{fpsr},~{flags}"()
asm|__asm mov eax, TYPE foo
asm|__asm mov eax, TYPE bar
asm|__asm mov eax, TYPE _foo
asm|__asm mov eax, TYPE _bar
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$1", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$1", "~{eax},~{dirflag},~{fpsr},~{flags}"()
asm|__asm mov eax, SIZE foo
asm|__asm mov eax, SIZE bar
asm|__asm mov eax, SIZE _foo
asm|__asm mov eax, SIZE _bar
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$1", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$16", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$2", "~{eax},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t21
parameter_list|()
block|{
asm|__asm {
asm|__asm push ebx
asm|__asm mov ebx, 0x07
asm|__asm pop ebx
asm|}
comment|// CHECK: t21
comment|// CHECK: call void asm sideeffect inteldialect "push ebx\0A\09mov ebx, $$0x07\0A\09pop ebx", "~{ebx},~{esp},~{dirflag},~{fpsr},~{flags}"()
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
comment|// CHECK: call void asm sideeffect inteldialect "push ebx\0A\09mov ebx, esp", "~{ebx},~{esp},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void @t22_helper
comment|// CHECK: call void asm sideeffect inteldialect "mov esp, ebx\0A\09pop ebx", "~{ebx},~{esp},~{dirflag},~{fpsr},~{flags}"()
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
comment|// CHECK: call void asm sideeffect inteldialect "the_label:", "~{dirflag},~{fpsr},~{flags}"()
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
comment|// CHECK: call void asm sideeffect inteldialect "call $0", "r,~{dirflag},~{fpsr},~{flags}"(void ()* @t24_helper)
block|}
end_function

begin_function
name|void
name|t25
parameter_list|()
block|{
asm|__asm mov eax, 0ffffffffh
asm|__asm mov eax, 0fh
asm|__asm mov eax, 0a2h
asm|__asm mov eax, 0xa2h
asm|__asm mov eax, 0xa2
comment|// CHECK: t25
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4294967295", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$15", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$162", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$0xa2h", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$0xa2", "~{eax},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t26
parameter_list|()
block|{
asm|__asm pushad
asm|__asm mov eax, 0
asm|__asm __emit 0fh
asm|__asm __emit 0a2h
asm|__asm __EMIT 0a2h
asm|__asm popad
comment|// FIXME: These all need to be merged into the same asm blob.
comment|// CHECK: t26
comment|// CHECK: call void asm sideeffect inteldialect "pushad", "~{esp},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$0", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect ".byte 0fh", "~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect ".byte 0a2h", "~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect ".byte 0a2h", "~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "popad", "~{eax},~{ebp},~{ebx},~{ecx},~{edi},~{edx},~{esi},~{esp},~{dirflag},~{fpsr},~{flags}"()
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
asm|__asm align 8
asm|__asm align 16;
asm|__asm align 128;
asm|__asm ALIGN 256;
comment|// CHECK: t28
comment|// CHECK: call void asm sideeffect inteldialect ".align 3", "~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect ".align 4", "~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect ".align 7", "~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect ".align 8", "~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t29
parameter_list|()
block|{
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
asm|__asm mov osize, SIZE arr
asm|__asm mov otype, TYPE arr
comment|// CHECK: t29
comment|// CHECK: call void asm sideeffect inteldialect "mov dword ptr $0, $$2", "=*m,~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov dword ptr $0, $$8", "=*m,~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov dword ptr $0, $$4", "=*m,~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
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
block|{
name|int
modifier|*
name|res
decl_stmt|;
asm|__asm lea edi, results
asm|__asm mov res, edi
return|return
name|res
return|;
comment|// CHECK: t30
comment|// CHECK: call void asm sideeffect inteldialect "lea edi, dword ptr $0", "*m,~{edi},~{dirflag},~{fpsr},~{flags}"([2 x i32]* @{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov dword ptr $0, edi", "=*m,~{dirflag},~{fpsr},~{flags}"(i32** %{{.*}})
block|}
end_function

begin_function
name|void
name|t31
parameter_list|()
block|{
asm|__asm pushad
asm|__asm popad
comment|// CHECK: t31
comment|// CHECK: call void asm sideeffect inteldialect "pushad", "~{esp},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "popad", "~{eax},~{ebp},~{ebx},~{ecx},~{edi},~{edx},~{esi},~{esp},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t32
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
asm|__asm mov eax, i
asm|__asm mov eax, dword ptr i
asm|__asm mov ax, word ptr i
asm|__asm mov al, byte ptr i
comment|// CHECK: t32
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov ax, word ptr $0", "*m,~{ax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov al, byte ptr $0", "*m,~{al},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
block|}
end_function

begin_function
name|void
name|t33
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
asm|__asm mov eax, [i]
asm|__asm mov eax, dword ptr [i]
asm|__asm mov ax, word ptr [i]
asm|__asm mov al, byte ptr [i]
comment|// CHECK: t33
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov ax, word ptr $0", "*m,~{ax},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov al, byte ptr $0", "*m,~{al},~{dirflag},~{fpsr},~{flags}"(i32* %{{.*}})
block|}
end_function

begin_function
name|void
name|t34
parameter_list|()
block|{
asm|__asm prefetchnta 64[eax]
asm|__asm mov eax, dword ptr 4[eax]
comment|// CHECK: t34
comment|// CHECK: call void asm sideeffect inteldialect "prefetchnta $$64[eax]", "~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$4[eax]", "~{eax},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t35
parameter_list|()
block|{
asm|__asm prefetchnta [eax + (200*64)]
asm|__asm mov eax, dword ptr [eax + (200*64)]
comment|// CHECK: t35
comment|// CHECK: call void asm sideeffect inteldialect "prefetchnta [eax + ($$200*$$64)]", "~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr [eax + ($$200*$$64)]", "~{eax},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t36
parameter_list|()
block|{
name|int
name|arr
index|[
literal|4
index|]
decl_stmt|;
asm|__asm mov eax, 4[arr]
asm|__asm mov eax, 4[arr + 4]
asm|__asm mov eax, 8[arr + 4 + 32*2 - 4]
asm|__asm mov eax, 12[4 + arr]
asm|__asm mov eax, 4[4 + arr + 4]
asm|__asm mov eax, 4[64 + arr + (2*32)]
asm|__asm mov eax, 4[64 + arr - 2*32]
asm|__asm mov eax, [arr + 4]
asm|__asm mov eax, [arr + 4 + 32*2 - 4]
asm|__asm mov eax, [4 + arr]
asm|__asm mov eax, [4 + arr + 4]
asm|__asm mov eax, [64 + arr + (2*32)]
asm|__asm mov eax, [64 + arr - 2*32]
comment|// CHECK: t36
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$4$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$8$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$72$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$16$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$12$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$132$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$4$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$4$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$64$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$4$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$8$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$128$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
block|}
end_function

begin_function
name|void
name|t37
parameter_list|()
block|{
asm|__asm mov eax, 4 + 8
asm|__asm mov eax, 4 + 8 * 16
asm|__asm mov eax, -4 + 8 * 16
asm|__asm mov eax, (4 + 4) * 16
asm|__asm mov eax, 4 + 8 * -16
asm|__asm mov eax, 4 + 16 / -8
asm|__asm mov eax, (16 + 16) / -8
asm|__asm mov eax, ~15
comment|// CHECK: t37
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$12", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$132", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$124", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$128", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4294967172", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$2", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4294967292", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, $$4294967280", "~{eax},~{dirflag},~{fpsr},~{flags}"()
block|}
end_function

begin_function
name|void
name|t38
parameter_list|()
block|{
name|int
name|arr
index|[
literal|4
index|]
decl_stmt|;
asm|__asm mov eax, 4+4[arr]
asm|__asm mov eax, (4+4)[arr + 4]
asm|__asm mov eax, 8*2[arr + 4 + 32*2 - 4]
asm|__asm mov eax, 12+20[4 + arr]
asm|__asm mov eax, 4*16+4[4 + arr + 4]
asm|__asm mov eax, 4*4[64 + arr + (2*32)]
asm|__asm mov eax, 4*(4-2)[64 + arr - 2*32]
asm|__asm mov eax, 32*(4-2)[arr - 2*32]
comment|// CHECK: t38
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$8$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$12$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$80$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$36$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$76$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$144$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$8$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, dword ptr $$0$0", "*m,~{eax},~{dirflag},~{fpsr},~{flags}"([4 x i32]* %{{.*}})
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

begin_function
name|void
name|t39
parameter_list|()
block|{
asm|__asm mov eax, [eax].A.b
asm|__asm mov eax, [eax] A.b
asm|__asm mov eax, fs:[0] A.b
comment|// CHECK-LABEL: define void @t39
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, [eax].4", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, [eax] .4", "~{eax},~{dirflag},~{fpsr},~{flags}"()
comment|// CHECK: call void asm sideeffect inteldialect "mov eax, fs:[$$0] .4", "~{eax},~{dirflag},~{fpsr},~{flags}"()
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
name|int
name|i
decl_stmt|;
asm|__asm fld a
asm|__asm fistp i
comment|// CHECK-LABEL: define void @t40
comment|// CHECK: call void asm sideeffect inteldialect "fld dword ptr $0", "*m,~{dirflag},~{fpsr},~{flags}"(float* {{.*}})
comment|// CHECK: call void asm sideeffect inteldialect "fistp dword ptr $0", "=*m,~{dirflag},~{fpsr},~{flags}"(i32* {{.*}})
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
asm|__asm mov cs, a;
asm|__asm mov ds, a;
asm|__asm mov es, a;
asm|__asm mov fs, a;
asm|__asm mov gs, a;
asm|__asm mov ss, a;
comment|// CHECK-LABEL: define void @t41(i16 zeroext %a)
comment|// CHECK: [[T41_A_ADDR:%.+]] = alloca i16
comment|// CHECK: store i16 %a, i16* [[T41_A_ADDR]]
comment|// CHECK: call void asm sideeffect inteldialect "mov cs, word ptr $0", "*m,~{dirflag},~{fpsr},~{flags}"(i16* [[T41_A_ADDR]])
comment|// CHECK: call void asm sideeffect inteldialect "mov ds, word ptr $0", "*m,~{dirflag},~{fpsr},~{flags}"(i16* [[T41_A_ADDR]])
comment|// CHECK: call void asm sideeffect inteldialect "mov es, word ptr $0", "*m,~{dirflag},~{fpsr},~{flags}"(i16* [[T41_A_ADDR]])
comment|// CHECK: call void asm sideeffect inteldialect "mov fs, word ptr $0", "*m,~{dirflag},~{fpsr},~{flags}"(i16* [[T41_A_ADDR]])
comment|// CHECK: call void asm sideeffect inteldialect "mov gs, word ptr $0", "*m,~{dirflag},~{fpsr},~{flags}"(i16* [[T41_A_ADDR]])
comment|// CHECK: call void asm sideeffect inteldialect "mov ss, word ptr $0", "*m,~{dirflag},~{fpsr},~{flags}"(i16* [[T41_A_ADDR]])
block|}
end_function

end_unit

