begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	quota.h	Melb 4.2	82/10/20	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|QUOTA
end_ifdef

begin_comment
comment|/*  *	Various junk to do with various quotas (etc) imposed upon  *	the average user (big brother finally hits unix)  *  *	The following structure exists in core for each logged on user  *	It contains global junk relevant to that user's quotas  *  *	The u_quota field of each user struct contains a pointer to  *	the quota struct relevant to the current process, this is changed  *	by 'setuid' sys call,&/or by the Q_SETUID quota() call  */
end_comment

begin_typedef
typedef|typedef
name|long
name|class_t
typedef|;
end_typedef

begin_struct
struct|struct
name|quinfo
block|{
name|u_short
name|qu_shares
decl_stmt|;
comment|/* allocated shares (MUSH) */
name|short
name|qu_plim
decl_stmt|;
comment|/* process limit */
name|long
name|qu_syflags
decl_stmt|;
comment|/* system permission flags */
name|float
name|qu_usage
decl_stmt|;
comment|/* current resource usage (MUSH) */
name|class_t
name|qu_class
decl_stmt|;
comment|/* user classes (MUSH) */
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
name|quota
block|{
name|struct
name|quota
modifier|*
name|q_forw
decl_stmt|;
comment|/* hash chain - MUST be first */
name|struct
name|quota
modifier|*
name|q_back
decl_stmt|;
comment|/* hash chain - MUST be last */
name|char
name|q_flg
decl_stmt|;
comment|/* struct management flags */
name|char
name|q_lcnt
decl_stmt|;
comment|/* count of logins for user */
name|short
name|q_cnt
decl_stmt|;
comment|/* ref count (# processes) */
name|short
name|q_uid
decl_stmt|;
comment|/* real uid of owner */
name|short
name|q_nice
decl_stmt|;
comment|/* nice added to p_cpu (MUSH) */
name|short
name|q_acnt
decl_stmt|;
comment|/* count of 'at' processes (MUSH) */
union|union
block|{
struct|struct
block|{
name|long
name|Q_rate
decl_stmt|;
comment|/* recent work rate (MUSH) */
name|long
name|Q_cost
decl_stmt|;
comment|/* cost in recent period (MUSH) */
block|}
name|q_s1
struct|;
struct|struct
block|{
name|struct
name|quota
modifier|*
name|Q_freef
decl_stmt|;
name|struct
name|quota
modifier|*
modifier|*
name|Q_freeb
decl_stmt|;
block|}
name|q_s2
struct|;
block|}
name|q_u
union|;
name|struct
name|quinfo
name|q_uinfo
decl_stmt|;
comment|/* user limits& usage (MUSH) */
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

begin_define
define|#
directive|define
name|q_rate
value|q_u.q_s1.Q_rate
end_define

begin_define
define|#
directive|define
name|q_cost
value|q_u.q_s1.Q_cost
end_define

begin_define
define|#
directive|define
name|q_freef
value|q_u.q_s2.Q_freef
end_define

begin_define
define|#
directive|define
name|q_freeb
value|q_u.q_s2.Q_freeb
end_define

begin_define
define|#
directive|define
name|q_shares
value|q_uinfo.qu_shares
end_define

begin_define
define|#
directive|define
name|q_plim
value|q_uinfo.qu_plim
end_define

begin_define
define|#
directive|define
name|q_syflags
value|q_uinfo.qu_syflags
end_define

begin_define
define|#
directive|define
name|q_usage
value|q_uinfo.qu_usage
end_define

begin_define
define|#
directive|define
name|q_class
value|q_uinfo.qu_class
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|QF_KASYNC
value|0x02
end_define

begin_comment
comment|/* kill async procs at logout */
end_comment

begin_define
define|#
directive|define
name|QF_FASTTY
value|0x04
end_define

begin_comment
comment|/* permitted to raise tty speed */
end_comment

begin_define
define|#
directive|define
name|QF_NASYNC
value|0x08
end_define

begin_comment
comment|/* nice async procs at logout */
end_comment

begin_define
define|#
directive|define
name|QF_MODTTY
value|0x10
end_define

begin_comment
comment|/* permitted to modify other tty */
end_comment

begin_define
define|#
directive|define
name|QF_UMASK
value|0x20
end_define

begin_comment
comment|/* not permitted to alter umask */
end_comment

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
comment|/*	q_flg flags	*/
end_comment

begin_define
define|#
directive|define
name|Q_LOCK
value|0x01
end_define

begin_comment
comment|/* quota struct locked (for disc i/o) */
end_comment

begin_define
define|#
directive|define
name|Q_WANT
value|0x02
end_define

begin_comment
comment|/* issue a wakeup when lock goes off */
end_comment

begin_define
define|#
directive|define
name|Q_NEW
value|0x04
end_define

begin_comment
comment|/* new quota - no proc1 msg sent yet */
end_comment

begin_define
define|#
directive|define
name|Q_NDQ
value|0x08
end_define

begin_comment
comment|/* account has NO disc quota */
end_comment

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
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_IQ_WARN
value|3
end_define

begin_define
define|#
directive|define
name|MAX_DQ_WARN
value|3
end_define

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
decl_stmt|;
comment|/* MUST be first entry */
name|struct
name|dquot
modifier|*
name|dq_back
decl_stmt|;
comment|/* MUST be second entry */
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
name|struct
name|dquot
modifier|*
name|Dq_freef
decl_stmt|;
comment|/* forward free chain ptr */
name|struct
name|dquot
modifier|*
modifier|*
name|Dq_freeb
decl_stmt|;
comment|/* backward free chain ptr */
block|}
name|dq_f
struct|;
block|}
name|dq_u
union|;
name|short
name|dq_flg
decl_stmt|;
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
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*	dq_flg flags	*/
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
name|Q_LOGIN
value|5
end_define

