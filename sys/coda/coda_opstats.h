begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   *             Coda: an Experimental Distributed File System  *                              Release 3.1  *   *           Copyright (c) 1987-1998 Carnegie Mellon University  *                          All Rights Reserved  *   * Permission  to  use, copy, modify and distribute this software and its  * documentation is hereby granted,  provided  that  both  the  copyright  * notice  and  this  permission  notice  appear  in  all  copies  of the  * software, derivative works or  modified  versions,  and  any  portions  * thereof, and that both notices appear in supporting documentation, and  * that credit is given to Carnegie Mellon University  in  all  documents  * and publicity pertaining to direct or indirect use of this code or its  * derivatives.  *   * CODA IS AN EXPERIMENTAL SOFTWARE SYSTEM AND IS  KNOWN  TO  HAVE  BUGS,  * SOME  OF  WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON ALLOWS  * FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION.   CARNEGIE  MELLON  * DISCLAIMS  ANY  LIABILITY  OF  ANY  KIND  FOR  ANY  DAMAGES WHATSOEVER  * RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE  OR  OF  * ANY DERIVATIVE WORK.  *   * Carnegie  Mellon  encourages  users  of  this  software  to return any  * improvements or extensions that  they  make,  and  to  grant  Carnegie  * Mellon the rights to redistribute these changes without encumbrance.  *   * 	@(#) src/sys/coda/coda_opstats.h,v 1.1.1.1 1998/08/29 21:14:52 rvb Exp $   * $FreeBSD$  *   */
end_comment

begin_comment
comment|/*  * operation stats: what the minicache can intercept that  * *isn't* seen by venus.  These stats are kept to augment  * the stats maintained by the Volume-Session mechanism.  */
end_comment

begin_comment
comment|/* vfsops:  *          mount: not currently bounced to Venus  *          umount: nope  *          root: only first call, rest is cached.  *          statfs: none (bogus)  *          sync: none (bogus)  *          vget: all  */
end_comment

begin_define
define|#
directive|define
name|CODA_MOUNT_STATS
value|0
end_define

begin_define
define|#
directive|define
name|CODA_UMOUNT_STATS
value|1
end_define

begin_define
define|#
directive|define
name|CODA_ROOT_STATS
value|2
end_define

begin_define
define|#
directive|define
name|CODA_STATFS_STATS
value|3
end_define

begin_define
define|#
directive|define
name|CODA_SYNC_STATS
value|4
end_define

begin_define
define|#
directive|define
name|CODA_VGET_STATS
value|5
end_define

begin_define
define|#
directive|define
name|CODA_VFSOPS_SIZE
value|6
end_define

begin_comment
comment|/* vnodeops:  *            open: all to venus  *            close: all to venus  *            rdrw: bogus.  Maybe redirected to UFS.  *                          May call open/close for internal opens/closes  *                          (Does exec not call open?)  *            ioctl: causes a lookupname  *                   passes through  *            select: can't get there from here.  *            getattr: can be satsified by cache  *            setattr: all go through  *            access: can be satisfied by cache  *            readlink: can be satisfied by cache  *            fsync: passes through  *            inactive: passes through  *            lookup: can be satisfied by cache  *            create: passes through  *            remove: passes through  *            link: passes through  *            rename: passes through  *            mkdir: passes through  *            rmdir: passes through  *            symlink: passes through  *            readdir: may be redirected to UFS  *                     may cause an "internal" open/close  */
end_comment

begin_define
define|#
directive|define
name|CODA_OPEN_STATS
value|0
end_define

begin_define
define|#
directive|define
name|CODA_CLOSE_STATS
value|1
end_define

begin_define
define|#
directive|define
name|CODA_RDWR_STATS
value|2
end_define

begin_define
define|#
directive|define
name|CODA_IOCTL_STATS
value|3
end_define

begin_define
define|#
directive|define
name|CODA_SELECT_STATS
value|4
end_define

begin_define
define|#
directive|define
name|CODA_GETATTR_STATS
value|5
end_define

begin_define
define|#
directive|define
name|CODA_SETATTR_STATS
value|6
end_define

begin_define
define|#
directive|define
name|CODA_ACCESS_STATS
value|7
end_define

begin_define
define|#
directive|define
name|CODA_READLINK_STATS
value|8
end_define

begin_define
define|#
directive|define
name|CODA_FSYNC_STATS
value|9
end_define

begin_define
define|#
directive|define
name|CODA_INACTIVE_STATS
value|10
end_define

begin_define
define|#
directive|define
name|CODA_LOOKUP_STATS
value|11
end_define

begin_define
define|#
directive|define
name|CODA_CREATE_STATS
value|12
end_define

begin_define
define|#
directive|define
name|CODA_REMOVE_STATS
value|13
end_define

begin_define
define|#
directive|define
name|CODA_LINK_STATS
value|14
end_define

begin_define
define|#
directive|define
name|CODA_RENAME_STATS
value|15
end_define

begin_define
define|#
directive|define
name|CODA_MKDIR_STATS
value|16
end_define

begin_define
define|#
directive|define
name|CODA_RMDIR_STATS
value|17
end_define

begin_define
define|#
directive|define
name|CODA_SYMLINK_STATS
value|18
end_define

begin_define
define|#
directive|define
name|CODA_READDIR_STATS
value|19
end_define

begin_define
define|#
directive|define
name|CODA_VNODEOPS_SIZE
value|20
end_define

begin_comment
comment|/*  * I propose the following structres:  */
end_comment

begin_struct
struct|struct
name|coda_op_stats
block|{
name|int
name|opcode
decl_stmt|;
comment|/* vfs opcode */
name|long
name|entries
decl_stmt|;
comment|/* number of times call attempted */
name|long
name|sat_intrn
decl_stmt|;
comment|/* number of times call satisfied by cache */
name|long
name|unsat_intrn
decl_stmt|;
comment|/* number of times call failed in cache, but                          was not bounced to venus proper. */
name|long
name|gen_intrn
decl_stmt|;
comment|/* number of times call generated internally */
comment|/* (do we need that?) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * With each call to the minicache, we'll bump the counters whenver  * a call is satisfied internally (through the cache or through a  * redirect), and whenever an operation is caused internally.  * Then, we can add the total operations caught by the minicache  * to the world-wide totals, and leave a caveat for the specific  * graphs later.  */
end_comment

end_unit

