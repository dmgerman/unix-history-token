begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	from ns.h	4.33 (Berkeley) 8/23/90  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * ++Copyright++ 1986  * -  * Copyright (c) 1986  *    The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_comment
comment|/*  * Global definitions for the name server.  */
end_comment

begin_comment
comment|/*  * Effort has been expended here to make all structure members 32 bits or  * larger land on 32-bit boundaries; smaller structure members have been  * deliberately shuffled and smaller integer sizes chosen where possible  * to make sure this happens.  This is all meant to avoid structure member  * padding which can cost a _lot_ of memory when you have hundreds of  * thousands of entries in your cache.  */
end_comment

begin_comment
comment|/*  * Timeout time should be around 1 minute or so.  Using the  * the current simplistic backoff strategy, the sequence  * retrys after 4, 8, and 16 seconds.  With 3 servers, this  * dies out in a little more than a minute.  * (sequence RETRYBASE, 2*RETRYBASE, 4*RETRYBASE... for MAXRETRY)  */
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
value|16
end_define

begin_comment
comment|/* max number of NS addrs to try ([0..255]) */
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
name|MAXCLASS
value|255
end_define

begin_comment
comment|/* XXX - may belong elsewhere */
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

begin_define
define|#
directive|define
name|MAXQSERIAL
value|4
end_define

begin_comment
comment|/* max # of outstanding QSERIAL's */
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
name|NADDRECS
value|20
end_define

begin_comment
comment|/* max addt'l rr's per resp */
end_comment

begin_define
define|#
directive|define
name|XFER_TIMER
value|120
end_define

begin_comment
comment|/* named-xfer's connect timeout */
end_comment

begin_define
define|#
directive|define
name|MAX_XFER_TIME
value|60*60*2
end_define

begin_comment
comment|/* max seconds for an xfer */
end_comment

begin_define
define|#
directive|define
name|XFER_TIME_FUDGE
value|10
end_define

begin_comment
comment|/* MAX_XFER_TIME fudge */
end_comment

begin_define
define|#
directive|define
name|MAX_XFERS_RUNNING
value|10
end_define

begin_comment
comment|/* default max value of xfers_running */
end_comment

begin_define
define|#
directive|define
name|MAX_XFERS_PER_NS
value|2
end_define

begin_comment
comment|/* max # of xfers per peer nameserver */
end_comment

begin_define
define|#
directive|define
name|XFER_BUFSIZE
value|(16*1024)
end_define

begin_comment
comment|/* arbitrary but bigger than most MTU's */
end_comment

begin_define
define|#
directive|define
name|ALPHA
value|0.7
end_define

begin_comment
comment|/* How much to preserve of old response time */
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

begin_comment
comment|/* sequence-space arithmetic */
end_comment

begin_define
define|#
directive|define
name|SEQ_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int32_t)((a)-(b))> 0)
end_define

begin_comment
comment|/* these fields are ordered to maintain word-alignment;  * be careful about changing them.  */
end_comment

