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
literal|"@(#)arc.c	4.1 (Berkeley) 6/27/83"
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
name|arc
argument_list|(
argument|xi
argument_list|,
argument|yi
argument_list|,
argument|x0
argument_list|,
argument|y0
argument_list|,
argument|x1
argument_list|,
argument|y1
argument_list|)
end_macro

begin_block
block|{
name|char
name|c
decl_stmt|;
name|c
operator|=
literal|6
expr_stmt|;
name|write
argument_list|(
name|vti
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|vti
argument_list|,
operator|&
name|xi
argument_list|,
literal|12
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

