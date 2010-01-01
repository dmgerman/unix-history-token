begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env QA_OVERRIDE_GCC3_OPTIONS="#+-Os +-Oz +-O +-O3 +-Oignore +a +b +c xb Xa Omagic ^-ccc-print-options  " %clang x -O2 b -O3 2>&1 | FileCheck %s
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

end_unit

