begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_QUOTA_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_QUOTA_H__
end_define

begin_comment
comment|/*  * The ondisk form of a dquot structure.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DQUOT_MAGIC
value|0x4451
end_define

begin_comment
comment|/* 'DQ' */
end_comment

begin_define
define|#
directive|define
name|XFS_DQUOT_VERSION
value|(u_int8_t)0x01
end_define

begin_comment
comment|/* latest version number */
end_comment

begin_comment
comment|/*  * uid_t and gid_t are hard-coded to 32 bits in the inode.  * Hence, an 'id' in a dquot is 32 bits..  */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|xfs_dqid_t
typedef|;
end_typedef

begin_comment
comment|/*  * Even though users may not have quota limits occupying all 64-bits,  * they may need 64-bit accounting. Hence, 64-bit quota-counters,  * and quota-limits. This is a waste in the common case, but hey ...  */
end_comment

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_qcnt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint16_t
name|xfs_qwarncnt_t
typedef|;
end_typedef

begin_comment
comment|/*  * This is the main portion of the on-disk representation of quota  * information for a user. This is the q_core of the xfs_dquot_t that  * is kept in kernel memory. We pad this with some more expansion room  * to construct the on disk structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_disk_dquot
block|{
name|__be16
name|d_magic
decl_stmt|;
comment|/* dquot magic = XFS_DQUOT_MAGIC */
name|__u8
name|d_version
decl_stmt|;
comment|/* dquot version */
name|__u8
name|d_flags
decl_stmt|;
comment|/* XFS_DQ_USER/PROJ/GROUP */
name|__be32
name|d_id
decl_stmt|;
comment|/* user,project,group id */
name|__be64
name|d_blk_hardlimit
decl_stmt|;
comment|/* absolute limit on disk blks */
name|__be64
name|d_blk_softlimit
decl_stmt|;
comment|/* preferred limit on disk blks */
name|__be64
name|d_ino_hardlimit
decl_stmt|;
comment|/* maximum # allocated inodes */
name|__be64
name|d_ino_softlimit
decl_stmt|;
comment|/* preferred inode limit */
name|__be64
name|d_bcount
decl_stmt|;
comment|/* disk blocks owned by the user */
name|__be64
name|d_icount
decl_stmt|;
comment|/* inodes owned by the user */
name|__be32
name|d_itimer
decl_stmt|;
comment|/* zero if within inode limits if not, 					   this is when we refuse service */
name|__be32
name|d_btimer
decl_stmt|;
comment|/* similar to above; for disk blocks */
name|__be16
name|d_iwarns
decl_stmt|;
comment|/* warnings issued wrt num inodes */
name|__be16
name|d_bwarns
decl_stmt|;
comment|/* warnings issued wrt disk blocks */
name|__be32
name|d_pad0
decl_stmt|;
comment|/* 64 bit align */
name|__be64
name|d_rtb_hardlimit
decl_stmt|;
comment|/* absolute limit on realtime blks */
name|__be64
name|d_rtb_softlimit
decl_stmt|;
comment|/* preferred limit on RT disk blks */
name|__be64
name|d_rtbcount
decl_stmt|;
comment|/* realtime blocks owned */
name|__be32
name|d_rtbtimer
decl_stmt|;
comment|/* similar to above; for RT disk blocks */
name|__be16
name|d_rtbwarns
decl_stmt|;
comment|/* warnings issued wrt RT disk blocks */
name|__be16
name|d_pad
decl_stmt|;
block|}
name|xfs_disk_dquot_t
typedef|;
end_typedef

begin_comment
comment|/*  * This is what goes on disk. This is separated from the xfs_disk_dquot because  * carrying the unnecessary padding would be a waste of memory.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dqblk
block|{
name|xfs_disk_dquot_t
name|dd_diskdq
decl_stmt|;
comment|/* portion that lives incore as well */
name|char
name|dd_fill
index|[
literal|32
index|]
decl_stmt|;
comment|/* filling for posterity */
block|}
name|xfs_dqblk_t
typedef|;
end_typedef

