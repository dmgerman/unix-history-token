begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * FST module - interface definitions  * Copyright (c) 2014, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FST_H
end_ifndef

begin_define
define|#
directive|define
name|FST_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_FST
end_ifdef

begin_include
include|#
directive|include
file|"common/defs.h"
end_include

begin_include
include|#
directive|include
file|"fst/fst_ctrl_iface.h"
end_include

begin_comment
comment|/* FST module hostap integration API */
end_comment

begin_define
define|#
directive|define
name|US_IN_MS
value|1000
end_define

begin_define
define|#
directive|define
name|LLT_UNIT_US
value|32
end_define

begin_comment
comment|/* See 10.32.2.2  Transitioning between states */
end_comment

begin_define
define|#
directive|define
name|FST_LLT_MS_TO_VAL
parameter_list|(
name|m
parameter_list|)
value|(((u32) (m)) * US_IN_MS / LLT_UNIT_US)
end_define

begin_define
define|#
directive|define
name|FST_LLT_VAL_TO_MS
parameter_list|(
name|v
parameter_list|)
value|(((u32) (v)) * LLT_UNIT_US / US_IN_MS)
end_define

begin_define
define|#
directive|define
name|FST_MAX_LLT_MS
value|FST_LLT_VAL_TO_MS(-1)
end_define

begin_define
define|#
directive|define
name|FST_MAX_PRIO_VALUE
value|((u8) -1)
end_define

begin_define
define|#
directive|define
name|FST_MAX_GROUP_ID_LEN
value|IFNAMSIZ
end_define

begin_define
define|#
directive|define
name|FST_DEFAULT_LLT_CFG_VALUE
value|50
end_define

