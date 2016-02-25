begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2015 Cavium Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NICVF_QUEUES_H
end_ifndef

begin_define
define|#
directive|define
name|NICVF_QUEUES_H
end_define

begin_include
include|#
directive|include
file|"q_struct.h"
end_include

begin_define
define|#
directive|define
name|MAX_QUEUE_SET
value|128
end_define

begin_define
define|#
directive|define
name|MAX_RCV_QUEUES_PER_QS
value|8
end_define

begin_define
define|#
directive|define
name|MAX_RCV_BUF_DESC_RINGS_PER_QS
value|2
end_define

begin_define
define|#
directive|define
name|MAX_SND_QUEUES_PER_QS
value|8
end_define

begin_define
define|#
directive|define
name|MAX_CMP_QUEUES_PER_QS
value|8
end_define

begin_comment
comment|/* VF's queue interrupt ranges */
end_comment

begin_define
define|#
directive|define
name|NICVF_INTR_ID_CQ
value|0
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_ID_SQ
value|8
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_ID_RBDR
value|16
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_ID_MISC
value|18
end_define

begin_define
define|#
directive|define
name|NICVF_INTR_ID_QS_ERR
value|19
end_define

begin_define
define|#
directive|define
name|for_each_cq_irq
parameter_list|(
name|irq
parameter_list|)
define|\
value|for ((irq) = NICVF_INTR_ID_CQ; (irq)< NICVF_INTR_ID_SQ; (irq)++)
end_define

begin_define
define|#
directive|define
name|for_each_sq_irq
parameter_list|(
name|irq
parameter_list|)
define|\
value|for ((irq) = NICVF_INTR_ID_SQ; (irq)< NICVF_INTR_ID_RBDR; (irq)++)
end_define

begin_define
define|#
directive|define
name|for_each_rbdr_irq
parameter_list|(
name|irq
parameter_list|)
define|\
value|for ((irq) = NICVF_INTR_ID_RBDR; (irq)< NICVF_INTR_ID_MISC; (irq)++)
end_define

begin_define
define|#
directive|define
name|RBDR_SIZE0
value|0UL
end_define

begin_comment
comment|/* 8K entries */
end_comment

begin_define
define|#
directive|define
name|RBDR_SIZE1
value|1UL
end_define

begin_comment
comment|/* 16K entries */
end_comment

begin_define
define|#
directive|define
name|RBDR_SIZE2
value|2UL
end_define

begin_comment
comment|/* 32K entries */
end_comment

begin_define
define|#
directive|define
name|RBDR_SIZE3
value|3UL
end_define

begin_comment
comment|/* 64K entries */
end_comment

begin_define
define|#
directive|define
name|RBDR_SIZE4
value|4UL
end_define

begin_comment
comment|/* 126K entries */
end_comment

begin_define
define|#
directive|define
name|RBDR_SIZE5
value|5UL
end_define

begin_comment
comment|/* 256K entries */
end_comment

begin_define
define|#
directive|define
name|RBDR_SIZE6
value|6UL
end_define

begin_comment
comment|/* 512K entries */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_SIZE0
value|0UL
end_define

begin_comment
comment|/* 1K entries */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_SIZE1
value|1UL
end_define

begin_comment
comment|/* 2K entries */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_SIZE2
value|2UL
end_define

begin_comment
comment|/* 4K entries */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_SIZE3
value|3UL
end_define

begin_comment
comment|/* 8K entries */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_SIZE4
value|4UL
end_define

begin_comment
comment|/* 16K entries */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_SIZE5
value|5UL
end_define

begin_comment
comment|/* 32K entries */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_SIZE6
value|6UL
end_define

begin_comment
comment|/* 64K entries */
end_comment

begin_define
define|#
directive|define
name|CMP_QUEUE_SIZE0
value|0UL
end_define

begin_comment
comment|/* 1K entries */
end_comment

