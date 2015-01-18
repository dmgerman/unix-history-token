begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O900 -o /dev/null 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -O8 -o /dev/null 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: warning: optimization level '-O{{.*}}' is not supported; using '-O3' instead
end_comment

end_unit

