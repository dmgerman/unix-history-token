begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMBFS_SMBFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMBFS_SMBFS_H_
end_define

begin_define
define|#
directive|define
name|VT_SMBFS
value|24
end_define

begin_define
define|#
directive|define
name|SMBFS_VERMAJ
value|1
end_define

begin_define
define|#
directive|define
name|SMBFS_VERMIN
value|1012
end_define

begin_define
define|#
directive|define
name|SMBFS_VERSION
value|(SMBFS_VERMAJ*100000 + SMBFS_VERMIN)
end_define

begin_define
define|#
directive|define
name|SMBFS_VFSNAME
value|"smbfs"
end_define

begin_comment
comment|/* Values for flags */
end_comment

begin_define
define|#
directive|define
name|SMBFS_MOUNT_SOFT
value|0x0001
end_define

begin_define
define|#
directive|define
name|SMBFS_MOUNT_INTR
value|0x0002
end_define

begin_define
define|#
directive|define
name|SMBFS_MOUNT_STRONG
value|0x0004
end_define

begin_define
define|#
directive|define
name|SMBFS_MOUNT_HAVE_NLS
value|0x0008
end_define

begin_define
define|#
directive|define
name|SMBFS_MOUNT_NO_LONG
value|0x0010
end_define

begin_define
define|#
directive|define
name|SMBFS_MAXPATHCOMP
value|256
end_define

begin_comment
comment|/* maximum number of path components */
end_comment

begin_comment
comment|/* Layout of the mount control block for a netware file system. */
end_comment

begin_struct
struct|struct
name|smbfs_args
block|{
name|int
name|version
decl_stmt|;
name|int
name|dev
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
name|char
name|mount_point
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|u_char
name|root_path
index|[
literal|512
operator|+
literal|1
index|]
decl_stmt|;
name|uid_t
name|uid
decl_stmt|;
name|gid_t
name|gid
decl_stmt|;
name|mode_t
name|file_mode
decl_stmt|;
name|mode_t
name|dir_mode
decl_stmt|;
name|int
name|caseopt
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_SMBFSMNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|smbnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|smb_share
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|u_cred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_ioctl_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|smbmount
block|{
name|struct
name|smbfs_args
name|sm_args
decl_stmt|;
name|struct
name|mount
modifier|*
name|sm_mp
decl_stmt|;
name|struct
name|smbnode
modifier|*
name|sm_root
decl_stmt|;
name|struct
name|ucred
modifier|*
name|sm_owner
decl_stmt|;
name|int
name|sm_flags
decl_stmt|;
name|long
name|sm_nextino
decl_stmt|;
name|struct
name|smb_share
modifier|*
name|sm_share
decl_stmt|;
comment|/*	struct simplelock	sm_npslock;*/
name|struct
name|smbnode
modifier|*
name|sm_npstack
index|[
name|SMBFS_MAXPATHCOMP
index|]
decl_stmt|;
name|int
name|sm_caseopt
decl_stmt|;
name|struct
name|lock
name|sm_hashlock
decl_stmt|;
name|LIST_HEAD
argument_list|(
name|smbnode_hashhead
argument_list|,
name|smbnode
argument_list|)
operator|*
name|sm_hash
expr_stmt|;
name|u_long
name|sm_hashlen
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VFSTOSMBFS
parameter_list|(
name|mp
parameter_list|)
value|((struct smbmount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|SMBFSTOVFS
parameter_list|(
name|smp
parameter_list|)
value|((struct mount *)((smp)->sm_mp))
end_define

begin_define
define|#
directive|define
name|VTOVFS
parameter_list|(
name|vp
parameter_list|)
value|((vp)->v_mount)
end_define

begin_define
define|#
directive|define
name|VTOSMBFS
parameter_list|(
name|vp
parameter_list|)
value|(VFSTOSMBFS(VTOVFS(vp)))
end_define

begin_function_decl
name|int
name|smbfs_ioctl
parameter_list|(
name|struct
name|vop_ioctl_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smbfs_doio
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|struct
name|ucred
modifier|*
name|cr
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smbfs_vinvalbuf
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|intrflg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SMBFS_SMBFS_H_ */
end_comment

end_unit

