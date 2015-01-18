begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -g -I%p %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Test that the location of the typedef points to the header file.
end_comment

begin_line
line|#
directive|line
number|1
file|"a.c"
end_line

begin_line
line|#
directive|line
number|2
file|"b.h"
end_line

begin_typedef
typedef|typedef
name|int
name|MyType
typedef|;
end_typedef

begin_line
line|#
directive|line
number|2
file|"a.c"
end_line

begin_decl_stmt
name|MyType
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:  !"0x16\00MyType\002\00{{.*}}", ![[HEADER:[0-9]+]], null{{.*}}} ; [ DW_TAG_typedef ] [MyType] [line 2, size 0, align 0, offset 0] [from int]
end_comment

begin_comment
comment|// CHECK: ![[HEADER]] = !{!"b.h",
end_comment

end_unit

