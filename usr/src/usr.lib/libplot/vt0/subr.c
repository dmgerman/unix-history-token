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
literal|"@(#)subr.c	4.1 (Berkeley) 6/27/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|float
name|obotx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|oboty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|boty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|botx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|scalex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|scaley
decl_stmt|;
end_decl_stmt

begin_macro
name|xsc
argument_list|(
argument|xi
argument_list|)
end_macro

begin_block
block|{
name|int
name|xa
decl_stmt|;
name|xa
operator|=
operator|(
name|xi
operator|-
name|obotx
operator|)
operator|*
name|scalex
operator|+
name|botx
expr_stmt|;
return|return
operator|(
name|xa
operator|)
return|;
block|}
end_block

begin_macro
name|ysc
argument_list|(
argument|yi
argument_list|)
end_macro

begin_block
block|{
name|int
name|ya
decl_stmt|;
name|ya
operator|=
operator|(
name|yi
operator|-
name|oboty
operator|)
operator|*
name|scaley
operator|+
name|boty
expr_stmt|;
return|return
operator|(
name|ya
operator|)
return|;
block|}
end_block

end_unit

