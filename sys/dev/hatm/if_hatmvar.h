begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $FreeBSD$  *  * Fore HE driver for NATM  */
end_comment

begin_comment
comment|/*  * Debug statistics of the HE driver  */
end_comment

begin_struct
struct|struct
name|istats
block|{
name|uint32_t
name|tdprq_full
decl_stmt|;
name|uint32_t
name|hbuf_error
decl_stmt|;
name|uint32_t
name|crc_error
decl_stmt|;
name|uint32_t
name|len_error
decl_stmt|;
name|uint32_t
name|flow_closed
decl_stmt|;
name|uint32_t
name|flow_drop
decl_stmt|;
name|uint32_t
name|tpd_no_mem
decl_stmt|;
name|uint32_t
name|rx_seg
decl_stmt|;
name|uint32_t
name|empty_hbuf
decl_stmt|;
name|uint32_t
name|short_aal5
decl_stmt|;
name|uint32_t
name|badlen_aal5
decl_stmt|;
name|uint32_t
name|bug_bad_isw
decl_stmt|;
name|uint32_t
name|bug_no_irq_upd
decl_stmt|;
name|uint32_t
name|itype_tbrq
decl_stmt|;
name|uint32_t
name|itype_tpd
decl_stmt|;
name|uint32_t
name|itype_rbps
decl_stmt|;
name|uint32_t
name|itype_rbpl
decl_stmt|;
name|uint32_t
name|itype_rbrq
decl_stmt|;
name|uint32_t
name|itype_rbrqt
decl_stmt|;
name|uint32_t
name|itype_unknown
decl_stmt|;
name|uint32_t
name|itype_phys
decl_stmt|;
name|uint32_t
name|itype_err
decl_stmt|;
name|uint32_t
name|defrag
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Card memory layout parameters */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_MEM_LAYOUT
value|{						\ 	{
comment|/* 155 */
value|\ 	  20,
comment|/* cells_per_row */
value|\ 	  1024,
comment|/* bytes_per_row */
value|\ 	  512,
comment|/* r0_numrows */
value|\ 	  1018,
comment|/* tx_numrows */
value|\ 	  512,
comment|/* r1_numrows */
value|\ 	  6,
comment|/* r0_startrow */
value|\ 	  2
comment|/* cells_per_lbuf */
value|\ 	}, {
comment|/* 622 */
value|\ 	  40,
comment|/* cells_per_row */
value|\ 	  2048,
comment|/* bytes_per_row */
value|\ 	  256,
comment|/* r0_numrows */
value|\ 	  512,
comment|/* tx_numrows */
value|\ 	  256,
comment|/* r1_numrows */
value|\ 	  0,
comment|/* r0_startrow */
value|\ 	  4
comment|/* cells_per_lbuf */
value|\ 	}								\ }
end_define

begin_comment
comment|/*********************************************************************/
end_comment

begin_struct_decl
struct_decl|struct
name|hatm_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * A chunk of DMA-able memory  */
end_comment

begin_struct
struct|struct
name|dmamem
block|{
name|u_int
name|size
decl_stmt|;
comment|/* in bytes */
name|u_int
name|align
decl_stmt|;
comment|/* alignement */
name|bus_dma_tag_t
name|tag
decl_stmt|;
comment|/* DMA tag */
name|void
modifier|*
name|base
decl_stmt|;
comment|/* the memory */
name|bus_addr_t
name|paddr
decl_stmt|;
comment|/* physical address */
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* the MAP */
block|}
struct|;
end_struct

begin_comment
comment|/*  * RBP (Receive Buffer Pool) queue entry and queue.  */
end_comment

begin_struct
struct|struct
name|herbp
block|{
name|u_int
name|size
decl_stmt|;
comment|/* RBP number of entries (power of two) */
name|u_int
name|thresh
decl_stmt|;
comment|/* interrupt treshold */
name|uint32_t
name|bsize
decl_stmt|;
comment|/* buffer size in bytes */
name|u_int
name|offset
decl_stmt|;
comment|/* free space at start for small bufs */
name|uint32_t
name|mask
decl_stmt|;
comment|/* mask for index */
name|struct
name|dmamem
name|mem
decl_stmt|;
comment|/* the queue area */
name|struct
name|he_rbpen
modifier|*
name|rbp
decl_stmt|;
name|uint32_t
name|head
decl_stmt|,
name|tail
decl_stmt|;
comment|/* head and tail */
block|}
struct|;
end_struct

begin_comment
comment|/*  * RBRQ (Receive Buffer Return Queue) entry and queue.  */
end_comment

begin_struct
struct|struct
name|herbrq
block|{
name|u_int
name|size
decl_stmt|;
comment|/* number of entries */
name|u_int
name|thresh
decl_stmt|;
comment|/* interrupt threshold */
name|u_int
name|tout
decl_stmt|;
comment|/* timeout value */
name|u_int
name|pcnt
decl_stmt|;
comment|/* packet count threshold */
name|struct
name|dmamem
name|mem
decl_stmt|;
comment|/* memory */
name|struct
name|he_rbrqen
modifier|*
name|rbrq
decl_stmt|;
name|uint32_t
name|head
decl_stmt|;
comment|/* driver end */
block|}
struct|;
end_struct

begin_comment
comment|/*  * TPDRQ (Transmit Packet Descriptor Ready Queue) entry and queue  */
end_comment

begin_struct
struct|struct
name|hetpdrq
block|{
name|u_int
name|size
decl_stmt|;
comment|/* number of entries */
name|struct
name|dmamem
name|mem
decl_stmt|;
comment|/* memory */
name|struct
name|he_tpdrqen
modifier|*
name|tpdrq
decl_stmt|;
name|u_int
name|head
decl_stmt|;
comment|/* head (copy of adapter) */
name|u_int
name|tail
decl_stmt|;
comment|/* written back to adapter */
block|}
struct|;
end_struct

begin_comment
comment|/*  * TBRQ (Transmit Buffer Return Queue) entry and queue  */
end_comment

begin_struct
struct|struct
name|hetbrq
block|{
name|u_int
name|size
decl_stmt|;
comment|/* number of entries */
name|u_int
name|thresh
decl_stmt|;
comment|/* interrupt threshold */
name|struct
name|dmamem
name|mem
decl_stmt|;
comment|/* memory */
name|struct
name|he_tbrqen
modifier|*
name|tbrq
decl_stmt|;
name|u_int
name|head
decl_stmt|;
comment|/* adapter end */
block|}
struct|;
end_struct

begin_comment
comment|/*==================================================================*/
end_comment

begin_comment
comment|/*  * TPDs are 32 byte and must be aligned on 64 byte boundaries. That means,  * that half of the space is free. We use this space to plug in a link for  * the list of free TPDs. Note, that the m_act member of the mbufs contain  * a pointer to the dmamap.  *  * The maximum number of TDPs is the size of the common transmit packet  * descriptor ready queue plus the sizes of the transmit buffer return queues  * (currently only queue 0). We allocate and map these TPD when initializing  * the card. We also allocate on DMA map for each TPD. Only the map in the  * last TPD of a packets is used when a packet is transmitted.  * This is signalled by having the mbuf member of this TPD non-zero and  * pointing to the mbuf.  */
end_comment

begin_define
define|#
directive|define
name|HE_TPD_SIZE
value|64
end_define

begin_struct
struct|struct
name|tpd
block|{
name|struct
name|he_tpd
name|tpd
decl_stmt|;
comment|/* at beginning */
name|SLIST_ENTRY
argument_list|(
argument|tpd
argument_list|)
name|link
expr_stmt|;
comment|/* free cid list link */
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
comment|/* the buf chain */
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* map */
name|uint32_t
name|cid
decl_stmt|;
comment|/* CID */
name|uint16_t
name|no
decl_stmt|;
comment|/* number of this tpd */
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|tpd_list
argument_list|,
name|tpd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|TPD_SET_USED
parameter_list|(
name|SC
parameter_list|,
name|I
parameter_list|)
value|do {				\ 	(SC)->tpd_used[(I) / 8] |= (1<< ((I) % 8));		\     } while (0)
end_define

begin_define
define|#
directive|define
name|TPD_CLR_USED
parameter_list|(
name|SC
parameter_list|,
name|I
parameter_list|)
value|do {				\ 	(SC)->tpd_used[(I) / 8]&= ~(1<< ((I) % 8));		\     } while (0)
end_define

begin_define
define|#
directive|define
name|TPD_TST_USED
parameter_list|(
name|SC
parameter_list|,
name|I
parameter_list|)
value|((SC)->tpd_used[(I) / 8]& (1<< ((I) % 8)))
end_define

begin_define
define|#
directive|define
name|TPD_ADDR
parameter_list|(
name|SC
parameter_list|,
name|I
parameter_list|)
value|((struct tpd *)((char *)sc->tpds.base +	\     (I) * HE_TPD_SIZE))
end_define

begin_comment
comment|/*==================================================================*/
end_comment

begin_comment
comment|/*  * External MBUFs. The card needs a lot of mbufs in the pools for high  * performance. The problem with using mbufs directly is that we would need  * a dmamap for each of the mbufs. This can exhaust iommu space on the sparc  * and it eats also a lot of processing time. So we use external mbufs  * for the small buffers and clusters for the large buffers.  * For receive group 0 we use 5 ATM cells, for group 1 one (52 byte) ATM  * cell. The mbuf storage is allocated pagewise and one dmamap is used per  * page.  *  * The handle we give to the card for the small buffers is a word combined  * of the page number and the number of the chunk in the page. This restricts  * the number of chunks per page to 256 (8 bit) and the number of pages to  * 65536 (16 bits).  *  * A chunk may be in one of three states: free, on the card and floating around  * in the system. If it is free, it is on one of the two free lists and  * start with a struct mbufx_free. Each page has a bitmap that tracks where  * its chunks are.  *  * For large buffers we use mbuf clusters. Here we have two problems: we need  * to track the buffers on the card (in the case we want to stop it) and  * we need to map the 64bit mbuf address to a 26bit handle for 64-bit machines.  * The card uses the buffers in the order we give it to the card. Therefor  * we can use a private array holding pointers to the mbufs as a circular  * queue for both tasks. This is done with the lbufs member of softc. The  * handle for these buffer is the lbufs index ored with a flag.  */
end_comment

begin_define
define|#
directive|define
name|MBUF0_SIZE
value|(5 * 48)
end_define

begin_comment
comment|/* 240 */
end_comment

begin_define
define|#
directive|define
name|MBUF1_SIZE
value|(52)
end_define

begin_define
define|#
directive|define
name|MBUF0_CHUNK
value|256
end_define

begin_comment
comment|/* 16 free bytes */
end_comment

begin_define
define|#
directive|define
name|MBUF1_CHUNK
value|96
end_define

begin_comment
comment|/* 44 free bytes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XXX
end_ifdef

begin_define
define|#
directive|define
name|MBUF0_OFFSET
value|(MBUF0_CHUNK - sizeof(struct mbuf_chunk_hdr) \     - MBUF0_SIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MBUF0_OFFSET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MBUF1_OFFSET
value|(MBUF1_CHUNK - sizeof(struct mbuf_chunk_hdr) \     - MBUF1_SIZE)
end_define

begin_define
define|#
directive|define
name|MBUFL_OFFSET
value|16
end_define

begin_comment
comment|/* two pointers for HARP */
end_comment

begin_define
define|#
directive|define
name|MBUF_ALLOC_SIZE
value|(PAGE_SIZE)
end_define

begin_comment
comment|/* each allocated page has one of these structures at its very end. */
end_comment

begin_struct
struct|struct
name|mbuf_page_hdr
block|{
name|uint8_t
name|card
index|[
literal|32
index|]
decl_stmt|;
comment|/* bitmap for on-card */
name|uint8_t
name|used
index|[
literal|32
index|]
decl_stmt|;
comment|/* bitmap for used but not on-card */
name|uint16_t
name|nchunks
decl_stmt|;
comment|/* chunks on this page */
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* the DMA MAP */
name|uint32_t
name|phys
decl_stmt|;
comment|/* physical base address */
name|uint32_t
name|hdroff
decl_stmt|;
comment|/* chunk header offset */
name|uint32_t
name|chunksize
decl_stmt|;
comment|/* chunk size */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mbuf_page
block|{
name|char
name|storage
index|[
name|MBUF_ALLOC_SIZE
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|mbuf_page_hdr
argument_list|)
index|]
decl_stmt|;
name|struct
name|mbuf_page_hdr
name|hdr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* numbers per page */
end_comment

begin_define
define|#
directive|define
name|MBUF0_PER_PAGE
value|((MBUF_ALLOC_SIZE - sizeof(struct mbuf_page_hdr)) / \     MBUF0_CHUNK)
end_define

begin_define
define|#
directive|define
name|MBUF1_PER_PAGE
value|((MBUF_ALLOC_SIZE - sizeof(struct mbuf_page_hdr)) / \     MBUF1_CHUNK)
end_define

begin_define
define|#
directive|define
name|MBUF_CLR_BIT
parameter_list|(
name|ARRAY
parameter_list|,
name|BIT
parameter_list|)
value|((ARRAY)[(BIT) / 8]&= ~(1<< ((BIT) % 8)))
end_define

begin_define
define|#
directive|define
name|MBUF_SET_BIT
parameter_list|(
name|ARRAY
parameter_list|,
name|BIT
parameter_list|)
value|((ARRAY)[(BIT) / 8] |= (1<< ((BIT) % 8)))
end_define

begin_define
define|#
directive|define
name|MBUF_TST_BIT
parameter_list|(
name|ARRAY
parameter_list|,
name|BIT
parameter_list|)
value|((ARRAY)[(BIT) / 8]& (1<< ((BIT) % 8)))
end_define

begin_define
define|#
directive|define
name|MBUF_MAKE_HANDLE
parameter_list|(
name|PAGENO
parameter_list|,
name|CHUNKNO
parameter_list|)
define|\
value|(((PAGENO)<< 10) | (CHUNKNO))
end_define

begin_define
define|#
directive|define
name|MBUF_PARSE_HANDLE
parameter_list|(
name|HANDLE
parameter_list|,
name|PAGENO
parameter_list|,
name|CHUNKNO
parameter_list|)
value|do {	\ 	(CHUNKNO) = (HANDLE)& 0x3ff;			\ 	(PAGENO) = ((HANDLE)>> 10)& 0x3ff;		\     } while (0)
end_define

begin_define
define|#
directive|define
name|MBUF_LARGE_FLAG
value|(1<< 20)
end_define

begin_comment
comment|/* chunks have the following structure at the end */
end_comment

begin_struct
struct|struct
name|mbuf_chunk_hdr
block|{
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
name|uint16_t
name|pageno
decl_stmt|;
name|uint16_t
name|chunkno
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MBUFX_STORAGE_SIZE
parameter_list|(
name|X
parameter_list|)
value|(MBUF##X##_CHUNK	\     - sizeof(struct mbuf_chunk_hdr))
end_define

begin_struct
struct|struct
name|mbuf0_chunk
block|{
name|char
name|storage
index|[
name|MBUFX_STORAGE_SIZE
argument_list|(
literal|0
argument_list|)
index|]
decl_stmt|;
name|struct
name|mbuf_chunk_hdr
name|hdr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mbuf1_chunk
block|{
name|char
name|storage
index|[
name|MBUFX_STORAGE_SIZE
argument_list|(
literal|1
argument_list|)
index|]
decl_stmt|;
name|struct
name|mbuf_chunk_hdr
name|hdr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mbufx_free
block|{
name|SLIST_ENTRY
argument_list|(
argument|mbufx_free
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|mbufx_free_list
argument_list|,
name|mbufx_free
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*==================================================================*/
end_comment

begin_comment
comment|/*  * Interrupt queue  */
end_comment

begin_struct
struct|struct
name|heirq
block|{
name|u_int
name|size
decl_stmt|;
comment|/* number of entries */
name|u_int
name|thresh
decl_stmt|;
comment|/* re-interrupt threshold */
name|u_int
name|line
decl_stmt|;
comment|/* interrupt line to use */
name|struct
name|dmamem
name|mem
decl_stmt|;
comment|/* interrupt queues */
name|uint32_t
modifier|*
name|irq
decl_stmt|;
comment|/* interrupt queue */
name|uint32_t
name|head
decl_stmt|;
comment|/* head index */
name|uint32_t
modifier|*
name|tailp
decl_stmt|;
comment|/* pointer to tail */
name|struct
name|hatm_softc
modifier|*
name|sc
decl_stmt|;
comment|/* back pointer */
name|u_int
name|group
decl_stmt|;
comment|/* interrupt group */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure describes all information for a VCC open on the card.  * The array of these structures is indexed by the compressed connection ID  * (CID).  */
end_comment

begin_struct
struct|struct
name|hevcc
block|{
name|u_int
name|vflags
decl_stmt|;
comment|/* private flags */
name|void
modifier|*
name|rxhand
decl_stmt|;
comment|/* NATM protocol block */
name|u_int
name|rc
decl_stmt|;
comment|/* rate control group for CBR */
name|struct
name|mbuf
modifier|*
name|chain
decl_stmt|;
comment|/* partial received PDU */
name|struct
name|mbuf
modifier|*
name|last
decl_stmt|;
comment|/* last mbuf in chain */
comment|/* from the OPEN_VCC ioctl */
name|struct
name|atmio_vcc
name|param
decl_stmt|;
comment|/* traffic parameters */
name|uint32_t
name|ibytes
decl_stmt|;
name|uint32_t
name|ipackets
decl_stmt|;
name|uint32_t
name|obytes
decl_stmt|;
name|uint32_t
name|opackets
decl_stmt|;
name|u_int
name|ntpds
decl_stmt|;
comment|/* number of active TPDs */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HE_VCC_OPEN
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|HE_VCC_RX_OPEN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HE_VCC_RX_CLOSING
value|0x00020000
end_define

begin_define
define|#
directive|define
name|HE_VCC_TX_OPEN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|HE_VCC_TX_CLOSING
value|0x00080000
end_define

begin_define
define|#
directive|define
name|HE_VCC_FLOW_CTRL
value|0x00100000
end_define

begin_define
define|#
directive|define
name|HE_VCC_ASYNC
value|0x00200000
end_define

begin_comment
comment|/*  * CBR rate groups  */
end_comment

begin_struct
struct|struct
name|herg
block|{
name|u_int
name|refcnt
decl_stmt|;
comment|/* how many connections reference this group */
name|u_int
name|rate
decl_stmt|;
comment|/* the value */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Softc  */
end_comment

begin_struct
struct|struct
name|hatm_softc
block|{
name|struct
name|ifatm
name|ifatm
decl_stmt|;
comment|/* common ATM stuff */
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/* lock */
name|struct
name|ifmedia
name|media
decl_stmt|;
comment|/* media */
name|device_t
name|dev
decl_stmt|;
comment|/* device */
name|int
name|memid
decl_stmt|;
comment|/* resoure id for memory */
name|struct
name|resource
modifier|*
name|memres
decl_stmt|;
comment|/* memory resource */
name|bus_space_handle_t
name|memh
decl_stmt|;
comment|/* handle */
name|bus_space_tag_t
name|memt
decl_stmt|;
comment|/* ... and tag */
name|bus_dma_tag_t
name|parent_tag
decl_stmt|;
comment|/* global restriction */
name|struct
name|cv
name|vcc_cv
decl_stmt|;
comment|/* condition variable */
name|int
name|irqid
decl_stmt|;
comment|/* resource id */
name|struct
name|resource
modifier|*
name|irqres
decl_stmt|;
comment|/* resource */
name|void
modifier|*
name|ih
decl_stmt|;
comment|/* interrupt handle */
name|struct
name|utopia
name|utopia
decl_stmt|;
comment|/* utopia state */
comment|/* rest has to be reset by stop */
name|int
name|he622
decl_stmt|;
comment|/* this is a HE622 */
name|int
name|pci64
decl_stmt|;
comment|/* 64bit bus */
name|char
name|prod_id
index|[
name|HE_EEPROM_PROD_ID_LEN
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|rev
index|[
name|HE_EEPROM_REV_LEN
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|heirq
name|irq_0
decl_stmt|;
comment|/* interrupt queues 0 */
comment|/* generic network controller state */
name|u_int
name|cells_per_row
decl_stmt|;
name|u_int
name|bytes_per_row
decl_stmt|;
name|u_int
name|r0_numrows
decl_stmt|;
name|u_int
name|tx_numrows
decl_stmt|;
name|u_int
name|r1_numrows
decl_stmt|;
name|u_int
name|r0_startrow
decl_stmt|;
name|u_int
name|tx_startrow
decl_stmt|;
name|u_int
name|r1_startrow
decl_stmt|;
name|u_int
name|cells_per_lbuf
decl_stmt|;
name|u_int
name|r0_numbuffs
decl_stmt|;
name|u_int
name|r1_numbuffs
decl_stmt|;
name|u_int
name|tx_numbuffs
decl_stmt|;
comment|/* HSP */
name|struct
name|he_hsp
modifier|*
name|hsp
decl_stmt|;
name|struct
name|dmamem
name|hsp_mem
decl_stmt|;
comment|/*** TX ***/
name|struct
name|hetbrq
name|tbrq
decl_stmt|;
comment|/* TBRQ 0 */
name|struct
name|hetpdrq
name|tpdrq
decl_stmt|;
comment|/* TPDRQ */
name|struct
name|tpd_list
name|tpd_free
decl_stmt|;
comment|/* Free TPDs */
name|u_int
name|tpd_nfree
decl_stmt|;
comment|/* number of free TPDs */
name|u_int
name|tpd_total
decl_stmt|;
comment|/* total TPDs */
name|uint8_t
modifier|*
name|tpd_used
decl_stmt|;
comment|/* bitmap of used TPDs */
name|struct
name|dmamem
name|tpds
decl_stmt|;
comment|/* TPD memory */
name|bus_dma_tag_t
name|tx_tag
decl_stmt|;
comment|/* DMA tag for all tx mbufs */
comment|/*** RX ***/
comment|/* receive/transmit groups */
name|struct
name|herbp
name|rbp_s0
decl_stmt|;
comment|/* RBPS0 */
name|struct
name|herbp
name|rbp_l0
decl_stmt|;
comment|/* RBPL0 */
name|struct
name|herbp
name|rbp_s1
decl_stmt|;
comment|/* RBPS1 */
name|struct
name|herbrq
name|rbrq_0
decl_stmt|;
comment|/* RBRQ0 */
name|struct
name|herbrq
name|rbrq_1
decl_stmt|;
comment|/* RBRQ1 */
comment|/* list of external mbuf storage */
name|bus_dma_tag_t
name|mbuf_tag
decl_stmt|;
name|struct
name|mbuf_page
modifier|*
modifier|*
name|mbuf_pages
decl_stmt|;
name|u_int
name|mbuf_npages
decl_stmt|;
name|struct
name|mtx
name|mbuf0_mtx
decl_stmt|;
name|struct
name|mbufx_free_list
name|mbuf0_list
decl_stmt|;
name|struct
name|mtx
name|mbuf1_mtx
decl_stmt|;
name|struct
name|mbufx_free_list
name|mbuf1_list
decl_stmt|;
comment|/* mbuf cluster tracking and mapping for group 0 */
name|struct
name|mbuf
modifier|*
modifier|*
name|lbufs
decl_stmt|;
comment|/* mbufs */
name|bus_dmamap_t
modifier|*
name|rmaps
decl_stmt|;
comment|/* DMA maps */
name|u_int
name|lbufs_size
decl_stmt|;
name|u_int
name|lbufs_next
decl_stmt|;
comment|/* VCCs */
name|struct
name|hevcc
modifier|*
name|vccs
index|[
name|HE_MAX_VCCS
index|]
decl_stmt|;
name|u_int
name|cbr_bw
decl_stmt|;
comment|/* BW allocated to CBR */
name|u_int
name|max_tpd
decl_stmt|;
comment|/* per VCC */
name|u_int
name|open_vccs
decl_stmt|;
name|uma_zone_t
name|vcc_zone
decl_stmt|;
comment|/* rate groups */
name|struct
name|herg
name|rate_ctrl
index|[
name|HE_REGN_CS_STPER
index|]
decl_stmt|;
comment|/* memory offsets */
name|u_int
name|tsrb
decl_stmt|,
name|tsrc
decl_stmt|,
name|tsrd
decl_stmt|;
name|u_int
name|rsrb
decl_stmt|;
name|struct
name|cv
name|cv_rcclose
decl_stmt|;
comment|/* condition variable */
name|uint32_t
name|rate_grid
index|[
literal|16
index|]
index|[
literal|16
index|]
decl_stmt|;
comment|/* our copy */
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
comment|/* internal statistics */
name|struct
name|istats
name|istats
decl_stmt|;
ifdef|#
directive|ifdef
name|HATM_DEBUG
comment|/* debugging */
name|u_int
name|debug
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|READ4
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|)
value|bus_space_read_4(SC->memt, SC->memh, (OFF))
end_define

begin_define
define|#
directive|define
name|READ2
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|)
value|bus_space_read_2(SC->memt, SC->memh, (OFF))
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
value|bus_space_read_1(SC->memt, SC->memh, (OFF))
end_define

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
value|bus_space_write_4(SC->memt, SC->memh, (OFF), (VAL))
end_define

begin_define
define|#
directive|define
name|WRITE2
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|,
name|VAL
parameter_list|)
value|bus_space_write_2(SC->memt, SC->memh, (OFF), (VAL))
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
value|bus_space_write_1(SC->memt, SC->memh, (OFF), (VAL))
end_define

begin_define
define|#
directive|define
name|BARRIER_R
parameter_list|(
name|SC
parameter_list|)
value|bus_space_barrier(SC->memt, SC->memh, 0, HE_REGO_END, \ 	BUS_SPACE_BARRIER_READ)
end_define

begin_define
define|#
directive|define
name|BARRIER_W
parameter_list|(
name|SC
parameter_list|)
value|bus_space_barrier(SC->memt, SC->memh, 0, HE_REGO_END, \ 	BUS_SPACE_BARRIER_WRITE)
end_define

begin_define
define|#
directive|define
name|BARRIER_RW
parameter_list|(
name|SC
parameter_list|)
value|bus_space_barrier(SC->memt, SC->memh, 0, HE_REGO_END, \ 	BUS_SPACE_BARRIER_READ | BUS_SPACE_BARRIER_WRITE)
end_define

begin_define
define|#
directive|define
name|READ_SUNI
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|)
value|READ4(SC, HE_REGO_SUNI + 4 * (OFF))
end_define

begin_define
define|#
directive|define
name|WRITE_SUNI
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|,
name|VAL
parameter_list|)
value|WRITE4(SC, HE_REGO_SUNI + 4 * (OFF), (VAL))
end_define

begin_define
define|#
directive|define
name|READ_LB4
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|)
define|\
value|({									\ 	WRITE4(SC, HE_REGO_LB_MEM_ADDR, (OFF));				\ 	WRITE4(SC, HE_REGO_LB_MEM_ACCESS,				\ 	    (HE_REGM_LB_MEM_HNDSHK | HE_REGM_LB_MEM_READ));		\ 	while((READ4(SC, HE_REGO_LB_MEM_ACCESS)& HE_REGM_LB_MEM_HNDSHK))\ 		;							\ 	READ4(SC, HE_REGO_LB_MEM_DATA);					\     })
end_define

begin_define
define|#
directive|define
name|WRITE_LB4
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|,
name|VAL
parameter_list|)
define|\
value|do {								\ 	WRITE4(SC, HE_REGO_LB_MEM_ADDR, (OFF));				\ 	WRITE4(SC, HE_REGO_LB_MEM_DATA, (VAL));				\ 	WRITE4(SC, HE_REGO_LB_MEM_ACCESS,				\ 	    (HE_REGM_LB_MEM_HNDSHK | HE_REGM_LB_MEM_WRITE));		\ 	while((READ4(SC, HE_REGO_LB_MEM_ACCESS)& HE_REGM_LB_MEM_HNDSHK))\ 		;							\     } while(0)
end_define

begin_define
define|#
directive|define
name|WRITE_MEM4
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|,
name|VAL
parameter_list|,
name|SPACE
parameter_list|)
define|\
value|do {								\ 	WRITE4(SC, HE_REGO_CON_DAT, (VAL));				\ 	WRITE4(SC, HE_REGO_CON_CTL,					\ 	    (SPACE | HE_REGM_CON_WE | HE_REGM_CON_STATUS | (OFF)));	\ 	while((READ4(SC, HE_REGO_CON_CTL)& HE_REGM_CON_STATUS) != 0)	\ 		;							\     } while(0)
end_define

begin_define
define|#
directive|define
name|READ_MEM4
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|,
name|SPACE
parameter_list|)
define|\
value|({									\ 	WRITE4(SC, HE_REGO_CON_CTL,					\ 	    (SPACE | HE_REGM_CON_STATUS | (OFF)));			\ 	while((READ4(SC, HE_REGO_CON_CTL)& HE_REGM_CON_STATUS) != 0)	\ 		;							\ 	READ4(SC, HE_REGO_CON_DAT);					\     })
end_define

begin_define
define|#
directive|define
name|WRITE_TCM4
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|,
name|VAL
parameter_list|)
value|WRITE_MEM4(SC,(OFF),(VAL),HE_REGM_CON_TCM)
end_define

begin_define
define|#
directive|define
name|WRITE_RCM4
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|,
name|VAL
parameter_list|)
value|WRITE_MEM4(SC,(OFF),(VAL),HE_REGM_CON_RCM)
end_define

begin_define
define|#
directive|define
name|WRITE_MBOX4
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|,
name|VAL
parameter_list|)
value|WRITE_MEM4(SC,(OFF),(VAL),HE_REGM_CON_MBOX)
end_define

begin_define
define|#
directive|define
name|READ_TCM4
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|)
value|READ_MEM4(SC,(OFF),HE_REGM_CON_TCM)
end_define

begin_define
define|#
directive|define
name|READ_RCM4
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|)
value|READ_MEM4(SC,(OFF),HE_REGM_CON_RCM)
end_define

begin_define
define|#
directive|define
name|READ_MBOX4
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|)
value|READ_MEM4(SC,(OFF),HE_REGM_CON_MBOX)
end_define

