begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2007, by Cisco Systems, Inc. All rights reserved.  * Copyright (c) 2008-2012, by Randall Stewart. All rights reserved.  * Copyright (c) 2008-2012, by Michael Tuexen. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
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
name|_NETINET_SCTP_OS_BSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_SCTP_OS_BSD_H_
end_define

begin_comment
comment|/*  * includes  */
end_comment

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
file|<sys/ktr.h>
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
file|<sys/jail.h>
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
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/rwlock.h>
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
file|<net/vnet.h>
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
name|INET6
end_ifdef

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

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

begin_include
include|#
directive|include
file|<crypto/sha1.h>
end_include

begin_include
include|#
directive|include
file|<crypto/sha2/sha256.h>
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
comment|/* Declare all the malloc names for all the various mallocs */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_MAP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_STRMI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_STRMO
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_ASC_ADDR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_ASC_IT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_AUTH_CL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_AUTH_KY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_AUTH_HL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_AUTH_IF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_STRESET
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_CMSG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_COPYAL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_VRF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_IFA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_IFN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_TIMW
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_MVRF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_ITER
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_SOCKOPT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|SCTP_M_MCORE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SCTP_LOCAL_TRACE_BUF
argument_list|)
end_if

begin_define
define|#
directive|define
name|SCTP_GET_CYCLECOUNT
value|get_cyclecount()
end_define

begin_define
define|#
directive|define
name|SCTP_CTR6
value|sctp_log_trace
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCTP_CTR6
value|CTR6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macros to expand out globals defined by various modules  * to either a real global or a virtualized instance of one,  * depending on whether VIMAGE is defined.  */
end_comment

begin_comment
comment|/* then define the macro(s) that hook into the vimage macros */
end_comment

begin_define
define|#
directive|define
name|MODULE_GLOBAL
parameter_list|(
name|__SYMBOL
parameter_list|)
value|V_##__SYMBOL
end_define

begin_define
define|#
directive|define
name|V_system_base_info
value|VNET(system_base_info)
end_define

begin_define
define|#
directive|define
name|SCTP_BASE_INFO
parameter_list|(
name|__m
parameter_list|)
value|V_system_base_info.sctppcbinfo.__m
end_define

begin_define
define|#
directive|define
name|SCTP_BASE_STATS
value|V_system_base_info.sctpstat
end_define

begin_define
define|#
directive|define
name|SCTP_BASE_STAT
parameter_list|(
name|__m
parameter_list|)
value|V_system_base_info.sctpstat.__m
end_define

begin_define
define|#
directive|define
name|SCTP_BASE_SYSCTL
parameter_list|(
name|__m
parameter_list|)
value|V_system_base_info.sctpsysctl.__m
end_define

begin_define
define|#
directive|define
name|SCTP_BASE_VAR
parameter_list|(
name|__m
parameter_list|)
value|V_system_base_info.__m
end_define

begin_define
define|#
directive|define
name|SCTP_PRINTF
parameter_list|(
name|params
modifier|...
parameter_list|)
value|printf(params)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SCTP_DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|SCTPDBG
parameter_list|(
name|level
parameter_list|,
name|params
modifier|...
parameter_list|)
define|\
value|{									\ 	do {								\ 		if (SCTP_BASE_SYSCTL(sctp_debug_on)& level ) {		\ 			SCTP_PRINTF(params);				\ 		}							\ 	} while (0);							\ }
end_define

