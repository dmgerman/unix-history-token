begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple i386-apple-darwin10 -fasm-blocks -emit-llvm -o - | opt -strip -S | FileCheck %s
end_comment

begin_comment
comment|// Some test cases for MS inline asm support from Mozilla code base.
end_comment

begin_function
name|void
name|invoke_copy_to_stack
parameter_list|()
block|{}
end_function

begin_function
name|void
name|invoke
parameter_list|(
name|void
modifier|*
name|that
parameter_list|,
name|unsigned
name|methodIndex
parameter_list|,
name|unsigned
name|paramCount
parameter_list|,
name|void
modifier|*
name|params
parameter_list|)
block|{
comment|// CHECK: @invoke
comment|// CHECK: %5 = alloca i8*, align 4
comment|// CHECK: %6 = alloca i32, align 4
comment|// CHECK: %7 = alloca i32, align 4
comment|// CHECK: %8 = alloca i8*, align 4
comment|// CHECK: store i8* %0, i8** %5, align 4
comment|// CHECK: store i32 %1, i32* %6, align 4
comment|// CHECK: store i32 %2, i32* %7, align 4
comment|// CHECK: store i8* %3, i8** %8, align 4
comment|// CHECK: call void asm sideeffect inteldialect
comment|// CHECK: mov edx,dword ptr $1
comment|// CHECK: test edx,edx
comment|// CHECK: jz {{[^_]*}}__MSASMLABEL_.0__noparams
comment|//             ^ Can't use {{.*}} here because the matching is greedy.
comment|// CHECK: mov eax,edx
comment|// CHECK: shl eax,$$3
comment|// CHECK: sub esp,eax
comment|// CHECK: mov ecx,esp
comment|// CHECK: push dword ptr $0
comment|// CHECK: call dword ptr $2
comment|// CHECK: {{.*}}__MSASMLABEL_.0__noparams:
comment|// CHECK: mov ecx,dword ptr $3
comment|// CHECK: push ecx
comment|// CHECK: mov edx,[ecx]
comment|// CHECK: mov eax,dword ptr $4
comment|// CHECK: call dword ptr[edx+eax*$$4]
comment|// CHECK: mov esp,ebp
comment|// CHECK: pop ebp
comment|// CHECK: ret
comment|// CHECK: "=*m,*m,*m,*m,*m,~{eax},~{ebp},~{ecx},~{edx},~{flags},~{esp},~{dirflag},~{fpsr},~{flags}"
comment|// CHECK: (i8** %8, i32* %7, void (...)* bitcast (void ()* @invoke_copy_to_stack to void (...)*), i8** %5, i32* %6)
comment|// CHECK: ret void
asm|__asm {
asm|mov     edx,paramCount
asm|test    edx,edx
asm|jz      noparams
asm|mov     eax,edx
asm|shl     eax,3
asm|sub     esp,eax
asm|mov     ecx,esp
asm|push    params
asm|call    invoke_copy_to_stack
asm|noparams:
asm|mov     ecx,that
asm|push    ecx
asm|mov     edx,[ecx]
asm|mov     eax,methodIndex
asm|call    dword ptr[edx+eax*4]
asm|mov     esp,ebp
asm|pop     ebp
asm|ret
asm|}
block|}
end_function

end_unit

