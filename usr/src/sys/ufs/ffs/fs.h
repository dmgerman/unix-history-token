begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1981 Regents of the University of California */
end_comment

begin_comment
comment|/*	fs.h	1.13	%G%	*/
end_comment

begin_comment
comment|/*  * Each disk drive contains some number of file systems.  * A file system consists of a number of cylinder groups.  * Each cylinder group has inodes and data.  *  * A file system is described by its super-block, which in turn  * describes the cylinder groups.  The super-block is critical  * data and is replicated in each cylinder group to protect against  * catastrophic loss.  This is done at mkfs time and the critical  * super-block data does not change, so the copies need not be  * referenced further unless disaster strikes.  *  * For file system fs, the offsets of the various blocks of interest  * are given in the super block as:  *	[fs->fs_bblkno]		Boot sector  *	[fs->fs_sblkno]		Super-block  *	[fs->fs_cblkno]		Cylinder group block  *	[fs->fs_iblkno]		Inode blocks  *	[fs->fs_dblkno]		Data blocks  * The beginning of cylinder group cg in fs, is given by  * the ``cgbase(fs, cg)'' macro.  *  * The first boot and super blocks are given in absolute disk addresses.  */
end_comment

begin_define
define|#
directive|define
name|BBSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|SBSIZE
value|8192
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
name|SBLOCK
value|((daddr_t)(BBLOCK + BBSIZE / DEV_BSIZE))
end_define

begin_comment
comment|/*  * Addresses stored in inodes are capable of addressing fragments  * of `blocks'. File system blocks of at most size MAXBSIZE can   * be optionally broken into 2, 4, or 8 pieces, each of which is  * addressible; these pieces may be DEV_BSIZE, or some multiple of  * a DEV_BSIZE unit.  *  * Large files consist of exclusively large data blocks.  To avoid  * undue wasted disk space, the last data block of a small file may be  * allocated as only as many fragments of a large block as are  * necessary.  The file system format retains only a single pointer  * to such a fragment, which is a piece of a single large block that  * has been divided.  The size of such a fragment is determinable from  * information in the inode, using the ``blksize(fs, ip, lbn)'' macro.  *  * The file system records space availability at the fragment level;  * to determine block availability, aligned fragments are examined.  *  * The root inode is the root of the file system.  * Inode 0 can't be used for normal purposes and  * historically bad blocks were linked to inode 1,  * thus the root inode is 2. (inode 1 is no longer used for  * this purpose, however numerous dump tapes make this  * assumption, so we are stuck with it)  * The lost+found directory is given the next available  * inode when it is created by ``mkfs''.  */
end_comment

begin_define
define|#
directive|define
name|ROOTINO
value|((ino_t)2)
end_define

begin_comment
comment|/* i number of all roots */
end_comment

begin_define
define|#
directive|define
name|LOSTFOUNDINO
value|(ROOTINO + 1)
end_define

begin_comment
comment|/*  * MINFREE gives the minimum acceptable percentage of file system  * blocks which may be free. If the freelist drops below this level  * only the superuser may continue to allocate blocks. This may  * be set to 0 if no reserve of free blocks is deemed necessary,  * however severe performance degredations will be observed if the  * file system is run at greater than 90% full; thus the default  * value of fs_minfree is 10%.  *  * Empirically the best trade-off between block fragmentation and  * overall disk utilization at a loading of 90% comes with a  * fragmentation of 4, thus the default fragment size is a fourth  * of the block size.  */
end_comment

begin_define
define|#
directive|define
name|MINFREE
value|10
end_define

begin_define
define|#
directive|define
name|DESFRAG
value|4
end_define

begin_comment
comment|/*  * Under current technology, most 300MB disks have 32 sectors and  * 19 tracks, thus these are the defaults used for fs_nsect and   * fs_ntrak respectively.  */
end_comment

begin_define
define|#
directive|define
name|DFLNSECT
value|32
end_define

