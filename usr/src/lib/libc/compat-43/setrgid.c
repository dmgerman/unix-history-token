begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	setrgid.c	4.1	83/06/30	*/
end_comment

begin_macro
name|setrgid
argument_list|(
argument|rgid
argument_list|)
end_macro

begin_decl_stmt
name|int
name|rgid
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|setregid
argument_list|(
name|rgid
argument_list|,
operator|-
literal|1
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

