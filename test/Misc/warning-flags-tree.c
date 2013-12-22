begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: diagtool tree | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: diagtool tree -Weverything | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: diagtool tree everything | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// These three ways of running diagtool tree are the same:
end_comment

begin_comment
comment|// they produce a tree for every top-level diagnostic flag.
end_comment

begin_comment
comment|// Just check a few to make sure we're actually showing more than one group.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK: -W
end_comment

begin_comment
comment|// CHECK:   -Wextra
end_comment

begin_comment
comment|// CHECK:     -Wmissing-field-initializers
end_comment

begin_comment
comment|// CHECK:       warn_missing_field_initializers
end_comment

begin_comment
comment|// CHECK: -Wall
end_comment

begin_comment
comment|// CHECK:   -Wmost
end_comment

begin_comment
comment|// These flags are currently unimplemented; test that we output them anyway.
end_comment

begin_comment
comment|// CHECK: -Wstrict-aliasing
end_comment

begin_comment
comment|// CHECK-NEXT: -Wstrict-aliasing=0
end_comment

begin_comment
comment|// CHECK-NEXT: -Wstrict-aliasing=1
end_comment

begin_comment
comment|// CHECK-NEXT: -Wstrict-aliasing=2
end_comment

begin_comment
comment|// CHECK: -Wstrict-overflow
end_comment

begin_comment
comment|// CHECK-NEXT: -Wstrict-overflow=0
end_comment

begin_comment
comment|// CHECK-NEXT: -Wstrict-overflow=1
end_comment

begin_comment
comment|// CHECK-NEXT: -Wstrict-overflow=2
end_comment

begin_comment
comment|// CHECK-NEXT: -Wstrict-overflow=3
end_comment

begin_comment
comment|// CHECK-NEXT: -Wstrict-overflow=4
end_comment

begin_comment
comment|// CHECK-NEXT: -Wstrict-overflow=5
end_comment

begin_comment
comment|// RUN: not diagtool tree -Wthis-is-not-a-valid-flag
end_comment

begin_comment
comment|// RUN: diagtool tree -Wgnu | FileCheck -strict-whitespace -check-prefix CHECK-GNU %s
end_comment

begin_comment
comment|// CHECK-GNU: -Wgnu
end_comment

begin_comment
comment|// CHECK-GNU:   -Wgnu-designator
end_comment

begin_comment
comment|// CHECK-GNU:     ext_gnu_array_range
end_comment

begin_comment
comment|// CHECK-GNU:     ext_gnu_missing_equal_designator
end_comment

begin_comment
comment|// CHECK-GNU:     ext_gnu_old_style_field_designator
end_comment

begin_comment
comment|// CHECK-GNU:   -Wvla-extension
end_comment

begin_comment
comment|// CHECK-GNU:     ext_vla
end_comment

begin_comment
comment|// There are more GNU extensions but we don't need to check them all.
end_comment

begin_comment
comment|// RUN: diagtool tree --flags-only -Wgnu | FileCheck -check-prefix CHECK-FLAGS-ONLY %s
end_comment

begin_comment
comment|// CHECK-FLAGS-ONLY: -Wgnu
end_comment

begin_comment
comment|// CHECK-FLAGS-ONLY:   -Wgnu-designator
end_comment

begin_comment
comment|// CHECK-FLAGS-ONLY-NOT:     ext_gnu_array_range
end_comment

begin_comment
comment|// CHECK-FLAGS-ONLY-NOT:     ext_gnu_missing_equal_designator
end_comment

begin_comment
comment|// CHECK-FLAGS-ONLY-NOT:     ext_gnu_old_style_field_designator
end_comment

begin_comment
comment|// CHECK-FLAGS-ONLY:   -Wvla
end_comment

begin_comment
comment|// CHECK-FLAGS-ONLY-NOT:     ext_vla
end_comment

begin_comment
comment|// CHECK-FLAGS-ONLY-NOT:   ext_array_init_copy
end_comment

begin_comment
comment|// CHECK-FLAGS-ONLY-NOT:   ext_empty_struct_union
end_comment

begin_comment
comment|// CHECK-FLAGS-ONLY-NOT:   ext_expr_not_ice
end_comment

end_unit

