begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__thread
name|yy1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__thread
name|xx1
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__thread
name|xx2
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__thread
name|xxa
index|[
literal|10
index|]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|xxyy
parameter_list|()
block|{
return|return
name|yy1
return|;
block|}
end_function

end_unit