begin_define
define|#
directive|define
name|DFLNTRAK
value|19
end_define

begin_comment
comment|/*  * Cylinder group related limits.  *  * For each cylinder we keep track of the availability of blocks at different  * rotational positions, so that we can lay out the data to be picked  * up with minimum rotational latency.  NRPOS is the number of rotational  * positions which we distinguish.  With NRPOS 8 the resolution of our  * summary information is 2ms for a typical 3600 rpm drive.  *  * ROTDELAY gives the minimum number of milliseconds to initiate  * another disk transfer on the same cylinder. It is used in  * determining the rotationally optimal layout for disk blocks  * within a file; the default of fs_rotdelay is 2ms.  */
end_comment

begin_define
define|#
directive|define
name|NRPOS
value|8
end_define

begin_comment
comment|/* number distinct rotational positions */
end_comment

begin_define
define|#
directive|define
name|ROTDELAY
value|2
end_define

begin_comment
comment|/*  * Each file system has a number of inodes statically allocated.  * We allocate one inode slot per NBPI bytes, expecting this  * to be far more than we will ever need.  *  * MAXIPG bounds the number of inodes per cylinder group, and  * is needed only to keep the structure simpler by having the  * only a single variable size element (the free bit map).  *  * N.B.: MAXIPG must be a multiple of INOPB(fs).  */
end_comment

begin_define
define|#
directive|define
name|NBPI
value|2048
end_define

begin_define
define|#
directive|define
name|MAXIPG
value|2048
end_define

begin_comment
comment|/* max number inodes/cyl group */
end_comment

begin_comment
comment|/*  * MINBSIZE is the smallest allowable block size.  * In order to insure that it is possible to create files of size  * 2^32 with only two levels of indirection, MINBSIZE is set to 4096.  * MINBSIZE must be big enough to hold a cylinder group block,  * thus changes to (struct cg) must keep its size within MINBSIZE.  * MAXCPG is limited only to dimension an array in (struct cg);  * it can be made larger as long as that structures size remains  * within the bounds dictated by MINBSIZE.  * Note that super blocks are always of size MAXBSIZE,  * and that MAXBSIZE must be>= MINBSIZE.  */
end_comment

begin_define
define|#
directive|define
name|MINBSIZE
value|4096
end_define

begin_define
define|#
directive|define
name|DESCPG
value|16
end_define

begin_comment
comment|/* desired fs_cpg */
end_comment

begin_define
define|#
directive|define
name|MAXCPG
value|32
end_define

begin_comment
comment|/* maximum fs_cpg */
end_comment

begin_comment
comment|/*  * Per cylinder group information; summarized in blocks allocated  * from first cylinder group data blocks.  These blocks have to be  * read in from fs_csaddr (size fs_cssize) in addition to the  * super block.  *  * N.B. sizeof(struct csum) must be a power of two in order for  * the ``fs_cs'' macro to work (see below).  */
end_comment

