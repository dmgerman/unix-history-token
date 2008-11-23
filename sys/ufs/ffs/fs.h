begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: fs.h,v 1.44 2004/05/25 14:54:59 hannken Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fs.h	8.13 (Berkeley) 3/21/95  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_FFS_FS_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_FFS_FS_H_
end_define

begin_comment
comment|/*  * Each disk drive contains some number of file systems.  * A file system consists of a number of cylinder groups.  * Each cylinder group has inodes and data.  *  * A file system is described by its super-block, which in turn  * describes the cylinder groups.  The super-block is critical  * data and is replicated in each cylinder group to protect against  * catastrophic loss.  This is done at `newfs' time and the critical  * super-block data does not change, so the copies need not be  * referenced further unless disaster strikes.  *  * For file system fs, the offsets of the various blocks of interest  * are given in the super block as:  *	[fs->fs_sblkno]		Super-block  *	[fs->fs_cblkno]		Cylinder group block  *	[fs->fs_iblkno]		Inode blocks  *	[fs->fs_dblkno]		Data blocks  * The beginning of cylinder group cg in fs, is given by  * the ``cgbase(fs, cg)'' macro.  *  * Depending on the architecture and the media, the superblock may  * reside in any one of four places. For tiny media where every block   * counts, it is placed at the very front of the partition. Historically,  * UFS1 placed it 8K from the front to leave room for the disk label and  * a small bootstrap. For UFS2 it got moved to 64K from the front to leave  * room for the disk label and a bigger bootstrap, and for really piggy  * systems we check at 256K from the front if the first three fail. In  * all cases the size of the superblock will be SBLOCKSIZE. All values are  * given in byte-offset form, so they do not imply a sector size. The  * SBLOCKSEARCH specifies the order in which the locations should be searched.  *  * Unfortunately the UFS2/FFSv2 change was done without adequate consideration  * of backward compatibility.  In particular 'newfs' for a FFSv2 partition  * must overwrite any old FFSv1 superblock at 8k, and preferrably as many  * of the alternates as it can find - otherwise attempting to mount on a  * system that only supports FFSv1 is likely to succeed!.  * For a small FFSv1 filesystem, an old FFSv2 superblock can be left on  * the disk, and a system that tries to find an FFSv2 filesystem in preference  * to and FFSv1 one (as NetBSD does) can mount the old FFSv2 filesystem.  * As a added bonus, the 'first alternate' superblock of a FFSv1 filesystem  * with 64k blocks is at 64k - just where the code looks first when playing  * 'hunt the superblock'.  *  * The ffsv2 superblock layout (which might contain an ffsv1 filesystem)  * can be detected by checking for sb->fs_old_flags& FS_FLAGS_UPDATED.  * This is the default suberblock type for NetBSD since ffsv2 support was added.  */
end_comment

begin_define
define|#
directive|define
name|BBSIZE
value|8192
end_define

begin_define
define|#
directive|define
name|BBOFF
value|((off_t)(0))
end_define

begin_define
define|#
directive|define
name|BBLOCK
value|((daddr_t)(0))
end_define

begin_define
define|#
directive|define
name|SBLOCK_FLOPPY
value|0
end_define

begin_define
define|#
directive|define
name|SBLOCK_UFS1
value|8192
end_define

begin_define
define|#
directive|define
name|SBLOCK_UFS2
value|65536
end_define

begin_define
define|#
directive|define
name|SBLOCK_PIGGY
value|262144
end_define

begin_define
define|#
directive|define
name|SBLOCKSIZE
value|8192
end_define

begin_comment
comment|/*  * NB: Do not, under any circumstances, look for an ffsv1 filesystem at  * SBLOCK_UFS2.  Doing so will find the wrong superblock for filesystems  * with a 64k block size.  */
end_comment

begin_define
define|#
directive|define
name|SBLOCKSEARCH
define|\
value|{ SBLOCK_UFS2, SBLOCK_UFS1, SBLOCK_FLOPPY, SBLOCK_PIGGY, -1 }
end_define

begin_comment
comment|/*  * Max number of fragments per block. This value is NOT tweakable.  */
end_comment

begin_define
define|#
directive|define
name|MAXFRAG
value|8
end_define

begin_comment
comment|/*  * Addresses stored in inodes are capable of addressing fragments  * of `blocks'. File system blocks of at most size MAXBSIZE can  * be optionally broken into 2, 4, or 8 pieces, each of which is  * addressable; these pieces may be DEV_BSIZE, or some multiple of  * a DEV_BSIZE unit.  *  * Large files consist of exclusively large data blocks.  To avoid  * undue wasted disk space, the last data block of a small file may be  * allocated as only as many fragments of a large block as are  * necessary.  The file system format retains only a single pointer  * to such a fragment, which is a piece of a single large block that  * has been divided.  The size of such a fragment is determinable from  * information in the inode, using the ``blksize(fs, ip, lbn)'' macro.  *  * The file system records space availability at the fragment level;  * to determine block availability, aligned fragments are examined.  */
end_comment

begin_comment
comment|/*  * MINBSIZE is the smallest allowable block size.  * In order to insure that it is possible to create files of size  * 2^32 with only two levels of indirection, MINBSIZE is set to 4096.  * MINBSIZE must be big enough to hold a cylinder group block,  * thus changes to (struct cg) must keep its size within MINBSIZE.  * Note that super blocks are always of size SBSIZE,  * and that both SBSIZE and MAXBSIZE must be>= MINBSIZE.  */
end_comment

begin_define
define|#
directive|define
name|MINBSIZE
value|4096
end_define

begin_comment
comment|/*  * The path name on which the file system is mounted is maintained  * in fs_fsmnt. MAXMNTLEN defines the amount of space allocated in  * the super block for this name.  */
end_comment

begin_define
define|#
directive|define
name|MAXMNTLEN
value|468
end_define

begin_comment
comment|/*  * The volume name for this filesystem is maintained in fs_volname.  * MAXVOLLEN defines the length of the buffer allocated.  * This space used to be part of of fs_fsmnt.  */
end_comment

begin_define
define|#
directive|define
name|MAXVOLLEN
value|32
end_define

begin_comment
comment|/*  * There is a 128-byte region in the superblock reserved for in-core  * pointers to summary information. Originally this included an array  * of pointers to blocks of struct csum; now there are just four  * pointers and the remaining space is padded with fs_ocsp[].  * NOCSPTRS determines the size of this padding. One pointer (fs_csp)  * is taken away to point to a contiguous array of struct csum for  * all cylinder groups; a second (fs_maxcluster) points to an array  * of cluster sizes that is computed as cylinder groups are inspected;  * the third (fs_contigdirs) points to an array that tracks the  * creation of new directories; and the fourth (fs_active) is used  * by snapshots.  */
end_comment

