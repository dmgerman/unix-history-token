begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)vnode_if.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * This file should be automatically generated from a corresponding .int file.  */
end_comment

begin_struct
struct|struct
name|vop_lookup_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_dvp
decl_stmt|;
name|struct
name|vnode
modifier|*
modifier|*
name|a_vpp
decl_stmt|;
name|struct
name|componentname
modifier|*
name|a_cnp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_lookup_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_LOOKUP
value|struct vop_lookup_args vop_lookup_a
end_define

begin_define
define|#
directive|define
name|VOP_LOOKUP
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|)
define|\
value|( vop_lookup_a.a_desc = VDESC(vop_lookup), \ 		vop_lookup_a.a_dvp=(A0), \ 		vop_lookup_a.a_vpp=(A1), \ 		vop_lookup_a.a_cnp=(A2), \ 		(VCALL((A0),VOFFSET(vop_lookup),&vop_lookup_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_create_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_dvp
decl_stmt|;
name|struct
name|vnode
modifier|*
modifier|*
name|a_vpp
decl_stmt|;
name|struct
name|componentname
modifier|*
name|a_cnp
decl_stmt|;
name|struct
name|vattr
modifier|*
name|a_vap
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_create_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_CREATE
value|struct vop_create_args vop_create_a
end_define

begin_define
define|#
directive|define
name|VOP_CREATE
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_create_a.a_desc = VDESC(vop_create), \ 		vop_create_a.a_dvp=(A0), \ 		vop_create_a.a_vpp=(A1), \ 		vop_create_a.a_cnp=(A2), \ 		vop_create_a.a_vap=(A3), \ 		(VCALL((A0),VOFFSET(vop_create),&vop_create_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_mknod_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_dvp
decl_stmt|;
name|struct
name|vnode
modifier|*
modifier|*
name|a_vpp
decl_stmt|;
name|struct
name|componentname
modifier|*
name|a_cnp
decl_stmt|;
name|struct
name|vattr
modifier|*
name|a_vap
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_mknod_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_MKNOD
value|struct vop_mknod_args vop_mknod_a
end_define

begin_define
define|#
directive|define
name|VOP_MKNOD
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_mknod_a.a_desc = VDESC(vop_mknod), \ 		vop_mknod_a.a_dvp=(A0), \ 		vop_mknod_a.a_vpp=(A1), \ 		vop_mknod_a.a_cnp=(A2), \ 		vop_mknod_a.a_vap=(A3), \ 		(VCALL((A0),VOFFSET(vop_mknod),&vop_mknod_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_open_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|int
name|a_mode
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
name|struct
name|proc
modifier|*
name|a_p
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_open_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_OPEN
value|struct vop_open_args vop_open_a
end_define

begin_define
define|#
directive|define
name|VOP_OPEN
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_open_a.a_desc = VDESC(vop_open), \ 		vop_open_a.a_vp=(A0), \ 		vop_open_a.a_mode=(A1), \ 		vop_open_a.a_cred=(A2), \ 		vop_open_a.a_p=(A3), \ 		(VCALL((A0),VOFFSET(vop_open),&vop_open_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_close_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|int
name|a_fflag
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
name|struct
name|proc
modifier|*
name|a_p
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_close_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_CLOSE
value|struct vop_close_args vop_close_a
end_define

begin_define
define|#
directive|define
name|VOP_CLOSE
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_close_a.a_desc = VDESC(vop_close), \ 		vop_close_a.a_vp=(A0), \ 		vop_close_a.a_fflag=(A1), \ 		vop_close_a.a_cred=(A2), \ 		vop_close_a.a_p=(A3), \ 		(VCALL((A0),VOFFSET(vop_close),&vop_close_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_access_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|int
name|a_mode
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
name|struct
name|proc
modifier|*
name|a_p
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_access_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_ACCESS
value|struct vop_access_args vop_access_a
end_define

begin_define
define|#
directive|define
name|VOP_ACCESS
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_access_a.a_desc = VDESC(vop_access), \ 		vop_access_a.a_vp=(A0), \ 		vop_access_a.a_mode=(A1), \ 		vop_access_a.a_cred=(A2), \ 		vop_access_a.a_p=(A3), \ 		(VCALL((A0),VOFFSET(vop_access),&vop_access_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_getattr_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|struct
name|vattr
modifier|*
name|a_vap
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
name|struct
name|proc
modifier|*
name|a_p
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_getattr_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_GETATTR
value|struct vop_getattr_args vop_getattr_a
end_define

begin_define
define|#
directive|define
name|VOP_GETATTR
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_getattr_a.a_desc = VDESC(vop_getattr), \ 		vop_getattr_a.a_vp=(A0), \ 		vop_getattr_a.a_vap=(A1), \ 		vop_getattr_a.a_cred=(A2), \ 		vop_getattr_a.a_p=(A3), \ 		(VCALL((A0),VOFFSET(vop_getattr),&vop_getattr_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_setattr_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|struct
name|vattr
modifier|*
name|a_vap
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
name|struct
name|proc
modifier|*
name|a_p
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_setattr_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_SETATTR
value|struct vop_setattr_args vop_setattr_a
end_define

begin_define
define|#
directive|define
name|VOP_SETATTR
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_setattr_a.a_desc = VDESC(vop_setattr), \ 		vop_setattr_a.a_vp=(A0), \ 		vop_setattr_a.a_vap=(A1), \ 		vop_setattr_a.a_cred=(A2), \ 		vop_setattr_a.a_p=(A3), \ 		(VCALL((A0),VOFFSET(vop_setattr),&vop_setattr_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_read_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|struct
name|uio
modifier|*
name|a_uio
decl_stmt|;
name|int
name|a_ioflag
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_read_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_READ
value|struct vop_read_args vop_read_a
end_define

begin_define
define|#
directive|define
name|VOP_READ
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_read_a.a_desc = VDESC(vop_read), \ 		vop_read_a.a_vp=(A0), \ 		vop_read_a.a_uio=(A1), \ 		vop_read_a.a_ioflag=(A2), \ 		vop_read_a.a_cred=(A3), \ 		(VCALL((A0),VOFFSET(vop_read),&vop_read_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_write_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|struct
name|uio
modifier|*
name|a_uio
decl_stmt|;
name|int
name|a_ioflag
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_write_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_WRITE
value|struct vop_write_args vop_write_a
end_define

begin_define
define|#
directive|define
name|VOP_WRITE
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_write_a.a_desc = VDESC(vop_write), \ 		vop_write_a.a_vp=(A0), \ 		vop_write_a.a_uio=(A1), \ 		vop_write_a.a_ioflag=(A2), \ 		vop_write_a.a_cred=(A3), \ 		(VCALL((A0),VOFFSET(vop_write),&vop_write_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_ioctl_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|int
name|a_command
decl_stmt|;
name|caddr_t
name|a_data
decl_stmt|;
name|int
name|a_fflag
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
name|struct
name|proc
modifier|*
name|a_p
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_ioctl_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_IOCTL
value|struct vop_ioctl_args vop_ioctl_a
end_define

begin_define
define|#
directive|define
name|VOP_IOCTL
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|,
name|A4
parameter_list|,
name|A5
parameter_list|)
define|\
value|( vop_ioctl_a.a_desc = VDESC(vop_ioctl), \ 		vop_ioctl_a.a_vp=(A0), \ 		vop_ioctl_a.a_command=(A1), \ 		vop_ioctl_a.a_data=(A2), \ 		vop_ioctl_a.a_fflag=(A3), \ 		vop_ioctl_a.a_cred=(A4), \ 		vop_ioctl_a.a_p=(A5), \ 		(VCALL((A0),VOFFSET(vop_ioctl),&vop_ioctl_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_select_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|int
name|a_which
decl_stmt|;
name|int
name|a_fflags
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
name|struct
name|proc
modifier|*
name|a_p
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_select_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_SELECT
value|struct vop_select_args vop_select_a
end_define

begin_define
define|#
directive|define
name|VOP_SELECT
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|,
name|A4
parameter_list|)
define|\
value|( vop_select_a.a_desc = VDESC(vop_select), \ 		vop_select_a.a_vp=(A0), \ 		vop_select_a.a_which=(A1), \ 		vop_select_a.a_fflags=(A2), \ 		vop_select_a.a_cred=(A3), \ 		vop_select_a.a_p=(A4), \ 		(VCALL((A0),VOFFSET(vop_select),&vop_select_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_mmap_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|int
name|a_fflags
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
name|struct
name|proc
modifier|*
name|a_p
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_mmap_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_MMAP
value|struct vop_mmap_args vop_mmap_a
end_define

begin_define
define|#
directive|define
name|VOP_MMAP
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_mmap_a.a_desc = VDESC(vop_mmap), \ 		vop_mmap_a.a_vp=(A0), \ 		vop_mmap_a.a_fflags=(A1), \ 		vop_mmap_a.a_cred=(A2), \ 		vop_mmap_a.a_p=(A3), \ 		(VCALL((A0),VOFFSET(vop_mmap),&vop_mmap_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_fsync_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
name|int
name|a_waitfor
decl_stmt|;
name|struct
name|proc
modifier|*
name|a_p
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_fsync_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_FSYNC
value|struct vop_fsync_args vop_fsync_a
end_define

begin_define
define|#
directive|define
name|VOP_FSYNC
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_fsync_a.a_desc = VDESC(vop_fsync), \ 		vop_fsync_a.a_vp=(A0), \ 		vop_fsync_a.a_cred=(A1), \ 		vop_fsync_a.a_waitfor=(A2), \ 		vop_fsync_a.a_p=(A3), \ 		(VCALL((A0),VOFFSET(vop_fsync),&vop_fsync_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_seek_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|off_t
name|a_oldoff
decl_stmt|;
name|off_t
name|a_newoff
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_seek_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_SEEK
value|struct vop_seek_args vop_seek_a
end_define

begin_define
define|#
directive|define
name|VOP_SEEK
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_seek_a.a_desc = VDESC(vop_seek), \ 		vop_seek_a.a_vp=(A0), \ 		vop_seek_a.a_oldoff=(A1), \ 		vop_seek_a.a_newoff=(A2), \ 		vop_seek_a.a_cred=(A3), \ 		(VCALL((A0),VOFFSET(vop_seek),&vop_seek_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_remove_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_dvp
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|struct
name|componentname
modifier|*
name|a_cnp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_remove_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_REMOVE
value|struct vop_remove_args vop_remove_a
end_define

begin_define
define|#
directive|define
name|VOP_REMOVE
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|)
define|\
value|( vop_remove_a.a_desc = VDESC(vop_remove), \ 		vop_remove_a.a_dvp=(A0), \ 		vop_remove_a.a_vp=(A1), \ 		vop_remove_a.a_cnp=(A2), \ 		(VCALL((A0),VOFFSET(vop_remove),&vop_remove_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_link_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_tdvp
decl_stmt|;
name|struct
name|componentname
modifier|*
name|a_cnp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_link_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_LINK
value|struct vop_link_args vop_link_a
end_define

begin_define
define|#
directive|define
name|VOP_LINK
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|)
define|\
value|( vop_link_a.a_desc = VDESC(vop_link), \ 		vop_link_a.a_vp=(A0), \ 		vop_link_a.a_tdvp=(A1), \ 		vop_link_a.a_cnp=(A2), \ 		(VCALL((A0),VOFFSET(vop_link),&vop_link_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_rename_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_fdvp
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_fvp
decl_stmt|;
name|struct
name|componentname
modifier|*
name|a_fcnp
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_tdvp
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_tvp
decl_stmt|;
name|struct
name|componentname
modifier|*
name|a_tcnp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_rename_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_RENAME
value|struct vop_rename_args vop_rename_a
end_define

begin_define
define|#
directive|define
name|VOP_RENAME
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|,
name|A4
parameter_list|,
name|A5
parameter_list|)
define|\
value|( vop_rename_a.a_desc = VDESC(vop_rename), \ 		vop_rename_a.a_fdvp=(A0), \ 		vop_rename_a.a_fvp=(A1), \ 		vop_rename_a.a_fcnp=(A2), \ 		vop_rename_a.a_tdvp=(A3), \ 		vop_rename_a.a_tvp=(A4), \ 		vop_rename_a.a_tcnp=(A5), \ 		(VCALL((A0),VOFFSET(vop_rename),&vop_rename_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_mkdir_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_dvp
decl_stmt|;
name|struct
name|vnode
modifier|*
modifier|*
name|a_vpp
decl_stmt|;
name|struct
name|componentname
modifier|*
name|a_cnp
decl_stmt|;
name|struct
name|vattr
modifier|*
name|a_vap
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_mkdir_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_MKDIR
value|struct vop_mkdir_args vop_mkdir_a
end_define

begin_define
define|#
directive|define
name|VOP_MKDIR
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_mkdir_a.a_desc = VDESC(vop_mkdir), \ 		vop_mkdir_a.a_dvp=(A0), \ 		vop_mkdir_a.a_vpp=(A1), \ 		vop_mkdir_a.a_cnp=(A2), \ 		vop_mkdir_a.a_vap=(A3), \ 		(VCALL((A0),VOFFSET(vop_mkdir),&vop_mkdir_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_rmdir_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_dvp
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|struct
name|componentname
modifier|*
name|a_cnp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_rmdir_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_RMDIR
value|struct vop_rmdir_args vop_rmdir_a
end_define

begin_define
define|#
directive|define
name|VOP_RMDIR
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|)
define|\
value|( vop_rmdir_a.a_desc = VDESC(vop_rmdir), \ 		vop_rmdir_a.a_dvp=(A0), \ 		vop_rmdir_a.a_vp=(A1), \ 		vop_rmdir_a.a_cnp=(A2), \ 		(VCALL((A0),VOFFSET(vop_rmdir),&vop_rmdir_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_symlink_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_dvp
decl_stmt|;
name|struct
name|vnode
modifier|*
modifier|*
name|a_vpp
decl_stmt|;
name|struct
name|componentname
modifier|*
name|a_cnp
decl_stmt|;
name|struct
name|vattr
modifier|*
name|a_vap
decl_stmt|;
name|char
modifier|*
name|a_target
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_symlink_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_SYMLINK
value|struct vop_symlink_args vop_symlink_a
end_define

begin_define
define|#
directive|define
name|VOP_SYMLINK
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|,
name|A4
parameter_list|)
define|\
value|( vop_symlink_a.a_desc = VDESC(vop_symlink), \ 		vop_symlink_a.a_dvp=(A0), \ 		vop_symlink_a.a_vpp=(A1), \ 		vop_symlink_a.a_cnp=(A2), \ 		vop_symlink_a.a_vap=(A3), \ 		vop_symlink_a.a_target=(A4), \ 		(VCALL((A0),VOFFSET(vop_symlink),&vop_symlink_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_readdir_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|struct
name|uio
modifier|*
name|a_uio
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_readdir_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_READDIR
value|struct vop_readdir_args vop_readdir_a
end_define

begin_define
define|#
directive|define
name|VOP_READDIR
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|)
define|\
value|( vop_readdir_a.a_desc = VDESC(vop_readdir), \ 		vop_readdir_a.a_vp=(A0), \ 		vop_readdir_a.a_uio=(A1), \ 		vop_readdir_a.a_cred=(A2), \ 		(VCALL((A0),VOFFSET(vop_readdir),&vop_readdir_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_readlink_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|struct
name|uio
modifier|*
name|a_uio
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_readlink_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_READLINK
value|struct vop_readlink_args vop_readlink_a
end_define

begin_define
define|#
directive|define
name|VOP_READLINK
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|)
define|\
value|( vop_readlink_a.a_desc = VDESC(vop_readlink), \ 		vop_readlink_a.a_vp=(A0), \ 		vop_readlink_a.a_uio=(A1), \ 		vop_readlink_a.a_cred=(A2), \ 		(VCALL((A0),VOFFSET(vop_readlink),&vop_readlink_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_abortop_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_dvp
decl_stmt|;
name|struct
name|componentname
modifier|*
name|a_cnp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_abortop_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_ABORTOP
value|struct vop_abortop_args vop_abortop_a
end_define

begin_define
define|#
directive|define
name|VOP_ABORTOP
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|)
define|\
value|( vop_abortop_a.a_desc = VDESC(vop_abortop), \ 		vop_abortop_a.a_dvp=(A0), \ 		vop_abortop_a.a_cnp=(A1), \ 		(VCALL((A0),VOFFSET(vop_abortop),&vop_abortop_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_inactive_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_inactive_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_INACTIVE
value|struct vop_inactive_args vop_inactive_a
end_define

begin_define
define|#
directive|define
name|VOP_INACTIVE
parameter_list|(
name|A0
parameter_list|)
define|\
value|( vop_inactive_a.a_desc = VDESC(vop_inactive), \ 		vop_inactive_a.a_vp=(A0), \ 		(VCALL((A0),VOFFSET(vop_inactive),&vop_inactive_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_reclaim_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_reclaim_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_RECLAIM
value|struct vop_reclaim_args vop_reclaim_a
end_define

begin_define
define|#
directive|define
name|VOP_RECLAIM
parameter_list|(
name|A0
parameter_list|)
define|\
value|( vop_reclaim_a.a_desc = VDESC(vop_reclaim), \ 		vop_reclaim_a.a_vp=(A0), \ 		(VCALL((A0),VOFFSET(vop_reclaim),&vop_reclaim_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_lock_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_lock_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_LOCK
value|struct vop_lock_args vop_lock_a
end_define

begin_define
define|#
directive|define
name|VOP_LOCK
parameter_list|(
name|A0
parameter_list|)
define|\
value|( vop_lock_a.a_desc = VDESC(vop_lock), \ 		vop_lock_a.a_vp=(A0), \ 		(VCALL((A0),VOFFSET(vop_lock),&vop_lock_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_unlock_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_unlock_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_UNLOCK
value|struct vop_unlock_args vop_unlock_a
end_define

begin_define
define|#
directive|define
name|VOP_UNLOCK
parameter_list|(
name|A0
parameter_list|)
define|\
value|( vop_unlock_a.a_desc = VDESC(vop_unlock), \ 		vop_unlock_a.a_vp=(A0), \ 		(VCALL((A0),VOFFSET(vop_unlock),&vop_unlock_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_bmap_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|daddr_t
name|a_bn
decl_stmt|;
name|struct
name|vnode
modifier|*
modifier|*
name|a_vpp
decl_stmt|;
name|daddr_t
modifier|*
name|a_bnp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_bmap_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_BMAP
value|struct vop_bmap_args vop_bmap_a
end_define

begin_define
define|#
directive|define
name|VOP_BMAP
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_bmap_a.a_desc = VDESC(vop_bmap), \ 		vop_bmap_a.a_vp=(A0), \ 		vop_bmap_a.a_bn=(A1), \ 		vop_bmap_a.a_vpp=(A2), \ 		vop_bmap_a.a_bnp=(A3), \ 		(VCALL((A0),VOFFSET(vop_bmap),&vop_bmap_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_strategy_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|buf
modifier|*
name|a_bp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_strategy_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_STRATEGY
value|struct vop_strategy_args vop_strategy_a
end_define

begin_define
define|#
directive|define
name|VOP_STRATEGY
parameter_list|(
name|A0
parameter_list|)
define|\
value|( vop_strategy_a.a_desc = VDESC(vop_strategy), \ 		vop_strategy_a.a_bp=(A0), \ 		(VCALL((A0),VOFFSET(vop_strategy),&vop_strategy_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_print_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_print_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_PRINT
value|struct vop_print_args vop_print_a
end_define

begin_define
define|#
directive|define
name|VOP_PRINT
parameter_list|(
name|A0
parameter_list|)
define|\
value|( vop_print_a.a_desc = VDESC(vop_print), \ 		vop_print_a.a_vp=(A0), \ 		(VCALL((A0),VOFFSET(vop_print),&vop_print_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_islocked_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_islocked_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_ISLOCKED
value|struct vop_islocked_args vop_islocked_a
end_define

begin_define
define|#
directive|define
name|VOP_ISLOCKED
parameter_list|(
name|A0
parameter_list|)
define|\
value|( vop_islocked_a.a_desc = VDESC(vop_islocked), \ 		vop_islocked_a.a_vp=(A0), \ 		(VCALL((A0),VOFFSET(vop_islocked),&vop_islocked_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_advlock_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|caddr_t
name|a_id
decl_stmt|;
name|int
name|a_op
decl_stmt|;
name|struct
name|flock
modifier|*
name|a_fl
decl_stmt|;
name|int
name|a_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_advlock_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_ADVLOCK
value|struct vop_advlock_args vop_advlock_a
end_define

begin_define
define|#
directive|define
name|VOP_ADVLOCK
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|,
name|A4
parameter_list|)
define|\
value|( vop_advlock_a.a_desc = VDESC(vop_advlock), \ 		vop_advlock_a.a_vp=(A0), \ 		vop_advlock_a.a_id=(A1), \ 		vop_advlock_a.a_op=(A2), \ 		vop_advlock_a.a_fl=(A3), \ 		vop_advlock_a.a_flags=(A4), \ 		(VCALL((A0),VOFFSET(vop_advlock),&vop_advlock_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_blkatoff_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|off_t
name|a_offset
decl_stmt|;
name|char
modifier|*
modifier|*
name|a_res
decl_stmt|;
name|struct
name|buf
modifier|*
modifier|*
name|a_bpp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_blkatoff_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_BLKATOFF
value|struct vop_blkatoff_args vop_blkatoff_a
end_define

begin_define
define|#
directive|define
name|VOP_BLKATOFF
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_blkatoff_a.a_desc = VDESC(vop_blkatoff), \ 		vop_blkatoff_a.a_vp=(A0), \ 		vop_blkatoff_a.a_offset=(A1), \ 		vop_blkatoff_a.a_res=(A2), \ 		vop_blkatoff_a.a_bpp=(A3), \ 		(VCALL((A0),VOFFSET(vop_blkatoff),&vop_blkatoff_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_vget_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|mount
modifier|*
name|a_mp
decl_stmt|;
name|ino_t
name|a_ino
decl_stmt|;
name|struct
name|vnode
modifier|*
modifier|*
name|a_vpp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_vget_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_VGET
value|struct vop_vget_args vop_vget_a
end_define

begin_define
define|#
directive|define
name|VOP_VGET
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|)
define|\
value|( vop_vget_a.a_desc = VDESC(vop_vget), \ 		vop_vget_a.a_mp=(A0), \ 		vop_vget_a.a_ino=(A1), \ 		vop_vget_a.a_vpp=(A2), \ 		(VCALL((A0),VOFFSET(vop_vget),&vop_vget_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_valloc_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_pvp
decl_stmt|;
name|int
name|a_mode
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
name|struct
name|vnode
modifier|*
modifier|*
name|a_vpp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_valloc_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_VALLOC
value|struct vop_valloc_args vop_valloc_a
end_define

begin_define
define|#
directive|define
name|VOP_VALLOC
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_valloc_a.a_desc = VDESC(vop_valloc), \ 		vop_valloc_a.a_pvp=(A0), \ 		vop_valloc_a.a_mode=(A1), \ 		vop_valloc_a.a_cred=(A2), \ 		vop_valloc_a.a_vpp=(A3), \ 		(VCALL((A0),VOFFSET(vop_valloc),&vop_valloc_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_vfree_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_pvp
decl_stmt|;
name|ino_t
name|a_ino
decl_stmt|;
name|int
name|a_mode
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_vfree_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_VFREE
value|struct vop_vfree_args vop_vfree_a
end_define

begin_define
define|#
directive|define
name|VOP_VFREE
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|)
define|\
value|( vop_vfree_a.a_desc = VDESC(vop_vfree), \ 		vop_vfree_a.a_pvp=(A0), \ 		vop_vfree_a.a_ino=(A1), \ 		vop_vfree_a.a_mode=(A2), \ 		(VCALL((A0),VOFFSET(vop_vfree),&vop_vfree_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_truncate_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|off_t
name|a_length
decl_stmt|;
name|int
name|a_flags
decl_stmt|;
name|struct
name|ucred
modifier|*
name|a_cred
decl_stmt|;
name|struct
name|proc
modifier|*
name|a_p
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_truncate_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_TRUNCATE
value|struct vop_truncate_args vop_truncate_a
end_define

begin_define
define|#
directive|define
name|VOP_TRUNCATE
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|,
name|A4
parameter_list|)
define|\
value|( vop_truncate_a.a_desc = VDESC(vop_truncate), \ 		vop_truncate_a.a_vp=(A0), \ 		vop_truncate_a.a_length=(A1), \ 		vop_truncate_a.a_flags=(A2), \ 		vop_truncate_a.a_cred=(A3), \ 		vop_truncate_a.a_p=(A4), \ 		(VCALL((A0),VOFFSET(vop_truncate),&vop_truncate_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_update_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|vnode
modifier|*
name|a_vp
decl_stmt|;
name|struct
name|timeval
modifier|*
name|a_ta
decl_stmt|;
name|struct
name|timeval
modifier|*
name|a_tm
decl_stmt|;
name|int
name|a_waitfor
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_update_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_UPDATE
value|struct vop_update_args vop_update_a
end_define

begin_define
define|#
directive|define
name|VOP_UPDATE
parameter_list|(
name|A0
parameter_list|,
name|A1
parameter_list|,
name|A2
parameter_list|,
name|A3
parameter_list|)
define|\
value|( vop_update_a.a_desc = VDESC(vop_update), \ 		vop_update_a.a_vp=(A0), \ 		vop_update_a.a_ta=(A1), \ 		vop_update_a.a_tm=(A2), \ 		vop_update_a.a_waitfor=(A3), \ 		(VCALL((A0),VOFFSET(vop_update),&vop_update_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_struct
struct|struct
name|vop_bwrite_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
name|struct
name|buf
modifier|*
name|a_bp
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_bwrite_desc
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_VOP_BWRITE
value|struct vop_bwrite_args vop_bwrite_a
end_define

begin_define
define|#
directive|define
name|VOP_BWRITE
parameter_list|(
name|A0
parameter_list|)
define|\
value|( vop_bwrite_a.a_desc = VDESC(vop_bwrite), \ 		vop_bwrite_a.a_bp=(A0), \ 		(VCALL((A0),VOFFSET(vop_bwrite),&vop_bwrite_a)))
end_define

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_comment
comment|/* BEGIN VERBATIM H */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_default_desc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* END VERBATIM H */
end_comment

begin_comment
comment|/* This is automatically generated.  Modify the corresponding .int file. */
end_comment

begin_comment
comment|/* BEGIN VERBATIM H */
end_comment

begin_comment
comment|/*  * Three existing BSD vnodeops (strategy, vget and bwrite)  * don't take any vnodes as arguments.  * This means that these operations will never function successfully  * through a bypass routine.  * Both these operations are going away (right, Kirk?):  *    vget will become a vfs operation  *    bwrite and strategy  *	will be replaced with an integrated VM page/buffer cache.  *  * To get around this problem for now we handle  * these ops as special cases.  */
end_comment

begin_undef
undef|#
directive|undef
name|VOP_STRATEGY
end_undef

begin_define
define|#
directive|define
name|VOP_STRATEGY
parameter_list|(
name|BP
parameter_list|)
define|\
value|( vop_strategy_a.a_desc = VDESC(vop_strategy), \ 		vop_strategy_a.a_bp=(BP), \ 		(VCALL((BP)->b_vp,VOFFSET(vop_strategy),&vop_strategy_a)))
end_define

begin_undef
undef|#
directive|undef
name|VOP_BWRITE
end_undef

begin_define
define|#
directive|define
name|VOP_BWRITE
parameter_list|(
name|BP
parameter_list|)
define|\
value|( vop_bwrite_a.a_desc = VDESC(vop_bwrite), \ 		vop_bwrite_a.a_bp=(BP), \ 		(VCALL((BP)->b_vp,VOFFSET(vop_bwrite),&vop_bwrite_a)))
end_define

begin_undef
undef|#
directive|undef
name|VOP_VGET
end_undef

begin_define
define|#
directive|define
name|VOP_VGET
parameter_list|(
name|VP
parameter_list|,
name|INO
parameter_list|,
name|VPP
parameter_list|)
define|\
value|( vop_vget_a.a_desc = VDESC(vop_vget), \ 		vop_vget_a.a_mp=(VP)->v_mount, \ 		vop_vget_a.a_ino=(INO), \ 		vop_vget_a.a_vpp=(VPP), \ 		(VCALL((VP),VOFFSET(vop_vget),&vop_vget_a)))
end_define

begin_comment
comment|/*  * Many clients invoke vop_vget directly.  To aid them,  * we define a few more macros.  (These go away  * whe vget goes to the vfs interface.)  */
end_comment

begin_define
define|#
directive|define
name|LFS_VGET
parameter_list|(
name|MP
parameter_list|,
name|INO
parameter_list|,
name|VPP
parameter_list|)
define|\
value|( vop_vget_a.a_desc = VDESC(vop_vget), \ 		vop_vget_a.a_mp=(MP), \ 		vop_vget_a.a_ino=(INO), \ 		vop_vget_a.a_vpp=(VPP), \ 		lfs_vget(&vop_vget_a))
end_define

begin_define
define|#
directive|define
name|FFS_VGET
parameter_list|(
name|MP
parameter_list|,
name|INO
parameter_list|,
name|VPP
parameter_list|)
define|\
value|( vop_vget_a.a_desc = VDESC(vop_vget), \ 		vop_vget_a.a_mp=(MP), \ 		vop_vget_a.a_ino=(INO), \ 		vop_vget_a.a_vpp=(VPP), \ 		ffs_vget(&vop_vget_a))
end_define

begin_comment
comment|/* END VERBATIM H */
end_comment

end_unit

