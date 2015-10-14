begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * FST module - internal Control interface definitions  * Copyright (c) 2014, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FST_CTRL_IFACE_H
end_ifndef

begin_define
define|#
directive|define
name|FST_CTRL_IFACE_H
end_define

begin_include
include|#
directive|include
file|"fst/fst_ctrl_aux.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_FST
end_ifdef

begin_comment
comment|/* receiver */
end_comment

begin_function_decl
name|int
name|fst_ctrl_iface_mb_info
parameter_list|(
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fst_ctrl_iface_receive
parameter_list|(
specifier|const
name|char
modifier|*
name|txtaddr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|fst_ctrl
modifier|*
name|fst_ctrl_cli
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_FST */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|fst_ctrl_iface_mb_info
parameter_list|(
specifier|const
name|u8
modifier|*
name|addr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_FST */
end_comment

begin_function_decl
name|int
name|fst_read_next_int_param
parameter_list|(
specifier|const
name|char
modifier|*
name|params
parameter_list|,
name|Boolean
modifier|*
name|valid
parameter_list|,
name|char
modifier|*
modifier|*
name|endp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fst_read_next_text_param
parameter_list|(
specifier|const
name|char
modifier|*
name|params
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|,
name|char
modifier|*
modifier|*
name|endp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fst_read_peer_addr
parameter_list|(
specifier|const
name|char
modifier|*
name|mac
parameter_list|,
name|u8
modifier|*
name|peer_addr
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|fst_iface_cfg
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|fst_parse_attach_command
parameter_list|(
specifier|const
name|char
modifier|*
name|cmd
parameter_list|,
name|char
modifier|*
name|ifname
parameter_list|,
name|size_t
name|ifname_size
parameter_list|,
name|struct
name|fst_iface_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fst_parse_detach_command
parameter_list|(
specifier|const
name|char
modifier|*
name|cmd
parameter_list|,
name|char
modifier|*
name|ifname
parameter_list|,
name|size_t
name|ifname_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fst_iface_detach
parameter_list|(
specifier|const
name|char
modifier|*
name|ifname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CTRL_IFACE_FST_H */
end_comment

end_unit

