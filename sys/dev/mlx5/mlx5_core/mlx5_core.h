begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2015, Mellanox Technologies, Ltd.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS `AS IS' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MLX5_CORE_H__
end_ifndef

begin_define
define|#
directive|define
name|__MLX5_CORE_H__
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/kernel.h>
end_include

begin_include
include|#
directive|include
file|<linux/sched.h>
end_include

begin_define
define|#
directive|define
name|DRIVER_NAME
value|"mlx5_core"
end_define

begin_define
define|#
directive|define
name|DRIVER_VERSION
value|"1.23.0 (03 Mar 2015)"
end_define

begin_define
define|#
directive|define
name|DRIVER_RELDATE
value|"03 Mar 2015"
end_define

begin_decl_stmt
specifier|extern
name|int
name|mlx5_core_debug_mask
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|mlx5_core_dbg
parameter_list|(
name|dev
parameter_list|,
name|format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|pr_debug("%s:%s:%d:(pid %d): " format,				\ 		 (dev)->priv.name, __func__, __LINE__, curthread->td_proc->p_pid,	\ 		 ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|mlx5_core_dbg_mask
parameter_list|(
name|dev
parameter_list|,
name|mask
parameter_list|,
name|format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {									\ 	if ((mask)& mlx5_core_debug_mask)				\ 		mlx5_core_dbg(dev, format, ##__VA_ARGS__);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|mlx5_core_err
parameter_list|(
name|dev
parameter_list|,
name|format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|printf("mlx5_core: ERR: ""%s:%s:%d:(pid %d): " format, \ 	       (dev)->priv.name, __func__, __LINE__, curthread->td_proc->p_pid, \ 	       ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|mlx5_core_warn
parameter_list|(
name|dev
parameter_list|,
name|format
parameter_list|,
modifier|...
parameter_list|)
define|\
value|printf("mlx5_core: WARN: ""%s:%s:%d:(pid %d): " format, \ 		(dev)->priv.name, __func__, __LINE__, curthread->td_proc->p_pid, \ 		##__VA_ARGS__)
end_define

begin_enum
enum|enum
block|{
name|MLX5_CMD_DATA
block|,
comment|/* print command payload only */
name|MLX5_CMD_TIME
block|,
comment|/* print command execution time */
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|mlx5_core_dev
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|mlx5_query_hca_caps
parameter_list|(
name|struct
name|mlx5_core_dev
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5_query_board_id
parameter_list|(
name|struct
name|mlx5_core_dev
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5_cmd_init_hca
parameter_list|(
name|struct
name|mlx5_core_dev
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx5_cmd_teardown_hca
parameter_list|(
name|struct
name|mlx5_core_dev
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx5e_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|mlx5_cmd_exec_check_status
parameter_list|(
name|struct
name|mlx5_core_dev
modifier|*
name|dev
parameter_list|,
name|u32
modifier|*
name|in
parameter_list|,
name|int
name|in_size
parameter_list|,
name|u32
modifier|*
name|out
parameter_list|,
name|int
name|out_size
parameter_list|)
block|{
name|int
name|err
decl_stmt|;
name|err
operator|=
name|mlx5_cmd_exec
argument_list|(
name|dev
argument_list|,
name|in
argument_list|,
name|in_size
argument_list|,
name|out
argument_list|,
name|out_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
return|return
name|err
return|;
block|}
name|err
operator|=
name|mlx5_cmd_status_to_err
argument_list|(
operator|(
expr|struct
name|mlx5_outbox_hdr
operator|*
operator|)
name|out
argument_list|)
expr_stmt|;
return|return
name|err
return|;
block|}
end_function

begin_function_decl
name|int
name|mlx5_rename_eq
parameter_list|(
name|struct
name|mlx5_core_dev
modifier|*
name|dev
parameter_list|,
name|int
name|eq_ix
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MLX5_CORE_H__ */
end_comment

end_unit

