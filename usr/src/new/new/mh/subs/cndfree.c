begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Conditional free -- perform a free call if the address passed  * is in free storage;  else NOP  */
end_comment

begin_macro
name|cndfree
argument_list|(
argument|addr
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|addr
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|char
name|end
decl_stmt|;
if|if
condition|(
name|addr
operator|>=
operator|&
name|end
condition|)
name|free
argument_list|(
name|addr
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

