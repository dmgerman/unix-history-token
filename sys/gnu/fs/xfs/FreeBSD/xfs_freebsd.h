begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_FREEBSD__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_FREEBSD__
end_define

begin_include
include|#
directive|include
file|<xfs_config.h>
end_include

begin_include
include|#
directive|include
file|<xfs_compat.h>
end_include

begin_comment
comment|/*  * Some types are conditional depending on the target system.  * XFS_BIG_BLKNOS needs block layer disk addresses to be 64 bits.  * XFS_BIG_INUMS needs the VFS inode number to be 64 bits, as well  * as requiring XFS_BIG_BLKNOS to be set.  */
end_comment

begin_define
define|#
directive|define
name|XFS_BIG_BLKNOS
value|1
end_define

begin_define
define|#
directive|define
name|XFS_BIG_INUMS
value|0
end_define

begin_include
include|#
directive|include
file|<xfs_types.h>
end_include

begin_include
include|#
directive|include
file|<xfs_arch.h>
end_include

begin_include
include|#
directive|include
file|<support/atomic.h>
end_include

begin_include
include|#
directive|include
file|<support/kmem.h>
end_include

begin_include
include|#
directive|include
file|<support/mrlock.h>
end_include

begin_include
include|#
directive|include
file|<support/spin.h>
end_include

begin_include
include|#
directive|include
file|<support/sv.h>
end_include

begin_include
include|#
directive|include
file|<support/ktrace.h>
end_include

begin_include
include|#
directive|include
file|<support/mutex.h>
end_include

begin_include
include|#
directive|include
file|<support/rwsem.h>
end_include

begin_include
include|#
directive|include
file|<support/rwlock.h>
end_include

begin_include
include|#
directive|include
file|<support/sema.h>
end_include

begin_include
include|#
directive|include
file|<support/debug.h>
end_include

begin_include
include|#
directive|include
file|<support/move.h>
end_include

begin_include
include|#
directive|include
file|<support/uuid.h>
end_include

begin_include
include|#
directive|include
file|<support/time.h>
end_include

begin_include
include|#
directive|include
file|<xfs_behavior.h>
end_include

begin_include
include|#
directive|include
file|<xfs_cred.h>
end_include

begin_include
include|#
directive|include
file|<xfs_vfs.h>
end_include

begin_include
include|#
directive|include
file|<xfs_vnode.h>
end_include

begin_include
include|#
directive|include
file|<xfs_stats.h>
end_include

begin_include
include|#
directive|include
file|<xfs_sysctl.h>
end_include

begin_include
include|#
directive|include
file|<xfs_iops.h>
end_include

begin_include
include|#
directive|include
file|<xfs_super.h>
end_include

begin_include
include|#
directive|include
file|<xfs_fs_subr.h>
end_include

begin_include
include|#
directive|include
file|<xfs_buf.h>
end_include

begin_include
include|#
directive|include
file|<xfs_frw.h>
end_include