begin_define
define|#
directive|define
name|WRITE_TCM
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|,
name|BYTES
parameter_list|,
name|VAL
parameter_list|)
define|\
value|WRITE_MEM4(SC,(OFF) | ((~(BYTES)& 0xf)<< HE_REGS_CON_DIS),	\ 	    (VAL), HE_REGM_CON_TCM)
end_define

begin_define
define|#
directive|define
name|WRITE_RCM
parameter_list|(
name|SC
parameter_list|,
name|OFF
parameter_list|,
name|BYTES
parameter_list|,
name|VAL
parameter_list|)
define|\
value|WRITE_MEM4(SC,(OFF) | ((~(BYTES)& 0xf)<< HE_REGS_CON_DIS),	\ 	    (VAL), HE_REGM_CON_RCM)
end_define

begin_define
define|#
directive|define
name|READ_TSR
parameter_list|(
name|SC
parameter_list|,
name|CID
parameter_list|,
name|NR
parameter_list|)
define|\
value|({									\ 	uint32_t _v;							\ 	if((NR)<= 7) {							\ 		_v = READ_TCM4(SC, HE_REGO_TSRA(0,CID,NR));		\ 	} else if((NR)<= 11) {						\ 		_v = READ_TCM4(SC, HE_REGO_TSRB((SC)->tsrb,CID,(NR-8)));\ 	} else if((NR)<= 13) {						\ 		_v = READ_TCM4(SC, HE_REGO_TSRC((SC)->tsrc,CID,(NR-12)));\ 	} else {							\ 		_v = READ_TCM4(SC, HE_REGO_TSRD((SC)->tsrd,CID));	\ 	}								\ 	_v;								\     })
end_define

