begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)ZFRAME.c 1.1 10/29/80"
decl_stmt|;
end_decl_stmt

begin_macro
name|ZFRAME
argument_list|(
argument|size
argument_list|,
argument|ptr
argument_list|)
end_macro

begin_decl_stmt
name|int
name|size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|long
modifier|*
name|ptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|long
modifier|*
name|end
decl_stmt|;
name|short
modifier|*
name|sptr
decl_stmt|;
name|end
operator|=
name|ptr
operator|+
operator|(
name|size
operator|/
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|)
expr_stmt|;
for|for
control|(
init|;
name|ptr
operator|<
name|end
condition|;
operator|*
name|ptr
operator|++
operator|=
literal|0
control|)
comment|/* void */
empty_stmt|;
if|if
condition|(
name|size
operator|%
sizeof|sizeof
argument_list|(
name|long
argument_list|)
condition|)
block|{
name|sptr
operator|=
operator|(
name|short
operator|*
operator|)
name|ptr
expr_stmt|;
operator|*
name|sptr
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_block

end_unit

