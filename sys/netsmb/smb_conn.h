begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_H_
end_ifndef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Two levels of connection hierarchy  */
end_comment

begin_define
define|#
directive|define
name|SMBL_SM
value|0
end_define

begin_define
define|#
directive|define
name|SMBL_VC
value|1
end_define

begin_define
define|#
directive|define
name|SMBL_SHARE
value|2
end_define

begin_define
define|#
directive|define
name|SMBL_NUM
value|3
end_define

begin_define
define|#
directive|define
name|SMBL_NONE
value|(-1)
end_define

begin_define
define|#
directive|define
name|SMB_CS_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|SMB_CS_UPPER
value|0x0001
end_define

begin_comment
comment|/* convert passed string to upper case */
end_comment

begin_define
define|#
directive|define
name|SMB_CS_LOWER
value|0x0002
end_define

begin_comment
comment|/* convert passed string to lower case */
end_comment

begin_comment
comment|/*  * Common object flags  */
end_comment

begin_define
define|#
directive|define
name|SMBO_GONE
value|0x1000000
end_define

begin_comment
comment|/*  * access modes  */
end_comment

begin_define
define|#
directive|define
name|SMBM_READ
value|0400
end_define

begin_comment
comment|/* read conn attrs.(like list shares) */
end_comment

begin_define
define|#
directive|define
name|SMBM_WRITE
value|0200
end_define

begin_comment
comment|/* modify conn attrs */
end_comment

begin_define
define|#
directive|define
name|SMBM_EXEC
value|0100
end_define

begin_comment
comment|/* can send SMB requests */
end_comment

begin_define
define|#
directive|define
name|SMBM_READGRP
value|0040
end_define

begin_define
define|#
directive|define
name|SMBM_WRITEGRP
value|0020
end_define

begin_define
define|#
directive|define
name|SMBM_EXECGRP
value|0010
end_define

begin_define
define|#
directive|define
name|SMBM_READOTH
value|0004
end_define

begin_define
define|#
directive|define
name|SMBM_WRITEOTH
value|0002
end_define

begin_define
define|#
directive|define
name|SMBM_EXECOTH
value|0001
end_define

begin_define
define|#
directive|define
name|SMBM_MASK
value|0777
end_define

begin_define
define|#
directive|define
name|SMBM_EXACT
value|010000
end_define

begin_comment
comment|/* check for specified mode exactly */
end_comment

begin_define
define|#
directive|define
name|SMBM_ALL
value|(SMBM_READ | SMBM_WRITE | SMBM_EXEC)
end_define

begin_define
define|#
directive|define
name|SMBM_DEFAULT
value|(SMBM_READ | SMBM_WRITE | SMBM_EXEC)
end_define

begin_define
define|#
directive|define
name|SMBM_ANY_OWNER
value|((uid_t)-1)
end_define

begin_define
define|#
directive|define
name|SMBM_ANY_GROUP
value|((gid_t)-1)
end_define

begin_comment
comment|/*  * VC flags  */
end_comment

begin_define
define|#
directive|define
name|SMBV_PERMANENT
value|0x0002
end_define

begin_define
define|#
directive|define
name|SMBV_LONGNAMES
value|0x0004
end_define

begin_comment
comment|/* connection is configured to use long names */
end_comment

begin_define
define|#
directive|define
name|SMBV_ENCRYPT
value|0x0008
end_define

begin_comment
comment|/* server asked for encrypted password */
end_comment

begin_define
define|#
directive|define
name|SMBV_WIN95
value|0x0010
end_define

begin_comment
comment|/* used to apply bugfixes for this OS */
end_comment

begin_define
define|#
directive|define
name|SMBV_PRIVATE
value|0x0020
end_define

begin_comment
comment|/* connection can be used only by creator */
end_comment

begin_define
define|#
directive|define
name|SMBV_RECONNECTING
value|0x0040
end_define

begin_comment
comment|/* conn is in the process of reconnection */
end_comment

begin_define
define|#
directive|define
name|SMBV_SINGLESHARE
value|0x0080
end_define

begin_comment
comment|/* only one share connectin should be allowed */
end_comment

begin_define
define|#
directive|define
name|SMBV_CREATE
value|0x0100
end_define

begin_comment
comment|/* lookup for create opeartion */
end_comment

