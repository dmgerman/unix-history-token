begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * %sccs.include.redist.c%  *  *	@(#)portal.h	8.4 (Berkeley) %G%  *  * $Id: portal.h,v 1.3 1992/05/30 10:05:24 jsp Exp jsp $  */
end_comment

begin_struct
struct|struct
name|portal_args
block|{
name|char
modifier|*
name|pa_config
decl_stmt|;
comment|/* Config file */
name|int
name|pa_socket
decl_stmt|;
comment|/* Socket to server */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|portal_cred
block|{
name|int
name|pcr_flag
decl_stmt|;
comment|/* File open mode */
name|uid_t
name|pcr_uid
decl_stmt|;
comment|/* From ucred */
name|short
name|pcr_ngroups
decl_stmt|;
comment|/* From ucred */
name|gid_t
name|pcr_groups
index|[
name|NGROUPS
index|]
decl_stmt|;
comment|/* From ucred */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct
struct|struct
name|portalmount
block|{
name|struct
name|vnode
modifier|*
name|pm_root
decl_stmt|;
comment|/* Root node */
name|struct
name|file
modifier|*
name|pm_server
decl_stmt|;
comment|/* Held reference to server socket */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|portalnode
block|{
name|int
name|pt_size
decl_stmt|;
comment|/* Length of Arg */
name|char
modifier|*
name|pt_arg
decl_stmt|;
comment|/* Arg to send to server */
name|int
name|pt_fileid
decl_stmt|;
comment|/* cookie */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VFSTOPORTAL
parameter_list|(
name|mp
parameter_list|)
value|((struct portalmount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|VTOPORTAL
parameter_list|(
name|vp
parameter_list|)
value|((struct portalnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|PORTAL_ROOTFILEID
value|2
end_define

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
modifier|*
name|portal_vnodeop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|portal_vfsops
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

