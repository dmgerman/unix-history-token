begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Paul Popelka (paulp@uts.amdahl.com)  *   * You can do anything you want with this software, just don't say you wrote  * it, and don't remove this notice.  *   * This software is provided "as is".  *   * The author supplies this software to be publicly redistributed on the  * understanding that the author is not responsible for the correct  * functioning of this software in any circumstances and is not liable for  * any damages caused by this software.  *   * October 1992  *   *	from NetBSD:	msdosfsmount.h,v 1.1 1993/08/13 11:35:41 cgd Exp  *	$Id$  */
end_comment

begin_comment
comment|/*  * Layout of the mount control block for a msdos file system.  */
end_comment

begin_struct
struct|struct
name|msdosfsmount
block|{
name|struct
name|mount
modifier|*
name|pm_mountp
decl_stmt|;
comment|/* vfs mount struct for this fs */
name|dev_t
name|pm_dev
decl_stmt|;
comment|/* block special device mounted */
name|struct
name|vnode
modifier|*
name|pm_devvp
decl_stmt|;
comment|/* vnode for block device mntd */
name|struct
name|bpb50
name|pm_bpb
decl_stmt|;
comment|/* BIOS parameter blk for this fs */
name|u_long
name|pm_fatblk
decl_stmt|;
comment|/* block # of first FAT */
name|u_long
name|pm_rootdirblk
decl_stmt|;
comment|/* block # of root directory */
name|u_long
name|pm_rootdirsize
decl_stmt|;
comment|/* size in blocks (not clusters) */
name|u_long
name|pm_firstcluster
decl_stmt|;
comment|/* block number of first cluster */
name|u_long
name|pm_nmbrofclusters
decl_stmt|;
comment|/* # of clusters in filesystem */
name|u_long
name|pm_maxcluster
decl_stmt|;
comment|/* maximum cluster number */
name|u_long
name|pm_freeclustercount
decl_stmt|;
comment|/* number of free clusters */
name|u_long
name|pm_lookhere
decl_stmt|;
comment|/* start free cluster search here */
name|u_long
name|pm_bnshift
decl_stmt|;
comment|/* shift file offset right this amount to get a block number */
name|u_long
name|pm_brbomask
decl_stmt|;
comment|/* and a file offset with this mask to get block rel offset */
name|u_long
name|pm_cnshift
decl_stmt|;
comment|/* shift file offset right this amount to get a cluster number */
name|u_long
name|pm_crbomask
decl_stmt|;
comment|/* and a file offset with this mask to get cluster rel offset */
name|u_long
name|pm_bpcluster
decl_stmt|;
comment|/* bytes per cluster */
name|u_long
name|pm_depclust
decl_stmt|;
comment|/* directory entries per cluster */
name|u_long
name|pm_fmod
decl_stmt|;
comment|/* ~0 if fs is modified, this can rollover to 0	*/
name|u_long
name|pm_fatblocksize
decl_stmt|;
comment|/* size of fat blocks in bytes */
name|u_long
name|pm_fatblocksec
decl_stmt|;
comment|/* size of fat blocks in sectors */
name|u_long
name|pm_fatsize
decl_stmt|;
comment|/* size of fat in bytes */
name|u_char
modifier|*
name|pm_inusemap
decl_stmt|;
comment|/* ptr to bitmap of in-use clusters */
name|char
name|pm_ronly
decl_stmt|;
comment|/* read only if non-zero */
name|char
name|pm_waitonfat
decl_stmt|;
comment|/* wait for writes of the fat to complt, when 0 use bdwrite, else use bwrite */
block|}
struct|;
end_struct

begin_comment
comment|/*  * How to compute pm_cnshift and pm_crbomask.  *   * pm_crbomask = (pm_SectPerClust * pm_BytesPerSect) - 1   * if (bytesperclust == * 0)   * 	return EBADBLKSZ;   * bit = 1;   * for (i = 0; i< 32; i++) {   *	if (bit& bytesperclust) {   *		if (bit ^ bytesperclust)   *			return EBADBLKSZ;   *		pm_cnshift = * i;   *		break;   *	}   *	bit<<= 1;   * }  */
end_comment

begin_comment
comment|/*  * Shorthand for fields in the bpb contained in the msdosfsmount structure.  */
end_comment

