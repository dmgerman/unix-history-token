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
literal|"@(#)$Id: clrerr.c,v 1.13 2001/09/11 04:04:48 gshapiro Exp $"
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
comment|/* **  SM_IO_CLEARERR -- public function to clear a file pointer's error status ** **	Parameters: **		fp -- the file pointer ** **	Returns: **		nothing. */
end_comment

begin_undef
undef|#
directive|undef
name|sm_io_clearerr
end_undef

begin_function
name|void
name|sm_io_clearerr
parameter_list|(
name|fp
parameter_list|)
name|SM_FILE_T
modifier|*
name|fp
decl_stmt|;
block|{
name|SM_REQUIRE_ISA
argument_list|(
name|fp
argument_list|,
name|SmFileMagic
argument_list|)
expr_stmt|;
name|sm_clearerr
argument_list|(
name|fp
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

