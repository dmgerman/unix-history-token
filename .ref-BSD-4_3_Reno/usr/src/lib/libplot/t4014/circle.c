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
literal|"@(#)circle.c	4.1 (Berkeley) 6/27/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|circle
argument_list|(
argument|x
argument_list|,
argument|y
argument_list|,
argument|r
argument_list|)
end_macro

begin_block
block|{
name|arc
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|x
operator|+
name|r
argument_list|,
name|y
argument_list|,
name|x
operator|+
name|r
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

