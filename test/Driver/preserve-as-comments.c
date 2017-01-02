begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -S -fno-preserve-as-comments %s -### 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-fno-preserve-as-comments"
end_comment

end_unit

