begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)lfs.h	8.3 (Berkeley) 9/23/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_LFS_LFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_LFS_LFS_H_
end_define

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

begin_comment
comment|/*  * XXX  * This is a kluge and NEEDS to go away.  *  * Right now, ufs code handles most of the calls for directory operations  * such as create, mkdir, link, etc.  As a result VOP_UPDATE is being  * called with waitfor set (since ffs does these things synchronously).  * Since LFS does not want to do these synchronously, we treat the last  * argument to lfs_update as a set of flags.  If LFS_SYNC is set, then  * the update should be synchronous, if not, do it asynchronously.  * Unfortunately, this means that LFS won't work with NFS yet because  * NFS goes through paths that will make normal calls to ufs which will  * call lfs with a last argument of 1.  */
end_comment

begin_define
define|#
directive|define
name|LFS_SYNC
value|0x02
end_define

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
comment|/* SEGUSE last modified timestamp */
name|u_short
name|su_nsums
decl_stmt|;
comment|/* number of summaries in segment */
name|u_short
name|su_ninos
decl_stmt|;
comment|/* number of inode blocks in seg */
define|#
directive|define
name|SEGUSE_ACTIVE
value|0x1
comment|/* segment is currently being written */
define|#
directive|define
name|SEGUSE_DIRTY
value|0x2
comment|/* segment has data in it */
define|#
directive|define
name|SEGUSE_SUPERBLOCK
value|0x4
comment|/* segment contains a superblock */
name|u_long
name|su_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SEGUPB
parameter_list|(
name|fs
parameter_list|)
value|(1<< (fs)->lfs_sushift)
end_define

begin_define
define|#
directive|define
name|SEGTABSIZE_SU
parameter_list|(
name|fs
parameter_list|)
define|\
value|(((fs)->lfs_nseg + SEGUPB(fs) - 1)>> (fs)->lfs_sushift)
end_define

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
comment|/* On-disk and in-memory super block. */
end_comment

