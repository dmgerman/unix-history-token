begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: route6d.h,v 1.4 2001/01/15 03:50:54 inoue Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* not yet in use  #define	ROUTE6D_CONF	"/usr/local/v6/etc/route6d.conf" */
end_comment

begin_define
define|#
directive|define
name|ROUTE6D_DUMP
value|"/var/run/route6d_dump"
end_define

begin_define
define|#
directive|define
name|ROUTE6D_PID
value|"/var/run/route6d.pid"
end_define

begin_define
define|#
directive|define
name|RIP6_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|RIP6_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|RIP6_RESPONSE
value|2
end_define

begin_define
define|#
directive|define
name|IFC_CHANGED
value|1
end_define

begin_struct
struct|struct
name|netinfo6
block|{
name|struct
name|in6_addr
name|rip6_dest
decl_stmt|;
name|u_short
name|rip6_tag
decl_stmt|;
name|u_char
name|rip6_plen
decl_stmt|;
name|u_char
name|rip6_metric
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rip6
block|{
name|u_char
name|rip6_cmd
decl_stmt|;
name|u_char
name|rip6_vers
decl_stmt|;
name|u_char
name|rip6_res1
index|[
literal|2
index|]
decl_stmt|;
union|union
block|{
name|struct
name|netinfo6
name|ru6_nets
index|[
literal|1
index|]
decl_stmt|;
name|char
name|ru6_tracefile
index|[
literal|1
index|]
decl_stmt|;
block|}
name|rip6un
union|;
define|#
directive|define
name|rip6_nets
value|rip6un.ru6_nets
define|#
directive|define
name|rip6_tracefile
value|rip6un.ru6_tracefile
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HOPCNT_INFINITY6
value|16
end_define

begin_define
define|#
directive|define
name|NEXTHOP_METRIC
value|0xff
end_define

begin_define
define|#
directive|define
name|RIP6_MAXMTU
value|1500
end_define

begin_define
define|#
directive|define
name|IFMINMTU
value|576
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_define
define|#
directive|define
name|SUPPLY_INTERVAL6
value|30
end_define

begin_define
define|#
directive|define
name|RIP_LIFETIME
value|180
end_define

begin_define
define|#
directive|define
name|RIP_HOLDDOWN
value|120
end_define

begin_define
define|#
directive|define
name|RIP_TRIG_INT6_MAX
value|5
end_define

begin_define
define|#
directive|define
name|RIP_TRIG_INT6_MIN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* only for debugging; can not wait for 30sec to appear a bug */
end_comment

begin_define
define|#
directive|define
name|SUPPLY_INTERVAL6
value|10
end_define

begin_define
define|#
directive|define
name|RIP_LIFETIME
value|60
end_define

begin_define
define|#
directive|define
name|RIP_HOLDDOWN
value|40
end_define

begin_define
define|#
directive|define
name|RIP_TRIG_INT6_MAX
value|5
end_define

begin_define
define|#
directive|define
name|RIP_TRIG_INT6_MIN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RIP6_PORT
value|521
end_define

begin_define
define|#
directive|define
name|RIP6_DEST
value|"ff02::9"
end_define

begin_define
define|#
directive|define
name|LOOPBACK_IF
value|"lo0"
end_define

end_unit

