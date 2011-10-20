begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: module asm "foo1"
end_comment

begin_asm
asm|__asm__ ("foo1");
end_asm

begin_comment
comment|// CHECK: module asm "foo2"
end_comment

begin_asm
asm|__asm__ ("foo2");
end_asm

begin_comment
comment|// CHECK: module asm "foo3"
end_comment

begin_asm
asm|__asm__ ("foo3");
end_asm

begin_comment
comment|// CHECK: module asm "foo4"
end_comment

begin_asm
asm|__asm__ ("foo4");
end_asm

begin_comment
comment|// CHECK: module asm "foo5"
end_comment

begin_asm
asm|__asm__ ("foo5");
end_asm

end_unit