begin_define
define|#
directive|define
name|CMP_QUEUE_SIZE1
value|1UL
end_define

begin_comment
comment|/* 2K entries */
end_comment

begin_define
define|#
directive|define
name|CMP_QUEUE_SIZE2
value|2UL
end_define

begin_comment
comment|/* 4K entries */
end_comment

begin_define
define|#
directive|define
name|CMP_QUEUE_SIZE3
value|3UL
end_define

begin_comment
comment|/* 8K entries */
end_comment

begin_define
define|#
directive|define
name|CMP_QUEUE_SIZE4
value|4UL
end_define

begin_comment
comment|/* 16K entries */
end_comment

begin_define
define|#
directive|define
name|CMP_QUEUE_SIZE5
value|5UL
end_define

begin_comment
comment|/* 32K entries */
end_comment

begin_define
define|#
directive|define
name|CMP_QUEUE_SIZE6
value|6UL
end_define

begin_comment
comment|/* 64K entries */
end_comment

begin_comment
comment|/* Default queue count per QS, its lengths and threshold values */
end_comment

begin_define
define|#
directive|define
name|RBDR_CNT
value|1
end_define

begin_define
define|#
directive|define
name|RCV_QUEUE_CNT
value|8
end_define

begin_define
define|#
directive|define
name|SND_QUEUE_CNT
value|8
end_define

begin_define
define|#
directive|define
name|CMP_QUEUE_CNT
value|8
end_define

begin_comment
comment|/* Max of RCV and SND qcount */
end_comment

begin_define
define|#
directive|define
name|SND_QSIZE
value|SND_QUEUE_SIZE2
end_define

begin_define
define|#
directive|define
name|SND_QUEUE_LEN
value|(1UL<< (SND_QSIZE + 10))
end_define

begin_define
define|#
directive|define
name|MAX_SND_QUEUE_LEN
value|(1UL<< (SND_QUEUE_SIZE6 + 10))
end_define

begin_define
define|#
directive|define
name|SND_QUEUE_THRESH
value|2UL
end_define

begin_define
define|#
directive|define
name|MIN_SQ_DESC_PER_PKT_XMIT
value|2
end_define

begin_comment
comment|/* Since timestamp not enabled, otherwise 2 */
end_comment

begin_define
define|#
directive|define
name|MAX_CQE_PER_PKT_XMIT
value|1
end_define

begin_comment
comment|/*  * Keep CQ and SQ sizes same, if timestamping  * is enabled this equation will change.  */
end_comment

begin_define
define|#
directive|define
name|CMP_QSIZE
value|CMP_QUEUE_SIZE2
end_define

begin_define
define|#
directive|define
name|CMP_QUEUE_LEN
value|(1UL<< (CMP_QSIZE + 10))
end_define

begin_define
define|#
directive|define
name|CMP_QUEUE_CQE_THRESH
value|32
end_define

begin_define
define|#
directive|define
name|CMP_QUEUE_TIMER_THRESH
value|220
end_define

begin_comment
comment|/* 10usec */
end_comment

begin_define
define|#
directive|define
name|RBDR_SIZE
value|RBDR_SIZE0
end_define

begin_define
define|#
directive|define
name|RCV_BUF_COUNT
value|(1UL<< (RBDR_SIZE + 13))
end_define

begin_define
define|#
directive|define
name|MAX_RCV_BUF_COUNT
value|(1UL<< (RBDR_SIZE6 + 13))
end_define

begin_define
define|#
directive|define
name|RBDR_THRESH
value|(RCV_BUF_COUNT / 2)
end_define

begin_define
define|#
directive|define
name|DMA_BUFFER_LEN
value|2048
end_define

begin_comment
comment|/* In multiples of 128bytes */
end_comment

begin_define
define|#
directive|define
name|MAX_CQES_FOR_TX
define|\
value|((SND_QUEUE_LEN / MIN_SQ_DESC_PER_PKT_XMIT) * MAX_CQE_PER_PKT_XMIT)
end_define

