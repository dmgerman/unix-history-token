begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|Sccsid
index|[]
init|=
literal|"@(#)verify.c	1.2	%G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 	If `astr1' contains any characters not in `str2' return the 	offset of the first such character found in `astr1', 	else return -1. */
end_comment

begin_macro
name|verify
argument_list|(
argument|astr1
argument_list|,
argument|str2
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|astr1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|str2
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|str1
decl_stmt|;
for|for
control|(
name|str1
operator|=
name|astr1
init|;
operator|*
name|str1
condition|;
name|str1
operator|++
control|)
if|if
condition|(
operator|!
name|any
argument_list|(
operator|*
name|str1
argument_list|,
name|str2
argument_list|)
condition|)
return|return
operator|(
name|str1
operator|-
name|astr1
operator|-
literal|1
operator|)
return|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

end_unit

