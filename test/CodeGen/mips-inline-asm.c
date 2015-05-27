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

end_unit

