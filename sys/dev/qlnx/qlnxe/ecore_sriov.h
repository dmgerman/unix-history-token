begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_SRIOV_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_SRIOV_H__
end_define

begin_include
include|#
directive|include
file|"ecore_status.h"
end_include

begin_include
include|#
directive|include
file|"ecore_vfpf_if.h"
end_include

begin_include
include|#
directive|include
file|"ecore_iov_api.h"
end_include

begin_include
include|#
directive|include
file|"ecore_hsi_common.h"
end_include

begin_include
include|#
directive|include
file|"ecore_l2.h"
end_include

begin_define
define|#
directive|define
name|ECORE_ETH_MAX_VF_NUM_VLAN_FILTERS
define|\
value|(MAX_NUM_VFS_E4 * ECORE_ETH_VF_NUM_VLAN_FILTERS)
end_define

begin_comment
comment|/* Represents a full message. Both the request filled by VF  * and the response filled by the PF. The VF needs one copy  * of this message, it fills the request part and sends it to  * the PF. The PF will copy the response to the response part for  * the VF to later read it. The PF needs to hold a message like this  * per VF, the request that is copied to the PF is placed in the  * request size, and the response is filled by the PF before sending  * it to the VF.  */
end_comment

begin_struct
struct|struct
name|ecore_vf_mbx_msg
block|{
name|union
name|vfpf_tlvs
name|req
decl_stmt|;
name|union
name|pfvf_tlvs
name|resp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This mailbox is maintained per VF in its PF  * contains all information required for sending / receiving  * a message  */
end_comment

begin_struct
struct|struct
name|ecore_iov_vf_mbx
block|{
name|union
name|vfpf_tlvs
modifier|*
name|req_virt
decl_stmt|;
name|dma_addr_t
name|req_phys
decl_stmt|;
name|union
name|pfvf_tlvs
modifier|*
name|reply_virt
decl_stmt|;
name|dma_addr_t
name|reply_phys
decl_stmt|;
comment|/* Address in VF where a pending message is located */
name|dma_addr_t
name|pending_req
decl_stmt|;
comment|/* Message from VF awaits handling */
name|bool
name|b_pending_msg
decl_stmt|;
name|u8
modifier|*
name|offset
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIG_ECORE_SW_CHANNEL
name|struct
name|ecore_iov_sw_mbx
name|sw_mbx
decl_stmt|;
endif|#
directive|endif
comment|/* VF GPA address */
name|u32
name|vf_addr_lo
decl_stmt|;
name|u32
name|vf_addr_hi
decl_stmt|;
name|struct
name|vfpf_first_tlv
name|first_tlv
decl_stmt|;
comment|/* saved VF request header */
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|VF_MSG_INPROCESS
value|0x1
comment|/* failsafe - the FW should prevent 					 * more then one pending msg 					 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ECORE_IOV_LEGACY_QID_RX
value|(0)
end_define

begin_define
define|#
directive|define
name|ECORE_IOV_LEGACY_QID_TX
value|(1)
end_define

begin_define
define|#
directive|define
name|ECORE_IOV_QID_INVALID
value|(0xFE)
end_define

begin_struct
struct|struct
name|ecore_vf_queue_cid
block|{
name|bool
name|b_is_tx
decl_stmt|;
name|struct
name|ecore_queue_cid
modifier|*
name|p_cid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Describes a qzone associated with the VF */
end_comment

begin_struct
struct|struct
name|ecore_vf_queue
block|{
comment|/* Input from upper-layer, mapping relateive queue to queue-zone */
name|u16
name|fw_rx_qid
decl_stmt|;
name|u16
name|fw_tx_qid
decl_stmt|;
name|struct
name|ecore_vf_queue_cid
name|cids
index|[
name|MAX_QUEUES_PER_QZONE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|vf_state
block|{
name|VF_FREE
init|=
literal|0
block|,
comment|/* VF ready to be acquired holds no resc */
name|VF_ACQUIRED
init|=
literal|1
block|,
comment|/* VF, aquired, but not initalized */
name|VF_ENABLED
init|=
literal|2
block|,
comment|/* VF, Enabled */
name|VF_RESET
init|=
literal|3
block|,
comment|/* VF, FLR'd, pending cleanup */
name|VF_STOPPED
init|=
literal|4
comment|/* VF, Stopped */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ecore_vf_vlan_shadow
block|{
name|bool
name|used
decl_stmt|;
name|u16
name|vid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_vf_shadow_config
block|{
comment|/* Shadow copy of all guest vlans */
name|struct
name|ecore_vf_vlan_shadow
name|vlans
index|[
name|ECORE_ETH_VF_NUM_VLAN_FILTERS
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Shadow copy of all configured MACs; Empty if forcing MACs */
name|u8
name|macs
index|[
name|ECORE_ETH_VF_NUM_MAC_FILTERS
index|]
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u8
name|inner_vlan_removal
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* PFs maintain an array of this structure, per VF */
end_comment

begin_struct
struct|struct
name|ecore_vf_info
block|{
name|struct
name|ecore_iov_vf_mbx
name|vf_mbx
decl_stmt|;
name|enum
name|vf_state
name|state
decl_stmt|;
name|bool
name|b_init
decl_stmt|;
name|bool
name|b_malicious
decl_stmt|;
name|u8
name|to_disable
decl_stmt|;
name|struct
name|ecore_bulletin
name|bulletin
decl_stmt|;
name|dma_addr_t
name|vf_bulletin
decl_stmt|;
comment|/* PF saves a copy of the last VF acquire message */
name|struct
name|vfpf_acquire_tlv
name|acquire
decl_stmt|;
name|u32
name|concrete_fid
decl_stmt|;
name|u16
name|opaque_fid
decl_stmt|;
name|u16
name|mtu
decl_stmt|;
name|u8
name|vport_id
decl_stmt|;
name|u8
name|rss_eng_id
decl_stmt|;
name|u8
name|relative_vf_id
decl_stmt|;
name|u8
name|abs_vf_id
decl_stmt|;
define|#
directive|define
name|ECORE_VF_ABS_ID
parameter_list|(
name|p_hwfn
parameter_list|,
name|p_vf
parameter_list|)
value|(ECORE_PATH_ID(p_hwfn) ? \ 					 (p_vf)->abs_vf_id + MAX_NUM_VFS_BB : \ 					 (p_vf)->abs_vf_id)
name|u8
name|vport_instance
decl_stmt|;
comment|/* Number of active vports */
name|u8
name|num_rxqs
decl_stmt|;
name|u8
name|num_txqs
decl_stmt|;
name|u16
name|rx_coal
decl_stmt|;
name|u16
name|tx_coal
decl_stmt|;
name|u8
name|num_sbs
decl_stmt|;
name|u8
name|num_mac_filters
decl_stmt|;
name|u8
name|num_vlan_filters
decl_stmt|;
name|struct
name|ecore_vf_queue
name|vf_queues
index|[
name|ECORE_MAX_VF_CHAINS_PER_PF
index|]
decl_stmt|;
name|u16
name|igu_sbs
index|[
name|ECORE_MAX_VF_CHAINS_PER_PF
index|]
decl_stmt|;
comment|/* TODO - Only windows is using it - should be removed */
name|u8
name|was_malicious
decl_stmt|;
name|u8
name|num_active_rxqs
decl_stmt|;
name|void
modifier|*
name|ctx
decl_stmt|;
name|struct
name|ecore_public_vf_info
name|p_vf_info
decl_stmt|;
name|bool
name|spoof_chk
decl_stmt|;
comment|/* Current configured on HW */
name|bool
name|req_spoofchk_val
decl_stmt|;
comment|/* Requested value */
comment|/* Stores the configuration requested by VF */
name|struct
name|ecore_vf_shadow_config
name|shadow_config
decl_stmt|;
comment|/* A bitfield using bulletin's valid-map bits, used to indicate 	 * which of the bulletin board features have been configured. 	 */
name|u64
name|configured_features
decl_stmt|;
define|#
directive|define
name|ECORE_IOV_CONFIGURED_FEATURES_MASK
value|((1<< MAC_ADDR_FORCED) | \ 						 (1<< VLAN_ADDR_FORCED))
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is part of ecore_hwfn and used only for PFs that have sriov  * capability enabled.  */
end_comment

begin_struct
struct|struct
name|ecore_pf_iov
block|{
name|struct
name|ecore_vf_info
name|vfs_array
index|[
name|MAX_NUM_VFS_E4
index|]
decl_stmt|;
name|u64
name|pending_flr
index|[
name|ECORE_VF_ARRAY_LENGTH
index|]
decl_stmt|;
ifndef|#
directive|ifndef
name|REMOVE_DBG
comment|/* This doesn't serve anything functionally, but it makes windows 	 * debugging of IOV related issues easier. 	 */
name|u64
name|active_vfs
index|[
name|ECORE_VF_ARRAY_LENGTH
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* Allocate message address continuosuly and split to each VF */
name|void
modifier|*
name|mbx_msg_virt_addr
decl_stmt|;
name|dma_addr_t
name|mbx_msg_phys_addr
decl_stmt|;
name|u32
name|mbx_msg_size
decl_stmt|;
name|void
modifier|*
name|mbx_reply_virt_addr
decl_stmt|;
name|dma_addr_t
name|mbx_reply_phys_addr
decl_stmt|;
name|u32
name|mbx_reply_size
decl_stmt|;
name|void
modifier|*
name|p_bulletins
decl_stmt|;
name|dma_addr_t
name|bulletins_phys
decl_stmt|;
name|u32
name|bulletins_size
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_ECORE_SRIOV
end_ifdef

begin_comment
comment|/**  * @brief Read sriov related information and allocated resources  *  reads from configuraiton space, shmem, etc.  *  * @param p_hwfn  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_iov_hw_info
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_add_tlv - place a given tlv on the tlv buffer at next offset  *  * @param offset  * @param type  * @param length  *  * @return pointer to the newly placed tlv  */
end_comment

begin_function_decl
name|void
modifier|*
name|ecore_add_tlv
parameter_list|(
name|u8
modifier|*
modifier|*
name|offset
parameter_list|,
name|u16
name|type
parameter_list|,
name|u16
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief list the types and lengths of the tlvs on the buffer  *  * @param p_hwfn  * @param tlvs_list  */
end_comment

begin_function_decl
name|void
name|ecore_dp_tlv_list
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|void
modifier|*
name|tlvs_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_iov_alloc - allocate sriov related resources  *  * @param p_hwfn  *  * @return enum _ecore_status_t  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_iov_alloc
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_iov_setup - setup sriov related resources  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_iov_setup
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_iov_free - free sriov related resources  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_iov_free
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief free sriov related memory that was allocated during hw_prepare  *  * @param p_dev  */
end_comment

begin_function_decl
name|void
name|ecore_iov_free_hw_info
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_sriov_eqe_event - handle async sriov event arrived on eqe.  *  * @param p_hwfn  * @param opcode  * @param echo  * @param data  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_sriov_eqe_event
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|opcode
parameter_list|,
name|__le16
name|echo
parameter_list|,
name|union
name|event_ring_data
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Mark structs of vfs that have been FLR-ed.  *  * @param p_hwfn  * @param disabled_vfs - bitmask of all VFs on path that were FLRed  *  * @return true iff one of the PF's vfs got FLRed. false otherwise.  */
end_comment

begin_function_decl
name|bool
name|ecore_iov_mark_vf_flr
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u32
modifier|*
name|disabled_vfs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Search extended TLVs in request/reply buffer.  *  * @param p_hwfn  * @param p_tlvs_list - Pointer to tlvs list  * @param req_type - Type of TLV  *  * @return pointer to tlv type if found, otherwise returns NULL.  */
end_comment

begin_function_decl
name|void
modifier|*
name|ecore_iov_search_list_tlvs
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|void
modifier|*
name|p_tlvs_list
parameter_list|,
name|u16
name|req_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_iov_get_vf_info - return the database of a  *        specific VF  *  * @param p_hwfn  * @param relative_vf_id - relative id of the VF for which info  *			 is requested  * @param b_enabled_only - false iff want to access even if vf is disabled  *  * @return struct ecore_vf_info*  */
end_comment

begin_function_decl
name|struct
name|ecore_vf_info
modifier|*
name|ecore_iov_get_vf_info
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u16
name|relative_vf_id
parameter_list|,
name|bool
name|b_enabled_only
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|OSAL_INLINE
name|enum
name|_ecore_status_t
name|ecore_iov_hw_info
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|)
block|{
return|return
name|ECORE_SUCCESS
return|;
block|}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
modifier|*
name|ecore_add_tlv
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|OSAL_UNUSED
modifier|*
modifier|*
name|offset
parameter_list|,
name|OSAL_UNUSED
name|u16
name|type
parameter_list|,
name|OSAL_UNUSED
name|u16
name|length
parameter_list|)
block|{
return|return
name|OSAL_NULL
return|;
block|}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
name|ecore_dp_tlv_list
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|void
name|OSAL_UNUSED
modifier|*
name|tlvs_list
parameter_list|)
block|{}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|enum
name|_ecore_status_t
name|ecore_iov_alloc
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|)
block|{
return|return
name|ECORE_SUCCESS
return|;
block|}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
name|ecore_iov_setup
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|)
block|{}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
name|ecore_iov_free
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|)
block|{}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
name|ecore_iov_free_hw_info
parameter_list|(
name|struct
name|ecore_dev
name|OSAL_UNUSED
modifier|*
name|p_dev
parameter_list|)
block|{}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|enum
name|_ecore_status_t
name|ecore_sriov_eqe_event
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|OSAL_UNUSED
name|opcode
parameter_list|,
name|__le16
name|OSAL_UNUSED
name|echo
parameter_list|,
name|union
name|event_ring_data
name|OSAL_UNUSED
modifier|*
name|data
parameter_list|)
block|{
return|return
name|ECORE_INVAL
return|;
block|}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|u32
name|ecore_crc32
parameter_list|(
name|u32
name|OSAL_UNUSED
name|crc
parameter_list|,
name|u8
name|OSAL_UNUSED
modifier|*
name|ptr
parameter_list|,
name|u32
name|OSAL_UNUSED
name|length
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|bool
name|ecore_iov_mark_vf_flr
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|u32
name|OSAL_UNUSED
modifier|*
name|disabled_vfs
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
specifier|static
name|OSAL_INLINE
name|void
modifier|*
name|ecore_iov_search_list_tlvs
parameter_list|(
name|struct
name|ecore_hwfn
name|OSAL_UNUSED
modifier|*
name|p_hwfn
parameter_list|,
name|void
name|OSAL_UNUSED
modifier|*
name|p_tlvs_list
parameter_list|,
name|u16
name|OSAL_UNUSED
name|req_type
parameter_list|)
block|{
return|return
name|OSAL_NULL
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|OSAL_INLINE
expr|struct
name|ecore_vf_info
operator|*
name|ecore_iov_get_vf_info
argument_list|(
argument|struct ecore_hwfn OSAL_UNUSED *p_hwfn
argument_list|,
argument|u16 OSAL_UNUSED relative_vf_id
argument_list|,
argument|bool OSAL_UNUSED b_enabled_only
argument_list|)
block|{
return|return
name|OSAL_NULL
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_SRIOV_H__ */
end_comment

end_unit

