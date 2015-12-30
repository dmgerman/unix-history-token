begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t&& mkdir %t
end_comment

begin_comment
comment|// RUN: echo 'module Foo { header "foo.h" }'> %t/module.modulemap
end_comment

begin_comment
comment|// RUN: echo '#define FOO_MACRO 42'> %t/foo.h
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:9:1 -I %t %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:9:1 -I %t -fmodules -fmodules-cache-path=%t %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"foo.h"
end_include

begin_decl_stmt
name|int
name|x
init|=
comment|/*here*/
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: FOO_MACRO
end_comment

end_unit

