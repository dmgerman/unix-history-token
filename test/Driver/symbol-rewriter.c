begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -frewrite-map-file %S/Inputs/rewrite.map -### %s 2>&1 | FileCheck %s -check-prefix CHECK-SINGLE
end_comment

begin_comment
comment|// CHECK-SINGLE: "-frewrite-map-file" "{{.*[\\/]}}rewrite.map"
end_comment

begin_comment
comment|// RUN: %clang -frewrite-map-file %S/Inputs/rewrite-1.map -frewrite-map-file %S/Inputs/rewrite-2.map -### %s 2>&1 | FileCheck %s -check-prefix CHECK-MULTIPLE
end_comment

begin_comment
comment|// CHECK-MULTIPLE: "-frewrite-map-file" "{{.*[\\/]}}rewrite-1.map" "-frewrite-map-file" "{{.*[\\/]}}rewrite-2.map"
end_comment

begin_comment
comment|// RUN: %clang -frewrite-map-file=%S/Inputs/rewrite.map -### %s 2>&1 | FileCheck %s -check-prefix CHECK-SINGLE-EQ
end_comment

begin_comment
comment|// CHECK-SINGLE-EQ: "-frewrite-map-file" "{{.*[\\/]}}rewrite.map"
end_comment

begin_comment
comment|// RUN: %clang -frewrite-map-file=%S/Inputs/rewrite-1.map -frewrite-map-file=%S/Inputs/rewrite-2.map -### %s 2>&1 | FileCheck %s -check-prefix CHECK-MULTIPLE-EQ
end_comment

begin_comment
comment|// CHECK-MULTIPLE-EQ: "-frewrite-map-file" "{{.*[\\/]}}rewrite-1.map"
end_comment

begin_comment
comment|// CHECK-MULTIPLE-EQ: "-frewrite-map-file" "{{.*[\\/]}}rewrite-2.map"
end_comment

begin_comment
comment|// RUN: %clang -frewrite-map-file %S/Inputs/rewrite-1.map -frewrite-map-file=%S/Inputs/rewrite-2.map -### %s 2>&1 | FileCheck %s -check-prefix CHECK-MIXED
end_comment

begin_comment
comment|// CHECK-MIXED: "-frewrite-map-file" "{{.*[\\/]}}rewrite-1.map" "-frewrite-map-file" "{{.*[\\/]}}rewrite-2.map"
end_comment

end_unit

