begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1982 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)CASERNG.c 1.1 2/2/82"
decl_stmt|;
end_decl_stmt

begin_macro
name|CASERNG
argument_list|(
argument|val
argument_list|)
end_macro

begin_decl_stmt
name|int
name|val
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|ERROR
argument_list|(
literal|"Label of %D not found in case\n"
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

