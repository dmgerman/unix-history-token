begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -O0 -o - | FileCheck %s
end_comment

begin_comment
comment|// pr6552
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// XTARGET: arm
end_comment

begin_function_decl
specifier|extern
name|void
name|bar
parameter_list|(
name|unsigned
name|int
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: mov r0, r12
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
specifier|register
name|unsigned
name|int
name|ip
asm|__asm ("ip");
name|bar
argument_list|(
name|ip
argument_list|)
decl_stmt|;
block|}
end_function

end_unit

