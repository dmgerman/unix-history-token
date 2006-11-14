begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: rdatastructpre.h,v 1.13.206.1 2004/03/06 08:14:02 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RDATASTRUCT_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RDATASTRUCT_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/sockaddr.h>
end_include

begin_include
include|#
directive|include
file|<dns/name.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_typedef
typedef|typedef
struct|struct
name|dns_rdatacommon
block|{
name|dns_rdataclass_t
name|rdclass
decl_stmt|;
name|dns_rdatatype_t
name|rdtype
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|struct dns_rdatacommon
argument_list|)
name|link
expr_stmt|;
block|}
name|dns_rdatacommon_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNS_RDATACOMMON_INIT
parameter_list|(
name|_data
parameter_list|,
name|_rdtype
parameter_list|,
name|_rdclass
parameter_list|)
define|\
value|do { \ 		(_data)->common.rdtype = (_rdtype); \ 		(_data)->common.rdclass = (_rdclass); \ 		ISC_LINK_INIT(&(_data)->common, link); \ 	} while (0)
end_define

end_unit

