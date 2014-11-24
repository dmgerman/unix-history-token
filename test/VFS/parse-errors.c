begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -ivfsoverlay %S/Inputs/invalid-yaml.yaml -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: invalid virtual filesystem overlay file
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -ivfsoverlay %S/Inputs/missing-key.yaml -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-MISSING-TYPE %s
end_comment

begin_comment
comment|// CHECK-MISSING-TYPE: missing key 'type'
end_comment

begin_comment
comment|// CHECK-MISSING-TYPE: invalid virtual filesystem overlay file
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -ivfsoverlay %S/Inputs/unknown-key.yaml -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-UNKNOWN-KEY %s
end_comment

begin_comment
comment|// CHECK-UNKNOWN-KEY: unknown key
end_comment

begin_comment
comment|// CHECK-UNKNOWN-KEY: invalid virtual filesystem overlay file
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -ivfsoverlay %S/Inputs/unknown-value.yaml -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-UNKNOWN-VALUE %s
end_comment

begin_comment
comment|// CHECK-UNKNOWN-VALUE: expected boolean value
end_comment

begin_comment
comment|// CHECK-UNKNOWN-VALUE: invalid virtual filesystem overlay file
end_comment

end_unit

