begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fs.h	8.13 (Berkeley) 3/21/95  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/dinode.h>
end_include

begin_comment
comment|/*  * Each disk drive contains some number of filesystems.  * A filesystem consists of a number of cylinder groups.  * Each cylinder group has inodes and data.  *  * A filesystem is described by its super-block, which in turn  * describes the cylinder groups.  The super-block is critical  * data and is replicated in each cylinder group to protect against  * catastrophic loss.  This is done at `newfs' time and the critical  * super-block data does not change, so the copies need not be  * referenced further unless disaster strikes.  *  * For filesystem fs, the offsets of the various blocks of interest  * are given in the super block as:  *	[fs->fs_sblkno]		Super-block  *	[fs->fs_cblkno]		Cylinder group block  *	[fs->fs_iblkno]		Inode blocks  *	[fs->fs_dblkno]		Data blocks  * The beginning of cylinder group cg in fs, is given by  * the ``cgbase(fs, cg)'' macro.  *  * Depending on the architecture and the media, the superblock may  * reside in any one of four places. For tiny media where every block   * counts, it is placed at the very front of the partition. Historically,  * UFS1 placed it 8K from the front to leave room for the disk label and  * a small bootstrap. For UFS2 it got moved to 64K from the front to leave  * room for the disk label and a bigger bootstrap, and for really piggy  * systems we check at 256K from the front if the first three fail. In  * all cases the size of the superblock will be SBLOCKSIZE. All values are  * given in byte-offset form, so they do not imply a sector size. The  * SBLOCKSEARCH specifies the order in which the locations should be searched.  */
end_comment

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
comment|/*  * Addresses stored in inodes are capable of addressing fragments  * of `blocks'. File system blocks of at most size MAXBSIZE can  * be optionally broken into 2, 4, or 8 pieces, each of which is  * addressable; these pieces may be DEV_BSIZE, or some multiple of  * a DEV_BSIZE unit.  *  * Large files consist of exclusively large data blocks.  To avoid  * undue wasted disk space, the last data block of a small file may be  * allocated as only as many fragments of a large block as are  * necessary.  The filesystem format retains only a single pointer  * to such a fragment, which is a piece of a single large block that  * has been divided.  The size of such a fragment is determinable from  * information in the inode, using the ``blksize(fs, ip, lbn)'' macro.  *  * The filesystem records space availability at the fragment level;  * to determine block availability, aligned fragments are examined.  */
end_comment

begin_comment
comment|/*  * MINBSIZE is the smallest allowable block size.  * In order to insure that it is possible to create files of size  * 2^32 with only two levels of indirection, MINBSIZE is set to 4096.  * MINBSIZE must be big enough to hold a cylinder group block,  * thus changes to (struct cg) must keep its size within MINBSIZE.  * Note that super blocks are always of size SBLOCKSIZE,  * and that both SBLOCKSIZE and MAXBSIZE must be>= MINBSIZE.  */
end_comment

begin_define
define|#
directive|define
name|MINBSIZE
value|4096
end_define

begin_comment
comment|/*  * The path name on which the filesystem is mounted is maintained  * in fs_fsmnt. MAXMNTLEN defines the amount of space allocated in  * the super block for this name.  */
end_comment

begin_define
define|#
directive|define
name|MAXMNTLEN
value|468
end_define

begin_comment
comment|/*  * The volume name for this filesystem is maintained in fs_volname.  * MAXVOLLEN defines the length of the buffer allocated.  */
end_comment

begin_define
define|#
directive|define
name|MAXVOLLEN
value|32
end_define

begin_comment
comment|/*  * There is a 128-byte region in the superblock reserved for in-core  * pointers to summary information. Originally this included an array  * of pointers to blocks of struct csum; now there are just a few  * pointers and the remaining space is padded with fs_ocsp[].  *  * NOCSPTRS determines the size of this padding. One pointer (fs_csp)  * is taken away to point to a contiguous array of struct csum for  * all cylinder groups; a second (fs_maxcluster) points to an array  * of cluster sizes that is computed as cylinder groups are inspected,  * and the third points to an array that tracks the creation of new  * directories. A fourth pointer, fs_active, is used when creating  * snapshots; it points to a bitmap of cylinder groups for which the  * free-block bitmap has changed since the snapshot operation began.  */
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
comment|/*  * MINFREE gives the minimum acceptable percentage of filesystem  * blocks which may be free. If the freelist drops below this level  * only the superuser may continue to allocate blocks. This may  * be set to 0 if no reserve of free blocks is deemed necessary,  * however throughput drops by fifty percent if the filesystem  * is run at between 95% and 100% full; thus the minimum default  * value of fs_minfree is 5%. However, to get good clustering  * performance, 10% is a better choice. hence we use 10% as our  * default value. With 10% free space, fragmentation is not a  * problem, so we choose to optimize for time.  */
end_comment

