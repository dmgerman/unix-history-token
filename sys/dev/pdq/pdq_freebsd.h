begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pdqvar.h,v 1.27 2000/05/03 19:17:54 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1995, 1996 Matt Thomas<matt@3am-software.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Id: pdqvar.h,v 1.21 1997/03/21 21:16:04 thomas Exp  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * DEC PDQ FDDI Controller; PDQ O/S dependent definitions  *  * Written by Matt Thomas  *  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PDQ_HWSUPPORT
argument_list|)
end_if

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
file|<sys/kernel.h>
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus_memio.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus_pio.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/fddi.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_comment
comment|/* for vtophys */
end_comment

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_comment
comment|/* for vtophys */
end_comment

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_comment
comment|/* for DELAY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PDQ_HWSUPPORT */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_pdq_t
name|pdq_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_pdq_csrs_t
name|pdq_csrs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_pdq_pci_csrs_t
name|pdq_pci_csrs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_pdq_lanaddr_t
name|pdq_lanaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|pdq_uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|pdq_uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|pdq_uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|_pdq_boolean_t
name|pdq_boolean_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|_pdq_type_t
name|pdq_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|_pdq_state_t
name|pdq_state_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mbuf
name|PDQ_OS_DATABUF_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bus_space_tag_t
name|pdq_bus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bus_space_handle_t
name|pdq_bus_memaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pdq_bus_memaddr_t
name|pdq_bus_memoffset_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|devclass_t
name|pdq_devclass
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|_pdq_type_t
block|{
name|PDQ_DEFPA
block|,
comment|/* PCI-bus */
name|PDQ_DEFEA
block|,
comment|/* EISA-bus */
name|PDQ_DEFTA
block|,
comment|/* TurboChannel */
name|PDQ_DEFAA
block|,
comment|/* FutureBus+ */
name|PDQ_DEFQA
comment|/* Q-bus */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|sc_ifmedia
value|ifmedia
end_define

begin_define
define|#
directive|define
name|sc_if
value|arpcom.ac_if
end_define

begin_define
define|#
directive|define
name|sc_bpf
value|sc_if.if_bpf
end_define

begin_define
define|#
directive|define
name|IFQ_DEQUEUE
value|IF_DEQUEUE
end_define

begin_define
define|#
directive|define
name|IFQ_IS_EMPTY
parameter_list|(
name|q
parameter_list|)
value|((q)->ifq_len == 0)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_pdq_os_ctx_t
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
name|struct
name|ifmedia
name|ifmedia
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|int
name|debug
decl_stmt|;
name|pdq_t
modifier|*
name|sc_pdq
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
define|#
directive|define
name|PDQIF_DOWNCALL
value|0x0001
comment|/* active calling from if to pdq */
name|struct
name|resource
modifier|*
name|io
decl_stmt|;
name|int
name|io_rid
decl_stmt|;
name|int
name|io_type
decl_stmt|;
name|bus_space_handle_t
name|io_bsh
decl_stmt|;
name|bus_space_tag_t
name|io_bst
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem
decl_stmt|;
name|int
name|mem_rid
decl_stmt|;
name|int
name|mem_type
decl_stmt|;
name|bus_space_handle_t
name|mem_bsh
decl_stmt|;
name|bus_space_tag_t
name|mem_bst
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|void
modifier|*
name|irq_ih
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
block|}
name|pdq_softc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PDQ_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|PDQ_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_HDR_OFFSET
value|PDQ_RX_FC_OFFSET
end_define

begin_define
define|#
directive|define
name|PDQ_OS_PAGESIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|PDQ_OS_TX_TRANSMIT
value|5
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IORD_32
parameter_list|(
name|bt
parameter_list|,
name|bh
parameter_list|,
name|off
parameter_list|)
value|bus_space_read_4(bt, bh, off)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IOWR_32
parameter_list|(
name|bt
parameter_list|,
name|bh
parameter_list|,
name|off
parameter_list|,
name|data
parameter_list|)
value|bus_space_write_4(bt, bh, off, data)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IORD_8
parameter_list|(
name|bt
parameter_list|,
name|bh
parameter_list|,
name|off
parameter_list|)
value|bus_space_read_1(bt, bh, off)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IOWR_8
parameter_list|(
name|bt
parameter_list|,
name|bh
parameter_list|,
name|off
parameter_list|,
name|data
parameter_list|)
value|bus_space_write_1(bt, bh, off, data)
end_define

begin_define
define|#
directive|define
name|PDQ_CSR_OFFSET
parameter_list|(
name|base
parameter_list|,
name|offset
parameter_list|)
value|(0 + (offset)*sizeof(pdq_uint32_t))
end_define