begin_comment
comment|/*  * Feature macros (disable/enable)  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_REFCACHE
end_undef

begin_comment
comment|/* Do not use refcache. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SENDFILE
end_undef

begin_comment
comment|/* sendfile(2) is available in FreeBSD. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVMS_MAJOR
end_ifndef

begin_define
define|#
directive|define
name|EVMS_MAJOR
value|117
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|restricted_chown
value|xfs_params.restrict_chown.val
end_define

begin_define
define|#
directive|define
name|irix_sgid_inherit
value|xfs_params.sgid_inherit.val
end_define

begin_define
define|#
directive|define
name|irix_symlink_mode
value|xfs_params.symlink_mode.val
end_define

begin_define
define|#
directive|define
name|xfs_panic_mask
value|xfs_params.panic_mask.val
end_define

begin_define
define|#
directive|define
name|xfs_error_level
value|xfs_params.error_level.val
end_define

begin_define
define|#
directive|define
name|xfs_syncd_centisecs
value|xfs_params.syncd_timer.val
end_define

begin_define
define|#
directive|define
name|xfs_probe_dmapi
value|xfs_params.probe_dmapi.val
end_define

begin_define
define|#
directive|define
name|xfs_probe_ioops
value|xfs_params.probe_ioops.val
end_define

begin_define
define|#
directive|define
name|xfs_probe_quota
value|xfs_params.probe_quota.val
end_define

begin_define
define|#
directive|define
name|xfs_stats_clear
value|xfs_params.stats_clear.val
end_define

begin_define
define|#
directive|define
name|xfs_inherit_sync
value|xfs_params.inherit_sync.val
end_define

begin_define
define|#
directive|define
name|xfs_inherit_nodump
value|xfs_params.inherit_nodump.val
end_define

begin_define
define|#
directive|define
name|xfs_inherit_noatime
value|xfs_params.inherit_noatim.val
end_define

begin_define
define|#
directive|define
name|xfs_buf_timer_centisecs
value|xfs_params.xfs_buf_timer.val
end_define

begin_define
define|#
directive|define
name|xfs_buf_age_centisecs
value|xfs_params.xfs_buf_age.val
end_define

begin_define
define|#
directive|define
name|xfs_inherit_nosymlinks
value|xfs_params.inherit_nosym.val
end_define

begin_define
define|#
directive|define
name|xfs_rotorstep
value|xfs_params.rotorstep.val
end_define

begin_define
define|#
directive|define
name|current_cpu
parameter_list|()
value|smp_processor_id()
end_define

begin_define
define|#
directive|define
name|current_pid
parameter_list|()
value|(curthread->td_proc->p_pid)
end_define

begin_define
define|#
directive|define
name|NBPP
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|DPPSHFT
value|(PAGE_SHIFT - 9)
end_define

begin_define
define|#
directive|define
name|NDPP
value|(1<< (PAGE_SHIFT - 9))
end_define

begin_define
define|#
directive|define
name|dtop
parameter_list|(
name|DD
parameter_list|)
value|(((DD) + NDPP - 1)>> DPPSHFT)
end_define

begin_define
define|#
directive|define
name|dtopt
parameter_list|(
name|DD
parameter_list|)
value|((DD)>> DPPSHFT)
end_define

begin_define
define|#
directive|define
name|dpoff
parameter_list|(
name|DD
parameter_list|)
value|((DD)& (NDPP-1))
end_define

begin_define
define|#
directive|define
name|NBBY
value|8
end_define

begin_comment
comment|/* number of bits per byte */
end_comment

begin_define
define|#
directive|define
name|NBPC
value|PAGE_SIZE
end_define

begin_comment
comment|/* Number of bytes per click */
end_comment

begin_define
define|#
directive|define
name|BPCSHIFT
value|PAGE_SHIFT
end_define

begin_comment
comment|/* LOG2(NBPC) if exact */
end_comment

begin_comment
comment|/*  * Size of block device i/o is parameterized here.  * Currently the system supports page-sized i/o.  */
end_comment

begin_define
define|#
directive|define
name|BLKDEV_IOSHIFT
value|BPCSHIFT
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BLKDEV_IOSIZE
end_ifndef

begin_define
define|#
directive|define
name|BLKDEV_IOSIZE
value|(1<<BLKDEV_IOSHIFT)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|NBPC
operator|!=
name|BLKDEV_IOSIZE
end_if

begin_error
error|#
directive|error
error|Wrong BLKDEV_IOSIZE
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* number of BB's per block device block */
end_comment

begin_define
define|#
directive|define
name|BLKDEV_BB
value|BTOBB(BLKDEV_IOSIZE)
end_define

begin_comment
comment|/* bytes to clicks */
end_comment

begin_define
define|#
directive|define
name|btoct
parameter_list|(
name|x
parameter_list|)
value|((__psunsigned_t)(x)>>BPCSHIFT)
end_define

begin_define
define|#
directive|define
name|btoc64
parameter_list|(
name|x
parameter_list|)
value|(((__uint64_t)(x)+(NBPC-1))>>BPCSHIFT)
end_define

begin_define
define|#
directive|define
name|btoct64
parameter_list|(
name|x
parameter_list|)
value|((__uint64_t)(x)>>BPCSHIFT)
end_define

begin_define
define|#
directive|define
name|io_btoc
parameter_list|(
name|x
parameter_list|)
value|(((__psunsigned_t)(x)+(IO_NBPC-1))>>IO_BPCSHIFT)
end_define

begin_define
define|#
directive|define
name|io_btoct
parameter_list|(
name|x
parameter_list|)
value|((__psunsigned_t)(x)>>IO_BPCSHIFT)
end_define

begin_comment
comment|/* off_t bytes to clicks */
end_comment

begin_define
define|#
directive|define
name|offtoc
parameter_list|(
name|x
parameter_list|)
value|(((__uint64_t)(x)+(NBPC-1))>>BPCSHIFT)
end_define

begin_define
define|#
directive|define
name|offtoct
parameter_list|(
name|x
parameter_list|)
value|((xfs_off_t)(x)>>BPCSHIFT)
end_define

