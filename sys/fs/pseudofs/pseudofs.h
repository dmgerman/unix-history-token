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

begin_define
define|#
directive|define
name|PFS_FILL_ARGS
define|\
value|struct proc *curp, struct proc *p, struct pfs_node *pn, struct sbuf *sb
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

begin_struct_decl
struct_decl|struct
name|pfs_bitmap
struct_decl|;
end_struct_decl

begin_comment
comment|/* opaque */
end_comment

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
name|MFSNAMELEN
index|]
decl_stmt|;
name|struct
name|pfs_node
modifier|*
name|pi_root
decl_stmt|;
comment|/* members below this line aren't initialized */
comment|/* currently, the mutex is only used to protect the bitmap */
name|struct
name|mtx
name|pi_mutex
decl_stmt|;
name|struct
name|pfs_bitmap
modifier|*
name|pi_bitmap
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
name|int
name|pn_flags
decl_stmt|;
name|uid_t
name|pn_uid
decl_stmt|;
name|gid_t
name|pn_gid
decl_stmt|;
name|mode_t
name|pn_mode
decl_stmt|;
union|union
block|{
name|void
modifier|*
name|_pn_data
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
name|pn_data
value|u1._pn_data
define|#
directive|define
name|pn_func
value|u1._pn_func
define|#
directive|define
name|pn_nodes
value|u1._pn_nodes
comment|/* members below this line aren't initialized */
name|struct
name|pfs_node
modifier|*
name|pn_parent
decl_stmt|;
name|u_int32_t
name|pn_fileno
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PFS_NODE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|,
name|flags
parameter_list|,
name|uid
parameter_list|,
name|gid
parameter_list|,
name|mode
parameter_list|,
name|data
parameter_list|)
define|\
value|{ (name), (type), (flags), (uid), (gid), (mode), { (data) } }
end_define

begin_define
define|#
directive|define
name|PFS_DIR
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|uid
parameter_list|,
name|gid
parameter_list|,
name|mode
parameter_list|,
name|nodes
parameter_list|)
define|\
value|PFS_NODE(name, pfstype_dir, flags, uid, gid, mode, nodes)
end_define

begin_define
define|#
directive|define
name|PFS_ROOT
parameter_list|(
name|nodes
parameter_list|)
define|\
value|PFS_NODE("/", pfstype_root, 0, 0, 0, 0555, nodes)
end_define

begin_define
define|#
directive|define
name|PFS_THIS
define|\
value|PFS_NODE(".", pfstype_this, 0, 0, 0, 0, NULL)
end_define

begin_define
define|#
directive|define
name|PFS_PARENT
define|\
value|PFS_NODE("..", pfstype_parent, 0, 0, 0, 0, NULL)
end_define

begin_define
define|#
directive|define
name|PFS_FILE
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|uid
parameter_list|,
name|gid
parameter_list|,
name|mode
parameter_list|,
name|func
parameter_list|)
define|\
value|PFS_NODE(name, pfstype_file, flags, uid, gid, mode, func)
end_define

begin_define
define|#
directive|define
name|PFS_SYMLINK
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|uid
parameter_list|,
name|gid
parameter_list|,
name|mode
parameter_list|,
name|func
parameter_list|)
define|\
value|PFS_NODE(name, pfstype_symlink, flags, uid, gid, mode, func)
end_define

begin_define
define|#
directive|define
name|PFS_PROCDIR
parameter_list|(
name|flags
parameter_list|,
name|uid
parameter_list|,
name|gid
parameter_list|,
name|mode
parameter_list|,
name|nodes
parameter_list|)
define|\
value|PFS_NODE("", pfstype_procdir, flags, 0, uid, gid, mode, nodes)
end_define

begin_define
define|#
directive|define
name|PFS_LASTNODE
define|\
value|PFS_NODE("", pfstype_none, 0, 0, 0, 0, NULL)
end_define

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
name|char
modifier|*
name|path
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|struct
name|nameidata
modifier|*
name|ndp
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
name|proc
modifier|*
name|p
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
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
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
name|proc
modifier|*
name|p
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
comment|/*  * Now for some initialization magic...  */
end_comment

begin_define
define|#
directive|define
name|PSEUDOFS
parameter_list|(
name|name
parameter_list|,
name|root
parameter_list|)
define|\ 									\
value|static struct pfs_info name##_info = {					\ 	#name,								\&(root)								\ };									\ 									\ static int								\ _##name##_mount(struct mount *mp, char *path, caddr_t data,		\ 	     struct nameidata *ndp, struct proc *p) {			\         return pfs_mount(&name##_info, mp, path, data, ndp, p);		\ }									\ 									\ static int								\ _##name##_init(struct vfsconf *vfc) {					\         return pfs_init(&name##_info, vfc);				\ }									\ 									\ static int								\ _##name##_uninit(struct vfsconf *vfc) {					\         return pfs_uninit(&name##_info, vfc);				\ }									\ 									\ static struct vfsops testfs_vfsops = {					\ 	_##name##_mount,						\ 	vfs_stdstart,							\ 	pfs_unmount,							\ 	pfs_root,							\ 	vfs_stdquotactl,						\ 	pfs_statfs,							\ 	vfs_stdsync,							\ 	vfs_stdvget,							\ 	vfs_stdfhtovp,							\ 	vfs_stdcheckexp,						\ 	vfs_stdvptofh,							\ 	_##name##_init,							\ 	_##name##_uninit,						\ 	vfs_stdextattrctl,						\ };									\ VFS_SET(name##_vfsops, name, VFCF_SYNTHETIC);				\ MODULE_DEPEND(name, pseudofs, 1, 1, 1);
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

