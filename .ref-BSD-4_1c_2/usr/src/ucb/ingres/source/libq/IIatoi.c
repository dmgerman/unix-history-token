begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)IIatoi.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  IIatoi() **  ASCII CHARACTER STRING TO 16-BIT INTEGER CONVERSION ** **	`a' is a pointer to the character string, `i' is a **	pointer to the word which is to contain the result. ** **	The return value of the function is: **		zero:	succesful conversion; `i' contains the integer **		+1:	numeric overflow; `i' is unchanged **		-1:	syntax error; `i' is unchanged ** **	A valid string is of the form: **<space>* [+-]<space>*<digit>*<space>* ** **		Eric's utility routine. ** */
end_comment

begin_macro
name|IIatoi
argument_list|(
argument|a1
argument_list|,
argument|i
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|i
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|sign
decl_stmt|;
comment|/* flag to indicate the sign */
specifier|register
name|int
name|x
decl_stmt|;
comment|/* holds the integer being formed */
specifier|register
name|char
name|c
decl_stmt|;
specifier|register
name|char
modifier|*
name|a
decl_stmt|;
name|a
operator|=
name|a1
expr_stmt|;
name|sign
operator|=
literal|0
expr_stmt|;
comment|/* skip leading blanks */
while|while
condition|(
operator|*
name|a
operator|==
literal|' '
condition|)
name|a
operator|++
expr_stmt|;
comment|/* check for sign */
switch|switch
condition|(
operator|*
name|a
condition|)
block|{
case|case
literal|'-'
case|:
name|sign
operator|=
operator|-
literal|1
expr_stmt|;
case|case
literal|'+'
case|:
while|while
condition|(
operator|*
operator|++
name|a
operator|==
literal|' '
condition|)
empty_stmt|;
block|}
comment|/* at this point everything had better be numeric */
name|x
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|a
operator|)
operator|<=
literal|'9'
operator|&&
name|c
operator|>=
literal|'0'
condition|)
block|{
if|if
condition|(
name|x
operator|>
literal|3276
operator|||
operator|(
name|x
operator|==
literal|3276
operator|&&
name|c
operator|>
literal|'7'
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* overflow */
name|x
operator|=
name|x
operator|*
literal|10
operator|+
name|c
operator|-
literal|'0'
expr_stmt|;
name|a
operator|++
expr_stmt|;
block|}
comment|/* eaten all the numerics; better be all blanks */
while|while
condition|(
name|c
operator|=
operator|*
name|a
operator|++
condition|)
if|if
condition|(
name|c
operator|!=
literal|' '
condition|)
comment|/* syntax error */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
operator|*
name|i
operator|=
name|sign
condition|?
operator|-
name|x
else|:
name|x
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
comment|/* successful termination */
block|}
end_block

end_unit

