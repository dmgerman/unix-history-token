begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Robert Elz at The University of Melbourne.  *  * %sccs.include.redist.c%  *  *	@(#)quota.h	7.12 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QUOTA_
end_ifndef

begin_define
define|#
directive|define
name|_QUOTA_
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
comment|/* 1 week */
end_comment

begin_define
define|#
directive|define
name|MAX_DQ_TIME
value|(7*24*60*60)
end_define

begin_comment
comment|/* 1 week */
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
value|\ 	"undefined", \ };
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
name|u_long
name|dqb_bhardlimit
decl_stmt|;
comment|/* absolute limit on disk blks alloc */
name|u_long
name|dqb_bsoftlimit
decl_stmt|;
comment|/* preferred limit on disk blks */
name|u_long
name|dqb_curblocks
decl_stmt|;
comment|/* current block count */
name|u_long
name|dqb_ihardlimit
decl_stmt|;
comment|/* maximum # allocated inodes + 1 */
name|u_long
name|dqb_isoftlimit
decl_stmt|;
comment|/* preferred inode limit */
name|u_long
name|dqb_curinodes
decl_stmt|;
comment|/* current # allocated inodes */
name|time_t
name|dqb_btime
decl_stmt|;
comment|/* time limit for excessive disk use */
name|time_t
name|dqb_itime
decl_stmt|;
comment|/* time limit for excessive files */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure records disk usage for a user or group on a  * filesystem. There is one allocated for each quota that exists on any  * filesystem for the current user or group. A cache is kept of recently  * used entries.  */
end_comment

begin_struct
struct|struct
name|dquot
block|{
name|struct
name|dquot
modifier|*
name|dq_forw
decl_stmt|,
modifier|*
modifier|*
name|dq_back
decl_stmt|;
comment|/* hash list */
name|struct
name|dquot
modifier|*
name|dq_freef
decl_stmt|,
modifier|*
modifier|*
name|dq_freeb
decl_stmt|;
comment|/* free list */
name|short
name|dq_flags
decl_stmt|;
comment|/* flags, see below */
name|short
name|dq_cnt
decl_stmt|;
comment|/* count of active references */
name|short
name|dq_spare
decl_stmt|;
comment|/* unused spare padding */
name|short
name|dq_type
decl_stmt|;
comment|/* quota type of this dquot */
name|u_long
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
comment|/*  * If the system has never checked for a quota for this file, then it is set  * to NODQUOT.  Once a write attempt is made the inode pointer is set to  * reference a dquot structure.  */
end_comment

begin_define
define|#
directive|define
name|NODQUOT
value|((struct dquot *) 0)
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

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_struct_decl
struct_decl|struct
name|dquot
struct_decl|;
end_struct_decl

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
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ufsmount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|chkdq
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
operator|,
name|long
operator|,
expr|struct
name|ucred
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chkdqchg
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
operator|,
name|long
operator|,
expr|struct
name|ucred
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chkiq
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
operator|,
name|long
operator|,
expr|struct
name|ucred
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chkiqchg
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
operator|,
name|long
operator|,
expr|struct
name|ucred
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dqflush
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dqget
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
name|u_long
operator|,
expr|struct
name|ufsmount
operator|*
operator|,
name|int
operator|,
expr|struct
name|dquot
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dqinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dqref
name|__P
argument_list|(
operator|(
expr|struct
name|dquot
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dqrele
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|dquot
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dqsync
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|dquot
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getinoquota
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getquota
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
name|u_long
operator|,
name|int
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|qsync
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|quotaoff
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|mount
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|quotaon
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|mount
operator|*
operator|,
name|int
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setquota
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
name|u_long
operator|,
name|int
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setuse
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
name|u_long
operator|,
name|int
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_quotactl
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
name|int
operator|,
name|uid_t
operator|,
name|caddr_t
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
ifdef|#
directive|ifdef
name|DIAGNOSTIC
name|__BEGIN_DECLS
name|void
name|chkdquot
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _QUOTA_ */
end_comment

end_unit

