begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)lfs.h	5.2 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|LFS_LABELPAD
value|8192
end_define

begin_comment
comment|/* LFS label size */
end_comment

begin_define
define|#
directive|define
name|LFS_SBPAD
value|8192
end_define

begin_comment
comment|/* LFS superblock size */
end_comment

begin_define
define|#
directive|define
name|MAXMNTLEN
value|512
end_define

begin_comment
comment|/* XXX move from fs.h to mount.h */
end_comment

begin_define
define|#
directive|define
name|LFS_BLKSIZE
value|4096
end_define

begin_comment
comment|/* LFS block size */
end_comment

begin_comment
comment|/* On-disk super block. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|lfs_super
block|{
define|#
directive|define
name|LFS_MAGIC
value|0xdeadbeef
name|u_long
name|lfs_magic
decl_stmt|;
comment|/* magic number */
define|#
directive|define
name|LFS_VERSION
value|1
name|u_long
name|lfs_version
decl_stmt|;
comment|/* version number */
name|u_long
name|lfs_size
decl_stmt|;
comment|/* number of blocks in fs */
name|u_long
name|lfs_ssize
decl_stmt|;
comment|/* number of blocks per segment */
name|u_long
name|lfs_dsize
decl_stmt|;
comment|/* number of data blocks in fs */
name|u_long
name|lfs_bsize
decl_stmt|;
comment|/* size of basic blocks in fs */
name|u_long
name|lfs_fsize
decl_stmt|;
comment|/* size of frag blocks in fs */
name|u_long
name|lfs_frag
decl_stmt|;
comment|/* number of frags in a block in fs */
name|u_long
name|lfs_sbsize
decl_stmt|;
comment|/* actual size of super block */
comment|/* Checkpoint region. */
name|ino_t
name|lfs_free
decl_stmt|;
comment|/* start of the free list */
name|daddr_t
name|lfs_idaddr
decl_stmt|;
comment|/* inode file disk address */
name|ino_t
name|lfs_ifile
decl_stmt|;
comment|/* inode file inode number */
name|daddr_t
name|lfs_lastseg
decl_stmt|;
comment|/* last segment written */
name|u_long
name|lfs_tstamp
decl_stmt|;
comment|/* time stamp */
comment|/* These are configuration parameters. */
name|u_long
name|lfs_minfree
decl_stmt|;
comment|/* minimum percentage of free blocks */
comment|/* These fields can be computed from the others. */
name|u_long
name|lfs_inopb
decl_stmt|;
comment|/* inodes per block */
name|u_long
name|lfs_ifpb
decl_stmt|;
comment|/* IFILE entries per block */
name|u_long
name|lfs_nindir
decl_stmt|;
comment|/* indirect pointers per block */
name|u_long
name|lfs_nseg
decl_stmt|;
comment|/* number of segments */
name|u_long
name|lfs_nspf
decl_stmt|;
comment|/* number of sectors per fragment */
name|u_long
name|lfs_segtabsz
decl_stmt|;
comment|/* segment table size in blocks */
name|u_long
name|lfs_segmask
decl_stmt|;
comment|/* calculate offset within a segment */
name|u_long
name|lfs_segshift
decl_stmt|;
comment|/* fast mult/div for segments */
name|u_long
name|lfs_bmask
decl_stmt|;
comment|/* calc block offset from file offset */
name|u_long
name|lfs_bshift
decl_stmt|;
comment|/* calc block number from file offset */
name|u_long
name|lfs_ffmask
decl_stmt|;
comment|/* calc frag offset from file offset */
name|u_long
name|lfs_ffshift
decl_stmt|;
comment|/* fast mult/div for frag from file */
name|u_long
name|lfs_fbmask
decl_stmt|;
comment|/* calc frag offset from block offset */
name|u_long
name|lfs_fbshift
decl_stmt|;
comment|/* fast mult/div for frag from block */
name|u_long
name|lfs_fsbtodb
decl_stmt|;
comment|/* fsbtodb and dbtofsb shift constant */
define|#
directive|define
name|LFS_MAXNUMSB
value|10
define|#
directive|define
name|LFS_MIN_SBINTERVAL
value|5
name|daddr_t
name|lfs_sboffs
index|[
name|LFS_MAXNUMSB
index|]
decl_stmt|;
comment|/* super-block disk offsets */
block|}
name|LFS_SUPER
typedef|;
end_typedef

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
value|LFSBLKSIZE
end_define

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
name|itod
parameter_list|(
name|fs
parameter_list|,
name|x
parameter_list|)
value|LFS -- IMPLEMENT
end_define

