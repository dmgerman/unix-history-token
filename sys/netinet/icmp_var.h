begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)icmp_var.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_ICMP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_ICMP_VAR_H_
end_define

begin_comment
comment|/*  * Variables related to this implementation  * of the internet control message protocol.  */
end_comment

begin_struct
struct|struct
name|icmpstat
block|{
comment|/* statistics related to icmp packets generated */
name|u_long
name|icps_error
decl_stmt|;
comment|/* # of calls to icmp_error */
name|u_long
name|icps_oldshort
decl_stmt|;
comment|/* no error 'cuz old ip too short */
name|u_long
name|icps_oldicmp
decl_stmt|;
comment|/* no error 'cuz old was icmp */
name|u_long
name|icps_outhist
index|[
name|ICMP_MAXTYPE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* statistics related to input messages processed */
name|u_long
name|icps_badcode
decl_stmt|;
comment|/* icmp_code out of range */
name|u_long
name|icps_tooshort
decl_stmt|;
comment|/* packet< ICMP_MINLEN */
name|u_long
name|icps_checksum
decl_stmt|;
comment|/* bad checksum */
name|u_long
name|icps_badlen
decl_stmt|;
comment|/* calculated bound mismatch */
name|u_long
name|icps_reflect
decl_stmt|;
comment|/* number of responses */
name|u_long
name|icps_inhist
index|[
name|ICMP_MAXTYPE
operator|+
literal|1
index|]
decl_stmt|;
name|u_long
name|icps_bmcastecho
decl_stmt|;
comment|/* b/mcast echo requests dropped */
name|u_long
name|icps_bmcasttstamp
decl_stmt|;
comment|/* b/mcast tstamp requests dropped */
name|u_long
name|icps_badaddr
decl_stmt|;
comment|/* bad return address */
name|u_long
name|icps_noroute
decl_stmt|;
comment|/* no route back */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Names for ICMP sysctl objects  */
end_comment

begin_define
define|#
directive|define
name|ICMPCTL_MASKREPL
value|1
end_define

begin_comment
comment|/* allow replies to netmask requests */
end_comment

begin_define
define|#
directive|define
name|ICMPCTL_STATS
value|2
end_define

begin_comment
comment|/* statistics (read-only) */
end_comment

begin_define
define|#
directive|define
name|ICMPCTL_ICMPLIM
value|3
end_define

begin_define
define|#
directive|define
name|ICMPCTL_MAXID
value|4
end_define

begin_define
define|#
directive|define
name|ICMPCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "maskrepl", CTLTYPE_INT }, \ 	{ "stats", CTLTYPE_STRUCT }, \ 	{ "icmplim", CTLTYPE_INT }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_icmp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|int
name|badport_bandlim
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BANDLIM_UNLIMITED
value|-1
end_define

begin_define
define|#
directive|define
name|BANDLIM_ICMP_UNREACH
value|0
end_define

begin_define
define|#
directive|define
name|BANDLIM_ICMP_ECHO
value|1
end_define

begin_define
define|#
directive|define
name|BANDLIM_ICMP_TSTAMP
value|2
end_define

begin_define
define|#
directive|define
name|BANDLIM_RST_CLOSEDPORT
value|3
end_define

begin_comment
comment|/* No connection, and no listeners */
end_comment

begin_define
define|#
directive|define
name|BANDLIM_RST_OPENPORT
value|4
end_define

begin_comment
comment|/* No connection, listener */
end_comment

begin_define
define|#
directive|define
name|BANDLIM_MAX
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

