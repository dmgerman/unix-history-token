begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1987, 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)resolv.h	5.14 (Berkeley) %G%  */
end_comment

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

begin_struct
struct|struct
name|state
block|{
name|int
name|retrans
decl_stmt|;
comment|/* retransmition time interval */
name|int
name|retry
decl_stmt|;
comment|/* number of times to retransmit */
name|long
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
name|defdname
index|[
name|MAXDNAME
index|]
decl_stmt|;
comment|/* default domain */
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
block|}
struct|;
end_struct

begin_comment
comment|/*  * Resolver options  */
end_comment

begin_define
define|#
directive|define
name|RES_INIT
value|0x0001
end_define

begin_comment
comment|/* address initialized */
end_comment

begin_define
define|#
directive|define
name|RES_DEBUG
value|0x0002
end_define

begin_comment
comment|/* print debug messages */
end_comment

begin_define
define|#
directive|define
name|RES_AAONLY
value|0x0004
end_define

begin_comment
comment|/* authoritative answers only */
end_comment

begin_define
define|#
directive|define
name|RES_USEVC
value|0x0008
end_define

begin_comment
comment|/* use virtual circuit */
end_comment

begin_define
define|#
directive|define
name|RES_PRIMARY
value|0x0010
end_define

begin_comment
comment|/* query primary server only */
end_comment

begin_define
define|#
directive|define
name|RES_IGNTC
value|0x0020
end_define

begin_comment
comment|/* ignore trucation errors */
end_comment

begin_define
define|#
directive|define
name|RES_RECURSE
value|0x0040
end_define

begin_comment
comment|/* recursion desired */
end_comment

begin_define
define|#
directive|define
name|RES_DEFNAMES
value|0x0080
end_define

begin_comment
comment|/* use default domain name */
end_comment

begin_define
define|#
directive|define
name|RES_STAYOPEN
value|0x0100
end_define

begin_comment
comment|/* Keep TCP socket open */
end_comment

begin_define
define|#
directive|define
name|RES_DNSRCH
value|0x0200
end_define

begin_comment
comment|/* search up local domain tree */
end_comment

begin_define
define|#
directive|define
name|RES_DEFAULT
value|(RES_RECURSE | RES_DEFNAMES | RES_DNSRCH)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|state
name|_res
decl_stmt|;
end_decl_stmt

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
name|__fp_query
name|__P
argument_list|(
operator|(
name|char
operator|*
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
name|u_long
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
name|u_short
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
name|char
modifier|*
name|__p_time
name|__P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
name|int
name|dn_comp
name|__P
argument_list|(
operator|(
specifier|const
name|u_char
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
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
expr|struct
name|rrec
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
name|res_send
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|char
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

end_unit

