begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  **	input character from standard input.  **	the global variable "cin" may be set to the descriptor  **		of the file to be input from.  Its default is zero.  **/
end_comment

begin_macro
name|getchar
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|int
name|cin
decl_stmt|;
return|return
operator|(
name|cgetc
argument_list|(
name|cin
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

