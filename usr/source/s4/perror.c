begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_macro
name|perror
argument_list|(
argument|s
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
name|char
modifier|*
name|c
decl_stmt|;
name|c
operator|=
literal|"Unknown error"
expr_stmt|;
if|if
condition|(
name|errno
operator|<
name|sys_nerr
condition|)
name|c
operator|=
name|sys_errlist
index|[
name|errno
index|]
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
literal|'\0'
condition|)
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|c
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"%s: %s\n"
argument_list|,
name|s
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

