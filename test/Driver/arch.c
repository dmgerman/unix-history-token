begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv7a-unknown-linux-gnueabi -S -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: target triple = "armv7-unknown-linux-gnueabi"
end_comment

end_unit

