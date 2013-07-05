begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Generic advertisement service (GAS) query  * Copyright (c) 2009, Atheros Communications  * Copyright (c) 2011, Qualcomm Atheros  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GAS_QUERY_H
end_ifndef

begin_define
define|#
directive|define
name|GAS_QUERY_H
end_define

begin_struct_decl
struct_decl|struct
name|gas_query
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_GAS
end_ifdef

begin_function_decl
name|struct
name|gas_query
modifier|*
name|gas_query_init
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gas_query_deinit
parameter_list|(
name|struct
name|gas_query
modifier|*
name|gas
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gas_query_rx
parameter_list|(
name|struct
name|gas_query
modifier|*
name|gas
parameter_list|,
specifier|const
name|u8
modifier|*
name|da
parameter_list|,
specifier|const
name|u8
modifier|*
name|sa
parameter_list|,
specifier|const
name|u8
modifier|*
name|bssid
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|freq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * enum gas_query_result - GAS query result  */
end_comment

begin_enum
enum|enum
name|gas_query_result
block|{
name|GAS_QUERY_SUCCESS
block|,
name|GAS_QUERY_FAILURE
block|,
name|GAS_QUERY_TIMEOUT
block|,
name|GAS_QUERY_PEER_ERROR
block|,
name|GAS_QUERY_INTERNAL_ERROR
block|,
name|GAS_QUERY_CANCELLED
block|,
name|GAS_QUERY_DELETED_AT_DEINIT
block|}
enum|;
end_enum

begin_function_decl
name|int
name|gas_query_req
parameter_list|(
name|struct
name|gas_query
modifier|*
name|gas
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
name|int
name|freq
parameter_list|,
name|struct
name|wpabuf
modifier|*
name|req
parameter_list|,
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
name|u8
name|dialog_token
parameter_list|,
name|enum
name|gas_query_result
name|result
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|adv_proto
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|resp
parameter_list|,
name|u16
name|status_code
parameter_list|)
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gas_query_cancel
parameter_list|(
name|struct
name|gas_query
modifier|*
name|gas
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst
parameter_list|,
name|u8
name|dialog_token
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_GAS */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|gas_query
modifier|*
name|gas_query_init
parameter_list|(
name|struct
name|wpa_supplicant
modifier|*
name|wpa_s
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
literal|1
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|gas_query_deinit
parameter_list|(
name|struct
name|gas_query
modifier|*
name|gas
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_GAS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GAS_QUERY_H */
end_comment

end_unit