begin_define
define|#
directive|define
name|NOCSPTRS
value|((128 / sizeof(void *)) - 4)
end_define

begin_comment
comment|/*  * A summary of contiguous blocks of various sizes is maintained  * in each cylinder group. Normally this is set by the initial  * value of fs_maxcontig. To conserve space, a maximum summary size  * is set by FS_MAXCONTIG.  */
end_comment

begin_define
define|#
directive|define
name|FS_MAXCONTIG
value|16
end_define

begin_comment
comment|/*  * The maximum number of snapshot nodes that can be associated  * with each filesystem. This limit affects only the number of  * snapshot files that can be recorded within the superblock so  * that they can be found when the filesystem is mounted. However,  * maintaining too many will slow the filesystem performance, so  * having this limit is a good idea.  */
end_comment

begin_define
define|#
directive|define
name|FSMAXSNAP
value|20
end_define

begin_comment
comment|/*  * Used to identify special blocks in snapshots:  *  * BLK_NOCOPY - A block that was unallocated at the time the snapshot  *      was taken, hence does not need to be copied when written.  * BLK_SNAP - A block held by another snapshot that is not needed by this  *      snapshot. When the other snapshot is freed, the BLK_SNAP entries  *      are converted to BLK_NOCOPY. These are needed to allow fsck to  *      identify blocks that are in use by other snapshots (which are  *      expunged from this snapshot).  */
end_comment

begin_define
define|#
directive|define
name|BLK_NOCOPY
value|((daddr_t)(1))
end_define

begin_define
define|#
directive|define
name|BLK_SNAP
value|((daddr_t)(2))
end_define

begin_comment
comment|/*  * MINFREE gives the minimum acceptable percentage of file system  * blocks which may be free. If the freelist drops below this level  * only the superuser may continue to allocate blocks. This may  * be set to 0 if no reserve of free blocks is deemed necessary,  * however throughput drops by fifty percent if the file system  * is run at between 95% and 100% full; thus the minimum default  * value of fs_minfree is 5%. However, to get good clustering  * performance, 10% is a better choice. hence we use 10% as our  * default value. With 10% free space, fragmentation is not a  * problem, so we choose to optimize for time.  */
end_comment

begin_define
define|#
directive|define
name|MINFREE
value|5
end_define

begin_define
define|#
directive|define
name|DEFAULTOPT
value|FS_OPTTIME
end_define

begin_comment
comment|/*  * Grigoriy Orlov<gluk@ptci.ru> has done some extensive work to fine  * tune the layout preferences for directories within a filesystem.  * His algorithm can be tuned by adjusting the following parameters  * which tell the system the average file size and the average number  * of files per directory. These defaults are well selected for typical  * filesystems, but may need to be tuned for odd cases like filesystems  * being used for squid caches or news spools.  */
end_comment

begin_define
define|#
directive|define
name|AVFILESIZ
value|16384
end_define

begin_comment
comment|/* expected average file size */
end_comment

begin_define
define|#
directive|define
name|AFPDIR
value|64
end_define

begin_comment
comment|/* expected number of files per directory */
end_comment

begin_comment
comment|/*  * Per cylinder group information; summarized in blocks allocated  * from first cylinder group data blocks.  These blocks have to be  * read in from fs_csaddr (size fs_cssize) in addition to the  * super block.  */
end_comment

