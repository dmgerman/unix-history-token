begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Netlink helper functions for driver wrappers  * Copyright (c) 2002-2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NETLINK_H
end_ifndef

begin_define
define|#
directive|define
name|NETLINK_H
end_define

begin_struct_decl
struct_decl|struct
name|netlink_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ifinfomsg
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|netlink_config
block|{
name|void
modifier|*
name|ctx
decl_stmt|;
name|void
function_decl|(
modifier|*
name|newlink_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|struct
name|ifinfomsg
modifier|*
name|ifi
parameter_list|,
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dellink_cb
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|struct
name|ifinfomsg
modifier|*
name|ifi
parameter_list|,
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|netlink_data
modifier|*
name|netlink_init
parameter_list|(
name|struct
name|netlink_config
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netlink_deinit
parameter_list|(
name|struct
name|netlink_data
modifier|*
name|netlink
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netlink_send_oper_ifla
parameter_list|(
name|struct
name|netlink_data
modifier|*
name|netlink
parameter_list|,
name|int
name|ifindex
parameter_list|,
name|int
name|linkmode
parameter_list|,
name|int
name|operstate
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETLINK_H */
end_comment

end_unit