begin_define
define|#
directive|define
name|pm_BytesPerSec
value|pm_bpb.bpbBytesPerSec
end_define

begin_define
define|#
directive|define
name|pm_SectPerClust
value|pm_bpb.bpbSecPerClust
end_define

begin_define
define|#
directive|define
name|pm_ResSectors
value|pm_bpb.bpbResSectors
end_define

begin_define
define|#
directive|define
name|pm_FATs
value|pm_bpb.bpbFATs
end_define

begin_define
define|#
directive|define
name|pm_RootDirEnts
value|pm_bpb.bpbRootDirEnts
end_define

begin_define
define|#
directive|define
name|pm_Sectors
value|pm_bpb.bpbSectors
end_define

begin_define
define|#
directive|define
name|pm_Media
value|pm_bpb.bpbMedia
end_define

begin_define
define|#
directive|define
name|pm_FATsecs
value|pm_bpb.bpbFATsecs
end_define

begin_define
define|#
directive|define
name|pm_SecPerTrack
value|pm_bpb.bpbSecPerTrack
end_define

begin_define
define|#
directive|define
name|pm_Heads
value|pm_bpb.bpbHeads
end_define

begin_define
define|#
directive|define
name|pm_HiddenSects
value|pm_bpb.bpbHiddenSecs
end_define

begin_define
define|#
directive|define
name|pm_HugeSectors
value|pm_bpb.bpbHugeSectors
end_define

begin_comment
comment|/*  * Map a cluster number into a filesystem relative block number.  */
end_comment

begin_define
define|#
directive|define
name|cntobn
parameter_list|(
name|pmp
parameter_list|,
name|cn
parameter_list|)
define|\
value|((((cn)-CLUST_FIRST) * (pmp)->pm_SectPerClust) + (pmp)->pm_firstcluster)
end_define

begin_comment
comment|/*  * Map a filesystem relative block number back into a cluster number.  */
end_comment

begin_define
define|#
directive|define
name|bntocn
parameter_list|(
name|pmp
parameter_list|,
name|bn
parameter_list|)
define|\
value|((((bn) - pmp->pm_firstcluster)/ (pmp)->pm_SectPerClust) + CLUST_FIRST)
end_define

begin_comment
comment|/*  * Calculate block number for directory entry in root dir, offset dirofs  */
end_comment

begin_define
define|#
directive|define
name|roottobn
parameter_list|(
name|pmp
parameter_list|,
name|dirofs
parameter_list|)
define|\
value|(((dirofs) / (pmp)->pm_depclust) * (pmp)->pm_SectPerClust \ 	+ (pmp)->pm_rootdirblk)
end_define

begin_comment
comment|/*  * Calculate block number for directory entry at cluster dirclu, offset  * dirofs  */
end_comment

begin_define
define|#
directive|define
name|detobn
parameter_list|(
name|pmp
parameter_list|,
name|dirclu
parameter_list|,
name|dirofs
parameter_list|)
define|\
value|((dirclu) == MSDOSFSROOT \ 	 ? roottobn((pmp), (dirofs)) \ 	 : cntobn((pmp), (dirclu)))
end_define

begin_comment
comment|/*  * Convert pointer to buffer -> pointer to direntry  */
end_comment

begin_define
define|#
directive|define
name|bptoep
parameter_list|(
name|pmp
parameter_list|,
name|bp
parameter_list|,
name|dirofs
parameter_list|)
define|\
value|((struct direntry *)((bp)->b_un.b_addr)	\ 	 + (dirofs) % (pmp)->pm_depclust)
end_define

begin_comment
comment|/*  * Prototypes for MSDOSFS virtual filesystem operations  */
end_comment

begin_decl_stmt
name|int
name|msdosfs_mount
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|char
operator|*
name|path
operator|,
name|caddr_t
name|data
operator|,
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_start
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|flags
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_unmount
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|mntflags
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_root
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_quotactl
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|cmds
operator|,
name|int
name|uid
comment|/* should be uid_t */
operator|,
name|caddr_t
name|arg
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_statfs
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
expr|struct
name|statfs
operator|*
name|sbp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_sync
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|waitfor
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_fhtovp
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
expr|struct
name|fid
operator|*
name|fhp
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_vptofh
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|fid
operator|*
name|fhp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msdosfs_init
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

