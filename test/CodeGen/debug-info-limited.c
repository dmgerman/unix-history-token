begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -flimit-debug-info -emit-llvm -g -S %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Ensure we emit the full definition of 'foo' even though only its declaration
end_comment

begin_comment
comment|// is needed, since C has no ODR to ensure that the definition will be the same
end_comment

begin_comment
comment|// in whatever TU actually uses/requires the definition of 'foo'.
end_comment

begin_comment
comment|// CHECK: ; [ DW_TAG_structure_type ] [foo] {{.*}} [def]
end_comment

begin_struct
struct|struct
name|foo
block|{ }
struct|;
end_struct

begin_decl_stmt
name|struct
name|foo
modifier|*
name|f
decl_stmt|;
end_decl_stmt

end_unit

