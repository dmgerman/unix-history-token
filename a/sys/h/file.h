begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	file.h	4.14	82/11/13	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Descriptor table entry.  * One for each kernel object.  */
end_comment

begin_struct
struct|struct
name|file
block|{
name|short
name|f_flag
decl_stmt|;
comment|/* see below */
name|short
name|f_type
decl_stmt|;
comment|/* descriptor type */
name|char
name|f_nbhow
decl_stmt|;
comment|/* state from dnblock */
name|char
name|f_sighow
decl_stmt|;
comment|/* state from dsignal */
name|short
name|f_count
decl_stmt|;
comment|/* reference count */
comment|/* begin XXX */
name|struct
name|inode
modifier|*
name|f_inode
decl_stmt|;
comment|/* inode */
union|union
block|{
struct|struct
name|f_in
block|{
name|off_t
name|fi_offset
decl_stmt|;
block|}
name|f_in
struct|;
struct|struct
name|f_so
block|{
name|struct
name|socket
modifier|*
name|fs_socket
decl_stmt|;
block|}
name|f_so
struct|;
block|}
name|f_un
union|;
define|#
directive|define
name|f_offset
value|f_un.f_in.fi_offset
define|#
directive|define
name|f_socket
value|f_un.f_so.fs_socket
comment|/* end XXX */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|file
modifier|*
name|file
decl_stmt|,
modifier|*
name|fileNFILE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfile
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|file
modifier|*
name|getf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|file
modifier|*
name|falloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|FREAD
value|0x001
end_define

begin_comment
comment|/* descriptor read/receive'able */
end_comment

begin_define
define|#
directive|define
name|FWRITE
value|0x002
end_define

begin_comment
comment|/* descriptor write/send'able */
end_comment

begin_define
define|#
directive|define
name|FAPPEND
value|0x004
end_define

begin_comment
comment|/* append on each write */
end_comment

begin_comment
comment|/* the following defines the bits that users can set in f_flag */
end_comment

begin_define
define|#
directive|define
name|FMODES
value|(FREAD|FWRITE|FAPPEND)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * User visible desriptor attributes.  * These are supplied at open or flock time.  * FRDONLY, FWRONLY, and FRDWR are  * converted to FREAD and FWRITE on open.  */
end_comment

begin_define
define|#
directive|define
name|FRDONLY
value|0x000
end_define

begin_comment
comment|/* open for reading only */
end_comment

begin_define
define|#
directive|define
name|FWRONLY
value|0x001
end_define

begin_comment
comment|/* open for writing only */
end_comment

begin_define
define|#
directive|define
name|FRDWR
value|0x002
end_define

begin_comment
comment|/* open for reading and writing */
end_comment

begin_define
define|#
directive|define
name|FAPPEND
value|0x004
end_define

begin_comment
comment|/* append on each write */
end_comment

begin_define
define|#
directive|define
name|FSHLOCK
value|0x008
end_define

begin_comment
comment|/* apply shared lock */
end_comment

begin_define
define|#
directive|define
name|FEXLOCK
value|0x010
end_define

begin_comment
comment|/* apply exclusive lock */
end_comment

begin_define
define|#
directive|define
name|FUNLOCK
value|0x100
end_define

begin_comment
comment|/* release all locks */
end_comment

begin_define
define|#
directive|define
name|FCREATE
value|0x200
end_define

begin_comment
comment|/* create file if nonexistant */
end_comment

begin_define
define|#
directive|define
name|FTRUNCATE
value|0x400
end_define

begin_comment
comment|/* truncate file to size 0 on open */
end_comment

begin_define
define|#
directive|define
name|FNBLOCK
value|0x800
end_define

begin_comment
comment|/* don't block on open */
end_comment

begin_comment
comment|/* these are for 3.0 "compatibility" */
end_comment

begin_define
define|#
directive|define
name|O_RDONLY
value|FRDONLY
end_define

begin_comment
comment|/* open for read */
end_comment

begin_define
define|#
directive|define
name|O_WRONLY
value|FWRONLY
end_define

begin_comment
comment|/* open for writing */
end_comment

begin_define
define|#
directive|define
name|O_RDWR
value|FRDWR
end_define

begin_comment
comment|/* open for read& write */
end_comment

begin_define
define|#
directive|define
name|O_NDELAY
value|FNBLOCK
end_define

begin_comment
comment|/* non-blocking I/O */
end_comment

begin_define
define|#
directive|define
name|O_APPEND
value|FAPPEND
end_define

begin_comment
comment|/* append */
end_comment

begin_define
define|#
directive|define
name|O_CREAT
value|FCREATE
end_define

begin_comment
comment|/* open with file create */
end_comment

begin_define
define|#
directive|define
name|O_TRUNC
value|FTRUNCATE
end_define

begin_comment
comment|/* open with truncation */
end_comment

begin_define
define|#
directive|define
name|O_EXCL
value|FEXLOCK
end_define

begin_comment
comment|/* exclusive open */
end_comment

begin_comment
comment|/* flags supplied to access call */
end_comment

begin_define
define|#
directive|define
name|FACCESS_EXISTS
value|0x0
end_define

begin_comment
comment|/* does file exist */
end_comment

begin_define
define|#
directive|define
name|FACCESS_EXECUTE
value|0x1
end_define

begin_comment
comment|/* is it executable by caller */
end_comment

begin_define
define|#
directive|define
name|FACCESS_WRITE
value|0x2
end_define

begin_comment
comment|/* writable by caller */
end_comment

begin_define
define|#
directive|define
name|FACCESS_READ
value|0x4
end_define

begin_comment
comment|/* readable by caller */
end_comment

begin_comment
comment|/* flags supplies to lseek call */
end_comment

begin_define
define|#
directive|define
name|FSEEK_ABSOLUTE
value|0x0
end_define

begin_comment
comment|/* absolute offset */
end_comment

begin_define
define|#
directive|define
name|FSEEK_RELATIVE
value|0x1
end_define

begin_comment
comment|/* relative to current offset */
end_comment

begin_define
define|#
directive|define
name|FSEEK_EOF
value|0x2
end_define

begin_comment
comment|/* relative to end of file */
end_comment

begin_comment
comment|/* file types which may be specified to mknod */
end_comment

begin_define
define|#
directive|define
name|FTYPE_CDEV
value|0x2000
end_define

begin_comment
comment|/* character special device */
end_comment

begin_define
define|#
directive|define
name|FTYPE_DIR
value|0x4000
end_define

begin_comment
comment|/* directory */
end_comment

begin_define
define|#
directive|define
name|FTYPE_BDEV
value|0x8000
end_define

begin_comment
comment|/* block special device */
end_comment

begin_define
define|#
directive|define
name|GETF
parameter_list|(
name|fp
parameter_list|,
name|fd
parameter_list|)
value|{ \ 	if ((unsigned)(fd)>= NOFILE || ((fp) = u.u_ofile[fd]) == NULL) { \ 		u.u_error = EBADF; \ 		return; \ 	} \ }
end_define

end_unit

