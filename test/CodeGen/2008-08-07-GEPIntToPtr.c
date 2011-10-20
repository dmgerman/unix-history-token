begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// PR2603
end_comment

begin_struct
struct|struct
name|A
block|{
name|char
name|num_fields
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|B
block|{
name|char
name|a
decl_stmt|,
name|b
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|const
name|struct
name|A
name|Foo
init|=
block|{
comment|// CHECK: i8 1
operator|(
name|char
operator|*
operator|)
operator|(
operator|&
operator|(
operator|(
expr|struct
name|B
operator|*
operator|)
operator|(
literal|16
operator|)
operator|)
operator|->
name|b
index|[
literal|0
index|]
operator|)
operator|-
operator|(
name|char
operator|*
operator|)
operator|(
literal|16
operator|)
block|}
decl_stmt|;
end_decl_stmt

end_unit

