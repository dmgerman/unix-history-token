begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ns.h	4.22 (Berkeley) 6/18/88  */
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
comment|/*  * Timeout time should be around 1 minute or so.  Using the  * the current simplistic backoff strategy, the sequence  * retrys after 4, 8, and 16 seconds.  With 3 servers, this  * dies out in a little more than a minute.  * (sequence RETRYBASE, 2*RETRYBASE, 4*RETRYBASE... for MAXRETRY)  */
end_comment

begin_define
define|#
directive|define
name|MAXZONES
value|128
end_define

begin_comment
comment|/* max number of zones supported */
end_comment

begin_define
define|#
directive|define
name|MINROOTS
value|2
end_define

begin_comment
comment|/* min number of root hints */
end_comment

begin_define
define|#
directive|define
name|NSMAX
value|10
end_define

begin_comment
comment|/* max number of NS's to try */
end_comment

begin_define
define|#
directive|define
name|RETRYBASE
value|4
end_define

begin_comment
comment|/* base time between retries */
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
name|MAXQUERIES
value|20
end_define

begin_comment
comment|/* max # of queries to be made */
end_comment

begin_comment
comment|/* (prevent "recursive" loops) */
end_comment

begin_define
define|#
directive|define
name|INIT_REFRESH
value|600
end_define

begin_comment
comment|/* retry time for initial secondary */
end_comment

begin_comment
comment|/* contact (10 minutes) */
end_comment

begin_define
define|#
directive|define
name|ALPHA
value|0.7
end_define

begin_comment
comment|/* How much to preserver of old response time */
end_comment

begin_define
define|#
directive|define
name|BETA
value|1.2
end_define

begin_comment
comment|/* How much to penalize response time on failure */
end_comment

begin_define
define|#
directive|define
name|GAMMA
value|0.98
end_define

begin_comment
comment|/* How much to decay unused response times */
end_comment

