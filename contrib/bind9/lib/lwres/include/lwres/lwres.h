begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: lwres.h,v 1.49.12.3 2004/03/08 09:05:11 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LWRES_LWRES_H
end_ifndef

begin_define
define|#
directive|define
name|LWRES_LWRES_H
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<lwres/context.h>
end_include

begin_include
include|#
directive|include
file|<lwres/lang.h>
end_include

begin_include
include|#
directive|include
file|<lwres/list.h>
end_include

begin_include
include|#
directive|include
file|<lwres/lwpacket.h>
end_include

begin_include
include|#
directive|include
file|<lwres/platform.h>
end_include

begin_comment
comment|/*  * Design notes:  *  * Each opcode has two structures and three functions which operate on each  * structure.  For example, using the "no operation/ping" opcode as an  * example:  *  *	lwres_nooprequest_t:  *  *		lwres_nooprequest_render() takes a lwres_nooprequest_t and  *		and renders it into wire format, storing the allocated  *		buffer information in a passed-in buffer.  When this buffer  *		is no longer needed, it must be freed by  *		lwres_context_freemem().  All other memory used by the  *		caller must be freed manually, including the  *		lwres_nooprequest_t passed in.  *  *		lwres_nooprequest_parse() takes a wire format message and  *		breaks it out into a lwres_nooprequest_t.  The structure  *		must be freed via lwres_nooprequest_free() when it is no longer  *		needed.  *  *		lwres_nooprequest_free() releases into the lwres_context_t  *		any space allocated during parsing.  *  *	lwres_noopresponse_t:  *  *		The functions used are similar to the three used for  *		requests, just with different names.  *  * Typically, the client will use request_render, response_parse, and  * response_free, while the daemon will use request_parse, response_render,  * and request_free.  *  * The basic flow of a typical client is:  *  *	fill in a request_t, and call the render function.  *  *	Transmit the buffer returned to the daemon.  *  *	Wait for a response.  *  *	When a response is received, parse it into a response_t.  *  *	free the request buffer using lwres_context_freemem().  *  *	free the response structure and its associated buffer using  *	response_free().  */
end_comment

begin_define
define|#
directive|define
name|LWRES_UDP_PORT
value|921
end_define

begin_define
define|#
directive|define
name|LWRES_RECVLENGTH
value|16384
end_define

begin_define
define|#
directive|define
name|LWRES_ADDR_MAXLEN
value|16
end_define

begin_comment
comment|/* changing this breaks ABI */
end_comment

begin_define
define|#
directive|define
name|LWRES_RESOLV_CONF
value|"/etc/resolv.conf"
end_define

begin_comment
comment|/*  * Flags.  *  * 	These flags are only relevant to rrset queries.  *  *	TRUSTNOTREQUIRED:  DNSSEC is not required (input)  *	SECUREDATA: The data was crypto-verified with DNSSEC (output)  *  */
end_comment

begin_define
define|#
directive|define
name|LWRES_FLAG_TRUSTNOTREQUIRED
value|0x00000001U
end_define

begin_define
define|#
directive|define
name|LWRES_FLAG_SECUREDATA
value|0x00000002U
end_define

begin_comment
comment|/*  * no-op  */
end_comment

begin_define
define|#
directive|define
name|LWRES_OPCODE_NOOP
value|0x00000000U
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* public */
name|lwres_uint16_t
name|datalength
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|lwres_nooprequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* public */
name|lwres_uint16_t
name|datalength
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|lwres_noopresponse_t
typedef|;
end_typedef

begin_comment
comment|/*  * get addresses by name  */
end_comment

begin_define
define|#
directive|define
name|LWRES_OPCODE_GETADDRSBYNAME
value|0x00010001U
end_define

