begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $FreeBSD$  *  * Driver for IDT77252 (ABR) based cards like ProSum's.  */
end_comment

begin_comment
comment|/* legal values are 0, 1, 2 and 8 */
end_comment

begin_define
define|#
directive|define
name|PATM_VPI_BITS
value|2
end_define

begin_define
define|#
directive|define
name|PATM_CFG_VPI
value|IDT_CFG_VP2
end_define

begin_comment
comment|/* receive status queue size */
end_comment

begin_define
define|#
directive|define
name|PATM_RSQ_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|PATM_CFQ_RSQ_SIZE
value|IDT_CFG_RXQ512
end_define

begin_comment
comment|/* alignment for SQ memory */
end_comment

begin_define
define|#
directive|define
name|PATM_SQ_ALIGNMENT
value|8192
end_define

begin_define
define|#
directive|define
name|PATM_PROATM_NAME_OFFSET
value|060
end_define

begin_define
define|#
directive|define
name|PATM_PROATM_NAME
value|"PROATM"
end_define

begin_define
define|#
directive|define
name|PATM_PROATM_MAC_OFFSET
value|044
end_define

begin_define
define|#
directive|define
name|PATM_IDT_MAC_OFFSET
value|0154
end_define

begin_comment
comment|/* maximum number of packets on UBR queue */
end_comment

begin_define
define|#
directive|define
name|PATM_DLFT_MAXQ
value|1000
end_define

begin_comment
comment|/* maximum number of packets on other queues. This should depend on the  * traffic contract. */
end_comment

begin_define
define|#
directive|define
name|PATM_TX_IFQLEN
value|100
end_define

begin_comment
comment|/*  * Maximum number of DMA maps we allocate. This is the minimum that can be  * set larger via a sysctl.  * Starting number of DMA maps.  * Step for growing.  */
end_comment

begin_define
define|#
directive|define
name|PATM_CFG_TXMAPS_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|PATM_CFG_TXMAPS_INIT
value|128
end_define

begin_define
define|#
directive|define
name|PATM_CFG_TXMAPS_STEP
value|128
end_define

begin_comment
comment|/* percents of TST slots to keep for non-CBR traffic */
end_comment

begin_define
define|#
directive|define
name|PATM_TST_RESERVE
value|2
end_define

begin_comment
comment|/*  * Structure to hold TX DMA maps  */
end_comment

