begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o - | opt -std-compile-opts | \
end_comment

begin_comment
comment|// RUN:    llvm-dis | grep {foo\[12345\]} | count 5
end_comment

begin_asm
asm|__asm__ ("foo1");
end_asm

begin_asm
asm|__asm__ ("foo2");
end_asm

begin_asm
asm|__asm__ ("foo3");
end_asm

begin_asm
asm|__asm__ ("foo4");
end_asm

begin_asm
asm|__asm__ ("foo5");
end_asm

end_unit

