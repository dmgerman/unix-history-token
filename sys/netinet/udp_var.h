begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)udp_var.h	7.7 (Berkeley) 6/28/90  *	$Id: udp_var.h,v 1.3 1993/11/07 17:48:16 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_UDP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_UDP_VAR_H_
value|1
end_define

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
name|int
name|udps_ipackets
decl_stmt|;
comment|/* total input packets */
name|int
name|udps_hdrops
decl_stmt|;
comment|/* packet shorter than header */
name|int
name|udps_badsum
decl_stmt|;
comment|/* checksum error */
name|int
name|udps_badlen
decl_stmt|;
comment|/* data length larger than packet */
name|int
name|udps_noport
decl_stmt|;
comment|/* no socket on port */
name|int
name|udps_noportbcast
decl_stmt|;
comment|/* of above, arrived as broadcast */
name|int
name|udps_fullsock
decl_stmt|;
comment|/* not delivered, input socket full */
name|int
name|udpps_pcbcachemiss
decl_stmt|;
comment|/* input packets missing pcb cache */
comment|/* output statistics: */
name|int
name|udps_opackets
decl_stmt|;
comment|/* total output packets */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UDP_TTL
value|30
end_define

begin_comment
comment|/* default time to live for UDP packets */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|inpcb
name|udb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|udpstat
name|udpstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From in_var.h: */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|udpcksum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|udp_ttl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|udp_sendspace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|udp_recvspace
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_UDP_VAR_H_ */
end_comment

end_unit

