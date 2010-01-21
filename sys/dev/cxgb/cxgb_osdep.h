begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2007-2008, Chelsio Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Neither the name of the Chelsio Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   $FreeBSD$  ***************************************************************************/
end_comment

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
file|<sys/ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/mii.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DEFINED
end_ifdef

begin_include
include|#
directive|include
file|<common/cxgb_version.h>
end_include

begin_include
include|#
directive|include
file|<cxgb_config.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<dev/cxgb/common/cxgb_version.h>
end_include

begin_include
include|#
directive|include
file|<dev/cxgb/cxgb_config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_CXGB_OSDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_CXGB_OSDEP_H_
end_define

begin_typedef
typedef|typedef
name|struct
name|adapter
name|adapter_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|port_info
name|pinfo_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|sge_rspq
struct_decl|;
end_struct_decl

begin_enum
enum|enum
block|{
name|TP_TMR_RES
init|=
literal|200
block|,
comment|/* TP timer resolution in usec */
name|MAX_NPORTS
init|=
literal|4
block|,
comment|/* max # of ports */
name|TP_SRAM_OFFSET
init|=
literal|4096
block|,
comment|/* TP SRAM content offset in eeprom */
name|TP_SRAM_LEN
init|=
literal|2112
block|,
comment|/* TP SRAM content offset in eeprom */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|t3_mbuf_hdr
block|{
name|struct
name|mbuf
modifier|*
name|mh_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mh_tail
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|PANIC_IF
end_ifndef

begin_define
define|#
directive|define
name|PANIC_IF
parameter_list|(
name|exp
parameter_list|)
value|do {                  \ 	if (exp)                            \ 		panic("BUG: %s", #exp);      \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|m_get_priority
parameter_list|(
name|m
parameter_list|)
value|((uintptr_t)(m)->m_pkthdr.rcvif)
end_define

begin_define
define|#
directive|define
name|m_set_priority
parameter_list|(
name|m
parameter_list|,
name|pri
parameter_list|)
value|((m)->m_pkthdr.rcvif = (struct ifnet *)((uintptr_t)pri))
end_define

begin_define
define|#
directive|define
name|m_set_sgl
parameter_list|(
name|m
parameter_list|,
name|sgl
parameter_list|)
value|((m)->m_pkthdr.header = (sgl))
end_define

begin_define
define|#
directive|define
name|m_get_sgl
parameter_list|(
name|m
parameter_list|)
value|((bus_dma_segment_t *)(m)->m_pkthdr.header)
end_define

begin_define
define|#
directive|define
name|m_set_sgllen
parameter_list|(
name|m
parameter_list|,
name|len
parameter_list|)
value|((m)->m_pkthdr.ether_vtag = len)
end_define

begin_define
define|#
directive|define
name|m_get_sgllen
parameter_list|(
name|m
parameter_list|)
value|((m)->m_pkthdr.ether_vtag)
end_define

begin_comment
comment|/*  * XXX FIXME  */
end_comment

begin_define
define|#
directive|define
name|m_set_toep
parameter_list|(
name|m
parameter_list|,
name|a
parameter_list|)
value|((m)->m_pkthdr.header = (a))
end_define

begin_define
define|#
directive|define
name|m_get_toep
parameter_list|(
name|m
parameter_list|)
value|((m)->m_pkthdr.header)
end_define

begin_define
define|#
directive|define
name|m_set_handler
parameter_list|(
name|m
parameter_list|,
name|handler
parameter_list|)
value|((m)->m_pkthdr.header = (handler))
end_define

begin_define
define|#
directive|define
name|m_set_socket
parameter_list|(
name|m
parameter_list|,
name|a
parameter_list|)
value|((m)->m_pkthdr.header = (a))
end_define

begin_define
define|#
directive|define
name|m_get_socket
parameter_list|(
name|m
parameter_list|)
value|((m)->m_pkthdr.header)
end_define

begin_define
define|#
directive|define
name|KTR_CXGB
value|KTR_SPARE2
end_define

begin_function_decl
name|void
name|cxgb_log_tcb
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|unsigned
name|int
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MT_DONTFREE
value|128
end_define

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>
literal|700030
end_if

begin_define
define|#
directive|define
name|INTR_FILTERS
end_define

begin_define
define|#
directive|define
name|FIRMWARE_LATEST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
operator|(
name|__FreeBSD_version
operator|>
literal|602103
operator|)
operator|&&
operator|(
name|__FreeBSD_version
operator|<
literal|700000
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|FIRMWARE_LATEST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>
literal|700000
end_if

begin_define
define|#
directive|define
name|MSI_SUPPORTED
end_define

begin_define
define|#
directive|define
name|TSO_SUPPORTED
end_define

begin_define
define|#
directive|define
name|VLAN_SUPPORTED
end_define

begin_define
define|#
directive|define
name|TASKQUEUE_CURRENT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|if_name
parameter_list|(
name|ifp
parameter_list|)
value|(ifp)->if_xname
end_define

begin_define
define|#
directive|define
name|M_SANITY
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__read_mostly
value|__attribute__((__section__(".data.read_mostly")))
end_define

begin_comment
comment|/*  * Workaround for weird Chelsio issue  */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>
literal|700029
end_if

begin_define
define|#
directive|define
name|PRIV_SUPPORTED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CXGB_TX_CLEANUP_THRESHOLD
value|32
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_PRINT
end_ifdef

begin_define
define|#
directive|define
name|DPRINTF
value|printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TX_MAX_SIZE
value|(1<< 16)
end_define

begin_comment
comment|/* 64KB                          */
end_comment

begin_define
define|#
directive|define
name|TX_MAX_SEGS
value|36
end_define

begin_comment
comment|/* maximum supported by card     */
end_comment

begin_define
define|#
directive|define
name|TX_MAX_DESC
value|4
end_define

begin_comment
comment|/* max descriptors per packet    */
end_comment

begin_define
define|#
directive|define
name|TX_START_MIN_DESC
value|(TX_MAX_DESC<< 2)
end_define

begin_define
define|#
directive|define
name|TX_START_MAX_DESC
value|(TX_MAX_DESC<< 3)
end_define

begin_comment
comment|/* maximum number of descriptors 						 * call to start used per 	 */
end_comment

begin_define
define|#
directive|define
name|TX_CLEAN_MAX_DESC
value|(TX_MAX_DESC<< 4)
end_define

begin_comment
comment|/* maximum tx descriptors 						 * to clean per iteration        */
end_comment

begin_define
define|#
directive|define
name|TX_WR_SIZE_MAX
value|11*1024
end_define

begin_comment
comment|/* the maximum total size of packets aggregated into a single 						* TX WR 						*/
end_comment

begin_define
define|#
directive|define
name|TX_WR_COUNT_MAX
value|7
end_define

begin_comment
comment|/* the maximum total number of packets that can be 						* aggregated into a single TX WR 						*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|__asm volatile("mfence":::"memory")
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|__asm volatile("lfence":::"memory")
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|__asm volatile("sfence" ::: "memory")
end_define

begin_define
define|#
directive|define
name|smp_mb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|L1_CACHE_BYTES
value|128
end_define

begin_function
specifier|static
name|__inline
name|void
name|prefetch
parameter_list|(
name|void
modifier|*
name|x
parameter_list|)
block|{
asm|__asm volatile("prefetcht0 %0" :: "m" (*(unsigned long *)x));
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|kdb_backtrace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|WARN_ON
parameter_list|(
name|condition
parameter_list|)
value|do { \ 	if (__predict_false((condition)!=0)) {	\                 log(LOG_WARNING, "BUG: warning at %s:%d/%s()\n", __FILE__, __LINE__, __FUNCTION__); \                 kdb_backtrace(); \         } \ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !i386&& !amd64 */
end_comment

begin_define
define|#
directive|define
name|mb
parameter_list|()
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
end_define

begin_define
define|#
directive|define
name|smp_mb
parameter_list|()
end_define

begin_define
define|#
directive|define
name|prefetch
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|L1_CACHE_BYTES
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|buf_ring
block|{
name|caddr_t
modifier|*
name|br_ring
decl_stmt|;
specifier|volatile
name|uint32_t
name|br_cons
decl_stmt|;
specifier|volatile
name|uint32_t
name|br_prod
decl_stmt|;
name|int
name|br_size
decl_stmt|;
name|struct
name|mtx
name|br_lock
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|buf_ring
modifier|*
name|buf_ring_alloc
parameter_list|(
name|int
name|count
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buf_ring_free
parameter_list|(
name|struct
name|buf_ring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|buf_ring_count
parameter_list|(
name|struct
name|buf_ring
modifier|*
name|mr
parameter_list|)
block|{
name|int
name|size
init|=
name|mr
operator|->
name|br_size
decl_stmt|;
name|uint32_t
name|mask
init|=
name|size
operator|-
literal|1
decl_stmt|;
return|return
operator|(
operator|(
name|size
operator|+
name|mr
operator|->
name|br_prod
operator|-
name|mr
operator|->
name|br_cons
operator|)
operator|&
name|mask
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|buf_ring_empty
parameter_list|(
name|struct
name|buf_ring
modifier|*
name|mr
parameter_list|)
block|{
return|return
operator|(
name|mr
operator|->
name|br_cons
operator|==
name|mr
operator|->
name|br_prod
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|buf_ring_full
parameter_list|(
name|struct
name|buf_ring
modifier|*
name|mr
parameter_list|)
block|{
name|uint32_t
name|mask
decl_stmt|;
name|mask
operator|=
name|mr
operator|->
name|br_size
operator|-
literal|1
expr_stmt|;
return|return
operator|(
name|mr
operator|->
name|br_cons
operator|==
operator|(
operator|(
name|mr
operator|->
name|br_prod
operator|+
literal|1
operator|)
operator|&
name|mask
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * The producer and consumer are independently locked  * this relies on the consumer providing his own serialization  *  */
end_comment

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|buf_ring_dequeue
parameter_list|(
name|struct
name|buf_ring
modifier|*
name|mr
parameter_list|)
block|{
name|uint32_t
name|prod
decl_stmt|,
name|cons
decl_stmt|,
name|mask
decl_stmt|;
name|caddr_t
modifier|*
name|ring
decl_stmt|,
name|m
decl_stmt|;
name|ring
operator|=
operator|(
name|caddr_t
operator|*
operator|)
name|mr
operator|->
name|br_ring
expr_stmt|;
name|mask
operator|=
name|mr
operator|->
name|br_size
operator|-
literal|1
expr_stmt|;
name|cons
operator|=
name|mr
operator|->
name|br_cons
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
name|prod
operator|=
name|mr
operator|->
name|br_prod
expr_stmt|;
name|m
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|cons
operator|!=
name|prod
condition|)
block|{
name|m
operator|=
name|ring
index|[
name|cons
index|]
expr_stmt|;
name|ring
index|[
name|cons
index|]
operator|=
name|NULL
expr_stmt|;
name|mr
operator|->
name|br_cons
operator|=
operator|(
name|cons
operator|+
literal|1
operator|)
operator|&
name|mask
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
block|}
return|return
operator|(
name|m
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_BUFRING
end_ifdef

begin_function
specifier|static
name|__inline
name|void
name|__buf_ring_scan
parameter_list|(
name|struct
name|buf_ring
modifier|*
name|mr
parameter_list|,
name|void
modifier|*
name|m
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|mr
operator|->
name|br_size
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|m
operator|==
name|mr
operator|->
name|br_ring
index|[
name|i
index|]
condition|)
name|panic
argument_list|(
literal|"%s:%d m=%p present prod=%d cons=%d idx=%d"
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|m
argument_list|,
name|mr
operator|->
name|br_prod
argument_list|,
name|mr
operator|->
name|br_cons
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|buf_ring_scan
parameter_list|(
name|struct
name|buf_ring
modifier|*
name|mr
parameter_list|,
name|void
modifier|*
name|m
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|mtx_lock
argument_list|(
operator|&
name|mr
operator|->
name|br_lock
argument_list|)
expr_stmt|;
name|__buf_ring_scan
argument_list|(
name|mr
argument_list|,
name|m
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|mr
operator|->
name|br_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|__inline
name|void
name|__buf_ring_scan
parameter_list|(
name|struct
name|buf_ring
modifier|*
name|mr
parameter_list|,
name|void
modifier|*
name|m
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|void
name|buf_ring_scan
parameter_list|(
name|struct
name|buf_ring
modifier|*
name|mr
parameter_list|,
name|void
modifier|*
name|m
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|int
name|__buf_ring_enqueue
parameter_list|(
name|struct
name|buf_ring
modifier|*
name|mr
parameter_list|,
name|void
modifier|*
name|m
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|uint32_t
name|prod
decl_stmt|,
name|cons
decl_stmt|,
name|mask
decl_stmt|;
name|int
name|err
decl_stmt|;
name|mask
operator|=
name|mr
operator|->
name|br_size
operator|-
literal|1
expr_stmt|;
name|prod
operator|=
name|mr
operator|->
name|br_prod
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
name|cons
operator|=
name|mr
operator|->
name|br_cons
expr_stmt|;
name|__buf_ring_scan
argument_list|(
name|mr
argument_list|,
name|m
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|prod
operator|+
literal|1
operator|)
operator|&
name|mask
operator|)
operator|!=
name|cons
condition|)
block|{
name|KASSERT
argument_list|(
name|mr
operator|->
name|br_ring
index|[
name|prod
index|]
operator|==
name|NULL
argument_list|,
operator|(
literal|"overwriting entry"
operator|)
argument_list|)
expr_stmt|;
name|mr
operator|->
name|br_ring
index|[
name|prod
index|]
operator|=
name|m
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
name|mr
operator|->
name|br_prod
operator|=
operator|(
name|prod
operator|+
literal|1
operator|)
operator|&
name|mask
expr_stmt|;
name|err
operator|=
literal|0
expr_stmt|;
block|}
else|else
name|err
operator|=
name|ENOBUFS
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|buf_ring_enqueue_
parameter_list|(
name|struct
name|buf_ring
modifier|*
name|mr
parameter_list|,
name|void
modifier|*
name|m
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|int
name|err
decl_stmt|;
name|mtx_lock
argument_list|(
operator|&
name|mr
operator|->
name|br_lock
argument_list|)
expr_stmt|;
name|err
operator|=
name|__buf_ring_enqueue
argument_list|(
name|mr
argument_list|,
name|m
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|mr
operator|->
name|br_lock
argument_list|)
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|buf_ring_enqueue
parameter_list|(
name|mr
parameter_list|,
name|m
parameter_list|)
value|buf_ring_enqueue_((mr), (m), __FILE__, __LINE__)
end_define

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|buf_ring_peek
parameter_list|(
name|struct
name|buf_ring
modifier|*
name|mr
parameter_list|)
block|{
name|int
name|prod
decl_stmt|,
name|cons
decl_stmt|,
name|mask
decl_stmt|;
name|caddr_t
modifier|*
name|ring
decl_stmt|,
name|m
decl_stmt|;
name|ring
operator|=
operator|(
name|caddr_t
operator|*
operator|)
name|mr
operator|->
name|br_ring
expr_stmt|;
name|mask
operator|=
name|mr
operator|->
name|br_size
operator|-
literal|1
expr_stmt|;
name|cons
operator|=
name|mr
operator|->
name|br_cons
expr_stmt|;
name|prod
operator|=
name|mr
operator|->
name|br_prod
expr_stmt|;
name|m
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|cons
operator|!=
name|prod
condition|)
name|m
operator|=
name|ring
index|[
name|cons
index|]
expr_stmt|;
return|return
operator|(
name|m
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|DBG_RX
value|(1<< 0)
end_define

begin_decl_stmt
specifier|static
specifier|const
name|int
name|debug_flags
init|=
name|DBG_RX
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_PRINT
end_ifdef

begin_define
define|#
directive|define
name|DBG
parameter_list|(
name|flag
parameter_list|,
name|msg
parameter_list|)
value|do {	\ 	if ((flag& debug_flags))	\ 		printf msg; \ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBG
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_define
define|#
directive|define
name|promisc_rx_mode
parameter_list|(
name|rm
parameter_list|)
value|((rm)->port->ifp->if_flags& IFF_PROMISC)
end_define

begin_define
define|#
directive|define
name|allmulti_rx_mode
parameter_list|(
name|rm
parameter_list|)
value|((rm)->port->ifp->if_flags& IFF_ALLMULTI)
end_define

begin_define
define|#
directive|define
name|CH_ERR
parameter_list|(
name|adap
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|log(LOG_ERR, fmt, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|CH_WARN
parameter_list|(
name|adap
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|log(LOG_WARNING, fmt, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|CH_ALERT
parameter_list|(
name|adap
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|log(LOG_ALERT, fmt, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|t3_os_sleep
parameter_list|(
name|x
parameter_list|)
value|DELAY((x) * 1000)
end_define

begin_define
define|#
directive|define
name|test_and_clear_bit
parameter_list|(
name|bit
parameter_list|,
name|p
parameter_list|)
value|atomic_cmpset_int((p), ((*(p)) | (1<<bit)), ((*(p))& ~(1<<bit)))
end_define

begin_define
define|#
directive|define
name|max_t
parameter_list|(
name|type
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|(type)max((a), (b))
end_define

begin_define
define|#
directive|define
name|net_device
value|ifnet
end_define

begin_define
define|#
directive|define
name|cpu_to_be32
value|htobe32
end_define

begin_comment
comment|/* Standard PHY definitions */
end_comment

begin_define
define|#
directive|define
name|BMCR_LOOPBACK
value|BMCR_LOOP
end_define

begin_define
define|#
directive|define
name|BMCR_ISOLATE
value|BMCR_ISO
end_define

begin_define
define|#
directive|define
name|BMCR_ANENABLE
value|BMCR_AUTOEN
end_define

begin_define
define|#
directive|define
name|BMCR_SPEED1000
value|BMCR_SPEED1
end_define

begin_define
define|#
directive|define
name|BMCR_SPEED100
value|BMCR_SPEED0
end_define

begin_define
define|#
directive|define
name|BMCR_ANRESTART
value|BMCR_STARTNEG
end_define

begin_define
define|#
directive|define
name|BMCR_FULLDPLX
value|BMCR_FDX
end_define

begin_define
define|#
directive|define
name|BMSR_LSTATUS
value|BMSR_LINK
end_define

begin_define
define|#
directive|define
name|BMSR_ANEGCOMPLETE
value|BMSR_ACOMP
end_define

begin_define
define|#
directive|define
name|MII_LPA
value|MII_ANLPAR
end_define

begin_define
define|#
directive|define
name|MII_ADVERTISE
value|MII_ANAR
end_define

begin_define
define|#
directive|define
name|MII_CTRL1000
value|MII_100T2CR
end_define

begin_define
define|#
directive|define
name|ADVERTISE_PAUSE_CAP
value|ANAR_FC
end_define

begin_define
define|#
directive|define
name|ADVERTISE_PAUSE_ASYM
value|0x800
end_define

begin_define
define|#
directive|define
name|ADVERTISE_PAUSE
value|ANAR_FC
end_define

begin_define
define|#
directive|define
name|ADVERTISE_1000HALF
value|0x100
end_define

begin_define
define|#
directive|define
name|ADVERTISE_1000FULL
value|0x200
end_define

begin_define
define|#
directive|define
name|ADVERTISE_10FULL
value|ANAR_10_FD
end_define

begin_define
define|#
directive|define
name|ADVERTISE_10HALF
value|ANAR_10
end_define

begin_define
define|#
directive|define
name|ADVERTISE_100FULL
value|ANAR_TX_FD
end_define

begin_define
define|#
directive|define
name|ADVERTISE_100HALF
value|ANAR_TX
end_define

begin_define
define|#
directive|define
name|ADVERTISE_1000XHALF
value|ANAR_X_HD
end_define

begin_define
define|#
directive|define
name|ADVERTISE_1000XFULL
value|ANAR_X_FD
end_define

begin_define
define|#
directive|define
name|ADVERTISE_1000XPSE_ASYM
value|ANAR_X_PAUSE_ASYM
end_define

begin_define
define|#
directive|define
name|ADVERTISE_1000XPAUSE
value|ANAR_X_PAUSE_SYM
end_define

begin_define
define|#
directive|define
name|ADVERTISE_CSMA
value|ANAR_CSMA
end_define

begin_define
define|#
directive|define
name|ADVERTISE_NPAGE
value|ANAR_NP
end_define

begin_comment
comment|/* Standard PCI Extended Capabilities definitions */
end_comment

begin_define
define|#
directive|define
name|PCI_CAP_ID_VPD
value|PCIY_VPD
end_define

begin_define
define|#
directive|define
name|PCI_VPD_ADDR
value|PCIR_VPD_ADDR
end_define

begin_define
define|#
directive|define
name|PCI_VPD_ADDR_F
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCI_VPD_DATA
value|PCIR_VPD_DATA
end_define

begin_define
define|#
directive|define
name|PCI_CAP_ID_EXP
value|PCIY_EXPRESS
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL
value|PCIR_EXPRESS_DEVICE_CTL
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_PAYLOAD
value|PCIM_EXP_CTL_MAX_PAYLOAD
end_define

begin_define
define|#
directive|define
name|PCI_EXP_DEVCTL_READRQ
value|PCIM_EXP_CTL_MAX_READ_REQUEST
end_define

begin_define
define|#
directive|define
name|PCI_EXP_LNKCTL
value|PCIR_EXPRESS_LINK_CTL
end_define

begin_define
define|#
directive|define
name|PCI_EXP_LNKSTA
value|PCIR_EXPRESS_LINK_STA
end_define

begin_comment
comment|/*  * Linux compatibility macros  */
end_comment

begin_comment
comment|/* Some simple translations */
end_comment

begin_define
define|#
directive|define
name|__devinit
end_define

begin_define
define|#
directive|define
name|udelay
parameter_list|(
name|x
parameter_list|)
value|DELAY(x)
end_define

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|x
parameter_list|)
value|(sizeof(x) / sizeof((x)[0]))
end_define

begin_define
define|#
directive|define
name|le32_to_cpu
parameter_list|(
name|x
parameter_list|)
value|le32toh(x)
end_define

begin_define
define|#
directive|define
name|le16_to_cpu
parameter_list|(
name|x
parameter_list|)
value|le16toh(x)
end_define

begin_define
define|#
directive|define
name|cpu_to_le32
parameter_list|(
name|x
parameter_list|)
value|htole32(x)
end_define

begin_define
define|#
directive|define
name|swab32
parameter_list|(
name|x
parameter_list|)
value|bswap32(x)
end_define

begin_define
define|#
directive|define
name|simple_strtoul
value|strtoul
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_TYPES_DEFINED
end_ifndef

begin_typedef
typedef|typedef
name|uint8_t
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|u64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|__u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|__u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|__be8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|__be16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__be32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|__be64
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|__BIG_ENDIAN_BITFIELD
end_define

begin_elif
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_elif

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN_BITFIELD
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Must set BYTE_ORDER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Indicates what features are supported by the interface. */
end_comment

begin_define
define|#
directive|define
name|SUPPORTED_10baseT_Half
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_10baseT_Full
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_100baseT_Half
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_100baseT_Full
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_1000baseT_Half
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_1000baseT_Full
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_Autoneg
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_TP
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_AUI
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_MII
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_FIBRE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_BNC
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_10000baseT_Full
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_Pause
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|SUPPORTED_Asym_Pause
value|(1<< 14)
end_define

begin_comment
comment|/* Indicates what features are advertised by the interface. */
end_comment

begin_define
define|#
directive|define
name|ADVERTISED_10baseT_Half
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|ADVERTISED_10baseT_Full
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ADVERTISED_100baseT_Half
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|ADVERTISED_100baseT_Full
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|ADVERTISED_1000baseT_Half
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|ADVERTISED_1000baseT_Full
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|ADVERTISED_Autoneg
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|ADVERTISED_TP
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|ADVERTISED_AUI
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|ADVERTISED_MII
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|ADVERTISED_FIBRE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|ADVERTISED_BNC
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|ADVERTISED_10000baseT_Full
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|ADVERTISED_Pause
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|ADVERTISED_Asym_Pause
value|(1<< 14)
end_define

begin_comment
comment|/* Enable or disable autonegotiation.  If this is set to enable,  * the forced link modes above are completely ignored.  */
end_comment

begin_define
define|#
directive|define
name|AUTONEG_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|AUTONEG_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|SPEED_10
value|10
end_define

begin_define
define|#
directive|define
name|SPEED_100
value|100
end_define

begin_define
define|#
directive|define
name|SPEED_1000
value|1000
end_define

begin_define
define|#
directive|define
name|SPEED_10000
value|10000
end_define

begin_define
define|#
directive|define
name|DUPLEX_HALF
value|0
end_define

begin_define
define|#
directive|define
name|DUPLEX_FULL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

