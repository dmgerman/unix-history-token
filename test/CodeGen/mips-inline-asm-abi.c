begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: mips-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips-linux-gnu -emit-obj -o - %s | \
end_comment

begin_comment
comment|// RUN:   llvm-readobj -h - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: EF_MIPS_ABI_O32
end_comment

begin_asm
asm|__asm__( "bar:\n" "  nop\n" );
end_asm

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

end_unit

