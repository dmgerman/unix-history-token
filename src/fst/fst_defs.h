begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * FST module - FST related definitions  * Copyright (c) 2014, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IEEE_80211_FST_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|IEEE_80211_FST_DEFS_H
end_define

begin_comment
comment|/* IEEE Std 802.11ad */
end_comment

begin_define
define|#
directive|define
name|MB_STA_CHANNEL_ALL
value|0
end_define

begin_enum
enum|enum
name|session_type
block|{
name|SESSION_TYPE_BSS
init|=
literal|0
block|,
comment|/*  Infrastructure BSS */
name|SESSION_TYPE_IBSS
init|=
literal|1
block|,
name|SESSION_TYPE_DLS
init|=
literal|2
block|,
name|SESSION_TYPE_TDLS
init|=
literal|3
block|,
name|SESSION_TYPE_PBSS
init|=
literal|4
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|SESSION_CONTROL
parameter_list|(
name|session_type
parameter_list|,
name|switch_intent
parameter_list|)
define|\
value|(((u8) ((session_type)& 0x7)) | ((switch_intent) ? 0x10 : 0x00))
end_define

begin_define
define|#
directive|define
name|GET_SESSION_CONTROL_TYPE
parameter_list|(
name|session_control
parameter_list|)
define|\
value|((u8) ((session_control)& 0x7))
end_define

begin_define
define|#
directive|define
name|GET_SESSION_CONTROL_SWITCH_INTENT
parameter_list|(
name|session_control
parameter_list|)
define|\
value|(((session_control)& 0x10)>> 4)
end_define

begin_comment
comment|/* 8.4.2.147  Session Transition element */
end_comment

begin_struct
struct|struct
name|session_transition_ie
block|{
name|u8
name|element_id
decl_stmt|;
name|u8
name|length
decl_stmt|;
name|u32
name|fsts_id
decl_stmt|;
name|u8
name|session_control
decl_stmt|;
name|u8
name|new_band_id
decl_stmt|;
name|u8
name|new_band_setup
decl_stmt|;
name|u8
name|new_band_op
decl_stmt|;
name|u8
name|old_band_id
decl_stmt|;
name|u8
name|old_band_setup
decl_stmt|;
name|u8
name|old_band_op
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|fst_setup_req
block|{
name|u8
name|action
decl_stmt|;
name|u8
name|dialog_token
decl_stmt|;
name|u32
name|llt
decl_stmt|;
name|struct
name|session_transition_ie
name|stie
decl_stmt|;
comment|/* Multi-band (optional) */
comment|/* Wakeup Schedule (optional) */
comment|/* Awake Window (optional) */
comment|/* Switching Stream (optional) */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|fst_setup_res
block|{
name|u8
name|action
decl_stmt|;
name|u8
name|dialog_token
decl_stmt|;
name|u8
name|status_code
decl_stmt|;
name|struct
name|session_transition_ie
name|stie
decl_stmt|;
comment|/* Multi-band (optional) */
comment|/* Wakeup Schedule (optional) */
comment|/* Awake Window (optional) */
comment|/* Switching Stream (optional) */
comment|/* Timeout Interval (optional) */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|fst_ack_req
block|{
name|u8
name|action
decl_stmt|;
name|u8
name|dialog_token
decl_stmt|;
name|u32
name|fsts_id
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|fst_ack_res
block|{
name|u8
name|action
decl_stmt|;
name|u8
name|dialog_token
decl_stmt|;
name|u32
name|fsts_id
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|fst_tear_down
block|{
name|u8
name|action
decl_stmt|;
name|u32
name|fsts_id
decl_stmt|;
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEEE_80211_FST_DEFS_H */
end_comment

end_unit

