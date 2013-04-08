begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: shell
end_comment

begin_comment
comment|// PR15642
end_comment

begin_comment
comment|// RUN: rm -rf %t.dir
end_comment

begin_comment
comment|// RUN: mkdir -p %t.dir
end_comment

begin_comment
comment|// RUN: echo> '%t.dir/    .h'
end_comment

begin_comment
comment|// RUN: echo> '%t.dir/$$.h'
end_comment

begin_comment
comment|// RUN: echo> '%t.dir/##.h'
end_comment

begin_comment
comment|// RUN: cd %t.dir
end_comment

begin_comment
comment|// RUN: %clang -MD -MF - %s -fsyntax-only -I. | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// CHECK: \ \ \ \ .h
end_comment

begin_comment
comment|// CHECK: $$$$.h
end_comment

begin_comment
comment|// CHECK: \#\#.h
end_comment

begin_include
include|#
directive|include
file|"    .h"
end_include

begin_include
include|#
directive|include
file|"$$.h"
end_include

begin_include
include|#
directive|include
file|"##.h"
end_include

end_unit

