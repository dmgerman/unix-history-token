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
literal|"@(#)open.c	4.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|xnow
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ynow
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|float
name|boty
literal|0.
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|float
name|botx
literal|0.
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|float
name|oboty
literal|0.
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|float
name|obotx
literal|0.
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|float
name|scalex
literal|1.
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|float
name|scaley
literal|1.
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|vti
operator|-
literal|1
expr_stmt|;
end_expr_stmt

begin_macro
name|openvt
argument_list|()
end_macro

begin_block
block|{
name|vti
operator|=
name|open
argument_list|(
literal|"/dev/vt0"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

begin_macro
name|openpl
argument_list|()
end_macro

begin_block
block|{
name|vti
operator|=
name|open
argument_list|(
literal|"/dev/vt0"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

end_unit

