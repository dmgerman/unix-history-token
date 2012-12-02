begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm-unknown-linux-gnueabi \
end_comment

begin_comment
comment|// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips-unknown-linux \
end_comment

begin_comment
comment|// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-unknown-linux \
end_comment

begin_comment
comment|// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-unknown-linux-gnueabi \
end_comment

begin_comment
comment|// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only -x c++ %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips-unknown-linux \
end_comment

begin_comment
comment|// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only -x c++ %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-unknown-linux \
end_comment

begin_comment
comment|// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only -x c++ %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:   -isystem %S/Inputs/include -ffreestanding -fsyntax-only -x c++ %s
end_comment

begin_include
include|#
directive|include
file|"unwind.h"
end_include

end_unit