begin_define
define|#
directive|define
name|MINFREE
value|8
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
comment|/*  * The maximum number of snapshot nodes that can be associated  * with each filesystem. This limit affects only the number of  * snapshot files that can be recorded within the superblock so  * that they can be found when the filesystem is mounted. However,  * maintaining too many will slow the filesystem performance, so  * having this limit is a good idea.  */
end_comment

begin_define
define|#
directive|define
name|FSMAXSNAP
value|20
end_define

begin_comment
comment|/*  * Used to identify special blocks in snapshots:  *  * BLK_NOCOPY - A block that was unallocated at the time the snapshot  *	was taken, hence does not need to be copied when written.  * BLK_SNAP - A block held by another snapshot that is not needed by this  *	snapshot. When the other snapshot is freed, the BLK_SNAP entries  *	are converted to BLK_NOCOPY. These are needed to allow fsck to  *	identify blocks that are in use by other snapshots (which are  *	expunged from this snapshot).  */
end_comment

begin_define
define|#
directive|define
name|BLK_NOCOPY
value|((ufs2_daddr_t)(1))
end_define

begin_define
define|#
directive|define
name|BLK_SNAP
value|((ufs2_daddr_t)(2))
end_define

begin_comment
comment|/*  * Sysctl values for the fast filesystem.  */
end_comment

begin_define
define|#
directive|define
name|FFS_ADJ_REFCNT
value|1
end_define

begin_comment
comment|/* adjust inode reference count */
end_comment

begin_define
define|#
directive|define
name|FFS_ADJ_BLKCNT
value|2
end_define

begin_comment
comment|/* adjust inode used block count */
end_comment

begin_define
define|#
directive|define
name|FFS_BLK_FREE
value|3
end_define

begin_comment
comment|/* free range of blocks in map */
end_comment

begin_define
define|#
directive|define
name|FFS_DIR_FREE
value|4
end_define

begin_comment
comment|/* free specified dir inodes in map */
end_comment

begin_define
define|#
directive|define
name|FFS_FILE_FREE
value|5
end_define

begin_comment
comment|/* free specified file inodes in map */
end_comment

begin_define
define|#
directive|define
name|FFS_SET_FLAGS
value|6
end_define

begin_comment
comment|/* set filesystem flags */
end_comment

begin_define
define|#
directive|define
name|FFS_ADJ_NDIR
value|7
end_define

begin_comment
comment|/* adjust number of directories */
end_comment

begin_define
define|#
directive|define
name|FFS_ADJ_NBFREE
value|8
end_define

begin_comment
comment|/* adjust number of free blocks */
end_comment

begin_define
define|#
directive|define
name|FFS_ADJ_NIFREE
value|9
end_define

begin_comment
comment|/* adjust number of free inodes */
end_comment

begin_define
define|#
directive|define
name|FFS_ADJ_NFFREE
value|10
end_define

begin_comment
comment|/* adjust number of free frags */
end_comment

begin_define
define|#
directive|define
name|FFS_ADJ_NUMCLUSTERS
value|11
end_define

begin_comment
comment|/* adjust number of free clusters */
end_comment

begin_define
define|#
directive|define
name|FFS_SET_CWD
value|12
end_define

begin_comment
comment|/* set current directory */
end_comment

begin_define
define|#
directive|define
name|FFS_SET_DOTDOT
value|13
end_define

begin_comment
comment|/* set inode number for ".." */
end_comment

begin_define
define|#
directive|define
name|FFS_UNLINK
value|14
end_define

begin_comment
comment|/* remove a name in the filesystem */
end_comment

begin_define
define|#
directive|define
name|FFS_SET_INODE
value|15
end_define

begin_comment
comment|/* update an on-disk inode */
end_comment

