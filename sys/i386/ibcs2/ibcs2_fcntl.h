begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ibcs2_fcntl.h,v 1.2 1994/10/26 02:52:54 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 Scott Bartram  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Scott Bartram.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBCS2_FCNTL_H
end_ifndef

begin_define
define|#
directive|define
name|_IBCS2_FCNTL_H
value|1
end_define

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_types.h>
end_include

begin_define
define|#
directive|define
name|IBCS2_O_RDONLY
value|0x0000
end_define

begin_define
define|#
directive|define
name|IBCS2_O_WRONLY
value|0x0001
end_define

begin_define
define|#
directive|define
name|IBCS2_O_RDWR
value|0x0002
end_define

begin_define
define|#
directive|define
name|IBCS2_O_NDELAY
value|0x0004
end_define

begin_define
define|#
directive|define
name|IBCS2_O_APPEND
value|0x0008
end_define

begin_define
define|#
directive|define
name|IBCS2_O_SYNC
value|0x0010
end_define

begin_define
define|#
directive|define
name|IBCS2_O_NONBLOCK
value|0x0080
end_define

begin_define
define|#
directive|define
name|IBCS2_O_CREAT
value|0x0100
end_define

begin_define
define|#
directive|define
name|IBCS2_O_TRUNC
value|0x0200
end_define

begin_define
define|#
directive|define
name|IBCS2_O_EXCL
value|0x0400
end_define

begin_define
define|#
directive|define
name|IBCS2_O_NOCTTY
value|0x0800
end_define

begin_define
define|#
directive|define
name|IBCS2_O_PRIV
value|0x1000
end_define

begin_define
define|#
directive|define
name|IBCS2_F_DUPFD
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_F_GETFD
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_F_SETFD
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_F_GETFL
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_F_SETFL
value|4
end_define

begin_define
define|#
directive|define
name|IBCS2_F_GETLK
value|5
end_define

begin_define
define|#
directive|define
name|IBCS2_F_SETLK
value|6
end_define

begin_define
define|#
directive|define
name|IBCS2_F_SETLKW
value|7
end_define

begin_struct
struct|struct
name|ibcs2_flock
block|{
name|short
name|l_type
decl_stmt|;
name|short
name|l_whence
decl_stmt|;
name|ibcs2_off_t
name|l_start
decl_stmt|;
name|ibcs2_off_t
name|l_len
decl_stmt|;
name|short
name|l_sysid
decl_stmt|;
name|ibcs2_pid_t
name|l_pid
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ibcs2_flock_len
value|(sizeof(struct ibcs2_flock))
end_define

begin_define
define|#
directive|define
name|IBCS2_F_RDLCK
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_F_WRLCK
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_F_UNLCK
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_O_ACCMODE
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_FD_CLOEXEC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IBCS2_FCNTL_H */
end_comment

end_unit