begin_define
define|#
directive|define
name|WRITE_TSR
parameter_list|(
name|SC
parameter_list|,
name|CID
parameter_list|,
name|NR
parameter_list|,
name|BEN
parameter_list|,
name|VAL
parameter_list|)
define|\
value|do {								\ 	if((NR)<= 7) {							\ 		WRITE_TCM(SC, HE_REGO_TSRA(0,CID,NR),BEN,VAL);		\ 	} else if((NR)<= 11) {						\ 		WRITE_TCM(SC, HE_REGO_TSRB((SC)->tsrb,CID,(NR-8)),BEN,VAL);\ 	} else if((NR)<= 13) {						\ 		WRITE_TCM(SC, HE_REGO_TSRC((SC)->tsrc,CID,(NR-12)),BEN,VAL);\ 	} else {							\ 		WRITE_TCM(SC, HE_REGO_TSRD((SC)->tsrd,CID),BEN,VAL);	\ 	}								\     } while(0)
end_define

begin_define
define|#
directive|define
name|READ_RSR
parameter_list|(
name|SC
parameter_list|,
name|CID
parameter_list|,
name|NR
parameter_list|)
define|\
value|({									\ 	uint32_t _v;							\ 	if((NR)<= 7) {							\ 		_v = READ_RCM4(SC, HE_REGO_RSRA(0,CID,NR));		\ 	} else {							\ 		_v = READ_RCM4(SC, HE_REGO_RSRB((SC)->rsrb,CID,(NR-8)));\ 	}								\ 	_v;								\     })
end_define

