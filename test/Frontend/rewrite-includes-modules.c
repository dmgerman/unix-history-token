begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodules-cache-path=%t -x objective-c %s -F %S/../Modules/Inputs -E -frewrite-includes -o - | FileCheck %s
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
file|<Module/Module.h>
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
file|<Module/Module.h>
end_include

begin_comment
comment|// CHECK: int bar();{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #include<Module/Module.h>{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: # 5 "{{.*[/\\]}}rewrite-includes-modules.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: @import Module; /* clang -frewrite-includes: implicit import */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: # 6 "{{.*[/\\]}}rewrite-includes-modules.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: int foo();{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #if 0 /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #include<Module/Module.h>{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #endif /* expanded by -frewrite-includes */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: # 7 "{{.*[/\\]}}rewrite-includes-modules.c"{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: @import Module; /* clang -frewrite-includes: implicit import */{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: # 8 "{{.*[/\\]}}rewrite-includes-modules.c"{{$}}
end_comment

end_unit

