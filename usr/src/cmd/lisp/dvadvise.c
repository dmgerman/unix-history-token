begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)dvadvise.c	34.1 10/3/80"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dummy vadvise function - used when creating a lisp which will run    on an operating system without vadvise. */
end_comment

begin_macro
name|vadvise
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

