begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=x86_64-apple-darwin9 -emit-pch -o %t.pch %S/target-options.h
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple=x86_64-unknown-freebsd7.0 -include-pch %t.pch %s -emit-llvm -o -> %t.err 2>&1
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t.err
end_comment

begin_comment
comment|// CHECK: for the target
end_comment

end_unit

