begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: bit.h,v 1.7.206.1 2004/03/06 08:13:51 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_BIT_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_BIT_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/int.h>
end_include

begin_include
include|#
directive|include
file|<isc/boolean.h>
end_include

begin_typedef
typedef|typedef
name|isc_uint64_t
name|dns_bitset_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNS_BIT_SET
parameter_list|(
name|bit
parameter_list|,
name|bitset
parameter_list|)
define|\
value|(*(bitset) |= ((dns_bitset_t)1<< (bit)))
end_define

begin_define
define|#
directive|define
name|DNS_BIT_CLEAR
parameter_list|(
name|bit
parameter_list|,
name|bitset
parameter_list|)
define|\
value|(*(bitset)&= ~((dns_bitset_t)1<< (bit)))
end_define

begin_define
define|#
directive|define
name|DNS_BIT_CHECK
parameter_list|(
name|bit
parameter_list|,
name|bitset
parameter_list|)
define|\
value|ISC_TF((*(bitset)& ((dns_bitset_t)1<< (bit))) \ 	    == ((dns_bitset_t)1<< (bit)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_BIT_H */
end_comment

end_unit