begin_comment
comment|/*  * flags for q_flags field in the dquot.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DQ_USER
value|0x0001
end_define

begin_comment
comment|/* a user quota */
end_comment

begin_define
define|#
directive|define
name|XFS_DQ_PROJ
value|0x0002
end_define

begin_comment
comment|/* project quota */
end_comment

begin_define
define|#
directive|define
name|XFS_DQ_GROUP
value|0x0004
end_define

begin_comment
comment|/* a group quota */
end_comment

begin_define
define|#
directive|define
name|XFS_DQ_FLOCKED
value|0x0008
end_define

begin_comment
comment|/* flush lock taken */
end_comment

begin_define
define|#
directive|define
name|XFS_DQ_DIRTY
value|0x0010
end_define

begin_comment
comment|/* dquot is dirty */
end_comment

begin_define
define|#
directive|define
name|XFS_DQ_WANT
value|0x0020
end_define

begin_comment
comment|/* for lookup/reclaim race */
end_comment

begin_define
define|#
directive|define
name|XFS_DQ_INACTIVE
value|0x0040
end_define

begin_comment
comment|/* dq off mplist& hashlist */
end_comment

begin_define
define|#
directive|define
name|XFS_DQ_MARKER
value|0x0080
end_define

begin_comment
comment|/* sentinel */
end_comment

begin_define
define|#
directive|define
name|XFS_DQ_ALLTYPES
value|(XFS_DQ_USER|XFS_DQ_PROJ|XFS_DQ_GROUP)
end_define

begin_comment
comment|/*  * In the worst case, when both user and group quotas are on,  * we can have a max of three dquots changing in a single transaction.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DQUOT_LOGRES
parameter_list|(
name|mp
parameter_list|)
value|(sizeof(xfs_disk_dquot_t) * 3)
end_define

begin_comment
comment|/*  * These are the structures used to lay out dquots and quotaoff  * records on the log. Quite similar to those of inodes.  */
end_comment

begin_comment
comment|/*  * log format struct for dquots.  * The first two fields must be the type and size fitting into  * 32 bits : log_recovery code assumes that.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dq_logformat
block|{
name|__uint16_t
name|qlf_type
decl_stmt|;
comment|/* dquot log item type */
name|__uint16_t
name|qlf_size
decl_stmt|;
comment|/* size of this item */
name|xfs_dqid_t
name|qlf_id
decl_stmt|;
comment|/* usr/grp/proj id : 32 bits */
name|__int64_t
name|qlf_blkno
decl_stmt|;
comment|/* blkno of dquot buffer */
name|__int32_t
name|qlf_len
decl_stmt|;
comment|/* len of dquot buffer */
name|__uint32_t
name|qlf_boffset
decl_stmt|;
comment|/* off of dquot in buffer */
block|}
name|xfs_dq_logformat_t
typedef|;
end_typedef

begin_comment
comment|/*  * log format struct for QUOTAOFF records.  * The first two fields must be the type and size fitting into  * 32 bits : log_recovery code assumes that.  * We write two LI_QUOTAOFF logitems per quotaoff, the last one keeps a pointer  * to the first and ensures that the first logitem is taken out of the AIL  * only when the last one is securely committed.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_qoff_logformat
block|{
name|unsigned
name|short
name|qf_type
decl_stmt|;
comment|/* quotaoff log item type */
name|unsigned
name|short
name|qf_size
decl_stmt|;
comment|/* size of this item */
name|unsigned
name|int
name|qf_flags
decl_stmt|;
comment|/* USR and/or GRP */
name|char
name|qf_pad
index|[
literal|12
index|]
decl_stmt|;
comment|/* padding for future */
block|}
name|xfs_qoff_logformat_t
typedef|;
end_typedef

begin_comment
comment|/*  * Disk quotas status in m_qflags, and also sb_qflags. 16 bits.  */
end_comment

begin_define
define|#
directive|define
name|XFS_UQUOTA_ACCT
value|0x0001
end_define

begin_comment
comment|/* user quota accounting ON */
end_comment

