begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|DEF_RDMAVT_INCQP_H
end_ifndef

begin_define
define|#
directive|define
name|DEF_RDMAVT_INCQP_H
end_define

begin_comment
comment|/*  * Copyright(c) 2016 Intel Corporation.  *  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * BSD LICENSE  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *  - Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  - Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  - Neither the name of Intel Corporation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<rdma/rdma_vt.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_pack.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_verbs.h>
end_include

begin_comment
comment|/*  * Atomic bit definitions for r_aflags.  */
end_comment

begin_define
define|#
directive|define
name|RVT_R_WRID_VALID
value|0
end_define

begin_define
define|#
directive|define
name|RVT_R_REWIND_SGE
value|1
end_define

begin_comment
comment|/*  * Bit definitions for r_flags.  */
end_comment

begin_define
define|#
directive|define
name|RVT_R_REUSE_SGE
value|0x01
end_define

begin_define
define|#
directive|define
name|RVT_R_RDMAR_SEQ
value|0x02
end_define

begin_define
define|#
directive|define
name|RVT_R_RSP_NAK
value|0x04
end_define

begin_define
define|#
directive|define
name|RVT_R_RSP_SEND
value|0x08
end_define

begin_define
define|#
directive|define
name|RVT_R_COMM_EST
value|0x10
end_define

begin_comment
comment|/*  * Bit definitions for s_flags.  *  * RVT_S_SIGNAL_REQ_WR - set if QP send WRs contain completion signaled  * RVT_S_BUSY - send tasklet is processing the QP  * RVT_S_TIMER - the RC retry timer is active  * RVT_S_ACK_PENDING - an ACK is waiting to be sent after RDMA read/atomics  * RVT_S_WAIT_FENCE - waiting for all prior RDMA read or atomic SWQEs  *                         before processing the next SWQE  * RVT_S_WAIT_RDMAR - waiting for a RDMA read or atomic SWQE to complete  *                         before processing the next SWQE  * RVT_S_WAIT_RNR - waiting for RNR timeout  * RVT_S_WAIT_SSN_CREDIT - waiting for RC credits to process next SWQE  * RVT_S_WAIT_DMA - waiting for send DMA queue to drain before generating  *                  next send completion entry not via send DMA  * RVT_S_WAIT_PIO - waiting for a send buffer to be available  * RVT_S_WAIT_PIO_DRAIN - waiting for a qp to drain pio packets  * RVT_S_WAIT_TX - waiting for a struct verbs_txreq to be available  * RVT_S_WAIT_DMA_DESC - waiting for DMA descriptors to be available  * RVT_S_WAIT_KMEM - waiting for kernel memory to be available  * RVT_S_WAIT_PSN - waiting for a packet to exit the send DMA queue  * RVT_S_WAIT_ACK - waiting for an ACK packet before sending more requests  * RVT_S_SEND_ONE - send one packet, request ACK, then wait for ACK  * RVT_S_ECN - a BECN was queued to the send engine  */
end_comment

begin_define
define|#
directive|define
name|RVT_S_SIGNAL_REQ_WR
value|0x0001
end_define

begin_define
define|#
directive|define
name|RVT_S_BUSY
value|0x0002
end_define

begin_define
define|#
directive|define
name|RVT_S_TIMER
value|0x0004
end_define

begin_define
define|#
directive|define
name|RVT_S_RESP_PENDING
value|0x0008
end_define

begin_define
define|#
directive|define
name|RVT_S_ACK_PENDING
value|0x0010
end_define

begin_define
define|#
directive|define
name|RVT_S_WAIT_FENCE
value|0x0020
end_define

begin_define
define|#
directive|define
name|RVT_S_WAIT_RDMAR
value|0x0040
end_define

begin_define
define|#
directive|define
name|RVT_S_WAIT_RNR
value|0x0080
end_define

begin_define
define|#
directive|define
name|RVT_S_WAIT_SSN_CREDIT
value|0x0100
end_define

begin_define
define|#
directive|define
name|RVT_S_WAIT_DMA
value|0x0200
end_define

begin_define
define|#
directive|define
name|RVT_S_WAIT_PIO
value|0x0400
end_define

begin_define
define|#
directive|define
name|RVT_S_WAIT_PIO_DRAIN
value|0x0800
end_define

