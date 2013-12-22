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

end_unit

