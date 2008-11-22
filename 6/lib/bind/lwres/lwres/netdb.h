begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: netdb.h.in,v 1.34.206.1 2004/03/06 08:15:35 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LWRES_NETDB_H
end_ifndef

begin_define
define|#
directive|define
name|LWRES_NETDB_H
value|1
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* Required on FreeBSD (and  others?) for size_t. */
end_comment

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_comment
comment|/* Contractual provision. */
end_comment

begin_include
include|#
directive|include
file|<lwres/lang.h>
end_include

begin_comment
comment|/*  * Define if<netdb.h> does not declare struct addrinfo.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISC_LWRES_NEEDADDRINFO
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_LWRES_NEEDADDRINFO
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Undefine all #defines we are interested in as<netdb.h> may or may not have  * defined them.  */
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
comment|/* Non-Authoritive Host not found, or SERVERFAIL */
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
comment|/*  * Constants for lwres_getnameinfo()  */
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
comment|/*  * Flag values for lwres_getnameinfo()  */
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
comment|/*  * Define if<netdb.h> does not declare struct rrsetinfo.  */
end_comment

begin_define
define|#
directive|define
name|ISC_LWRES_NEEDRRSETINFO
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_LWRES_NEEDRRSETINFO
end_ifdef

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

begin_define
define|#
directive|define
name|ERRSET_NONAME
value|4
end_define

begin_define
define|#
directive|define
name|ERRSET_NODATA
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define to map into lwres_ namespace.  */
end_comment

begin_define
define|#
directive|define
name|LWRES_NAMESPACE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LWRES_NAMESPACE
end_ifdef

begin_comment
comment|/*  * Use our versions not the ones from the C library.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|getnameinfo
end_ifdef

begin_undef
undef|#
directive|undef
name|getnameinfo
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getnameinfo
value|lwres_getnameinfo
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|getaddrinfo
end_ifdef

begin_undef
undef|#
directive|undef
name|getaddrinfo
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getaddrinfo
value|lwres_getaddrinfo
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|freeaddrinfo
end_ifdef

begin_undef
undef|#
directive|undef
name|freeaddrinfo
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|freeaddrinfo
value|lwres_freeaddrinfo
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|gai_strerror
end_ifdef

begin_undef
undef|#
directive|undef
name|gai_strerror
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|gai_strerror
value|lwres_gai_strerror
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|herror
end_ifdef

begin_undef
undef|#
directive|undef
name|herror
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|herror
value|lwres_herror
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|hstrerror
end_ifdef

begin_undef
undef|#
directive|undef
name|hstrerror
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|hstrerror
value|lwres_hstrerror
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|getipnodebyname
end_ifdef

begin_undef
undef|#
directive|undef
name|getipnodebyname
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getipnodebyname
value|lwres_getipnodebyname
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|getipnodebyaddr
end_ifdef

begin_undef
undef|#
directive|undef
name|getipnodebyaddr
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getipnodebyaddr
value|lwres_getipnodebyaddr
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|freehostent
end_ifdef

begin_undef
undef|#
directive|undef
name|freehostent
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|freehostent
value|lwres_freehostent
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|gethostbyname
end_ifdef

begin_undef
undef|#
directive|undef
name|gethostbyname
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|gethostbyname
value|lwres_gethostbyname
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|gethostbyname2
end_ifdef

begin_undef
undef|#
directive|undef
name|gethostbyname2
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|gethostbyname2
value|lwres_gethostbyname2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|gethostbyaddr
end_ifdef

begin_undef
undef|#
directive|undef
name|gethostbyaddr
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|gethostbyaddr
value|lwres_gethostbyaddr
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|gethostent
end_ifdef

begin_undef
undef|#
directive|undef
name|gethostent
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|gethostent
value|lwres_gethostent
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|sethostent
end_ifdef

begin_undef
undef|#
directive|undef
name|sethostent
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|sethostent
value|lwres_sethostent
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|endhostent
end_ifdef

begin_undef
undef|#
directive|undef
name|endhostent
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|endhostent
value|lwres_endhostent
end_define

begin_comment
comment|/* #define sethostfile lwres_sethostfile */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|gethostbyname_r
end_ifdef

begin_undef
undef|#
directive|undef
name|gethostbyname_r
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|gethostbyname_r
value|lwres_gethostbyname_r
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|gethostbyaddr_r
end_ifdef

