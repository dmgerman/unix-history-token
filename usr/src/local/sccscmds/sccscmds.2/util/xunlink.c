begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|Sccsid
index|[]
init|=
literal|"@(#)xunlink.c	1.2	%G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 	Interface to unlink(II) which handles all error conditions. 	Returns 0 on success, 	fatal() on failure. */
end_comment

begin_macro
name|xunlink
argument_list|(
argument|f
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|unlink
argument_list|(
name|f
argument_list|)
condition|)
return|return
operator|(
name|xmsg
argument_list|(
name|f
argument_list|,
literal|"xunlink"
argument_list|)
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

