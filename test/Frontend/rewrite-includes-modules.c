begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir %t
end_comment

begin_comment
comment|// RUN: echo 'extern int dummy;'> %t/dummy.h
end_comment

begin_comment
comment|// RUN: echo 'module dummy { header "dummy.h" }'> %t/module.modulemap
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fimplicit-module-maps -fmodules-cache-path=%t %s -I%t -E -frewrite-includes -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fimplicit-module-maps -fmodules-cache-path=%t -x objective-c %s -I%t -E -frewrite-includes -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fimplicit-module-maps -fmodules-cache-path=%t -x c++ %s -I%t -E -frewrite-includes -o - | FileCheck %s
end_comment

begin_function_decl
name|int
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"dummy.h"
end_include

begin_function_decl
name|int
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"dummy.h"
end_include

begin_comment
comment|// CHECK: int bar();{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #include "dummy.h"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: # 10 "{{.*[/\\]}}rewrite-includes-modules.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #pragma clang module import dummy /* clang -frewrite-includes: implicit import */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: # 11 "{{.*[/\\]}}rewrite-includes-modules.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: int foo();{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #include "dummy.h"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: # 12 "{{.*[/\\]}}rewrite-includes-modules.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #pragma clang module import dummy /* clang -frewrite-includes: implicit import */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: # 13 "{{.*[/\\]}}rewrite-includes-modules.c"{{$}}
end_comment

end_unit