begin_define
define|#
directive|define
name|XFS_UQUOTA_ENFD
value|0x0002
end_define

begin_comment
comment|/* user quota limits enforced */
end_comment

begin_define
define|#
directive|define
name|XFS_UQUOTA_CHKD
value|0x0004
end_define

begin_comment
comment|/* quotacheck run on usr quotas */
end_comment

begin_define
define|#
directive|define
name|XFS_PQUOTA_ACCT
value|0x0008
end_define

begin_comment
comment|/* project quota accounting ON */
end_comment

begin_define
define|#
directive|define
name|XFS_OQUOTA_ENFD
value|0x0010
end_define

begin_comment
comment|/* other (grp/prj) quota limits enforced */
end_comment

begin_define
define|#
directive|define
name|XFS_OQUOTA_CHKD
value|0x0020
end_define

begin_comment
comment|/* quotacheck run on other (grp/prj) quotas */
end_comment

begin_define
define|#
directive|define
name|XFS_GQUOTA_ACCT
value|0x0040
end_define

begin_comment
comment|/* group quota accounting ON */
end_comment

begin_comment
comment|/*  * Quota Accounting/Enforcement flags  */
end_comment

begin_define
define|#
directive|define
name|XFS_ALL_QUOTA_ACCT
define|\
value|(XFS_UQUOTA_ACCT | XFS_GQUOTA_ACCT | XFS_PQUOTA_ACCT)
end_define

begin_define
define|#
directive|define
name|XFS_ALL_QUOTA_ENFD
value|(XFS_UQUOTA_ENFD | XFS_OQUOTA_ENFD)
end_define

begin_define
define|#
directive|define
name|XFS_ALL_QUOTA_CHKD
value|(XFS_UQUOTA_CHKD | XFS_OQUOTA_CHKD)
end_define

begin_define
define|#
directive|define
name|XFS_IS_QUOTA_RUNNING
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_qflags& XFS_ALL_QUOTA_ACCT)
end_define

begin_define
define|#
directive|define
name|XFS_IS_QUOTA_ENFORCED
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_qflags& XFS_ALL_QUOTA_ENFD)
end_define

begin_define
define|#
directive|define
name|XFS_IS_UQUOTA_RUNNING
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_qflags& XFS_UQUOTA_ACCT)
end_define

begin_define
define|#
directive|define
name|XFS_IS_PQUOTA_RUNNING
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_qflags& XFS_PQUOTA_ACCT)
end_define

begin_define
define|#
directive|define
name|XFS_IS_GQUOTA_RUNNING
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_qflags& XFS_GQUOTA_ACCT)
end_define

begin_comment
comment|/*  * Incore only flags for quotaoff - these bits get cleared when quota(s)  * are in the process of getting turned off. These flags are in m_qflags but  * never in sb_qflags.  */
end_comment

begin_define
define|#
directive|define
name|XFS_UQUOTA_ACTIVE
value|0x0100
end_define

begin_comment
comment|/* uquotas are being turned off */
end_comment

begin_define
define|#
directive|define
name|XFS_PQUOTA_ACTIVE
value|0x0200
end_define

begin_comment
comment|/* pquotas are being turned off */
end_comment

begin_define
define|#
directive|define
name|XFS_GQUOTA_ACTIVE
value|0x0400
end_define

begin_comment
comment|/* gquotas are being turned off */
end_comment

begin_comment
comment|/*  * Checking XFS_IS_*QUOTA_ON() while holding any inode lock guarantees  * quota will be not be switched off as long as that inode lock is held.  */
end_comment

begin_define
define|#
directive|define
name|XFS_IS_QUOTA_ON
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_qflags& (XFS_UQUOTA_ACTIVE | \ 						   XFS_GQUOTA_ACTIVE | \ 						   XFS_PQUOTA_ACTIVE))
end_define

begin_define
define|#
directive|define
name|XFS_IS_OQUOTA_ON
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_qflags& (XFS_GQUOTA_ACTIVE | \ 						   XFS_PQUOTA_ACTIVE))
end_define

