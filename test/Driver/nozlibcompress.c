begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: nozlib
end_comment

begin_comment
comment|// RUN: %clang -### -fintegrated-as -gz -c %s 2>&1 | FileCheck %s -check-prefix CHECK-WARN
end_comment

begin_comment
comment|// RUN: %clang -### -fintegrated-as -gz=none -c %s 2>&1 | FileCheck -allow-empty -check-prefix CHECK-NOWARN %s
end_comment

begin_comment
comment|// CHECK-WARN: warning: cannot compress debug sections (zlib not installed)
end_comment

begin_comment
comment|// CHECK-NOWARN-NOT: warning: cannot compress debug sections (zlib not installed)
end_comment

end_unit

