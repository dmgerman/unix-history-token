begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *      All rights reserved.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  */
end_comment

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_macro
name|SM_RCSID
argument_list|(
literal|"@(#)$Id: vprintf.c,v 1.14 2001/09/11 04:04:49 gshapiro Exp $"
argument_list|)
end_macro

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
comment|/* **  SM_VPRINTF -- print to standard out with variable length args ** **	Parameters: **		timeout -- length of time allow to do the print **		fmt -- the format of the output **		ap -- the variable number of args to be used for output ** **	Returns: **		as sm_io_vfprintf() does. */
end_comment

begin_function
name|int
name|sm_vprintf
parameter_list|(
name|timeout
parameter_list|,
name|fmt
parameter_list|,
name|ap
parameter_list|)
name|int
name|timeout
decl_stmt|;
name|char
specifier|const
modifier|*
name|fmt
decl_stmt|;
function|SM_VA_LOCAL_DECL
block|{
return|return
name|sm_io_vfprintf
argument_list|(
name|smiostdout
argument_list|,
name|timeout
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
return|;
block|}
end_function

end_unit

