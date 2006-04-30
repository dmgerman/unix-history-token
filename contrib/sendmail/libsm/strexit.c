begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  */
end_comment

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_macro
name|SM_RCSID
argument_list|(
literal|"@(#)$Id: strexit.c,v 1.5 2001/09/11 04:04:49 gshapiro Exp $"
argument_list|)
end_macro

begin_include
include|#
directive|include
file|<sm/string.h>
end_include

begin_include
include|#
directive|include
file|<sm/sysexits.h>
end_include

begin_comment
comment|/* **  SM_STREXIT -- convert EX_* value from<sm/sysexits.h> to a character string ** **	This function is analogous to strerror(), except that it **	operates on EX_* values from<sm/sysexits.h>. ** **	Parameters: **		ex -- EX_* value ** **	Results: **		pointer to a static message string */
end_comment

begin_function
name|char
modifier|*
name|sm_strexit
parameter_list|(
name|ex
parameter_list|)
name|int
name|ex
decl_stmt|;
block|{
name|char
modifier|*
name|msg
decl_stmt|;
specifier|static
name|char
name|buf
index|[
literal|64
index|]
decl_stmt|;
name|msg
operator|=
name|sm_sysexitmsg
argument_list|(
name|ex
argument_list|)
expr_stmt|;
if|if
condition|(
name|msg
operator|==
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|sm_snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|,
literal|"Unknown exit status %d"
argument_list|,
name|ex
argument_list|)
expr_stmt|;
name|msg
operator|=
name|buf
expr_stmt|;
block|}
return|return
name|msg
return|;
block|}
end_function

begin_comment
comment|/* **  SM_SYSEXITMSG -- convert an EX_* value to a character string, or NULL ** **	Parameters: **		ex -- EX_* value ** **	Results: **		If ex is a known exit value, then a pointer to a static **		message string is returned.  Otherwise NULL is returned. */
end_comment

begin_function
name|char
modifier|*
name|sm_sysexitmsg
parameter_list|(
name|ex
parameter_list|)
name|int
name|ex
decl_stmt|;
block|{
name|char
modifier|*
name|msg
decl_stmt|;
name|msg
operator|=
name|sm_sysexmsg
argument_list|(
name|ex
argument_list|)
expr_stmt|;
if|if
condition|(
name|msg
operator|!=
name|NULL
condition|)
return|return
operator|&
name|msg
index|[
literal|11
index|]
return|;
else|else
return|return
name|msg
return|;
block|}
end_function

begin_comment
comment|/* **  SM_SYSEXMSG -- convert an EX_* value to a character string, or NULL ** **	Parameters: **		ex -- EX_* value ** **	Results: **		If ex is a known exit value, then a pointer to a static **		string is returned.  Otherwise NULL is returned. **		The string contains the following fixed width fields: **		 [0]	':' if there is an errno value associated with this **			exit value, otherwise ' '. **		 [1,3]	3 digit SMTP error code **		 [4]	' ' **		 [5,9]	3 digit SMTP extended error code **		 [10]	' ' **		 [11,]	message string */
end_comment

begin_function
name|char
modifier|*
name|sm_sysexmsg
parameter_list|(
name|ex
parameter_list|)
name|int
name|ex
decl_stmt|;
block|{
switch|switch
condition|(
name|ex
condition|)
block|{
case|case
name|EX_USAGE
case|:
return|return
literal|" 500 5.0.0 Command line usage error"
return|;
case|case
name|EX_DATAERR
case|:
return|return
literal|" 501 5.6.0 Data format error"
return|;
case|case
name|EX_NOINPUT
case|:
return|return
literal|":550 5.3.0 Cannot open input"
return|;
case|case
name|EX_NOUSER
case|:
return|return
literal|" 550 5.1.1 User unknown"
return|;
case|case
name|EX_NOHOST
case|:
return|return
literal|" 550 5.1.2 Host unknown"
return|;
case|case
name|EX_UNAVAILABLE
case|:
return|return
literal|" 554 5.0.0 Service unavailable"
return|;
case|case
name|EX_SOFTWARE
case|:
return|return
literal|":554 5.3.0 Internal error"
return|;
case|case
name|EX_OSERR
case|:
return|return
literal|":451 4.0.0 Operating system error"
return|;
case|case
name|EX_OSFILE
case|:
return|return
literal|":554 5.3.5 System file missing"
return|;
case|case
name|EX_CANTCREAT
case|:
return|return
literal|":550 5.0.0 Can't create output"
return|;
case|case
name|EX_IOERR
case|:
return|return
literal|":451 4.0.0 I/O error"
return|;
case|case
name|EX_TEMPFAIL
case|:
return|return
literal|" 450 4.0.0 Deferred"
return|;
case|case
name|EX_PROTOCOL
case|:
return|return
literal|" 554 5.5.0 Remote protocol error"
return|;
case|case
name|EX_NOPERM
case|:
return|return
literal|":550 5.0.0 Insufficient permission"
return|;
case|case
name|EX_CONFIG
case|:
return|return
literal|" 554 5.3.5 Local configuration error"
return|;
default|default:
return|return
name|NULL
return|;
block|}
block|}
end_function

end_unit

