begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1987 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)resolv.h	5.5 (Berkeley) 5/12/87  */
end_comment

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
name|MAXDNSRCH
value|3
end_define

begin_comment
comment|/* max # default domain levels to try */
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
value|4
end_define

begin_comment
comment|/* seconds between retries */
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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|p_cdname
argument_list|()
decl_stmt|,
modifier|*
name|p_rr
argument_list|()
decl_stmt|,
modifier|*
name|p_type
argument_list|()
decl_stmt|,
modifier|*
name|p_class
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

