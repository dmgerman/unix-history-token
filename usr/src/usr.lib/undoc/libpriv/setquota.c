begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	%W%	(Melbourne)	%E%	*/
end_comment

begin_macro
name|setquota
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|,
argument|c
argument_list|,
argument|d
argument_list|)
end_macro

begin_block
block|{
return|return
operator|(
name|syscall
argument_list|(
literal|64
operator|+
literal|61
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

