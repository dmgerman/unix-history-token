begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 The Regents of the University of California.  * Copyright (c) 1994 Jan-Simon Pendry.  * All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * %sccs.include.redist.c%  *  *	@(#)union.h	1.2 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|union_args
block|{
name|char
modifier|*
name|target
decl_stmt|;
comment|/* Target of loopback  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|union_mount
block|{
name|struct
name|vnode
modifier|*
name|um_uppervp
decl_stmt|;
name|struct
name|vnode
modifier|*
name|um_lowervp
decl_stmt|;
name|struct
name|ucred
modifier|*
name|um_cred
decl_stmt|;
comment|/* Credentials of user calling mount */
block|}
struct|;
end_struct

begin_comment
comment|/* begin XXX */
end_comment

begin_define
define|#
directive|define
name|VT_UNION
value|VT_LOFS
end_define

begin_comment
comment|/*#define MOUNT_UNION 15*/
end_comment

begin_comment
comment|/* end XXX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * DEFDIRMODE is the mode bits used to create a shadow directory.  */
end_comment

begin_define
define|#
directive|define
name|VRWXMODE
value|(VREAD|VWRITE|VEXEC)
end_define

begin_define
define|#
directive|define
name|VRWMODE
value|(VREAD|VWRITE)
end_define

begin_define
define|#
directive|define
name|UN_DIRMODE
value|((VRWXMODE)|(VRWXMODE>>3)|(VRWXMODE>>6))
end_define

begin_define
define|#
directive|define
name|UN_FILEMODE
value|((VRWMODE)|(VRWMODE>>3)|(VRWMODE>>6))
end_define

begin_comment
comment|/*  * A cache of vnode references  */
end_comment

begin_struct
struct|struct
name|union_node
block|{
name|struct
name|union_node
modifier|*
name|un_next
decl_stmt|;
comment|/* Hash chain */
name|struct
name|vnode
modifier|*
name|un_uppervp
decl_stmt|;
comment|/* overlaying object */
name|struct
name|vnode
modifier|*
name|un_lowervp
decl_stmt|;
comment|/* underlying object */
name|struct
name|vnode
modifier|*
name|un_dirvp
decl_stmt|;
comment|/* Parent dir of uppervp */
name|struct
name|vnode
modifier|*
name|un_vnode
decl_stmt|;
comment|/* Back pointer */
name|char
modifier|*
name|un_path
decl_stmt|;
comment|/* saved component name */
name|int
name|un_flags
decl_stmt|;
name|pid_t
name|un_pid
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UN_WANT
value|0x01
end_define

begin_define
define|#
directive|define
name|UN_LOCKED
value|0x02
end_define

begin_decl_stmt
specifier|extern
name|int
name|union_node_create
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
expr|struct
name|vnode
operator|*
name|target
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MOUNTTOUNIONMOUNT
parameter_list|(
name|mp
parameter_list|)
value|((struct union_mount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|VTOUNION
parameter_list|(
name|vp
parameter_list|)
value|((struct union_node *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|UNIONTOV
parameter_list|(
name|un
parameter_list|)
value|((un)->un_vnode)
end_define

begin_define
define|#
directive|define
name|LOWERVP
parameter_list|(
name|vp
parameter_list|)
value|(VTOUNION(vp)->un_lowervp)
end_define

begin_define
define|#
directive|define
name|UPPERVP
parameter_list|(
name|vp
parameter_list|)
value|(VTOUNION(vp)->un_lowervp)
end_define

begin_define
define|#
directive|define
name|OTHERVP
parameter_list|(
name|vp
parameter_list|)
value|(UPPERVP(vp) ? UPPERVP(vp) : LOWERVP(vp))
end_define

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
modifier|*
name|union_vnodeop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|union_vfsops
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

