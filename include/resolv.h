begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1987, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Portions Copyright (c) 1996 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  *	@(#)resolv.h	8.1 (Berkeley) 6/2/93  *	From Id: resolv.h,v 8.12 1998/04/28 19:36:46 halley Exp $  * $FreeBSD$  */
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

begin_comment
comment|/*  * Revision information.  This is the release date in YYYYMMDD format.  * It can change every day so the right thing to do with it is use it  * in preprocessor commands such as "#if (__RES> 19931104)".  Do not  * compare for equality; rather, use it to determine whether your resolver  * is new enough to contain a certain feature.  */
end_comment

begin_define
define|#
directive|define
name|__RES
value|19960801
end_define

begin_comment
comment|/*  * Resolver configuration file.  * Normally not present, but may contain the address of the  * inital name server(s) to query and the domain search list.  */
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

begin_struct
struct|struct
name|__res_state
block|{
name|int
name|retrans
decl_stmt|;
comment|/* retransmition time interval */
name|int
name|retry
decl_stmt|;
comment|/* number of times to retransmit */
name|u_long
name|options
decl_stmt|;
comment|/* option flags - see below. */
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
name|u_long
name|pfcode
decl_stmt|;
comment|/* RES_PRF_ flags - see below. */
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
name|char
name|pad
index|[
literal|72
index|]
decl_stmt|;
comment|/* on an i386 this means 512b total */
block|}
struct|;
end_struct

begin_comment
comment|/* for INET6 */
end_comment

begin_comment
comment|/*  * replacement of __res_state, separated to keep binary compatibility.  */
end_comment

begin_struct
struct|struct
name|__res_state_ext
block|{
name|struct
name|sockaddr_storage
name|nsaddr_list
index|[
name|MAXNS
index|]
decl_stmt|;
struct|struct
block|{
name|int
name|af
decl_stmt|;
comment|/* address family for addr, mask */
union|union
block|{
name|struct
name|in_addr
name|ina
decl_stmt|;
name|struct
name|in6_addr
name|in6a
decl_stmt|;
block|}
name|addr
union|,
name|mask
union|;
block|}
name|sort_list
index|[
name|MAXRESOLVSORT
index|]
struct|;
block|}
struct|;
end_struct

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
name|RES_NOTLDQUERY
value|0x00004000
end_define

begin_comment
comment|/* Don't query TLD names */
end_comment

begin_comment
comment|/* KAME extensions: use higher bit to avoid conflict with ISC use */
end_comment

begin_define
define|#
directive|define
name|RES_USE_EDNS0
value|0x40000000
end_define

begin_comment
comment|/* use EDNS0 */
end_comment

begin_define
define|#
directive|define
name|RES_DEFAULT
value|(RES_RECURSE | RES_DEFNAMES | RES_DNSRCH)
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

begin_comment
comment|/*			0x00008000	*/
end_comment

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
name|sockaddr_in
modifier|*
specifier|const
modifier|*
name|ns
parameter_list|,
specifier|const
name|u_char
modifier|*
modifier|*
name|query
parameter_list|,
name|int
modifier|*
name|querylen
parameter_list|,
name|u_char
modifier|*
name|ans
parameter_list|,
name|int
name|anssiz
parameter_list|,
name|int
modifier|*
name|resplen
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
name|sockaddr_in
modifier|*
name|ns
parameter_list|,
specifier|const
name|u_char
modifier|*
name|query
parameter_list|,
name|int
name|querylen
parameter_list|,
name|u_char
modifier|*
name|ans
parameter_list|,
name|int
name|anssiz
parameter_list|,
name|int
modifier|*
name|resplen
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
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Its symbolic name, like "MX" */
name|char
modifier|*
name|humanname
decl_stmt|;
comment|/* Its fun name, like "mail exchanger" */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|__res_state
name|_res
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for INET6 */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|__res_state_ext
name|_res_ext
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

begin_comment
comment|/* Private routines shared between libc/net, named, nslookup and others. */
end_comment

begin_define
define|#
directive|define
name|res_hnok
value|__res_hnok
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
name|res_mailok
value|__res_mailok
end_define

begin_define
define|#
directive|define
name|res_dnok
value|__res_dnok
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
name|sym_ntos
value|__sym_ntos
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
name|loc_ntoa
value|__loc_ntoa
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
name|fp_resstat
value|__fp_resstat
end_define

begin_define
define|#
directive|define
name|p_query
value|__p_query
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
name|fp_query
value|__fp_query
end_define

begin_define
define|#
directive|define
name|fp_nquery
value|__fp_nquery
end_define

begin_define
define|#
directive|define
name|hostalias
value|__hostalias
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
name|p_class
value|__p_class
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
name|p_query
value|__p_query
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
name|p_section
value|__p_section
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
name|p_fqnname
value|__p_fqnname
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
name|dn_count_labels
value|__dn_count_labels
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
name|dn_expand
value|__dn_expand
end_define

begin_define
define|#
directive|define
name|res_init
value|__res_init
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
name|res_query
value|__res_query
end_define

begin_define
define|#
directive|define
name|res_search
value|__res_search
end_define

begin_define
define|#
directive|define
name|res_querydomain
value|__res_querydomain
end_define

begin_define
define|#
directive|define
name|res_mkquery
value|__res_mkquery
end_define

begin_define
define|#
directive|define
name|res_send
value|__res_send
end_define

begin_define
define|#
directive|define
name|res_isourserver
value|__res_isourserver
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
name|res_queriesmatch
value|__res_queriesmatch
end_define

begin_define
define|#
directive|define
name|res_close
value|__res_close
end_define

begin_define
define|#
directive|define
name|res_opt
value|__res_opt
end_define

begin_define
define|#
directive|define
name|res_mkupdate
value|__res_mkupdate
end_define

begin_define
define|#
directive|define
name|res_mkupdrec
value|__res_mkupdrec
end_define

begin_define
define|#
directive|define
name|res_freeupdrec
value|__res_freeupdrec
end_define

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
name|fp_resstat
parameter_list|(
name|struct
name|__res_state
modifier|*
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
name|int
name|res_init
parameter_list|(
name|void
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
name|void
name|res_close
parameter_list|(
name|void
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
comment|/* XXX The following depend on the ns_updrec typedef in arpa/nameser.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_ARPA_NAMESER_H_
end_ifdef

begin_function_decl
name|int
name|res_update
parameter_list|(
name|ns_updrec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_mkupdate
parameter_list|(
name|ns_updrec
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
name|ns_updrec
modifier|*
name|res_mkupdrec
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|res_freeupdrec
parameter_list|(
name|ns_updrec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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

