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
literal|"@(#)blkclr.c 1.1 3/7/81"
decl_stmt|;
end_decl_stmt

begin_macro
name|blkclr
argument_list|(
argument|siz
argument_list|,
argument|at
argument_list|)
end_macro

begin_decl_stmt
name|long
name|siz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|at
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|size
init|=
name|siz
decl_stmt|;
while|while
condition|(
name|size
operator|--
operator|>
literal|0
condition|)
operator|*
name|at
operator|++
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit

