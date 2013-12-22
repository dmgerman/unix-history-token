begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-pth -o %t %S/pth.h
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple i386-unknown-unknown -include-pth %t -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_error
error|#
directive|error
error|This is the only diagnostic
end_error

begin_comment
comment|// CHECK: This is the only diagnostic
end_comment

begin_comment
comment|// CHECK: 1 error generated.
end_comment

end_unit