begin_comment
comment|/* Count this as a login process */
end_comment

begin_define
define|#
directive|define
name|Q_LCOUNT
value|6
end_define

begin_comment
comment|/* get count of login processes */
end_comment

begin_define
define|#
directive|define
name|Q_PCOUNT
value|7
end_define

begin_comment
comment|/* get count of processes */
end_comment

begin_define
define|#
directive|define
name|Q_USAGE
value|8
end_define

begin_comment
comment|/* get current usage */
end_comment

begin_define
define|#
directive|define
name|Q_SFLAGS
value|9
end_define

begin_comment
comment|/* set system flags */
end_comment

begin_define
define|#
directive|define
name|Q_SUSAGE
value|10
end_define

begin_comment
comment|/* set usage */
end_comment

begin_define
define|#
directive|define
name|Q_SPLIMIT
value|11
end_define

begin_comment
comment|/* set process limit */
end_comment

begin_define
define|#
directive|define
name|Q_ISLOGIN
value|12
end_define

begin_comment
comment|/* is this a login process ?? */
end_comment

begin_define
define|#
directive|define
name|Q_SCLASS
value|13
end_define

begin_comment
comment|/* set user class */
end_comment

begin_define
define|#
directive|define
name|Q_SCURCL
value|14
end_define

begin_comment
comment|/* set current system classes */
end_comment

begin_define
define|#
directive|define
name|Q_GCURCL
value|15
end_define

begin_comment
comment|/* get current system classes */
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
name|Q_FLOGIN
value|17
end_define

begin_comment
comment|/* "fake" login (counts as 1, but isn't) */
end_comment

begin_define
define|#
directive|define
name|Q_SETCOST
value|18
end_define

begin_comment
comment|/* set system charge rates */
end_comment

begin_define
define|#
directive|define
name|Q_GETCOST
value|19
end_define

begin_comment
comment|/* get system charge rates */
end_comment

begin_define
define|#
directive|define
name|Q_SSHARE
value|20
end_define

begin_comment
comment|/* set shares */
end_comment

begin_define
define|#
directive|define
name|Q_SUINFO
value|21
end_define

begin_comment
comment|/* set user info */
end_comment

begin_define
define|#
directive|define
name|Q_GUINFO
value|22
end_define

begin_comment
comment|/* get user info */
end_comment

begin_define
define|#
directive|define
name|Q_ATJOB
value|23
end_define

begin_comment
comment|/* this process is an 'at' job (background) */
end_comment

begin_define
define|#
directive|define
name|Q_ACOUNT
value|24
end_define

begin_comment
comment|/* return count of procs descended from ATJ */
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

begin_define
define|#
directive|define
name|Q_KILL
value|27
end_define

begin_comment
comment|/* send signal to procs attatched to quota */
end_comment

begin_define
define|#
directive|define
name|Q_NICE
value|28
end_define

begin_comment
comment|/* set niceness for procs attatched to quota */
end_comment

begin_comment
comment|/*  * current class information  *  *	records sched biasing for classes that are to have priority  *	enhanced or degraded  */
end_comment

begin_define
define|#
directive|define
name|NCLASS
value|8
end_define

begin_struct
struct|struct
name|qclass
block|{
name|class_t
name|class
decl_stmt|;
comment|/* classes this applies to */
name|long
name|cost
decl_stmt|;
comment|/* +/- mod to cost incurred */
name|short
name|maxn
decl_stmt|;
comment|/* in this class, no nice> this */
name|short
name|minn
decl_stmt|;
comment|/* in this class, no nice< this */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|qclass
name|curclass
index|[
name|NCLASS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Flag definitions for u_qflags in user struct (u_qflags)  */
end_comment

begin_define
define|#
directive|define
name|QUF_LOGIN
value|0x0001
end_define

begin_comment
comment|/* this process incremented login cnt */
end_comment

begin_define
define|#
directive|define
name|QUF_ATJ
value|0x0002
end_define

begin_comment
comment|/* this process descended from atrun */
end_comment

begin_endif
endif|#
directive|endif
endif|QUOTA
end_endif

end_unit

