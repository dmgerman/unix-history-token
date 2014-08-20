begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2011-2014 Matteo Landi, Luigi Rizzo. All rights reserved.  * Copyright (C) 2013-2014 Universita` di Pisa. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  *  * The header contains the definitions of constants and function  * prototypes used only in kernelspace.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_NETMAP_KERN_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_NETMAP_KERN_H_
end_define

begin_define
define|#
directive|define
name|WITH_VALE
end_define

begin_comment
comment|// comment out to disable VALE support
end_comment

begin_define
define|#
directive|define
name|WITH_PIPES
end_define

begin_define
define|#
directive|define
name|WITH_MONITOR
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect((long)!!(x), 1L)
end_define

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect((long)!!(x), 0L)
end_define

begin_define
define|#
directive|define
name|NM_LOCK_T
value|struct mtx
end_define

begin_define
define|#
directive|define
name|NMG_LOCK_T
value|struct mtx
end_define

begin_define
define|#
directive|define
name|NMG_LOCK_INIT
parameter_list|()
value|mtx_init(&netmap_global_lock, \ 				"netmap global lock", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|NMG_LOCK_DESTROY
parameter_list|()
value|mtx_destroy(&netmap_global_lock)
end_define

begin_define
define|#
directive|define
name|NMG_LOCK
parameter_list|()
value|mtx_lock(&netmap_global_lock)
end_define

begin_define
define|#
directive|define
name|NMG_UNLOCK
parameter_list|()
value|mtx_unlock(&netmap_global_lock)
end_define

begin_define
define|#
directive|define
name|NMG_LOCK_ASSERT
parameter_list|()
value|mtx_assert(&netmap_global_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|NM_SELINFO_T
value|struct selinfo
end_define

begin_define
define|#
directive|define
name|MBUF_LEN
parameter_list|(
name|m
parameter_list|)
value|((m)->m_pkthdr.len)
end_define

begin_define
define|#
directive|define
name|MBUF_IFP
parameter_list|(
name|m
parameter_list|)
value|((m)->m_pkthdr.rcvif)
end_define

begin_define
define|#
directive|define
name|NM_SEND_UP
parameter_list|(
name|ifp
parameter_list|,
name|m
parameter_list|)
value|((NA(ifp))->if_input)(ifp, m)
end_define

begin_define
define|#
directive|define
name|NM_ATOMIC_T
value|volatile int
end_define

begin_comment
comment|// XXX ?
end_comment

begin_comment
comment|/* atomic operations */
end_comment

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_define
define|#
directive|define
name|NM_ATOMIC_TEST_AND_SET
parameter_list|(
name|p
parameter_list|)
value|(!atomic_cmpset_acq_int((p), 0, 1))
end_define

begin_define
define|#
directive|define
name|NM_ATOMIC_CLEAR
parameter_list|(
name|p
parameter_list|)
value|atomic_store_rel_int((p), 0)
end_define

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|1100005
end_if

begin_function_decl
name|struct
name|netmap_adapter
modifier|*
name|netmap_getna
parameter_list|(
name|if_t
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|1100027
end_if

begin_define
define|#
directive|define
name|GET_MBUF_REFCNT
parameter_list|(
name|m
parameter_list|)
value|((m)->m_ext.ext_cnt ? *((m)->m_ext.ext_cnt) : -1)
end_define

begin_define
define|#
directive|define
name|SET_MBUF_REFCNT
parameter_list|(
name|m
parameter_list|,
name|x
parameter_list|)
value|*((m)->m_ext.ext_cnt) = x
end_define

begin_define
define|#
directive|define
name|PNT_MBUF_REFCNT
parameter_list|(
name|m
parameter_list|)
value|((m)->m_ext.ext_cnt)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GET_MBUF_REFCNT
parameter_list|(
name|m
parameter_list|)
value|((m)->m_ext.ref_cnt ? *((m)->m_ext.ref_cnt) : -1)
end_define

begin_define
define|#
directive|define
name|SET_MBUF_REFCNT
parameter_list|(
name|m
parameter_list|,
name|x
parameter_list|)
value|*((m)->m_ext.ref_cnt) = x
end_define

begin_define
define|#
directive|define
name|PNT_MBUF_REFCNT
parameter_list|(
name|m
parameter_list|)
value|((m)->m_ext.ref_cnt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NETMAP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// XXX linux struct, not used in FreeBSD
end_comment

begin_struct
struct|struct
name|net_device_ops
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|ethtool_ops
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|hrtimer
block|{ }
struct|;
end_struct

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|linux
argument_list|)
end_elif

begin_define
define|#
directive|define
name|NM_LOCK_T
value|safe_spinlock_t
end_define

begin_comment
comment|// see bsd_glue.h
end_comment

begin_define
define|#
directive|define
name|NM_SELINFO_T
value|wait_queue_head_t
end_define

begin_define
define|#
directive|define
name|MBUF_LEN
parameter_list|(
name|m
parameter_list|)
value|((m)->len)
end_define

begin_define
define|#
directive|define
name|MBUF_IFP
parameter_list|(
name|m
parameter_list|)
value|((m)->dev)
end_define

begin_define
define|#
directive|define
name|NM_SEND_UP
parameter_list|(
name|ifp
parameter_list|,
name|m
parameter_list|)
define|\
value|do { \                             m->priority = NM_MAGIC_PRIORITY_RX; \                             netif_rx(m); \                         } while (0)
end_define

begin_define
define|#
directive|define
name|NM_ATOMIC_T
value|volatile long unsigned int
end_define

begin_comment
comment|// XXX a mtx would suffice here too 20130404 gl
end_comment

begin_define
define|#
directive|define
name|NMG_LOCK_T
value|struct semaphore
end_define

begin_define
define|#
directive|define
name|NMG_LOCK_INIT
parameter_list|()
value|sema_init(&netmap_global_lock, 1)
end_define

begin_define
define|#
directive|define
name|NMG_LOCK_DESTROY
parameter_list|()
end_define

begin_define
define|#
directive|define
name|NMG_LOCK
parameter_list|()
value|down(&netmap_global_lock)
end_define

begin_define
define|#
directive|define
name|NMG_UNLOCK
parameter_list|()
value|up(&netmap_global_lock)
end_define

begin_define
define|#
directive|define
name|NMG_LOCK_ASSERT
parameter_list|()
end_define

begin_comment
comment|//	XXX to be completed
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_NETMAP
end_ifndef

begin_define
define|#
directive|define
name|DEV_NETMAP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_NETMAP */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_elif

begin_warning
warning|#
directive|warning
warning|apple support is incomplete.
end_warning

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 1)
end_define

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 0)
end_define

begin_define
define|#
directive|define
name|NM_LOCK_T
value|IOLock *
end_define

begin_define
define|#
directive|define
name|NM_SELINFO_T
value|struct selinfo
end_define

begin_define
define|#
directive|define
name|MBUF_LEN
parameter_list|(
name|m
parameter_list|)
value|((m)->m_pkthdr.len)
end_define

begin_define
define|#
directive|define
name|NM_SEND_UP
parameter_list|(
name|ifp
parameter_list|,
name|m
parameter_list|)
value|((ifp)->if_input)(ifp, m)
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|unsupported platform
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end - platform-specific code */
end_comment

begin_define
define|#
directive|define
name|ND
parameter_list|(
name|format
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|D
parameter_list|(
name|format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {							\ 		struct timeval __xxts;				\ 		microtime(&__xxts);				\ 		printf("%03d.%06d [%4d] %-25s " format "\n",	\ 		(int)__xxts.tv_sec % 1000, (int)__xxts.tv_usec,	\ 		__LINE__, __FUNCTION__, ##__VA_ARGS__);		\ 	} while (0)
end_define

begin_comment
comment|/* rate limited, lps indicates how many per second */
end_comment

begin_define
define|#
directive|define
name|RD
parameter_list|(
name|lps
parameter_list|,
name|format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {							\ 		static int t0, __cnt;				\ 		if (t0 != time_second) {			\ 			t0 = time_second;			\ 			__cnt = 0;				\ 		}						\ 		if (__cnt++< lps)				\ 			D(format, ##__VA_ARGS__);		\ 	} while (0)
end_define

begin_struct_decl
struct_decl|struct
name|netmap_adapter
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nm_bdg_fwd
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nm_bridge
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|netmap_priv_d
struct_decl|;
end_struct_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|nm_dump_buf
parameter_list|(
name|char
modifier|*
name|p
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|lim
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"netmap_mbq.h"
end_include

begin_decl_stmt
specifier|extern
name|NMG_LOCK_T
name|netmap_global_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * private, kernel view of a ring. Keeps track of the status of  * a ring across system calls.  *  *	nr_hwcur	index of the next buffer to refill.  *			It corresponds to ring->head  *			at the time the system call returns.  *  *	nr_hwtail	index of the first buffer owned by the kernel.  *			On RX, hwcur->hwtail are receive buffers  *			not yet released. hwcur is advanced following  *			ring->head, hwtail is advanced on incoming packets,  *			and a wakeup is generated when hwtail passes ring->cur  *			    On TX, hwcur->rcur have been filled by the sender  *			but not sent yet to the NIC; rcur->hwtail are available  *			for new transmissions, and hwtail->hwcur-1 are pending  *			transmissions not yet acknowledged.  *  * The indexes in the NIC and netmap rings are offset by nkr_hwofs slots.  * This is so that, on a reset, buffers owned by userspace are not  * modified by the kernel. In particular:  * RX rings: the next empty buffer (hwtail + hwofs) coincides with  * 	the next empty buffer as known by the hardware (next_to_check or so).  * TX rings: hwcur + hwofs coincides with next_to_send  *  * For received packets, slot->flags is set to nkr_slot_flags  * so we can provide a proper initial value (e.g. set NS_FORWARD  * when operating in 'transparent' mode).  *  * The following fields are used to implement lock-free copy of packets  * from input to output ports in VALE switch:  *	nkr_hwlease	buffer after the last one being copied.  *			A writer in nm_bdg_flush reserves N buffers  *			from nr_hwlease, advances it, then does the  *			copy outside the lock.  *			In RX rings (used for VALE ports),  *			nkr_hwtail<= nkr_hwlease< nkr_hwcur+N-1  *			In TX rings (used for NIC or host stack ports)  *			nkr_hwcur<= nkr_hwlease< nkr_hwtail  *	nkr_leases	array of nkr_num_slots where writers can report  *			completion of their block. NR_NOSLOT (~0) indicates  *			that the writer has not finished yet  *	nkr_lease_idx	index of next free slot in nr_leases, to be assigned  *  * The kring is manipulated by txsync/rxsync and generic netmap function.  *  * Concurrent rxsync or txsync on the same ring are prevented through  * by nm_kr_(try)lock() which in turn uses nr_busy. This is all we need  * for NIC rings, and for TX rings attached to the host stack.  *  * RX rings attached to the host stack use an mbq (rx_queue) on both  * rxsync_from_host() and netmap_transmit(). The mbq is protected  * by its internal lock.  *  * RX rings attached to the VALE switch are accessed by both senders  * and receiver. They are protected through the q_lock on the RX ring.  */
end_comment

begin_struct
struct|struct
name|netmap_kring
block|{
name|struct
name|netmap_ring
modifier|*
name|ring
decl_stmt|;
name|uint32_t
name|nr_hwcur
decl_stmt|;
name|uint32_t
name|nr_hwtail
decl_stmt|;
comment|/* 	 * Copies of values in user rings, so we do not need to look 	 * at the ring (which could be modified). These are set in the 	 * *sync_prologue()/finalize() routines. 	 */
name|uint32_t
name|rhead
decl_stmt|;
name|uint32_t
name|rcur
decl_stmt|;
name|uint32_t
name|rtail
decl_stmt|;
name|uint32_t
name|nr_kflags
decl_stmt|;
comment|/* private driver flags */
define|#
directive|define
name|NKR_PENDINTR
value|0x1
comment|// Pending interrupt.
name|uint32_t
name|nkr_num_slots
decl_stmt|;
comment|/* 	 * On a NIC reset, the NIC ring indexes may be reset but the 	 * indexes in the netmap rings remain the same. nkr_hwofs 	 * keeps track of the offset between the two. 	 */
name|int32_t
name|nkr_hwofs
decl_stmt|;
name|uint16_t
name|nkr_slot_flags
decl_stmt|;
comment|/* initial value for flags */
comment|/* last_reclaim is opaque marker to help reduce the frequency 	 * of operations such as reclaiming tx buffers. A possible use 	 * is set it to ticks and do the reclaim only once per tick. 	 */
name|uint64_t
name|last_reclaim
decl_stmt|;
name|NM_SELINFO_T
name|si
decl_stmt|;
comment|/* poll/select wait queue */
name|NM_LOCK_T
name|q_lock
decl_stmt|;
comment|/* protects kring and ring. */
name|NM_ATOMIC_T
name|nr_busy
decl_stmt|;
comment|/* prevent concurrent syscalls */
name|struct
name|netmap_adapter
modifier|*
name|na
decl_stmt|;
comment|/* The folloiwing fields are for VALE switch support */
name|struct
name|nm_bdg_fwd
modifier|*
name|nkr_ft
decl_stmt|;
name|uint32_t
modifier|*
name|nkr_leases
decl_stmt|;
define|#
directive|define
name|NR_NOSLOT
value|((uint32_t)~0)
comment|/* used in nkr_*lease* */
name|uint32_t
name|nkr_hwlease
decl_stmt|;
name|uint32_t
name|nkr_lease_idx
decl_stmt|;
comment|/* while nkr_stopped is set, no new [tr]xsync operations can 	 * be started on this kring. 	 * This is used by netmap_disable_all_rings() 	 * to find a synchronization point where critical data 	 * structures pointed to by the kring can be added or removed 	 */
specifier|volatile
name|int
name|nkr_stopped
decl_stmt|;
comment|/* Support for adapters without native netmap support. 	 * On tx rings we preallocate an array of tx buffers 	 * (same size as the netmap ring), on rx rings we 	 * store incoming mbufs in a queue that is drained by 	 * a rxsync. 	 */
name|struct
name|mbuf
modifier|*
modifier|*
name|tx_pool
decl_stmt|;
comment|// u_int nr_ntc;		/* Emulation of a next-to-clean RX ring pointer. */
name|struct
name|mbq
name|rx_queue
decl_stmt|;
comment|/* intercepted rx mbufs. */
name|uint32_t
name|ring_id
decl_stmt|;
comment|/* debugging */
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
comment|/* diagnostic */
comment|/* [tx]sync callback for this kring. 	 * The default nm_kring_create callback (netmap_krings_create) 	 * sets the nm_sync callback of each hardware tx(rx) kring to 	 * the corresponding nm_txsync(nm_rxsync) taken from the 	 * netmap_adapter; moreover, it sets the sync callback 	 * of the host tx(rx) ring to netmap_txsync_to_host 	 * (netmap_rxsync_from_host). 	 * 	 * Overrides: the above configuration is not changed by 	 * any of the nm_krings_create callbacks. 	 */
name|int
function_decl|(
modifier|*
name|nm_sync
function_decl|)
parameter_list|(
name|struct
name|netmap_kring
modifier|*
name|kring
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|WITH_PIPES
name|struct
name|netmap_kring
modifier|*
name|pipe
decl_stmt|;
comment|/* if this is a pipe ring, 					 * pointer to the other end 					 */
name|struct
name|netmap_ring
modifier|*
name|save_ring
decl_stmt|;
comment|/* pointer to hidden rings        					 * (see netmap_pipe.c for details) 					 */
endif|#
directive|endif
comment|/* WITH_PIPES */
ifdef|#
directive|ifdef
name|WITH_MONITOR
comment|/* pointer to the adapter that is monitoring this kring (if any) 	 */
name|struct
name|netmap_monitor_adapter
modifier|*
name|monitor
decl_stmt|;
comment|/* 	 * Monitors work by intercepting the txsync and/or rxsync of the 	 * monitored krings. This is implemented by replacing 	 * the nm_sync pointer above and saving the previous 	 * one in save_sync below. 	 */
name|int
function_decl|(
modifier|*
name|save_sync
function_decl|)
parameter_list|(
name|struct
name|netmap_kring
modifier|*
name|kring
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
name|__attribute__
argument_list|(
operator|(
name|__aligned__
argument_list|(
literal|64
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* return the next index, with wraparound */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|nm_next
parameter_list|(
name|uint32_t
name|i
parameter_list|,
name|uint32_t
name|lim
parameter_list|)
block|{
return|return
name|unlikely
argument_list|(
name|i
operator|==
name|lim
argument_list|)
condition|?
literal|0
else|:
name|i
operator|+
literal|1
return|;
block|}
end_function

begin_comment
comment|/* return the previous index, with wraparound */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|nm_prev
parameter_list|(
name|uint32_t
name|i
parameter_list|,
name|uint32_t
name|lim
parameter_list|)
block|{
return|return
name|unlikely
argument_list|(
name|i
operator|==
literal|0
argument_list|)
condition|?
name|lim
else|:
name|i
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  *  * Here is the layout for the Rx and Tx rings.         RxRING                            TxRING        +-----------------+            +-----------------+       |                 |            |                 |       |XXX free slot XXX|            |XXX free slot XXX|       +-----------------+            +-----------------+ head->| owned by user   |<-hwcur     | not sent to nic |<-hwcur       |                 |            | yet             |       +-----------------+            |                 |  cur->| available to    |            |                 |       | user, not read  |            +-----------------+       | yet             |       cur->| (being          |       |                 |            |  prepared)      |       |                 |            |                 |       +-----------------+            +     ------      + tail->|                 |<-hwtail    |                 |<-hwlease       | (being          | ...        |                 | ...       |  prepared)      | ...        |                 | ...       +-----------------+ ...        |                 | ...       |                 |<-hwlease   +-----------------+       |                 |      tail->|                 |<-hwtail       |                 |            |                 |       |                 |            |                 |       |                 |            |                 |       +-----------------+            +-----------------+   * The cur/tail (user view) and hwcur/hwtail (kernel view)  * are used in the normal operation of the card.  *  * When a ring is the output of a switch port (Rx ring for  * a VALE port, Tx ring for the host stack or NIC), slots  * are reserved in blocks through 'hwlease' which points  * to the next unused slot.  * On an Rx ring, hwlease is always after hwtail,  * and completions cause hwtail to advance.  * On a Tx ring, hwlease is always between cur and hwtail,  * and completions cause cur to advance.  *  * nm_kr_space() returns the maximum number of slots that  * can be assigned.  * nm_kr_lease() reserves the required number of buffers,  *    advances nkr_hwlease and also returns an entry in  *    a circular array where completions should be reported.  */
end_comment

begin_enum
enum|enum
name|txrx
block|{
name|NR_RX
init|=
literal|0
block|,
name|NR_TX
init|=
literal|1
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|netmap_vp_adapter
struct_decl|;
end_struct_decl

begin_comment
comment|// forward
end_comment

begin_comment
comment|/*  * The "struct netmap_adapter" extends the "struct adapter"  * (or equivalent) device descriptor.  * It contains all base fields needed to support netmap operation.  * There are in fact different types of netmap adapters  * (native, generic, VALE switch...) so a netmap_adapter is  * just the first field in the derived type.  */
end_comment

begin_struct
struct|struct
name|netmap_adapter
block|{
comment|/* 	 * On linux we do not have a good way to tell if an interface 	 * is netmap-capable. So we always use the following trick: 	 * NA(ifp) points here, and the first entry (which hopefully 	 * always exists and is at least 32 bits) contains a magic 	 * value which we can use to detect that the interface is good. 	 */
name|uint32_t
name|magic
decl_stmt|;
name|uint32_t
name|na_flags
decl_stmt|;
comment|/* enabled, and other flags */
define|#
directive|define
name|NAF_SKIP_INTR
value|1
comment|/* use the regular interrupt handler. 				 * useful during initialization 				 */
define|#
directive|define
name|NAF_SW_ONLY
value|2
comment|/* forward packets only to sw adapter */
define|#
directive|define
name|NAF_BDG_MAYSLEEP
value|4
comment|/* the bridge is allowed to sleep when 				 * forwarding packets coming from this 				 * interface 				 */
define|#
directive|define
name|NAF_MEM_OWNER
value|8
comment|/* the adapter is responsible for the 				 * deallocation of the memory allocator 				 */
define|#
directive|define
name|NAF_NATIVE_ON
value|16
comment|/* the adapter is native and the attached 				 * interface is in netmap mode. 				 * Virtual ports (vale, pipe, monitor...) 				 * should never use this flag. 				 */
define|#
directive|define
name|NAF_NETMAP_ON
value|32
comment|/* netmap is active (either native or 				 * emulated). Where possible (e.g. FreeBSD) 				 * IFCAP_NETMAP also mirrors this flag. 				 */
define|#
directive|define
name|NAF_HOST_RINGS
value|64
comment|/* the adapter supports the host rings */
define|#
directive|define
name|NAF_FORCE_NATIVE
value|128
comment|/* the adapter is always NATIVE */
define|#
directive|define
name|NAF_BUSY
value|(1U<<31)
comment|/* the adapter is used internally and 				  * cannot be registered from userspace 				  */
name|int
name|active_fds
decl_stmt|;
comment|/* number of user-space descriptors using this 			 interface, which is equal to the number of 			 struct netmap_if objs in the mapped region. */
name|u_int
name|num_rx_rings
decl_stmt|;
comment|/* number of adapter receive rings */
name|u_int
name|num_tx_rings
decl_stmt|;
comment|/* number of adapter transmit rings */
name|u_int
name|num_tx_desc
decl_stmt|;
comment|/* number of descriptor in each queue */
name|u_int
name|num_rx_desc
decl_stmt|;
comment|/* tx_rings and rx_rings are private but allocated 	 * as a contiguous chunk of memory. Each array has 	 * N+1 entries, for the adapter queues and for the host queue. 	 */
name|struct
name|netmap_kring
modifier|*
name|tx_rings
decl_stmt|;
comment|/* array of TX rings. */
name|struct
name|netmap_kring
modifier|*
name|rx_rings
decl_stmt|;
comment|/* array of RX rings. */
name|void
modifier|*
name|tailroom
decl_stmt|;
comment|/* space below the rings array */
comment|/* (used for leases) */
name|NM_SELINFO_T
name|tx_si
decl_stmt|,
name|rx_si
decl_stmt|;
comment|/* global wait queues */
comment|/* count users of the global wait queues */
name|int
name|tx_si_users
decl_stmt|,
name|rx_si_users
decl_stmt|;
name|void
modifier|*
name|pdev
decl_stmt|;
comment|/* used to store pci device */
comment|/* copy of if_qflush and if_transmit pointers, to intercept 	 * packets from the network stack when netmap is active. 	 */
name|int
function_decl|(
modifier|*
name|if_transmit
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
comment|/* copy of if_input for netmap_send_up() */
name|void
function_decl|(
modifier|*
name|if_input
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
comment|/* references to the ifnet and device routines, used by 	 * the generic netmap functions. 	 */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* adapter is ifp->if_softc */
comment|/*---- callbacks for this netmap adapter -----*/
comment|/* 	 * nm_dtor() is the cleanup routine called when destroying 	 *	the adapter. 	 *	Called with NMG_LOCK held. 	 * 	 * nm_register() is called on NIOCREGIF and close() to enter 	 *	or exit netmap mode on the NIC 	 *	Called with NNG_LOCK held. 	 * 	 * nm_txsync() pushes packets to the underlying hw/switch 	 * 	 * nm_rxsync() collects packets from the underlying hw/switch 	 * 	 * nm_config() returns configuration information from the OS 	 *	Called with NMG_LOCK held. 	 * 	 * nm_krings_create() create and init the tx_rings and 	 * 	rx_rings arrays of kring structures. In particular, 	 * 	set the nm_sync callbacks for each ring. 	 * 	There is no need to also allocate the corresponding 	 * 	netmap_rings, since netmap_mem_rings_create() will always 	 * 	be called to provide the missing ones. 	 *	Called with NNG_LOCK held. 	 * 	 * nm_krings_delete() cleanup and delete the tx_rings and rx_rings 	 * 	arrays 	 *	Called with NMG_LOCK held. 	 * 	 * nm_notify() is used to act after data have become available 	 * 	(or the stopped state of the ring has changed) 	 *	For hw devices this is typically a selwakeup(), 	 *	but for NIC/host ports attached to a switch (or vice-versa) 	 *	we also need to invoke the 'txsync' code downstream. 	 */
name|void
function_decl|(
modifier|*
name|nm_dtor
function_decl|)
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|nm_register
function_decl|)
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|,
name|int
name|onoff
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|nm_txsync
function_decl|)
parameter_list|(
name|struct
name|netmap_kring
modifier|*
name|kring
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|nm_rxsync
function_decl|)
parameter_list|(
name|struct
name|netmap_kring
modifier|*
name|kring
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
define|#
directive|define
name|NAF_FORCE_READ
value|1
define|#
directive|define
name|NAF_FORCE_RECLAIM
value|2
comment|/* return configuration information */
name|int
function_decl|(
modifier|*
name|nm_config
function_decl|)
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|,
name|u_int
modifier|*
name|txr
parameter_list|,
name|u_int
modifier|*
name|txd
parameter_list|,
name|u_int
modifier|*
name|rxr
parameter_list|,
name|u_int
modifier|*
name|rxd
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|nm_krings_create
function_decl|)
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|nm_krings_delete
function_decl|)
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|nm_notify
function_decl|)
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|,
name|u_int
name|ring
parameter_list|,
name|enum
name|txrx
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
define|#
directive|define
name|NAF_DISABLE_NOTIFY
value|8
comment|/* notify that the stopped state of the 				 * ring has changed (kring->nkr_stopped) 				 */
ifdef|#
directive|ifdef
name|WITH_VALE
comment|/* 	 * nm_bdg_attach() initializes the na_vp field to point 	 *      to an adapter that can be attached to a VALE switch. If the 	 *      current adapter is already a VALE port, na_vp is simply a cast; 	 *      otherwise, na_vp points to a netmap_bwrap_adapter. 	 *      If applicable, this callback also initializes na_hostvp, 	 *      that can be used to connect the adapter host rings to the 	 *      switch. 	 *      Called with NMG_LOCK held. 	 * 	 * nm_bdg_ctl() is called on the actual attach/detach to/from 	 *      to/from the switch, to perform adapter-specific 	 *      initializations 	 *      Called with NMG_LOCK held. 	 */
name|int
function_decl|(
modifier|*
name|nm_bdg_attach
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|bdg_name
parameter_list|,
name|struct
name|netmap_adapter
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|nm_bdg_ctl
function_decl|)
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|,
name|struct
name|nmreq
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* adapter used to attach this adapter to a VALE switch (if any) */
name|struct
name|netmap_vp_adapter
modifier|*
name|na_vp
decl_stmt|;
comment|/* adapter used to attach the host rings of this adapter 	 * to a VALE switch (if any) */
name|struct
name|netmap_vp_adapter
modifier|*
name|na_hostvp
decl_stmt|;
endif|#
directive|endif
comment|/* standard refcount to control the lifetime of the adapter 	 * (it should be equal to the lifetime of the corresponding ifp) 	 */
name|int
name|na_refcount
decl_stmt|;
comment|/* memory allocator (opaque) 	 * We also cache a pointer to the lut_entry for translating 	 * buffer addresses, and the total number of buffers. 	 */
name|struct
name|netmap_mem_d
modifier|*
name|nm_mem
decl_stmt|;
name|struct
name|lut_entry
modifier|*
name|na_lut
decl_stmt|;
name|uint32_t
name|na_lut_objtotal
decl_stmt|;
comment|/* max buffer index */
name|uint32_t
name|na_lut_objsize
decl_stmt|;
comment|/* buffer size */
comment|/* additional information attached to this adapter 	 * by other netmap subsystems. Currently used by 	 * bwrap and LINUX/v1000. 	 */
name|void
modifier|*
name|na_private
decl_stmt|;
ifdef|#
directive|ifdef
name|WITH_PIPES
comment|/* array of pipes that have this adapter as a parent */
name|struct
name|netmap_pipe_adapter
modifier|*
modifier|*
name|na_pipes
decl_stmt|;
name|int
name|na_next_pipe
decl_stmt|;
comment|/* next free slot in the array */
name|int
name|na_max_pipes
decl_stmt|;
comment|/* size of the array */
endif|#
directive|endif
comment|/* WITH_PIPES */
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * If the NIC is owned by the kernel  * (i.e., bridge), neither another bridge nor user can use it;  * if the NIC is owned by a user, only users can share it.  * Evaluation must be done under NMG_LOCK().  */
end_comment

begin_define
define|#
directive|define
name|NETMAP_OWNED_BY_KERN
parameter_list|(
name|na
parameter_list|)
value|((na)->na_flags& NAF_BUSY)
end_define

begin_define
define|#
directive|define
name|NETMAP_OWNED_BY_ANY
parameter_list|(
name|na
parameter_list|)
define|\
value|(NETMAP_OWNED_BY_KERN(na) || ((na)->active_fds> 0))
end_define

begin_comment
comment|/*  * derived netmap adapters for various types of ports  */
end_comment

begin_struct
struct|struct
name|netmap_vp_adapter
block|{
comment|/* VALE software port */
name|struct
name|netmap_adapter
name|up
decl_stmt|;
comment|/* 	 * Bridge support: 	 * 	 * bdg_port is the port number used in the bridge; 	 * na_bdg points to the bridge this NA is attached to. 	 */
name|int
name|bdg_port
decl_stmt|;
name|struct
name|nm_bridge
modifier|*
name|na_bdg
decl_stmt|;
name|int
name|retry
decl_stmt|;
comment|/* Offset of ethernet header for each packet. */
name|u_int
name|virt_hdr_len
decl_stmt|;
comment|/* Maximum Frame Size, used in bdg_mismatch_datapath() */
name|u_int
name|mfs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|netmap_hw_adapter
block|{
comment|/* physical device */
name|struct
name|netmap_adapter
name|up
decl_stmt|;
name|struct
name|net_device_ops
name|nm_ndo
decl_stmt|;
comment|// XXX linux only
name|struct
name|ethtool_ops
name|nm_eto
decl_stmt|;
comment|// XXX linux only
specifier|const
name|struct
name|ethtool_ops
modifier|*
name|save_ethtool
decl_stmt|;
name|int
function_decl|(
modifier|*
name|nm_hw_register
function_decl|)
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|,
name|int
name|onoff
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* Mitigation support. */
end_comment

begin_struct
struct|struct
name|nm_generic_mit
block|{
name|struct
name|hrtimer
name|mit_timer
decl_stmt|;
name|int
name|mit_pending
decl_stmt|;
name|int
name|mit_ring_idx
decl_stmt|;
comment|/* index of the ring being mitigated */
name|struct
name|netmap_adapter
modifier|*
name|mit_na
decl_stmt|;
comment|/* backpointer */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|netmap_generic_adapter
block|{
comment|/* emulated device */
name|struct
name|netmap_hw_adapter
name|up
decl_stmt|;
comment|/* Pointer to a previously used netmap adapter. */
name|struct
name|netmap_adapter
modifier|*
name|prev
decl_stmt|;
comment|/* generic netmap adapters support: 	 * a net_device_ops struct overrides ndo_select_queue(), 	 * save_if_input saves the if_input hook (FreeBSD), 	 * mit implements rx interrupt mitigation, 	 */
name|struct
name|net_device_ops
name|generic_ndo
decl_stmt|;
name|void
function_decl|(
modifier|*
name|save_if_input
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
name|struct
name|nm_generic_mit
modifier|*
name|mit
decl_stmt|;
ifdef|#
directive|ifdef
name|linux
name|netdev_tx_t
function_decl|(
modifier|*
name|save_start_xmit
function_decl|)
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline
name|int
name|netmap_real_tx_rings
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|)
block|{
return|return
name|na
operator|->
name|num_tx_rings
operator|+
operator|!
operator|!
operator|(
name|na
operator|->
name|na_flags
operator|&
name|NAF_HOST_RINGS
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|netmap_real_rx_rings
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|)
block|{
return|return
name|na
operator|->
name|num_rx_rings
operator|+
operator|!
operator|!
operator|(
name|na
operator|->
name|na_flags
operator|&
name|NAF_HOST_RINGS
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_VALE
end_ifdef

begin_comment
comment|/*  * Bridge wrapper for non VALE ports attached to a VALE switch.  *  * The real device must already have its own netmap adapter (hwna).  * The bridge wrapper and the hwna adapter share the same set of  * netmap rings and buffers, but they have two separate sets of  * krings descriptors, with tx/rx meanings swapped:  *  *                                  netmap  *           bwrap     krings       rings      krings      hwna  *         +------+   +------+     +-----+    +------+   +------+  *         |tx_rings->|      |\   /|     |----|      |<-tx_rings|  *         |      |   +------+ \ / +-----+    +------+   |      |  *         |      |             X                        |      |  *         |      |            / \                       |      |  *         |      |   +------+/   \+-----+    +------+   |      |  *         |rx_rings->|      |     |     |----|      |<-rx_rings|  *         |      |   +------+     +-----+    +------+   |      |  *         +------+                                      +------+  *  * - packets coming from the bridge go to the brwap rx rings,  *   which are also the hwna tx rings.  The bwrap notify callback  *   will then complete the hwna tx (see netmap_bwrap_notify).  *  * - packets coming from the outside go to the hwna rx rings,  *   which are also the bwrap tx rings.  The (overwritten) hwna  *   notify method will then complete the bridge tx  *   (see netmap_bwrap_intr_notify).  *  *   The bridge wrapper may optionally connect the hwna 'host' rings  *   to the bridge. This is done by using a second port in the  *   bridge and connecting it to the 'host' netmap_vp_adapter  *   contained in the netmap_bwrap_adapter. The brwap host adapter  *   cross-links the hwna host rings in the same way as shown above.  *  * - packets coming from the bridge and directed to the host stack  *   are handled by the bwrap host notify callback  *   (see netmap_bwrap_host_notify)  *  * - packets coming from the host stack are still handled by the  *   overwritten hwna notify callback (netmap_bwrap_intr_notify),  *   but are diverted to the host adapter depending on the ring number.  *  */
end_comment

begin_struct
struct|struct
name|netmap_bwrap_adapter
block|{
name|struct
name|netmap_vp_adapter
name|up
decl_stmt|;
name|struct
name|netmap_vp_adapter
name|host
decl_stmt|;
comment|/* for host rings */
name|struct
name|netmap_adapter
modifier|*
name|hwna
decl_stmt|;
comment|/* the underlying device */
comment|/* backup of the hwna notify callback */
name|int
function_decl|(
modifier|*
name|save_notify
function_decl|)
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|,
name|u_int
name|ring
parameter_list|,
name|enum
name|txrx
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
comment|/* backup of the hwna memory allocator */
name|struct
name|netmap_mem_d
modifier|*
name|save_nmd
decl_stmt|;
comment|/* 	 * When we attach a physical interface to the bridge, we 	 * allow the controlling process to terminate, so we need 	 * a place to store the n_detmap_priv_d data structure. 	 * This is only done when physical interfaces 	 * are attached to a bridge. 	 */
name|struct
name|netmap_priv_d
modifier|*
name|na_kpriv
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|netmap_bwrap_attach
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|netmap_adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_VALE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_PIPES
end_ifdef

begin_define
define|#
directive|define
name|NM_MAXPIPES
value|64
end_define

begin_comment
comment|/* max number of pipes per adapter */
end_comment

begin_struct
struct|struct
name|netmap_pipe_adapter
block|{
name|struct
name|netmap_adapter
name|up
decl_stmt|;
name|u_int
name|id
decl_stmt|;
comment|/* pipe identifier */
name|int
name|role
decl_stmt|;
comment|/* either NR_REG_PIPE_MASTER or NR_REG_PIPE_SLAVE */
name|struct
name|netmap_adapter
modifier|*
name|parent
decl_stmt|;
comment|/* adapter that owns the memory */
name|struct
name|netmap_pipe_adapter
modifier|*
name|peer
decl_stmt|;
comment|/* the other end of the pipe */
name|int
name|peer_ref
decl_stmt|;
comment|/* 1 iff we are holding a ref to the peer */
name|u_int
name|parent_slot
decl_stmt|;
comment|/* index in the parent pipe array */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_PIPES */
end_comment

begin_comment
comment|/* return slots reserved to rx clients; used in drivers */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|nm_kr_rxspace
parameter_list|(
name|struct
name|netmap_kring
modifier|*
name|k
parameter_list|)
block|{
name|int
name|space
init|=
name|k
operator|->
name|nr_hwtail
operator|-
name|k
operator|->
name|nr_hwcur
decl_stmt|;
if|if
condition|(
name|space
operator|<
literal|0
condition|)
name|space
operator|+=
name|k
operator|->
name|nkr_num_slots
expr_stmt|;
name|ND
argument_list|(
literal|"preserving %d rx slots %d -> %d"
argument_list|,
name|space
argument_list|,
name|k
operator|->
name|nr_hwcur
argument_list|,
name|k
operator|->
name|nr_hwtail
argument_list|)
expr_stmt|;
return|return
name|space
return|;
block|}
end_function

begin_comment
comment|/* True if no space in the tx ring. only valid after txsync_prologue */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|nm_kr_txempty
parameter_list|(
name|struct
name|netmap_kring
modifier|*
name|kring
parameter_list|)
block|{
return|return
name|kring
operator|->
name|rcur
operator|==
name|kring
operator|->
name|nr_hwtail
return|;
block|}
end_function

begin_comment
comment|/*  * protect against multiple threads using the same ring.  * also check that the ring has not been stopped.  * We only care for 0 or !=0 as a return code.  */
end_comment

begin_define
define|#
directive|define
name|NM_KR_BUSY
value|1
end_define

begin_define
define|#
directive|define
name|NM_KR_STOPPED
value|2
end_define

begin_function
specifier|static
name|__inline
name|void
name|nm_kr_put
parameter_list|(
name|struct
name|netmap_kring
modifier|*
name|kr
parameter_list|)
block|{
name|NM_ATOMIC_CLEAR
argument_list|(
operator|&
name|kr
operator|->
name|nr_busy
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|nm_kr_tryget
parameter_list|(
name|struct
name|netmap_kring
modifier|*
name|kr
parameter_list|)
block|{
comment|/* check a first time without taking the lock 	 * to avoid starvation for nm_kr_get() 	 */
if|if
condition|(
name|unlikely
argument_list|(
name|kr
operator|->
name|nkr_stopped
argument_list|)
condition|)
block|{
name|ND
argument_list|(
literal|"ring %p stopped (%d)"
argument_list|,
name|kr
argument_list|,
name|kr
operator|->
name|nkr_stopped
argument_list|)
expr_stmt|;
return|return
name|NM_KR_STOPPED
return|;
block|}
if|if
condition|(
name|unlikely
argument_list|(
name|NM_ATOMIC_TEST_AND_SET
argument_list|(
operator|&
name|kr
operator|->
name|nr_busy
argument_list|)
argument_list|)
condition|)
return|return
name|NM_KR_BUSY
return|;
comment|/* check a second time with lock held */
if|if
condition|(
name|unlikely
argument_list|(
name|kr
operator|->
name|nkr_stopped
argument_list|)
condition|)
block|{
name|ND
argument_list|(
literal|"ring %p stopped (%d)"
argument_list|,
name|kr
argument_list|,
name|kr
operator|->
name|nkr_stopped
argument_list|)
expr_stmt|;
name|nm_kr_put
argument_list|(
name|kr
argument_list|)
expr_stmt|;
return|return
name|NM_KR_STOPPED
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * The following functions are used by individual drivers to  * support netmap operation.  *  * netmap_attach() initializes a struct netmap_adapter, allocating the  * 	struct netmap_ring's and the struct selinfo.  *  * netmap_detach() frees the memory allocated by netmap_attach().  *  * netmap_transmit() replaces the if_transmit routine of the interface,  *	and is used to intercept packets coming from the stack.  *  * netmap_load_map/netmap_reload_map are helper routines to set/reset  *	the dmamap for a packet buffer  *  * netmap_reset() is a helper routine to be called in the hw driver  *	when reinitializing a ring. It should not be called by  *	virtual ports (vale, pipes, monitor)  */
end_comment

begin_function_decl
name|int
name|netmap_attach
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_detach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_transmit
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netmap_slot
modifier|*
name|netmap_reset
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|,
name|enum
name|txrx
name|tx
parameter_list|,
name|u_int
name|n
parameter_list|,
name|u_int
name|new_cur
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_ring_reinit
parameter_list|(
name|struct
name|netmap_kring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* default functions to handle rx/tx interrupts */
end_comment

begin_function_decl
name|int
name|netmap_rx_irq
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|netmap_tx_irq
parameter_list|(
name|_n
parameter_list|,
name|_q
parameter_list|)
value|netmap_rx_irq(_n, _q, NULL)
end_define

begin_function_decl
name|void
name|netmap_common_irq
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
modifier|*
name|work_done
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_VALE
end_ifdef

begin_comment
comment|/* functions used by external modules to interface with VALE */
end_comment

begin_define
define|#
directive|define
name|netmap_vp_to_ifp
parameter_list|(
name|_vp
parameter_list|)
value|((_vp)->up.ifp)
end_define

begin_define
define|#
directive|define
name|netmap_ifp_to_vp
parameter_list|(
name|_ifp
parameter_list|)
value|(NA(_ifp)->na_vp)
end_define

begin_define
define|#
directive|define
name|netmap_ifp_to_host_vp
parameter_list|(
name|_ifp
parameter_list|)
value|(NA(_ifp)->na_hostvp)
end_define

begin_define
define|#
directive|define
name|netmap_bdg_idx
parameter_list|(
name|_vp
parameter_list|)
value|((_vp)->bdg_port)
end_define

begin_function_decl
specifier|const
name|char
modifier|*
name|netmap_bdg_name
parameter_list|(
name|struct
name|netmap_vp_adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !WITH_VALE */
end_comment

begin_define
define|#
directive|define
name|netmap_vp_to_ifp
parameter_list|(
name|_vp
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|netmap_ifp_to_vp
parameter_list|(
name|_ifp
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|netmap_ifp_to_host_vp
parameter_list|(
name|_ifp
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|netmap_bdg_idx
parameter_list|(
name|_vp
parameter_list|)
value|-1
end_define

begin_define
define|#
directive|define
name|netmap_bdg_name
parameter_list|(
name|_vp
parameter_list|)
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_VALE */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|nm_native_on
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|)
block|{
return|return
name|na
operator|&&
name|na
operator|->
name|na_flags
operator|&
name|NAF_NATIVE_ON
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|nm_netmap_on
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|)
block|{
return|return
name|na
operator|&&
name|na
operator|->
name|na_flags
operator|&
name|NAF_NETMAP_ON
return|;
block|}
end_function

begin_comment
comment|/* set/clear native flags and if_transmit/netdev_ops */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|nm_set_native_flags
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|)
block|{
name|struct
name|ifnet
modifier|*
name|ifp
init|=
name|na
operator|->
name|ifp
decl_stmt|;
name|na
operator|->
name|na_flags
operator||=
operator|(
name|NAF_NATIVE_ON
operator||
name|NAF_NETMAP_ON
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|IFCAP_NETMAP
comment|/* or FreeBSD ? */
name|ifp
operator|->
name|if_capenable
operator||=
name|IFCAP_NETMAP
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__FreeBSD__
name|na
operator|->
name|if_transmit
operator|=
name|ifp
operator|->
name|if_transmit
expr_stmt|;
name|ifp
operator|->
name|if_transmit
operator|=
name|netmap_transmit
expr_stmt|;
else|#
directive|else
name|na
operator|->
name|if_transmit
operator|=
operator|(
name|void
operator|*
operator|)
name|ifp
operator|->
name|netdev_ops
expr_stmt|;
name|ifp
operator|->
name|netdev_ops
operator|=
operator|&
operator|(
operator|(
expr|struct
name|netmap_hw_adapter
operator|*
operator|)
name|na
operator|)
operator|->
name|nm_ndo
expr_stmt|;
operator|(
operator|(
expr|struct
name|netmap_hw_adapter
operator|*
operator|)
name|na
operator|)
operator|->
name|save_ethtool
operator|=
name|ifp
operator|->
name|ethtool_ops
expr_stmt|;
name|ifp
operator|->
name|ethtool_ops
operator|=
operator|&
operator|(
operator|(
expr|struct
name|netmap_hw_adapter
operator|*
operator|)
name|na
operator|)
operator|->
name|nm_eto
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|nm_clear_native_flags
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|)
block|{
name|struct
name|ifnet
modifier|*
name|ifp
init|=
name|na
operator|->
name|ifp
decl_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
name|ifp
operator|->
name|if_transmit
operator|=
name|na
operator|->
name|if_transmit
expr_stmt|;
else|#
directive|else
name|ifp
operator|->
name|netdev_ops
operator|=
operator|(
name|void
operator|*
operator|)
name|na
operator|->
name|if_transmit
expr_stmt|;
name|ifp
operator|->
name|ethtool_ops
operator|=
operator|(
operator|(
expr|struct
name|netmap_hw_adapter
operator|*
operator|)
name|na
operator|)
operator|->
name|save_ethtool
expr_stmt|;
endif|#
directive|endif
name|na
operator|->
name|na_flags
operator|&=
operator|~
operator|(
name|NAF_NATIVE_ON
operator||
name|NAF_NETMAP_ON
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|IFCAP_NETMAP
comment|/* or FreeBSD ? */
name|ifp
operator|->
name|if_capenable
operator|&=
operator|~
name|IFCAP_NETMAP
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * validates parameters in the ring/kring, returns a value for head  * If any error, returns ring_size to force a reinit.  */
end_comment

begin_function_decl
name|uint32_t
name|nm_txsync_prologue
parameter_list|(
name|struct
name|netmap_kring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * validates parameters in the ring/kring, returns a value for head,  * and the 'reserved' value in the argument.  * If any error, returns ring_size lim to force a reinit.  */
end_comment

begin_function_decl
name|uint32_t
name|nm_rxsync_prologue
parameter_list|(
name|struct
name|netmap_kring
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * update kring and ring at the end of txsync.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|nm_txsync_finalize
parameter_list|(
name|struct
name|netmap_kring
modifier|*
name|kring
parameter_list|)
block|{
comment|/* update ring tail to what the kernel knows */
name|kring
operator|->
name|ring
operator|->
name|tail
operator|=
name|kring
operator|->
name|rtail
operator|=
name|kring
operator|->
name|nr_hwtail
expr_stmt|;
comment|/* note, head/rhead/hwcur might be behind cur/rcur 	 * if no carrier 	 */
name|ND
argument_list|(
literal|5
argument_list|,
literal|"%s now hwcur %d hwtail %d head %d cur %d tail %d"
argument_list|,
name|kring
operator|->
name|name
argument_list|,
name|kring
operator|->
name|nr_hwcur
argument_list|,
name|kring
operator|->
name|nr_hwtail
argument_list|,
name|kring
operator|->
name|rhead
argument_list|,
name|kring
operator|->
name|rcur
argument_list|,
name|kring
operator|->
name|rtail
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * update kring and ring at the end of rxsync  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|nm_rxsync_finalize
parameter_list|(
name|struct
name|netmap_kring
modifier|*
name|kring
parameter_list|)
block|{
comment|/* tell userspace that there might be new packets */
comment|//struct netmap_ring *ring = kring->ring;
name|ND
argument_list|(
literal|"head %d cur %d tail %d -> %d"
argument_list|,
name|ring
operator|->
name|head
argument_list|,
name|ring
operator|->
name|cur
argument_list|,
name|ring
operator|->
name|tail
argument_list|,
name|kring
operator|->
name|nr_hwtail
argument_list|)
expr_stmt|;
name|kring
operator|->
name|ring
operator|->
name|tail
operator|=
name|kring
operator|->
name|rtail
operator|=
name|kring
operator|->
name|nr_hwtail
expr_stmt|;
comment|/* make a copy of the state for next round */
name|kring
operator|->
name|rhead
operator|=
name|kring
operator|->
name|ring
operator|->
name|head
expr_stmt|;
name|kring
operator|->
name|rcur
operator|=
name|kring
operator|->
name|ring
operator|->
name|cur
expr_stmt|;
block|}
end_function

begin_comment
comment|/* check/fix address and len in tx rings */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/* debug version */
end_comment

begin_define
define|#
directive|define
name|NM_CHECK_ADDR_LEN
parameter_list|(
name|_na
parameter_list|,
name|_a
parameter_list|,
name|_l
parameter_list|)
value|do {				\ 	if (_a == NETMAP_BUF_BASE(_na) || _l> NETMAP_BUF_SIZE(_na)) {	\ 		RD(5, "bad addr/len ring %d slot %d idx %d len %d",	\ 			kring->ring_id, nm_i, slot->buf_idx, len);	\ 		if (_l> NETMAP_BUF_SIZE(_na))				\ 			_l = NETMAP_BUF_SIZE(_na);			\ 	} } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no debug version */
end_comment

begin_define
define|#
directive|define
name|NM_CHECK_ADDR_LEN
parameter_list|(
name|_na
parameter_list|,
name|_a
parameter_list|,
name|_l
parameter_list|)
value|do {				\ 		if (_l> NETMAP_BUF_SIZE(_na))				\ 			_l = NETMAP_BUF_SIZE(_na);			\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------*/
end_comment

begin_comment
comment|/*  * Support routines used by netmap subsystems  * (native drivers, VALE, generic, pipes, monitors, ...)  */
end_comment

begin_comment
comment|/* common routine for all functions that create a netmap adapter. It performs  * two main tasks:  * - if the na points to an ifp, mark the ifp as netmap capable  *   using na as its native adapter;  * - provide defaults for the setup callbacks and the memory allocator  */
end_comment

begin_function_decl
name|int
name|netmap_attach_common
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* common actions to be performed on netmap adapter destruction */
end_comment

begin_function_decl
name|void
name|netmap_detach_common
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fill priv->np_[tr]xq{first,last} using the ringid and flags information  * coming from a struct nmreq  */
end_comment

begin_function_decl
name|int
name|netmap_interp_ringid
parameter_list|(
name|struct
name|netmap_priv_d
modifier|*
name|priv
parameter_list|,
name|uint16_t
name|ringid
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* update the ring parameters (number and size of tx and rx rings).  * It calls the nm_config callback, if available.  */
end_comment

begin_function_decl
name|int
name|netmap_update_config
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* create and initialize the common fields of the krings array.  * using the information that must be already available in the na.  * tailroom can be used to request the allocation of additional  * tailroom bytes after the krings array. This is used by  * netmap_vp_adapter's (i.e., VALE ports) to make room for  * leasing-related data structures  */
end_comment

begin_function_decl
name|int
name|netmap_krings_create
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|,
name|u_int
name|tailroom
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* deletes the kring array of the adapter. The array must have  * been created using netmap_krings_create  */
end_comment

begin_function_decl
name|void
name|netmap_krings_delete
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set the stopped/enabled status of ring  * When stopping, they also wait for all current activity on the ring to  * terminate. The status change is then notified using the na nm_notify  * callback.  */
end_comment

begin_function_decl
name|void
name|netmap_set_txring
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|,
name|u_int
name|ring_id
parameter_list|,
name|int
name|stopped
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_set_rxring
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|,
name|u_int
name|ring_id
parameter_list|,
name|int
name|stopped
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set the stopped/enabled status of all rings of the adapter. */
end_comment

begin_function_decl
name|void
name|netmap_set_all_rings
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|,
name|int
name|stopped
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* convenience wrappers for netmap_set_all_rings, used in drivers */
end_comment

begin_function_decl
name|void
name|netmap_disable_all_rings
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_enable_all_rings
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_rxsync_from_host
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|void
modifier|*
name|pwait
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netmap_if
modifier|*
name|netmap_do_regif
parameter_list|(
name|struct
name|netmap_priv_d
modifier|*
name|priv
parameter_list|,
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|,
name|uint16_t
name|ringid
parameter_list|,
name|uint32_t
name|flags
parameter_list|,
name|int
modifier|*
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|nm_bound_var
parameter_list|(
name|u_int
modifier|*
name|v
parameter_list|,
name|u_int
name|dflt
parameter_list|,
name|u_int
name|lo
parameter_list|,
name|u_int
name|hi
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_get_na
parameter_list|(
name|struct
name|nmreq
modifier|*
name|nmr
parameter_list|,
name|struct
name|netmap_adapter
modifier|*
modifier|*
name|na
parameter_list|,
name|int
name|create
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_get_hw_na
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|netmap_adapter
modifier|*
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_VALE
end_ifdef

begin_comment
comment|/*  * The following bridge-related functions are used by other  * kernel modules.  *  * VALE only supports unicast or broadcast. The lookup  * function can return 0 .. NM_BDG_MAXPORTS-1 for regular ports,  * NM_BDG_MAXPORTS for broadcast, NM_BDG_MAXPORTS+1 for unknown.  * XXX in practice "unknown" might be handled same as broadcast.  */
end_comment

begin_typedef
typedef|typedef
name|u_int
function_decl|(
modifier|*
name|bdg_lookup_fn_t
function_decl|)
parameter_list|(
name|struct
name|nm_bdg_fwd
modifier|*
name|ft
parameter_list|,
name|uint8_t
modifier|*
name|ring_nr
parameter_list|,
specifier|const
name|struct
name|netmap_vp_adapter
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|bdg_config_fn_t
function_decl|)
parameter_list|(
name|struct
name|nm_ifreq
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|bdg_dtor_fn_t
function_decl|)
parameter_list|(
specifier|const
name|struct
name|netmap_vp_adapter
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|netmap_bdg_ops
block|{
name|bdg_lookup_fn_t
name|lookup
decl_stmt|;
name|bdg_config_fn_t
name|config
decl_stmt|;
name|bdg_dtor_fn_t
name|dtor
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|u_int
name|netmap_bdg_learning
parameter_list|(
name|struct
name|nm_bdg_fwd
modifier|*
name|ft
parameter_list|,
name|uint8_t
modifier|*
name|dst_ring
parameter_list|,
specifier|const
name|struct
name|netmap_vp_adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NM_BDG_MAXPORTS
value|254
end_define

begin_comment
comment|/* up to 254 */
end_comment

begin_define
define|#
directive|define
name|NM_BDG_BROADCAST
value|NM_BDG_MAXPORTS
end_define

begin_define
define|#
directive|define
name|NM_BDG_NOPORT
value|(NM_BDG_MAXPORTS+1)
end_define

begin_define
define|#
directive|define
name|NM_NAME
value|"vale"
end_define

begin_comment
comment|/* prefix for bridge port name */
end_comment

begin_comment
comment|/* these are redefined in case of no VALE support */
end_comment

begin_function_decl
name|int
name|netmap_get_bdg_na
parameter_list|(
name|struct
name|nmreq
modifier|*
name|nmr
parameter_list|,
name|struct
name|netmap_adapter
modifier|*
modifier|*
name|na
parameter_list|,
name|int
name|create
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_init_bridges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_bdg_ctl
parameter_list|(
name|struct
name|nmreq
modifier|*
name|nmr
parameter_list|,
name|struct
name|netmap_bdg_ops
modifier|*
name|bdg_ops
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_bdg_config
parameter_list|(
name|struct
name|nmreq
modifier|*
name|nmr
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !WITH_VALE */
end_comment

begin_define
define|#
directive|define
name|netmap_get_bdg_na
parameter_list|(
name|_1
parameter_list|,
name|_2
parameter_list|,
name|_3
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|netmap_init_bridges
parameter_list|(
name|_1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|netmap_bdg_ctl
parameter_list|(
name|_1
parameter_list|,
name|_2
parameter_list|)
value|EINVAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !WITH_VALE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_PIPES
end_ifdef

begin_comment
comment|/* max number of pipes per device */
end_comment

begin_define
define|#
directive|define
name|NM_MAXPIPES
value|64
end_define

begin_comment
comment|/* XXX how many? */
end_comment

begin_comment
comment|/* in case of no error, returns the actual number of pipes in nmr->nr_arg1 */
end_comment

begin_function_decl
name|int
name|netmap_pipe_alloc
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|,
name|struct
name|nmreq
modifier|*
name|nmr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_pipe_dealloc
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_get_pipe_na
parameter_list|(
name|struct
name|nmreq
modifier|*
name|nmr
parameter_list|,
name|struct
name|netmap_adapter
modifier|*
modifier|*
name|na
parameter_list|,
name|int
name|create
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !WITH_PIPES */
end_comment

begin_define
define|#
directive|define
name|NM_MAXPIPES
value|0
end_define

begin_define
define|#
directive|define
name|netmap_pipe_alloc
parameter_list|(
name|_1
parameter_list|,
name|_2
parameter_list|)
value|EOPNOTSUPP
end_define

begin_define
define|#
directive|define
name|netmap_pipe_dealloc
parameter_list|(
name|_1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|netmap_get_pipe_na
parameter_list|(
name|_1
parameter_list|,
name|_2
parameter_list|,
name|_3
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_MONITOR
end_ifdef

begin_function_decl
name|int
name|netmap_get_monitor_na
parameter_list|(
name|struct
name|nmreq
modifier|*
name|nmr
parameter_list|,
name|struct
name|netmap_adapter
modifier|*
modifier|*
name|na
parameter_list|,
name|int
name|create
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|netmap_get_monitor_na
parameter_list|(
name|_1
parameter_list|,
name|_2
parameter_list|,
name|_3
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Various prototypes */
end_comment

begin_function_decl
name|int
name|netmap_poll
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
name|int
name|events
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_get_memory
parameter_list|(
name|struct
name|netmap_priv_d
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_dtor
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_dtor_locked
parameter_list|(
name|struct
name|netmap_priv_d
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_ioctl
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|fflag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* netmap_adapter creation/destruction */
end_comment

begin_comment
comment|// #define NM_DEBUG_PUTGET 1
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NM_DEBUG_PUTGET
end_ifdef

begin_define
define|#
directive|define
name|NM_DBG
parameter_list|(
name|f
parameter_list|)
value|__##f
end_define

begin_function_decl
name|void
name|__netmap_adapter_get
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|netmap_adapter_get
parameter_list|(
name|na
parameter_list|)
define|\
value|do {						\ 		struct netmap_adapter *__na = na;	\ 		D("getting %p:%s (%d)", __na, (__na)->name, (__na)->na_refcount);	\ 		__netmap_adapter_get(__na);		\ 	} while (0)
end_define

begin_function_decl
name|int
name|__netmap_adapter_put
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|netmap_adapter_put
parameter_list|(
name|na
parameter_list|)
define|\
value|({						\ 		struct netmap_adapter *__na = na;	\ 		D("putting %p:%s (%d)", __na, (__na)->name, (__na)->na_refcount);	\ 		__netmap_adapter_put(__na);		\ 	})
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !NM_DEBUG_PUTGET */
end_comment

begin_define
define|#
directive|define
name|NM_DBG
parameter_list|(
name|f
parameter_list|)
value|f
end_define

begin_function_decl
name|void
name|netmap_adapter_get
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_adapter_put
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NM_DEBUG_PUTGET */
end_comment

begin_comment
comment|/*  * module variables  */
end_comment

begin_define
define|#
directive|define
name|NETMAP_BUF_BASE
parameter_list|(
name|na
parameter_list|)
value|((na)->na_lut[0].vaddr)
end_define

begin_define
define|#
directive|define
name|NETMAP_BUF_SIZE
parameter_list|(
name|na
parameter_list|)
value|((na)->na_lut_objsize)
end_define

begin_decl_stmt
specifier|extern
name|int
name|netmap_mitigate
decl_stmt|;
end_decl_stmt

begin_comment
comment|// XXX not really used
end_comment

begin_decl_stmt
specifier|extern
name|int
name|netmap_no_pendintr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|netmap_verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|// XXX debugging
end_comment

begin_enum
enum|enum
block|{
comment|/* verbose flags */
name|NM_VERB_ON
init|=
literal|1
block|,
comment|/* generic verbose */
name|NM_VERB_HOST
init|=
literal|0x2
block|,
comment|/* verbose host stack */
name|NM_VERB_RXSYNC
init|=
literal|0x10
block|,
comment|/* verbose on rxsync/txsync */
name|NM_VERB_TXSYNC
init|=
literal|0x20
block|,
name|NM_VERB_RXINTR
init|=
literal|0x100
block|,
comment|/* verbose on rx/tx intr (driver) */
name|NM_VERB_TXINTR
init|=
literal|0x200
block|,
name|NM_VERB_NIC_RXSYNC
init|=
literal|0x1000
block|,
comment|/* verbose on rx/tx intr (driver) */
name|NM_VERB_NIC_TXSYNC
init|=
literal|0x2000
block|, }
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|int
name|netmap_txsync_retry
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|netmap_generic_mit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|netmap_generic_ringsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|netmap_generic_rings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * NA returns a pointer to the struct netmap adapter from the ifp,  * WNA is used to write it.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WNA
end_ifndef

begin_define
define|#
directive|define
name|WNA
parameter_list|(
name|_ifp
parameter_list|)
value|(_ifp)->if_pspare[0]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NA
parameter_list|(
name|_ifp
parameter_list|)
value|((struct netmap_adapter *)WNA(_ifp))
end_define

begin_comment
comment|/*  * Macros to determine if an interface is netmap capable or netmap enabled.  * See the magic field in struct netmap_adapter.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|/*  * on FreeBSD just use if_capabilities and if_capenable.  */
end_comment

begin_define
define|#
directive|define
name|NETMAP_CAPABLE
parameter_list|(
name|ifp
parameter_list|)
value|(NA(ifp)&&		\ 	(ifp)->if_capabilities& IFCAP_NETMAP )
end_define

begin_define
define|#
directive|define
name|NETMAP_SET_CAPABLE
parameter_list|(
name|ifp
parameter_list|)
define|\
value|(ifp)->if_capabilities |= IFCAP_NETMAP
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* linux */
end_comment

begin_comment
comment|/*  * on linux:  * we check if NA(ifp) is set and its first element has a related  * magic value. The capenable is within the struct netmap_adapter.  */
end_comment

begin_define
define|#
directive|define
name|NETMAP_MAGIC
value|0x52697a7a
end_define

begin_define
define|#
directive|define
name|NETMAP_CAPABLE
parameter_list|(
name|ifp
parameter_list|)
value|(NA(ifp)&&		\ 	((uint32_t)(uintptr_t)NA(ifp) ^ NA(ifp)->magic) == NETMAP_MAGIC )
end_define

begin_define
define|#
directive|define
name|NETMAP_SET_CAPABLE
parameter_list|(
name|ifp
parameter_list|)
define|\
value|NA(ifp)->magic = ((uint32_t)(uintptr_t)NA(ifp)) ^ NETMAP_MAGIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* linux */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_comment
comment|/* Assigns the device IOMMU domain to an allocator.  * Returns -ENOMEM in case the domain is different */
end_comment

begin_define
define|#
directive|define
name|nm_iommu_group_id
parameter_list|(
name|dev
parameter_list|)
value|(0)
end_define

begin_comment
comment|/* Callback invoked by the dma machinery after a successful dmamap_load */
end_comment

begin_function
specifier|static
name|void
name|netmap_dmamap_cb
parameter_list|(
name|__unused
name|void
modifier|*
name|arg
parameter_list|,
name|__unused
name|bus_dma_segment_t
modifier|*
name|segs
parameter_list|,
name|__unused
name|int
name|nseg
parameter_list|,
name|__unused
name|int
name|error
parameter_list|)
block|{ }
end_function

begin_comment
comment|/* bus_dmamap_load wrapper: call aforementioned function if map != NULL.  * XXX can we do it without a callback ?  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|netmap_load_map
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|,
name|bus_dma_tag_t
name|tag
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
block|{
if|if
condition|(
name|map
condition|)
name|bus_dmamap_load
argument_list|(
name|tag
argument_list|,
name|map
argument_list|,
name|buf
argument_list|,
name|NETMAP_BUF_SIZE
argument_list|(
name|na
argument_list|)
argument_list|,
name|netmap_dmamap_cb
argument_list|,
name|NULL
argument_list|,
name|BUS_DMA_NOWAIT
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|netmap_unload_map
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|,
name|bus_dma_tag_t
name|tag
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|)
block|{
if|if
condition|(
name|map
condition|)
name|bus_dmamap_unload
argument_list|(
name|tag
argument_list|,
name|map
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* update the map when a buffer changes. */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|netmap_reload_map
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|,
name|bus_dma_tag_t
name|tag
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
block|{
if|if
condition|(
name|map
condition|)
block|{
name|bus_dmamap_unload
argument_list|(
name|tag
argument_list|,
name|map
argument_list|)
expr_stmt|;
name|bus_dmamap_load
argument_list|(
name|tag
argument_list|,
name|map
argument_list|,
name|buf
argument_list|,
name|NETMAP_BUF_SIZE
argument_list|(
name|na
argument_list|)
argument_list|,
name|netmap_dmamap_cb
argument_list|,
name|NULL
argument_list|,
name|BUS_DMA_NOWAIT
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* linux */
end_comment

begin_function_decl
name|int
name|nm_iommu_group_id
parameter_list|(
name|bus_dma_tag_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|netmap_mem_get_bufsize
parameter_list|(
name|struct
name|netmap_mem_d
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<linux/dma-mapping.h>
end_include

begin_function
specifier|static
specifier|inline
name|void
name|netmap_load_map
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|,
name|bus_dma_tag_t
name|tag
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
block|{
if|if
condition|(
name|map
condition|)
block|{
operator|*
name|map
operator|=
name|dma_map_single
argument_list|(
name|na
operator|->
name|pdev
argument_list|,
name|buf
argument_list|,
name|netmap_mem_get_bufsize
argument_list|(
name|na
operator|->
name|nm_mem
argument_list|)
argument_list|,
name|DMA_BIDIRECTIONAL
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|netmap_unload_map
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|,
name|bus_dma_tag_t
name|tag
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|)
block|{
name|u_int
name|sz
init|=
name|netmap_mem_get_bufsize
argument_list|(
name|na
operator|->
name|nm_mem
argument_list|)
decl_stmt|;
if|if
condition|(
operator|*
name|map
condition|)
block|{
name|dma_unmap_single
argument_list|(
name|na
operator|->
name|pdev
argument_list|,
operator|*
name|map
argument_list|,
name|sz
argument_list|,
name|DMA_BIDIRECTIONAL
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|netmap_reload_map
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|,
name|bus_dma_tag_t
name|tag
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
block|{
name|u_int
name|sz
init|=
name|netmap_mem_get_bufsize
argument_list|(
name|na
operator|->
name|nm_mem
argument_list|)
decl_stmt|;
if|if
condition|(
operator|*
name|map
condition|)
block|{
name|dma_unmap_single
argument_list|(
name|na
operator|->
name|pdev
argument_list|,
operator|*
name|map
argument_list|,
name|sz
argument_list|,
name|DMA_BIDIRECTIONAL
argument_list|)
expr_stmt|;
block|}
operator|*
name|map
operator|=
name|dma_map_single
argument_list|(
name|na
operator|->
name|pdev
argument_list|,
name|buf
argument_list|,
name|sz
argument_list|,
name|DMA_BIDIRECTIONAL
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * XXX How do we redefine these functions:  *  * on linux we need  *	dma_map_single(&pdev->dev, virt_addr, len, direction)  *	dma_unmap_single(&adapter->pdev->dev, phys_addr, len, direction  * The len can be implicit (on netmap it is NETMAP_BUF_SIZE)  * unfortunately the direction is not, so we need to change  * something to have a cross API  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|struct e1000_buffer *buffer_info =&tx_ring->buffer_info[l];
comment|/* set time_stamp *before* dma to help avoid a possible race */
end_comment

begin_comment
unit|buffer_info->time_stamp = jiffies; 	buffer_info->mapped_as_page = false; 	buffer_info->length = len;
comment|//buffer_info->next_to_watch = l;
end_comment

begin_comment
comment|/* reload dma map */
end_comment

begin_comment
unit|dma_unmap_single(&adapter->pdev->dev, buffer_info->dma, 			NETMAP_BUF_SIZE, DMA_TO_DEVICE); 	buffer_info->dma = dma_map_single(&adapter->pdev->dev, 			addr, NETMAP_BUF_SIZE, DMA_TO_DEVICE);  	if (dma_mapping_error(&adapter->pdev->dev, buffer_info->dma)) { 		D("dma mapping error");
comment|/* goto dma_error; See e1000_put_txbuf() */
end_comment

begin_comment
comment|/* XXX reset */
end_comment

begin_comment
unit|} 	tx_desc->buffer_addr = htole64(buffer_info->dma);
comment|//XXX
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The bus_dmamap_sync() can be one of wmb() or rmb() depending on direction.  */
end_comment

begin_define
define|#
directive|define
name|bus_dmamap_sync
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* linux */
end_comment

begin_comment
comment|/*  * functions to map NIC to KRING indexes (n2k) and vice versa (k2n)  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|netmap_idx_n2k
parameter_list|(
name|struct
name|netmap_kring
modifier|*
name|kr
parameter_list|,
name|int
name|idx
parameter_list|)
block|{
name|int
name|n
init|=
name|kr
operator|->
name|nkr_num_slots
decl_stmt|;
name|idx
operator|+=
name|kr
operator|->
name|nkr_hwofs
expr_stmt|;
if|if
condition|(
name|idx
operator|<
literal|0
condition|)
return|return
name|idx
operator|+
name|n
return|;
elseif|else
if|if
condition|(
name|idx
operator|<
name|n
condition|)
return|return
name|idx
return|;
else|else
return|return
name|idx
operator|-
name|n
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|netmap_idx_k2n
parameter_list|(
name|struct
name|netmap_kring
modifier|*
name|kr
parameter_list|,
name|int
name|idx
parameter_list|)
block|{
name|int
name|n
init|=
name|kr
operator|->
name|nkr_num_slots
decl_stmt|;
name|idx
operator|-=
name|kr
operator|->
name|nkr_hwofs
expr_stmt|;
if|if
condition|(
name|idx
operator|<
literal|0
condition|)
return|return
name|idx
operator|+
name|n
return|;
elseif|else
if|if
condition|(
name|idx
operator|<
name|n
condition|)
return|return
name|idx
return|;
else|else
return|return
name|idx
operator|-
name|n
return|;
block|}
end_function

begin_comment
comment|/* Entries of the look-up table. */
end_comment

begin_struct
struct|struct
name|lut_entry
block|{
name|void
modifier|*
name|vaddr
decl_stmt|;
comment|/* virtual address. */
name|vm_paddr_t
name|paddr
decl_stmt|;
comment|/* physical address. */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|netmap_obj_pool
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * NMB return the virtual address of a buffer (buffer 0 on bad index)  * PNMB also fills the physical address  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|NMB
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|,
name|struct
name|netmap_slot
modifier|*
name|slot
parameter_list|)
block|{
name|struct
name|lut_entry
modifier|*
name|lut
init|=
name|na
operator|->
name|na_lut
decl_stmt|;
name|uint32_t
name|i
init|=
name|slot
operator|->
name|buf_idx
decl_stmt|;
return|return
operator|(
name|unlikely
argument_list|(
name|i
operator|>=
name|na
operator|->
name|na_lut_objtotal
argument_list|)
operator|)
condition|?
name|lut
index|[
literal|0
index|]
operator|.
name|vaddr
else|:
name|lut
index|[
name|i
index|]
operator|.
name|vaddr
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|PNMB
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|,
name|struct
name|netmap_slot
modifier|*
name|slot
parameter_list|,
name|uint64_t
modifier|*
name|pp
parameter_list|)
block|{
name|uint32_t
name|i
init|=
name|slot
operator|->
name|buf_idx
decl_stmt|;
name|struct
name|lut_entry
modifier|*
name|lut
init|=
name|na
operator|->
name|na_lut
decl_stmt|;
name|void
modifier|*
name|ret
init|=
operator|(
name|i
operator|>=
name|na
operator|->
name|na_lut_objtotal
operator|)
condition|?
name|lut
index|[
literal|0
index|]
operator|.
name|vaddr
else|:
name|lut
index|[
name|i
index|]
operator|.
name|vaddr
decl_stmt|;
operator|*
name|pp
operator|=
operator|(
name|i
operator|>=
name|na
operator|->
name|na_lut_objtotal
operator|)
condition|?
name|lut
index|[
literal|0
index|]
operator|.
name|paddr
else|:
name|lut
index|[
name|i
index|]
operator|.
name|paddr
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_comment
comment|/* Generic version of NMB, which uses device-specific memory. */
end_comment

begin_function_decl
name|void
name|netmap_txsync_to_host
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Structure associated to each thread which registered an interface.  *  * The first 4 fields of this structure are written by NIOCREGIF and  * read by poll() and NIOC?XSYNC.  *  * There is low contention among writers (a correct user program  * should have none) and among writers and readers, so we use a  * single global lock to protect the structure initialization;  * since initialization involves the allocation of memory,  * we reuse the memory allocator lock.  *  * Read access to the structure is lock free. Readers must check that  * np_nifp is not NULL before using the other fields.  * If np_nifp is NULL initialization has not been performed,  * so they should return an error to userspace.  *  * The ref_done field is used to regulate access to the refcount in the  * memory allocator. The refcount must be incremented at most once for  * each open("/dev/netmap"). The increment is performed by the first  * function that calls netmap_get_memory() (currently called by  * mmap(), NIOCGINFO and NIOCREGIF).  * If the refcount is incremented, it is then decremented when the  * private structure is destroyed.  */
end_comment

begin_struct
struct|struct
name|netmap_priv_d
block|{
name|struct
name|netmap_if
modifier|*
specifier|volatile
name|np_nifp
decl_stmt|;
comment|/* netmap if descriptor. */
name|struct
name|netmap_adapter
modifier|*
name|np_na
decl_stmt|;
name|uint32_t
name|np_flags
decl_stmt|;
comment|/* from the ioctl */
name|u_int
name|np_txqfirst
decl_stmt|,
name|np_txqlast
decl_stmt|;
comment|/* range of tx rings to scan */
name|u_int
name|np_rxqfirst
decl_stmt|,
name|np_rxqlast
decl_stmt|;
comment|/* range of rx rings to scan */
name|uint16_t
name|np_txpoll
decl_stmt|;
comment|/* XXX and also np_rxpoll ? */
name|struct
name|netmap_mem_d
modifier|*
name|np_mref
decl_stmt|;
comment|/* use with NMG_LOCK held */
comment|/* np_refcount is only used on FreeBSD */
name|int
name|np_refcount
decl_stmt|;
comment|/* use with NMG_LOCK held */
comment|/* pointers to the selinfo to be used for selrecord. 	 * Either the local or the global one depending on the 	 * number of rings. 	 */
name|NM_SELINFO_T
modifier|*
name|np_rxsi
decl_stmt|,
modifier|*
name|np_txsi
decl_stmt|;
name|struct
name|thread
modifier|*
name|np_td
decl_stmt|;
comment|/* kqueue, just debugging */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_MONITOR
end_ifdef

begin_struct
struct|struct
name|netmap_monitor_adapter
block|{
name|struct
name|netmap_adapter
name|up
decl_stmt|;
name|struct
name|netmap_priv_d
name|priv
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_MONITOR */
end_comment

begin_comment
comment|/*  * generic netmap emulation for devices that do not have  * native netmap support.  */
end_comment

begin_function_decl
name|int
name|generic_netmap_attach
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_catch_rx
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|,
name|int
name|intercept
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generic_rx_handler
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|netmap_catch_tx
parameter_list|(
name|struct
name|netmap_generic_adapter
modifier|*
name|na
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|generic_xmit_frame
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|u_int
name|len
parameter_list|,
name|u_int
name|ring_nr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|generic_find_num_desc
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|u_int
modifier|*
name|tx
parameter_list|,
name|u_int
modifier|*
name|rx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generic_find_num_queues
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|u_int
modifier|*
name|txq
parameter_list|,
name|u_int
modifier|*
name|rxq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//#define RATE_GENERIC  /* Enables communication statistics for generic. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RATE_GENERIC
end_ifdef

begin_function_decl
name|void
name|generic_rate
parameter_list|(
name|int
name|txp
parameter_list|,
name|int
name|txs
parameter_list|,
name|int
name|txi
parameter_list|,
name|int
name|rxp
parameter_list|,
name|int
name|rxs
parameter_list|,
name|int
name|rxi
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|generic_rate
parameter_list|(
name|txp
parameter_list|,
name|txs
parameter_list|,
name|txi
parameter_list|,
name|rxp
parameter_list|,
name|rxs
parameter_list|,
name|rxi
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * netmap_mitigation API. This is used by the generic adapter  * to reduce the number of interrupt requests/selwakeup  * to clients on incoming packets.  */
end_comment

begin_function_decl
name|void
name|netmap_mitigation_init
parameter_list|(
name|struct
name|nm_generic_mit
modifier|*
name|mit
parameter_list|,
name|int
name|idx
parameter_list|,
name|struct
name|netmap_adapter
modifier|*
name|na
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_mitigation_start
parameter_list|(
name|struct
name|nm_generic_mit
modifier|*
name|mit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_mitigation_restart
parameter_list|(
name|struct
name|nm_generic_mit
modifier|*
name|mit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_mitigation_active
parameter_list|(
name|struct
name|nm_generic_mit
modifier|*
name|mit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_mitigation_cleanup
parameter_list|(
name|struct
name|nm_generic_mit
modifier|*
name|mit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Shared declarations for the VALE switch. */
end_comment

begin_comment
comment|/*  * Each transmit queue accumulates a batch of packets into  * a structure before forwarding. Packets to the same  * destination are put in a list using ft_next as a link field.  * ft_frags and ft_next are valid only on the first fragment.  */
end_comment

begin_struct
struct|struct
name|nm_bdg_fwd
block|{
comment|/* forwarding entry for a bridge */
name|void
modifier|*
name|ft_buf
decl_stmt|;
comment|/* netmap or indirect buffer */
name|uint8_t
name|ft_frags
decl_stmt|;
comment|/* how many fragments (only on 1st frag) */
name|uint8_t
name|_ft_port
decl_stmt|;
comment|/* dst port (unused) */
name|uint16_t
name|ft_flags
decl_stmt|;
comment|/* flags, e.g. indirect */
name|uint16_t
name|ft_len
decl_stmt|;
comment|/* src fragment len */
name|uint16_t
name|ft_next
decl_stmt|;
comment|/* next packet to same destination */
block|}
struct|;
end_struct

begin_comment
comment|/* struct 'virtio_net_hdr' from linux. */
end_comment

begin_struct
struct|struct
name|nm_vnet_hdr
block|{
define|#
directive|define
name|VIRTIO_NET_HDR_F_NEEDS_CSUM
value|1
comment|/* Use csum_start, csum_offset */
define|#
directive|define
name|VIRTIO_NET_HDR_F_DATA_VALID
value|2
comment|/* Csum is valid */
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|VIRTIO_NET_HDR_GSO_NONE
value|0
comment|/* Not a GSO frame */
define|#
directive|define
name|VIRTIO_NET_HDR_GSO_TCPV4
value|1
comment|/* GSO frame, IPv4 TCP (TSO) */
define|#
directive|define
name|VIRTIO_NET_HDR_GSO_UDP
value|3
comment|/* GSO frame, IPv4 UDP (UFO) */
define|#
directive|define
name|VIRTIO_NET_HDR_GSO_TCPV6
value|4
comment|/* GSO frame, IPv6 TCP */
define|#
directive|define
name|VIRTIO_NET_HDR_GSO_ECN
value|0x80
comment|/* TCP has ECN set */
name|uint8_t
name|gso_type
decl_stmt|;
name|uint16_t
name|hdr_len
decl_stmt|;
name|uint16_t
name|gso_size
decl_stmt|;
name|uint16_t
name|csum_start
decl_stmt|;
name|uint16_t
name|csum_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WORST_CASE_GSO_HEADER
value|(14+40+60)
end_define

begin_comment
comment|/* IPv6 + TCP */
end_comment

begin_comment
comment|/* Private definitions for IPv4, IPv6, UDP and TCP headers. */
end_comment

begin_struct
struct|struct
name|nm_iphdr
block|{
name|uint8_t
name|version_ihl
decl_stmt|;
name|uint8_t
name|tos
decl_stmt|;
name|uint16_t
name|tot_len
decl_stmt|;
name|uint16_t
name|id
decl_stmt|;
name|uint16_t
name|frag_off
decl_stmt|;
name|uint8_t
name|ttl
decl_stmt|;
name|uint8_t
name|protocol
decl_stmt|;
name|uint16_t
name|check
decl_stmt|;
name|uint32_t
name|saddr
decl_stmt|;
name|uint32_t
name|daddr
decl_stmt|;
comment|/*The options start here. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nm_tcphdr
block|{
name|uint16_t
name|source
decl_stmt|;
name|uint16_t
name|dest
decl_stmt|;
name|uint32_t
name|seq
decl_stmt|;
name|uint32_t
name|ack_seq
decl_stmt|;
name|uint8_t
name|doff
decl_stmt|;
comment|/* Data offset + Reserved */
name|uint8_t
name|flags
decl_stmt|;
name|uint16_t
name|window
decl_stmt|;
name|uint16_t
name|check
decl_stmt|;
name|uint16_t
name|urg_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nm_udphdr
block|{
name|uint16_t
name|source
decl_stmt|;
name|uint16_t
name|dest
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|check
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nm_ipv6hdr
block|{
name|uint8_t
name|priority_version
decl_stmt|;
name|uint8_t
name|flow_lbl
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|payload_len
decl_stmt|;
name|uint8_t
name|nexthdr
decl_stmt|;
name|uint8_t
name|hop_limit
decl_stmt|;
name|uint8_t
name|saddr
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|daddr
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Type used to store a checksum (in host byte order) that hasn't been  * folded yet.  */
end_comment

begin_define
define|#
directive|define
name|rawsum_t
value|uint32_t
end_define

begin_function_decl
name|rawsum_t
name|nm_csum_raw
parameter_list|(
name|uint8_t
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|,
name|rawsum_t
name|cur_sum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|nm_csum_ipv4
parameter_list|(
name|struct
name|nm_iphdr
modifier|*
name|iph
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nm_csum_tcpudp_ipv4
parameter_list|(
name|struct
name|nm_iphdr
modifier|*
name|iph
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|datalen
parameter_list|,
name|uint16_t
modifier|*
name|check
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nm_csum_tcpudp_ipv6
parameter_list|(
name|struct
name|nm_ipv6hdr
modifier|*
name|ip6h
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|datalen
parameter_list|,
name|uint16_t
modifier|*
name|check
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|nm_csum_fold
parameter_list|(
name|rawsum_t
name|cur_sum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bdg_mismatch_datapath
parameter_list|(
name|struct
name|netmap_vp_adapter
modifier|*
name|na
parameter_list|,
name|struct
name|netmap_vp_adapter
modifier|*
name|dst_na
parameter_list|,
name|struct
name|nm_bdg_fwd
modifier|*
name|ft_p
parameter_list|,
name|struct
name|netmap_ring
modifier|*
name|ring
parameter_list|,
name|u_int
modifier|*
name|j
parameter_list|,
name|u_int
name|lim
parameter_list|,
name|u_int
modifier|*
name|howmany
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* persistent virtual port routines */
end_comment

begin_function_decl
name|int
name|nm_vi_persist
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nm_vi_detach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nm_vi_init_index
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_NETMAP_KERN_H_ */
end_comment

end_unit

