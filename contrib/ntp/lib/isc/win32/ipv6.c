begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2007  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: ipv6.c,v 1.8 2007/06/19 23:47:19 tbox Exp $ */
end_comment

begin_include
include|#
directive|include
file|<isc/net.h>
end_include

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_expr_stmt
name|LIBISC_EXTERNAL_DATA
specifier|const
expr|struct
name|in6_addr
name|isc_in6addr_any
operator|=
name|IN6ADDR_ANY_INIT
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIBISC_EXTERNAL_DATA
specifier|const
expr|struct
name|in6_addr
name|isc_in6addr_loopback
operator|=
name|IN6ADDR_LOOPBACK_INIT
expr_stmt|;
end_expr_stmt

end_unit

