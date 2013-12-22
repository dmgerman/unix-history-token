begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Don't attempt slash switches on msys bash.
end_comment

begin_comment
comment|// REQUIRES: shell-preserves-root
end_comment

begin_comment
comment|// Note: %s must be preceded by --, otherwise it may be interpreted as a
end_comment

begin_comment
comment|// command-line option, e.g. on Mac where %s is commonly under /Users.
end_comment

begin_comment
comment|// First check that regular clang doesn't do any of this stuff.
end_comment

begin_comment
comment|// RUN: %clang -### %s 2>&1 | FileCheck -check-prefix=CHECK-CLANG %s
end_comment

begin_comment
comment|// CHECK-CLANG-NOT: "-D_DEBUG"
end_comment

begin_comment
comment|// CHECK-CLANG-NOT: "-D_MT"
end_comment

begin_comment
comment|// CHECK-CLANG-NOT: "-D_DLL"
end_comment

begin_comment
comment|// CHECK-CLANG-NOT: --dependent-lib
end_comment

begin_comment
comment|// RUN: %clang_cl -### -- %s 2>&1 | FileCheck -check-prefix=CHECK-MT %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /MT -- %s 2>&1 | FileCheck -check-prefix=CHECK-MT %s
end_comment

begin_comment
comment|// CHECK-MT-NOT: "-D_DEBUG"
end_comment

begin_comment
comment|// CHECK-MT: "-D_MT"
end_comment

begin_comment
comment|// CHECK-MT-NOT: "-D_DLL"
end_comment

begin_comment
comment|// CHECK-MT: "--dependent-lib=libcmt"
end_comment

begin_comment
comment|// CHECK-MT: "--dependent-lib=oldnames"
end_comment

begin_comment
comment|// RUN: %clang_cl -### /MTd -- %s 2>&1 | FileCheck -check-prefix=CHECK-MTd %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /LD /MTd -- %s 2>&1 | FileCheck -check-prefix=CHECK-MTd %s
end_comment

begin_comment
comment|// CHECK-MTd: "-D_DEBUG"
end_comment

begin_comment
comment|// CHECK-MTd: "-D_MT"
end_comment

begin_comment
comment|// CHECK-MTd-NOT: "-D_DLL"
end_comment

begin_comment
comment|// CHECK-MTd: "--dependent-lib=libcmtd"
end_comment

begin_comment
comment|// CHECK-MTd: "--dependent-lib=oldnames"
end_comment

begin_comment
comment|// RUN: %clang_cl -### /MD -- %s 2>&1 | FileCheck -check-prefix=CHECK-MD %s
end_comment

begin_comment
comment|// CHECK-MD-NOT: "-D_DEBUG"
end_comment

begin_comment
comment|// CHECK-MD: "-D_MT"
end_comment

begin_comment
comment|// CHECK-MD: "-D_DLL"
end_comment

begin_comment
comment|// CHECK-MD: "--dependent-lib=msvcrt"
end_comment

begin_comment
comment|// CHECK-MD: "--dependent-lib=oldnames"
end_comment

begin_comment
comment|// RUN: %clang_cl -### /MDd -- %s 2>&1 | FileCheck -check-prefix=CHECK-MDd %s
end_comment

begin_comment
comment|// CHECK-MDd: "-D_DEBUG"
end_comment

begin_comment
comment|// CHECK-MDd: "-D_MT"
end_comment

begin_comment
comment|// CHECK-MDd: "-D_DLL"
end_comment

begin_comment
comment|// CHECK-MDd: "--dependent-lib=msvcrtd"
end_comment

begin_comment
comment|// CHECK-MDd: "--dependent-lib=oldnames"
end_comment

begin_comment
comment|// RUN: %clang_cl -### /LD -- %s 2>&1 | FileCheck -check-prefix=CHECK-LD %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /LD /MT -- %s 2>&1 | FileCheck -check-prefix=CHECK-LD %s
end_comment

begin_comment
comment|// CHECK-LD-NOT: "-D_DEBUG"
end_comment

