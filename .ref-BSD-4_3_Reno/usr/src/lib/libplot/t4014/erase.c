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
literal|"@(#)erase.c	4.2 (Berkeley) 1/2/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|ohiy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ohix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|oloy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|oextra
decl_stmt|;
end_decl_stmt

begin_macro
name|erase
argument_list|()
end_macro

begin_block
block|{
name|int
name|i
decl_stmt|;
name|putch
argument_list|(
literal|033
argument_list|)
expr_stmt|;
name|putch
argument_list|(
literal|014
argument_list|)
expr_stmt|;
name|ohiy
operator|=
operator|-
literal|1
expr_stmt|;
name|ohix
operator|=
operator|-
literal|1
expr_stmt|;
name|oextra
operator|=
operator|-
literal|1
expr_stmt|;
name|oloy
operator|=
operator|-
literal|1
expr_stmt|;
return|return;
block|}
end_block

end_unit

