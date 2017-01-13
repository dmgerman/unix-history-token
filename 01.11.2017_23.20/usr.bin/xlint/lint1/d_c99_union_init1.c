begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* C99 union initialization */
end_comment

begin_union
union|union
block|{
name|int
name|i
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
block|}
name|c
index|[]
init|=
block|{
block|{
name|i
operator|:
literal|1
block|}
block|,
block|{
name|s
operator|:
literal|"foo"
block|}
block|}
union|;
end_union

end_unit

