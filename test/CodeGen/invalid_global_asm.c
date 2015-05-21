begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -emit-obj -triple armv6-unknown-unknown -o %t %s 2>&1 | FileCheck %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wmissing-noreturn"
end_pragma

begin_asm
asm|__asm__(".Lfoo: movw r2, #:lower16:.Lbar - .Lfoo");
end_asm

begin_comment
comment|// CHECK:<inline asm>:1:8: error: instruction requires: armv6t2
end_comment

end_unit

