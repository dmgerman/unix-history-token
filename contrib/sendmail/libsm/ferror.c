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
literal|"@(#)$Id: ferror.c,v 1.13 2001/09/11 04:04:48 gshapiro Exp $"
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
comment|/* **  SM_IO_ERROR -- subroutine version of the macro sm_io_error. ** **	Parameters: **		fp -- file pointer ** **	Returns: **		0 (zero) when 'fp' is not in an error state **		non-zero when 'fp' is in an error state */
end_comment

begin_undef
undef|#
directive|undef
name|sm_io_error
end_undef

begin_function
name|int
name|sm_io_error
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
return|return
name|sm_error
argument_list|(
name|fp
argument_list|)
return|;
block|}
end_function

end_unit

