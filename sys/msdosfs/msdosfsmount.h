begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: msdosfsmount.h,v 1.11 1997/03/03 17:36:11 bde Exp $ */
end_comment

begin_comment
comment|/*	$NetBSD: msdosfsmount.h,v 1.7 1994/08/21 18:44:17 ws Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1994 Wolfgang Solfrank.  * Copyright (C) 1994 TooLs GmbH.  * All rights reserved.  * Original code by Paul Popelka (paulp@uts.amdahl.com) (see below).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Written by Paul Popelka (paulp@uts.amdahl.com)  *  * You can do anything you want with this software, just don't say you wrote  * it, and don't remove this notice.  *  * This software is provided "as is".  *  * The author supplies this software to be publicly redistributed on the  * understanding that the author is not responsible for the correct  * functioning of this software in any circumstances and is not liable for  * any damages caused by this software.  *  * October 1992  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MSDOSFS_MSDOSFSMOUNT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MSDOSFS_MSDOSFSMOUNT_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_MSDOSFSMNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|uid_t
name|pm_mounter
decl_stmt|;
comment|/* uid of the user who mounted the FS */
name|uid_t
name|pm_uid
decl_stmt|;
comment|/* uid to set as owner of the files */
name|gid_t
name|pm_gid
decl_stmt|;
comment|/* gid to set as owner of the files */
name|mode_t
name|pm_mask
decl_stmt|;
comment|/* mask to and with file protection bits */
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
name|u_int
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
comment|/* wait for writes of the fat to complete, when 0 use bdwrite, else use bwrite */
name|struct
name|netexport
name|pm_export
decl_stmt|;
comment|/* export information */
block|}
struct|;
end_struct

begin_comment
comment|/* Number of bits in one pm_inusemap item: */
end_comment

begin_define
define|#
directive|define
name|N_INUSEBITS
value|(8 * sizeof(u_int))
end_define

begin_comment
comment|/*  * How to compute pm_cnshift and pm_crbomask.  *  * pm_crbomask = (pm_SectPerClust * pm_BytesPerSect) - 1  * if (bytesperclust == * 0)  * 	return EBADBLKSZ;  * bit = 1;  * for (i = 0; i< 32; i++) {  *	if (bit& bytesperclust) {  *		if (bit ^ bytesperclust)  *			return EBADBLKSZ;  *		pm_cnshift = * i;  *		break;  *	}  *	bit<<= 1;  * }  */
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
value|((struct direntry *)((bp)->b_data)	\ 	 + (dirofs) % (pmp)->pm_depclust)
end_define

begin_comment
comment|/*  * Convert filesize to block number  */
end_comment

begin_define
define|#
directive|define
name|de_blk
parameter_list|(
name|pmp
parameter_list|,
name|off
parameter_list|)
define|\
value|((off)>> (pmp)->pm_cnshift)
end_define

begin_comment
comment|/*  * Clusters required to hold size bytes  */
end_comment

begin_define
define|#
directive|define
name|de_clcount
parameter_list|(
name|pmp
parameter_list|,
name|size
parameter_list|)
define|\
value|(((size) + (pmp)->pm_bpcluster - 1)>> (pmp)->pm_cnshift)
end_define

begin_decl_stmt
name|int
name|msdosfs_init
name|__P
argument_list|(
operator|(
expr|struct
name|vfsconf
operator|*
name|vfsp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/*  *  Arguments to mount MSDOS filesystems.  */
end_comment

begin_struct
struct|struct
name|msdosfs_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
comment|/* blocks special holding the fs to mount */
name|struct
name|export_args
name|export
decl_stmt|;
comment|/* network export information */
name|uid_t
name|uid
decl_stmt|;
comment|/* uid that owns msdosfs files */
name|gid_t
name|gid
decl_stmt|;
comment|/* gid that owns msdosfs files */
name|mode_t
name|mask
decl_stmt|;
comment|/* mask to be applied for msdosfs perms */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MSDOSFS_MSDOSFSMOUNT_H_ */
end_comment

end_unit

