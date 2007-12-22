begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)globals.h	8.1 (Berkeley) 6/6/93  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<protocols/timed.h>
end_include

begin_define
define|#
directive|define
name|SECHR
value|(60*60)
end_define

begin_define
define|#
directive|define
name|SECDAY
value|(24*SECHR)
end_define

begin_decl_stmt
specifier|extern
name|int
name|sock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Best expected round trip for a measurement.  * This is essentially the number of milliseconds per CPU tick (CLK_TCK?).  * All delays shorter than this are usually reported as 0.  */
end_comment

begin_define
define|#
directive|define
name|MIN_ROUND
value|((1000-1)/CLK_TCK)
end_define

begin_define
define|#
directive|define
name|SAMPLEINTVL
value|240
end_define

begin_comment
comment|/* synch() freq for master in sec */
end_comment

begin_define
define|#
directive|define
name|MAXADJ
value|20
end_define

begin_comment
comment|/* max adjtime() correction in sec */
end_comment

begin_define
define|#
directive|define
name|MAX_TRIM
value|3000000
end_define

begin_comment
comment|/* max drift in nsec/sec, 0.3% */
end_comment

begin_define
define|#
directive|define
name|BIG_ADJ
value|(MAX_TRIM/1000*SAMPLEINTVL*2)
end_define

begin_comment
comment|/* max good adj */
end_comment

begin_define
define|#
directive|define
name|MINTOUT
value|360
end_define

begin_comment
comment|/* election delays, 6-15 minutes */
end_comment

begin_define
define|#
directive|define
name|MAXTOUT
value|900
end_define

begin_define
define|#
directive|define
name|BAD_STATUS
value|(-1)
end_define

begin_define
define|#
directive|define
name|GOOD
value|1
end_define

begin_define
define|#
directive|define
name|UNREACHABLE
value|2
end_define

begin_define
define|#
directive|define
name|NONSTDTIME
value|3
end_define

begin_define
define|#
directive|define
name|HOSTDOWN
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|OFF
value|0
end_define

begin_define
define|#
directive|define
name|ON
value|1
end_define

begin_define
define|#
directive|define
name|MAX_HOPCNT
value|10
end_define

begin_comment
comment|/* max value for tsp_hpcnt */
end_comment

begin_define
define|#
directive|define
name|LOSTHOST
value|3
end_define

begin_comment
comment|/* forget after this many failures */
end_comment

begin_define
define|#
directive|define
name|VALID_RANGE
value|(MAXADJ*1000)
end_define

begin_comment
comment|/* good times in milliseconds */
end_comment

begin_define
define|#
directive|define
name|GOOD_RANGE
value|(MIN_ROUND*2)
end_define

begin_define
define|#
directive|define
name|VGOOD_RANGE
value|(MIN_ROUND-1)
end_define

begin_comment
comment|/*  * Global and per-network states.  */
end_comment

begin_define
define|#
directive|define
name|NOMASTER
value|0
end_define

begin_comment
comment|/* no good master */
end_comment

begin_define
define|#
directive|define
name|SLAVE
value|1
end_define

begin_define
define|#
directive|define
name|MASTER
value|2
end_define

begin_define
define|#
directive|define
name|IGNORE
value|4
end_define

begin_define
define|#
directive|define
name|ALL
value|(SLAVE|MASTER|IGNORE)
end_define

begin_define
define|#
directive|define
name|SUBMASTER
value|(SLAVE|MASTER)
end_define

begin_define
define|#
directive|define
name|NHOSTS
value|1013
end_define

begin_comment
comment|/* max of hosts controlled by timed 					 * This must be a prime number. 					 */
end_comment

begin_struct
struct|struct
name|hosttbl
block|{
name|struct
name|hosttbl
modifier|*
name|h_bak
decl_stmt|;
comment|/* hash chain */
name|struct
name|hosttbl
modifier|*
name|h_fwd
decl_stmt|;
name|struct
name|hosttbl
modifier|*
name|l_bak
decl_stmt|;
comment|/* "sequential" list */
name|struct
name|hosttbl
modifier|*
name|l_fwd
decl_stmt|;
name|struct
name|netinfo
modifier|*
name|ntp
decl_stmt|;
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
name|char
name|name
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
name|u_char
name|head
decl_stmt|;
comment|/* 1=head of hash chain */
name|u_char
name|good
decl_stmt|;
comment|/* 0=trusted host, for averaging */
name|u_char
name|noanswer
decl_stmt|;
comment|/* count of failures to answer */
name|u_char
name|need_set
decl_stmt|;
comment|/* need a SETTIME */
name|u_short
name|seq
decl_stmt|;
name|long
name|delta
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* closed hash table with internal chaining */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|hosttbl
name|hosttbl
index|[
name|NHOSTS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|self
value|hosttbl[0]
end_define

begin_define
define|#
directive|define
name|hostname
value|(self.name)
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
name|struct
name|in_addr
name|net
decl_stmt|;
name|u_int32_t
name|mask
decl_stmt|;
name|struct
name|in_addr
name|my_addr
decl_stmt|;
name|struct
name|sockaddr_in
name|dest_addr
decl_stmt|;
comment|/* broadcast addr or point-point */
name|long
name|status
decl_stmt|;
name|struct
name|timeval
name|slvwait
decl_stmt|;
comment|/* delay before sending our time */
name|int
name|quit_count
decl_stmt|;
comment|/* recent QUITs */
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_define
define|#
directive|define
name|tvtomsround
parameter_list|(
name|tv
parameter_list|)
value|((tv).tv_sec*1000 + ((tv).tv_usec + 500)/1000)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|netinfo
modifier|*
name|nettab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|trace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in
name|from
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|from_when
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when the last msg arrived */
end_comment

begin_decl_stmt
specifier|extern
name|u_short
name|sequence
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TSP message sequence number */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|netinfo
modifier|*
name|fromnet
decl_stmt|,
modifier|*
name|slavenet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|delay1
decl_stmt|,
name|delay2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nslavenets
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nets were I could be a slave */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nmasternets
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nets were I could be a master */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nignorednets
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ignored nets */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nnets
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nets I am connected to */
end_comment

begin_define
define|#
directive|define
name|trace_msg
parameter_list|(
name|msg
parameter_list|)
value|{if (trace) fprintf(fd, msg);}
end_define

begin_define
define|#
directive|define
name|trace_sendto_err
parameter_list|(
name|addr
parameter_list|)
value|{					\ 	int st_errno = errno;						\ 	syslog(LOG_ERR, "%s %d: sendto %s: %m",				\ 		__FILE__, __LINE__, inet_ntoa(addr));			\ 	if (trace)							\ 		fprintf(fd, "%s %d: sendto %s: %d", __FILE__, __LINE__,	\ 			inet_ntoa(addr), st_errno);			\ }
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a<b ? b : a)
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a>b ? b : a)
end_define

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|x
parameter_list|)
value|(x>=0 ? x : -(x))
end_define

end_unit

