begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2007, Cisco Systems, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__sctp_os_bsd_h__
end_ifndef

begin_define
define|#
directive|define
name|__sctp_os_bsd_h__
end_define

begin_comment
comment|/*  * includes  */
end_comment

begin_include
include|#
directive|include
file|"opt_ipsec.h"
end_include

begin_include
include|#
directive|include
file|"opt_compat.h"
end_include

begin_include
include|#
directive|include
file|"opt_inet6.h"
end_include

begin_include
include|#
directive|include
file|"opt_inet.h"
end_include

begin_include
include|#
directive|include
file|"opt_sctp.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<sys/random.h>
end_include

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_icmp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/icmp_var.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IPSEC
end_ifdef

begin_include
include|#
directive|include
file|<netinet6/ipsec.h>
end_include

begin_include
include|#
directive|include
file|<netkey/key.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPSEC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IPSEC
end_ifdef

begin_include
include|#
directive|include
file|<netinet6/ipsec6.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ip6_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/in6_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netinet/icmp6.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ip6protosw.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/nd6.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/scope6_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET6 */
end_comment

begin_include
include|#
directive|include
file|<netinet/ip_options.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|in6pcb
end_ifndef

begin_define
define|#
directive|define
name|in6pcb
value|inpcb
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|USER_ADDR_NULL
value|(NULL)
end_define

begin_comment
comment|/* FIX ME: temp */
end_comment

begin_define
define|#
directive|define
name|SCTP_LIST_EMPTY
parameter_list|(
name|list
parameter_list|)
value|LIST_EMPTY(list)
end_define

begin_comment
comment|/*  * Local address and interface list handling  */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_VRF_ID
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_SIZE_OF_VRF_HASH
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_IFNAMSIZ
value|IFNAMSIZ
end_define

begin_define
define|#
directive|define
name|SCTP_DEFAULT_VRFID
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_VRF_HASH_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|SCTP_IFN_IS_IFT_LOOP
parameter_list|(
name|ifn
parameter_list|)
value|((ifn)->ifn_type == IFT_LOOP)
end_define

begin_comment
comment|/*  * Access to IFN's to help with src-addr-selection  */
end_comment

begin_comment
comment|/* This could return VOID if the index works but for BSD we provide both. */
end_comment

begin_define
define|#
directive|define
name|SCTP_GET_IFN_VOID_FROM_ROUTE
parameter_list|(
name|ro
parameter_list|)
value|(void *)ro->ro_rt->rt_ifp
end_define

begin_define
define|#
directive|define
name|SCTP_GET_IF_INDEX_FROM_ROUTE
parameter_list|(
name|ro
parameter_list|)
value|ro->ro_rt->rt_ifp->if_index
end_define

begin_comment
comment|/*  * general memory allocation  */
end_comment

begin_define
define|#
directive|define
name|SCTP_MALLOC
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|,
name|size
parameter_list|,
name|name
parameter_list|)
define|\
value|do { \ 	MALLOC(var, type, size, M_PCB, M_NOWAIT); \     } while (0)
end_define

begin_define
define|#
directive|define
name|SCTP_FREE
parameter_list|(
name|var
parameter_list|)
value|FREE(var, M_PCB)
end_define

begin_define
define|#
directive|define
name|SCTP_MALLOC_SONAME
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|,
name|size
parameter_list|)
define|\
value|do { \ 	MALLOC(var, type, size, M_SONAME, M_WAITOK | M_ZERO); \     } while (0)
end_define

begin_define
define|#
directive|define
name|SCTP_FREE_SONAME
parameter_list|(
name|var
parameter_list|)
value|FREE(var, M_SONAME)
end_define

begin_define
define|#
directive|define
name|SCTP_PROCESS_STRUCT
value|struct proc *
end_define

begin_comment
comment|/*  * zone allocation functions  */
end_comment

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_comment
comment|/* SCTP_ZONE_INIT: initialize the zone */
end_comment

