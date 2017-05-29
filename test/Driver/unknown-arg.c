begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang %s -cake-is-lie -%0 -%d -HHHH -munknown-to-clang-option -print-stats -funknown-to-clang-option -### 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cl -cake-is-lie -%0 -%d -HHHH -munknown-to-clang-option -print-stats -funknown-to-clang-option -### -c -- %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck %s --check-prefix=CL
end_comment

begin_comment
comment|// RUN: not %clang_cl -cake-is-lie -%0 -%d -HHHH -munknown-to-clang-option -print-stats -funknown-to-clang-option -c -Werror=unknown-argument -### -- %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck %s --check-prefix=CL-ERROR
end_comment

begin_comment
comment|// RUN: %clang_cl -cake-is-lie -%0 -%d -HHHH -munknown-to-clang-option -print-stats -funknown-to-clang-option -c -Wno-unknown-argument -### -- %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck %s --check-prefix=SILENT
end_comment

begin_comment
comment|// CHECK: error: unknown argument: '-cake-is-lie'
end_comment

begin_comment
comment|// CHECK: error: unknown argument: '-%0'
end_comment

begin_comment
comment|// CHECK: error: unknown argument: '-%d'
end_comment

begin_comment
comment|// CHECK: error: unknown argument: '-HHHH'
end_comment

begin_comment
comment|// CHECK: error: unknown argument: '-munknown-to-clang-option'
end_comment

begin_comment
comment|// CHECK: error: unknown argument: '-print-stats'
end_comment

begin_comment
comment|// CHECK: error: unknown argument: '-funknown-to-clang-option'
end_comment

begin_comment
comment|// CL: warning: unknown argument ignored in clang-cl: '-cake-is-lie'
end_comment

begin_comment
comment|// CL: warning: unknown argument ignored in clang-cl: '-%0'
end_comment

begin_comment
comment|// CL: warning: unknown argument ignored in clang-cl: '-%d'
end_comment

begin_comment
comment|// CL: warning: unknown argument ignored in clang-cl: '-HHHH'
end_comment

begin_comment
comment|// CL: warning: unknown argument ignored in clang-cl: '-munknown-to-clang-option'
end_comment

begin_comment
comment|// CL: warning: unknown argument ignored in clang-cl: '-print-stats'
end_comment

begin_comment
comment|// CL: warning: unknown argument ignored in clang-cl: '-funknown-to-clang-option'
end_comment

begin_comment
comment|// CL-ERROR: error: unknown argument ignored in clang-cl: '-cake-is-lie'
end_comment

begin_comment
comment|// CL-ERROR: error: unknown argument ignored in clang-cl: '-%0'
end_comment

begin_comment
comment|// CL-ERROR: error: unknown argument ignored in clang-cl: '-%d'
end_comment

begin_comment
comment|// CL-ERROR: error: unknown argument ignored in clang-cl: '-HHHH'
end_comment

begin_comment
comment|// CL-ERROR: error: unknown argument ignored in clang-cl: '-munknown-to-clang-option'
end_comment

begin_comment
comment|// CL-ERROR: error: unknown argument ignored in clang-cl: '-print-stats'
end_comment

begin_comment
comment|// CL-ERROR: error: unknown argument ignored in clang-cl: '-funknown-to-clang-option'
end_comment

begin_comment
comment|// SILENT-NOT: error:
end_comment

begin_comment
comment|// SILENT-NOT: warning:
end_comment

begin_comment
comment|// RUN: %clang -S %s -o %t.s  -Wunknown-to-clang-option 2>&1 | FileCheck --check-prefix=IGNORED %s
end_comment

begin_comment
comment|// IGNORED: warning: unknown warning option '-Wunknown-to-clang-option'
end_comment

end_unit