begin_comment
comment|/* clicks to off_t bytes */
end_comment

begin_define
define|#
directive|define
name|ctooff
parameter_list|(
name|x
parameter_list|)
value|((xfs_off_t)(x)<<BPCSHIFT)
end_define

begin_comment
comment|/* clicks to bytes */
end_comment

begin_define
define|#
directive|define
name|btoct
parameter_list|(
name|x
parameter_list|)
value|((__psunsigned_t)(x)>>BPCSHIFT)
end_define

begin_define
define|#
directive|define
name|ctob64
parameter_list|(
name|x
parameter_list|)
value|((__uint64_t)(x)<<BPCSHIFT)
end_define

begin_define
define|#
directive|define
name|io_ctob
parameter_list|(
name|x
parameter_list|)
value|((__psunsigned_t)(x)<<IO_BPCSHIFT)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CELL_CAPABLE
end_ifndef

begin_define
define|#
directive|define
name|FSC_NOTIFY_NAME_CHANGED
parameter_list|(
name|vp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOATTR
end_ifndef

begin_define
define|#
directive|define
name|ENOATTR
value|ENODATA
end_define

begin_comment
comment|/* Attribute not found */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Note: EWRONGFS never visible outside the kernel */
end_comment

begin_define
define|#
directive|define
name|EWRONGFS
value|EINVAL
end_define

begin_comment
comment|/* Mount with wrong filesystem type */
end_comment

begin_comment
comment|/*  * XXX EFSCORRUPTED needs a real value in errno.h. asm-i386/errno.h won't  *     return codes out of its known range in errno.  * XXX Also note: needs to be< 1000 and fairly unique on Linux (mustn't  *     conflict with any code we use already or any code a driver may use)  * XXX Some options (currently we do #2):  *	1/ New error code ["Filesystem is corrupted", _after_ glibc updated]  *	2/ 990 ["Unknown error 990"]  *	3/ EUCLEAN ["Structure needs cleaning"]  *	4/ Convert EFSCORRUPTED to EIO [just prior to return into userspace]  */
end_comment

begin_define
define|#
directive|define
name|EFSCORRUPTED
value|990
end_define

begin_comment
comment|/* Filesystem is corrupted */
end_comment

begin_define
define|#
directive|define
name|SYNCHRONIZE
parameter_list|()
value|barrier()
end_define

begin_define
define|#
directive|define
name|__return_address
value|__builtin_return_address(0)
end_define

begin_comment
comment|/*  * IRIX (BSD) quotactl makes use of separate commands for user/group,  * whereas on Linux the syscall encodes this information into the cmd  * field (see the QCMD macro in quota.h).  These macros help keep the  * code portable - they are not visible from the syscall interface.  */
end_comment

begin_define
define|#
directive|define
name|Q_XSETGQLIM
value|XQM_CMD(0x8)
end_define

begin_comment
comment|/* set groups disk limits */
end_comment

begin_define
define|#
directive|define
name|Q_XGETGQUOTA
value|XQM_CMD(0x9)
end_define

begin_comment
comment|/* get groups disk limits */
end_comment

begin_comment
comment|/* IRIX uses a dynamic sizing algorithm (ndquot = 200 + numprocs*2) */
end_comment

begin_comment
comment|/* we may well need to fine-tune this if it ever becomes an issue.  */
end_comment

begin_define
define|#
directive|define
name|DQUOT_MAX_HEURISTIC
value|1024
end_define

begin_comment
comment|/* NR_DQUOTS */
end_comment

begin_define
define|#
directive|define
name|ndquot
value|DQUOT_MAX_HEURISTIC
end_define

begin_comment
comment|/* IRIX uses the current size of the name cache to guess a good value */
end_comment

begin_comment
comment|/* - this isn't the same but is a good enough starting point for now. */
end_comment

begin_define
define|#
directive|define
name|DQUOT_HASH_HEURISTIC
value|files_stat.nr_files
end_define

begin_comment
comment|/* IRIX inodes maintain the project ID also, zero this field on Linux */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PROJID
value|0
end_define

begin_define
define|#
directive|define
name|dfltprid
value|DEFAULT_PROJID
end_define

begin_define
define|#
directive|define
name|FINVIS
value|0x0102
end_define

begin_comment
comment|/* don't update timestamps - XFS */
end_comment

begin_define
define|#
directive|define
name|howmany
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)+((y)-1))/(y))
end_define

