begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	quota.h	4.3	83/05/21	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|QUOTA
end_ifdef

begin_comment
comment|/*  *	Various junk to do with various quotas (etc) imposed upon  *	the average user (big brother finally hits unix)  *  *	The following structure exists in core for each logged on user  *	It contains global junk relevant to that user's quotas  *  *	The u_quota field of each user struct contains a pointer to  *	the quota struct relevant to the current process, this is changed  *	by 'setuid' sys call,&/or by the Q_SETUID quota() call  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct
struct|struct
name|quota
block|{
name|struct
name|quota
modifier|*
name|q_forw
decl_stmt|,
modifier|*
name|q_back
decl_stmt|;
comment|/* hash chain, MUST be first */
name|short
name|q_cnt
decl_stmt|;
comment|/* ref count (# processes) */
name|short
name|q_uid
decl_stmt|;
comment|/* real uid of owner */
name|char
name|q_flg
decl_stmt|;
comment|/* struct management flags */
define|#
directive|define
name|Q_LOCK
value|0x01
comment|/* quota struct locked (for disc i/o) */
define|#
directive|define
name|Q_WANT
value|0x02
comment|/* issue a wakeup when lock goes off */
define|#
directive|define
name|Q_NEW
value|0x04
comment|/* new quota - no proc1 msg sent yet */
define|#
directive|define
name|Q_NDQ
value|0x08
comment|/* account has NO disc quota */
name|struct
name|quota
modifier|*
name|q_freef
decl_stmt|,
modifier|*
modifier|*
name|q_freeb
decl_stmt|;
name|struct
name|dquot
modifier|*
name|q_dq
index|[
name|NMOUNT
index|]
decl_stmt|;
comment|/* disc quotas for mounted filesys's */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NOQUOT
value|((struct quota *) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|quota
modifier|*
name|quota
decl_stmt|,
modifier|*
name|quotaNQUOTA
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nquota
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|quota
modifier|*
name|getquota
argument_list|()
decl_stmt|,
modifier|*
name|qfind
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	The following structure defines the format of the disc quota file  *	(as it appears on disc) - the file is an array of these structures  *	indexed by user number. A sys call (setquota) establishes the  *	inode for each applicable file (a pointer is retained in the mount  *	structure)  *  *	nb: warning fields contain the number of warnings left before  *		allocation is halted completely  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|dlim_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dqblk
block|{
name|dlim_t
name|dqb_ilim
decl_stmt|;
comment|/* max num allocated inodes + 1 */
name|dlim_t
name|dqb_iq
decl_stmt|;
comment|/* preferred inode limit */
name|dlim_t
name|dqb_inod
decl_stmt|;
comment|/* current num allocated inodes */
name|dlim_t
name|dqb_iwarn
decl_stmt|;
comment|/* # warnings about excessive inodes */
define|#
directive|define
name|MAX_IQ_WARN
value|3
name|dlim_t
name|dqb_blim
decl_stmt|;
comment|/* abs limit on disc blks alloc */
name|dlim_t
name|dqb_quot
decl_stmt|;
comment|/* preferred limit on disc blks */
name|dlim_t
name|dqb_blks
decl_stmt|;
comment|/* current block count */
name|dlim_t
name|dqb_dwarn
decl_stmt|;
comment|/* # warnings about excessive disc use */
define|#
directive|define
name|MAX_DQ_WARN
value|3
block|}
struct|;
end_struct

begin_comment
comment|/*  *	The following structure records disc usage for a user on a filesystem  *	There is one allocated for each quota that exists on any filesystem  *	for the current user. A cache is kept of other recently used entries.  */
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
name|dq_back
decl_stmt|;
comment|/* MUST be first entry */
union|union
block|{
name|struct
name|quota
modifier|*
name|Dq_own
decl_stmt|;
comment|/* the quota that points to this */
struct|struct
block|{
comment|/* free list */
name|struct
name|dquot
modifier|*
name|Dq_freef
decl_stmt|,
modifier|*
modifier|*
name|Dq_freeb
decl_stmt|;
block|}
name|dq_f
struct|;
block|}
name|dq_u
union|;
name|short
name|dq_flg
decl_stmt|;
define|#
directive|define
name|DQ_LOCK
value|0x01
comment|/* this quota locked (no MODS) */
define|#
directive|define
name|DQ_WANT
value|0x02
comment|/* wakeup on unlock */
define|#
directive|define
name|DQ_MOD
value|0x04
comment|/* this quota modified since read */
define|#
directive|define
name|DQ_FAKE
value|0x08
comment|/* no limits here, just usage */
define|#
directive|define
name|DQ_BLKS
value|0x10
comment|/* has been warned about blk limit */
define|#
directive|define
name|DQ_INODS
value|0x20
comment|/* has been warned about inode limit */
name|short
name|dq_cnt
decl_stmt|;
comment|/* count of active references */
name|short
name|dq_uid
decl_stmt|;
comment|/* user this applies to */
name|dev_t
name|dq_dev
decl_stmt|;
comment|/* filesystem this relates to */
name|struct
name|dqblk
name|dq_dqb
decl_stmt|;
comment|/* actual usage& quotas */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dq_own
value|dq_u.Dq_own
end_define

begin_define
define|#
directive|define
name|dq_freef
value|dq_u.dq_f.Dq_freef
end_define

begin_define
define|#
directive|define
name|dq_freeb
value|dq_u.dq_f.Dq_freeb
end_define

begin_define
define|#
directive|define
name|dq_ilim
value|dq_dqb.dqb_ilim
end_define

begin_define
define|#
directive|define
name|dq_iq
value|dq_dqb.dqb_iq
end_define

begin_define
define|#
directive|define
name|dq_inod
value|dq_dqb.dqb_inod
end_define

begin_define
define|#
directive|define
name|dq_iwarn
value|dq_dqb.dqb_iwarn
end_define

begin_define
define|#
directive|define
name|dq_blim
value|dq_dqb.dqb_blim
end_define

begin_define
define|#
directive|define
name|dq_quot
value|dq_dqb.dqb_quot
end_define

begin_define
define|#
directive|define
name|dq_blks
value|dq_dqb.dqb_blks
end_define

begin_define
define|#
directive|define
name|dq_dwarn
value|dq_dqb.dqb_dwarn
end_define

begin_define
define|#
directive|define
name|NODQUOT
value|((struct dquot *) 0)
end_define

begin_define
define|#
directive|define
name|LOSTDQUOT
value|((struct dquot *) 1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|dquot
modifier|*
name|dquot
decl_stmt|,
modifier|*
name|dquotNDQUOT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ndquot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|dquot
modifier|*
name|discquota
argument_list|()
decl_stmt|,
modifier|*
name|inoquota
argument_list|()
decl_stmt|,
modifier|*
name|dqalloc
argument_list|()
decl_stmt|,
modifier|*
name|dqp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Commands for the 'quota' system call  */
end_comment

begin_define
define|#
directive|define
name|Q_SETDLIM
value|1
end_define

begin_comment
comment|/* set disc limits& usage */
end_comment

begin_define
define|#
directive|define
name|Q_GETDLIM
value|2
end_define

begin_comment
comment|/* get disc limits& usage */
end_comment

begin_define
define|#
directive|define
name|Q_SETDUSE
value|3
end_define

begin_comment
comment|/* set disc usage only */
end_comment

begin_define
define|#
directive|define
name|Q_SYNC
value|4
end_define

begin_comment
comment|/* update disc copy if quota usages */
end_comment

begin_define
define|#
directive|define
name|Q_SETUID
value|16
end_define

begin_comment
comment|/* change proc to use quotas for uid */
end_comment

begin_define
define|#
directive|define
name|Q_SETWARN
value|25
end_define

begin_comment
comment|/* alter inode/block warning counts */
end_comment

begin_define
define|#
directive|define
name|Q_DOWARN
value|26
end_define

begin_comment
comment|/* warn user about excessive space/inodes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

