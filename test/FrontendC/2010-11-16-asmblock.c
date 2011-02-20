begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -fasm-blocks -o - | FileCheck %s
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// XTARGET: x86,i386,i686
end_comment

begin_comment
comment|// 84282548
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
comment|// CHECK:  %0 = call i32 asm sideeffect "", "={ecx}"() nounwind
comment|// CHECK:  %asmtmp = call i32 asm sideeffect alignstack "sall $$3, $0", "={ecx},{ecx},~{dirflag},~{fpsr},~{flags},~{memory}"(i32 %0) nounwind
comment|// CHECK:  store i32 %asmtmp, i32* %"%ecx"
asm|__asm {
asm|sal ecx, 3;
asm|add esi, ecx;
asm|add edi, ecx;
asm|}
block|}
end_function

end_unit

