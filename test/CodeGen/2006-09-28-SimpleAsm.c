begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// PR924
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{
comment|// Extended asm
comment|// CHECK: call void asm sideeffect "ext: xorl %eax, eax; movl eax, fs; movl eax, gs  %blah
asm|asm
specifier|volatile
asm|("ext: xorl %%eax, eax; movl eax, fs; movl eax, gs  %%blah %= %\ % " : : "r"(1));
comment|// CHECK: call void asm sideeffect "nonext: xorl %eax, %eax; movl %eax, %fs; movl %eax, %gs  %%blah %= %%
comment|// Non-extended asm.
asm|asm
specifier|volatile
asm|("nonext: xorl %eax, %eax; movl %eax, %fs; movl %eax, %gs  %%blah %= %% ");
block|}
end_function

end_unit

