begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 EMC Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_VM_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_VM_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/sf_buf.h>
end_include

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|zfs_vm_pagerret_bad
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|zfs_vm_pagerret_error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|zfs_vm_pagerret_ok
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|zfs_vm_pagerput_sync
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|zfs_vm_pagerput_inval
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|zfs_vmobject_assert_wlocked
parameter_list|(
name|vm_object_t
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|zfs_vmobject_wlock
parameter_list|(
name|vm_object_t
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|zfs_vmobject_wunlock
parameter_list|(
name|vm_object_t
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|caddr_t
name|zfs_map_page
parameter_list|(
name|vm_page_t
name|pp
parameter_list|,
name|struct
name|sf_buf
modifier|*
modifier|*
name|sfp
parameter_list|)
block|{
operator|*
name|sfp
operator|=
name|sf_buf_alloc
argument_list|(
name|pp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|caddr_t
operator|)
name|sf_buf_kva
argument_list|(
operator|*
name|sfp
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|zfs_unmap_page
parameter_list|(
name|struct
name|sf_buf
modifier|*
name|sf
parameter_list|)
block|{
name|sf_buf_free
argument_list|(
name|sf
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENSOLARIS_SYS_VM_H_ */
end_comment

end_unit

