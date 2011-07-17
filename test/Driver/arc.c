begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ObjC -ccc-host-triple i386-apple-darwin9 -m32 -fobjc-arc %s -fsyntax-only 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -x objective-c -ccc-host-triple i386-apple-darwin9 -m32 -fobjc-arc %s -fsyntax-only 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -x objective-c++ -ccc-host-triple i386-apple-darwin9 -m32 -fobjc-arc %s -fsyntax-only 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -x c -ccc-host-triple i386-apple-darwin9 -m32 -fobjc-arc %s -fsyntax-only 2>&1 | FileCheck -check-prefix NOTOBJC %s
end_comment

begin_comment
comment|// RUN: %clang -x c++ -ccc-host-triple i386-apple-darwin9 -m32 -fobjc-arc %s -fsyntax-only 2>&1 | FileCheck -check-prefix NOTOBJC %s
end_comment

begin_comment
comment|// Just to test clang is working.
end_comment

begin_empty
empty|# foo
end_empty

begin_comment
comment|// CHECK: error: -fobjc-arc is not supported with fragile abi
end_comment

begin_comment
comment|// CHECK-NOT: invalid preprocessing directive
end_comment

begin_comment
comment|// NOTOBJC-NOT: error: -fobjc-arc is not supported with fragile abi
end_comment

begin_comment
comment|// NOTOBJC: invalid preprocessing directive
end_comment

end_unit