begin_typedef
typedef|typedef
name|struct
name|lwres_addr
name|lwres_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|LWRES_LIST
argument_list|(
argument|lwres_addr_t
argument_list|)
name|lwres_addrlist_t
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|lwres_addr
block|{
name|lwres_uint32_t
name|family
decl_stmt|;
name|lwres_uint16_t
name|length
decl_stmt|;
name|unsigned
name|char
name|address
index|[
name|LWRES_ADDR_MAXLEN
index|]
decl_stmt|;
name|LWRES_LINK
argument_list|(
argument|lwres_addr_t
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* public */
name|lwres_uint32_t
name|flags
decl_stmt|;
name|lwres_uint32_t
name|addrtypes
decl_stmt|;
name|lwres_uint16_t
name|namelen
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|lwres_gabnrequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* public */
name|lwres_uint32_t
name|flags
decl_stmt|;
name|lwres_uint16_t
name|naliases
decl_stmt|;
name|lwres_uint16_t
name|naddrs
decl_stmt|;
name|char
modifier|*
name|realname
decl_stmt|;
name|char
modifier|*
modifier|*
name|aliases
decl_stmt|;
name|lwres_uint16_t
name|realnamelen
decl_stmt|;
name|lwres_uint16_t
modifier|*
name|aliaslen
decl_stmt|;
name|lwres_addrlist_t
name|addrs
decl_stmt|;
comment|/* if base != NULL, it will be freed when this structure is freed. */
name|void
modifier|*
name|base
decl_stmt|;
name|size_t
name|baselen
decl_stmt|;
block|}
name|lwres_gabnresponse_t
typedef|;
end_typedef

begin_comment
comment|/*  * get name by address  */
end_comment

begin_define
define|#
directive|define
name|LWRES_OPCODE_GETNAMEBYADDR
value|0x00010002U
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* public */
name|lwres_uint32_t
name|flags
decl_stmt|;
name|lwres_addr_t
name|addr
decl_stmt|;
block|}
name|lwres_gnbarequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* public */
name|lwres_uint32_t
name|flags
decl_stmt|;
name|lwres_uint16_t
name|naliases
decl_stmt|;
name|char
modifier|*
name|realname
decl_stmt|;
name|char
modifier|*
modifier|*
name|aliases
decl_stmt|;
name|lwres_uint16_t
name|realnamelen
decl_stmt|;
name|lwres_uint16_t
modifier|*
name|aliaslen
decl_stmt|;
comment|/* if base != NULL, it will be freed when this structure is freed. */
name|void
modifier|*
name|base
decl_stmt|;
name|size_t
name|baselen
decl_stmt|;
block|}
name|lwres_gnbaresponse_t
typedef|;
end_typedef

begin_comment
comment|/*  * get rdata by name  */
end_comment

begin_define
define|#
directive|define
name|LWRES_OPCODE_GETRDATABYNAME
value|0x00010003U
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* public */
name|lwres_uint32_t
name|flags
decl_stmt|;
name|lwres_uint16_t
name|rdclass
decl_stmt|;
name|lwres_uint16_t
name|rdtype
decl_stmt|;
name|lwres_uint16_t
name|namelen
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|lwres_grbnrequest_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* public */
name|lwres_uint32_t
name|flags
decl_stmt|;
name|lwres_uint16_t
name|rdclass
decl_stmt|;
name|lwres_uint16_t
name|rdtype
decl_stmt|;
name|lwres_uint32_t
name|ttl
decl_stmt|;
name|lwres_uint16_t
name|nrdatas
decl_stmt|;
name|lwres_uint16_t
name|nsigs
decl_stmt|;
name|char
modifier|*
name|realname
decl_stmt|;
name|lwres_uint16_t
name|realnamelen
decl_stmt|;
name|unsigned
name|char
modifier|*
modifier|*
name|rdatas
decl_stmt|;
name|lwres_uint16_t
modifier|*
name|rdatalen
decl_stmt|;
name|unsigned
name|char
modifier|*
modifier|*
name|sigs
decl_stmt|;
name|lwres_uint16_t
modifier|*
name|siglen
decl_stmt|;
comment|/* if base != NULL, it will be freed when this structure is freed. */
name|void
modifier|*
name|base
decl_stmt|;
name|size_t
name|baselen
decl_stmt|;
block|}
name|lwres_grbnresponse_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LWRDATA_VALIDATED
value|0x00000001
end_define

