begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)exit.c	5.2 (Berkeley) 3/9/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_macro
name|exit
argument_list|(
argument|code
argument_list|)
end_macro

begin_decl_stmt
name|int
name|code
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|_cleanup
argument_list|()
expr_stmt|;
name|_exit
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

