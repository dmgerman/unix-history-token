begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: msdosfsmount.h,v 1.15 1998/02/23 09:39:29 ache Exp $ */
end_comment

begin_comment
comment|/*	$NetBSD: msdosfsmount.h,v 1.17 1997/11/17 15:37:07 ws Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1994, 1995, 1997 Wolfgang Solfrank.  * Copyright (C) 1994, 1995, 1997 TooLs GmbH.  * All rights reserved.  * Original code by Paul Popelka (paulp@uts.amdahl.com) (see below).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
name|pm_FATsecs
decl_stmt|;
comment|/* actual number of fat sectors */
name|u_long
name|pm_fatblk
decl_stmt|;
comment|/* block # of first FAT */
name|u_long
name|pm_rootdirblk
decl_stmt|;
comment|/* block # (cluster # for FAT32) of root directory number */
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
name|pm_cnshift
decl_stmt|;
comment|/* shift file offset right this amount to get a cluster number */
name|u_long
name|pm_crbomask
decl_stmt|;
comment|/* and a file offset with this mask to get cluster rel offset */
name|u_long
name|pm_bnshift
decl_stmt|;
comment|/* shift file offset right this amount to get a block number */
name|u_long
name|pm_bpcluster
decl_stmt|;
comment|/* bytes per cluster */
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
name|u_long
name|pm_fatmask
decl_stmt|;
comment|/* mask to use for fat numbers */
name|u_long
name|pm_fsinfo
decl_stmt|;
comment|/* fsinfo block number */
name|u_long
name|pm_nxtfree
decl_stmt|;
comment|/* next free cluster in fsinfo block */
name|u_int
name|pm_fatmult
decl_stmt|;
comment|/* these 2 values are used in fat */
name|u_int
name|pm_fatdiv
decl_stmt|;
comment|/*	offset computation */
name|u_int
name|pm_curfat
decl_stmt|;
comment|/* current fat for FAT32 (0 otherwise) */
name|u_int
modifier|*
name|pm_inusemap
decl_stmt|;
comment|/* ptr to bitmap of in-use clusters */
name|u_int
name|pm_flags
decl_stmt|;
comment|/* see below */
name|struct
name|netexport
name|pm_export
decl_stmt|;
comment|/* export information */
name|u_int16_t
name|pm_u2w
index|[
literal|128
index|]
decl_stmt|;
comment|/* Local->Unicode table */
name|u_int8_t
name|pm_ul
index|[
literal|128
index|]
decl_stmt|;
comment|/* Local upper->lower table */
name|u_int8_t
name|pm_lu
index|[
literal|128
index|]
decl_stmt|;
comment|/* Local lower->upper table */
name|u_int8_t
name|pm_d2u
index|[
literal|128
index|]
decl_stmt|;
comment|/* DOS->local table */
name|u_int8_t
name|pm_u2d
index|[
literal|128
index|]
decl_stmt|;
comment|/* Local->DOS table */
block|}
struct|;
end_struct

begin_comment
comment|/* Byte offset in FAT on filesystem pmp, cluster cn */
end_comment

begin_define
define|#
directive|define
name|FATOFS
parameter_list|(
name|pmp
parameter_list|,
name|cn
parameter_list|)
value|((cn) * (pmp)->pm_fatmult / (pmp)->pm_fatdiv)
end_define

begin_define
define|#
directive|define
name|VFSTOMSDOSFS
parameter_list|(
name|mp
parameter_list|)
value|((struct msdosfsmount *)mp->mnt_data)
end_define

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
value|((struct direntry *)(((bp)->b_data)	\ 	 + ((dirofs)& (pmp)->pm_crbomask)))
end_define

begin_comment
comment|/*  * Convert block number to cluster number  */
end_comment

begin_define
define|#
directive|define
name|de_bn2cn
parameter_list|(
name|pmp
parameter_list|,
name|bn
parameter_list|)
define|\
value|((bn)>> ((pmp)->pm_cnshift - (pmp)->pm_bnshift))
end_define

begin_comment
comment|/*  * Convert cluster number to block number  */
end_comment

begin_define
define|#
directive|define
name|de_cn2bn
parameter_list|(
name|pmp
parameter_list|,
name|cn
parameter_list|)
define|\
value|((cn)<< ((pmp)->pm_cnshift - (pmp)->pm_bnshift))
end_define