begin_comment
comment|/*  * resolv.conf data  */
end_comment

begin_define
define|#
directive|define
name|LWRES_CONFMAXNAMESERVERS
value|3
end_define

begin_comment
comment|/* max 3 "nameserver" entries */
end_comment

begin_define
define|#
directive|define
name|LWRES_CONFMAXLWSERVERS
value|1
end_define

begin_comment
comment|/* max 1 "lwserver" entry */
end_comment

begin_define
define|#
directive|define
name|LWRES_CONFMAXSEARCH
value|8
end_define

begin_comment
comment|/* max 8 domains in "search" entry */
end_comment

begin_define
define|#
directive|define
name|LWRES_CONFMAXLINELEN
value|256
end_define

begin_comment
comment|/* max size of a line */
end_comment

begin_define
define|#
directive|define
name|LWRES_CONFMAXSORTLIST
value|10
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|lwres_context_t
modifier|*
name|lwctx
decl_stmt|;
name|lwres_addr_t
name|nameservers
index|[
name|LWRES_CONFMAXNAMESERVERS
index|]
decl_stmt|;
name|lwres_uint8_t
name|nsnext
decl_stmt|;
comment|/* index for next free slot */
name|lwres_addr_t
name|lwservers
index|[
name|LWRES_CONFMAXLWSERVERS
index|]
decl_stmt|;
name|lwres_uint8_t
name|lwnext
decl_stmt|;
comment|/* index for next free slot */
name|char
modifier|*
name|domainname
decl_stmt|;
name|char
modifier|*
name|search
index|[
name|LWRES_CONFMAXSEARCH
index|]
decl_stmt|;
name|lwres_uint8_t
name|searchnxt
decl_stmt|;
comment|/* index for next free slot */
struct|struct
block|{
name|lwres_addr_t
name|addr
decl_stmt|;
comment|/* mask has a non-zero 'family' and 'length' if set */
name|lwres_addr_t
name|mask
decl_stmt|;
block|}
name|sortlist
index|[
name|LWRES_CONFMAXSORTLIST
index|]
struct|;
name|lwres_uint8_t
name|sortlistnxt
decl_stmt|;
name|lwres_uint8_t
name|resdebug
decl_stmt|;
comment|/* non-zero if 'options debug' set */
name|lwres_uint8_t
name|ndots
decl_stmt|;
comment|/* set to n in 'options ndots:n' */
name|lwres_uint8_t
name|no_tld_query
decl_stmt|;
comment|/* non-zero if 'options no_tld_query' */
block|}
name|lwres_conf_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LWRES_ADDRTYPE_V4
value|0x00000001U
end_define

begin_comment
comment|/* ipv4 */
end_comment

begin_define
define|#
directive|define
name|LWRES_ADDRTYPE_V6
value|0x00000002U
end_define

begin_comment
comment|/* ipv6 */
end_comment

begin_define
define|#
directive|define
name|LWRES_MAX_ALIASES
value|16
end_define

begin_comment
comment|/* max # of aliases */
end_comment

begin_define
define|#
directive|define
name|LWRES_MAX_ADDRS
value|64
end_define

begin_comment
comment|/* max # of addrs */
end_comment

begin_decl_stmt
name|LWRES_LANG_BEGINDECLS
comment|/*  * This is in host byte order.  */
name|LIBLWRES_EXTERNAL_DATA
specifier|extern
name|lwres_uint16_t
name|lwres_udp_port
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBLWRES_EXTERNAL_DATA
specifier|extern
specifier|const
name|char
modifier|*
name|lwres_resolv_conf
decl_stmt|;
end_decl_stmt

