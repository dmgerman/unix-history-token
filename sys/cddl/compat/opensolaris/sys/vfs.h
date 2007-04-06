begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_VFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_VFS_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_define
define|#
directive|define
name|rootdir
value|rootvnode
end_define

begin_typedef
typedef|typedef
name|struct
name|mount
name|vfs_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|vfs_flag
value|mnt_flag
end_define

begin_define
define|#
directive|define
name|vfs_data
value|mnt_data
end_define

begin_define
define|#
directive|define
name|vfs_count
value|mnt_ref
end_define

begin_define
define|#
directive|define
name|vfs_fsid
value|mnt_stat.f_fsid
end_define

begin_define
define|#
directive|define
name|vfs_bsize
value|mnt_stat.f_bsize
end_define

begin_define
define|#
directive|define
name|v_flag
value|v_vflag
end_define

begin_define
define|#
directive|define
name|v_vfsp
value|v_mount
end_define

begin_define
define|#
directive|define
name|VFS_RDONLY
value|MNT_RDONLY
end_define

begin_define
define|#
directive|define
name|VFS_NOSETUID
value|MNT_NOSUID
end_define

begin_define
define|#
directive|define
name|VFS_NOEXEC
value|MNT_NOEXEC
end_define

begin_define
define|#
directive|define
name|VFS_HOLD
parameter_list|(
name|vfsp
parameter_list|)
value|do {						\ 	MNT_ILOCK(vfsp);						\ 	MNT_REF(vfsp);							\ 	MNT_IUNLOCK(vfsp);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|VFS_RELE
parameter_list|(
name|vfsp
parameter_list|)
value|do {						\ 	MNT_ILOCK(vfsp);						\ 	MNT_REL(vfsp);							\ 	MNT_IUNLOCK(vfsp);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|VROOT
value|VV_ROOT
end_define

begin_comment
comment|/*  * Structure defining a mount option for a filesystem.  * option names are found in mntent.h  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mntopt
block|{
name|char
modifier|*
name|mo_name
decl_stmt|;
comment|/* option name */
name|char
modifier|*
modifier|*
name|mo_cancel
decl_stmt|;
comment|/* list of options cancelled by this one */
name|char
modifier|*
name|mo_arg
decl_stmt|;
comment|/* argument string for this option */
name|int
name|mo_flags
decl_stmt|;
comment|/* flags for this mount option */
name|void
modifier|*
name|mo_data
decl_stmt|;
comment|/* filesystem specific data */
block|}
name|mntopt_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flags that apply to mount options  */
end_comment

begin_define
define|#
directive|define
name|MO_SET
value|0x01
end_define

begin_comment
comment|/* option is set */
end_comment

begin_define
define|#
directive|define
name|MO_NODISPLAY
value|0x02
end_define

begin_comment
comment|/* option not listed in mnttab */
end_comment

begin_define
define|#
directive|define
name|MO_HASVALUE
value|0x04
end_define

begin_comment
comment|/* option takes a value */
end_comment

begin_define
define|#
directive|define
name|MO_IGNORE
value|0x08
end_define

begin_comment
comment|/* option ignored by parser */
end_comment

begin_define
define|#
directive|define
name|MO_DEFAULT
value|MO_SET
end_define

begin_comment
comment|/* option is on by default */
end_comment

begin_define
define|#
directive|define
name|MO_TAG
value|0x10
end_define

begin_comment
comment|/* flags a tag set by user program */
end_comment

begin_define
define|#
directive|define
name|MO_EMPTY
value|0x20
end_define

begin_comment
comment|/* empty space in option table */
end_comment

begin_define
define|#
directive|define
name|VFS_NOFORCEOPT
value|0x01
end_define

begin_comment
comment|/* honor MO_IGNORE (don't set option) */
end_comment

begin_define
define|#
directive|define
name|VFS_DISPLAY
value|0x02
end_define

begin_comment
comment|/* Turn off MO_NODISPLAY bit for opt */
end_comment

begin_define
define|#
directive|define
name|VFS_NODISPLAY
value|0x04
end_define

begin_comment
comment|/* Turn on MO_NODISPLAY bit for opt */
end_comment

begin_define
define|#
directive|define
name|VFS_CREATEOPT
value|0x08
end_define

begin_comment
comment|/* Create the opt if it's not there */
end_comment

begin_comment
comment|/*  * Structure holding mount option strings for the mounted file system.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mntopts
block|{
name|uint_t
name|mo_count
decl_stmt|;
comment|/* number of entries in table */
name|mntopt_t
modifier|*
name|mo_list
decl_stmt|;
comment|/* list of mount options */
block|}
name|mntopts_t
typedef|;
end_typedef

begin_function_decl
name|void
name|vfs_setmntopt
parameter_list|(
name|vfs_t
modifier|*
name|vfsp
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|arg
parameter_list|,
name|int
name|flags
name|__unused
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_clearmntopt
parameter_list|(
name|vfs_t
modifier|*
name|vfsp
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_optionisset
parameter_list|(
specifier|const
name|vfs_t
modifier|*
name|vfsp
parameter_list|,
specifier|const
name|char
modifier|*
name|opt
parameter_list|,
name|char
modifier|*
modifier|*
name|argp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|traverse
parameter_list|(
name|vnode_t
modifier|*
modifier|*
name|cvpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|domount
parameter_list|(
name|kthread_t
modifier|*
name|td
parameter_list|,
name|vnode_t
modifier|*
name|vp
parameter_list|,
specifier|const
name|char
modifier|*
name|fstype
parameter_list|,
name|char
modifier|*
name|fspath
parameter_list|,
name|char
modifier|*
name|fspec
parameter_list|,
name|int
name|fsflags
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
comment|/* _OPENSOLARIS_SYS_VFS_H_ */
end_comment

end_unit