begin_typedef
typedef|typedef
name|struct
name|uma_zone
modifier|*
name|sctp_zone_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UMA_ZFLAG_FULL
value|0x0020
end_define

begin_define
define|#
directive|define
name|SCTP_ZONE_INIT
parameter_list|(
name|zone
parameter_list|,
name|name
parameter_list|,
name|size
parameter_list|,
name|number
parameter_list|)
value|{ \ 	zone = uma_zcreate(name, size, NULL, NULL, NULL, NULL, UMA_ALIGN_PTR,\ 		UMA_ZFLAG_FULL); \ 	uma_zone_set_max(zone, number); \ }
end_define

begin_comment
comment|/* SCTP_ZONE_GET: allocate element from the zone */
end_comment

begin_define
define|#
directive|define
name|SCTP_ZONE_GET
parameter_list|(
name|zone
parameter_list|,
name|type
parameter_list|)
define|\
value|(type *)uma_zalloc(zone, M_NOWAIT);
end_define

begin_comment
comment|/* SCTP_ZONE_FREE: free element from the zone */
end_comment

begin_define
define|#
directive|define
name|SCTP_ZONE_FREE
parameter_list|(
name|zone
parameter_list|,
name|element
parameter_list|)
define|\
value|uma_zfree(zone, element);
end_define

begin_define
define|#
directive|define
name|SCTP_HASH_INIT
parameter_list|(
name|size
parameter_list|,
name|hashmark
parameter_list|)
value|hashinit_flags(size, M_PCB, hashmark, HASH_NOWAIT)
end_define

begin_define
define|#
directive|define
name|SCTP_HASH_FREE
parameter_list|(
name|table
parameter_list|,
name|hashmark
parameter_list|)
value|hashdestroy(table, M_PCB, hashmark)
end_define

begin_define
define|#
directive|define
name|SCTP_M_COPYM
value|m_copym
end_define

begin_comment
comment|/*  * timers  */
end_comment

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|callout
name|sctp_os_timer_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SCTP_OS_TIMER_INIT
parameter_list|(
name|tmr
parameter_list|)
value|callout_init(tmr, 1)
end_define

begin_define
define|#
directive|define
name|SCTP_OS_TIMER_START
value|callout_reset
end_define

begin_define
define|#
directive|define
name|SCTP_OS_TIMER_STOP
value|callout_stop
end_define

begin_define
define|#
directive|define
name|SCTP_OS_TIMER_STOP_DRAIN
value|callout_drain
end_define

begin_define
define|#
directive|define
name|SCTP_OS_TIMER_PENDING
value|callout_pending
end_define

begin_define
define|#
directive|define
name|SCTP_OS_TIMER_ACTIVE
value|callout_active
end_define

begin_define
define|#
directive|define
name|SCTP_OS_TIMER_DEACTIVATE
value|callout_deactivate
end_define

begin_comment
comment|/*  * Functions  */
end_comment

begin_comment
comment|/* Mbuf manipulation and access macros  */
end_comment

begin_define
define|#
directive|define
name|SCTP_BUF_LEN
parameter_list|(
name|m
parameter_list|)
value|(m->m_len)
end_define

begin_define
define|#
directive|define
name|SCTP_BUF_NEXT
parameter_list|(
name|m
parameter_list|)
value|(m->m_next)
end_define

begin_define
define|#
directive|define
name|SCTP_BUF_NEXT_PKT
parameter_list|(
name|m
parameter_list|)
value|(m->m_nextpkt)
end_define

begin_define
define|#
directive|define
name|SCTP_BUF_RESV_UF
parameter_list|(
name|m
parameter_list|,
name|size
parameter_list|)
value|m->m_data += size
end_define

begin_define
define|#
directive|define
name|SCTP_BUF_AT
parameter_list|(
name|m
parameter_list|,
name|size
parameter_list|)
value|m->m_data + size
end_define

