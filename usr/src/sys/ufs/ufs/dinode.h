begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	dinode.h	3.6	%G%	*/
end_comment

begin_comment
comment|/*  * The I node is the focus of all  * file activity in unix. There is a unique  * inode allocated for each active file,  * each current directory, each mounted-on  * file, text file, and the root. An inode is 'named'  * by its dev/inumber pair. (iget/iget.c)  * Data, from mode on, is read in  * from permanent inode on volume.  */
end_comment

begin_define
define|#
directive|define
name|NADDR
value|13
end_define

begin_define
define|#
directive|define
name|NINDEX
value|15
end_define

begin_struct
struct|struct
name|group
block|{
name|short
name|g_state
decl_stmt|;
name|char
name|g_index
decl_stmt|;
name|char
name|g_rot
decl_stmt|;
name|struct
name|group
modifier|*
name|g_group
decl_stmt|;
name|struct
name|inode
modifier|*
name|g_inode
decl_stmt|;
name|struct
name|file
modifier|*
name|g_file
decl_stmt|;
name|short
name|g_rotmask
decl_stmt|;
name|short
name|g_datq
decl_stmt|;
name|struct
name|chan
modifier|*
name|g_chans
index|[
name|NINDEX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|inode
block|{
name|char
name|i_flag
decl_stmt|;
name|char
name|i_count
decl_stmt|;
comment|/* reference count */
name|dev_t
name|i_dev
decl_stmt|;
comment|/* device where inode resides */
name|ino_t
name|i_number
decl_stmt|;
comment|/* i number, 1-to-1 with device address */
name|unsigned
name|short
name|i_mode
decl_stmt|;
name|short
name|i_nlink
decl_stmt|;
comment|/* directory entries */
name|short
name|i_uid
decl_stmt|;
comment|/* owner */
name|short
name|i_gid
decl_stmt|;
comment|/* group of owner */
name|off_t
name|i_size
decl_stmt|;
comment|/* size of file */
union|union
block|{
struct|struct
block|{
name|daddr_t
name|I_addr
index|[
name|NADDR
index|]
decl_stmt|;
comment|/* if normal file/directory */
name|daddr_t
name|I_lastr
decl_stmt|;
comment|/* last read (for read-ahead) */
block|}
name|i_f
struct|;
define|#
directive|define
name|i_addr
value|i_f.I_addr
define|#
directive|define
name|i_lastr
value|i_f.I_lastr
struct|struct
block|{
name|daddr_t
name|I_rdev
decl_stmt|;
comment|/* i_addr[0] */
name|struct
name|group
name|I_group
decl_stmt|;
comment|/* multiplexor group file */
block|}
name|i_d
struct|;
define|#
directive|define
name|i_rdev
value|i_d.I_rdev
define|#
directive|define
name|i_group
value|i_d.I_group
block|}
name|i_un
union|;
name|short
name|i_vfdcnt
decl_stmt|;
comment|/* number of fd's vreading this inode */
name|short
name|i_hlink
decl_stmt|;
comment|/* link in hash chain (iget/iput/ifind) */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|inode
name|inode
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The inode table itself */
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

begin_decl_stmt
name|struct
name|inode
modifier|*
name|mpxip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mpx virtual inode */
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
name|ifind
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
name|ILOCK
value|01
end_define

begin_comment
comment|/* inode is locked */
end_comment

begin_define
define|#
directive|define
name|IUPD
value|02
end_define

begin_comment
comment|/* file has been modified */
end_comment

begin_define
define|#
directive|define
name|IACC
value|04
end_define

begin_comment
comment|/* inode access time to be updated */
end_comment

begin_define
define|#
directive|define
name|IMOUNT
value|010
end_define

begin_comment
comment|/* inode is mounted on */
end_comment

begin_define
define|#
directive|define
name|IWANT
value|020
end_define

begin_comment
comment|/* some process waiting on lock */
end_comment

begin_define
define|#
directive|define
name|ITEXT
value|040
end_define

begin_comment
comment|/* inode is pure text prototype */
end_comment

begin_define
define|#
directive|define
name|ICHG
value|0100
end_define

begin_comment
comment|/* inode has been changed */
end_comment

begin_define
define|#
directive|define
name|IPIPE
value|0200
end_define

begin_comment
comment|/* inode is a pipe */
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
name|IFDIR
value|0040000
end_define

begin_comment
comment|/* directory */
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
name|IFMPC
value|0030000
end_define

begin_comment
comment|/* multiplexed char special */
end_comment

begin_define
define|#
directive|define
name|IFMPB
value|0070000
end_define

begin_comment
comment|/* multiplexed block special */
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

end_unit

