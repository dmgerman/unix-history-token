begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -arch armv7 -target thumbv7-apple-darwin-eabi -### -c %s 2>&1 | FileCheck %s --check-prefix=CHECK-AAPCS
end_comment

begin_comment
comment|// RUN: %clang -arch armv7s -target thumbv7-apple-ios -### -c %s 2>&1 | FileCheck %s --check-prefix=CHECK-APCS
end_comment

begin_comment
comment|// RUN: %clang -arch armv7s -target thumbv7-apple-darwin -### -c %s 2>&1 | FileCheck %s --check-prefix=CHECK-APCS
end_comment

begin_comment
comment|// RUN: %clang -arch armv6m -target thumbv7-apple-darwin -### -c %s 2>&1 | FileCheck %s --check-prefix=CHECK-DARWIN-EABI
end_comment

begin_comment
comment|// RUN: %clang -arch armv7m -target thumbv7-apple-darwin -### -c %s 2>&1 | FileCheck %s --check-prefix=CHECK-DARWIN-EABI
end_comment

begin_comment
comment|// RUN: %clang -arch armv7em -target thumbv7-apple-darwin -### -c %s 2>&1 | FileCheck %s --check-prefix=CHECK-DARWIN-EABI
end_comment

begin_comment
comment|// CHECK-DARWIN-EABI: "-triple" "{{thumbv[67]e?m}}-apple-darwin-eabi"
end_comment

begin_comment
comment|// CHECK-IOS: "-triple" "thumbv7" "thumbv7-apple-ios
end_comment

begin_comment
comment|// CHECK-AAPCS: "-target-abi" "aapcs"
end_comment

begin_comment
comment|// CHECK-APCS: "-target-abi" "apcs-gnu"
end_comment

end_unit

