begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP-WSC common routines for Wi-Fi Protected Setup  * Copyright (c) 2007, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"eap_defs.h"
end_include

begin_include
include|#
directive|include
file|"eap_common.h"
end_include

begin_include
include|#
directive|include
file|"wps/wps.h"
end_include

begin_include
include|#
directive|include
file|"eap_wsc_common.h"
end_include

begin_function
name|struct
name|wpabuf
modifier|*
name|eap_wsc_build_frag_ack
parameter_list|(
name|u8
name|id
parameter_list|,
name|u8
name|code
parameter_list|)
block|{
name|struct
name|wpabuf
modifier|*
name|msg
decl_stmt|;
name|msg
operator|=
name|eap_msg_alloc
argument_list|(
name|EAP_VENDOR_WFA
argument_list|,
name|EAP_VENDOR_TYPE_WSC
argument_list|,
literal|2
argument_list|,
name|code
argument_list|,
name|id
argument_list|)
expr_stmt|;
if|if
condition|(
name|msg
operator|==
name|NULL
condition|)
block|{
name|wpa_printf
argument_list|(
name|MSG_ERROR
argument_list|,
literal|"EAP-WSC: Failed to allocate memory for "
literal|"FRAG_ACK"
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|wpa_printf
argument_list|(
name|MSG_DEBUG
argument_list|,
literal|"EAP-WSC: Send WSC/FRAG_ACK"
argument_list|)
expr_stmt|;
name|wpabuf_put_u8
argument_list|(
name|msg
argument_list|,
name|WSC_FRAG_ACK
argument_list|)
expr_stmt|;
comment|/* Op-Code */
name|wpabuf_put_u8
argument_list|(
name|msg
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Flags */
return|return
name|msg
return|;
block|}
end_function

end_unit

