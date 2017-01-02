begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -debug-info-kind=limited %s -o - | FileCheck %s
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
comment|// CHECK: !DICompositeType(tag: DW_TAG_array_type,
end_comment

begin_comment
comment|// CHECK-SAME:             baseType: ![[INT:[0-9]+]]
end_comment

begin_comment
comment|// CHECK-SAME:             size: 128
end_comment

begin_comment
comment|// CHECK-SAME:             DIFlagVector
end_comment

begin_comment
comment|// CHECK: ![[INT]] = !DIBasicType(name: "int"
end_comment

end_unit

