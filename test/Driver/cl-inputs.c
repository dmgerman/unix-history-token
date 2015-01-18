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
comment|// RUN: %clang_cl /TC -### -- %s 2>&1 | FileCheck -check-prefix=TC %s
end_comment

begin_comment
comment|// TC:  "-x" "c"
end_comment

begin_comment
comment|// TC-NOT: warning
end_comment

begin_comment
comment|// TC-NOT: note
end_comment

begin_comment
comment|// RUN: %clang_cl /TP -### -- %s 2>&1 | FileCheck -check-prefix=TP %s
end_comment

begin_comment
comment|// TP:  "-x" "c++"
end_comment

begin_comment
comment|// TP-NOT: warning
end_comment

begin_comment
comment|// TP-NOT: note
end_comment

begin_comment
comment|// RUN: %clang_cl -### /Tc%s /TP -- %s 2>&1 | FileCheck -check-prefix=Tc %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /TP /Tc%s -- %s 2>&1 | FileCheck -check-prefix=Tc %s
end_comment

begin_comment
comment|// Tc:  "-x" "c"
end_comment

begin_comment
comment|// Tc:  "-x" "c++"
end_comment

begin_comment
comment|// Tc-NOT: warning
end_comment

begin_comment
comment|// Tc-NOT: note
end_comment

begin_comment
comment|// RUN: %clang_cl -### /Tp%s /TC -- %s 2>&1 | FileCheck -check-prefix=Tp %s
end_comment

begin_comment
comment|// RUN: %clang_cl -### /TC /Tp%s -- %s 2>&1 | FileCheck -check-prefix=Tp %s
end_comment

begin_comment
comment|// Tp:  "-x" "c++"
end_comment

begin_comment
comment|// Tp:  "-x" "c"
end_comment

begin_comment
comment|// Tp-NOT: warning
end_comment

begin_comment
comment|// Tp-NOT: note
end_comment

begin_comment
comment|// RUN: %clang_cl /TP /TC /TP -### -- %s 2>&1 | FileCheck -check-prefix=WARN %s
end_comment

begin_comment
comment|// WARN: warning: overriding '/TP' option with '/TC'
end_comment

begin_comment
comment|// WARN: warning: overriding '/TC' option with '/TP'
end_comment

begin_comment
comment|// WARN: note: The last /TC or /TP option takes precedence over earlier instances
end_comment

begin_comment
comment|// WARN-NOT: note
end_comment

begin_comment
comment|// RUN: env LIB=%S/Inputs/cl-libs %clang_cl /c /TP cl-test.lib -### 2>&1 | FileCheck -check-prefix=TPlib %s
end_comment

begin_comment
comment|// TPlib: warning: cl-test.lib: 'linker' input unused
end_comment

begin_comment
comment|// TPlib: warning: argument unused during compilation: '/TP'
end_comment

begin_comment
comment|// TPlib-NOT: cl-test.lib
end_comment

begin_comment
comment|// RUN: env LIB=%S/Inputs/cl-libs %clang_cl /c /TC cl-test.lib -### 2>&1 | FileCheck -check-prefix=TClib %s
end_comment

begin_comment
comment|// TClib: warning: cl-test.lib: 'linker' input unused
end_comment

begin_comment
comment|// TClib: warning: argument unused during compilation: '/TC'
end_comment

begin_comment
comment|// TClib-NOT: cl-test.lib
end_comment

begin_comment
comment|// RUN: not %clang_cl - 2>&1 | FileCheck -check-prefix=STDIN %s
end_comment

begin_comment
comment|// STDIN: error: use /Tc or /Tp
end_comment

begin_comment
comment|// RUN: %clang_cl -### /Tc - 2>&1 | FileCheck -check-prefix=STDINTc %s
end_comment

begin_comment
comment|// STDINTc: "-x" "c"
end_comment

begin_comment
comment|// RUN: env LIB=%S/Inputs/cl-libs %clang_cl -### -- %s cl-test.lib 2>&1 | FileCheck -check-prefix=LIBINPUT %s
end_comment

begin_comment
comment|// LIBINPUT: link.exe"
end_comment

begin_comment
comment|// LIBINPUT: "cl-test.lib"
end_comment

begin_comment
comment|// RUN: env LIB=%S/Inputs/cl-libs %clang_cl -### -- %s cl-test2.lib 2>&1 | FileCheck -check-prefix=LIBINPUT2 %s
end_comment

begin_comment
comment|// LIBINPUT2: error: no such file or directory: 'cl-test2.lib'
end_comment

begin_comment
comment|// LIBINPUT2: link.exe"
end_comment

begin_comment
comment|// LIBINPUT2-NOT: "cl-test2.lib"
end_comment

begin_function_decl
name|void
name|f
parameter_list|()
function_decl|;
end_function_decl

end_unit

