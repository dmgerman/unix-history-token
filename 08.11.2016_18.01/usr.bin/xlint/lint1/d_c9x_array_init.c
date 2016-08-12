begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* C9X array initializers */
end_comment

begin_decl_stmt
name|int
name|foo
index|[
literal|256
index|]
init|=
block|{
index|[
literal|2
index|]
operator|=
literal|1
block|,
index|[
literal|3
index|]
operator|=
literal|2
block|,
index|[
literal|4
operator|...
literal|5
index|]
operator|=
literal|3
block|}
decl_stmt|;
end_decl_stmt

end_unit