begin_comment
comment|/* Calculate number of CQEs to reserve for all SQEs.  * Its 1/256th level of CQ size.  * '+ 1' to account for pipelining  */
end_comment

begin_define
define|#
directive|define
name|RQ_CQ_DROP
define|\
value|((256 / (CMP_QUEUE_LEN / (CMP_QUEUE_LEN - MAX_CQES_FOR_TX))) + 1)
end_define

begin_comment
comment|/* Descriptor size in bytes */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_DESC_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|CMP_QUEUE_DESC_SIZE
value|512
end_define

begin_comment
comment|/* Buffer / descriptor alignments */
end_comment

begin_define
define|#
directive|define
name|NICVF_RCV_BUF_ALIGN
value|7
end_define

begin_define
define|#
directive|define
name|NICVF_RCV_BUF_ALIGN_BYTES
value|(1UL<< NICVF_RCV_BUF_ALIGN)
end_define

begin_define
define|#
directive|define
name|NICVF_CQ_BASE_ALIGN_BYTES
value|512
end_define

begin_comment
comment|/* 9 bits */
end_comment

begin_define
define|#
directive|define
name|NICVF_SQ_BASE_ALIGN_BYTES
value|128
end_define

begin_comment
comment|/* 7 bits */
end_comment

begin_define
define|#
directive|define
name|NICVF_ALIGNED_ADDR
parameter_list|(
name|addr
parameter_list|,
name|align_bytes
parameter_list|)
define|\
value|roundup2((addr), (align_bytes))
end_define

begin_define
define|#
directive|define
name|NICVF_ADDR_ALIGN_LEN
parameter_list|(
name|addr
parameter_list|,
name|bytes
parameter_list|)
define|\
value|(NICVF_ALIGNED_ADDR((addr), (bytes)) - (bytes))
end_define

begin_define
define|#
directive|define
name|NICVF_RCV_BUF_ALIGN_LEN
parameter_list|(
name|addr
parameter_list|)
define|\
value|(NICVF_ALIGNED_ADDR((addr), NICVF_RCV_BUF_ALIGN_BYTES) - (addr))
end_define

begin_define
define|#
directive|define
name|NICVF_TXBUF_MAXSIZE
value|9212
end_define

begin_comment
comment|/* Total max payload without TSO */
end_comment

begin_define
define|#
directive|define
name|NICVF_TXBUF_NSEGS
value|256
end_define

begin_comment
comment|/* Single command is at most 256 buffers 					   (hdr + 255 subcmds) */
end_comment

begin_comment
comment|/* Queue enable/disable */
end_comment

begin_define
define|#
directive|define
name|NICVF_SQ_EN
value|(1UL<< 19)
end_define

begin_comment
comment|/* Queue reset */
end_comment

begin_define
define|#
directive|define
name|NICVF_CQ_RESET
value|(1UL<< 41)
end_define

begin_define
define|#
directive|define
name|NICVF_SQ_RESET
value|(1UL<< 17)
end_define

begin_define
define|#
directive|define
name|NICVF_RBDR_RESET
value|(1UL<< 43)
end_define

