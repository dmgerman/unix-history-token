begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Generic advertisement service (GAS) server  * Copyright (c) 2011-2012, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GAS_SERV_H
end_ifndef

begin_define
define|#
directive|define
name|GAS_SERV_H
end_define

begin_define
define|#
directive|define
name|ANQP_REQ_CAPABILITY_LIST
define|\
value|(1<< (ANQP_CAPABILITY_LIST - ANQP_QUERY_LIST))
end_define

begin_define
define|#
directive|define
name|ANQP_REQ_VENUE_NAME
define|\
value|(1<< (ANQP_VENUE_NAME - ANQP_QUERY_LIST))
end_define

begin_define
define|#
directive|define
name|ANQP_REQ_NETWORK_AUTH_TYPE
define|\
value|(1<< (ANQP_NETWORK_AUTH_TYPE - ANQP_QUERY_LIST))
end_define

begin_define
define|#
directive|define
name|ANQP_REQ_ROAMING_CONSORTIUM
define|\
value|(1<< (ANQP_ROAMING_CONSORTIUM - ANQP_QUERY_LIST))
end_define

begin_define
define|#
directive|define
name|ANQP_REQ_IP_ADDR_TYPE_AVAILABILITY
define|\
value|(1<< (ANQP_IP_ADDR_TYPE_AVAILABILITY - ANQP_QUERY_LIST))
end_define

begin_define
define|#
directive|define
name|ANQP_REQ_NAI_REALM
define|\
value|(1<< (ANQP_NAI_REALM - ANQP_QUERY_LIST))
end_define

begin_define
define|#
directive|define
name|ANQP_REQ_3GPP_CELLULAR_NETWORK
define|\
value|(1<< (ANQP_3GPP_CELLULAR_NETWORK - ANQP_QUERY_LIST))
end_define

begin_define
define|#
directive|define
name|ANQP_REQ_DOMAIN_NAME
define|\
value|(1<< (ANQP_DOMAIN_NAME - ANQP_QUERY_LIST))
end_define

begin_define
define|#
directive|define
name|ANQP_REQ_HS_CAPABILITY_LIST
define|\
value|(0x10000<< HS20_STYPE_CAPABILITY_LIST)
end_define

begin_define
define|#
directive|define
name|ANQP_REQ_OPERATOR_FRIENDLY_NAME
define|\
value|(0x10000<< HS20_STYPE_OPERATOR_FRIENDLY_NAME)
end_define

begin_define
define|#
directive|define
name|ANQP_REQ_WAN_METRICS
define|\
value|(0x10000<< HS20_STYPE_WAN_METRICS)
end_define

begin_define
define|#
directive|define
name|ANQP_REQ_CONNECTION_CAPABILITY
define|\
value|(0x10000<< HS20_STYPE_CONNECTION_CAPABILITY)
end_define

begin_define
define|#
directive|define
name|ANQP_REQ_NAI_HOME_REALM
define|\
value|(0x10000<< HS20_STYPE_NAI_HOME_REALM_QUERY)
end_define

begin_define
define|#
directive|define
name|ANQP_REQ_OPERATING_CLASS
define|\
value|(0x10000<< HS20_STYPE_OPERATING_CLASS)
end_define

begin_comment
comment|/* To account for latencies between hostapd and external ANQP processor */
end_comment

begin_define
define|#
directive|define
name|GAS_SERV_COMEBACK_DELAY_FUDGE
value|10
end_define

begin_define
define|#
directive|define
name|GAS_SERV_MIN_COMEBACK_DELAY
value|100
end_define

begin_comment
comment|/* in TU */
end_comment

begin_struct
struct|struct
name|gas_dialog_info
block|{
name|u8
name|valid
decl_stmt|;
name|u8
name|index
decl_stmt|;
name|struct
name|wpabuf
modifier|*
name|sd_resp
decl_stmt|;
comment|/* Fragmented response */
name|u8
name|dialog_token
decl_stmt|;
name|size_t
name|sd_resp_pos
decl_stmt|;
comment|/* Offset in sd_resp */
name|u8
name|sd_frag_id
decl_stmt|;
name|u16
name|comeback_delay
decl_stmt|;
name|unsigned
name|int
name|requested
decl_stmt|;
name|unsigned
name|int
name|received
decl_stmt|;
name|unsigned
name|int
name|all_requested
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|hostapd_data
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|gas_serv_tx_gas_response
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
name|struct
name|gas_dialog_info
modifier|*
name|dialog
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|gas_dialog_info
modifier|*
name|gas_serv_dialog_find
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|u8
name|dialog_token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gas_serv_dialog_clear
parameter_list|(
name|struct
name|gas_dialog_info
modifier|*
name|dialog
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gas_serv_init
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gas_serv_deinit
parameter_list|(
name|struct
name|hostapd_data
modifier|*
name|hapd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GAS_SERV_H */
end_comment

end_unit

