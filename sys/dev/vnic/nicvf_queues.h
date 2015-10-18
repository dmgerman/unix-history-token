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
file|<linux/netdevice.h>
end_include

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
value|for (irq = NICVF_INTR_ID_CQ; irq< NICVF_INTR_ID_SQ; irq++)
end_define

begin_define
define|#
directive|define
name|for_each_sq_irq
parameter_list|(
name|irq
parameter_list|)
define|\
value|for (irq = NICVF_INTR_ID_SQ; irq< NICVF_INTR_ID_RBDR; irq++)
end_define

begin_define
define|#
directive|define
name|for_each_rbdr_irq
parameter_list|(
name|irq
parameter_list|)
define|\
value|for (irq = NICVF_INTR_ID_RBDR; irq< NICVF_INTR_ID_MISC; irq++)
end_define

begin_define
define|#
directive|define
name|RBDR_SIZE0
value|0ULL
end_define

begin_comment
comment|/* 8K entries */
end_comment

begin_define
define|#
directive|define
name|RBDR_SIZE1
value|1ULL
end_define

begin_comment
comment|/* 16K entries */
end_comment

begin_define
define|#
directive|define
name|RBDR_SIZE2
value|2ULL
end_define

begin_comment
comment|/* 32K entries */
end_comment

begin_define
define|#
directive|define
name|RBDR_SIZE3
value|3ULL
end_define

begin_comment
comment|/* 64K entries */
end_comment

begin_define
define|#
directive|define
name|RBDR_SIZE4
value|4ULL
end_define

begin_comment
comment|/* 126K entries */
end_comment

begin_define
define|#
directive|define
name|RBDR_SIZE5
value|5ULL
end_define

begin_comment
comment|/* 256K entries */
end_comment

begin_define
define|#
directive|define
name|RBDR_SIZE6
value|6ULL
end_define

begin_comment
comment|/* 512K entries */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_SIZE0
value|0ULL
end_define

begin_comment
comment|/* 1K entries */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_SIZE1
value|1ULL
end_define

begin_comment
comment|/* 2K entries */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_SIZE2
value|2ULL
end_define

begin_comment
comment|/* 4K entries */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_SIZE3
value|3ULL
end_define

begin_comment
comment|/* 8K entries */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_SIZE4
value|4ULL
end_define

begin_comment
comment|/* 16K entries */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_SIZE5
value|5ULL
end_define

begin_comment
comment|/* 32K entries */
end_comment

begin_define
define|#
directive|define
name|SND_QUEUE_SIZE6
value|6ULL
end_define

begin_comment
comment|/* 64K entries */
end_comment

begin_define
define|#
directive|define
name|CMP_QUEUE_SIZE0
value|0ULL
end_define

begin_comment
comment|/* 1K entries */
end_comment

begin_define
define|#
directive|define
name|CMP_QUEUE_SIZE1
value|1ULL
end_define

begin_comment
comment|/* 2K entries */
end_comment

begin_define
define|#
directive|define
name|CMP_QUEUE_SIZE2
value|2ULL
end_define

begin_comment
comment|/* 4K entries */
end_comment

begin_define
define|#
directive|define
name|CMP_QUEUE_SIZE3
value|3ULL
end_define

begin_comment
comment|/* 8K entries */
end_comment

begin_define
define|#
directive|define
name|CMP_QUEUE_SIZE4
value|4ULL
end_define

begin_comment
comment|/* 16K entries */
end_comment

begin_define
define|#
directive|define
name|CMP_QUEUE_SIZE5
value|5ULL
end_define

begin_comment
comment|/* 32K entries */
end_comment

begin_define
define|#
directive|define
name|CMP_QUEUE_SIZE6
value|6ULL
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
value|(1ULL<< (SND_QSIZE + 10))
end_define

begin_define
define|#
directive|define
name|MAX_SND_QUEUE_LEN
value|(1ULL<< (SND_QUEUE_SIZE6 + 10))
end_define

begin_define
define|#
directive|define
name|SND_QUEUE_THRESH
value|2ULL
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
comment|/* Keep CQ and SQ sizes same, if timestamping  * is enabled this equation will change.  */
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
value|(1ULL<< (CMP_QSIZE + 10))
end_define

