begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: system-darwin
end_comment

begin_comment
comment|// Ensure that we never pick a version that's based on the SDK that's newer than
end_comment

begin_comment
comment|// the system version:
end_comment

begin_comment
comment|// RUN: rm -rf %t/SDKs/MacOSX10.99.99.sdk
end_comment

begin_comment
comment|// RUN: mkdir -p %t/SDKs/MacOSX10.99.99.sdk
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -isysroot %t/SDKs/MacOSX10.99.99.sdk %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MACOSX-SYSTEM-VERSION %s
end_comment

begin_comment
comment|// CHECK-MACOSX-SYSTEM-VERSION-NOT: 10.99.99"
end_comment

end_unit

