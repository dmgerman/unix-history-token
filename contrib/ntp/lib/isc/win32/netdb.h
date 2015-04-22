begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006, 2007, 2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: netdb.h,v 1.9 2009/01/18 23:48:14 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NETDB_H
end_ifndef

begin_define
define|#
directive|define
name|NETDB_H
value|1
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_comment
comment|/*  * Define if<netdb.h> does not declare struct addrinfo.  */
end_comment

begin_struct
struct|struct
name|addrinfo
block|{
name|int
name|ai_flags
decl_stmt|;
comment|/* AI_PASSIVE, AI_CANONNAME */
name|int
name|ai_family
decl_stmt|;
comment|/* PF_xxx */
name|int
name|ai_socktype
decl_stmt|;
comment|/* SOCK_xxx */
name|int
name|ai_protocol
decl_stmt|;
comment|/* 0 or IPPROTO_xxx for IPv4 and IPv6 */
name|size_t
name|ai_addrlen
decl_stmt|;
comment|/* Length of ai_addr */
name|char
modifier|*
name|ai_canonname
decl_stmt|;
comment|/* Canonical name for hostname */
name|struct
name|sockaddr
modifier|*
name|ai_addr
decl_stmt|;
comment|/* Binary address */
name|struct
name|addrinfo
modifier|*
name|ai_next
decl_stmt|;
comment|/* Next structure in linked list */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Undefine all \#defines we are interested in as<netdb.h> may or may not have  * defined them.  */
end_comment

begin_comment
comment|/*  * Error return codes from gethostbyname() and gethostbyaddr()  * (left in extern int h_errno).  */
end_comment

begin_undef
undef|#
directive|undef
name|NETDB_INTERNAL
end_undef

begin_undef
undef|#
directive|undef
name|NETDB_SUCCESS
end_undef

begin_undef
undef|#
directive|undef
name|HOST_NOT_FOUND
end_undef

begin_undef
undef|#
directive|undef
name|TRY_AGAIN
end_undef

begin_undef
undef|#
directive|undef
name|NO_RECOVERY
end_undef

begin_undef
undef|#
directive|undef
name|NO_DATA
end_undef

begin_undef
undef|#
directive|undef
name|NO_ADDRESS
end_undef

begin_define
define|#
directive|define
name|NETDB_INTERNAL
value|-1
end_define

begin_comment
comment|/* see errno */
end_comment

begin_define
define|#
directive|define
name|NETDB_SUCCESS
value|0
end_define

begin_comment
comment|/* no problem */
end_comment

begin_define
define|#
directive|define
name|HOST_NOT_FOUND
value|1
end_define

begin_comment
comment|/* Authoritative Answer Host not found */
end_comment

begin_define
define|#
directive|define
name|TRY_AGAIN
value|2
end_define

begin_comment
comment|/* Non-Authoritative Host not found, or SERVERFAIL */
end_comment

begin_define
define|#
directive|define
name|NO_RECOVERY
value|3
end_define

begin_comment
comment|/* Non recoverable errors, FORMERR, REFUSED, NOTIMP */
end_comment

begin_define
define|#
directive|define
name|NO_DATA
value|4
end_define

begin_comment
comment|/* Valid name, no data record of requested type */
end_comment

begin_define
define|#
directive|define
name|NO_ADDRESS
value|NO_DATA
end_define

begin_comment
comment|/* no address, look for MX record */
end_comment

begin_comment
comment|/*  * Error return codes from getaddrinfo()  */
end_comment

begin_undef
undef|#
directive|undef
name|EAI_ADDRFAMILY
end_undef

begin_undef
undef|#
directive|undef
name|EAI_AGAIN
end_undef

begin_undef
undef|#
directive|undef
name|EAI_BADFLAGS
end_undef

begin_undef
undef|#
directive|undef
name|EAI_FAIL
end_undef

begin_undef
undef|#
directive|undef
name|EAI_FAMILY
end_undef

begin_undef
undef|#
directive|undef
name|EAI_MEMORY
end_undef

begin_undef
undef|#
directive|undef
name|EAI_NODATA
end_undef

begin_undef
undef|#
directive|undef
name|EAI_NONAME
end_undef

begin_undef
undef|#
directive|undef
name|EAI_SERVICE
end_undef

begin_undef
undef|#
directive|undef
name|EAI_SOCKTYPE
end_undef

begin_undef
undef|#
directive|undef
name|EAI_SYSTEM
end_undef

begin_undef
undef|#
directive|undef
name|EAI_BADHINTS
end_undef

begin_undef
undef|#
directive|undef
name|EAI_PROTOCOL
end_undef

begin_undef
undef|#
directive|undef
name|EAI_MAX
end_undef

begin_define
define|#
directive|define
name|EAI_ADDRFAMILY
value|1
end_define

begin_comment
comment|/* address family for hostname not supported */
end_comment

begin_define
define|#
directive|define
name|EAI_AGAIN
value|2
end_define

begin_comment
comment|/* temporary failure in name resolution */
end_comment

begin_define
define|#
directive|define
name|EAI_BADFLAGS
value|3
end_define

begin_comment
comment|/* invalid value for ai_flags */
end_comment

begin_define
define|#
directive|define
name|EAI_FAIL
value|4
end_define

begin_comment
comment|/* non-recoverable failure in name resolution */
end_comment

begin_define
define|#
directive|define
name|EAI_FAMILY
value|5
end_define

begin_comment
comment|/* ai_family not supported */
end_comment

begin_define
define|#
directive|define
name|EAI_MEMORY
value|6
end_define

begin_comment
comment|/* memory allocation failure */
end_comment

begin_define
define|#
directive|define
name|EAI_NODATA
value|7
end_define

begin_comment
comment|/* no address associated with hostname */
end_comment

begin_define
define|#
directive|define
name|EAI_NONAME
value|8
end_define

begin_comment
comment|/* hostname nor servname provided, or not known */
end_comment

begin_define
define|#
directive|define
name|EAI_SERVICE
value|9
end_define

begin_comment
comment|/* servname not supported for ai_socktype */
end_comment

begin_define
define|#
directive|define
name|EAI_SOCKTYPE
value|10
end_define

begin_comment
comment|/* ai_socktype not supported */
end_comment

begin_define
define|#
directive|define
name|EAI_SYSTEM
value|11
end_define

begin_comment
comment|/* system error returned in errno */
end_comment

begin_define
define|#
directive|define
name|EAI_BADHINTS
value|12
end_define

begin_define
define|#
directive|define
name|EAI_PROTOCOL
value|13
end_define

begin_define
define|#
directive|define
name|EAI_MAX
value|14
end_define

begin_comment
comment|/*  * Flag values for getaddrinfo()  */
end_comment

begin_undef
undef|#
directive|undef
name|AI_PASSIVE
end_undef

begin_undef
undef|#
directive|undef
name|AI_CANONNAME
end_undef

begin_undef
undef|#
directive|undef
name|AI_NUMERICHOST
end_undef

begin_define
define|#
directive|define
name|AI_PASSIVE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AI_CANONNAME
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AI_NUMERICHOST
value|0x00000004
end_define

begin_comment
comment|/*  * Flag values for getipnodebyname()  */
end_comment

begin_undef
undef|#
directive|undef
name|AI_V4MAPPED
end_undef

begin_undef
undef|#
directive|undef
name|AI_ALL
end_undef

begin_undef
undef|#
directive|undef
name|AI_ADDRCONFIG
end_undef

begin_undef
undef|#
directive|undef
name|AI_DEFAULT
end_undef

begin_define
define|#
directive|define
name|AI_V4MAPPED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AI_ALL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AI_ADDRCONFIG
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AI_DEFAULT
value|(AI_V4MAPPED|AI_ADDRCONFIG)
end_define

begin_comment
comment|/*  * Constants for getnameinfo()  */
end_comment

begin_undef
undef|#
directive|undef
name|NI_MAXHOST
end_undef

begin_undef
undef|#
directive|undef
name|NI_MAXSERV
end_undef

begin_define
define|#
directive|define
name|NI_MAXHOST
value|1025
end_define

begin_define
define|#
directive|define
name|NI_MAXSERV
value|32
end_define

begin_comment
comment|/*  * Flag values for getnameinfo()  */
end_comment

begin_undef
undef|#
directive|undef
name|NI_NOFQDN
end_undef

begin_undef
undef|#
directive|undef
name|NI_NUMERICHOST
end_undef

begin_undef
undef|#
directive|undef
name|NI_NAMEREQD
end_undef

begin_undef
undef|#
directive|undef
name|NI_NUMERICSERV
end_undef

begin_undef
undef|#
directive|undef
name|NI_DGRAM
end_undef

begin_undef
undef|#
directive|undef
name|NI_NUMERICSCOPE
end_undef

begin_define
define|#
directive|define
name|NI_NOFQDN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NI_NUMERICHOST
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NI_NAMEREQD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NI_NUMERICSERV
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NI_DGRAM
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NI_NUMERICSCOPE
value|0x00000020
end_define

begin_comment
comment|/*2553bis-00*/
end_comment

begin_comment
comment|/*  * Structures for getrrsetbyname()  */
end_comment

begin_struct
struct|struct
name|rdatainfo
block|{
name|unsigned
name|int
name|rdi_length
decl_stmt|;
name|unsigned
name|char
modifier|*
name|rdi_data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rrsetinfo
block|{
name|unsigned
name|int
name|rri_flags
decl_stmt|;
name|int
name|rri_rdclass
decl_stmt|;
name|int
name|rri_rdtype
decl_stmt|;
name|unsigned
name|int
name|rri_ttl
decl_stmt|;
name|unsigned
name|int
name|rri_nrdatas
decl_stmt|;
name|unsigned
name|int
name|rri_nsigs
decl_stmt|;
name|char
modifier|*
name|rri_name
decl_stmt|;
name|struct
name|rdatainfo
modifier|*
name|rri_rdatas
decl_stmt|;
name|struct
name|rdatainfo
modifier|*
name|rri_sigs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for getrrsetbyname()  */
end_comment

begin_define
define|#
directive|define
name|RRSET_VALIDATED
value|0x00000001
end_define

begin_comment
comment|/* Set was dnssec validated */
end_comment

begin_comment
comment|/*  * Return codes for getrrsetbyname()  */
end_comment

begin_define
define|#
directive|define
name|ERRSET_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|ERRSET_NOMEMORY
value|1
end_define

begin_define
define|#
directive|define
name|ERRSET_FAIL
value|2
end_define

begin_define
define|#
directive|define
name|ERRSET_INVAL
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETDB_H */
end_comment

end_unit

