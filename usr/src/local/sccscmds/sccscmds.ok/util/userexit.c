begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|Sccsid
index|[]
init|=
literal|"@(#)userexit.c	1.2	%G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 	Default userexit routine for fatal and setsig. 	User supplied userexit routines can be used for logging. */
end_comment

begin_macro
name|userexit
argument_list|(
argument|code
argument_list|)
end_macro

begin_block
block|{
return|return
operator|(
name|code
operator|)
return|;
block|}
end_block

end_unit

