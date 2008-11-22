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
literal|"@(#)$Id: fpurge.c,v 1.20 2001/09/11 04:04:48 gshapiro Exp $"
argument_list|)
end_macro

begin_include
include|#
directive|include
file|<stdlib.h>
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

begin_comment
comment|/* **  SM_IO_PURGE -- purge/empty the buffer without committing buffer content ** **	Parameters: **		fp -- file pointer to purge ** **	Returns: **		Failure: returns SM_IO_EOF and sets errno **		Success: returns 0 (zero) */
end_comment

begin_function
name|int
name|sm_io_purge
parameter_list|(
name|fp
parameter_list|)
specifier|register
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
if|if
condition|(
operator|!
name|fp
operator|->
name|f_flags
condition|)
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
name|SM_IO_EOF
return|;
block|}
if|if
condition|(
name|HASUB
argument_list|(
name|fp
argument_list|)
condition|)
name|FREEUB
argument_list|(
name|fp
argument_list|)
expr_stmt|;
name|fp
operator|->
name|f_p
operator|=
name|fp
operator|->
name|f_bf
operator|.
name|smb_base
expr_stmt|;
name|fp
operator|->
name|f_r
operator|=
literal|0
expr_stmt|;
comment|/* implies SMFBF */
name|fp
operator|->
name|f_w
operator|=
name|fp
operator|->
name|f_flags
operator|&
operator|(
name|SMLBF
operator||
name|SMNBF
operator|)
condition|?
literal|0
else|:
name|fp
operator|->
name|f_bf
operator|.
name|smb_size
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

