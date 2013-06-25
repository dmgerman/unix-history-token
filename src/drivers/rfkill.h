begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Linux rfkill helper functions for driver wrappers  * Copyright (c) 2010, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RFKILL_H
end_ifndef

begin_define
define|#
directive|define
name|RFKILL_H
end_define

begin_struct_decl
struct_decl|struct
name|rfkill_data
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|rfkill_config
block|{
name|void
modifier|*
name|ctx
decl_stmt|;
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|void
function_decl|(
modifier|*
name|blocked_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|unblocked_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|rfkill_data
modifier|*
name|rfkill_init
parameter_list|(
name|struct
name|rfkill_config
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rfkill_deinit
parameter_list|(
name|struct
name|rfkill_data
modifier|*
name|rfkill
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rfkill_is_blocked
parameter_list|(
name|struct
name|rfkill_data
modifier|*
name|rfkill
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RFKILL_H */
end_comment

end_unit

