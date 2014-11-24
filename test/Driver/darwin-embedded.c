begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -arch armv6m -resource-dir=%S/Inputs/resource_dir %s -### 2> %t
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -arch armv7em -resource-dir=%S/Inputs/resource_dir %s -### 2>> %t
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -arch armv7em -mhard-float -resource-dir=%S/Inputs/resource_dir %s -### 2>> %t
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -arch armv7m -fPIC -resource-dir=%S/Inputs/resource_dir %s -### 2>> %t
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -arch armv7em -fPIC -mfloat-abi=hard -resource-dir=%S/Inputs/resource_dir %s -### 2>> %t
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -arch armv7em -fPIC -mfloat-abi=softfp -resource-dir=%S/Inputs/resource_dir %s -### 2>> %t
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-none-macho -arch armv7 -mhard-float -resource-dir=%S/Inputs/resource_dir %s -### 2>> %t
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-none-macho -arch armv7 -msoft-float -fPIC -resource-dir=%S/Inputs/resource_dir %s -### 2>> %t
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t
end_comment

begin_comment
comment|// ARMv6m has no float
end_comment

begin_comment
comment|// CHECK-LABEL: Target:
end_comment

begin_comment
comment|// CHECK-NOT: warning: unknown platform
end_comment

begin_comment
comment|// CHECK: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|// CHECK: libclang_rt.soft_static.a
end_comment

begin_comment
comment|// ARMv7em does, but defaults to soft
end_comment

begin_comment
comment|// CHECK-LABEL: Target:
end_comment

begin_comment
comment|// CHECK-NOT: warning: unknown platform
end_comment

begin_comment
comment|// CHECK: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|// CHECK: libclang_rt.soft_static.a
end_comment

begin_comment
comment|// Which can be overridden
end_comment

begin_comment
comment|// CHECK-LABEL: Target:
end_comment

begin_comment
comment|// CHECK-NOT: warning: unknown platform
end_comment

begin_comment
comment|// CHECK: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|// CHECK: libclang_rt.hard_static.a
end_comment

begin_comment
comment|// ARMv7m has no float either
end_comment

begin_comment
comment|// CHECK-LABEL: Target:
end_comment

begin_comment
comment|// CHECK-NOT: warning: unknown platform
end_comment

begin_comment
comment|// CHECK: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|// CHECK: libclang_rt.soft_pic.a
end_comment

begin_comment
comment|// But it can be enabled on ARMv7em
end_comment

begin_comment
comment|// CHECK-LABEL: Target:
end_comment

begin_comment
comment|// CHECK-NOT: warning: unknown platform
end_comment

begin_comment
comment|// CHECK: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|// CHECK: libclang_rt.hard_pic.a
end_comment

begin_comment
comment|// "softfp" must link against a soft-float library since that's what the
end_comment

begin_comment
comment|// callers we're compiling will expect.
end_comment

begin_comment
comment|// CHECK-LABEL: Target:
end_comment

begin_comment
comment|// CHECK-NOT: warning: unknown platform
end_comment

begin_comment
comment|// CHECK: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|// CHECK: libclang_rt.soft_pic.a
end_comment

begin_comment
comment|// -arch "armv7" (== embedded v7a) can be used in a couple of variants:
end_comment

begin_comment
comment|// CHECK-LABEL: Target:
end_comment

begin_comment
comment|// CHECK-NOT: warning: unknown platform
end_comment

begin_comment
comment|// CHECK: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|// CHECK: libclang_rt.hard_static.a
end_comment

begin_comment
comment|// CHECK-LABEL: Target:
end_comment

begin_comment
comment|// CHECK-NOT: warning: unknown platform
end_comment

begin_comment
comment|// CHECK: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|// CHECK: libclang_rt.soft_pic.a
end_comment

end_unit