begin_undef
undef|#
directive|undef
name|gethostbyaddr_r
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|gethostbyaddr_r
value|lwres_gethostbyaddr_r
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|gethostent_r
end_ifdef

begin_undef
undef|#
directive|undef
name|gethostent_r
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|gethostent_r
value|lwres_gethostent_r
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|sethostent_r
end_ifdef

begin_undef
undef|#
directive|undef
name|sethostent_r
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|sethostent_r
value|lwres_sethostent_r
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|endhostent_r
end_ifdef

begin_undef
undef|#
directive|undef
name|endhostent_r
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|endhostent_r
value|lwres_endhostent_r
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|getrrsetbyname
end_ifdef

begin_undef
undef|#
directive|undef
name|getrrsetbyname
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getrrsetbyname
value|lwres_getrrsetbyname
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|freerrset
end_ifdef

begin_undef
undef|#
directive|undef
name|freerrset
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|freerrset
value|lwres_freerrset
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|getservbyname
value|lwres_getservbyname
end_define

begin_define
define|#
directive|define
name|getservbyport
value|lwres_getservbyport
end_define

begin_define
define|#
directive|define
name|getservent
value|lwres_getservent
end_define

begin_define
define|#
directive|define
name|setservent
value|lwres_setservent
end_define

begin_define
define|#
directive|define
name|endservent
value|lwres_endservent
end_define

begin_define
define|#
directive|define
name|getservbyname_r
value|lwres_getservbyname_r
end_define

begin_define
define|#
directive|define
name|getservbyport_r
value|lwres_getservbyport_r
end_define

begin_define
define|#
directive|define
name|getservent_r
value|lwres_getservent_r
end_define

begin_define
define|#
directive|define
name|setservent_r
value|lwres_setservent_r
end_define

begin_define
define|#
directive|define
name|endservent_r
value|lwres_endservent_r
end_define

begin_define
define|#
directive|define
name|getprotobyname
value|lwres_getprotobyname
end_define

begin_define
define|#
directive|define
name|getprotobynumber
value|lwres_getprotobynumber
end_define

begin_define
define|#
directive|define
name|getprotoent
value|lwres_getprotoent
end_define

begin_define
define|#
directive|define
name|setprotoent
value|lwres_setprotoent
end_define

begin_define
define|#
directive|define
name|endprotoent
value|lwres_endprotoent
end_define

begin_define
define|#
directive|define
name|getprotobyname_r
value|lwres_getprotobyname_r
end_define

begin_define
define|#
directive|define
name|getprotobynumber_r
value|lwres_getprotobynumber_r
end_define

begin_define
define|#
directive|define
name|getprotoent_r
value|lwres_getprotoent_r
end_define

begin_define
define|#
directive|define
name|setprotoent_r
value|lwres_setprotoent_r
end_define

begin_define
define|#
directive|define
name|endprotoent_r
value|lwres_endprotoent_r
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|getnetbyname
end_ifdef

begin_undef
undef|#
directive|undef
name|getnetbyname
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getnetbyname
value|lwres_getnetbyname
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|getnetbyaddr
end_ifdef

begin_undef
undef|#
directive|undef
name|getnetbyaddr
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getnetbyaddr
value|lwres_getnetbyaddr
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|getnetent
end_ifdef

begin_undef
undef|#
directive|undef
name|getnetent
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getnetent
value|lwres_getnetent
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|setnetent
end_ifdef

begin_undef
undef|#
directive|undef
name|setnetent
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|setnetent
value|lwres_setnetent
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|endnetent
end_ifdef

begin_undef
undef|#
directive|undef
name|endnetent
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|endnetent
value|lwres_endnetent
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|getnetbyname_r
end_ifdef

begin_undef
undef|#
directive|undef
name|getnetbyname_r
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getnetbyname_r
value|lwres_getnetbyname_r
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|getnetbyaddr_r
end_ifdef

begin_undef
undef|#
directive|undef
name|getnetbyaddr_r
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getnetbyaddr_r
value|lwres_getnetbyaddr_r
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|getnetent_r
end_ifdef

begin_undef
undef|#
directive|undef
name|getnetent_r
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getnetent_r
value|lwres_getnetent_r
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|setnetent_r
end_ifdef

begin_undef
undef|#
directive|undef
name|setnetent_r
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|setnetent_r
value|lwres_setnetent_r
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|endnetent_r
end_ifdef

