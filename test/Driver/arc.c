begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang -ObjC -target i386-apple-darwin10 -m32 -fobjc-arc %s -fsyntax-only 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang -x objective-c -target i386-apple-darwin10 -m32 -fobjc-arc %s -fsyntax-only 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang -x objective-c++ -target i386-apple-darwin10 -m32 -fobjc-arc %s -fsyntax-only 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang -x c -target i386-apple-darwin10 -m32 -fobjc-arc %s -fsyntax-only 2>&1 | FileCheck -check-prefix NOTOBJC %s
end_comment

begin_comment
comment|// RUN: not %clang -x c++ -target i386-apple-darwin10 -m32 -fobjc-arc %s -fsyntax-only 2>&1 | FileCheck -check-prefix NOTOBJC %s
end_comment

begin_comment
comment|// RUN: not %clang -x objective-c -target x86_64-apple-darwin11 -mmacosx-version-min=10.5 -fobjc-arc %s -fsyntax-only 2>&1 | FileCheck -check-prefix UNSUPPORTED %s
end_comment

begin_comment
comment|// Just to test clang is working.
end_comment

begin_empty
empty|# foo
end_empty

begin_comment
comment|// CHECK: error: -fobjc-arc is not supported on platforms using the legacy runtime
end_comment

begin_comment
comment|// CHECK-NOT: invalid preprocessing directive
end_comment

begin_comment
comment|// NOTOBJC-NOT: error: -fobjc-arc is not supported on platforms using the legacy runtime
end_comment

begin_comment
comment|// NOTOBJC: invalid preprocessing directive
end_comment

begin_comment
comment|// UNSUPPORTED: error: -fobjc-arc is not supported on versions of OS X prior to 10.6
end_comment

end_unit

