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
literal|"@(#)erase.c	4.1 (Berkeley) 6/27/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern vti;
end_extern

begin_macro
name|erase
argument_list|()
end_macro

begin_block
block|{
name|int
name|i
decl_stmt|;
name|i
operator|=
literal|0401
expr_stmt|;
name|write
argument_list|(
name|vti
argument_list|,
operator|&
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

