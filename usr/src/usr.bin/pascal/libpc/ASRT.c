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
literal|"@(#)ASRT.c 1.2 %G%"
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_macro
name|ASRT
argument_list|(
argument|cond
argument_list|,
argument|stmt
argument_list|)
end_macro

begin_decl_stmt
name|short
name|cond
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|stmt
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|cond
condition|)
return|return;
if|if
condition|(
name|stmt
operator|!=
name|NULL
condition|)
block|{
name|ERROR
argument_list|(
literal|"Assertion failed: %s\n"
argument_list|,
name|stmt
argument_list|)
expr_stmt|;
return|return;
block|}
else|else
block|{
name|ERROR
argument_list|(
literal|"Assertion failed\n"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
end_block

end_unit

