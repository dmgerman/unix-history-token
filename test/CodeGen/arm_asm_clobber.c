begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple armv6-unknown-unknown -emit-llvm -o %t %s
end_comment

begin_function
name|void
name|test0
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("mov r0, r0" :: );
block|}
end_function

begin_function
name|void
name|test1
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("mov r0, r0" ::: 				 "cc", "memory" );
block|}
end_function

begin_function
name|void
name|test2
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("mov r0, r0" ::: 				 "r0", "r1", "r2", "r3");
asm|asm
specifier|volatile
asm|("mov r0, r0" ::: 				 "r4", "r5", "r6", "r8");
block|}
end_function

begin_function
name|void
name|test3
parameter_list|(
name|void
parameter_list|)
block|{
asm|asm
specifier|volatile
asm|("mov r0, r0" ::: 				 "a1", "a2", "a3", "a4");
asm|asm
specifier|volatile
asm|("mov r0, r0" ::: 				 "v1", "v2", "v3", "v5");
block|}
end_function

end_unit

