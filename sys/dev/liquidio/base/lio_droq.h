begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   BSD LICENSE  *  *   Copyright(c) 2017 Cavium, Inc.. All rights reserved.  *   All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in  *       the documentation and/or other materials provided with the  *       distribution.  *     * Neither the name of Cavium, Inc. nor the names of its  *       contributors may be used to endorse or promote products derived  *       from this software without specific prior written permission.  *  *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *   OWNER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_comment
comment|/*   \file  lio_droq.h  *   \brief Implementation of Octeon Output queues. "Output" is with  *   respect to the Octeon device on the NIC. From this driver's point of  *   view they are ingress queues.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIO_DROQ_H__
end_ifndef

begin_define
define|#
directive|define
name|__LIO_DROQ_H__
end_define

begin_comment
comment|/*  *  Octeon descriptor format.  *  The descriptor ring is made of descriptors which have 2 64-bit values:  *  -# Physical (bus) address of the data buffer.  *  -# Physical (bus) address of a lio_droq_info structure.  *  The Octeon device DMA's incoming packets and its information at the address  *  given by these descriptor fields.  */
end_comment

begin_struct
struct|struct
name|lio_droq_desc
block|{
comment|/* The buffer pointer */
name|uint64_t
name|buffer_ptr
decl_stmt|;
comment|/* The Info pointer */
name|uint64_t
name|info_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIO_DROQ_DESC_SIZE
value|(sizeof(struct lio_droq_desc))
end_define

begin_comment
comment|/*  *  Information about packet DMA'ed by Octeon.  *  The format of the information available at Info Pointer after Octeon  *  has posted a packet. Not all descriptors have valid information. Only  *  the Info field of the first descriptor for a packet has information  *  about the packet.  */
end_comment

begin_struct
struct|struct
name|lio_droq_info
block|{
comment|/* The Length of the packet. */
name|uint64_t
name|length
decl_stmt|;
comment|/* The Output Receive Header. */
name|union
name|octeon_rh
name|rh
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIO_DROQ_INFO_SIZE
value|(sizeof(struct lio_droq_info))
end_define

begin_comment
comment|/*  *  Pointer to data buffer.  *  Driver keeps a pointer to the data buffer that it made available to  *  the Octeon device. Since the descriptor ring keeps physical (bus)  *  addresses, this field is required for the driver to keep track of  *  the virtual address pointers.  */
end_comment

begin_struct
struct|struct
name|lio_recv_buffer
block|{
comment|/* Packet buffer, including metadata. */
name|void
modifier|*
name|buffer
decl_stmt|;
comment|/* Data in the packet buffer.  */
name|uint8_t
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIO_DROQ_RECVBUF_SIZE
value|(sizeof(struct lio_recv_buffer))
end_define

begin_comment
comment|/* Output Queue statistics. Each output queue has four stats fields. */
end_comment

begin_struct
struct|struct
name|lio_droq_stats
block|{
comment|/* Number of packets received in this queue. */
name|uint64_t
name|pkts_received
decl_stmt|;
comment|/* Bytes received by this queue. */
name|uint64_t
name|bytes_received
decl_stmt|;
comment|/* Packets dropped due to no dispatch function. */
name|uint64_t
name|dropped_nodispatch
decl_stmt|;
comment|/* Packets dropped due to no memory available. */
name|uint64_t
name|dropped_nomem
decl_stmt|;
comment|/* Packets dropped due to large number of pkts to process. */
name|uint64_t
name|dropped_toomany
decl_stmt|;
comment|/* Number of packets  sent to stack from this queue. */
name|uint64_t
name|rx_pkts_received
decl_stmt|;
comment|/* Number of Bytes sent to stack from this queue. */
name|uint64_t
name|rx_bytes_received
decl_stmt|;
comment|/* Num of Packets dropped due to receive path failures. */
name|uint64_t
name|rx_dropped
decl_stmt|;
name|uint64_t
name|rx_vxlan
decl_stmt|;
comment|/* Num of failures of lio_recv_buffer_alloc() */
name|uint64_t
name|rx_alloc_failure
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The maximum number of buffers that can be dispatched from the  * output/dma queue. Set to 64 assuming 1K buffers in DROQ and the fact that  * max packet size from DROQ is 64K.  */
end_comment

begin_define
define|#
directive|define
name|LIO_MAX_RECV_BUFS
value|64
end_define

begin_comment
comment|/*  *  Receive Packet format used when dispatching output queue packets  *  with non-raw opcodes.  *  The received packet will be sent to the upper layers using this  *  structure which is passed as a parameter to the dispatch function  */
end_comment

begin_struct
struct|struct
name|lio_recv_pkt
block|{
comment|/* Number of buffers in this received packet */
name|uint16_t
name|buffer_count
decl_stmt|;
comment|/* Id of the device that is sending the packet up */
name|uint16_t
name|octeon_id
decl_stmt|;
comment|/* Length of data in the packet buffer */
name|uint32_t
name|length
decl_stmt|;
comment|/* The receive header */
name|union
name|octeon_rh
name|rh
decl_stmt|;
comment|/* Pointer to the OS-specific packet buffer */
name|struct
name|mbuf
modifier|*
name|buffer_ptr
index|[
name|LIO_MAX_RECV_BUFS
index|]
decl_stmt|;
comment|/* Size of the buffers pointed to by ptr's in buffer_ptr */
name|uint32_t
name|buffer_size
index|[
name|LIO_MAX_RECV_BUFS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIO_RECV_PKT_SIZE
value|(sizeof(struct lio_recv_pkt))
end_define

begin_comment
comment|/*  *  The first parameter of a dispatch function.  *  For a raw mode opcode, the driver dispatches with the device  *  pointer in this structure.  *  For non-raw mode opcode, the driver dispatches the recv_pkt  *  created to contain the buffers with data received from Octeon.  *  ---------------------  *  |     *recv_pkt ----|---  *  |-------------------|   |  *  | 0 or more bytes   |   |  *  | reserved by driver|   |  *  |-------------------|<-/  *  | lio_recv_pkt   |  *  |                   |  *  |___________________|  */
end_comment

begin_struct
struct|struct
name|lio_recv_info
block|{
name|void
modifier|*
name|rsvd
decl_stmt|;
name|struct
name|lio_recv_pkt
modifier|*
name|recv_pkt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIO_RECV_INFO_SIZE
value|(sizeof(struct lio_recv_info))
end_define

begin_comment
comment|/*  *  Allocate a recv_info structure. The recv_pkt pointer in the recv_info  *  structure is filled in before this call returns.  *  @param extra_bytes - extra bytes to be allocated at the end of the recv info  *                       structure.  *  @return - pointer to a newly allocated recv_info structure.  */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|lio_recv_info
modifier|*
name|lio_alloc_recv_info
parameter_list|(
name|int
name|extra_bytes
parameter_list|)
block|{
name|struct
name|lio_recv_info
modifier|*
name|recv_info
decl_stmt|;
name|uint8_t
modifier|*
name|buf
decl_stmt|;
name|buf
operator|=
name|malloc
argument_list|(
name|LIO_RECV_PKT_SIZE
operator|+
name|LIO_RECV_INFO_SIZE
operator|+
name|extra_bytes
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_NOWAIT
operator||
name|M_ZERO
argument_list|)
expr_stmt|;
if|if
condition|(
name|buf
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|recv_info
operator|=
operator|(
expr|struct
name|lio_recv_info
operator|*
operator|)
name|buf
expr_stmt|;
name|recv_info
operator|->
name|recv_pkt
operator|=
operator|(
expr|struct
name|lio_recv_pkt
operator|*
operator|)
operator|(
name|buf
operator|+
name|LIO_RECV_INFO_SIZE
operator|)
expr_stmt|;
name|recv_info
operator|->
name|rsvd
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|extra_bytes
condition|)
name|recv_info
operator|->
name|rsvd
operator|=
name|buf
operator|+
name|LIO_RECV_INFO_SIZE
operator|+
name|LIO_RECV_PKT_SIZE
expr_stmt|;
return|return
operator|(
name|recv_info
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *  Free a recv_info structure.  *  @param recv_info - Pointer to receive_info to be freed  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|lio_free_recv_info
parameter_list|(
name|struct
name|lio_recv_info
modifier|*
name|recv_info
parameter_list|)
block|{
name|free
argument_list|(
name|recv_info
argument_list|,
name|M_DEVBUF
argument_list|)
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|lio_dispatch_fn_t
function_decl|)
parameter_list|(
name|struct
name|lio_recv_info
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Used by NIC module to register packet handler and to get device  * information for each octeon device.  */
end_comment

begin_struct
struct|struct
name|lio_droq_ops
block|{
comment|/* 	 *  This registered function will be called by the driver with 	 *  the pointer to buffer from droq and length of 	 *  data in the buffer. The receive header gives the port 	 *  number to the caller.  Function pointer is set by caller. 	 */
name|void
function_decl|(
modifier|*
name|fptr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|union
name|octeon_rh
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|farg
decl_stmt|;
comment|/* 	 *  Flag indicating if the DROQ handler should drop packets that 	 *  it cannot handle in one iteration. Set by caller. 	 */
name|uint32_t
name|drop_on_max
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The Descriptor Ring Output Queue structure.  *  This structure has all the information required to implement a  *  Octeon DROQ.  */
end_comment

begin_struct
struct|struct
name|lio_droq
block|{
comment|/* A lock to protect access to this ring. */
name|struct
name|mtx
name|lock
decl_stmt|;
name|uint32_t
name|q_no
decl_stmt|;
name|uint32_t
name|pkt_count
decl_stmt|;
name|struct
name|lio_droq_ops
name|ops
decl_stmt|;
name|struct
name|octeon_device
modifier|*
name|oct_dev
decl_stmt|;
comment|/* The 8B aligned descriptor ring starts at this address. */
name|struct
name|lio_droq_desc
modifier|*
name|desc_ring
decl_stmt|;
comment|/* Index in the ring where the driver should read the next packet */
name|uint32_t
name|read_idx
decl_stmt|;
comment|/* 	 * Index in the ring where the driver will refill the descriptor's 	 * buffer 	 */
name|uint32_t
name|refill_idx
decl_stmt|;
comment|/* Packets pending to be processed */
specifier|volatile
name|int
name|pkts_pending
decl_stmt|;
comment|/* Number of  descriptors in this ring. */
name|uint32_t
name|max_count
decl_stmt|;
comment|/* The number of descriptors pending refill. */
name|uint32_t
name|refill_count
decl_stmt|;
name|uint32_t
name|pkts_per_intr
decl_stmt|;
name|uint32_t
name|refill_threshold
decl_stmt|;
comment|/* 	 * The max number of descriptors in DROQ without a buffer. 	 * This field is used to keep track of empty space threshold. If the 	 * refill_count reaches this value, the DROQ cannot accept a max-sized 	 * (64K) packet. 	 */
name|uint32_t
name|max_empty_descs
decl_stmt|;
comment|/* 	 * The receive buffer list. This list has the virtual addresses of 	 * the buffers. 	 */
name|struct
name|lio_recv_buffer
modifier|*
name|recv_buf_list
decl_stmt|;
comment|/* The size of each buffer pointed by the buffer pointer. */
name|uint32_t
name|buffer_size
decl_stmt|;
comment|/* 	 * Offset to packet credit register. 	 * Host writes number of info/buffer ptrs available to this register 	 */
name|uint32_t
name|pkts_credit_reg
decl_stmt|;
comment|/* 	 * Offset packet sent register. 	 * Octeon writes the number of packets DMA'ed to host memory 	 * in this register. 	 */
name|uint32_t
name|pkts_sent_reg
decl_stmt|;
name|struct
name|lio_stailq_head
name|dispatch_stq_head
decl_stmt|;
comment|/* Statistics for this DROQ. */
name|struct
name|lio_droq_stats
name|stats
decl_stmt|;
comment|/* DMA mapped address of the DROQ descriptor ring. */
name|vm_paddr_t
name|desc_ring_dma
decl_stmt|;
comment|/* application context */
name|void
modifier|*
name|app_ctx
decl_stmt|;
name|uint32_t
name|cpu_id
decl_stmt|;
name|struct
name|task
name|droq_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|droq_taskqueue
decl_stmt|;
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIO_DROQ_SIZE
value|(sizeof(struct lio_droq))
end_define

begin_comment
comment|/*  * Allocates space for the descriptor ring for the droq and sets the  *   base addr, num desc etc in Octeon registers.  *  * @param  oct_dev    - pointer to the octeon device structure  * @param  q_no       - droq no.  * @param app_ctx     - pointer to application context  * @return Success: 0    Failure: 1  */
end_comment

begin_function_decl
name|int
name|lio_init_droq
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct_dev
parameter_list|,
name|uint32_t
name|q_no
parameter_list|,
name|uint32_t
name|num_descs
parameter_list|,
name|uint32_t
name|desc_size
parameter_list|,
name|void
modifier|*
name|app_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Frees the space for descriptor ring for the droq.  *  *  @param oct_dev - pointer to the octeon device structure  *  @param q_no    - droq no.  *  @return:    Success: 0    Failure: 1  */
end_comment

begin_function_decl
name|int
name|lio_delete_droq
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct_dev
parameter_list|,
name|uint32_t
name|q_no
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Register a change in droq operations. The ops field has a pointer to a  * function which will called by the DROQ handler for all packets arriving  * on output queues given by q_no irrespective of the type of packet.  * The ops field also has a flag which if set tells the DROQ handler to  * drop packets if it receives more than what it can process in one  * invocation of the handler.  * @param oct       - octeon device  * @param q_no      - octeon output queue number (0<= q_no<= MAX_OCTEON_DROQ-1  * @param ops       - the droq_ops settings for this queue  * @return          - 0 on success, -ENODEV or -EINVAL on error.  */
end_comment

begin_function_decl
name|int
name|lio_register_droq_ops
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|q_no
parameter_list|,
name|struct
name|lio_droq_ops
modifier|*
name|ops
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Resets the function pointer and flag settings made by  * lio_register_droq_ops(). After this routine is called, the DROQ handler  * will lookup dispatch function for each arriving packet on the output queue  * given by q_no.  * @param oct       - octeon device  * @param q_no      - octeon output queue number (0<= q_no<= MAX_OCTEON_DROQ-1  * @return          - 0 on success, -ENODEV or -EINVAL on error.  */
end_comment

begin_function_decl
name|int
name|lio_unregister_droq_ops
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|q_no
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *    Register a dispatch function for a opcode/subcode. The driver will call  *    this dispatch function when it receives a packet with the given  *    opcode/subcode in its output queues along with the user specified  *    argument.  *    @param  oct        - the octeon device to register with.  *    @param  opcode     - the opcode for which the dispatch will be registered.  *    @param  subcode    - the subcode for which the dispatch will be registered  *    @param  fn         - the dispatch function.  *    @param  fn_arg     - user specified that will be passed along with the  *                         dispatch function by the driver.  *    @return Success: 0; Failure: 1  */
end_comment

begin_function_decl
name|int
name|lio_register_dispatch_fn
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint16_t
name|opcode
parameter_list|,
name|uint16_t
name|subcode
parameter_list|,
name|lio_dispatch_fn_t
name|fn
parameter_list|,
name|void
modifier|*
name|fn_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *   Remove registration for an opcode/subcode. This will delete the mapping for  *   an opcode/subcode. The dispatch function will be unregistered and will no  *   longer be called if a packet with the opcode/subcode arrives in the driver  *   output queues.  *   @param  oct        -  the octeon device to unregister from.  *   @param  opcode     -  the opcode to be unregistered.  *   @param  subcode    -  the subcode to be unregistered.  *  *   @return Success: 0; Failure: 1  */
end_comment

begin_function_decl
name|int
name|lio_unregister_dispatch_fn
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint16_t
name|opcode
parameter_list|,
name|uint16_t
name|subcode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|lio_droq_check_hw_for_pkts
parameter_list|(
name|struct
name|lio_droq
modifier|*
name|droq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_create_droq
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|q_no
parameter_list|,
name|uint32_t
name|num_descs
parameter_list|,
name|uint32_t
name|desc_size
parameter_list|,
name|void
modifier|*
name|app_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_droq_process_packets
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|struct
name|lio_droq
modifier|*
name|droq
parameter_list|,
name|uint32_t
name|budget
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|lio_droq_refill
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|octeon_dev
parameter_list|,
name|struct
name|lio_droq
modifier|*
name|droq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lio_droq_bh
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|pending
name|__unused
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LIO_DROQ_H__ */
end_comment

end_unit