begin_struct
struct|struct
name|zoneinfo
block|{
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
name|u_int32_t
name|z_refresh
decl_stmt|;
comment|/* refresh interval */
name|u_int32_t
name|z_retry
decl_stmt|;
comment|/* refresh retry interval */
name|u_int32_t
name|z_expire
decl_stmt|;
comment|/* expiration time for cached info */
name|u_int32_t
name|z_minimum
decl_stmt|;
comment|/* minimum TTL value */
name|u_int32_t
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
name|struct
name|in_addr
name|z_xaddr
decl_stmt|;
comment|/* override server for next xfer */
name|struct
name|in_addr
name|z_addr
index|[
name|NSMAX
index|]
decl_stmt|;
comment|/* list of master servers for zone */
name|u_char
name|z_addrcnt
decl_stmt|;
comment|/* number of entries in z_addr[] */
name|u_char
name|z_type
decl_stmt|;
comment|/* type of zone; see below */
name|u_int16_t
name|z_flags
decl_stmt|;
comment|/* state bits; see below */
name|pid_t
name|z_xferpid
decl_stmt|;
comment|/* xfer child pid */
name|int
name|z_class
decl_stmt|;
comment|/* class of zone */
ifdef|#
directive|ifdef
name|SECURE_ZONES
name|struct
name|netinfo
modifier|*
name|secure_nets
decl_stmt|;
comment|/* list of secure networks for zone */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BIND_NOTIFY
comment|/* XXX - this will have to move to the name when we do !SOA notify */
name|struct
name|notify
modifier|*
name|z_notifylist
decl_stmt|;
comment|/* list of servers we should notify */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|BIND_NOTIFY
end_ifdef

begin_struct
struct|struct
name|notify
block|{
name|struct
name|in_addr
name|addr
decl_stmt|;
comment|/* of server */
name|time_t
name|last
decl_stmt|;
comment|/* when they asked */
name|struct
name|notify
modifier|*
name|next
decl_stmt|;
comment|/* XXX - this will need a type field when we do !SOA notify */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* zone types (z_type) */
end_comment

begin_define
define|#
directive|define
name|Z_NIL
value|0
end_define

begin_comment
comment|/* zone slot not in use */
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
name|Z_STUB
value|4
end_define

begin_comment
comment|/* zone state bits (16 bits) */
end_comment

begin_define
define|#
directive|define
name|Z_AUTH
value|0x0001
end_define

begin_comment
comment|/* zone is authoritative */
end_comment

begin_define
define|#
directive|define
name|Z_NEED_XFER
value|0x0002
end_define

begin_comment
comment|/* waiting to do xfer */
end_comment

begin_define
define|#
directive|define
name|Z_XFER_RUNNING
value|0x0004
end_define

begin_comment
comment|/* asynch. xfer is running */
end_comment

begin_define
define|#
directive|define
name|Z_NEED_RELOAD
value|0x0008
end_define

begin_comment
comment|/* waiting to do reload */
end_comment

begin_define
define|#
directive|define
name|Z_SYSLOGGED
value|0x0010
end_define

begin_comment
comment|/* have logged timeout */
end_comment

begin_define
define|#
directive|define
name|Z_QSERIAL
value|0x0020
end_define

begin_comment
comment|/* sysquery()'ing for serial number */
end_comment

begin_define
define|#
directive|define
name|Z_FOUND
value|0x0040
end_define

begin_comment
comment|/* found in boot file when reloading */
end_comment

begin_define
define|#
directive|define
name|Z_INCLUDE
value|0x0080
end_define

begin_comment
comment|/* set if include used in file */
end_comment

begin_define
define|#
directive|define
name|Z_DB_BAD
value|0x0100
end_define

begin_comment
comment|/* errors when loading file */
end_comment

begin_define
define|#
directive|define
name|Z_TMP_FILE
value|0x0200
end_define

begin_comment
comment|/* backup file for xfer is temporary */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ALLOW_UPDATES
end_ifdef

begin_define
define|#
directive|define
name|Z_DYNAMIC
value|0x0400
end_define

begin_comment
comment|/* allow dynamic updates */
end_comment

begin_define
define|#
directive|define
name|Z_DYNADDONLY
value|0x0800
end_define

begin_comment
comment|/* dynamic mode: add new data only */
end_comment

begin_define
define|#
directive|define
name|Z_CHANGED
value|0x1000
end_define

begin_comment
comment|/* zone has changed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALLOW_UPDATES */
end_comment

begin_comment
comment|/* named_xfer exit codes */
end_comment

begin_define
define|#
directive|define
name|XFER_UPTODATE
value|0
end_define

begin_comment
comment|/* zone is up-to-date */
end_comment

begin_define
define|#
directive|define
name|XFER_SUCCESS
value|1
end_define

begin_comment
comment|/* performed transfer successfully */
end_comment

begin_define
define|#
directive|define
name|XFER_TIMEOUT
value|2
end_define

begin_comment
comment|/* no server reachable/xfer timeout */
end_comment

begin_define
define|#
directive|define
name|XFER_FAIL
value|3
end_define

begin_comment
comment|/* other failure, has been logged */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* XXX - "struct qserv" is deprecated in favor of "struct nameser" */
end_comment

begin_struct
struct|struct
name|qserv
block|{
name|struct
name|sockaddr_in
name|ns_addr
decl_stmt|;
comment|/* address of NS */
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
struct|;
end_struct

begin_comment
comment|/*  * Structure for recording info on forwarded or generated queries.  */
end_comment

begin_struct
struct|struct
name|qinfo
block|{
name|u_int16_t
name|q_id
decl_stmt|;
comment|/* id of query */
name|u_int16_t
name|q_nsid
decl_stmt|;
comment|/* id of forwarded query */
name|struct
name|sockaddr_in
name|q_from
decl_stmt|;
comment|/* requestor's address */
name|u_char
modifier|*
name|q_msg
decl_stmt|,
comment|/* the message */
modifier|*
name|q_cmsg
decl_stmt|;
comment|/* the cname message */
name|int16_t
name|q_msglen
decl_stmt|,
comment|/* len of message */
name|q_cmsglen
decl_stmt|;
comment|/* len of cname message */
name|int16_t
name|q_dfd
decl_stmt|;
comment|/* UDP file descriptor */
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
name|time_t
name|q_expire
decl_stmt|;
comment|/* time to expire */
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
name|databuf
modifier|*
name|q_usedns
index|[
name|NSMAX
index|]
decl_stmt|;
comment|/* databuf for NS that we've tried */
name|struct
name|qserv
name|q_addr
index|[
name|NSMAX
index|]
decl_stmt|;
comment|/* addresses of NS's */
ifdef|#
directive|ifdef
name|notyet
name|struct
name|nameser
modifier|*
name|q_ns
index|[
name|NSMAX
index|]
decl_stmt|;
comment|/* name servers */
endif|#
directive|endif
name|u_char
name|q_naddr
decl_stmt|;
comment|/* number of addr's in q_addr */
name|u_char
name|q_curaddr
decl_stmt|;
comment|/* last addr sent to */
name|u_char
name|q_nusedns
decl_stmt|;
comment|/* number of elements in q_usedns[] */
name|u_int8_t
name|q_flags
decl_stmt|;
comment|/* see below */
name|int16_t
name|q_cname
decl_stmt|;
comment|/* # of cnames found */
name|int16_t
name|q_nqueries
decl_stmt|;
comment|/* # of queries required */
name|struct
name|qstream
modifier|*
name|q_stream
decl_stmt|;
comment|/* TCP stream, null if UDP */
name|struct
name|zoneinfo
modifier|*
name|q_zquery
decl_stmt|;
comment|/* Zone query is about (Q_ZSERIAL) */
ifdef|#
directive|ifdef
name|LAME_DELEGATION
name|char
name|q_domain
index|[
name|MAXDNAME
index|]
decl_stmt|;
comment|/* domain for servers we are querying */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BIND_NOTIFY
name|int
name|q_notifyzone
decl_stmt|;
comment|/* zone which needs a sysnotify() 					 * when the reply to this comes in. 					 */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* q_flags bits (8 bits) */
end_comment

begin_define
define|#
directive|define
name|Q_SYSTEM
value|0x01
end_define

begin_comment
comment|/* is a system query */
end_comment

begin_define
define|#
directive|define
name|Q_PRIMING
value|0x02
end_define

begin_comment
comment|/* generated during priming phase */
end_comment

begin_define
define|#
directive|define
name|Q_ZSERIAL
value|0x04
end_define

begin_comment
comment|/* getting zone serial for xfer test */
end_comment

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
name|RETRY_TIMEOUT
value|45
end_define

begin_define
define|#
directive|define
name|QINFO_NULL
value|((struct qinfo *)0)
end_define

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
name|u_char
modifier|*
name|s_buf
decl_stmt|;
comment|/* buffer of received data */
name|u_char
modifier|*
name|s_bufp
decl_stmt|;
comment|/* pointer into s_buf of recived data*/
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
name|u_int32_t
name|s_time
decl_stmt|;
comment|/* time stamp of last transaction */
name|int
name|s_refcnt
decl_stmt|;
comment|/* number of outstanding queries */
name|u_int16_t
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

begin_struct
struct|struct
name|qdatagram
block|{
name|int
name|dq_dfd
decl_stmt|;
comment|/* datagram file descriptor */
name|time_t
name|dq_gen
decl_stmt|;
comment|/* generation number */
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
comment|/* interface address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|QDATAGRAM_NULL
value|((struct qdatagram *)0)
end_define

begin_struct
struct|struct
name|netinfo
block|{
name|struct
name|netinfo
modifier|*
name|next
decl_stmt|;
name|u_int32_t
name|addr
decl_stmt|;
name|u_int32_t
name|mask
decl_stmt|;
name|struct
name|in_addr
name|my_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ALLOW_NETS
value|0x0001
end_define

begin_define
define|#
directive|define
name|ALLOW_HOSTS
value|0x0002
end_define

begin_define
define|#
directive|define
name|ALLOW_ALL
value|(ALLOW_NETS | ALLOW_HOSTS)
end_define

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

begin_enum
enum|enum
name|nameserStats
block|{
name|nssRcvdQ
block|,
comment|/* sent us a query */
name|nssRcvdR
block|,
comment|/* sent us an answer */
name|nssRcvdIQ
block|,
comment|/* sent us an inverse query */
name|nssRcvdNXD
block|,
comment|/* sent us a negative response */
name|nssRcvdFwdQ
block|,
comment|/* sent us a query we had to fwd */
name|nssRcvdFwdR
block|,
comment|/* sent us a response we had to fwd */
name|nssRcvdDupQ
block|,
comment|/* sent us a retry */
name|nssRcvdDupR
block|,
comment|/* sent us an extra answer */
name|nssRcvdFail
block|,
comment|/* sent us a SERVFAIL */
name|nssRcvdFErr
block|,
comment|/* sent us a FORMERR */
name|nssRcvdErr
block|,
comment|/* sent us some other error */
name|nssRcvdTCP
block|,
comment|/* sent us a query using TCP */
name|nssRcvdAXFR
block|,
comment|/* sent us an AXFR */
name|nssRcvdLDel
block|,
comment|/* sent us a lame delegation */
name|nssRcvdOpts
block|,
comment|/* sent us some IP options */
name|nssSentSysQ
block|,
comment|/* sent them a sysquery */
name|nssSentAns
block|,
comment|/* sent them an answer */
name|nssSentFwdQ
block|,
comment|/* fwdd a query to them */
name|nssSentFwdR
block|,
comment|/* fwdd a response to them */
name|nssSentDupQ
block|,
comment|/* sent them a retry */
name|nssSentFail
block|,
comment|/* sent them a SERVFAIL */
name|nssSentFErr
block|,
comment|/* sent them a FORMERR */
name|nssSendtoErr
block|,
comment|/* error in sendto */
ifdef|#
directive|ifdef
name|XSTATS
name|nssNotNsQ
block|,
comment|/* query received from remote port != ns_port */
name|nssSentNaAns
block|,
comment|/* sent them a non autoritative answer */
name|nssSentNXD
block|,
comment|/* sent them a negative response */
endif|#
directive|endif
name|nssLast
block|}
enum|;
end_enum

begin_struct
struct|struct
name|nameser
block|{
name|struct
name|in_addr
name|addr
decl_stmt|;
comment|/* key */
name|u_long
name|stats
index|[
name|nssLast
index|]
decl_stmt|;
comment|/* statistics */
ifdef|#
directive|ifdef
name|notyet
name|u_int32_t
name|rtt
decl_stmt|;
comment|/* round trip time */
comment|/* XXX - need to add more stuff from "struct qserv", and use our rtt */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* see below */
endif|#
directive|endif
name|u_int8_t
name|xfers
decl_stmt|;
comment|/* #/xfers running right now */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|NCACHE
end_ifdef

begin_define
define|#
directive|define
name|NOERROR_NODATA
value|6
end_define

begin_comment
comment|/* only used internally by the server, used for                             * -ve $ing non-existence of records. 6 is not                             * a code used as yet anyway. anant@isi.edu                             */
end_comment

begin_define
define|#
directive|define
name|NTTL
value|600
end_define

begin_comment
comment|/* ttl for negative data: 10 minutes? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*NCACHE*/
end_comment

begin_define
define|#
directive|define
name|VQEXPIRY
value|900
end_define

begin_comment
comment|/* a VQ entry expires in 15*60 = 900 seconds */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VALIDATE
end_ifdef

begin_define
define|#
directive|define
name|INVALID
value|0
end_define

begin_define
define|#
directive|define
name|VALID_NO_CACHE
value|1
end_define

begin_define
define|#
directive|define
name|VALID_CACHE
value|2
end_define

begin_define
define|#
directive|define
name|MAXNAMECACHE
value|100
end_define

begin_define
define|#
directive|define
name|MAXVQ
value|100
end_define

begin_comment
comment|/* Max number of elements in TO_Validate queue */
end_comment

begin_struct
struct|struct
name|_nameaddr
block|{
name|struct
name|in_addr
name|ns_addr
decl_stmt|;
name|char
modifier|*
name|nsname
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_nameaddr
name|NAMEADDR
typedef|;
end_typedef

begin_struct
struct|struct
name|_to_validate
block|{
name|int16_t
name|class
decl_stmt|;
comment|/* Name Class */
name|int16_t
name|type
decl_stmt|;
comment|/* RR type */
name|char
modifier|*
name|data
decl_stmt|;
comment|/* RR data */
name|char
modifier|*
name|dname
decl_stmt|;
comment|/* Name */
name|time_t
name|time
decl_stmt|;
comment|/* time at which inserted in queue */
name|struct
name|_to_validate
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_to_validate
name|TO_Validate
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*VALIDATE*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|dprintf
parameter_list|(
name|lev
parameter_list|,
name|args
parameter_list|)
value|(ddt&& (debug>= lev)&& fprintf args)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dprintf
parameter_list|(
name|lev
parameter_list|,
name|args
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INIT
end_ifdef

begin_expr_stmt
name|error
literal|"INIT already defined, check system include files"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DECL
name|error
literal|"DECL already defined, check system include files"
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MAIN_PROGRAM
end_ifdef

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|x
parameter_list|)
value|= x
end_define

begin_define
define|#
directive|define
name|DECL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DECL
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