begin_struct_decl
struct_decl|struct
name|hostapd_hw_modes
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_mgmt
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fst_iface
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fst_group
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fst_session
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fst_get_peer_ctx
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fst_ctrl_handle
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|fst_wpa_obj
block|{
name|void
modifier|*
name|ctx
decl_stmt|;
comment|/** 	 * get_bssid - Get BSSID of the interface 	 * @ctx: User context %ctx 	 * Returns: BSSID for success, %NULL for failure. 	 * 	 * NOTE: For AP it returns the own BSSID, while for STA - the BSSID of 	 * the associated AP. 	 */
specifier|const
name|u8
modifier|*
function_decl|(
modifier|*
name|get_bssid
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/** 	 * get_channel_info - Get current channel info 	 * @ctx: User context %ctx 	 * @hw_mode: OUT, current HW mode 	 * @channel: OUT, current channel 	 */
name|void
function_decl|(
modifier|*
name|get_channel_info
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|enum
name|hostapd_hw_mode
modifier|*
name|hw_mode
parameter_list|,
name|u8
modifier|*
name|channel
parameter_list|)
function_decl|;
comment|/** 	 * get_hw_modes - Get hardware modes 	 * @ctx: User context %ctx 	 * @modes: OUT, pointer on array of hw modes 	 * 	 * Returns: Number of hw modes available. 	 */
name|int
function_decl|(
modifier|*
name|get_hw_modes
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|struct
name|hostapd_hw_modes
modifier|*
modifier|*
name|modes
parameter_list|)
function_decl|;
comment|/** 	 * set_ies - Set interface's MB IE 	 * @ctx: User context %ctx 	 * @fst_ies: MB IE buffer (owned by FST module) 	 */
name|void
function_decl|(
modifier|*
name|set_ies
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|fst_ies
parameter_list|)
function_decl|;
comment|/** 	 * send_action - Send FST Action frame via the interface 	 * @ctx: User context %ctx 	 * @addr: Address of the destination STA 	 * @data: Action frame buffer 	 * Returns: 0 for success, negative error code for failure. 	 */
name|int
function_decl|(
modifier|*
name|send_action
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/** 	 * get_mb_ie - Get last MB IE received from STA 	 * @ctx: User context %ctx 	 * @addr: Address of the STA 	 * Returns: MB IE buffer, %NULL if no MB IE received from the STA 	 */
specifier|const
name|struct
name|wpabuf
modifier|*
function_decl|(
modifier|*
name|get_mb_ie
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
comment|/** 	 * update_mb_ie - Update last MB IE received from STA 	 * @ctx: User context %ctx 	 * @addr: Address of the STA 	 * @buf: Buffer that contains the MB IEs data 	 * @size: Size of data in %buf 	 */
name|void
function_decl|(
modifier|*
name|update_mb_ie
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/** 	 * get_peer_first - Get MAC address of the 1st connected STA 	 * @ctx: User context %ctx 	 * @get_ctx: Context to be used for %get_peer_next call 	 * @mb_only: %TRUE if only multi-band capable peer should be reported 	 * Returns: Address of the 1st connected STA, %NULL if no STAs connected 	 */
specifier|const
name|u8
modifier|*
function_decl|(
modifier|*
name|get_peer_first
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|struct
name|fst_get_peer_ctx
modifier|*
modifier|*
name|get_ctx
parameter_list|,
name|Boolean
name|mb_only
parameter_list|)
function_decl|;
comment|/** 	 * get_peer_next - Get MAC address of the next connected STA 	 * @ctx: User context %ctx 	 * @get_ctx: Context received from %get_peer_first or previous 	 *           %get_peer_next call 	 * @mb_only: %TRUE if only multi-band capable peer should be reported 	 * Returns: Address of the next connected STA, %NULL if no more STAs 	 *          connected 	 */
specifier|const
name|u8
modifier|*
function_decl|(
modifier|*
name|get_peer_next
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|struct
name|fst_get_peer_ctx
modifier|*
modifier|*
name|get_ctx
parameter_list|,
name|Boolean
name|mb_only
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * fst_global_init - Global FST module initiator  * Returns: 0 for success, negative error code for failure.  * Note: The purpose of this function is to allocate and initiate global  *       FST module data structures (linked lists, static data etc.)  *       This function should be called prior to the 1st %fst_attach call.  */
end_comment

begin_function_decl
name|int
name|fst_global_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fst_global_deinit - Global FST module de-initiator  * Note: The purpose of this function is to deallocate and de-initiate global  *       FST module data structures (linked lists, static data etc.)  */
end_comment

begin_function_decl
name|void
name|fst_global_deinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * struct fst_ctrl - Notification interface for FST module  */
end_comment

begin_struct
struct|struct
name|fst_ctrl
block|{
comment|/** 	 * init - Initialize the notification interface 	 * Returns: 0 for success, negative error code for failure. 	 */
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/** 	 * deinit - Deinitialize the notification interface 	 */
name|void
function_decl|(
modifier|*
name|deinit
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/** 	 * on_group_created - Notify about FST group creation 	 * Returns: 0 for success, negative error code for failure. 	 */
name|int
function_decl|(
modifier|*
name|on_group_created
function_decl|)
parameter_list|(
name|struct
name|fst_group
modifier|*
name|g
parameter_list|)
function_decl|;
comment|/** 	 * on_group_deleted - Notify about FST group deletion 	 */
name|void
function_decl|(
modifier|*
name|on_group_deleted
function_decl|)
parameter_list|(
name|struct
name|fst_group
modifier|*
name|g
parameter_list|)
function_decl|;
comment|/** 	 * on_iface_added - Notify about interface addition 	 * Returns: 0 for success, negative error code for failure. 	 */
name|int
function_decl|(
modifier|*
name|on_iface_added
function_decl|)
parameter_list|(
name|struct
name|fst_iface
modifier|*
name|i
parameter_list|)
function_decl|;
comment|/** 	 * on_iface_removed - Notify about interface removal 	 */
name|void
function_decl|(
modifier|*
name|on_iface_removed
function_decl|)
parameter_list|(
name|struct
name|fst_iface
modifier|*
name|i
parameter_list|)
function_decl|;
comment|/** 	 * on_session_added - Notify about FST session addition 	 * Returns: 0 for success, negative error code for failure. 	 */
name|int
function_decl|(
modifier|*
name|on_session_added
function_decl|)
parameter_list|(
name|struct
name|fst_session
modifier|*
name|s
parameter_list|)
function_decl|;
comment|/** 	 * on_session_removed - Notify about FST session removal 	 */
name|void
function_decl|(
modifier|*
name|on_session_removed
function_decl|)
parameter_list|(
name|struct
name|fst_session
modifier|*
name|s
parameter_list|)
function_decl|;
comment|/** 	 * on_event - Notify about FST event 	 * @event_type: Event type 	 * @i: Interface object that relates to the event or NULL 	 * @g: Group object that relates to the event or NULL 	 * @extra - Event specific data (see fst_ctrl_iface.h for more info) 	 */
name|void
function_decl|(
modifier|*
name|on_event
function_decl|)
parameter_list|(
name|enum
name|fst_event_type
name|event_type
parameter_list|,
name|struct
name|fst_iface
modifier|*
name|i
parameter_list|,
name|struct
name|fst_session
modifier|*
name|s
parameter_list|,
specifier|const
name|union
name|fst_event_extra
modifier|*
name|extra
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|fst_ctrl_handle
modifier|*
name|fst_global_add_ctrl
parameter_list|(
specifier|const
name|struct
name|fst_ctrl
modifier|*
name|ctrl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fst_global_del_ctrl
parameter_list|(
name|struct
name|fst_ctrl_handle
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * NOTE: These values have to be read from configuration file  */
end_comment

begin_struct
struct|struct
name|fst_iface_cfg
block|{
name|char
name|group_id
index|[
name|FST_MAX_GROUP_ID_LEN
operator|+
literal|1
index|]
decl_stmt|;
name|u8
name|priority
decl_stmt|;
name|u32
name|llt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * fst_attach - Attach interface to an FST group according to configuration read  * @ifname: Interface name  * @own_addr: Own interface MAC address  * @iface_obj: Callbacks to be used by FST module to communicate with  *             hostapd/wpa_supplicant  * @cfg: FST-related interface configuration read from the configuration file  * Returns: FST interface object for success, %NULL for failure.  */
end_comment

begin_function_decl
name|struct
name|fst_iface
modifier|*
name|fst_attach
parameter_list|(
specifier|const
name|char
modifier|*
name|ifname
parameter_list|,
specifier|const
name|u8
modifier|*
name|own_addr
parameter_list|,
specifier|const
name|struct
name|fst_wpa_obj
modifier|*
name|iface_obj
parameter_list|,
specifier|const
name|struct
name|fst_iface_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fst_detach - Detach an interface  * @iface: FST interface object  */
end_comment

begin_function_decl
name|void
name|fst_detach
parameter_list|(
name|struct
name|fst_iface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FST module inputs */
end_comment

begin_comment
comment|/**  * fst_rx_action - FST Action frames handler  * @iface: FST interface object  * @mgmt: Action frame arrived  * @len: Action frame length  */
end_comment

begin_function_decl
name|void
name|fst_rx_action
parameter_list|(
name|struct
name|fst_iface
modifier|*
name|iface
parameter_list|,
specifier|const
name|struct
name|ieee80211_mgmt
modifier|*
name|mgmt
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fst_notify_peer_connected - FST STA connect handler  * @iface: FST interface object  * @addr: Address of the connected STA  */
end_comment

begin_function_decl
name|void
name|fst_notify_peer_connected
parameter_list|(
name|struct
name|fst_iface
modifier|*
name|iface
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fst_notify_peer_disconnected - FST STA disconnect handler  * @iface: FST interface object  * @addr: Address of the disconnected STA  */
end_comment

begin_function_decl
name|void
name|fst_notify_peer_disconnected
parameter_list|(
name|struct
name|fst_iface
modifier|*
name|iface
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FST module auxiliary routines */
end_comment

begin_comment
comment|/**  * fst_are_ifaces_aggregated - Determines whether 2 interfaces belong to the  *                             same FST group  * @iface1: 1st FST interface object  * @iface1: 2nd FST interface object  *  * Returns: %TRUE if the interfaces belong to the same FST group,  *          %FALSE otherwise  */
end_comment

begin_function_decl
name|Boolean
name|fst_are_ifaces_aggregated
parameter_list|(
name|struct
name|fst_iface
modifier|*
name|iface1
parameter_list|,
name|struct
name|fst_iface
modifier|*
name|iface2
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_FST */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|fst_global_init
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|fst_global_start
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|fst_global_stop
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|fst_global_deinit
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_FST */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FST_H */
end_comment

end_unit

