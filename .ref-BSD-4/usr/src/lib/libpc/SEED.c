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
literal|"@(#)SEED.c 1.1 10/29/80"
decl_stmt|;
end_decl_stmt

begin_macro
name|SEED
argument_list|(
argument|value
argument_list|)
end_macro

begin_decl_stmt
name|long
name|value
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|long
name|seed
decl_stmt|;
name|long
name|tmp
decl_stmt|;
name|srand
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|tmp
operator|=
name|seed
expr_stmt|;
name|seed
operator|=
name|value
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_block

end_unit