begin_define
define|#
directive|define
name|SCTP_BUF_IS_EXTENDED
parameter_list|(
name|m
parameter_list|)
value|(m->m_flags& M_EXT)
end_define

begin_define
define|#
directive|define
name|SCTP_BUF_EXTEND_SIZE
parameter_list|(
name|m
parameter_list|)
value|(m->m_ext.ext_size)
end_define

begin_define
define|#
directive|define
name|SCTP_BUF_TYPE
parameter_list|(
name|m
parameter_list|)
value|(m->m_type)
end_define

begin_define
define|#
directive|define
name|SCTP_BUF_RECVIF
parameter_list|(
name|m
parameter_list|)
value|(m->m_pkthdr.rcvif)
end_define

begin_define
define|#
directive|define
name|SCTP_BUF_PREPEND
value|M_PREPEND
end_define

begin_comment
comment|/*************************/
end_comment

begin_comment
comment|/* These are for logging */
end_comment

begin_comment
comment|/*************************/
end_comment

begin_comment
comment|/* return the base ext data pointer */
end_comment

begin_define
define|#
directive|define
name|SCTP_BUF_EXTEND_BASE
parameter_list|(
name|m
parameter_list|)
value|(m->m_ext.ext_buf)
end_define

begin_comment
comment|/* return the refcnt of the data pointer */
end_comment

begin_define
define|#
directive|define
name|SCTP_BUF_EXTEND_REFCNT
parameter_list|(
name|m
parameter_list|)
value|(*m->m_ext.ref_cnt)
end_define

begin_comment
comment|/* return any buffer related flags, this is  * used beyond logging for apple only.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_BUF_GET_FLAGS
parameter_list|(
name|m
parameter_list|)
value|(m->m_flags)
end_define

begin_comment
comment|/* For BSD this just accesses the M_PKTHDR length  * so it operates on an mbuf with hdr flag. Other  * O/S's may have seperate packet header and mbuf  * chain pointers.. thus the macro.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_HEADER_TO_CHAIN
parameter_list|(
name|m
parameter_list|)
value|(m)
end_define

begin_define
define|#
directive|define
name|SCTP_HEADER_LEN
parameter_list|(
name|m
parameter_list|)
value|(m->m_pkthdr.len)
end_define

begin_define
define|#
directive|define
name|SCTP_GET_HEADER_FOR_OUTPUT
parameter_list|(
name|len
parameter_list|)
value|sctp_get_mbuf_for_msg(len, 1, M_DONTWAIT, 1, MT_DATA)
end_define

begin_comment
comment|/* Attach the chain of data into the sendable packet. */
end_comment

begin_define
define|#
directive|define
name|SCTP_ATTACH_CHAIN
parameter_list|(
name|pak
parameter_list|,
name|m
parameter_list|,
name|packet_length
parameter_list|)
value|do { \                                                  pak->m_next = m; \                                                  pak->m_pkthdr.len = packet_length; \                          } while(0)
end_define

begin_comment
comment|/* Other m_pkthdr type things */
end_comment

begin_define
define|#
directive|define
name|SCTP_IS_IT_BROADCAST
parameter_list|(
name|dst
parameter_list|,
name|m
parameter_list|)
value|in_broadcast(dst, m->m_pkthdr.rcvif)
end_define

begin_define
define|#
directive|define
name|SCTP_IS_IT_LOOPBACK
parameter_list|(
name|m
parameter_list|)
value|((m->m_pkthdr.rcvif == NULL) ||(m->m_pkthdr.rcvif->if_type == IFT_LOOP))
end_define

begin_comment
comment|/* This converts any input packet header  * into the chain of data holders, for BSD  * its a NOP.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_PAK_TO_BUF
parameter_list|(
name|i_pak
parameter_list|)
value|(i_pak)
end_define

begin_comment
comment|/* Macro's for getting length from V6/V4 header */
end_comment

