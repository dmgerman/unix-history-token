begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 - 2001, 2003 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
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

begin_define
define|#
directive|define
name|_AFSCIOCTL
parameter_list|(
name|id
parameter_list|)
value|((unsigned int ) _IOW('C', id, struct ViceIoctl))
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

begin_define
define|#
directive|define
name|VIOCGETTOK2
value|_AFSCIOCTL(7)
end_define

begin_define
define|#
directive|define
name|VIOCSETTOK2
value|_AFSCIOCTL(8)
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
name|unsigned
name|short
name|in_size
decl_stmt|;
name|unsigned
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

begin_comment
comment|/* Use k_hasafs() to probe if the machine supports AFS syscalls.    The other functions will generate a SIGSYS if AFS is not supported */
end_comment

begin_function_decl
name|int
name|k_hasafs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|k_hasafs_recheck
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb_afslog
parameter_list|(
specifier|const
name|char
modifier|*
name|cell
parameter_list|,
specifier|const
name|char
modifier|*
name|realm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb_afslog_uid
parameter_list|(
specifier|const
name|char
modifier|*
name|cell
parameter_list|,
specifier|const
name|char
modifier|*
name|realm
parameter_list|,
name|uid_t
name|uid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb_afslog_home
parameter_list|(
specifier|const
name|char
modifier|*
name|cell
parameter_list|,
specifier|const
name|char
modifier|*
name|realm
parameter_list|,
specifier|const
name|char
modifier|*
name|homedir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb_afslog_uid_home
parameter_list|(
specifier|const
name|char
modifier|*
name|cell
parameter_list|,
specifier|const
name|char
modifier|*
name|realm
parameter_list|,
name|uid_t
name|uid
parameter_list|,
specifier|const
name|char
modifier|*
name|homedir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb_realm_of_cell
parameter_list|(
specifier|const
name|char
modifier|*
name|cell
parameter_list|,
name|char
modifier|*
modifier|*
name|realm
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|int
name|k_pioctl
parameter_list|(
name|char
modifier|*
name|a_path
parameter_list|,
name|int
name|o_opcode
parameter_list|,
name|struct
name|ViceIoctl
modifier|*
name|a_paramsP
parameter_list|,
name|int
name|a_followSymlinks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|k_unlog
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|k_setpag
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|k_afs_cell_of_file
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|cell
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|void
name|kafs_set_verbose
parameter_list|(
name|void
function_decl|(
modifier|*
name|kafs_verbose
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kafs_settoken_rxkad
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|ClearToken
modifier|*
parameter_list|,
name|void
modifier|*
name|ticket
parameter_list|,
name|size_t
name|ticket_len
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KRB_H_INCLUDED
end_ifdef

begin_function_decl
name|int
name|kafs_settoken
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|CREDENTIALS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5_H_INCLUDED
end_ifdef

begin_function_decl
name|int
name|kafs_settoken5
parameter_list|(
name|krb5_context
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|krb5_creds
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5_H_INCLUDED
end_ifdef

begin_function_decl
name|krb5_error_code
name|krb5_afslog_uid
parameter_list|(
name|krb5_context
name|context
parameter_list|,
name|krb5_ccache
name|id
parameter_list|,
specifier|const
name|char
modifier|*
name|cell
parameter_list|,
name|krb5_const_realm
name|realm
parameter_list|,
name|uid_t
name|uid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|krb5_afslog
parameter_list|(
name|krb5_context
name|context
parameter_list|,
name|krb5_ccache
name|id
parameter_list|,
specifier|const
name|char
modifier|*
name|cell
parameter_list|,
name|krb5_const_realm
name|realm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|krb5_afslog_uid_home
parameter_list|(
name|krb5_context
name|context
parameter_list|,
name|krb5_ccache
name|id
parameter_list|,
specifier|const
name|char
modifier|*
name|cell
parameter_list|,
name|krb5_const_realm
name|realm
parameter_list|,
name|uid_t
name|uid
parameter_list|,
specifier|const
name|char
modifier|*
name|homedir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|krb5_afslog_home
parameter_list|(
name|krb5_context
name|context
parameter_list|,
name|krb5_ccache
name|id
parameter_list|,
specifier|const
name|char
modifier|*
name|cell
parameter_list|,
name|krb5_const_realm
name|realm
parameter_list|,
specifier|const
name|char
modifier|*
name|homedir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|krb5_realm_of_cell
parameter_list|(
specifier|const
name|char
modifier|*
name|cell
parameter_list|,
name|char
modifier|*
modifier|*
name|realm
parameter_list|)
function_decl|;
end_function_decl

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

begin_define
define|#
directive|define
name|_PATH_OPENAFS_DEBIAN_VICE
value|"/etc/openafs/"
end_define

begin_define
define|#
directive|define
name|_PATH_OPENAFS_DEBIAN_THISCELL
value|_PATH_OPENAFS_DEBIAN_VICE "ThisCell"
end_define

begin_define
define|#
directive|define
name|_PATH_OPENAFS_DEBIAN_CELLSERVDB
value|_PATH_OPENAFS_DEBIAN_VICE "CellServDB"
end_define

begin_define
define|#
directive|define
name|_PATH_OPENAFS_DEBIAN_THESECELLS
value|_PATH_OPENAFS_DEBIAN_VICE "TheseCells"
end_define

begin_define
define|#
directive|define
name|_PATH_OPENAFS_MACOSX_VICE
value|"/var/db/openafs/etc/"
end_define

begin_define
define|#
directive|define
name|_PATH_OPENAFS_MACOSX_THISCELL
value|_PATH_OPENAFS_MACOSX_VICE "ThisCell"
end_define

begin_define
define|#
directive|define
name|_PATH_OPENAFS_MACOSX_CELLSERVDB
value|_PATH_OPENAFS_MACOSX_VICE "CellServDB"
end_define

begin_define
define|#
directive|define
name|_PATH_OPENAFS_MACOSX_THESECELLS
value|_PATH_OPENAFS_MACOSX_VICE "TheseCells"
end_define

begin_define
define|#
directive|define
name|_PATH_ARLA_DEBIAN_VICE
value|"/etc/arla/"
end_define

begin_define
define|#
directive|define
name|_PATH_ARLA_DEBIAN_THISCELL
value|_PATH_ARLA_DEBIAN_VICE "ThisCell"
end_define

begin_define
define|#
directive|define
name|_PATH_ARLA_DEBIAN_CELLSERVDB
value|_PATH_ARLA_DEBIAN_VICE "CellServDB"
end_define

begin_define
define|#
directive|define
name|_PATH_ARLA_DEBIAN_THESECELLS
value|_PATH_ARLA_DEBIAN_VICE "TheseCells"
end_define

begin_define
define|#
directive|define
name|_PATH_ARLA_OPENBSD_VICE
value|"/etc/afs/"
end_define

begin_define
define|#
directive|define
name|_PATH_ARLA_OPENBSD_THISCELL
value|_PATH_ARLA_OPENBSD_VICE "ThisCell"
end_define

begin_define
define|#
directive|define
name|_PATH_ARLA_OPENBSD_CELLSERVDB
value|_PATH_ARLA_OPENBSD_VICE "CellServDB"
end_define

begin_define
define|#
directive|define
name|_PATH_ARLA_OPENBSD_THESECELLS
value|_PATH_ARLA_OPENBSD_VICE "TheseCells"
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

