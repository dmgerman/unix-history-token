begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)in_pcb.h	8.1 (Berkeley) 6/10/93  * $Id: in_pcb.h,v 1.23 1998/01/27 09:15:04 davidg Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IN_PCB_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Common structure pcb for internet protocol implementation.  * Here are stored pointers to local and foreign host table  * entries, local and foreign socket numbers, and pointers  * up (to a socket structure) and down (to a protocol-specific)  * control block.  */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|inpcbhead
argument_list|,
name|inpcb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|inpcbporthead
argument_list|,
name|inpcbport
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * NB: the zone allocator is type-stable EXCEPT FOR THE FIRST TWO LONGS  * of the structure.  Therefore, it is important that the members in  * that position not contain any information which is required to be  * stable.  */
end_comment

begin_struct
struct|struct
name|inpcb
block|{
name|LIST_ENTRY
argument_list|(
argument|inpcb
argument_list|)
name|inp_hash
expr_stmt|;
comment|/* hash list */
name|struct
name|in_addr
name|inp_faddr
decl_stmt|;
comment|/* foreign host table entry */
name|struct
name|in_addr
name|inp_laddr
decl_stmt|;
comment|/* local host table entry */
name|u_short
name|inp_fport
decl_stmt|;
comment|/* foreign port */
name|u_short
name|inp_lport
decl_stmt|;
comment|/* local port */
name|LIST_ENTRY
argument_list|(
argument|inpcb
argument_list|)
name|inp_list
expr_stmt|;
comment|/* list for all PCBs of this proto */
name|caddr_t
name|inp_ppcb
decl_stmt|;
comment|/* pointer to per-protocol pcb */
name|struct
name|inpcbinfo
modifier|*
name|inp_pcbinfo
decl_stmt|;
comment|/* PCB list info */
name|struct
name|socket
modifier|*
name|inp_socket
decl_stmt|;
comment|/* back pointer to socket */
name|struct
name|mbuf
modifier|*
name|inp_options
decl_stmt|;
comment|/* IP options */
name|struct
name|route
name|inp_route
decl_stmt|;
comment|/* placeholder for routing entry */
name|int
name|inp_flags
decl_stmt|;
comment|/* generic IP/datagram flags */
name|u_char
name|inp_ip_tos
decl_stmt|;
comment|/* type of service proto */
name|u_char
name|inp_ip_ttl
decl_stmt|;
comment|/* time to live proto */
name|u_char
name|inp_ip_p
decl_stmt|;
comment|/* protocol proto */
name|u_char
name|pad
index|[
literal|1
index|]
decl_stmt|;
comment|/* alignment */
name|struct
name|ip_moptions
modifier|*
name|inp_moptions
decl_stmt|;
comment|/* IP multicast options */
name|LIST_ENTRY
argument_list|(
argument|inpcb
argument_list|)
name|inp_portlist
expr_stmt|;
comment|/* list for this PCB's local port */
name|struct
name|inpcbport
modifier|*
name|inp_phd
decl_stmt|;
comment|/* head of list for this PCB's local port */
name|u_quad_t
name|inp_gencnt
decl_stmt|;
comment|/* generation count of this instance */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The range of the generation count, as used in this implementation,  * is 9e19.  We would have to create 300 billion connections per  * second for this number to roll over in a year.  This seems sufficiently  * unlikely that we simply don't concern ourselves with that possibility.  */
end_comment

begin_struct
struct|struct
name|inpcbport
block|{
name|LIST_ENTRY
argument_list|(
argument|inpcbport
argument_list|)
name|phd_hash
expr_stmt|;
name|struct
name|inpcbhead
name|phd_pcblist
decl_stmt|;
name|u_short
name|phd_port
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|inpcbinfo
block|{
comment|/* XXX documentation, prefixes */
name|struct
name|inpcbhead
modifier|*
name|hashbase
decl_stmt|;
name|u_long
name|hashmask
decl_stmt|;
name|struct
name|inpcbporthead
modifier|*
name|porthashbase
decl_stmt|;
name|u_long
name|porthashmask
decl_stmt|;
name|struct
name|inpcbhead
modifier|*
name|listhead
decl_stmt|;
name|u_short
name|lastport
decl_stmt|;
name|u_short
name|lastlow
decl_stmt|;
name|u_short
name|lasthi
decl_stmt|;
name|struct
name|vm_zone
modifier|*
name|ipi_zone
decl_stmt|;
comment|/* zone to allocate pcbs from */
name|u_int
name|ipi_count
decl_stmt|;
comment|/* number of pcbs in this list */
name|u_quad_t
name|ipi_gencnt
decl_stmt|;
comment|/* current generation count */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INP_PCBHASH
parameter_list|(
name|faddr
parameter_list|,
name|lport
parameter_list|,
name|fport
parameter_list|,
name|mask
parameter_list|)
define|\
value|(((faddr) ^ ((faddr)>> 16) ^ ntohs((lport) ^ (fport)))& (mask))
end_define

begin_define
define|#
directive|define
name|INP_PCBPORTHASH
parameter_list|(
name|lport
parameter_list|,
name|mask
parameter_list|)
define|\
value|(ntohs((lport))& (mask))
end_define

begin_comment
comment|/* flags in inp_flags: */
end_comment

begin_define
define|#
directive|define
name|INP_RECVOPTS
value|0x01
end_define

begin_comment
comment|/* receive incoming IP options */
end_comment

begin_define
define|#
directive|define
name|INP_RECVRETOPTS
value|0x02
end_define

begin_comment
comment|/* receive IP options for reply */
end_comment

begin_define
define|#
directive|define
name|INP_RECVDSTADDR
value|0x04
end_define

begin_comment
comment|/* receive IP dst address */
end_comment

begin_define
define|#
directive|define
name|INP_HDRINCL
value|0x08
end_define

begin_comment
comment|/* user supplies entire IP header */
end_comment

begin_define
define|#
directive|define
name|INP_HIGHPORT
value|0x10
end_define

begin_comment
comment|/* user wants "high" port binding */
end_comment

begin_define
define|#
directive|define
name|INP_LOWPORT
value|0x20
end_define

begin_comment
comment|/* user wants "low" port binding */
end_comment

begin_define
define|#
directive|define
name|INP_ANONPORT
value|0x40
end_define

begin_comment
comment|/* port chosen for user */
end_comment

begin_define
define|#
directive|define
name|INP_RECVIF
value|0x80
end_define

begin_comment
comment|/* receive incoming interface */
end_comment

begin_define
define|#
directive|define
name|INP_MTUDISC
value|0x100
end_define

begin_comment
comment|/* user can do MTU discovery */
end_comment

begin_define
define|#
directive|define
name|INP_CONTROLOPTS
value|(INP_RECVOPTS|INP_RECVRETOPTS|INP_RECVDSTADDR|\ 					INP_RECVIF)
end_define

begin_define
define|#
directive|define
name|INPLOOKUP_WILDCARD
value|1
end_define

begin_define
define|#
directive|define
name|sotoinpcb
parameter_list|(
name|so
parameter_list|)
value|((struct inpcb *)(so)->so_pcb)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|void
name|in_losing
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_pcballoc
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
expr|struct
name|inpcbinfo
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_pcbbind
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_pcbconnect
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in_pcbdetach
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in_pcbdisconnect
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_pcbinshash
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_pcbladdr
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|inpcb
modifier|*
name|in_pcblookup_local
name|__P
argument_list|(
operator|(
expr|struct
name|inpcbinfo
operator|*
operator|,
expr|struct
name|in_addr
operator|,
name|u_int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|inpcb
modifier|*
name|in_pcblookup_hash
name|__P
argument_list|(
operator|(
expr|struct
name|inpcbinfo
operator|*
operator|,
expr|struct
name|in_addr
operator|,
name|u_int
operator|,
expr|struct
name|in_addr
operator|,
name|u_int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in_pcbnotify
name|__P
argument_list|(
operator|(
expr|struct
name|inpcbhead
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|u_int
operator|,
expr|struct
name|in_addr
operator|,
name|u_int
operator|,
name|int
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|inpcb
operator|*
argument_list|,
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|in_pcbrehash
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_setpeeraddr
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
name|nam
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in_setsockaddr
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
name|nam
operator|)
argument_list|)
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

end_unit

