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
literal|"@(#)EXPO.c 1.1 10/29/80"
decl_stmt|;
end_decl_stmt

begin_macro
name|EXPO
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
if|if
condition|(
name|value
operator|==
literal|0
condition|)
return|return
literal|0
return|;
return|return
operator|(
operator|(
name|value
operator|&
operator|~
literal|0xffff8000
operator|)
operator|>>
literal|7
operator|)
operator|-
literal|128
return|;
block|}
end_block

end_unit

