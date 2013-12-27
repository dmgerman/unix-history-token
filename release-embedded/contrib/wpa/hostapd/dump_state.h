begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / State dump  * Copyright (c) 2002-2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DUMP_STATE_H
end_ifndef

begin_define
define|#
directive|define
name|DUMP_STATE_H
end_define

begin_function_decl
name|int
name|handle_dump_state_iface
parameter_list|(
name|struct
name|hostapd_iface
modifier|*
name|iface
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DUMP_STATE_H */
end_comment

end_unit

