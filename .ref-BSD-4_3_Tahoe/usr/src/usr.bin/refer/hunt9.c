begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)hunt9.c	4.1 (Berkeley) 5/6/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|remote
argument_list|(
argument|in
argument_list|,
argument|out
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|in
decl_stmt|,
modifier|*
name|out
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* "in" is a long distance file name: get it */
empty_stmt|;
block|}
end_block

end_unit

