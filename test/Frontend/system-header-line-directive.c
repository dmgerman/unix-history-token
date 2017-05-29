begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wall %s -I %S/Inputs -isystem %S/Inputs/SystemHeaderPrefix -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E -o - -I %S/Inputs -isystem %S/Inputs/SystemHeaderPrefix | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<noline.h>
end_include

begin_include
include|#
directive|include
file|<line-directive-in-system.h>
end_include

begin_comment
comment|// expected-warning@line-directive.h:* {{type specifier missing, defaults to 'int'}}
end_comment

begin_include
include|#
directive|include
file|"line-directive.h"
end_include

begin_comment
comment|// This tests that "#line" directives in system headers preserve system
end_comment

begin_comment
comment|// header-ness just like GNU line markers that don't have filenames.  This was
end_comment

begin_comment
comment|// PR30752.
end_comment

begin_comment
comment|// CHECK: # {{[0-9]+}} "{{.*}}system-header-line-directive.c" 2
end_comment

begin_comment
comment|// CHECK: # 1 "{{.*}}noline.h" 1 3
end_comment

begin_comment
comment|// CHECK: foo();
end_comment

begin_comment
comment|// CHECK: # 4 "{{.*}}system-header-line-directive.c" 2
end_comment

begin_comment
comment|// CHECK: # 1 "{{.*}}line-directive-in-system.h" 1 3
end_comment

begin_comment
comment|//      The "3" below indicates that "foo.h" is considered a system header.
end_comment

begin_comment
comment|// CHECK: # 1 "foo.h" 3
end_comment

begin_comment
comment|// CHECK: foo();
end_comment

begin_comment
comment|// CHECK: # {{[0-9]+}} "{{.*}}system-header-line-directive.c" 2
end_comment

begin_comment
comment|// CHECK: # 1 "{{.*}}line-directive.h" 1
end_comment

begin_comment
comment|// CHECK: # 10 "foo.h"{{$}}
end_comment

end_unit

