begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: bind9.h,v 1.2 2009/12/05 23:31:41 each Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_BIND9_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_BIND9_H
value|1
end_define

begin_comment
comment|/*  * This determines whether we are building BIND9 or using the exported  * libisc/libdns libraries.  The version of this file included in the  * standard BIND9 build defines BIND9; the version included with the  * exportable libraries does not.  */
end_comment

begin_define
define|#
directive|define
name|BIND9
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_BIND9_H */
end_comment

end_unit

