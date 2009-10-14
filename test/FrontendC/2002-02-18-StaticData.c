begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_decl_stmt
name|double
name|FOO
init|=
literal|17
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|BAR
init|=
literal|12.0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|XX
init|=
literal|12.0f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|procnames
index|[]
init|=
block|{
literal|"EXIT"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|Data
index|[]
init|=
block|{
operator|&
name|FOO
block|,
operator|&
name|BAR
block|,
operator|&
name|XX
block|}
decl_stmt|;
end_decl_stmt

end_unit

