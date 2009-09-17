begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP-TNC - TNCS (IF-IMV, IF-TNCCS, and IF-TNCCS-SOH)  * Copyright (c) 2007-2008, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TNCS_H
end_ifndef

begin_define
define|#
directive|define
name|TNCS_H
end_define

begin_struct_decl
struct_decl|struct
name|tncs_data
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|tncs_data
modifier|*
name|tncs_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tncs_deinit
parameter_list|(
name|struct
name|tncs_data
modifier|*
name|tncs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tncs_init_connection
parameter_list|(
name|struct
name|tncs_data
modifier|*
name|tncs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|tncs_total_send_len
parameter_list|(
name|struct
name|tncs_data
modifier|*
name|tncs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
modifier|*
name|tncs_copy_send_buf
parameter_list|(
name|struct
name|tncs_data
modifier|*
name|tncs
parameter_list|,
name|u8
modifier|*
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tncs_if_tnccs_start
parameter_list|(
name|struct
name|tncs_data
modifier|*
name|tncs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tncs_if_tnccs_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|tncs_process_res
block|{
name|TNCCS_PROCESS_ERROR
init|=
operator|-
literal|1
block|,
name|TNCCS_PROCESS_OK_NO_RECOMMENDATION
init|=
literal|0
block|,
name|TNCCS_RECOMMENDATION_ERROR
block|,
name|TNCCS_RECOMMENDATION_ALLOW
block|,
name|TNCCS_RECOMMENDATION_NONE
block|,
name|TNCCS_RECOMMENDATION_ISOLATE
block|,
name|TNCCS_RECOMMENDATION_NO_ACCESS
block|,
name|TNCCS_RECOMMENDATION_NO_RECOMMENDATION
block|}
enum|;
end_enum

begin_function_decl
name|enum
name|tncs_process_res
name|tncs_process_if_tnccs
parameter_list|(
name|struct
name|tncs_data
modifier|*
name|tncs
parameter_list|,
specifier|const
name|u8
modifier|*
name|msg
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tncs_global_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tncs_global_deinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|tncs_build_soh_request
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|tncs_process_soh
parameter_list|(
specifier|const
name|u8
modifier|*
name|soh_tlv
parameter_list|,
name|size_t
name|soh_tlv_len
parameter_list|,
name|int
modifier|*
name|failure
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TNCS_H */
end_comment

end_unit

