begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Robert Elz at The University of Melbourne.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)quota.h	8.3 (Berkeley) 8/19/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_UFS_QUOTA_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_UFS_QUOTA_H_
end_define

begin_comment
comment|/*  * Definitions for disk quotas imposed on the average user  * (big brother finally hits UNIX).  *  * The following constants define the amount of time given a user before the  * soft limits are treated as hard limits (usually resulting in an allocation  * failure). The timer is started when the user crosses their soft limit, it  * is reset when they go below their soft limit.  */
end_comment

begin_define
define|#
directive|define
name|MAX_IQ_TIME
value|(7*24*60*60)
end_define

begin_comment
comment|/* seconds in 1 week */
end_comment

begin_define
define|#
directive|define
name|MAX_DQ_TIME
value|(7*24*60*60)
end_define

begin_comment
comment|/* seconds in 1 week */
end_comment

begin_comment
comment|/*  * The following constants define the usage of the quota file array in the  * ufsmount structure and dquot array in the inode structure.  The semantics  * of the elements of these arrays are defined in the routine getinoquota;  * the remainder of the quota code treats them generically and need not be  * inspected when changing the size of the array.  */
end_comment

begin_define
define|#
directive|define
name|MAXQUOTAS
value|2
end_define

begin_define
define|#
directive|define
name|USRQUOTA
value|0
end_define

begin_comment
comment|/* element used for user quotas */
end_comment

begin_define
define|#
directive|define
name|GRPQUOTA
value|1
end_define

begin_comment
comment|/* element used for group quotas */
end_comment

begin_comment
comment|/*  * Definitions for the default names of the quotas files.  */
end_comment

begin_define
define|#
directive|define
name|INITQFNAMES
value|{ \ 	"user",
comment|/* USRQUOTA */
value|\ 	"group",
comment|/* GRPQUOTA */
value|\ 	"undefined", \ }
end_define

begin_define
define|#
directive|define
name|QUOTAFILENAME
value|"quota"
end_define

begin_define
define|#
directive|define
name|QUOTAGROUP
value|"operator"
end_define

begin_comment
comment|/*  * Command definitions for the 'quotactl' system call.  The commands are  * broken into a main command defined below and a subcommand that is used  * to convey the type of quota that is being manipulated (see above).  */
end_comment

begin_define
define|#
directive|define
name|SUBCMDMASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SUBCMDSHIFT
value|8
end_define

begin_define
define|#
directive|define
name|QCMD
parameter_list|(
name|cmd
parameter_list|,
name|type
parameter_list|)
value|(((cmd)<< SUBCMDSHIFT) | ((type)& SUBCMDMASK))
end_define

begin_define
define|#
directive|define
name|Q_QUOTAON
value|0x0100
end_define

begin_comment
comment|/* enable quotas */
end_comment

begin_define
define|#
directive|define
name|Q_QUOTAOFF
value|0x0200
end_define

begin_comment
comment|/* disable quotas */
end_comment

begin_define
define|#
directive|define
name|Q_GETQUOTA
value|0x0300
end_define

begin_comment
comment|/* get limits and usage */
end_comment

begin_define
define|#
directive|define
name|Q_SETQUOTA
value|0x0400
end_define

begin_comment
comment|/* set limits and usage */
end_comment

begin_define
define|#
directive|define
name|Q_SETUSE
value|0x0500
end_define

begin_comment
comment|/* set usage */
end_comment

begin_define
define|#
directive|define
name|Q_SYNC
value|0x0600
end_define

begin_comment
comment|/* sync disk copy of a filesystems quotas */
end_comment

begin_comment
comment|/*  * The following structure defines the format of the disk quota file  * (as it appears on disk) - the file is an array of these structures  * indexed by user or group number.  The setquota system call establishes  * the vnode for each quota file (a pointer is retained in the ufsmount  * structure).  */
end_comment