begin_define
define|#
directive|define
name|XFS_IS_UQUOTA_ON
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_qflags& XFS_UQUOTA_ACTIVE)
end_define

begin_define
define|#
directive|define
name|XFS_IS_GQUOTA_ON
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_qflags& XFS_GQUOTA_ACTIVE)
end_define

begin_define
define|#
directive|define
name|XFS_IS_PQUOTA_ON
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_qflags& XFS_PQUOTA_ACTIVE)
end_define

begin_comment
comment|/*  * Flags to tell various functions what to do. Not all of these are meaningful  * to a single function. None of these XFS_QMOPT_* flags are meant to have  * persistent values (ie. their values can and will change between versions)  */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_DQLOCK
value|0x0000001
end_define

begin_comment
comment|/* dqlock */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_DQALLOC
value|0x0000002
end_define

begin_comment
comment|/* alloc dquot ondisk if needed */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_UQUOTA
value|0x0000004
end_define

begin_comment
comment|/* user dquot requested */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_PQUOTA
value|0x0000008
end_define

begin_comment
comment|/* project dquot requested */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_FORCE_RES
value|0x0000010
end_define

begin_comment
comment|/* ignore quota limits */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_DQSUSER
value|0x0000020
end_define

begin_comment
comment|/* don't cache super users dquot */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_SBVERSION
value|0x0000040
end_define

begin_comment
comment|/* change superblock version num */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_QUOTAOFF
value|0x0000080
end_define

begin_comment
comment|/* quotas are being turned off */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_UMOUNTING
value|0x0000100
end_define

begin_comment
comment|/* filesys is being unmounted */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_DOLOG
value|0x0000200
end_define

begin_comment
comment|/* log buf changes (in quotacheck) */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_DOWARN
value|0x0000400
end_define

begin_comment
comment|/* increase warning cnt if needed */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_ILOCKED
value|0x0000800
end_define

begin_comment
comment|/* inode is already locked (excl) */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_DQREPAIR
value|0x0001000
end_define

begin_comment
comment|/* repair dquot if damaged */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_GQUOTA
value|0x0002000
end_define

begin_comment
comment|/* group dquot requested */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_ENOSPC
value|0x0004000
end_define

begin_comment
comment|/* enospc instead of edquot (prj) */
end_comment

begin_comment
comment|/*  * flags to xfs_trans_mod_dquot to indicate which field needs to be  * modified.  */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_RES_REGBLKS
value|0x0010000
end_define

begin_define
define|#
directive|define
name|XFS_QMOPT_RES_RTBLKS
value|0x0020000
end_define

begin_define
define|#
directive|define
name|XFS_QMOPT_BCOUNT
value|0x0040000
end_define

begin_define
define|#
directive|define
name|XFS_QMOPT_ICOUNT
value|0x0080000
end_define

begin_define
define|#
directive|define
name|XFS_QMOPT_RTBCOUNT
value|0x0100000
end_define

begin_define
define|#
directive|define
name|XFS_QMOPT_DELBCOUNT
value|0x0200000
end_define

begin_define
define|#
directive|define
name|XFS_QMOPT_DELRTBCOUNT
value|0x0400000
end_define

begin_define
define|#
directive|define
name|XFS_QMOPT_RES_INOS
value|0x0800000
end_define

begin_comment
comment|/*  * flags for dqflush and dqflush_all.  */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_SYNC
value|0x1000000
end_define

begin_define
define|#
directive|define
name|XFS_QMOPT_ASYNC
value|0x2000000
end_define

begin_define
define|#
directive|define
name|XFS_QMOPT_DELWRI
value|0x4000000
end_define

begin_comment
comment|/*  * flags for dqalloc.  */
end_comment

begin_define
define|#
directive|define
name|XFS_QMOPT_INHERIT
value|0x8000000
end_define

begin_comment
comment|/*  * flags to xfs_trans_mod_dquot.  */
end_comment

