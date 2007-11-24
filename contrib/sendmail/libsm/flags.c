begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001, 2004, 2006 Sendmail, Inc. and its suppliers.  *      All rights reserved.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  */
end_comment

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_macro
name|SM_RCSID
argument_list|(
literal|"@(#)$Id: flags.c,v 1.23 2006/12/19 19:44:23 ca Exp $"
argument_list|)
end_macro

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sm/io.h>
end_include

begin_include
include|#
directive|include
file|"local.h"
end_include

begin_comment
comment|/* **  SM_FLAGS -- translate external (user) flags into internal flags ** **	Paramters: **		flags -- user select flags ** **	Returns: **		Internal flag value matching user selected flags */
end_comment

begin_function
name|int
name|sm_flags
parameter_list|(
name|flags
parameter_list|)
name|int
name|flags
decl_stmt|;
block|{
name|int
name|ret
decl_stmt|;
switch|switch
condition|(
name|SM_IO_MODE
argument_list|(
name|flags
argument_list|)
condition|)
block|{
case|case
name|SM_IO_RDONLY
case|:
comment|/* open for reading */
name|ret
operator|=
name|SMRD
expr_stmt|;
break|break;
case|case
name|SM_IO_WRONLY
case|:
comment|/* open for writing */
name|ret
operator|=
name|SMWR
expr_stmt|;
break|break;
case|case
name|SM_IO_APPEND
case|:
comment|/* open for appending */
name|ret
operator|=
name|SMWR
expr_stmt|;
break|break;
case|case
name|SM_IO_RDWR
case|:
comment|/* open for read and write */
name|ret
operator|=
name|SMRW
expr_stmt|;
break|break;
default|default:
name|ret
operator|=
literal|0
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|SM_IS_BINARY
argument_list|(
name|flags
argument_list|)
condition|)
name|ret
operator||=
name|SM_IO_BINARY
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

end_unit

