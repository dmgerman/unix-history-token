begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)lfs.h	5.5 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|buf
name|BUF
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dinode
name|DINODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|inode
name|INODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mount
name|MOUNT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ucred
name|UCRED
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ufsmount
name|UFSMOUNT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|vnode
name|VNODE
typedef|;
end_typedef

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

begin_comment
comment|/* On-disk and in-memory checkpoint segment usage structure. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|segusage
name|SEGUSE
typedef|;
end_typedef

begin_struct
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
name|SEGUSE_DIRTY
value|0x1
comment|/* XXX fill in comment */
name|u_long
name|su_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* On-disk file information.  One per file with data blocks in the segment. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|finfo
name|FINFO
typedef|;
end_typedef

begin_struct
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
name|u_long
name|fi_ino
decl_stmt|;
comment|/* inode number */
name|long
name|fi_blocks
index|[
literal|1
index|]
decl_stmt|;
comment|/* array of logical block numbers */
block|}
struct|;
end_struct

begin_comment
comment|/* In-memory description of a segment about to be written */
end_comment

begin_typedef
typedef|typedef
name|struct
name|segment
name|SEGMENT
typedef|;
end_typedef

begin_struct
struct|struct
name|segment
block|{
name|SEGMENT
modifier|*
name|nextp
decl_stmt|;
comment|/* Links segments together */
name|BUF
modifier|*
modifier|*
name|bpp
decl_stmt|;
comment|/* Pointer to buffer array */
name|BUF
modifier|*
modifier|*
name|cbpp
decl_stmt|;
comment|/* Pointer to next available bp */
name|BUF
modifier|*
name|ibp
decl_stmt|;
comment|/* Buffer pointer to inode page */
name|BUF
modifier|*
name|sbp
decl_stmt|;
comment|/* Segment summary buffer pointer */
name|void
modifier|*
name|segsum
decl_stmt|;
comment|/* Segment Summary info */
name|u_long
name|sum_bytes_left
decl_stmt|;
comment|/* Bytes left in summary */
name|u_long
name|seg_bytes_left
decl_stmt|;
comment|/* Bytes left in segment */
name|daddr_t
name|saddr
decl_stmt|;
comment|/* Current disk address */
name|daddr_t
name|sum_addr
decl_stmt|;
comment|/* Address of current summary */
name|u_long
name|ninodes
decl_stmt|;
comment|/* Number of inodes in this segment */
name|u_long
name|sum_num
decl_stmt|;
comment|/* Number of current summary block */
name|u_long
name|seg_number
decl_stmt|;
comment|/* Number of this segment */
name|FINFO
modifier|*
name|fip
decl_stmt|;
comment|/* Current fileinfo pointer */
block|}
struct|;
end_struct

begin_comment
comment|/* On-disk and in-memory super block. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|lfs
name|LFS
typedef|;
end_typedef

begin_struct
struct|struct
name|lfs
block|{
define|#
directive|define
name|LFS_MAGIC
value|0xbedead
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
comment|/* Checkpoint region. */
name|ino_t
name|lfs_free
decl_stmt|;
comment|/* start of the free list */
name|u_long
name|lfs_bfree
decl_stmt|;
comment|/* number of free blocks */
name|u_long
name|lfs_nfiles
decl_stmt|;
comment|/* number of allocated inodes */
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
name|daddr_t
name|lfs_nextseg
decl_stmt|;
comment|/* next segment to write */
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
name|LFS_MIN_SBINTERVAL
value|5
comment|/* minimum superblock segment spacing */
define|#
directive|define
name|LFS_MAXNUMSB
value|10
comment|/* superblock disk offsets */
name|daddr_t
name|lfs_sboffs
index|[
name|LFS_MAXNUMSB
index|]
decl_stmt|;
comment|/* These fields are set at mount time and are meaningless on disk. */
name|VNODE
modifier|*
name|lfs_ivnode
decl_stmt|;
comment|/* vnode for the ifile */
name|SEGUSE
modifier|*
name|lfs_segtab
decl_stmt|;
comment|/* in-memory segment usage table */
name|SEGMENT
modifier|*
name|lfs_seglist
decl_stmt|;
comment|/* list of segments being written */
name|u_long
name|lfs_iocount
decl_stmt|;
comment|/* Number of ios pending */
name|u_char
name|lfs_fmod
decl_stmt|;
comment|/* super block modified flag */
name|u_char
name|lfs_clean
decl_stmt|;
comment|/* file system is clean flag */
name|u_char
name|lfs_ronly
decl_stmt|;
comment|/* mounted read-only flag */
name|u_char
name|lfs_flags
decl_stmt|;
comment|/* currently unused flag */
name|u_char
name|lfs_fsmnt
index|[
name|MAXMNTLEN
index|]
decl_stmt|;
comment|/* name mounted on */
name|u_char
name|pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* long-align */
comment|/* Checksum; valid on disk. */
name|u_long
name|lfs_cksum
decl_stmt|;
comment|/* checksum for superblock checking */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The root inode is the root of the file system.  Inode 0 is the out-of-band  * inode, and inode 1 is the inode number for the ifile.  Thus the root inode  * is 2.  */
end_comment

