begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2008  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: platform.h.in,v 1.2.6.2 2008/01/23 02:15:02 tbox Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*! \file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_PLATFORM_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_PLATFORM_H
end_define

begin_comment
comment|/*  * Define if the OS does not define struct timespec.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_PLATFORM_NEEDTIMESPEC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDTIMESPEC
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/* For time_t */
end_comment

begin_struct
struct|struct
name|timespec
block|{
name|time_t
name|tv_sec
decl_stmt|;
comment|/* seconds */
name|long
name|tv_nsec
decl_stmt|;
comment|/* nanoseconds */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

