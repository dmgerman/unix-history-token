begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: sed -e "s:INPUT_DIR:%S/Inputs:g" -e "s:OUT_DIR:%t:g" -e "s:EXTERNAL_NAMES:true:" %S/Inputs/use-external-names.yaml> %t.external.yaml
end_comment

begin_comment
comment|// RUN: sed -e "s:INPUT_DIR:%S/Inputs:g" -e "s:OUT_DIR:%t:g" -e "s:EXTERNAL_NAMES:false:" %S/Inputs/use-external-names.yaml> %t.yaml
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

begin_include
include|#
directive|include
file|"external-names.h"
end_include

begin_comment
comment|////
end_comment

begin_comment
comment|// Preprocessor (__FILE__ macro and # directives):
end_comment

begin_comment
comment|// RUN: %clang_cc1 -I %t -ivfsoverlay %t.external.yaml -E %s | FileCheck -check-prefix=CHECK-PP-EXTERNAL %s
end_comment

begin_comment
comment|// CHECK-PP-EXTERNAL: # {{[0-9]*}} "[[NAME:.*Inputs.external-names.h]]"
end_comment

begin_comment
comment|// CHECK-PP-EXTERNAL-NEXT: void foo(char **c) {
end_comment

begin_comment
comment|// CHECK-PP-EXTERNAL-NEXT: *c = "[[NAME]]";
end_comment

begin_comment
comment|// RUN: %clang_cc1 -I %t -ivfsoverlay %t.yaml -E %s | FileCheck -check-prefix=CHECK-PP %s
end_comment

begin_comment
comment|// CHECK-PP-NOT: Inputs
end_comment

begin_comment
comment|////
end_comment

begin_comment
comment|// Diagnostics:
end_comment

begin_comment
comment|// RUN: %clang_cc1 -I %t -ivfsoverlay %t.external.yaml -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-DIAG-EXTERNAL %s
end_comment

begin_comment
comment|// CHECK-DIAG-EXTERNAL: {{.*}}Inputs{{.}}external-names.h:{{[0-9]*:[0-9]*}}: warning: incompatible pointer
end_comment

begin_comment
comment|// RUN: %clang_cc1 -I %t -ivfsoverlay %t.yaml -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-DIAG %s
end_comment

begin_comment
comment|// CHECK-DIAG-NOT: Inputs
end_comment

begin_comment
comment|////
end_comment

begin_comment
comment|// Debug info
end_comment

begin_comment
comment|// RUN: %clang_cc1 -I %t -ivfsoverlay %t.external.yaml -triple %itanium_abi_triple -g -emit-llvm %s -o - | FileCheck -check-prefix=CHECK-DEBUG-EXTERNAL %s
end_comment

begin_comment
comment|// CHECK-DEBUG-EXTERNAL: ![[Num:[0-9]*]] = !{!"{{.*}}Inputs{{.}}external-names.h
end_comment

begin_comment
comment|// CHECK-DEBUG-EXTERNAL: !{!"0x29", ![[Num]]{{.*}}DW_TAG_file_type
end_comment

begin_comment
comment|// RUN: %clang_cc1 -I %t -ivfsoverlay %t.yaml -triple %itanium_abi_triple -g -emit-llvm %s -o - | FileCheck -check-prefix=CHECK-DEBUG %s
end_comment

begin_comment
comment|// CHECK-DEBUG-NOT: Inputs
end_comment

end_unit

