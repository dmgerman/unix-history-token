begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2014, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXLV_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXLV_H_
end_define

begin_define
define|#
directive|define
name|IXLV_AQ_MAX_ERR
value|100
end_define

begin_define
define|#
directive|define
name|IXLV_MAX_FILTERS
value|128
end_define

begin_define
define|#
directive|define
name|IXLV_MAX_QUEUES
value|16
end_define

begin_define
define|#
directive|define
name|IXLV_AQ_TIMEOUT
value|(1 * hz)
end_define

begin_define
define|#
directive|define
name|IXLV_CALLOUT_TIMO
value|(hz / 50)
end_define

begin_comment
comment|// 20 msec
end_comment

begin_define
define|#
directive|define
name|IXLV_FLAG_AQ_ENABLE_QUEUES
value|(u32)(1)
end_define

begin_define
define|#
directive|define
name|IXLV_FLAG_AQ_DISABLE_QUEUES
value|(u32)(1<< 1)
end_define

begin_define
define|#
directive|define
name|IXLV_FLAG_AQ_ADD_MAC_FILTER
value|(u32)(1<< 2)
end_define

begin_define
define|#
directive|define
name|IXLV_FLAG_AQ_ADD_VLAN_FILTER
value|(u32)(1<< 3)
end_define

begin_define
define|#
directive|define
name|IXLV_FLAG_AQ_DEL_MAC_FILTER
value|(u32)(1<< 4)
end_define

begin_define
define|#
directive|define
name|IXLV_FLAG_AQ_DEL_VLAN_FILTER
value|(u32)(1<< 5)
end_define

begin_define
define|#
directive|define
name|IXLV_FLAG_AQ_CONFIGURE_QUEUES
value|(u32)(1<< 6)
end_define

begin_define
define|#
directive|define
name|IXLV_FLAG_AQ_MAP_VECTORS
value|(u32)(1<< 7)
end_define

begin_define
define|#
directive|define
name|IXLV_FLAG_AQ_HANDLE_RESET
value|(u32)(1<< 8)
end_define

begin_define
define|#
directive|define
name|IXLV_FLAG_AQ_CONFIGURE_PROMISC
value|(u32)(1<< 9)
end_define

begin_define
define|#
directive|define
name|IXLV_FLAG_AQ_GET_STATS
value|(u32)(1<< 10)
end_define

begin_comment
comment|/* printf %b arg */
end_comment

begin_define
define|#
directive|define
name|IXLV_FLAGS
define|\
value|"\20\1ENABLE_QUEUES\2DISABLE_QUEUES\3ADD_MAC_FILTER" \     "\4ADD_VLAN_FILTER\5DEL_MAC_FILTER\6DEL_VLAN_FILTER" \     "\7CONFIGURE_QUEUES\10MAP_VECTORS\11HANDLE_RESET" \     "\12CONFIGURE_PROMISC\13GET_STATS"
end_define

begin_comment
comment|/* Driver state */
end_comment

begin_enum
enum|enum
name|ixlv_state_t
block|{
name|IXLV_START
block|,
name|IXLV_FAILED
block|,
name|IXLV_RESET_REQUIRED
block|,
name|IXLV_RESET_PENDING
block|,
name|IXLV_VERSION_CHECK
block|,
name|IXLV_GET_RESOURCES
block|,
name|IXLV_INIT_READY
block|,
name|IXLV_INIT_START
block|,
name|IXLV_INIT_CONFIG
block|,
name|IXLV_INIT_MAPPING
block|,
name|IXLV_INIT_ENABLE
block|,
name|IXLV_INIT_COMPLETE
block|,
name|IXLV_RUNNING
block|,	 }
enum|;
end_enum

