begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)fsck.h	5.20 (Berkeley) %G%  */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|BUFSIZ
end_ifndef

begin_define
define|#
directive|define
name|BUFSIZ
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|daddr_t
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
name|daddr_t
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

begin_function_decl
name|struct
name|bufarea
modifier|*
name|getdatablk
parameter_list|()
function_decl|;
end_function_decl

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
value|(bp)->b_dirty = 0; \ 	(bp)->b_bno = (daddr_t)-1; \ 	(bp)->b_flags = 0;
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
name|daddr_t
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

begin_define
define|#
directive|define
name|ADDR
value|2
end_define

begin_comment
comment|/*  * Linked list of duplicate blocks.  *   * The list is composed of two parts. The first part of the  * list (from duplist through the node pointed to by muldup)  * contains a single copy of each duplicate block that has been   * found. The second part of the list (from muldup to the end)  * contains duplicate blocks that have been found more than once.  * To check if a block has been found as a duplicate it is only  * necessary to search from duplist through muldup. To find the   * total number of times that a block has been found as a duplicate  * the entire list must be searched for occurences of the block  * in question. The following diagram shows a sample list where  * w (found twice), x (found once), y (found three times), and z  * (found once) are duplicate block numbers:  *  *    w -> y -> x -> z -> y -> w -> y  *    ^		     ^  *    |		     |  * duplist	  muldup  */
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
name|daddr_t
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
name|daddr_t
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
name|listmax
decl_stmt|,
name|inplast
decl_stmt|;
end_decl_stmt

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
name|preen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* just fix normal inconsistencies */
end_comment

begin_decl_stmt
name|char
name|hotroot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* checking root device */
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
name|daddr_t
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
name|lastino
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last inode in use */
end_comment

begin_decl_stmt
name|char
modifier|*
name|statemap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to inode state table */
end_comment

begin_decl_stmt
name|char
modifier|*
name|typemap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to inode type table */
end_comment

begin_decl_stmt
name|short
modifier|*
name|lncntp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to link count table */
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
name|daddr_t
name|n_blks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of blocks in use */
end_comment

begin_decl_stmt
name|daddr_t
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

begin_function_decl
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|dinode
modifier|*
name|ginode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inoinfo
modifier|*
name|getinoinfo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getblk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ino_t
name|allocino
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|findino
parameter_list|()
function_decl|;
end_function_decl

end_unit