begin_define
define|#
directive|define
name|CMP_QUEUE_CQE_THRESH
value|0
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
value|(1ULL<< (RBDR_SIZE + 13))
end_define

begin_define
define|#
directive|define
name|MAX_RCV_BUF_COUNT
value|(1ULL<< (RBDR_SIZE6 + 13))
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
name|RCV_FRAG_LEN
value|(SKB_DATA_ALIGN(DMA_BUFFER_LEN + NET_SKB_PAD) + \ 			 SKB_DATA_ALIGN(sizeof(struct skb_shared_info)) + \ 			 (NICVF_RCV_BUF_ALIGN_BYTES * 2))
end_define

begin_define
define|#
directive|define
name|RCV_DATA_OFFSET
value|NICVF_RCV_BUF_ALIGN_BYTES
end_define

begin_define
define|#
directive|define
name|MAX_CQES_FOR_TX
value|((SND_QUEUE_LEN / MIN_SQ_DESC_PER_PKT_XMIT) * \ 				 MAX_CQE_PER_PKT_XMIT)
end_define

begin_comment
comment|/* Calculate number of CQEs to reserve for all SQEs.  * Its 1/256th level of CQ size.  * '+ 1' to account for pipelining  */
end_comment

begin_define
define|#
directive|define
name|RQ_CQ_DROP
value|((256 / (CMP_QUEUE_LEN / \ 				 (CMP_QUEUE_LEN - MAX_CQES_FOR_TX))) + 1)
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
value|(1ULL<< NICVF_RCV_BUF_ALIGN)
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
name|ADDR
parameter_list|,
name|ALIGN_BYTES
parameter_list|)
value|ALIGN(ADDR, ALIGN_BYTES)
end_define

begin_define
define|#
directive|define
name|NICVF_ADDR_ALIGN_LEN
parameter_list|(
name|ADDR
parameter_list|,
name|BYTES
parameter_list|)
define|\
value|(NICVF_ALIGNED_ADDR(ADDR, BYTES) - BYTES)
end_define

begin_define
define|#
directive|define
name|NICVF_RCV_BUF_ALIGN_LEN
parameter_list|(
name|X
parameter_list|)
define|\
value|(NICVF_ALIGNED_ADDR(X, NICVF_RCV_BUF_ALIGN_BYTES) - X)
end_define

begin_comment
comment|/* Queue enable/disable */
end_comment

begin_define
define|#
directive|define
name|NICVF_SQ_EN
value|BIT_ULL(19)
end_define

begin_comment
comment|/* Queue reset */
end_comment

begin_define
define|#
directive|define
name|NICVF_CQ_RESET
value|BIT_ULL(41)
end_define

begin_define
define|#
directive|define
name|NICVF_SQ_RESET
value|BIT_ULL(17)
end_define

begin_define
define|#
directive|define
name|NICVF_RBDR_RESET
value|BIT_ULL(43)
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
name|u64
name|good
decl_stmt|;
name|u64
name|desc_fault
decl_stmt|;
name|u64
name|hdr_cons_err
decl_stmt|;
name|u64
name|subdesc_err
decl_stmt|;
name|u64
name|imm_size_oflow
decl_stmt|;
name|u64
name|data_seq_err
decl_stmt|;
name|u64
name|mem_seq_err
decl_stmt|;
name|u64
name|lock_viol
decl_stmt|;
name|u64
name|data_fault
decl_stmt|;
name|u64
name|tstmp_conflict
decl_stmt|;
name|u64
name|tstmp_timeout
decl_stmt|;
name|u64
name|mem_fault
decl_stmt|;
name|u64
name|csum_overlap
decl_stmt|;
name|u64
name|csum_overflow
decl_stmt|;
block|}
name|tx
struct|;
block|}
name|____cacheline_aligned_in_smp
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
name|u64
name|bytes
decl_stmt|;
name|u64
name|pkts
decl_stmt|;
block|}
name|____cacheline_aligned_in_smp
struct|;
end_struct

