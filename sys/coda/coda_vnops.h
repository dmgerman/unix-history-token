begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   *             Coda: an Experimental Distributed File System  *                              Release 3.1  *   *           Copyright (c) 1987-1998 Carnegie Mellon University  *                          All Rights Reserved  *   * Permission  to  use, copy, modify and distribute this software and its  * documentation is hereby granted,  provided  that  both  the  copyright  * notice  and  this  permission  notice  appear  in  all  copies  of the  * software, derivative works or  modified  versions,  and  any  portions  * thereof, and that both notices appear in supporting documentation, and  * that credit is given to Carnegie Mellon University  in  all  documents  * and publicity pertaining to direct or indirect use of this code or its  * derivatives.  *   * CODA IS AN EXPERIMENTAL SOFTWARE SYSTEM AND IS  KNOWN  TO  HAVE  BUGS,  * SOME  OF  WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON ALLOWS  * FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION.   CARNEGIE  MELLON  * DISCLAIMS  ANY  LIABILITY  OF  ANY  KIND  FOR  ANY  DAMAGES WHATSOEVER  * RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE  OR  OF  * ANY DERIVATIVE WORK.  *   * Carnegie  Mellon  encourages  users  of  this  software  to return any  * improvements or extensions that  they  make,  and  to  grant  Carnegie  * Mellon the rights to redistribute these changes without encumbrance.  *   * 	@(#) src/sys/coda/coda_vnops.h,v 1.1.1.1 1998/08/29 21:14:52 rvb Exp $  * $FreeBSD$  *    */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1990 Carnegie-Mellon University  * Copyright (c) 1989 Carnegie-Mellon University  * All rights reserved.  The CMU software License Agreement specifies  * the terms and conditions for use and redistribution.  */
end_comment

begin_comment
comment|/*  * This code was written for the Coda file system at Carnegie Mellon  * University.  Contributers include David Steere, James Kistler, and  * M. Satyanarayanan.    */
end_comment

begin_comment
comment|/* NetBSD interfaces to the vnodeops */
end_comment

begin_function_decl
name|int
name|coda_open
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_close
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_read
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_write
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_ioctl
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 1.3 int cfs_select(void *);*/
end_comment

begin_function_decl
name|int
name|coda_getattr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_setattr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_access
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_abortop
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_readlink
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_fsync
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_inactive
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_lookup
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_create
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_remove
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_link
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_rename
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_mkdir
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_rmdir
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_symlink
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_readdir
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_bmap
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_strategy
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_reclaim
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_lock
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_unlock
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|coda_islocked
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|int
name|coda_fbsd_getpages
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
name|dev_t
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

