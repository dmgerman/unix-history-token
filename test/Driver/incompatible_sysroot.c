begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -Wincompatible-sysroot -isysroot SDKs/MacOSX10.9.sdk -mios-version-min=9.0 -S -o - %s 2>&1 | FileCheck -check-prefix CHECK-OSX-IOS %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64-apple-darwin -Wincompatible-sysroot -isysroot SDKs/iPhoneOS9.2.sdk -mwatchos-version-min=2.0 -S -o - %s 2>&1 | FileCheck -check-prefix CHECK-IOS-WATCHOS %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64-apple-darwin -Wincompatible-sysroot -isysroot SDKs/iPhoneOS9.2.sdk -mtvos-version-min=9.0 -S -o - %s 2>&1 | FileCheck -check-prefix CHECK-IOS-TVOS %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -Wincompatible-sysroot -isysroot SDKs/iPhoneSimulator9.2.sdk -mios-version-min=9.0 -S -o - %s 2>&1 | FileCheck -check-prefix CHECK-IOS-IOSSIM %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -Wno-incompatible-sysroot -isysroot SDKs/MacOSX10.9.sdk -mios-version-min=9.0 -S -o - %s 2>&1 | FileCheck -check-prefix CHECK-OSX-IOS-DISABLED %s
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-OSX-IOS: warning: using sysroot for 'MacOSX' but targeting 'iPhone'
end_comment

begin_comment
comment|// CHECK-IOS-WATCHOS: warning: using sysroot for 'iPhoneOS' but targeting 'Watch'
end_comment

begin_comment
comment|// CHECK-IOS-TVOS: warning: using sysroot for 'iPhoneOS' but targeting 'AppleTV'
end_comment

begin_comment
comment|// CHECK-IOS-IOSSIM-NOT: warning: using sysroot for '{{.*}}' but targeting '{{.*}}'
end_comment

begin_comment
comment|// CHECK-OSX-IOS-DISABLED-NOT: warning: using sysroot for '{{.*}}' but targeting '{{.*}}'
end_comment

end_unit

