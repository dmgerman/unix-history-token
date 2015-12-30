begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -meabi 4 -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-EABI4 %s
end_comment

begin_comment
comment|// RUN: %clang %s -meabi 5 -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-EABI5 %s
end_comment

begin_comment
comment|// RUN: %clang %s -meabi gnu -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-GNUEABI %s
end_comment

begin_comment
comment|// RUN: not %clang %s -meabi unknown 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-UNKNOWN %s
end_comment

begin_comment
comment|// CHECK-EABI4: "-meabi" "4"
end_comment

begin_comment
comment|// CHECK-EABI5: "-meabi" "5"
end_comment

begin_comment
comment|// CHECK-GNUEABI: "-meabi" "gnu"
end_comment

begin_comment
comment|// CHECK-UNKNOWN: error: invalid value 'unknown' in '-meabi unknown'
end_comment

end_unit

