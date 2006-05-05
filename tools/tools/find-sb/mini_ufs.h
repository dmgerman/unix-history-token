begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This program, created 2002-10-03 by Garrett A. Wollman  *<wollman@FreeBSD.org>, is in the public domain.  Use at your own risk.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Small extract from ufs/ffs/fs.h to get definition of superblock  * in order to make this tool portable to other unix-like systems.  *  * Based upon:  *  * FreeBSD: src/sys/ufs/ffs/fs.h,v 1.48 2005/02/20 08:02:15 delphij  * FreeBSD: src/sys/ufs/ufs/dinode.h,v 1.15 2005/01/07 02:29:26 imp  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|SBLOCKSIZE
value|8192
end_define

begin_define
define|#
directive|define
name|DEV_BSIZE
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|FS_UFS1_MAGIC
value|0x011954
end_define

begin_define
define|#
directive|define
name|FS_UFS2_MAGIC
value|0x19540119
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
name|MAXMNTLEN
value|468
end_define

begin_define
define|#
directive|define
name|MAXVOLLEN
value|32
end_define

begin_define
define|#
directive|define
name|NOCSPTRS
value|((128 / sizeof(void *)) - 4)
end_define

begin_define
define|#
directive|define
name|FSMAXSNAP
value|20
end_define

begin_typedef
typedef|typedef
name|int64_t
name|ufs_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|ufs2_daddr_t
typedef|;
end_typedef

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
name|int32_t
name|fs_pendinginodes
decl_stmt|;
comment|/* (u) inodes being freed */
name|int32_t
name|fs_snapinum
index|[
name|FSMAXSNAP
index|]
decl_stmt|;
comment|/* list of snapshot inode numbers */
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

end_unit

