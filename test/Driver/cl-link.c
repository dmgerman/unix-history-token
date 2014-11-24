begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Don't attempt slash switches on msys bash.
end_comment

begin_comment
comment|// REQUIRES: shell-preserves-root
end_comment

begin_comment
comment|// Note: %s must be preceded by -- or bound to another option, otherwise it may
end_comment

begin_comment
comment|// be interpreted as a command-line option, e.g. on Mac where %s is commonly
end_comment

begin_comment
comment|// under /Users.
end_comment

begin_comment
comment|// RUN: %clang_cl /Tc%s -### /link foo bar baz 2>&1 | FileCheck --check-prefix=LINK %s
end_comment

begin_comment
comment|// LINK: link.exe
end_comment

begin_comment
comment|// LINK: "foo"
end_comment

begin_comment
comment|// LINK: "bar"
end_comment

begin_comment
comment|// LINK: "baz"
end_comment

begin_comment
comment|// RUN: %clang_cl /Tc%s -### -fsanitize=address 2>&1 | FileCheck --check-prefix=ASAN %s
end_comment

begin_comment
comment|// ASAN: link.exe
end_comment

begin_comment
comment|// ASAN: "-debug"
end_comment

begin_comment
comment|// ASAN: "-incremental:no"
end_comment

begin_comment
comment|// ASAN: "{{.*}}clang_rt.asan-i386.lib"
end_comment

begin_comment
comment|// ASAN: "{{.*}}clang_rt.asan_cxx-i386.lib"
end_comment

begin_comment
comment|// ASAN: "{{.*}}cl-link{{.*}}.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /LD -### /Tc%s 2>&1 | FileCheck --check-prefix=DLL %s
end_comment

begin_comment
comment|// RUN: %clang_cl /LDd -### /Tc%s 2>&1 | FileCheck --check-prefix=DLL %s
end_comment

begin_comment
comment|// DLL: link.exe
end_comment

begin_comment
comment|// "-dll"
end_comment

begin_comment
comment|// RUN: %clang_cl /LD /Tc%s -### -fsanitize=address 2>&1 | FileCheck --check-prefix=ASAN-DLL %s
end_comment

begin_comment
comment|// RUN: %clang_cl /LDd /Tc%s -### -fsanitize=address 2>&1 | FileCheck --check-prefix=ASAN-DLL %s
end_comment

begin_comment
comment|// ASAN-DLL: link.exe
end_comment

begin_comment
comment|// ASAN-DLL: "-dll"
end_comment

begin_comment
comment|// ASAN-DLL: "-debug"
end_comment

begin_comment
comment|// ASAN-DLL: "-incremental:no"
end_comment

begin_comment
comment|// ASAN-DLL: "{{.*}}clang_rt.asan_dll_thunk-i386.lib"
end_comment

begin_comment
comment|// ASAN-DLL: "{{.*}}cl-link{{.*}}.obj"
end_comment

begin_comment
comment|// RUN: %clang_cl /Zi /Tc%s -### 2>&1 | FileCheck --check-prefix=DEBUG %s
end_comment

begin_comment
comment|// DEBUG: link.exe
end_comment

begin_comment
comment|// DEBUG: "-debug"
end_comment

end_unit

