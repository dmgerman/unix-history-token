begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997, 1998, 1999 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: kafs.h,v 1.32 1999/12/02 16:58:40 joda Exp $ */
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

begin_comment
comment|/* XXX must include krb5.h or krb.h */
end_comment

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
name|VIOCSETAL
value|_VICEIOCTL(1)
end_define

begin_define
define|#
directive|define
name|VIOCGETAL
value|_VICEIOCTL(2)
end_define

begin_define
define|#
directive|define
name|VIOCSETTOK
value|_VICEIOCTL(3)
end_define

begin_define
define|#
directive|define
name|VIOCGETVOLSTAT
value|_VICEIOCTL(4)
end_define

begin_define
define|#
directive|define
name|VIOCSETVOLSTAT
value|_VICEIOCTL(5)
end_define

begin_define
define|#
directive|define
name|VIOCFLUSH
value|_VICEIOCTL(6)
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
name|VIOCCKSERV
value|_VICEIOCTL(10)
end_define

begin_define
define|#
directive|define
name|VIOCCKBACK
value|_VICEIOCTL(11)
end_define

begin_define
define|#
directive|define
name|VIOCCKCONN
value|_VICEIOCTL(12)
end_define

begin_define
define|#
directive|define
name|VIOCWHEREIS
value|_VICEIOCTL(14)
end_define

begin_define
define|#
directive|define
name|VIOCACCESS
value|_VICEIOCTL(20)
end_define

begin_define
define|#
directive|define
name|VIOCUNPAG
value|_VICEIOCTL(21)
end_define

begin_define
define|#
directive|define
name|VIOCGETFID
value|_VICEIOCTL(22)
end_define

begin_define
define|#
directive|define
name|VIOCSETCACHESIZE
value|_VICEIOCTL(24)
end_define

begin_define
define|#
directive|define
name|VIOCFLUSHCB
value|_VICEIOCTL(25)
end_define

begin_define
define|#
directive|define
name|VIOCNEWCELL
value|_VICEIOCTL(26)
end_define

begin_define
define|#
directive|define
name|VIOCGETCELL
value|_VICEIOCTL(27)
end_define

begin_define
define|#
directive|define
name|VIOC_AFS_DELETE_MT_PT
value|_VICEIOCTL(28)
end_define

begin_define
define|#
directive|define
name|VIOC_AFS_STAT_MT_PT
value|_VICEIOCTL(29)
end_define

begin_define
define|#
directive|define
name|VIOC_FILE_CELL_NAME
value|_VICEIOCTL(30)
end_define

begin_define
define|#
directive|define
name|VIOC_GET_WS_CELL
value|_VICEIOCTL(31)
end_define

begin_define
define|#
directive|define
name|VIOC_AFS_MARINER_HOST
value|_VICEIOCTL(32)
end_define

begin_define
define|#
directive|define
name|VIOC_GET_PRIMARY_CELL
value|_VICEIOCTL(33)
end_define

begin_define
define|#
directive|define
name|VIOC_VENUSLOG
value|_VICEIOCTL(34)
end_define

begin_define
define|#
directive|define
name|VIOC_GETCELLSTATUS
value|_VICEIOCTL(35)
end_define

begin_define
define|#
directive|define
name|VIOC_SETCELLSTATUS
value|_VICEIOCTL(36)
end_define

begin_define
define|#
directive|define
name|VIOC_FLUSHVOLUME
value|_VICEIOCTL(37)
end_define

begin_define
define|#
directive|define
name|VIOC_AFS_SYSNAME
value|_VICEIOCTL(38)
end_define

begin_define
define|#
directive|define
name|VIOC_EXPORTAFS
value|_VICEIOCTL(39)
end_define

begin_define
define|#
directive|define
name|VIOCGETCACHEPARAMS
value|_VICEIOCTL(40)
end_define

begin_define
define|#
directive|define
name|VIOC_GCPAGS
value|_VICEIOCTL(48)
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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

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

begin_else
else|#
directive|else
end_else

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
value|()
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
name|krb_afslog
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
name|krb_afslog_uid
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
name|krb_afslog_home
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
specifier|const
name|char
operator|*
name|homedir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_afslog_uid_home
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
operator|,
specifier|const
name|char
operator|*
name|homedir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_realm_of_cell
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|cell
operator|,
name|char
operator|*
operator|*
name|realm
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* compat */
end_comment

begin_define
define|#
directive|define
name|k_afsklog
value|krb_afslog
end_define

begin_define
define|#
directive|define
name|k_afsklog_uid
value|krb_afslog_uid
end_define

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

begin_comment
comment|/* XXX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KFAILURE
end_ifdef

begin_define
define|#
directive|define
name|KRB_H_INCLUDED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5_RECVAUTH_IGNORE_VERSION
end_ifdef

begin_define
define|#
directive|define
name|KRB5_H_INCLUDED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KRB_H_INCLUDED
end_ifdef

begin_decl_stmt
name|int
name|kafs_settoken
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|uid_t
operator|,
name|CREDENTIALS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5_H_INCLUDED
end_ifdef

begin_decl_stmt
name|krb5_error_code
name|krb5_afslog_uid
name|__P
argument_list|(
operator|(
name|krb5_context
name|context
operator|,
name|krb5_ccache
name|id
operator|,
specifier|const
name|char
operator|*
name|cell
operator|,
name|krb5_const_realm
name|realm
operator|,
name|uid_t
name|uid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|krb5_error_code
name|krb5_afslog
name|__P
argument_list|(
operator|(
name|krb5_context
name|context
operator|,
name|krb5_ccache
name|id
operator|,
specifier|const
name|char
operator|*
name|cell
operator|,
name|krb5_const_realm
name|realm
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|krb5_error_code
name|krb5_afslog_uid_home
name|__P
argument_list|(
operator|(
name|krb5_context
name|context
operator|,
name|krb5_ccache
name|id
operator|,
specifier|const
name|char
operator|*
name|cell
operator|,
name|krb5_const_realm
name|realm
operator|,
name|uid_t
name|uid
operator|,
specifier|const
name|char
operator|*
name|homedir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|krb5_error_code
name|krb5_afslog_home
name|__P
argument_list|(
operator|(
name|krb5_context
name|context
operator|,
name|krb5_ccache
name|id
operator|,
specifier|const
name|char
operator|*
name|cell
operator|,
name|krb5_const_realm
name|realm
operator|,
specifier|const
name|char
operator|*
name|homedir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|krb5_error_code
name|krb5_realm_of_cell
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|cell
operator|,
name|char
operator|*
operator|*
name|realm
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|_PATH_ARLA_VICE
value|"/usr/arla/etc/"
end_define

begin_define
define|#
directive|define
name|_PATH_ARLA_THISCELL
value|_PATH_ARLA_VICE "ThisCell"
end_define

begin_define
define|#
directive|define
name|_PATH_ARLA_CELLSERVDB
value|_PATH_ARLA_VICE "CellServDB"
end_define

begin_define
define|#
directive|define
name|_PATH_ARLA_THESECELLS
value|_PATH_ARLA_VICE "TheseCells"
end_define

begin_decl_stmt
specifier|extern
name|int
name|_kafs_debug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KAFS_H */
end_comment

end_unit