begin_struct
struct|struct
name|csum
block|{
name|long
name|cs_ndir
decl_stmt|;
comment|/* number of directories */
name|long
name|cs_nbfree
decl_stmt|;
comment|/* number of free blocks */
name|long
name|cs_nifree
decl_stmt|;
comment|/* number of free inodes */
name|long
name|cs_nffree
decl_stmt|;
comment|/* number of free frags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Super block for a file system.  */
end_comment

begin_define
define|#
directive|define
name|FS_MAGIC
value|0x110854
end_define

begin_struct
struct|struct
name|fs
block|{
name|long
name|fs_magic
decl_stmt|;
comment|/* magic number */
name|daddr_t
name|fs_bblkno
decl_stmt|;
comment|/* abs addr of boot-block in filesys */
name|daddr_t
name|fs_sblkno
decl_stmt|;
comment|/* abs addr of super-block in filesys */
name|daddr_t
name|fs_cblkno
decl_stmt|;
comment|/* offset of cyl-block in filesys */
name|daddr_t
name|fs_iblkno
decl_stmt|;
comment|/* offset of inode-blocks in filesys */
name|daddr_t
name|fs_dblkno
decl_stmt|;
comment|/* offset of data-blocks in filesys */
name|time_t
name|fs_time
decl_stmt|;
comment|/* last time written */
name|long
name|fs_size
decl_stmt|;
comment|/* number of blocks in fs */
name|long
name|fs_dsize
decl_stmt|;
comment|/* number of data blocks in fs */
name|long
name|fs_ncg
decl_stmt|;
comment|/* number of cylinder groups */
name|long
name|fs_bsize
decl_stmt|;
comment|/* size of basic blocks in fs */
name|long
name|fs_fsize
decl_stmt|;
comment|/* size of frag blocks in fs */
name|short
name|fs_frag
decl_stmt|;
comment|/* number of frags in a block in fs */
name|short
name|fs_minfree
decl_stmt|;
comment|/* minimum percentage of free blocks */
name|short
name|fs_rotdelay
decl_stmt|;
comment|/* num of ms for optimal next block */
name|short
name|fs_rps
decl_stmt|;
comment|/* disk revolutions per second */
comment|/* sizes determined by number of cylinder groups and their sizes */
name|daddr_t
name|fs_csaddr
decl_stmt|;
comment|/* blk addr of cyl grp summary area */
name|long
name|fs_cssize
decl_stmt|;
comment|/* size of cyl grp summary area */
name|long
name|fs_cgsize
decl_stmt|;
comment|/* cylinder group size */
comment|/* these fields should be derived from the hardware */
name|short
name|fs_ntrak
decl_stmt|;
comment|/* tracks per cylinder */
name|short
name|fs_nsect
decl_stmt|;
comment|/* sectors per track */
name|long
name|fs_spc
decl_stmt|;
comment|/* sectors per cylinder */
comment|/* this comes from the disk driver partitioning */
name|long
name|fs_ncyl
decl_stmt|;
comment|/* cylinders in file system */
comment|/* these fields can be computed from the others */
name|short
name|fs_cpg
decl_stmt|;
comment|/* cylinders per group */
name|short
name|fs_ipg
decl_stmt|;
comment|/* inodes per group */
name|long
name|fs_fpg
decl_stmt|;
comment|/* blocks per group * fs_frag */
comment|/* this data must be re-computed after crashes */
name|struct
name|csum
name|fs_cstotal
decl_stmt|;
comment|/* cylinder summary information */
comment|/* these fields are cleared at mount time */
name|char
name|fs_fmod
decl_stmt|;
comment|/* super block modified flag */
name|char
name|fs_ronly
decl_stmt|;
comment|/* mounted read-only flag */
name|char
name|fs_fsmnt
index|[
literal|34
index|]
decl_stmt|;
comment|/* name mounted on */
comment|/* these fields retain the current block allocation info */
name|long
name|fs_cgrotor
decl_stmt|;
comment|/* last cg searched */
name|struct
name|csum
modifier|*
name|fs_csp
index|[
name|NBUF
index|]
decl_stmt|;
comment|/* list of fs_cs info buffers */
name|short
name|fs_cpc
decl_stmt|;
comment|/* cyl per cycle in postbl */
name|short
name|fs_postbl
index|[
name|MAXCPG
index|]
index|[
name|NRPOS
index|]
decl_stmt|;
comment|/* head of blocks for each rotation */
name|u_char
name|fs_rotbl
index|[
literal|1
index|]
decl_stmt|;
comment|/* list of blocks for each rotation */
comment|/* actually longer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * convert cylinder group to base address of its global summary info.  *  * N.B. This macro assumes that sizeof(struct csum) is a power of two.  */
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
define|\
value|fs_csp[(indx) / ((fs)->fs_bsize / sizeof(struct csum))] \ 	[(indx) % ((fs)->fs_bsize / sizeof(struct csum))]
end_define

begin_comment
comment|/*  * MAXBPC bounds the size of the rotational layout tables and  * is limited by the fact that the super block is of size SBSIZE.  * The size of these tables is INVERSELY proportional to the block  * size of the file system. It is aggravated by sector sizes that  * are not powers of two, as this increases the number of cylinders  * included before the rotational pattern repeats (fs_cpc).  * Its size is derived from the number of bytes remaining in (struct fs)  */
end_comment

begin_define
define|#
directive|define
name|MAXBPC
value|(SBSIZE - sizeof (struct fs))
end_define

begin_comment
comment|/*  * Cylinder group block for a file system.  */
end_comment

begin_define
define|#
directive|define
name|CG_MAGIC
value|0x092752
end_define

begin_struct
struct|struct
name|cg
block|{
name|long
name|cg_magic
decl_stmt|;
comment|/* magic number */
name|time_t
name|cg_time
decl_stmt|;
comment|/* time last written */
name|long
name|cg_cgx
decl_stmt|;
comment|/* we are the cgx'th cylinder group */
name|short
name|cg_ncyl
decl_stmt|;
comment|/* number of cyl's this cg */
name|short
name|cg_niblk
decl_stmt|;
comment|/* number of inode blocks this cg */
name|long
name|cg_ndblk
decl_stmt|;
comment|/* number of data blocks this cg */
name|struct
name|csum
name|cg_cs
decl_stmt|;
comment|/* cylinder summary information */
name|long
name|cg_rotor
decl_stmt|;
comment|/* position of last used block */
name|long
name|cg_frotor
decl_stmt|;
comment|/* position of last used frag */
name|long
name|cg_irotor
decl_stmt|;
comment|/* position of last used inode */
name|long
name|cg_frsum
index|[
name|MAXFRAG
index|]
decl_stmt|;
comment|/* counts of available frags */
name|long
name|cg_btot
index|[
name|MAXCPG
index|]
decl_stmt|;
comment|/* block totals per cylinder */
name|short
name|cg_b
index|[
name|MAXCPG
index|]
index|[
name|NRPOS
index|]
decl_stmt|;
comment|/* positions of free blocks */
name|char
name|cg_iused
index|[
name|MAXIPG
operator|/
name|NBBY
index|]
decl_stmt|;
comment|/* used inode map */
name|char
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
comment|/*  * MAXBPG bounds the number of blocks of data per cylinder group,  * and is limited by the fact that cylinder groups are at most one block.  * Its size is derived from the size of blocks and the (struct cg) size,  * by the number of remaining bits.  */
end_comment

begin_define
define|#
directive|define
name|MAXBPG
parameter_list|(
name|fs
parameter_list|)
define|\
value|(NBBY * ((fs)->fs_bsize - (sizeof (struct cg))) / (fs)->fs_frag)
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
value|((b) * ((fs)->fs_fsize / DEV_BSIZE))
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
value|((b) / ((fs)->fs_fsize / DEV_BSIZE))
end_define

begin_comment
comment|/*  * Cylinder group macros to locate things in cylinder groups.  *  * cylinder group to disk block address of spare boot block  * and super block  * Note that these are in absolute addresses, and can NOT  * in general be expressable in terms of file system addresses.  */
end_comment

begin_define
define|#
directive|define
name|cgbblock
parameter_list|(
name|fs
parameter_list|,
name|c
parameter_list|)
value|(fsbtodb(fs, cgbase(fs, c)) + (fs)->fs_bblkno)
end_define

begin_define
define|#
directive|define
name|cgsblock
parameter_list|(
name|fs
parameter_list|,
name|c
parameter_list|)
value|(fsbtodb(fs, cgbase(fs, c)) + (fs)->fs_sblkno)
end_define

begin_comment
comment|/*  * file system addresses of cylinder group data structures  */
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
value|((daddr_t)((fs)->fs_fpg * (c)))
end_define

begin_comment
comment|/* base addr */
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
value|(cgbase(fs, c) + (fs)->fs_cblkno)
end_define

begin_comment
comment|/* cg block */
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
value|(cgbase(fs, c) + (fs)->fs_iblkno)
end_define

begin_comment
comment|/* inode blk */
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
value|(cgbase(fs, c) + (fs)->fs_dblkno)
end_define

begin_comment
comment|/* 1st data */
end_comment

begin_comment
comment|/*  * macros for handling inode numbers  *     inode number to file system block offset  *     inode number to cylinder group number  *     inode number to file system block address  */
end_comment

begin_define
define|#
directive|define
name|itoo
parameter_list|(
name|fs
parameter_list|,
name|x
parameter_list|)
value|((x) % INOPB(fs))
end_define

begin_define
define|#
directive|define
name|itog
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
name|itod
parameter_list|(
name|fs
parameter_list|,
name|x
parameter_list|)
define|\
value|((daddr_t)(cgimin(fs, itog(fs, x)) + \ 	(x) % (fs)->fs_ipg / INOPB(fs) * (fs)->fs_frag))
end_define

begin_comment
comment|/*  * give cylinder group number for a file system block  * give cylinder group block number for a file system block  */
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
comment|/*  * compute the cylinder and rotational position of a cyl block addr  */
end_comment

begin_define
define|#
directive|define
name|cbtocylno
parameter_list|(
name|fs
parameter_list|,
name|bno
parameter_list|)
define|\
value|((bno) * NSPF(fs) / (fs)->fs_spc)
end_define

begin_define
define|#
directive|define
name|cbtorpos
parameter_list|(
name|fs
parameter_list|,
name|bno
parameter_list|)
define|\
value|((bno) * NSPF(fs) % (fs)->fs_nsect * NRPOS / (fs)->fs_nsect)
end_define

begin_comment
comment|/*  * determining the size of a file block in the file system  */
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
value|(((lbn)>= NDADDR || (ip)->i_size>= ((lbn) + 1) * (fs)->fs_bsize) \ 		? (fs)->fs_bsize \ 		: (roundup((ip)->i_size % (fs)->fs_bsize, (fs)->fs_fsize)))
end_define

begin_define
define|#
directive|define
name|dblksize
parameter_list|(
name|fs
parameter_list|,
name|dip
parameter_list|,
name|lbn
parameter_list|)
define|\
value|(((lbn)>= NDADDR || (dip)->di_size>= ((lbn) + 1) * (fs)->fs_bsize) \ 		? (fs)->fs_bsize \ 		: (roundup((dip)->di_size % (fs)->fs_bsize, (fs)->fs_fsize)))
end_define

begin_comment
comment|/*  * number of disk sectors per block; assumes DEV_BSIZE byte sector size  */
end_comment

begin_define
define|#
directive|define
name|NSPB
parameter_list|(
name|fs
parameter_list|)
value|((fs)->fs_bsize / DEV_BSIZE)
end_define

begin_define
define|#
directive|define
name|NSPF
parameter_list|(
name|fs
parameter_list|)
value|((fs)->fs_fsize / DEV_BSIZE)
end_define

begin_comment
comment|/*  * INOPB is the number of inodes in a secondary storage block  */
end_comment

begin_define
define|#
directive|define
name|INOPB
parameter_list|(
name|fs
parameter_list|)
value|((fs)->fs_bsize / sizeof (struct dinode))
end_define

begin_define
define|#
directive|define
name|INOPF
parameter_list|(
name|fs
parameter_list|)
value|((fs)->fs_fsize / sizeof (struct dinode))
end_define

begin_comment
comment|/*  * NINDIR is the number of indirects in a file system block  */
end_comment

begin_define
define|#
directive|define
name|NINDIR
parameter_list|(
name|fs
parameter_list|)
value|((fs)->fs_bsize / sizeof (daddr_t))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|struct
name|fs
modifier|*
name|getfs
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

