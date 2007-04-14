begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Dag-Erling Coïdan Smørgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *      $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PSEUDOFS_INTERNAL_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_PSEUDOFS_INTERNAL_H_INCLUDED
end_define

begin_comment
comment|/*  * Sysctl subtree  */
end_comment

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_vfs_pfs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Vnode data  */
end_comment

begin_struct
struct|struct
name|pfs_vdata
block|{
name|struct
name|pfs_node
modifier|*
name|pvd_pn
decl_stmt|;
name|pid_t
name|pvd_pid
decl_stmt|;
name|struct
name|vnode
modifier|*
name|pvd_vnode
decl_stmt|;
name|struct
name|pfs_vdata
modifier|*
name|pvd_prev
decl_stmt|,
modifier|*
name|pvd_next
decl_stmt|;
name|int
name|pvd_dead
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Vnode cache  */
end_comment

begin_function_decl
name|void
name|pfs_vncache_load
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfs_vncache_unload
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfs_vncache_alloc
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|,
name|struct
name|pfs_node
modifier|*
parameter_list|,
name|pid_t
name|pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfs_vncache_free
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * File number bitmap  */
end_comment

begin_function_decl
name|void
name|pfs_fileno_init
parameter_list|(
name|struct
name|pfs_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfs_fileno_uninit
parameter_list|(
name|struct
name|pfs_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfs_fileno_alloc
parameter_list|(
name|struct
name|pfs_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfs_fileno_free
parameter_list|(
name|struct
name|pfs_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

