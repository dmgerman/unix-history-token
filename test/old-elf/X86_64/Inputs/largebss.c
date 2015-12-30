begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|largebss
index|[
literal|1000
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|largecommon
index|[
literal|1000
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__thread
name|int
name|largetbss
index|[
literal|1000
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