begin_enum
enum|enum
name|CQ_RX_ERRLVL_E
block|{
name|CQ_ERRLVL_MAC
block|,
name|CQ_ERRLVL_L2
block|,
name|CQ_ERRLVL_L3
block|,
name|CQ_ERRLVL_L4
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|CQ_RX_ERROP_E
block|{
name|CQ_RX_ERROP_RE_NONE
init|=
literal|0x0
block|,
name|CQ_RX_ERROP_RE_PARTIAL
init|=
literal|0x1
block|,
name|CQ_RX_ERROP_RE_JABBER
init|=
literal|0x2
block|,
name|CQ_RX_ERROP_RE_FCS
init|=
literal|0x7
block|,
name|CQ_RX_ERROP_RE_TERMINATE
init|=
literal|0x9
block|,
name|CQ_RX_ERROP_RE_RX_CTL
init|=
literal|0xb
block|,
name|CQ_RX_ERROP_PREL2_ERR
init|=
literal|0x1f
block|,
name|CQ_RX_ERROP_L2_FRAGMENT
init|=
literal|0x20
block|,
name|CQ_RX_ERROP_L2_OVERRUN
init|=
literal|0x21
block|,
name|CQ_RX_ERROP_L2_PFCS
init|=
literal|0x22
block|,
name|CQ_RX_ERROP_L2_PUNY
init|=
literal|0x23
block|,
name|CQ_RX_ERROP_L2_MAL
init|=
literal|0x24
block|,
name|CQ_RX_ERROP_L2_OVERSIZE
init|=
literal|0x25
block|,
name|CQ_RX_ERROP_L2_UNDERSIZE
init|=
literal|0x26
block|,
name|CQ_RX_ERROP_L2_LENMISM
init|=
literal|0x27
block|,
name|CQ_RX_ERROP_L2_PCLP
init|=
literal|0x28
block|,
name|CQ_RX_ERROP_IP_NOT
init|=
literal|0x41
block|,
name|CQ_RX_ERROP_IP_CSUM_ERR
init|=
literal|0x42
block|,
name|CQ_RX_ERROP_IP_MAL
init|=
literal|0x43
block|,
name|CQ_RX_ERROP_IP_MALD
init|=
literal|0x44
block|,
name|CQ_RX_ERROP_IP_HOP
init|=
literal|0x45
block|,
name|CQ_RX_ERROP_L3_ICRC
init|=
literal|0x46
block|,
name|CQ_RX_ERROP_L3_PCLP
init|=
literal|0x47
block|,
name|CQ_RX_ERROP_L4_MAL
init|=
literal|0x61
block|,
name|CQ_RX_ERROP_L4_CHK
init|=
literal|0x62
block|,
name|CQ_RX_ERROP_UDP_LEN
init|=
literal|0x63
block|,
name|CQ_RX_ERROP_L4_PORT
init|=
literal|0x64
block|,
name|CQ_RX_ERROP_TCP_FLAG
init|=
literal|0x65
block|,
name|CQ_RX_ERROP_TCP_OFFSET
init|=
literal|0x66
block|,
name|CQ_RX_ERROP_L4_PCLP
init|=
literal|0x67
block|,
name|CQ_RX_ERROP_RBDR_TRUNC
init|=
literal|0x70
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|CQ_TX_ERROP_E
block|{
name|CQ_TX_ERROP_GOOD
init|=
literal|0x0
block|,
name|CQ_TX_ERROP_DESC_FAULT
init|=
literal|0x10
block|,
name|CQ_TX_ERROP_HDR_CONS_ERR
init|=
literal|0x11
block|,
name|CQ_TX_ERROP_SUBDC_ERR
init|=
literal|0x12
block|,
name|CQ_TX_ERROP_IMM_SIZE_OFLOW
init|=
literal|0x80
block|,
name|CQ_TX_ERROP_DATA_SEQUENCE_ERR
init|=
literal|0x81
block|,
name|CQ_TX_ERROP_MEM_SEQUENCE_ERR
init|=
literal|0x82
block|,
name|CQ_TX_ERROP_LOCK_VIOL
init|=
literal|0x83
block|,
name|CQ_TX_ERROP_DATA_FAULT
init|=
literal|0x84
block|,
name|CQ_TX_ERROP_TSTMP_CONFLICT
init|=
literal|0x85
block|,
name|CQ_TX_ERROP_TSTMP_TIMEOUT
init|=
literal|0x86
block|,
name|CQ_TX_ERROP_MEM_FAULT
init|=
literal|0x87
block|,
name|CQ_TX_ERROP_CK_OVERLAP
init|=
literal|0x88
block|,
name|CQ_TX_ERROP_CK_OFLOW
init|=
literal|0x89
block|,
name|CQ_TX_ERROP_ENUM_LAST
init|=
literal|0x8a
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|cmp_queue_stats
block|{
struct|struct
name|tx_stats
block|{
name|uint64_t
name|good
decl_stmt|;
name|uint64_t
name|desc_fault
decl_stmt|;
name|uint64_t
name|hdr_cons_err
decl_stmt|;
name|uint64_t
name|subdesc_err
decl_stmt|;
name|uint64_t
name|imm_size_oflow
decl_stmt|;
name|uint64_t
name|data_seq_err
decl_stmt|;
name|uint64_t
name|mem_seq_err
decl_stmt|;
name|uint64_t
name|lock_viol
decl_stmt|;
name|uint64_t
name|data_fault
decl_stmt|;
name|uint64_t
name|tstmp_conflict
decl_stmt|;
name|uint64_t
name|tstmp_timeout
decl_stmt|;
name|uint64_t
name|mem_fault
decl_stmt|;
name|uint64_t
name|csum_overlap
decl_stmt|;
name|uint64_t
name|csum_overflow
decl_stmt|;
block|}
name|tx
struct|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_enum
enum|enum
name|RQ_SQ_STATS
block|{
name|RQ_SQ_STATS_OCTS
block|,
name|RQ_SQ_STATS_PKTS
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|rx_tx_queue_stats
block|{
name|uint64_t
name|bytes
decl_stmt|;
name|uint64_t
name|pkts
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|q_desc_mem
block|{
name|bus_dma_tag_t
name|dmat
decl_stmt|;
name|bus_dmamap_t
name|dmap
decl_stmt|;
name|void
modifier|*
name|base
decl_stmt|;
name|bus_addr_t
name|phys_base
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
name|uint16_t
name|q_len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rbdr
block|{
name|boolean_t
name|enable
decl_stmt|;
name|uint32_t
name|dma_size
decl_stmt|;
name|uint32_t
name|frag_len
decl_stmt|;
name|uint32_t
name|thresh
decl_stmt|;
comment|/* Threshold level for interrupt */
name|void
modifier|*
name|desc
decl_stmt|;
name|uint32_t
name|head
decl_stmt|;
name|uint32_t
name|tail
decl_stmt|;
name|struct
name|q_desc_mem
name|dmem
decl_stmt|;
name|struct
name|nicvf
modifier|*
name|nic
decl_stmt|;
name|int
name|idx
decl_stmt|;
name|struct
name|task
name|rbdr_task
decl_stmt|;
name|struct
name|task
name|rbdr_task_nowait
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|rbdr_taskq
decl_stmt|;
name|bus_dma_tag_t
name|rbdr_buff_dmat
decl_stmt|;
name|bus_dmamap_t
modifier|*
name|rbdr_buff_dmaps
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|rcv_queue
block|{
name|boolean_t
name|enable
decl_stmt|;
name|struct
name|rbdr
modifier|*
name|rbdr_start
decl_stmt|;
name|struct
name|rbdr
modifier|*
name|rbdr_cont
decl_stmt|;
name|boolean_t
name|en_tcp_reassembly
decl_stmt|;
name|uint8_t
name|cq_qs
decl_stmt|;
comment|/* CQ's QS to which this RQ is assigned */
name|uint8_t
name|cq_idx
decl_stmt|;
comment|/* CQ index (0 to 7) in the QS */
name|uint8_t
name|cont_rbdr_qs
decl_stmt|;
comment|/* Continue buffer ptrs - QS num */
name|uint8_t
name|cont_qs_rbdr_idx
decl_stmt|;
comment|/* RBDR idx in the cont QS */
name|uint8_t
name|start_rbdr_qs
decl_stmt|;
comment|/* First buffer ptrs - QS num */
name|uint8_t
name|start_qs_rbdr_idx
decl_stmt|;
comment|/* RBDR idx in the above QS */
name|uint8_t
name|caching
decl_stmt|;
name|struct
name|rx_tx_queue_stats
name|stats
decl_stmt|;
name|boolean_t
name|lro_enabled
decl_stmt|;
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|cmp_queue
block|{
name|boolean_t
name|enable
decl_stmt|;
name|uint16_t
name|thresh
decl_stmt|;
name|struct
name|nicvf
modifier|*
name|nic
decl_stmt|;
name|int
name|idx
decl_stmt|;
comment|/* This queue index */
name|struct
name|buf_ring
modifier|*
name|rx_br
decl_stmt|;
comment|/* Reception buf ring */
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/* lock to serialize processing CQEs */
name|char
name|mtx_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|task
name|cmp_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|cmp_taskq
decl_stmt|;
name|void
modifier|*
name|desc
decl_stmt|;
name|struct
name|q_desc_mem
name|dmem
decl_stmt|;
name|struct
name|cmp_queue_stats
name|stats
decl_stmt|;
name|int
name|irq
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|snd_buff
block|{
name|bus_dmamap_t
name|dmap
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|snd_queue
block|{
name|boolean_t
name|enable
decl_stmt|;
name|uint8_t
name|cq_qs
decl_stmt|;
comment|/* CQ's QS to which this SQ is pointing */
name|uint8_t
name|cq_idx
decl_stmt|;
comment|/* CQ index (0 to 7) in the above QS */
name|uint16_t
name|thresh
decl_stmt|;
specifier|volatile
name|int
name|free_cnt
decl_stmt|;
name|uint32_t
name|head
decl_stmt|;
name|uint32_t
name|tail
decl_stmt|;
name|uint64_t
modifier|*
name|skbuff
decl_stmt|;
name|void
modifier|*
name|desc
decl_stmt|;
name|struct
name|nicvf
modifier|*
name|nic
decl_stmt|;
name|int
name|idx
decl_stmt|;
comment|/* This queue index */
name|bus_dma_tag_t
name|snd_buff_dmat
decl_stmt|;
name|struct
name|snd_buff
modifier|*
name|snd_buff
decl_stmt|;
name|struct
name|buf_ring
modifier|*
name|br
decl_stmt|;
comment|/* Transmission buf ring */
name|struct
name|mtx
name|mtx
decl_stmt|;
name|char
name|mtx_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|task
name|snd_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|snd_taskq
decl_stmt|;
name|struct
name|q_desc_mem
name|dmem
decl_stmt|;
name|struct
name|rx_tx_queue_stats
name|stats
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|queue_set
block|{
name|boolean_t
name|enable
decl_stmt|;
name|boolean_t
name|be_en
decl_stmt|;
name|uint8_t
name|vnic_id
decl_stmt|;
name|uint8_t
name|rq_cnt
decl_stmt|;
name|uint8_t
name|cq_cnt
decl_stmt|;
name|uint64_t
name|cq_len
decl_stmt|;
name|uint8_t
name|sq_cnt
decl_stmt|;
name|uint64_t
name|sq_len
decl_stmt|;
name|uint8_t
name|rbdr_cnt
decl_stmt|;
name|uint64_t
name|rbdr_len
decl_stmt|;
name|struct
name|rcv_queue
name|rq
index|[
name|MAX_RCV_QUEUES_PER_QS
index|]
decl_stmt|;
name|struct
name|cmp_queue
name|cq
index|[
name|MAX_CMP_QUEUES_PER_QS
index|]
decl_stmt|;
name|struct
name|snd_queue
name|sq
index|[
name|MAX_SND_QUEUES_PER_QS
index|]
decl_stmt|;
name|struct
name|rbdr
name|rbdr
index|[
name|MAX_RCV_BUF_DESC_RINGS_PER_QS
index|]
decl_stmt|;
name|struct
name|task
name|qs_err_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|qs_err_taskq
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|GET_RBDR_DESC
parameter_list|(
name|RING
parameter_list|,
name|idx
parameter_list|)
define|\
value|(&(((struct rbdr_entry_t *)((RING)->desc))[(idx)]))
end_define

begin_define
define|#
directive|define
name|GET_SQ_DESC
parameter_list|(
name|RING
parameter_list|,
name|idx
parameter_list|)
define|\
value|(&(((struct sq_hdr_subdesc *)((RING)->desc))[(idx)]))
end_define

begin_define
define|#
directive|define
name|GET_CQ_DESC
parameter_list|(
name|RING
parameter_list|,
name|idx
parameter_list|)
define|\
value|(&(((union cq_desc_t *)((RING)->desc))[(idx)]))
end_define

begin_comment
comment|/* CQ status bits */
end_comment

begin_define
define|#
directive|define
name|CQ_WR_FUL
value|(1UL<< 26)
end_define

begin_define
define|#
directive|define
name|CQ_WR_DISABLE
value|(1UL<< 25)
end_define

begin_define
define|#
directive|define
name|CQ_WR_FAULT
value|(1UL<< 24)
end_define

begin_define
define|#
directive|define
name|CQ_CQE_COUNT
value|(0xFFFF<< 0)
end_define

begin_define
define|#
directive|define
name|CQ_ERR_MASK
value|(CQ_WR_FUL | CQ_WR_DISABLE | CQ_WR_FAULT)
end_define

begin_define
define|#
directive|define
name|NICVF_TX_LOCK
parameter_list|(
name|sq
parameter_list|)
value|mtx_lock(&(sq)->mtx)
end_define

begin_define
define|#
directive|define
name|NICVF_TX_TRYLOCK
parameter_list|(
name|sq
parameter_list|)
value|mtx_trylock(&(sq)->mtx)
end_define

begin_define
define|#
directive|define
name|NICVF_TX_UNLOCK
parameter_list|(
name|sq
parameter_list|)
value|mtx_unlock(&(sq)->mtx)
end_define

begin_define
define|#
directive|define
name|NICVF_TX_LOCK_ASSERT
parameter_list|(
name|sq
parameter_list|)
value|mtx_assert(&(sq)->mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|NICVF_CMP_LOCK
parameter_list|(
name|cq
parameter_list|)
value|mtx_lock(&(cq)->mtx)
end_define

begin_define
define|#
directive|define
name|NICVF_CMP_UNLOCK
parameter_list|(
name|cq
parameter_list|)
value|mtx_unlock(&(cq)->mtx)
end_define

begin_function_decl
name|int
name|nicvf_set_qset_resources
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nicvf_config_data_transfer
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicvf_qset_config
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicvf_enable_intr
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicvf_disable_intr
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicvf_clear_intr
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nicvf_is_intr_enabled
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nicvf_tx_mbuf_locked
parameter_list|(
name|struct
name|snd_queue
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Register access APIs */
end_comment

begin_function_decl
name|void
name|nicvf_reg_write
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|nicvf_reg_read
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicvf_qset_reg_write
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|nicvf_qset_reg_read
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicvf_queue_reg_write
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|nicvf_queue_reg_read
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Stats */
end_comment

begin_function_decl
name|void
name|nicvf_update_rq_stats
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicvf_update_sq_stats
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nicvf_check_cqe_rx_errs
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|struct
name|cmp_queue
modifier|*
parameter_list|,
name|struct
name|cqe_rx_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nicvf_check_cqe_tx_errs
parameter_list|(
name|struct
name|nicvf
modifier|*
parameter_list|,
name|struct
name|cmp_queue
modifier|*
parameter_list|,
name|struct
name|cqe_send_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NICVF_QUEUES_H */
end_comment

end_unit