begin_define
define|#
directive|define
name|FFS_SET_BUFOUTPUT
value|16
end_define

begin_comment
comment|/* set buffered writing on descriptor */
end_comment

begin_define
define|#
directive|define
name|FFS_MAXID
value|16
end_define

begin_comment
comment|/* number of valid ffs ids */
end_comment

begin_comment
comment|/*  * Command structure passed in to the filesystem to adjust filesystem values.  */
end_comment

begin_define
define|#
directive|define
name|FFS_CMD_VERSION
value|0x19790518
end_define

begin_comment
comment|/* version ID */
end_comment

begin_struct
struct|struct
name|fsck_cmd
block|{
name|int32_t
name|version
decl_stmt|;
comment|/* version of command structure */
name|int32_t
name|handle
decl_stmt|;
comment|/* reference to filesystem to be changed */
name|int64_t
name|value
decl_stmt|;
comment|/* inode or block number to be affected */
name|int64_t
name|size
decl_stmt|;
comment|/* amount or range to be adjusted */
name|int64_t
name|spare
decl_stmt|;
comment|/* reserved for future use */
block|}
struct|;
end_struct

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
name|cs_numclusters
decl_stmt|;
comment|/* number of free clusters */
name|int64_t
name|cs_spare
index|[
literal|3
index|]
decl_stmt|;
comment|/* future expansion */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Super block for an FFS filesystem.  */
end_comment

