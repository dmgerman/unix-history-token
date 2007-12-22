begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *   *             Coda: an Experimental Distributed File System  *                              Release 3.1  *   *           Copyright (c) 1987-1998 Carnegie Mellon University  *                          All Rights Reserved  *   * Permission  to  use, copy, modify and distribute this software and its  * documentation is hereby granted,  provided  that  both  the  copyright  * notice  and  this  permission  notice  appear  in  all  copies  of the  * software, derivative works or  modified  versions,  and  any  portions  * thereof, and that both notices appear in supporting documentation, and  * that credit is given to Carnegie Mellon University  in  all  documents  * and publicity pertaining to direct or indirect use of this code or its  * derivatives.  *   * CODA IS AN EXPERIMENTAL SOFTWARE SYSTEM AND IS  KNOWN  TO  HAVE  BUGS,  * SOME  OF  WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON ALLOWS  * FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION.   CARNEGIE  MELLON  * DISCLAIMS  ANY  LIABILITY  OF  ANY  KIND  FOR  ANY  DAMAGES WHATSOEVER  * RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE  OR  OF  * ANY DERIVATIVE WORK.  *   * Carnegie  Mellon  encourages  users  of  this  software  to return any  * improvements or extensions that  they  make,  and  to  grant  Carnegie  * Mellon the rights to redistribute these changes without encumbrance.  *   * 	@(#) src/sys/cfs/coda_vfsops.h,v 1.1.1.1 1998/08/29 21:14:52 rvb Exp $   * $FreeBSD$  *   */
end_comment

begin_comment
comment|/*  * cfid structure:  * This overlays the fid structure (see vfs.h)  * Only used below and will probably go away.  */
end_comment

begin_struct
struct|struct
name|cfid
block|{
name|u_short
name|cfid_len
decl_stmt|;
name|u_short
name|padding
decl_stmt|;
name|CodaFid
name|cfid_fid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mount
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|coda_vfsopstats_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_fhtovp
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|fid
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|vfs_mount_t
name|coda_mount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_unmount_t
name|coda_unmount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_root_t
name|coda_root
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_quotactl_t
name|coda_quotactl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_statfs_t
name|coda_nb_statfs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_sync_t
name|coda_sync
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_vget_t
name|coda_vget
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_init_t
name|coda_init
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|getNewVnode
parameter_list|(
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
end_function_decl

end_unit

