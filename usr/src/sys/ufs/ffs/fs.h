begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1981 Regents of the University of California */
end_comment

begin_comment
comment|/*	fs.h	1.6	%G%	*/
end_comment

begin_comment
comment|/*  * Each disk drive contains some number of file systems.  * A file system consists of a number of cylinder groups.  * Each cylinder group has inodes and data.  *  * A file system is described by its super-block, which in turn  * describes the cylinder groups.  The super-block is critical  * data and is replicated in each cylinder group to protect against  * catastrophic loss.  This is done at mkfs time and the critical  * super-block data does not change, so the copies need not be  * referenced further unless disaster strikes.  *  * For file system fs and a cylinder group number cg:  *	[BBLOCK]	Boot sector and bad block information  *	[SBLOCK]	Super-block  *	[CBLOCK]	Cylinder group block  *	[IBLOCK..IBLOCK+fs.fs_ipg/INOPB)  *			Inode blocks  *	[IBLOCK+fs.fs_ipg/INOPB..fs.fs_fpg/FRAG)  *			Data blocks  * The beginning of data blocks for cg in fs is also given by cgdmin(cg,fs).  */
end_comment

begin_define
define|#
directive|define
name|BBLOCK
value|((daddr_t)(0*FRAG))
end_define

begin_define
define|#
directive|define
name|SBLOCK
value|((daddr_t)(1*FRAG))
end_define

begin_define
define|#
directive|define
name|CBLOCK
value|((daddr_t)(2*FRAG))
end_define

begin_define
define|#
directive|define
name|IBLOCK
value|((daddr_t)(3*FRAG))
end_define

begin_comment
comment|/*  * Addresses stored in inodes are capable of addressing fragments of `blocks.'  * File system blocks of size BSIZE can be broken into FRAG pieces,  * each of which is addressible; these pieces may be sectors, or some  * multiple of a sector size (e.g. 1k byte units).  *  * Large files consist of exclusively large (BSIZE) data blocks.  To avoid  * undue fragmentation, the last data block of a small file may be  * allocated as only as many pieces  * of a large block as are necessary.  The file system format retains  * only a single pointer to such a fragment, which is a piece of a single  * BSIZE block which has been divided.  The size of such a fragment is  * determinable from information in the inode.  *  * The file system records space availability at the fragment level;  * to determine block availability, aligned fragments are examined.  *  * For each cylinder we keep track of the availability of blocks at different  * rotational positions, so that we can lay out the data to be picked  * up with minimum rotational latency.  NRPOS is the number of rotational  * positions which we distinguish.  With NRPOS 8 the resolution of our  * summary information is 2ms for a typical 3600 rpm drive.  */
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
comment|/*  * Information per cylinder group summarized in blocks allocated  * from first cylinder group data blocks.  These blocks have to be  * specially noticed in mkfs, icheck and fsck.  */
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

begin_define
define|#
directive|define
name|cssize
parameter_list|(
name|fs
parameter_list|)
value|((fs)->fs_ncg*sizeof(struct csum))
end_define

begin_define
define|#
directive|define
name|csaddr
parameter_list|(
name|fs
parameter_list|)
value|(cgdmin(0, fs))
end_define

begin_comment
comment|/*  * Each file system has a number of inodes statically allocated.  * We allocate one inode slot per NBPI data bytes, expecting this  * to be far more than we will ever need.  Actually, the directory  * structure has inode numbers kept in 16 bits, so no more than  * 65K inodes are possible, and this usually cuts off well above  * the number suggested by NBPI.  *   * THE DIRECTORY STRUCTURE SHOULD BE CHANGED SOON TO ALLOW  * LARGER INODE NUMBERS (SEE DIR.H).  */
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
comment|/* MAXCPG is limited only to dimension an array in (struct cg); */
end_comment

begin_comment
comment|/* it can be made larger as long as that structures size remains sane. */
end_comment

begin_comment
comment|/*  * Super block for a file system.  *  * The super block is nominally located at disk block 1 although  * this is naive due to bad blocks.  Inode 0 can't be used for normal  * purposes, historically bad blocks were linked to inode 1,  * thus the root inode is 2. (inode 1 is no longer used for  * this purpose, however numerous dump tapes make this  * assumption, so we are stuck with it)  */
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
name|fs_sblkno
decl_stmt|;
comment|/* offset of super-block in filesys */
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
comment|/* sizes determined by number of cylinder groups and their sizes */
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
comment|/* blocks per group*FRAG */
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
name|fs_postbl
index|[
name|NRPOS
index|]
decl_stmt|;
comment|/* head of blocks for each rotation */
name|short
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

