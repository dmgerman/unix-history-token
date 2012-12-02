begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -x objective-c -target i386-apple-darwin10 -arch i386 -mios-simulator-version-min=4.2.1 -fobjc-arc -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-OPTIONS1 %s
end_comment

begin_comment
comment|// RUN: %clang -### -x objective-c -target i386-apple-darwin10 -arch i386 -mios-simulator-version-min=5.0.0 -fobjc-arc -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-OPTIONS2 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-OPTIONS1: i386-apple-ios4.2.1
end_comment

begin_comment
comment|// CHECK-OPTIONS1: -fobjc-runtime=ios-4.2.1
end_comment

begin_comment
comment|// CHECK-OPTIONS2: i386-apple-ios5.0.0
end_comment

begin_comment
comment|// CHECK-OPTIONS2: -fobjc-runtime=ios-5.0.0
end_comment

end_unit