begin_define
define|#
directive|define
name|PDQ_CSR_WRITE
parameter_list|(
name|csr
parameter_list|,
name|name
parameter_list|,
name|data
parameter_list|)
value|PDQ_OS_IOWR_32((csr)->csr_bus, (csr)->csr_base, (csr)->name, data)
end_define

begin_define
define|#
directive|define
name|PDQ_CSR_READ
parameter_list|(
name|csr
parameter_list|,
name|name
parameter_list|)
value|PDQ_OS_IORD_32((csr)->csr_bus, (csr)->csr_base, (csr)->name)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_FREE
parameter_list|(
name|pdq
parameter_list|,
name|b
parameter_list|)
value|(m_freem(b))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PDQ_OSSUPPORT
argument_list|)
end_if

begin_define
define|#
directive|define
name|PDQ_OS_TX_TIMEOUT
value|5
end_define

begin_comment
comment|/* seconds */
end_comment

begin_define
define|#
directive|define
name|PDQ_OS_IFP_TO_SOFTC
parameter_list|(
name|ifp
parameter_list|)
value|((pdq_softc_t *) (ifp)->if_softc)
end_define

begin_define
define|#
directive|define
name|PDQ_BPF_MTAP
parameter_list|(
name|sc
parameter_list|,
name|m
parameter_list|)
value|bpf_mtap(&(sc)->arpcom.ac_if, m)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PDQ_OSSUPPORT */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PDQ_HWSUPPORT
argument_list|)
end_if

begin_define
define|#
directive|define
name|PDQ_OS_PREFIX
value|"%s%d: "
end_define

begin_define
define|#
directive|define
name|PDQ_OS_PREFIX_ARGS
value|pdq->pdq_os_name, pdq->pdq_unit
end_define

begin_define
define|#
directive|define
name|PDQ_OS_PTR_FMT
value|"%p"
end_define

begin_define
define|#
directive|define
name|PDQ_OS_CSR_FMT
value|"0x%x"
end_define

