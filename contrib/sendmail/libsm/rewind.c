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
literal|"@(#)$Id: rewind.c,v 1.18 2001/09/11 04:04:49 gshapiro Exp $"
argument_list|)
end_macro

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

begin_comment
comment|/* **  SM_IO_REWIND -- rewind the file ** **	Seeks the file to the begining and clears any outstanding errors. ** **	Parameters: **		fp -- the flie pointer for rewind **		timeout -- time to complete the rewind ** **	Returns: **		none. */
end_comment

begin_function
name|void
name|sm_io_rewind
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
operator|(
name|void
operator|)
name|sm_io_seek
argument_list|(
name|fp
argument_list|,
name|timeout
argument_list|,
literal|0L
argument_list|,
name|SM_IO_SEEK_SET
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sm_io_clearerr
argument_list|(
name|fp
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
comment|/* not required, but seems reasonable */
block|}
end_function

end_unit

