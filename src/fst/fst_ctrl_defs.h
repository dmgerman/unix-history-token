begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * FST module - shared Control interface definitions  * Copyright (c) 2014, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FST_CTRL_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|FST_CTRL_DEFS_H
end_define

begin_comment
comment|/* Undefined value */
end_comment

begin_define
define|#
directive|define
name|FST_CTRL_PVAL_NONE
value|"NONE"
end_define

begin_comment
comment|/* FST-ATTACH parameters */
end_comment

begin_define
define|#
directive|define
name|FST_ATTACH_CMD_PNAME_LLT
value|"llt"
end_define

begin_comment
comment|/* pval = desired LLT */
end_comment

begin_define
define|#
directive|define
name|FST_ATTACH_CMD_PNAME_PRIORITY
value|"priority"
end_define

begin_comment
comment|/* pval = desired priority */
end_comment

begin_comment
comment|/* FST-MANAGER parameters */
end_comment

begin_comment
comment|/* FST Session states */
end_comment

begin_define
define|#
directive|define
name|FST_CS_PVAL_STATE_INITIAL
value|"INITIAL"
end_define

begin_define
define|#
directive|define
name|FST_CS_PVAL_STATE_SETUP_COMPLETION
value|"SETUP_COMPLETION"
end_define

begin_define
define|#
directive|define
name|FST_CS_PVAL_STATE_TRANSITION_DONE
value|"TRANSITION_DONE"
end_define

begin_define
define|#
directive|define
name|FST_CS_PVAL_STATE_TRANSITION_CONFIRMED
value|"TRANSITION_CONFIRMED"
end_define

begin_comment
comment|/* FST Session reset reasons */
end_comment

begin_define
define|#
directive|define
name|FST_CS_PVAL_REASON_TEARDOWN
value|"REASON_TEARDOWN"
end_define

begin_define
define|#
directive|define
name|FST_CS_PVAL_REASON_SETUP
value|"REASON_SETUP"
end_define

begin_define
define|#
directive|define
name|FST_CS_PVAL_REASON_SWITCH
value|"REASON_SWITCH"
end_define

begin_define
define|#
directive|define
name|FST_CS_PVAL_REASON_STT
value|"REASON_STT"
end_define

begin_define
define|#
directive|define
name|FST_CS_PVAL_REASON_REJECT
value|"REASON_REJECT"
end_define

begin_define
define|#
directive|define
name|FST_CS_PVAL_REASON_ERROR_PARAMS
value|"REASON_ERROR_PARAMS"
end_define

begin_define
define|#
directive|define
name|FST_CS_PVAL_REASON_RESET
value|"REASON_RESET"
end_define

begin_define
define|#
directive|define
name|FST_CS_PVAL_REASON_DETACH_IFACE
value|"REASON_DETACH_IFACE"
end_define

begin_comment
comment|/* FST Session responses */
end_comment

begin_define
define|#
directive|define
name|FST_CS_PVAL_RESPONSE_ACCEPT
value|"ACCEPT"
end_define

begin_define
define|#
directive|define
name|FST_CS_PVAL_RESPONSE_REJECT
value|"REJECT"
end_define

begin_comment
comment|/* FST Session action initiator */
end_comment

begin_define
define|#
directive|define
name|FST_CS_PVAL_INITIATOR_LOCAL
value|"LOCAL"
end_define

begin_define
define|#
directive|define
name|FST_CS_PVAL_INITIATOR_REMOTE
value|"REMOTE"
end_define

begin_comment
comment|/* FST-CLI subcommands and parameter names */
end_comment

begin_define
define|#
directive|define
name|FST_CMD_LIST_GROUPS
value|"list_groups"
end_define

begin_define
define|#
directive|define
name|FST_CMD_LIST_IFACES
value|"list_ifaces"
end_define

begin_define
define|#
directive|define
name|FST_CMD_IFACE_PEERS
value|"iface_peers"
end_define

begin_define
define|#
directive|define
name|FST_CMD_GET_PEER_MBIES
value|"get_peer_mbies"
end_define

begin_define
define|#
directive|define
name|FST_CMD_LIST_SESSIONS
value|"list_sessions"
end_define

begin_define
define|#
directive|define
name|FST_CMD_SESSION_ADD
value|"session_add"
end_define

begin_define
define|#
directive|define
name|FST_CMD_SESSION_REMOVE
value|"session_remove"
end_define

begin_define
define|#
directive|define
name|FST_CMD_SESSION_GET
value|"session_get"
end_define

begin_define
define|#
directive|define
name|FST_CSG_PNAME_OLD_PEER_ADDR
value|"old_peer_addr"
end_define

begin_comment
comment|/* pval = address string */
end_comment

begin_define
define|#
directive|define
name|FST_CSG_PNAME_NEW_PEER_ADDR
value|"new_peer_addr"
end_define

begin_comment
comment|/* pval = address string */
end_comment

begin_define
define|#
directive|define
name|FST_CSG_PNAME_OLD_IFNAME
value|"old_ifname"
end_define

begin_comment
comment|/* pval = ifname */
end_comment

begin_define
define|#
directive|define
name|FST_CSG_PNAME_NEW_IFNAME
value|"new_ifname"
end_define

begin_comment
comment|/* pval = ifname */
end_comment

begin_define
define|#
directive|define
name|FST_CSG_PNAME_LLT
value|"llt"
end_define

begin_comment
comment|/* pval = numeric llt value */
end_comment

begin_define
define|#
directive|define
name|FST_CSG_PNAME_STATE
value|"state"
end_define

begin_comment
comment|/* pval = FST_CS_PVAL_STATE_... */
end_comment

begin_define
define|#
directive|define
name|FST_CMD_SESSION_SET
value|"session_set"
end_define