begin_define
define|#
directive|define
name|SCTP_GET_IPV4_LENGTH
parameter_list|(
name|iph
parameter_list|)
value|(iph->ip_len)
end_define

begin_define
define|#
directive|define
name|SCTP_GET_IPV6_LENGTH
parameter_list|(
name|ip6
parameter_list|)
value|(ntohs(ip6->ip6_plen))
end_define

begin_comment
comment|/* is the endpoint v6only? */
end_comment

begin_define
define|#
directive|define
name|SCTP_IPV6_V6ONLY
parameter_list|(
name|inp
parameter_list|)
value|(((struct inpcb *)inp)->inp_flags& IN6P_IPV6_V6ONLY)
end_define

begin_comment
comment|/* is the socket non-blocking? */
end_comment

begin_define
define|#
directive|define
name|SCTP_SO_IS_NBIO
parameter_list|(
name|so
parameter_list|)
value|((so)->so_state& SS_NBIO)
end_define

begin_define
define|#
directive|define
name|SCTP_SET_SO_NBIO
parameter_list|(
name|so
parameter_list|)
value|((so)->so_state |= SS_NBIO)
end_define

begin_define
define|#
directive|define
name|SCTP_CLEAR_SO_NBIO
parameter_list|(
name|so
parameter_list|)
value|((so)->so_state&= ~SS_NBIO)
end_define

begin_comment
comment|/* get the socket type */
end_comment

begin_define
define|#
directive|define
name|SCTP_SO_TYPE
parameter_list|(
name|so
parameter_list|)
value|((so)->so_type)
end_define

begin_comment
comment|/* reserve sb space for a socket */
end_comment

begin_define
define|#
directive|define
name|SCTP_SORESERVE
parameter_list|(
name|so
parameter_list|,
name|send
parameter_list|,
name|recv
parameter_list|)
value|soreserve(so, send, recv)
end_define

begin_comment
comment|/* clear the socket buffer state */
end_comment

begin_define
define|#
directive|define
name|SCTP_SB_CLEAR
parameter_list|(
name|sb
parameter_list|)
define|\
value|(sb).sb_cc = 0;		\ 	(sb).sb_mb = NULL;	\ 	(sb).sb_mbcnt = 0;
end_define

begin_define
define|#
directive|define
name|SCTP_SB_LIMIT_RCV
parameter_list|(
name|so
parameter_list|)
value|so->so_rcv.sb_hiwat
end_define

begin_define
define|#
directive|define
name|SCTP_SB_LIMIT_SND
parameter_list|(
name|so
parameter_list|)
value|so->so_snd.sb_hiwat
end_define

begin_comment
comment|/*  * SCTP AUTH  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SHA2
end_define

begin_define
define|#
directive|define
name|SCTP_READ_RANDOM
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|)
value|read_random(buf, len)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SCTP_SHA1
end_ifdef

begin_include
include|#
directive|include
file|<netinet/sctp_sha1.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<crypto/sha1.h>
end_include

begin_comment
comment|/* map standard crypto API names */
end_comment

begin_define
define|#
directive|define
name|SHA1_Init
value|SHA1Init
end_define

begin_define
define|#
directive|define
name|SHA1_Update
value|SHA1Update
end_define

begin_define
define|#
directive|define
name|SHA1_Final
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|SHA1Final((caddr_t)x, y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SHA2
argument_list|)
end_if

begin_include
include|#
directive|include
file|<crypto/sha2/sha2.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/md5.h>
end_include

begin_comment
comment|/* map standard crypto API names */
end_comment

begin_define
define|#
directive|define
name|MD5_Init
value|MD5Init
end_define

begin_define
define|#
directive|define
name|MD5_Update
value|MD5Update
end_define

begin_define
define|#
directive|define
name|MD5_Final
value|MD5Final
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

