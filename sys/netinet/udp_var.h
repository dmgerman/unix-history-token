begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)udp_var.h	8.1 (Berkeley) 6/10/93  * $Id$  */
end_comment

begin_comment
comment|/*  * UDP kernel structures and variables.  */
end_comment

begin_struct
struct|struct
name|udpiphdr
block|{
name|struct
name|ipovly
name|ui_i
decl_stmt|;
comment|/* overlaid ip structure */
name|struct
name|udphdr
name|ui_u
decl_stmt|;
comment|/* udp header */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ui_next
value|ui_i.ih_next
end_define

begin_define
define|#
directive|define
name|ui_prev
value|ui_i.ih_prev
end_define

begin_define
define|#
directive|define
name|ui_x1
value|ui_i.ih_x1
end_define

begin_define
define|#
directive|define
name|ui_pr
value|ui_i.ih_pr
end_define

begin_define
define|#
directive|define
name|ui_len
value|ui_i.ih_len
end_define

begin_define
define|#
directive|define
name|ui_src
value|ui_i.ih_src
end_define

begin_define
define|#
directive|define
name|ui_dst
value|ui_i.ih_dst
end_define

begin_define
define|#
directive|define
name|ui_sport
value|ui_u.uh_sport
end_define

begin_define
define|#
directive|define
name|ui_dport
value|ui_u.uh_dport
end_define

begin_define
define|#
directive|define
name|ui_ulen
value|ui_u.uh_ulen
end_define

begin_define
define|#
directive|define
name|ui_sum
value|ui_u.uh_sum
end_define

begin_struct
struct|struct
name|udpstat
block|{
comment|/* input statistics: */
name|u_long
name|udps_ipackets
decl_stmt|;
comment|/* total input packets */
name|u_long
name|udps_hdrops
decl_stmt|;
comment|/* packet shorter than header */
name|u_long
name|udps_badsum
decl_stmt|;
comment|/* checksum error */
name|u_long
name|udps_badlen
decl_stmt|;
comment|/* data length larger than packet */
name|u_long
name|udps_noport
decl_stmt|;
comment|/* no socket on port */
name|u_long
name|udps_noportbcast
decl_stmt|;
comment|/* of above, arrived as broadcast */
name|u_long
name|udps_fullsock
decl_stmt|;
comment|/* not delivered, input socket full */
name|u_long
name|udpps_pcbcachemiss
decl_stmt|;
comment|/* input packets missing pcb cache */
comment|/* output statistics: */
name|u_long
name|udps_opackets
decl_stmt|;
comment|/* total output packets */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Names for UDP sysctl objects  */
end_comment

begin_define
define|#
directive|define
name|UDPCTL_CHECKSUM
value|1
end_define

begin_comment
comment|/* checksum UDP packets */
end_comment

begin_define
define|#
directive|define
name|UDPCTL_MAXID
value|2
end_define

begin_define
define|#
directive|define
name|UDPCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "checksum", CTLTYPE_INT }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|inpcb
name|udb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|udpstat
name|udpstat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|udp_ctlinput
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|ip
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|udp_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|udp_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|udp_output
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|udp_sysctl
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|u_int
operator|,
name|void
operator|*
operator|,
name|size_t
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|udp_usrreq
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
name|int
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