begin_struct
struct|struct
name|patm_txmap
block|{
name|SLIST_ENTRY
argument_list|(
argument|patm_txmap
argument_list|)
name|link
expr_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Receive buffers.  *  * We manage our own external mbufs for small receive buffers for two reasons:  * the card may consume a rather large number of buffers. Mapping each buffer  * would consume a lot of iospace on sparc64. Also the card allows us to set  * a 32-bit handle for identification of the buffers. On a 64-bit system this  * requires us to use a mapping between buffers and handles.  *  * For large buffers we use mbuf clusters directly. We track these by using  * an array of pointers (lbufs) to special structs and a free list of these  * structs.  *  * For AAL0 cell we use FBQ2 and make the 1 cell long.  */
end_comment

begin_comment
comment|/*  * Define the small buffer chunk so that we have at least 16 byte free  * at the end of the chunk and that there is an integral number of chunks  * in a page.  */
end_comment

begin_define
define|#
directive|define
name|SMBUF_PAGE_SIZE
value|16384
end_define

begin_comment
comment|/* 16k pages */
end_comment

begin_define
define|#
directive|define
name|SMBUF_MAX_PAGES
value|64
end_define

begin_comment
comment|/* maximum number of pages */
end_comment

begin_define
define|#
directive|define
name|SMBUF_CHUNK_SIZE
value|256
end_define

begin_comment
comment|/* 256 bytes per chunk */
end_comment

begin_define
define|#
directive|define
name|SMBUF_CELLS
value|5
end_define

begin_define
define|#
directive|define
name|SMBUF_SIZE
value|(SMBUF_CELLS * 48)
end_define

begin_define
define|#
directive|define
name|SMBUF_THRESHOLD
value|9
end_define

begin_comment
comment|/* 9/16 of queue size */
end_comment

begin_define
define|#
directive|define
name|SMBUF_NI_THRESH
value|3
end_define

begin_define
define|#
directive|define
name|SMBUF_CI_THRESH
value|1
end_define

begin_define
define|#
directive|define
name|VMBUF_PAGE_SIZE
value|16384
end_define

begin_comment
comment|/* 16k pages */
end_comment

begin_define
define|#
directive|define
name|VMBUF_MAX_PAGES
value|16
end_define

begin_comment
comment|/* maximum number of pages */
end_comment

begin_define
define|#
directive|define
name|VMBUF_CHUNK_SIZE
value|64
end_define

begin_comment
comment|/* 64 bytes per chunk */
end_comment

begin_define
define|#
directive|define
name|VMBUF_CELLS
value|1
end_define

begin_define
define|#
directive|define
name|VMBUF_SIZE
value|(VMBUF_CELLS * 48)
end_define

begin_define
define|#
directive|define
name|VMBUF_THRESHOLD
value|15
end_define

begin_comment
comment|/* 15/16 of size */
end_comment

begin_define
define|#
directive|define
name|SMBUF_OFFSET
value|(SMBUF_CHUNK_SIZE - 8 - SMBUF_SIZE)
end_define

begin_define
define|#
directive|define
name|VMBUF_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|MBUF_SHANDLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MBUF_LHANDLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MBUF_VHANDLE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MBUF_HMASK
value|0x3fffffff
end_define

begin_comment
comment|/*  * Large buffers  *  * The problem with these is the maximum count. When the card assembles  * a AAL5 pdu it moves a buffer from the FBQ to the VC. This frees space  * in the FBQ, put the buffer may pend on the card for an unlimited amount  * of time (we don't idle connections). This means that the upper limit  * on buffers on the card may be (no-of-open-vcs + FBQ_SIZE). Because  * this is far too much, make this a tuneable. We could also make  * this dynamic by allocating pages of several lbufs at once during run time.  */
end_comment

begin_define
define|#
directive|define
name|LMBUF_MAX
value|(IDT_FBQ_SIZE * 2)
end_define

begin_define
define|#
directive|define
name|LMBUF_CELLS
value|(MCLBYTES / 48)
end_define

begin_comment
comment|/* 42 cells = 2048 byte */
end_comment

begin_define
define|#
directive|define
name|LMBUF_SIZE
value|(LMBUF_CELLS * 48)
end_define

begin_define
define|#
directive|define
name|LMBUF_THRESHOLD
value|9
end_define

begin_comment
comment|/* 9/16 of queue size */
end_comment

begin_define
define|#
directive|define
name|LMBUF_OFFSET
value|(MCLBYTES - LMBUF_SIZE)
end_define

begin_define
define|#
directive|define
name|LMBUF_NI_THRESH
value|3
end_define

begin_define
define|#
directive|define
name|LMBUF_CI_THRESH
value|1
end_define

begin_define
define|#
directive|define
name|LMBUF_HANDLE
value|0x80000000
end_define

begin_struct
struct|struct
name|lmbuf
block|{
name|SLIST_ENTRY
argument_list|(
argument|lmbuf
argument_list|)
name|link
expr_stmt|;
comment|/* free list link */
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* DMA map */
name|u_int
name|handle
decl_stmt|;
comment|/* this is the handle index */
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
comment|/* the current mbuf */
name|bus_addr_t
name|phy
decl_stmt|;
comment|/* phy addr */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PATM_CID
parameter_list|(
name|SC
parameter_list|,
name|VPI
parameter_list|,
name|VCI
parameter_list|)
define|\
value|(((VPI)<< (SC)->ifatm.mib.vci_bits) | (VCI))
end_define

begin_comment
comment|/*  * Internal driver statistics  */
end_comment

begin_struct
struct|struct
name|patm_stats
block|{
name|uint32_t
name|raw_cells
decl_stmt|;
name|uint32_t
name|raw_no_vcc
decl_stmt|;
name|uint32_t
name|raw_no_buf
decl_stmt|;
name|uint32_t
name|tx_qfull
decl_stmt|;
name|uint32_t
name|tx_out_of_tbds
decl_stmt|;
name|uint32_t
name|tx_out_of_maps
decl_stmt|;
name|uint32_t
name|tx_load_err
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * These are allocated as DMA able memory  */
end_comment

begin_struct
struct|struct
name|patm_scd
block|{
name|struct
name|idt_tbd
name|scq
index|[
name|IDT_SCQ_SIZE
index|]
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|patm_scd
argument_list|)
name|link
expr_stmt|;
comment|/* all active SCDs */
name|uint32_t
name|sram
decl_stmt|;
comment|/* SRAM address */
name|bus_addr_t
name|phy
decl_stmt|;
comment|/* physical address */
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* DMA map */
name|u_int
name|tail
decl_stmt|;
comment|/* next free entry for host */
name|int
name|space
decl_stmt|;
comment|/* number of free entries (minus one) */
name|u_int
name|slots
decl_stmt|;
comment|/* CBR slots allocated */
name|uint8_t
name|tag
decl_stmt|;
comment|/* next tag for TSI */
name|uint8_t
name|last_tag
decl_stmt|;
comment|/* last tag checked in interrupt */
name|uint8_t
name|num_on_card
decl_stmt|;
comment|/* number of PDUs on tx queue */
name|uint8_t
name|lacr
decl_stmt|;
comment|/* LogACR value */
name|uint8_t
name|init_er
decl_stmt|;
comment|/* LogER value */
name|struct
name|ifqueue
name|q
decl_stmt|;
comment|/* queue of packets */
name|struct
name|mbuf
modifier|*
name|on_card
index|[
name|IDT_TSQE_TAG_SPACE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-VCC data  */
end_comment

begin_struct
struct|struct
name|patm_vcc
block|{
name|struct
name|atmio_vcc
name|vcc
decl_stmt|;
comment|/* caller's parameters */
name|void
modifier|*
name|rxhand
decl_stmt|;
comment|/* NATM handle */
name|u_int
name|vflags
decl_stmt|;
comment|/* open and other flags */
name|uint32_t
name|ipackets
decl_stmt|;
comment|/* packets received */
name|uint32_t
name|opackets
decl_stmt|;
comment|/* packets sent */
name|uint64_t
name|ibytes
decl_stmt|;
comment|/* bytes received */
name|uint64_t
name|obytes
decl_stmt|;
comment|/* bytes sent */
name|struct
name|mbuf
modifier|*
name|chain
decl_stmt|;
comment|/* currently received chain */
name|struct
name|mbuf
modifier|*
name|last
decl_stmt|;
comment|/* end of chain */
name|u_int
name|cid
decl_stmt|;
comment|/* index */
name|u_int
name|cps
decl_stmt|;
comment|/* last ABR cps */
name|struct
name|patm_scd
modifier|*
name|scd
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PATM_VCC_TX_OPEN
value|0x0001
end_define

begin_define
define|#
directive|define
name|PATM_VCC_RX_OPEN
value|0x0002
end_define

begin_define
define|#
directive|define
name|PATM_VCC_TX_CLOSING
value|0x0004
end_define

begin_define
define|#
directive|define
name|PATM_VCC_RX_CLOSING
value|0x0008
end_define

begin_define
define|#
directive|define
name|PATM_VCC_OPEN
value|0x000f
end_define

begin_comment
comment|/* all the above */
end_comment

begin_define
define|#
directive|define
name|PATM_RAW_CELL
value|0x0000
end_define

begin_comment
comment|/* 53 byte cells */
end_comment

begin_define
define|#
directive|define
name|PATM_RAW_NOHEC
value|0x0100
end_define

begin_comment
comment|/* 52 byte cells */
end_comment

begin_define
define|#
directive|define
name|PATM_RAW_CS
value|0x0200
end_define

begin_comment
comment|/* 64 byte cell stream */
end_comment

begin_define
define|#
directive|define
name|PATM_RAW_FORMAT
value|0x0300
end_define

begin_comment
comment|/* format mask */
end_comment

begin_comment
comment|/*  * Per adapter data  */
end_comment

begin_struct
struct|struct
name|patm_softc
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
comment|/* phy state */
specifier|const
name|struct
name|idt_mmap
modifier|*
name|mmap
decl_stmt|;
comment|/* SRAM memory map */
name|u_int
name|flags
decl_stmt|;
comment|/* see below */
name|u_int
name|revision
decl_stmt|;
comment|/* chip revision */
comment|/* DMAable status queue memory */
name|size_t
name|sq_size
decl_stmt|;
comment|/* size of memory area */
name|bus_dma_tag_t
name|sq_tag
decl_stmt|;
comment|/* DMA tag */
name|bus_dmamap_t
name|sq_map
decl_stmt|;
comment|/* map */
name|bus_addr_t
name|tsq_phy
decl_stmt|;
comment|/* phys addr. */
name|struct
name|idt_tsqe
modifier|*
name|tsq
decl_stmt|;
comment|/* transmit status queue */
name|struct
name|idt_tsqe
modifier|*
name|tsq_next
decl_stmt|;
comment|/* last processed entry */
name|struct
name|idt_rsqe
modifier|*
name|rsq
decl_stmt|;
comment|/* receive status queue */
name|bus_addr_t
name|rsq_phy
decl_stmt|;
comment|/* phys addr. */
name|u_int
name|rsq_last
decl_stmt|;
comment|/* last processed entry */
name|struct
name|idt_rawhnd
modifier|*
name|rawhnd
decl_stmt|;
comment|/* raw cell handle */
name|bus_addr_t
name|rawhnd_phy
decl_stmt|;
comment|/* phys addr. */
comment|/* TST */
name|u_int
name|tst_state
decl_stmt|;
comment|/* active TST and others */
name|u_int
name|tst_jump
index|[
literal|2
index|]
decl_stmt|;
comment|/* address of the jumps */
name|u_int
name|tst_base
index|[
literal|2
index|]
decl_stmt|;
comment|/* base address of TST */
name|u_int
modifier|*
name|tst_soft
decl_stmt|;
comment|/* soft TST */
name|struct
name|mtx
name|tst_lock
decl_stmt|;
name|struct
name|callout
name|tst_callout
decl_stmt|;
name|u_int
name|tst_free
decl_stmt|;
comment|/* free slots */
name|u_int
name|tst_reserve
decl_stmt|;
comment|/* non-CBR reserve */
name|u_int
name|bwrem
decl_stmt|;
comment|/* remaining bandwith */
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
comment|/* EEPROM contents */
name|uint8_t
name|eeprom
index|[
literal|256
index|]
decl_stmt|;
comment|/* large buffer mapping */
name|bus_dma_tag_t
name|lbuf_tag
decl_stmt|;
comment|/* DMA tag */
name|u_int
name|lbuf_max
decl_stmt|;
comment|/* maximum number */
name|struct
name|lmbuf
modifier|*
name|lbufs
decl_stmt|;
comment|/* array for indexing */
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|lmbuf
argument_list|)
name|lbuf_free_list
expr_stmt|;
comment|/* free list */
comment|/* small buffer handling */
name|bus_dma_tag_t
name|sbuf_tag
decl_stmt|;
comment|/* DMA tag */
name|struct
name|mbpool
modifier|*
name|sbuf_pool
decl_stmt|;
comment|/* pool */
name|struct
name|mbpool
modifier|*
name|vbuf_pool
decl_stmt|;
comment|/* pool */
comment|/* raw cell queue */
name|struct
name|lmbuf
modifier|*
name|rawh
decl_stmt|;
comment|/* current header buf */
name|u_int
name|rawi
decl_stmt|;
comment|/* cell index into buffer */
comment|/* statistics */
name|struct
name|patm_stats
name|stats
decl_stmt|;
comment|/* statistics */
comment|/* Vccs */
name|struct
name|patm_vcc
modifier|*
modifier|*
name|vccs
decl_stmt|;
comment|/* channel pointer array */
name|u_int
name|vccs_open
decl_stmt|;
comment|/* number of open channels */
name|uma_zone_t
name|vcc_zone
decl_stmt|;
name|struct
name|cv
name|vcc_cv
decl_stmt|;
comment|/* SCDs */
name|uint32_t
name|scd_free
decl_stmt|;
comment|/* SRAM of first free SCD */
name|bus_dma_tag_t
name|scd_tag
decl_stmt|;
name|struct
name|patm_scd
modifier|*
name|scd0
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|patm_scd
argument_list|)
name|scd_list
expr_stmt|;
comment|/* list of all active SCDs */
comment|/* Tx */
name|bus_dma_tag_t
name|tx_tag
decl_stmt|;
comment|/* for transmission */
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|patm_txmap
argument_list|)
name|tx_maps_free
expr_stmt|;
comment|/* free maps */
name|u_int
name|tx_nmaps
decl_stmt|;
comment|/* allocated maps */
name|u_int
name|tx_maxmaps
decl_stmt|;
comment|/* maximum number */
name|struct
name|uma_zone
modifier|*
name|tx_mapzone
decl_stmt|;
comment|/* zone for maps */
ifdef|#
directive|ifdef
name|PATM_DEBUG
comment|/* debugging */
name|u_int
name|debug
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|PATM_25M
value|0x0001
end_define

begin_comment
comment|/* 25MBit card */
end_comment

begin_define
define|#
directive|define
name|PATM_SBUFW
value|0x0002
end_define

begin_comment
comment|/* warned */
end_comment

begin_define
define|#
directive|define
name|PATM_VBUFW
value|0x0004
end_define

begin_comment
comment|/* warned */
end_comment

begin_define
define|#
directive|define
name|PATM_UNASS
value|0x0010
end_define

begin_comment
comment|/* unassigned cells */
end_comment

begin_define
define|#
directive|define
name|PATM_CLR
value|0x0007
end_define

begin_comment
comment|/* clear on stop */
end_comment

begin_comment
comment|/* tst - uses unused fields */
end_comment

begin_define
define|#
directive|define
name|TST_BOTH
value|0x03000000
end_define

begin_define
define|#
directive|define
name|TST_CH0
value|0x01000000
end_define

begin_define
define|#
directive|define
name|TST_CH1
value|0x02000000
end_define

begin_comment
comment|/* tst_state */
end_comment

begin_define
define|#
directive|define
name|TST_ACT1
value|0x0001
end_define

begin_comment
comment|/* active TST */
end_comment

begin_define
define|#
directive|define
name|TST_PENDING
value|0x0002
end_define

begin_comment
comment|/* need update */
end_comment

begin_define
define|#
directive|define
name|TST_WAIT
value|0x0004
end_define

begin_comment
comment|/* wait fo jump */
end_comment

begin_define
define|#
directive|define
name|patm_printf
parameter_list|(
name|SC
parameter_list|,
modifier|...
parameter_list|)
value|if_printf(&(SC)->ifatm.ifnet, __VA_ARGS__);
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PATM_DEBUG
end_ifdef

begin_comment
comment|/*  * Debugging  */
end_comment

begin_enum
enum|enum
block|{
name|DBG_ATTACH
init|=
literal|0x0001
block|,
comment|/* attaching the card */
name|DBG_INTR
init|=
literal|0x0002
block|,
comment|/* interrupts */
name|DBG_REG
init|=
literal|0x0004
block|,
comment|/* register access */
name|DBG_SRAM
init|=
literal|0x0008
block|,
comment|/* SRAM access */
name|DBG_PHY
init|=
literal|0x0010
block|,
comment|/* PHY access */
name|DBG_IOCTL
init|=
literal|0x0020
block|,
comment|/* ioctl */
name|DBG_FREEQ
init|=
literal|0x0040
block|,
comment|/* free bufq supply */
name|DBG_VCC
init|=
literal|0x0080
block|,
comment|/* open/close */
name|DBG_TX
init|=
literal|0x0100
block|,
comment|/* transmission */
name|DBG_TST
init|=
literal|0x0200
block|,
comment|/* TST */
name|DBG_ALL
init|=
literal|0xffff
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|patm_debug
parameter_list|(
name|SC
parameter_list|,
name|FLAG
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	if((SC)->debug& DBG_##FLAG) { 					\ 		if_printf(&(SC)->ifatm.ifnet, "%s: ", __func__);	\ 		printf(__VA_ARGS__);					\ 		printf("\n");						\ 	}								\     } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|patm_debug
parameter_list|(
name|SC
parameter_list|,
name|FLAG
parameter_list|,
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* start output */
end_comment

begin_function_decl
name|void
name|patm_start
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ioctl handler */
end_comment

begin_function_decl
name|int
name|patm_ioctl
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

begin_comment
comment|/* start the interface */
end_comment

begin_function_decl
name|void
name|patm_init
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* start the interface with the lock held */
end_comment

begin_function_decl
name|void
name|patm_initialize
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* stop the interface */
end_comment

begin_function_decl
name|void
name|patm_stop
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* software reset of interface */
end_comment

begin_function_decl
name|void
name|patm_reset
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* interrupt handler */
end_comment

begin_function_decl
name|void
name|patm_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check RSQ */
end_comment

begin_function_decl
name|void
name|patm_intr_rsq
parameter_list|(
name|struct
name|patm_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* enable the vcc */
end_comment

begin_function_decl
name|void
name|patm_load_vc
parameter_list|(
name|struct
name|patm_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|patm_vcc
modifier|*
name|vcc
parameter_list|,
name|int
name|reload
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* close the given vcc for transmission */
end_comment

begin_function_decl
name|void
name|patm_tx_vcc_close
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|,
name|struct
name|patm_vcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* close the given vcc for receive */
end_comment

begin_function_decl
name|void
name|patm_rx_vcc_close
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|,
name|struct
name|patm_vcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* transmission side finally closed */
end_comment

begin_function_decl
name|void
name|patm_tx_vcc_closed
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|,
name|struct
name|patm_vcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* receive side finally closed */
end_comment

begin_function_decl
name|void
name|patm_rx_vcc_closed
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|,
name|struct
name|patm_vcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* vcc closed */
end_comment

begin_function_decl
name|void
name|patm_vcc_closed
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|,
name|struct
name|patm_vcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check if we can open this one */
end_comment

begin_function_decl
name|int
name|patm_tx_vcc_can_open
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|,
name|struct
name|patm_vcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check if we can open this one */
end_comment

begin_function_decl
name|int
name|patm_rx_vcc_can_open
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|,
name|struct
name|patm_vcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* open it */
end_comment

begin_function_decl
name|void
name|patm_tx_vcc_open
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|,
name|struct
name|patm_vcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* open it */
end_comment

begin_function_decl
name|void
name|patm_rx_vcc_open
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|,
name|struct
name|patm_vcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* receive packet */
end_comment

begin_function_decl
name|void
name|patm_rx
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|,
name|struct
name|idt_rsqe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* packet transmitted */
end_comment

begin_function_decl
name|void
name|patm_tx
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* VBR connection went idle */
end_comment

begin_function_decl
name|void
name|patm_tx_idle
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* allocate an SCQ */
end_comment

begin_function_decl
name|struct
name|patm_scd
modifier|*
name|patm_scd_alloc
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* free an SCD */
end_comment

begin_function_decl
name|void
name|patm_scd_free
parameter_list|(
name|struct
name|patm_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|patm_scd
modifier|*
name|scd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* setup SCD in SRAM */
end_comment

begin_function_decl
name|void
name|patm_scd_setup
parameter_list|(
name|struct
name|patm_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|patm_scd
modifier|*
name|scd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* setup TCT entry in SRAM */
end_comment

begin_function_decl
name|void
name|patm_tct_setup
parameter_list|(
name|struct
name|patm_softc
modifier|*
parameter_list|,
name|struct
name|patm_scd
modifier|*
parameter_list|,
name|struct
name|patm_vcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* free a large buffer */
end_comment

begin_function_decl
name|void
name|patm_lbuf_free
parameter_list|(
name|struct
name|patm_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|lmbuf
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Process the raw cell at the given address */
end_comment

begin_function_decl
name|void
name|patm_rx_raw
parameter_list|(
name|struct
name|patm_softc
modifier|*
name|sc
parameter_list|,
name|u_char
modifier|*
name|cell
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* load a one segment DMA map */
end_comment

begin_function_decl
name|void
name|patm_load_callback
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_dma_segment_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* network operation register access */
end_comment

begin_function
specifier|static
name|__inline
name|uint32_t
name|patm_nor_read
parameter_list|(
name|struct
name|patm_softc
modifier|*
name|sc
parameter_list|,
name|u_int
name|reg
parameter_list|)
block|{
name|uint32_t
name|val
decl_stmt|;
name|val
operator|=
name|bus_space_read_4
argument_list|(
name|sc
operator|->
name|memt
argument_list|,
name|sc
operator|->
name|memh
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|patm_debug
argument_list|(
name|sc
argument_list|,
name|REG
argument_list|,
literal|"reg(0x%x)=%04x"
argument_list|,
name|reg
argument_list|,
name|val
argument_list|)
expr_stmt|;
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|patm_nor_write
parameter_list|(
name|struct
name|patm_softc
modifier|*
name|sc
parameter_list|,
name|u_int
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|patm_debug
argument_list|(
name|sc
argument_list|,
name|REG
argument_list|,
literal|"reg(0x%x)=%04x"
argument_list|,
name|reg
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|sc
operator|->
name|memt
argument_list|,
name|sc
operator|->
name|memh
argument_list|,
name|reg
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Execute command */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|patm_cmd_wait
parameter_list|(
name|struct
name|patm_softc
modifier|*
name|sc
parameter_list|)
block|{
while|while
condition|(
name|patm_nor_read
argument_list|(
name|sc
argument_list|,
name|IDT_NOR_STAT
argument_list|)
operator|&
name|IDT_STAT_CMDBZ
condition|)
empty_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|patm_cmd_exec
parameter_list|(
name|struct
name|patm_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|cmd
parameter_list|)
block|{
name|patm_cmd_wait
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|patm_nor_write
argument_list|(
name|sc
argument_list|,
name|IDT_NOR_CMD
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Read/write SRAM at the given word address. */
end_comment

begin_function
specifier|static
name|__inline
name|uint32_t
name|patm_sram_read
parameter_list|(
name|struct
name|patm_softc
modifier|*
name|sc
parameter_list|,
name|u_int
name|addr
parameter_list|)
block|{
name|uint32_t
name|val
decl_stmt|;
name|patm_cmd_exec
argument_list|(
name|sc
argument_list|,
name|IDT_MKCMD_RSRAM
argument_list|(
name|addr
argument_list|)
argument_list|)
expr_stmt|;
name|patm_cmd_wait
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|val
operator|=
name|patm_nor_read
argument_list|(
name|sc
argument_list|,
name|IDT_NOR_D0
argument_list|)
expr_stmt|;
name|patm_debug
argument_list|(
name|sc
argument_list|,
name|SRAM
argument_list|,
literal|"read %04x=%08x"
argument_list|,
name|addr
argument_list|,
name|val
argument_list|)
expr_stmt|;
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|patm_sram_write
parameter_list|(
name|struct
name|patm_softc
modifier|*
name|sc
parameter_list|,
name|u_int
name|addr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|patm_debug
argument_list|(
name|sc
argument_list|,
name|SRAM
argument_list|,
literal|"write %04x=%08x"
argument_list|,
name|addr
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|patm_cmd_wait
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|patm_nor_write
argument_list|(
name|sc
argument_list|,
name|IDT_NOR_D0
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|patm_cmd_exec
argument_list|(
name|sc
argument_list|,
name|IDT_MKCMD_WSRAM
argument_list|(
name|addr
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|patm_sram_write4
parameter_list|(
name|struct
name|patm_softc
modifier|*
name|sc
parameter_list|,
name|u_int
name|addr
parameter_list|,
name|uint32_t
name|v0
parameter_list|,
name|uint32_t
name|v1
parameter_list|,
name|uint32_t
name|v2
parameter_list|,
name|uint32_t
name|v3
parameter_list|)
block|{
name|patm_debug
argument_list|(
name|sc
argument_list|,
name|SRAM
argument_list|,
literal|"write %04x=%08x,%08x,%08x,%08x"
argument_list|,
name|addr
argument_list|,
name|v0
argument_list|,
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
expr_stmt|;
name|patm_cmd_wait
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|patm_nor_write
argument_list|(
name|sc
argument_list|,
name|IDT_NOR_D0
argument_list|,
name|v0
argument_list|)
expr_stmt|;
name|patm_nor_write
argument_list|(
name|sc
argument_list|,
name|IDT_NOR_D1
argument_list|,
name|v1
argument_list|)
expr_stmt|;
name|patm_nor_write
argument_list|(
name|sc
argument_list|,
name|IDT_NOR_D2
argument_list|,
name|v2
argument_list|)
expr_stmt|;
name|patm_nor_write
argument_list|(
name|sc
argument_list|,
name|IDT_NOR_D3
argument_list|,
name|v3
argument_list|)
expr_stmt|;
name|patm_cmd_exec
argument_list|(
name|sc
argument_list|,
name|IDT_MKCMD_WSRAM
argument_list|(
name|addr
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|LEGAL_VPI
parameter_list|(
name|SC
parameter_list|,
name|VPI
parameter_list|)
define|\
value|(((VPI)& ~((1<< (SC)->ifatm.mib.vpi_bits) - 1)) == 0)
end_define

begin_define
define|#
directive|define
name|LEGAL_VCI
parameter_list|(
name|SC
parameter_list|,
name|VCI
parameter_list|)
define|\
value|(((VCI)& ~((1<< (SC)->ifatm.mib.vci_bits) - 1)) == 0)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|uint32_t
name|patm_rtables155
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint32_t
name|patm_rtables25
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u_int
name|patm_rtables_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u_int
name|patm_rtables_ntab
decl_stmt|;
end_decl_stmt

end_unit

