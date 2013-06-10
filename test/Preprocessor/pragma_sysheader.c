begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -pedantic %s -fsyntax-only
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// rdar://6899937
end_comment

begin_include
include|#
directive|include
file|"pragma_sysheader.h"
end_include

begin_comment
comment|// PR9861: Verify that line markers are not messed up in -E mode.
end_comment

begin_comment
comment|// CHECK: # 1 "{{.*}}pragma_sysheader.h" 1
end_comment

begin_comment
comment|// CHECK-NEXT: # 2 "{{.*}}pragma_sysheader.h" 3
end_comment

begin_comment
comment|// CHECK-NEXT: typedef int x;
end_comment

begin_comment
comment|// CHECK-NEXT: typedef int x;
end_comment

begin_comment
comment|// CHECK-NEXT: # 6 "{{.*}}pragma_sysheader.c" 2
end_comment

end_unit

