begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fimplicit-module-maps -fmodules-cache-path=%t -x objective-c %s -F %S/../Modules/Inputs -E -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: int bar();
end_comment

begin_function_decl
name|int
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: #pragma clang module import Module /* clang -E: implicit import for #include<Module/Module.h> */{{$}}
end_comment

begin_include
include|#
directive|include
file|<Module/Module.h>
end_include

begin_comment
comment|// CHECK: int foo();
end_comment

begin_function_decl
name|int
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: #pragma clang module import Module /* clang -E: implicit import for #include<Module/Module.h> */{{$}}
end_comment

begin_include
include|#
directive|include
file|<Module/Module.h>
end_include

begin_include
include|#
directive|include
file|"pp-modules.h"
end_include

begin_comment
comment|// CHECK: # 1 "{{.*}}pp-modules.h" 1
end_comment

begin_comment
comment|// CHECK: #pragma clang module import Module /* clang -E: implicit import for #include<Module/Module.h> */{{$}}
end_comment

begin_comment
comment|// CHECK: # 14 "{{.*}}pp-modules.c" 2
end_comment

end_unit

