begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -arch armv7 -target thumbv7-apple-darwin-eabi -### -c %s 2>&1 | FileCheck %s --check-prefix=CHECK-AAPCS
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-macosx10.9 -arch armv7m -### -c %s 2>&1 | FileCheck %s --check-prefix=CHECK-AAPCS
end_comment

begin_comment
comment|// RUN: %clang -arch armv7s -target thumbv7-apple-ios -### -c %s 2>&1 | FileCheck %s --check-prefix=CHECK-APCS
end_comment

begin_comment
comment|// RUN: %clang -arch armv7s -target thumbv7-apple-darwin -### -c %s 2>&1 | FileCheck %s --check-prefix=CHECK-APCS
end_comment

begin_comment
comment|// RUN: %clang -arch armv6m -target thumbv7-apple-darwin -### -c %s 2>&1 | FileCheck %s --check-prefix=CHECK-MACHO-EMBEDDED
end_comment

begin_comment
comment|// RUN: %clang -arch armv7m -target thumbv7-apple-darwin -### -c %s 2>&1 | FileCheck %s --check-prefix=CHECK-MACHO-EMBEDDED
end_comment

begin_comment
comment|// RUN: %clang -arch armv7em -target thumbv7-apple-darwin -### -c %s 2>&1 | FileCheck %s --check-prefix=CHECK-MACHO-EMBEDDED
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

begin_comment
comment|// CHECK-MACHO-EMBEDDED: "-triple" "{{thumbv[67]e?m}}-apple-unknown-macho"
end_comment

begin_comment
comment|// CHECK-MACHO-EMBEDDED: "-mrelocation-model" "pic"
end_comment

end_unit

