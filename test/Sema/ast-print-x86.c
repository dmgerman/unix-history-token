begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-elf %s -ast-print | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_function
name|void
name|assembly
parameter_list|()
block|{
name|int
name|added
decl_stmt|;
comment|// CHECK: asm volatile ("addl %%ebx,%%eax" : "=a" (added) : "a" (1), "b" (2));
asm|__asm__
specifier|__volatile__
asm|("addl %%ebx,%%eax" : "=a" (added) : "a" (1), "b" (2) );
block|}
end_function

end_unit

