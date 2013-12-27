begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005, PADL Software Pty Ltd.  * All rights reserved.  *  * Portions Copyright (c) 2009 Apple Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of PADL Software nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY PADL SOFTWARE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL PADL SOFTWARE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KCM_LOCL_H__
end_ifndef

begin_define
define|#
directive|define
name|__KCM_LOCL_H__
end_define

begin_include
include|#
directive|include
file|"headers.h"
end_include

begin_include
include|#
directive|include
file|<kcm.h>
end_include

begin_define
define|#
directive|define
name|KCM_LOG_REQUEST
parameter_list|(
name|_context
parameter_list|,
name|_client
parameter_list|,
name|_opcode
parameter_list|)
value|do { \     kcm_log(1, "%s request by process %d/uid %d", \ 	    kcm_op2string(_opcode), (_client)->pid, (_client)->uid); \     } while (0)
end_define

begin_define
define|#
directive|define
name|KCM_LOG_REQUEST_NAME
parameter_list|(
name|_context
parameter_list|,
name|_client
parameter_list|,
name|_opcode
parameter_list|,
name|_name
parameter_list|)
value|do { \     kcm_log(1, "%s request for cache %s by process %d/uid %d", \ 	    kcm_op2string(_opcode), (_name), (_client)->pid, (_client)->uid); \     } while (0)
end_define

begin_comment
comment|/* Cache management */
end_comment

begin_define
define|#
directive|define
name|KCM_FLAGS_VALID
value|0x0001
end_define

begin_define
define|#
directive|define
name|KCM_FLAGS_USE_KEYTAB
value|0x0002
end_define

begin_define
define|#
directive|define
name|KCM_FLAGS_RENEWABLE
value|0x0004
end_define

begin_define
define|#
directive|define
name|KCM_FLAGS_OWNER_IS_SYSTEM
value|0x0008
end_define

begin_define
define|#
directive|define
name|KCM_FLAGS_USE_CACHED_KEY
value|0x0010
end_define

begin_define
define|#
directive|define
name|KCM_MASK_KEY_PRESENT
value|( KCM_FLAGS_USE_KEYTAB | \ 					  KCM_FLAGS_USE_CACHED_KEY )
end_define