begin_struct
struct|struct
name|dqblk
block|{
name|u_int32_t
name|dqb_bhardlimit
decl_stmt|;
comment|/* absolute limit on disk blks alloc */
name|u_int32_t
name|dqb_bsoftlimit
decl_stmt|;
comment|/* preferred limit on disk blks */
name|u_int32_t
name|dqb_curblocks
decl_stmt|;
comment|/* current block count */
name|u_int32_t
name|dqb_ihardlimit
decl_stmt|;
comment|/* maximum # allocated inodes + 1 */
name|u_int32_t
name|dqb_isoftlimit
decl_stmt|;
comment|/* preferred inode limit */
name|u_int32_t
name|dqb_curinodes
decl_stmt|;
comment|/* current # allocated inodes */
name|int32_t
name|dqb_btime
decl_stmt|;
comment|/* time limit for excessive disk use */
name|int32_t
name|dqb_itime
decl_stmt|;
comment|/* time limit for excessive files */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * The following structure records disk usage for a user or group on a  * filesystem. There is one allocated for each quota that exists on any  * filesystem for the current user or group. A cache is kept of recently  * used entries.  */
end_comment

begin_struct
struct|struct
name|dquot
block|{
name|LIST_ENTRY
argument_list|(
argument|dquot
argument_list|)
name|dq_hash
expr_stmt|;
comment|/* hash list */
name|TAILQ_ENTRY
argument_list|(
argument|dquot
argument_list|)
name|dq_freelist
expr_stmt|;
comment|/* free list */
name|u_int16_t
name|dq_flags
decl_stmt|;
comment|/* flags, see below */
name|u_int16_t
name|dq_type
decl_stmt|;
comment|/* quota type of this dquot */
name|u_int32_t
name|dq_cnt
decl_stmt|;
comment|/* count of active references */
name|u_int32_t
name|dq_id
decl_stmt|;
comment|/* identifier this applies to */
name|struct
name|ufsmount
modifier|*
name|dq_ump
decl_stmt|;
comment|/* filesystem that this is taken from */
name|struct
name|dqblk
name|dq_dqb
decl_stmt|;
comment|/* actual usage& quotas */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flag values.  */
end_comment

begin_define
define|#
directive|define
name|DQ_LOCK
value|0x01
end_define

begin_comment
comment|/* this quota locked (no MODS) */
end_comment

begin_define
define|#
directive|define
name|DQ_WANT
value|0x02
end_define

begin_comment
comment|/* wakeup on unlock */
end_comment

begin_define
define|#
directive|define
name|DQ_MOD
value|0x04
end_define

begin_comment
comment|/* this quota modified since read */
end_comment

begin_define
define|#
directive|define
name|DQ_FAKE
value|0x08
end_define

begin_comment
comment|/* no limits here, just usage */
end_comment

begin_define
define|#
directive|define
name|DQ_BLKS
value|0x10
end_define

begin_comment
comment|/* has been warned about blk limit */
end_comment

begin_define
define|#
directive|define
name|DQ_INODS
value|0x20
end_define

begin_comment
comment|/* has been warned about inode limit */
end_comment

begin_comment
comment|/*  * Shorthand notation.  */
end_comment

begin_define
define|#
directive|define
name|dq_bhardlimit
value|dq_dqb.dqb_bhardlimit
end_define

begin_define
define|#
directive|define
name|dq_bsoftlimit
value|dq_dqb.dqb_bsoftlimit
end_define

begin_define
define|#
directive|define
name|dq_curblocks
value|dq_dqb.dqb_curblocks
end_define

begin_define
define|#
directive|define
name|dq_ihardlimit
value|dq_dqb.dqb_ihardlimit
end_define

begin_define
define|#
directive|define
name|dq_isoftlimit
value|dq_dqb.dqb_isoftlimit
end_define

begin_define
define|#
directive|define
name|dq_curinodes
value|dq_dqb.dqb_curinodes
end_define

begin_define
define|#
directive|define
name|dq_btime
value|dq_dqb.dqb_btime
end_define

begin_define
define|#
directive|define
name|dq_itime
value|dq_dqb.dqb_itime
end_define

begin_comment
comment|/*  * If the system has never checked for a quota for this file, then it is  * set to NODQUOT.  Once a write attempt is made the inode pointer is set  * to reference a dquot structure.  */
end_comment

begin_define
define|#
directive|define
name|NODQUOT
value|NULL
end_define

begin_comment
comment|/*  * Flags to chkdq() and chkiq()  */
end_comment

begin_define
define|#
directive|define
name|FORCE
value|0x01
end_define

begin_comment
comment|/* force usage changes independent of limits */
end_comment

begin_define
define|#
directive|define
name|CHOWN
value|0x02
end_define

begin_comment
comment|/* (advisory) change initiated by chown */
end_comment

begin_comment
comment|/*  * Macros to avoid subroutine calls to trivial functions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTIC
end_ifdef

begin_define
define|#
directive|define
name|DQREF
parameter_list|(
name|dq
parameter_list|)
value|dqref(dq)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DQREF
parameter_list|(
name|dq
parameter_list|)
value|(dq)->dq_cnt++
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|chkdq
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|int64_t
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chkiq
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dqinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dqrele
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|dquot
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dquninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getinoquota
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getquota
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|mount
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|qsync
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|quotaoff
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mount
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|quotaon
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mount
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setquota
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|mount
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setuse
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|mount
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|vfs_quotactl_t
name|ufs_quotactl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|quotactl
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_UFS_UFS_QUOTA_H_ */
end_comment

end_unit

