begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  modified for EXT2FS support in Lites 1.1  *  *  Aug 1995, Godmar Back (gback@cs.utah.edu)  *  University of Utah, Department of Computer Science  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fs.h	8.7 (Berkeley) 4/19/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Each disk drive contains some number of file systems.  * A file system consists of a number of cylinder groups.  * Each cylinder group has inodes and data.  *  * A file system is described by its super-block, which in turn  * describes the cylinder groups.  The super-block is critical  * data and is replicated in each cylinder group to protect against  * catastrophic loss.  This is done at `newfs' time and the critical  * super-block data does not change, so the copies need not be  * referenced further unless disaster strikes.  *  * The first boot and super blocks are given in absolute disk addresses.  * The byte-offset forms are preferred, as they don't imply a sector size.  */
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
value|1024
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
name|SBOFF
value|((off_t)(BBOFF + BBSIZE))
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
comment|/*  * The path name on which the file system is mounted is maintained  * in fs_fsmnt. MAXMNTLEN defines the amount of space allocated in   * the super block for this name.  */
end_comment

begin_define
define|#
directive|define
name|MAXMNTLEN
value|512
end_define

begin_comment
comment|/*  * Macros for access to superblock array structures  */
end_comment

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
name|cgindx
parameter_list|)
value|(((struct ext2_group_desc *) \         (fs->s_group_desc[cgindx / EXT2_DESC_PER_BLOCK(fs)]->b_data)) \ 		[cgindx % EXT2_DESC_PER_BLOCK(fs)])
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
value|((b)<< ((fs)->s_fsbtodb))
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
value|((b)>> ((fs)->s_fsbtodb))
end_define

begin_comment
comment|/* get group containing inode */
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
value|(((x) - 1) / EXT2_INODES_PER_GROUP(fs))
end_define

begin_comment
comment|/* get block containing inode from its number x */
end_comment

begin_define
define|#
directive|define
name|ino_to_fsba
parameter_list|(
name|fs
parameter_list|,
name|x
parameter_list|)
value|fs_cs(fs, ino_to_cg(fs, x)).bg_inode_table + \ 	(((x)-1) % EXT2_INODES_PER_GROUP(fs))/EXT2_INODES_PER_BLOCK(fs)
end_define

begin_comment
comment|/* get offset for inode in block */
end_comment

begin_define
define|#
directive|define
name|ino_to_fsbo
parameter_list|(
name|fs
parameter_list|,
name|x
parameter_list|)
value|((x-1) % EXT2_INODES_PER_BLOCK(fs))
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
value|(((d) - fs->s_es->s_first_data_block) / \ 			EXT2_BLOCKS_PER_GROUP(fs))
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
value|(((d) - fs->s_es->s_first_data_block) % \ 			EXT2_BLOCKS_PER_GROUP(fs))
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
value|((loc)& (fs)->s_qbmask)
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
comment|/* calculates (blk * fs->fs_bsize) */
define|\
value|((blk)<< (fs->s_bshift))
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
value|((loc)>> (fs->s_bshift))
end_define

begin_comment
comment|/* no fragments -> logical block number equal # of frags */
end_comment

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
value|((loc)>> (fs->s_bshift))
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
value|roundup(size, fs->s_frag_size)
end_define

begin_comment
comment|/* was (((size) + (fs)->fs_qfmask)& (fs)->fs_fmask) */
end_comment

begin_comment
comment|/*  * Determining the size of a file block in the file system.  * easy w/o fragments  */
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
value|((fs)->s_frag_size)
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
value|EXT2_INODES_PER_BLOCK(fs)
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
value|(EXT2_ADDR_PER_BLOCK(fs))
end_define

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
comment|/* a few remarks about superblock locking/unlocking  * Linux provides special routines for doing so  * I haven't figured out yet what BSD does  * I think I'll try a VOP_LOCK/VOP_UNLOCK on the device vnode  */
end_comment

begin_define
define|#
directive|define
name|DEVVP
parameter_list|(
name|inode
parameter_list|)
value|(VFSTOUFS(ITOV(inode)->v_mount)->um_devvp)
end_define

begin_define
define|#
directive|define
name|lock_super
parameter_list|(
name|devvp
parameter_list|)
value|vn_lock(devvp, LK_EXCLUSIVE | LK_RETRY, curproc)
end_define

begin_define
define|#
directive|define
name|unlock_super
parameter_list|(
name|devvp
parameter_list|)
value|VOP_UNLOCK(devvp, 0, curproc)
end_define

begin_comment
comment|/*  * To lock a buffer, set the B_LOCKED flag and then brelse() it. To unlock,  * reset the B_LOCKED flag and brelse() the buffer back on the LRU list  */
end_comment

begin_define
define|#
directive|define
name|LCK_BUF
parameter_list|(
name|bp
parameter_list|)
value|{ \ 	int s; \ 	s = splbio(); \ 	(bp)->b_flags |= B_LOCKED; \ 	splx(s); \ 	brelse(bp); \ }
end_define

begin_define
define|#
directive|define
name|ULCK_BUF
parameter_list|(
name|bp
parameter_list|)
value|{ \ 	long flags; \ 	int s; \ 	s = splbio(); \ 	flags = (bp)->b_flags; \ 	(bp)->b_flags&= ~(B_DIRTY | B_LOCKED); \ 	BUF_LOCK(bp, LK_EXCLUSIVE); \ 	bremfree(bp); \ 	splx(s); \ 	if (flags& B_DIRTY) \ 		bwrite(bp); \ 	else \ 		brelse(bp); \ }
end_define

end_unit

