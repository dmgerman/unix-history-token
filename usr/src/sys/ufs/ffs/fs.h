begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)fs.h	6.6 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Each disk drive contains some number of file systems.  * A file system consists of a number of cylinder groups.  * Each cylinder group has inodes and data.  *  * A file system is described by its super-block, which in turn  * describes the cylinder groups.  The super-block is critical  * data and is replicated in each cylinder group to protect against  * catastrophic loss.  This is done at mkfs time and the critical  * super-block data does not change, so the copies need not be  * referenced further unless disaster strikes.  *  * For file system fs, the offsets of the various blocks of interest  * are given in the super block as:  *	[fs->fs_sblkno]		Super-block  *	[fs->fs_cblkno]		Cylinder group block  *	[fs->fs_iblkno]		Inode blocks  *	[fs->fs_dblkno]		Data blocks  * The beginning of cylinder group cg in fs, is given by  * the ``cgbase(fs, cg)'' macro.  *  * The first boot and super blocks are given in absolute disk addresses.  */
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
comment|/*  * Cylinder group related limits.  *  * For each cylinder we keep track of the availability of blocks at different  * rotational positions, so that we can lay out the data to be picked  * up with minimum rotational latency.  NRPOS is the number of rotational  * positions which we distinguish.  With NRPOS 8 the resolution of our  * summary information is 2ms for a typical 3600 rpm drive.  */
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

begin_comment
comment|/*  * MAXIPG bounds the number of inodes per cylinder group, and  * is needed only to keep the structure simpler by having the  * only a single variable size element (the free bit map).  *  * N.B.: MAXIPG must be a multiple of INOPB(fs).  */
end_comment

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
comment|/*  * MINBSIZE is the smallest allowable block size.  * In order to insure that it is possible to create files of size  * 2^32 with only two levels of indirection, MINBSIZE is set to 4096.  * MINBSIZE must be big enough to hold a cylinder group block,  * thus changes to (struct cg) must keep its size within MINBSIZE.  * MAXCPG is limited only to dimension an array in (struct cg);  * it can be made larger as long as that structures size remains  * within the bounds dictated by MINBSIZE.  * Note that super blocks are always of size SBSIZE,  * and that both SBSIZE and MAXBSIZE must be>= MINBSIZE.  */
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
name|MAXCPG
value|32
end_define

begin_comment
comment|/* maximum fs_cpg */
end_comment

begin_comment
comment|/*  * The path name on which the file system is mounted is maintained  * in fs_fsmnt. MAXMNTLEN defines the amount of space allocated in   * the super block for this name.  * The limit on the amount of summary information per file system  * is defined by MAXCSBUFS. It is currently parameterized for a  * maximum of two million cylinders.  */
end_comment

begin_define
define|#
directive|define
name|MAXMNTLEN
value|512
end_define

begin_define
define|#
directive|define
name|MAXCSBUFS
value|32
end_define

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
value|0x011954
end_define

