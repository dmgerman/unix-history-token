begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_FCNTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_FCNTL_H_
end_define

begin_include
include|#
directive|include
file|<svr4/svr4_types.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_define
define|#
directive|define
name|SVR4_O_RDONLY
value|0x0000
end_define

begin_define
define|#
directive|define
name|SVR4_O_WRONLY
value|0x0001
end_define

begin_define
define|#
directive|define
name|SVR4_O_RDWR
value|0x0002
end_define

begin_define
define|#
directive|define
name|SVR4_O_ACCMODE
value|0x0003
end_define

begin_define
define|#
directive|define
name|SVR4_O_NDELAY
value|0x0004
end_define

begin_define
define|#
directive|define
name|SVR4_O_APPEND
value|0x0008
end_define

begin_define
define|#
directive|define
name|SVR4_O_SYNC
value|0x0010
end_define

begin_define
define|#
directive|define
name|SVR4_O_NONBLOCK
value|0x0080
end_define

begin_define
define|#
directive|define
name|SVR4_O_CREAT
value|0x0100
end_define

begin_define
define|#
directive|define
name|SVR4_O_TRUNC
value|0x0200
end_define

begin_define
define|#
directive|define
name|SVR4_O_EXCL
value|0x0400
end_define

begin_define
define|#
directive|define
name|SVR4_O_NOCTTY
value|0x0800
end_define

begin_define
define|#
directive|define
name|SVR4_O_PRIV
value|0x1000
end_define

begin_define
define|#
directive|define
name|SVR4_FD_CLOEXEC
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_F_DUPFD
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_F_GETFD
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_F_SETFD
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_F_GETFL
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_F_SETFL
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_F_GETLK_SVR3
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_F_SETLK
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_F_SETLKW
value|7
end_define

begin_define
define|#
directive|define
name|SVR4_F_CHKFL
value|8
end_define

begin_define
define|#
directive|define
name|SVR4_F_DUP2FD
value|9
end_define

begin_define
define|#
directive|define
name|SVR4_F_ALLOCSP
value|10
end_define

begin_define
define|#
directive|define
name|SVR4_F_FREESP
value|11
end_define

begin_define
define|#
directive|define
name|SVR4_F_ISSTREAM
value|13
end_define

begin_define
define|#
directive|define
name|SVR4_F_GETLK
value|14
end_define

begin_define
define|#
directive|define
name|SVR4_F_PRIV
value|15
end_define

begin_define
define|#
directive|define
name|SVR4_F_NPRIV
value|16
end_define

begin_define
define|#
directive|define
name|SVR4_F_QUOTACTL
value|17
end_define

begin_define
define|#
directive|define
name|SVR4_F_BLOCKS
value|18
end_define

begin_define
define|#
directive|define
name|SVR4_F_BLKSIZE
value|19
end_define

begin_define
define|#
directive|define
name|SVR4_F_RSETLK
value|20
end_define

begin_define
define|#
directive|define
name|SVR4_F_RGETLK
value|21
end_define

begin_define
define|#
directive|define
name|SVR4_F_RSETLKW
value|22
end_define

begin_define
define|#
directive|define
name|SVR4_F_GETOWN
value|23
end_define

begin_define
define|#
directive|define
name|SVR4_F_SETOWN
value|24
end_define

begin_define
define|#
directive|define
name|SVR4_F_REVOKE
value|25
end_define

begin_define
define|#
directive|define
name|SVR4_F_HASREMOTELOCKS
value|26
end_define

begin_define
define|#
directive|define
name|SVR4_F_FREESP64
value|27
end_define

begin_define
define|#
directive|define
name|SVR4_F_GETLK64
value|33
end_define

begin_define
define|#
directive|define
name|SVR4_F_SETLK64
value|34
end_define

begin_define
define|#
directive|define
name|SVR4_F_SETLKW64
value|35
end_define

begin_define
define|#
directive|define
name|SVR4_F_SHARE
value|40
end_define

begin_define
define|#
directive|define
name|SVR4_F_UNSHARE
value|41
end_define

begin_define
define|#
directive|define
name|SVR4_F_CHSIZE_XENIX
value|0x6000
end_define

begin_define
define|#
directive|define
name|SVR4_F_RDCHK_XENIX
value|0x6001
end_define

begin_define
define|#
directive|define
name|SVR4_F_LK_UNLCK_XENIX
value|0x6300
end_define

begin_define
define|#
directive|define
name|SVR4_F_LK_LOCK_XENIX
value|0x7200
end_define

begin_define
define|#
directive|define
name|SVR4_F_LK_NBLCK_XENIX
value|0x6200
end_define

begin_define
define|#
directive|define
name|SVR4_F_LK_RLCK_XENIX
value|0x7100
end_define

begin_define
define|#
directive|define
name|SVR4_F_LK_NBRLCK_XENIX
value|0x6100
end_define

begin_define
define|#
directive|define
name|SVR4_LK_CMDTYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x7)
end_define

begin_define
define|#
directive|define
name|SVR4_LK_LCKTYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x7)
end_define

begin_define
define|#
directive|define
name|SVR4_F_RDLCK
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_F_WRLCK
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_F_UNLCK
value|3
end_define

begin_struct
struct|struct
name|svr4_flock_svr3
block|{
name|short
name|l_type
decl_stmt|;
name|short
name|l_whence
decl_stmt|;
name|svr4_off_t
name|l_start
decl_stmt|;
name|svr4_off_t
name|l_len
decl_stmt|;
name|short
name|l_sysid
decl_stmt|;
name|svr4_o_pid_t
name|l_pid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_flock
block|{
name|short
name|l_type
decl_stmt|;
name|short
name|l_whence
decl_stmt|;
name|svr4_off_t
name|l_start
decl_stmt|;
name|svr4_off_t
name|l_len
decl_stmt|;
name|long
name|l_sysid
decl_stmt|;
name|svr4_pid_t
name|l_pid
decl_stmt|;
name|long
name|pad
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_flock64
block|{
name|short
name|l_type
decl_stmt|;
name|short
name|l_whence
decl_stmt|;
name|svr4_off64_t
name|l_start
decl_stmt|;
name|svr4_off64_t
name|l_len
decl_stmt|;
name|long
name|l_sysid
decl_stmt|;
name|svr4_pid_t
name|l_pid
decl_stmt|;
name|long
name|pad
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_FCNTL_H_ */
end_comment

end_unit

