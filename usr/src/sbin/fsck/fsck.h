begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)fsck.h	3.5 (Berkeley) %G% */
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
name|MAXLNCNT
value|500
end_define

begin_comment
comment|/* num zero link cnts to remember */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|SIG_TYP
function_decl|)
parameter_list|()
function_decl|;
end_typedef

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
name|direct
name|DIRECT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|dip
parameter_list|)
value|(((dip)->di_mode& IFMT) != 0)
end_define

begin_define
define|#
directive|define
name|DIRCT
parameter_list|(
name|dip
parameter_list|)
value|(((dip)->di_mode& IFMT) == IFDIR)
end_define

begin_define
define|#
directive|define
name|SPECIAL
parameter_list|(
name|dip
parameter_list|)
define|\
value|(((dip)->di_mode& IFMT) == IFBLK || ((dip)->di_mode& IFMT) == IFCHR)
end_define

begin_define
define|#
directive|define
name|MAXNINDIR
value|(MAXBSIZE / sizeof (daddr_t))
end_define

begin_define
define|#
directive|define
name|MAXINOPB
value|(MAXBSIZE / sizeof (struct dinode))
end_define

begin_define
define|#
directive|define
name|SPERB
value|(MAXBSIZE / sizeof(short))
end_define

begin_struct
struct|struct
name|bufarea
block|{
name|struct
name|bufarea
modifier|*
name|b_next
decl_stmt|;
comment|/* must be first */
name|daddr_t
name|b_bno
decl_stmt|;
name|int
name|b_size
decl_stmt|;
name|int
name|b_errs
decl_stmt|;
union|union
block|{
name|char
name|b_buf
index|[
name|MAXBSIZE
index|]
decl_stmt|;
comment|/* buffer space */
name|short
name|b_lnks
index|[
name|SPERB
index|]
decl_stmt|;
comment|/* link counts */
name|daddr_t
name|b_indir
index|[
name|MAXNINDIR
index|]
decl_stmt|;
comment|/* indirect block */
name|struct
name|fs
name|b_fs
decl_stmt|;
comment|/* super block */
name|struct
name|cg
name|b_cg
decl_stmt|;
comment|/* cylinder group */
name|struct
name|dinode
name|b_dinode
index|[
name|MAXINOPB
index|]
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

begin_typedef
typedef|typedef
name|struct
name|bufarea
name|BUFAREA
typedef|;
end_typedef

begin_decl_stmt
name|BUFAREA
name|inoblk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inode blocks */
end_comment

begin_decl_stmt
name|BUFAREA
name|fileblk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* other blks in filesys */
end_comment

begin_decl_stmt
name|BUFAREA
name|sblk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file system superblock */
end_comment

begin_decl_stmt
name|BUFAREA
name|cgblk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cylinder group blocks */
end_comment

begin_define
define|#
directive|define
name|initbarea
parameter_list|(
name|x
parameter_list|)
value|(x)->b_dirty = 0;(x)->b_bno = (daddr_t)-1
end_define

begin_define
define|#
directive|define
name|dirty
parameter_list|(
name|x
parameter_list|)
value|(x)->b_dirty = 1
end_define

begin_define
define|#
directive|define
name|inodirty
parameter_list|()
value|inoblk.b_dirty = 1
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
name|dirblk
value|fileblk.b_un
end_define

begin_define
define|#
directive|define
name|sblock
value|sblk.b_un.b_fs
end_define

begin_define
define|#
directive|define
name|cgrp
value|cgblk.b_un.b_cg
end_define

begin_struct
struct|struct
name|filecntl
block|{
name|int
name|rfdes
decl_stmt|;
name|int
name|wfdes
decl_stmt|;
name|int
name|mod
decl_stmt|;
block|}
name|dfile
struct|;
end_struct

begin_comment
comment|/* file descriptors for filesys */
end_comment

begin_enum
enum|enum
name|fixstate
block|{
name|DONTKNOW
block|,
name|NOFIX
block|,
name|FIX
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
name|long
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
name|DIRECT
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
comment|/*  * Linked list of duplicate blocks  */
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

begin_decl_stmt
name|ino_t
name|badlncnt
index|[
name|MAXLNCNT
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table of inos with zero link cnts */
end_comment

begin_decl_stmt
name|ino_t
modifier|*
name|badlnp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next entry in table */
end_comment

begin_decl_stmt
name|char
name|rawflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|devname
decl_stmt|;
end_decl_stmt

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
modifier|*
name|blockmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to primary blk allocation map */
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
name|short
modifier|*
name|lncntp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to link count table */
end_comment

begin_decl_stmt
name|char
name|pathname
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current pathname */
end_comment

begin_decl_stmt
name|char
modifier|*
name|pathp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to pathname position */
end_comment

begin_decl_stmt
name|char
modifier|*
name|endpathname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|daddr_t
name|fmax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of blocks in the volume */
end_comment

begin_decl_stmt
name|ino_t
name|imax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of inodes */
end_comment

begin_decl_stmt
name|ino_t
name|lastino
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hiwater mark of inodes */
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
name|off_t
name|maxblk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* largest logical blk in file */
end_comment

begin_decl_stmt
name|off_t
name|bmapsz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* num chars in blockmap */
end_comment

begin_decl_stmt
name|daddr_t
name|n_blks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of blocks used */
end_comment

begin_decl_stmt
name|daddr_t
name|n_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of files seen */
end_comment

begin_define
define|#
directive|define
name|zapino
parameter_list|(
name|x
parameter_list|)
value|(*(x) = zino)
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
name|x
parameter_list|)
value|setbit(blockmap, x)
end_define

begin_define
define|#
directive|define
name|getbmap
parameter_list|(
name|x
parameter_list|)
value|isset(blockmap, x)
end_define

begin_define
define|#
directive|define
name|clrbmap
parameter_list|(
name|x
parameter_list|)
value|clrbit(blockmap, x)
end_define

begin_define
define|#
directive|define
name|ALTERED
value|010
end_define

begin_define
define|#
directive|define
name|KEEPON
value|04
end_define

begin_define
define|#
directive|define
name|SKIP
value|02
end_define

begin_define
define|#
directive|define
name|STOP
value|01
end_define

begin_function_decl
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|DINODE
modifier|*
name|ginode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|BUFAREA
modifier|*
name|getblk
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

