begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1983, 1995-1997 Eric P. Allman.  All rights reserved.  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_include
include|#
directive|include
file|<sendmail.h>
end_include

begin_macro
name|SM_RCSID
argument_list|(
literal|"@(#)$Id: sysexits.c,v 8.33 2001/09/11 04:05:17 gshapiro Exp $"
argument_list|)
end_macro

begin_comment
comment|/* **  DSNTOEXITSTAT -- convert DSN-style error code to EX_ style. ** **	Parameters: **		dsncode -- the text of the DSN-style code. ** **	Returns: **		The corresponding exit status. */
end_comment

begin_function
name|int
name|dsntoexitstat
parameter_list|(
name|dsncode
parameter_list|)
name|char
modifier|*
name|dsncode
decl_stmt|;
block|{
name|int
name|code2
decl_stmt|,
name|code3
decl_stmt|;
comment|/* first the easy cases.... */
if|if
condition|(
operator|*
name|dsncode
operator|==
literal|'2'
condition|)
return|return
name|EX_OK
return|;
if|if
condition|(
operator|*
name|dsncode
operator|==
literal|'4'
condition|)
return|return
name|EX_TEMPFAIL
return|;
comment|/* now decode the other two field parts */
if|if
condition|(
operator|*
operator|++
name|dsncode
operator|==
literal|'.'
condition|)
name|dsncode
operator|++
expr_stmt|;
name|code2
operator|=
name|atoi
argument_list|(
name|dsncode
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|dsncode
operator|!=
literal|'\0'
operator|&&
operator|*
name|dsncode
operator|!=
literal|'.'
condition|)
name|dsncode
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|dsncode
operator|!=
literal|'\0'
condition|)
name|dsncode
operator|++
expr_stmt|;
name|code3
operator|=
name|atoi
argument_list|(
name|dsncode
argument_list|)
expr_stmt|;
comment|/* and do a nested switch to work them out */
switch|switch
condition|(
name|code2
condition|)
block|{
case|case
literal|0
case|:
comment|/* Other or Undefined status */
return|return
name|EX_UNAVAILABLE
return|;
case|case
literal|1
case|:
comment|/* Address Status */
switch|switch
condition|(
name|code3
condition|)
block|{
case|case
literal|0
case|:
comment|/* Other Address Status */
return|return
name|EX_DATAERR
return|;
case|case
literal|1
case|:
comment|/* Bad destination mailbox address */
case|case
literal|6
case|:
comment|/* Mailbox has moved, No forwarding address */
return|return
name|EX_NOUSER
return|;
case|case
literal|2
case|:
comment|/* Bad destination system address */
case|case
literal|8
case|:
comment|/* Bad senders system address */
return|return
name|EX_NOHOST
return|;
case|case
literal|3
case|:
comment|/* Bad destination mailbox address syntax */
case|case
literal|7
case|:
comment|/* Bad senders mailbox address syntax */
return|return
name|EX_USAGE
return|;
case|case
literal|4
case|:
comment|/* Destination mailbox address ambiguous */
return|return
name|EX_UNAVAILABLE
return|;
case|case
literal|5
case|:
comment|/* Destination address valid */
return|return
name|EX_OK
return|;
block|}
break|break;
case|case
literal|2
case|:
comment|/* Mailbox Status */
switch|switch
condition|(
name|code3
condition|)
block|{
case|case
literal|0
case|:
comment|/* Other or Undefined mailbox status */
case|case
literal|1
case|:
comment|/* Mailbox disabled, not accepting messages */
case|case
literal|2
case|:
comment|/* Mailbox full */
case|case
literal|4
case|:
comment|/* Mailing list expansion problem */
return|return
name|EX_UNAVAILABLE
return|;
case|case
literal|3
case|:
comment|/* Message length exceeds administrative lim */
return|return
name|EX_DATAERR
return|;
block|}
break|break;
case|case
literal|3
case|:
comment|/* System Status */
return|return
name|EX_OSERR
return|;
case|case
literal|4
case|:
comment|/* Network and Routing Status */
switch|switch
condition|(
name|code3
condition|)
block|{
case|case
literal|0
case|:
comment|/* Other or undefined network or routing stat */
return|return
name|EX_IOERR
return|;
case|case
literal|1
case|:
comment|/* No answer from host */
case|case
literal|3
case|:
comment|/* Routing server failure */
case|case
literal|5
case|:
comment|/* Network congestion */
return|return
name|EX_TEMPFAIL
return|;
case|case
literal|2
case|:
comment|/* Bad connection */
return|return
name|EX_IOERR
return|;
case|case
literal|4
case|:
comment|/* Unable to route */
return|return
name|EX_PROTOCOL
return|;
case|case
literal|6
case|:
comment|/* Routing loop detected */
return|return
name|EX_CONFIG
return|;
case|case
literal|7
case|:
comment|/* Delivery time expired */
return|return
name|EX_UNAVAILABLE
return|;
block|}
break|break;
case|case
literal|5
case|:
comment|/* Protocol Status */
return|return
name|EX_PROTOCOL
return|;
case|case
literal|6
case|:
comment|/* Message Content or Media Status */
return|return
name|EX_UNAVAILABLE
return|;
case|case
literal|7
case|:
comment|/* Security Status */
return|return
name|EX_DATAERR
return|;
block|}
return|return
name|EX_CONFIG
return|;
block|}
end_function

begin_comment
comment|/* **  EXITSTAT -- convert EX_ value to error text. ** **	Parameters: **		excode -- rstatus which might consists of an EX_* value. ** **	Returns: **		The corresponding error text or the original string. */
end_comment

begin_function
name|char
modifier|*
name|exitstat
parameter_list|(
name|excode
parameter_list|)
name|char
modifier|*
name|excode
decl_stmt|;
block|{
name|char
modifier|*
name|c
decl_stmt|;
name|int
name|i
decl_stmt|;
name|char
modifier|*
name|exitmsg
decl_stmt|;
if|if
condition|(
name|excode
operator|==
name|NULL
operator|||
operator|*
name|excode
operator|==
literal|'\0'
condition|)
return|return
name|excode
return|;
name|i
operator|=
operator|(
name|int
operator|)
name|strtol
argument_list|(
name|excode
argument_list|,
operator|&
name|c
argument_list|,
literal|10
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|c
operator|!=
literal|'\0'
condition|)
return|return
name|excode
return|;
name|exitmsg
operator|=
name|sm_sysexitmsg
argument_list|(
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|exitmsg
operator|!=
name|NULL
condition|)
return|return
name|exitmsg
return|;
return|return
name|excode
return|;
block|}
end_function

end_unit

