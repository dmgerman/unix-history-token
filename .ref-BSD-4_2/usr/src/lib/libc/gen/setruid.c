begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	setruid.c	4.1	83/06/30	*/
end_comment

begin_macro
name|setruid
argument_list|(
argument|ruid
argument_list|)
end_macro

begin_decl_stmt
name|int
name|ruid
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|setreuid
argument_list|(
name|ruid
argument_list|,
operator|-
literal|1
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

