begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fsck.h	8.4 (Berkeley) 5/9/95  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|MAXDUP
value|10
end_define

begin_comment
comment|/* limit on dup blks (per inode) */
end_comment

begin_define
define|#
directive|define
name|MAXBAD
value|10
end_define

begin_comment
comment|/* limit on bad blks (per inode) */
end_comment

begin_define
define|#
directive|define
name|MAXBUFSPACE
value|40*1024
end_define

begin_comment
comment|/* maximum space to allocate to buffers */
end_comment

begin_define
define|#
directive|define
name|INOBUFSIZE
value|56*1024
end_define

begin_comment
comment|/* size of buffer to read inodes in pass1 */
end_comment

begin_comment
comment|/*  * Each inode on the filesystem is described by the following structure.  * The linkcnt is initially set to the value in the inode. Each time it  * is found during the descent in passes 2, 3, and 4 the count is  * decremented. Any inodes whose count is non-zero after pass 4 needs to  * have its link count adjusted by the value remaining in ino_linkcnt.  */
end_comment

begin_struct
struct|struct
name|inostat
block|{
name|char
name|ino_state
decl_stmt|;
comment|/* state of inode, see below */
name|char
name|ino_type
decl_stmt|;
comment|/* type of inode */
name|short
name|ino_linkcnt
decl_stmt|;
comment|/* number of links not found */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Inode states.  */
end_comment

begin_define
define|#
directive|define
name|USTATE
value|01
end_define

begin_comment
comment|/* inode not allocated */
end_comment

begin_define
define|#
directive|define
name|FSTATE
value|02
end_define

begin_comment
comment|/* inode is file */
end_comment

begin_define
define|#
directive|define
name|DSTATE
value|03
end_define

begin_comment
comment|/* inode is directory */
end_comment

begin_define
define|#
directive|define
name|DFOUND
value|04
end_define

begin_comment
comment|/* directory found during descent */
end_comment

begin_define
define|#
directive|define
name|DCLEAR
value|05
end_define

begin_comment
comment|/* directory is to be cleared */
end_comment

begin_define
define|#
directive|define
name|FCLEAR
value|06
end_define

begin_comment
comment|/* file is to be cleared */
end_comment

begin_comment
comment|/*  * Inode state information is contained on per cylinder group lists  * which are described by the following structure.  */
end_comment

begin_struct
struct|struct
name|inostatlist
block|{
name|long
name|il_numalloced
decl_stmt|;
comment|/* number of inodes allocated in this cg */
name|struct
name|inostat
modifier|*
name|il_stat
decl_stmt|;
comment|/* inostat info for this cylinder group */
block|}
modifier|*
name|inostathead
struct|;
end_struct

begin_comment
comment|/*  * buffer cache structure.  */
end_comment

begin_struct
struct|struct
name|bufarea
block|{
name|struct
name|bufarea
modifier|*
name|b_next
decl_stmt|;
comment|/* free list queue */
name|struct
name|bufarea
modifier|*
name|b_prev
decl_stmt|;
comment|/* free list queue */
name|ufs_daddr_t
name|b_bno
decl_stmt|;
name|int
name|b_size
decl_stmt|;
name|int
name|b_errs
decl_stmt|;
name|int
name|b_flags
decl_stmt|;
union|union
block|{
name|char
modifier|*
name|b_buf
decl_stmt|;
comment|/* buffer space */
name|ufs_daddr_t
modifier|*
name|b_indir
decl_stmt|;
comment|/* indirect block */
name|struct
name|fs
modifier|*
name|b_fs
decl_stmt|;
comment|/* super block */
name|struct
name|cg
modifier|*
name|b_cg
decl_stmt|;
comment|/* cylinder group */
name|struct
name|dinode
modifier|*
name|b_dinode
decl_stmt|;
comment|/* inode block */
block|}
name|b_un
union|;
name|char
name|b_dirty
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|B_INUSE
value|1
end_define

begin_define
define|#
directive|define
name|MINBUFS
value|5
end_define

begin_comment
comment|/* minimum number of buffers required */
end_comment

begin_decl_stmt
name|struct
name|bufarea
name|bufhead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of list of other blks in filesys */
end_comment

begin_decl_stmt
name|struct
name|bufarea
name|sblk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file system superblock */
end_comment

begin_decl_stmt
name|struct
name|bufarea
name|cgblk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cylinder group blocks */
end_comment

begin_decl_stmt
name|struct
name|bufarea
modifier|*
name|pdirbp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current directory contents */
end_comment

begin_decl_stmt
name|struct
name|bufarea
modifier|*
name|pbp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current inode block */
end_comment

begin_define
define|#
directive|define
name|dirty
parameter_list|(
name|bp
parameter_list|)
value|(bp)->b_dirty = 1
end_define

begin_define
define|#
directive|define
name|initbarea
parameter_list|(
name|bp
parameter_list|)
define|\
value|(bp)->b_dirty = 0; \ 	(bp)->b_bno = (ufs_daddr_t)-1; \ 	(bp)->b_flags = 0;
end_define

begin_define
define|#
directive|define
name|sbdirty
parameter_list|()
value|sblk.b_dirty = 1
end_define

begin_define
define|#
directive|define
name|cgdirty
parameter_list|()
value|cgblk.b_dirty = 1
end_define

begin_define
define|#
directive|define
name|sblock
value|(*sblk.b_un.b_fs)
end_define

begin_define
define|#
directive|define
name|cgrp
value|(*cgblk.b_un.b_cg)
end_define

begin_enum
enum|enum
name|fixstate
block|{
name|DONTKNOW
block|,
name|NOFIX
block|,
name|FIX
block|,
name|IGNORE
block|}
enum|;
end_enum

begin_decl_stmt
name|ino_t
name|cursnapshot
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|inodesc
block|{
name|enum
name|fixstate
name|id_fix
decl_stmt|;
comment|/* policy on fixing errors */
name|int
function_decl|(
modifier|*
name|id_func
function_decl|)
parameter_list|()
function_decl|;
comment|/* function to be applied to blocks of inode */
name|ino_t
name|id_number
decl_stmt|;
comment|/* inode number described */
name|ino_t
name|id_parent
decl_stmt|;
comment|/* for DATA nodes, their parent */
name|int
name|id_lbn
decl_stmt|;
comment|/* logical block number of current block */
name|ufs_daddr_t
name|id_blkno
decl_stmt|;
comment|/* current block number being examined */
name|int
name|id_numfrags
decl_stmt|;
comment|/* number of frags contained in block */
name|quad_t
name|id_filesize
decl_stmt|;
comment|/* for DATA nodes, the size of the directory */
name|int
name|id_loc
decl_stmt|;
comment|/* for DATA nodes, current location in dir */
name|int
name|id_entryno
decl_stmt|;
comment|/* for DATA nodes, current entry number */
name|struct
name|direct
modifier|*
name|id_dirp
decl_stmt|;
comment|/* for DATA nodes, ptr to current entry */
name|char
modifier|*
name|id_name
decl_stmt|;
comment|/* for DATA nodes, name to find or enter */
name|char
name|id_type
decl_stmt|;
comment|/* type of descriptor, DATA or ADDR */
block|}
struct|;
end_struct

begin_comment
comment|/* file types */
end_comment

begin_define
define|#
directive|define
name|DATA
value|1
end_define

begin_comment
comment|/* a directory */
end_comment

begin_define
define|#
directive|define
name|SNAP
value|2
end_define

begin_comment
comment|/* a snapshot */
end_comment

begin_define
define|#
directive|define
name|ADDR
value|3
end_define

begin_comment
comment|/* anything but a directory or a snapshot */
end_comment

begin_comment
comment|/*  * Linked list of duplicate blocks.  *  * The list is composed of two parts. The first part of the  * list (from duplist through the node pointed to by muldup)  * contains a single copy of each duplicate block that has been  * found. The second part of the list (from muldup to the end)  * contains duplicate blocks that have been found more than once.  * To check if a block has been found as a duplicate it is only  * necessary to search from duplist through muldup. To find the  * total number of times that a block has been found as a duplicate  * the entire list must be searched for occurences of the block  * in question. The following diagram shows a sample list where  * w (found twice), x (found once), y (found three times), and z  * (found once) are duplicate block numbers:  *  *    w -> y -> x -> z -> y -> w -> y  *    ^		     ^  *    |		     |  * duplist	  muldup  */
end_comment

begin_struct
struct|struct
name|dups
block|{
name|struct
name|dups
modifier|*
name|next
decl_stmt|;
name|ufs_daddr_t
name|dup
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|dups
modifier|*
name|duplist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of dup list */
end_comment

begin_decl_stmt
name|struct
name|dups
modifier|*
name|muldup
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of unique duplicate dup block numbers */
end_comment

begin_comment
comment|/*  * Linked list of inodes with zero link counts.  */
end_comment

begin_struct
struct|struct
name|zlncnt
block|{
name|struct
name|zlncnt
modifier|*
name|next
decl_stmt|;
name|ino_t
name|zlncnt
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|zlncnt
modifier|*
name|zlnhead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of zero link count list */
end_comment

begin_comment
comment|/*  * Inode cache data structures.  */
end_comment

begin_struct
struct|struct
name|inoinfo
block|{
name|struct
name|inoinfo
modifier|*
name|i_nexthash
decl_stmt|;
comment|/* next entry in hash chain */
name|ino_t
name|i_number
decl_stmt|;
comment|/* inode number of this entry */
name|ino_t
name|i_parent
decl_stmt|;
comment|/* inode number of parent */
name|ino_t
name|i_dotdot
decl_stmt|;
comment|/* inode number of `..' */
name|size_t
name|i_isize
decl_stmt|;
comment|/* size of inode */
name|u_int
name|i_numblks
decl_stmt|;
comment|/* size of block array in bytes */
name|ufs_daddr_t
name|i_blks
index|[
literal|1
index|]
decl_stmt|;
comment|/* actually longer */
block|}
modifier|*
modifier|*
name|inphead
struct|,
modifier|*
modifier|*
name|inpsort
struct|;
end_struct

begin_decl_stmt
name|long
name|numdirs
decl_stmt|,
name|dirhash
decl_stmt|,
name|listmax
decl_stmt|,
name|inplast
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|countdirs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of directories we actually found */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cdevname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of device being checked */
end_comment

begin_decl_stmt
name|long
name|dev_bsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* computed value of DEV_BSIZE */
end_comment

begin_decl_stmt
name|long
name|secsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* actual disk sector size */
end_comment

begin_decl_stmt
name|char
name|fflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* force check, ignore clean flag */
end_comment

begin_decl_stmt
name|char
name|nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* assume a no response */
end_comment

begin_decl_stmt
name|char
name|yflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* assume a yes response */
end_comment

begin_decl_stmt
name|int
name|bflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of alternate super block */
end_comment

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output debugging info */
end_comment

begin_decl_stmt
name|int
name|cvtlevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* convert to newer file system format */
end_comment

begin_decl_stmt
name|int
name|doinglevel1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* converting to new cylinder group format */
end_comment

begin_decl_stmt
name|int
name|doinglevel2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* converting to new inode format */
end_comment

begin_decl_stmt
name|int
name|newinofmt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filesystem has new inode format */
end_comment

begin_decl_stmt
name|char
name|usedsoftdep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* just fix soft dependency inconsistencies */
end_comment

begin_decl_stmt
name|char
name|preen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* just fix normal inconsistencies */
end_comment

begin_decl_stmt
name|char
name|rerun
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rerun fsck. Only used in non-preen mode */
end_comment

begin_decl_stmt
name|int
name|returntosingle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => return to single user mode on exit */
end_comment

begin_decl_stmt
name|char
name|resolved
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cleared if unresolved changes => not clean */
end_comment

begin_decl_stmt
name|int
name|markclean
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mark file system clean when done */
end_comment

begin_decl_stmt
name|char
name|havesb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* superblock has been read */
end_comment

begin_decl_stmt
name|char
name|skipclean
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* skip clean file systems if preening */
end_comment

begin_decl_stmt
name|int
name|fsmodified
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => write done to file system */
end_comment

begin_decl_stmt
name|int
name|fsreadfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for reading file system */
end_comment

begin_decl_stmt
name|int
name|fswritefd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for writing file system */
end_comment

begin_decl_stmt
name|ufs_daddr_t
name|maxfsblock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of blocks in the file system */
end_comment

begin_decl_stmt
name|char
modifier|*
name|blockmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to primary blk allocation map */
end_comment

begin_decl_stmt
name|ino_t
name|maxino
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of inodes in file system */
end_comment

begin_decl_stmt
name|ino_t
name|lfdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lost& found directory inode number */
end_comment

begin_decl_stmt
name|char
modifier|*
name|lfname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lost& found directory name */
end_comment

begin_decl_stmt
name|int
name|lfmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lost& found directory creation mode */
end_comment

begin_decl_stmt
name|ufs_daddr_t
name|n_blks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of blocks in use */
end_comment

begin_decl_stmt
name|ufs_daddr_t
name|n_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of files in use */
end_comment

begin_define
define|#
directive|define
name|clearinode
parameter_list|(
name|dp
parameter_list|)
value|(*(dp) = zino)
end_define

begin_decl_stmt
name|struct
name|dinode
name|zino
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|setbmap
parameter_list|(
name|blkno
parameter_list|)
value|setbit(blockmap, blkno)
end_define

begin_define
define|#
directive|define
name|testbmap
parameter_list|(
name|blkno
parameter_list|)
value|isset(blockmap, blkno)
end_define

begin_define
define|#
directive|define
name|clrbmap
parameter_list|(
name|blkno
parameter_list|)
value|clrbit(blockmap, blkno)
end_define

begin_define
define|#
directive|define
name|STOP
value|0x01
end_define

begin_define
define|#
directive|define
name|SKIP
value|0x02
end_define

begin_define
define|#
directive|define
name|KEEPON
value|0x04
end_define

begin_define
define|#
directive|define
name|ALTERED
value|0x08
end_define

begin_define
define|#
directive|define
name|FOUND
value|0x10
end_define

begin_define
define|#
directive|define
name|EEXIT
value|8
end_define

begin_comment
comment|/* Standard error exit. */
end_comment

begin_struct_decl
struct_decl|struct
name|fstab
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|adjust
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|,
name|int
name|lcnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ufs_daddr_t
name|allocblk
parameter_list|(
name|long
name|frags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ino_t
name|allocdir
parameter_list|(
name|ino_t
name|parent
parameter_list|,
name|ino_t
name|request
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ino_t
name|allocino
parameter_list|(
name|ino_t
name|request
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blkerror
parameter_list|(
name|ino_t
name|ino
parameter_list|,
name|char
modifier|*
name|type
parameter_list|,
name|ufs_daddr_t
name|blk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|blockcheck
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bread
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|ufs_daddr_t
name|blk
parameter_list|,
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwrite
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|ufs_daddr_t
name|blk
parameter_list|,
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cacheino
parameter_list|(
name|struct
name|dinode
modifier|*
name|dp
parameter_list|,
name|ino_t
name|inumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|catch
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|catchquit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|changeino
parameter_list|(
name|ino_t
name|dir
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|ino_t
name|newnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chkrange
parameter_list|(
name|ufs_daddr_t
name|blk
parameter_list|,
name|int
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ckfini
parameter_list|(
name|int
name|markclean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ckinode
parameter_list|(
name|struct
name|dinode
modifier|*
name|dp
parameter_list|,
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clri
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|,
name|char
modifier|*
name|type
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|clearentry
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|direrror
parameter_list|(
name|ino_t
name|ino
parameter_list|,
name|char
modifier|*
name|errmesg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dirscan
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dofix
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffs_clrblock
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|ufs_daddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffs_fragacct
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int32_t
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ffs_isblock
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|ufs_daddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffs_setblock
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|ufs_daddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fileerror
parameter_list|(
name|ino_t
name|cwd
parameter_list|,
name|ino_t
name|ino
parameter_list|,
name|char
modifier|*
name|errmesg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|findino
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|findname
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flush
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|bufarea
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freeblk
parameter_list|(
name|ufs_daddr_t
name|blkno
parameter_list|,
name|long
name|frags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freeino
parameter_list|(
name|ino_t
name|ino
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freeinodebuf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ftypeok
parameter_list|(
name|struct
name|dinode
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getblk
parameter_list|(
name|struct
name|bufarea
modifier|*
name|bp
parameter_list|,
name|ufs_daddr_t
name|blk
parameter_list|,
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bufarea
modifier|*
name|getdatablk
parameter_list|(
name|ufs_daddr_t
name|blkno
parameter_list|,
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inoinfo
modifier|*
name|getinoinfo
parameter_list|(
name|ino_t
name|inumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|dinode
modifier|*
name|getnextinode
parameter_list|(
name|ino_t
name|inumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getpathname
parameter_list|(
name|char
modifier|*
name|namebuf
parameter_list|,
name|ino_t
name|curdir
parameter_list|,
name|ino_t
name|ino
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|dinode
modifier|*
name|ginode
parameter_list|(
name|ino_t
name|inumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inocleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|inodirty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inostat
modifier|*
name|inoinfo
parameter_list|(
name|ino_t
name|inum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linkup
parameter_list|(
name|ino_t
name|orphan
parameter_list|,
name|ino_t
name|parentdir
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|makeentry
parameter_list|(
name|ino_t
name|parent
parameter_list|,
name|ino_t
name|ino
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|panic
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|pass1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pass1b
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pass1check
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pass2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pass3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pass4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pass4check
parameter_list|(
name|struct
name|inodesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pass5
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfatal
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|pinode
parameter_list|(
name|ino_t
name|ino
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|propagate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pwarn
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|reply
parameter_list|(
name|char
modifier|*
name|question
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setinodebuf
parameter_list|(
name|ino_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setup
parameter_list|(
name|char
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|voidquit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

