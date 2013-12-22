begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -frewrite-includes -include rewrite-includes2.h -I %S/Inputs %s -o - | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// STARTMAIN
end_comment

begin_comment
comment|// CHECK-NOT: {{^}}#define
end_comment

begin_comment
comment|// CHECK: included_line2
end_comment

begin_comment
comment|// CHECK: {{^}}// STARTMAIN{{$}}
end_comment

end_unit

