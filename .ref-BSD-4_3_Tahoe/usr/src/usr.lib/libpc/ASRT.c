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
literal|"@(#)ASRT.c 1.3 11/12/82"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|EASRT
index|[]
init|=
literal|"Assertion failed\n"
decl_stmt|;
end_decl_stmt

begin_macro
name|ASRT
argument_list|(
argument|cond
argument_list|)
end_macro

begin_decl_stmt
name|short
name|cond
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|cond
condition|)
return|return;
name|ERROR
argument_list|(
name|EASRT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

end_unit

