begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	ns.h	4.3	86/06/04	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California  *	All Rights Reserved  */
end_comment

begin_comment
comment|/*  * Global definitions and variables for the name server.  */
end_comment

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_comment
comment|/* MAXRETRY * RETRYTIME * #ns should be less than 1 minute or so */
end_comment

begin_comment
comment|/* 3 * 8 * 3 = 72 seconds for 3 root domain servers */
end_comment

begin_define
define|#
directive|define
name|MAXNS
value|10
end_define

begin_comment
comment|/* max number of NS's to try */
end_comment

begin_define
define|#
directive|define
name|RETRYTIME
value|8
end_define

begin_comment
comment|/* time between retries */
end_comment

begin_define
define|#
directive|define
name|MAXRETRY
value|3
end_define

begin_comment
comment|/* max number of retries per addr */
end_comment

begin_define
define|#
directive|define
name|MAXCNAMES
value|8
end_define

begin_comment
comment|/* max # of CNAMES tried per addr */
end_comment

begin_define
define|#
directive|define
name|MAXZONES
value|32
end_define

begin_struct
struct|struct
name|zoneinfo
block|{
name|int
name|z_type
decl_stmt|;
comment|/* type of zone */
name|char
modifier|*
name|z_origin
decl_stmt|;
comment|/* root domain name of zone */
name|time_t
name|z_time
decl_stmt|;
comment|/* time left before refresh */
name|u_long
name|z_refresh
decl_stmt|;
comment|/* refresh interval */
name|u_long
name|z_retry
decl_stmt|;
comment|/* refresh retry interval */
name|u_long
name|z_expire
decl_stmt|;
comment|/* expiriation time for cached info */
name|u_long
name|z_minimum
decl_stmt|;
comment|/* minimum TTL value */
name|u_long
name|z_serial
decl_stmt|;
comment|/* changes if zone modified */
name|char
modifier|*
name|z_source
decl_stmt|;
comment|/* source location of data */
name|int
name|z_addrcnt
decl_stmt|;
comment|/* address count */
name|struct
name|in_addr
name|z_addr
index|[
name|MAXNS
index|]
decl_stmt|;
comment|/* list of master servers for zone */
block|}
struct|;
end_struct

begin_comment
comment|/* zone types (z_type) */
end_comment

begin_define
define|#
directive|define
name|Z_PRIMARY
value|1
end_define

begin_define
define|#
directive|define
name|Z_SECONDARY
value|2
end_define

begin_define
define|#
directive|define
name|Z_CACHE
value|3
end_define

begin_define
define|#
directive|define
name|Z_DOMAIN
value|4
end_define

begin_comment
comment|/* Flags to ns_req() */
end_comment

begin_define
define|#
directive|define
name|ISTCP
value|01
end_define

begin_define
define|#
directive|define
name|ISLOCAL
value|02
end_define

begin_comment
comment|/*  * Structure for recording info on forwarded queries.  */
end_comment

begin_struct
struct|struct
name|qinfo
block|{
name|u_short
name|q_id
decl_stmt|;
comment|/* id of query */
name|u_short
name|q_nsid
decl_stmt|;
comment|/* id of forwarded query */
name|struct
name|sockaddr_in
name|q_from
decl_stmt|;
comment|/* requestor's address */
name|char
modifier|*
name|q_msg
decl_stmt|;
comment|/* the message */
name|int
name|q_msglen
decl_stmt|;
comment|/* len of message */
name|int
name|q_naddr
decl_stmt|;
comment|/* number of addr's in q_addr */
name|int
name|q_curaddr
decl_stmt|;
comment|/* last addr sent to */
name|time_t
name|q_time
decl_stmt|;
comment|/* time to retry */
name|struct
name|qinfo
modifier|*
name|q_next
decl_stmt|;
comment|/* rexmit list (sorted by time) */
name|struct
name|qinfo
modifier|*
name|q_link
decl_stmt|;
comment|/* storage list (random order) */
name|struct
name|sockaddr_in
name|q_addr
index|[
name|MAXNS
index|]
decl_stmt|;
comment|/* addresses of NS's */
name|int
name|q_nretry
index|[
name|MAXNS
index|]
decl_stmt|;
comment|/* # of times addr retried */
name|int
name|q_cname
decl_stmt|;
comment|/* # of cnames found */
name|char
modifier|*
name|q_cmsg
decl_stmt|;
comment|/* the cname message */
name|int
name|q_cmsglen
decl_stmt|;
comment|/* len of cname message */
name|struct
name|qstream
modifier|*
name|q_stream
decl_stmt|;
comment|/* TCP stream, null if UDP */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|QINFO_NULL
value|((struct qinfo *)0)
end_define

begin_function_decl
specifier|extern
name|struct
name|qinfo
modifier|*
name|qfindid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|qinfo
modifier|*
name|qnew
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|qinfo
modifier|*
name|retryqp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next query to retry */
end_comment

begin_struct
struct|struct
name|qstream
block|{
name|int
name|s_rfd
decl_stmt|;
comment|/* stream file descriptor */
name|int
name|s_size
decl_stmt|;
comment|/* expected amount of data to recive */
name|int
name|s_bufsize
decl_stmt|;
comment|/* amount of data recived in s_buf */
name|char
modifier|*
name|s_buf
decl_stmt|;
comment|/* buffer of recived data */
name|char
modifier|*
name|s_bufp
decl_stmt|;
comment|/* pointer into s_buf of recived data */
name|struct
name|qstream
modifier|*
name|s_next
decl_stmt|;
comment|/* next stream */
name|struct
name|sockaddr_in
name|s_from
decl_stmt|;
comment|/* address query came from */
name|u_long
name|s_time
decl_stmt|;
comment|/* time stamp of last transaction */
name|int
name|s_refcnt
decl_stmt|;
comment|/* number of outstanding queries */
name|u_short
name|s_tempsize
decl_stmt|;
comment|/* temporary for size from net */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|QSTREAM_NULL
value|((struct qstream *)0)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|qstream
modifier|*
name|streamq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stream queue */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug flag */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|ddt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug file discriptor */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|ds
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* datagram socket */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|tt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* place to store time */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|itimerval
name|ival
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maintenance interval */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|zoneinfo
name|zones
index|[
name|MAXZONES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* zone information */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nzones
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of zones in use */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_decl_stmt
specifier|extern
name|u_short
name|htons
argument_list|()
decl_stmt|,
name|ntohs
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|htonl
argument_list|()
decl_stmt|,
name|ntohl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

