begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o - | opt -std-compile-opts | \
end_comment

begin_comment
comment|// RUN:    llvm-dis | grep {@nate.*internal global i32 0}
end_comment

begin_struct
struct|struct
name|X
block|{
name|int
modifier|*
name|XX
decl_stmt|;
name|int
name|Y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|foo
parameter_list|()
block|{
specifier|static
name|int
name|nate
init|=
literal|0
decl_stmt|;
name|struct
name|X
name|bob
init|=
block|{
operator|&
name|nate
block|,
literal|14
block|}
decl_stmt|;
name|bar
argument_list|(
operator|&
name|bob
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

