begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S -g %s  -o /dev/null
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|out
index|[]
init|=
block|{
literal|0
block|,
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|unsigned
name|char
name|str1
index|[]
init|=
literal|"1"
decl_stmt|;
end_decl_stmt

end_unit

