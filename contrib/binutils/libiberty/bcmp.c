begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bcmp    This function is in the public domain.  */
end_comment

begin_comment
comment|/*  NAME  	bcmp -- compare two memory regions  SYNOPSIS  	int bcmp (char *from, char *to, int count)  DESCRIPTION  	Compare two memory regions and return zero if they are identical, 	non-zero otherwise.  If count is zero, return zero.  NOTES  	No guarantee is made about the non-zero returned value.  In 	particular, the results may be signficantly different than 	strcmp(), where the return value is guaranteed to be less than, 	equal to, or greater than zero, according to lexicographical 	sorting of the compared regions.  BUGS  */
end_comment

begin_function
name|int
name|bcmp
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|count
parameter_list|)
name|char
modifier|*
name|from
decl_stmt|,
decl|*
name|to
decl_stmt|;
end_function

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|rtnval
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|count
operator|--
operator|>
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|from
operator|++
operator|!=
operator|*
name|to
operator|++
condition|)
block|{
name|rtnval
operator|=
literal|1
expr_stmt|;
break|break;
block|}
block|}
return|return
operator|(
name|rtnval
operator|)
return|;
block|}
end_block

end_unit

