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

end_unit