begin_struct
struct|struct
name|zoneinfo
block|{
name|int
name|z_type
decl_stmt|;
comment|/* type of zone */
name|int
name|z_auth
decl_stmt|;
comment|/* zone is authoritative */
name|char
modifier|*
name|z_origin
decl_stmt|;
comment|/* root domain name of zone */
name|time_t
name|z_time
decl_stmt|;
comment|/* time for next refresh */
name|time_t
name|z_lastupdate
decl_stmt|;
comment|/* time of last refresh */
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
comment|/* expiration time for cached info */
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
name|time_t
name|z_ftime
decl_stmt|;
comment|/* modification time of source file */
name|int
name|z_addrcnt
decl_stmt|;
comment|/* address count */
name|struct
name|in_addr
name|z_addr
index|[
name|NSMAX
index|]
decl_stmt|;
comment|/* list of master servers for zone */
name|int
name|z_sysloged
decl_stmt|;
comment|/* has fail to transfer been sysloged */
ifdef|#
directive|ifdef
name|ALLOW_UPDATES
name|int
name|hasChanged
decl_stmt|;
comment|/* non-zero if zone has been updated 					 * since last checkpoint 					 */
endif|#
directive|endif
endif|ALLOW_UPDATES
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
name|int
name|q_dfd
decl_stmt|;
comment|/* UDP file descriptor */
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
name|struct
name|fwdinfo
modifier|*
name|q_fwd
decl_stmt|;
comment|/* last	forwarder used */
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
struct|struct
name|qserv
block|{
name|struct
name|sockaddr_in
name|ns_addr
decl_stmt|;
comment|/* addresses of NS's */
name|struct
name|databuf
modifier|*
name|ns
decl_stmt|;
comment|/* databuf for NS record */
name|struct
name|databuf
modifier|*
name|nsdata
decl_stmt|;
comment|/* databuf for server address */
name|struct
name|timeval
name|stime
decl_stmt|;
comment|/* time first query started */
name|int
name|nretry
decl_stmt|;
comment|/* # of times addr retried */
block|}
name|q_addr
index|[
name|NSMAX
index|]
struct|;
comment|/* addresses of NS's */
name|struct
name|databuf
modifier|*
name|q_usedns
index|[
name|NSMAX
index|]
decl_stmt|;
comment|/* databuf for NS that we've tried */
name|int
name|q_nusedns
decl_stmt|;
name|int
name|q_cname
decl_stmt|;
comment|/* # of cnames found */
name|int
name|q_nqueries
decl_stmt|;
comment|/* # of queries required */
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
name|int
name|q_system
decl_stmt|;
comment|/* boolean, system query */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|Q_NEXTADDR
parameter_list|(
name|qp
parameter_list|,
name|n
parameter_list|)
define|\
value|(((qp)->q_fwd == (struct fwdinfo *)0) ? \&(qp)->q_addr[n].ns_addr :&(qp)->q_fwd->fwdaddr)
end_define

begin_define
define|#
directive|define
name|PRIMING_CACHE
value|42
end_define

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

begin_comment
comment|/*  * Return codes from ns_forw:  */
end_comment

begin_define
define|#
directive|define
name|FW_OK
value|0
end_define

begin_define
define|#
directive|define
name|FW_DUP
value|1
end_define

begin_define
define|#
directive|define
name|FW_NOSERVER
value|2
end_define

begin_define
define|#
directive|define
name|FW_SERVFAIL
value|3
end_define

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

begin_struct
struct|struct
name|qdatagram
block|{
name|int
name|dq_dfd
decl_stmt|;
comment|/* datagram file descriptor */
name|struct
name|qdatagram
modifier|*
name|dq_next
decl_stmt|;
comment|/* next datagram */
name|struct
name|in_addr
name|dq_addr
decl_stmt|;
comment|/* address of interface */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|QDATAGRAM_NULL
value|((struct qdatagram *)0)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|qdatagram
modifier|*
name|datagramq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* datagram queue */
end_comment

begin_struct
struct|struct
name|netinfo
block|{
name|struct
name|netinfo
modifier|*
name|next
decl_stmt|;
name|u_long
name|net
decl_stmt|;
name|u_long
name|mask
decl_stmt|;
name|struct
name|in_addr
name|my_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fwdinfo
block|{
name|struct
name|fwdinfo
modifier|*
name|next
decl_stmt|;
name|struct
name|sockaddr_in
name|fwdaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nets
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|long
name|net
decl_stmt|;
name|struct
name|nets
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  Statistics Defines  */
end_comment

begin_struct
struct|struct
name|stats
block|{
name|unsigned
name|long
name|cnt
decl_stmt|;
name|char
modifier|*
name|description
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* gross count of UDP packets in and out */
end_comment

begin_define
define|#
directive|define
name|S_INPKTS
value|0
end_define

begin_define
define|#
directive|define
name|S_OUTPKTS
value|1
end_define

begin_comment
comment|/* gross count of queries and inverse queries received */
end_comment

begin_define
define|#
directive|define
name|S_QUERIES
value|2
end_define

begin_define
define|#
directive|define
name|S_IQUERIES
value|3
end_define

begin_define
define|#
directive|define
name|S_DUPQUERIES
value|4
end_define

begin_define
define|#
directive|define
name|S_RESPONSES
value|5
end_define

begin_define
define|#
directive|define
name|S_DUPRESP
value|6
end_define

begin_define
define|#
directive|define
name|S_RESPOK
value|7
end_define

begin_define
define|#
directive|define
name|S_RESPFAIL
value|8
end_define

begin_define
define|#
directive|define
name|S_RESPFORMERR
value|9
end_define

begin_define
define|#
directive|define
name|S_SYSQUERIES
value|10
end_define

begin_define
define|#
directive|define
name|S_PRIMECACHE
value|11
end_define

begin_define
define|#
directive|define
name|S_CHECKNS
value|12
end_define

begin_define
define|#
directive|define
name|S_BADRESPONSES
value|13
end_define

begin_define
define|#
directive|define
name|S_MARTIANS
value|14
end_define

begin_define
define|#
directive|define
name|S_NSTATS
value|15
end_define

begin_comment
comment|/* Careful! */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STATS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|stats
name|stats
index|[
name|S_NSTATS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|typestats
index|[
name|T_ANY
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|qdatagram
modifier|*
name|dqp
decl_stmt|;
end_decl_stmt

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

