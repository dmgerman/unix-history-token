begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_macro
name|stmes
argument_list|(
argument|code
argument_list|)
end_macro

begin_decl_stmt
name|int
name|code
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|mesp
decl_stmt|;
name|mesp
operator|=
literal|" : err reg         "
expr_stmt|;
name|l2x
argument_list|(
name|code
argument_list|,
operator|&
name|mesp
index|[
literal|11
index|]
argument_list|)
expr_stmt|;
name|putlin
argument_list|(
name|mesp
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

