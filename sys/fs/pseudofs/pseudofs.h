begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Dag-Erling Coïdan Smørgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *      $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PSEUDOFS_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_PSEUDOFS_H_INCLUDED
end_define

begin_comment
comment|/*  * Opaque structures  */
end_comment

begin_struct_decl
struct_decl|struct
name|mntarg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nameidata
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|statfs
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vfsconf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Limits and constants  */
end_comment

begin_define
define|#
directive|define
name|PFS_NAMELEN
value|24
end_define

begin_define
define|#
directive|define
name|PFS_FSNAMELEN
value|16
end_define

begin_comment
comment|/* equal to MFSNAMELEN */
end_comment

begin_define
define|#
directive|define
name|PFS_DELEN
value|(8 + PFS_NAMELEN)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|pfstype_none
init|=
literal|0
block|,
name|pfstype_root
block|,
name|pfstype_dir
block|,
name|pfstype_this
block|,
name|pfstype_parent
block|,
name|pfstype_file
block|,
name|pfstype_symlink
block|,
name|pfstype_procdir
block|}
name|pfs_type_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flags  */
end_comment

begin_define
define|#
directive|define
name|PFS_RD
value|0x0001
end_define

begin_comment
comment|/* readable */
end_comment

begin_define
define|#
directive|define
name|PFS_WR
value|0x0002
end_define

begin_comment
comment|/* writeable */
end_comment

begin_define
define|#
directive|define
name|PFS_RDWR
value|(PFS_RD|PFS_WR)
end_define

begin_define
define|#
directive|define
name|PFS_RAWRD
value|0x0004
end_define

begin_comment
comment|/* raw reader */
end_comment

begin_define
define|#
directive|define
name|PFS_RAWWR
value|0x0008
end_define

begin_comment
comment|/* raw writer */
end_comment

begin_define
define|#
directive|define
name|PFS_RAW
value|(PFS_RAWRD|PFS_RAWWR)
end_define

begin_define
define|#
directive|define
name|PFS_PROCDEP
value|0x0010
end_define

begin_comment
comment|/* process-dependent */
end_comment

begin_define
define|#
directive|define
name|PFS_DISABLED
value|0x8000
end_define

begin_comment
comment|/* node is disabled */
end_comment

begin_comment
comment|/*  * Data structures  */
end_comment

begin_struct_decl
struct_decl|struct
name|pfs_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pfs_node
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pfs_bitmap
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Init / uninit callback  */
end_comment

begin_define
define|#
directive|define
name|PFS_INIT_ARGS
define|\
value|struct pfs_info *pi, struct vfsconf *vfc
end_define

begin_define
define|#
directive|define
name|PFS_INIT_PROTO
parameter_list|(
name|name
parameter_list|)
define|\
value|int name(PFS_INIT_ARGS);
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pfs_init_t
function_decl|)
parameter_list|(
name|PFS_INIT_ARGS
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Filler callback  */
end_comment

begin_define
define|#
directive|define
name|PFS_FILL_ARGS
define|\
value|struct thread *td, struct proc *p, struct pfs_node *pn, \ 	struct sbuf *sb, struct uio *uio
end_define

begin_define
define|#
directive|define
name|PFS_FILL_PROTO
parameter_list|(
name|name
parameter_list|)
define|\
value|int name(PFS_FILL_ARGS);
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pfs_fill_t
function_decl|)
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Attribute callback  */
end_comment

begin_struct_decl
struct_decl|struct
name|vattr
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|PFS_ATTR_ARGS
define|\
value|struct thread *td, struct proc *p, struct pfs_node *pn, \ 	struct vattr *vap
end_define

begin_define
define|#
directive|define
name|PFS_ATTR_PROTO
parameter_list|(
name|name
parameter_list|)
define|\
value|int name(PFS_ATTR_ARGS);
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pfs_attr_t
function_decl|)
parameter_list|(
name|PFS_ATTR_ARGS
parameter_list|)
function_decl|;
end_typedef

begin_struct_decl
struct_decl|struct
name|pfs_bitmap
struct_decl|;
end_struct_decl

begin_comment
comment|/* opaque */
end_comment

begin_comment
comment|/*  * Visibility callback  */
end_comment

begin_define
define|#
directive|define
name|PFS_VIS_ARGS
define|\
value|struct thread *td, struct proc *p, struct pfs_node *pn
end_define

