begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)quota.h	7.3 (Berkeley) 6/27/88  */
end_comment

begin_comment
comment|/*  * MELBOURNE DISC QUOTAS  *  * Various junk to do with various quotas (etc) imposed upon  * the average user (big brother finally hits UNIX).  *  * The following structure exists in core for each logged on user.  * It contains global junk relevant to that user's quotas.  *  * The u_quota field of each user struct contains a pointer to  * the quota struct relevant to the current process, this is changed  * by 'setuid' sys call,&/or by the Q_SETUID quota() call.  */
end_comment

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
name|uid_t
name|q_uid
decl_stmt|;
comment|/* real uid of owner */
name|int
name|q_flags
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
name|NOQUOTA
value|((struct quota *) 0)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|QUOTA
argument_list|)
end_if

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
comment|/*  * The following structure defines the format of the disc quota file  * (as it appears on disc) - the file is an array of these structures  * indexed by user number.  The setquota sys call establishes the inode  * for each quota file (a pointer is retained in the mount structure).  *  * The following constants define the number of warnings given a user  * before the soft limits are treated as hard limits (usually resulting  * in an allocation failure).  The warnings are normally manipulated  * each time a user logs in through the Q_DOWARN quota call.  If  * the user logs in and is under the soft limit the warning count  * is reset to MAX_*_WARN, otherwise a message is printed and the  * warning count is decremented.  This makes MAX_*_WARN equivalent to  * the number of logins before soft limits are treated as hard limits.  */
end_comment

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

begin_struct
struct|struct
name|dqblk
block|{
name|u_long
name|dqb_bhardlimit
decl_stmt|;
comment|/* absolute limit on disc blks alloc */
name|u_long
name|dqb_bsoftlimit
decl_stmt|;
comment|/* preferred limit on disc blks */
name|u_long
name|dqb_curblocks
decl_stmt|;
comment|/* current block count */
name|u_short
name|dqb_ihardlimit
decl_stmt|;
comment|/* maximum # allocated inodes + 1 */
name|u_short
name|dqb_isoftlimit
decl_stmt|;
comment|/* preferred inode limit */
name|u_short
name|dqb_curinodes
decl_stmt|;
comment|/* current # allocated inodes */
name|u_char
name|dqb_bwarn
decl_stmt|;
comment|/* # warnings left about excessive disc use */
name|u_char
name|dqb_iwarn
decl_stmt|;
comment|/* # warnings left about excessive inodes */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure records disc usage for a user on a filesystem.  * There is one allocated for each quota that exists on any filesystem  * for the current user. A cache is kept of other recently used entries.  */
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
name|dq_flags
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
name|uid_t
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
name|dq_bwarn
value|dq_dqb.dqb_bwarn
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
name|NODQUOT
value|((struct dquot *) 0)
end_define

begin_define
define|#
directive|define
name|LOSTDQUOT
value|((struct dquot *) 1)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|QUOTA
argument_list|)
end_if

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
comment|/*  * Definitions for the 'quota' system call.  */
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
comment|/* update disc copy of quota usages */
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

begin_comment
comment|/*  * Used in Q_SETDUSE.  */
end_comment

begin_struct
struct|struct
name|dqusage
block|{
name|u_short
name|du_curinodes
decl_stmt|;
name|u_long
name|du_curblocks
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Used in Q_SETWARN.  */
end_comment

begin_struct
struct|struct
name|dqwarn
block|{
name|u_char
name|dw_bwarn
decl_stmt|;
name|u_char
name|dw_iwarn
decl_stmt|;
block|}
struct|;
end_struct

end_unit

