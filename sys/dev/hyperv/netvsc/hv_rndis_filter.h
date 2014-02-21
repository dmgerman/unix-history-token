begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2012 Microsoft Corp.  * Copyright (c) 2010-2012 Citrix Inc.  * Copyright (c) 2012 NetApp Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HV_RNDIS_FILTER_H__
end_ifndef

begin_define
define|#
directive|define
name|__HV_RNDIS_FILTER_H__
end_define

begin_comment
comment|/*  * Defines  */
end_comment

begin_comment
comment|/* Destroy or preserve channel on filter/netvsc teardown */
end_comment

begin_define
define|#
directive|define
name|HV_RF_NV_DESTROY_CHANNEL
value|TRUE
end_define

begin_define
define|#
directive|define
name|HV_RF_NV_RETAIN_CHANNEL
value|FALSE
end_define

begin_comment
comment|/*  * Number of page buffers to reserve for the RNDIS filter packet in the  * transmitted message.  */
end_comment

begin_define
define|#
directive|define
name|HV_RF_NUM_TX_RESERVED_PAGE_BUFS
value|1
end_define

begin_comment
comment|/*  * Data types  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|RNDIS_DEV_UNINITIALIZED
init|=
literal|0
block|,
name|RNDIS_DEV_INITIALIZING
block|,
name|RNDIS_DEV_INITIALIZED
block|,
name|RNDIS_DEV_DATAINITIALIZED
block|, }
name|rndis_device_state
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rndis_request_
block|{
name|STAILQ_ENTRY
argument_list|(
argument|rndis_request_
argument_list|)
name|mylist_entry
expr_stmt|;
name|struct
name|sema
name|wait_sema
decl_stmt|;
comment|/* 	 * Fixme:  We assumed a fixed size response here.  If we do ever 	 * need to handle a bigger response, we can either define a max 	 * response message or add a response buffer variable above this field 	 */
name|rndis_msg
name|response_msg
decl_stmt|;
comment|/* Simplify allocation by having a netvsc packet inline */
name|netvsc_packet
name|pkt
decl_stmt|;
name|hv_vmbus_page_buffer
name|buffer
decl_stmt|;
comment|/* Fixme:  We assumed a fixed size request here. */
name|rndis_msg
name|request_msg
decl_stmt|;
comment|/* Fixme:  Poor man's semaphore. */
name|uint32_t
name|halt_complete_flag
decl_stmt|;
block|}
name|rndis_request
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rndis_device_
block|{
name|netvsc_dev
modifier|*
name|net_dev
decl_stmt|;
name|rndis_device_state
name|state
decl_stmt|;
name|uint32_t
name|link_status
decl_stmt|;
name|uint32_t
name|new_request_id
decl_stmt|;
name|struct
name|mtx
name|req_lock
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument|RQ
argument_list|,
argument|rndis_request_
argument_list|)
name|myrequest_list
expr_stmt|;
name|uint8_t
name|hw_mac_addr
index|[
name|HW_MACADDR_LEN
index|]
decl_stmt|;
block|}
name|rndis_device
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rndis_filter_packet_
block|{
name|void
modifier|*
name|completion_context
decl_stmt|;
comment|/* No longer used */
name|pfn_on_send_rx_completion
name|on_completion
decl_stmt|;
name|rndis_msg
name|message
decl_stmt|;
block|}
name|rndis_filter_packet
typedef|;
end_typedef

begin_comment
comment|/*  * Externs  */
end_comment

begin_function_decl
specifier|extern
name|int
name|hv_rf_on_receive
parameter_list|(
name|struct
name|hv_device
modifier|*
name|device
parameter_list|,
name|netvsc_packet
modifier|*
name|pkt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hv_rf_on_device_add
parameter_list|(
name|struct
name|hv_device
modifier|*
name|device
parameter_list|,
name|void
modifier|*
name|additl_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hv_rf_on_device_remove
parameter_list|(
name|struct
name|hv_device
modifier|*
name|device
parameter_list|,
name|boolean_t
name|destroy_channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hv_rf_on_open
parameter_list|(
name|struct
name|hv_device
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hv_rf_on_close
parameter_list|(
name|struct
name|hv_device
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hv_rf_on_send
parameter_list|(
name|struct
name|hv_device
modifier|*
name|device
parameter_list|,
name|netvsc_packet
modifier|*
name|pkt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HV_RNDIS_FILTER_H__ */
end_comment

end_unit

