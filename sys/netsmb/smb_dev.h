begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETSMB_DEV_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETSMB_DEV_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<netsmb/smb.h>
end_include

begin_define
define|#
directive|define
name|NSMB_NAME
value|"nsmb"
end_define

begin_define
define|#
directive|define
name|NSMB_MAJOR
value|144
end_define

begin_define
define|#
directive|define
name|NSMB_VERMAJ
value|1
end_define

begin_define
define|#
directive|define
name|NSMB_VERMIN
value|3006
end_define

begin_define
define|#
directive|define
name|NSMB_VERSION
value|(NSMB_VERMAJ * 100000 + NSMB_VERMIN)
end_define

begin_define
define|#
directive|define
name|NSMBFL_OPEN
value|0x0001
end_define

begin_define
define|#
directive|define
name|SMBVOPT_CREATE
value|0x0001
end_define

begin_comment
comment|/* create object if necessary */
end_comment

begin_define
define|#
directive|define
name|SMBVOPT_PRIVATE
value|0x0002
end_define

begin_comment
comment|/* connection should be private */
end_comment

begin_define
define|#
directive|define
name|SMBVOPT_SINGLESHARE
value|0x0004
end_define

begin_comment
comment|/* keep only one share at this VC */
end_comment

begin_define
define|#
directive|define
name|SMBVOPT_PERMANENT
value|0x0010
end_define

begin_comment
comment|/* object will keep last reference */
end_comment

begin_define
define|#
directive|define
name|SMBSOPT_CREATE
value|0x0001
end_define

begin_comment
comment|/* create object if necessary */
end_comment

begin_define
define|#
directive|define
name|SMBSOPT_PERMANENT
value|0x0010
end_define

begin_comment
comment|/* object will keep last reference */
end_comment

begin_comment
comment|/*  * SMBIOC_LOOKUP flags  */
end_comment

begin_define
define|#
directive|define
name|SMBLK_CREATE
value|0x0001
end_define

