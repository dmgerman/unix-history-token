begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   *             Coda: an Experimental Distributed File System  *                              Release 3.1  *   *           Copyright (c) 1987-1998 Carnegie Mellon University  *                          All Rights Reserved  *   * Permission  to  use, copy, modify and distribute this software and its  * documentation is hereby granted,  provided  that  both  the  copyright  * notice  and  this  permission  notice  appear  in  all  copies  of the  * software, derivative works or  modified  versions,  and  any  portions  * thereof, and that both notices appear in supporting documentation, and  * that credit is given to Carnegie Mellon University  in  all  documents  * and publicity pertaining to direct or indirect use of this code or its  * derivatives.  *   * CODA IS AN EXPERIMENTAL SOFTWARE SYSTEM AND IS  KNOWN  TO  HAVE  BUGS,  * SOME  OF  WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON ALLOWS  * FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION.   CARNEGIE  MELLON  * DISCLAIMS  ANY  LIABILITY  OF  ANY  KIND  FOR  ANY  DAMAGES WHATSOEVER  * RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE  OR  OF  * ANY DERIVATIVE WORK.  *   * Carnegie  Mellon  encourages  users  of  this  software  to return any  * improvements or extensions that  they  make,  and  to  grant  Carnegie  * Mellon the rights to redistribute these changes without encumbrance.  *   * 	@(#) src/sys/coda/cnode.h,v 1.1.1.1 1998/08/29 21:14:52 rvb Exp $   * $FreeBSD$  *   */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1990 Carnegie-Mellon University  * Copyright (c) 1989 Carnegie-Mellon University  * All rights reserved.  The CMU software License Agreement specifies  * the terms and conditions for use and redistribution.  */
end_comment

begin_comment
comment|/*  * This code was written for the Coda file system at Carnegie Mellon University.  * Contributers include David Steere, James Kistler, and M. Satyanarayanan.  */
end_comment

begin_comment
comment|/*   * HISTORY  * $Log: cnode.h,v $  * Revision 1.5  1998/11/11 20:32:20  rvb  * coda_lookup now passes up an extra flag.  But old veni will  * be ok; new veni will check /dev/cfs0 to make sure that a new  * kernel is running.  * Also, a bug in vc_nb_close iff CODA_SIGNAL's were seen has been  * fixed.  *  * Revision 1.4  1998/09/13 13:57:59  rvb  * Finish conversion of cfs -> coda  *  * Revision 1.3  1998/09/11 18:50:17  rvb  * All the references to cfs, in symbols, structs, and strings  * have been changed to coda.  (Same for CFS.)  *  * Revision 1.2  1998/09/02 19:09:53  rvb  * Pass2 complete  *  * Revision 1.1.1.1  1998/08/29 21:14:52  rvb  * Very Preliminary Coda  *  * Revision 1.10  1998/08/28 18:12:25  rvb  * Now it also works on FreeBSD -current.  This code will be  * committed to the FreeBSD -current and NetBSD -current  * trees.  It will then be tailored to the particular platform  * by flushing conditional code.  *  * Revision 1.9  1998/08/18 17:05:24  rvb  * Don't use __RCSID now  *  * Revision 1.8  1998/08/18 16:31:49  rvb  * Sync the code for NetBSD -current; test on 1.3 later  *  * Revision 1.7  98/02/24  22:22:53  rvb  * Fixes up mainly to flush iopen and friends  *   * Revision 1.6  98/01/31  20:53:19  rvb  * First version that works on FreeBSD 2.2.5  *   * Revision 1.5  98/01/23  11:53:51  rvb  * Bring RVB_CODA1_1 to HEAD  *   * Revision 1.4.2.5  98/01/23  11:21:14  rvb  * Sync with 2.2.5  *   * Revision 1.4.2.4  98/01/22  13:03:38  rvb  * Had Breaken ls .  *   * Revision 1.4.2.3  97/12/19  14:26:09  rvb  * session id  *   * Revision 1.4.2.2  97/12/16  12:40:24  rvb  * Sync with 1.3  *   * Revision 1.4.2.1  97/12/06  17:41:28  rvb  * Sync with peters coda.h  *   * Revision 1.4  97/12/05  10:39:30  rvb  * Read CHANGES  *   * Revision 1.3.18.2  97/11/12  12:09:45  rvb  * reorg pass1  *   * Revision 1.3.18.1  97/10/29  16:06:31  rvb  * Kill DYING  *   * Revision 1.3  1996/12/12 22:11:03  bnoble  * Fixed the "downcall invokes venus operation" deadlock in all known cases.   *  There may be more.  *  * Revision 1.2  1996/01/02 16:57:26  bnoble  * Added support for Coda MiniCache and raw inode calls (final commit)  *  * Revision 1.1.2.1  1995/12/20 01:57:53  bnoble  * Added CODA-specific files  *  * Revision 3.1.1.1  1995/03/04  19:08:23  bnoble  * Branch for NetBSD port revisions  *  * Revision 3.1  1995/03/04  19:08:23  bnoble  * Bump to major revision 3 to prepare for NetBSD port  *  * Revision 2.2  1994/12/06  13:39:18  dcs  * Add a flag value to indicate a cnode was orphaned, e.g. the venus  * that created it has exited. This will allow one to restart venus  * even though some process may be cd'd into /coda.  *  * Revision 2.1  94/07/21  16:25:33  satya  * Conversion to C++ 3.0; start of Coda Release 2.0  *   * Revision 1.2.7.1  94/06/16  11:26:02  raiff  * Branch for release beta-16Jun1994_39118  *   * Revision 1.2  92/10/27  17:58:41  lily  * merge kernel/latest and alpha/src/cfs  *   * Revision 2.3  92/09/30  14:16:53  mja  * 	Picked up fixed #ifdef _KERNEL. Also...  *   * 	Substituted rvb's history blurb so that we agree with Mach 2.5 sources.  * 	[91/02/09            jjk]  *   * 	Added contributors blurb.  * 	[90/12/13            jjk]  *   * Revision 2.2  90/07/05  11:27:24  mrt  * 	Created for the Coda File System.  * 	[90/05/23            dcs]  *   * Revision 1.4  90/05/31  17:02:16  dcs  * Prepare for merge with facilities kernel.  *   *   *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CNODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_CNODE_H_
end_define

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_CODA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * tmp below since we need struct queue  */
end_comment

begin_include
include|#
directive|include
file|<coda/coda_kernel.h>
end_include

begin_comment
comment|/*  * Cnode lookup stuff.  * NOTE: CODA_CACHESIZE must be a power of 2 for cfshash to work!  */
end_comment

begin_define
define|#
directive|define
name|CODA_CACHESIZE
value|512
end_define

begin_define
define|#
directive|define
name|CODA_ALLOC
parameter_list|(
name|ptr
parameter_list|,
name|cast
parameter_list|,
name|size
parameter_list|)
define|\
value|do {                                                                      \     ptr = (cast)malloc((unsigned long) size, M_CODA, M_WAITOK);            \     if (ptr == 0) {                                                       \ 	panic("kernel malloc returns 0 at %s:%d\n", __FILE__, __LINE__);  \     }                                                                     \ } while (0)
end_define

begin_define
define|#
directive|define
name|CODA_FREE
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
value|free((ptr), M_CODA)
end_define

begin_comment
comment|/*  * global cache state control  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|coda_nc_use
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Used to select debugging statements throughout the cfs code.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|codadebug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|coda_nc_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|coda_printf_delay
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|coda_vnop_print_entry
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|coda_psdev_print_entry
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|coda_vfsop_print_entry
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CODADBGMSK
parameter_list|(
name|N
parameter_list|)
value|(1<< N)
end_define

begin_define
define|#
directive|define
name|CODADEBUG
parameter_list|(
name|N
parameter_list|,
name|STMT
parameter_list|)
value|{ if (codadebug& CODADBGMSK(N)) { STMT } }
end_define

begin_define
define|#
directive|define
name|myprintf
parameter_list|(
name|args
parameter_list|)
define|\
value|do {                            \     if (coda_printf_delay)       \ 	DELAY(coda_printf_delay);\     printf args ;               \ } while (0)
end_define

begin_struct
struct|struct
name|cnode
block|{
name|struct
name|vnode
modifier|*
name|c_vnode
decl_stmt|;
name|u_short
name|c_flags
decl_stmt|;
comment|/* flags (see below) */
name|ViceFid
name|c_fid
decl_stmt|;
comment|/* file handle */
name|struct
name|lock
name|c_lock
decl_stmt|;
comment|/* new lock protocol */
name|struct
name|vnode
modifier|*
name|c_ovp
decl_stmt|;
comment|/* open vnode pointer */
name|u_short
name|c_ocount
decl_stmt|;
comment|/* count of openers */
name|u_short
name|c_owrite
decl_stmt|;
comment|/* count of open for write */
name|struct
name|vattr
name|c_vattr
decl_stmt|;
comment|/* attributes */
name|char
modifier|*
name|c_symlink
decl_stmt|;
comment|/* pointer to symbolic link */
name|u_short
name|c_symlen
decl_stmt|;
comment|/* length of symbolic link */
name|dev_t
name|c_device
decl_stmt|;
comment|/* associated vnode device */
name|ino_t
name|c_inode
decl_stmt|;
comment|/* associated vnode inode */
name|struct
name|cnode
modifier|*
name|c_next
decl_stmt|;
comment|/* links if on NetBSD machine */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VTOC
parameter_list|(
name|vp
parameter_list|)
value|((struct cnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|CTOV
parameter_list|(
name|cp
parameter_list|)
value|((struct vnode *)((cp)->c_vnode))
end_define

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|C_VATTR
value|0x01
end_define

begin_comment
comment|/* Validity of vattr in the cnode */
end_comment

begin_define
define|#
directive|define
name|C_SYMLINK
value|0x02
end_define

begin_comment
comment|/* Validity of symlink pointer in the Code */
end_comment

begin_define
define|#
directive|define
name|C_WANTED
value|0x08
end_define

begin_comment
comment|/* Set if lock wanted */
end_comment

begin_define
define|#
directive|define
name|C_LOCKED
value|0x10
end_define

begin_comment
comment|/* Set if lock held */
end_comment

begin_define
define|#
directive|define
name|C_UNMOUNTING
value|0X20
end_define

begin_comment
comment|/* Set if unmounting */
end_comment

begin_define
define|#
directive|define
name|C_PURGING
value|0x40
end_define

begin_comment
comment|/* Set if purging a fid */
end_comment

begin_define
define|#
directive|define
name|VALID_VATTR
parameter_list|(
name|cp
parameter_list|)
value|((cp->c_flags)& C_VATTR)
end_define

begin_define
define|#
directive|define
name|VALID_SYMLINK
parameter_list|(
name|cp
parameter_list|)
value|((cp->c_flags)& C_SYMLINK)
end_define

begin_define
define|#
directive|define
name|IS_UNMOUNTING
parameter_list|(
name|cp
parameter_list|)
value|((cp)->c_flags& C_UNMOUNTING)
end_define

begin_struct
struct|struct
name|vcomm
block|{
name|u_long
name|vc_seq
decl_stmt|;
name|struct
name|selinfo
name|vc_selproc
decl_stmt|;
name|struct
name|queue
name|vc_requests
decl_stmt|;
name|struct
name|queue
name|vc_replys
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VC_OPEN
parameter_list|(
name|vcp
parameter_list|)
value|((vcp)->vc_requests.forw != NULL)
end_define

begin_define
define|#
directive|define
name|MARK_VC_CLOSED
parameter_list|(
name|vcp
parameter_list|)
value|(vcp)->vc_requests.forw = NULL;
end_define

begin_define
define|#
directive|define
name|MARK_VC_OPEN
parameter_list|(
name|vcp
parameter_list|)
end_define

begin_comment
comment|/* MT */
end_comment

begin_struct
struct|struct
name|coda_clstat
block|{
name|int
name|ncalls
decl_stmt|;
comment|/* client requests */
name|int
name|nbadcalls
decl_stmt|;
comment|/* upcall failures */
name|int
name|reqs
index|[
name|CODA_NCALLS
index|]
decl_stmt|;
comment|/* count of each request */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|coda_clstat
name|coda_clstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * CODA structure to hold mount/file system information  */
end_comment

begin_struct
struct|struct
name|coda_mntinfo
block|{
name|struct
name|vnode
modifier|*
name|mi_rootvp
decl_stmt|;
name|struct
name|mount
modifier|*
name|mi_vfsp
decl_stmt|;
name|struct
name|vcomm
name|mi_vcomm
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|coda_mntinfo
name|coda_mnttbl
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* indexed by minor device number */
end_comment

begin_comment
comment|/*  * vfs pointer to mount info  */
end_comment

begin_define
define|#
directive|define
name|vftomi
parameter_list|(
name|vfsp
parameter_list|)
value|((struct coda_mntinfo *)(vfsp->mnt_data))
end_define

begin_define
define|#
directive|define
name|CODA_MOUNTED
parameter_list|(
name|vfsp
parameter_list|)
value|(vftomi((vfsp)) != (struct coda_mntinfo *)0)
end_define

begin_comment
comment|/*  * vnode pointer to mount info  */
end_comment

begin_define
define|#
directive|define
name|vtomi
parameter_list|(
name|vp
parameter_list|)
value|((struct coda_mntinfo *)(vp->v_mount->mnt_data))
end_define

begin_comment
comment|/*  * Used for identifying usage of "Control" object  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnode
modifier|*
name|coda_ctlvp
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IS_CTL_VP
parameter_list|(
name|vp
parameter_list|)
value|((vp) == coda_ctlvp)
end_define

begin_define
define|#
directive|define
name|IS_CTL_NAME
parameter_list|(
name|vp
parameter_list|,
name|name
parameter_list|,
name|l
parameter_list|)
value|((l == CODA_CONTROLLEN) \&& ((vp) == vtomi((vp))->mi_rootvp)    \&& strncmp(name, CODA_CONTROL, l) == 0)
end_define

begin_comment
comment|/*   * An enum to tell us whether something that will remove a reference  * to a cnode was a downcall or not  */
end_comment

begin_enum
enum|enum
name|dc_status
block|{
name|IS_DOWNCALL
init|=
literal|6
block|,
name|NOT_DOWNCALL
init|=
literal|7
block|}
enum|;
end_enum

begin_comment
comment|/* cfs_psdev.h */
end_comment

begin_function_decl
specifier|extern
name|int
name|coda_call
parameter_list|(
name|struct
name|coda_mntinfo
modifier|*
name|mntinfo
parameter_list|,
name|int
name|inSize
parameter_list|,
name|int
modifier|*
name|outSize
parameter_list|,
name|caddr_t
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|coda_kernel_version
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cfs_subr.h */
end_comment

begin_function_decl
specifier|extern
name|int
name|handleDownCall
parameter_list|(
name|int
name|opcode
parameter_list|,
name|union
name|outputArgs
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coda_unmounting
parameter_list|(
name|struct
name|mount
modifier|*
name|whoIam
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|coda_vmflush
parameter_list|(
name|struct
name|cnode
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cfs_vnodeops.h */
end_comment

begin_function_decl
specifier|extern
name|struct
name|cnode
modifier|*
name|make_coda_node
parameter_list|(
name|ViceFid
modifier|*
name|fid
parameter_list|,
name|struct
name|mount
modifier|*
name|vfsp
parameter_list|,
name|short
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|coda_vnodeopstats_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* coda_vfsops.h */
end_comment

begin_function_decl
specifier|extern
name|struct
name|mount
modifier|*
name|devtomp
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sigh */
end_comment

begin_define
define|#
directive|define
name|CODA_RDWR
value|((u_long) 31)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CNODE_H_ */
end_comment

end_unit