begin_define
define|#
directive|define
name|ROOTINO
value|((ino_t)2)
end_define

begin_define
define|#
directive|define
name|LOSTFOUNDINO
value|((ino_t)3)
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

begin_comment
comment|/* First free inode number. */
end_comment

begin_define
define|#
directive|define
name|LFS_FIRST_INUM
value|(LOSTFOUNDINO + 1)
end_define

begin_comment
comment|/*  * Used to access the first spare of the dinode which we use to store  * the ifile number so we can identify them  */
end_comment

begin_define
define|#
directive|define
name|di_inum
value|di_spare[0]
end_define

begin_comment
comment|/*  * Logical block numbers of indirect blocks.  */
end_comment

begin_define
define|#
directive|define
name|S_INDIR
value|-1
end_define

begin_define
define|#
directive|define
name|D_INDIR
value|-2
end_define

begin_define
define|#
directive|define
name|T_INDIR
value|-3
end_define

begin_typedef
typedef|typedef
name|struct
name|ifile
name|IFILE
typedef|;
end_typedef

begin_struct
struct|struct
name|ifile
block|{
name|u_long
name|if_version
decl_stmt|;
comment|/* inode version number */
define|#
directive|define
name|LFS_UNUSED_DADDR
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
struct|;
end_struct

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
value|(((fs)->fs_nseg * sizeof(SEGUSE) + \ 	    ((fs)->fs_bsize - 1))>> (fs)->fs_bshift)
end_define

begin_define
define|#
directive|define
name|SEGTABSIZE_SU
parameter_list|(
name|fs
parameter_list|)
define|\
value|(((fs)->lfs_nseg * sizeof(SEGUSE) + \ 	    ((fs)->lfs_bsize - 1))>> (fs)->lfs_bshift)
end_define

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
name|struct
name|segsum
name|SEGSUM
typedef|;
end_typedef

begin_struct
struct|struct
name|segsum
block|{
name|u_long
name|ss_cksum
decl_stmt|;
comment|/* check sum */
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
name|ss_ninos
decl_stmt|;
comment|/* number of inode blocks */
comment|/* FINFO's... */
block|}
struct|;
end_struct

begin_comment
comment|/* NINDIR is the number of indirects in a file system block. */
end_comment

begin_define
define|#
directive|define
name|NINDIR
parameter_list|(
name|fs
parameter_list|)
value|((fs)->lfs_nindir)
end_define

begin_comment
comment|/* INOPB is the number of inodes in a secondary storage block. */
end_comment

begin_define
define|#
directive|define
name|INOPB
parameter_list|(
name|fs
parameter_list|)
value|((fs)->lfs_inopb)
end_define

begin_comment
comment|/* IFPB -- IFILE's per block */
end_comment

begin_define
define|#
directive|define
name|IFPB
parameter_list|(
name|fs
parameter_list|)
value|((fs)->lfs_ifpb)
end_define

begin_define
define|#
directive|define
name|blksize
parameter_list|(
name|fs
parameter_list|)
value|((fs)->lfs_bsize)
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
value|((loc)& (fs)->lfs_bmask)
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
value|((b)<< (fs)->lfs_fsbtodb)
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
value|((loc)>> (fs)->lfs_bshift)
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
value|((blk)<< (fs)->lfs_bshift)
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
value|((loc)>> (fs)->lfs_bshift)
end_define

begin_define
define|#
directive|define
name|satosn
parameter_list|(
name|fs
parameter_list|,
name|saddr
parameter_list|)
define|\
value|((int)((saddr - fs->lfs_sboffs[0]) / fsbtodb(fs, fs->lfs_ssize)))
end_define

begin_define
define|#
directive|define
name|sntosa
parameter_list|(
name|fs
parameter_list|,
name|sn
parameter_list|)
define|\
value|((daddr_t)(sn * (fs->lfs_ssize<< fs->lfs_fsbtodb) + fs->lfs_sboffs[0]))
end_define

end_unit