begin_struct
struct|struct
name|lfs
block|{
define|#
directive|define
name|LFS_MAGIC
value|0x070162
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
comment|/* number of disk blocks in fs */
name|u_long
name|lfs_bsize
decl_stmt|;
comment|/* file system block size */
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
comment|/* number of free disk blocks */
name|u_long
name|lfs_nfiles
decl_stmt|;
comment|/* number of allocated inodes */
name|long
name|lfs_avail
decl_stmt|;
comment|/* blocks available for writing */
name|u_long
name|lfs_uinodes
decl_stmt|;
comment|/* inodes in cache not yet on disk */
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
comment|/* address of last segment written */
name|daddr_t
name|lfs_nextseg
decl_stmt|;
comment|/* address of next segment to write */
name|daddr_t
name|lfs_curseg
decl_stmt|;
comment|/* current segment being written */
name|daddr_t
name|lfs_offset
decl_stmt|;
comment|/* offset in curseg for next partial */
name|daddr_t
name|lfs_lastpseg
decl_stmt|;
comment|/* address of last partial written */
name|u_long
name|lfs_tstamp
decl_stmt|;
comment|/* time stamp */
name|long
name|lfs_maxsymlinklen
decl_stmt|;
comment|/* max length of an internal symlink */
comment|/* These are configuration parameters. */
name|u_long
name|lfs_minfree
decl_stmt|;
comment|/* minimum percentage of free blocks */
comment|/* These fields can be computed from the others. */
name|u_quad_t
name|lfs_maxfilesize
decl_stmt|;
comment|/* maximum representable file size */
name|u_long
name|lfs_dbpseg
decl_stmt|;
comment|/* disk blocks per segment */
name|u_long
name|lfs_inopb
decl_stmt|;
comment|/* inodes per block */
name|u_long
name|lfs_ifpb
decl_stmt|;
comment|/* IFILE entries per block */
name|u_long
name|lfs_sepb
decl_stmt|;
comment|/* SEGUSE entries per block */
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
name|lfs_cleansz
decl_stmt|;
comment|/* cleaner info size in blocks */
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
name|u_long
name|lfs_sushift
decl_stmt|;
comment|/* fast mult/div for segusage table */
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
name|struct
name|segment
modifier|*
name|lfs_sp
decl_stmt|;
comment|/* current segment being written */
name|struct
name|vnode
modifier|*
name|lfs_ivnode
decl_stmt|;
comment|/* vnode for the ifile */
name|u_long
name|lfs_seglock
decl_stmt|;
comment|/* single-thread the segment writer */
name|pid_t
name|lfs_lockpid
decl_stmt|;
comment|/* pid of lock holder */
name|u_long
name|lfs_iocount
decl_stmt|;
comment|/* number of ios pending */
name|u_long
name|lfs_writer
decl_stmt|;
comment|/* don't allow any dirops to start */
name|u_long
name|lfs_dirops
decl_stmt|;
comment|/* count of active directory ops */
name|u_long
name|lfs_doifile
decl_stmt|;
comment|/* Write ifile blocks on next write */
name|u_long
name|lfs_nactive
decl_stmt|;
comment|/* Number of segments since last ckp */
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
name|MNAMELEN
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
name|u_char
name|pad2
index|[
literal|156
index|]
decl_stmt|;
comment|/* Block align */
comment|/* Checksum; valid on disk. */
name|u_long
name|lfs_cksum
decl_stmt|;
comment|/* checksum for superblock checking */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Inode 0 is the out-of-band inode number, inode 1 is the inode number for  * the IFILE, the root inode is 2 and the lost+found inode is 3.  */
end_comment

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
comment|/* out of band inode number */
end_comment

begin_define
define|#
directive|define
name|LFS_IFILE_INUM
value|1
end_define

begin_comment
comment|/* IFILE inode number */
end_comment

begin_define
define|#
directive|define
name|LOSTFOUNDINO
value|3
end_define

begin_comment
comment|/* lost+found inode number */
end_comment

begin_define
define|#
directive|define
name|LFS_FIRST_INUM
value|4
end_define

begin_comment
comment|/* first free inode number */
end_comment

begin_comment
comment|/* Address calculations for metadata located in the inode */
end_comment

begin_define
define|#
directive|define
name|S_INDIR
parameter_list|(
name|fs
parameter_list|)
value|-NDADDR
end_define

begin_define
define|#
directive|define
name|D_INDIR
parameter_list|(
name|fs
parameter_list|)
value|(S_INDIR(fs) - NINDIR(fs) - 1)
end_define

begin_define
define|#
directive|define
name|T_INDIR
parameter_list|(
name|fs
parameter_list|)
value|(D_INDIR(fs) - NINDIR(fs) * NINDIR(fs) - 1)
end_define

begin_comment
comment|/* Unassigned disk address. */
end_comment

begin_define
define|#
directive|define
name|UNASSIGNED
value|-1
end_define

begin_comment
comment|/* Unused logical block number */
end_comment

begin_define
define|#
directive|define
name|LFS_UNUSED_LBN
value|-1
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
name|ino_t
name|if_nextfree
decl_stmt|;
comment|/* next-unallocated inode */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Cleaner information structure.  This resides in the ifile and is used  * to pass information between the cleaner and the kernel.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cleanerinfo
block|{
name|u_long
name|clean
decl_stmt|;
comment|/* K: number of clean segments */
name|u_long
name|dirty
decl_stmt|;
comment|/* K: number of dirty segments */
block|}
name|CLEANERINFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CLEANSIZE_SU
parameter_list|(
name|fs
parameter_list|)
define|\
value|((sizeof(CLEANERINFO) + (fs)->lfs_bsize - 1)>> (fs)->lfs_bshift)
end_define

begin_comment
comment|/*  * All summary blocks are the same size, so we can always read a summary  * block easily from a segment.  */
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
name|ss_sumsum
decl_stmt|;
comment|/* check sum of summary block */
name|u_long
name|ss_datasum
decl_stmt|;
comment|/* check sum of data */
name|daddr_t
name|ss_next
decl_stmt|;
comment|/* next segment */
name|u_long
name|ss_create
decl_stmt|;
comment|/* creation time stamp */
name|u_short
name|ss_nfinfo
decl_stmt|;
comment|/* number of file info structures */
name|u_short
name|ss_ninos
decl_stmt|;
comment|/* number of inodes in summary */
define|#
directive|define
name|SS_DIROP
value|0x01
comment|/* segment begins a dirop */
define|#
directive|define
name|SS_CONT
value|0x02
comment|/* more partials to finish this write*/
name|u_short
name|ss_flags
decl_stmt|;
comment|/* used for directory operations */
name|u_short
name|ss_pad
decl_stmt|;
comment|/* extra space */
comment|/* FINFO's and inode daddr's... */
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
name|dbtofsb
parameter_list|(
name|fs
parameter_list|,
name|b
parameter_list|)
value|((b)>> (fs)->lfs_fsbtodb)
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
name|datosn
parameter_list|(
name|fs
parameter_list|,
name|daddr
parameter_list|)
comment|/* disk address to segment number */
define|\
value|(((daddr) - (fs)->lfs_sboffs[0]) / fsbtodb((fs), (fs)->lfs_ssize))
end_define

begin_define
define|#
directive|define
name|sntoda
parameter_list|(
name|fs
parameter_list|,
name|sn
parameter_list|)
comment|/* segment number to disk address */
define|\
value|((daddr_t)((sn) * ((fs)->lfs_ssize<< (fs)->lfs_fsbtodb) +	\ 	    (fs)->lfs_sboffs[0]))
end_define

begin_comment
comment|/* Read in the block with the cleaner info from the ifile. */
end_comment

begin_define
define|#
directive|define
name|LFS_CLEANERINFO
parameter_list|(
name|CP
parameter_list|,
name|F
parameter_list|,
name|BP
parameter_list|)
value|{					\ 	VTOI((F)->lfs_ivnode)->i_flag |= IN_ACCESS;			\ 	if (bread((F)->lfs_ivnode,					\ 	    (daddr_t)0, (F)->lfs_bsize, NOCRED,&(BP)))			\ 		panic("lfs: ifile read");				\ 	(CP) = (CLEANERINFO *)(BP)->b_data;				\ }
end_define

begin_comment
comment|/* Read in the block with a specific inode from the ifile. */
end_comment

begin_define
define|#
directive|define
name|LFS_IENTRY
parameter_list|(
name|IP
parameter_list|,
name|F
parameter_list|,
name|IN
parameter_list|,
name|BP
parameter_list|)
value|{					\ 	int _e;								\ 	VTOI((F)->lfs_ivnode)->i_flag |= IN_ACCESS;			\ 	if (_e = bread((F)->lfs_ivnode,					\ 	    (IN) / (F)->lfs_ifpb + (F)->lfs_cleansz + (F)->lfs_segtabsz,\ 	    (F)->lfs_bsize, NOCRED,&(BP)))				\ 		panic("lfs: ifile read %d", _e);			\ 	(IP) = (IFILE *)(BP)->b_data + (IN) % (F)->lfs_ifpb;		\ }
end_define

begin_comment
comment|/* Read in the block with a specific segment usage entry from the ifile. */
end_comment

begin_define
define|#
directive|define
name|LFS_SEGENTRY
parameter_list|(
name|SP
parameter_list|,
name|F
parameter_list|,
name|IN
parameter_list|,
name|BP
parameter_list|)
value|{					\ 	int _e;								\ 	VTOI((F)->lfs_ivnode)->i_flag |= IN_ACCESS;			\ 	_e = bread((F)->lfs_ivnode,					\ 	    ((IN)>> (F)->lfs_sushift) + (F)->lfs_cleansz,		\ 	    (F)->lfs_bsize, NOCRED,&(BP));				\ 	if (_e)								\ 		panic("lfs: ifile read: %d", _e);			\ 	(SP) = (SEGUSE *)(BP)->b_data + ((IN)& (F)->lfs_sepb - 1);	\ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CC_WALL
end_ifdef

begin_comment
comment|/* The above                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^  * looks like a potential bug to me.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Determine if there is enough room currently available to write db  * disk blocks.  We need enough blocks for the new blocks, the current,  * inode blocks, a summary block, plus potentially the ifile inode and  * the segment usage table, plus an ifile page.  */
end_comment

begin_define
define|#
directive|define
name|LFS_FITS
parameter_list|(
name|fs
parameter_list|,
name|db
parameter_list|)
define|\
value|((long)((db + ((fs)->lfs_uinodes + INOPB((fs))) / INOPB((fs)) +	\ 	fsbtodb(fs, 1) + LFS_SUMMARY_SIZE / DEV_BSIZE +			\ 	(fs)->lfs_segtabsz))< (fs)->lfs_avail)
end_define

begin_comment
comment|/* Determine if a buffer belongs to the ifile */
end_comment

begin_define
define|#
directive|define
name|IS_IFILE
parameter_list|(
name|bp
parameter_list|)
value|(VTOI(bp->b_vp)->i_number == LFS_IFILE_INUM)
end_define

begin_comment
comment|/*  * Structures used by lfs_bmapv and lfs_markv to communicate information  * about inodes and data blocks.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|block_info
block|{
name|ino_t
name|bi_inode
decl_stmt|;
comment|/* inode # */
name|daddr_t
name|bi_lbn
decl_stmt|;
comment|/* logical block w/in file */
name|daddr_t
name|bi_daddr
decl_stmt|;
comment|/* disk address of block */
name|time_t
name|bi_segcreate
decl_stmt|;
comment|/* origin segment create time */
name|int
name|bi_version
decl_stmt|;
comment|/* file version number */
name|void
modifier|*
name|bi_bp
decl_stmt|;
comment|/* data buffer */
block|}
name|BLOCK_INFO
typedef|;
end_typedef

begin_comment
comment|/* In-memory description of a segment about to be written. */
end_comment

begin_struct
struct|struct
name|segment
block|{
name|struct
name|lfs
modifier|*
name|fs
decl_stmt|;
comment|/* file system pointer */
name|struct
name|buf
modifier|*
modifier|*
name|bpp
decl_stmt|;
comment|/* pointer to buffer array */
name|struct
name|buf
modifier|*
modifier|*
name|cbpp
decl_stmt|;
comment|/* pointer to next available bp */
name|struct
name|buf
modifier|*
modifier|*
name|start_bpp
decl_stmt|;
comment|/* pointer to first bp in this set */
name|struct
name|buf
modifier|*
name|ibp
decl_stmt|;
comment|/* buffer pointer to inode page */
name|struct
name|finfo
modifier|*
name|fip
decl_stmt|;
comment|/* current fileinfo pointer */
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
comment|/* vnode being gathered */
name|void
modifier|*
name|segsum
decl_stmt|;
comment|/* segment summary info */
name|u_long
name|ninodes
decl_stmt|;
comment|/* number of inodes in this segment */
name|u_long
name|seg_bytes_left
decl_stmt|;
comment|/* bytes left in segment */
name|u_long
name|sum_bytes_left
decl_stmt|;
comment|/* bytes left in summary block */
name|u_long
name|seg_number
decl_stmt|;
comment|/* number of this segment */
name|daddr_t
modifier|*
name|start_lbp
decl_stmt|;
comment|/* beginning lbn for this set */
define|#
directive|define
name|SEGM_CKP
value|0x01
comment|/* doing a checkpoint */
define|#
directive|define
name|SEGM_CLEAN
value|0x02
comment|/* cleaner call; don't sort */
define|#
directive|define
name|SEGM_SYNC
value|0x04
comment|/* wait for segment */
name|u_long
name|seg_flags
decl_stmt|;
comment|/* run-time flags for this segment */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|F
parameter_list|,
name|BB
parameter_list|,
name|C
parameter_list|)
define|\
value|(((C)->cr_uid == 0&& (F)->lfs_bfree>= (BB)) ||		\ 	((C)->cr_uid != 0&& IS_FREESPACE(F, BB)))
end_define

begin_define
define|#
directive|define
name|IS_FREESPACE
parameter_list|(
name|F
parameter_list|,
name|BB
parameter_list|)
define|\
value|((F)->lfs_bfree> ((F)->lfs_dsize * (F)->lfs_minfree / 100 + (BB)))
end_define

begin_define
define|#
directive|define
name|ISSPACE_XXX
parameter_list|(
name|F
parameter_list|,
name|BB
parameter_list|)
define|\
value|((F)->lfs_bfree>= (BB))
end_define

begin_define
define|#
directive|define
name|DOSTATS
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DOSTATS
end_ifdef

begin_comment
comment|/* Statistics Counters */
end_comment

begin_struct
struct|struct
name|lfs_stats
block|{
name|int
name|segsused
decl_stmt|;
name|int
name|psegwrites
decl_stmt|;
name|int
name|psyncwrites
decl_stmt|;
name|int
name|pcleanwrites
decl_stmt|;
name|int
name|blocktot
decl_stmt|;
name|int
name|cleanblocks
decl_stmt|;
name|int
name|ncheckpoints
decl_stmt|;
name|int
name|nwrites
decl_stmt|;
name|int
name|nsync_writes
decl_stmt|;
name|int
name|wait_exceeded
decl_stmt|;
name|int
name|write_exceeded
decl_stmt|;
name|int
name|flush_invoked
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|lfs_stats
name|lfs_stats
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

