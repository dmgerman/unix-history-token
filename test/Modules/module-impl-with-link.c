begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules-cache-path=%t -fmodules -fimplicit-module-maps -fmodule-name=Clib %s -I %S/Inputs/module-impl-with-link -emit-llvm -o - | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"foo.h"
end_include

begin_comment
comment|// CHECK: !{{[0-9]+}} = !{i32 6, !"Linker Options", ![[LINK_OPTIONS:[0-9]+]]}
end_comment

begin_comment
comment|// Make sure we don't generate linker option for module Clib since this TU is
end_comment

begin_comment
comment|// an implementation of Clib.
end_comment

begin_comment
comment|// CHECK: ![[LINK_OPTIONS]] = !{}
end_comment

end_unit

