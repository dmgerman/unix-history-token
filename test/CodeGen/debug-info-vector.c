begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -g %s -o - | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|int
name|v4si
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_decl_stmt
name|v4si
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Test that we get an array type that's also a vector out of debug.
end_comment

begin_comment
comment|// CHECK: [ DW_TAG_array_type ] [line 0, size 128, align 128, offset 0] [vector] [from int]
end_comment

end_unit

