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
literal|"@(#)$Id: put.c,v 1.27 2001/12/19 05:19:35 ca Exp $"
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
file|<sm/errstring.h>
end_include

begin_include
include|#
directive|include
file|<sm/string.h>
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
comment|/* **  SM_IO_PUTC -- output a character to the file ** **  Function version of the macro sm_io_putc (in<sm/io.h>). ** **	Parameters: **		fp -- file to output to **		timeout -- time to complete putc **		c -- int value of character to output ** **	Returns: **		Failure: returns SM_IO_EOF _and_ sets errno **		Success: returns sm_putc() value. ** */
end_comment

begin_undef
undef|#
directive|undef
name|sm_io_putc
end_undef

begin_function
name|int
name|sm_io_putc
parameter_list|(
name|fp
parameter_list|,
name|timeout
parameter_list|,
name|c
parameter_list|)
name|SM_FILE_T
modifier|*
name|fp
decl_stmt|;
name|int
name|timeout
decl_stmt|;
name|int
name|c
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
name|cantwrite
argument_list|(
name|fp
argument_list|)
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
return|return
name|sm_putc
argument_list|(
name|fp
argument_list|,
name|timeout
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* **  SM_PERROR -- print system error messages to smioerr ** **	Parameters: **		s -- message to print ** **	Returns: **		none */
end_comment

begin_function
name|void
name|sm_perror
parameter_list|(
name|s
parameter_list|)
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|int
name|save_errno
init|=
name|errno
decl_stmt|;
if|if
condition|(
name|s
operator|!=
name|NULL
operator|&&
operator|*
name|s
operator|!=
literal|'\0'
condition|)
operator|(
name|void
operator|)
name|sm_io_fprintf
argument_list|(
name|smioerr
argument_list|,
name|SM_TIME_DEFAULT
argument_list|,
literal|"%s: "
argument_list|,
name|s
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sm_io_fprintf
argument_list|(
name|smioerr
argument_list|,
name|SM_TIME_DEFAULT
argument_list|,
literal|"%s\n"
argument_list|,
name|sm_errstring
argument_list|(
name|save_errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