begin_struct
struct|struct
name|smbioc_ossn
block|{
name|int
name|ioc_opt
decl_stmt|;
name|int
name|ioc_svlen
decl_stmt|;
comment|/* size of ioc_server address */
name|struct
name|sockaddr
modifier|*
name|ioc_server
decl_stmt|;
name|int
name|ioc_lolen
decl_stmt|;
comment|/* size of ioc_local address */
name|struct
name|sockaddr
modifier|*
name|ioc_local
decl_stmt|;
name|char
name|ioc_srvname
index|[
name|SMB_MAXSRVNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|ioc_timeout
decl_stmt|;
name|int
name|ioc_retrycount
decl_stmt|;
comment|/* number of retries before giveup */
name|char
name|ioc_localcs
index|[
literal|16
index|]
decl_stmt|;
comment|/* local charset */
name|char
name|ioc_servercs
index|[
literal|16
index|]
decl_stmt|;
comment|/* server charset */
name|char
name|ioc_user
index|[
name|SMB_MAXUSERNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|ioc_workgroup
index|[
name|SMB_MAXUSERNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|ioc_password
index|[
name|SMB_MAXPASSWORDLEN
operator|+
literal|1
index|]
decl_stmt|;
name|uid_t
name|ioc_owner
decl_stmt|;
comment|/* proposed owner */
name|gid_t
name|ioc_group
decl_stmt|;
comment|/* proposed group */
name|mode_t
name|ioc_mode
decl_stmt|;
comment|/* desired access mode */
name|mode_t
name|ioc_rights
decl_stmt|;
comment|/* SMBM_* */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|smbioc_oshare
block|{
name|int
name|ioc_opt
decl_stmt|;
name|int
name|ioc_stype
decl_stmt|;
comment|/* share type */
name|char
name|ioc_share
index|[
name|SMB_MAXSHARENAMELEN
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|ioc_password
index|[
name|SMB_MAXPASSWORDLEN
operator|+
literal|1
index|]
decl_stmt|;
name|uid_t
name|ioc_owner
decl_stmt|;
comment|/* proposed owner of share */
name|gid_t
name|ioc_group
decl_stmt|;
comment|/* proposed group of share */
name|mode_t
name|ioc_mode
decl_stmt|;
comment|/* desired access mode to share */
name|mode_t
name|ioc_rights
decl_stmt|;
comment|/* SMBM_* */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|smbioc_rq
block|{
name|u_char
name|ioc_cmd
decl_stmt|;
name|u_char
name|ioc_twc
decl_stmt|;
name|void
modifier|*
name|ioc_twords
decl_stmt|;
name|u_short
name|ioc_tbc
decl_stmt|;
name|void
modifier|*
name|ioc_tbytes
decl_stmt|;
name|int
name|ioc_rpbufsz
decl_stmt|;
name|char
modifier|*
name|ioc_rpbuf
decl_stmt|;
name|u_char
name|ioc_rwc
decl_stmt|;
name|u_short
name|ioc_rbc
decl_stmt|;
name|u_int8_t
name|ioc_errclass
decl_stmt|;
name|u_int16_t
name|ioc_serror
decl_stmt|;
name|u_int32_t
name|ioc_error
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|smbioc_t2rq
block|{
name|u_int16_t
name|ioc_setup
index|[
literal|3
index|]
decl_stmt|;
name|int
name|ioc_setupcnt
decl_stmt|;
name|char
modifier|*
name|ioc_name
decl_stmt|;
name|u_short
name|ioc_tparamcnt
decl_stmt|;
name|void
modifier|*
name|ioc_tparam
decl_stmt|;
name|u_short
name|ioc_tdatacnt
decl_stmt|;
name|void
modifier|*
name|ioc_tdata
decl_stmt|;
name|u_short
name|ioc_rparamcnt
decl_stmt|;
name|void
modifier|*
name|ioc_rparam
decl_stmt|;
name|u_short
name|ioc_rdatacnt
decl_stmt|;
name|void
modifier|*
name|ioc_rdata
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|smbioc_flags
block|{
name|int
name|ioc_level
decl_stmt|;
comment|/* 0 - session, 1 - share */
name|int
name|ioc_mask
decl_stmt|;
name|int
name|ioc_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|smbioc_lookup
block|{
name|int
name|ioc_level
decl_stmt|;
name|int
name|ioc_flags
decl_stmt|;
name|struct
name|smbioc_ossn
name|ioc_ssn
decl_stmt|;
name|struct
name|smbioc_oshare
name|ioc_sh
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|smbioc_rw
block|{
name|smbfh
name|ioc_fh
decl_stmt|;
name|char
modifier|*
name|ioc_base
decl_stmt|;
name|off_t
name|ioc_offset
decl_stmt|;
name|int
name|ioc_cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Device IOCTLs  */
end_comment

begin_define
define|#
directive|define
name|SMBIOC_OPENSESSION
value|_IOW('n',  100, struct smbioc_ossn)
end_define

begin_define
define|#
directive|define
name|SMBIOC_OPENSHARE
value|_IOW('n',  101, struct smbioc_oshare)
end_define

begin_define
define|#
directive|define
name|SMBIOC_REQUEST
value|_IOWR('n', 102, struct smbioc_rq)
end_define

begin_define
define|#
directive|define
name|SMBIOC_T2RQ
value|_IOWR('n', 103, struct smbioc_t2rq)
end_define

begin_define
define|#
directive|define
name|SMBIOC_SETFLAGS
value|_IOW('n',  104, struct smbioc_flags)
end_define

begin_define
define|#
directive|define
name|SMBIOC_LOOKUP
value|_IOW('n',  106, struct smbioc_lookup)
end_define

begin_define
define|#
directive|define
name|SMBIOC_READ
value|_IOWR('n', 107, struct smbioc_rw)
end_define

begin_define
define|#
directive|define
name|SMBIOC_WRITE
value|_IOWR('n', 108, struct smbioc_rw)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|SMBST_CONNECTED
value|1
end_define

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|smbrqh
argument_list|,
name|smb_rq
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|smb_dev
block|{
name|int
name|sd_opened
decl_stmt|;
name|int
name|sd_level
decl_stmt|;
name|struct
name|smb_vc
modifier|*
name|sd_vc
decl_stmt|;
comment|/* reference to VC */
name|struct
name|smb_share
modifier|*
name|sd_share
decl_stmt|;
comment|/* reference to share if any */
name|int
name|sd_poll
decl_stmt|;
name|int
name|sd_seq
decl_stmt|;
comment|/*	struct ifqueue	sd_rdqueue; 	struct ifqueue	sd_wrqueue; 	struct selinfo	sd_pollinfo; 	struct smbrqh	sd_rqlist; 	struct smbrqh	sd_rplist; 	struct ucred 	*sd_owner;*/
name|int
name|sd_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|smb_cred
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Compound user interface  */
end_comment

begin_function_decl
name|int
name|smb_usr_lookup
parameter_list|(
name|struct
name|smbioc_lookup
modifier|*
name|dp
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|,
name|struct
name|smb_vc
modifier|*
modifier|*
name|vcpp
parameter_list|,
name|struct
name|smb_share
modifier|*
modifier|*
name|sspp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_usr_opensession
parameter_list|(
name|struct
name|smbioc_ossn
modifier|*
name|data
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|,
name|struct
name|smb_vc
modifier|*
modifier|*
name|vcpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_usr_openshare
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|,
name|struct
name|smbioc_oshare
modifier|*
name|data
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|,
name|struct
name|smb_share
modifier|*
modifier|*
name|sspp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_usr_simplerequest
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
parameter_list|,
name|struct
name|smbioc_rq
modifier|*
name|data
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_usr_t2request
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
parameter_list|,
name|struct
name|smbioc_t2rq
modifier|*
name|data
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_dev2share
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|,
name|struct
name|smb_share
modifier|*
modifier|*
name|sspp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETSMB_DEV_H_ */
end_comment

end_unit

