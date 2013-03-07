begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)in_pcb.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/_rwlock.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/rwlock.h>
end_include

begin_include
include|#
directive|include
file|<net/vnet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|in6pcb
value|inpcb
end_define

begin_comment
comment|/* for KAME src sync over BSD*'s */
end_comment

begin_define
define|#
directive|define
name|in6p_sp
value|inp_sp
end_define

begin_comment
comment|/* for KAME src sync over BSD*'s */
end_comment

begin_struct_decl
struct_decl|struct
name|inpcbpolicy
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * struct inpcb is the common protocol control block structure used in most  * IP transport protocols.  *  * Pointers to local and foreign host table entries, local and foreign socket  * numbers, and pointers up (to a socket structure) and down (to a  * protocol-specific control block) are stored here.  */
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

begin_typedef
typedef|typedef
name|u_quad_t
name|inp_gen_t
typedef|;
end_typedef

begin_comment
comment|/*  * PCB with AF_INET6 null bind'ed laddr can receive AF_INET input packet.  * So, AF_INET6 null laddr is also used as AF_INET null laddr, by utilizing  * the following structure.  */
end_comment

begin_struct
struct|struct
name|in_addr_4in6
block|{
name|u_int32_t
name|ia46_pad32
index|[
literal|3
index|]
decl_stmt|;
name|struct
name|in_addr
name|ia46_addr4
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NOTE: ipv6 addrs should be 64-bit aligned, per RFC 2553.  in_conninfo has  * some extra padding to accomplish this.  */
end_comment

begin_struct
struct|struct
name|in_endpoints
block|{
name|u_int16_t
name|ie_fport
decl_stmt|;
comment|/* foreign port */
name|u_int16_t
name|ie_lport
decl_stmt|;
comment|/* local port */
comment|/* protocol dependent part, local and foreign addr */
union|union
block|{
comment|/* foreign host table entry */
name|struct
name|in_addr_4in6
name|ie46_foreign
decl_stmt|;
name|struct
name|in6_addr
name|ie6_foreign
decl_stmt|;
block|}
name|ie_dependfaddr
union|;
union|union
block|{
comment|/* local host table entry */
name|struct
name|in_addr_4in6
name|ie46_local
decl_stmt|;
name|struct
name|in6_addr
name|ie6_local
decl_stmt|;
block|}
name|ie_dependladdr
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ie_faddr
value|ie_dependfaddr.ie46_foreign.ia46_addr4
end_define

begin_define
define|#
directive|define
name|ie_laddr
value|ie_dependladdr.ie46_local.ia46_addr4
end_define

begin_define
define|#
directive|define
name|ie6_faddr
value|ie_dependfaddr.ie6_foreign
end_define

begin_define
define|#
directive|define
name|ie6_laddr
value|ie_dependladdr.ie6_local
end_define

begin_comment
comment|/*  * XXX The defines for inc_* are hacks and should be changed to direct  * references.  */
end_comment

begin_struct
struct|struct
name|in_conninfo
block|{
name|u_int8_t
name|inc_flags
decl_stmt|;
name|u_int8_t
name|inc_len
decl_stmt|;
name|u_int16_t
name|inc_fibnum
decl_stmt|;
comment|/* XXX was pad, 16 bits is plenty */
comment|/* protocol dependent part */
name|struct
name|in_endpoints
name|inc_ie
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for inc_flags.  */
end_comment

begin_define
define|#
directive|define
name|INC_ISIPV6
value|0x01
end_define

begin_define
define|#
directive|define
name|inc_isipv6
value|inc_flags
end_define

begin_comment
comment|/* temp compatability */
end_comment

begin_define
define|#
directive|define
name|inc_fport
value|inc_ie.ie_fport
end_define

begin_define
define|#
directive|define
name|inc_lport
value|inc_ie.ie_lport
end_define

begin_define
define|#
directive|define
name|inc_faddr
value|inc_ie.ie_faddr
end_define

begin_define
define|#
directive|define
name|inc_laddr
value|inc_ie.ie_laddr
end_define

begin_define
define|#
directive|define
name|inc6_faddr
value|inc_ie.ie6_faddr
end_define

begin_define
define|#
directive|define
name|inc6_laddr
value|inc_ie.ie6_laddr
end_define

begin_struct_decl
struct_decl|struct
name|icmp6_filter
struct_decl|;
end_struct_decl

begin_comment
comment|/*-  * struct inpcb captures the network layer state for TCP, UDP, and raw IPv4  * and IPv6 sockets.  In the case of TCP, further per-connection state is  * hung off of inp_ppcb most of the time.  Almost all fields of struct inpcb  * are static after creation or protected by a per-inpcb rwlock, inp_lock.  A  * few fields also require the global pcbinfo lock for the inpcb to be held,  * when modified, such as the global connection lists and hashes, as well as  * binding information (which affects which hash a connection is on).  This  * model means that connections can be looked up without holding the  * per-connection lock, which is important for performance when attempting to  * find the connection for a packet given its IP and port tuple.  Writing to  * these fields that write locks be held on both the inpcb and global locks.  *  * Key:  * (c) - Constant after initialization  * (i) - Protected by the inpcb lock  * (p) - Protected by the pcbinfo lock for the inpcb  * (s) - Protected by another subsystem's locks  * (x) - Undefined locking  *  * A few other notes:  *  * When a read lock is held, stability of the field is guaranteed; to write  * to a field, a write lock must generally be held.  *  * netinet/netinet6-layer code should not assume that the inp_socket pointer  * is safe to dereference without inp_lock being held, even for protocols  * other than TCP (where the inpcb persists during TIMEWAIT even after the  * socket has been freed), or there may be close(2)-related races.  *  * The inp_vflag field is overloaded, and would otherwise ideally be (c).  */
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
comment|/* (i/p) hash list */
name|LIST_ENTRY
argument_list|(
argument|inpcb
argument_list|)
name|inp_list
expr_stmt|;
comment|/* (i/p) list for all PCBs for proto */
name|void
modifier|*
name|inp_ppcb
decl_stmt|;
comment|/* (i) pointer to per-protocol pcb */
name|struct
name|inpcbinfo
modifier|*
name|inp_pcbinfo
decl_stmt|;
comment|/* (c) PCB list info */
name|struct
name|socket
modifier|*
name|inp_socket
decl_stmt|;
comment|/* (i) back pointer to socket */
name|struct
name|ucred
modifier|*
name|inp_cred
decl_stmt|;
comment|/* (c) cache of socket cred */
name|u_int32_t
name|inp_flow
decl_stmt|;
comment|/* (i) IPv6 flow information */
name|int
name|inp_flags
decl_stmt|;
comment|/* (i) generic IP/datagram flags */
name|int
name|inp_flags2
decl_stmt|;
comment|/* (i) generic IP/datagram flags #2*/
name|u_char
name|inp_vflag
decl_stmt|;
comment|/* (i) IP version flag (v4/v6) */
name|u_char
name|inp_ip_ttl
decl_stmt|;
comment|/* (i) time to live proto */
name|u_char
name|inp_ip_p
decl_stmt|;
comment|/* (c) protocol proto */
name|u_char
name|inp_ip_minttl
decl_stmt|;
comment|/* (i) minimum TTL or drop */
name|uint32_t
name|inp_flowid
decl_stmt|;
comment|/* (x) flow id / queue id */
name|u_int
name|inp_refcount
decl_stmt|;
comment|/* (i) refcount */
name|void
modifier|*
name|inp_pspare
index|[
literal|4
index|]
decl_stmt|;
comment|/* (x) rtentry / general use */
name|u_int
name|inp_ispare
index|[
literal|4
index|]
decl_stmt|;
comment|/* general use */
comment|/* Local and foreign ports, local and foreign addr. */
name|struct
name|in_conninfo
name|inp_inc
decl_stmt|;
comment|/* (i/p) list for PCB's local port */
comment|/* MAC and IPSEC policy information. */
name|struct
name|label
modifier|*
name|inp_label
decl_stmt|;
comment|/* (i) MAC label */
name|struct
name|inpcbpolicy
modifier|*
name|inp_sp
decl_stmt|;
comment|/* (s) for IPSEC */
comment|/* Protocol-dependent part; options. */
struct|struct
block|{
name|u_char
name|inp4_ip_tos
decl_stmt|;
comment|/* (i) type of service proto */
name|struct
name|mbuf
modifier|*
name|inp4_options
decl_stmt|;
comment|/* (i) IP options */
name|struct
name|ip_moptions
modifier|*
name|inp4_moptions
decl_stmt|;
comment|/* (i) IP mcast options */
block|}
name|inp_depend4
struct|;
struct|struct
block|{
comment|/* (i) IP options */
name|struct
name|mbuf
modifier|*
name|inp6_options
decl_stmt|;
comment|/* (i) IP6 options for outgoing packets */
name|struct
name|ip6_pktopts
modifier|*
name|inp6_outputopts
decl_stmt|;
comment|/* (i) IP multicast options */
name|struct
name|ip6_moptions
modifier|*
name|inp6_moptions
decl_stmt|;
comment|/* (i) ICMPv6 code type filter */
name|struct
name|icmp6_filter
modifier|*
name|inp6_icmp6filt
decl_stmt|;
comment|/* (i) IPV6_CHECKSUM setsockopt */
name|int
name|inp6_cksum
decl_stmt|;
name|short
name|inp6_hops
decl_stmt|;
block|}
name|inp_depend6
struct|;
name|LIST_ENTRY
argument_list|(
argument|inpcb
argument_list|)
name|inp_portlist
expr_stmt|;
comment|/* (i/p) */
name|struct
name|inpcbport
modifier|*
name|inp_phd
decl_stmt|;
comment|/* (i/p) head of this list */
define|#
directive|define
name|inp_zero_size
value|offsetof(struct inpcb, inp_gencnt)
name|inp_gen_t
name|inp_gencnt
decl_stmt|;
comment|/* (c) generation count */
name|struct
name|llentry
modifier|*
name|inp_lle
decl_stmt|;
comment|/* cached L2 information */
name|struct
name|rtentry
modifier|*
name|inp_rt
decl_stmt|;
comment|/* cached L3 information */
name|struct
name|rwlock
name|inp_lock
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|inp_fport
value|inp_inc.inc_fport
end_define

begin_define
define|#
directive|define
name|inp_lport
value|inp_inc.inc_lport
end_define

begin_define
define|#
directive|define
name|inp_faddr
value|inp_inc.inc_faddr
end_define

begin_define
define|#
directive|define
name|inp_laddr
value|inp_inc.inc_laddr
end_define

begin_define
define|#
directive|define
name|inp_ip_tos
value|inp_depend4.inp4_ip_tos
end_define

begin_define
define|#
directive|define
name|inp_options
value|inp_depend4.inp4_options
end_define

begin_define
define|#
directive|define
name|inp_moptions
value|inp_depend4.inp4_moptions
end_define

begin_define
define|#
directive|define
name|in6p_faddr
value|inp_inc.inc6_faddr
end_define

begin_define
define|#
directive|define
name|in6p_laddr
value|inp_inc.inc6_laddr
end_define

begin_define
define|#
directive|define
name|in6p_hops
value|inp_depend6.inp6_hops
end_define

begin_comment
comment|/* default hop limit */
end_comment

begin_define
define|#
directive|define
name|in6p_flowinfo
value|inp_flow
end_define

begin_define
define|#
directive|define
name|in6p_options
value|inp_depend6.inp6_options
end_define

begin_define
define|#
directive|define
name|in6p_outputopts
value|inp_depend6.inp6_outputopts
end_define

begin_define
define|#
directive|define
name|in6p_moptions
value|inp_depend6.inp6_moptions
end_define

begin_define
define|#
directive|define
name|in6p_icmp6filt
value|inp_depend6.inp6_icmp6filt
end_define

begin_define
define|#
directive|define
name|in6p_cksum
value|inp_depend6.inp6_cksum
end_define

begin_define
define|#
directive|define
name|inp_vnet
value|inp_pcbinfo->ipi_vnet
end_define

begin_comment
comment|/*  * The range of the generation count, as used in this implementation, is 9e19.  * We would have to create 300 billion connections per second for this number  * to roll over in a year.  This seems sufficiently unlikely that we simply  * don't concern ourselves with that possibility.  */
end_comment

begin_comment
comment|/*  * Interface exported to userland by various protocols which use inpcbs.  Hack  * alert -- only define if struct xsocket is in scope.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_SOCKETVAR_H_
end_ifdef

begin_struct
struct|struct
name|xinpcb
block|{
name|size_t
name|xi_len
decl_stmt|;
comment|/* length of this structure */
name|struct
name|inpcb
name|xi_inp
decl_stmt|;
name|struct
name|xsocket
name|xi_socket
decl_stmt|;
name|u_quad_t
name|xi_alignment_hack
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xinpgen
block|{
name|size_t
name|xig_len
decl_stmt|;
comment|/* length of this structure */
name|u_int
name|xig_count
decl_stmt|;
comment|/* number of PCBs at this time */
name|inp_gen_t
name|xig_gen
decl_stmt|;
comment|/* generation count at this time */
name|so_gen_t
name|xig_sogen
decl_stmt|;
comment|/* socket generation count at this time */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SOCKETVAR_H_ */
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

begin_comment
comment|/*  * Global data structure for each high-level protocol (UDP, TCP, ...) in both  * IPv4 and IPv6.  Holds inpcb lists and information for managing them.  */
end_comment

begin_struct
struct|struct
name|inpcbinfo
block|{
comment|/* 	 * Global list of inpcbs on the protocol. 	 */
name|struct
name|inpcbhead
modifier|*
name|ipi_listhead
decl_stmt|;
name|u_int
name|ipi_count
decl_stmt|;
comment|/* 	 * Global hash of inpcbs, hashed by local and foreign addresses and 	 * port numbers. 	 */
name|struct
name|inpcbhead
modifier|*
name|ipi_hashbase
decl_stmt|;
name|u_long
name|ipi_hashmask
decl_stmt|;
comment|/* 	 * Global hash of inpcbs, hashed by only local port number. 	 */
name|struct
name|inpcbporthead
modifier|*
name|ipi_porthashbase
decl_stmt|;
name|u_long
name|ipi_porthashmask
decl_stmt|;
comment|/* 	 * Fields associated with port lookup and allocation. 	 */
name|u_short
name|ipi_lastport
decl_stmt|;
name|u_short
name|ipi_lastlow
decl_stmt|;
name|u_short
name|ipi_lasthi
decl_stmt|;
comment|/* 	 * UMA zone from which inpcbs are allocated for this protocol. 	 */
name|struct
name|uma_zone
modifier|*
name|ipi_zone
decl_stmt|;
comment|/* 	 * Generation count--incremented each time a connection is allocated 	 * or freed. 	 */
name|u_quad_t
name|ipi_gencnt
decl_stmt|;
name|struct
name|rwlock
name|ipi_lock
decl_stmt|;
comment|/* 	 * Pointer to network stack instance 	 */
name|struct
name|vnet
modifier|*
name|ipi_vnet
decl_stmt|;
comment|/* 	 * general use 2 	 */
name|void
modifier|*
name|ipi_pspare
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INP_LOCK_INIT
parameter_list|(
name|inp
parameter_list|,
name|d
parameter_list|,
name|t
parameter_list|)
define|\
value|rw_init_flags(&(inp)->inp_lock, (t), RW_RECURSE |  RW_DUPOK)
end_define

begin_define
define|#
directive|define
name|INP_LOCK_DESTROY
parameter_list|(
name|inp
parameter_list|)
value|rw_destroy(&(inp)->inp_lock)
end_define

begin_define
define|#
directive|define
name|INP_RLOCK
parameter_list|(
name|inp
parameter_list|)
value|rw_rlock(&(inp)->inp_lock)
end_define

begin_define
define|#
directive|define
name|INP_WLOCK
parameter_list|(
name|inp
parameter_list|)
value|rw_wlock(&(inp)->inp_lock)
end_define

begin_define
define|#
directive|define
name|INP_TRY_RLOCK
parameter_list|(
name|inp
parameter_list|)
value|rw_try_rlock(&(inp)->inp_lock)
end_define

begin_define
define|#
directive|define
name|INP_TRY_WLOCK
parameter_list|(
name|inp
parameter_list|)
value|rw_try_wlock(&(inp)->inp_lock)
end_define

begin_define
define|#
directive|define
name|INP_RUNLOCK
parameter_list|(
name|inp
parameter_list|)
value|rw_runlock(&(inp)->inp_lock)
end_define

begin_define
define|#
directive|define
name|INP_WUNLOCK
parameter_list|(
name|inp
parameter_list|)
value|rw_wunlock(&(inp)->inp_lock)
end_define

begin_define
define|#
directive|define
name|INP_TRY_UPGRADE
parameter_list|(
name|inp
parameter_list|)
value|rw_try_upgrade(&(inp)->inp_lock)
end_define

begin_define
define|#
directive|define
name|INP_DOWNGRADE
parameter_list|(
name|inp
parameter_list|)
value|rw_downgrade(&(inp)->inp_lock)
end_define

begin_define
define|#
directive|define
name|INP_WLOCKED
parameter_list|(
name|inp
parameter_list|)
value|rw_wowned(&(inp)->inp_lock)
end_define

begin_define
define|#
directive|define
name|INP_LOCK_ASSERT
parameter_list|(
name|inp
parameter_list|)
value|rw_assert(&(inp)->inp_lock, RA_LOCKED)
end_define

begin_define
define|#
directive|define
name|INP_RLOCK_ASSERT
parameter_list|(
name|inp
parameter_list|)
value|rw_assert(&(inp)->inp_lock, RA_RLOCKED)
end_define

begin_define
define|#
directive|define
name|INP_WLOCK_ASSERT
parameter_list|(
name|inp
parameter_list|)
value|rw_assert(&(inp)->inp_lock, RA_WLOCKED)
end_define

begin_define
define|#
directive|define
name|INP_UNLOCK_ASSERT
parameter_list|(
name|inp
parameter_list|)
value|rw_assert(&(inp)->inp_lock, RA_UNLOCKED)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * These locking functions are for inpcb consumers outside of sys/netinet,  * more specifically, they were added for the benefit of TOE drivers. The  * macros are reserved for use by the stack.  */
end_comment

begin_function_decl
name|void
name|inp_wlock
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inp_wunlock
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inp_rlock
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inp_runlock
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_function_decl
name|void
name|inp_lock_assert
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inp_unlock_assert
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|__inline
name|void
name|inp_lock_assert
parameter_list|(
name|struct
name|inpcb
modifier|*
name|inp
name|__unused
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|void
name|inp_unlock_assert
parameter_list|(
name|struct
name|inpcb
modifier|*
name|inp
name|__unused
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|inp_apply_all
parameter_list|(
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inp_ip_tos_get
parameter_list|(
specifier|const
name|struct
name|inpcb
modifier|*
name|inp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inp_ip_tos_set
parameter_list|(
name|struct
name|inpcb
modifier|*
name|inp
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|socket
modifier|*
name|inp_inpcbtosocket
parameter_list|(
name|struct
name|inpcb
modifier|*
name|inp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcpcb
modifier|*
name|inp_inpcbtotcpcb
parameter_list|(
name|struct
name|inpcb
modifier|*
name|inp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inp_4tuple_get
parameter_list|(
name|struct
name|inpcb
modifier|*
name|inp
parameter_list|,
name|uint32_t
modifier|*
name|laddr
parameter_list|,
name|uint16_t
modifier|*
name|lp
parameter_list|,
name|uint32_t
modifier|*
name|faddr
parameter_list|,
name|uint16_t
modifier|*
name|fp
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

begin_define
define|#
directive|define
name|INP_INFO_LOCK_INIT
parameter_list|(
name|ipi
parameter_list|,
name|d
parameter_list|)
define|\
value|rw_init_flags(&(ipi)->ipi_lock, (d), RW_RECURSE)
end_define

begin_define
define|#
directive|define
name|INP_INFO_LOCK_DESTROY
parameter_list|(
name|ipi
parameter_list|)
value|rw_destroy(&(ipi)->ipi_lock)
end_define

begin_define
define|#
directive|define
name|INP_INFO_RLOCK
parameter_list|(
name|ipi
parameter_list|)
value|rw_rlock(&(ipi)->ipi_lock)
end_define

begin_define
define|#
directive|define
name|INP_INFO_WLOCK
parameter_list|(
name|ipi
parameter_list|)
value|rw_wlock(&(ipi)->ipi_lock)
end_define

begin_define
define|#
directive|define
name|INP_INFO_TRY_RLOCK
parameter_list|(
name|ipi
parameter_list|)
value|rw_try_rlock(&(ipi)->ipi_lock)
end_define

begin_define
define|#
directive|define
name|INP_INFO_TRY_WLOCK
parameter_list|(
name|ipi
parameter_list|)
value|rw_try_wlock(&(ipi)->ipi_lock)
end_define

begin_define
define|#
directive|define
name|INP_INFO_TRY_UPGRADE
parameter_list|(
name|ipi
parameter_list|)
value|rw_try_upgrade(&(ipi)->ipi_lock)
end_define

begin_define
define|#
directive|define
name|INP_INFO_RUNLOCK
parameter_list|(
name|ipi
parameter_list|)
value|rw_runlock(&(ipi)->ipi_lock)
end_define

begin_define
define|#
directive|define
name|INP_INFO_WUNLOCK
parameter_list|(
name|ipi
parameter_list|)
value|rw_wunlock(&(ipi)->ipi_lock)
end_define

begin_define
define|#
directive|define
name|INP_INFO_LOCK_ASSERT
parameter_list|(
name|ipi
parameter_list|)
value|rw_assert(&(ipi)->ipi_lock, RA_LOCKED)
end_define

begin_define
define|#
directive|define
name|INP_INFO_RLOCK_ASSERT
parameter_list|(
name|ipi
parameter_list|)
value|rw_assert(&(ipi)->ipi_lock, RA_RLOCKED)
end_define

begin_define
define|#
directive|define
name|INP_INFO_WLOCK_ASSERT
parameter_list|(
name|ipi
parameter_list|)
value|rw_assert(&(ipi)->ipi_lock, RA_WLOCKED)
end_define

begin_define
define|#
directive|define
name|INP_INFO_UNLOCK_ASSERT
parameter_list|(
name|ipi
parameter_list|)
value|rw_assert(&(ipi)->ipi_lock, RA_UNLOCKED)
end_define

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
comment|/*  * Flags for inp_vflags -- historically version flags only  */
end_comment

begin_define
define|#
directive|define
name|INP_IPV4
value|0x1
end_define

begin_define
define|#
directive|define
name|INP_IPV6
value|0x2
end_define

begin_define
define|#
directive|define
name|INP_IPV6PROTO
value|0x4
end_define

begin_comment
comment|/* opened under IPv6 protocol */
end_comment

begin_comment
comment|/*  * Flags for inp_flags.  */
end_comment

begin_define
define|#
directive|define
name|INP_RECVOPTS
value|0x00000001
end_define

begin_comment
comment|/* receive incoming IP options */
end_comment

begin_define
define|#
directive|define
name|INP_RECVRETOPTS
value|0x00000002
end_define

begin_comment
comment|/* receive IP options for reply */
end_comment

begin_define
define|#
directive|define
name|INP_RECVDSTADDR
value|0x00000004
end_define

begin_comment
comment|/* receive IP dst address */
end_comment

begin_define
define|#
directive|define
name|INP_HDRINCL
value|0x00000008
end_define

begin_comment
comment|/* user supplies entire IP header */
end_comment

begin_define
define|#
directive|define
name|INP_HIGHPORT
value|0x00000010
end_define

begin_comment
comment|/* user wants "high" port binding */
end_comment

begin_define
define|#
directive|define
name|INP_LOWPORT
value|0x00000020
end_define

begin_comment
comment|/* user wants "low" port binding */
end_comment

begin_define
define|#
directive|define
name|INP_ANONPORT
value|0x00000040
end_define

begin_comment
comment|/* port chosen for user */
end_comment

begin_define
define|#
directive|define
name|INP_RECVIF
value|0x00000080
end_define

begin_comment
comment|/* receive incoming interface */
end_comment

begin_define
define|#
directive|define
name|INP_MTUDISC
value|0x00000100
end_define

begin_comment
comment|/* user can do MTU discovery */
end_comment

begin_define
define|#
directive|define
name|INP_FAITH
value|0x00000200
end_define

begin_comment
comment|/* accept FAITH'ed connections */
end_comment

begin_define
define|#
directive|define
name|INP_RECVTTL
value|0x00000400
end_define

begin_comment
comment|/* receive incoming IP TTL */
end_comment

begin_define
define|#
directive|define
name|INP_DONTFRAG
value|0x00000800
end_define

begin_comment
comment|/* don't fragment packet */
end_comment

begin_define
define|#
directive|define
name|INP_BINDANY
value|0x00001000
end_define

begin_comment
comment|/* allow bind to any address */
end_comment

begin_define
define|#
directive|define
name|INP_INHASHLIST
value|0x00002000
end_define

begin_comment
comment|/* in_pcbinshash() has been called */
end_comment

begin_define
define|#
directive|define
name|INP_RECVTOS
value|0x00004000
end_define

begin_comment
comment|/* receive incoming IP TOS */
end_comment

begin_define
define|#
directive|define
name|IN6P_IPV6_V6ONLY
value|0x00008000
end_define

begin_comment
comment|/* restrict AF_INET6 socket for v6 */
end_comment

begin_define
define|#
directive|define
name|IN6P_PKTINFO
value|0x00010000
end_define

begin_comment
comment|/* receive IP6 dst and I/F */
end_comment

begin_define
define|#
directive|define
name|IN6P_HOPLIMIT
value|0x00020000
end_define

begin_comment
comment|/* receive hoplimit */
end_comment

begin_define
define|#
directive|define
name|IN6P_HOPOPTS
value|0x00040000
end_define

begin_comment
comment|/* receive hop-by-hop options */
end_comment

begin_define
define|#
directive|define
name|IN6P_DSTOPTS
value|0x00080000
end_define

begin_comment
comment|/* receive dst options after rthdr */
end_comment

begin_define
define|#
directive|define
name|IN6P_RTHDR
value|0x00100000
end_define

begin_comment
comment|/* receive routing header */
end_comment

begin_define
define|#
directive|define
name|IN6P_RTHDRDSTOPTS
value|0x00200000
end_define

begin_comment
comment|/* receive dstoptions before rthdr */
end_comment

begin_define
define|#
directive|define
name|IN6P_TCLASS
value|0x00400000
end_define

begin_comment
comment|/* receive traffic class value */
end_comment

begin_define
define|#
directive|define
name|IN6P_AUTOFLOWLABEL
value|0x00800000
end_define

begin_comment
comment|/* attach flowlabel automatically */
end_comment

begin_define
define|#
directive|define
name|INP_TIMEWAIT
value|0x01000000
end_define

begin_comment
comment|/* in TIMEWAIT, ppcb is tcptw */
end_comment

begin_define
define|#
directive|define
name|INP_ONESBCAST
value|0x02000000
end_define

begin_comment
comment|/* send all-ones broadcast */
end_comment

begin_define
define|#
directive|define
name|INP_DROPPED
value|0x04000000
end_define

begin_comment
comment|/* protocol drop flag */
end_comment

begin_define
define|#
directive|define
name|INP_SOCKREF
value|0x08000000
end_define

begin_comment
comment|/* strong socket reference */
end_comment

begin_define
define|#
directive|define
name|INP_SW_FLOWID
value|0x10000000
end_define

begin_comment
comment|/* software generated flow id */
end_comment

begin_define
define|#
directive|define
name|INP_HW_FLOWID
value|0x20000000
end_define

begin_comment
comment|/* hardware generated flow id */
end_comment

begin_define
define|#
directive|define
name|IN6P_RFC2292
value|0x40000000
end_define

begin_comment
comment|/* used RFC2292 API on the socket */
end_comment

begin_define
define|#
directive|define
name|IN6P_MTU
value|0x80000000
end_define

begin_comment
comment|/* receive path MTU */
end_comment

begin_define
define|#
directive|define
name|INP_CONTROLOPTS
value|(INP_RECVOPTS|INP_RECVRETOPTS|INP_RECVDSTADDR|\ 				 INP_RECVIF|INP_RECVTTL|INP_RECVTOS|\ 				 IN6P_PKTINFO|IN6P_HOPLIMIT|IN6P_HOPOPTS|\ 				 IN6P_DSTOPTS|IN6P_RTHDR|IN6P_RTHDRDSTOPTS|\ 				 IN6P_TCLASS|IN6P_AUTOFLOWLABEL|IN6P_RFC2292|\ 				 IN6P_MTU)
end_define

begin_comment
comment|/*  * Flags for inp_flags2.  */
end_comment

begin_define
define|#
directive|define
name|INP_LLE_VALID
value|0x00000001
end_define

begin_comment
comment|/* cached lle is valid */
end_comment

begin_define
define|#
directive|define
name|INP_RT_VALID
value|0x00000002
end_define

begin_comment
comment|/* cached rtentry is valid */
end_comment

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

begin_define
define|#
directive|define
name|sotoin6pcb
parameter_list|(
name|so
parameter_list|)
value|sotoinpcb(so)
end_define

begin_comment
comment|/* for KAME src sync over BSD*'s */
end_comment

begin_define
define|#
directive|define
name|INP_SOCKAF
parameter_list|(
name|so
parameter_list|)
value|so->so_proto->pr_domain->dom_family
end_define

begin_define
define|#
directive|define
name|INP_CHECK_SOCKAF
parameter_list|(
name|so
parameter_list|,
name|af
parameter_list|)
value|(INP_SOCKAF(so) == af)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipport_reservedhigh
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipport_reservedlow
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipport_lowfirstauto
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipport_lowlastauto
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipport_firstauto
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipport_lastauto
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipport_hifirstauto
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipport_hilastauto
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipport_randomized
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipport_randomcps
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipport_randomtime
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipport_stoprandom
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VNET_DECLARE
argument_list|(
name|int
argument_list|,
name|ipport_tcpallocs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|V_ipport_reservedhigh
value|VNET(ipport_reservedhigh)
end_define

begin_define
define|#
directive|define
name|V_ipport_reservedlow
value|VNET(ipport_reservedlow)
end_define

begin_define
define|#
directive|define
name|V_ipport_lowfirstauto
value|VNET(ipport_lowfirstauto)
end_define

begin_define
define|#
directive|define
name|V_ipport_lowlastauto
value|VNET(ipport_lowlastauto)
end_define

begin_define
define|#
directive|define
name|V_ipport_firstauto
value|VNET(ipport_firstauto)
end_define

begin_define
define|#
directive|define
name|V_ipport_lastauto
value|VNET(ipport_lastauto)
end_define

begin_define
define|#
directive|define
name|V_ipport_hifirstauto
value|VNET(ipport_hifirstauto)
end_define

begin_define
define|#
directive|define
name|V_ipport_hilastauto
value|VNET(ipport_hilastauto)
end_define

begin_define
define|#
directive|define
name|V_ipport_randomized
value|VNET(ipport_randomized)
end_define

begin_define
define|#
directive|define
name|V_ipport_randomcps
value|VNET(ipport_randomcps)
end_define

begin_define
define|#
directive|define
name|V_ipport_randomtime
value|VNET(ipport_randomtime)
end_define

begin_define
define|#
directive|define
name|V_ipport_stoprandom
value|VNET(ipport_stoprandom)
end_define

begin_define
define|#
directive|define
name|V_ipport_tcpallocs
value|VNET(ipport_tcpallocs)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|callout
name|ipport_tick_callout
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|in_pcbpurgeif0
parameter_list|(
name|struct
name|inpcbinfo
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_pcballoc
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|inpcbinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_pcbbind
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_pcb_lport
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_pcbbind_setup
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|in_addr_t
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_pcbconnect
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_pcbconnect_setup
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|in_addr_t
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|in_addr_t
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in_pcbdetach
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in_pcbdisconnect
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in_pcbdrop
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in_pcbfree
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_pcbinshash
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inpcb
modifier|*
name|in_pcblookup_local
parameter_list|(
name|struct
name|inpcbinfo
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inpcb
modifier|*
name|in_pcblookup_hash
parameter_list|(
name|struct
name|inpcbinfo
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|in_pcbnotifyall
argument_list|(
expr|struct
name|inpcbinfo
operator|*
name|pcbinfo
argument_list|,
expr|struct
name|in_addr
argument_list|,
name|int
argument_list|,
expr|struct
name|inpcb
operator|*
call|(
modifier|*
call|)
argument_list|(
expr|struct
name|inpcb
operator|*
argument_list|,
name|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|in_pcbref
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in_pcbrehash
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_pcbrele
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in_pcbsetsolabel
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
name|in_getpeeraddr
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|nam
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_getsockaddr
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|nam
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sockaddr
modifier|*
name|in_sockaddr
parameter_list|(
name|in_port_t
name|port
parameter_list|,
name|struct
name|in_addr
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|in_pcbsosetlabel
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipport_tick
parameter_list|(
name|void
modifier|*
name|xtp
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
comment|/* !_NETINET_IN_PCB_H_ */
end_comment

end_unit

