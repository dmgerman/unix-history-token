begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1987, 1989  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Portions Copyright (c) 1996-1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  *	@(#)resolv.h	8.1 (Berkeley) 6/2/93  *	$Id: resolv.h,v 1.3 2000/07/17 20:54:12 mellon Exp $  */
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
name|void
name|__h_errno_set
parameter_list|(
name|struct
name|__res_state
modifier|*
name|res
parameter_list|,
name|int
name|err
parameter_list|)
function_decl|;
end_function_decl

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
name|double
modifier|*
modifier|*
name|query
parameter_list|,
name|unsigned
modifier|*
name|querylen
parameter_list|,
name|double
modifier|*
name|ans
parameter_list|,
name|unsigned
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
name|double
modifier|*
name|query
parameter_list|,
name|unsigned
name|querylen
parameter_list|,
name|double
modifier|*
name|ans
parameter_list|,
name|unsigned
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
name|_sock
decl_stmt|;
comment|/* PRIVATE: for res_send i/o */
name|u_int
name|_flags
decl_stmt|;
comment|/* PRIVATE: see below */
name|char
name|pad
index|[
literal|52
index|]
decl_stmt|;
comment|/* On an i386 this means 512b total. */
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

begin_comment
comment|/* res_findzonecut() options */
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Things involving an internal (static) resolver context. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_REENTRANT
end_ifdef

begin_define
unit|extern struct __res_state *__res_state(void);
define|#
directive|define
name|_res
value|(*__res_state())
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__BIND_NOSTATIC
end_ifndef

begin_endif
unit|extern struct __res_state _res;
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
unit|void		fp_nquery (const u_char *, int, FILE *); void		fp_query (const u_char *, FILE *); const char *	hostalias (const char *); void		p_query (const u_char *); void		res_close (void); int		res_init (void); int		res_isourserver (const struct sockaddr_in *); int		res_mkquery (int, const char *, int, int, const u_char *, 				 int, const u_char *, u_char *, int); int		res_query (const char *, int, int, u_char *, int); int		res_querydomain (const char *, const char *, int, int, 				     u_char *, int); int		res_search (const char *, int, int, u_char *, int); int		res_send (const u_char *, int, u_char *, int); int		res_sendsigned (const u_char *, int, ns_tsig_key *, 				    u_char *, int);
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
end_if

begin_comment
comment|/*  * If libbind is a shared object (well, DLL anyway)  * these externs break the linker when resolv.h is   * included by a lib client (like named)  * Make them go away if a client is including this  *  */
end_comment

begin_endif
unit|extern const struct res_sym __p_key_syms[]; extern const struct res_sym __p_cert_syms[]; extern const struct res_sym __p_class_syms[]; extern const struct res_sym __p_type_syms[]; extern const struct res_sym __p_rcode_syms[];
endif|#
directive|endif
end_endif

begin_comment
comment|/* SHARED_LIBBIND */
end_comment

begin_comment
unit|int		res_hnok (const char *); int		res_ownok (const char *); int		res_mailok (const char *); int		res_dnok (const char *); int		sym_ston (const struct res_sym *, const char *, int *); const char *	sym_ntos (const struct res_sym *, int, int *); const char *	sym_ntop (const struct res_sym *, int, int *); int		b64_ntop (u_char const *, size_t, char *, size_t); int		b64_pton (char const *, u_char *, size_t); int		loc_aton (const char *ascii, u_char *binary); const char *	loc_ntoa (const u_char *binary, char *ascii); int		dn_skipname (const u_char *, const u_char *); void		putlong (u_int32_t, u_char *); void		putshort (u_int16_t, u_char *); const char *	p_class (int); const char *	p_time (u_int32_t); const char *	p_type (int); const char *	p_rcode (int); const u_char *	p_cdnname (const u_char *, const u_char *, int, FILE *); const u_char *	p_cdname (const u_char *, const u_char *, FILE *); const u_char *	p_fqnname (const u_char *cp, const u_char *msg, 			       int, char *, int); const u_char *	p_fqname (const u_char *, const u_char *, FILE *); const char *	p_option (u_long option); char *		p_secstodate (u_long); int		dn_count_labels (const char *); int		dn_expand (const u_char *, const u_char *, const u_char *, 			       char *, int); u_int		res_randomid (void); int		res_nameinquery (const char *, int, int, 				     const u_char *, const u_char *); int		res_queriesmatch (const u_char *, const u_char *, 				      const u_char *, const u_char *); const char *	p_section (int section, int opcode);
comment|/* Things involving a resolver context. */
end_comment

begin_endif
unit|int		res_ninit (res_state); int		res_nisourserver (const res_state, 				      const struct sockaddr_in *); void		fp_resstat (const res_state, FILE *); void		res_npquery (const res_state, const u_char *, int, FILE *); const char *	res_hostalias (const res_state, const char *, 				   char *, size_t); int		res_nquery (res_state, 				const char *, int, int, u_char *, int); int		res_nsearch (res_state, const char *, int, 				 int, u_char *, int); int		res_nquerydomain (res_state, 				      const char *, const char *, int, int, 				      u_char *, int); int		res_nmkquery (res_state, 				  int, const char *, int, int, const u_char *, 				  int, const u_char *, u_char *, int); int		res_nsend (res_state, const u_char *, int, u_char *, int); int		res_nsendsigned (res_state, const u_char *, int, 				     ns_tsig_key *, u_char *, int); int		res_findzonecut (res_state, const char *, ns_class, int, 				     char *, size_t, struct in_addr *, int); void		res_nclose (res_state);
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RESOLV_H_ */
end_comment

end_unit

