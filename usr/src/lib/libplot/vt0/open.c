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
literal|"@(#)open.c	4.2 (Berkeley) 11/10/83"
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

begin_decl_stmt
name|float
name|boty
init|=
literal|0.
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|botx
init|=
literal|0.
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|oboty
init|=
literal|0.
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|obotx
init|=
literal|0.
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|scalex
init|=
literal|1.
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|scaley
init|=
literal|1.
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vti
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

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

