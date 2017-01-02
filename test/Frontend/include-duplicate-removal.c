begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -v -I%S/Inputs -iquote %S/Inputs/SystemHeaderPrefix -isystem %S/Inputs/SystemHeaderPrefix -isystem %S/Inputs/SystemHeaderPrefix %s 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<test.h>
end_include

begin_comment
comment|// CHECK: ignoring duplicate directory
end_comment

begin_comment
comment|// CHECK-SAME: Inputs/SystemHeaderPrefix"{{$}}
end_comment

begin_comment
comment|// CHECK:      #include "..."
end_comment

begin_comment
comment|// CHECK-NEXT: {{.*}}Inputs/SystemHeaderPrefix{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: #include<...>
end_comment

begin_comment
comment|// CHECK-NEXT: {{.*}}Inputs{{$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{.*}}Inputs/SystemHeaderPrefix{{$}}
end_comment

end_unit