begin_struct
struct|struct
name|fs
block|{
name|int32_t
name|fs_firstfield
decl_stmt|;
comment|/* historic filesystem linked list, */
name|int32_t
name|fs_unused_1
decl_stmt|;
comment|/*     used for incore super blocks */
name|int32_t
name|fs_sblkno
decl_stmt|;
comment|/* offset of super-block in filesys */
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
name|u_int32_t
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
name|u_int32_t
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
name|int32_t
name|fs_id
index|[
literal|2
index|]
decl_stmt|;
comment|/* unique filesystem id */
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
comment|/* cylinders in filesystem */
name|int32_t
name|fs_old_cpg
decl_stmt|;
comment|/* cylinders per group */
name|u_int32_t
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
comment|/* filesystem is clean flag */
name|int8_t
name|fs_ronly
decl_stmt|;
comment|/* mounted read-only flag */
name|int8_t
name|fs_old_flags
decl_stmt|;
comment|/* old FS_ flags */
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
name|u_int64_t
name|fs_swuid
decl_stmt|;
comment|/* system-wide uid */
name|int32_t
name|fs_pad
decl_stmt|;
comment|/* due to alignment of fs_swuid */
comment|/* these fields retain the current block allocation info */
name|int32_t
name|fs_cgrotor
decl_stmt|;
comment|/* last cg searched */
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
comment|/* (u) # of contig. allocated dirs */
name|struct
name|csum
modifier|*
name|fs_csp
decl_stmt|;
comment|/* (u) cg summary info buffer */
name|int32_t
modifier|*
name|fs_maxcluster
decl_stmt|;
comment|/* (u) max cluster in each cyl group */
name|u_int
modifier|*
name|fs_active
decl_stmt|;
comment|/* (u) used by snapshots to track fs */
name|int32_t
name|fs_old_cpc
decl_stmt|;
comment|/* cyl per cycle in postbl */
name|int32_t
name|fs_maxbsize
decl_stmt|;
comment|/* maximum blocking factor permitted */
name|int64_t
name|fs_unrefs
decl_stmt|;
comment|/* number of unreferenced inodes */
name|int64_t
name|fs_providersize
decl_stmt|;
comment|/* size of underlying GEOM provider */
name|int64_t
name|fs_metaspace
decl_stmt|;
comment|/* size of area reserved for metadata */
name|int64_t
name|fs_sparecon64
index|[
literal|14
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
comment|/* (u) cylinder summary information */
name|ufs_time_t
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
name|ufs2_daddr_t
name|fs_csaddr
decl_stmt|;
comment|/* blk addr of cyl grp summary area */
name|int64_t
name|fs_pendingblocks
decl_stmt|;
comment|/* (u) blocks being freed */
name|u_int32_t
name|fs_pendinginodes
decl_stmt|;
comment|/* (u) inodes being freed */
name|uint32_t
name|fs_snapinum
index|[
name|FSMAXSNAP
index|]
decl_stmt|;
comment|/* list of snapshot inode numbers */
name|u_int32_t
name|fs_avgfilesize
decl_stmt|;
comment|/* expected average file size */
name|u_int32_t
name|fs_avgfpdir
decl_stmt|;
comment|/* expected # of files per directory */
name|int32_t
name|fs_save_cgsize
decl_stmt|;
comment|/* save real cg size to use fs_bsize */
name|ufs_time_t
name|fs_mtime
decl_stmt|;
comment|/* Last mount or fsck time. */
name|int32_t
name|fs_sujfree
decl_stmt|;
comment|/* SUJ free list */
name|int32_t
name|fs_sparecon32
index|[
literal|23
index|]
decl_stmt|;
comment|/* reserved for future constants */
name|int32_t
name|fs_flags
decl_stmt|;
comment|/* see FS_ flags below */
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
comment|/* validate fs_clean field */
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

begin_comment
comment|/* Sanity checking. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CTASSERT
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|fs
argument_list|)
operator|==
literal|1376
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Filesystem identification  */
end_comment

begin_define
define|#
directive|define
name|FS_UFS1_MAGIC
value|0x011954
end_define

begin_comment
comment|/* UFS1 fast filesystem magic number */
end_comment

begin_define
define|#
directive|define
name|FS_UFS2_MAGIC
value|0x19540119
end_define

begin_comment
comment|/* UFS2 fast filesystem magic number */
end_comment

begin_define
define|#
directive|define
name|FS_BAD_MAGIC
value|0x19960408
end_define

begin_comment
comment|/* UFS incomplete newfs magic number */
end_comment

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
comment|/*  * Filesystem flags.  *  * The FS_UNCLEAN flag is set by the kernel when the filesystem was  * mounted with fs_clean set to zero. The FS_DOSOFTDEP flag indicates  * that the filesystem should be managed by the soft updates code.  * Note that the FS_NEEDSFSCK flag is set and cleared only by the  * fsck utility. It is set when background fsck finds an unexpected  * inconsistency which requires a traditional foreground fsck to be  * run. Such inconsistencies should only be found after an uncorrectable  * disk error. A foreground fsck will clear the FS_NEEDSFSCK flag when  * it has successfully cleaned up the filesystem. The kernel uses this  * flag to enforce that inconsistent filesystems be mounted read-only.  * The FS_INDEXDIRS flag when set indicates that the kernel maintains  * on-disk auxiliary indexes (such as B-trees) for speeding directory  * accesses. Kernels that do not support auxiliary indices clear the  * flag to indicate that the indices need to be rebuilt (by fsck) before  * they can be used.  *  * FS_ACLS indicates that POSIX.1e ACLs are administratively enabled  * for the file system, so they should be loaded from extended attributes,  * observed for access control purposes, and be administered by object  * owners.  FS_NFS4ACLS indicates that NFSv4 ACLs are administratively  * enabled.  This flag is mutually exclusive with FS_ACLS.  FS_MULTILABEL  * indicates that the TrustedBSD MAC Framework should attempt to back MAC  * labels into extended attributes on the file system rather than maintain  * a single mount label for all objects.  */
end_comment

begin_define
define|#
directive|define
name|FS_UNCLEAN
value|0x0001
end_define

begin_comment
comment|/* filesystem not clean at mount */
end_comment

begin_define
define|#
directive|define
name|FS_DOSOFTDEP
value|0x0002
end_define

begin_comment
comment|/* filesystem using soft dependencies */
end_comment

begin_define
define|#
directive|define
name|FS_NEEDSFSCK
value|0x0004
end_define

begin_comment
comment|/* filesystem needs sync fsck before mount */
end_comment

begin_define
define|#
directive|define
name|FS_SUJ
value|0x0008
end_define

begin_comment
comment|/* Filesystem using softupdate journal */
end_comment

begin_define
define|#
directive|define
name|FS_ACLS
value|0x0010
end_define

begin_comment
comment|/* file system has POSIX.1e ACLs enabled */
end_comment

begin_define
define|#
directive|define
name|FS_MULTILABEL
value|0x0020
end_define

begin_comment
comment|/* file system is MAC multi-label */
end_comment

begin_define
define|#
directive|define
name|FS_GJOURNAL
value|0x0040
end_define

begin_comment
comment|/* gjournaled file system */
end_comment

begin_define
define|#
directive|define
name|FS_FLAGS_UPDATED
value|0x0080
end_define

begin_comment
comment|/* flags have been moved to new location */
end_comment

begin_define
define|#
directive|define
name|FS_NFS4ACLS
value|0x0100
end_define

begin_comment
comment|/* file system has NFSv4 ACLs enabled */
end_comment

begin_define
define|#
directive|define
name|FS_INDEXDIRS
value|0x0200
end_define

begin_comment
comment|/* kernel supports indexed directories */
end_comment

begin_define
define|#
directive|define
name|FS_TRIM
value|0x0400
end_define

begin_comment
comment|/* issue BIO_DELETE for deleted blocks */
end_comment

begin_comment
comment|/*  * Macros to access bits in the fs_active array.  */
end_comment

begin_define
define|#
directive|define
name|ACTIVECGNUM
parameter_list|(
name|fs
parameter_list|,
name|cg
parameter_list|)
value|((fs)->fs_active[(cg) / (NBBY * sizeof(int))])
end_define

begin_define
define|#
directive|define
name|ACTIVECGOFF
parameter_list|(
name|cg
parameter_list|)
value|(1<< ((cg) % (NBBY * sizeof(int))))
end_define

begin_define
define|#
directive|define
name|ACTIVESET
parameter_list|(
name|fs
parameter_list|,
name|cg
parameter_list|)
value|do {					\ 	if ((fs)->fs_active)						\ 		ACTIVECGNUM((fs), (cg)) |= ACTIVECGOFF((cg));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|ACTIVECLEAR
parameter_list|(
name|fs
parameter_list|,
name|cg
parameter_list|)
value|do {					\ 	if ((fs)->fs_active)						\ 		ACTIVECGNUM((fs), (cg))&= ~ACTIVECGOFF((cg));		\ } while (0)
end_define

begin_comment
comment|/*  * The size of a cylinder group is calculated by CGSIZE. The maximum size  * is limited by the fact that cylinder groups are at most one block.  * Its size is derived from the size of the maps maintained in the  * cylinder group and the (struct cg) size.  */
end_comment

begin_define
define|#
directive|define
name|CGSIZE
parameter_list|(
name|fs
parameter_list|)
define|\
comment|/* base cg */
value|(sizeof(struct cg) + sizeof(int32_t) + \
comment|/* old btotoff */
value|(fs)->fs_old_cpg * sizeof(int32_t) + \
comment|/* old boff */
value|(fs)->fs_old_cpg * sizeof(u_int16_t) + \
comment|/* inode map */
value|howmany((fs)->fs_ipg, NBBY) + \
comment|/* block map */
value|howmany((fs)->fs_fpg, NBBY) +\
comment|/* if present */
value|((fs)->fs_contigsumsize<= 0 ? 0 : \
comment|/* cluster sum */
value|(fs)->fs_contigsumsize * sizeof(int32_t) + \
comment|/* cluster map */
value|howmany(fragstoblks(fs, (fs)->fs_fpg), NBBY)))
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
comment|/*  * Cylinder group block for a filesystem.  */
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
name|u_int32_t
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
name|u_int32_t
name|cg_ndblk
decl_stmt|;
comment|/* number of data blocks this cg */
name|struct
name|csum
name|cg_cs
decl_stmt|;
comment|/* cylinder summary information */
name|u_int32_t
name|cg_rotor
decl_stmt|;
comment|/* position of last used block */
name|u_int32_t
name|cg_frotor
decl_stmt|;
comment|/* position of last used frag */
name|u_int32_t
name|cg_irotor
decl_stmt|;
comment|/* position of last used inode */
name|u_int32_t
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
name|u_int32_t
name|cg_iusedoff
decl_stmt|;
comment|/* (u_int8) used inode map */
name|u_int32_t
name|cg_freeoff
decl_stmt|;
comment|/* (u_int8) free block map */
name|u_int32_t
name|cg_nextfreeoff
decl_stmt|;
comment|/* (u_int8) next available space */
name|u_int32_t
name|cg_clustersumoff
decl_stmt|;
comment|/* (u_int32) counts of avail clusters */
name|u_int32_t
name|cg_clusteroff
decl_stmt|;
comment|/* (u_int8) free cluster map */
name|u_int32_t
name|cg_nclusterblks
decl_stmt|;
comment|/* number of clusters this cg */
name|u_int32_t
name|cg_niblk
decl_stmt|;
comment|/* number of inode blocks this cg */
name|u_int32_t
name|cg_initediblk
decl_stmt|;
comment|/* last initialized inode */
name|u_int32_t
name|cg_unrefs
decl_stmt|;
comment|/* number of unreferenced inodes */
name|int32_t
name|cg_sparecon32
index|[
literal|2
index|]
decl_stmt|;
comment|/* reserved for future use */
name|ufs_time_t
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
comment|/*  * Macros for access to cylinder group array structures  */
end_comment

begin_define
define|#
directive|define
name|cg_chkmagic
parameter_list|(
name|cgp
parameter_list|)
value|((cgp)->cg_magic == CG_MAGIC)
end_define

begin_define
define|#
directive|define
name|cg_inosused
parameter_list|(
name|cgp
parameter_list|)
define|\
value|((u_int8_t *)((u_int8_t *)(cgp) + (cgp)->cg_iusedoff))
end_define

begin_define
define|#
directive|define
name|cg_blksfree
parameter_list|(
name|cgp
parameter_list|)
define|\
value|((u_int8_t *)((u_int8_t *)(cgp) + (cgp)->cg_freeoff))
end_define

begin_define
define|#
directive|define
name|cg_clustersfree
parameter_list|(
name|cgp
parameter_list|)
define|\
value|((u_int8_t *)((u_int8_t *)(cgp) + (cgp)->cg_clusteroff))
end_define

begin_define
define|#
directive|define
name|cg_clustersum
parameter_list|(
name|cgp
parameter_list|)
define|\
value|((int32_t *)((uintptr_t)(cgp) + (cgp)->cg_clustersumoff))
end_define

begin_comment
comment|/*  * Turn filesystem block numbers into disk block addresses.  * This maps filesystem blocks to device size blocks.  */
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
value|((daddr_t)(b)<< (fs)->fs_fsbtodb)
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
comment|/*  * Cylinder group macros to locate things in cylinder groups.  * They calc filesystem addresses of cylinder group data structures.  */
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
value|(((ufs2_daddr_t)(fs)->fs_fpg) * (c))
end_define

begin_define
define|#
directive|define
name|cgdata
parameter_list|(
name|fs
parameter_list|,
name|c
parameter_list|)
value|(cgdmin(fs, c) + (fs)->fs_metaspace)
end_define

begin_comment
comment|/* data zone */
end_comment

begin_define
define|#
directive|define
name|cgmeta
parameter_list|(
name|fs
parameter_list|,
name|c
parameter_list|)
value|(cgdmin(fs, c))
end_define

begin_comment
comment|/* meta data */
end_comment

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

begin_define
define|#
directive|define
name|cgstart
parameter_list|(
name|fs
parameter_list|,
name|c
parameter_list|)
define|\
value|((fs)->fs_magic == FS_UFS2_MAGIC ? cgbase(fs, c) :		\        (cgbase(fs, c) + (fs)->fs_old_cgoffset * ((c)& ~((fs)->fs_old_cgmask))))
end_define

begin_comment
comment|/*  * Macros for handling inode numbers:  *     inode number to filesystem block offset.  *     inode number to cylinder group number.  *     inode number to filesystem block address.  */
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
value|(((ino_t)(x)) / (fs)->fs_ipg)
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
value|((ufs2_daddr_t)(cgimin(fs, ino_to_cg(fs, (ino_t)(x))) +		\ 	    (blkstofrags((fs), ((((ino_t)(x)) % (fs)->fs_ipg) / INOPB(fs))))))
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
value|(((ino_t)(x)) % INOPB(fs))
end_define

begin_comment
comment|/*  * Give cylinder group number for a filesystem block.  * Give cylinder group block number for a filesystem block.  */
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

begin_comment
comment|/* Use this only when `blk' is known to be small, e.g.,< UFS_NDADDR. */
end_comment

begin_define
define|#
directive|define
name|smalllblktosize
parameter_list|(
name|fs
parameter_list|,
name|blk
parameter_list|)
comment|/* calculates (blk * fs->fs_bsize) */
define|\
value|((blk)<< (fs)->fs_bshift)
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
comment|/*  * Determining the size of a file block in the filesystem.  */
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
value|(((lbn)>= UFS_NDADDR || (ip)->i_size>= \ 	    (uint64_t)smalllblktosize(fs, (lbn) + 1)) \ 	    ? (fs)->fs_bsize \ 	    : (fragroundup(fs, blkoff(fs, (ip)->i_size))))
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
value|(((lbn)>= UFS_NDADDR || (size)>= ((lbn) + 1)<< (fs)->fs_bshift) \ 	  ? (fs)->fs_bsize \ 	  : (fragroundup(fs, blkoff(fs, (size)))))
end_define

begin_comment
comment|/*  * Number of indirects in a filesystem block.  */
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
comment|/*  * Indirect lbns are aligned on UFS_NDADDR addresses where single indirects  * are the negated address of the lowest lbn reachable, double indirects  * are this lbn - 1 and triple indirects are this lbn - 2.  This yields  * an unusual bit order to determine level.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|lbn_level
parameter_list|(
name|ufs_lbn_t
name|lbn
parameter_list|)
block|{
if|if
condition|(
name|lbn
operator|>=
literal|0
condition|)
return|return
literal|0
return|;
switch|switch
condition|(
name|lbn
operator|&
literal|0x3
condition|)
block|{
case|case
literal|0
case|:
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|1
case|:
break|break;
case|case
literal|2
case|:
return|return
operator|(
literal|2
operator|)
return|;
case|case
literal|3
case|:
return|return
operator|(
literal|1
operator|)
return|;
default|default:
break|break;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ufs_lbn_t
name|lbn_offset
parameter_list|(
name|struct
name|fs
modifier|*
name|fs
parameter_list|,
name|int
name|level
parameter_list|)
block|{
name|ufs_lbn_t
name|res
decl_stmt|;
for|for
control|(
name|res
operator|=
literal|1
init|;
name|level
operator|>
literal|0
condition|;
name|level
operator|--
control|)
name|res
operator|*=
name|NINDIR
argument_list|(
name|fs
argument_list|)
expr_stmt|;
return|return
operator|(
name|res
operator|)
return|;
block|}
end_function

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
comment|/*  * Softdep journal record format.  */
end_comment

begin_define
define|#
directive|define
name|JOP_ADDREF
value|1
end_define

begin_comment
comment|/* Add a reference to an inode. */
end_comment

begin_define
define|#
directive|define
name|JOP_REMREF
value|2
end_define

begin_comment
comment|/* Remove a reference from an inode. */
end_comment

begin_define
define|#
directive|define
name|JOP_NEWBLK
value|3
end_define

begin_comment
comment|/* Allocate a block. */
end_comment

begin_define
define|#
directive|define
name|JOP_FREEBLK
value|4
end_define

begin_comment
comment|/* Free a block or a tree of blocks. */
end_comment

begin_define
define|#
directive|define
name|JOP_MVREF
value|5
end_define

begin_comment
comment|/* Move a reference from one off to another. */
end_comment

begin_define
define|#
directive|define
name|JOP_TRUNC
value|6
end_define

begin_comment
comment|/* Partial truncation record. */
end_comment

begin_define
define|#
directive|define
name|JOP_SYNC
value|7
end_define

begin_comment
comment|/* fsync() complete record. */
end_comment

begin_define
define|#
directive|define
name|JREC_SIZE
value|32
end_define

begin_comment
comment|/* Record and segment header size. */
end_comment

begin_define
define|#
directive|define
name|SUJ_MIN
value|(4 * 1024 * 1024)
end_define

begin_comment
comment|/* Minimum journal size */
end_comment

begin_define
define|#
directive|define
name|SUJ_MAX
value|(32 * 1024 * 1024)
end_define

begin_comment
comment|/* Maximum journal size */
end_comment

begin_define
define|#
directive|define
name|SUJ_FILE
value|".sujournal"
end_define

begin_comment
comment|/* Journal file name */
end_comment

begin_comment
comment|/*  * Size of the segment record header.  There is at most one for each disk  * block in the journal.  The segment header is followed by an array of  * records.  fsck depends on the first element in each record being 'op'  * and the second being 'ino'.  Segments may span multiple disk blocks but  * the header is present on each.  */
end_comment

begin_struct
struct|struct
name|jsegrec
block|{
name|uint64_t
name|jsr_seq
decl_stmt|;
comment|/* Our sequence number */
name|uint64_t
name|jsr_oldest
decl_stmt|;
comment|/* Oldest valid sequence number */
name|uint16_t
name|jsr_cnt
decl_stmt|;
comment|/* Count of valid records */
name|uint16_t
name|jsr_blocks
decl_stmt|;
comment|/* Count of device bsize blocks. */
name|uint32_t
name|jsr_crc
decl_stmt|;
comment|/* 32bit crc of the valid space */
name|ufs_time_t
name|jsr_time
decl_stmt|;
comment|/* timestamp for mount instance */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Reference record.  Records a single link count modification.  */
end_comment

begin_struct
struct|struct
name|jrefrec
block|{
name|uint32_t
name|jr_op
decl_stmt|;
name|uint32_t
name|jr_ino
decl_stmt|;
name|uint32_t
name|jr_parent
decl_stmt|;
name|uint16_t
name|jr_nlink
decl_stmt|;
name|uint16_t
name|jr_mode
decl_stmt|;
name|int64_t
name|jr_diroff
decl_stmt|;
name|uint64_t
name|jr_unused
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Move record.  Records a reference moving within a directory block.  The  * nlink is unchanged but we must search both locations.  */
end_comment

begin_struct
struct|struct
name|jmvrec
block|{
name|uint32_t
name|jm_op
decl_stmt|;
name|uint32_t
name|jm_ino
decl_stmt|;
name|uint32_t
name|jm_parent
decl_stmt|;
name|uint16_t
name|jm_unused
decl_stmt|;
name|int64_t
name|jm_oldoff
decl_stmt|;
name|int64_t
name|jm_newoff
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Block record.  A set of frags or tree of blocks starting at an indirect are  * freed or a set of frags are allocated.  */
end_comment

begin_struct
struct|struct
name|jblkrec
block|{
name|uint32_t
name|jb_op
decl_stmt|;
name|uint32_t
name|jb_ino
decl_stmt|;
name|ufs2_daddr_t
name|jb_blkno
decl_stmt|;
name|ufs_lbn_t
name|jb_lbn
decl_stmt|;
name|uint16_t
name|jb_frags
decl_stmt|;
name|uint16_t
name|jb_oldfrags
decl_stmt|;
name|uint32_t
name|jb_unused
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Truncation record.  Records a partial truncation so that it may be  * completed at check time.  Also used for sync records.  */
end_comment

begin_struct
struct|struct
name|jtrncrec
block|{
name|uint32_t
name|jt_op
decl_stmt|;
name|uint32_t
name|jt_ino
decl_stmt|;
name|int64_t
name|jt_size
decl_stmt|;
name|uint32_t
name|jt_extsize
decl_stmt|;
name|uint32_t
name|jt_pad
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|jrec
block|{
name|struct
name|jsegrec
name|rec_jsegrec
decl_stmt|;
name|struct
name|jrefrec
name|rec_jrefrec
decl_stmt|;
name|struct
name|jmvrec
name|rec_jmvrec
decl_stmt|;
name|struct
name|jblkrec
name|rec_jblkrec
decl_stmt|;
name|struct
name|jtrncrec
name|rec_jtrncrec
decl_stmt|;
block|}
union|;
end_union

begin_ifdef
ifdef|#
directive|ifdef
name|CTASSERT
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|jsegrec
argument_list|)
operator|==
name|JREC_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|jrefrec
argument_list|)
operator|==
name|JREC_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|jmvrec
argument_list|)
operator|==
name|JREC_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|jblkrec
argument_list|)
operator|==
name|JREC_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|jtrncrec
argument_list|)
operator|==
name|JREC_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|union
name|jrec
argument_list|)
operator|==
name|JREC_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|inside
index|[]
decl_stmt|,
name|around
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
modifier|*
name|fragtbl
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * IOCTLs used for filesystem write suspension.  */
end_comment

begin_define
define|#
directive|define
name|UFSSUSPEND
value|_IOW('U', 1, fsid_t)
end_define

begin_define
define|#
directive|define
name|UFSRESUME
value|_IO('U', 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