begin_define
define|#
directive|define
name|RVT_S_WAIT_TX
value|0x1000
end_define

begin_define
define|#
directive|define
name|RVT_S_WAIT_DMA_DESC
value|0x2000
end_define

begin_define
define|#
directive|define
name|RVT_S_WAIT_KMEM
value|0x4000
end_define

begin_define
define|#
directive|define
name|RVT_S_WAIT_PSN
value|0x8000
end_define

begin_define
define|#
directive|define
name|RVT_S_WAIT_ACK
value|0x10000
end_define

begin_define
define|#
directive|define
name|RVT_S_SEND_ONE
value|0x20000
end_define

begin_define
define|#
directive|define
name|RVT_S_UNLIMITED_CREDIT
value|0x40000
end_define

begin_define
define|#
directive|define
name|RVT_S_AHG_VALID
value|0x80000
end_define

begin_define
define|#
directive|define
name|RVT_S_AHG_CLEAR
value|0x100000
end_define

begin_define
define|#
directive|define
name|RVT_S_ECN
value|0x200000
end_define

begin_comment
comment|/*  * Wait flags that would prevent any packet type from being sent.  */
end_comment

begin_define
define|#
directive|define
name|RVT_S_ANY_WAIT_IO
define|\
value|(RVT_S_WAIT_PIO | RVT_S_WAIT_PIO_DRAIN | RVT_S_WAIT_TX | \ 	 RVT_S_WAIT_DMA_DESC | RVT_S_WAIT_KMEM)
end_define

begin_comment
comment|/*  * Wait flags that would prevent send work requests from making progress.  */
end_comment

begin_define
define|#
directive|define
name|RVT_S_ANY_WAIT_SEND
value|(RVT_S_WAIT_FENCE | RVT_S_WAIT_RDMAR | \ 	RVT_S_WAIT_RNR | RVT_S_WAIT_SSN_CREDIT | RVT_S_WAIT_DMA | \ 	RVT_S_WAIT_PSN | RVT_S_WAIT_ACK)
end_define

begin_define
define|#
directive|define
name|RVT_S_ANY_WAIT
value|(RVT_S_ANY_WAIT_IO | RVT_S_ANY_WAIT_SEND)
end_define

begin_comment
comment|/* Number of bits to pay attention to in the opcode for checking qp type */
end_comment

begin_define
define|#
directive|define
name|RVT_OPCODE_QP_MASK
value|0xE0
end_define

begin_comment
comment|/* Flags for checking QP state (see ib_rvt_state_ops[]) */
end_comment

begin_define
define|#
directive|define
name|RVT_POST_SEND_OK
value|0x01
end_define

begin_define
define|#
directive|define
name|RVT_POST_RECV_OK
value|0x02
end_define

begin_define
define|#
directive|define
name|RVT_PROCESS_RECV_OK
value|0x04
end_define

begin_define
define|#
directive|define
name|RVT_PROCESS_SEND_OK
value|0x08
end_define

begin_define
define|#
directive|define
name|RVT_PROCESS_NEXT_SEND_OK
value|0x10
end_define

begin_define
define|#
directive|define
name|RVT_FLUSH_SEND
value|0x20
end_define

begin_define
define|#
directive|define
name|RVT_FLUSH_RECV
value|0x40
end_define

begin_define
define|#
directive|define
name|RVT_PROCESS_OR_FLUSH_SEND
define|\
value|(RVT_PROCESS_SEND_OK | RVT_FLUSH_SEND)
end_define

begin_comment
comment|/*  * Internal send flags  */
end_comment

begin_define
define|#
directive|define
name|RVT_SEND_RESERVE_USED
value|IB_SEND_RESERVED_START
end_define

begin_define
define|#
directive|define
name|RVT_SEND_COMPLETION_ONLY
value|(IB_SEND_RESERVED_START<< 1)
end_define

begin_comment
comment|/*  * Send work request queue entry.  * The size of the sg_list is determined when the QP is created and stored  * in qp->s_max_sge.  */
end_comment

