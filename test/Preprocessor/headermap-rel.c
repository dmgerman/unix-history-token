begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This uses a headermap with this entry:
end_comment

begin_comment
comment|//   Foo.h -> Foo/Foo.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s -o %t.i -I %S/Inputs/headermap-rel/foo.hmap -F %S/Inputs/headermap-rel
end_comment

begin_comment
comment|// RUN: FileCheck %s -input-file %t.i
end_comment

begin_comment
comment|// CHECK: Foo.h is parsed
end_comment

begin_comment
comment|// CHECK: Foo.h is parsed
end_comment

begin_include
include|#
directive|include
file|"Foo.h"
end_include

begin_include
include|#
directive|include
file|"Foo.h"
end_include

end_unit

