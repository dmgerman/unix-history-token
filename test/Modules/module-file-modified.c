begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir %t
end_comment

begin_comment
comment|// RUN: echo 'int foo = 0;'> %t/a.h
end_comment

begin_comment
comment|// RUN: echo 'module A { header "a.h" }'> %t/m.modulemap
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -emit-module -fmodule-name=A -x c %t/m.modulemap -o %t/m.pcm
end_comment

begin_comment
comment|// RUN: echo 'int bar;'> %t/a.h
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fmodules -fmodule-file=%t/m.pcm -fmodule-map-file=%t/m.modulemap -x c %s -I%t -fsyntax-only 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"a.h"
end_include

begin_decl_stmt
name|int
name|foo
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// redefinition of 'foo'
end_comment

begin_comment
comment|// CHECK: fatal error: file {{.*}} has been modified since the module file {{.*}} was built
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

end_unit

