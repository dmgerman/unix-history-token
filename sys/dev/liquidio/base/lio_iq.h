begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   BSD LICENSE  *  *   Copyright(c) 2017 Cavium, Inc.. All rights reserved.  *   All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in  *       the documentation and/or other materials provided with the  *       distribution.  *     * Neither the name of Cavium, Inc. nor the names of its  *       contributors may be used to endorse or promote products derived  *       from this software without specific prior written permission.  *  *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *   OWNER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_comment
comment|/*   \file  lio_iq.h  *   \brief Host Driver: Implementation of Octeon input queues. "Input" is  *   with respect to the Octeon device on the NIC. From this driver's  *   point of view they are egress queues.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIO_IQ_H__
end_ifndef

begin_define
define|#
directive|define
name|__LIO_IQ_H__
end_define

begin_define
define|#
directive|define
name|LIO_IQ_SEND_OK
value|0
end_define

begin_define
define|#
directive|define
name|LIO_IQ_SEND_STOP
value|1
end_define

begin_define
define|#
directive|define
name|LIO_IQ_SEND_FAILED
value|-1
end_define

begin_comment
comment|/*-------------------------  INSTRUCTION QUEUE --------------------------*/
end_comment

begin_define
define|#
directive|define
name|LIO_REQTYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|LIO_REQTYPE_NORESP_NET
value|1
end_define

begin_define
define|#
directive|define
name|LIO_REQTYPE_NORESP_NET_SG
value|2
end_define

begin_define
define|#
directive|define
name|LIO_REQTYPE_RESP_NET
value|3
end_define

begin_define
define|#
directive|define
name|LIO_REQTYPE_SOFT_COMMAND
value|4
end_define

begin_comment
comment|/*  * This structure is used by NIC driver to store information required  * to free the mbuf when the packet has been fetched by Octeon.  * Bytes offset below assume worst-case of a 64-bit system.  */
end_comment

