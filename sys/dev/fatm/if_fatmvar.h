begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $FreeBSD$  *  * Fore PCA200E driver definitions.  */
end_comment

begin_comment
comment|/*  * Debug statistics of the PCA200 driver  */
end_comment

begin_struct
struct|struct
name|istats
block|{
name|uint32_t
name|cmd_queue_full
decl_stmt|;
name|uint32_t
name|get_stat_errors
decl_stmt|;
name|uint32_t
name|clr_stat_errors
decl_stmt|;
name|uint32_t
name|get_prom_errors
decl_stmt|;
name|uint32_t
name|suni_reg_errors
decl_stmt|;
name|uint32_t
name|tx_queue_full
decl_stmt|;
name|uint32_t
name|tx_queue_almost_full
decl_stmt|;
name|uint32_t
name|tx_pdu2big
decl_stmt|;
name|uint32_t
name|tx_too_many_segs
decl_stmt|;
name|uint32_t
name|tx_retry
decl_stmt|;
name|uint32_t
name|fix_empty
decl_stmt|;
name|uint32_t
name|fix_addr_copy
decl_stmt|;
name|uint32_t
name|fix_addr_noext
decl_stmt|;
name|uint32_t
name|fix_addr_ext
decl_stmt|;
name|uint32_t
name|fix_len_noext
decl_stmt|;
name|uint32_t
name|fix_len_copy
decl_stmt|;
name|uint32_t
name|fix_len
decl_stmt|;
name|uint32_t
name|rx_badvc
decl_stmt|;
name|uint32_t
name|rx_closed
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Addresses on the on-board RAM are expressed as offsets to the  * start of that RAM.  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|cardoff_t
typedef|;
end_typedef

begin_comment
comment|/*  * The card uses a number of queues for communication with the host.  * Parts of the queue are located on the card (pointers to the status  * word and the ioblk and the command blocks), the rest in host memory.  * Each of these queues forms a ring, where the head and tail pointers are  * managed * either by the card or the host. For the receive queue the  * head is managed by the card (and not used altogether by the host) and the  * tail by the host - for all other queues its the other way around.  * The host resident parts of the queue entries contain pointers to  * the host resident status and the host resident ioblk (the latter not for  * the command queue) as well as DMA addresses for supply to the card.  */
end_comment

begin_struct
struct|struct
name|fqelem
block|{
name|cardoff_t
name|card
decl_stmt|;
comment|/* corresponding element on card */
name|bus_addr_t
name|card_ioblk
decl_stmt|;
comment|/* ioblk address to supply to card */
specifier|volatile
name|uint32_t
modifier|*
name|statp
decl_stmt|;
comment|/* host status pointer */
name|void
modifier|*
name|ioblk
decl_stmt|;
comment|/* host ioblk (not for commands) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fqueue
block|{
name|struct
name|fqelem
modifier|*
name|chunk
decl_stmt|;
comment|/* pointer to the element array */
name|int
name|head
decl_stmt|;
comment|/* queue head */
name|int
name|tail
decl_stmt|;
comment|/* queue tail */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Queue manipulation macros  */
end_comment

begin_define
define|#
directive|define
name|NEXT_QUEUE_ENTRY
parameter_list|(
name|HEAD
parameter_list|,
name|LEN
parameter_list|)
value|((HEAD) = ((HEAD) + 1) % LEN)
end_define

begin_define
define|#
directive|define
name|GET_QUEUE
parameter_list|(
name|Q
parameter_list|,
name|TYPE
parameter_list|,
name|IDX
parameter_list|)
value|(&((TYPE *)(Q).chunk)[(IDX)])
end_define

begin_comment
comment|/*  * Now define structures for the different queues. Each of these structures  * must start with a struct fqelem.  */
end_comment

begin_struct
struct|struct
name|txqueue
block|{
comment|/* transmit queue element */
name|struct
name|fqelem
name|q
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
comment|/* the chain we are transmitting */
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* map for the packet */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rxqueue
block|{
comment|/* receive queue element */
name|struct
name|fqelem
name|q
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|supqueue
block|{
comment|/* supply queue element */
name|struct
name|fqelem
name|q
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|cmdqueue
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fatm_softc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|completion_cb
function_decl|)
parameter_list|(
name|struct
name|fatm_softc
modifier|*
parameter_list|,
name|struct
name|cmdqueue
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|cmdqueue
block|{
comment|/* command queue element */
name|struct
name|fqelem
name|q
decl_stmt|;
name|completion_cb
name|cb
decl_stmt|;
comment|/* call on command completion */
name|int
name|error
decl_stmt|;
comment|/* set if error occured */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Card-DMA-able memory is managed by means of the bus_dma* functions.  * To allocate a chunk of memory with a specific size and alignment one  * has to:  *	1. create a DMA tag  *	2. allocate the memory  *	3. load the memory into a map.  * This finally gives the physical address that can be given to the card.  * The card can DMA the entire 32-bit space without boundaries. We assume,  * that all the allocations can be mapped in one contiguous segment. This  * may be wrong in the future if we have more than 32 bit addresses.  * Allocation is done at attach time and managed by the following structure.  *  * This could be done easier with the NetBSD bus_dma* functions. They appear  * to be more useful and consistent.  */
end_comment

begin_struct
struct|struct
name|fatm_mem
block|{
name|u_int
name|size
decl_stmt|;
comment|/* size */
name|u_int
name|align
decl_stmt|;
comment|/* alignment */
name|bus_dma_tag_t
name|dmat
decl_stmt|;
comment|/* DMA tag */
name|void
modifier|*
name|mem
decl_stmt|;
comment|/* memory block */
name|bus_addr_t
name|paddr
decl_stmt|;
comment|/* pysical address */
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* map */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Each of these structures describes one receive buffer while the buffer  * is on the card or in the receive return queue. These structures are  * allocated at initialisation time together with the DMA maps. The handle that  * is given to the card is the index into the array of these structures.  */
end_comment

begin_struct
struct|struct
name|rbuf
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
comment|/* the mbuf while we are on the card */
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* the map */
name|LIST_ENTRY
argument_list|(
argument|rbuf
argument_list|)
name|link
expr_stmt|;
comment|/* the free list link */
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|rbuf_list
argument_list|,
name|rbuf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * The driver maintains a list of all open VCCs. Because we  * use only VPI=0 and a maximum VCI of 1024, the list is rather an array  * than a list. We also store the atm pseudoheader flags here and the  * rxhand (aka. protocol block).  */
end_comment

begin_struct
struct|struct
name|card_vcc
block|{
name|struct
name|atmio_vcc
name|param
decl_stmt|;
comment|/* traffic parameters */
name|void
modifier|*
name|rxhand
decl_stmt|;
name|u_int
name|vflags
decl_stmt|;
name|uint32_t
name|ipackets
decl_stmt|;
name|uint32_t
name|opackets
decl_stmt|;
name|uint32_t
name|ibytes
decl_stmt|;
name|uint32_t
name|obytes
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FATM_VCC_OPEN
value|0x00010000
end_define

begin_comment
comment|/* is open */
end_comment

begin_define
define|#
directive|define
name|FATM_VCC_TRY_OPEN
value|0x00020000
end_define

begin_comment
comment|/* is currently opening */
end_comment

begin_define
define|#
directive|define
name|FATM_VCC_TRY_CLOSE
value|0x00040000
end_define

begin_comment
comment|/* is currently closing */
end_comment

begin_define
define|#
directive|define
name|FATM_VCC_BUSY
value|0x00070000
end_define

begin_comment
comment|/* one of the above */
end_comment

begin_define
define|#
directive|define
name|FATM_VCC_REOPEN
value|0x00080000
end_define

begin_comment
comment|/* reopening during init */
end_comment

begin_comment
comment|/*  * Finally the softc structure  */
end_comment

begin_struct
struct|struct
name|fatm_softc
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* common part */
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/* lock this structure */
name|struct
name|ifmedia
name|media
decl_stmt|;
comment|/* media */
name|struct
name|callout
name|watchdog_timer
decl_stmt|;
name|int
name|init_state
decl_stmt|;
comment|/* initialisation step */
name|int
name|memid
decl_stmt|;
comment|/* resource id for card memory */
name|struct
name|resource
modifier|*
name|memres
decl_stmt|;
comment|/* resource for card memory */
name|bus_space_handle_t
name|memh
decl_stmt|;
comment|/* handle for card memory */
name|bus_space_tag_t
name|memt
decl_stmt|;
comment|/* tag for card memory */
name|int
name|irqid
decl_stmt|;
comment|/* resource id for interrupt */
name|struct
name|resource
modifier|*
name|irqres
decl_stmt|;
comment|/* resource for interrupt */
name|void
modifier|*
name|ih
decl_stmt|;
comment|/* interrupt handler */
name|bus_dma_tag_t
name|parent_dmat
decl_stmt|;
comment|/* parent DMA tag */
name|struct
name|fatm_mem
name|stat_mem
decl_stmt|;
comment|/* memory for status blocks */
name|struct
name|fatm_mem
name|txq_mem
decl_stmt|;
comment|/* TX descriptor queue */
name|struct
name|fatm_mem
name|rxq_mem
decl_stmt|;
comment|/* RX descriptor queue */
name|struct
name|fatm_mem
name|s1q_mem
decl_stmt|;
comment|/* Small buffer 1 queue */
name|struct
name|fatm_mem
name|l1q_mem
decl_stmt|;
comment|/* Large buffer 1 queue */
name|struct
name|fatm_mem
name|prom_mem
decl_stmt|;
comment|/* PROM memory */
name|struct
name|fqueue
name|txqueue
decl_stmt|;
comment|/* transmission queue */
name|struct
name|fqueue
name|rxqueue
decl_stmt|;
comment|/* receive queue */
name|struct
name|fqueue
name|s1queue
decl_stmt|;
comment|/* SMALL S1 queue */
name|struct
name|fqueue
name|l1queue
decl_stmt|;
comment|/* LARGE S1 queue */
name|struct
name|fqueue
name|cmdqueue
decl_stmt|;
comment|/* command queue */
comment|/* fields for access to the SUNI registers */
name|struct
name|fatm_mem
name|reg_mem
decl_stmt|;
comment|/* DMAable memory for readregs */
name|struct
name|cv
name|cv_regs
decl_stmt|;
comment|/* to serialize access to reg_mem */
comment|/* fields for access to statistics */
name|struct
name|fatm_mem
name|sadi_mem
decl_stmt|;
comment|/* sadistics memory */
name|struct
name|cv
name|cv_stat
decl_stmt|;
comment|/* to serialize access to sadi_mem */
name|u_int
name|flags
decl_stmt|;
define|#
directive|define
name|FATM_STAT_INUSE
value|0x0001
define|#
directive|define
name|FATM_REGS_INUSE
value|0x0002
name|u_int
name|txcnt
decl_stmt|;
comment|/* number of used transmit desc */
name|int
name|retry_tx
decl_stmt|;
comment|/* keep mbufs in queue if full */
name|struct
name|card_vcc
modifier|*
modifier|*
name|vccs
decl_stmt|;
comment|/* table of vccs */
name|int
name|open_vccs
decl_stmt|;
comment|/* number of vccs in use */
name|int
name|small_cnt
decl_stmt|;
comment|/* number of buffers owned by card */
name|int
name|large_cnt
decl_stmt|;
comment|/* number of buffers owned by card */
name|uma_zone_t
name|vcc_zone
decl_stmt|;
comment|/* allocator for VCCs */
comment|/* receiving */
name|struct
name|rbuf
modifier|*
name|rbufs
decl_stmt|;
comment|/* rbuf array */
name|struct
name|rbuf_list
name|rbuf_free
decl_stmt|;
comment|/* free rbufs list */
name|struct
name|rbuf_list
name|rbuf_used
decl_stmt|;
comment|/* used rbufs list */
name|u_int
name|rbuf_total
decl_stmt|;
comment|/* total number of buffs */
name|bus_dma_tag_t
name|rbuf_tag
decl_stmt|;
comment|/* tag for rbuf mapping */
comment|/* transmission */
name|bus_dma_tag_t
name|tx_tag
decl_stmt|;
comment|/* transmission tag */
name|uint32_t
name|heartbeat
decl_stmt|;
comment|/* last heartbeat */
name|u_int
name|stop_cnt
decl_stmt|;
comment|/* how many times checked */
name|struct
name|istats
name|istats
decl_stmt|;
comment|/* internal statistics */
comment|/* SUNI state */
name|struct
name|utopia
name|utopia
decl_stmt|;
comment|/* sysctl support */
name|struct
name|sysctl_ctx_list
name|sysctl_ctx
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sysctl_tree
decl_stmt|;
ifdef|#
directive|ifdef
name|FATM_DEBUG
comment|/* debugging */
name|u_int
name|debug
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|FATM_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|FATM_LOCK
parameter_list|(
name|SC
parameter_list|)
value|mtx_lock(&(SC)->mtx)
end_define

begin_define
define|#
directive|define
name|FATM_UNLOCK
parameter_list|(
name|SC
parameter_list|)
value|mtx_unlock(&(SC)->mtx)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FATM_LOCK
parameter_list|(
name|SC
parameter_list|)
value|do {					\ 	DBG(SC, LOCK, ("locking in line %d", __LINE__));	\ 	mtx_lock(&(SC)->mtx);					\     } while (0)
end_define

begin_define
define|#
directive|define
name|FATM_UNLOCK
parameter_list|(
name|SC
parameter_list|)
value|do {					\ 	DBG(SC, LOCK, ("unlocking in line %d", __LINE__));	\ 	mtx_unlock(&(SC)->mtx);					\     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FATM_CHECKLOCK
parameter_list|(
name|SC
parameter_list|)
value|mtx_assert(&sc->mtx, MA_OWNED)
end_define

begin_comment
comment|/*  * Macros to access host memory fields that are also access by the card.  * These fields need to little-endian always.  */
end_comment

begin_define
define|#
directive|define
name|H_GETSTAT
parameter_list|(
name|STATP
parameter_list|)
value|(le32toh(*(STATP)))
end_define

begin_define
define|#
directive|define
name|H_SETSTAT
parameter_list|(
name|STATP
parameter_list|,
name|S
parameter_list|)
value|do { *(STATP) = htole32(S); } while (0)
end_define

begin_define
define|#
directive|define
name|H_SETDESC
parameter_list|(
name|DESC
parameter_list|,
name|D
parameter_list|)
value|do { (DESC) = htole32(D); } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|H_SYNCSTAT_POSTREAD
parameter_list|(
name|SC
parameter_list|,
name|P
parameter_list|)
define|\
value|bus_dmamap_sync_size((SC)->stat_mem.dmat,			\ 	    (SC)->stat_mem.map,						\ 	    (volatile char *)(P) - (volatile char *)(SC)->stat_mem.mem,	\ 	    sizeof(volatile uint32_t), BUS_DMASYNC_POSTREAD)
end_define

begin_define
define|#
directive|define
name|H_SYNCSTAT_PREWRITE
parameter_list|(
name|SC
parameter_list|,
name|P
parameter_list|)
define|\
value|bus_dmamap_sync_size((SC)->stat_mem.dmat,			\ 	    (SC)->stat_mem.map,						\ 	    (volatile char *)(P) - (volatile char *)(SC)->stat_mem.mem,	\ 	    sizeof(volatile uint32_t), BUS_DMASYNC_PREWRITE)
end_define

begin_define
define|#
directive|define
name|H_SYNCQ_PREWRITE
parameter_list|(
name|M
parameter_list|,
name|P
parameter_list|,
name|SZ
parameter_list|)
define|\
value|bus_dmamap_sync_size((M)->dmat, (M)->map,			\ 	    (volatile char *)(P) - (volatile char *)(M)->mem, (SZ),	\ 	    BUS_DMASYNC_PREWRITE)
end_define

begin_define
define|#
directive|define
name|H_SYNCQ_POSTREAD
parameter_list|(
name|M
parameter_list|,
name|P
parameter_list|,
name|SZ
parameter_list|)
define|\
value|bus_dmamap_sync_size((M)->dmat, (M)->map,			\ 	    (volatile char *)(P) - (volatile char *)(M)->mem, (SZ),	\ 	    BUS_DMASYNC_POSTREAD)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|H_SYNCSTAT_POSTREAD
parameter_list|(
name|SC
parameter_list|,
name|P
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|H_SYNCSTAT_PREWRITE
parameter_list|(
name|SC
parameter_list|,
name|P
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|H_SYNCQ_PREWRITE
parameter_list|(
name|M
parameter_list|,
name|P
parameter_list|,
name|SZ
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|H_SYNCQ_POSTREAD
parameter_list|(
name|M
parameter_list|,
name|P
parameter_list|,
name|SZ
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macros to manipulate VPVCs  */
end_comment

begin_define
define|#
directive|define
name|MKVPVC
parameter_list|(
name|VPI
parameter_list|,
name|VCI
parameter_list|)
value|(((VPI)<< 16) | (VCI))
end_define

begin_define
define|#
directive|define
name|GETVPI
parameter_list|(
name|VPVC
parameter_list|)
value|(((VPVC)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|GETVCI
parameter_list|(
name|VPVC
parameter_list|)
value|((VPVC)& 0xffff)
end_define

begin_comment
comment|/*  * These macros encapsulate the bus_space functions for better readabiliy.  */
end_comment

begin_define
define|#
directive|define
name|WRITE4
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|,
name|VAL
parameter_list|)
value|bus_space_write_4(SC->memt, SC->memh, OFF, VAL)
end_define

begin_define
define|#
directive|define
name|WRITE1
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|,
name|VAL
parameter_list|)
value|bus_space_write_1(SC->memt, SC->memh, OFF, VAL)
end_define

begin_define
define|#
directive|define
name|READ4
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|)
value|bus_space_read_4(SC->memt, SC->memh, OFF)
end_define

begin_define
define|#
directive|define
name|READ1
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|)
value|bus_space_read_1(SC->memt, SC->memh, OFF)
end_define

begin_define
define|#
directive|define
name|BARRIER_R
parameter_list|(
name|SC
parameter_list|)
define|\
value|bus_space_barrier(SC->memt, SC->memh, 0, FATMO_END, \ 	    BUS_SPACE_BARRIER_READ)
end_define

begin_define
define|#
directive|define
name|BARRIER_W
parameter_list|(
name|SC
parameter_list|)
define|\
value|bus_space_barrier(SC->memt, SC->memh, 0, FATMO_END, \ 	    BUS_SPACE_BARRIER_WRITE)
end_define

begin_define
define|#
directive|define
name|BARRIER_RW
parameter_list|(
name|SC
parameter_list|)
define|\
value|bus_space_barrier(SC->memt, SC->memh, 0, FATMO_END, \ 	    BUS_SPACE_BARRIER_WRITE|BUS_SPACE_BARRIER_READ)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FATM_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DBG
parameter_list|(
name|SC
parameter_list|,
name|FL
parameter_list|,
name|PRINT
parameter_list|)
value|do {						\ 	if ((SC)->debug& DBG_##FL) { 					\ 		if_printf(&(SC)->ifatm.ifnet, "%s: ", __func__);	\ 		printf PRINT;						\ 		printf("\n");						\ 	}								\     } while (0)
end_define

begin_define
define|#
directive|define
name|DBGC
parameter_list|(
name|SC
parameter_list|,
name|FL
parameter_list|,
name|PRINT
parameter_list|)
value|do {					\ 	if ((SC)->debug& DBG_##FL) 					\ 		printf PRINT;						\     } while (0)
end_define

begin_enum
enum|enum
block|{
name|DBG_RCV
init|=
literal|0x0001
block|,
name|DBG_XMIT
init|=
literal|0x0002
block|,
name|DBG_VCC
init|=
literal|0x0004
block|,
name|DBG_IOCTL
init|=
literal|0x0008
block|,
name|DBG_ATTACH
init|=
literal|0x0010
block|,
name|DBG_INIT
init|=
literal|0x0020
block|,
name|DBG_DMA
init|=
literal|0x0040
block|,
name|DBG_BEAT
init|=
literal|0x0080
block|,
name|DBG_UART
init|=
literal|0x0100
block|,
name|DBG_LOCK
init|=
literal|0x0200
block|,
name|DBG_ALL
init|=
literal|0xffff
block|}
enum|;
end_enum

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBG
parameter_list|(
name|SC
parameter_list|,
name|FL
parameter_list|,
name|PRINT
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBGC
parameter_list|(
name|SC
parameter_list|,
name|FL
parameter_list|,
name|PRINT
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Configuration.  *  * This section contains tunable parameters and dependend defines.  */
end_comment

begin_define
define|#
directive|define
name|FATM_CMD_QLEN
value|16
end_define

begin_comment
comment|/* command queue length */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TEST_DMA_SYNC
end_ifndef

begin_define
define|#
directive|define
name|FATM_TX_QLEN
value|128
end_define

begin_comment
comment|/* transmit queue length */
end_comment

begin_define
define|#
directive|define
name|FATM_RX_QLEN
value|64
end_define

begin_comment
comment|/* receive queue length */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FATM_TX_QLEN
value|8
end_define

begin_comment
comment|/* transmit queue length */
end_comment

begin_define
define|#
directive|define
name|FATM_RX_QLEN
value|8
end_define

begin_comment
comment|/* receive queue length */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SMALL_SUPPLY_QLEN
value|16
end_define

begin_define
define|#
directive|define
name|SMALL_POOL_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|SMALL_SUPPLY_BLKSIZE
value|8
end_define

begin_define
define|#
directive|define
name|LARGE_SUPPLY_QLEN
value|16
end_define

begin_define
define|#
directive|define
name|LARGE_POOL_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|LARGE_SUPPLY_BLKSIZE
value|8
end_define

end_unit

