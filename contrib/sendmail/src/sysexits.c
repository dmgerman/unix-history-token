begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998, 1999 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1983, 1995-1997 Eric P. Allman.  All rights reserved.  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|id
index|[]
init|=
literal|"@(#)$Id: sysexits.c,v 8.25 1999/09/23 19:59:24 ca Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! lint */
end_comment

begin_include
include|#
directive|include
file|<sendmail.h>
end_include

begin_comment
comment|/* **  SYSEXITS.C -- error messages corresponding to sysexits.h ** **	If the first character of the string is a colon, interpolate **	the current errno after the rest of the string. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SysExMsg
index|[]
init|=
block|{
comment|/* 64 USAGE */
literal|" 500 5.0.0 Bad usage"
block|,
comment|/* 65 DATAERR */
literal|" 501 5.6.0 Data format error"
block|,
comment|/* 66 NOINPUT */
literal|":550 5.3.0 Cannot open input"
block|,
comment|/* 67 NOUSER */
literal|" 550 5.1.1 User unknown"
block|,
comment|/* 68 NOHOST */
literal|" 550 5.1.2 Host unknown"
block|,
comment|/* 69 UNAVAILABLE */
literal|" 554 5.0.0 Service unavailable"
block|,
comment|/* 70 SOFTWARE */
literal|":554 5.3.0 Internal error"
block|,
comment|/* 71 OSERR */
literal|":451 4.0.0 Operating system error"
block|,
comment|/* 72 OSFILE */
literal|":554 5.3.5 System file missing"
block|,
comment|/* 73 CANTCREAT */
literal|":550 5.0.0 Can't create output"
block|,
comment|/* 74 IOERR */
literal|":451 4.0.0 I/O error"
block|,
comment|/* 75 TEMPFAIL */
literal|" 450 4.0.0 Deferred"
block|,
comment|/* 76 PROTOCOL */
literal|" 554 5.5.0 Remote protocol error"
block|,
comment|/* 77 NOPERM */
literal|":550 5.0.0 Insufficient permission"
block|,
comment|/* 78 CONFIG */
literal|" 554 5.3.5 Local configuration error"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|N_SysEx
init|=
sizeof|sizeof
argument_list|(
name|SysExMsg
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|SysExMsg
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|SysExitMsg
index|[]
init|=
block|{
literal|"command line usage error"
block|,
literal|"data format error"
block|,
literal|"cannot open input"
block|,
literal|"addressee unknown"
block|,
literal|"host name unknown"
block|,
literal|"service unavailable"
block|,
literal|"internal software error"
block|,
literal|"system error (e.g., can't fork)"
block|,
literal|"critical OS file missing"
block|,
literal|"can't create (user) output file"
block|,
literal|"input/output error"
block|,
literal|"temp failure; user is invited to retry"
block|,
literal|"remote error in protocol"
block|,
literal|"permission denied"
block|,
literal|"configuration error"
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

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

begin_escape
end_escape

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
literal|0
expr_stmt|;
for|for
control|(
name|c
operator|=
name|excode
init|;
operator|*
name|c
operator|!=
literal|'\0'
condition|;
name|c
operator|++
control|)
block|{
if|if
condition|(
name|isascii
argument_list|(
operator|*
name|c
argument_list|)
operator|&&
name|isdigit
argument_list|(
operator|*
name|c
argument_list|)
condition|)
name|i
operator|=
name|i
operator|*
literal|10
operator|+
operator|(
operator|*
name|c
operator|-
literal|'0'
operator|)
expr_stmt|;
else|else
return|return
name|excode
return|;
block|}
name|i
operator|-=
name|EX__BASE
expr_stmt|;
if|if
condition|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<=
name|N_SysEx
condition|)
return|return
name|SysExitMsg
index|[
name|i
index|]
return|;
return|return
name|excode
return|;
block|}
end_function

end_unit