begin_define
define|#
directive|define
name|roundup
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((((x)+((y)-1))/(y))*(y))
end_define

begin_define
define|#
directive|define
name|xfs_sort
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|,
name|fn
parameter_list|)
value|qsort(a,n,s,fn)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_itruncate_data
parameter_list|(
name|void
modifier|*
name|ip
parameter_list|,
name|xfs_off_t
name|off
parameter_list|)
block|{
name|printf
argument_list|(
literal|"xfs_itruncate_data NI\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Juggle IRIX device numbers - still used in ondisk structures  */
end_comment

begin_define
define|#
directive|define
name|XFS_DEV_BITSMAJOR
value|14
end_define

begin_define
define|#
directive|define
name|XFS_DEV_BITSMINOR
value|18
end_define

begin_define
define|#
directive|define
name|XFS_DEV_MAXMAJ
value|0x1ff
end_define

begin_define
define|#
directive|define
name|XFS_DEV_MAXMIN
value|0x3ffff
end_define

begin_define
define|#
directive|define
name|XFS_DEV_MAJOR
parameter_list|(
name|dev
parameter_list|)
value|((int)(((unsigned)(dev)>>XFS_DEV_BITSMINOR) \& XFS_DEV_MAXMAJ))
end_define

begin_define
define|#
directive|define
name|XFS_DEV_MINOR
parameter_list|(
name|dev
parameter_list|)
value|((int)((dev)&XFS_DEV_MAXMIN))
end_define

begin_define
define|#
directive|define
name|XFS_MKDEV
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
value|((xfs_dev_t)(((major)<<XFS_DEV_BITSMINOR) \ 				    | (minor&XFS_DEV_MAXMIN)))
end_define

begin_define
define|#
directive|define
name|XFS_DEV_TO_KDEVT
parameter_list|(
name|dev
parameter_list|)
value|mk_kdev(XFS_DEV_MAJOR(dev),XFS_DEV_MINOR(dev))
end_define

begin_comment
comment|/* Produce a kernel stack trace */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xfs_stack_trace
parameter_list|(
name|void
parameter_list|)
block|{
name|kdb_backtrace
argument_list|()
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|xfs_statvfs_fsid
parameter_list|(
name|statp
parameter_list|,
name|mp
parameter_list|)
define|\
value|({				   \ 		(statp)->f_fsid.val[0] =
comment|/*dev2udev(mp->m_dev) */
value|1;	\ 		(statp)->f_fsid.val[1] = 0;			\ 	})
end_define

begin_comment
comment|/* Move the kernel do_div definition off to one side */
end_comment

begin_if
if|#
directive|if
name|defined
name|__i386__
end_if

begin_comment
comment|/* For ia32 we need to pull some tricks to get past various versions  * of the compiler which do not like us using do_div in the middle  * of large functions.  */
end_comment

begin_function
specifier|static
specifier|inline
name|__u32
name|xfs_do_div
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|__u32
name|b
parameter_list|,
name|int
name|n
parameter_list|)
block|{
name|__u32
name|mod
decl_stmt|;
switch|switch
condition|(
name|n
condition|)
block|{
case|case
literal|4
case|:
name|mod
operator|=
operator|*
operator|(
name|__u32
operator|*
operator|)
name|a
operator|%
name|b
expr_stmt|;
operator|*
operator|(
name|__u32
operator|*
operator|)
name|a
operator|=
operator|*
operator|(
name|__u32
operator|*
operator|)
name|a
operator|/
name|b
expr_stmt|;
return|return
name|mod
return|;
case|case
literal|8
case|:
block|{
name|unsigned
name|long
name|__upper
decl_stmt|,
name|__low
decl_stmt|,
name|__high
decl_stmt|,
name|__mod
decl_stmt|;
name|__u64
name|c
init|=
operator|*
operator|(
name|__u64
operator|*
operator|)
name|a
decl_stmt|;
name|__upper
operator|=
name|__high
operator|=
name|c
operator|>>
literal|32
expr_stmt|;
name|__low
operator|=
name|c
expr_stmt|;
if|if
condition|(
name|__high
condition|)
block|{
name|__upper
operator|=
name|__high
operator|%
operator|(
name|b
operator|)
expr_stmt|;
name|__high
operator|=
name|__high
operator|/
operator|(
name|b
operator|)
expr_stmt|;
block|}
asm|asm("divl %2":"=a" (__low), "=d" (__mod):"rm" (b), "0" (__low), "1" (__upper));
asm|asm("":"=A" (c):"a" (__low),"d" (__high));
operator|*
operator|(
name|__u64
operator|*
operator|)
name|a
operator|=
name|c
expr_stmt|;
return|return
name|__mod
return|;
block|}
block|}
comment|/* NOTREACHED */
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Side effect free 64 bit mod operation */
end_comment

begin_function
specifier|static
specifier|inline
name|__u32
name|xfs_do_mod
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|__u32
name|b
parameter_list|,
name|int
name|n
parameter_list|)
block|{
switch|switch
condition|(
name|n
condition|)
block|{
case|case
literal|4
case|:
return|return
operator|*
operator|(
name|__u32
operator|*
operator|)
name|a
operator|%
name|b
return|;
case|case
literal|8
case|:
block|{
name|unsigned
name|long
name|__upper
decl_stmt|,
name|__low
decl_stmt|,
name|__high
decl_stmt|,
name|__mod
decl_stmt|;
name|__u64
name|c
init|=
operator|*
operator|(
name|__u64
operator|*
operator|)
name|a
decl_stmt|;
name|__upper
operator|=
name|__high
operator|=
name|c
operator|>>
literal|32
expr_stmt|;
name|__low
operator|=
name|c
expr_stmt|;
if|if
condition|(
name|__high
condition|)
block|{
name|__upper
operator|=
name|__high
operator|%
operator|(
name|b
operator|)
expr_stmt|;
name|__high
operator|=
name|__high
operator|/
operator|(
name|b
operator|)
expr_stmt|;
block|}
asm|asm("divl %2":"=a" (__low), "=d" (__mod):"rm" (b), "0" (__low), "1" (__upper));
asm|asm("":"=A" (c):"a" (__low),"d" (__high));
return|return
name|__mod
return|;
block|}
block|}
comment|/* NOTREACHED */
return|return
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|do_div
parameter_list|(
name|n
parameter_list|,
name|base
parameter_list|)
value|({\ 	int __res; \ 	__res = ((__u64)(n)) % (__u32)(base); \ 	(n) = ((__u64)(n)) / (__u32)(base); \ 	__res; })
end_define

begin_function
specifier|static
specifier|inline
name|__u32
name|xfs_do_div
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|__u32
name|b
parameter_list|,
name|int
name|n
parameter_list|)
block|{
name|__u32
name|mod
decl_stmt|;
switch|switch
condition|(
name|n
condition|)
block|{
case|case
literal|4
case|:
name|mod
operator|=
operator|*
operator|(
name|__u32
operator|*
operator|)
name|a
operator|%
name|b
expr_stmt|;
operator|*
operator|(
name|__u32
operator|*
operator|)
name|a
operator|=
operator|*
operator|(
name|__u32
operator|*
operator|)
name|a
operator|/
name|b
expr_stmt|;
return|return
name|mod
return|;
case|case
literal|8
case|:
name|mod
operator|=
name|do_div
argument_list|(
operator|*
operator|(
name|__u64
operator|*
operator|)
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|mod
return|;
block|}
comment|/* NOTREACHED */
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Side effect free 64 bit mod operation */
end_comment

begin_function
specifier|static
specifier|inline
name|__u32
name|xfs_do_mod
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|__u32
name|b
parameter_list|,
name|int
name|n
parameter_list|)
block|{
switch|switch
condition|(
name|n
condition|)
block|{
case|case
literal|4
case|:
return|return
operator|*
operator|(
name|__u32
operator|*
operator|)
name|a
operator|%
name|b
return|;
case|case
literal|8
case|:
block|{
name|__u64
name|c
init|=
operator|*
operator|(
name|__u64
operator|*
operator|)
name|a
decl_stmt|;
return|return
name|do_div
argument_list|(
name|c
argument_list|,
name|b
argument_list|)
return|;
block|}
block|}
comment|/* NOTREACHED */
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|do_div
end_undef

begin_define
define|#
directive|define
name|do_div
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|xfs_do_div(&(a), (b), sizeof(a))
end_define

begin_define
define|#
directive|define
name|do_mod
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|xfs_do_mod(&(a), (b), sizeof(a))
end_define

begin_function
specifier|static
specifier|inline
name|__uint64_t
name|roundup_64
parameter_list|(
name|__uint64_t
name|x
parameter_list|,
name|__uint32_t
name|y
parameter_list|)
block|{
name|x
operator|+=
name|y
operator|-
literal|1
expr_stmt|;
name|do_div
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
return|return
operator|(
name|x
operator|*
name|y
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_FREEBSD__ */
end_comment

end_unit

