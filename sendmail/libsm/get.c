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
literal|"@(#)$Id: get.c,v 1.18 2001/09/11 04:04:48 gshapiro Exp $"
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
file|<sm/assert.h>
end_include

begin_include
include|#
directive|include
file|"local.h"
end_include

begin_comment
comment|/* **  SM_IO_GETC -- get a character from a file ** **	Parameters: **		fp -- the file to get the character from **		timeout -- time to complete getc ** **	Returns: **		Success: the value of the character read. **		Failure: SM_IO_EOF ** **	This is a function version of the macro (in<sm/io.h>). **	It is guarded with locks (which are currently not functional) **	for multi-threaded programs. */
end_comment

begin_undef
undef|#
directive|undef
name|sm_io_getc
end_undef

begin_function
name|int
name|sm_io_getc
parameter_list|(
name|fp
parameter_list|,
name|timeout
parameter_list|)
specifier|register
name|SM_FILE_T
modifier|*
name|fp
decl_stmt|;
name|int
name|timeout
decl_stmt|;
block|{
name|SM_REQUIRE_ISA
argument_list|(
name|fp
argument_list|,
name|SmFileMagic
argument_list|)
expr_stmt|;
return|return
name|sm_getc
argument_list|(
name|fp
argument_list|,
name|timeout
argument_list|)
return|;
block|}
end_function

end_unit