begin_define
define|#
directive|define
name|FST_CSS_PNAME_OLD_PEER_ADDR
value|FST_CSG_PNAME_OLD_PEER_ADDR
end_define

begin_define
define|#
directive|define
name|FST_CSS_PNAME_NEW_PEER_ADDR
value|FST_CSG_PNAME_NEW_PEER_ADDR
end_define

begin_define
define|#
directive|define
name|FST_CSS_PNAME_OLD_IFNAME
value|FST_CSG_PNAME_OLD_IFNAME
end_define

begin_define
define|#
directive|define
name|FST_CSS_PNAME_NEW_IFNAME
value|FST_CSG_PNAME_NEW_IFNAME
end_define

begin_define
define|#
directive|define
name|FST_CSS_PNAME_LLT
value|FST_CSG_PNAME_LLT
end_define

begin_define
define|#
directive|define
name|FST_CMD_SESSION_INITIATE
value|"session_initiate"
end_define

begin_define
define|#
directive|define
name|FST_CMD_SESSION_RESPOND
value|"session_respond"
end_define

begin_define
define|#
directive|define
name|FST_CMD_SESSION_TRANSFER
value|"session_transfer"
end_define

begin_define
define|#
directive|define
name|FST_CMD_SESSION_TEARDOWN
value|"session_teardown"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_FST_TEST
end_ifdef

begin_define
define|#
directive|define
name|FST_CTR_PVAL_BAD_NEW_BAND
value|"bad_new_band"
end_define

begin_define
define|#
directive|define
name|FST_CMD_TEST_REQUEST
value|"test_request"
end_define

begin_define
define|#
directive|define
name|FST_CTR_IS_SUPPORTED
value|"is_supported"
end_define

begin_define
define|#
directive|define
name|FST_CTR_SEND_SETUP_REQUEST
value|"send_setup_request"
end_define

begin_define
define|#
directive|define
name|FST_CTR_SEND_SETUP_RESPONSE
value|"send_setup_response"
end_define

begin_define
define|#
directive|define
name|FST_CTR_SEND_ACK_REQUEST
value|"send_ack_request"
end_define

begin_define
define|#
directive|define
name|FST_CTR_SEND_ACK_RESPONSE
value|"send_ack_response"
end_define

begin_define
define|#
directive|define
name|FST_CTR_SEND_TEAR_DOWN
value|"send_tear_down"
end_define

begin_define
define|#
directive|define
name|FST_CTR_GET_FSTS_ID
value|"get_fsts_id"
end_define

begin_define
define|#
directive|define
name|FST_CTR_GET_LOCAL_MBIES
value|"get_local_mbies"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_FST_TEST */
end_comment

begin_comment
comment|/* Events */
end_comment

begin_define
define|#
directive|define
name|FST_CTRL_EVENT_IFACE
value|"FST-EVENT-IFACE"
end_define

begin_define
define|#
directive|define
name|FST_CEI_PNAME_IFNAME
value|"ifname"
end_define

begin_define
define|#
directive|define
name|FST_CEI_PNAME_GROUP
value|"group"
end_define

begin_define
define|#
directive|define
name|FST_CEI_PNAME_ATTACHED
value|"attached"
end_define

begin_define
define|#
directive|define
name|FST_CEI_PNAME_DETACHED
value|"detached"
end_define

begin_define
define|#
directive|define
name|FST_CTRL_EVENT_PEER
value|"FST-EVENT-PEER"
end_define

begin_define
define|#
directive|define
name|FST_CEP_PNAME_IFNAME
value|"ifname"
end_define

begin_define
define|#
directive|define
name|FST_CEP_PNAME_ADDR
value|"peer_addr"
end_define

begin_define
define|#
directive|define
name|FST_CEP_PNAME_CONNECTED
value|"connected"
end_define

begin_define
define|#
directive|define
name|FST_CEP_PNAME_DISCONNECTED
value|"disconnected"
end_define

begin_define
define|#
directive|define
name|FST_CTRL_EVENT_SESSION
value|"FST-EVENT-SESSION"
end_define

begin_define
define|#
directive|define
name|FST_CES_PNAME_SESSION_ID
value|"session_id"
end_define

begin_define
define|#
directive|define
name|FST_CES_PNAME_EVT_TYPE
value|"event_type"
end_define

begin_define
define|#
directive|define
name|FST_PVAL_EVT_TYPE_SESSION_STATE
value|"EVENT_FST_SESSION_STATE"
end_define

begin_comment
comment|/* old_state/new_state: pval = FST_CS_PVAL_STATE_... */
end_comment

begin_define
define|#
directive|define
name|FST_CES_PNAME_OLD_STATE
value|"old_state"
end_define

begin_define
define|#
directive|define
name|FST_CES_PNAME_NEW_STATE
value|"new_state"
end_define

begin_define
define|#
directive|define
name|FST_CES_PNAME_REASON
value|"reason"
end_define

begin_comment
comment|/* pval = FST_CS_PVAL_REASON_... */
end_comment

begin_define
define|#
directive|define
name|FST_CES_PNAME_REJECT_CODE
value|"reject_code"
end_define

begin_comment
comment|/* pval = u8 code */
end_comment

begin_comment
comment|/* pval = FST_CS_PVAL_INITIATOR_... */
end_comment

begin_define
define|#
directive|define
name|FST_CES_PNAME_INITIATOR
value|"initiator"
end_define

begin_define
define|#
directive|define
name|FST_PVAL_EVT_TYPE_ESTABLISHED
value|"EVENT_FST_ESTABLISHED"
end_define

begin_define
define|#
directive|define
name|FST_PVAL_EVT_TYPE_SETUP
value|"EVENT_FST_SETUP"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FST_CTRL_DEFS_H */
end_comment

end_unit

