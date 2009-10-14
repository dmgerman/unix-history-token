begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* This testcase doesn't actually test a bug, it's just the result of me   * figuring out the syntax for forward declaring a static variable. */
end_comment

begin_struct
struct|struct
name|list
block|{
name|int
name|x
decl_stmt|;
name|struct
name|list
modifier|*
name|Next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|list
name|B
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward declare static */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|list
name|A
init|=
block|{
literal|7
block|,
operator|&
name|B
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|list
name|B
init|=
block|{
literal|8
block|,
operator|&
name|A
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|list
name|D
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* forward declare normal var */
end_comment

begin_decl_stmt
name|struct
name|list
name|C
init|=
block|{
literal|7
block|,
operator|&
name|D
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|list
name|D
init|=
block|{
literal|8
block|,
operator|&
name|C
block|}
decl_stmt|;
end_decl_stmt

end_unit

