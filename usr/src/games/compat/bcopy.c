begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_macro
name|bcopy
argument_list|(
argument|from
argument_list|,
argument|to
argument_list|,
argument|count
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|from
decl_stmt|,
modifier|*
name|to
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{
asm|asm("	movc3	12(ap),*4(ap),*8(ap)");
block|}
end_block

begin_macro
name|seteuid
argument_list|(
argument|n
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_macro
name|setegid
argument_list|(
argument|n
argument_list|)
end_macro

begin_block
block|{ }
end_block

end_unit

