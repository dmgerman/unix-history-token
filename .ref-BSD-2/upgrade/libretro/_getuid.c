begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* getuid is supposed to return full word (integer) uid */
end_comment

begin_macro
name|_getuid
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|getuid
argument_list|()
operator|&
literal|0377
operator|)
return|;
block|}
end_block

end_unit

