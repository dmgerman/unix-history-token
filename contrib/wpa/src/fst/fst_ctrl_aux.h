begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * FST module - miscellaneous definitions  * Copyright (c) 2014, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FST_CTRL_AUX_H
end_ifndef

begin_define
define|#
directive|define
name|FST_CTRL_AUX_H
end_define

begin_include
include|#
directive|include
file|"common/defs.h"
end_include

begin_comment
comment|/* FST module control interface API */
end_comment

begin_define
define|#
directive|define
name|FST_INVALID_SESSION_ID
value|((u32) -1)
end_define

begin_define
define|#
directive|define
name|FST_MAX_GROUP_ID_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|FST_MAX_INTERFACE_SIZE
value|32
end_define

begin_enum
enum|enum
name|fst_session_state
block|{
name|FST_SESSION_STATE_INITIAL
block|,
name|FST_SESSION_STATE_SETUP_COMPLETION
block|,
name|FST_SESSION_STATE_TRANSITION_DONE
block|,
name|FST_SESSION_STATE_TRANSITION_CONFIRMED
block|,
name|FST_SESSION_STATE_LAST
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fst_event_type
block|{
name|EVENT_FST_IFACE_STATE_CHANGED
block|,
comment|/* An interface has been either attached 					 * to or detached from an FST group */
name|EVENT_FST_ESTABLISHED
block|,
comment|/* FST Session has been established */
name|EVENT_FST_SETUP
block|,
comment|/* FST Session request received */
name|EVENT_FST_SESSION_STATE_CHANGED
block|,
comment|/* FST Session state has been changed */
name|EVENT_PEER_STATE_CHANGED
comment|/* FST related generic event occurred, 					 * see struct fst_hostap_event_data for 					 *  more info */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fst_initiator
block|{
name|FST_INITIATOR_UNDEFINED
block|,
name|FST_INITIATOR_LOCAL
block|,
name|FST_INITIATOR_REMOTE
block|, }
enum|;
end_enum

begin_union
union|union
name|fst_event_extra
block|{
struct|struct
name|fst_event_extra_iface_state
block|{
name|Boolean
name|attached
decl_stmt|;
name|char
name|ifname
index|[
name|FST_MAX_INTERFACE_SIZE
index|]
decl_stmt|;
name|char
name|group_id
index|[
name|FST_MAX_GROUP_ID_SIZE
index|]
decl_stmt|;
block|}
name|iface_state
struct|;
comment|/* for EVENT_FST_IFACE_STATE_CHANGED */
struct|struct
name|fst_event_extra_peer_state
block|{
name|Boolean
name|connected
decl_stmt|;
name|char
name|ifname
index|[
name|FST_MAX_INTERFACE_SIZE
index|]
decl_stmt|;
name|u8
name|addr
index|[
name|ETH_ALEN
index|]
decl_stmt|;
block|}
name|peer_state
struct|;
comment|/* for EVENT_PEER_STATE_CHANGED */
struct|struct
name|fst_event_extra_session_state
block|{
name|enum
name|fst_session_state
name|old_state
decl_stmt|;
name|enum
name|fst_session_state
name|new_state
decl_stmt|;
union|union
name|fst_session_state_switch_extra
block|{
struct|struct
block|{
enum|enum
name|fst_reason
block|{
name|REASON_TEARDOWN
block|,
name|REASON_SETUP
block|,
name|REASON_SWITCH
block|,
name|REASON_STT
block|,
name|REASON_REJECT
block|,
name|REASON_ERROR_PARAMS
block|,
name|REASON_RESET
block|,
name|REASON_DETACH_IFACE
block|, 				}
name|reason
enum|;
name|u8
name|reject_code
decl_stmt|;
comment|/* REASON_REJECT */
comment|/* REASON_SWITCH, 				 * REASON_TEARDOWN, 				 * REASON_REJECT 				 */
name|enum
name|fst_initiator
name|initiator
decl_stmt|;
block|}
name|to_initial
struct|;
block|}
name|extra
union|;
block|}
name|session_state
struct|;
comment|/* for EVENT_FST_SESSION_STATE_CHANGED */
block|}
union|;
end_union

begin_comment
comment|/* helpers - prints enum in string form */
end_comment

begin_define
define|#
directive|define
name|FST_NAME_UNKNOWN
value|"UNKNOWN"
end_define

begin_function_decl
specifier|const
name|char
modifier|*
name|fst_get_str_name
parameter_list|(
name|unsigned
name|index
parameter_list|,
specifier|const
name|char
modifier|*
name|names
index|[]
parameter_list|,
name|size_t
name|names_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|fst_session_event_type_name
parameter_list|(
name|enum
name|fst_event_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|fst_reason_name
parameter_list|(
name|enum
name|fst_reason
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|fst_session_state_name
parameter_list|(
name|enum
name|fst_session_state
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FST_CTRL_AUX_H */
end_comment

end_unit

