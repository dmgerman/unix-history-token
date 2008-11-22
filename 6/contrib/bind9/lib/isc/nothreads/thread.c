begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: thread.c,v 1.2.206.1 2004/03/06 08:14:52 marka Exp $ */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<isc/thread.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_function
name|void
name|isc_thread_setconcurrency
parameter_list|(
name|unsigned
name|int
name|level
parameter_list|)
block|{
name|UNUSED
argument_list|(
name|level
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