begin_define
define|#
directive|define
name|XFS_TRANS_DQ_RES_BLKS
value|XFS_QMOPT_RES_REGBLKS
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_DQ_RES_RTBLKS
value|XFS_QMOPT_RES_RTBLKS
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_DQ_RES_INOS
value|XFS_QMOPT_RES_INOS
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_DQ_BCOUNT
value|XFS_QMOPT_BCOUNT
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_DQ_DELBCOUNT
value|XFS_QMOPT_DELBCOUNT
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_DQ_ICOUNT
value|XFS_QMOPT_ICOUNT
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_DQ_RTBCOUNT
value|XFS_QMOPT_RTBCOUNT
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_DQ_DELRTBCOUNT
value|XFS_QMOPT_DELRTBCOUNT
end_define

begin_define
define|#
directive|define
name|XFS_QMOPT_QUOTALL
define|\
value|(XFS_QMOPT_UQUOTA | XFS_QMOPT_PQUOTA | XFS_QMOPT_GQUOTA)
end_define

begin_define
define|#
directive|define
name|XFS_QMOPT_RESBLK_MASK
value|(XFS_QMOPT_RES_REGBLKS | XFS_QMOPT_RES_RTBLKS)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * This check is done typically without holding the inode lock;  * that may seem racy, but it is harmless in the context that it is used.  * The inode cannot go inactive as long a reference is kept, and  * therefore if dquot(s) were attached, they'll stay consistent.  * If, for example, the ownership of the inode changes while  * we didn't have the inode locked, the appropriate dquot(s) will be  * attached atomically.  */
end_comment

begin_define
define|#
directive|define
name|XFS_NOT_DQATTACHED
parameter_list|(
name|mp
parameter_list|,
name|ip
parameter_list|)
value|((XFS_IS_UQUOTA_ON(mp)&&\ 				     (ip)->i_udquot == NULL) || \ 				    (XFS_IS_OQUOTA_ON(mp)&& \ 				     (ip)->i_gdquot == NULL))
end_define

begin_define
define|#
directive|define
name|XFS_QM_NEED_QUOTACHECK
parameter_list|(
name|mp
parameter_list|)
define|\
value|((XFS_IS_UQUOTA_ON(mp)&& \ 		(mp->m_sb.sb_qflags& XFS_UQUOTA_CHKD) == 0) || \ 	 (XFS_IS_GQUOTA_ON(mp)&& \ 		((mp->m_sb.sb_qflags& XFS_OQUOTA_CHKD) == 0 || \ 		 (mp->m_sb.sb_qflags& XFS_PQUOTA_ACCT))) || \ 	 (XFS_IS_PQUOTA_ON(mp)&& \ 		((mp->m_sb.sb_qflags& XFS_OQUOTA_CHKD) == 0 || \ 		 (mp->m_sb.sb_qflags& XFS_GQUOTA_ACCT))))
end_define

begin_define
define|#
directive|define
name|XFS_MOUNT_QUOTA_SET1
value|(XFS_UQUOTA_ACCT|XFS_UQUOTA_ENFD|\ 				 XFS_UQUOTA_CHKD|XFS_PQUOTA_ACCT|\ 				 XFS_OQUOTA_ENFD|XFS_OQUOTA_CHKD)
end_define

begin_define
define|#
directive|define
name|XFS_MOUNT_QUOTA_SET2
value|(XFS_UQUOTA_ACCT|XFS_UQUOTA_ENFD|\ 				 XFS_UQUOTA_CHKD|XFS_GQUOTA_ACCT|\ 				 XFS_OQUOTA_ENFD|XFS_OQUOTA_CHKD)
end_define

begin_define
define|#
directive|define
name|XFS_MOUNT_QUOTA_ALL
value|(XFS_UQUOTA_ACCT|XFS_UQUOTA_ENFD|\ 				 XFS_UQUOTA_CHKD|XFS_PQUOTA_ACCT|\ 				 XFS_OQUOTA_ENFD|XFS_OQUOTA_CHKD|\ 				 XFS_GQUOTA_ACCT)
end_define