begin_struct
struct|struct
name|q_desc_mem
block|{
name|dma_addr_t
name|dma
decl_stmt|;
name|u64
name|size
decl_stmt|;
name|u16
name|q_len
decl_stmt|;
name|dma_addr_t
name|phys_base
decl_stmt|;
name|void
modifier|*
name|base
decl_stmt|;
name|void
modifier|*
name|unalign_base
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rbdr
block|{
name|bool
name|enable
decl_stmt|;
name|u32
name|dma_size
decl_stmt|;
name|u32
name|frag_len
decl_stmt|;
name|u32
name|thresh
decl_stmt|;
comment|/* Threshold level for interrupt */
name|void
modifier|*
name|desc
decl_stmt|;
name|u32
name|head
decl_stmt|;
name|u32
name|tail
decl_stmt|;
name|struct
name|q_desc_mem
name|dmem
decl_stmt|;
block|}
name|____cacheline_aligned_in_smp
struct|;
end_struct

begin_struct
struct|struct
name|rcv_queue
block|{
name|bool
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
name|bool
name|en_tcp_reassembly
decl_stmt|;
name|u8
name|cq_qs
decl_stmt|;
comment|/* CQ's QS to which this RQ is assigned */
name|u8
name|cq_idx
decl_stmt|;
comment|/* CQ index (0 to 7) in the QS */
name|u8
name|cont_rbdr_qs
decl_stmt|;
comment|/* Continue buffer ptrs - QS num */
name|u8
name|cont_qs_rbdr_idx
decl_stmt|;
comment|/* RBDR idx in the cont QS */
name|u8
name|start_rbdr_qs
decl_stmt|;
comment|/* First buffer ptrs - QS num */
name|u8
name|start_qs_rbdr_idx
decl_stmt|;
comment|/* RBDR idx in the above QS */
name|u8
name|caching
decl_stmt|;
name|struct
name|rx_tx_queue_stats
name|stats
decl_stmt|;
block|}
name|____cacheline_aligned_in_smp
struct|;
end_struct

begin_struct
struct|struct
name|cmp_queue
block|{
name|bool
name|enable
decl_stmt|;
name|u16
name|thresh
decl_stmt|;
name|spinlock_t
name|lock
decl_stmt|;
comment|/* lock to serialize processing CQEs */
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
name|____cacheline_aligned_in_smp
struct|;
end_struct

begin_struct
struct|struct
name|snd_queue
block|{
name|bool
name|enable
decl_stmt|;
name|u8
name|cq_qs
decl_stmt|;
comment|/* CQ's QS to which this SQ is pointing */
name|u8
name|cq_idx
decl_stmt|;
comment|/* CQ index (0 to 7) in the above QS */
name|u16
name|thresh
decl_stmt|;
name|atomic_t
name|free_cnt
decl_stmt|;
name|u32
name|head
decl_stmt|;
name|u32
name|tail
decl_stmt|;
name|u64
modifier|*
name|skbuff
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
name|rx_tx_queue_stats
name|stats
decl_stmt|;
block|}
name|____cacheline_aligned_in_smp
struct|;
end_struct

begin_struct
struct|struct
name|queue_set
block|{
name|bool
name|enable
decl_stmt|;
name|bool
name|be_en
decl_stmt|;
name|u8
name|vnic_id
decl_stmt|;
name|u8
name|rq_cnt
decl_stmt|;
name|u8
name|cq_cnt
decl_stmt|;
name|u64
name|cq_len
decl_stmt|;
name|u8
name|sq_cnt
decl_stmt|;
name|u64
name|sq_len
decl_stmt|;
name|u8
name|rbdr_cnt
decl_stmt|;
name|u64
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
block|}
name|____cacheline_aligned_in_smp
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
value|(&(((struct rbdr_entry_t *)((RING)->desc))[idx]))
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
value|(&(((struct sq_hdr_subdesc *)((RING)->desc))[idx]))
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
value|(&(((union cq_desc_t *)((RING)->desc))[idx]))
end_define

begin_comment
comment|/* CQ status bits */
end_comment

begin_define
define|#
directive|define
name|CQ_WR_FULL
value|BIT(26)
end_define

begin_define
define|#
directive|define
name|CQ_WR_DISABLE
value|BIT(25)
end_define

begin_define
define|#
directive|define
name|CQ_WR_FAULT
value|BIT(24)
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
value|(CQ_WR_FULL | CQ_WR_DISABLE | CQ_WR_FAULT)
end_define

begin_function_decl
name|void
name|nicvf_config_vlan_stripping
parameter_list|(
name|struct
name|nicvf
modifier|*
name|nic
parameter_list|,
name|netdev_features_t
name|features
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nicvf_set_qset_resources
parameter_list|(
name|struct
name|nicvf
modifier|*
name|nic
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
name|nic
parameter_list|,
name|bool
name|enable
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
name|nic
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicvf_cmp_queue_config
parameter_list|(
name|struct
name|nicvf
modifier|*
name|nic
parameter_list|,
name|struct
name|queue_set
modifier|*
name|qs
parameter_list|,
name|int
name|qidx
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicvf_sq_enable
parameter_list|(
name|struct
name|nicvf
modifier|*
name|nic
parameter_list|,
name|struct
name|snd_queue
modifier|*
name|sq
parameter_list|,
name|int
name|qidx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicvf_sq_disable
parameter_list|(
name|struct
name|nicvf
modifier|*
name|nic
parameter_list|,
name|int
name|qidx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicvf_put_sq_desc
parameter_list|(
name|struct
name|snd_queue
modifier|*
name|sq
parameter_list|,
name|int
name|desc_cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicvf_sq_free_used_descs
parameter_list|(
name|struct
name|net_device
modifier|*
name|netdev
parameter_list|,
name|struct
name|snd_queue
modifier|*
name|sq
parameter_list|,
name|int
name|qidx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nicvf_sq_append_skb
parameter_list|(
name|struct
name|nicvf
modifier|*
name|nic
parameter_list|,
name|struct
name|sk_buff
modifier|*
name|skb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sk_buff
modifier|*
name|nicvf_get_rcv_skb
parameter_list|(
name|struct
name|nicvf
modifier|*
name|nic
parameter_list|,
name|struct
name|cqe_rx_t
modifier|*
name|cqe_rx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicvf_rbdr_task
parameter_list|(
name|unsigned
name|long
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nicvf_rbdr_work
parameter_list|(
name|struct
name|work_struct
modifier|*
name|work
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
name|nic
parameter_list|,
name|int
name|int_type
parameter_list|,
name|int
name|q_idx
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
name|nic
parameter_list|,
name|int
name|int_type
parameter_list|,
name|int
name|q_idx
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
name|nic
parameter_list|,
name|int
name|int_type
parameter_list|,
name|int
name|q_idx
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
name|nic
parameter_list|,
name|int
name|int_type
parameter_list|,
name|int
name|q_idx
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
name|nic
parameter_list|,
name|u64
name|offset
parameter_list|,
name|u64
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u64
name|nicvf_reg_read
parameter_list|(
name|struct
name|nicvf
modifier|*
name|nic
parameter_list|,
name|u64
name|offset
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
name|nic
parameter_list|,
name|u64
name|offset
parameter_list|,
name|u64
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u64
name|nicvf_qset_reg_read
parameter_list|(
name|struct
name|nicvf
modifier|*
name|nic
parameter_list|,
name|u64
name|offset
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
name|nic
parameter_list|,
name|u64
name|offset
parameter_list|,
name|u64
name|qidx
parameter_list|,
name|u64
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u64
name|nicvf_queue_reg_read
parameter_list|(
name|struct
name|nicvf
modifier|*
name|nic
parameter_list|,
name|u64
name|offset
parameter_list|,
name|u64
name|qidx
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
name|nic
parameter_list|,
name|int
name|rq_idx
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
name|nic
parameter_list|,
name|int
name|sq_idx
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
name|nic
parameter_list|,
name|struct
name|cmp_queue
modifier|*
name|cq
parameter_list|,
name|struct
name|cqe_rx_t
modifier|*
name|cqe_rx
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
name|nic
parameter_list|,
name|struct
name|cmp_queue
modifier|*
name|cq
parameter_list|,
name|struct
name|cqe_send_t
modifier|*
name|cqe_tx
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

