begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1987, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  *  *	@(#)resolv.h	8.1 (Berkeley) 6/2/93  *	From Id: resolv.h,v 4.9.1.2 1993/05/17 09:59:01 vixie Exp  *	$Id: resolv.h,v 1.2 1994/09/25 02:11:32 pst Exp $  */
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
file|<stdio.h>
end_include

begin_comment
comment|/*  * revision information.  this is the release date in YYYYMMDD format.  * it can change every day so the right thing to do with it is use it  * in preprocessor commands such as "#if (__RES> 19931104)".  do not  * compare for equality; rather, use it to determine whether your resolver  * is new enough to contain a certain feature.  */
end_comment

begin_define
define|#
directive|define
name|__RES
value|19940415
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
comment|/* current packet id */
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
name|MAXDNAME
index|]
decl_stmt|;
comment|/* default domain */
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
comment|/* authoritative answers only */
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
comment|/* query primary server only */
end_comment

begin_define
define|#
directive|define
name|RES_IGNTC
value|0x00000020
end_define

begin_comment
comment|/* ignore trucation errors */
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

begin_comment
comment|/*			0x00000002	*/
end_comment

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

begin_comment
comment|/* hooks are still experimental as of 4.9.2 */
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
argument_list|(
argument|*res_send_qhook
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
specifier|const
operator|*
name|ns
operator|,
specifier|const
name|u_char
operator|*
operator|*
name|query
operator|,
name|int
operator|*
name|querylen
operator|,
name|u_char
operator|*
name|ans
operator|,
name|int
name|anssiz
operator|,
name|int
operator|*
name|resplen
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|res_sendhookact
argument_list|(
argument|*res_send_rhook
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|sockaddr_in
operator|*
name|ns
operator|,
specifier|const
name|u_char
operator|*
name|query
operator|,
name|int
name|querylen
operator|,
name|u_char
operator|*
name|ans
operator|,
name|int
name|anssiz
operator|,
name|int
operator|*
name|resplen
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|__res_state
name|_res
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Private routines shared between libc/net, named, nslookup and others. */
end_comment

begin_define
define|#
directive|define
name|dn_skipname
value|__dn_skipname
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
name|p_cdnname
value|__p_cdnname
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
name|p_fqname
value|__p_fqname
end_define

begin_define
define|#
directive|define
name|p_rr
value|__p_rr
end_define

begin_define
define|#
directive|define
name|p_option
value|__p_option
end_define

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|__dn_skipname
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__fp_resstat
name|__P
argument_list|(
operator|(
expr|struct
name|__res_state
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__fp_query
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__fp_nquery
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|__hostalias
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__putlong
name|__P
argument_list|(
operator|(
name|u_int32_t
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__putshort
name|__P
argument_list|(
operator|(
name|u_int16_t
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|__p_time
name|__P
argument_list|(
operator|(
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__p_query
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|u_char
modifier|*
name|__p_cdnname
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|u_char
modifier|*
name|__p_cdname
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|u_char
modifier|*
name|__p_fqname
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|u_char
modifier|*
name|__p_rr
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|__p_type
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|__p_class
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|__p_option
name|__P
argument_list|(
operator|(
name|u_long
name|option
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dn_comp
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|int
operator|,
name|u_char
operator|*
operator|*
operator|,
name|u_char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dn_expand
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_query
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_search
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_querydomain
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_mkquery
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|int
operator|,
specifier|const
name|u_char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|res_send
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
operator|*
operator|,
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

