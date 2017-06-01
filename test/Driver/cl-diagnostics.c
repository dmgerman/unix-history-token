begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Note: %s must be preceded by --, otherwise it may be interpreted as a
end_comment

begin_comment
comment|// command-line option, e.g. on Mac where %s is commonly under /Users.
end_comment

begin_comment
comment|// RUN: %clang_cl /diagnostics:classic -### -- %s 2>&1 | FileCheck %s --check-prefix=CLASSIC
end_comment

begin_comment
comment|// CLASSIC: -fno-caret-diagnostics
end_comment

begin_comment
comment|// CLASSIC: -fno-show-column
end_comment

begin_comment
comment|// RUN: %clang_cl /diagnostics:column -### -- %s 2>&1 | FileCheck %s --check-prefix=COLUMN
end_comment

begin_comment
comment|// COLUMN: -fno-caret-diagnostics
end_comment

begin_comment
comment|// COLUMN-NOT: -fno-show-column
end_comment

begin_comment
comment|// RUN: %clang_cl /diagnostics:caret -### -- %s 2>&1 | FileCheck %s --check-prefix=CARET
end_comment

begin_comment
comment|// CARET-NOT: -fno-caret-diagnostics
end_comment

begin_comment
comment|// CARET-NOT: -fno-show-column
end_comment

begin_comment
comment|// RUN: not %clang_cl -fms-compatibility-version=19  /diagnostics:classic /Zs -c -- %s 2>&1 | FileCheck %s --check-prefix=OUTPUT_CLASSIC
end_comment

begin_comment
comment|// OUTPUT_CLASSIC: cl-diagnostics.c({{[0-9]+}}): error: "asdf"
end_comment

begin_comment
comment|// OUTPUT_CLASSIC-NOT: #error
end_comment

begin_comment
comment|// RUN: not %clang_cl -fms-compatibility-version=19 /diagnostics:caret /Zs -c -- %s 2>&1 | FileCheck %s --check-prefix=OUTPUT_CARET
end_comment

begin_comment
comment|// OUTPUT_CARET: cl-diagnostics.c({{[0-9]+,[0-9]+}}): error: "asdf"
end_comment

begin_comment
comment|// OUTPUT_CARET-NEXT: #error "asdf"
end_comment

begin_comment
comment|// OUTPUT_CARET-NEXT: ^
end_comment

begin_error
error|#
directive|error
literal|"asdf"
end_error

end_unit

