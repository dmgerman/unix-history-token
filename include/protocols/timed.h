begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)timed.h	8.1 (Berkeley) 6/2/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROTOCOLS_TIMED_H_
end_ifndef

begin_define
define|#
directive|define
name|_PROTOCOLS_TIMED_H_
end_define

begin_comment
comment|/*  * Time Synchronization Protocol  */
end_comment

begin_define
define|#
directive|define
name|TSPVERSION
value|1
end_define

begin_define
define|#
directive|define
name|ANYADDR
value|NULL
end_define

begin_struct
struct|struct
name|tsp
block|{
name|u_char
name|tsp_type
decl_stmt|;
name|u_char
name|tsp_vers
decl_stmt|;
name|u_short
name|tsp_seq
decl_stmt|;
union|union
block|{
name|struct
name|timeval
name|tspu_time
decl_stmt|;
name|char
name|tspu_hopcnt
decl_stmt|;
block|}
name|tsp_u
union|;
name|char
name|tsp_name
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tsp_time
value|tsp_u.tspu_time
end_define

begin_define
define|#
directive|define
name|tsp_hopcnt
value|tsp_u.tspu_hopcnt
end_define

begin_comment
comment|/*  * Command types.  */
end_comment

begin_define
define|#
directive|define
name|TSP_ANY
value|0
end_define

begin_comment
comment|/* match any types */
end_comment

begin_define
define|#
directive|define
name|TSP_ADJTIME
value|1
end_define

begin_comment
comment|/* send adjtime */
end_comment

begin_define
define|#
directive|define
name|TSP_ACK
value|2
end_define

begin_comment
comment|/* generic acknowledgement */
end_comment

begin_define
define|#
directive|define
name|TSP_MASTERREQ
value|3
end_define

begin_comment
comment|/* ask for master's name */
end_comment

begin_define
define|#
directive|define
name|TSP_MASTERACK
value|4
end_define

begin_comment
comment|/* acknowledge master request */
end_comment

begin_define
define|#
directive|define
name|TSP_SETTIME
value|5
end_define

begin_comment
comment|/* send network time */
end_comment

begin_define
define|#
directive|define
name|TSP_MASTERUP
value|6
end_define

begin_comment
comment|/* inform slaves that master is up */
end_comment

begin_define
define|#
directive|define
name|TSP_SLAVEUP
value|7
end_define

begin_comment
comment|/* slave is up but not polled */
end_comment

begin_define
define|#
directive|define
name|TSP_ELECTION
value|8
end_define

begin_comment
comment|/* advance candidature for master */
end_comment

begin_define
define|#
directive|define
name|TSP_ACCEPT
value|9
end_define

begin_comment
comment|/* support candidature of master */
end_comment

begin_define
define|#
directive|define
name|TSP_REFUSE
value|10
end_define

begin_comment
comment|/* reject candidature of master */
end_comment

begin_define
define|#
directive|define
name|TSP_CONFLICT
value|11
end_define

begin_comment
comment|/* two or more masters present */
end_comment

begin_define
define|#
directive|define
name|TSP_RESOLVE
value|12
end_define

begin_comment
comment|/* masters' conflict resolution */
end_comment

begin_define
define|#
directive|define
name|TSP_QUIT
value|13
end_define

begin_comment
comment|/* reject candidature if master is up */
end_comment

begin_define
define|#
directive|define
name|TSP_DATE
value|14
end_define

begin_comment
comment|/* reset the time (date command) */
end_comment

begin_define
define|#
directive|define
name|TSP_DATEREQ
value|15
end_define

begin_comment
comment|/* remote request to reset the time */
end_comment

begin_define
define|#
directive|define
name|TSP_DATEACK
value|16
end_define

begin_comment
comment|/* acknowledge time setting  */
end_comment

begin_define
define|#
directive|define
name|TSP_TRACEON
value|17
end_define

begin_comment
comment|/* turn tracing on */
end_comment

begin_define
define|#
directive|define
name|TSP_TRACEOFF
value|18
end_define

begin_comment
comment|/* turn tracing off */
end_comment

begin_define
define|#
directive|define
name|TSP_MSITE
value|19
end_define

begin_comment
comment|/* find out master's site */
end_comment

begin_define
define|#
directive|define
name|TSP_MSITEREQ
value|20
end_define

begin_comment
comment|/* remote master's site request */
end_comment

begin_define
define|#
directive|define
name|TSP_TEST
value|21
end_define

begin_comment
comment|/* for testing election algo */
end_comment

begin_define
define|#
directive|define
name|TSP_SETDATE
value|22
end_define

begin_comment
comment|/* New from date command */
end_comment

begin_define
define|#
directive|define
name|TSP_SETDATEREQ
value|23
end_define

begin_comment
comment|/* New remote for above */
end_comment

begin_define
define|#
directive|define
name|TSP_LOOP
value|24
end_define

begin_comment
comment|/* loop detection packet */
end_comment

begin_define
define|#
directive|define
name|TSPTYPENUMBER
value|25
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TSPTYPES
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|tsptype
index|[
name|TSPTYPENUMBER
index|]
init|=
block|{
literal|"ANY"
block|,
literal|"ADJTIME"
block|,
literal|"ACK"
block|,
literal|"MASTERREQ"
block|,
literal|"MASTERACK"
block|,
literal|"SETTIME"
block|,
literal|"MASTERUP"
block|,
literal|"SLAVEUP"
block|,
literal|"ELECTION"
block|,
literal|"ACCEPT"
block|,
literal|"REFUSE"
block|,
literal|"CONFLICT"
block|,
literal|"RESOLVE"
block|,
literal|"QUIT"
block|,
literal|"DATE"
block|,
literal|"DATEREQ"
block|,
literal|"DATEACK"
block|,
literal|"TRACEON"
block|,
literal|"TRACEOFF"
block|,
literal|"MSITE"
block|,
literal|"MSITEREQ"
block|,
literal|"TEST"
block|,
literal|"SETDATE"
block|,
literal|"SETDATEREQ"
block|,
literal|"LOOP"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TIMED_H_ */
end_comment

end_unit

