begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: rtsold.h,v 1.11 2000/10/10 06:18:04 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|ifinfo
block|{
name|struct
name|ifinfo
modifier|*
name|next
decl_stmt|;
comment|/* pointer to the next interface */
name|struct
name|sockaddr_dl
modifier|*
name|sdl
decl_stmt|;
comment|/* link-layer address */
name|char
name|ifname
index|[
name|IF_NAMESIZE
index|]
decl_stmt|;
comment|/* interface name */
name|int
name|active
decl_stmt|;
comment|/* interface status */
name|int
name|probeinterval
decl_stmt|;
comment|/* interval of probe timer(if necessary) */
name|int
name|probetimer
decl_stmt|;
comment|/* rest of probe timer */
name|int
name|mediareqok
decl_stmt|;
comment|/* wheter the IF supports SIOCGIFMEDIA */
name|int
name|state
decl_stmt|;
name|int
name|probes
decl_stmt|;
name|int
name|dadcount
decl_stmt|;
name|struct
name|timeval
name|timer
decl_stmt|;
name|struct
name|timeval
name|expire
decl_stmt|;
name|int
name|errors
decl_stmt|;
comment|/* # of errors we've got - detect wedge */
name|int
name|racnt
decl_stmt|;
comment|/* total # of valid RAs it have got */
name|size_t
name|rs_datalen
decl_stmt|;
name|u_char
modifier|*
name|rs_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* per interface status */
end_comment

begin_define
define|#
directive|define
name|IFS_IDLE
value|0
end_define

begin_define
define|#
directive|define
name|IFS_DELAY
value|1
end_define

begin_define
define|#
directive|define
name|IFS_PROBE
value|2
end_define

begin_define
define|#
directive|define
name|IFS_DOWN
value|3
end_define

begin_define
define|#
directive|define
name|IFS_TENTATIVE
value|4
end_define

begin_comment
comment|/* rtsold.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|tm_max
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifinfo
modifier|*
name|find_ifinfo
name|__P
argument_list|(
operator|(
name|int
name|ifindex
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rtsol_timer_update
name|__P
argument_list|(
operator|(
expr|struct
name|ifinfo
operator|*
name|ifinfo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|warnmsg
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|__format__
argument_list|(
name|__printf__
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ifinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|interface_up
name|__P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|interface_status
name|__P
argument_list|(
operator|(
expr|struct
name|ifinfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lladdropt_length
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_dl
operator|*
name|sdl
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|lladdropt_fill
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_dl
operator|*
name|sdl
operator|,
expr|struct
name|nd_opt_hdr
operator|*
name|ndopt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_dl
modifier|*
name|if_nametosdl
name|__P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getinet6sysctl
name|__P
argument_list|(
operator|(
name|int
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rtsol.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sockopen
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sendpacket
name|__P
argument_list|(
operator|(
expr|struct
name|ifinfo
operator|*
name|ifinfo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rtsol_input
name|__P
argument_list|(
operator|(
name|int
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* probe.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|probe_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|defrouter_probe
name|__P
argument_list|(
operator|(
name|int
name|ifindex
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dump.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|rtsold_dump_file
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rtsock.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rtsock_open
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rtsock_input
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

