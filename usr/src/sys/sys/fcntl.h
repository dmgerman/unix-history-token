begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)fcntl.h	5.5 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|F_DUPFD
end_ifndef

begin_comment
comment|/* command values for fcntl(2) */
end_comment

begin_define
define|#
directive|define
name|F_DUPFD
value|0
end_define

begin_comment
comment|/* duplicate file descriptor */
end_comment

begin_define
define|#
directive|define
name|F_GETFD
value|1
end_define

begin_comment
comment|/* get file descriptor flags */
end_comment

begin_define
define|#
directive|define
name|F_SETFD
value|2
end_define

begin_comment
comment|/* set file descriptor flags */
end_comment

begin_define
define|#
directive|define
name|F_GETFL
value|3
end_define

begin_comment
comment|/* get file status flags */
end_comment

begin_define
define|#
directive|define
name|F_SETFL
value|4
end_define

begin_comment
comment|/* set file status flags */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|F_GETOWN
value|5
end_define

begin_comment
comment|/* get SIGIO/SIGURG proc/pgrp */
end_comment

begin_define
define|#
directive|define
name|F_SETOWN
value|6
end_define

begin_comment
comment|/* set SIGIO/SIGURG proc/pgrp */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|F_GETLK
value|7
end_define

begin_comment
comment|/* get record locking information */
end_comment

begin_define
define|#
directive|define
name|F_SETLK
value|8
end_define

begin_comment
comment|/* set record locking information */
end_comment

begin_define
define|#
directive|define
name|F_SETLKW
value|9
end_define

begin_comment
comment|/* F_SETLK; wait if blocked */
end_comment

begin_comment
comment|/* file descriptor flags (F_GETFD, F_SETFD) */
end_comment

begin_define
define|#
directive|define
name|FD_CLOEXEC
value|1
end_define

begin_comment
comment|/* close-on-exec flag */
end_comment

begin_comment
comment|/* record locking flags (F_GETLK, F_SETLK, F_SETLKW) */
end_comment

begin_define
define|#
directive|define
name|F_RDLCK
value|1
end_define

begin_comment
comment|/* shared or read lock */
end_comment

begin_define
define|#
directive|define
name|F_UNLCK
value|2
end_define

begin_comment
comment|/* unlock */
end_comment

begin_define
define|#
directive|define
name|F_WRLCK
value|3
end_define

begin_comment
comment|/* exclusive or write lock */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_comment
comment|/* lock operations for flock(2) */
end_comment

begin_define
define|#
directive|define
name|LOCK_SH
value|0x01
end_define

begin_comment
comment|/* shared file lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_EX
value|0x02
end_define

begin_comment
comment|/* exclusive file lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_NB
value|0x04
end_define

begin_comment
comment|/* don't block when locking */
end_comment

begin_define
define|#
directive|define
name|LOCK_UN
value|0x08
end_define

begin_comment
comment|/* unlock file */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* file status flags */
end_comment

begin_define
define|#
directive|define
name|O_RDONLY
value|00000
end_define

begin_comment
comment|/* open for reading only */
end_comment

begin_define
define|#
directive|define
name|O_WRONLY
value|00001
end_define

begin_comment
comment|/* open for writing only */
end_comment

begin_define
define|#
directive|define
name|O_RDWR
value|00002
end_define

begin_comment
comment|/* open for reading and writing */
end_comment

begin_define
define|#
directive|define
name|O_NONBLOCK
value|00004
end_define

begin_comment
comment|/* no delay */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|O_NDELAY
value|O_NONBLOCK
end_define

begin_define
define|#
directive|define
name|FNDELAY
value|O_NONBLOCK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*			00008		/* unused */
end_comment

begin_define
define|#
directive|define
name|O_APPEND
value|00010
end_define

begin_comment
comment|/* set append mode */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|FAPPEND
value|O_APPEND
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* kernel placeholders */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|&&
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|O_MARK
value|00020
end_define

begin_comment
comment|/* mark during gc() */
end_comment

begin_define
define|#
directive|define
name|O_DEFER
value|00040
end_define

begin_comment
comment|/* defer for next gc pass */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*			00080		/* unused */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|O_ASYNC
value|00100
end_define

begin_comment
comment|/* signal pgrp when data ready */
end_comment

begin_define
define|#
directive|define
name|FASYNC
value|O_ASYNC
end_define

begin_define
define|#
directive|define
name|O_SHLOCK
value|00200
end_define

begin_comment
comment|/* shared file lock present */
end_comment

begin_define
define|#
directive|define
name|O_EXLOCK
value|00400
end_define

begin_comment
comment|/* exclusive file lock present */
end_comment

begin_comment
comment|/*			00800		/* unused */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|O_CREAT
value|01000
end_define

begin_comment
comment|/* create if nonexistant */
end_comment

begin_define
define|#
directive|define
name|O_TRUNC
value|02000
end_define

begin_comment
comment|/* truncate to zero length */
end_comment

begin_define
define|#
directive|define
name|O_EXCL
value|04000
end_define

begin_comment
comment|/* error if already exists */
end_comment

begin_comment
comment|/*			08000		/* unused */
end_comment

begin_comment
comment|/* defined by POSIX 1003.1; BSD default, so no bit required */
end_comment

begin_define
define|#
directive|define
name|O_NOCTTY
value|0
end_define

begin_comment
comment|/* don't assign controlling terminal */
end_comment

begin_comment
comment|/* mask for file access modes */
end_comment

begin_define
define|#
directive|define
name|O_ACCMODE
value|(O_RDONLY|O_WRONLY|O_RDWR)
end_define

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

begin_function_decl
specifier|extern
name|int
name|fcntl
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|creat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|int
name|fcntl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|creat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|open
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !F_DUPFD */
end_comment

end_unit