begin_comment
comment|/* In-memory super block. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|lfs
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
name|time_t
name|fs_time
decl_stmt|;
comment|/* last time written */
comment|/* These fields are cleared at mount time. */
name|u_char
name|fs_fmod
decl_stmt|;
comment|/* super block modified flag */
name|u_char
name|fs_clean
decl_stmt|;
comment|/* file system is clean flag */
name|u_char
name|fs_ronly
decl_stmt|;
comment|/* mounted read-only flag */
name|u_char
name|fs_flags
decl_stmt|;
comment|/* currently unused flag */
name|u_char
name|fs_fsmnt
index|[
name|MAXMNTLEN
index|]
decl_stmt|;
comment|/* name mounted on */
comment|/* On-disk structure. */
name|LFS_SUPER
name|fs_super
decl_stmt|;
block|}
name|LFS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fs_bmask
value|fs_super.lfs_bmask
end_define

begin_define
define|#
directive|define
name|fs_bshift
value|fs_super.lfs_bshift
end_define

begin_define
define|#
directive|define
name|fs_bsize
value|fs_super.lfs_bsize
end_define

begin_define
define|#
directive|define
name|fs_dsize
value|fs_super.lfs_dsize
end_define

begin_define
define|#
directive|define
name|fs_fbmask
value|fs_super.lfs_fbmask
end_define

begin_define
define|#
directive|define
name|fs_fbshift
value|fs_super.lfs_fbshift
end_define

begin_define
define|#
directive|define
name|fs_ffmask
value|fs_super.lfs_ffmask
end_define

begin_define
define|#
directive|define
name|fs_ffshift
value|fs_super.lfs_ffshift
end_define

begin_define
define|#
directive|define
name|fs_frag
value|fs_super.lfs_frag
end_define

begin_define
define|#
directive|define
name|fs_free
value|fs_super.lfs_free
end_define

begin_define
define|#
directive|define
name|fs_fsbtodb
value|fs_super.lfs_fsbtodb
end_define

begin_define
define|#
directive|define
name|fs_fsize
value|fs_super.lfs_fsize
end_define

begin_define
define|#
directive|define
name|fs_idaddr
value|fs_super.lfs_idaddr
end_define

begin_define
define|#
directive|define
name|fs_ifile
value|fs_super.lfs_ifile
end_define

begin_define
define|#
directive|define
name|fs_ifpb
value|fs_super.lfs_ifpb
end_define

begin_define
define|#
directive|define
name|fs_inopb
value|fs_super.lfs_inopb
end_define

begin_define
define|#
directive|define
name|fs_lastseg
value|fs_super.lfs_lastseg
end_define

begin_define
define|#
directive|define
name|fs_magic
value|fs_super.lfs_magic
end_define

begin_define
define|#
directive|define
name|fs_minfree
value|fs_super.lfs_minfree
end_define

begin_define
define|#
directive|define
name|fs_nindir
value|fs_super.lfs_nindir
end_define

begin_define
define|#
directive|define
name|fs_nseg
value|fs_super.lfs_nseg
end_define

begin_define
define|#
directive|define
name|fs_nspf
value|fs_super.lfs_nspf
end_define

begin_define
define|#
directive|define
name|fs_sboffs
value|fs_super.lfs_sboffs
end_define

begin_define
define|#
directive|define
name|fs_sbsize
value|fs_super.lfs_sbsize
end_define

begin_define
define|#
directive|define
name|fs_segmask
value|fs_super.lfs_segmask
end_define

begin_define
define|#
directive|define
name|fs_segshift
value|fs_super.lfs_segshift
end_define

begin_define
define|#
directive|define
name|fs_segtabsz
value|fs_super.lfs_segtabsz
end_define

begin_define
define|#
directive|define
name|fs_size
value|fs_super.lfs_size
end_define

begin_define
define|#
directive|define
name|fs_ssize
value|fs_super.lfs_ssize
end_define

begin_define
define|#
directive|define
name|fs_tstamp
value|fs_super.lfs_tstamp
end_define

begin_define
define|#
directive|define
name|fs_version
value|fs_super.lfs_version
end_define

begin_comment
comment|/* Fixed inode numbers. */
end_comment

begin_define
define|#
directive|define
name|LFS_UNUSED_INUM
value|0
end_define

begin_comment
comment|/* Out of band inode number. */
end_comment

