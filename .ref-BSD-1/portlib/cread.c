begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  **	block read  **/
end_comment

begin_macro
name|cread
argument_list|(
argument|buff
argument_list|,
argument|itemlen
argument_list|,
argument|nitems
argument_list|,
argument|fn
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|buff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|itemlen
decl_stmt|,
name|nitems
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fn
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|n
decl_stmt|;
specifier|register
name|int
name|r
decl_stmt|;
name|n
operator|=
name|read
argument_list|(
name|fn
argument_list|,
name|buff
argument_list|,
name|itemlen
operator|*
name|nitems
argument_list|)
expr_stmt|;
name|r
operator|=
name|n
operator|<
literal|0
condition|?
operator|-
literal|1
else|:
name|n
operator|/
name|itemlen
expr_stmt|;
return|return
operator|(
name|r
operator|)
return|;
block|}
end_block

end_unit