begin_comment
comment|/*  * Convert file offset to cluster number  */
end_comment

begin_define
define|#
directive|define
name|de_cluster
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

begin_comment
comment|/*  * Convert file offset to block number  */
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
value|(de_cn2bn(pmp, de_cluster((pmp), (off))))
end_define

begin_comment
comment|/*  * Convert cluster number to file offset  */
end_comment

begin_define
define|#
directive|define
name|de_cn2off
parameter_list|(
name|pmp
parameter_list|,
name|cn
parameter_list|)
define|\
value|((cn)<< (pmp)->pm_cnshift)
end_define

begin_comment
comment|/*  * Convert block number to file offset  */
end_comment

begin_define
define|#
directive|define
name|de_bn2off
parameter_list|(
name|pmp
parameter_list|,
name|bn
parameter_list|)
define|\
value|((bn)<< (pmp)->pm_bnshift)
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
value|(de_cn2bn((pmp), (cn)-CLUST_FIRST) + (pmp)->pm_firstcluster)
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
value|(de_blk((pmp), (dirofs)) + (pmp)->pm_rootdirblk)
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

begin_decl_stmt
name|int
name|msdosfs_mountroot
name|__P
argument_list|(
operator|(
name|void
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
name|int
name|flags
decl_stmt|;
comment|/* see below */
name|int
name|magic
decl_stmt|;
comment|/* version number */
name|u_int16_t
name|u2w
index|[
literal|128
index|]
decl_stmt|;
comment|/* Local->Unicode table */
name|u_int8_t
name|ul
index|[
literal|128
index|]
decl_stmt|;
comment|/* Local upper->lower table */
name|u_int8_t
name|lu
index|[
literal|128
index|]
decl_stmt|;
comment|/* Local lower->upper table */
name|u_int8_t
name|d2u
index|[
literal|128
index|]
decl_stmt|;
comment|/* DOS->local table */
name|u_int8_t
name|u2d
index|[
literal|128
index|]
decl_stmt|;
comment|/* Local->DOS table */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Msdosfs mount options:  */
end_comment

begin_define
define|#
directive|define
name|MSDOSFSMNT_SHORTNAME
value|1
end_define

begin_comment
comment|/* Force old DOS short names only */
end_comment

begin_define
define|#
directive|define
name|MSDOSFSMNT_LONGNAME
value|2
end_define

begin_comment
comment|/* Force Win'95 long names */
end_comment

begin_define
define|#
directive|define
name|MSDOSFSMNT_NOWIN95
value|4
end_define

begin_comment
comment|/* Completely ignore Win95 entries */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_define
define|#
directive|define
name|MSDOSFSMNT_GEMDOSFS
value|8
end_define

begin_comment
comment|/* This is a gemdos-flavour */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MSDOSFSMNT_U2WTABLE
value|0x10
end_define

begin_comment
comment|/* Local->Unicode and local<->DOS   */
end_comment

begin_comment
comment|/* tables loaded                    */
end_comment

begin_define
define|#
directive|define
name|MSDOSFSMNT_ULTABLE
value|0x20
end_define

begin_comment
comment|/* Local upper<->lower table loaded */
end_comment

begin_comment
comment|/* All flags above: */
end_comment

begin_define
define|#
directive|define
name|MSDOSFSMNT_MNTOPT
define|\
value|(MSDOSFSMNT_SHORTNAME|MSDOSFSMNT_LONGNAME|MSDOSFSMNT_NOWIN95 \
comment|/*|MSDOSFSMNT_GEMDOSFS*/
value||MSDOSFSMNT_U2WTABLE|MSDOSFSMNT_ULTABLE)
end_define

begin_define
define|#
directive|define
name|MSDOSFSMNT_RONLY
value|0x80000000
end_define

begin_comment
comment|/* mounted read-only	*/
end_comment

begin_define
define|#
directive|define
name|MSDOSFSMNT_WAITONFAT
value|0x40000000
end_define

begin_comment
comment|/* mounted synchronous	*/
end_comment

begin_define
define|#
directive|define
name|MSDOSFS_FATMIRROR
value|0x20000000
end_define

begin_comment
comment|/* FAT is mirrored */
end_comment

begin_define
define|#
directive|define
name|MSDOSFS_ARGSMAGIC
value|0xe4eff300
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MSDOSFS_MSDOSFSMOUNT_H_ */
end_comment

end_unit

