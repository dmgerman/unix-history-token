begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*         This program is, essentially, a cross product generator.  It takes         an input file which is said to consist of a number of lines, and         expands each line.  A line like                 (a,b)(c,d)         will be expanded to lines like                 ac                 ad                 bc                 bd         (without regard for the ORDER of the output; ie: the lines can appear         in any order).          Parenthesis can be nested, so                 (a,b)(c(d,e),f)         will produce                 acd                 ace                 af                 bcd                 bce                 bf  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|char
name|leftParen
decl_stmt|,
comment|/* The left parenthesis character */
name|rightParen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The right parenthesis character */
end_comment

begin_comment
comment|/* Finds next occurrence of 'character' at this level of nesting.         Returns 0 if no such character found.  */
end_comment

begin_function
name|char
modifier|*
name|ThisLevel
parameter_list|(
name|string
parameter_list|,
name|character
parameter_list|)
name|char
modifier|*
name|string
decl_stmt|,
name|character
decl_stmt|;
block|{
name|int
name|level
decl_stmt|;
comment|/* Level 0 is OUR level */
name|level
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|*
name|string
operator|!=
literal|'\0'
condition|)
block|{
if|if
condition|(
operator|*
name|string
operator|==
name|leftParen
condition|)
name|level
operator|++
expr_stmt|;
elseif|else
if|if
condition|(
operator|*
name|string
operator|==
name|rightParen
condition|)
block|{
name|level
operator|--
expr_stmt|;
if|if
condition|(
name|level
operator|<
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
operator|(
name|level
operator|==
literal|0
operator|)
operator|&&
operator|(
operator|*
name|string
operator|==
name|character
operator|)
condition|)
return|return
operator|(
name|string
operator|)
return|;
name|string
operator|++
expr_stmt|;
block|}
end_function

end_unit

