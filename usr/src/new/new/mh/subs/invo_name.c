begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This routine returns the address on the stack of the text of the  *  first argument to the process.  It only works on the VAX, and only  *  if the process was not called with 4 empty args in a row.  */
end_comment

begin_function
name|char
modifier|*
name|invo_name
parameter_list|()
block|{
specifier|register
name|int
modifier|*
name|ip
decl_stmt|;
name|ip
operator|=
operator|(
name|int
operator|*
operator|)
literal|0x7ffffff8
expr_stmt|;
comment|/* Highest stack address -4 */
while|while
condition|(
operator|*
operator|--
name|ip
operator|!=
literal|0
condition|)
comment|/* Look backwards for bumber */
empty_stmt|;
return|return
operator|(
name|char
operator|*
operator|)
operator|&
name|ip
index|[
literal|1
index|]
return|;
comment|/* Next string is it. */
block|}
end_function

end_unit

