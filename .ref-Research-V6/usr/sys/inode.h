begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The I node is the focus of all  * file activity in unix. There is a unique  * inode allocated for each active file,  * each current directory, each mounted-on  * file, text file, and the root. An inode is 'named'  * by its dev/inumber pair. (iget/iget.c)  * Data, from mode on, is read in  * from permanent inode on volume.  */
end_comment

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
name|int
name|i_dev
decl_stmt|;
comment|/* device where inode resides */
name|int
name|i_number
decl_stmt|;
comment|/* i number, 1-to-1 with device address */
name|int
name|i_mode
decl_stmt|;
name|char
name|i_nlink
decl_stmt|;
comment|/* directory entries */
name|char
name|i_uid
decl_stmt|;
comment|/* owner */
name|char
name|i_gid
decl_stmt|;
comment|/* group of owner */
name|char
name|i_size0
decl_stmt|;
comment|/* most significant of size */
name|char
modifier|*
name|i_size1
decl_stmt|;
comment|/* least sig */
name|int
name|i_addr
index|[
literal|8
index|]
decl_stmt|;
comment|/* device addresses constituting file */
name|int
name|i_lastr
decl_stmt|;
comment|/* last logical block read (for read-ahead) */
block|}
name|inode
index|[
name|NINODE
index|]
struct|;
end_struct

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
comment|/* inode has been modified */
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

begin_comment
comment|/* modes */
end_comment

begin_define
define|#
directive|define
name|IALLOC
value|0100000
end_define

begin_comment
comment|/* file is used */
end_comment

begin_define
define|#
directive|define
name|IFMT
value|060000
end_define

begin_comment
comment|/* type of file */
end_comment

begin_define
define|#
directive|define
name|IFDIR
value|040000
end_define

begin_comment
comment|/* directory */
end_comment

begin_define
define|#
directive|define
name|IFCHR
value|020000
end_define

begin_comment
comment|/* character special */
end_comment

begin_define
define|#
directive|define
name|IFBLK
value|060000
end_define

begin_comment
comment|/* block special, 0 is regular */
end_comment

begin_define
define|#
directive|define
name|ILARG
value|010000
end_define

begin_comment
comment|/* large addressing algorithm */
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

