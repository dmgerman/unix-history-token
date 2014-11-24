begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -E -frewrite-includes %s -o - | FileCheck -strict-whitespace %s
end_comment

begin_include
include|#
directive|include
file|"foobar.h"
end_include

begin_comment
comment|// expected-error {{'foobar.h' file not found}}
end_comment

begin_comment
comment|// CHECK: {{^}}#if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#include "foobar.h"
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}#endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 3 "{{.*}}rewrite-includes-missing.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^}}# 4 "{{.*}}rewrite-includes-missing.c"{{$}}
end_comment

end_unit