begin_define
define|#
directive|define
name|LFS_IFILE_INUM
value|1
end_define

begin_comment
comment|/* Inode number of the ifile. */
end_comment

begin_define
define|#
directive|define
name|LFS_FIRST_INUM
value|2
end_define

begin_comment
comment|/* First free inode number. */
end_comment

begin_comment
comment|/*   * Used to access the first spare of the dinode which we use to store  * the ifile number so we can identify them  */
end_comment

begin_define
define|#
directive|define
name|di_inum
value|di_spare[0]
end_define

begin_typedef
typedef|typedef
struct|struct
name|ifile
block|{
name|u_long
name|if_version
decl_stmt|;
comment|/* inode version number */
define|#
directive|define
name|UNUSED_DADDR
value|0
comment|/* out-of-band daddr */
name|daddr_t
name|if_daddr
decl_stmt|;
comment|/* inode disk address */
union|union
block|{
name|ino_t
name|nextfree
decl_stmt|;
comment|/* next-unallocated inode */
name|time_t
name|st_atime
decl_stmt|;
comment|/* access time */
block|}
name|__ifile_u
union|;
define|#
directive|define
name|if_st_atime
value|__ifile_u.st_atime
define|#
directive|define
name|if_nextfree
value|__ifile_u.nextfree
block|}
name|IFILE
typedef|;
end_typedef

begin_comment
comment|/* Segment table size, in blocks. */
end_comment

begin_define
define|#
directive|define
name|SEGTABSIZE
parameter_list|(
name|fs
parameter_list|)
define|\
value|(((fs)->fs_nseg * sizeof(SEGUSAGE) + \ 	    ((fs)->fs_bsize - 1))<< (fs)->fs_bshift)
end_define

begin_define
define|#
directive|define
name|SEGTABSIZE_SU
parameter_list|(
name|fs
parameter_list|)
define|\
value|(((fs)->lfs_nseg * sizeof(SEGUSAGE) + \ 	    ((fs)->lfs_bsize - 1))>> (fs)->lfs_bshift)
end_define

begin_comment
comment|/* In-memory and on-disk checkpoint segment usage structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|segusage
block|{
name|u_long
name|su_nbytes
decl_stmt|;
comment|/* number of live bytes */
name|u_long
name|su_lastmod
decl_stmt|;
comment|/* last modified timestamp */
define|#
directive|define
name|SEGUSAGE_DIRTY
value|0x1
name|u_long
name|su_flags
decl_stmt|;
block|}
name|SEGUSAGE
typedef|;
end_typedef

begin_comment
comment|/*  * All summary blocks are the same size, so we can always read a summary  * block easily from a segment  */
end_comment

begin_define
define|#
directive|define
name|LFS_SUMMARY_SIZE
value|512
end_define

begin_comment
comment|/* On-disk segment summary information */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|segsum
block|{
name|daddr_t
name|ss_next
decl_stmt|;
comment|/* next segment */
name|daddr_t
name|ss_prev
decl_stmt|;
comment|/* next segment */
name|daddr_t
name|ss_nextsum
decl_stmt|;
comment|/* next summary block */
name|u_long
name|ss_create
decl_stmt|;
comment|/* creation time stamp */
name|u_long
name|ss_nfinfo
decl_stmt|;
comment|/* number of file info structures */
name|u_long
name|ss_niinfo
decl_stmt|;
comment|/* number of inode info structures */
name|u_long
name|ss_cksum
decl_stmt|;
comment|/* check sum */
block|}
name|SEGSUM
typedef|;
end_typedef

begin_comment
comment|/* On-disk file information.  One per file with data blocks in the segment. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|finfo
block|{
name|u_long
name|fi_nblocks
decl_stmt|;
comment|/* number of blocks */
name|u_long
name|fi_version
decl_stmt|;
comment|/* version number */
name|ino_t
name|fi_ino
decl_stmt|;
comment|/* inode number */
name|u_long
name|fi_blocks
index|[
literal|1
index|]
decl_stmt|;
comment|/* array of logical block numbers */
block|}
name|FINFO
typedef|;
end_typedef

begin_comment
comment|/* On-disk inode information.  One per block of inodes in the segment. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|iinfo
block|{
name|u_long
name|ii_ninodes
decl_stmt|;
comment|/* number of inodes */
name|ino_t
name|ii_inodes
decl_stmt|;
comment|/* array of inode numbers */
block|}
name|IINFO
typedef|;
end_typedef

end_unit

