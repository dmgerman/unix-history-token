begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The user structure.  * One allocated per process.  * Contains all per process data  * that doesn't need to be referenced  * while the process is swapped.  * The user block is USIZE*64 bytes  * long; resides at virtual kernel  * loc 140000; contains the system  * stack per user; is cross referenced  * with the proc structure for the  * same process.  */
end_comment

begin_struct
struct|struct
name|user
block|{
name|int
name|u_rsav
index|[
literal|2
index|]
decl_stmt|;
comment|/* save r5,r6 when exchanging stacks */
name|int
name|u_fsav
index|[
literal|25
index|]
decl_stmt|;
comment|/* save fp registers */
comment|/* rsav and fsav must be first in structure */
name|char
name|u_segflg
decl_stmt|;
comment|/* flag for IO; user or kernel space */
name|char
name|u_error
decl_stmt|;
comment|/* return error code */
name|char
name|u_uid
decl_stmt|;
comment|/* effective user id */
name|char
name|u_gid
decl_stmt|;
comment|/* effective group id */
name|char
name|u_ruid
decl_stmt|;
comment|/* real user id */
name|char
name|u_rgid
decl_stmt|;
comment|/* real group id */
name|int
name|u_procp
decl_stmt|;
comment|/* pointer to proc structure */
name|char
modifier|*
name|u_base
decl_stmt|;
comment|/* base address for IO */
name|char
modifier|*
name|u_count
decl_stmt|;
comment|/* bytes remaining for IO */
name|char
modifier|*
name|u_offset
index|[
literal|2
index|]
decl_stmt|;
comment|/* offset in file for IO */
name|int
modifier|*
name|u_cdir
decl_stmt|;
comment|/* pointer to inode of current directory */
name|char
name|u_dbuf
index|[
name|DIRSIZ
index|]
decl_stmt|;
comment|/* current pathname component */
name|char
modifier|*
name|u_dirp
decl_stmt|;
comment|/* current pointer to inode */
struct|struct
block|{
comment|/* current directory entry */
name|int
name|u_ino
decl_stmt|;
name|char
name|u_name
index|[
name|DIRSIZ
index|]
decl_stmt|;
block|}
name|u_dent
struct|;
name|int
modifier|*
name|u_pdir
decl_stmt|;
comment|/* inode of parent directory of dirp */
name|int
name|u_uisa
index|[
literal|16
index|]
decl_stmt|;
comment|/* prototype of segmentation addresses */
name|int
name|u_uisd
index|[
literal|16
index|]
decl_stmt|;
comment|/* prototype of segmentation descriptors */
name|int
name|u_ofile
index|[
name|NOFILE
index|]
decl_stmt|;
comment|/* pointers to file structures of open files */
name|int
name|u_arg
index|[
literal|5
index|]
decl_stmt|;
comment|/* arguments to current system call */
name|int
name|u_tsize
decl_stmt|;
comment|/* text size (*64) */
name|int
name|u_dsize
decl_stmt|;
comment|/* data size (*64) */
name|int
name|u_ssize
decl_stmt|;
comment|/* stack size (*64) */
name|int
name|u_sep
decl_stmt|;
comment|/* flag for I and D separation */
name|int
name|u_qsav
index|[
literal|2
index|]
decl_stmt|;
comment|/* label variable for quits and interrupts */
name|int
name|u_ssav
index|[
literal|2
index|]
decl_stmt|;
comment|/* label variable for swapping */
name|int
name|u_signal
index|[
name|NSIG
index|]
decl_stmt|;
comment|/* disposition of signals */
name|int
name|u_utime
decl_stmt|;
comment|/* this process user time */
name|int
name|u_stime
decl_stmt|;
comment|/* this process system time */
name|int
name|u_cutime
index|[
literal|2
index|]
decl_stmt|;
comment|/* sum of childs' utimes */
name|int
name|u_cstime
index|[
literal|2
index|]
decl_stmt|;
comment|/* sum of childs' stimes */
name|int
modifier|*
name|u_ar0
decl_stmt|;
comment|/* address of users saved R0 */
name|int
name|u_prof
index|[
literal|4
index|]
decl_stmt|;
comment|/* profile arguments */
name|char
name|u_intflg
decl_stmt|;
comment|/* catch intr from sys */
comment|/* kernel stack per user 					 * extends from u + USIZE*64 					 * backward not to reach here 					 */
block|}
name|u
struct|;
end_struct

begin_comment
comment|/* u_error codes */
end_comment

begin_define
define|#
directive|define
name|EFAULT
value|106
end_define

begin_define
define|#
directive|define
name|EPERM
value|1
end_define

begin_define
define|#
directive|define
name|ENOENT
value|2
end_define

begin_define
define|#
directive|define
name|ESRCH
value|3
end_define

begin_define
define|#
directive|define
name|EINTR
value|4
end_define

begin_define
define|#
directive|define
name|EIO
value|5
end_define

begin_define
define|#
directive|define
name|ENXIO
value|6
end_define

begin_define
define|#
directive|define
name|E2BIG
value|7
end_define

begin_define
define|#
directive|define
name|ENOEXEC
value|8
end_define

begin_define
define|#
directive|define
name|EBADF
value|9
end_define

begin_define
define|#
directive|define
name|ECHILD
value|10
end_define

begin_define
define|#
directive|define
name|EAGAIN
value|11
end_define

begin_define
define|#
directive|define
name|ENOMEM
value|12
end_define

begin_define
define|#
directive|define
name|EACCES
value|13
end_define

begin_define
define|#
directive|define
name|ENOTBLK
value|15
end_define

begin_define
define|#
directive|define
name|EBUSY
value|16
end_define

begin_define
define|#
directive|define
name|EEXIST
value|17
end_define

begin_define
define|#
directive|define
name|EXDEV
value|18
end_define

begin_define
define|#
directive|define
name|ENODEV
value|19
end_define

begin_define
define|#
directive|define
name|ENOTDIR
value|20
end_define

begin_define
define|#
directive|define
name|EISDIR
value|21
end_define

begin_define
define|#
directive|define
name|EINVAL
value|22
end_define

begin_define
define|#
directive|define
name|ENFILE
value|23
end_define

begin_define
define|#
directive|define
name|EMFILE
value|24
end_define

begin_define
define|#
directive|define
name|ENOTTY
value|25
end_define

begin_define
define|#
directive|define
name|ETXTBSY
value|26
end_define

begin_define
define|#
directive|define
name|EFBIG
value|27
end_define

begin_define
define|#
directive|define
name|ENOSPC
value|28
end_define

begin_define
define|#
directive|define
name|ESPIPE
value|29
end_define

begin_define
define|#
directive|define
name|EROFS
value|30
end_define

begin_define
define|#
directive|define
name|EMLINK
value|31
end_define

begin_define
define|#
directive|define
name|EPIPE
value|32
end_define

end_unit

