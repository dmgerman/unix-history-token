begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env QA_OVERRIDE_GCC3_OPTIONS="#+-Os +-Oz +-O +-O3 +-Oignore +a +b +c xb Xa Omagic ^-ccc-print-options  " %clang x -O2 b -O3 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: env QA_OVERRIDE_GCC3_OPTIONS="x-Werror +-mfoo" %clang -Werror %s -c 2>&1 | FileCheck %s -check-prefix=RM-WERROR
end_comment

begin_comment
comment|// FIXME: It seems doesn't work with gcc-driver.
end_comment

begin_comment
comment|// REQUIRES: clang-driver
end_comment

begin_comment
comment|// CHECK-NOT: ###
end_comment

begin_comment
comment|// CHECK: Option 0 - Name: "-ccc-print-options", Values: {}
end_comment

begin_comment
comment|// CHECK-NEXT: Option 1 - Name: "<input>", Values: {"x"}
end_comment

begin_comment
comment|// CHECK-NEXT: Option 2 - Name: "-O", Values: {"ignore"}
end_comment

begin_comment
comment|// CHECK-NEXT: Option 3 - Name: "-O", Values: {"magic"}
end_comment

begin_comment
comment|// RM-WERROR: ### QA_OVERRIDE_GCC3_OPTIONS: x-Werror +-mfoo
end_comment

begin_comment
comment|// RM-WERROR-NEXT: ### Deleting argument -Werror
end_comment

begin_comment
comment|// RM-WERROR-NEXT: ### Adding argument -mfoo at end
end_comment

begin_comment
comment|// RM-WERROR-NEXT: warning: argument unused during compilation: '-mfoo'
end_comment

end_unit

