begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_macro
name|putchar
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
extern|extern cout;
name|cputc
argument_list|(
name|c
argument_list|,
name|cout
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

