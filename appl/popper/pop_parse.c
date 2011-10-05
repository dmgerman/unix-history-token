begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_include
include|#
directive|include
file|<popper.h>
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  *  parse:  Parse a raw input line from a POP client  *  into null-delimited tokens  */
end_comment

begin_function
name|int
name|pop_parse
parameter_list|(
name|POP
modifier|*
name|p
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
block|{
name|char
modifier|*
name|mp
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|/*  Loop through the POP command array */
for|for
control|(
name|mp
operator|=
name|buf
operator|,
name|i
operator|=
literal|0
init|;
condition|;
name|i
operator|++
control|)
block|{
comment|/*  Skip leading spaces and tabs in the message */
while|while
condition|(
name|isspace
argument_list|(
operator|(
name|unsigned
name|char
operator|)
operator|*
name|mp
argument_list|)
condition|)
name|mp
operator|++
expr_stmt|;
comment|/*  Are we at the end of the message? */
if|if
condition|(
operator|*
name|mp
operator|==
literal|0
condition|)
break|break;
comment|/*  Have we already obtained the maximum allowable parameters? */
if|if
condition|(
name|i
operator|>=
name|MAXPARMCOUNT
condition|)
block|{
name|pop_msg
argument_list|(
name|p
argument_list|,
name|POP_FAILURE
argument_list|,
literal|"Too many arguments supplied."
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/*  Point to the start of the token */
name|p
operator|->
name|pop_parm
index|[
name|i
index|]
operator|=
name|mp
expr_stmt|;
comment|/*  Search for the first space character (end of the token) */
while|while
condition|(
operator|!
name|isspace
argument_list|(
operator|(
name|unsigned
name|char
operator|)
operator|*
name|mp
argument_list|)
operator|&&
operator|*
name|mp
condition|)
name|mp
operator|++
expr_stmt|;
comment|/*  Delimit the token with a null */
if|if
condition|(
operator|*
name|mp
condition|)
operator|*
name|mp
operator|++
operator|=
literal|0
expr_stmt|;
block|}
comment|/*  Were any parameters passed at all? */
if|if
condition|(
name|i
operator|==
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/*  Convert the first token (POP command) to lower case */
name|strlwr
argument_list|(
name|p
operator|->
name|pop_command
argument_list|)
expr_stmt|;
comment|/*  Return the number of tokens extracted minus the command itself */
return|return
operator|(
name|i
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