begin_struct_decl
struct_decl|struct
name|kcm_ccache_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|kcm_creds
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|kcm_default_cache
block|{
name|uid_t
name|uid
decl_stmt|;
name|pid_t
name|session
decl_stmt|;
comment|/* really au_asid_t */
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|kcm_default_cache
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|kcm_default_cache
modifier|*
name|default_caches
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|kcm_creds
block|{
name|kcmuuid_t
name|uuid
decl_stmt|;
name|krb5_creds
name|cred
decl_stmt|;
name|struct
name|kcm_creds
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|kcm_ccache_data
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|kcmuuid_t
name|uuid
decl_stmt|;
name|unsigned
name|refcnt
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
name|uint16_t
name|mode
decl_stmt|;
name|uid_t
name|uid
decl_stmt|;
name|gid_t
name|gid
decl_stmt|;
name|pid_t
name|session
decl_stmt|;
comment|/* really au_asid_t */
name|krb5_principal
name|client
decl_stmt|;
comment|/* primary client principal */
name|krb5_principal
name|server
decl_stmt|;
comment|/* primary server principal (TGS if NULL) */
name|struct
name|kcm_creds
modifier|*
name|creds
decl_stmt|;
name|krb5_deltat
name|tkt_life
decl_stmt|;
name|krb5_deltat
name|renew_life
decl_stmt|;
name|int32_t
name|kdc_offset
decl_stmt|;
union|union
block|{
name|krb5_keytab
name|keytab
decl_stmt|;
name|krb5_keyblock
name|keyblock
decl_stmt|;
block|}
name|key
union|;
name|HEIMDAL_MUTEX
name|mutex
decl_stmt|;
name|struct
name|kcm_ccache_data
modifier|*
name|next
decl_stmt|;
block|}
name|kcm_ccache_data
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KCM_ASSERT_VALID
parameter_list|(
name|_ccache
parameter_list|)
value|do { \     if (((_ccache)->flags& KCM_FLAGS_VALID) == 0) \ 	krb5_abortx(context, "kcm_free_ccache_data: ccache invalid"); \     else if ((_ccache)->refcnt == 0) \ 	krb5_abortx(context, "kcm_free_ccache_data: ccache refcnt == 0"); \     } while (0)
end_define

begin_typedef
typedef|typedef
name|kcm_ccache_data
modifier|*
name|kcm_ccache
typedef|;
end_typedef

begin_comment
comment|/* Event management */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|kcm_event
block|{
name|int
name|valid
decl_stmt|;
name|time_t
name|fire_time
decl_stmt|;
name|unsigned
name|fire_count
decl_stmt|;
name|time_t
name|expire_time
decl_stmt|;
name|time_t
name|backoff_time
decl_stmt|;
enum|enum
block|{
name|KCM_EVENT_NONE
init|=
literal|0
block|,
name|KCM_EVENT_ACQUIRE_CREDS
block|,
name|KCM_EVENT_RENEW_CREDS
block|,
name|KCM_EVENT_DESTROY_CREDS
block|,
name|KCM_EVENT_DESTROY_EMPTY_CACHE
block|}
name|action
enum|;
name|kcm_ccache
name|ccache
decl_stmt|;
name|struct
name|kcm_event
modifier|*
name|next
decl_stmt|;
block|}
name|kcm_event
typedef|;
end_typedef

begin_comment
comment|/* wakeup interval for event queue */
end_comment

begin_define
define|#
directive|define
name|KCM_EVENT_QUEUE_INTERVAL
value|60
end_define

begin_define
define|#
directive|define
name|KCM_EVENT_DEFAULT_BACKOFF_TIME
value|5
end_define

begin_define
define|#
directive|define
name|KCM_EVENT_MAX_BACKOFF_TIME
value|(12 * 60 * 60)
end_define

begin_comment
comment|/* Request format is  LENGTH | MAJOR | MINOR | OPERATION | request */
end_comment

begin_comment
comment|/* Response format is LENGTH | STATUS | response */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|kcm_client
block|{
name|pid_t
name|pid
decl_stmt|;
name|uid_t
name|uid
decl_stmt|;
name|gid_t
name|gid
decl_stmt|;
name|pid_t
name|session
decl_stmt|;
block|}
name|kcm_client
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CLIENT_IS_ROOT
parameter_list|(
name|client
parameter_list|)
value|((client)->uid == 0)
end_define

begin_comment
comment|/* Dispatch table */
end_comment

begin_comment
comment|/* passed in OPERATION | ... ; returns STATUS | ... */
end_comment

begin_typedef
typedef|typedef
name|krb5_error_code
function_decl|(
modifier|*
name|kcm_method
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|kcm_client
modifier|*
parameter_list|,
name|kcm_operation
parameter_list|,
name|krb5_storage
modifier|*
parameter_list|,
name|krb5_storage
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|kcm_op
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|kcm_method
name|method
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEFAULT_LOG_DEST
value|"0/FILE:" LOCALSTATEDIR "/log/kcmd.log"
end_define

begin_define
define|#
directive|define
name|_PATH_KCM_CONF
value|SYSCONFDIR "/kcm.conf"
end_define

begin_decl_stmt
specifier|extern
name|krb5_context
name|kcm_context
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|socket_path
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|door_path
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|max_request
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sig_atomic_t
name|exit_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|name_constraints
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_DETACH
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|detach_from_console
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|launchd_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|disallow_getting_krbtgt
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern const krb5_cc_ops krb5_kcmss_ops;
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|kcm_service
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|heim_idata
modifier|*
parameter_list|,
specifier|const
name|heim_icred
parameter_list|,
name|heim_ipc_complete
parameter_list|,
name|heim_sipc_call
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<kcm-protos.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KCM_LOCL_H__ */
end_comment

end_unit