begin_function_decl
name|lwres_result_t
name|lwres_gabnrequest_render
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_gabnrequest_t
modifier|*
name|req
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_gabnresponse_render
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_gabnresponse_t
modifier|*
name|req
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_gabnrequest_parse
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_gabnrequest_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_gabnresponse_parse
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_gabnresponse_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_gabnrequest_free
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_gabnrequest_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Frees any dynamically allocated memory for this structure.  *  * Requires:  *  *	ctx != NULL, and be a context returned via lwres_contextcreate().  *  *	structp != NULL&& *structp != NULL.  *  * Ensures:  *  *	*structp == NULL.  *  *	All memory allocated by this structure will be returned to the  *	system via the context's free function.  */
end_comment

begin_function_decl
name|void
name|lwres_gabnresponse_free
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_gabnresponse_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Frees any dynamically allocated memory for this structure.  *  * Requires:  *  *	ctx != NULL, and be a context returned via lwres_contextcreate().  *  *	structp != NULL&& *structp != NULL.  *  * Ensures:  *  *	*structp == NULL.  *  *	All memory allocated by this structure will be returned to the  *	system via the context's free function.  */
end_comment

begin_function_decl
name|lwres_result_t
name|lwres_gnbarequest_render
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_gnbarequest_t
modifier|*
name|req
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_gnbaresponse_render
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_gnbaresponse_t
modifier|*
name|req
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_gnbarequest_parse
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_gnbarequest_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_gnbaresponse_parse
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_gnbaresponse_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_gnbarequest_free
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_gnbarequest_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Frees any dynamically allocated memory for this structure.  *  * Requires:  *  *	ctx != NULL, and be a context returned via lwres_contextcreate().  *  *	structp != NULL&& *structp != NULL.  *  * Ensures:  *  *	*structp == NULL.  *  *	All memory allocated by this structure will be returned to the  *	system via the context's free function.  */
end_comment

begin_function_decl
name|void
name|lwres_gnbaresponse_free
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_gnbaresponse_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Frees any dynamically allocated memory for this structure.  *  * Requires:  *  *	ctx != NULL, and be a context returned via lwres_contextcreate().  *  *	structp != NULL&& *structp != NULL.  *  * Ensures:  *  *	*structp == NULL.  *  *	All memory allocated by this structure will be returned to the  *	system via the context's free function.  */
end_comment

begin_function_decl
name|lwres_result_t
name|lwres_grbnrequest_render
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_grbnrequest_t
modifier|*
name|req
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_grbnresponse_render
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_grbnresponse_t
modifier|*
name|req
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_grbnrequest_parse
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_grbnrequest_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_grbnresponse_parse
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_grbnresponse_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_grbnrequest_free
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_grbnrequest_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Frees any dynamically allocated memory for this structure.  *  * Requires:  *  *	ctx != NULL, and be a context returned via lwres_contextcreate().  *  *	structp != NULL&& *structp != NULL.  *  * Ensures:  *  *	*structp == NULL.  *  *	All memory allocated by this structure will be returned to the  *	system via the context's free function.  */
end_comment

begin_function_decl
name|void
name|lwres_grbnresponse_free
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_grbnresponse_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Frees any dynamically allocated memory for this structure.  *  * Requires:  *  *	ctx != NULL, and be a context returned via lwres_contextcreate().  *  *	structp != NULL&& *structp != NULL.  *  * Ensures:  *  *	*structp == NULL.  *  *	All memory allocated by this structure will be returned to the  *	system via the context's free function.  */
end_comment

begin_function_decl
name|lwres_result_t
name|lwres_nooprequest_render
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_nooprequest_t
modifier|*
name|req
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate space and render into wire format a noop request packet.  *  * Requires:  *  *	ctx != NULL, and be a context returned via lwres_contextcreate().  *  *	b != NULL, and points to a lwres_buffer_t.  The contents of the  *	buffer structure will be initialized to contain the wire-format  *	noop request packet.  *  *	Caller needs to fill in parts of "pkt" before calling:  *		serial, maxrecv, result.  *  * Returns:  *  *	Returns 0 on success, non-zero on failure.  *  *	On successful return, *b will contain data about the wire-format  *	packet.  It can be transmitted in any way, including lwres_sendblock().  */
end_comment