begin_struct
struct|struct
name|csum
block|{
name|int32_t
name|cs_ndir
decl_stmt|;
comment|/* number of directories */
name|int32_t
name|cs_nbfree
decl_stmt|;
comment|/* number of free blocks */
name|int32_t
name|cs_nifree
decl_stmt|;
comment|/* number of free inodes */
name|int32_t
name|cs_nffree
decl_stmt|;
comment|/* number of free frags */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|csum_total
block|{
name|int64_t
name|cs_ndir
decl_stmt|;
comment|/* number of directories */
name|int64_t
name|cs_nbfree
decl_stmt|;
comment|/* number of free blocks */
name|int64_t
name|cs_nifree
decl_stmt|;
comment|/* number of free inodes */
name|int64_t
name|cs_nffree
decl_stmt|;
comment|/* number of free frags */
name|int64_t
name|cs_spare
index|[
literal|4
index|]
decl_stmt|;
comment|/* future expansion */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Super block for an FFS file system in memory.  */
end_comment

begin_struct
struct|struct
name|fs
block|{
name|int32_t
name|fs_firstfield
decl_stmt|;
comment|/* historic file system linked list, */
name|int32_t
name|fs_unused_1
decl_stmt|;
comment|/*     used for incore super blocks */
name|int32_t
name|fs_sblkno
decl_stmt|;
comment|/* addr of super-block in filesys */
name|int32_t
name|fs_cblkno
decl_stmt|;
comment|/* offset of cyl-block in filesys */
name|int32_t
name|fs_iblkno
decl_stmt|;
comment|/* offset of inode-blocks in filesys */
name|int32_t
name|fs_dblkno
decl_stmt|;
comment|/* offset of first data after cg */
name|int32_t
name|fs_old_cgoffset
decl_stmt|;
comment|/* cylinder group offset in cylinder */
name|int32_t
name|fs_old_cgmask
decl_stmt|;
comment|/* used to calc mod fs_ntrak */
name|int32_t
name|fs_old_time
decl_stmt|;
comment|/* last time written */
name|int32_t
name|fs_old_size
decl_stmt|;
comment|/* number of blocks in fs */
name|int32_t
name|fs_old_dsize
decl_stmt|;
comment|/* number of data blocks in fs */
name|int32_t
name|fs_ncg
decl_stmt|;
comment|/* number of cylinder groups */
name|int32_t
name|fs_bsize
decl_stmt|;
comment|/* size of basic blocks in fs */
name|int32_t
name|fs_fsize
decl_stmt|;
comment|/* size of frag blocks in fs */
name|int32_t
name|fs_frag
decl_stmt|;
comment|/* number of frags in a block in fs */
comment|/* these are configuration parameters */
name|int32_t
name|fs_minfree
decl_stmt|;
comment|/* minimum percentage of free blocks */
name|int32_t
name|fs_old_rotdelay
decl_stmt|;
comment|/* num of ms for optimal next block */
name|int32_t
name|fs_old_rps
decl_stmt|;
comment|/* disk revolutions per second */
comment|/* these fields can be computed from the others */
name|int32_t
name|fs_bmask
decl_stmt|;
comment|/* ``blkoff'' calc of blk offsets */
name|int32_t
name|fs_fmask
decl_stmt|;
comment|/* ``fragoff'' calc of frag offsets */
name|int32_t
name|fs_bshift
decl_stmt|;
comment|/* ``lblkno'' calc of logical blkno */
name|int32_t
name|fs_fshift
decl_stmt|;
comment|/* ``numfrags'' calc number of frags */
comment|/* these are configuration parameters */
name|int32_t
name|fs_maxcontig
decl_stmt|;
comment|/* max number of contiguous blks */
name|int32_t
name|fs_maxbpg
decl_stmt|;
comment|/* max number of blks per cyl group */
comment|/* these fields can be computed from the others */
name|int32_t
name|fs_fragshift
decl_stmt|;
comment|/* block to frag shift */
name|int32_t
name|fs_fsbtodb
decl_stmt|;
comment|/* fsbtodb and dbtofsb shift constant */
name|int32_t
name|fs_sbsize
decl_stmt|;
comment|/* actual size of super block */
name|int32_t
name|fs_spare1
index|[
literal|2
index|]
decl_stmt|;
comment|/* old fs_csmask */
comment|/* old fs_csshift */
name|int32_t
name|fs_nindir
decl_stmt|;
comment|/* value of NINDIR */
name|int32_t
name|fs_inopb
decl_stmt|;
comment|/* value of INOPB */
name|int32_t
name|fs_old_nspf
decl_stmt|;
comment|/* value of NSPF */
comment|/* yet another configuration parameter */
name|int32_t
name|fs_optim
decl_stmt|;
comment|/* optimization preference, see below */
comment|/* these fields are derived from the hardware */
name|int32_t
name|fs_old_npsect
decl_stmt|;
comment|/* # sectors/track including spares */
name|int32_t
name|fs_old_interleave
decl_stmt|;
comment|/* hardware sector interleave */
name|int32_t
name|fs_old_trackskew
decl_stmt|;
comment|/* sector 0 skew, per track */
comment|/* fs_id takes the space of the unused fs_headswitch and fs_trkseek fields */
name|int32_t
name|fs_id
index|[
literal|2
index|]
decl_stmt|;
comment|/* unique file system id */
comment|/* sizes determined by number of cylinder groups and their sizes */
name|int32_t
name|fs_old_csaddr
decl_stmt|;
comment|/* blk addr of cyl grp summary area */
name|int32_t
name|fs_cssize
decl_stmt|;
comment|/* size of cyl grp summary area */
name|int32_t
name|fs_cgsize
decl_stmt|;
comment|/* cylinder group size */
comment|/* these fields are derived from the hardware */
name|int32_t
name|fs_spare2
decl_stmt|;
comment|/* old fs_ntrak */
name|int32_t
name|fs_old_nsect
decl_stmt|;
comment|/* sectors per track */
name|int32_t
name|fs_old_spc
decl_stmt|;
comment|/* sectors per cylinder */
name|int32_t
name|fs_old_ncyl
decl_stmt|;
comment|/* cylinders in file system */
name|int32_t
name|fs_old_cpg
decl_stmt|;
comment|/* cylinders per group */
name|int32_t
name|fs_ipg
decl_stmt|;
comment|/* inodes per group */
name|int32_t
name|fs_fpg
decl_stmt|;
comment|/* blocks per group * fs_frag */
comment|/* this data must be re-computed after crashes */
name|struct
name|csum
name|fs_old_cstotal
decl_stmt|;
comment|/* cylinder summary information */
comment|/* these fields are cleared at mount time */
name|int8_t
name|fs_fmod
decl_stmt|;
comment|/* super block modified flag */
name|int8_t
name|fs_clean
decl_stmt|;
comment|/* file system is clean flag */
name|int8_t
name|fs_ronly
decl_stmt|;
comment|/* mounted read-only flag */
name|uint8_t
name|fs_old_flags
decl_stmt|;
comment|/* see FS_ flags below */
name|u_char
name|fs_fsmnt
index|[
name|MAXMNTLEN
index|]
decl_stmt|;
comment|/* name mounted on */
name|u_char
name|fs_volname
index|[
name|MAXVOLLEN
index|]
decl_stmt|;
comment|/* volume name */
name|uint64_t
name|fs_swuid
decl_stmt|;
comment|/* system-wide uid */
name|int32_t
name|fs_pad
decl_stmt|;
comment|/* these fields retain the current block allocation info */
name|int32_t
name|fs_cgrotor
decl_stmt|;
comment|/* last cg searched (UNUSED) */
name|void
modifier|*
name|fs_ocsp
index|[
name|NOCSPTRS
index|]
decl_stmt|;
comment|/* padding; was list of fs_cs buffers */
name|u_int8_t
modifier|*
name|fs_contigdirs
decl_stmt|;
comment|/* # of contiguously allocated dirs */
name|struct
name|csum
modifier|*
name|fs_csp
decl_stmt|;
comment|/* cg summary info buffer for fs_cs */
name|int32_t
modifier|*
name|fs_maxcluster
decl_stmt|;
comment|/* max cluster in each cyl group */
name|u_char
modifier|*
name|fs_active
decl_stmt|;
comment|/* used by snapshots to track fs */
name|int32_t
name|fs_old_cpc
decl_stmt|;
comment|/* cyl per cycle in postbl */
comment|/* this area is otherwise allocated unless fs_old_flags& FS_FLAGS_UPDATED */
name|int32_t
name|fs_maxbsize
decl_stmt|;
comment|/* maximum blocking factor permitted */
name|int64_t
name|fs_sparecon64
index|[
literal|17
index|]
decl_stmt|;
comment|/* old rotation block list head */
name|int64_t
name|fs_sblockloc
decl_stmt|;
comment|/* byte offset of standard superblock */
name|struct
name|csum_total
name|fs_cstotal
decl_stmt|;
comment|/* cylinder summary information */
name|int64_t
name|fs_time
decl_stmt|;
comment|/* last time written */
name|int64_t
name|fs_size
decl_stmt|;
comment|/* number of blocks in fs */
name|int64_t
name|fs_dsize
decl_stmt|;
comment|/* number of data blocks in fs */
name|int64_t
name|fs_csaddr
decl_stmt|;
comment|/* blk addr of cyl grp summary area */
name|int64_t
name|fs_pendingblocks
decl_stmt|;
comment|/* blocks in process of being freed */
name|int32_t
name|fs_pendinginodes
decl_stmt|;
comment|/* inodes in process of being freed */
name|int32_t
name|fs_snapinum
index|[
name|FSMAXSNAP
index|]
decl_stmt|;
comment|/* list of snapshot inode numbers */
comment|/* back to stuff that has been around a while */
name|int32_t
name|fs_avgfilesize
decl_stmt|;
comment|/* expected average file size */
name|int32_t
name|fs_avgfpdir
decl_stmt|;
comment|/* expected # of files per directory */
name|int32_t
name|fs_save_cgsize
decl_stmt|;
comment|/* save real cg size to use fs_bsize */
name|int32_t
name|fs_sparecon32
index|[
literal|26
index|]
decl_stmt|;
comment|/* reserved for future constants */
name|uint32_t
name|fs_flags
decl_stmt|;
comment|/* see FS_ flags below */
comment|/* back to stuff that has been around a while (again) */
name|int32_t
name|fs_contigsumsize
decl_stmt|;
comment|/* size of cluster summary array */
name|int32_t
name|fs_maxsymlinklen
decl_stmt|;
comment|/* max length of an internal symlink */
name|int32_t
name|fs_old_inodefmt
decl_stmt|;
comment|/* format of on-disk inodes */
name|u_int64_t
name|fs_maxfilesize
decl_stmt|;
comment|/* maximum representable file size */
name|int64_t
name|fs_qbmask
decl_stmt|;
comment|/* ~fs_bmask for use with 64-bit size */
name|int64_t
name|fs_qfmask
decl_stmt|;
comment|/* ~fs_fmask for use with 64-bit size */
name|int32_t
name|fs_state
decl_stmt|;
comment|/* validate fs_clean field (UNUSED) */
name|int32_t
name|fs_old_postblformat
decl_stmt|;
comment|/* format of positional layout tables */
name|int32_t
name|fs_old_nrpos
decl_stmt|;
comment|/* number of rotational positions */
name|int32_t
name|fs_spare5
index|[
literal|2
index|]
decl_stmt|;
comment|/* old fs_postbloff */
comment|/* old fs_rotbloff */
name|int32_t
name|fs_magic
decl_stmt|;
comment|/* magic number */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|fs_old_postbloff
value|fs_spare5[0]
end_define

begin_define
define|#
directive|define
name|fs_old_rotbloff
value|fs_spare5[1]
end_define

begin_define
define|#
directive|define
name|fs_old_postbl_start
value|fs_maxbsize
end_define

begin_define
define|#
directive|define
name|fs_old_headswitch
value|fs_id[0]
end_define

begin_define
define|#
directive|define
name|fs_old_trkseek
value|fs_id[1]
end_define

begin_define
define|#
directive|define
name|fs_old_csmask
value|fs_spare1[0]
end_define

begin_define
define|#
directive|define
name|fs_old_csshift
value|fs_spare1[1]
end_define

begin_define
define|#
directive|define
name|FS_42POSTBLFMT
value|-1
end_define

begin_comment
comment|/* 4.2BSD rotational table format */
end_comment

begin_define
define|#
directive|define
name|FS_DYNAMICPOSTBLFMT
value|1
end_define

begin_comment
comment|/* dynamic rotational table format */
end_comment

begin_define
define|#
directive|define
name|old_fs_postbl
parameter_list|(
name|fs_
parameter_list|,
name|cylno
parameter_list|,
name|opostblsave
parameter_list|)
define|\
value|((((fs_)->fs_old_postblformat == FS_42POSTBLFMT) || \      ((fs_)->fs_old_postbloff == offsetof(struct fs, fs_old_postbl_start))) \     ? ((int16_t *)(opostblsave) + (cylno) * (fs_)->fs_old_nrpos) \     : ((int16_t *)((uint8_t *)(fs_) + \ 	(fs_)->fs_old_postbloff) + (cylno) * (fs_)->fs_old_nrpos))
end_define

begin_define
define|#
directive|define
name|old_fs_rotbl
parameter_list|(
name|fs
parameter_list|)
define|\
value|(((fs)->fs_old_postblformat == FS_42POSTBLFMT) \     ? ((uint8_t *)(&(fs)->fs_magic+1)) \     : ((uint8_t *)((uint8_t *)(fs) + (fs)->fs_old_rotbloff)))
end_define

begin_comment
comment|/*  * File system identification  */
end_comment

begin_define
define|#
directive|define
name|FS_UFS1_MAGIC
value|0x011954
end_define

begin_comment
comment|/* UFS1 fast file system magic number */
end_comment

begin_define
define|#
directive|define
name|FS_UFS2_MAGIC
value|0x19540119
end_define

begin_comment
comment|/* UFS2 fast file system magic number */
end_comment

begin_define
define|#
directive|define
name|FS_UFS1_MAGIC_SWAPPED
value|0x54190100
end_define

begin_define
define|#
directive|define
name|FS_UFS2_MAGIC_SWAPPED
value|0x19015419
end_define

begin_define
define|#
directive|define
name|FS_OKAY
value|0x7c269d38
end_define

begin_comment
comment|/* superblock checksum */
end_comment

begin_define
define|#
directive|define
name|FS_42INODEFMT
value|-1
end_define

begin_comment
comment|/* 4.2BSD inode format */
end_comment

begin_define
define|#
directive|define
name|FS_44INODEFMT
value|2
end_define

begin_comment
comment|/* 4.4BSD inode format */
end_comment

begin_comment
comment|/*  * File system clean flags  */
end_comment

begin_define
define|#
directive|define
name|FS_ISCLEAN
value|0x01
end_define

begin_define
define|#
directive|define
name|FS_WASCLEAN
value|0x02
end_define

begin_comment
comment|/*  * Preference for optimization.  */
end_comment

begin_define
define|#
directive|define
name|FS_OPTTIME
value|0
end_define

begin_comment
comment|/* minimize allocation time */
end_comment

begin_define
define|#
directive|define
name|FS_OPTSPACE
value|1
end_define

begin_comment
comment|/* minimize disk fragmentation */
end_comment

begin_comment
comment|/*  * File system flags  */
end_comment

begin_define
define|#
directive|define
name|FS_UNCLEAN
value|0x01
end_define

begin_comment
comment|/* file system not clean at mount (unused) */
end_comment

begin_define
define|#
directive|define
name|FS_DOSOFTDEP
value|0x02
end_define

begin_comment
comment|/* file system using soft dependencies */
end_comment

begin_define
define|#
directive|define
name|FS_NEEDSFSCK
value|0x04
end_define

begin_comment
comment|/* needs sync fsck (FreeBSD compat, unused) */
end_comment

begin_define
define|#
directive|define
name|FS_INDEXDIRS
value|0x08
end_define

begin_comment
comment|/* kernel supports indexed directories */
end_comment

begin_define
define|#
directive|define
name|FS_ACLS
value|0x10
end_define

begin_comment
comment|/* file system has ACLs enabled */
end_comment

begin_define
define|#
directive|define
name|FS_MULTILABEL
value|0x20
end_define

begin_comment
comment|/* file system is MAC multi-label */
end_comment

begin_define
define|#
directive|define
name|FS_FLAGS_UPDATED
value|0x80
end_define

begin_comment
comment|/* flags have been moved to new location */
end_comment

begin_comment
comment|/*  * File system internal flags, also in fs_flags.  * (Pick highest number to avoid conflicts with others)  */
end_comment

begin_define
define|#
directive|define
name|FS_SWAPPED
value|0x80000000
end_define

begin_comment
comment|/* file system is endian swapped */
end_comment

begin_define
define|#
directive|define
name|FS_INTERNAL
value|0x80000000
end_define

begin_comment
comment|/* mask for internal flags */
end_comment

begin_comment
comment|/*  * Macros to access bits in the fs_active array.  */
end_comment

begin_define
define|#
directive|define
name|ACTIVECG_SET
parameter_list|(
name|fs
parameter_list|,
name|cg
parameter_list|)
define|\
value|do {						\ 		if ((fs)->fs_active != NULL)		\ 			setbit((fs)->fs_active, (cg));	\ 	} while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|ACTIVECG_CLR
parameter_list|(
name|fs
parameter_list|,
name|cg
parameter_list|)
define|\
value|do {						\ 		if ((fs)->fs_active != NULL)		\ 			clrbit((fs)->fs_active, (cg));	\ 	} while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|ACTIVECG_ISSET
parameter_list|(
name|fs
parameter_list|,
name|cg
parameter_list|)
define|\
value|((fs)->fs_active != NULL&& isset((fs)->fs_active, (cg)))
end_define

begin_comment
comment|/*  * The size of a cylinder group is calculated by CGSIZE. The maximum size  * is limited by the fact that cylinder groups are at most one block.  * Its size is derived from the size of the maps maintained in the  * cylinder group and the (struct cg) size.  */
end_comment

begin_define
define|#
directive|define
name|CGSIZE_IF
parameter_list|(
name|fs
parameter_list|,
name|ipg
parameter_list|,
name|fpg
parameter_list|)
define|\
comment|/* base cg */
value|(sizeof(struct cg) + sizeof(int32_t) + \
comment|/* old btotoff */
value|(fs)->fs_old_cpg * sizeof(int32_t) + \
comment|/* old boff */
value|(fs)->fs_old_cpg * sizeof(u_int16_t) + \
comment|/* inode map */
value|howmany((ipg), NBBY) + \
comment|/* block map */
value|howmany((fpg), NBBY) +\
comment|/* if present */
value|((fs)->fs_contigsumsize<= 0 ? 0 : \
comment|/* cluster sum */
value|(fs)->fs_contigsumsize * sizeof(int32_t) + \
comment|/* cluster map */
value|howmany(fragstoblks(fs, (fpg)), NBBY)))
end_define

begin_define
define|#
directive|define
name|CGSIZE
parameter_list|(
name|fs
parameter_list|)
value|CGSIZE_IF((fs), (fs)->fs_ipg, (fs)->fs_fpg)
end_define

begin_comment
comment|/*  * The minimal number of cylinder groups that should be created.  */
end_comment

begin_define
define|#
directive|define
name|MINCYLGRPS
value|4
end_define

begin_comment
comment|/*  * Convert cylinder group to base address of its global summary info.  */
end_comment

begin_define
define|#
directive|define
name|fs_cs
parameter_list|(
name|fs
parameter_list|,
name|indx
parameter_list|)
value|fs_csp[indx]
end_define

begin_comment
comment|/*  * Cylinder group block for a file system.  */
end_comment

begin_define
define|#
directive|define
name|CG_MAGIC
value|0x090255
end_define

begin_struct
struct|struct
name|cg
block|{
name|int32_t
name|cg_firstfield
decl_stmt|;
comment|/* historic cyl groups linked list */
name|int32_t
name|cg_magic
decl_stmt|;
comment|/* magic number */
name|int32_t
name|cg_old_time
decl_stmt|;
comment|/* time last written */
name|int32_t
name|cg_cgx
decl_stmt|;
comment|/* we are the cgx'th cylinder group */
name|int16_t
name|cg_old_ncyl
decl_stmt|;
comment|/* number of cyl's this cg */
name|int16_t
name|cg_old_niblk
decl_stmt|;
comment|/* number of inode blocks this cg */
name|int32_t
name|cg_ndblk
decl_stmt|;
comment|/* number of data blocks this cg */
name|struct
name|csum
name|cg_cs
decl_stmt|;
comment|/* cylinder summary information */
name|int32_t
name|cg_rotor
decl_stmt|;
comment|/* position of last used block */
name|int32_t
name|cg_frotor
decl_stmt|;
comment|/* position of last used frag */
name|int32_t
name|cg_irotor
decl_stmt|;
comment|/* position of last used inode */
name|int32_t
name|cg_frsum
index|[
name|MAXFRAG
index|]
decl_stmt|;
comment|/* counts of available frags */
name|int32_t
name|cg_old_btotoff
decl_stmt|;
comment|/* (int32) block totals per cylinder */
name|int32_t
name|cg_old_boff
decl_stmt|;
comment|/* (u_int16) free block positions */
name|int32_t
name|cg_iusedoff
decl_stmt|;
comment|/* (u_int8) used inode map */
name|int32_t
name|cg_freeoff
decl_stmt|;
comment|/* (u_int8) free block map */
name|int32_t
name|cg_nextfreeoff
decl_stmt|;
comment|/* (u_int8) next available space */
name|int32_t
name|cg_clustersumoff
decl_stmt|;
comment|/* (u_int32) counts of avail clusters */
name|int32_t
name|cg_clusteroff
decl_stmt|;
comment|/* (u_int8) free cluster map */
name|int32_t
name|cg_nclusterblks
decl_stmt|;
comment|/* number of clusters this cg */
name|int32_t
name|cg_niblk
decl_stmt|;
comment|/* number of inode blocks this cg */
name|int32_t
name|cg_initediblk
decl_stmt|;
comment|/* last initialized inode */
name|int32_t
name|cg_sparecon32
index|[
literal|3
index|]
decl_stmt|;
comment|/* reserved for future use */
name|int64_t
name|cg_time
decl_stmt|;
comment|/* time last written */
name|int64_t
name|cg_sparecon64
index|[
literal|3
index|]
decl_stmt|;
comment|/* reserved for future use */
name|u_int8_t
name|cg_space
index|[
literal|1
index|]
decl_stmt|;
comment|/* space for cylinder group maps */
comment|/* actually longer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure is defined  * for compatibility with old file systems.  */
end_comment

begin_struct
struct|struct
name|ocg
block|{
name|int32_t
name|cg_firstfield
decl_stmt|;
comment|/* historic linked list of cyl groups */
name|int32_t
name|cg_unused_1
decl_stmt|;
comment|/*     used for incore cyl groups */
name|int32_t
name|cg_time
decl_stmt|;
comment|/* time last written */
name|int32_t
name|cg_cgx
decl_stmt|;
comment|/* we are the cgx'th cylinder group */
name|int16_t
name|cg_ncyl
decl_stmt|;
comment|/* number of cyl's this cg */
name|int16_t
name|cg_niblk
decl_stmt|;
comment|/* number of inode blocks this cg */
name|int32_t
name|cg_ndblk
decl_stmt|;
comment|/* number of data blocks this cg */
name|struct
name|csum
name|cg_cs
decl_stmt|;
comment|/* cylinder summary information */
name|int32_t
name|cg_rotor
decl_stmt|;
comment|/* position of last used block */
name|int32_t
name|cg_frotor
decl_stmt|;
comment|/* position of last used frag */
name|int32_t
name|cg_irotor
decl_stmt|;
comment|/* position of last used inode */
name|int32_t
name|cg_frsum
index|[
literal|8
index|]
decl_stmt|;
comment|/* counts of available frags */
name|int32_t
name|cg_btot
index|[
literal|32
index|]
decl_stmt|;
comment|/* block totals per cylinder */
name|int16_t
name|cg_b
index|[
literal|32
index|]
index|[
literal|8
index|]
decl_stmt|;
comment|/* positions of free blocks */
name|u_int8_t
name|cg_iused
index|[
literal|256
index|]
decl_stmt|;
comment|/* used inode map */
name|int32_t
name|cg_magic
decl_stmt|;
comment|/* magic number */
name|u_int8_t
name|cg_free
index|[
literal|1
index|]
decl_stmt|;
comment|/* free block map */
comment|/* actually longer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macros for access to cylinder group array structures.  */
end_comment

begin_define
define|#
directive|define
name|old_cg_blktot_old
parameter_list|(
name|cgp
parameter_list|,
name|ns
parameter_list|)
define|\
value|(((struct ocg *)(cgp))->cg_btot)
end_define

begin_define
define|#
directive|define
name|old_cg_blks_old
parameter_list|(
name|fs
parameter_list|,
name|cgp
parameter_list|,
name|cylno
parameter_list|,
name|ns
parameter_list|)
define|\
value|(((struct ocg *)(cgp))->cg_b[cylno])
end_define

begin_define
define|#
directive|define
name|old_cg_blktot_new
parameter_list|(
name|cgp
parameter_list|,
name|ns
parameter_list|)
define|\
value|((int32_t *)((u_int8_t *)(cgp) + \ 	ufs_rw32((cgp)->cg_old_btotoff, (ns))))
end_define

begin_define
define|#
directive|define
name|old_cg_blks_new
parameter_list|(
name|fs
parameter_list|,
name|cgp
parameter_list|,
name|cylno
parameter_list|,
name|ns
parameter_list|)
define|\
value|((int16_t *)((u_int8_t *)(cgp) + \ 	ufs_rw32((cgp)->cg_old_boff, (ns))) + (cylno) * (fs)->fs_old_nrpos)
end_define

begin_define
define|#
directive|define
name|old_cg_blktot
parameter_list|(
name|cgp
parameter_list|,
name|ns
parameter_list|)
define|\
value|((ufs_rw32((cgp)->cg_magic, (ns)) != CG_MAGIC) ? \       old_cg_blktot_old(cgp, ns) : old_cg_blktot_new(cgp, ns))
end_define

begin_define
define|#
directive|define
name|old_cg_blks
parameter_list|(
name|fs
parameter_list|,
name|cgp
parameter_list|,
name|cylno
parameter_list|,
name|ns
parameter_list|)
define|\
value|((ufs_rw32((cgp)->cg_magic, (ns)) != CG_MAGIC) ? \       old_cg_blks_old(fs, cgp, cylno, ns) : old_cg_blks_new(fs, cgp, cylno, ns))
end_define

begin_define
define|#
directive|define
name|cg_inosused_new
parameter_list|(
name|cgp
parameter_list|,
name|ns
parameter_list|)
define|\
value|((u_int8_t *)((u_int8_t *)(cgp) + \ 	ufs_rw32((cgp)->cg_iusedoff, (ns))))
end_define

begin_define
define|#
directive|define
name|cg_blksfree_new
parameter_list|(
name|cgp
parameter_list|,
name|ns
parameter_list|)
define|\
value|((u_int8_t *)((u_int8_t *)(cgp) + \ 	ufs_rw32((cgp)->cg_freeoff, (ns))))
end_define

begin_define
define|#
directive|define
name|cg_chkmagic_new
parameter_list|(
name|cgp
parameter_list|,
name|ns
parameter_list|)
define|\
value|(ufs_rw32((cgp)->cg_magic, (ns)) == CG_MAGIC)
end_define

begin_define
define|#
directive|define
name|cg_inosused_old
parameter_list|(
name|cgp
parameter_list|,
name|ns
parameter_list|)
define|\
value|(((struct ocg *)(cgp))->cg_iused)
end_define

begin_define
define|#
directive|define
name|cg_blksfree_old
parameter_list|(
name|cgp
parameter_list|,
name|ns
parameter_list|)
define|\
value|(((struct ocg *)(cgp))->cg_free)
end_define

begin_define
define|#
directive|define
name|cg_chkmagic_old
parameter_list|(
name|cgp
parameter_list|,
name|ns
parameter_list|)
define|\
value|(ufs_rw32(((struct ocg *)(cgp))->cg_magic, (ns)) == CG_MAGIC)
end_define

begin_define
define|#
directive|define
name|cg_inosused
parameter_list|(
name|cgp
parameter_list|,
name|ns
parameter_list|)
define|\
value|((ufs_rw32((cgp)->cg_magic, (ns)) != CG_MAGIC) ? \       cg_inosused_old(cgp, ns) : cg_inosused_new(cgp, ns))
end_define

begin_define
define|#
directive|define
name|cg_blksfree
parameter_list|(
name|cgp
parameter_list|,
name|ns
parameter_list|)
define|\
value|((ufs_rw32((cgp)->cg_magic, (ns)) != CG_MAGIC) ? \       cg_blksfree_old(cgp, ns) : cg_blksfree_new(cgp, ns))
end_define

begin_define
define|#
directive|define
name|cg_chkmagic
parameter_list|(
name|cgp
parameter_list|,
name|ns
parameter_list|)
define|\
value|(cg_chkmagic_new(cgp, ns) || cg_chkmagic_old(cgp, ns))
end_define

begin_define
define|#
directive|define
name|cg_clustersfree
parameter_list|(
name|cgp
parameter_list|,
name|ns
parameter_list|)
define|\
value|((u_int8_t *)((u_int8_t *)(cgp) + \ 	ufs_rw32((cgp)->cg_clusteroff, (ns))))
end_define

begin_define
define|#
directive|define
name|cg_clustersum
parameter_list|(
name|cgp
parameter_list|,
name|ns
parameter_list|)
define|\
value|((int32_t *)((u_int8_t *)(cgp) + \ 	ufs_rw32((cgp)->cg_clustersumoff, (ns))))
end_define

begin_comment
comment|/*  * Turn file system block numbers into disk block addresses.  * This maps file system blocks to device size blocks.  */
end_comment

begin_define
define|#
directive|define
name|fsbtodb
parameter_list|(
name|fs
parameter_list|,
name|b
parameter_list|)
value|((b)<< (fs)->fs_fsbtodb)
end_define

begin_define
define|#
directive|define
name|dbtofsb
parameter_list|(
name|fs
parameter_list|,
name|b
parameter_list|)
value|((b)>> (fs)->fs_fsbtodb)
end_define

begin_comment
comment|/*  * Cylinder group macros to locate things in cylinder groups.  * They calc file system addresses of cylinder group data structures.  */
end_comment

begin_define
define|#
directive|define
name|cgbase
parameter_list|(
name|fs
parameter_list|,
name|c
parameter_list|)
value|(((daddr_t)(fs)->fs_fpg) * (c))
end_define

begin_define
define|#
directive|define
name|cgstart_ufs1
parameter_list|(
name|fs
parameter_list|,
name|c
parameter_list|)
define|\
value|(cgbase(fs, c) + (fs)->fs_old_cgoffset * ((c)& ~((fs)->fs_old_cgmask)))
end_define

begin_define
define|#
directive|define
name|cgstart_ufs2
parameter_list|(
name|fs
parameter_list|,
name|c
parameter_list|)
value|cgbase((fs), (c))
end_define

begin_define
define|#
directive|define
name|cgstart
parameter_list|(
name|fs
parameter_list|,
name|c
parameter_list|)
value|((fs)->fs_magic == FS_UFS2_MAGIC \ 			    ? cgstart_ufs2((fs), (c)) : cgstart_ufs1((fs), (c)))
end_define

begin_define
define|#
directive|define
name|cgdmin
parameter_list|(
name|fs
parameter_list|,
name|c
parameter_list|)
value|(cgstart(fs, c) + (fs)->fs_dblkno)
end_define

begin_comment
comment|/* 1st data */
end_comment

begin_define
define|#
directive|define
name|cgimin
parameter_list|(
name|fs
parameter_list|,
name|c
parameter_list|)
value|(cgstart(fs, c) + (fs)->fs_iblkno)
end_define

begin_comment
comment|/* inode blk */
end_comment

begin_define
define|#
directive|define
name|cgsblock
parameter_list|(
name|fs
parameter_list|,
name|c
parameter_list|)
value|(cgstart(fs, c) + (fs)->fs_sblkno)
end_define

begin_comment
comment|/* super blk */
end_comment

begin_define
define|#
directive|define
name|cgtod
parameter_list|(
name|fs
parameter_list|,
name|c
parameter_list|)
value|(cgstart(fs, c) + (fs)->fs_cblkno)
end_define

begin_comment
comment|/* cg block */
end_comment

begin_comment
comment|/*  * Macros for handling inode numbers:  *     inode number to file system block offset.  *     inode number to cylinder group number.  *     inode number to file system block address.  */
end_comment

begin_define
define|#
directive|define
name|ino_to_cg
parameter_list|(
name|fs
parameter_list|,
name|x
parameter_list|)
value|((x) / (fs)->fs_ipg)
end_define

begin_define
define|#
directive|define
name|ino_to_fsba
parameter_list|(
name|fs
parameter_list|,
name|x
parameter_list|)
define|\
value|((daddr_t)(cgimin(fs, ino_to_cg(fs, x)) +			\ 	    (blkstofrags((fs), (((x) % (fs)->fs_ipg) / INOPB(fs))))))
end_define

begin_define
define|#
directive|define
name|ino_to_fsbo
parameter_list|(
name|fs
parameter_list|,
name|x
parameter_list|)
value|((x) % INOPB(fs))
end_define

begin_comment
comment|/*  * Give cylinder group number for a file system block.  * Give cylinder group block number for a file system block.  */
end_comment

begin_define
define|#
directive|define
name|dtog
parameter_list|(
name|fs
parameter_list|,
name|d
parameter_list|)
value|((d) / (fs)->fs_fpg)
end_define

begin_define
define|#
directive|define
name|dtogd
parameter_list|(
name|fs
parameter_list|,
name|d
parameter_list|)
value|((d) % (fs)->fs_fpg)
end_define

begin_comment
comment|/*  * Extract the bits for a block from a map.  * Compute the cylinder and rotational position of a cyl block addr.  */
end_comment

begin_define
define|#
directive|define
name|blkmap
parameter_list|(
name|fs
parameter_list|,
name|map
parameter_list|,
name|loc
parameter_list|)
define|\
value|(((map)[(loc) / NBBY]>> ((loc) % NBBY))& (0xff>> (NBBY - (fs)->fs_frag)))
end_define

begin_define
define|#
directive|define
name|old_cbtocylno
parameter_list|(
name|fs
parameter_list|,
name|bno
parameter_list|)
define|\
value|(fsbtodb(fs, bno) / (fs)->fs_old_spc)
end_define

begin_define
define|#
directive|define
name|old_cbtorpos
parameter_list|(
name|fs
parameter_list|,
name|bno
parameter_list|)
define|\
value|((fs)->fs_old_nrpos<= 1 ? 0 : \      (fsbtodb(fs, bno) % (fs)->fs_old_spc / (fs)->fs_old_nsect * (fs)->fs_old_trackskew + \       fsbtodb(fs, bno) % (fs)->fs_old_spc % (fs)->fs_old_nsect * (fs)->fs_old_interleave) % \      (fs)->fs_old_nsect * (fs)->fs_old_nrpos / (fs)->fs_old_npsect)
end_define

begin_comment
comment|/*  * The following macros optimize certain frequently calculated  * quantities by using shifts and masks in place of divisions  * modulos and multiplications.  */
end_comment

begin_define
define|#
directive|define
name|blkoff
parameter_list|(
name|fs
parameter_list|,
name|loc
parameter_list|)
comment|/* calculates (loc % fs->fs_bsize) */
define|\
value|((loc)& (fs)->fs_qbmask)
end_define

begin_define
define|#
directive|define
name|fragoff
parameter_list|(
name|fs
parameter_list|,
name|loc
parameter_list|)
comment|/* calculates (loc % fs->fs_fsize) */
define|\
value|((loc)& (fs)->fs_qfmask)
end_define

begin_define
define|#
directive|define
name|lfragtosize
parameter_list|(
name|fs
parameter_list|,
name|frag
parameter_list|)
comment|/* calculates ((off_t)frag * fs->fs_fsize) */
define|\
value|(((off_t)(frag))<< (fs)->fs_fshift)
end_define

begin_define
define|#
directive|define
name|lblktosize
parameter_list|(
name|fs
parameter_list|,
name|blk
parameter_list|)
comment|/* calculates ((off_t)blk * fs->fs_bsize) */
define|\
value|(((off_t)(blk))<< (fs)->fs_bshift)
end_define

begin_define
define|#
directive|define
name|lblkno
parameter_list|(
name|fs
parameter_list|,
name|loc
parameter_list|)
comment|/* calculates (loc / fs->fs_bsize) */
define|\
value|((loc)>> (fs)->fs_bshift)
end_define

begin_define
define|#
directive|define
name|numfrags
parameter_list|(
name|fs
parameter_list|,
name|loc
parameter_list|)
comment|/* calculates (loc / fs->fs_fsize) */
define|\
value|((loc)>> (fs)->fs_fshift)
end_define

begin_define
define|#
directive|define
name|blkroundup
parameter_list|(
name|fs
parameter_list|,
name|size
parameter_list|)
comment|/* calculates roundup(size, fs->fs_bsize) */
define|\
value|(((size) + (fs)->fs_qbmask)& (fs)->fs_bmask)
end_define

begin_define
define|#
directive|define
name|fragroundup
parameter_list|(
name|fs
parameter_list|,
name|size
parameter_list|)
comment|/* calculates roundup(size, fs->fs_fsize) */
define|\
value|(((size) + (fs)->fs_qfmask)& (fs)->fs_fmask)
end_define

begin_define
define|#
directive|define
name|fragstoblks
parameter_list|(
name|fs
parameter_list|,
name|frags
parameter_list|)
comment|/* calculates (frags / fs->fs_frag) */
define|\
value|((frags)>> (fs)->fs_fragshift)
end_define

begin_define
define|#
directive|define
name|blkstofrags
parameter_list|(
name|fs
parameter_list|,
name|blks
parameter_list|)
comment|/* calculates (blks * fs->fs_frag) */
define|\
value|((blks)<< (fs)->fs_fragshift)
end_define

begin_define
define|#
directive|define
name|fragnum
parameter_list|(
name|fs
parameter_list|,
name|fsb
parameter_list|)
comment|/* calculates (fsb % fs->fs_frag) */
define|\
value|((fsb)& ((fs)->fs_frag - 1))
end_define

begin_define
define|#
directive|define
name|blknum
parameter_list|(
name|fs
parameter_list|,
name|fsb
parameter_list|)
comment|/* calculates rounddown(fsb, fs->fs_frag) */
define|\
value|((fsb)&~ ((fs)->fs_frag - 1))
end_define

begin_comment
comment|/*  * Determine the number of available frags given a  * percentage to hold in reserve.  */
end_comment

begin_define
define|#
directive|define
name|freespace
parameter_list|(
name|fs
parameter_list|,
name|percentreserved
parameter_list|)
define|\
value|(blkstofrags((fs), (fs)->fs_cstotal.cs_nbfree) + \ 	(fs)->fs_cstotal.cs_nffree - \ 	(((off_t)((fs)->fs_dsize)) * (percentreserved) / 100))
end_define

begin_comment
comment|/*  * Determining the size of a file block in the file system.  */
end_comment

begin_define
define|#
directive|define
name|blksize
parameter_list|(
name|fs
parameter_list|,
name|ip
parameter_list|,
name|lbn
parameter_list|)
define|\
value|(((lbn)>= NDADDR || (ip)->i_size>= lblktosize(fs, (lbn) + 1)) \ 	    ? (fs)->fs_bsize \ 	    : (fragroundup(fs, blkoff(fs, (ip)->i_size))))
end_define

begin_define
define|#
directive|define
name|sblksize
parameter_list|(
name|fs
parameter_list|,
name|size
parameter_list|,
name|lbn
parameter_list|)
define|\
value|(((lbn)>= NDADDR || (size)>= ((lbn) + 1)<< (fs)->fs_bshift) \ 	  ? (fs)->fs_bsize \ 	  : (fragroundup(fs, blkoff(fs, (size)))))
end_define

begin_comment
comment|/*  * Number of inodes in a secondary storage block/fragment.  */
end_comment

begin_define
define|#
directive|define
name|INOPB
parameter_list|(
name|fs
parameter_list|)
value|((fs)->fs_inopb)
end_define

begin_define
define|#
directive|define
name|INOPF
parameter_list|(
name|fs
parameter_list|)
value|((fs)->fs_inopb>> (fs)->fs_fragshift)
end_define

begin_comment
comment|/*  * Number of indirects in a file system block.  */
end_comment

begin_define
define|#
directive|define
name|NINDIR
parameter_list|(
name|fs
parameter_list|)
value|((fs)->fs_nindir)
end_define

begin_comment
comment|/*  * Apple UFS Label:  *  We check for this to decide to use APPLEUFS_DIRBLKSIZ  */
end_comment

begin_define
define|#
directive|define
name|APPLEUFS_LABEL_MAGIC
value|0x4c41424c
end_define

begin_comment
comment|/* LABL */
end_comment

begin_define
define|#
directive|define
name|APPLEUFS_LABEL_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|APPLEUFS_LABEL_OFFSET
value|(BBSIZE - APPLEUFS_LABEL_SIZE)
end_define

begin_comment
comment|/* located at 7k */
end_comment

begin_define
define|#
directive|define
name|APPLEUFS_LABEL_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|APPLEUFS_MAX_LABEL_NAME
value|512
end_define

begin_struct
struct|struct
name|appleufslabel
block|{
name|u_int32_t
name|ul_magic
decl_stmt|;
name|u_int16_t
name|ul_checksum
decl_stmt|;
name|u_int16_t
name|ul_unused0
decl_stmt|;
name|u_int32_t
name|ul_version
decl_stmt|;
name|u_int32_t
name|ul_time
decl_stmt|;
name|u_int16_t
name|ul_namelen
decl_stmt|;
name|u_char
name|ul_name
index|[
name|APPLEUFS_MAX_LABEL_NAME
index|]
decl_stmt|;
comment|/* Warning: may not be null terminated */
name|u_int16_t
name|ul_unused1
decl_stmt|;
name|u_int64_t
name|ul_uuid
decl_stmt|;
comment|/* Note this is only 4 byte aligned */
name|u_char
name|ul_reserved
index|[
literal|24
index|]
decl_stmt|;
name|u_char
name|ul_unused
index|[
literal|460
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_UFS_FFS_FS_H_ */
end_comment

end_unit

