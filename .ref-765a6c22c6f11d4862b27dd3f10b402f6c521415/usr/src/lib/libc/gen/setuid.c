begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	setuid.c	4.1	83/06/30	*/
end_comment

begin_comment
comment|/*  * Backwards compatible setuid.  */
end_comment

begin_macro
name|setuid
argument_list|(
argument|uid
argument_list|)
end_macro

begin_decl_stmt
name|int
name|uid
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|setreuid
argument_list|(
name|uid
argument_list|,
name|uid
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

