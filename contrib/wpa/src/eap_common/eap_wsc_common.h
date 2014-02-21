begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP-WSC definitions for Wi-Fi Protected Setup  * Copyright (c) 2007, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_WSC_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_WSC_COMMON_H
end_define

begin_define
define|#
directive|define
name|EAP_VENDOR_TYPE_WSC
value|1
end_define

begin_define
define|#
directive|define
name|WSC_FLAGS_MF
value|0x01
end_define

begin_define
define|#
directive|define
name|WSC_FLAGS_LF
value|0x02
end_define

begin_define
define|#
directive|define
name|WSC_ID_REGISTRAR
value|"WFA-SimpleConfig-Registrar-1-0"
end_define

begin_define
define|#
directive|define
name|WSC_ID_REGISTRAR_LEN
value|30
end_define

begin_define
define|#
directive|define
name|WSC_ID_ENROLLEE
value|"WFA-SimpleConfig-Enrollee-1-0"
end_define

begin_define
define|#
directive|define
name|WSC_ID_ENROLLEE_LEN
value|29
end_define

begin_define
define|#
directive|define
name|WSC_FRAGMENT_SIZE
value|1400
end_define

begin_function_decl
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
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_WSC_COMMON_H */
end_comment

end_unit