begin_define
define|#
directive|define
name|fs_cs
parameter_list|(
name|indx
parameter_list|)
value|fs_csp[(indx) / (BSIZE / sizeof(struct csum))] \ 			  [(indx) % (BSIZE / sizeof(struct csum))]
end_define

begin_comment
comment|/*  * Cylinder group macros to locate things in cylinder groups.  */
end_comment

begin_comment
comment|/* cylinder group to disk block at very beginning */
end_comment

begin_define
define|#
directive|define
name|cgbase
parameter_list|(
name|c
parameter_list|,
name|fs
parameter_list|)
value|((daddr_t)((fs)->fs_fpg*(c)))
end_define

begin_comment
comment|/* cylinder group to spare super block address */
end_comment

begin_define
define|#
directive|define
name|cgsblock
parameter_list|(
name|c
parameter_list|,
name|fs
parameter_list|)
define|\
value|(cgbase(c,fs) + SBLOCK)
end_define

begin_comment
comment|/* convert cylinder group to index of its cg block */
end_comment

begin_define
define|#
directive|define
name|cgtod
parameter_list|(
name|c
parameter_list|,
name|fs
parameter_list|)
define|\
value|(cgbase(c,fs) + CBLOCK)
end_define

begin_comment
comment|/* give address of first inode block in cylinder group */
end_comment

begin_define
define|#
directive|define
name|cgimin
parameter_list|(
name|c
parameter_list|,
name|fs
parameter_list|)
define|\
value|(cgbase(c,fs) + IBLOCK)
end_define

begin_comment
comment|/* give address of first data block in cylinder group */
end_comment

begin_define
define|#
directive|define
name|cgdmin
parameter_list|(
name|c
parameter_list|,
name|fs
parameter_list|)
value|(cgimin(c,fs) + (fs)->fs_ipg / INOPF)
end_define

begin_comment
comment|/* turn inode number into cylinder group number */
end_comment

begin_define
define|#
directive|define
name|itog
parameter_list|(
name|x
parameter_list|,
name|fs
parameter_list|)
value|((x)/(fs)->fs_ipg)
end_define

begin_comment
comment|/* turn inode number into disk block address */
end_comment

begin_define
define|#
directive|define
name|itod
parameter_list|(
name|x
parameter_list|,
name|fs
parameter_list|)
value|(cgimin(itog(x,fs),fs)+FRAG*((x)%(fs)->fs_ipg/INOPB))
end_define

begin_comment
comment|/* turn inode number into disk block offset */
end_comment

begin_define
define|#
directive|define
name|itoo
parameter_list|(
name|x
parameter_list|)
value|((x)%INOPB)
end_define

begin_comment
comment|/* give cylinder group number for a disk block */
end_comment

begin_define
define|#
directive|define
name|dtog
parameter_list|(
name|d
parameter_list|,
name|fs
parameter_list|)
value|((d)/(fs)->fs_fpg)
end_define

begin_comment
comment|/* give cylinder group block number for a disk block */
end_comment

begin_define
define|#
directive|define
name|dtogd
parameter_list|(
name|d
parameter_list|,
name|fs
parameter_list|)
value|((d)%(fs)->fs_fpg)
end_define

begin_comment
comment|/*  * Cylinder group related limits.  */
end_comment

begin_comment
comment|/*  * MAXIPG bounds the number of inodes per cylinder group, and  * is needed only to keep the structure simpler by having the  * only a single variable size element (the free bit map).  *  * N.B.: MAXIPG must be a multiple of INOPB.  */
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
comment|/*  * MAXBPG bounds the number of blocks of data per cylinder group,  * and is limited by the fact that cylinder groups are at most one block.  * Its size is derived from the size of blocks and the (struct cg) size,  * by the number of remaining bits.  */
end_comment

begin_define
define|#
directive|define
name|MAXBPG
value|(NBBY*(BSIZE-(sizeof (struct cg)))/FRAG)
end_define

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
name|FRAG
index|]
decl_stmt|;
comment|/* counts of available frags */
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

begin_define
define|#
directive|define
name|cgsize
parameter_list|(
name|fp
parameter_list|)
value|(sizeof (struct cg) + ((fp)->fs_fpg+NBBY-1)/NBBY)
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

