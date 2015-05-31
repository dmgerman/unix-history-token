begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Roman Divacky  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_FILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_FILE_H_
end_define

begin_define
define|#
directive|define
name|LINUX_AT_FDCWD
value|-100
end_define

begin_define
define|#
directive|define
name|LINUX_AT_SYMLINK_NOFOLLOW
value|0x100
end_define

begin_define
define|#
directive|define
name|LINUX_AT_EACCESS
value|0x200
end_define

begin_define
define|#
directive|define
name|LINUX_AT_REMOVEDIR
value|0x200
end_define

begin_define
define|#
directive|define
name|LINUX_AT_SYMLINK_FOLLOW
value|0x400
end_define

begin_comment
comment|/*  * posix_fadvise advice  */
end_comment

begin_define
define|#
directive|define
name|LINUX_POSIX_FADV_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_POSIX_FADV_RANDOM
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_POSIX_FADV_SEQUENTIAL
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_POSIX_FADV_WILLNEED
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_POSIX_FADV_DONTNEED
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_POSIX_FADV_NOREUSE
value|5
end_define

begin_comment
comment|/*  * mount flags  */
end_comment

begin_define
define|#
directive|define
name|LINUX_MS_RDONLY
value|0x0001
end_define

begin_define
define|#
directive|define
name|LINUX_MS_NOSUID
value|0x0002
end_define

begin_define
define|#
directive|define
name|LINUX_MS_NODEV
value|0x0004
end_define

begin_define
define|#
directive|define
name|LINUX_MS_NOEXEC
value|0x0008
end_define

begin_define
define|#
directive|define
name|LINUX_MS_REMOUNT
value|0x0020
end_define

begin_comment
comment|/*  * common open/fcntl flags  */
end_comment

begin_define
define|#
directive|define
name|LINUX_O_RDONLY
value|00000000
end_define

begin_define
define|#
directive|define
name|LINUX_O_WRONLY
value|00000001
end_define

begin_define
define|#
directive|define
name|LINUX_O_RDWR
value|00000002
end_define

begin_define
define|#
directive|define
name|LINUX_O_ACCMODE
value|00000003
end_define

begin_define
define|#
directive|define
name|LINUX_O_CREAT
value|00000100
end_define

begin_define
define|#
directive|define
name|LINUX_O_EXCL
value|00000200
end_define

begin_define
define|#
directive|define
name|LINUX_O_NOCTTY
value|00000400
end_define

begin_define
define|#
directive|define
name|LINUX_O_TRUNC
value|00001000
end_define

begin_define
define|#
directive|define
name|LINUX_O_APPEND
value|00002000
end_define

begin_define
define|#
directive|define
name|LINUX_O_NONBLOCK
value|00004000
end_define

begin_define
define|#
directive|define
name|LINUX_O_NDELAY
value|LINUX_O_NONBLOCK
end_define

begin_define
define|#
directive|define
name|LINUX_O_SYNC
value|00010000
end_define

begin_define
define|#
directive|define
name|LINUX_FASYNC
value|00020000
end_define

begin_define
define|#
directive|define
name|LINUX_O_DIRECT
value|00040000
end_define

begin_comment
comment|/* Direct disk access hint */
end_comment

begin_define
define|#
directive|define
name|LINUX_O_LARGEFILE
value|00100000
end_define

begin_define
define|#
directive|define
name|LINUX_O_DIRECTORY
value|00200000
end_define

begin_comment
comment|/* Must be a directory */
end_comment

begin_define
define|#
directive|define
name|LINUX_O_NOFOLLOW
value|00400000
end_define

begin_comment
comment|/* Do not follow links */
end_comment

begin_define
define|#
directive|define
name|LINUX_O_NOATIME
value|01000000
end_define

begin_define
define|#
directive|define
name|LINUX_O_CLOEXEC
value|02000000
end_define

begin_define
define|#
directive|define
name|LINUX_F_DUPFD
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETFD
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETFD
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETFL
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETFL
value|4
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_F_GETLK
end_ifndef

begin_define
define|#
directive|define
name|LINUX_F_GETLK
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETLK
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETLKW
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_F_SETOWN
end_ifndef

begin_define
define|#
directive|define
name|LINUX_F_SETOWN
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETOWN
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_F_SETSIG
end_ifndef

begin_define
define|#
directive|define
name|LINUX_F_SETSIG
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETSIG
value|11
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_F_SETOWN_EX
end_ifndef

begin_define
define|#
directive|define
name|LINUX_F_SETOWN_EX
value|15
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETOWN_EX
value|16
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETOWNER_UIDS
value|17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINUX_F_SPECIFIC_BASE
value|1024
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETLEASE
value|(LINUX_F_SPECIFIC_BASE + 0)
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETLEASE
value|(LINUX_F_SPECIFIC_BASE + 1)
end_define

begin_define
define|#
directive|define
name|LINUX_F_CANCELLK
value|(LINUX_F_SPECIFIC_BASE + 5)
end_define

begin_define
define|#
directive|define
name|LINUX_F_DUPFD_CLOEXEC
value|(LINUX_F_SPECIFIC_BASE + 6)
end_define

begin_define
define|#
directive|define
name|LINUX_F_NOTIFY
value|(LINUX_F_SPECIFIC_BASE + 2)
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETPIPE_SZ
value|(LINUX_F_SPECIFIC_BASE + 7)
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETPIPE_SZ
value|(LINUX_F_SPECIFIC_BASE + 8)
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETLKP
value|36
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETLKP
value|37
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETLKPW
value|38
end_define

begin_define
define|#
directive|define
name|LINUX_F_OWNER_TID
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_F_OWNER_PID
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_F_OWNER_PGRP
value|2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_F_RDLCK
end_ifndef

begin_define
define|#
directive|define
name|LINUX_F_RDLCK
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_F_WRLCK
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_F_UNLCK
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LINUX_FILE_H_ */
end_comment

end_unit

