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
literal|"@(#)scale.c	4.1 (Berkeley) 6/27/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_decl_stmt
specifier|extern
name|int
name|scaleflag
decl_stmt|;
end_decl_stmt

begin_macro
name|scale
argument_list|(
argument|i
argument_list|,
argument|x
argument_list|,
argument|y
argument_list|)
end_macro

begin_decl_stmt
name|char
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|x
decl_stmt|,
name|y
decl_stmt|;
end_decl_stmt

begin_block
block|{
switch|switch
condition|(
name|i
condition|)
block|{
default|default:
return|return;
case|case
literal|'c'
case|:
name|x
operator|*=
literal|2.54
expr_stmt|;
name|y
operator|*=
literal|2.54
expr_stmt|;
case|case
literal|'i'
case|:
name|x
operator|/=
literal|200
expr_stmt|;
name|y
operator|/=
literal|200
expr_stmt|;
case|case
literal|'u'
case|:
name|scalex
operator|=
literal|1
operator|/
name|x
expr_stmt|;
name|scaley
operator|=
literal|1
operator|/
name|y
expr_stmt|;
block|}
name|scaleflag
operator|=
literal|1
expr_stmt|;
block|}
end_block

end_unit

