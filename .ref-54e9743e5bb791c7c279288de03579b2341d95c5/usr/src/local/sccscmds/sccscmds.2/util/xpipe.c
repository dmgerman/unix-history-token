begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|Sccsid
index|[]
init|=
literal|"@(#)xpipe.c	1.2	%G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 	Interface to pipe(II) which handles all error conditions. 	Returns 0 on success, 	fatal() on failure. */
end_comment

begin_macro
name|xpipe
argument_list|(
argument|t
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|t
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|char
name|p
index|[]
init|=
literal|"pipe"
decl_stmt|;
if|if
condition|(
name|pipe
argument_list|(
name|t
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|xmsg
argument_list|(
name|p
argument_list|,
name|p
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

