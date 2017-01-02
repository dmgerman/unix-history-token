begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-apple-darwin -target-cpu skylake-avx512 -O0  -S -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_comment
comment|// This test checks validity of inline assembly using curly brackets syntax
end_comment

begin_comment
comment|// for extended inline asm.
end_comment

begin_function
name|void
name|test_curly_brackets
parameter_list|()
block|{
comment|//CHECK:  %xmm1,%xmm0,%xmm1 {%k1}{z}
asm|asm("vpaddb\t %%xmm1,%%xmm0,%%xmm1 %{%%k1%}%{z%}\t":::);
block|}
end_function

end_unit

