begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -emit-llvm %s -debug-info-kind=limited -o - | FileCheck %s
end_comment

begin_comment
comment|// Here two temporary nodes are identical (but should not get uniqued) while
end_comment

begin_comment
comment|// building the full debug type.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|x
decl_stmt|;
block|}
name|foo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|foo
modifier|*
name|x
decl_stmt|;
block|}
name|bar
typedef|;
end_typedef

begin_comment
comment|// CHECK: !DICompositeType(tag: DW_TAG_structure_type,{{.*}} line: 4, size: 64,
end_comment

begin_comment
comment|// CHECK: !DICompositeType(tag: DW_TAG_structure_type,{{.*}} line: 4, size: 64,
end_comment

begin_decl_stmt
name|bar
name|b
decl_stmt|;
end_decl_stmt

end_unit

