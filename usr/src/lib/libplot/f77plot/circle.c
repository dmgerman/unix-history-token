begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)circle.c	1.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|circle_
argument_list|(
argument|x
argument_list|,
argument|y
argument_list|,
argument|r
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|x
decl_stmt|,
modifier|*
name|y
decl_stmt|,
modifier|*
name|r
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|circle
argument_list|(
operator|*
name|x
argument_list|,
operator|*
name|y
argument_list|,
operator|*
name|r
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

