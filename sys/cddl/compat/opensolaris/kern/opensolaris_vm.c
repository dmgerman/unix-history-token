begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 EMC Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/freebsd_rwlock.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_pager.h>
end_include

begin_decl_stmt
specifier|const
name|int
name|zfs_vm_pagerret_bad
init|=
name|VM_PAGER_BAD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|zfs_vm_pagerret_error
init|=
name|VM_PAGER_ERROR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|zfs_vm_pagerret_ok
init|=
name|VM_PAGER_OK
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|zfs_vm_pagerput_sync
init|=
name|VM_PAGER_PUT_SYNC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|zfs_vm_pagerput_inval
init|=
name|VM_PAGER_PUT_INVAL
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|zfs_vmobject_assert_wlocked
parameter_list|(
name|vm_object_t
name|object
parameter_list|)
block|{
comment|/* 	 * This is not ideal because FILE/LINE used by assertions will not 	 * be too helpful, but it must be an hard function for 	 * compatibility reasons. 	 */
name|VM_OBJECT_ASSERT_WLOCKED
argument_list|(
name|object
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|zfs_vmobject_wlock
parameter_list|(
name|vm_object_t
name|object
parameter_list|)
block|{
name|VM_OBJECT_WLOCK
argument_list|(
name|object
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|zfs_vmobject_wunlock
parameter_list|(
name|vm_object_t
name|object
parameter_list|)
block|{
name|VM_OBJECT_WUNLOCK
argument_list|(
name|object
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

