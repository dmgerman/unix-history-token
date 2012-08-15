begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -gline-tables-only -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Checks that clang with "-gline-tables-only" doesn't emit debug info
end_comment

begin_comment
comment|// for variables and types.
end_comment

begin_comment
comment|// CHECK-NOT: DW_TAG_variable
end_comment

begin_decl_stmt
name|int
name|global
init|=
literal|42
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-NOT: DW_TAG_typedef
end_comment

begin_comment
comment|// CHECK-NOT: DW_TAG_const_type
end_comment

begin_comment
comment|// CHECK-NOT: DW_TAG_pointer_type
end_comment

begin_comment
comment|// CHECK-NOT: DW_TAG_array_type
end_comment

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
name|constCharPtrArray
index|[
literal|10
index|]
typedef|;
end_typedef

begin_comment
comment|// CHECK-NOT: DW_TAG_structure_type
end_comment

begin_struct
struct|struct
name|S
block|{
comment|// CHECK-NOT: DW_TAG_member
name|char
name|a
decl_stmt|;
name|double
name|b
decl_stmt|;
name|constCharPtrArray
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK-NOT: DW_TAG_enumerator
end_comment

begin_comment
comment|// CHECK-NOT: DW_TAG_enumeration_type
end_comment

begin_enum
enum|enum
name|E
block|{
name|ZERO
init|=
literal|0
block|,
name|ONE
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
comment|// CHECK-NOT: DW_TAG_arg_variable
end_comment

begin_function
name|int
name|sum
parameter_list|(
name|int
name|p
parameter_list|,
name|int
name|q
parameter_list|)
block|{
comment|// CHECK-NOT: DW_TAG_auto_variable
name|int
name|r
init|=
name|p
operator|+
name|q
decl_stmt|;
name|struct
name|S
name|s
decl_stmt|;
name|enum
name|E
name|e
decl_stmt|;
return|return
name|r
return|;
block|}
end_function

end_unit

