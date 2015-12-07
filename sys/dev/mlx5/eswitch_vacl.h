begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2015, Mellanox Technologies, Ltd.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS `AS IS' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MLX5_ESWITCH_VACL_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|MLX5_ESWITCH_VACL_TABLE_H
end_define

begin_include
include|#
directive|include
file|<dev/mlx5/driver.h>
end_include

begin_function_decl
name|void
modifier|*
name|mlx5_vacl_table_create
parameter_list|(
name|struct
name|mlx5_core_dev
modifier|*
name|dev
parameter_list|,
name|u16
name|vport
parameter_list|,
name|bool
name|is_egress
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5_vacl_table_cleanup
parameter_list|(
name|void
modifier|*
name|acl_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5_vacl_table_add_vlan
parameter_list|(
name|void
modifier|*
name|acl_t
parameter_list|,
name|u16
name|vlan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5_vacl_table_del_vlan
parameter_list|(
name|void
modifier|*
name|acl_t
parameter_list|,
name|u16
name|vlan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5_vacl_table_enable_vlan_filter
parameter_list|(
name|void
modifier|*
name|acl_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5_vacl_table_disable_vlan_filter
parameter_list|(
name|void
modifier|*
name|acl_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5_vacl_table_drop_untagged
parameter_list|(
name|void
modifier|*
name|acl_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5_vacl_table_allow_untagged
parameter_list|(
name|void
modifier|*
name|acl_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5_vacl_table_drop_unknown_vlan
parameter_list|(
name|void
modifier|*
name|acl_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5_vacl_table_allow_unknown_vlan
parameter_list|(
name|void
modifier|*
name|acl_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5_vacl_table_set_spoofchk
parameter_list|(
name|void
modifier|*
name|acl_t
parameter_list|,
name|bool
name|spoofchk
parameter_list|,
name|u8
modifier|*
name|vport_mac
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MLX5_ESWITCH_VACL_TABLE_H */
end_comment

end_unit

