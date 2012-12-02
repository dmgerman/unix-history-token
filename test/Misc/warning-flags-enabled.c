begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: diagtool show-enabled %s | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This shows warnings which are on by default.
end_comment

begin_comment
comment|// We just check a few to make sure it's doing something sensible.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: ext_unterminated_string
end_comment

begin_comment
comment|// CHECK: warn_condition_is_assignment
end_comment

begin_comment
comment|// CHECK: warn_null_arg
end_comment

begin_comment
comment|// RUN: diagtool show-enabled -Wno-everything %s | count 0
end_comment

begin_comment
comment|// RUN: diagtool show-enabled -Wno-everything -Wobjc-root-class %s | FileCheck -check-prefix CHECK-WARN %s
end_comment

begin_comment
comment|// RUN: diagtool show-enabled -Wno-everything -Werror=objc-root-class %s | FileCheck -check-prefix CHECK-ERROR %s
end_comment

begin_comment
comment|// RUN: diagtool show-enabled -Wno-everything -Wfatal-errors=objc-root-class %s | FileCheck -check-prefix CHECK-FATAL %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-WARN:  W  warn_objc_root_class_missing [-Wobjc-root-class]
end_comment

begin_comment
comment|// CHECK-ERROR: E  warn_objc_root_class_missing [-Wobjc-root-class]
end_comment

begin_comment
comment|// CHECK-FATAL: F  warn_objc_root_class_missing [-Wobjc-root-class]
end_comment

begin_comment
comment|// RUN: diagtool show-enabled --no-levels -Wno-everything -Wobjc-root-class %s | FileCheck -check-prefix CHECK-NO-LEVELS %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NO-LEVELS-NOT: W
end_comment

begin_comment
comment|// CHECK-NO-LEVELS-NOT: E
end_comment

begin_comment
comment|// CHECK-NO-LEVELS-NOT: F
end_comment

begin_comment
comment|// CHECK-NO-LEVELS: warn_objc_root_class_missing [-Wobjc-root-class]
end_comment

begin_comment
comment|// Test if EnumConversion is a subgroup of -Wconversion.
end_comment

begin_comment
comment|// RUN: diagtool show-enabled --no-levels -Wno-conversion -Wenum-conversion %s | FileCheck --check-prefix CHECK-ENUM-CONVERSION %s
end_comment

begin_comment
comment|// RUN: diagtool show-enabled --no-levels %s | FileCheck --check-prefix CHECK-ENUM-CONVERSION %s
end_comment

begin_comment
comment|// RUN: diagtool show-enabled --no-levels -Wno-conversion %s | FileCheck --check-prefix CHECK-NO-ENUM-CONVERSION %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ENUM-CONVERSION: -Wenum-conversion
end_comment

begin_comment
comment|// CHECK-NO-ENUM-CONVERSION-NOT: -Wenum-conversion
end_comment

begin_comment
comment|// Test if -Wshift-op-parentheses is a subgroup of -Wparentheses
end_comment

begin_comment
comment|// RUN: diagtool show-enabled --no-levels -Wno-parentheses -Wshift-op-parentheses %s | FileCheck --check-prefix CHECK-SHIFT-OP-PARENTHESES %s
end_comment

begin_comment
comment|// RUN: diagtool show-enabled --no-levels %s | FileCheck --check-prefix CHECK-SHIFT-OP-PARENTHESES %s
end_comment

begin_comment
comment|// RUN: diagtool show-enabled --no-levels -Wno-parentheses %s | FileCheck --check-prefix CHECK-NO-SHIFT-OP-PARENTHESES %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-SHIFT-OP-PARENTHESES: -Wshift-op-parentheses
end_comment

begin_comment
comment|// CHECK-NO-SHIFT-OP-PARENTHESES-NOT: -Wshift-op-parentheses
end_comment

end_unit

