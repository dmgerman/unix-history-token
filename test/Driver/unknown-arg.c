begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang %s -cake-is-lie -%0 -%d -HHHH -munknown-to-clang-option -print-stats -funknown-to-clang-option 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck %s
end_comment

begin_comment
comment|// CHECK: unknown argument: '-cake-is-lie'
end_comment

begin_comment
comment|// CHECK: unknown argument: '-%0'
end_comment

begin_comment
comment|// CHECK: unknown argument: '-%d'
end_comment

begin_comment
comment|// CHECK: unknown argument: '-HHHH'
end_comment

begin_comment
comment|// CHECK: unknown argument: '-munknown-to-clang-option'
end_comment

begin_comment
comment|// CHECK: unknown argument: '-print-stats'
end_comment

begin_comment
comment|// CHECK: unknown argument: '-funknown-to-clang-option'
end_comment

begin_comment
comment|// RUN: %clang -S %s -o %t.s  -Wunknown-to-clang-option 2>&1 | FileCheck --check-prefix=IGNORED %s
end_comment

begin_comment
comment|// IGNORED: warning: unknown warning option '-Wunknown-to-clang-option'
end_comment

end_unit