begin_struct
struct|struct
name|rvt_swqe
block|{
union|union
block|{
name|struct
name|ib_send_wr
name|wr
decl_stmt|;
comment|/* don't use wr.sg_list */
name|struct
name|ib_ud_wr
name|ud_wr
decl_stmt|;
name|struct
name|ib_reg_wr
name|reg_wr
decl_stmt|;
name|struct
name|ib_rdma_wr
name|rdma_wr
decl_stmt|;
name|struct
name|ib_atomic_wr
name|atomic_wr
decl_stmt|;
block|}
union|;
name|u32
name|psn
decl_stmt|;
comment|/* first packet sequence number */
name|u32
name|lpsn
decl_stmt|;
comment|/* last packet sequence number */
name|u32
name|ssn
decl_stmt|;
comment|/* send sequence number */
name|u32
name|length
decl_stmt|;
comment|/* total length of data in sg_list */
name|struct
name|rvt_sge
name|sg_list
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Receive work request queue entry.  * The size of the sg_list is determined when the QP (or SRQ) is created  * and stored in qp->r_rq.max_sge (or srq->rq.max_sge).  */
end_comment

begin_struct
struct|struct
name|rvt_rwqe
block|{
name|u64
name|wr_id
decl_stmt|;
name|u8
name|num_sge
decl_stmt|;
name|struct
name|ib_sge
name|sg_list
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure is used to contain the head pointer, tail pointer,  * and receive work queue entries as a single memory allocation so  * it can be mmap'ed into user space.  * Note that the wq array elements are variable size so you can't  * just index into the array to get the N'th element;  * use get_rwqe_ptr() instead.  */
end_comment

begin_struct
struct|struct
name|rvt_rwq
block|{
name|u32
name|head
decl_stmt|;
comment|/* new work requests posted to the head */
name|u32
name|tail
decl_stmt|;
comment|/* receives pull requests from here. */
name|struct
name|rvt_rwqe
name|wq
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rvt_rq
block|{
name|struct
name|rvt_rwq
modifier|*
name|wq
decl_stmt|;
name|u32
name|size
decl_stmt|;
comment|/* size of RWQE array */
name|u8
name|max_sge
decl_stmt|;
comment|/* protect changes in this struct */
name|spinlock_t
name|lock
name|____cacheline_aligned_in_smp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure is used by rvt_mmap() to validate an offset  * when an mmap() request is made.  The vm_area_struct then uses  * this as its vm_private_data.  */
end_comment

begin_struct
struct|struct
name|rvt_mmap_info
block|{
name|struct
name|list_head
name|pending_mmaps
decl_stmt|;
name|struct
name|ib_ucontext
modifier|*
name|context
decl_stmt|;
name|void
modifier|*
name|obj
decl_stmt|;
name|__u64
name|offset
decl_stmt|;
name|struct
name|kref
name|ref
decl_stmt|;
name|unsigned
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure holds the information that the send tasklet needs  * to send a RDMA read response or atomic operation.  */
end_comment

begin_struct
struct|struct
name|rvt_ack_entry
block|{
name|struct
name|rvt_sge
name|rdma_sge
decl_stmt|;
name|u64
name|atomic_data
decl_stmt|;
name|u32
name|psn
decl_stmt|;
name|u32
name|lpsn
decl_stmt|;
name|u8
name|opcode
decl_stmt|;
name|u8
name|sent
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RC_QP_SCALING_INTERVAL
value|5
end_define

begin_define
define|#
directive|define
name|RVT_OPERATION_PRIV
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RVT_OPERATION_ATOMIC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RVT_OPERATION_ATOMIC_SGE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RVT_OPERATION_LOCAL
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RVT_OPERATION_USE_RESERVE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RVT_OPERATION_MAX
value|(IB_WR_RESERVED10 + 1)
end_define

begin_comment
comment|/**  * rvt_operation_params - op table entry  * @length - the length to copy into the swqe entry  * @qpt_support - a bit mask indicating QP type support  * @flags - RVT_OPERATION flags (see above)  *  * This supports table driven post send so that  * the driver can have differing an potentially  * different sets of operations.  *  **/
end_comment

begin_struct
struct|struct
name|rvt_operation_params
block|{
name|size_t
name|length
decl_stmt|;
name|u32
name|qpt_support
decl_stmt|;
name|u32
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Common variables are protected by both r_rq.lock and s_lock in that order  * which only happens in modify_qp() or changing the QP 'state'.  */
end_comment

begin_struct
struct|struct
name|rvt_qp
block|{
name|struct
name|ib_qp
name|ibqp
decl_stmt|;
name|void
modifier|*
name|priv
decl_stmt|;
comment|/* Driver private data */
comment|/* read mostly fields above and below */
name|struct
name|ib_ah_attr
name|remote_ah_attr
decl_stmt|;
name|struct
name|ib_ah_attr
name|alt_ah_attr
decl_stmt|;
name|struct
name|rvt_qp
name|__rcu
modifier|*
name|next
decl_stmt|;
comment|/* link list for QPN hash table */
name|struct
name|rvt_swqe
modifier|*
name|s_wq
decl_stmt|;
comment|/* send work queue */
name|struct
name|rvt_mmap_info
modifier|*
name|ip
decl_stmt|;
name|unsigned
name|long
name|timeout_jiffies
decl_stmt|;
comment|/* computed from timeout */
name|enum
name|ib_mtu
name|path_mtu
decl_stmt|;
name|int
name|srate_mbps
decl_stmt|;
comment|/* s_srate (below) converted to Mbit/s */
name|pid_t
name|pid
decl_stmt|;
comment|/* pid for user mode QPs */
name|u32
name|remote_qpn
decl_stmt|;
name|u32
name|qkey
decl_stmt|;
comment|/* QKEY for this QP (for UD or RD) */
name|u32
name|s_size
decl_stmt|;
comment|/* send work queue size */
name|u32
name|s_ahgpsn
decl_stmt|;
comment|/* set to the psn in the copy of the header */
name|u16
name|pmtu
decl_stmt|;
comment|/* decoded from path_mtu */
name|u8
name|log_pmtu
decl_stmt|;
comment|/* shift for pmtu */
name|u8
name|state
decl_stmt|;
comment|/* QP state */
name|u8
name|allowed_ops
decl_stmt|;
comment|/* high order bits of allowed opcodes */
name|u8
name|qp_access_flags
decl_stmt|;
name|u8
name|alt_timeout
decl_stmt|;
comment|/* Alternate path timeout for this QP */
name|u8
name|timeout
decl_stmt|;
comment|/* Timeout for this QP */
name|u8
name|s_srate
decl_stmt|;
name|u8
name|s_mig_state
decl_stmt|;
name|u8
name|port_num
decl_stmt|;
name|u8
name|s_pkey_index
decl_stmt|;
comment|/* PKEY index to use */
name|u8
name|s_alt_pkey_index
decl_stmt|;
comment|/* Alternate path PKEY index to use */
name|u8
name|r_max_rd_atomic
decl_stmt|;
comment|/* max number of RDMA read/atomic to receive */
name|u8
name|s_max_rd_atomic
decl_stmt|;
comment|/* max number of RDMA read/atomic to send */
name|u8
name|s_retry_cnt
decl_stmt|;
comment|/* number of times to retry */
name|u8
name|s_rnr_retry_cnt
decl_stmt|;
name|u8
name|r_min_rnr_timer
decl_stmt|;
comment|/* retry timeout value for RNR NAKs */
name|u8
name|s_max_sge
decl_stmt|;
comment|/* size of s_wq->sg_list */
name|u8
name|s_draining
decl_stmt|;
comment|/* start of read/write fields */
name|atomic_t
name|refcount
name|____cacheline_aligned_in_smp
decl_stmt|;
name|wait_queue_head_t
name|wait
decl_stmt|;
name|struct
name|rvt_ack_entry
modifier|*
name|s_ack_queue
decl_stmt|;
name|struct
name|rvt_sge_state
name|s_rdma_read_sge
decl_stmt|;
name|spinlock_t
name|r_lock
name|____cacheline_aligned_in_smp
decl_stmt|;
comment|/* used for APM */
name|u32
name|r_psn
decl_stmt|;
comment|/* expected rcv packet sequence number */
name|unsigned
name|long
name|r_aflags
decl_stmt|;
name|u64
name|r_wr_id
decl_stmt|;
comment|/* ID for current receive WQE */
name|u32
name|r_ack_psn
decl_stmt|;
comment|/* PSN for next ACK or atomic ACK */
name|u32
name|r_len
decl_stmt|;
comment|/* total length of r_sge */
name|u32
name|r_rcv_len
decl_stmt|;
comment|/* receive data len processed */
name|u32
name|r_msn
decl_stmt|;
comment|/* message sequence number */
name|u8
name|r_state
decl_stmt|;
comment|/* opcode of last packet received */
name|u8
name|r_flags
decl_stmt|;
name|u8
name|r_head_ack_queue
decl_stmt|;
comment|/* index into s_ack_queue[] */
name|struct
name|list_head
name|rspwait
decl_stmt|;
comment|/* link for waiting to respond */
name|struct
name|rvt_sge_state
name|r_sge
decl_stmt|;
comment|/* current receive data */
name|struct
name|rvt_rq
name|r_rq
decl_stmt|;
comment|/* receive work queue */
comment|/* post send line */
name|spinlock_t
name|s_hlock
name|____cacheline_aligned_in_smp
decl_stmt|;
name|u32
name|s_head
decl_stmt|;
comment|/* new entries added here */
name|u32
name|s_next_psn
decl_stmt|;
comment|/* PSN for next request */
name|u32
name|s_avail
decl_stmt|;
comment|/* number of entries avail */
name|u32
name|s_ssn
decl_stmt|;
comment|/* SSN of tail entry */
name|atomic_t
name|s_reserved_used
decl_stmt|;
comment|/* reserved entries in use */
name|spinlock_t
name|s_lock
name|____cacheline_aligned_in_smp
decl_stmt|;
name|u32
name|s_flags
decl_stmt|;
name|struct
name|rvt_sge_state
modifier|*
name|s_cur_sge
decl_stmt|;
name|struct
name|rvt_swqe
modifier|*
name|s_wqe
decl_stmt|;
name|struct
name|rvt_sge_state
name|s_sge
decl_stmt|;
comment|/* current send request data */
name|struct
name|rvt_mregion
modifier|*
name|s_rdma_mr
decl_stmt|;
name|u32
name|s_cur_size
decl_stmt|;
comment|/* size of send packet in bytes */
name|u32
name|s_len
decl_stmt|;
comment|/* total length of s_sge */
name|u32
name|s_rdma_read_len
decl_stmt|;
comment|/* total length of s_rdma_read_sge */
name|u32
name|s_last_psn
decl_stmt|;
comment|/* last response PSN processed */
name|u32
name|s_sending_psn
decl_stmt|;
comment|/* lowest PSN that is being sent */
name|u32
name|s_sending_hpsn
decl_stmt|;
comment|/* highest PSN that is being sent */
name|u32
name|s_psn
decl_stmt|;
comment|/* current packet sequence number */
name|u32
name|s_ack_rdma_psn
decl_stmt|;
comment|/* PSN for sending RDMA read responses */
name|u32
name|s_ack_psn
decl_stmt|;
comment|/* PSN for acking sends and RDMA writes */
name|u32
name|s_tail
decl_stmt|;
comment|/* next entry to process */
name|u32
name|s_cur
decl_stmt|;
comment|/* current work queue entry */
name|u32
name|s_acked
decl_stmt|;
comment|/* last un-ACK'ed entry */
name|u32
name|s_last
decl_stmt|;
comment|/* last completed entry */
name|u32
name|s_lsn
decl_stmt|;
comment|/* limit sequence number (credit) */
name|u16
name|s_hdrwords
decl_stmt|;
comment|/* size of s_hdr in 32 bit words */
name|u16
name|s_rdma_ack_cnt
decl_stmt|;
name|s8
name|s_ahgidx
decl_stmt|;
name|u8
name|s_state
decl_stmt|;
comment|/* opcode of last packet sent */
name|u8
name|s_ack_state
decl_stmt|;
comment|/* opcode of packet to ACK */
name|u8
name|s_nak_state
decl_stmt|;
comment|/* non-zero if NAK is pending */
name|u8
name|r_nak_state
decl_stmt|;
comment|/* non-zero if NAK is pending */
name|u8
name|s_retry
decl_stmt|;
comment|/* requester retry counter */
name|u8
name|s_rnr_retry
decl_stmt|;
comment|/* requester RNR retry counter */
name|u8
name|s_num_rd_atomic
decl_stmt|;
comment|/* number of RDMA read/atomic pending */
name|u8
name|s_tail_ack_queue
decl_stmt|;
comment|/* index into s_ack_queue[] */
name|struct
name|rvt_sge_state
name|s_ack_rdma_sge
decl_stmt|;
name|struct
name|timer_list
name|s_timer
decl_stmt|;
name|atomic_t
name|local_ops_pending
decl_stmt|;
comment|/* number of fast_reg/local_inv reqs */
comment|/* 	 * This sge list MUST be last. Do not add anything below here. 	 */
name|struct
name|rvt_sge
name|r_sg_list
index|[
literal|0
index|]
comment|/* verified SGEs */
name|____cacheline_aligned_in_smp
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rvt_srq
block|{
name|struct
name|ib_srq
name|ibsrq
decl_stmt|;
name|struct
name|rvt_rq
name|rq
decl_stmt|;
name|struct
name|rvt_mmap_info
modifier|*
name|ip
decl_stmt|;
comment|/* send signal when number of RWQEs< limit */
name|u32
name|limit
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RVT_QPN_MAX
value|BIT(24)
end_define

begin_define
define|#
directive|define
name|RVT_QPNMAP_ENTRIES
value|(RVT_QPN_MAX / PAGE_SIZE / BITS_PER_BYTE)
end_define

begin_define
define|#
directive|define
name|RVT_BITS_PER_PAGE
value|(PAGE_SIZE * BITS_PER_BYTE)
end_define

begin_define
define|#
directive|define
name|RVT_BITS_PER_PAGE_MASK
value|(RVT_BITS_PER_PAGE - 1)
end_define

begin_define
define|#
directive|define
name|RVT_QPN_MASK
value|0xFFFFFF
end_define

begin_comment
comment|/*  * QPN-map pages start out as NULL, they get allocated upon  * first use and are never deallocated. This way,  * large bitmaps are not allocated unless large numbers of QPs are used.  */
end_comment

begin_struct
struct|struct
name|rvt_qpn_map
block|{
name|void
modifier|*
name|page
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rvt_qpn_table
block|{
name|spinlock_t
name|lock
decl_stmt|;
comment|/* protect changes to the qp table */
name|unsigned
name|flags
decl_stmt|;
comment|/* flags for QP0/1 allocated for each port */
name|u32
name|last
decl_stmt|;
comment|/* last QP number allocated */
name|u32
name|nmaps
decl_stmt|;
comment|/* size of the map table */
name|u16
name|limit
decl_stmt|;
name|u8
name|incr
decl_stmt|;
comment|/* bit map of free QP numbers other than 0/1 */
name|struct
name|rvt_qpn_map
name|map
index|[
name|RVT_QPNMAP_ENTRIES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rvt_qp_ibdev
block|{
name|u32
name|qp_table_size
decl_stmt|;
name|u32
name|qp_table_bits
decl_stmt|;
name|struct
name|rvt_qp
name|__rcu
modifier|*
modifier|*
name|qp_table
decl_stmt|;
name|spinlock_t
name|qpt_lock
decl_stmt|;
comment|/* qptable lock */
name|struct
name|rvt_qpn_table
name|qpn_table
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * There is one struct rvt_mcast for each multicast GID.  * All attached QPs are then stored as a list of  * struct rvt_mcast_qp.  */
end_comment

begin_struct
struct|struct
name|rvt_mcast_qp
block|{
name|struct
name|list_head
name|list
decl_stmt|;
name|struct
name|rvt_qp
modifier|*
name|qp
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rvt_mcast
block|{
name|struct
name|rb_node
name|rb_node
decl_stmt|;
name|union
name|ib_gid
name|mgid
decl_stmt|;
name|struct
name|list_head
name|qp_list
decl_stmt|;
name|wait_queue_head_t
name|wait
decl_stmt|;
name|atomic_t
name|refcount
decl_stmt|;
name|int
name|n_attached
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Since struct rvt_swqe is not a fixed size, we can't simply index into  * struct rvt_qp.s_wq.  This function does the array index computation.  */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|rvt_swqe
modifier|*
name|rvt_get_swqe_ptr
parameter_list|(
name|struct
name|rvt_qp
modifier|*
name|qp
parameter_list|,
name|unsigned
name|n
parameter_list|)
block|{
return|return
operator|(
expr|struct
name|rvt_swqe
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|qp
operator|->
name|s_wq
operator|+
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|rvt_swqe
argument_list|)
operator|+
name|qp
operator|->
name|s_max_sge
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|rvt_sge
argument_list|)
operator|)
operator|*
name|n
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Since struct rvt_rwqe is not a fixed size, we can't simply index into  * struct rvt_rwq.wq.  This function does the array index computation.  */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|rvt_rwqe
modifier|*
name|rvt_get_rwqe_ptr
parameter_list|(
name|struct
name|rvt_rq
modifier|*
name|rq
parameter_list|,
name|unsigned
name|n
parameter_list|)
block|{
return|return
operator|(
expr|struct
name|rvt_rwqe
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|rq
operator|->
name|wq
operator|->
name|wq
operator|+
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|rvt_rwqe
argument_list|)
operator|+
name|rq
operator|->
name|max_sge
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|ib_sge
argument_list|)
operator|)
operator|*
name|n
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * rvt_get_qp - get a QP reference  * @qp - the QP to hold  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|rvt_get_qp
parameter_list|(
name|struct
name|rvt_qp
modifier|*
name|qp
parameter_list|)
block|{
name|atomic_inc
argument_list|(
operator|&
name|qp
operator|->
name|refcount
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * rvt_put_qp - release a QP reference  * @qp - the QP to release  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|rvt_put_qp
parameter_list|(
name|struct
name|rvt_qp
modifier|*
name|qp
parameter_list|)
block|{
if|if
condition|(
name|qp
operator|&&
name|atomic_dec_and_test
argument_list|(
operator|&
name|qp
operator|->
name|refcount
argument_list|)
condition|)
name|wake_up
argument_list|(
operator|&
name|qp
operator|->
name|wait
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * rvt_qp_wqe_reserve - reserve operation  * @qp - the rvt qp  * @wqe - the send wqe  *  * This routine used in post send to record  * a wqe relative reserved operation use.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|rvt_qp_wqe_reserve
parameter_list|(
name|struct
name|rvt_qp
modifier|*
name|qp
parameter_list|,
name|struct
name|rvt_swqe
modifier|*
name|wqe
parameter_list|)
block|{
name|wqe
operator|->
name|wr
operator|.
name|send_flags
operator||=
name|RVT_SEND_RESERVE_USED
expr_stmt|;
name|atomic_inc
argument_list|(
operator|&
name|qp
operator|->
name|s_reserved_used
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * rvt_qp_wqe_unreserve - clean reserved operation  * @qp - the rvt qp  * @wqe - the send wqe  *  * This decrements the reserve use count.  *  * This call MUST precede the change to  * s_last to insure that post send sees a stable  * s_avail.  *  * An smp_mp__after_atomic() is used to insure  * the compiler does not juggle the order of the s_last  * ring index and the decrementing of s_reserved_used.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|rvt_qp_wqe_unreserve
parameter_list|(
name|struct
name|rvt_qp
modifier|*
name|qp
parameter_list|,
name|struct
name|rvt_swqe
modifier|*
name|wqe
parameter_list|)
block|{
if|if
condition|(
name|unlikely
argument_list|(
name|wqe
operator|->
name|wr
operator|.
name|send_flags
operator|&
name|RVT_SEND_RESERVE_USED
argument_list|)
condition|)
block|{
name|wqe
operator|->
name|wr
operator|.
name|send_flags
operator|&=
operator|~
name|RVT_SEND_RESERVE_USED
expr_stmt|;
name|atomic_dec
argument_list|(
operator|&
name|qp
operator|->
name|s_reserved_used
argument_list|)
expr_stmt|;
comment|/* insure no compiler re-order up to s_last change */
name|smp_mb__after_atomic
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|ib_rvt_state_ops
index|[]
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|rvt_dev_info
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|rvt_error_qp
parameter_list|(
name|struct
name|rvt_qp
modifier|*
name|qp
parameter_list|,
name|enum
name|ib_wc_status
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEF_RDMAVT_INCQP_H */
end_comment

end_unit

