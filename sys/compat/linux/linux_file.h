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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LINUX_FILE_H_ */
end_comment

end_unit