begin_struct
struct|struct
name|ixlv_mac_filter
block|{
name|SLIST_ENTRY
argument_list|(
argument|ixlv_mac_filter
argument_list|)
name|next
expr_stmt|;
name|u8
name|macaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u16
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|mac_list
argument_list|,
name|ixlv_mac_filter
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|ixlv_vlan_filter
block|{
name|SLIST_ENTRY
argument_list|(
argument|ixlv_vlan_filter
argument_list|)
name|next
expr_stmt|;
name|u16
name|vlan
decl_stmt|;
name|u16
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|vlan_list
argument_list|,
name|ixlv_vlan_filter
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Software controller structure */
end_comment

begin_struct
struct|struct
name|ixlv_sc
block|{
name|struct
name|i40e_hw
name|hw
decl_stmt|;
name|struct
name|i40e_osdep
name|osdep
decl_stmt|;
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|pci_mem
decl_stmt|;
name|struct
name|resource
modifier|*
name|msix_mem
decl_stmt|;
name|enum
name|ixlv_state_t
name|init_state
decl_stmt|;
comment|/* 	 * Interrupt resources 	 */
name|void
modifier|*
name|tag
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
comment|/* For the AQ */
name|struct
name|ifmedia
name|media
decl_stmt|;
name|struct
name|callout
name|timer
decl_stmt|;
name|struct
name|callout
name|aq_task
decl_stmt|;
name|int
name|msix
decl_stmt|;
name|int
name|if_flags
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|struct
name|mtx
name|aq_task_mtx
decl_stmt|;
name|u32
name|qbase
decl_stmt|;
name|u32
name|admvec
decl_stmt|;
name|struct
name|timeout_task
name|timeout
decl_stmt|;
name|struct
name|task
name|aq_irq
decl_stmt|;
name|struct
name|task
name|aq_sched
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
name|struct
name|ixl_vsi
name|vsi
decl_stmt|;
comment|/* Mac Filter List */
name|struct
name|mac_list
modifier|*
name|mac_filters
decl_stmt|;
comment|/* Vlan Filter List */
name|struct
name|vlan_list
modifier|*
name|vlan_filters
decl_stmt|;
comment|/* Promiscuous mode */
name|u32
name|promiscuous_flags
decl_stmt|;
comment|/* Admin queue task flags */
name|u32
name|aq_wait_count
decl_stmt|;
name|u32
name|aq_required
decl_stmt|;
name|u32
name|aq_pending
decl_stmt|;
comment|/* Virtual comm channel */
name|enum
name|i40e_virtchnl_ops
name|current_op
decl_stmt|;
name|struct
name|i40e_virtchnl_vf_resource
modifier|*
name|vf_res
decl_stmt|;
name|struct
name|i40e_virtchnl_vsi_resource
modifier|*
name|vsi_res
decl_stmt|;
comment|/* Misc stats maintained by the driver */
name|u64
name|watchdog_events
decl_stmt|;
name|u64
name|admin_irq
decl_stmt|;
comment|/* Signaling channels */
name|u8
name|init_done
decl_stmt|;
name|u8
name|config_queues_done
decl_stmt|;
name|u8
name|map_vectors_done
decl_stmt|;
name|u8
name|enable_queues_done
decl_stmt|;
name|u8
name|disable_queues_done
decl_stmt|;
name|u8
name|add_ether_done
decl_stmt|;
name|u8
name|del_ether_done
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ** This checks for a zero mac addr, something that will be likely ** unless the Admin on the Host has created one. */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|ixlv_check_ether_addr
parameter_list|(
name|u8
modifier|*
name|addr
parameter_list|)
block|{
name|bool
name|status
init|=
name|TRUE
decl_stmt|;
if|if
condition|(
operator|(
name|addr
index|[
literal|0
index|]
operator|==
literal|0
operator|&&
name|addr
index|[
literal|1
index|]
operator|==
literal|0
operator|&&
name|addr
index|[
literal|2
index|]
operator|==
literal|0
operator|&&
name|addr
index|[
literal|3
index|]
operator|==
literal|0
operator|&&
name|addr
index|[
literal|4
index|]
operator|==
literal|0
operator|&&
name|addr
index|[
literal|5
index|]
operator|==
literal|0
operator|)
condition|)
name|status
operator|=
name|FALSE
expr_stmt|;
return|return
operator|(
name|status
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ** VF Common function prototypes */
end_comment

begin_function_decl
name|int
name|ixlv_send_api_ver
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixlv_verify_api_ver
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixlv_send_vf_config_msg
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixlv_get_vf_config
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_init
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixlv_reinit_locked
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_configure_queues
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_enable_queues
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_disable_queues
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_map_queues
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_enable_intr
parameter_list|(
name|struct
name|ixl_vsi
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_disable_intr
parameter_list|(
name|struct
name|ixl_vsi
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_add_ether_filters
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_del_ether_filters
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_request_stats
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_request_reset
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_vc_completion
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|,
name|enum
name|i40e_virtchnl_ops
parameter_list|,
name|i40e_status
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|u16
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_add_ether_filter
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_add_vlans
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_del_vlans
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixlv_update_stats_counters
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|,
name|struct
name|i40e_eth_stats
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXLV_H_ */
end_comment

end_unit

