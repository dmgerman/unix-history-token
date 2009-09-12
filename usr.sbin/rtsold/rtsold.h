begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: rtsold.h,v 1.19 2003/04/16 09:48:15 itojun Exp $	*/
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
name|u_int32_t
name|linkid
decl_stmt|;
comment|/* link ID of this interface */
name|int
name|active
decl_stmt|;
comment|/* interface status */
name|int
name|probeinterval
decl_stmt|;
comment|/* interval of probe timer (if necessary) */
name|int
name|probetimer
decl_stmt|;
comment|/* rest of probe timer */
name|int
name|mediareqok
decl_stmt|;
comment|/* wheter the IF supports SIOCGIFMEDIA */
name|int
name|otherconfig
decl_stmt|;
comment|/* need a separate protocol for the "other" 				 * configuration */
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
specifier|extern
name|int
name|aflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Fflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|otherconf_script
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|ifconfig
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iflist_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifinfo
modifier|*
name|find_ifinfo
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtsol_timer_update
parameter_list|(
name|struct
name|ifinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|warnmsg
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|autoifprobe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* if.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|ifinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|interface_up
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|interface_status
parameter_list|(
name|struct
name|ifinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lladdropt_length
parameter_list|(
name|struct
name|sockaddr_dl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lladdropt_fill
parameter_list|(
name|struct
name|sockaddr_dl
modifier|*
parameter_list|,
name|struct
name|nd_opt_hdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|sockaddr_dl
modifier|*
name|if_nametosdl
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getinet6sysctl
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setinet6sysctl
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* rtsol.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|sockopen
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sendpacket
parameter_list|(
name|struct
name|ifinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rtsol_input
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* probe.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|probe_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|defrouter_probe
parameter_list|(
name|struct
name|ifinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dump.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|rtsold_dump_file
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* rtsock.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|rtsock_open
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rtsock_input
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

