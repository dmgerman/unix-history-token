begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2011-2012, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HS20_SUPPLICANT_H
end_ifndef

begin_define
define|#
directive|define
name|HS20_SUPPLICANT_H
end_define

begin_function_decl
name|void
name|wpas_hs20_add_indication
parameter_list|(
name|struct
name|wpabuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hs20_anqp_send_req
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
name|u32
name|stypes
parameter_list|,
specifier|const
name|u8
modifier|*
name|payload
parameter_list|,
name|size_t
name|payload_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|hs20_build_anqp_req
parameter_list|(
name|u32
name|stypes
parameter_list|,
specifier|const
name|u8
modifier|*
name|payload
parameter_list|,
name|size_t
name|payload_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hs20_parse_rx_hs20_anqp_resp
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|,
specifier|const
name|u8
modifier|*
name|sa
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|slen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HS20_SUPPLICANT_H */
end_comment

end_unit

