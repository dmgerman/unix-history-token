begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * %sccs.include.redist.c%  *  *	@(#)kernfs.h	8.5 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|_PATH_KERNFS
value|"/kern"
end_define

begin_comment
comment|/* Default mountpoint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct
struct|struct
name|kernfs_mount
block|{
name|struct
name|vnode
modifier|*
name|kf_root
decl_stmt|;
comment|/* Root node */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|kernfs_node
block|{
name|struct
name|kern_target
modifier|*
name|kf_kt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VFSTOKERNFS
parameter_list|(
name|mp
parameter_list|)
value|((struct kernfs_mount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|VTOKERN
parameter_list|(
name|vp
parameter_list|)
value|((struct kernfs_node *)(vp)->v_data)
end_define

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
modifier|*
name|kernfs_vnodeop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|kernfs_vfsops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dev_t
name|rrootdev
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

