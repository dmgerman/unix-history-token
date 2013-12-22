begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv7a-unknown-linux-gnueabi -S -emit-llvm %s -o - | FileCheck %s --check-prefix=V7
end_comment

begin_comment
comment|// RUN: %clang -target armv8a-unknown-linux-gnueabi -S -emit-llvm %s -o - | FileCheck %s --check-prefix=V8
end_comment

begin_comment
comment|// V7: target triple = "armv7-unknown-linux-gnueabi"
end_comment

begin_comment
comment|// V8: target triple = "armv8-unknown-linux-gnueabi"
end_comment

end_unit

