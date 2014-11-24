begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -c -mcmodel=small %s 2>&1 | FileCheck -check-prefix CHECK-SMALL %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -mcmodel=kernel %s 2>&1 | FileCheck -check-prefix CHECK-KERNEL %s
end_comment

begin_comment
comment|// RUN: %clang -### -c -mcmodel=medium %s 2>&1 | FileCheck -check-prefix CHECK-MEDIUM %s
end_comment

begin_comment
comment|// RUN: %clang -### -S -mcmodel=large %s 2>&1 | FileCheck -check-prefix CHECK-LARGE %s
end_comment

begin_comment
comment|// RUN: not %clang -c -mcmodel=lager %s 2>&1 | FileCheck -check-prefix CHECK-INVALID %s
end_comment

begin_comment
comment|// CHECK-SMALL: "-mcode-model" "small"
end_comment

begin_comment
comment|// CHECK-KERNEL: "-mcode-model" "kernel"
end_comment

begin_comment
comment|// CHECK-MEDIUM: "-mcode-model" "medium"
end_comment

begin_comment
comment|// CHECK-LARGE: "-mcode-model" "large"
end_comment

begin_comment
comment|// CHECK-INVALID: error: invalid value 'lager' in '-mcode-model lager'
end_comment

end_unit

