begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: netaddr.h,v 1.18.12.9 2005/07/29 00:13:10 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_NETADDR_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_NETADDR_H
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
file|<isc/net.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_struct
struct|struct
name|isc_netaddr
block|{
name|unsigned
name|int
name|family
decl_stmt|;
union|union
block|{
name|struct
name|in_addr
name|in
decl_stmt|;
name|struct
name|in6_addr
name|in6
decl_stmt|;
block|}
name|type
union|;
name|isc_uint32_t
name|zone
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|isc_boolean_t
name|isc_netaddr_equal
parameter_list|(
specifier|const
name|isc_netaddr_t
modifier|*
name|a
parameter_list|,
specifier|const
name|isc_netaddr_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|isc_netaddr_eqprefix
parameter_list|(
specifier|const
name|isc_netaddr_t
modifier|*
name|a
parameter_list|,
specifier|const
name|isc_netaddr_t
modifier|*
name|b
parameter_list|,
name|unsigned
name|int
name|prefixlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Compare the 'prefixlen' most significant bits of the network  * addresses 'a' and 'b'.  Return ISC_TRUE if they are equal,  * ISC_FALSE if not.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_netaddr_masktoprefixlen
parameter_list|(
specifier|const
name|isc_netaddr_t
modifier|*
name|s
parameter_list|,
name|unsigned
name|int
modifier|*
name|lenp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert a netmask in 's' into a prefix length in '*lenp'.  * The mask should consist of zero or more '1' bits in the most  * most significant part of the address, followed by '0' bits.  * If this is not the case, ISC_R_MASKNONCONTIG is returned.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_MASKNONCONTIG  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_netaddr_totext
parameter_list|(
specifier|const
name|isc_netaddr_t
modifier|*
name|netaddr
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Append a text representation of 'sockaddr' to the buffer 'target'.  * The text is NOT null terminated.  Handles IPv4 and IPv6 addresses.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOSPACE	The text or the null termination did not fit.  *	ISC_R_FAILURE	Unspecified failure  */
end_comment

begin_function_decl
name|void
name|isc_netaddr_format
parameter_list|(
specifier|const
name|isc_netaddr_t
modifier|*
name|na
parameter_list|,
name|char
modifier|*
name|array
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Format a human-readable representation of the network address '*na'  * into the character array 'array', which is of size 'size'.  * The resulting string is guaranteed to be null-terminated.  */
end_comment

begin_define
define|#
directive|define
name|ISC_NETADDR_FORMATSIZE
define|\
value|sizeof("xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:XXX.XXX.XXX.XXX%SSSSSSSSSS")
end_define

begin_comment
comment|/*  * Minimum size of array to pass to isc_netaddr_format().  */
end_comment

begin_function_decl
name|void
name|isc_netaddr_fromsockaddr
parameter_list|(
name|isc_netaddr_t
modifier|*
name|netaddr
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_netaddr_fromin
parameter_list|(
name|isc_netaddr_t
modifier|*
name|netaddr
parameter_list|,
specifier|const
name|struct
name|in_addr
modifier|*
name|ina
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_netaddr_fromin6
parameter_list|(
name|isc_netaddr_t
modifier|*
name|netaddr
parameter_list|,
specifier|const
name|struct
name|in6_addr
modifier|*
name|ina6
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_netaddr_setzone
parameter_list|(
name|isc_netaddr_t
modifier|*
name|netaddr
parameter_list|,
name|isc_uint32_t
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_uint32_t
name|isc_netaddr_getzone
parameter_list|(
specifier|const
name|isc_netaddr_t
modifier|*
name|netaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_netaddr_any
parameter_list|(
name|isc_netaddr_t
modifier|*
name|netaddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the IPv4 wildcard address.  */
end_comment

begin_function_decl
name|void
name|isc_netaddr_any6
parameter_list|(
name|isc_netaddr_t
modifier|*
name|netaddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the IPv6 wildcard address.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_netaddr_ismulticast
parameter_list|(
name|isc_netaddr_t
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns ISC_TRUE if the address is a multicast address.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_netaddr_isexperimental
parameter_list|(
name|isc_netaddr_t
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns ISC_TRUE if the address is a experimental (CLASS E) address.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_netaddr_islinklocal
parameter_list|(
name|isc_netaddr_t
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns ISC_TRUE if the address is a link local address.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_netaddr_issitelocal
parameter_list|(
name|isc_netaddr_t
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns ISC_TRUE if the address is a site local address.  */
end_comment

begin_function_decl
name|void
name|isc_netaddr_fromv4mapped
parameter_list|(
name|isc_netaddr_t
modifier|*
name|t
parameter_list|,
specifier|const
name|isc_netaddr_t
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert an IPv6 v4mapped address into an IPv4 address.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_NETADDR_H */
end_comment

end_unit

