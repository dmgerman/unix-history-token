begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2011-2012 Matteo Landi, Luigi Rizzo. All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  * $Id: netmap_kern.h 10602 2012-02-21 16:47:55Z luigi $  *  * The header contains the definitions of constants and function  * prototypes used only in kernelspace.  */
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
name|NM_LOCK_T
value|struct mtx
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
value|spinlock_t
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NETMAP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_struct_decl
struct_decl|struct
name|netmap_adapter
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * private, kernel view of a ring. Keeps track of the status of  * a ring across system calls.  *  *	nr_hwcur	index of the next buffer to refill.  *			It corresponds to ring->cur - ring->reserved  *  *	nr_hwavail	the number of slots "owned" by userspace.  *			nr_hwavail =:= ring->avail + ring->reserved  *  * The indexes in the NIC and netmap rings are offset by nkr_hwofs slots.  * This is so that, on a reset, buffers owned by userspace are not  * modified by the kernel. In particular:  * RX rings: the next empty buffer (hwcur + hwavail + hwofs) coincides with  * 	the next empty buffer as known by the hardware (next_to_check or so).  * TX rings: hwcur + hwofs coincides with next_to_send  */
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
name|int
name|nkr_hwofs
decl_stmt|;
comment|/* offset between NIC and netmap ring */
name|struct
name|netmap_adapter
modifier|*
name|na
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
name|int
name|refcount
decl_stmt|;
comment|/* number of user-space descriptors using this 			 interface, which is equal to the number of 			 struct netmap_if objs in the mapped region. */
name|int
name|separate_locks
decl_stmt|;
comment|/* set if the interface suports different 			       locks for rx, tx and core. */
name|u_int
name|num_rx_queues
decl_stmt|;
comment|/* number of tx/rx queue pairs: this is 			   a duplicate field needed to simplify the 			   signature of ``netmap_detach``. */
name|u_int
name|num_tx_queues
decl_stmt|;
comment|// if nonzero, overrides num_queues XXX
name|u_int
name|num_tx_desc
decl_stmt|;
comment|/* number of descriptor in each queue */
name|u_int
name|num_rx_desc
decl_stmt|;
name|u_int
name|buff_size
decl_stmt|;
comment|// XXX deprecate, use NETMAP_BUF_SIZE
comment|//u_int	flags;	// XXX unused
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
comment|/* copy of if_qflush and if_transmit pointers, to intercept 	 * packets from the network stack when netmap is active. 	 * XXX probably if_qflush is not necessary. 	 */
comment|//void    (*if_qflush)(struct ifnet *);	// XXX unused
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
comment|/*  * The combination of "enable" (ifp->if_capabilities&IFCAP_NETMAP)  * and refcount gives the status of the interface, namely:  *  *	enable	refcount	Status  *  *	FALSE	0		normal operation  *	FALSE	!= 0		-- (impossible)  *	TRUE	1		netmap mode  *	TRUE	0		being deleted.  */
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

begin_decl_stmt
specifier|extern
name|int
name|netmap_buf_size
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NETMAP_BUF_SIZE
value|netmap_buf_size
end_define

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
name|i
operator|>=
name|netmap_total_buffers
operator|)
condition|?
name|netmap_buffer_base
else|:
name|netmap_buffer_base
operator|+
operator|(
name|i
operator|*
name|NETMAP_BUF_SIZE
operator|)
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
name|netmap_buffer_base
else|:
name|netmap_buffer_base
operator|+
operator|(
name|i
operator|*
name|NETMAP_BUF_SIZE
operator|)
decl_stmt|;
operator|*
name|pp
operator|=
name|vtophys
argument_list|(
name|ret
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