begin_define
define|#
directive|define
name|XFS_MOUNT_QUOTA_MASK
value|(XFS_MOUNT_QUOTA_ALL | XFS_UQUOTA_ACTIVE | \ 				 XFS_GQUOTA_ACTIVE | XFS_PQUOTA_ACTIVE)
end_define

begin_comment
comment|/*  * The structure kept inside the xfs_trans_t keep track of dquot changes  * within a transaction and apply them later.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dqtrx
block|{
name|struct
name|xfs_dquot
modifier|*
name|qt_dquot
decl_stmt|;
comment|/* the dquot this refers to */
name|ulong
name|qt_blk_res
decl_stmt|;
comment|/* blks reserved on a dquot */
name|ulong
name|qt_blk_res_used
decl_stmt|;
comment|/* blks used from the reservation */
name|ulong
name|qt_ino_res
decl_stmt|;
comment|/* inode reserved on a dquot */
name|ulong
name|qt_ino_res_used
decl_stmt|;
comment|/* inodes used from the reservation */
name|long
name|qt_bcount_delta
decl_stmt|;
comment|/* dquot blk count changes */
name|long
name|qt_delbcnt_delta
decl_stmt|;
comment|/* delayed dquot blk count changes */
name|long
name|qt_icount_delta
decl_stmt|;
comment|/* dquot inode count changes */
name|ulong
name|qt_rtblk_res
decl_stmt|;
comment|/* # blks reserved on a dquot */
name|ulong
name|qt_rtblk_res_used
decl_stmt|;
comment|/* # blks used from reservation */
name|long
name|qt_rtbcount_delta
decl_stmt|;
comment|/* dquot realtime blk changes */
name|long
name|qt_delrtb_delta
decl_stmt|;
comment|/* delayed RT blk count changes */
block|}
name|xfs_dqtrx_t
typedef|;
end_typedef

