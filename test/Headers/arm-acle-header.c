begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7-eabi -target-cpu cortex-a15 -fsyntax-only -ffreestanding %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-eabi -target-cpu cortex-a53 -fsyntax-only -ffreestanding %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-windows -target-cpu cortex-a53 -fsyntax-only -ffreestanding %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -triple armv7-eabi -target-cpu cortex-a15 -fsyntax-only -ffreestanding %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -triple aarch64-eabi -target-cpu cortex-a57 -fsyntax-only -ffreestanding %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c++ -triple thumbv7-windows -target-cpu cortex-a15 -fsyntax-only -ffreestanding %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_include
include|#
directive|include
file|<arm_acle.h>
end_include

end_unit

