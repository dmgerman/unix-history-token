begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: sockaddr.h,v 1.35.12.10 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_SOCKADDR_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_SOCKADDR_H
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

begin_struct
struct|struct
name|isc_sockaddr
block|{
union|union
block|{
name|struct
name|sockaddr
name|sa
decl_stmt|;
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
name|struct
name|sockaddr_in6
name|sin6
decl_stmt|;
block|}
name|type
union|;
name|unsigned
name|int
name|length
decl_stmt|;
comment|/* XXXRTH beginning? */
name|ISC_LINK
argument_list|(
argument|struct isc_sockaddr
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|struct isc_sockaddr
argument_list|)
name|isc_sockaddrlist_t
expr_stmt|;
end_typedef

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_boolean_t
name|isc_sockaddr_equal
parameter_list|(
specifier|const
name|isc_sockaddr_t
modifier|*
name|a
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return ISC_TRUE iff the socket addresses 'a' and 'b' are equal.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_sockaddr_eqaddr
parameter_list|(
specifier|const
name|isc_sockaddr_t
modifier|*
name|a
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return ISC_TRUE iff the address parts of the socket addresses  * 'a' and 'b' are equal, ignoring the ports.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_sockaddr_eqaddrprefix
parameter_list|(
specifier|const
name|isc_sockaddr_t
modifier|*
name|a
parameter_list|,
specifier|const
name|isc_sockaddr_t
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
comment|/*  * Return ISC_TRUE iff the most significant 'prefixlen' bits of the  * socket addresses 'a' and 'b' are equal, ignoring the ports.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_sockaddr_hash
parameter_list|(
specifier|const
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|,
name|isc_boolean_t
name|address_only
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a hash value for the socket address 'sockaddr'.  If 'address_only'  * is ISC_TRUE, the hash value will not depend on the port.  *  * IPv6 addresses containing mapped IPv4 addresses generate the same hash  * value as the equivalent IPv4 address.  */
end_comment

begin_function_decl
name|void
name|isc_sockaddr_any
parameter_list|(
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the IPv4 wildcard address.  */
end_comment

begin_function_decl
name|void
name|isc_sockaddr_any6
parameter_list|(
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the IPv6 wildcard address.  */
end_comment

begin_function_decl
name|void
name|isc_sockaddr_anyofpf
parameter_list|(
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|,
name|int
name|family
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set '*sockaddr' to the wildcard address of protocol family  * 'family'.  *  * Requires:  *	'family' is AF_INET or AF_INET6.  */
end_comment

begin_function_decl
name|void
name|isc_sockaddr_fromin
parameter_list|(
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|,
specifier|const
name|struct
name|in_addr
modifier|*
name|ina
parameter_list|,
name|in_port_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Construct an isc_sockaddr_t from an IPv4 address and port.  */
end_comment

begin_function_decl
name|void
name|isc_sockaddr_fromin6
parameter_list|(
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|,
specifier|const
name|struct
name|in6_addr
modifier|*
name|ina6
parameter_list|,
name|in_port_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Construct an isc_sockaddr_t from an IPv6 address and port.  */
end_comment

begin_function_decl
name|void
name|isc_sockaddr_v6fromin
parameter_list|(
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|,
specifier|const
name|struct
name|in_addr
modifier|*
name|ina
parameter_list|,
name|in_port_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Construct an IPv6 isc_sockaddr_t representing a mapped IPv4 address.  */
end_comment

begin_function_decl
name|void
name|isc_sockaddr_fromnetaddr
parameter_list|(
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|,
specifier|const
name|isc_netaddr_t
modifier|*
name|na
parameter_list|,
name|in_port_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Construct an isc_sockaddr_t from an isc_netaddr_t and port.  */
end_comment

begin_function_decl
name|int
name|isc_sockaddr_pf
parameter_list|(
specifier|const
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the protocol family of 'sockaddr'.  *  * Requires:  *  *	'sockaddr' is a valid sockaddr with an address family of AF_INET  *	or AF_INET6.  *  * Returns:  *  *	The protocol family of 'sockaddr', e.g. PF_INET or PF_INET6.  */
end_comment

begin_function_decl
name|void
name|isc_sockaddr_setport
parameter_list|(
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|,
name|in_port_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the port of 'sockaddr' to 'port'.  */
end_comment

begin_function_decl
name|in_port_t
name|isc_sockaddr_getport
parameter_list|(
specifier|const
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the port stored in 'sockaddr'.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_sockaddr_totext
parameter_list|(
specifier|const
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Append a text representation of 'sockaddr' to the buffer 'target'.  * The text will include both the IP address (v4 or v6) and the port.  * The text is null terminated, but the terminating null is not  * part of the buffer's used region.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOSPACE	The text or the null termination did not fit.  */
end_comment

begin_function_decl
name|void
name|isc_sockaddr_format
parameter_list|(
specifier|const
name|isc_sockaddr_t
modifier|*
name|sa
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
comment|/*  * Format a human-readable representation of the socket address '*sa'  * into the character array 'array', which is of size 'size'.  * The resulting string is guaranteed to be null-terminated.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_sockaddr_ismulticast
parameter_list|(
specifier|const
name|isc_sockaddr_t
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns ISC_TRUE if the address is a multicast address.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_sockaddr_isexperimental
parameter_list|(
specifier|const
name|isc_sockaddr_t
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns ISC_TRUE if the address is a experimental (CLASS E) address.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_sockaddr_islinklocal
parameter_list|(
specifier|const
name|isc_sockaddr_t
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns ISC_TRUE if the address is a link local addresss.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_sockaddr_issitelocal
parameter_list|(
specifier|const
name|isc_sockaddr_t
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns ISC_TRUE if the address is a sitelocal address.  */
end_comment

begin_define
define|#
directive|define
name|ISC_SOCKADDR_FORMATSIZE
define|\
value|sizeof("xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:XXX.XXX.XXX.XXX#YYYYY%SSSSSSSSSS")
end_define

begin_comment
comment|/*  * Minimum size of array to pass to isc_sockaddr_format().  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_SOCKADDR_H */
end_comment

end_unit

