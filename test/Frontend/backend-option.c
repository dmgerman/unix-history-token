begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -backend-option -time-passes -o - 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -backend-option -time-passes -o - -triple spir-unknown-unknown 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: Pass execution timing report
end_comment

end_unit

