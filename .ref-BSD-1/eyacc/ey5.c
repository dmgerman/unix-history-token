begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fake portable I/O routines, for those     sites so backward as to not have the      port. library */
end_comment

begin_decl_stmt
name|int
name|cin
decl_stmt|,
name|cout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fin
decl_stmt|,
name|fout
decl_stmt|;
end_decl_stmt

begin_macro
name|copen
argument_list|(
argument|s
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|f
decl_stmt|;
if|if
condition|(
name|c
operator|==
literal|'r'
condition|)
block|{
name|fin
operator|=
name|f
operator|=
name|open
argument_list|(
name|s
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|c
operator|==
literal|'a'
condition|)
block|{
name|f
operator|=
name|open
argument_list|(
name|s
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|seek
argument_list|(
name|f
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* c == w */
name|f
operator|=
name|creat
argument_list|(
name|s
argument_list|,
literal|0666
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|f
operator|)
return|;
block|}
end_block

begin_macro
name|cflush
argument_list|(
argument|x
argument_list|)
end_macro

begin_block
block|{
comment|/* fake! sets file to x */
name|flush
argument_list|()
expr_stmt|;
name|fout
operator|=
name|x
expr_stmt|;
block|}
end_block

begin_macro
name|system
argument_list|()
end_macro

begin_block
block|{
name|error
argument_list|(
literal|"The function \"system\" is called"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|cclose
argument_list|(
argument|i
argument_list|)
end_macro

begin_block
block|{
name|close
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|cexit
argument_list|(
argument|i
argument_list|)
end_macro

begin_block
block|{
name|flush
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

