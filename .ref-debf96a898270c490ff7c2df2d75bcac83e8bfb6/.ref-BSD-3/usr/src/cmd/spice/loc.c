begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* return the address of arg */
end_comment

begin_macro
name|loc_
argument_list|(
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|int
operator|)
name|arg
return|;
block|}
end_block

begin_comment
comment|/* c program to call library routine times*/
end_comment

begin_macro
name|times_
argument_list|(
argument|iarg
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|iarg
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|times
argument_list|(
name|iarg
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

