begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -fsyntax-only -isysroot /FOO %s 2>&1 | FileCheck --check-prefix=CHECK-SHOW-OPTION-NAMES %s
end_comment

begin_comment
comment|// CHECK-SHOW-OPTION-NAMES: warning: no such sysroot directory: '{{([A-Za-z]:.*)?}}/FOO' [-Wmissing-sysroot]
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -fsyntax-only -fno-diagnostics-show-option -isysroot /FOO %s 2>&1 | FileCheck --check-prefix=CHECK-NO-SHOW-OPTION-NAMES %s
end_comment

begin_comment
comment|// CHECK-NO-SHOW-OPTION-NAMES: warning: no such sysroot directory: '{{([A-Za-z]:.*)?}}/FOO'{{$}}
end_comment

end_unit

