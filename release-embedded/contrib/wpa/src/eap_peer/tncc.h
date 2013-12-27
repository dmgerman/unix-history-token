begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP-TNC - TNCC (IF-IMC and IF-TNCCS)  * Copyright (c) 2007, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TNCC_H
end_ifndef

begin_define
define|#
directive|define
name|TNCC_H
end_define

begin_struct_decl
struct_decl|struct
name|tncc_data
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|tncc_data
modifier|*
name|tncc_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tncc_deinit
parameter_list|(
name|struct
name|tncc_data
modifier|*
name|tncc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tncc_init_connection
parameter_list|(
name|struct
name|tncc_data
modifier|*
name|tncc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|tncc_total_send_len
parameter_list|(
name|struct
name|tncc_data
modifier|*
name|tncc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
modifier|*
name|tncc_copy_send_buf
parameter_list|(
name|struct
name|tncc_data
modifier|*
name|tncc
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
name|tncc_if_tnccs_start
parameter_list|(
name|struct
name|tncc_data
modifier|*
name|tncc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tncc_if_tnccs_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|tncc_process_res
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
block|}
enum|;
end_enum

begin_function_decl
name|enum
name|tncc_process_res
name|tncc_process_if_tnccs
parameter_list|(
name|struct
name|tncc_data
modifier|*
name|tncc
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
name|struct
name|wpabuf
modifier|*
name|tncc_process_soh_request
parameter_list|(
name|int
name|ver
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TNCC_H */
end_comment

end_unit

