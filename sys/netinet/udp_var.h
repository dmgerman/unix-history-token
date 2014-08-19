begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)udp_var.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
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
name|ui_x1
value|ui_i.ih_x1
end_define

begin_define
define|#
directive|define
name|ui_v
value|ui_i.ih_x1[0]
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

begin_struct_decl
struct_decl|struct
name|inpcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|udp_tun_func_t
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
name|off
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * UDP control block; one per udp.  */
end_comment

begin_struct
struct|struct
name|udpcb
block|{
name|udp_tun_func_t
name|u_tun_func
decl_stmt|;
comment|/* UDP kernel tunneling callback. */
name|u_int
name|u_flags
decl_stmt|;
comment|/* Generic UDP flags. */
name|uint16_t
name|u_rxcslen
decl_stmt|;
comment|/* Coverage for incoming datagrams. */
name|uint16_t
name|u_txcslen
decl_stmt|;
comment|/* Coverage for outgoing datagrams. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|intoudpcb
parameter_list|(
name|ip
parameter_list|)
value|((struct udpcb *)(ip)->inp_ppcb)
end_define

begin_define
define|#
directive|define
name|sotoudpcb
parameter_list|(
name|so
parameter_list|)
value|(intoudpcb(sotoinpcb(so)))
end_define

begin_comment
comment|/* IPsec: ESP in UDP tunneling: */
end_comment

begin_define
define|#
directive|define
name|UF_ESPINUDP_NON_IKE
value|0x00000001
end_define

begin_comment
comment|/* w/ non-IKE marker .. */
end_comment

begin_comment
comment|/* .. per draft-ietf-ipsec-nat-t-ike-0[01], 	 * and draft-ietf-ipsec-udp-encaps-(00/)01.txt */
end_comment

begin_define
define|#
directive|define
name|UF_ESPINUDP
value|0x00000002
end_define

begin_comment
comment|/* w/ non-ESP marker. */
end_comment

begin_struct
struct|struct
name|udpstat
block|{
comment|/* input statistics: */
name|uint64_t
name|udps_ipackets
decl_stmt|;
comment|/* total input packets */
name|uint64_t
name|udps_hdrops
decl_stmt|;
comment|/* packet shorter than header */
name|uint64_t
name|udps_badsum
decl_stmt|;
comment|/* checksum error */
name|uint64_t
name|udps_nosum
decl_stmt|;
comment|/* no checksum */
name|uint64_t
name|udps_badlen
decl_stmt|;
comment|/* data length larger than packet */
name|uint64_t
name|udps_noport
decl_stmt|;
comment|/* no socket on port */
name|uint64_t
name|udps_noportbcast
decl_stmt|;
comment|/* of above, arrived as broadcast */
name|uint64_t
name|udps_fullsock
decl_stmt|;
comment|/* not delivered, input socket full */
name|uint64_t
name|udpps_pcbcachemiss
decl_stmt|;
comment|/* input packets missing pcb cache */
name|uint64_t
name|udpps_pcbhashmiss
decl_stmt|;
comment|/* input packets not for hashed pcb */
comment|/* output statistics: */
name|uint64_t
name|udps_opackets
decl_stmt|;
comment|/* total output packets */
name|uint64_t
name|udps_fastout
decl_stmt|;
comment|/* output packets on fast path */
comment|/* of no socket on port, arrived as multicast */
name|uint64_t
name|udps_noportmcast
decl_stmt|;
name|uint64_t
name|udps_filtermcast
decl_stmt|;
comment|/* blocked by multicast filter */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/counter.h>
end_include

begin_expr_stmt
name|VNET_PCPUSTAT_DECLARE
argument_list|(
expr|struct
name|udpstat
argument_list|,
name|udpstat
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * In-kernel consumers can use these accessor macros directly to update  * stats.  */
end_comment

begin_define
define|#
directive|define
name|UDPSTAT_ADD
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
define|\
value|VNET_PCPUSTAT_ADD(struct udpstat, udpstat, name, (val))
end_define

begin_define
define|#
directive|define
name|UDPSTAT_INC
parameter_list|(
name|name
parameter_list|)
value|UDPSTAT_ADD(name, 1)
end_define

begin_comment
comment|/*  * Kernel module consumers must use this accessor macro.  */
end_comment

begin_function_decl
name|void
name|kmod_udpstat_inc
parameter_list|(
name|int
name|statnum
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KMOD_UDPSTAT_INC
parameter_list|(
name|name
parameter_list|)
define|\
value|kmod_udpstat_inc(offsetof(struct udpstat, name) / sizeof(uint64_t))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Identifiers for UDP sysctl nodes.  */
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
name|UDPCTL_STATS
value|2
end_define

begin_comment
comment|/* statistics (read-only) */
end_comment

begin_define
define|#
directive|define
name|UDPCTL_MAXDGRAM
value|3
end_define

begin_comment
comment|/* max datagram size */
end_comment

begin_define
define|#
directive|define
name|UDPCTL_RECVSPACE
value|4
end_define

begin_comment
comment|/* default receive buffer space */
end_comment

begin_define
define|#
directive|define
name|UDPCTL_PCBLIST
value|5
end_define

begin_comment
comment|/* list of PCBs for UDP sockets */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in_pcb.h>
end_include

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_udp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|udp_usrreqs
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|inpcbhead
argument_list|,
name|udb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|inpcbinfo
argument_list|,
name|udbinfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|inpcbhead
argument_list|,
name|ulitecb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
expr|struct
name|inpcbinfo
argument_list|,
name|ulitecbinfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_udb
value|VNET(udb)
end_define

begin_define
define|#
directive|define
name|V_udbinfo
value|VNET(udbinfo)
end_define

begin_define
define|#
directive|define
name|V_ulitecb
value|VNET(ulitecb)
end_define

begin_define
define|#
directive|define
name|V_ulitecbinfo
value|VNET(ulitecbinfo)
end_define

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

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|udp_cksum
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|udp_blackhole
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_udp_cksum
value|VNET(udp_cksum)
end_define

begin_define
define|#
directive|define
name|V_udp_blackhole
value|VNET(udp_blackhole)
end_define

begin_decl_stmt
specifier|extern
name|int
name|udp_log_in_vain
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|inpcbinfo
operator|*
name|get_inpcbinfo
argument_list|(
argument|uint8_t protocol
argument_list|)
block|{
return|return
operator|(
name|protocol
operator|==
name|IPPROTO_UDP
operator|)
operator|?
operator|&
name|V_udbinfo
operator|:
operator|&
name|V_ulitecbinfo
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|inpcbhead
operator|*
name|get_pcblist
argument_list|(
argument|uint8_t protocol
argument_list|)
block|{
return|return
operator|(
name|protocol
operator|==
name|IPPROTO_UDP
operator|)
operator|?
operator|&
name|V_udb
operator|:
operator|&
name|V_ulitecb
return|;
block|}
end_expr_stmt

begin_function_decl
name|int
name|udp_newudpcb
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|udp_discardcb
parameter_list|(
name|struct
name|udpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|udp_ctlinput
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|udplite_ctlinput
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|udp_ctloutput
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|udp_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|udplite_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_function_decl
name|void
name|udp_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|udplite_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|udp_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|udplite_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inpcb
modifier|*
name|udp_notify
parameter_list|(
name|struct
name|inpcb
modifier|*
name|inp
parameter_list|,
name|int
name|errno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|udp_shutdown
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|udp_set_kernel_tunneling
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|udp_tun_func_t
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_UDP_VAR_H_ */
end_comment

end_unit

