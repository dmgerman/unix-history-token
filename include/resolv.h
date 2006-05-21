begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1987, 1989  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (c) 1996-1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  *	@(#)resolv.h	8.1 (Berkeley) 6/2/93  *	$Id: resolv.h,v 1.7.2.11.4.3 2005/08/25 04:44:13 marka Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RESOLV_H_
end_ifndef

begin_define
define|#
directive|define
name|_RESOLV_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_comment
comment|/*  * Revision information.  This is the release date in YYYYMMDD format.  * It can change every day so the right thing to do with it is use it  * in preprocessor commands such as "#if (__RES> 19931104)".  Do not  * compare for equality; rather, use it to determine whether your resolver  * is new enough to contain a certain feature.  */
end_comment

begin_define
define|#
directive|define
name|__RES
value|20030124
end_define

begin_comment
comment|/*  * This used to be defined in res_query.c, now it's in herror.c.  * [XXX no it's not.  It's in irs/irs_data.c]  * It was  * never extern'd by any *.h file before it was placed here.  For thread  * aware programs, the last h_errno value set is stored in res->h_errno.  *  * XXX:	There doesn't seem to be a good reason for exposing RES_SET_H_ERRNO  *	(and __h_errno_set) to the public via<resolv.h>.  * XXX:	__h_errno_set is really part of IRS, not part of the resolver.  *	If somebody wants to build and use a resolver that doesn't use IRS,  *	what do they do?  Perhaps something like  *		#ifdef WANT_IRS  *		# define RES_SET_H_ERRNO(r,x) __h_errno_set(r,x)  *		#else  *		# define RES_SET_H_ERRNO(r,x) (h_errno = (r)->res_h_errno = (x))  *		#endif  */
end_comment

begin_define
define|#
directive|define
name|RES_SET_H_ERRNO
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|)
value|__h_errno_set(r,x)
end_define

begin_struct_decl
struct_decl|struct
name|__res_state
struct_decl|;
end_struct_decl

