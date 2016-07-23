begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Tests that make sure armv7k is mapped to the correct CPU and ABI choices
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-macosx10.9 -arch armv7k -c %s -### 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-cc1"{{.*}} "-target-cpu" "cortex-a7"
end_comment

begin_comment
comment|// CHECK-NOT: "-fsjlj-exceptions"
end_comment

begin_comment
comment|// "thumbv7k-apple-ios" is a bit of a weird triple, but since the backend is
end_comment

begin_comment
comment|// going to choose to use dwarf-based exceptions for it, the front-end needs to
end_comment

begin_comment
comment|// match.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-macosx10.9 -arch armv7k -miphoneos-version-min=9.0 -c %s -### 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-macosx10.9 -arch armv7 -mwatchos-version-min=9.0 -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-SJLJ
end_comment

begin_comment
comment|// CHECK-SJLJ: "-fsjlj-exceptions"
end_comment

end_unit

