begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * IEEE Std 802.1X-2010 Controlled Port of PAE state machine - CP state machine  * Copyright (c) 2013, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IEEE802_1X_CP_H
end_ifndef

begin_define
define|#
directive|define
name|IEEE802_1X_CP_H
end_define

begin_include
include|#
directive|include
file|"common/defs.h"
end_include

begin_include
include|#
directive|include
file|"common/ieee802_1x_defs.h"
end_include

begin_struct_decl
struct_decl|struct
name|ieee802_1x_cp_sm
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee802_1x_kay
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ieee802_1x_mka_ki
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ieee802_1x_cp_conf
block|{
name|Boolean
name|protect
decl_stmt|;
name|Boolean
name|replay_protect
decl_stmt|;
name|enum
name|validate_frames
name|validate
decl_stmt|;
name|u32
name|replay_window
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|ieee802_1x_cp_sm
modifier|*
name|ieee802_1x_cp_sm_init
parameter_list|(
name|struct
name|ieee802_1x_kay
modifier|*
name|kay
parameter_list|,
name|struct
name|ieee802_1x_cp_conf
modifier|*
name|pcp_conf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_sm_deinit
parameter_list|(
name|struct
name|ieee802_1x_cp_sm
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_sm_step
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_connect_pending
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_connect_unauthenticated
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_connect_authenticated
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_connect_secure
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_signal_chgdserver
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_set_electedself
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|,
name|Boolean
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_set_authorizationdata
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|,
name|u8
modifier|*
name|pdata
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_set_ciphersuite
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|,
name|void
modifier|*
name|pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_set_offset
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|,
name|enum
name|confidentiality_offset
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_signal_newsak
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_set_distributedki
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|,
specifier|const
name|struct
name|ieee802_1x_mka_ki
modifier|*
name|dki
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_set_distributedan
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|,
name|u8
name|an
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_set_usingreceivesas
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|,
name|Boolean
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_set_allreceiving
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|,
name|Boolean
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_set_servertransmitting
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|,
name|Boolean
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee802_1x_cp_set_usingtransmitas
parameter_list|(
name|void
modifier|*
name|cp_ctx
parameter_list|,
name|Boolean
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEEE802_1X_CP_H */
end_comment

end_unit

