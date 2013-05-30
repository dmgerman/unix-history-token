begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2011-2013 Matteo Landi, Luigi Rizzo. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
value|struct mtx
end_define

begin_define
define|#
directive|define
name|NM_RWLOCK_T
value|struct rwlock
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
name|NM_RWLOCK_T
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
name|NM_SEND_UP
parameter_list|(
name|ifp
parameter_list|,
name|m
parameter_list|)
value|netif_rx(m)
end_define

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
comment|/*  * IFCAP_NETMAP goes into net_device's priv_flags (if_capenable).  * This was 16 bits up to linux 2.6.36, so we need a 16 bit value on older  * platforms and tolerate the clash with IFF_DYNAMIC and IFF_BRIDGE_PORT.  * For the 32-bit value, 0x100000 has no clashes until at least 3.5.1  */
end_comment

begin_if
if|#
directive|if
name|LINUX_VERSION_CODE
operator|<
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|6
operator|,
literal|37
argument_list|)
end_if

begin_define
define|#
directive|define
name|IFCAP_NETMAP
value|0x8000
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IFCAP_NETMAP
value|0x200000
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|do {							\ 		struct timeval __xxts;				\ 		microtime(&__xxts);				\ 		printf("%03d.%06d %s [%d] " format "\n",	\ 		(int)__xxts.tv_sec % 1000, (int)__xxts.tv_usec,	\ 		__FUNCTION__, __LINE__, ##__VA_ARGS__);		\ 	} while (0)
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

begin_comment
comment|/*  * private, kernel view of a ring. Keeps track of the status of  * a ring across system calls.  *  *	nr_hwcur	index of the next buffer to refill.  *			It corresponds to ring->cur - ring->reserved  *  *	nr_hwavail	the number of slots "owned" by userspace.  *			nr_hwavail =:= ring->avail + ring->reserved  *  * The indexes in the NIC and netmap rings are offset by nkr_hwofs slots.  * This is so that, on a reset, buffers owned by userspace are not  * modified by the kernel. In particular:  * RX rings: the next empty buffer (hwcur + hwavail + hwofs) coincides with  * 	the next empty buffer as known by the hardware (next_to_check or so).  * TX rings: hwcur + hwofs coincides with next_to_send  *  * For received packets, slot->flags is set to nkr_slot_flags  * so we can provide a proper initial value (e.g. set NS_FORWARD  * when operating in 'transparent' mode).  */
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
name|u_int
name|nr_hwcur
decl_stmt|;
name|int
name|nr_hwavail
decl_stmt|;
name|u_int
name|nr_kflags
decl_stmt|;
comment|/* private driver flags */
define|#
directive|define
name|NKR_PENDINTR
value|0x1
comment|// Pending interrupt.
name|u_int
name|nkr_num_slots
decl_stmt|;
name|uint16_t
name|nkr_slot_flags
decl_stmt|;
comment|/* initial value for flags */
name|int
name|nkr_hwofs
decl_stmt|;
comment|/* offset between NIC and netmap ring */
name|struct
name|netmap_adapter
modifier|*
name|na
decl_stmt|;
name|struct
name|nm_bdg_fwd
modifier|*
name|nkr_ft
decl_stmt|;
name|NM_SELINFO_T
name|si
decl_stmt|;
comment|/* poll/select wait queue */
name|NM_LOCK_T
name|q_lock
decl_stmt|;
comment|/* used if no device lock available */
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
comment|/*  * This struct extends the 'struct adapter' (or  * equivalent) device descriptor. It contains all fields needed to  * support netmap operation.  */
end_comment

begin_struct
struct|struct
name|netmap_adapter
block|{
comment|/* 	 * On linux we do not have a good way to tell if an interface 	 * is netmap-capable. So we use the following trick: 	 * NA(ifp) points here, and the first entry (which hopefully 	 * always exists and is at least 32 bits) contains a magic 	 * value which we can use to detect that the interface is good. 	 */
name|uint32_t
name|magic
decl_stmt|;
name|uint32_t
name|na_flags
decl_stmt|;
comment|/* future place for IFCAP_NETMAP */
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
name|int
name|refcount
decl_stmt|;
comment|/* number of user-space descriptors using this 			 interface, which is equal to the number of 			 struct netmap_if objs in the mapped region. */
comment|/* 	 * The selwakeup in the interrupt thread can use per-ring 	 * and/or global wait queues. We track how many clients 	 * of each type we have so we can optimize the drivers, 	 * and especially avoid huge contention on the locks. 	 */
name|int
name|na_single
decl_stmt|;
comment|/* threads attached to a single hw queue */
name|int
name|na_multi
decl_stmt|;
comment|/* threads attached to multiple hw queues */
name|int
name|separate_locks
decl_stmt|;
comment|/* set if the interface suports different 			       locks for rx, tx and core. */
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
name|NM_SELINFO_T
name|tx_si
decl_stmt|,
name|rx_si
decl_stmt|;
comment|/* global wait queues */
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
comment|/* references to the ifnet and device routines, used by 	 * the generic netmap functions. 	 */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* adapter is ifp->if_softc */
name|NM_LOCK_T
name|core_lock
decl_stmt|;
comment|/* used if no device lock available */
name|int
function_decl|(
modifier|*
name|nm_register
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
name|onoff
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|nm_lock
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
name|what
parameter_list|,
name|u_int
name|ringid
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|nm_txsync
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_int
name|ring
parameter_list|,
name|int
name|lock
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|nm_rxsync
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_int
name|ring
parameter_list|,
name|int
name|lock
parameter_list|)
function_decl|;
comment|/* return configuration information */
name|int
function_decl|(
modifier|*
name|nm_config
function_decl|)
parameter_list|(
name|struct
name|ifnet
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
comment|/* 	 * Bridge support: 	 * 	 * bdg_port is the port number used in the bridge; 	 * na_bdg_refcount is a refcount used for bridge ports, 	 *	when it goes to 0 we can detach+free this port 	 *	(a bridge port is always attached if it exists; 	 *	it is not always registered) 	 * na_bdg points to the bridge this NA is attached to. 	 */
name|int
name|bdg_port
decl_stmt|;
name|int
name|na_bdg_refcount
decl_stmt|;
name|struct
name|nm_bridge
modifier|*
name|na_bdg
decl_stmt|;
comment|/* When we attach a physical interface to the bridge, we 	 * allow the controlling process to terminate, so we need 	 * a place to store the netmap_priv_d data structure. 	 * This is only done when physical interfaces are attached to a bridge. 	 */
name|struct
name|netmap_priv_d
modifier|*
name|na_kpriv
decl_stmt|;
ifdef|#
directive|ifdef
name|linux
name|struct
name|net_device_ops
name|nm_ndo
decl_stmt|;
endif|#
directive|endif
comment|/* linux */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The combination of "enable" (ifp->if_capenable& IFCAP_NETMAP)  * and refcount gives the status of the interface, namely:  *  *	enable	refcount	Status  *  *	FALSE	0		normal operation  *	FALSE	!= 0		-- (impossible)  *	TRUE	1		netmap mode  *	TRUE	0		being deleted.  */
end_comment

begin_define
define|#
directive|define
name|NETMAP_DELETING
parameter_list|(
name|_na
parameter_list|)
value|(  ((_na)->refcount == 0)&&	\ 	( (_na)->ifp->if_capenable& IFCAP_NETMAP) )
end_define

begin_comment
comment|/*  * parameters for (*nm_lock)(adapter, what, index)  */
end_comment

begin_enum
enum|enum
block|{
name|NETMAP_NO_LOCK
init|=
literal|0
block|,
name|NETMAP_CORE_LOCK
block|,
name|NETMAP_CORE_UNLOCK
block|,
name|NETMAP_TX_LOCK
block|,
name|NETMAP_TX_UNLOCK
block|,
name|NETMAP_RX_LOCK
block|,
name|NETMAP_RX_UNLOCK
block|,
ifdef|#
directive|ifdef
name|__FreeBSD__
define|#
directive|define
name|NETMAP_REG_LOCK
value|NETMAP_CORE_LOCK
define|#
directive|define
name|NETMAP_REG_UNLOCK
value|NETMAP_CORE_UNLOCK
else|#
directive|else
name|NETMAP_REG_LOCK
block|,
name|NETMAP_REG_UNLOCK
endif|#
directive|endif
block|}
enum|;
end_enum

begin_comment
comment|/* How to handle locking support in netmap_rx_irq/netmap_tx_irq */
end_comment

begin_define
define|#
directive|define
name|NETMAP_LOCKED_ENTER
value|0x10000000
end_define

begin_comment
comment|/* already locked on enter */
end_comment

begin_define
define|#
directive|define
name|NETMAP_LOCKED_EXIT
value|0x20000000
end_define

begin_comment
comment|/* keep locked on exit */
end_comment

begin_comment
comment|/*  * The following are support routines used by individual drivers to  * support netmap operation.  *  * netmap_attach() initializes a struct netmap_adapter, allocating the  * 	struct netmap_ring's and the struct selinfo.  *  * netmap_detach() frees the memory allocated by netmap_attach().  *  * netmap_start() replaces the if_transmit routine of the interface,  *	and is used to intercept packets coming from the stack.  *  * netmap_load_map/netmap_reload_map are helper routines to set/reset  *	the dmamap for a packet buffer  *  * netmap_reset() is a helper routine to be called in the driver  *	when reinitializing a ring.  */
end_comment

begin_function_decl
name|int
name|netmap_attach
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|,
name|int
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
name|netmap_start
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
name|int
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
comment|/*  * The following bridge-related interfaces are used by other kernel modules  * In the version that only supports unicast or broadcast, the lookup  * function can return 0 .. NM_BDG_MAXPORTS-1 for regular ports,  * NM_BDG_MAXPORTS for broadcast, NM_BDG_MAXPORTS+1 for unknown.  * XXX in practice "unknown" might be handled same as broadcast.  */
end_comment

begin_typedef
typedef|typedef
name|u_int
function_decl|(
modifier|*
name|bdg_lookup_fn_t
function_decl|)
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|u_int
name|len
parameter_list|,
name|uint8_t
modifier|*
name|ring_nr
parameter_list|,
name|struct
name|netmap_adapter
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|netmap_bdg_ctl
parameter_list|(
name|struct
name|nmreq
modifier|*
name|nmr
parameter_list|,
name|bdg_lookup_fn_t
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|netmap_bdg_learning
parameter_list|(
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|struct
name|netmap_adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NM_NAME
value|"vale"
end_define

begin_comment
comment|/* prefix for the bridge port name */
end_comment

begin_define
define|#
directive|define
name|NM_BDG_MAXPORTS
value|254
end_define

begin_comment
comment|/* up to 32 for bitmap, 254 ok otherwise */
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

begin_decl_stmt
specifier|extern
name|u_int
name|netmap_buf_size
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NETMAP_BUF_SIZE
value|netmap_buf_size
end_define

begin_comment
comment|// XXX remove
end_comment

begin_decl_stmt
specifier|extern
name|int
name|netmap_mitigate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|netmap_no_pendintr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|netmap_total_buffers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|netmap_buffer_base
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

begin_comment
comment|/*  * NA returns a pointer to the struct netmap adapter from the ifp,  * WNA is used to write it.  * SWNA() is used for the "host stack" endpoint associated  *	to an interface. It is allocated together with the main NA(),  *	as an array of two objects.  */
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

begin_define
define|#
directive|define
name|SWNA
parameter_list|(
name|_ifp
parameter_list|)
value|(NA(_ifp) + 1)
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
comment|/* Callback invoked by the dma machinery after a successfull dmamap_load */
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

begin_comment
comment|/* update the map when a buffer changes. */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|netmap_reload_map
parameter_list|(
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

begin_comment
comment|/*  * XXX How do we redefine these functions:  *  * on linux we need  *	dma_map_single(&pdev->dev, virt_addr, len, direction)  *	dma_unmap_single(&adapter->pdev->dev, phys_addr, len, direction  * The len can be implicit (on netmap it is NETMAP_BUF_SIZE)  * unfortunately the direction is not, so we need to change  * something to have a cross API  */
end_comment

begin_define
define|#
directive|define
name|netmap_load_map
parameter_list|(
name|_t
parameter_list|,
name|_m
parameter_list|,
name|_b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|netmap_reload_map
parameter_list|(
name|_t
parameter_list|,
name|_m
parameter_list|,
name|_b
parameter_list|)
end_define

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

begin_decl_stmt
specifier|extern
name|struct
name|lut_entry
modifier|*
name|netmap_buffer_lut
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NMB_VA
parameter_list|(
name|i
parameter_list|)
value|(netmap_buffer_lut[i].vaddr)
end_define

begin_define
define|#
directive|define
name|NMB_PA
parameter_list|(
name|i
parameter_list|)
value|(netmap_buffer_lut[i].paddr)
end_define

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
name|netmap_slot
modifier|*
name|slot
parameter_list|)
block|{
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
name|netmap_total_buffers
argument_list|)
operator|)
condition|?
name|NMB_VA
argument_list|(
literal|0
argument_list|)
else|:
name|NMB_VA
argument_list|(
name|i
argument_list|)
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
name|void
modifier|*
name|ret
init|=
operator|(
name|i
operator|>=
name|netmap_total_buffers
operator|)
condition|?
name|NMB_VA
argument_list|(
literal|0
argument_list|)
else|:
name|NMB_VA
argument_list|(
name|i
argument_list|)
decl_stmt|;
operator|*
name|pp
operator|=
operator|(
name|i
operator|>=
name|netmap_total_buffers
operator|)
condition|?
name|NMB_PA
argument_list|(
literal|0
argument_list|)
else|:
name|NMB_PA
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

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
name|int
parameter_list|,
name|int
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_NETMAP_KERN_H_ */
end_comment

end_unit

