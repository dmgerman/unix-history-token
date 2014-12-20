begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2007, 2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: strerror.c,v 1.10 2009/02/16 23:48:04 tbox Exp $ */
end_comment

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<isc/once.h>
end_include

begin_include
include|#
directive|include
file|<isc/print.h>
end_include

begin_include
include|#
directive|include
file|<isc/strerror.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_include
include|#
directive|include
file|"l_stdlib.h"
end_include

begin_comment
comment|/* NTP local change */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRERROR
end_ifdef

begin_comment
comment|/*%  * We need to do this this way for profiled locks.  */
end_comment

begin_decl_stmt
specifier|static
name|isc_mutex_t
name|isc_strerror_lock
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|init_lock
parameter_list|(
name|void
parameter_list|)
block|{
name|RUNTIME_CHECK
argument_list|(
name|isc_mutex_init
argument_list|(
operator|&
name|isc_strerror_lock
argument_list|)
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|isc__strerror
parameter_list|(
name|int
name|num
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|HAVE_STRERROR
name|char
modifier|*
name|msg
decl_stmt|;
name|unsigned
name|int
name|unum
init|=
operator|(
name|unsigned
name|int
operator|)
name|num
decl_stmt|;
specifier|static
name|isc_once_t
name|once
init|=
name|ISC_ONCE_INIT
decl_stmt|;
name|REQUIRE
argument_list|(
name|buf
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|RUNTIME_CHECK
argument_list|(
name|isc_once_do
argument_list|(
operator|&
name|once
argument_list|,
name|init_lock
argument_list|)
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
name|LOCK
argument_list|(
operator|&
name|isc_strerror_lock
argument_list|)
expr_stmt|;
name|msg
operator|=
name|strerror
argument_list|(
name|num
argument_list|)
expr_stmt|;
if|if
condition|(
name|msg
operator|!=
name|NULL
condition|)
name|snprintf
argument_list|(
name|buf
argument_list|,
name|size
argument_list|,
literal|"%s"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
else|else
name|snprintf
argument_list|(
name|buf
argument_list|,
name|size
argument_list|,
literal|"Unknown error: %u"
argument_list|,
name|unum
argument_list|)
expr_stmt|;
name|UNLOCK
argument_list|(
operator|&
name|isc_strerror_lock
argument_list|)
expr_stmt|;
else|#
directive|else
name|unsigned
name|int
name|unum
init|=
operator|(
name|unsigned
name|int
operator|)
name|num
decl_stmt|;
name|REQUIRE
argument_list|(
name|buf
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|num
operator|>=
literal|0
operator|&&
name|num
operator|<
name|sys_nerr
condition|)
name|snprintf
argument_list|(
name|buf
argument_list|,
name|size
argument_list|,
literal|"%s"
argument_list|,
name|sys_errlist
index|[
name|num
index|]
argument_list|)
expr_stmt|;
else|else
name|snprintf
argument_list|(
name|buf
argument_list|,
name|size
argument_list|,
literal|"Unknown error: %u"
argument_list|,
name|unum
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