begin_undef
undef|#
directive|undef
name|endnetent_r
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|endnetent_r
value|lwres_endnetent_r
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* notyet */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|h_errno
end_ifdef

begin_undef
undef|#
directive|undef
name|h_errno
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|h_errno
value|lwres_h_errno
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LWRES_NAMESPACE */
end_comment

begin_decl_stmt
name|LWRES_LANG_BEGINDECLS
specifier|extern
name|int
name|lwres_h_errno
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|lwres_getaddrinfo
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|addrinfo
modifier|*
parameter_list|,
name|struct
name|addrinfo
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lwres_getnameinfo
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_freeaddrinfo
parameter_list|(
name|struct
name|addrinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|lwres_gai_strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|lwres_gethostbyaddr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|lwres_gethostbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|lwres_gethostbyname2
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|lwres_gethostent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|lwres_getipnodebyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|lwres_getipnodebyaddr
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_endhostent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_sethostent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* void		lwres_sethostfile(const char *); */
end_comment

begin_function_decl
name|void
name|lwres_freehostent
parameter_list|(
name|struct
name|hostent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lwres_getrrsetbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|struct
name|rrsetinfo
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_freerrset
parameter_list|(
name|struct
name|rrsetinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_function_decl
name|struct
name|netent
modifier|*
name|lwres_getnetbyaddr
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netent
modifier|*
name|lwres_getnetbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netent
modifier|*
name|lwres_getnetent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_endnetent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_setnetent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|lwres_getprotobyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|lwres_getprotobynumber
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|lwres_getprotoent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_endprotoent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_setprotoent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|servent
modifier|*
name|lwres_getservbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|servent
modifier|*
name|lwres_getservbyport
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|servent
modifier|*
name|lwres_getservent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_endservent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_setservent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* notyet */
end_comment

begin_function_decl
name|void
name|lwres_herror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|lwres_hstrerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|lwres_gethostbyaddr_r
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|hostent
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|lwres_gethostbyname_r
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|hostent
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|lwres_gethostent_r
parameter_list|(
name|struct
name|hostent
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_sethostent_r
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_endhostent_r
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_function_decl
name|struct
name|netent
modifier|*
name|lwres_getnetbyname_r
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|netent
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netent
modifier|*
name|lwres_getnetbyaddr_r
parameter_list|(
name|long
parameter_list|,
name|int
parameter_list|,
name|struct
name|netent
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netent
modifier|*
name|lwres_getnetent_r
parameter_list|(
name|struct
name|netent
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_setnetent_r
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_endnetent_r
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|lwres_getprotobyname_r
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|protoent
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|lwres_getprotobynumber_r
parameter_list|(
name|int
parameter_list|,
name|struct
name|protoent
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|lwres_getprotoent_r
parameter_list|(
name|struct
name|protoent
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_setprotoent_r
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_endprotoent_r
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|servent
modifier|*
name|lwres_getservbyname_r
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|servent
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|servent
modifier|*
name|lwres_getservbyport_r
parameter_list|(
name|int
name|port
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|servent
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|servent
modifier|*
name|lwres_getservent_r
parameter_list|(
name|struct
name|servent
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_setservent_r
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lwres_endservent_r
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* notyet */
end_comment

begin_macro
name|LWRES_LANG_ENDDECLS
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_comment
comment|/* This is nec'y to make this include file properly replace the sun version. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNU_LIBRARY__
end_ifdef

begin_include
include|#
directive|include
file|<rpc/netdb.h>
end_include

begin_comment
comment|/* Required. */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__GNU_LIBRARY__ */
end_comment

begin_struct
struct|struct
name|rpcent
block|{
name|char
modifier|*
name|r_name
decl_stmt|;
comment|/* name of server for this rpc program */
name|char
modifier|*
modifier|*
name|r_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|r_number
decl_stmt|;
comment|/* rpc program number */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|rpcent
modifier|*
name|lwres_getrpcbyname
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|rpcent
modifier|*
name|lwres_getrpcbynumber
argument_list|()
decl_stmt|, struct
name|rpcent
modifier|*
name|lwres_getrpcent
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNU_LIBRARY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* notyet */
end_comment

begin_comment
comment|/*  * Tell Emacs to use C mode on this file.  * Local variables:  * mode: c  * End:  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LWRES_NETDB_H */
end_comment

end_unit

