begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Matt Thomas (thomas@lkg.dec.com)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  * $Log: pdq_os.h,v $  * Revision 1.3  1995/07/16  10:07:20  bde  * Fix compiler warnings (systm.h wasn't included).  *  * Revision 1.2  1995/03/25  22:40:49  bde  * Remove wrong redeclarations of printf() and bzero().  Include the correct  * header to declare DELAY().  *  * Revision 1.1  1995/03/14  09:16:07  davidg  * Added support for generic FDDI and the DEC DEFEA and DEFPA FDDI adapters.  *  * Submitted by:	Matt Thomas  *  * Revision 1.6  1995/03/14  01:52:52  thomas  * Update for new FreeBSD PCI Interrupt interface  * Use inl/inb/... inline macros provided by FreeBSD and BSDI  *  * Revision 1.5  1995/03/10  17:42:24  thomas  * More changes for BSDI  *  * Revision 1.4  1995/03/06  17:08:56  thomas  * Add copyright/disclaimer  * Add inx/outx macros  *  * Revision 1.3  1995/03/03  13:48:35  thomas  * more fixes  *  *  */
end_comment

begin_comment
comment|/*  * DEC PDQ FDDI Controller; PDQ O/S dependent definitions  *  * Written by Matt Thomas  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PDQ_OS_H
end_ifndef

begin_define
define|#
directive|define
name|_PDQ_OS_H
end_define

begin_define
define|#
directive|define
name|PDQ_OS_TX_TIMEOUT
value|5
end_define

begin_comment
comment|/* seconds */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PDQTEST
end_ifdef

begin_include
include|#
directive|include
file|<pdq_os_test.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_elif

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

begin_ifndef
ifndef|#
directive|ifndef
name|M_MCAST
end_ifndef

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PDQ_USE_MBUFS
end_define

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
name|PDQ_OS_PAGESIZE
value|NBPG
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
name|PDQ_OS_VA_TO_PA
parameter_list|(
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

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|PDQ_OS_MEMALLOC_CONTIG
parameter_list|(
name|n
parameter_list|)
value|vm_page_alloc_contig(n, 0, 0xffffffff, PAGE_SIZE)
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
value|kmem_free(kernel_map, (vm_offset_t) p, n)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PDQ_OS_MEMALLOC_CONTIG
value|PDQ_OS_MEMALLOC
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMFREE_CONTIG
value|PDQ_OS_MEMFREE
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
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<machine/inline.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PDQ_OS_IORD_32
parameter_list|(
name|port
parameter_list|)
value|inl(port)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IOWR_32
parameter_list|(
name|port
parameter_list|,
name|data
parameter_list|)
value|outl(port, data)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IORD_8
parameter_list|(
name|port
parameter_list|)
value|inb(port)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IOWR_8
parameter_list|(
name|port
parameter_list|,
name|data
parameter_list|)
value|outb(port, data)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDQ_USE_MBUFS
end_ifdef

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_SIZE
value|(MCLBYTES)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_FREE
parameter_list|(
name|b
parameter_list|)
value|(m_freem(b))
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

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_LEN_ADJ
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|((b)->m_len += (n))
end_define

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
name|PDQ_OS_DATABUF_PTR_ADJ
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|((b)->m_data += (n))
end_define

begin_typedef
typedef|typedef
name|struct
name|mbuf
name|PDQ_OS_DATABUF_T
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_ALLOC
parameter_list|(
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PDQ_USE_MBUFS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PDQ_USE_STREAMS
end_ifdef

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_FREE
parameter_list|(
name|b
parameter_list|)
value|(freemsg(b))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_NEXT
parameter_list|(
name|b
parameter_list|)
value|((b)->b_cont)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_NEXTPKT
parameter_list|(
name|b
parameter_list|)
value|((b)->b_next)
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
value|((b)->b_next = (b1))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_LEN
parameter_list|(
name|b
parameter_list|)
value|((b)->b_wptr - (b)->b_rptr)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_PTR
parameter_list|(
name|b
parameter_list|)
value|((pdq_uint8_t *) (b)->b_rptr)
end_define

begin_typedef
typedef|typedef
name|mblk_t
name|PDQ_OS_DATABUF_T
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PDQ_USE_STREAMS */
end_comment

begin_define
define|#
directive|define
name|PDQ_OS_TX_TRANSMIT
value|5
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

begin_function_decl
specifier|extern
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
specifier|extern
name|void
name|pdq_os_receive_pdu
parameter_list|(
name|pdq_t
modifier|*
parameter_list|,
name|PDQ_OS_DATABUF_T
modifier|*
name|pdu
parameter_list|,
name|size_t
name|pdulen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
specifier|extern
name|void
name|pdq_os_transmit_done
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
specifier|extern
name|void
name|pdq_print_fddi_chars
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|,
specifier|const
name|pdq_response_status_chars_get_t
modifier|*
name|rsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_init_csrs
parameter_list|(
name|pdq_csrs_t
modifier|*
name|csrs
parameter_list|,
name|void
modifier|*
name|csrs_va
parameter_list|,
name|size_t
name|csr_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_init_pci_csrs
parameter_list|(
name|pdq_pci_csrs_t
modifier|*
name|csrs
parameter_list|,
name|void
modifier|*
name|csrs_va
parameter_list|,
name|size_t
name|csr_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_flush_databuf_queue
parameter_list|(
name|pdq_databuf_queue_t
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pdq_boolean_t
name|pdq_do_port_control
parameter_list|(
specifier|const
name|pdq_csrs_t
modifier|*
specifier|const
name|csrs
parameter_list|,
name|pdq_uint32_t
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_read_mla
parameter_list|(
specifier|const
name|pdq_csrs_t
modifier|*
specifier|const
name|csrs
parameter_list|,
name|pdq_lanaddr_t
modifier|*
name|hwaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_read_fwrev
parameter_list|(
specifier|const
name|pdq_csrs_t
modifier|*
specifier|const
name|csrs
parameter_list|,
name|pdq_fwrev_t
modifier|*
name|fwrev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pdq_boolean_t
name|pdq_read_error_log
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|,
name|pdq_response_error_log_get_t
modifier|*
name|log_entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pdq_chip_rev_t
name|pdq_read_chiprev
parameter_list|(
specifier|const
name|pdq_csrs_t
modifier|*
specifier|const
name|csrs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_queue_commands
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_process_command_responses
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_process_unsolicited_events
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_process_received_data
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|,
name|pdq_rx_info_t
modifier|*
name|rx
parameter_list|,
name|pdq_rxdesc_t
modifier|*
name|receives
parameter_list|,
name|pdq_uint32_t
name|completion_goal
parameter_list|,
name|pdq_uint32_t
name|ring_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
specifier|extern
name|void
name|pdq_process_transmitted_data
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_flush_transmitter
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pdq_state_t
name|pdq_stop
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
specifier|extern
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
specifier|extern
name|pdq_t
modifier|*
name|pdq_initialize
parameter_list|(
name|void
modifier|*
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PDQ_OS_H */
end_comment

end_unit