begin_struct
struct|struct
name|fs
block|{
name|struct
name|fs
modifier|*
name|fs_link
decl_stmt|;
comment|/* linked list of file systems */
name|struct
name|fs
modifier|*
name|fs_rlink
decl_stmt|;
comment|/*     used for incore super blocks */
name|daddr_t
name|fs_sblkno
decl_stmt|;
comment|/* addr of super-block in filesys */
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
comment|/* offset of first data after cg */
name|long
name|fs_cgoffset
decl_stmt|;
comment|/* cylinder group offset in cylinder */
name|long
name|fs_cgmask
decl_stmt|;
comment|/* used to calc mod fs_ntrak */
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
name|long
name|fs_frag
decl_stmt|;
comment|/* number of frags in a block in fs */
comment|/* these are configuration parameters */
name|long
name|fs_minfree
decl_stmt|;
comment|/* minimum percentage of free blocks */
name|long
name|fs_rotdelay
decl_stmt|;
comment|/* num of ms for optimal next block */
name|long
name|fs_rps
decl_stmt|;
comment|/* disk revolutions per second */
comment|/* these fields can be computed from the others */
name|long
name|fs_bmask
decl_stmt|;
comment|/* ``blkoff'' calc of blk offsets */
name|long
name|fs_fmask
decl_stmt|;
comment|/* ``fragoff'' calc of frag offsets */
name|long
name|fs_bshift
decl_stmt|;
comment|/* ``lblkno'' calc of logical blkno */
name|long
name|fs_fshift
decl_stmt|;
comment|/* ``numfrags'' calc number of frags */
comment|/* these are configuration parameters */
name|long
name|fs_maxcontig
decl_stmt|;
comment|/* max number of contiguous blks */
name|long
name|fs_maxbpg
decl_stmt|;
comment|/* max number of blks per cyl group */
comment|/* these fields can be computed from the others */
name|long
name|fs_fragshift
decl_stmt|;
comment|/* block to frag shift */
name|long
name|fs_fsbtodb
decl_stmt|;
comment|/* fsbtodb and dbtofsb shift constant */
name|long
name|fs_sbsize
decl_stmt|;
comment|/* actual size of super block */
name|long
name|fs_csmask
decl_stmt|;
comment|/* csum block offset */
name|long
name|fs_csshift
decl_stmt|;
comment|/* csum block number */
name|long
name|fs_nindir
decl_stmt|;
comment|/* value of NINDIR */
name|long
name|fs_inopb
decl_stmt|;
comment|/* value of INOPB */
name|long
name|fs_nspf
decl_stmt|;
comment|/* value of NSPF */
name|long
name|fs_optim
decl_stmt|;
comment|/* optimization preference, see below */
name|long
name|fs_sparecon
index|[
literal|5
index|]
decl_stmt|;
comment|/* reserved for future constants */
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
name|long
name|fs_ntrak
decl_stmt|;
comment|/* tracks per cylinder */
name|long
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
name|long
name|fs_cpg
decl_stmt|;
comment|/* cylinders per group */
name|long
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
name|fs_clean
decl_stmt|;
comment|/* file system is clean flag */
name|char
name|fs_ronly
decl_stmt|;
comment|/* mounted read-only flag */
name|char
name|fs_flags
decl_stmt|;
comment|/* currently unused flag */
name|char
name|fs_fsmnt
index|[
name|MAXMNTLEN
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
name|MAXCSBUFS
index|]
decl_stmt|;
comment|/* list of fs_cs info buffers */
name|long
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
name|long
name|fs_magic
decl_stmt|;
comment|/* magic number */
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
comment|/*  * Convert cylinder group to base address of its global summary info.  *  * N.B. This macro assumes that sizeof(struct csum) is a power of two.  */
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
value|fs_csp[(indx)>> (fs)->fs_csshift][(indx)& ~(fs)->fs_csmask]
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
value|0x090255
end_define

begin_struct
struct|struct
name|cg
block|{
name|struct
name|cg
modifier|*
name|cg_link
decl_stmt|;
comment|/* linked list of cyl groups */
name|struct
name|cg
modifier|*
name|cg_rlink
decl_stmt|;
comment|/*     used for incore cyl groups */
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
name|long
name|cg_magic
decl_stmt|;
comment|/* magic number */
name|u_char
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
value|(fragstoblks((fs), (NBBY * ((fs)->fs_bsize - (sizeof (struct cg))))))
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
value|((daddr_t)((fs)->fs_fpg * (c)))
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
define|\
value|(cgbase(fs, c) + (fs)->fs_cgoffset * ((c)& ~((fs)->fs_cgmask)))
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

begin_comment
comment|/*  * Macros for handling inode numbers:  *     inode number to file system block offset.  *     inode number to cylinder group number.  *     inode number to file system block address.  */
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
value|((daddr_t)(cgimin(fs, itog(fs, x)) + \ 	(blkstofrags((fs), (((x) % (fs)->fs_ipg) / INOPB(fs))))))
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
value|((bno) * NSPF(fs) % (fs)->fs_spc % (fs)->fs_nsect * NRPOS / (fs)->fs_nsect)
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
value|((loc)& ~(fs)->fs_bmask)
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
value|((loc)& ~(fs)->fs_fmask)
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
value|(((size) + (fs)->fs_bsize - 1)& (fs)->fs_bmask)
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
value|(((size) + (fs)->fs_fsize - 1)& (fs)->fs_fmask)
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
comment|/*  * Determine the number of available frags given a  * percentage to hold in reserve  */
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
value|(blkstofrags((fs), (fs)->fs_cstotal.cs_nbfree) + \ 	(fs)->fs_cstotal.cs_nffree - ((fs)->fs_dsize * (percentreserved) / 100))
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
value|(((lbn)>= NDADDR || (ip)->i_size>= ((lbn) + 1)<< (fs)->fs_bshift) \ 	    ? (fs)->fs_bsize \ 	    : (fragroundup(fs, blkoff(fs, (ip)->i_size))))
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
value|(((lbn)>= NDADDR || (dip)->di_size>= ((lbn) + 1)<< (fs)->fs_bshift) \ 	    ? (fs)->fs_bsize \ 	    : (fragroundup(fs, blkoff(fs, (dip)->di_size))))
end_define

begin_comment
comment|/*  * Number of disk sectors per block; assumes DEV_BSIZE byte sector size.  */
end_comment

begin_define
define|#
directive|define
name|NSPB
parameter_list|(
name|fs
parameter_list|)
value|((fs)->fs_nspf<< (fs)->fs_fragshift)
end_define

begin_define
define|#
directive|define
name|NSPF
parameter_list|(
name|fs
parameter_list|)
value|((fs)->fs_nspf)
end_define

begin_comment
comment|/*  * INOPB is the number of inodes in a secondary storage block.  */
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
comment|/*  * NINDIR is the number of indirects in a file system block.  */
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

begin_function_decl
name|struct
name|fs
modifier|*
name|mountfs
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

