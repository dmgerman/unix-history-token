begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the Kungliga Tekniska  *      Högskolan and its contributors.  *   * 4. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: kafs.h,v 1.19 1997/05/14 17:41:02 joda Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KAFS_H
end_ifndef

begin_define
define|#
directive|define
name|__KAFS_H
end_define

begin_include
include|#
directive|include
file|<ktypes.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* sys/ioctl.h must be included manually before kafs.h */
end_comment

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|AFSCALL_PIOCTL
value|20
end_define

begin_define
define|#
directive|define
name|AFSCALL_SETPAG
value|21
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_VICEIOCTL
end_ifndef

begin_define
define|#
directive|define
name|_VICEIOCTL
parameter_list|(
name|id
parameter_list|)
value|((unsigned int ) _IOW('V', id, struct ViceIoctl))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VICEIOCTL */
end_comment

begin_define
define|#
directive|define
name|VIOCSETTOK
value|_VICEIOCTL(3)
end_define

begin_define
define|#
directive|define
name|VIOCGETTOK
value|_VICEIOCTL(8)
end_define

begin_define
define|#
directive|define
name|VIOCUNLOG
value|_VICEIOCTL(9)
end_define

begin_define
define|#
directive|define
name|VIOC_FILE_CELL_NAME
value|_VICEIOCTL(30)
end_define

begin_struct
struct|struct
name|ViceIoctl
block|{
name|caddr_t
name|in
decl_stmt|,
name|out
decl_stmt|;
name|short
name|in_size
decl_stmt|;
name|short
name|out_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ClearToken
block|{
name|int32_t
name|AuthHandle
decl_stmt|;
name|char
name|HandShakeKey
index|[
literal|8
index|]
decl_stmt|;
name|int32_t
name|ViceId
decl_stmt|;
name|int32_t
name|BeginTimestamp
decl_stmt|;
name|int32_t
name|EndTimestamp
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use k_hasafs() to probe if the machine supports AFS syscalls.    The other functions will generate a SIGSYS if AFS is not supported */
end_comment

begin_decl_stmt
name|int
name|k_hasafs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_afsklog
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|cell
operator|,
specifier|const
name|char
operator|*
name|realm
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_afsklog_uid
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|cell
operator|,
specifier|const
name|char
operator|*
name|realm
operator|,
name|uid_t
name|uid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_pioctl
name|__P
argument_list|(
operator|(
name|char
operator|*
name|a_path
operator|,
name|int
name|o_opcode
operator|,
expr|struct
name|ViceIoctl
operator|*
name|a_paramsP
operator|,
name|int
name|a_followSymlinks
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_unlog
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_setpag
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_afs_cell_of_file
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|path
operator|,
name|char
operator|*
name|cell
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_PATH_VICE
value|"/usr/vice/etc/"
end_define

begin_define
define|#
directive|define
name|_PATH_THISCELL
value|_PATH_VICE "ThisCell"
end_define

begin_define
define|#
directive|define
name|_PATH_CELLSERVDB
value|_PATH_VICE "CellServDB"
end_define

begin_define
define|#
directive|define
name|_PATH_THESECELLS
value|_PATH_VICE "TheseCells"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KAFS_H */
end_comment

end_unit

