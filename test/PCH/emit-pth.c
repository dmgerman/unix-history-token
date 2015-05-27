begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-pth -o %t1 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-pth -o - %s> %t2
end_comment

begin_comment
comment|// RUN: cmp %t1 %t2
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-pth -o - %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s
end_comment

begin_comment
comment|// CHECK: cfe-pth
end_comment

end_unit

