begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup group_udma_api API  * @ingroup group_udma  * UDMA API  * @{  * @}  *  * @defgroup group_udma_main UDMA Main  * @ingroup group_udma_api  * UDMA main API  * @{  * @file   al_hal_udma.h  *  * @brief C Header file for the Universal DMA HAL driver  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_UDMA_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_UDMA_H__
end_define

begin_include
include|#
directive|include
file|"al_hal_common.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_udma_regs.h"
end_include

begin_comment
comment|/* *INDENT-OFF* */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* *INDENT-ON* */
define|#
directive|define
name|DMA_MAX_Q
value|4
define|#
directive|define
name|AL_UDMA_MIN_Q_SIZE
value|4
define|#
directive|define
name|AL_UDMA_MAX_Q_SIZE
value|(1<< 16)
comment|/* hw can do more, but we limit it */
comment|/* Default Max number of descriptors supported per action */
define|#
directive|define
name|AL_UDMA_DEFAULT_MAX_ACTN_DESCS
value|16
define|#
directive|define
name|AL_UDMA_REV_ID_1
value|1
define|#
directive|define
name|AL_UDMA_REV_ID_2
value|2
define|#
directive|define
name|DMA_RING_ID_MASK
value|0x3
comment|/* New registers ?? */
comment|/* Statistics - TBD */
comment|/** UDMA submission descriptor */
union|union
name|al_udma_desc
block|{
comment|/* TX */
struct|struct
block|{
name|uint32_t
name|len_ctrl
decl_stmt|;
name|uint32_t
name|meta_ctrl
decl_stmt|;
name|uint64_t
name|buf_ptr
decl_stmt|;
block|}
name|tx
struct|;
comment|/* TX Meta, used by upper layer */
struct|struct
block|{
name|uint32_t
name|len_ctrl
decl_stmt|;
name|uint32_t
name|meta_ctrl
decl_stmt|;
name|uint32_t
name|meta1
decl_stmt|;
name|uint32_t
name|meta2
decl_stmt|;
block|}
name|tx_meta
struct|;
comment|/* RX */
struct|struct
block|{
name|uint32_t
name|len_ctrl
decl_stmt|;
name|uint32_t
name|buf2_ptr_lo
decl_stmt|;
name|uint64_t
name|buf1_ptr
decl_stmt|;
block|}
name|rx
struct|;
block|}
name|__packed_a16
union|;
comment|/* TX desc length and control fields */
define|#
directive|define
name|AL_M2S_DESC_CONCAT
value|AL_BIT(31)
comment|/* concatenate */
define|#
directive|define
name|AL_M2S_DESC_DMB
value|AL_BIT(30)
comment|/** Data Memory Barrier */
define|#
directive|define
name|AL_M2S_DESC_NO_SNOOP_H
value|AL_BIT(29)
define|#
directive|define
name|AL_M2S_DESC_INT_EN
value|AL_BIT(28)
comment|/** enable interrupt */
define|#
directive|define
name|AL_M2S_DESC_LAST
value|AL_BIT(27)
define|#
directive|define
name|AL_M2S_DESC_FIRST
value|AL_BIT(26)
define|#
directive|define
name|AL_M2S_DESC_RING_ID_SHIFT
value|24
define|#
directive|define
name|AL_M2S_DESC_RING_ID_MASK
value|(0x3<< AL_M2S_DESC_RING_ID_SHIFT)
define|#
directive|define
name|AL_M2S_DESC_META_DATA
value|AL_BIT(23)
define|#
directive|define
name|AL_M2S_DESC_DUMMY
value|AL_BIT(22)
comment|/* for Metdata only */
define|#
directive|define
name|AL_M2S_DESC_LEN_ADJ_SHIFT
value|20
define|#
directive|define
name|AL_M2S_DESC_LEN_ADJ_MASK
value|(0x7<< AL_M2S_DESC_LEN_ADJ_SHIFT)
define|#
directive|define
name|AL_M2S_DESC_LEN_SHIFT
value|0
define|#
directive|define
name|AL_M2S_DESC_LEN_MASK
value|(0xfffff<< AL_M2S_DESC_LEN_SHIFT)
define|#
directive|define
name|AL_S2M_DESC_DUAL_BUF
value|AL_BIT(31)
define|#
directive|define
name|AL_S2M_DESC_NO_SNOOP_H
value|AL_BIT(29)
define|#
directive|define
name|AL_S2M_DESC_INT_EN
value|AL_BIT(28)
comment|/** enable interrupt */
define|#
directive|define
name|AL_S2M_DESC_RING_ID_SHIFT
value|24
define|#
directive|define
name|AL_S2M_DESC_RING_ID_MASK
value|(0x3<< AL_S2M_DESC_RING_ID_SHIFT)
define|#
directive|define
name|AL_S2M_DESC_LEN_SHIFT
value|0
define|#
directive|define
name|AL_S2M_DESC_LEN_MASK
value|(0xffff<< AL_S2M_DESC_LEN_SHIFT)
define|#
directive|define
name|AL_S2M_DESC_LEN2_SHIFT
value|16
define|#
directive|define
name|AL_S2M_DESC_LEN2_MASK
value|(0x3fff<< AL_S2M_DESC_LEN2_SHIFT)
define|#
directive|define
name|AL_S2M_DESC_LEN2_GRANULARITY_SHIFT
value|6
comment|/* TX/RX descriptor Target-ID field (in the buffer address 64 bit field) */
define|#
directive|define
name|AL_UDMA_DESC_TGTID_SHIFT
value|48
comment|/** UDMA completion descriptor */
union|union
name|al_udma_cdesc
block|{
comment|/* TX completion */
struct|struct
block|{
name|uint32_t
name|ctrl_meta
decl_stmt|;
block|}
name|al_desc_comp_tx
struct|;
comment|/* RX completion */
struct|struct
block|{
comment|/* TBD */
name|uint32_t
name|ctrl_meta
decl_stmt|;
block|}
name|al_desc_comp_rx
struct|;
block|}
name|__packed_a4
union|;
comment|/* TX/RX common completion desc ctrl_meta feilds */
define|#
directive|define
name|AL_UDMA_CDESC_ERROR
value|AL_BIT(31)
define|#
directive|define
name|AL_UDMA_CDESC_BUF1_USED
value|AL_BIT(30)
define|#
directive|define
name|AL_UDMA_CDESC_DDP
value|AL_BIT(29)
define|#
directive|define
name|AL_UDMA_CDESC_LAST
value|AL_BIT(27)
define|#
directive|define
name|AL_UDMA_CDESC_FIRST
value|AL_BIT(26)
comment|/* word 2 */
define|#
directive|define
name|AL_UDMA_CDESC_BUF2_USED
value|AL_BIT(31)
define|#
directive|define
name|AL_UDMA_CDESC_BUF2_LEN_SHIFT
value|16
define|#
directive|define
name|AL_UDMA_CDESC_BUF2_LEN_MASK
value|AL_FIELD_MASK(29, 16)
comment|/** Basic Buffer structure */
struct|struct
name|al_buf
block|{
name|al_phys_addr_t
name|addr
decl_stmt|;
comment|/**< Buffer physical address */
name|uint32_t
name|len
decl_stmt|;
comment|/**< Buffer lenght in bytes */
block|}
struct|;
comment|/** Block is a set of buffers that belong to same source or destination */
struct|struct
name|al_block
block|{
name|struct
name|al_buf
modifier|*
name|bufs
decl_stmt|;
comment|/**< The buffers of the block */
name|uint32_t
name|num
decl_stmt|;
comment|/**< Number of buffers of the block */
comment|/**< 	 * Target-ID to be assigned to the block descriptors 	 * Requires Target-ID in descriptor to be enabled for the specific UDMA 	 * queue. 	 */
name|uint16_t
name|tgtid
decl_stmt|;
block|}
struct|;
comment|/** UDMA type */
enum|enum
name|al_udma_type
block|{
name|UDMA_TX
block|,
name|UDMA_RX
block|}
enum|;
comment|/** UDMA state */
enum|enum
name|al_udma_state
block|{
name|UDMA_DISABLE
init|=
literal|0
block|,
name|UDMA_IDLE
block|,
name|UDMA_NORMAL
block|,
name|UDMA_ABORT
block|,
name|UDMA_RESET
block|}
enum|;
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|al_udma_states_name
index|[]
decl_stmt|;
comment|/** UDMA Q specific parameters from upper layer */
struct|struct
name|al_udma_q_params
block|{
name|uint32_t
name|size
decl_stmt|;
comment|/**< ring size (in descriptors), submission and 				 * completion rings must have same size 				 */
name|union
name|al_udma_desc
modifier|*
name|desc_base
decl_stmt|;
comment|/**< cpu address for submission ring 					 * descriptors 					 */
name|al_phys_addr_t
name|desc_phy_base
decl_stmt|;
comment|/**< submission ring descriptors 					 * physical base address 					 */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|bus_dma_tag_t
name|desc_phy_base_tag
decl_stmt|;
name|bus_dmamap_t
name|desc_phy_base_map
decl_stmt|;
endif|#
directive|endif
name|uint8_t
modifier|*
name|cdesc_base
decl_stmt|;
comment|/**< completion descriptors pointer, NULL */
comment|/* means no completion update */
name|al_phys_addr_t
name|cdesc_phy_base
decl_stmt|;
comment|/**< completion descriptors ring 					 * physical base address 					 */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|bus_dma_tag_t
name|cdesc_phy_base_tag
decl_stmt|;
name|bus_dmamap_t
name|cdesc_phy_base_map
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|cdesc_size
decl_stmt|;
comment|/**< size (in bytes) of a single dma completion 					* descriptor 					*/
name|uint8_t
name|adapter_rev_id
decl_stmt|;
comment|/**<PCI adapter revision ID */
block|}
struct|;
comment|/** UDMA parameters from upper layer */
struct|struct
name|al_udma_params
block|{
name|struct
name|unit_regs
name|__iomem
modifier|*
name|udma_regs_base
decl_stmt|;
name|enum
name|al_udma_type
name|type
decl_stmt|;
comment|/**< Tx or Rx */
name|uint8_t
name|num_of_queues
decl_stmt|;
comment|/**< number of queues supported by the UDMA */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< the upper layer must keep the string area */
block|}
struct|;
comment|/* Fordward decleration */
struct_decl|struct
name|al_udma
struct_decl|;
comment|/** SW status of a queue */
enum|enum
name|al_udma_queue_status
block|{
name|AL_QUEUE_NOT_INITIALIZED
init|=
literal|0
block|,
name|AL_QUEUE_DISABLED
block|,
name|AL_QUEUE_ENABLED
block|,
name|AL_QUEUE_ABORTED
block|}
enum|;
comment|/** UDMA Queue private data structure */
struct|struct
name|__cache_aligned
name|al_udma_q
block|{
name|uint16_t
name|size_mask
decl_stmt|;
comment|/**< mask used for pointers wrap around 					 * equals to size - 1 					 */
name|union
name|udma_q_regs
name|__iomem
modifier|*
name|q_regs
decl_stmt|;
comment|/**< pointer to the per queue UDMA 					   * registers 					   */
name|union
name|al_udma_desc
modifier|*
name|desc_base_ptr
decl_stmt|;
comment|/**< base address submission ring 						* descriptors 						*/
name|uint16_t
name|next_desc_idx
decl_stmt|;
comment|/**< index to the next available submission 				      * descriptor 				      */
name|uint32_t
name|desc_ring_id
decl_stmt|;
comment|/**< current submission ring id */
name|uint8_t
modifier|*
name|cdesc_base_ptr
decl_stmt|;
comment|/**< completion descriptors pointer, NULL */
comment|/* means no completion */
name|uint32_t
name|cdesc_size
decl_stmt|;
comment|/**< size (in bytes) of the udma completion ring 				 * descriptor 				 */
name|uint16_t
name|next_cdesc_idx
decl_stmt|;
comment|/**< index in descriptors for next completing 			      * ring descriptor 			      */
name|uint8_t
modifier|*
name|end_cdesc_ptr
decl_stmt|;
comment|/**< used for wrap around detection */
name|uint16_t
name|comp_head_idx
decl_stmt|;
comment|/**< completion ring head pointer register 				 *shadow 				 */
specifier|volatile
name|union
name|al_udma_cdesc
modifier|*
name|comp_head_ptr
decl_stmt|;
comment|/**< when working in get_packet mode 				       * we maintain pointer instead of the 				       * above idx 				       */
name|uint32_t
name|pkt_crnt_descs
decl_stmt|;
comment|/**< holds the number of processed descriptors 				  * of the current packet 				  */
name|uint32_t
name|comp_ring_id
decl_stmt|;
comment|/**< current completion Ring Id */
name|al_phys_addr_t
name|desc_phy_base
decl_stmt|;
comment|/**< submission desc. physical base */
name|al_phys_addr_t
name|cdesc_phy_base
decl_stmt|;
comment|/**< completion desc. physical base */
name|uint32_t
name|flags
decl_stmt|;
comment|/**< flags used for completion modes */
name|uint32_t
name|size
decl_stmt|;
comment|/**< ring size in descriptors  */
name|enum
name|al_udma_queue_status
name|status
decl_stmt|;
name|struct
name|al_udma
modifier|*
name|udma
decl_stmt|;
comment|/**< pointer to parent UDMA */
name|uint32_t
name|qid
decl_stmt|;
comment|/**< the index number of the queue */
comment|/* 	 * The following fields are duplicated from the UDMA parent adapter 	 * due to performance considerations. 	 */
name|uint8_t
name|adapter_rev_id
decl_stmt|;
comment|/**<PCI adapter revision ID */
block|}
struct|;
comment|/* UDMA */
struct|struct
name|al_udma
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|enum
name|al_udma_type
name|type
decl_stmt|;
comment|/* Tx or Rx */
name|enum
name|al_udma_state
name|state
decl_stmt|;
name|uint8_t
name|num_of_queues
decl_stmt|;
comment|/* number of queues supported by the UDMA */
name|union
name|udma_regs
name|__iomem
modifier|*
name|udma_regs
decl_stmt|;
comment|/* pointer to the UDMA registers */
name|struct
name|udma_gen_regs
modifier|*
name|gen_regs
decl_stmt|;
comment|/* pointer to the Gen registers*/
name|struct
name|al_udma_q
name|udma_q
index|[
name|DMA_MAX_Q
index|]
decl_stmt|;
comment|/* Array of UDMA Qs pointers */
name|unsigned
name|int
name|rev_id
decl_stmt|;
comment|/* UDMA revision ID */
block|}
struct|;
comment|/*  * Configurations  */
comment|/* Initializations functions */
comment|/**  * Initialize the udma engine  *  * @param udma udma data structure  * @param udma_params udma parameters from upper layer  *  * @return 0 on success. -EINVAL otherwise.  */
name|int
name|al_udma_init
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_params
modifier|*
name|udma_params
parameter_list|)
function_decl|;
comment|/**  * Initialize the udma queue data structure  *  * @param udma  * @param qid  * @param q_params  *  * @return 0 if no error found.  *	   -EINVAL if the qid is out of range  *	   -EIO if queue was already initialized  */
name|int
name|al_udma_q_init
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|uint32_t
name|qid
parameter_list|,
name|struct
name|al_udma_q_params
modifier|*
name|q_params
parameter_list|)
function_decl|;
comment|/**  * Reset a udma queue  *  * Prior to calling this function make sure:  * 1. Queue interrupts are masked  * 2. No additional descriptors are written to the descriptor ring of the queue  * 3. No completed descriptors are being fetched  *  * The queue can be initialized again using 'al_udma_q_init'  *  * @param udma_q  *  * @return 0 if no error found.  */
name|int
name|al_udma_q_reset
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|)
function_decl|;
comment|/**  * return (by reference) a pointer to a specific queue date structure.  * this pointer needed for calling functions (i.e. al_udma_desc_action_add) that  * require this pointer as input argument.  *  * @param udma udma data structure  * @param qid queue index  * @param q_handle pointer to the location where the queue structure pointer  * written to.  *  * @return  0 on success. -EINVAL otherwise.  */
name|int
name|al_udma_q_handle_get
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|uint32_t
name|qid
parameter_list|,
name|struct
name|al_udma_q
modifier|*
modifier|*
name|q_handle
parameter_list|)
function_decl|;
comment|/**  * Change the UDMA's state  *  * @param udma udma data structure  * @param state the target state  *  * @return 0  */
name|int
name|al_udma_state_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|enum
name|al_udma_state
name|state
parameter_list|)
function_decl|;
comment|/**  * return the current UDMA hardware state  *  * @param udma udma handle  *  * @return the UDMA state as reported by the hardware.  */
name|enum
name|al_udma_state
name|al_udma_state_get
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|)
function_decl|;
comment|/*  * Action handling  */
comment|/**  * get number of descriptors that can be submitted to the udma.  * keep one free descriptor to simplify full/empty management  * @param udma_q queue handle  *  * @return num of free descriptors.  */
specifier|static
name|INLINE
name|uint32_t
name|al_udma_available_get
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|)
block|{
name|uint16_t
name|tmp
init|=
name|udma_q
operator|->
name|next_cdesc_idx
operator|-
operator|(
name|udma_q
operator|->
name|next_desc_idx
operator|+
literal|1
operator|)
decl_stmt|;
name|tmp
operator|&=
name|udma_q
operator|->
name|size_mask
expr_stmt|;
return|return
operator|(
name|uint32_t
operator|)
name|tmp
return|;
block|}
comment|/**  * check if queue has pending descriptors  *  * @param udma_q queue handle  *  * @return AL_TRUE if descriptors are submitted to completion ring and still  * not completed (with ack). AL_FALSE otherwise.  */
specifier|static
name|INLINE
name|al_bool
name|al_udma_is_empty
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|)
block|{
if|if
condition|(
operator|(
operator|(
name|udma_q
operator|->
name|next_cdesc_idx
operator|-
name|udma_q
operator|->
name|next_desc_idx
operator|)
operator|&
name|udma_q
operator|->
name|size_mask
operator|)
operator|==
literal|0
condition|)
return|return
name|AL_TRUE
return|;
return|return
name|AL_FALSE
return|;
block|}
comment|/**  * get next available descriptor  * @param udma_q queue handle  *  * @return pointer to the next available descriptor  */
specifier|static
name|INLINE
expr|union
name|al_udma_desc
operator|*
name|al_udma_desc_get
argument_list|(
argument|struct al_udma_q *udma_q
argument_list|)
block|{
expr|union
name|al_udma_desc
operator|*
name|desc
block|;
name|uint16_t
name|next_desc_idx
block|;
name|al_assert
argument_list|(
name|udma_q
argument_list|)
block|;
name|next_desc_idx
operator|=
name|udma_q
operator|->
name|next_desc_idx
block|;
name|desc
operator|=
name|udma_q
operator|->
name|desc_base_ptr
operator|+
name|next_desc_idx
block|;
name|next_desc_idx
operator|++
block|;
comment|/* if reached end of queue, wrap around */
name|udma_q
operator|->
name|next_desc_idx
operator|=
name|next_desc_idx
operator|&
name|udma_q
operator|->
name|size_mask
block|;
return|return
name|desc
return|;
block|}
comment|/**  * get ring id for the last allocated descriptor  * @param udma_q  *  * @return ring id for the last allocated descriptor  * this function must be called each time a new descriptor is allocated  * by the al_udma_desc_get(), unless ring id is ignored.  */
specifier|static
name|INLINE
name|uint32_t
name|al_udma_ring_id_get
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|)
block|{
name|uint32_t
name|ring_id
decl_stmt|;
name|al_assert
argument_list|(
name|udma_q
argument_list|)
expr_stmt|;
name|ring_id
operator|=
name|udma_q
operator|->
name|desc_ring_id
expr_stmt|;
comment|/* calculate the ring id of the next desc */
comment|/* if next_desc points to first desc, then queue wrapped around */
if|if
condition|(
name|unlikely
argument_list|(
name|udma_q
operator|->
name|next_desc_idx
argument_list|)
operator|==
literal|0
condition|)
name|udma_q
operator|->
name|desc_ring_id
operator|=
operator|(
name|udma_q
operator|->
name|desc_ring_id
operator|+
literal|1
operator|)
operator|&
name|DMA_RING_ID_MASK
expr_stmt|;
return|return
name|ring_id
return|;
block|}
comment|/* add DMA action - trigger the engine */
comment|/**  * add num descriptors to the submission queue.  *  * @param udma_q queue handle  * @param num number of descriptors to add to the queues ring.  *  * @return 0;  */
specifier|static
name|INLINE
name|int
name|al_udma_desc_action_add
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|,
name|uint32_t
name|num
parameter_list|)
block|{
name|uint32_t
modifier|*
name|addr
decl_stmt|;
name|al_assert
argument_list|(
name|udma_q
argument_list|)
expr_stmt|;
name|al_assert
argument_list|(
operator|(
name|num
operator|>
literal|0
operator|)
operator|&&
operator|(
name|num
operator|<=
name|udma_q
operator|->
name|size
operator|)
argument_list|)
expr_stmt|;
name|addr
operator|=
operator|&
name|udma_q
operator|->
name|q_regs
operator|->
name|rings
operator|.
name|drtp_inc
expr_stmt|;
comment|/* make sure data written to the descriptors will be visible by the */
comment|/* DMA */
name|al_local_data_memory_barrier
argument_list|()
expr_stmt|;
comment|/* 	 * As we explicitly invoke the synchronization function 	 * (al_data_memory_barrier()), then we can use the relaxed version. 	 */
name|al_reg_write32_relaxed
argument_list|(
name|addr
argument_list|,
name|num
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
define|#
directive|define
name|cdesc_is_first
parameter_list|(
name|flags
parameter_list|)
value|((flags)& AL_UDMA_CDESC_FIRST)
define|#
directive|define
name|cdesc_is_last
parameter_list|(
name|flags
parameter_list|)
value|((flags)& AL_UDMA_CDESC_LAST)
comment|/**  * return pointer to the cdesc + offset desciptors. wrap around when needed.  *  * @param udma_q queue handle  * @param cdesc pointer that set by this function  * @param offset offset desciptors  *  */
specifier|static
name|INLINE
specifier|volatile
expr|union
name|al_udma_cdesc
operator|*
name|al_cdesc_next
argument_list|(
argument|struct al_udma_q		*udma_q
argument_list|,
argument|volatile union al_udma_cdesc	*cdesc
argument_list|,
argument|uint32_t			offset
argument_list|)
block|{
specifier|volatile
name|uint8_t
operator|*
name|tmp
operator|=
operator|(
specifier|volatile
name|uint8_t
operator|*
operator|)
name|cdesc
operator|+
name|offset
operator|*
name|udma_q
operator|->
name|cdesc_size
block|;
name|al_assert
argument_list|(
name|udma_q
argument_list|)
block|;
name|al_assert
argument_list|(
name|cdesc
argument_list|)
block|;
comment|/* if wrap around */
if|if
condition|(
name|unlikely
argument_list|(
operator|(
name|tmp
operator|>
name|udma_q
operator|->
name|end_cdesc_ptr
operator|)
argument_list|)
condition|)
return|return
operator|(
expr|union
name|al_udma_cdesc
operator|*
operator|)
operator|(
name|udma_q
operator|->
name|cdesc_base_ptr
operator|+
operator|(
name|tmp
operator|-
name|udma_q
operator|->
name|end_cdesc_ptr
operator|-
name|udma_q
operator|->
name|cdesc_size
operator|)
operator|)
return|;
return|return
operator|(
specifier|volatile
expr|union
name|al_udma_cdesc
operator|*
operator|)
name|tmp
return|;
block|}
end_extern

begin_comment
comment|/**  * check if the flags of the descriptor indicates that is new one  * the function uses the ring id from the descriptor flags to know whether it  * new one by comparing it with the curring ring id of the queue  *  * @param udma_q queue handle  * @param flags the flags of the completion descriptor  *  * @return AL_TRUE if the completion descriptor is new one.  * 	AL_FALSE if it old one.  */
end_comment

begin_function
specifier|static
name|INLINE
name|al_bool
name|al_udma_new_cdesc
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
block|{
if|if
condition|(
operator|(
operator|(
name|flags
operator|&
name|AL_M2S_DESC_RING_ID_MASK
operator|)
operator|>>
name|AL_M2S_DESC_RING_ID_SHIFT
operator|)
operator|==
name|udma_q
operator|->
name|comp_ring_id
condition|)
return|return
name|AL_TRUE
return|;
return|return
name|AL_FALSE
return|;
block|}
end_function

begin_comment
comment|/**  * get next completion descriptor  * this function will also increment the completion ring id when the ring wraps  * around  *  * @param udma_q queue handle  * @param cdesc current completion descriptor  *  * @return pointer to the completion descriptor that follows the one pointed by  * cdesc  */
end_comment

begin_expr_stmt
specifier|static
name|INLINE
specifier|volatile
expr|union
name|al_udma_cdesc
operator|*
name|al_cdesc_next_update
argument_list|(
argument|struct al_udma_q		*udma_q
argument_list|,
argument|volatile union al_udma_cdesc	*cdesc
argument_list|)
block|{
comment|/* if last desc, wrap around */
if|if
condition|(
name|unlikely
argument_list|(
operator|(
operator|(
specifier|volatile
name|uint8_t
operator|*
operator|)
name|cdesc
operator|==
name|udma_q
operator|->
name|end_cdesc_ptr
operator|)
argument_list|)
condition|)
block|{
name|udma_q
operator|->
name|comp_ring_id
operator|=
operator|(
name|udma_q
operator|->
name|comp_ring_id
operator|+
literal|1
operator|)
operator|&
name|DMA_RING_ID_MASK
expr_stmt|;
return|return
operator|(
expr|union
name|al_udma_cdesc
operator|*
operator|)
name|udma_q
operator|->
name|cdesc_base_ptr
return|;
block|}
end_expr_stmt

begin_return
return|return
operator|(
specifier|volatile
expr|union
name|al_udma_cdesc
operator|*
operator|)
operator|(
operator|(
specifier|volatile
name|uint8_t
operator|*
operator|)
name|cdesc
operator|+
name|udma_q
operator|->
name|cdesc_size
operator|)
return|;
end_return

begin_comment
unit|}
comment|/**  * get next completed packet from completion ring of the queue  *  * @param udma_q udma queue handle  * @param desc pointer that set by this function to the first descriptor  * note: desc is valid only when return value is not zero  * @return number of descriptors that belong to the packet. 0 means no completed  * full packet was found.  * If the descriptors found in the completion queue don't form full packet (no  * desc with LAST flag), then this function will do the following:  * (1) save the number of processed descriptors.  * (2) save last processed descriptor, so next time it called, it will resume  *     from there.  * (3) return 0.  * note: the descriptors that belong to the completed packet will still be  * considered as used, that means the upper layer is safe to access those  * descriptors when this function returns. the al_udma_cdesc_ack() should be  * called to inform the udma driver that those descriptors are freed.  */
end_comment

begin_expr_stmt
unit|uint32_t
name|al_udma_cdesc_packet_get
argument_list|(
expr|struct
name|al_udma_q
operator|*
name|udma_q
argument_list|,
specifier|volatile
expr|union
name|al_udma_cdesc
operator|*
operator|*
name|desc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/** get completion descriptor pointer from its index */
end_comment

begin_define
define|#
directive|define
name|al_udma_cdesc_idx_to_ptr
parameter_list|(
name|udma_q
parameter_list|,
name|idx
parameter_list|)
define|\
value|((volatile union al_udma_cdesc *) ((udma_q)->cdesc_base_ptr +	\ 				(idx) * (udma_q)->cdesc_size))
end_define

begin_comment
comment|/**  * return number of all completed descriptors in the completion ring  *  * @param udma_q udma queue handle  * @param cdesc pointer that set by this function to the first descriptor  * note: desc is valid only when return value is not zero  * note: pass NULL if not interested  * @return number of descriptors. 0 means no completed descriptors were found.  * note: the descriptors that belong to the completed packet will still be  * considered as used, that means the upper layer is safe to access those  * descriptors when this function returns. the al_udma_cdesc_ack() should be  * called to inform the udma driver that those descriptors are freed.  */
end_comment

begin_function
specifier|static
name|INLINE
name|uint32_t
name|al_udma_cdesc_get_all
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|,
specifier|volatile
name|union
name|al_udma_cdesc
modifier|*
modifier|*
name|cdesc
parameter_list|)
block|{
name|uint16_t
name|count
init|=
literal|0
decl_stmt|;
name|al_assert
argument_list|(
name|udma_q
argument_list|)
expr_stmt|;
name|udma_q
operator|->
name|comp_head_idx
operator|=
call|(
name|uint16_t
call|)
argument_list|(
name|al_reg_read32
argument_list|(
operator|&
name|udma_q
operator|->
name|q_regs
operator|->
name|rings
operator|.
name|crhp
argument_list|)
operator|&
literal|0xFFFF
argument_list|)
expr_stmt|;
name|count
operator|=
operator|(
name|udma_q
operator|->
name|comp_head_idx
operator|-
name|udma_q
operator|->
name|next_cdesc_idx
operator|)
operator|&
name|udma_q
operator|->
name|size_mask
expr_stmt|;
if|if
condition|(
name|cdesc
condition|)
operator|*
name|cdesc
operator|=
name|al_udma_cdesc_idx_to_ptr
argument_list|(
name|udma_q
argument_list|,
name|udma_q
operator|->
name|next_cdesc_idx
argument_list|)
expr_stmt|;
return|return
operator|(
name|uint32_t
operator|)
name|count
return|;
block|}
end_function

begin_comment
comment|/**  * acknowledge the driver that the upper layer completed processing completion  * descriptors  *  * @param udma_q udma queue handle  * @param num number of descriptors to acknowledge  *  * @return 0  */
end_comment

begin_function
specifier|static
name|INLINE
name|int
name|al_udma_cdesc_ack
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|,
name|uint32_t
name|num
parameter_list|)
block|{
name|al_assert
argument_list|(
name|udma_q
argument_list|)
expr_stmt|;
name|udma_q
operator|->
name|next_cdesc_idx
operator|+=
name|num
expr_stmt|;
name|udma_q
operator|->
name|next_cdesc_idx
operator|&=
name|udma_q
operator|->
name|size_mask
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* *INDENT-OFF* */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* *INDENT-ON* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AL_HAL_UDMA_H__ */
end_comment

begin_comment
comment|/** @} end of UDMA group */
end_comment

end_unit

