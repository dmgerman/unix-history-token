begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	inode.h	4.24	83/07/01	*/
end_comment

begin_comment
comment|/*  * The I node is the focus of all file activity in UNIX.  * There is a unique inode allocated for each active file,  * each current directory, each mounted-on file, text file, and the root.  * An inode is 'named' by its dev/inumber pair. (iget/iget.c)  * Data in icommon is read in from permanent inode on volume.  */
end_comment

begin_define
define|#
directive|define
name|NDADDR
value|12
end_define

begin_comment
comment|/* direct addresses in inode */
end_comment

begin_define
define|#
directive|define
name|NIADDR
value|3
end_define

begin_comment
comment|/* indirect addresses in inode */
end_comment

begin_struct
struct|struct
name|inode
block|{
name|struct
name|inode
modifier|*
name|i_chain
index|[
literal|2
index|]
decl_stmt|;
comment|/* must be first */
name|u_short
name|i_flag
decl_stmt|;
name|u_short
name|i_count
decl_stmt|;
comment|/* reference count */
name|dev_t
name|i_dev
decl_stmt|;
comment|/* device where inode resides */
name|u_short
name|i_shlockc
decl_stmt|;
comment|/* count of shared locks on inode */
name|u_short
name|i_exlockc
decl_stmt|;
comment|/* count of exclusive locks on inode */
name|ino_t
name|i_number
decl_stmt|;
comment|/* i number, 1-to-1 with device address */
name|struct
name|fs
modifier|*
name|i_fs
decl_stmt|;
comment|/* file sys associated with this inode */
name|struct
name|dquot
modifier|*
name|i_dquot
decl_stmt|;
comment|/* quota structure controlling this file */
union|union
block|{
name|daddr_t
name|if_lastr
decl_stmt|;
comment|/* last read (read-ahead) */
name|struct
name|socket
modifier|*
name|is_socket
decl_stmt|;
struct|struct
block|{
name|struct
name|inode
modifier|*
name|if_freef
decl_stmt|;
comment|/* free list forward */
name|struct
name|inode
modifier|*
modifier|*
name|if_freeb
decl_stmt|;
comment|/* free list back */
block|}
name|i_fr
struct|;
block|}
name|i_un
union|;
struct|struct
name|icommon
block|{
name|u_short
name|ic_mode
decl_stmt|;
comment|/*  0: mode and type of file */
name|short
name|ic_nlink
decl_stmt|;
comment|/*  2: number of links to file */
name|short
name|ic_uid
decl_stmt|;
comment|/*  4: owner's user id */
name|short
name|ic_gid
decl_stmt|;
comment|/*  6: owner's group id */
name|quad
name|ic_size
decl_stmt|;
comment|/*  8: number of bytes in file */
name|time_t
name|ic_atime
decl_stmt|;
comment|/* 16: time last accessed */
name|long
name|ic_atspare
decl_stmt|;
name|time_t
name|ic_mtime
decl_stmt|;
comment|/* 24: time last modified */
name|long
name|ic_mtspare
decl_stmt|;
name|time_t
name|ic_ctime
decl_stmt|;
comment|/* 32: last time inode changed */
name|long
name|ic_ctspare
decl_stmt|;
name|daddr_t
name|ic_db
index|[
name|NDADDR
index|]
decl_stmt|;
comment|/* 40: disk block addresses */
name|daddr_t
name|ic_ib
index|[
name|NIADDR
index|]
decl_stmt|;
comment|/* 88: indirect blocks */
name|long
name|ic_flags
decl_stmt|;
comment|/* 100: status, currently unused */
name|long
name|ic_blocks
decl_stmt|;
comment|/* 104: blocks actually held */
name|long
name|ic_spare
index|[
literal|5
index|]
decl_stmt|;
comment|/* 108: reserved, currently unused */
block|}
name|i_ic
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dinode
block|{
union|union
block|{
name|struct
name|icommon
name|di_icom
decl_stmt|;
name|char
name|di_size
index|[
literal|128
index|]
decl_stmt|;
block|}
name|di_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|i_mode
value|i_ic.ic_mode
end_define

begin_define
define|#
directive|define
name|i_nlink
value|i_ic.ic_nlink
end_define

begin_define
define|#
directive|define
name|i_uid
value|i_ic.ic_uid
end_define

begin_define
define|#
directive|define
name|i_gid
value|i_ic.ic_gid
end_define

begin_comment
comment|/* ugh! -- must be fixed */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|i_size
value|i_ic.ic_size.val[0]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|i_db
value|i_ic.ic_db
end_define

begin_define
define|#
directive|define
name|i_ib
value|i_ic.ic_ib
end_define

begin_define
define|#
directive|define
name|i_atime
value|i_ic.ic_atime
end_define

begin_define
define|#
directive|define
name|i_mtime
value|i_ic.ic_mtime
end_define

begin_define
define|#
directive|define
name|i_ctime
value|i_ic.ic_ctime
end_define

begin_define
define|#
directive|define
name|i_blocks
value|i_ic.ic_blocks
end_define

begin_define
define|#
directive|define
name|i_rdev
value|i_ic.ic_db[0]
end_define

begin_define
define|#
directive|define
name|i_lastr
value|i_un.if_lastr
end_define

begin_define
define|#
directive|define
name|i_socket
value|i_un.is_socket
end_define

begin_define
define|#
directive|define
name|i_forw
value|i_chain[0]
end_define

begin_define
define|#
directive|define
name|i_back
value|i_chain[1]
end_define

begin_define
define|#
directive|define
name|i_freef
value|i_un.i_fr.if_freef
end_define

begin_define
define|#
directive|define
name|i_freeb
value|i_un.i_fr.if_freeb
end_define

begin_define
define|#
directive|define
name|di_ic
value|di_un.di_icom
end_define

begin_define
define|#
directive|define
name|di_mode
value|di_ic.ic_mode
end_define

begin_define
define|#
directive|define
name|di_nlink
value|di_ic.ic_nlink
end_define

begin_define
define|#
directive|define
name|di_uid
value|di_ic.ic_uid
end_define

begin_define
define|#
directive|define
name|di_gid
value|di_ic.ic_gid
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|di_size
value|di_ic.ic_size.val[0]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|di_db
value|di_ic.ic_db
end_define

begin_define
define|#
directive|define
name|di_ib
value|di_ic.ic_ib
end_define

begin_define
define|#
directive|define
name|di_atime
value|di_ic.ic_atime
end_define

begin_define
define|#
directive|define
name|di_mtime
value|di_ic.ic_mtime
end_define

begin_define
define|#
directive|define
name|di_ctime
value|di_ic.ic_ctime
end_define

begin_define
define|#
directive|define
name|di_rdev
value|di_ic.ic_db[0]
end_define

begin_define
define|#
directive|define
name|di_blocks
value|di_ic.ic_blocks
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|inode
modifier|*
name|inode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the inode table itself */
end_comment

begin_decl_stmt
name|struct
name|inode
modifier|*
name|inodeNINODE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the end of the inode table */
end_comment

begin_decl_stmt
name|int
name|ninode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of slots in the table */
end_comment

begin_decl_stmt
name|struct
name|inode
modifier|*
name|rootdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to inode of root directory */
end_comment

begin_function_decl
name|struct
name|inode
modifier|*
name|ialloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inode
modifier|*
name|iget
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_function_decl
name|struct
name|inode
modifier|*
name|ifind
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|inode
modifier|*
name|owner
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inode
modifier|*
name|maknode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inode
modifier|*
name|namei
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ino_t
name|dirpref
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|ILOCKED
value|0x1
end_define

begin_comment
comment|/* inode is locked */
end_comment

begin_define
define|#
directive|define
name|IUPD
value|0x2
end_define

begin_comment
comment|/* file has been modified */
end_comment

begin_define
define|#
directive|define
name|IACC
value|0x4
end_define

begin_comment
comment|/* inode access time to be updated */
end_comment

begin_define
define|#
directive|define
name|IMOUNT
value|0x8
end_define

begin_comment
comment|/* inode is mounted on */
end_comment

begin_define
define|#
directive|define
name|IWANT
value|0x10
end_define

begin_comment
comment|/* some process waiting on lock */
end_comment

begin_define
define|#
directive|define
name|ITEXT
value|0x20
end_define

begin_comment
comment|/* inode is pure text prototype */
end_comment

begin_define
define|#
directive|define
name|ICHG
value|0x40
end_define

begin_comment
comment|/* inode has been changed */
end_comment

begin_define
define|#
directive|define
name|ISHLOCK
value|0x80
end_define

begin_comment
comment|/* file has shared lock */
end_comment

begin_define
define|#
directive|define
name|IEXLOCK
value|0x100
end_define

begin_comment
comment|/* file has exclusive lock */
end_comment

begin_define
define|#
directive|define
name|ILWAIT
value|0x200
end_define

begin_comment
comment|/* someone waiting on file lock */
end_comment

begin_comment
comment|/* modes */
end_comment

begin_define
define|#
directive|define
name|IFMT
value|0170000
end_define

begin_comment
comment|/* type of file */
end_comment

begin_define
define|#
directive|define
name|IFCHR
value|0020000
end_define

begin_comment
comment|/* character special */
end_comment

begin_define
define|#
directive|define
name|IFDIR
value|0040000
end_define

begin_comment
comment|/* directory */
end_comment

begin_define
define|#
directive|define
name|IFBLK
value|0060000
end_define

begin_comment
comment|/* block special */
end_comment

begin_define
define|#
directive|define
name|IFREG
value|0100000
end_define

begin_comment
comment|/* regular */
end_comment

begin_define
define|#
directive|define
name|IFLNK
value|0120000
end_define

begin_comment
comment|/* symbolic link */
end_comment

begin_define
define|#
directive|define
name|IFSOCK
value|0140000
end_define

begin_comment
comment|/* socket */
end_comment

begin_define
define|#
directive|define
name|ISUID
value|04000
end_define

begin_comment
comment|/* set user id on execution */
end_comment

begin_define
define|#
directive|define
name|ISGID
value|02000
end_define

begin_comment
comment|/* set group id on execution */
end_comment

begin_define
define|#
directive|define
name|ISVTX
value|01000
end_define

begin_comment
comment|/* save swapped text even after use */
end_comment

begin_define
define|#
directive|define
name|IREAD
value|0400
end_define

begin_comment
comment|/* read, write, execute permissions */
end_comment

begin_define
define|#
directive|define
name|IWRITE
value|0200
end_define

begin_define
define|#
directive|define
name|IEXEC
value|0100
end_define

begin_define
define|#
directive|define
name|ILOCK
parameter_list|(
name|ip
parameter_list|)
value|{ \ 	while ((ip)->i_flag& ILOCKED) { \ 		(ip)->i_flag |= IWANT; \ 		sleep((caddr_t)(ip), PINOD); \ 	} \ 	(ip)->i_flag |= ILOCKED; \ }
end_define

begin_define
define|#
directive|define
name|IUNLOCK
parameter_list|(
name|ip
parameter_list|)
value|{ \ 	(ip)->i_flag&= ~ILOCKED; \ 	if ((ip)->i_flag&IWANT) { \ 		(ip)->i_flag&= ~IWANT; \ 		wakeup((caddr_t)(ip)); \ 	} \ }
end_define

begin_define
define|#
directive|define
name|IUPDAT
parameter_list|(
name|ip
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|,
name|waitfor
parameter_list|)
value|{ \ 	if (ip->i_flag&(IUPD|IACC|ICHG)) \ 		iupdat(ip, t1, t2, waitfor); \ }
end_define

end_unit

