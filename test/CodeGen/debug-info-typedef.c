begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -debug-info-kind=limited -I%p %s -o - | FileCheck %s
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
comment|// CHECK: !DIDerivedType(tag: DW_TAG_typedef, name: "MyType", file: ![[HEADER:[0-9]+]], line: 2,
end_comment

begin_comment
comment|// CHECK: ![[HEADER]] = !DIFile(filename: "b.h",
end_comment

end_unit