begin_comment
comment|/*  * Dquot transaction functions, used if quota is enabled.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|qo_dup_dqinfo_t
function_decl|)
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|struct
name|xfs_trans
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|qo_mod_dquot_byino_t
function_decl|)
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|uint
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|qo_free_dqinfo_t
function_decl|)
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|qo_apply_dquot_deltas_t
function_decl|)
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|qo_unreserve_and_mod_dquots_t
function_decl|)
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|qo_reserve_quota_nblks_t
function_decl|)
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|long
parameter_list|,
name|long
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|qo_reserve_quota_bydquots_t
function_decl|)
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|struct
name|xfs_dquot
modifier|*
parameter_list|,
name|struct
name|xfs_dquot
modifier|*
parameter_list|,
name|long
parameter_list|,
name|long
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_dqtrxops
block|{
name|qo_dup_dqinfo_t
name|qo_dup_dqinfo
decl_stmt|;
name|qo_free_dqinfo_t
name|qo_free_dqinfo
decl_stmt|;
name|qo_mod_dquot_byino_t
name|qo_mod_dquot_byino
decl_stmt|;
name|qo_apply_dquot_deltas_t
name|qo_apply_dquot_deltas
decl_stmt|;
name|qo_reserve_quota_nblks_t
name|qo_reserve_quota_nblks
decl_stmt|;
name|qo_reserve_quota_bydquots_t
name|qo_reserve_quota_bydquots
decl_stmt|;
name|qo_unreserve_and_mod_dquots_t
name|qo_unreserve_and_mod_dquots
decl_stmt|;
block|}
name|xfs_dqtrxops_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_DQTRXOP
parameter_list|(
name|mp
parameter_list|,
name|tp
parameter_list|,
name|op
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|((mp)->m_qm_ops.xfs_dqtrxops ? \ 		((mp)->m_qm_ops.xfs_dqtrxops->op)(tp, ## args) : 0)
end_define

begin_define
define|#
directive|define
name|XFS_DQTRXOP_VOID
parameter_list|(
name|mp
parameter_list|,
name|tp
parameter_list|,
name|op
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|((mp)->m_qm_ops.xfs_dqtrxops ? \ 		((mp)->m_qm_ops.xfs_dqtrxops->op)(tp, ## args) : (void)0)
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_DUP_DQINFO
parameter_list|(
name|mp
parameter_list|,
name|otp
parameter_list|,
name|ntp
parameter_list|)
define|\
value|XFS_DQTRXOP_VOID(mp, otp, qo_dup_dqinfo, ntp)
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_FREE_DQINFO
parameter_list|(
name|mp
parameter_list|,
name|tp
parameter_list|)
define|\
value|XFS_DQTRXOP_VOID(mp, tp, qo_free_dqinfo)
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_MOD_DQUOT_BYINO
parameter_list|(
name|mp
parameter_list|,
name|tp
parameter_list|,
name|ip
parameter_list|,
name|field
parameter_list|,
name|delta
parameter_list|)
define|\
value|XFS_DQTRXOP_VOID(mp, tp, qo_mod_dquot_byino, ip, field, delta)
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_APPLY_DQUOT_DELTAS
parameter_list|(
name|mp
parameter_list|,
name|tp
parameter_list|)
define|\
value|XFS_DQTRXOP_VOID(mp, tp, qo_apply_dquot_deltas)
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_RESERVE_QUOTA_NBLKS
parameter_list|(
name|mp
parameter_list|,
name|tp
parameter_list|,
name|ip
parameter_list|,
name|nblks
parameter_list|,
name|ninos
parameter_list|,
name|fl
parameter_list|)
define|\
value|XFS_DQTRXOP(mp, tp, qo_reserve_quota_nblks, mp, ip, nblks, ninos, fl)
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_RESERVE_QUOTA_BYDQUOTS
parameter_list|(
name|mp
parameter_list|,
name|tp
parameter_list|,
name|ud
parameter_list|,
name|gd
parameter_list|,
name|nb
parameter_list|,
name|ni
parameter_list|,
name|fl
parameter_list|)
define|\
value|XFS_DQTRXOP(mp, tp, qo_reserve_quota_bydquots, mp, ud, gd, nb, ni, fl)
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_UNRESERVE_AND_MOD_DQUOTS
parameter_list|(
name|mp
parameter_list|,
name|tp
parameter_list|)
define|\
value|XFS_DQTRXOP_VOID(mp, tp, qo_unreserve_and_mod_dquots)
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_UNRESERVE_QUOTA_NBLKS
parameter_list|(
name|mp
parameter_list|,
name|tp
parameter_list|,
name|ip
parameter_list|,
name|nblks
parameter_list|,
name|ninos
parameter_list|,
name|flags
parameter_list|)
define|\
value|XFS_TRANS_RESERVE_QUOTA_NBLKS(mp, tp, ip, -(nblks), -(ninos), flags)
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_RESERVE_QUOTA
parameter_list|(
name|mp
parameter_list|,
name|tp
parameter_list|,
name|ud
parameter_list|,
name|gd
parameter_list|,
name|nb
parameter_list|,
name|ni
parameter_list|,
name|f
parameter_list|)
define|\
value|XFS_TRANS_RESERVE_QUOTA_BYDQUOTS(mp, tp, ud, gd, nb, ni, \ 				f | XFS_QMOPT_RES_REGBLKS)
end_define

begin_define
define|#
directive|define
name|XFS_TRANS_UNRESERVE_QUOTA
parameter_list|(
name|mp
parameter_list|,
name|tp
parameter_list|,
name|ud
parameter_list|,
name|gd
parameter_list|,
name|nb
parameter_list|,
name|ni
parameter_list|,
name|f
parameter_list|)
define|\
value|XFS_TRANS_RESERVE_QUOTA_BYDQUOTS(mp, tp, ud, gd, -(nb), -(ni), \ 				f | XFS_QMOPT_RES_REGBLKS)
end_define

begin_function_decl
specifier|extern
name|int
name|xfs_qm_dqcheck
parameter_list|(
name|xfs_disk_dquot_t
modifier|*
parameter_list|,
name|xfs_dqid_t
parameter_list|,
name|uint
parameter_list|,
name|uint
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_mount_reset_sbqflags
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|bhv_vfsops
name|xfs_qmops
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_QUOTA_H__ */
end_comment

end_unit

