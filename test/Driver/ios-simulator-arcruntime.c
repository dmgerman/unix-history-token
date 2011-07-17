begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -x objective-c -ccc-host-triple i386-apple-darwin10 -arch i386 -mmacosx-version-min=10.6 -D__IPHONE_OS_VERSION_MIN_REQUIRED=40201 -fobjc-arc -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-OPTIONS1 %s
end_comment

begin_comment
comment|// RUN: %clang -### -x objective-c -ccc-host-triple i386-apple-darwin10 -arch i386 -mmacosx-version-min=10.6 -D__IPHONE_OS_VERSION_MIN_REQUIRED=50000 -fobjc-arc -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-OPTIONS2 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-OPTIONS1-NOT: -fobjc-runtime-has-weak
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fobjc-runtime-has-weak
end_comment

end_unit

