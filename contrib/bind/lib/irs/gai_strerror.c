begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* %%% copyright-cmetz-97 This software is Copyright 1997-1998 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to this software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.  */
end_comment

begin_include
include|#
directive|include
file|<port_before.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<port_after.h>
end_include

begin_function
name|char
modifier|*
name|gai_strerror
parameter_list|(
name|int
name|errnum
parameter_list|)
block|{
switch|switch
condition|(
name|errnum
condition|)
block|{
case|case
literal|0
case|:
return|return
literal|"no error"
return|;
case|case
name|EAI_BADFLAGS
case|:
return|return
literal|"invalid value for ai_flags"
return|;
case|case
name|EAI_NONAME
case|:
return|return
literal|"name or service is not known"
return|;
case|case
name|EAI_AGAIN
case|:
return|return
literal|"temporary failure in name resolution"
return|;
case|case
name|EAI_FAIL
case|:
return|return
literal|"non-recoverable failure in name resolution"
return|;
case|case
name|EAI_NODATA
case|:
return|return
literal|"no address associated with name"
return|;
case|case
name|EAI_FAMILY
case|:
return|return
literal|"ai_family not supported"
return|;
case|case
name|EAI_SOCKTYPE
case|:
return|return
literal|"ai_socktype not supported"
return|;
case|case
name|EAI_SERVICE
case|:
return|return
literal|"service not supported for ai_socktype"
return|;
case|case
name|EAI_ADDRFAMILY
case|:
return|return
literal|"address family for name not supported"
return|;
case|case
name|EAI_MEMORY
case|:
return|return
literal|"memory allocation failure"
return|;
case|case
name|EAI_SYSTEM
case|:
return|return
literal|"system error"
return|;
default|default:
return|return
literal|"unknown error"
return|;
block|}
empty_stmt|;
block|}
end_function

end_unit

