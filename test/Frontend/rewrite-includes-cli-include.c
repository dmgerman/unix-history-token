begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -verify -E -frewrite-includes -include %S/Inputs/rewrite-includes2.h %s -o - | FileCheck -strict-whitespace %s
end_comment

begin_macro
name|main_file_line
end_macro

begin_comment
comment|// CHECK: {{^}}# 1 "<built-in>"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 1 "{{.*[/\\]Inputs(/|\\\\)}}rewrite-includes2.h" 1{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}included_line2{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 1 "<built-in>" 2{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 1 "{{.*}}rewrite-includes-cli-include.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: FileCheck
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}main_file_line{{$}}
end_comment

end_unit

