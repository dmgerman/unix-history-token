begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SMB_H
end_ifndef

begin_define
define|#
directive|define
name|__SMB_H
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|smbcmd
block|{
name|char
name|cmd
decl_stmt|;
name|int
name|count
decl_stmt|;
name|u_char
name|slave
decl_stmt|;
union|union
block|{
name|char
name|byte
decl_stmt|;
name|short
name|word
decl_stmt|;
name|char
modifier|*
name|byte_ptr
decl_stmt|;
name|short
modifier|*
name|word_ptr
decl_stmt|;
struct|struct
block|{
name|short
name|sdata
decl_stmt|;
name|short
modifier|*
name|rdata
decl_stmt|;
block|}
name|process
struct|;
block|}
name|data
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SMB_QUICK_WRITE
value|_IOW('i', 1, struct smbcmd)
end_define

begin_define
define|#
directive|define
name|SMB_QUICK_READ
value|_IOW('i', 2, struct smbcmd)
end_define

begin_define
define|#
directive|define
name|SMB_SENDB
value|_IOW('i', 3, struct smbcmd)
end_define

begin_define
define|#
directive|define
name|SMB_RECVB
value|_IOW('i', 4, struct smbcmd)
end_define

begin_define
define|#
directive|define
name|SMB_WRITEB
value|_IOW('i', 5, struct smbcmd)
end_define

begin_define
define|#
directive|define
name|SMB_WRITEW
value|_IOW('i', 6, struct smbcmd)
end_define

begin_define
define|#
directive|define
name|SMB_READB
value|_IOW('i', 7, struct smbcmd)
end_define

begin_define
define|#
directive|define
name|SMB_READW
value|_IOW('i', 8, struct smbcmd)
end_define

begin_define
define|#
directive|define
name|SMB_PCALL
value|_IOW('i', 9, struct smbcmd)
end_define

begin_define
define|#
directive|define
name|SMB_BWRITE
value|_IOW('i', 10, struct smbcmd)
end_define

begin_define
define|#
directive|define
name|SMB_BREAD
value|_IOW('i', 11, struct smbcmd)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

