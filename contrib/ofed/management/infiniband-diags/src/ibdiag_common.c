begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006-2007 The Regents of the University of California.  * Copyright (c) 2004-2006 Voltaire, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/**  * Define common functions which can be included in the various C based diags.  */
end_comment

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ibdiag_common.h"
end_include

begin_decl_stmt
name|int
name|ibdebug
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|iberror
parameter_list|(
specifier|const
name|char
modifier|*
name|fn
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|,
modifier|...
parameter_list|)
block|{
name|char
name|buf
index|[
literal|512
index|]
decl_stmt|,
modifier|*
name|s
decl_stmt|;
name|va_list
name|va
decl_stmt|;
name|int
name|n
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|n
operator|=
name|vsprintf
argument_list|(
name|buf
argument_list|,
name|msg
argument_list|,
name|va
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
name|buf
index|[
name|n
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
name|s
operator|=
name|strrchr
argument_list|(
name|argv0
argument_list|,
literal|'/'
argument_list|)
operator|)
condition|)
name|argv0
operator|=
name|s
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|ibdebug
condition|)
name|printf
argument_list|(
literal|"%s: iberror: [pid %d] %s: failed: %s\n"
argument_list|,
name|argv0
argument_list|,
name|getpid
argument_list|()
argument_list|,
name|fn
argument_list|,
name|buf
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"%s: iberror: failed: %s\n"
argument_list|,
name|argv0
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

