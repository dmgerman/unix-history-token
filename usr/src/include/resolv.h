begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	resolv.h	4.1	85/03/01	*/
end_comment

begin_comment
comment|/*  * Global defines and variables for resolver stub.  */
end_comment

begin_comment
comment|/*  * Resolver configuration file. Contains the address of the  * inital name server to query and the default domain for  * non fully qualified domain names.  */
end_comment

begin_define
define|#
directive|define
name|CONFFILE
value|"/usr/local/lib/resolv.conf"
end_define

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
name|int
name|options
decl_stmt|;
comment|/* option flags - see below. */
name|struct
name|sockaddr_in
name|nsaddr
decl_stmt|;
comment|/* address of name server */
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
value|0x001
end_define

begin_comment
comment|/* address initialized */
end_comment

begin_define
define|#
directive|define
name|RES_DEBUG
value|0x002
end_define

begin_comment
comment|/* print debug messages */
end_comment

begin_define
define|#
directive|define
name|RES_AAONLY
value|0x004
end_define

begin_comment
comment|/* authoritative answers only */
end_comment

begin_define
define|#
directive|define
name|RES_USEVC
value|0x008
end_define

begin_comment
comment|/* use virtual circuit */
end_comment

begin_define
define|#
directive|define
name|RES_PRIMARY
value|0x010
end_define

begin_comment
comment|/* query primary server only */
end_comment

begin_define
define|#
directive|define
name|RES_IGNTC
value|0x020
end_define

begin_comment
comment|/* ignore trucation errors */
end_comment

begin_define
define|#
directive|define
name|RES_RECURSE
value|0x040
end_define

begin_comment
comment|/* recursion desired */
end_comment

begin_define
define|#
directive|define
name|RES_DEFNAMES
value|0x080
end_define

begin_comment
comment|/* use default domain name */
end_comment

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

