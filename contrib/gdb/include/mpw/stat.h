begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* The<sys/stat.h> header defines a struct that is used in the stat() and  * fstat functions.  The information in this struct comes from the i-node of  * some file.  These calls are the only approved way to inspect i-nodes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STAT_H
end_ifndef

begin_define
define|#
directive|define
name|_STAT_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_TYPES_H
end_ifndef

begin_comment
comment|/* not quite right */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|stat
block|{
name|dev_t
name|st_dev
decl_stmt|;
comment|/* major/minor device number */
name|ino_t
name|st_ino
decl_stmt|;
comment|/* i-node number */
name|mode_t
name|st_mode
decl_stmt|;
comment|/* file mode, protection bits, etc. */
name|short
name|int
name|st_nlink
decl_stmt|;
comment|/* # links; TEMPORARY HACK: should be nlink_t*/
name|uid_t
name|st_uid
decl_stmt|;
comment|/* uid of the file's owner */
name|short
name|int
name|st_gid
decl_stmt|;
comment|/* gid; TEMPORARY HACK: should be gid_t */
name|dev_t
name|st_rdev
decl_stmt|;
name|off_t
name|st_size
decl_stmt|;
comment|/* file size */
name|time_t
name|st_atime
decl_stmt|;
comment|/* time of last access */
name|time_t
name|st_mtime
decl_stmt|;
comment|/* time of last data modification */
name|time_t
name|st_ctime
decl_stmt|;
comment|/* time of last file status change */
block|}
struct|;
end_struct

begin_comment
comment|/* Traditional mask definitions for st_mode. */
end_comment

begin_define
define|#
directive|define
name|S_IFMT
value|0170000
end_define

begin_comment
comment|/* type of file */
end_comment

begin_define
define|#
directive|define
name|S_IFREG
value|0100000
end_define

begin_comment
comment|/* regular */
end_comment

begin_define
define|#
directive|define
name|S_IFBLK
value|0060000
end_define

begin_comment
comment|/* block special */
end_comment

begin_define
define|#
directive|define
name|S_IFDIR
value|0040000
end_define

begin_comment
comment|/* directory */
end_comment

begin_define
define|#
directive|define
name|S_IFCHR
value|0020000
end_define

begin_comment
comment|/* character special */
end_comment

begin_define
define|#
directive|define
name|S_IFIFO
value|0010000
end_define

begin_comment
comment|/* this is a FIFO */
end_comment

begin_define
define|#
directive|define
name|S_ISUID
value|0004000
end_define

begin_comment
comment|/* set user id on execution */
end_comment

begin_define
define|#
directive|define
name|S_ISGID
value|0002000
end_define

begin_comment
comment|/* set group id on execution */
end_comment

begin_comment
comment|/* next is reserved for future use */
end_comment

begin_define
define|#
directive|define
name|S_ISVTX
value|01000
end_define

begin_comment
comment|/* save swapped text even after use */
end_comment

begin_comment
comment|/* POSIX masks for st_mode. */
end_comment

begin_define
define|#
directive|define
name|S_IRWXU
value|00700
end_define

begin_comment
comment|/* owner:  rwx------ */
end_comment

begin_define
define|#
directive|define
name|S_IRUSR
value|00400
end_define

begin_comment
comment|/* owner:  r-------- */
end_comment

begin_define
define|#
directive|define
name|S_IWUSR
value|00200
end_define

begin_comment
comment|/* owner:  -w------- */
end_comment

begin_define
define|#
directive|define
name|S_IXUSR
value|00100
end_define

begin_comment
comment|/* owner:  --x------ */
end_comment

begin_define
define|#
directive|define
name|S_IRWXG
value|00070
end_define

begin_comment
comment|/* group:  ---rwx--- */
end_comment

begin_define
define|#
directive|define
name|S_IRGRP
value|00040
end_define

begin_comment
comment|/* group:  ---r----- */
end_comment

begin_define
define|#
directive|define
name|S_IWGRP
value|00020
end_define

begin_comment
comment|/* group:  ----w---- */
end_comment

begin_define
define|#
directive|define
name|S_IXGRP
value|00010
end_define

begin_comment
comment|/* group:  -----x--- */
end_comment

begin_define
define|#
directive|define
name|S_IRWXO
value|00007
end_define

begin_comment
comment|/* others: ------rwx */
end_comment

begin_define
define|#
directive|define
name|S_IROTH
value|00004
end_define

begin_comment
comment|/* others: ------r-- */
end_comment

begin_define
define|#
directive|define
name|S_IWOTH
value|00002
end_define

begin_comment
comment|/* others: -------w- */
end_comment

begin_define
define|#
directive|define
name|S_IXOTH
value|00001
end_define

begin_comment
comment|/* others: --------x */
end_comment

begin_comment
comment|/* The following macros test st_mode (from POSIX Sec. 5.6.1.1. */
end_comment

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFREG)
end_define

begin_comment
comment|/* is a reg file */
end_comment

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFDIR)
end_define

begin_comment
comment|/* is a directory */
end_comment

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFCHR)
end_define

begin_comment
comment|/* is a char spec */
end_comment

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFBLK)
end_define

begin_comment
comment|/* is a block spec */
end_comment

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFIFO)
end_define

begin_comment
comment|/* is a pipe/FIFO */
end_comment

begin_comment
comment|/* Function Prototypes. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_H
end_ifndef

begin_include
include|#
directive|include
file|<ansi.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int chmod
argument_list|,
argument|(const char *_path, int _mode)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int fstat
argument_list|,
argument|(int _fildes, struct stat *_buf)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int mkdir
argument_list|,
argument|(const char *_path, int _mode)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int mkfifo
argument_list|,
argument|(const char *_path, int _mode)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|int stat
argument_list|,
argument|(const char *_path, struct stat *_buf)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYPE
argument_list|(
argument|mode_t umask
argument_list|,
argument|(int _cmask)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STAT_H */
end_comment

end_unit

