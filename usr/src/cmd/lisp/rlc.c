begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)rlc.c	34.2 10/9/80"
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_decl_stmt
specifier|extern
name|char
name|holend
index|[]
decl_stmt|,
name|end
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|usehole
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|curhbeg
decl_stmt|;
end_decl_stmt

begin_macro
name|rlc
argument_list|()
end_macro

begin_block
block|{
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|dp
decl_stmt|;
name|brk
argument_list|(
name|end
argument_list|)
expr_stmt|;
name|dp
operator|=
name|holend
expr_stmt|;
name|cp
operator|=
name|dp
operator|-
name|HOLE
expr_stmt|;
while|while
condition|(
name|dp
operator|<
name|end
condition|)
operator|*
name|dp
operator|++
operator|=
operator|*
name|cp
operator|++
expr_stmt|;
name|curhbeg
operator|=
name|holend
operator|-
name|HOLE
expr_stmt|;
comment|/* set up the hole */
name|usehole
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

end_unit

