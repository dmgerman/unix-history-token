begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fmodules -x objective-c -fmodules-cache-path=%t -I %S/Inputs %s 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"recursive1.h"
end_include

begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fmodules -x objective-c -fmodules-cache-path=%t -emit-module -fmodule-name=recursive1 %S/Inputs/module.map 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK:      While building module 'recursive1'{{( imported from .*[/\]recursive.c:3)?}}:
end_comment

begin_comment
comment|// CHECK-NEXT: While building module 'recursive2' imported from {{.*Inputs[/\]}}recursive1.h:1:
end_comment

begin_comment
comment|// CHECK-NEXT: In file included from<module-includes>:1:
end_comment

begin_comment
comment|// CHECK-NEXT: recursive2.h:1:10: fatal error: cyclic dependency in module 'recursive1': recursive1 -> recursive2 -> recursive1
end_comment

end_unit

