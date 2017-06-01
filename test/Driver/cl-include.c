begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Note: %s must be preceded by --, otherwise it may be interpreted as a
end_comment

begin_comment
comment|// command-line option, e.g. on Mac where %s is commonly under /Users.
end_comment

begin_comment
comment|// RUN: %clang_cl -### -- %s 2>&1 | FileCheck %s --check-prefix=BUILTIN
end_comment

begin_comment
comment|// BUILTIN: "-internal-isystem" "{{.*lib.*clang.*include}}"
end_comment

begin_comment
comment|// RUN: %clang_cl -nobuiltininc -### -- %s 2>&1 | FileCheck %s --check-prefix=NOBUILTIN
end_comment

begin_comment
comment|// NOBUILTIN-NOT: "-internal-isystem" "{{.*lib.*clang.*include}}"
end_comment

begin_comment
comment|// RUN: env INCLUDE=/my/system/inc %clang_cl -### -- %s 2>&1 | FileCheck %s --check-prefix=STDINC
end_comment

begin_comment
comment|// STDINC: "-internal-isystem" "/my/system/inc"
end_comment

begin_comment
comment|// RUN: env INCLUDE=/my/system/inc %clang_cl -nostdinc -### -- %s 2>&1 | FileCheck %s --check-prefix=NOSTDINC
end_comment

begin_comment
comment|// NOSTDINC-NOT: "-internal-isystem" "/my/system/inc"
end_comment

end_unit

