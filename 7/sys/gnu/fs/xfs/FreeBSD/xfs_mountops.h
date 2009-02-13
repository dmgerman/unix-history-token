begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Alexander Kabaev  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XFS_XFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_XFS_XFS_H_
end_define

begin_define
define|#
directive|define
name|XFSFS_VMAJOR
value|0
end_define

begin_define
define|#
directive|define
name|XFS_VMINOR
value|1
end_define

begin_define
define|#
directive|define
name|XFS_VERSION
value|((XFS_VMAJOR<< 16) | XFS_VMINOR)
end_define

begin_define
define|#
directive|define
name|XFS_NAME
value|"xfs"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|xfsmount
block|{
name|struct
name|xfs_mount_args
name|m_args
decl_stmt|;
comment|/* Mount parameters */
name|struct
name|mount
modifier|*
name|m_mp
decl_stmt|;
comment|/* Back pointer */
name|xfs_vfs_t
name|m_vfs
decl_stmt|;
comment|/* SHOULD BE FIRST */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XFSTOMNT
parameter_list|(
name|xmp
parameter_list|)
value|((xmp)->m_mp)
end_define

begin_define
define|#
directive|define
name|XFSTOVFS
parameter_list|(
name|xmp
parameter_list|)
value|(&(xmp)->m_vfs)
end_define

begin_define
define|#
directive|define
name|MNTTOXFS
parameter_list|(
name|mp
parameter_list|)
value|((struct xfsmount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|MNTTOVFS
parameter_list|(
name|mp
parameter_list|)
value|XFSTOVFS(MNTTOXFS(mp))
end_define

begin_define
define|#
directive|define
name|VFSTOMNT
parameter_list|(
name|vfsp
parameter_list|)
value|(vfsp)->vfs_mp
end_define

begin_define
define|#
directive|define
name|VFSTOXFS
parameter_list|(
name|vfsp
parameter_list|)
value|MNTTOXFS(VFSTOMNT(vfsp))
end_define

begin_function_decl
name|struct
name|xfsmount
modifier|*
name|xfsmount_allocate
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfsmount_deallocate
parameter_list|(
name|struct
name|xfsmount
modifier|*
name|xmp
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* _XFS_XFS_H*/
end_comment

end_unit