begin_define
define|#
directive|define
name|SCTPDBG_ADDR
parameter_list|(
name|level
parameter_list|,
name|addr
parameter_list|)
define|\
value|{									\ 	do {								\ 		if (SCTP_BASE_SYSCTL(sctp_debug_on)& level ) {		\ 			sctp_print_address(addr);			\ 		}							\ 	} while (0);							\ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCTPDBG
parameter_list|(
name|level
parameter_list|,
name|params
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SCTPDBG_ADDR
parameter_list|(
name|level
parameter_list|,
name|addr
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCTP_LTRACE_CHUNKS
end_ifdef

begin_define
define|#
directive|define
name|SCTP_LTRACE_CHK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|if(SCTP_BASE_SYSCTL(sctp_logging_level)& SCTP_LTRACE_CHUNK_ENABLE) SCTP_CTR6(KTR_SUBSYS, "SCTP:%d[%d]:%x-%x-%x-%x", SCTP_LOG_CHUNK_PROC, 0, a, b, c, d)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCTP_LTRACE_CHK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SCTP_LTRACE_ERRORS
end_ifdef

begin_define
define|#
directive|define
name|SCTP_LTRACE_ERR_RET_PKT
parameter_list|(
name|m
parameter_list|,
name|inp
parameter_list|,
name|stcb
parameter_list|,
name|net
parameter_list|,
name|file
parameter_list|,
name|err
parameter_list|)
define|\
value|if (SCTP_BASE_SYSCTL(sctp_logging_level)& SCTP_LTRACE_ERROR_ENABLE) \ 		SCTP_PRINTF("mbuf:%p inp:%p stcb:%p net:%p file:%x line:%d error:%d\n", \ 		            m, inp, stcb, net, file, __LINE__, err);
end_define

begin_define
define|#
directive|define
name|SCTP_LTRACE_ERR_RET
parameter_list|(
name|inp
parameter_list|,
name|stcb
parameter_list|,
name|net
parameter_list|,
name|file
parameter_list|,
name|err
parameter_list|)
define|\
value|if (SCTP_BASE_SYSCTL(sctp_logging_level)& SCTP_LTRACE_ERROR_ENABLE) \ 		SCTP_PRINTF("inp:%p stcb:%p net:%p file:%x line:%d error:%d\n", \ 		            inp, stcb, net, file, __LINE__, err);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCTP_LTRACE_ERR_RET_PKT
parameter_list|(
name|m
parameter_list|,
name|inp
parameter_list|,
name|stcb
parameter_list|,
name|net
parameter_list|,
name|file
parameter_list|,
name|err
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SCTP_LTRACE_ERR_RET
parameter_list|(
name|inp
parameter_list|,
name|stcb
parameter_list|,
name|net
parameter_list|,
name|file
parameter_list|,
name|err
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|SCTP_VRF_ADDR_HASH_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|SCTP_VRF_IFN_HASH_SIZE
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_INIT_VRF_TABLEID
parameter_list|(
name|vrf
parameter_list|)
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

begin_define
define|#
directive|define
name|SCTP_ROUTE_IS_REAL_LOOP
parameter_list|(
name|ro
parameter_list|)
value|((ro)->ro_rt&& (ro)->ro_rt->rt_ifa&& (ro)->ro_rt->rt_ifa->ifa_ifp&& (ro)->ro_rt->rt_ifa->ifa_ifp->if_type == IFT_LOOP)
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
value|(ro)->ro_rt->rt_ifp->if_index
end_define

begin_define
define|#
directive|define
name|SCTP_ROUTE_HAS_VALID_IFN
parameter_list|(
name|ro
parameter_list|)
value|((ro)->ro_rt&& (ro)->ro_rt->rt_ifp)
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
value|do { \ 		var = (type)malloc(size, name, M_NOWAIT); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|SCTP_FREE
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|)
value|free(var, type)
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
value|do { \ 		var = (type)malloc(size, M_SONAME, M_WAITOK | M_ZERO); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|SCTP_FREE_SONAME
parameter_list|(
name|var
parameter_list|)
value|free(var, M_SONAME)
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
value|{ \ 	zone = uma_zcreate(name, size, NULL, NULL, NULL, NULL, UMA_ALIGN_PTR,\ 		0); \ 	uma_zone_set_max(zone, number); \ }
end_define

begin_define
define|#
directive|define
name|SCTP_ZONE_DESTROY
parameter_list|(
name|zone
parameter_list|)
value|uma_zdestroy(zone)
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

begin_define
define|#
directive|define
name|sctp_get_tick_count
parameter_list|()
value|(ticks)
end_define

begin_define
define|#
directive|define
name|SCTP_UNUSED
value|__attribute__((unused))
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
name|SCTP_BUF_SIZE
value|M_SIZE
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

begin_define
define|#
directive|define
name|SCTP_ALIGN_TO_END
parameter_list|(
name|m
parameter_list|,
name|len
parameter_list|)
value|M_ALIGN(m, len)
end_define

begin_comment
comment|/* We make it so if you have up to 4 threads  * writing based on the default size of  * the packet log 65 k, that would be  * 4 16k packets before we would hit  * a problem.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_PKTLOG_WRITERS_NEED_LOCK
value|3
end_define

begin_comment
comment|/*************************/
end_comment

begin_comment
comment|/*      MTU              */
end_comment

begin_comment
comment|/*************************/
end_comment

begin_define
define|#
directive|define
name|SCTP_GATHER_MTU_FROM_IFN_INFO
parameter_list|(
name|ifn
parameter_list|,
name|ifn_index
parameter_list|,
name|af
parameter_list|)
value|((struct ifnet *)ifn)->if_mtu
end_define

begin_define
define|#
directive|define
name|SCTP_GATHER_MTU_FROM_ROUTE
parameter_list|(
name|sctp_ifa
parameter_list|,
name|sa
parameter_list|,
name|rt
parameter_list|)
value|((uint32_t)((rt != NULL) ? rt->rt_mtu : 0))
end_define

begin_define
define|#
directive|define
name|SCTP_GATHER_MTU_FROM_INTFC
parameter_list|(
name|sctp_ifn
parameter_list|)
value|((sctp_ifn->ifn_p != NULL) ? ((struct ifnet *)(sctp_ifn->ifn_p))->if_mtu : 0)
end_define

begin_define
define|#
directive|define
name|SCTP_SET_MTU_OF_ROUTE
parameter_list|(
name|sa
parameter_list|,
name|rt
parameter_list|,
name|mtu
parameter_list|)
value|do { \                                               if (rt != NULL) \                                                  rt->rt_mtu = mtu; \                                            } while(0)
end_define

begin_comment
comment|/* (de-)register interface event notifications */
end_comment

begin_define
define|#
directive|define
name|SCTP_REGISTER_INTERFACE
parameter_list|(
name|ifhandle
parameter_list|,
name|af
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SCTP_DEREGISTER_INTERFACE
parameter_list|(
name|ifhandle
parameter_list|,
name|af
parameter_list|)
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
value|(*m->m_ext.ext_cnt)
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
comment|/* For BSD this just accesses the M_PKTHDR length  * so it operates on an mbuf with hdr flag. Other  * O/S's may have separate packet header and mbuf  * chain pointers.. thus the macro.  */
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
name|SCTP_DETACH_HEADER_FROM_CHAIN
parameter_list|(
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SCTP_HEADER_LEN
parameter_list|(
name|m
parameter_list|)
value|((m)->m_pkthdr.len)
end_define

begin_define
define|#
directive|define
name|SCTP_GET_HEADER_FOR_OUTPUT
parameter_list|(
name|o_pak
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_RELEASE_HEADER
parameter_list|(
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SCTP_RELEASE_PKT
parameter_list|(
name|m
parameter_list|)
value|sctp_m_freem(m)
end_define

begin_define
define|#
directive|define
name|SCTP_ENABLE_UDP_CSUM
parameter_list|(
name|m
parameter_list|)
value|do { \ 					m->m_pkthdr.csum_flags = CSUM_UDP; \ 					m->m_pkthdr.csum_data = offsetof(struct udphdr, uh_sum); \ 				} while (0)
end_define

begin_define
define|#
directive|define
name|SCTP_GET_PKT_VRFID
parameter_list|(
name|m
parameter_list|,
name|vrf_id
parameter_list|)
value|((vrf_id = SCTP_DEFAULT_VRFID) != SCTP_DEFAULT_VRFID)
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
value|do { \                                                  pak = m; \                                                  pak->m_pkthdr.len = packet_length; \                          } while(0)
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
value|((m->m_flags& M_PKTHDR) ? in_broadcast(dst, m->m_pkthdr.rcvif) : 0)
end_define

begin_define
define|#
directive|define
name|SCTP_IS_IT_LOOPBACK
parameter_list|(
name|m
parameter_list|)
value|((m->m_flags& M_PKTHDR)&& ((m->m_pkthdr.rcvif == NULL) || (m->m_pkthdr.rcvif->if_type == IFT_LOOP)))
end_define

begin_comment
comment|/* This converts any input packet header  * into the chain of data holders, for BSD  * its a NOP.  */
end_comment

begin_comment
comment|/* get the v6 hop limit */
end_comment

begin_define
define|#
directive|define
name|SCTP_GET_HLIM
parameter_list|(
name|inp
parameter_list|,
name|ro
parameter_list|)
value|in6_selecthlim((struct in6pcb *)&inp->ip_inp.inp, (ro ? (ro->ro_rt ? (ro->ro_rt->rt_ifp) : (NULL)) : (NULL)));
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
comment|/* Use a macro for renaming sb_cc to sb_acc.  * Initially sb_ccc was used, but this broke select() when used  * with SCTP sockets.  */
end_comment

begin_define
define|#
directive|define
name|sb_cc
value|sb_acc
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
comment|/* wakeup a socket */
end_comment

begin_define
define|#
directive|define
name|SCTP_SOWAKEUP
parameter_list|(
name|so
parameter_list|)
value|wakeup(&(so)->so_timeo)
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
comment|/*  * routes, output, etc.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|route
name|sctp_route_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|rtentry
name|sctp_rtentry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SCTP_RTALLOC
parameter_list|(
name|ro
parameter_list|,
name|vrf_id
parameter_list|,
name|fibnum
parameter_list|)
define|\
value|rtalloc_ign_fib((struct route *)ro, 0UL, fibnum)
end_define

begin_comment
comment|/* Future zero copy wakeup/send  function */
end_comment

begin_define
define|#
directive|define
name|SCTP_ZERO_COPY_EVENT
parameter_list|(
name|inp
parameter_list|,
name|so
parameter_list|)
end_define

begin_comment
comment|/* This is re-pulse ourselves for sendbuf */
end_comment

begin_define
define|#
directive|define
name|SCTP_ZERO_COPY_SENDQ_EVENT
parameter_list|(
name|inp
parameter_list|,
name|so
parameter_list|)
end_define

begin_comment
comment|/*  * SCTP protocol specific mbuf flags.  */
end_comment

begin_define
define|#
directive|define
name|M_NOTIFICATION
value|M_PROTO1
end_define

begin_comment
comment|/* SCTP notification */
end_comment

begin_comment
comment|/*  * IP output routines  */
end_comment

begin_define
define|#
directive|define
name|SCTP_IP_OUTPUT
parameter_list|(
name|result
parameter_list|,
name|o_pak
parameter_list|,
name|ro
parameter_list|,
name|stcb
parameter_list|,
name|vrf_id
parameter_list|)
define|\
value|{ \ 	int o_flgs = IP_RAWOUTPUT; \ 	struct sctp_tcb *local_stcb = stcb; \ 	if (local_stcb&& \ 	    local_stcb->sctp_ep&& \ 	    local_stcb->sctp_ep->sctp_socket) \ 		o_flgs |= local_stcb->sctp_ep->sctp_socket->so_options& SO_DONTROUTE; \ 	m_clrprotoflags(o_pak); \ 	result = ip_output(o_pak, NULL, ro, o_flgs, 0, NULL); \ }
end_define

begin_define
define|#
directive|define
name|SCTP_IP6_OUTPUT
parameter_list|(
name|result
parameter_list|,
name|o_pak
parameter_list|,
name|ro
parameter_list|,
name|ifp
parameter_list|,
name|stcb
parameter_list|,
name|vrf_id
parameter_list|)
define|\
value|{ \ 	struct sctp_tcb *local_stcb = stcb; \ 	m_clrprotoflags(o_pak); \ 	if (local_stcb&& local_stcb->sctp_ep) \ 		result = ip6_output(o_pak, \ 				    ((struct in6pcb *)(local_stcb->sctp_ep))->in6p_outputopts, \ 				    (ro), 0, 0, ifp, NULL); \ 	else \ 		result = ip6_output(o_pak, NULL, (ro), 0, 0, ifp, NULL); \ }
end_define

begin_function_decl
name|struct
name|mbuf
modifier|*
name|sctp_get_mbuf_for_msg
parameter_list|(
name|unsigned
name|int
name|space_needed
parameter_list|,
name|int
name|want_header
parameter_list|,
name|int
name|how
parameter_list|,
name|int
name|allonebuf
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * SCTP AUTH  */
end_comment

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

begin_comment
comment|/* map standard crypto API names */
end_comment

begin_define
define|#
directive|define
name|SCTP_SHA1_CTX
value|SHA1_CTX
end_define

begin_define
define|#
directive|define
name|SCTP_SHA1_INIT
value|SHA1Init
end_define

begin_define
define|#
directive|define
name|SCTP_SHA1_UPDATE
value|SHA1Update
end_define

begin_define
define|#
directive|define
name|SCTP_SHA1_FINAL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|SHA1Final((caddr_t)x, y)
end_define

begin_define
define|#
directive|define
name|SCTP_SHA256_CTX
value|SHA256_CTX
end_define

begin_define
define|#
directive|define
name|SCTP_SHA256_INIT
value|SHA256_Init
end_define

begin_define
define|#
directive|define
name|SCTP_SHA256_UPDATE
value|SHA256_Update
end_define

begin_define
define|#
directive|define
name|SCTP_SHA256_FINAL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|SHA256_Final((caddr_t)x, y)
end_define

begin_define
define|#
directive|define
name|SCTP_DECREMENT_AND_CHECK_REFCOUNT
parameter_list|(
name|addr
parameter_list|)
value|(atomic_fetchadd_int(addr, -1) == 1)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|SCTP_SAVE_ATOMIC_DECREMENT
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|{ \ 	int32_t oldval; \ 	oldval = atomic_fetchadd_int(addr, -val); \ 	if (oldval< val) { \ 		panic("Counter goes negative"); \ 	} \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCTP_SAVE_ATOMIC_DECREMENT
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|{ \ 	int32_t oldval; \ 	oldval = atomic_fetchadd_int(addr, -val); \ 	if (oldval< val) { \ 		*addr = 0; \ 	} \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCTP_IS_LISTENING
parameter_list|(
name|inp
parameter_list|)
value|((inp->sctp_flags& SCTP_PCB_FLAGS_ACCEPTING) != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

