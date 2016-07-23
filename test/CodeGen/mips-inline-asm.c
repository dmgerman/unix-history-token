begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: mips-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_decl_stmt
name|int
name|data
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|m
parameter_list|()
block|{
asm|asm("lw $1, %0" :: "m"(data));
comment|// CHECK: call void asm sideeffect "lw $$1, $0", "*m,~{$1}"(i32* @data)
block|}
end_function

begin_function
name|void
name|ZC
parameter_list|()
block|{
asm|asm("ll $1, %0" :: "ZC"(data));
comment|// CHECK: call void asm sideeffect "ll $$1, $0", "*^ZC,~{$1}"(i32* @data)
block|}
end_function

begin_function
name|void
name|R
parameter_list|()
block|{
asm|asm("lw $1, %0" :: "R"(data));
comment|// CHECK: call void asm sideeffect "lw $$1, $0", "*R,~{$1}"(i32* @data)
block|}
end_function

begin_function
name|int
name|additionalClobberedRegisters
parameter_list|()
block|{
name|int
name|temp0
decl_stmt|;
asm|asm
specifier|volatile
asm|(                 "mfhi %[temp0], $ac1 \n\t"                   : [temp0]"=&r"(temp0)                   :                   : "memory", "t0", "t1", "$ac1hi", "$ac1lo", "$ac2hi", "$ac2lo", "$ac3hi", "$ac3lo"   );
return|return
literal|0
return|;
comment|// CHECK: call i32 asm sideeffect "mfhi $0, $$ac1 \0A\09", "=&r,~{memory},~{$8},~{$9},~{$ac1hi},~{$ac1lo},~{$ac2hi},~{$ac2lo},~{$ac3hi},~{$ac3lo},~{$1}"
block|}
end_function

end_unit

