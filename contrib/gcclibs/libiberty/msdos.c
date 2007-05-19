begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
name|msg
index|[]
init|=
literal|"No vfork available - aborting\n"
decl_stmt|;
end_decl_stmt

begin_macro
name|vfork
argument_list|()
end_macro

begin_block
block|{
name|write
argument_list|(
literal|1
argument_list|,
name|msg
argument_list|,
sizeof|sizeof
argument_list|(
name|msg
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|sigsetmask
argument_list|()
end_macro

begin_block
block|{
comment|/* no signals support in go32 (yet) */
block|}
end_block

begin_macro
name|waitpid
argument_list|()
end_macro

begin_block
block|{
return|return
operator|-
literal|1
return|;
block|}
end_block

end_unit

