begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: fixedname.h,v 1.12.206.1 2004/03/06 08:13:55 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_FIXEDNAME_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_FIXEDNAME_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Fixed-size Names  *  * dns_fixedname_t is a convenience type containing a name, an offsets table,  * and a dedicated buffer big enough for the longest possible name.  *  * MP:  *	The caller must ensure any required synchronization.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *	Per dns_fixedname_t:  *		sizeof(dns_name_t) + sizeof(dns_offsets_t) +  *		sizeof(isc_buffer_t) + 255 bytes + structure padding  *  * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
end_comment

begin_comment
comment|/*****  ***** Imports  *****/
end_comment

begin_include
include|#
directive|include
file|<isc/buffer.h>
end_include

begin_include
include|#
directive|include
file|<dns/name.h>
end_include

begin_comment
comment|/*****  ***** Types  *****/
end_comment

begin_struct
struct|struct
name|dns_fixedname
block|{
name|dns_name_t
name|name
decl_stmt|;
name|dns_offsets_t
name|offsets
decl_stmt|;
name|isc_buffer_t
name|buffer
decl_stmt|;
name|unsigned
name|char
name|data
index|[
name|DNS_NAME_MAXWIRE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dns_fixedname_init
parameter_list|(
name|fn
parameter_list|)
define|\
value|do { \ 		dns_name_init(&((fn)->name), (fn)->offsets); \ 		isc_buffer_init(&((fn)->buffer), (fn)->data, \                                   DNS_NAME_MAXWIRE); \ 		dns_name_setbuffer(&((fn)->name),&((fn)->buffer)); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|dns_fixedname_invalidate
parameter_list|(
name|fn
parameter_list|)
define|\
value|dns_name_invalidate(&((fn)->name))
end_define

begin_define
define|#
directive|define
name|dns_fixedname_name
parameter_list|(
name|fn
parameter_list|)
value|(&((fn)->name))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_FIXEDNAME_H */
end_comment

end_unit

