begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -c -fveclib=none %s 2>&1 | FileCheck -check-prefix CHECK-NOLIB %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -fveclib=Accelerate %s 2>&1 | FileCheck -check-prefix CHECK-ACCELERATE %s
end_comment

begin_comment
comment|// RUN: not %clang -c -fveclib=something %s 2>&1 | FileCheck -check-prefix CHECK-INVALID %s
end_comment

begin_comment
comment|// CHECK-NOLIB: "-fveclib=none"
end_comment

begin_comment
comment|// CHECK-ACCELERATE: "-fveclib=Accelerate"
end_comment

begin_comment
comment|// CHECK-INVALID: error: invalid value 'something' in '-fveclib=something'
end_comment

begin_comment
comment|// RUN: %clang -fveclib=Accelerate %s -target arm64-apple-ios8.0.0 -### 2>&1 | FileCheck --check-prefix=CHECK-LINK %s
end_comment

begin_comment
comment|// CHECK-LINK: "-framework" "Accelerate"
end_comment

begin_comment
comment|// RUN: %clang -fveclib=Accelerate %s -nostdlib -target arm64-apple-ios8.0.0 -### 2>&1 | FileCheck --check-prefix=CHECK-LINK-NOSTDLIB %s
end_comment

begin_comment
comment|// CHECK-LINK-NOSTDLIB-NOT: "-framework" "Accelerate"
end_comment

begin_comment
comment|// RUN: %clang -fveclib=Accelerate %s -nodefaultlibs -target arm64-apple-ios8.0.0 -### 2>&1 | FileCheck --check-prefix=CHECK-LINK-NODEFAULTLIBS %s
end_comment

begin_comment
comment|// CHECK-LINK-NODEFAULTLIBS-NOT: "-framework" "Accelerate"
end_comment

end_unit