begin_define
define|#
directive|define
name|PDQ_OS_USEC_DELAY
parameter_list|(
name|n
parameter_list|)
value|DELAY(n)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_VA_TO_BUSPA
parameter_list|(
name|pdq
parameter_list|,
name|p
parameter_list|)
value|vtophys(p)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMALLOC
parameter_list|(
name|n
parameter_list|)
value|malloc(n, M_DEVBUF, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMFREE
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|free((void *) p, M_DEVBUF)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMZERO
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|bzero((caddr_t)(p), (n))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMALLOC_CONTIG
parameter_list|(
name|n
parameter_list|)
value|contigmalloc(n, M_DEVBUF, M_NOWAIT, 0x800000, ~0, PAGE_SIZE, 0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMFREE_CONTIG
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|contigfree(p, n, M_DEVBUF)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_SIZE
value|(MCLBYTES)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_NEXT
parameter_list|(
name|b
parameter_list|)
value|((b)->m_next)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_NEXT_SET
parameter_list|(
name|b
parameter_list|,
name|b1
parameter_list|)
value|((b)->m_next = (b1))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_NEXTPKT
parameter_list|(
name|b
parameter_list|)
value|((b)->m_nextpkt)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_NEXTPKT_SET
parameter_list|(
name|b
parameter_list|,
name|b1
parameter_list|)
value|((b)->m_nextpkt = (b1))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_LEN
parameter_list|(
name|b
parameter_list|)
value|((b)->m_len)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_LEN_SET
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|((b)->m_len = (n))
end_define

begin_comment
comment|/* #define	PDQ_OS_DATABUF_LEN_ADJ(b, n)		((b)->m_len += (n)) */
end_comment

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_PTR
parameter_list|(
name|b
parameter_list|)
value|(mtod((b), pdq_uint8_t *))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_ADJ
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|((b)->m_data += (n), (b)->m_len -= (n))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_ALLOC
parameter_list|(
name|pdq
parameter_list|,
name|b
parameter_list|)
value|do { \     PDQ_OS_DATABUF_T *x_m0; \     MGETHDR(x_m0, M_DONTWAIT, MT_DATA); \     if (x_m0 != NULL) { \ 	MCLGET(x_m0, M_DONTWAIT);	\ 	if ((x_m0->m_flags& M_EXT) == 0) { \ 	    m_free(x_m0); \ 	    (b) = NULL; \ 	} else { \ 	    (b) = x_m0; \ 	    x_m0->m_len = PDQ_OS_DATABUF_SIZE; \ 	} \     } else { \ 	(b) = NULL; \     } \ } while (0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_RESET
parameter_list|(
name|b
parameter_list|)
value|((b)->m_data = (b)->m_ext.ext_buf, (b)->m_len = MCLBYTES)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_ENQUEUE
parameter_list|(
name|q
parameter_list|,
name|b
parameter_list|)
value|do { \     PDQ_OS_DATABUF_NEXTPKT_SET(b, NULL); \     if ((q)->q_tail == NULL) \ 	(q)->q_head = (b); \     else \ 	PDQ_OS_DATABUF_NEXTPKT_SET(((PDQ_OS_DATABUF_T *)(q)->q_tail), b); \     (q)->q_tail = (b); \ } while (0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_DEQUEUE
parameter_list|(
name|q
parameter_list|,
name|b
parameter_list|)
value|do { \     if (((b) = (PDQ_OS_DATABUF_T *) (q)->q_head) != NULL) { \ 	if (((q)->q_head = PDQ_OS_DATABUF_NEXTPKT(b)) == NULL) \ 	    (q)->q_tail = NULL; \ 	PDQ_OS_DATABUF_NEXTPKT_SET(b, NULL); \     } \ } while (0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_BUSPA
parameter_list|(
name|pdq
parameter_list|,
name|b
parameter_list|)
value|PDQ_OS_VA_TO_BUSPA(pdq, PDQ_OS_DATABUF_PTR(b))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_CONSUMER_PRESYNC
parameter_list|(
name|pdq
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_CONSUMER_POSTSYNC
parameter_list|(
name|pdq
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DESC_PRESYNC
parameter_list|(
name|pdq
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DESC_POSTSYNC
parameter_list|(
name|pdq
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_CMDRQST_PRESYNC
parameter_list|(
name|pdq
parameter_list|,
name|s
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_CMDRQST_POSTSYNC
parameter_list|(
name|pdq
parameter_list|,
name|s
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_CMDRSP_PRESYNC
parameter_list|(
name|pdq
parameter_list|,
name|s
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_CMDRSP_POSTSYNC
parameter_list|(
name|pdq
parameter_list|,
name|s
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_RXPDU_PRESYNC
parameter_list|(
name|pdq
parameter_list|,
name|b
parameter_list|,
name|o
parameter_list|,
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_RXPDU_POSTSYNC
parameter_list|(
name|pdq
parameter_list|,
name|b
parameter_list|,
name|o
parameter_list|,
name|l
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_UNSOL_EVENT_PRESYNC
parameter_list|(
name|pdq
parameter_list|,
name|e
parameter_list|)
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_UNSOL_EVENT_POSTSYNC
parameter_list|(
name|pdq
parameter_list|,
name|e
parameter_list|)
value|do { } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PDQ_HWSUPPORT */
end_comment

begin_comment
comment|/*  * OS dependent functions provided by pdq_ifsubr.c to pdq.c  */
end_comment

begin_function_decl
name|void
name|pdq_os_addr_fill
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|,
name|pdq_lanaddr_t
modifier|*
name|addrs
parameter_list|,
name|size_t
name|numaddrs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pdq_os_receive_pdu
parameter_list|(
name|pdq_t
modifier|*
parameter_list|,
name|PDQ_OS_DATABUF_T
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pdq_os_restart_transmitter
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pdq_os_transmit_done
parameter_list|(
name|pdq_t
modifier|*
parameter_list|,
name|PDQ_OS_DATABUF_T
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pdq_os_update_status
parameter_list|(
name|pdq_t
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Driver interfaces functions provided by pdq.c to pdq_ifsubr.c  */
end_comment

begin_function_decl
name|pdq_boolean_t
name|pdq_queue_transmit_data
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|,
name|PDQ_OS_DATABUF_T
modifier|*
name|pdu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pdq_run
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pdq_state_t
name|pdq_stop
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * OS dependent functions provided by  * pdq_ifsubr.c or pdq.c to the bus front ends  */
end_comment

begin_function_decl
name|void
name|pdq_ifattach
parameter_list|(
name|pdq_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pdq_ifdetach
parameter_list|(
name|pdq_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pdq_free
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pdq_interrupt
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pdq_hwreset
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pdq_t
modifier|*
name|pdq_initialize
parameter_list|(
name|pdq_bus_t
name|bus
parameter_list|,
name|pdq_bus_memaddr_t
name|csr_va
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|,
name|pdq_type_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Misc prototypes.  */
end_comment

begin_function_decl
name|void
name|pdq_flush_transmitter
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

end_unit