begin_comment
comment|/* forward */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|void
name|__h_errno_set
parameter_list|(
name|struct
name|__res_state
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_comment
comment|/*  * Resolver configuration file.  * Normally not present, but may contain the address of the  * initial name server(s) to query and the domain search list.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_RESCONF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_RESCONF
value|"/etc/resolv.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
enum|enum
block|{
name|res_goahead
block|,
name|res_nextns
block|,
name|res_modified
block|,
name|res_done
block|,
name|res_error
block|}
name|res_sendhookact
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|res_sendhookact
function_decl|(
modifier|*
name|res_send_qhook
function_decl|)
parameter_list|(
name|struct
name|sockaddr
modifier|*
specifier|const
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|res_sendhookact
function_decl|(
modifier|*
name|res_send_rhook
function_decl|)
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|res_sym
block|{
name|int
name|number
decl_stmt|;
comment|/* Identifying number, like T_MX */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Its symbolic name, like "MX" */
specifier|const
name|char
modifier|*
name|humanname
decl_stmt|;
comment|/* Its fun name, like "mail exchanger" */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Global defines and variables for resolver stub.  */
end_comment

begin_define
define|#
directive|define
name|MAXNS
value|3
end_define

begin_comment
comment|/* max # name servers we'll track */
end_comment

begin_define
define|#
directive|define
name|MAXDFLSRCH
value|3
end_define

begin_comment
comment|/* # default domain levels to try */
end_comment

begin_define
define|#
directive|define
name|MAXDNSRCH
value|6
end_define

begin_comment
comment|/* max # domains in search path */
end_comment

begin_define
define|#
directive|define
name|LOCALDOMAINPARTS
value|2
end_define

begin_comment
comment|/* min levels in name that is "local" */
end_comment

begin_define
define|#
directive|define
name|RES_TIMEOUT
value|5
end_define

begin_comment
comment|/* min. seconds between retries */
end_comment

begin_define
define|#
directive|define
name|MAXRESOLVSORT
value|10
end_define

begin_comment
comment|/* number of net to sort on */
end_comment

begin_define
define|#
directive|define
name|RES_MAXNDOTS
value|15
end_define

begin_comment
comment|/* should reflect bit field size */
end_comment

begin_define
define|#
directive|define
name|RES_MAXRETRANS
value|30
end_define

begin_comment
comment|/* only for resolv.conf/RES_OPTIONS */
end_comment

begin_define
define|#
directive|define
name|RES_MAXRETRY
value|5
end_define

begin_comment
comment|/* only for resolv.conf/RES_OPTIONS */
end_comment

begin_define
define|#
directive|define
name|RES_DFLRETRY
value|2
end_define

begin_comment
comment|/* Default #/tries. */
end_comment

begin_define
define|#
directive|define
name|RES_MAXTIME
value|65535
end_define

begin_comment
comment|/* Infinity, in milliseconds. */
end_comment

begin_struct_decl
struct_decl|struct
name|__res_state_ext
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|__res_state
block|{
name|int
name|retrans
decl_stmt|;
comment|/* retransmission time interval */
name|int
name|retry
decl_stmt|;
comment|/* number of times to retransmit */
comment|/* 	 * XXX: If `sun' is defined, `options' and `pfcode' are 	 * defined as u_int in original BIND9 distribution.  However, 	 * it breaks binary backward compatibility against FreeBSD's 	 * resolver.  So, we changed not to see `sun'. 	 */
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
literal|0
name|u_int
name|options
decl_stmt|;
comment|/* option flags - see below. */
else|#
directive|else
name|u_long
name|options
decl_stmt|;
comment|/* option flags - see below. */
endif|#
directive|endif
name|int
name|nscount
decl_stmt|;
comment|/* number of name servers */
name|struct
name|sockaddr_in
name|nsaddr_list
index|[
name|MAXNS
index|]
decl_stmt|;
comment|/* address of name server */
define|#
directive|define
name|nsaddr
value|nsaddr_list[0]
comment|/* for backward compatibility */
name|u_short
name|id
decl_stmt|;
comment|/* current message id */
name|char
modifier|*
name|dnsrch
index|[
name|MAXDNSRCH
operator|+
literal|1
index|]
decl_stmt|;
comment|/* components of domain to search */
name|char
name|defdname
index|[
literal|256
index|]
decl_stmt|;
comment|/* default domain (deprecated) */
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
literal|0
name|u_int
name|pfcode
decl_stmt|;
comment|/* RES_PRF_ flags - see below. */
else|#
directive|else
name|u_long
name|pfcode
decl_stmt|;
comment|/* RES_PRF_ flags - see below. */
endif|#
directive|endif
name|unsigned
name|ndots
range|:
literal|4
decl_stmt|;
comment|/* threshold for initial abs. query */
name|unsigned
name|nsort
range|:
literal|4
decl_stmt|;
comment|/* number of elements in sort_list[] */
name|char
name|unused
index|[
literal|3
index|]
decl_stmt|;
struct|struct
block|{
name|struct
name|in_addr
name|addr
decl_stmt|;
name|u_int32_t
name|mask
decl_stmt|;
block|}
name|sort_list
index|[
name|MAXRESOLVSORT
index|]
struct|;
name|res_send_qhook
name|qhook
decl_stmt|;
comment|/* query hook */
name|res_send_rhook
name|rhook
decl_stmt|;
comment|/* response hook */
name|int
name|res_h_errno
decl_stmt|;
comment|/* last one set for this context */
name|int
name|_vcsock
decl_stmt|;
comment|/* PRIVATE: for res_send VC i/o */
name|u_int
name|_flags
decl_stmt|;
comment|/* PRIVATE: see below */
name|u_int
name|_pad
decl_stmt|;
comment|/* make _u 64 bit aligned */
union|union
block|{
comment|/* On an 32-bit arch this means 512b total. */
name|char
name|pad
index|[
literal|72
operator|-
literal|4
operator|*
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|-
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
struct|struct
block|{
name|u_int16_t
name|nscount
decl_stmt|;
name|u_int16_t
name|nstimes
index|[
name|MAXNS
index|]
decl_stmt|;
comment|/* ms. */
name|int
name|nssocks
index|[
name|MAXNS
index|]
decl_stmt|;
name|struct
name|__res_state_ext
modifier|*
name|ext
decl_stmt|;
comment|/* extention for IPv6 */
block|}
name|_ext
struct|;
block|}
name|_u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|__res_state
modifier|*
name|res_state
typedef|;
end_typedef

begin_union
union|union
name|res_sockaddr_union
block|{
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
ifdef|#
directive|ifdef
name|IN6ADDR_ANY_INIT
name|struct
name|sockaddr_in6
name|sin6
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ISC_ALIGN64
name|int64_t
name|__align64
decl_stmt|;
comment|/* 64bit alignment */
else|#
directive|else
name|int32_t
name|__align32
decl_stmt|;
comment|/* 32bit alignment */
endif|#
directive|endif
name|char
name|__space
index|[
literal|128
index|]
decl_stmt|;
comment|/* max size */
block|}
union|;
end_union

begin_comment
comment|/*  * Resolver flags (used to be discrete per-module statics ints).  */
end_comment

begin_define
define|#
directive|define
name|RES_F_VC
value|0x00000001
end_define

begin_comment
comment|/* socket is TCP */
end_comment

begin_define
define|#
directive|define
name|RES_F_CONN
value|0x00000002
end_define

begin_comment
comment|/* socket is connected */
end_comment

begin_define
define|#
directive|define
name|RES_F_EDNS0ERR
value|0x00000004
end_define

begin_comment
comment|/* EDNS0 caused errors */
end_comment

begin_define
define|#
directive|define
name|RES_F__UNUSED
value|0x00000008
end_define

begin_comment
comment|/* (unused) */
end_comment

begin_define
define|#
directive|define
name|RES_F_LASTMASK
value|0x000000F0
end_define

begin_comment
comment|/* ordinal server of last res_nsend */
end_comment

begin_define
define|#
directive|define
name|RES_F_LASTSHIFT
value|4
end_define

begin_comment
comment|/* bit position of LASTMASK "flag" */
end_comment

begin_define
define|#
directive|define
name|RES_GETLAST
parameter_list|(
name|res
parameter_list|)
value|(((res)._flags& RES_F_LASTMASK)>> RES_F_LASTSHIFT)
end_define

begin_comment
comment|/* res_findzonecut2() options */
end_comment

begin_define
define|#
directive|define
name|RES_EXHAUSTIVE
value|0x00000001
end_define

begin_comment
comment|/* always do all queries */
end_comment

begin_define
define|#
directive|define
name|RES_IPV4ONLY
value|0x00000002
end_define

begin_comment
comment|/* IPv4 only */
end_comment

begin_define
define|#
directive|define
name|RES_IPV6ONLY
value|0x00000004
end_define

begin_comment
comment|/* IPv6 only */
end_comment

begin_comment
comment|/*  * Resolver options (keep these in synch with res_debug.c, please)  */
end_comment

begin_define
define|#
directive|define
name|RES_INIT
value|0x00000001
end_define

begin_comment
comment|/* address initialized */
end_comment

begin_define
define|#
directive|define
name|RES_DEBUG
value|0x00000002
end_define

begin_comment
comment|/* print debug messages */
end_comment

begin_define
define|#
directive|define
name|RES_AAONLY
value|0x00000004
end_define

begin_comment
comment|/* authoritative answers only (!IMPL)*/
end_comment

begin_define
define|#
directive|define
name|RES_USEVC
value|0x00000008
end_define

begin_comment
comment|/* use virtual circuit */
end_comment

begin_define
define|#
directive|define
name|RES_PRIMARY
value|0x00000010
end_define

begin_comment
comment|/* query primary server only (!IMPL) */
end_comment

begin_define
define|#
directive|define
name|RES_IGNTC
value|0x00000020
end_define

begin_comment
comment|/* ignore truncation errors */
end_comment

begin_define
define|#
directive|define
name|RES_RECURSE
value|0x00000040
end_define

begin_comment
comment|/* recursion desired */
end_comment

begin_define
define|#
directive|define
name|RES_DEFNAMES
value|0x00000080
end_define

begin_comment
comment|/* use default domain name */
end_comment

begin_define
define|#
directive|define
name|RES_STAYOPEN
value|0x00000100
end_define

begin_comment
comment|/* Keep TCP socket open */
end_comment

begin_define
define|#
directive|define
name|RES_DNSRCH
value|0x00000200
end_define

begin_comment
comment|/* search up local domain tree */
end_comment

begin_define
define|#
directive|define
name|RES_INSECURE1
value|0x00000400
end_define

begin_comment
comment|/* type 1 security disabled */
end_comment

begin_define
define|#
directive|define
name|RES_INSECURE2
value|0x00000800
end_define

begin_comment
comment|/* type 2 security disabled */
end_comment

begin_define
define|#
directive|define
name|RES_NOALIASES
value|0x00001000
end_define

begin_comment
comment|/* shuts off HOSTALIASES feature */
end_comment

begin_define
define|#
directive|define
name|RES_USE_INET6
value|0x00002000
end_define

begin_comment
comment|/* use/map IPv6 in gethostbyname() */
end_comment

begin_define
define|#
directive|define
name|RES_ROTATE
value|0x00004000
end_define

begin_comment
comment|/* rotate ns list after each query */
end_comment

begin_define
define|#
directive|define
name|RES_NOCHECKNAME
value|0x00008000
end_define

begin_comment
comment|/* do not check names for sanity. */
end_comment

begin_define
define|#
directive|define
name|RES_KEEPTSIG
value|0x00010000
end_define

begin_comment
comment|/* do not strip TSIG records */
end_comment

begin_define
define|#
directive|define
name|RES_BLAST
value|0x00020000
end_define

begin_comment
comment|/* blast all recursive servers */
end_comment

begin_define
define|#
directive|define
name|RES_NOTLDQUERY
value|0x00100000
end_define

begin_comment
comment|/* don't unqualified name as a tld */
end_comment

begin_define
define|#
directive|define
name|RES_USE_DNSSEC
value|0x00200000
end_define

begin_comment
comment|/* use DNSSEC using OK bit in OPT */
end_comment

begin_comment
comment|/* #define RES_DEBUG2	0x00400000 */
end_comment

begin_comment
comment|/* nslookup internal */
end_comment

begin_comment
comment|/* KAME extensions: use higher bit to avoid conflict with ISC use */
end_comment

begin_define
define|#
directive|define
name|RES_USE_DNAME
value|0x10000000
end_define

begin_comment
comment|/* use DNAME */
end_comment

begin_define
define|#
directive|define
name|RES_USE_EDNS0
value|0x40000000
end_define

begin_comment
comment|/* use EDNS0 if configured */
end_comment

begin_define
define|#
directive|define
name|RES_NO_NIBBLE2
value|0x80000000
end_define

begin_comment
comment|/* disable alternate nibble lookup */
end_comment

begin_define
define|#
directive|define
name|RES_DEFAULT
value|(RES_RECURSE | RES_DEFNAMES | \ 			 RES_DNSRCH | RES_NO_NIBBLE2)
end_define

begin_comment
comment|/*  * Resolver "pfcode" values.  Used by dig.  */
end_comment

begin_define
define|#
directive|define
name|RES_PRF_STATS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RES_PRF_UPDATE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RES_PRF_CLASS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RES_PRF_CMD
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RES_PRF_QUES
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RES_PRF_ANS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RES_PRF_AUTH
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RES_PRF_ADD
value|0x00000080
end_define

begin_define
define|#
directive|define
name|RES_PRF_HEAD1
value|0x00000100
end_define

begin_define
define|#
directive|define
name|RES_PRF_HEAD2
value|0x00000200
end_define

begin_define
define|#
directive|define
name|RES_PRF_TTLID
value|0x00000400
end_define

begin_define
define|#
directive|define
name|RES_PRF_HEADX
value|0x00000800
end_define

begin_define
define|#
directive|define
name|RES_PRF_QUERY
value|0x00001000
end_define

begin_define
define|#
directive|define
name|RES_PRF_REPLY
value|0x00002000
end_define

begin_define
define|#
directive|define
name|RES_PRF_INIT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|RES_PRF_TRUNC
value|0x00008000
end_define

begin_comment
comment|/*			0x00010000	*/
end_comment

begin_comment
comment|/* Things involving an internal (static) resolver context. */
end_comment

begin_expr_stmt
name|__BEGIN_DECLS
specifier|extern
expr|struct
name|__res_state
operator|*
name|__res_state
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|__END_DECLS
define|#
directive|define
name|_res
value|(*__res_state())
ifndef|#
directive|ifndef
name|__BIND_NOSTATIC
define|#
directive|define
name|fp_nquery
value|__fp_nquery
define|#
directive|define
name|fp_query
value|__fp_query
define|#
directive|define
name|hostalias
value|__hostalias
define|#
directive|define
name|p_query
value|__p_query
define|#
directive|define
name|res_close
value|__res_close
define|#
directive|define
name|res_init
value|__res_init
define|#
directive|define
name|res_isourserver
value|__res_isourserver
define|#
directive|define
name|res_mkquery
value|__res_mkquery
define|#
directive|define
name|res_opt
value|__res_opt
define|#
directive|define
name|res_query
value|__res_query
define|#
directive|define
name|res_querydomain
value|__res_querydomain
define|#
directive|define
name|res_search
value|__res_search
define|#
directive|define
name|res_send
value|__res_send
define|#
directive|define
name|res_sendsigned
value|__res_sendsigned
name|__BEGIN_DECLS
name|void
name|fp_nquery
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fp_query
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|hostalias
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|p_query
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|res_close
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_isourserver
parameter_list|(
specifier|const
name|struct
name|sockaddr_in
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_mkquery
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_opt
parameter_list|(
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_query
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_querydomain
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_search
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_send
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_sendsigned
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|ns_tsig_key
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|__END_DECLS
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SHARED_LIBBIND
argument_list|)
operator|||
name|defined
argument_list|(
name|LIB
argument_list|)
comment|/*  * If libbind is a shared object (well, DLL anyway)  * these externs break the linker when resolv.h is   * included by a lib client (like named)  * Make them go away if a client is including this  *  */
specifier|extern
specifier|const
expr|struct
name|res_sym
name|__p_key_syms
index|[]
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|res_sym
name|__p_cert_syms
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|res_sym
name|__p_class_syms
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|res_sym
name|__p_type_syms
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|res_sym
name|__p_rcode_syms
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SHARED_LIBBIND */
end_comment

begin_define
define|#
directive|define
name|b64_ntop
value|__b64_ntop
end_define

begin_define
define|#
directive|define
name|b64_pton
value|__b64_pton
end_define

begin_define
define|#
directive|define
name|dn_comp
value|__dn_comp
end_define

begin_define
define|#
directive|define
name|dn_count_labels
value|__dn_count_labels
end_define

begin_define
define|#
directive|define
name|dn_expand
value|__dn_expand
end_define

begin_define
define|#
directive|define
name|dn_skipname
value|__dn_skipname
end_define

begin_define
define|#
directive|define
name|fp_resstat
value|__fp_resstat
end_define

begin_define
define|#
directive|define
name|loc_aton
value|__loc_aton
end_define

begin_define
define|#
directive|define
name|loc_ntoa
value|__loc_ntoa
end_define

begin_define
define|#
directive|define
name|p_cdname
value|__p_cdname
end_define

begin_define
define|#
directive|define
name|p_cdnname
value|__p_cdnname
end_define

begin_define
define|#
directive|define
name|p_class
value|__p_class
end_define

begin_define
define|#
directive|define
name|p_fqname
value|__p_fqname
end_define

begin_define
define|#
directive|define
name|p_fqnname
value|__p_fqnname
end_define

begin_define
define|#
directive|define
name|p_option
value|__p_option
end_define

begin_define
define|#
directive|define
name|p_secstodate
value|__p_secstodate
end_define

begin_define
define|#
directive|define
name|p_section
value|__p_section
end_define

begin_define
define|#
directive|define
name|p_time
value|__p_time
end_define

begin_define
define|#
directive|define
name|p_type
value|__p_type
end_define

begin_define
define|#
directive|define
name|p_rcode
value|__p_rcode
end_define

begin_define
define|#
directive|define
name|p_sockun
value|__p_sockun
end_define

begin_define
define|#
directive|define
name|putlong
value|__putlong
end_define

begin_define
define|#
directive|define
name|putshort
value|__putshort
end_define

begin_define
define|#
directive|define
name|res_dnok
value|__res_dnok
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|res_findzonecut
value|__res_findzonecut
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|res_findzonecut2
value|__res_findzonecut2
end_define

begin_define
define|#
directive|define
name|res_hnok
value|__res_hnok
end_define

begin_define
define|#
directive|define
name|res_hostalias
value|__res_hostalias
end_define

begin_define
define|#
directive|define
name|res_mailok
value|__res_mailok
end_define

begin_define
define|#
directive|define
name|res_nameinquery
value|__res_nameinquery
end_define

begin_define
define|#
directive|define
name|res_nclose
value|__res_nclose
end_define

begin_define
define|#
directive|define
name|res_ninit
value|__res_ninit
end_define

begin_define
define|#
directive|define
name|res_nmkquery
value|__res_nmkquery
end_define

begin_define
define|#
directive|define
name|res_pquery
value|__res_pquery
end_define

begin_define
define|#
directive|define
name|res_nquery
value|__res_nquery
end_define

begin_define
define|#
directive|define
name|res_nquerydomain
value|__res_nquerydomain
end_define

begin_define
define|#
directive|define
name|res_nsearch
value|__res_nsearch
end_define

begin_define
define|#
directive|define
name|res_nsend
value|__res_nsend
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|res_nsendsigned
value|__res_nsendsigned
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|res_nisourserver
value|__res_nisourserver
end_define

begin_define
define|#
directive|define
name|res_ownok
value|__res_ownok
end_define

begin_define
define|#
directive|define
name|res_queriesmatch
value|__res_queriesmatch
end_define

begin_define
define|#
directive|define
name|res_randomid
value|__res_randomid
end_define

begin_define
define|#
directive|define
name|sym_ntop
value|__sym_ntop
end_define

begin_define
define|#
directive|define
name|sym_ntos
value|__sym_ntos
end_define

begin_define
define|#
directive|define
name|sym_ston
value|__sym_ston
end_define

begin_define
define|#
directive|define
name|res_nopt
value|__res_nopt
end_define

begin_define
define|#
directive|define
name|res_ndestroy
value|__res_ndestroy
end_define

begin_define
define|#
directive|define
name|res_nametoclass
value|__res_nametoclass
end_define

begin_define
define|#
directive|define
name|res_nametotype
value|__res_nametotype
end_define

begin_define
define|#
directive|define
name|res_setservers
value|__res_setservers
end_define

begin_define
define|#
directive|define
name|res_getservers
value|__res_getservers
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|res_buildprotolist
value|__res_buildprotolist
end_define

begin_define
define|#
directive|define
name|res_destroyprotolist
value|__res_destroyprotolist
end_define

begin_define
define|#
directive|define
name|res_destroyservicelist
value|__res_destroyservicelist
end_define

begin_define
define|#
directive|define
name|res_get_nibblesuffix
value|__res_get_nibblesuffix
end_define

begin_define
define|#
directive|define
name|res_get_nibblesuffix2
value|__res_get_nibblesuffix2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|res_ourserver_p
value|__res_ourserver_p
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|res_protocolname
value|__res_protocolname
end_define

begin_define
define|#
directive|define
name|res_protocolnumber
value|__res_protocolnumber
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|res_send_setqhook
value|__res_send_setqhook
end_define

begin_define
define|#
directive|define
name|res_send_setrhook
value|__res_send_setrhook
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|res_servicename
value|__res_servicename
end_define

begin_define
define|#
directive|define
name|res_servicenumber
value|__res_servicenumber
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__BEGIN_DECLS
name|int
name|res_hnok
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_ownok
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_mailok
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_dnok
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sym_ston
parameter_list|(
specifier|const
name|struct
name|res_sym
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|sym_ntos
parameter_list|(
specifier|const
name|struct
name|res_sym
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
specifier|const
name|char
modifier|*
name|sym_ntop
parameter_list|(
specifier|const
name|struct
name|res_sym
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
name|int
name|b64_ntop
parameter_list|(
name|u_char
specifier|const
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|b64_pton
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|loc_aton
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|loc_ntoa
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_skipname
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|putlong
parameter_list|(
name|u_int32_t
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|putshort
parameter_list|(
name|u_int16_t
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|__ultrix__
end_ifndef

begin_function_decl
name|u_int16_t
name|_getshort
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|_getlong
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|const
name|char
modifier|*
name|p_class
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|p_time
parameter_list|(
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|p_type
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|p_rcode
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|p_sockun
parameter_list|(
name|union
name|res_sockaddr_union
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|u_char
modifier|*
name|p_cdnname
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|u_char
modifier|*
name|p_cdname
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|u_char
modifier|*
name|p_fqnname
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|u_char
modifier|*
name|p_fqname
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|p_option
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|p_secstodate
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_count_labels
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_comp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_expand
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
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
name|u_int
name|res_randomid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_nameinquery
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_queriesmatch
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|p_section
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Things involving a resolver context. */
end_comment

begin_function_decl
name|int
name|res_ninit
parameter_list|(
name|res_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_nisourserver
parameter_list|(
specifier|const
name|res_state
parameter_list|,
specifier|const
name|struct
name|sockaddr_in
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fp_resstat
parameter_list|(
specifier|const
name|res_state
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|res_pquery
parameter_list|(
specifier|const
name|res_state
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|res_hostalias
parameter_list|(
specifier|const
name|res_state
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_nquery
parameter_list|(
name|res_state
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_nsearch
parameter_list|(
name|res_state
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_nquerydomain
parameter_list|(
name|res_state
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_nmkquery
parameter_list|(
name|res_state
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_nsend
parameter_list|(
name|res_state
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|int		res_nsendsigned(res_state, const u_char *, int, 				ns_tsig_key *, u_char *, int); int		res_findzonecut(res_state, const char *, ns_class, int, 				char *, size_t, struct in_addr *, int);
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|res_findzonecut2
parameter_list|(
name|res_state
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|ns_class
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|union
name|res_sockaddr_union
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|res_nclose
parameter_list|(
name|res_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_nopt
parameter_list|(
name|res_state
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|res_send_setqhook
parameter_list|(
name|res_send_qhook
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|res_send_setrhook
parameter_list|(
name|res_send_rhook
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__res_vinit
parameter_list|(
name|res_state
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|void		res_destroyservicelist(void); const char *	res_servicename(u_int16_t, const char *); const char *	res_protocolname(int); void		res_destroyprotolist(void); void		res_buildprotolist(void); const char *	res_get_nibblesuffix(res_state); const char *	res_get_nibblesuffix2(res_state);
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|res_ndestroy
parameter_list|(
name|res_state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|res_nametoclass
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|res_nametotype
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|res_setservers
parameter_list|(
name|res_state
parameter_list|,
specifier|const
name|union
name|res_sockaddr_union
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_getservers
parameter_list|(
name|res_state
parameter_list|,
name|union
name|res_sockaddr_union
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RESOLV_H_ */
end_comment

end_unit

