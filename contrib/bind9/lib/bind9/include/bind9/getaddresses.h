begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: getaddresses.h,v 1.2.200.3 2004/03/08 09:04:28 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIND9_GETADDRESSES_H
end_ifndef

begin_define
define|#
directive|define
name|BIND9_GETADDRESSES_H
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
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/net.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|bind9_getaddresses
parameter_list|(
specifier|const
name|char
modifier|*
name|hostname
parameter_list|,
name|in_port_t
name|port
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|addrs
parameter_list|,
name|int
name|addrsize
parameter_list|,
name|int
modifier|*
name|addrcount
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Use the system resolver to get the addresses associated with a hostname.  * If successful, the number of addresses found is returned in 'addrcount'.  * If a hostname lookup is performed and addresses of an unknown family is  * seen, it is ignored.  If more than 'addrsize' addresses are seen, the  * first 'addrsize' are returned and the remainder silently truncated.  *  * This routine may block.  If called by a program using the isc_app  * framework, it should be surounded by isc_app_block()/isc_app_unblock().  *  *  Requires:  *	'hostname' is not NULL.  *	'addrs' is not NULL.  *	'addrsize'> 0  *	'addrcount' is not NULL.  *  *   * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOTFOUND  *	ISC_R_NOFAMILYSUPPORT - 'hostname' is an IPv6 address, and IPv6 is  *		not supported.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BIND9_GETADDRESSES_H */
end_comment

end_unit

