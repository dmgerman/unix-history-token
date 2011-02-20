begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s  -o /dev/null
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_struct
specifier|static
specifier|const
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|type
decl_stmt|;
block|}
name|scan_special
index|[]
init|=
block|{
block|{
literal|"shift"
block|,
literal|1
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
struct|;
end_struct

begin_function
specifier|static
name|void
name|sb
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
operator|*
name|str
operator|==
literal|' '
operator|||
operator|*
name|str
operator|==
literal|'\t'
condition|)
name|str
operator|++
expr_stmt|;
block|}
end_function

end_unit