begin_define
define|#
directive|define
name|PFS_VIS_PROTO
parameter_list|(
name|name
parameter_list|)
define|\
value|int name(PFS_VIS_ARGS);
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pfs_vis_t
function_decl|)
parameter_list|(
name|PFS_VIS_ARGS
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Ioctl callback  */
end_comment

begin_define
define|#
directive|define
name|PFS_IOCTL_ARGS
define|\
value|struct thread *td, struct proc *p, struct pfs_node *pn, \ 	unsigned long cmd, void *data
end_define

begin_define
define|#
directive|define
name|PFS_IOCTL_PROTO
parameter_list|(
name|name
parameter_list|)
define|\
value|int name(PFS_IOCTL_ARGS);
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pfs_ioctl_t
function_decl|)
parameter_list|(
name|PFS_IOCTL_ARGS
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Getextattr callback  */
end_comment

begin_define
define|#
directive|define
name|PFS_GETEXTATTR_ARGS
define|\
value|struct thread *td, struct proc *p, struct pfs_node *pn, \ 	int attrnamespace, const char *name, struct uio *uio,	\ 	size_t *size, struct ucred *cred
end_define

begin_define
define|#
directive|define
name|PFS_GETEXTATTR_PROTO
parameter_list|(
name|name
parameter_list|)
define|\
value|int name(PFS_GETEXTATTR_ARGS);
end_define

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pfs_getextattr_t
function_decl|)
parameter_list|(
name|PFS_GETEXTATTR_ARGS
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Last-close callback  */
end_comment

begin_define
define|#
directive|define
name|PFS_CLOSE_ARGS
define|\
value|struct thread *td, struct proc *p, struct pfs_node *pn
end_define

begin_define
define|#
directive|define
name|PFS_CLOSE_PROTO
parameter_list|(
name|name
parameter_list|)
define|\
value|int name(PFS_CLOSE_ARGS);
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pfs_close_t
function_decl|)
parameter_list|(
name|PFS_CLOSE_ARGS
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Destroy callback  */
end_comment

begin_define
define|#
directive|define
name|PFS_DESTROY_ARGS
define|\
value|struct pfs_node *pn
end_define

begin_define
define|#
directive|define
name|PFS_DESTROY_PROTO
parameter_list|(
name|name
parameter_list|)
define|\
value|int name(PFS_DESTROY_ARGS);
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pfs_destroy_t
function_decl|)
parameter_list|(
name|PFS_DESTROY_ARGS
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * pfs_info: describes a pseudofs instance  */
end_comment

begin_struct
struct|struct
name|pfs_info
block|{
name|char
name|pi_name
index|[
name|PFS_FSNAMELEN
index|]
decl_stmt|;
name|pfs_init_t
name|pi_init
decl_stmt|;
name|pfs_init_t
name|pi_uninit
decl_stmt|;
comment|/* members below this line aren't initialized */
name|struct
name|pfs_node
modifier|*
name|pi_root
decl_stmt|;
comment|/* currently, the mutex is only used to protect the bitmap */
name|struct
name|mtx
name|pi_mutex
decl_stmt|;
name|struct
name|unrhdr
modifier|*
name|pi_unrhdr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * pfs_node: describes a node (file or directory) within a pseudofs  */
end_comment

begin_struct
struct|struct
name|pfs_node
block|{
name|char
name|pn_name
index|[
name|PFS_NAMELEN
index|]
decl_stmt|;
name|pfs_type_t
name|pn_type
decl_stmt|;
union|union
block|{
name|void
modifier|*
name|_pn_dummy
decl_stmt|;
name|pfs_fill_t
name|_pn_func
decl_stmt|;
name|struct
name|pfs_node
modifier|*
name|_pn_nodes
decl_stmt|;
block|}
name|u1
union|;
define|#
directive|define
name|pn_func
value|u1._pn_func
define|#
directive|define
name|pn_nodes
value|u1._pn_nodes
name|pfs_ioctl_t
name|pn_ioctl
decl_stmt|;
name|pfs_close_t
name|pn_close
decl_stmt|;
name|pfs_attr_t
name|pn_attr
decl_stmt|;
name|pfs_vis_t
name|pn_vis
decl_stmt|;
name|pfs_getextattr_t
name|pn_getextattr
decl_stmt|;
name|pfs_destroy_t
name|pn_destroy
decl_stmt|;
name|void
modifier|*
name|pn_data
decl_stmt|;
name|int
name|pn_flags
decl_stmt|;
name|struct
name|pfs_info
modifier|*
name|pn_info
decl_stmt|;
name|struct
name|pfs_node
modifier|*
name|pn_parent
decl_stmt|;
name|struct
name|pfs_node
modifier|*
name|pn_next
decl_stmt|;
name|u_int32_t
name|pn_fileno
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * VFS interface  */
end_comment

begin_function_decl
name|int
name|pfs_mount
parameter_list|(
name|struct
name|pfs_info
modifier|*
name|pi
parameter_list|,
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfs_cmount
parameter_list|(
name|struct
name|mntarg
modifier|*
name|ma
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfs_unmount
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|int
name|mntflags
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfs_root
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfs_statfs
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|statfs
modifier|*
name|sbp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfs_init
parameter_list|(
name|struct
name|pfs_info
modifier|*
name|pi
parameter_list|,
name|struct
name|vfsconf
modifier|*
name|vfc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfs_uninit
parameter_list|(
name|struct
name|pfs_info
modifier|*
name|pi
parameter_list|,
name|struct
name|vfsconf
modifier|*
name|vfc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Directory structure construction and manipulation  */
end_comment

begin_function_decl
name|struct
name|pfs_node
modifier|*
name|pfs_create_dir
parameter_list|(
name|struct
name|pfs_node
modifier|*
name|parent
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|pfs_attr_t
name|attr
parameter_list|,
name|pfs_vis_t
name|vis
parameter_list|,
name|pfs_destroy_t
name|destroy
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pfs_node
modifier|*
name|pfs_create_file
parameter_list|(
name|struct
name|pfs_node
modifier|*
name|parent
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|pfs_fill_t
name|fill
parameter_list|,
name|pfs_attr_t
name|attr
parameter_list|,
name|pfs_vis_t
name|vis
parameter_list|,
name|pfs_destroy_t
name|destroy
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pfs_node
modifier|*
name|pfs_create_link
parameter_list|(
name|struct
name|pfs_node
modifier|*
name|parent
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|pfs_fill_t
name|fill
parameter_list|,
name|pfs_attr_t
name|attr
parameter_list|,
name|pfs_vis_t
name|vis
parameter_list|,
name|pfs_destroy_t
name|destroy
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pfs_node
modifier|*
name|pfs_find_node
parameter_list|(
name|struct
name|pfs_node
modifier|*
name|parent
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfs_purge
parameter_list|(
name|struct
name|pfs_node
modifier|*
name|pn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfs_disable
parameter_list|(
name|struct
name|pfs_node
modifier|*
name|pn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfs_enable
parameter_list|(
name|struct
name|pfs_node
modifier|*
name|pn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfs_destroy
parameter_list|(
name|struct
name|pfs_node
modifier|*
name|pn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Now for some initialization magic...  */
end_comment

begin_define
define|#
directive|define
name|PSEUDOFS
parameter_list|(
name|name
parameter_list|,
name|version
parameter_list|)
define|\ 									\
value|static struct pfs_info name##_info = {					\ 	#name,								\ 	name##_init,							\ 	name##_uninit,							\ };									\ 									\ static int								\ _##name##_mount(struct mount *mp, struct thread *td) {			\ 	return pfs_mount(&name##_info, mp, td);				\ }									\ 									\ static int								\ _##name##_init(struct vfsconf *vfc) {					\ 	return pfs_init(&name##_info, vfc);				\ }									\ 									\ static int								\ _##name##_uninit(struct vfsconf *vfc) {					\ 	return pfs_uninit(&name##_info, vfc);				\ }									\ 									\ static struct vfsops name##_vfsops = {					\ 	.vfs_cmount =		pfs_cmount,				\ 	.vfs_init =		_##name##_init,				\ 	.vfs_mount =		_##name##_mount,			\ 	.vfs_root =		pfs_root,				\ 	.vfs_statfs =		pfs_statfs,				\ 	.vfs_uninit =		_##name##_uninit,			\ 	.vfs_unmount =		pfs_unmount,				\ };									\ VFS_SET(name##_vfsops, name, VFCF_SYNTHETIC);				\ MODULE_VERSION(name, version);						\ MODULE_DEPEND(name, pseudofs, 1, 1, 1);
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

