begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* compound literals */
end_comment

begin_struct
struct|struct
name|p
block|{
name|short
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|;
block|}
struct|;
end_struct

begin_macro
name|foo
argument_list|()
end_macro

begin_block
block|{
name|struct
name|p
name|me
init|=
operator|(
expr|struct
name|p
operator|)
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|me
operator|.
name|a
operator|=
name|me
operator|.
name|b
expr_stmt|;
block|}
end_block

end_unit

