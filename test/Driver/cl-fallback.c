begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Note: %s must be preceded by --, otherwise it may be interpreted as a
end_comment

begin_comment
comment|// command-line option, e.g. on Mac where %s is commonly under /Users.
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i686-pc-win32 /fallback /Dfoo=bar /Ubaz /Ifoo /O0 /Ox /GR /GR- /GS /GS- /Gy /Gy- \
end_comment

begin_comment
comment|// RUN:   /Gw /Gw- /LD /LDd /EHs /EHs- /Zl /MD /MDd /MTd /MT /FImyheader.h /Zi \
end_comment

begin_comment
comment|// RUN:   -garbage -moregarbage \
end_comment

begin_comment
comment|// RUN:   -### -- %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-fdiagnostics-format" "msvc-fallback"
end_comment

begin_comment
comment|// CHECK: ||
end_comment

begin_comment
comment|// CHECK: cl.exe
end_comment

begin_comment
comment|// CHECK: "/nologo"
end_comment

begin_comment
comment|// CHECK: "/c"
end_comment

begin_comment
comment|// CHECK: "/W0"
end_comment

begin_comment
comment|// CHECK: "-D" "foo=bar"
end_comment

begin_comment
comment|// CHECK: "-U" "baz"
end_comment

begin_comment
comment|// CHECK: "-I" "foo"
end_comment

begin_comment
comment|// CHECK: "/Oi"
end_comment

begin_comment
comment|// CHECK: "/Og"
end_comment

begin_comment
comment|// CHECK: "/Ot"
end_comment

begin_comment
comment|// CHECK: "/Ob2"
end_comment

begin_comment
comment|// CHECK: "/Oy"
end_comment

begin_comment
comment|// CHECK: "/GF"
end_comment

begin_comment
comment|// CHECK: "/GR-"
end_comment

begin_comment
comment|// CHECK: "/GS-"
end_comment

begin_comment
comment|// CHECK: "/Gy-"
end_comment

begin_comment
comment|// CHECK: "/Gw-"
end_comment

begin_comment
comment|// CHECK: "/Z7"
end_comment

begin_comment
comment|// CHECK: "/FImyheader.h"
end_comment

begin_comment
comment|// CHECK: "/LD"
end_comment

begin_comment
comment|// CHECK: "/LDd"
end_comment

begin_comment
comment|// CHECK: "/EHs"
end_comment

begin_comment
comment|// CHECK: "/EHs-"
end_comment

begin_comment
comment|// CHECK: "/Zl"
end_comment

begin_comment
comment|// CHECK: "/MT"
end_comment

begin_comment
comment|// CHECK: "-garbage"
end_comment

begin_comment
comment|// CHECK: "-moregarbage"
end_comment

begin_comment
comment|// CHECK: "/Tc" "{{.*cl-fallback.c}}"
end_comment

begin_comment
comment|// CHECK: "/Fo{{.*cl-fallback.*.obj}}"
end_comment

begin_comment
comment|// RUN: %clang_cl /fallback /GR- -### -- %s 2>&1 | FileCheck -check-prefix=GR %s
end_comment

begin_comment
comment|// GR: cl.exe
end_comment

begin_comment
comment|// GR: "/GR-"
end_comment

begin_comment
comment|// RUN: %clang_cl /fallback /GS- -### -- %s 2>&1 | FileCheck -check-prefix=GS %s
end_comment

begin_comment
comment|// GS: cl.exe
end_comment

begin_comment
comment|// GS: "/GS-"
end_comment

begin_comment
comment|// RUN: %clang_cl /fallback /Zc:threadSafeInit -### -- %s 2>&1 | FileCheck -check-prefix=ThreadSafe %s
end_comment

begin_comment
comment|// ThreadSafe: /Zc:threadSafeInit
end_comment

begin_comment
comment|// RUN: %clang_cl /fallback /Zc:threadSafeInit- -### -- %s 2>&1 | FileCheck -check-prefix=NonThreadSafe %s
end_comment

begin_comment
comment|// NonThreadSafe: /Zc:threadSafeInit-
end_comment

begin_comment
comment|// RUN: %clang_cl /fallback /Od -### -- %s 2>&1 | FileCheck -check-prefix=O0 %s
end_comment

begin_comment
comment|// O0: cl.exe
end_comment

begin_comment
comment|// O0: "/Od"
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i686-pc-win32 /fallback /O1 -### -- %s 2>&1 | FileCheck -check-prefix=O1 %s
end_comment

begin_comment
comment|// O1: cl.exe
end_comment

begin_comment
comment|// O1: "/Og" "/Os" "/Ob2" "/Oy" "/GF" "/Gy"
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i686-pc-win32 /fallback /O2 -### -- %s 2>&1 | FileCheck -check-prefix=O2 %s
end_comment

begin_comment
comment|// O2: cl.exe
end_comment

begin_comment
comment|// O2: "/Oi" "/Og" "/Ot" "/Ob2" "/Oy" "/GF" "/Gy"
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i686-pc-win32 /fallback /Os -### -- %s 2>&1 | FileCheck -check-prefix=Os %s
end_comment

begin_comment
comment|// Os: cl.exe
end_comment

begin_comment
comment|// Os: "/Os"
end_comment

begin_comment
comment|// RUN: %clang_cl --target=i686-pc-win32 /fallback /Ox -### -- %s 2>&1 | FileCheck -check-prefix=Ox %s
end_comment

begin_comment
comment|// Ox: cl.exe
end_comment

begin_comment
comment|// Ox: "/Oi" "/Og" "/Ot" "/Ob2" "/Oy" "/GF"
end_comment

begin_comment
comment|// Only fall back when actually compiling, not for e.g. /P (preprocess).
end_comment

begin_comment
comment|// RUN: %clang_cl /fallback /P -### -- %s 2>&1 | FileCheck -check-prefix=P %s
end_comment

begin_comment
comment|// P-NOT: ||
end_comment

begin_comment
comment|// P-NOT: "cl.exe"
end_comment

begin_comment
comment|// RUN: not %clang_cl /fallback /c -- %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:     FileCheck -check-prefix=ErrWarn %s
end_comment

begin_comment
comment|// ErrWarn: warning: falling back to {{.*}}cl.exe
end_comment

begin_comment
comment|// RUN: %clang_cl /fallback /c /GR /GR- -### -- %s 2>&1 | \
end_comment

begin_comment
comment|// RUN:     FileCheck -check-prefix=NO_RTTI %s
end_comment

begin_comment
comment|// NO_RTTI: "-cc1"
end_comment

begin_comment
comment|// NO_RTTI: ||
end_comment

begin_comment
comment|// NO_RTTI: cl.exe
end_comment

begin_comment
comment|// NO_RTTI: "/GR-"
end_comment

begin_comment
comment|// Don't fall back on non-C or C++ files.
end_comment

begin_comment
comment|// RUN: %clang_cl /fallback -### -- %S/Inputs/file.ll 2>&1 | FileCheck -check-prefix=LL %s
end_comment

begin_comment
comment|// LL: file.ll
end_comment

begin_comment
comment|// LL-NOT: ||
end_comment

begin_comment
comment|// LL-NOT: "cl.exe"
end_comment

begin_error
error|#
directive|error
literal|"This fails to compile."
end_error

end_unit