begin_comment
comment|// CHECK-LD: "-D_MT"
end_comment

begin_comment
comment|// CHECK-LD-NOT: "-D_DLL"
end_comment

begin_comment
comment|// CHECK-LD: "--dependent-lib=libcmt"
end_comment

begin_comment
comment|// RUN: %clang_cl -### /LDd -- %s 2>&1 | FileCheck -check-prefix=CHECK-LDd %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /LDd /MTd -- %s 2>&1 | FileCheck -check-prefix=CHECK-LDd %s
end_comment

begin_comment
comment|// CHECK-LDd: "-D_DEBUG"
end_comment

begin_comment
comment|// CHECK-LDd: "-D_MT"
end_comment

begin_comment
comment|// CHECK-LDd-NOT: "-D_DLL"
end_comment

begin_comment
comment|// CHECK-LDd: "--dependent-lib=libcmtd"
end_comment

begin_comment
comment|// RUN: %clang_cl -### /LDd /MT -- %s 2>&1 | FileCheck -check-prefix=CHECK-LDdMT %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /MT /LDd -- %s 2>&1 | FileCheck -check-prefix=CHECK-LDdMT %s
end_comment

begin_comment
comment|// CHECK-LDdMT: "-D_DEBUG"
end_comment

begin_comment
comment|// CHECK-LDdMT: "-D_MT"
end_comment

begin_comment
comment|// CHECK-LDdMT-NOT: "-D_DLL"
end_comment

begin_comment
comment|// CHECK-LDdMT: "--dependent-lib=libcmt"
end_comment

begin_comment
comment|// RUN: %clang_cl -### /LD /MD -- %s 2>&1 | FileCheck -check-prefix=CHECK-LDMD %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /MD /LD -- %s 2>&1 | FileCheck -check-prefix=CHECK-LDMD %s
end_comment

begin_comment
comment|// CHECK-LDMD-NOT: "-D_DEBUG"
end_comment

begin_comment
comment|// CHECK-LDMD: "-D_MT"
end_comment

begin_comment
comment|// CHECK-LDMD: "-D_DLL"
end_comment

begin_comment
comment|// CHECK-LDMD: "--dependent-lib=msvcrt"
end_comment

begin_comment
comment|// RUN: %clang_cl -### /LDd /MD -- %s 2>&1 | FileCheck -check-prefix=CHECK-LDdMD %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /MD /LDd -- %s 2>&1 | FileCheck -check-prefix=CHECK-LDdMD %s
end_comment

begin_comment
comment|// CHECK-LDdMD: "-D_DEBUG"
end_comment

begin_comment
comment|// CHECK-LDdMD: "-D_MT"
end_comment

begin_comment
comment|// CHECK-LDdMD: "-D_DLL"
end_comment

begin_comment
comment|// CHECK-LDdMD: "--dependent-lib=msvcrt"
end_comment

begin_comment
comment|// RUN: %clang_cl -### /LD /MDd -- %s 2>&1 | FileCheck -check-prefix=CHECK-LDMDd %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /MDd /LD -- %s 2>&1 | FileCheck -check-prefix=CHECK-LDMDd %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /LDd /MDd -- %s 2>&1 | FileCheck -check-prefix=CHECK-LDMDd %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /MDd /LDd -- %s 2>&1 | FileCheck -check-prefix=CHECK-LDMDd %s
end_comment

begin_comment
comment|// CHECK-LDMDd: "-D_DEBUG"
end_comment

begin_comment
comment|// CHECK-LDMDd: "-D_MT"
end_comment

begin_comment
comment|// CHECK-LDMDd: "-D_DLL"
end_comment

begin_comment
comment|// CHECK-LDMDd: "--dependent-lib=msvcrtd"
end_comment

begin_comment
comment|// RUN: %clang_cl /MD /MT -### -- %s 2>&1 | FileCheck -check-prefix=MTOVERRIDE %s
end_comment

begin_comment
comment|// MTOVERRIDE: "--dependent-lib=libcmt"
end_comment

end_unit

