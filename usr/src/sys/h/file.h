begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)file.h	7.1 (Berkeley) 6/4/86  */
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
name|int
name|f_flag
decl_stmt|;
comment|/* see below */
name|short
name|f_type
decl_stmt|;
comment|/* descriptor type */
name|short
name|f_count
decl_stmt|;
comment|/* reference count */
name|short
name|f_msgcount
decl_stmt|;
comment|/* references from message queue */
struct|struct
name|fileops
block|{
name|int
function_decl|(
modifier|*
name|fo_rw
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_ioctl
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_select
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_close
function_decl|)
parameter_list|()
function_decl|;
block|}
modifier|*
name|f_ops
struct|;
name|caddr_t
name|f_data
decl_stmt|;
comment|/* inode */
name|off_t
name|f_offset
decl_stmt|;
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * flags- also for fcntl call.  */
end_comment

begin_define
define|#
directive|define
name|FOPEN
value|(-1)
end_define

begin_define
define|#
directive|define
name|FREAD
value|00001
end_define

begin_comment
comment|/* descriptor read/receive'able */
end_comment

begin_define
define|#
directive|define
name|FWRITE
value|00002
end_define

begin_comment
comment|/* descriptor write/send'able */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|F_DUPFD
end_ifndef

begin_define
define|#
directive|define
name|FNDELAY
value|00004
end_define

begin_comment
comment|/* no delay */
end_comment

begin_define
define|#
directive|define
name|FAPPEND
value|00010
end_define

begin_comment
comment|/* append on each write */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FMARK
value|00020
end_define

begin_comment
comment|/* mark during gc() */
end_comment

begin_define
define|#
directive|define
name|FDEFER
value|00040
end_define

begin_comment
comment|/* defer for next gc pass */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|F_DUPFD
end_ifndef

begin_define
define|#
directive|define
name|FASYNC
value|00100
end_define

begin_comment
comment|/* signal pgrp when data ready */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FSHLOCK
value|00200
end_define

begin_comment
comment|/* shared lock present */
end_comment

begin_define
define|#
directive|define
name|FEXLOCK
value|00400
end_define

begin_comment
comment|/* exclusive lock present */
end_comment

begin_comment
comment|/* bits to save after open */
end_comment

begin_define
define|#
directive|define
name|FMASK
value|00113
end_define

begin_define
define|#
directive|define
name|FCNTLCANT
value|(FREAD|FWRITE|FMARK|FDEFER|FSHLOCK|FEXLOCK)
end_define

begin_comment
comment|/* open only modes */
end_comment

begin_define
define|#
directive|define
name|FCREAT
value|01000
end_define

begin_comment
comment|/* create if nonexistant */
end_comment

begin_define
define|#
directive|define
name|FTRUNC
value|02000
end_define

begin_comment
comment|/* truncate to zero length */
end_comment

begin_define
define|#
directive|define
name|FEXCL
value|04000
end_define

begin_comment
comment|/* error if already created */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|F_DUPFD
end_ifndef

begin_comment
comment|/* fcntl(2) requests--from<fcntl.h> */
end_comment

begin_define
define|#
directive|define
name|F_DUPFD
value|0
end_define

begin_comment
comment|/* Duplicate fildes */
end_comment

begin_define
define|#
directive|define
name|F_GETFD
value|1
end_define

begin_comment
comment|/* Get fildes flags */
end_comment

begin_define
define|#
directive|define
name|F_SETFD
value|2
end_define

begin_comment
comment|/* Set fildes flags */
end_comment

begin_define
define|#
directive|define
name|F_GETFL
value|3
end_define

begin_comment
comment|/* Get file flags */
end_comment

begin_define
define|#
directive|define
name|F_SETFL
value|4
end_define

begin_comment
comment|/* Set file flags */
end_comment

begin_define
define|#
directive|define
name|F_GETOWN
value|5
end_define

begin_comment
comment|/* Get owner */
end_comment

begin_define
define|#
directive|define
name|F_SETOWN
value|6
end_define

begin_comment
comment|/* Set owner */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * User definitions.  */
end_comment

begin_comment
comment|/*  * Open call.  */
end_comment

begin_define
define|#
directive|define
name|O_RDONLY
value|000
end_define

begin_comment
comment|/* open for reading */
end_comment

begin_define
define|#
directive|define
name|O_WRONLY
value|001
end_define

begin_comment
comment|/* open for writing */
end_comment

begin_define
define|#
directive|define
name|O_RDWR
value|002
end_define

begin_comment
comment|/* open for read& write */
end_comment

begin_define
define|#
directive|define
name|O_NDELAY
value|FNDELAY
end_define

begin_comment
comment|/* non-blocking open */
end_comment

begin_define
define|#
directive|define
name|O_APPEND
value|FAPPEND
end_define

begin_comment
comment|/* append on each write */
end_comment

begin_define
define|#
directive|define
name|O_CREAT
value|FCREAT
end_define

begin_comment
comment|/* open with file create */
end_comment

begin_define
define|#
directive|define
name|O_TRUNC
value|FTRUNC
end_define

begin_comment
comment|/* open with truncation */
end_comment

begin_define
define|#
directive|define
name|O_EXCL
value|FEXCL
end_define

begin_comment
comment|/* error on create if file exists */
end_comment

begin_comment
comment|/*  * Flock call.  */
end_comment

begin_define
define|#
directive|define
name|LOCK_SH
value|1
end_define

begin_comment
comment|/* shared lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_EX
value|2
end_define

begin_comment
comment|/* exclusive lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_NB
value|4
end_define

begin_comment
comment|/* don't block when locking */
end_comment

begin_define
define|#
directive|define
name|LOCK_UN
value|8
end_define

begin_comment
comment|/* unlock */
end_comment

begin_comment
comment|/*  * Access call.  */
end_comment

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_comment
comment|/* does file exist */
end_comment

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_comment
comment|/* is it executable by caller */
end_comment

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_comment
comment|/* writable by caller */
end_comment

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_comment
comment|/* readable by caller */
end_comment

begin_comment
comment|/*  * Lseek call.  */
end_comment

begin_define
define|#
directive|define
name|L_SET
value|0
end_define

begin_comment
comment|/* absolute offset */
end_comment

begin_define
define|#
directive|define
name|L_INCR
value|1
end_define

begin_comment
comment|/* relative to current offset */
end_comment

begin_define
define|#
directive|define
name|L_XTND
value|2
end_define

begin_comment
comment|/* relative to end of file */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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

begin_define
define|#
directive|define
name|DTYPE_INODE
value|1
end_define

begin_comment
comment|/* file */
end_comment

begin_define
define|#
directive|define
name|DTYPE_SOCKET
value|2
end_define

begin_comment
comment|/* communications endpoint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

