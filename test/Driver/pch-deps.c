begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -x c-header %s -o %t.pch -MMD -MT dependencies -MF %t.d -### 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck %s -input-file=%t
end_comment

begin_comment
comment|// CHECK: -emit-pch
end_comment

begin_comment
comment|// CHECK: -dependency-file
end_comment

begin_comment
comment|// CHECK: -module-file-deps
end_comment

begin_comment
comment|// RUN: %clang -c %s -o %t -MMD -MT dependencies -MF %t.d -### 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=CHECK-NOPCH -input-file=%t
end_comment

begin_comment
comment|// CHECK-NOPCH: -dependency-file
end_comment

begin_comment
comment|// CHECK-NOPCH-NOT: -module-file-deps
end_comment

begin_comment
comment|// RUN: %clang -x c-header %s -o %t.pch -MMD -MT dependencies -MF %t.d \
end_comment

begin_comment
comment|// RUN:     -fno-module-file-deps -### 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=CHECK-EXPLICIT -input-file=%t
end_comment

begin_comment
comment|// CHECK-EXPLICIT: -dependency-file
end_comment

begin_comment
comment|// CHECK-EXPLICIT-NOT: -module-file-deps
end_comment

begin_comment
comment|// RUN: %clang -x c++ %s -o %t.o -MMD -MT dependencies -MF %t.d -fmodule-file-deps -### 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=CHECK-EXPLICIT-NOPCH -input-file=%t
end_comment

begin_comment
comment|// CHECK-EXPLICIT-NOPCH: -dependency-file
end_comment

begin_comment
comment|// CHECK-EXPLICIT-NOPCH: -module-file-deps
end_comment

end_unit