begin_comment
comment|/*#define SMBV_FAILED		0x0200*/
end_comment

begin_comment
comment|/* last reconnect attempt has failed */
end_comment

begin_define
define|#
directive|define
name|SMBV_UNICODE
value|0x0400
end_define

begin_comment
comment|/* connection is configured to use Unicode */
end_comment

begin_comment
comment|/*  * smb_share flags  */
end_comment

begin_define
define|#
directive|define
name|SMBS_PERMANENT
value|0x0001
end_define

begin_define
define|#
directive|define
name|SMBS_RECONNECTING
value|0x0002
end_define

begin_define
define|#
directive|define
name|SMBS_CONNECTED
value|0x0004
end_define

begin_comment
comment|/*  * share types  */
end_comment

begin_define
define|#
directive|define
name|SMB_ST_DISK
value|0x0
end_define

begin_comment
comment|/* A: */
end_comment

begin_define
define|#
directive|define
name|SMB_ST_PRINTER
value|0x1
end_define

begin_comment
comment|/* LPT: */
end_comment

begin_define
define|#
directive|define
name|SMB_ST_PIPE
value|0x2
end_define

begin_comment
comment|/* IPC */
end_comment

begin_define
define|#
directive|define
name|SMB_ST_COMM
value|0x3
end_define

begin_comment
comment|/* COMM */
end_comment

begin_define
define|#
directive|define
name|SMB_ST_ANY
value|0x4
end_define

begin_define
define|#
directive|define
name|SMB_ST_MAX
value|0x4
end_define

begin_define
define|#
directive|define
name|SMB_ST_NONE
value|0xff
end_define

begin_comment
comment|/* not a part of protocol */
end_comment

begin_comment
comment|/*  * Negotiated protocol parameters  */
end_comment

begin_struct
struct|struct
name|smb_sopt
block|{
name|int
name|sv_proto
decl_stmt|;
name|int16_t
name|sv_tz
decl_stmt|;
comment|/* offset in min relative to UTC */
name|u_int32_t
name|sv_maxtx
decl_stmt|;
comment|/* maximum transmit buf size */
name|u_char
name|sv_sm
decl_stmt|;
comment|/* security mode */
name|u_int16_t
name|sv_maxmux
decl_stmt|;
comment|/* max number of outstanding rq's */
name|u_int16_t
name|sv_maxvcs
decl_stmt|;
comment|/* max number of VCs */
name|u_int16_t
name|sv_rawmode
decl_stmt|;
name|u_int32_t
name|sv_maxraw
decl_stmt|;
comment|/* maximum raw-buffer size */
name|u_int32_t
name|sv_skey
decl_stmt|;
comment|/* session key */
name|u_int32_t
name|sv_caps
decl_stmt|;
comment|/* capabilites SMB_CAP_ */
block|}
struct|;
end_struct

begin_comment
comment|/*  * network IO daemon states  */
end_comment

