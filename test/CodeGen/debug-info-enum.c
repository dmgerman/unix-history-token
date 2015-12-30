begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -debug-info-kind=limited %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: !DICompositeType(tag: DW_TAG_enumeration_type, name: "e"
end_comment

begin_comment
comment|// CHECK-SAME:             elements: [[TEST3_ENUMS:![0-9]*]]
end_comment

begin_comment
comment|// CHECK: [[TEST3_ENUMS]] = !{[[TEST3_E:![0-9]*]]}
end_comment

begin_comment
comment|// CHECK: [[TEST3_E]] = !DIEnumerator(name: "E", value: -1)
end_comment

begin_enum_decl
enum_decl|enum
name|e
enum_decl|;
end_enum_decl

begin_function
name|void
name|func
parameter_list|(
name|enum
name|e
modifier|*
name|p
parameter_list|)
block|{ }
end_function

begin_enum
enum|enum
name|e
block|{
name|E
init|=
operator|-
literal|1
block|}
enum|;
end_enum

end_unit

