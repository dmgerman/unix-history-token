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
literal|"@(#)$Id: fprintf.c,v 1.17 2001/09/11 04:04:48 gshapiro Exp $"
argument_list|)
end_macro

begin_include
include|#
directive|include
file|<sm/varargs.h>
end_include

begin_include
include|#
directive|include
file|<sm/io.h>
end_include

begin_include
include|#
directive|include
file|<sm/assert.h>
end_include

begin_include
include|#
directive|include
file|"local.h"
end_include

begin_comment
comment|/* **  SM_IO_FPRINTF -- format and print a string to a file pointer ** **	Parameters: **		fp -- file pointer to be printed to **		timeout -- time to complete print **		fmt -- markup format for the string to be printed **		... -- additional information for 'fmt' ** **	Returns: **		Failure: returns SM_IO_EOF and sets errno **		Success: returns the number of characters o/p */
end_comment

begin_function
name|int
if|#
directive|if
name|SM_VA_STD
name|sm_io_fprintf
parameter_list|(
name|SM_FILE_T
modifier|*
name|fp
parameter_list|,
name|int
name|timeout
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
comment|/* SM_VA_STD */
function|sm_io_fprintf
parameter_list|(
name|fp
parameter_list|,
name|timeout
parameter_list|,
name|fmt
parameter_list|,
name|va_alist
parameter_list|)
name|SM_FILE_T
modifier|*
name|fp
decl_stmt|;
name|int
name|timeout
decl_stmt|;
name|char
modifier|*
name|fmt
decl_stmt|;
function|va_dcl
endif|#
directive|endif
comment|/* SM_VA_STD */
block|{
name|int
name|ret
decl_stmt|;
name|SM_VA_LOCAL_DECL
name|SM_REQUIRE_ISA
argument_list|(
name|fp
argument_list|,
name|SmFileMagic
argument_list|)
decl_stmt|;
name|SM_VA_START
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|ret
operator|=
name|sm_io_vfprintf
argument_list|(
name|fp
argument_list|,
name|timeout
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|SM_VA_END
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

end_unit