begin_enum
enum|enum
name|smbiod_state
block|{
name|SMBIOD_ST_NOTCONN
block|,
comment|/* no connect request was made */
name|SMBIOD_ST_RECONNECT
block|,
comment|/* a [re]connect attempt is in progress */
name|SMBIOD_ST_TRANACTIVE
block|,
comment|/* transport level is up */
name|SMBIOD_ST_VCACTIVE
block|,
comment|/* session established */
name|SMBIOD_ST_DEAD
comment|/* connection broken, transport is down */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Info structures  */
end_comment

begin_define
define|#
directive|define
name|SMB_INFO_NONE
value|0
end_define

begin_define
define|#
directive|define
name|SMB_INFO_VC
value|2
end_define

begin_define
define|#
directive|define
name|SMB_INFO_SHARE
value|3
end_define

begin_struct
struct|struct
name|smb_vc_info
block|{
name|int
name|itype
decl_stmt|;
name|int
name|usecount
decl_stmt|;
name|uid_t
name|uid
decl_stmt|;
comment|/* user id of connection */
name|gid_t
name|gid
decl_stmt|;
comment|/* group of connection */
name|mode_t
name|mode
decl_stmt|;
comment|/* access mode */
name|int
name|flags
decl_stmt|;
name|enum
name|smbiod_state
name|iodstate
decl_stmt|;
name|struct
name|smb_sopt
name|sopt
decl_stmt|;
name|char
name|srvname
index|[
name|SMB_MAXSRVNAMELEN
index|]
decl_stmt|;
name|char
name|vcname
index|[
literal|128
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|smb_share_info
block|{
name|int
name|itype
decl_stmt|;
name|int
name|usecount
decl_stmt|;
name|u_short
name|tid
decl_stmt|;
comment|/* TID */
name|int
name|type
decl_stmt|;
comment|/* share type */
name|uid_t
name|uid
decl_stmt|;
comment|/* user id of connection */
name|gid_t
name|gid
decl_stmt|;
comment|/* group of connection */
name|mode_t
name|mode
decl_stmt|;
comment|/* access mode */
name|int
name|flags
decl_stmt|;
name|char
name|sname
index|[
literal|128
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<netsmb/smb_subr.h>
end_include

begin_define
define|#
directive|define
name|CONNADDREQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|((a1)->sa_len == (a2)->sa_len&& \ 				 bcmp(a1, a2, (a1)->sa_len) == 0)
end_define

begin_struct_decl
struct_decl|struct
name|smb_vc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|smb_share
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|smb_cred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|smb_rq
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbdata
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|smbioc_oshare
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|smbioc_ossn
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|smb_rqhead
argument_list|,
name|smb_rq
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|SMB_DEFRQTIMO
value|5
end_define

begin_define
define|#
directive|define
name|SMB_DIALECT
parameter_list|(
name|vcp
parameter_list|)
value|((vcp)->vc_sopt.sv_proto)
end_define

begin_struct_decl
struct_decl|struct
name|smb_tran_desc
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Connection object  */
end_comment

begin_struct_decl
struct_decl|struct
name|smb_connobj
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
name|smb_co_gone_t
parameter_list|(
name|struct
name|smb_connobj
modifier|*
name|cp
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|smb_co_free_t
parameter_list|(
name|struct
name|smb_connobj
modifier|*
name|cp
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|SMB_CO_LOCK
parameter_list|(
name|cp
parameter_list|)
value|smb_sl_lock(&(cp)->co_interlock)
end_define

begin_define
define|#
directive|define
name|SMB_CO_UNLOCK
parameter_list|(
name|cp
parameter_list|)
value|smb_sl_unlock(&(cp)->co_interlock)
end_define

begin_struct
struct|struct
name|smb_connobj
block|{
name|int
name|co_level
decl_stmt|;
comment|/* SMBL_ */
name|int
name|co_flags
decl_stmt|;
name|struct
name|lock
name|co_lock
decl_stmt|;
name|struct
name|smb_slock
name|co_interlock
decl_stmt|;
name|int
name|co_usecount
decl_stmt|;
name|struct
name|smb_connobj
modifier|*
name|co_parent
decl_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|smb_connobj
argument_list|)
name|co_children
expr_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|smb_connobj
argument_list|)
name|co_next
expr_stmt|;
name|smb_co_gone_t
modifier|*
name|co_gone
decl_stmt|;
name|smb_co_free_t
modifier|*
name|co_free
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SMBCO_FOREACH
parameter_list|(
name|var
parameter_list|,
name|cp
parameter_list|)
value|SLIST_FOREACH((var),&(cp)->co_children, co_next)
end_define

begin_comment
comment|/*  * Virtual Circuit (session) to a server.  * This is the most (over)complicated part of SMB protocol.  * For the user security level (usl), each session with different remote  * user name has its own VC.  * It is unclear however, should share security level (ssl) allow additional  * VCs, because user name is not used and can be the same. On other hand,  * multiple VCs allows us to create separate sessions to server on a per  * user basis.  */
end_comment

begin_comment
comment|/*  * This lock protects vc_flags  */
end_comment

begin_define
define|#
directive|define
name|SMBC_ST_LOCK
parameter_list|(
name|vcp
parameter_list|)
value|smb_sl_lock(&(vcp)->vc_stlock)
end_define

begin_define
define|#
directive|define
name|SMBC_ST_UNLOCK
parameter_list|(
name|vcp
parameter_list|)
value|smb_sl_unlock(&(vcp)->vc_stlock)
end_define

begin_struct
struct|struct
name|smb_vc
block|{
name|struct
name|smb_connobj
name|obj
decl_stmt|;
name|char
modifier|*
name|vc_srvname
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|vc_paddr
decl_stmt|;
comment|/* server addr */
name|struct
name|sockaddr
modifier|*
name|vc_laddr
decl_stmt|;
comment|/* local addr, if any */
name|char
modifier|*
name|vc_username
decl_stmt|;
name|char
modifier|*
name|vc_pass
decl_stmt|;
comment|/* password for usl case */
name|char
modifier|*
name|vc_domain
decl_stmt|;
comment|/* workgroup/primary domain */
name|u_int
name|vc_timo
decl_stmt|;
comment|/* default request timeout */
name|int
name|vc_maxvcs
decl_stmt|;
comment|/* maximum number of VC per connection */
name|void
modifier|*
name|vc_tolower
decl_stmt|;
comment|/* local charset */
name|void
modifier|*
name|vc_toupper
decl_stmt|;
comment|/* local charset */
name|void
modifier|*
name|vc_toserver
decl_stmt|;
comment|/* local charset to server one */
name|void
modifier|*
name|vc_tolocal
decl_stmt|;
comment|/* server charset to local one */
name|int
name|vc_number
decl_stmt|;
comment|/* number of this VC from the client side */
name|int
name|vc_genid
decl_stmt|;
name|uid_t
name|vc_uid
decl_stmt|;
comment|/* user id of connection */
name|gid_t
name|vc_grp
decl_stmt|;
comment|/* group of connection */
name|mode_t
name|vc_mode
decl_stmt|;
comment|/* access mode */
name|struct
name|tnode
modifier|*
name|vc_tnode
decl_stmt|;
comment|/* backing object */
name|u_short
name|vc_smbuid
decl_stmt|;
comment|/* unique vc id assigned by server */
name|u_char
name|vc_hflags
decl_stmt|;
comment|/* or'ed with flags in the smb header */
name|u_short
name|vc_hflags2
decl_stmt|;
comment|/* or'ed with flags in the smb header */
name|void
modifier|*
name|vc_tdata
decl_stmt|;
comment|/* transport control block */
name|struct
name|smb_tran_desc
modifier|*
name|vc_tdesc
decl_stmt|;
name|int
name|vc_chlen
decl_stmt|;
comment|/* actual challenge length */
name|u_char
name|vc_ch
index|[
name|SMB_MAXCHALLENGELEN
index|]
decl_stmt|;
name|u_short
name|vc_mid
decl_stmt|;
comment|/* multiplex id */
name|struct
name|smb_sopt
name|vc_sopt
decl_stmt|;
comment|/* server options */
name|struct
name|smb_cred
modifier|*
name|vc_scred
decl_stmt|;
comment|/* used in reconnect procedure */
name|int
name|vc_txmax
decl_stmt|;
comment|/* max tx/rx packet size */
name|struct
name|smbiod
modifier|*
name|vc_iod
decl_stmt|;
name|struct
name|smb_slock
name|vc_stlock
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|vc_maxmux
value|vc_sopt.sv_maxmux
end_define

begin_define
define|#
directive|define
name|vc_flags
value|obj.co_flags
end_define

begin_comment
comment|/*  * smb_share structure describes connection to the given SMB share (tree).  * Connection to share is always built on top of the VC.  */
end_comment

begin_comment
comment|/*  * This lock protects ss_flags  */
end_comment

begin_define
define|#
directive|define
name|SMBS_ST_LOCK
parameter_list|(
name|ssp
parameter_list|)
value|smb_sl_lock(&(ssp)->ss_stlock)
end_define

begin_define
define|#
directive|define
name|SMBS_ST_LOCKPTR
parameter_list|(
name|ssp
parameter_list|)
value|(&(ssp)->ss_stlock)
end_define

begin_define
define|#
directive|define
name|SMBS_ST_UNLOCK
parameter_list|(
name|ssp
parameter_list|)
value|smb_sl_unlock(&(ssp)->ss_stlock)
end_define

begin_struct
struct|struct
name|smb_share
block|{
name|struct
name|smb_connobj
name|obj
decl_stmt|;
name|char
modifier|*
name|ss_name
decl_stmt|;
name|u_short
name|ss_tid
decl_stmt|;
comment|/* TID */
name|int
name|ss_type
decl_stmt|;
comment|/* share type */
name|uid_t
name|ss_uid
decl_stmt|;
comment|/* user id of connection */
name|gid_t
name|ss_grp
decl_stmt|;
comment|/* group of connection */
name|mode_t
name|ss_mode
decl_stmt|;
comment|/* access mode */
name|int
name|ss_vcgenid
decl_stmt|;
name|char
modifier|*
name|ss_pass
decl_stmt|;
comment|/* password to a share, can be null */
name|struct
name|smb_slock
name|ss_stlock
decl_stmt|;
name|struct
name|smb_cred
modifier|*
name|ss_cred
decl_stmt|;
comment|/* used in reconnect procedure */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ss_flags
value|obj.co_flags
end_define

begin_define
define|#
directive|define
name|CPTOVC
parameter_list|(
name|cp
parameter_list|)
value|((struct smb_vc*)(cp))
end_define

begin_define
define|#
directive|define
name|VCTOCP
parameter_list|(
name|vcp
parameter_list|)
value|(&(vcp)->obj)
end_define

begin_define
define|#
directive|define
name|CPTOSS
parameter_list|(
name|cp
parameter_list|)
value|((struct smb_share*)(cp))
end_define

begin_define
define|#
directive|define
name|SSTOVC
parameter_list|(
name|ssp
parameter_list|)
value|CPTOVC(((ssp)->obj.co_parent))
end_define

begin_define
define|#
directive|define
name|SSTOCP
parameter_list|(
name|ssp
parameter_list|)
value|(&(ssp)->obj)
end_define

begin_struct
struct|struct
name|smb_vcspec
block|{
name|char
modifier|*
name|srvname
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|sap
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|lap
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|char
modifier|*
name|username
decl_stmt|;
name|char
modifier|*
name|pass
decl_stmt|;
name|char
modifier|*
name|domain
decl_stmt|;
name|mode_t
name|mode
decl_stmt|;
name|mode_t
name|rights
decl_stmt|;
name|uid_t
name|owner
decl_stmt|;
name|gid_t
name|group
decl_stmt|;
name|char
modifier|*
name|localcs
decl_stmt|;
name|char
modifier|*
name|servercs
decl_stmt|;
name|struct
name|smb_sharespec
modifier|*
name|shspec
decl_stmt|;
name|struct
name|smb_share
modifier|*
name|ssp
decl_stmt|;
comment|/* returned */
comment|/* 	 * The rest is an internal data 	 */
name|struct
name|smb_cred
modifier|*
name|scred
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|smb_sharespec
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|pass
decl_stmt|;
name|mode_t
name|mode
decl_stmt|;
name|mode_t
name|rights
decl_stmt|;
name|uid_t
name|owner
decl_stmt|;
name|gid_t
name|group
decl_stmt|;
name|int
name|stype
decl_stmt|;
comment|/* 	 * The rest is an internal data 	 */
name|struct
name|smb_cred
modifier|*
name|scred
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Session level functions  */
end_comment

begin_function_decl
name|int
name|smb_sm_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_sm_done
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_sm_lookup
parameter_list|(
name|struct
name|smb_vcspec
modifier|*
name|vcspec
parameter_list|,
name|struct
name|smb_sharespec
modifier|*
name|shspec
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

begin_comment
comment|/*  * Connection object  */
end_comment

begin_function_decl
name|void
name|smb_co_ref
parameter_list|(
name|struct
name|smb_connobj
modifier|*
name|cp
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_co_rele
parameter_list|(
name|struct
name|smb_connobj
modifier|*
name|cp
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
name|smb_co_get
parameter_list|(
name|struct
name|smb_connobj
modifier|*
name|cp
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_co_put
parameter_list|(
name|struct
name|smb_connobj
modifier|*
name|cp
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
name|smb_co_lock
parameter_list|(
name|struct
name|smb_connobj
modifier|*
name|cp
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_co_unlock
parameter_list|(
name|struct
name|smb_connobj
modifier|*
name|cp
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * session level functions  */
end_comment

begin_function_decl
name|int
name|smb_vc_create
parameter_list|(
name|struct
name|smb_vcspec
modifier|*
name|vcspec
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
name|smb_vc_connect
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
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
name|smb_vc_access
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|,
name|mode_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_vc_get
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_vc_put
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_vc_ref
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_vc_rele
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
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
name|smb_vc_lock
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_vc_unlock
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_vc_lookupshare
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|,
name|struct
name|smb_sharespec
modifier|*
name|shspec
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
specifier|const
name|char
modifier|*
name|smb_vc_getpass
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|smb_vc_nextmid
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * share level functions  */
end_comment

begin_function_decl
name|int
name|smb_share_create
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|,
name|struct
name|smb_sharespec
modifier|*
name|shspec
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
name|smb_share_access
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|,
name|mode_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_share_ref
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_share_rele
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
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
name|smb_share_get
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_share_put
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
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
name|smb_share_lock
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_share_unlock
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_share_invalidate
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_share_valid
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|smb_share_getpass
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * SMB protocol level functions  */
end_comment

begin_function_decl
name|int
name|smb_smb_negotiate
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
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
name|smb_smb_ssnsetup
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
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
name|smb_smb_ssnclose
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
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
name|smb_smb_treeconnect
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
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
name|smb_smb_treedisconnect
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
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
name|smb_read
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
parameter_list|,
name|u_int16_t
name|fid
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
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
name|smb_write
parameter_list|(
name|struct
name|smb_share
modifier|*
name|ssp
parameter_list|,
name|u_int16_t
name|fid
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
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
name|smb_smb_echo
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|,
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * smbiod thread  */
end_comment

begin_define
define|#
directive|define
name|SMBIOD_EV_NEWRQ
value|0x0001
end_define

begin_define
define|#
directive|define
name|SMBIOD_EV_SHUTDOWN
value|0x0002
end_define

begin_define
define|#
directive|define
name|SMBIOD_EV_CONNECT
value|0x0003
end_define

begin_define
define|#
directive|define
name|SMBIOD_EV_DISCONNECT
value|0x0004
end_define

begin_define
define|#
directive|define
name|SMBIOD_EV_TREECONNECT
value|0x0005
end_define

begin_define
define|#
directive|define
name|SMBIOD_EV_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|SMBIOD_EV_SYNC
value|0x0100
end_define

begin_define
define|#
directive|define
name|SMBIOD_EV_PROCESSING
value|0x0200
end_define

begin_struct
struct|struct
name|smbiod_event
block|{
name|int
name|ev_type
decl_stmt|;
name|int
name|ev_error
decl_stmt|;
name|void
modifier|*
name|ev_ident
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|smbiod_event
argument_list|)
name|ev_link
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SMBIOD_SHUTDOWN
value|0x0001
end_define

begin_struct
struct|struct
name|smbiod
block|{
name|int
name|iod_id
decl_stmt|;
name|int
name|iod_flags
decl_stmt|;
name|enum
name|smbiod_state
name|iod_state
decl_stmt|;
name|int
name|iod_muxcnt
decl_stmt|;
comment|/* number of active outstanding requests */
name|int
name|iod_sleeptimo
decl_stmt|;
name|struct
name|smb_vc
modifier|*
name|iod_vc
decl_stmt|;
name|struct
name|smb_slock
name|iod_rqlock
decl_stmt|;
comment|/* iod_rqlist, iod_muxwant */
name|struct
name|smb_rqhead
name|iod_rqlist
decl_stmt|;
comment|/* list of outstanding requests */
name|int
name|iod_muxwant
decl_stmt|;
name|struct
name|proc
modifier|*
name|iod_p
decl_stmt|;
name|struct
name|smb_cred
name|iod_scred
decl_stmt|;
name|struct
name|smb_slock
name|iod_evlock
decl_stmt|;
comment|/* iod_evlist */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|smbiod_event
argument_list|)
name|iod_evlist
expr_stmt|;
name|struct
name|timespec
name|iod_lastrqsent
decl_stmt|;
name|struct
name|timespec
name|iod_pingtimo
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|smb_iod_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_iod_done
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_iod_create
parameter_list|(
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_iod_destroy
parameter_list|(
name|struct
name|smbiod
modifier|*
name|iod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_iod_request
parameter_list|(
name|struct
name|smbiod
modifier|*
name|iod
parameter_list|,
name|int
name|event
parameter_list|,
name|void
modifier|*
name|ident
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_iod_addrq
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_iod_waitrq
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_iod_removerq
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
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

end_unit