begin_define
define|#
directive|define
name|WRITE_RSR
parameter_list|(
name|SC
parameter_list|,
name|CID
parameter_list|,
name|NR
parameter_list|,
name|BEN
parameter_list|,
name|VAL
parameter_list|)
define|\
value|do {								\ 	if((NR)<= 7) {							\ 		WRITE_RCM(SC, HE_REGO_RSRA(0,CID,NR),BEN,VAL);		\ 	} else {							\ 		WRITE_RCM(SC, HE_REGO_RSRB((SC)->rsrb,CID,(NR-8)),BEN,VAL);\ 	}								\     } while(0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HATM_DEBUG
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
value|do {						\ 	if((SC)->debug& DBG_##FL) { 					\ 		if_printf(&(SC)->ifatm.ifnet, "%s: ", __func__);	\ 		printf PRINT;						\ 		printf("\n");						\ 	}								\     } while (0)
end_define

begin_enum
enum|enum
block|{
name|DBG_RX
init|=
literal|0x0001
block|,
name|DBG_TX
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
name|DBG_INTR
init|=
literal|0x0020
block|,
name|DBG_DMA
init|=
literal|0x0040
block|,
name|DBG_DMAH
init|=
literal|0x0080
block|,
name|DBG_ALL
init|=
literal|0x00ff
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

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|u_int
name|hatm_cps2atmf
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|hatm_atmf2cps
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hatm_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hatm_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hatm_initialize
parameter_list|(
name|struct
name|hatm_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hatm_stop
parameter_list|(
name|struct
name|hatm_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hatm_start
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hatm_rx
parameter_list|(
name|struct
name|hatm_softc
modifier|*
name|sc
parameter_list|,
name|u_int
name|cid
parameter_list|,
name|u_int
name|flags
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|u_int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hatm_tx_complete
parameter_list|(
name|struct
name|hatm_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|tpd
modifier|*
name|tpd
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hatm_tx_vcc_can_open
parameter_list|(
name|struct
name|hatm_softc
modifier|*
name|sc
parameter_list|,
name|u_int
name|cid
parameter_list|,
name|struct
name|hevcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hatm_tx_vcc_open
parameter_list|(
name|struct
name|hatm_softc
modifier|*
name|sc
parameter_list|,
name|u_int
name|cid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hatm_rx_vcc_open
parameter_list|(
name|struct
name|hatm_softc
modifier|*
name|sc
parameter_list|,
name|u_int
name|cid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hatm_tx_vcc_close
parameter_list|(
name|struct
name|hatm_softc
modifier|*
name|sc
parameter_list|,
name|u_int
name|cid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hatm_rx_vcc_close
parameter_list|(
name|struct
name|hatm_softc
modifier|*
name|sc
parameter_list|,
name|u_int
name|cid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hatm_tx_vcc_closed
parameter_list|(
name|struct
name|hatm_softc
modifier|*
name|sc
parameter_list|,
name|u_int
name|cid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hatm_vcc_closed
parameter_list|(
name|struct
name|hatm_softc
modifier|*
name|sc
parameter_list|,
name|u_int
name|cid
parameter_list|)
function_decl|;
end_function_decl

end_unit

