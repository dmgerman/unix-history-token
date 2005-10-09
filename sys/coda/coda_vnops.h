begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *   *             Coda: an Experimental Distributed File System  *                              Release 3.1  *   *           Copyright (c) 1987-1998 Carnegie Mellon University  *                          All Rights Reserved  *   * Permission  to  use, copy, modify and distribute this software and its  * documentation is hereby granted,  provided  that  both  the  copyright  * notice  and  this  permission  notice  appear  in  all  copies  of the  * software, derivative works or  modified  versions,  and  any  portions  * thereof, and that both notices appear in supporting documentation, and  * that credit is given to Carnegie Mellon University  in  all  documents  * and publicity pertaining to direct or indirect use of this code or its  * derivatives.  *   * CODA IS AN EXPERIMENTAL SOFTWARE SYSTEM AND IS  KNOWN  TO  HAVE  BUGS,  * SOME  OF  WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON ALLOWS  * FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION.   CARNEGIE  MELLON  * DISCLAIMS  ANY  LIABILITY  OF  ANY  KIND  FOR  ANY  DAMAGES WHATSOEVER  * RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE  OR  OF  * ANY DERIVATIVE WORK.  *   * Carnegie  Mellon  encourages  users  of  this  software  to return any  * improvements or extensions that  they  make,  and  to  grant  Carnegie  * Mellon the rights to redistribute these changes without encumbrance.  *   * 	@(#) src/sys/coda/coda_vnops.h,v 1.1.1.1 1998/08/29 21:14:52 rvb Exp $  * $FreeBSD$  *    */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1990 Carnegie-Mellon University  * Copyright (c) 1989 Carnegie-Mellon University  * All rights reserved.  The CMU software License Agreement specifies  * the terms and conditions for use and redistribution.  */
end_comment

begin_comment
comment|/*  * This code was written for the Coda filesystem at Carnegie Mellon  * University.  Contributers include David Steere, James Kistler, and  * M. Satyanarayanan.    */
end_comment

begin_comment
comment|/* NetBSD interfaces to the vnodeops */
end_comment

begin_decl_stmt
name|vop_open_t
name|coda_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_close_t
name|coda_close
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_read_t
name|coda_read
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_write_t
name|coda_write
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_ioctl_t
name|coda_ioctl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.3 int cfs_select(void *);*/
end_comment

begin_decl_stmt
name|vop_getattr_t
name|coda_getattr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_setattr_t
name|coda_setattr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_access_t
name|coda_access
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|coda_abortop
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|vop_readlink_t
name|coda_readlink
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_fsync_t
name|coda_fsync
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_inactive_t
name|coda_inactive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_lookup_t
name|coda_lookup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_create_t
name|coda_create
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_remove_t
name|coda_remove
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_link_t
name|coda_link
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_rename_t
name|coda_rename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_mkdir_t
name|coda_mkdir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_rmdir_t
name|coda_rmdir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_symlink_t
name|coda_symlink
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_readdir_t
name|coda_readdir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_bmap_t
name|coda_bmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_strategy_t
name|coda_strategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_reclaim_t
name|coda_reclaim
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_lock_t
name|coda_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_unlock_t
name|coda_unlock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vop_islocked_t
name|coda_islocked
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|coda_vop_error
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_vop_nop
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|vop_pathconf_t
name|coda_pathconf
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|coda_rdwr
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|uio
modifier|*
name|uiop
parameter_list|,
name|enum
name|uio_rw
name|rw
parameter_list|,
name|int
name|ioflag
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
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
name|coda_grab_vnode
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
name|ino_t
name|ino
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
name|void
name|print_vattr
parameter_list|(
name|struct
name|vattr
modifier|*
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_cred
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

end_unit

