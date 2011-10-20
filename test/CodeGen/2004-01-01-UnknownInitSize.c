begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o /dev/null
end_comment

begin_comment
comment|/*  * This regression test ensures that the C front end can compile initializers  * even when it cannot determine the size (as below). */
end_comment

begin_struct
struct|struct
name|one
block|{
name|int
name|a
decl_stmt|;
name|int
name|values
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|one
name|hobbit
init|=
block|{
literal|5
block|,
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