begin_struct
struct|struct
name|lio_mbuf_free_info
block|{
comment|/* Pointer to mbuf. */
name|struct
name|mbuf
modifier|*
name|mb
decl_stmt|;
comment|/* Pointer to gather list. */
name|struct
name|lio_gather
modifier|*
name|g
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lio_request_list
block|{
name|uint32_t
name|reqtype
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|struct
name|lio_mbuf_free_info
name|finfo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Input Queue statistics. Each input queue has four stats fields. */
end_comment

begin_struct
struct|struct
name|lio_iq_stats
block|{
name|uint64_t
name|instr_posted
decl_stmt|;
comment|/**< Instructions posted to this queue. */
name|uint64_t
name|instr_processed
decl_stmt|;
comment|/**< Instructions processed in this queue. */
name|uint64_t
name|instr_dropped
decl_stmt|;
comment|/**< Instructions that could not be processed */
name|uint64_t
name|bytes_sent
decl_stmt|;
comment|/**< Bytes sent through this queue. */
name|uint64_t
name|sgentry_sent
decl_stmt|;
comment|/**< Gather entries sent through this queue. */
name|uint64_t
name|tx_done
decl_stmt|;
comment|/**< Num of packets sent to network. */
name|uint64_t
name|tx_iq_busy
decl_stmt|;
comment|/**< Numof times this iq was found to be full. */
name|uint64_t
name|tx_dropped
decl_stmt|;
comment|/**< Numof pkts dropped dueto xmitpath errors. */
name|uint64_t
name|tx_tot_bytes
decl_stmt|;
comment|/**< Total count of bytes sento to network. */
name|uint64_t
name|tx_gso
decl_stmt|;
comment|/* count of tso */
name|uint64_t
name|tx_vxlan
decl_stmt|;
comment|/* tunnel */
name|uint64_t
name|tx_dmamap_fail
decl_stmt|;
name|uint64_t
name|tx_restart
decl_stmt|;
name|uint64_t
name|mbuf_defrag_failed
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  The instruction (input) queue.  *  The input queue is used to post raw (instruction) mode data or packet  *  data to Octeon device from the host. Each input queue for  *  a Octeon device has one such structure to represent it.  */
end_comment

begin_struct
struct|struct
name|lio_instr_queue
block|{
name|struct
name|octeon_device
modifier|*
name|oct_dev
decl_stmt|;
comment|/* A lock to protect access to the input ring.  */
name|struct
name|mtx
name|lock
decl_stmt|;
comment|/* A lock to protect while enqueue to the input ring.  */
name|struct
name|mtx
name|enq_lock
decl_stmt|;
comment|/* A lock to protect while posting on the ring.  */
name|struct
name|mtx
name|post_lock
decl_stmt|;
name|uint32_t
name|pkt_in_done
decl_stmt|;
comment|/* A lock to protect access to the input ring. */
name|struct
name|mtx
name|iq_flush_running_lock
decl_stmt|;
comment|/* Flag that indicates if the queue uses 64 byte commands. */
name|uint32_t
name|iqcmd_64B
range|:
literal|1
decl_stmt|;
comment|/* Queue info. */
name|union
name|octeon_txpciq
name|txpciq
decl_stmt|;
name|uint32_t
name|rsvd
range|:
literal|17
decl_stmt|;
name|uint32_t
name|status
range|:
literal|8
decl_stmt|;
comment|/* Maximum no. of instructions in this queue. */
name|uint32_t
name|max_count
decl_stmt|;
comment|/* Index in input ring where the driver should write the next packet */
name|uint32_t
name|host_write_index
decl_stmt|;
comment|/* 	 * Index in input ring where Octeon is expected to read the next 	 * packet. 	 */
name|uint32_t
name|octeon_read_index
decl_stmt|;
comment|/* 	 * This index aids in finding the window in the queue where Octeon 	 * has read the commands. 	 */
name|uint32_t
name|flush_index
decl_stmt|;
comment|/* This field keeps track of the instructions pending in this queue. */
specifier|volatile
name|int
name|instr_pending
decl_stmt|;
name|uint32_t
name|reset_instr_cnt
decl_stmt|;
comment|/* Pointer to the Virtual Base addr of the input ring. */
name|uint8_t
modifier|*
name|base_addr
decl_stmt|;
name|bus_dma_tag_t
name|txtag
decl_stmt|;
name|struct
name|lio_request_list
modifier|*
name|request_list
decl_stmt|;
name|struct
name|buf_ring
modifier|*
name|br
decl_stmt|;
comment|/* Octeon doorbell register for the ring. */
name|uint32_t
name|doorbell_reg
decl_stmt|;
comment|/* Octeon instruction count register for this ring. */
name|uint32_t
name|inst_cnt_reg
decl_stmt|;
comment|/* Number of instructions pending to be posted to Octeon. */
name|uint32_t
name|fill_cnt
decl_stmt|;
comment|/* The last time that the doorbell was rung. */
name|uint64_t
name|last_db_time
decl_stmt|;
comment|/* 	 * The doorbell timeout. If the doorbell was not rung for this time 	 * and fill_cnt is non-zero, ring the doorbell again. 	 */
name|uint32_t
name|db_timeout
decl_stmt|;
comment|/* Statistics for this input queue. */
name|struct
name|lio_iq_stats
name|stats
decl_stmt|;
comment|/* DMA mapped base address of the input descriptor ring. */
name|uint64_t
name|base_addr_dma
decl_stmt|;
comment|/* Application context */
name|void
modifier|*
name|app_ctx
decl_stmt|;
comment|/* network stack queue index */
name|int
name|q_index
decl_stmt|;
comment|/* os ifidx associated with this queue */
name|int
name|ifidx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*----------------------  INSTRUCTION FORMAT ----------------------------*/
end_comment

begin_struct
struct|struct
name|lio_instr3_64B
block|{
comment|/* Pointer where the input data is available. */
name|uint64_t
name|dptr
decl_stmt|;
comment|/* Instruction Header. */
name|uint64_t
name|ih3
decl_stmt|;
comment|/* Instruction Header. */
name|uint64_t
name|pki_ih3
decl_stmt|;
comment|/* Input Request Header. */
name|uint64_t
name|irh
decl_stmt|;
comment|/* opcode/subcode specific parameters */
name|uint64_t
name|ossp
index|[
literal|2
index|]
decl_stmt|;
comment|/* Return Data Parameters */
name|uint64_t
name|rdp
decl_stmt|;
comment|/* 	 * Pointer where the response for a RAW mode packet will be written 	 * by Octeon. 	 */
name|uint64_t
name|rptr
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|lio_instr_64B
block|{
name|struct
name|lio_instr3_64B
name|cmd3
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* The size of each buffer in soft command buffer pool */
end_comment

begin_define
define|#
directive|define
name|LIO_SOFT_COMMAND_BUFFER_SIZE
value|2048
end_define

begin_struct
struct|struct
name|lio_soft_command
block|{
comment|/* Soft command buffer info. */
name|struct
name|lio_stailq_node
name|node
decl_stmt|;
name|uint64_t
name|dma_addr
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
comment|/* Command and return status */
name|union
name|lio_instr_64B
name|cmd
decl_stmt|;
define|#
directive|define
name|COMPLETION_WORD_INIT
value|0xffffffffffffffffULL
name|uint64_t
modifier|*
name|status_word
decl_stmt|;
comment|/* Data buffer info */
name|void
modifier|*
name|virtdptr
decl_stmt|;
name|uint64_t
name|dmadptr
decl_stmt|;
name|uint32_t
name|datasize
decl_stmt|;
comment|/* Return buffer info */
name|void
modifier|*
name|virtrptr
decl_stmt|;
name|uint64_t
name|dmarptr
decl_stmt|;
name|uint32_t
name|rdatasize
decl_stmt|;
comment|/* Context buffer info */
name|void
modifier|*
name|ctxptr
decl_stmt|;
name|uint32_t
name|ctxsize
decl_stmt|;
comment|/* Time out and callback */
name|int
name|wait_time
decl_stmt|;
name|int
name|timeout
decl_stmt|;
name|uint32_t
name|iq_no
decl_stmt|;
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|struct
name|octeon_device
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|callback_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Maximum number of buffers to allocate into soft command buffer pool */
end_comment

begin_define
define|#
directive|define
name|LIO_MAX_SOFT_COMMAND_BUFFERS
value|256
end_define

begin_comment
comment|/* Head of a soft command buffer pool. */
end_comment

begin_struct
struct|struct
name|lio_sc_buffer_pool
block|{
comment|/* List structure to add delete pending entries to */
name|struct
name|lio_stailq_head
name|head
decl_stmt|;
comment|/* A lock for this response list */
name|struct
name|mtx
name|lock
decl_stmt|;
specifier|volatile
name|uint32_t
name|alloc_buf_count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIO_INCR_INSTRQUEUE_PKT_COUNT
parameter_list|(
name|octeon_dev_ptr
parameter_list|,
name|iq_no
parameter_list|,
name|field
parameter_list|,
name|count
parameter_list|)
define|\
value|(((octeon_dev_ptr)->instr_queue[iq_no]->stats.field) += count)
end_define

begin_function_decl
name|int
name|lio_setup_sc_buffer_pool
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_free_sc_buffer_pool
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|lio_soft_command
modifier|*
name|lio_alloc_soft_command
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|datasize
parameter_list|,
name|uint32_t
name|rdatasize
parameter_list|,
name|uint32_t
name|ctxsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lio_free_soft_command
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|struct
name|lio_soft_command
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  lio_init_instr_queue()  *  @param octeon_dev      - pointer to the octeon device structure.  *  @param txpciq          - queue to be initialized (0<= q_no<= 3).  *  *  Called at driver init time for each input queue. iq_conf has the  *  configuration parameters for the queue.  *  *  @return  Success: 0   Failure: 1  */
end_comment

begin_function_decl
name|int
name|lio_init_instr_queue
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|octeon_dev
parameter_list|,
name|union
name|octeon_txpciq
name|txpciq
parameter_list|,
name|uint32_t
name|num_descs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  lio_delete_instr_queue()  *  @param octeon_dev      - pointer to the octeon device structure.  *  @param iq_no           - queue to be deleted  *  *  Called at driver unload time for each input queue. Deletes all  *  allocated resources for the input queue.  *  *  @return  Success: 0   Failure: 1  */
end_comment

begin_function_decl
name|int
name|lio_delete_instr_queue
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|octeon_dev
parameter_list|,
name|uint32_t
name|iq_no
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_wait_for_instr_fetch
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_process_iq_request_list
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|struct
name|lio_instr_queue
modifier|*
name|iq
parameter_list|,
name|uint32_t
name|budget
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_send_command
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|iq_no
parameter_list|,
name|uint32_t
name|force_db
parameter_list|,
name|void
modifier|*
name|cmd
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|uint32_t
name|datasize
parameter_list|,
name|uint32_t
name|reqtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lio_prepare_soft_command
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|struct
name|lio_soft_command
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|opcode
parameter_list|,
name|uint8_t
name|subcode
parameter_list|,
name|uint32_t
name|irh_ossp
parameter_list|,
name|uint64_t
name|ossp0
parameter_list|,
name|uint64_t
name|ossp1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_send_soft_command
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|struct
name|lio_soft_command
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_setup_iq
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|int
name|ifidx
parameter_list|,
name|int
name|q_index
parameter_list|,
name|union
name|octeon_txpciq
name|iq_no
parameter_list|,
name|uint32_t
name|num_descs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_flush_iq
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|struct
name|lio_instr_queue
modifier|*
name|iq
parameter_list|,
name|uint32_t
name|budget
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LIO_IQ_H__ */
end_comment

end_unit

