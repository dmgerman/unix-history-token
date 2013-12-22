begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang -c -gstabs %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang -c -gstabs+ %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang -c -gcoff %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang -c -gxcoff %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang -c -gxcoff+ %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang -c -gvms %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang -c -gstabs1 %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang -c -gcoff2 %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang -c -gxcoff3 %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang -c -gvms0 %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang -c -gtoggle %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: error: unsupported option
end_comment

end_unit

