begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bcmp    This function is in the public domain.  */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental int bcmp (char *@var{x}, char *@var{y}, int @var{count})  Compares the first @var{count} bytes of two areas of memory.  Returns zero if they are the same, nonzero otherwise.  Returns zero if @var{count} is zero.  A nonzero result only indicates a difference, it does not indicate any sorting order (say, by having a positive result mean @var{x} sorts before @var{y}).  @end deftypefn  */
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

