begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	setgid.c	4.1	83/06/30	*/
end_comment

begin_comment
comment|/*  * Backwards compatible setgid.  */
end_comment

begin_macro
name|setgid
argument_list|(
argument|gid
argument_list|)
end_macro

begin_decl_stmt
name|int
name|gid
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|setregid
argument_list|(
name|gid
argument_list|,
name|gid
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

