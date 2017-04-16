begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang -cc1 -mrelocation-model tinkywinky \
end_comment

begin_comment
comment|// RUN: -emit-llvm %s 2>&1 | FileCheck -check-prefix CHECK-INVALID %s
end_comment

begin_comment
comment|// CHECK-INVALID: error: invalid value 'tinkywinky' in '-mrelocation-model tinkywinky'
end_comment

end_unit

