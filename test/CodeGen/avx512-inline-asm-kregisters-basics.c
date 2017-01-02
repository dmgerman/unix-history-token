begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O0 -triple=x86_64-apple-darwin -target-cpu skylake-avx512 -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_comment
comment|// This test checks basic inline assembly recognition of k0-k7 registers for avx512.
end_comment

begin_function
name|void
name|test_basic_inline_asm_with_k_regs
parameter_list|()
block|{
comment|//CHECK: kandw %k1, %k2, %k3
asm|asm("kandw %k1, %k2, %k3\t");
comment|//CHECK: kandw %k4, %k5, %k6
asm|asm("kandw %k4, %k5, %k6\t");
comment|//CHECK: kandw %k7, %k0, %k1
asm|asm("kandw %k7, %k0, %k1\t");
block|}
end_function

end_unit

