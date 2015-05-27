begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux -S -ffunction-sections -fdata-sections -fno-unique-section-names  -o -< %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux -S -ffunction-sections -fdata-sections -o -< %s | FileCheck %s --check-prefix=UNIQUE
end_comment

begin_decl_stmt
specifier|const
name|int
name|hello
init|=
literal|123
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|world
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: .section .text,"ax",@progbits,unique
end_comment

begin_comment
comment|// CHECK: .section .rodata,"a",@progbits,unique
end_comment

begin_comment
comment|// UNIQUE: .section .text.world,"ax",@progbits
end_comment

begin_comment
comment|// UNIQUE: .section .rodata.hello,"a",@progbits
end_comment

end_unit

