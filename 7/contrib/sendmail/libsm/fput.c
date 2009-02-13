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
literal|"@(#)$Id: fput.c,v 1.20 2001/09/11 04:04:48 gshapiro Exp $"
argument_list|)
end_macro

begin_include
include|#
directive|include
file|<string.h>
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
file|<sm/assert.h>
end_include

begin_include
include|#
directive|include
file|"local.h"
end_include

begin_include
include|#
directive|include
file|"fvwrite.h"
end_include

begin_comment
comment|/* **  SM_IO_FPUTS -- add a string to the buffer for the file pointer ** **	Parameters: **		fp -- the file pointer for the buffer to be written to **		timeout -- time to complete the put-string **		s -- string to be placed in the buffer ** **	Returns: **		Failure: returns SM_IO_EOF **		Success: returns 0 (zero) */
end_comment

begin_function
name|int
name|sm_io_fputs
parameter_list|(
name|fp
parameter_list|,
name|timeout
parameter_list|,
name|s
parameter_list|)
name|SM_FILE_T
modifier|*
name|fp
decl_stmt|;
name|int
name|timeout
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|struct
name|sm_uio
name|uio
decl_stmt|;
name|struct
name|sm_iov
name|iov
decl_stmt|;
name|SM_REQUIRE_ISA
argument_list|(
name|fp
argument_list|,
name|SmFileMagic
argument_list|)
expr_stmt|;
name|iov
operator|.
name|iov_base
operator|=
operator|(
name|void
operator|*
operator|)
name|s
expr_stmt|;
name|iov
operator|.
name|iov_len
operator|=
name|uio
operator|.
name|uio_resid
operator|=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|uio
operator|.
name|uio_iov
operator|=
operator|&
name|iov
expr_stmt|;
name|uio
operator|.
name|uio_iovcnt
operator|=
literal|1
expr_stmt|;
return|return
name|sm_fvwrite
argument_list|(
name|fp
argument_list|,
name|timeout
argument_list|,
operator|&
name|uio
argument_list|)
return|;
block|}
end_function

end_unit

