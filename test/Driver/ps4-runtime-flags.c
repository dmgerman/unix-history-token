begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Test the profile runtime library to be linked for PS4 compiler.
end_comment

begin_comment
comment|// Check PS4 runtime flag --dependent-lib which does not append the default library search path.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-scei-ps4 --coverage %s -### 2>&1 | FileCheck --check-prefix=CHECK-PS4-PROFILE %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-scei-ps4 -fprofile-arcs %s -### 2>&1 | FileCheck --check-prefix=CHECK-PS4-PROFILE %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-scei-ps4 -fno-profile-arcs -fprofile-arcs %s -### 2>&1 | FileCheck --check-prefix=CHECK-PS4-PROFILE %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-scei-ps4 -fno-profile-arcs %s -### 2>&1 | FileCheck -check-prefix=CHECK-PS4-NO-PROFILE %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-scei-ps4 -fprofile-arcs -fno-profile-arcs %s -### 2>&1 | FileCheck --check-prefix=CHECK-PS4-NO-PROFILE %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-scei-ps4 -fprofile-generate %s -### 2>&1 | FileCheck --check-prefix=CHECK-PS4-PROFILE %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-scei-ps4 -fno-profile-generate %s -### 2>&1 | FileCheck --check-prefix=CHECK-PS4-NO-PROFILE %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-scei-ps4 -fprofile-generate=dir %s -### 2>&1 | FileCheck --check-prefix=CHECK-PS4-PROFILE %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-scei-ps4 -fprofile-instr-generate %s -### 2>&1 | FileCheck --check-prefix=CHECK-PS4-PROFILE %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-scei-ps4 -fno-profile-instr-generate %s -### 2>&1 | FileCheck --check-prefix=CHECK-PS4-NO-PROFILE %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-scei-ps4 -fprofile-instr-generate=somefile.profraw %s -### 2>&1 | FileCheck --check-prefix=CHECK-PS4-PROFILE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-PS4-PROFILE: "--dependent-lib=libclang_rt.profile-x86_64.a"
end_comment

begin_comment
comment|// CHECK-PS4-NO-PROFILE-NOT: "--dependent-lib=libclang_rt.profile-x86_64.a"
end_comment

end_unit

