begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_macro
name|signal_
argument_list|(
argument|sigp
argument_list|,
argument|procp
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|sigp
decl_stmt|,
argument_list|(
operator|*
operator|*
name|procp
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|signal
argument_list|(
operator|*
name|sigp
argument_list|,
operator|*
name|procp
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