begin_function_decl
name|lwres_result_t
name|lwres_noopresponse_render
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_noopresponse_t
modifier|*
name|req
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_nooprequest_parse
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_nooprequest_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Parse a noop request.  Note that to get here, the lwpacket must have  * already been parsed and removed by the caller, otherwise it would be  * pretty hard for it to know this is the right function to call.  *  * The function verifies bits of the header, but does not modify it.  */
end_comment

begin_function_decl
name|lwres_result_t
name|lwres_noopresponse_parse
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|lwres_lwpacket_t
modifier|*
name|pkt
parameter_list|,
name|lwres_noopresponse_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_nooprequest_free
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_nooprequest_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_noopresponse_free
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_noopresponse_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Frees any dynamically allocated memory for this structure.  *  * Requires:  *  *	ctx != NULL, and be a context returned via lwres_contextcreate().  *  *	structp != NULL&& *structp != NULL.  *  * Ensures:  *  *	*structp == NULL.  *  *	All memory allocated by this structure will be returned to the  *	system via the context's free function.  */
end_comment

begin_function_decl
name|lwres_result_t
name|lwres_conf_parse
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * parses a resolv.conf-format file and stores the results in the structure  * pointed to by *ctx.  *  * Requires:  *	ctx != NULL  *	filename != NULL&& strlen(filename)> 0  *  * Returns:  *	LWRES_R_SUCCESS on a successful parse.  *	Anything else on error, although the structure may be partially filled  *	in.  */
end_comment

begin_function_decl
name|lwres_result_t
name|lwres_conf_print
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Prints a resolv.conf-format of confdata output to fp.  *  * Requires:  *	ctx != NULL  */
end_comment

begin_function_decl
name|void
name|lwres_conf_init
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * sets all internal fields to a default state. Used to initialize a new  * lwres_conf_t structure (not reset a used on).  *  * Requires:  *	ctx != NULL  */
end_comment

begin_function_decl
name|void
name|lwres_conf_clear
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * frees all internally allocated memory in confdata. Uses the memory  * routines supplied by ctx.  *  * Requires:  *	ctx != NULL  */
end_comment

begin_function_decl
name|lwres_conf_t
modifier|*
name|lwres_conf_get
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * returns a pointer to the current config structure.  * Be extremely cautions in modifying the contents of this structure; it  * needs an API to return the various bits of data, walk lists, etc.  *  * Requires:  *	ctx != NULL  */
end_comment

begin_comment
comment|/*  * Helper functions  */
end_comment

begin_function_decl
name|lwres_result_t
name|lwres_data_parse
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
name|p
parameter_list|,
name|lwres_uint16_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_string_parse
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|char
modifier|*
modifier|*
name|c
parameter_list|,
name|lwres_uint16_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_addr_parse
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|lwres_addr_t
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_getaddrsbyname
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|lwres_uint32_t
name|addrtypes
parameter_list|,
name|lwres_gabnresponse_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_getnamebyaddr
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
name|lwres_uint32_t
name|addrtype
parameter_list|,
name|lwres_uint16_t
name|addrlen
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|addr
parameter_list|,
name|lwres_gnbaresponse_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|lwres_result_t
name|lwres_getrdatabyname
parameter_list|(
name|lwres_context_t
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|lwres_uint16_t
name|rdclass
parameter_list|,
name|lwres_uint16_t
name|rdtype
parameter_list|,
name|lwres_uint32_t
name|flags
parameter_list|,
name|lwres_grbnresponse_t
modifier|*
modifier|*
name|structp
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|LWRES_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LWRES_LWRES_H */
end_comment

end_unit

