begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2000 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: admin.h,v 1.18 2000/08/04 11:26:21 joda Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KADM5_ADMIN_H__
end_ifndef

begin_define
define|#
directive|define
name|__KADM5_ADMIN_H__
end_define

begin_define
define|#
directive|define
name|KADM5_API_VERSION_1
value|1
end_define

begin_define
define|#
directive|define
name|KADM5_API_VERSION_2
value|2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|USE_KADM5_API_VERSION
end_ifndef

begin_define
define|#
directive|define
name|USE_KADM5_API_VERSION
value|KADM5_API_VERSION_2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|USE_KADM5_API_VERSION
operator|!=
name|KADM5_API_VERSION_2
end_if

begin_error
error|#
directive|error
error|No support for API versions other than 2
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KADM5_STRUCT_VERSION
value|0
end_define

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_define
define|#
directive|define
name|KRB5_KDB_DISALLOW_POSTDATED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|KRB5_KDB_DISALLOW_FORWARDABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|KRB5_KDB_DISALLOW_TGT_BASED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|KRB5_KDB_DISALLOW_RENEWABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|KRB5_KDB_DISALLOW_PROXIABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|KRB5_KDB_DISALLOW_DUP_SKEY
value|0x00000020
end_define

begin_define
define|#
directive|define
name|KRB5_KDB_DISALLOW_ALL_TIX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|KRB5_KDB_REQUIRES_PRE_AUTH
value|0x00000080
end_define

begin_define
define|#
directive|define
name|KRB5_KDB_REQUIRES_HW_AUTH
value|0x00000100
end_define

begin_define
define|#
directive|define
name|KRB5_KDB_REQUIRES_PWCHANGE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|KRB5_KDB_DISALLOW_SVR
value|0x00001000
end_define

begin_define
define|#
directive|define
name|KRB5_KDB_PWCHANGE_SERVICE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|KRB5_KDB_SUPPORT_DESMD5
value|0x00004000
end_define

begin_define
define|#
directive|define
name|KRB5_KDB_NEW_PRINC
value|0x00008000
end_define

begin_define
define|#
directive|define
name|KADM5_PRINCIPAL
value|0x000001
end_define

begin_define
define|#
directive|define
name|KADM5_PRINC_EXPIRE_TIME
value|0x000002
end_define

begin_define
define|#
directive|define
name|KADM5_PW_EXPIRATION
value|0x000004
end_define

begin_define
define|#
directive|define
name|KADM5_LAST_PWD_CHANGE
value|0x000008
end_define

begin_define
define|#
directive|define
name|KADM5_ATTRIBUTES
value|0x000010
end_define

begin_define
define|#
directive|define
name|KADM5_MAX_LIFE
value|0x000020
end_define

begin_define
define|#
directive|define
name|KADM5_MOD_TIME
value|0x000040
end_define

begin_define
define|#
directive|define
name|KADM5_MOD_NAME
value|0x000080
end_define

begin_define
define|#
directive|define
name|KADM5_KVNO
value|0x000100
end_define

begin_define
define|#
directive|define
name|KADM5_MKVNO
value|0x000200
end_define

begin_define
define|#
directive|define
name|KADM5_AUX_ATTRIBUTES
value|0x000400
end_define

begin_define
define|#
directive|define
name|KADM5_POLICY
value|0x000800
end_define

begin_define
define|#
directive|define
name|KADM5_POLICY_CLR
value|0x001000
end_define

begin_define
define|#
directive|define
name|KADM5_MAX_RLIFE
value|0x002000
end_define

begin_define
define|#
directive|define
name|KADM5_LAST_SUCCESS
value|0x004000
end_define

begin_define
define|#
directive|define
name|KADM5_LAST_FAILED
value|0x008000
end_define

begin_define
define|#
directive|define
name|KADM5_FAIL_AUTH_COUNT
value|0x010000
end_define

begin_define
define|#
directive|define
name|KADM5_KEY_DATA
value|0x020000
end_define

begin_define
define|#
directive|define
name|KADM5_TL_DATA
value|0x040000
end_define

begin_define
define|#
directive|define
name|KADM5_PRINCIPAL_NORMAL_MASK
value|(~(KADM5_KEY_DATA | KADM5_TL_DATA))
end_define

begin_define
define|#
directive|define
name|KADM5_PW_MAX_LIFE
value|0x004000
end_define

begin_define
define|#
directive|define
name|KADM5_PW_MIN_LIFE
value|0x008000
end_define

begin_define
define|#
directive|define
name|KADM5_PW_MIN_LENGTH
value|0x010000
end_define

begin_define
define|#
directive|define
name|KADM5_PW_MIN_CLASSES
value|0x020000
end_define

begin_define
define|#
directive|define
name|KADM5_PW_HISTORY_NUM
value|0x040000
end_define

begin_define
define|#
directive|define
name|KADM5_REF_COUNT
value|0x080000
end_define

begin_define
define|#
directive|define
name|KADM5_POLICY_NORMAL_MASK
value|(~0)
end_define

begin_define
define|#
directive|define
name|KADM5_ADMIN_SERVICE
value|"kadmin/admin"
end_define

begin_define
define|#
directive|define
name|KADM5_HIST_PRINCIPAL
value|"kadmin/history"
end_define

begin_define
define|#
directive|define
name|KADM5_CHANGEPW_SERVICE
value|"kadmin/changepw"
end_define

begin_typedef
typedef|typedef
struct|struct
name|_krb5_key_data
block|{
name|int16_t
name|key_data_ver
decl_stmt|;
comment|/* Version */
name|int16_t
name|key_data_kvno
decl_stmt|;
comment|/* Key Version */
name|int16_t
name|key_data_type
index|[
literal|2
index|]
decl_stmt|;
comment|/* Array of types */
name|int16_t
name|key_data_length
index|[
literal|2
index|]
decl_stmt|;
comment|/* Array of lengths */
name|void
modifier|*
name|key_data_contents
index|[
literal|2
index|]
decl_stmt|;
comment|/* Array of pointers */
block|}
name|krb5_key_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_krb5_tl_data
block|{
name|struct
name|_krb5_tl_data
modifier|*
name|tl_data_next
decl_stmt|;
name|int16_t
name|tl_data_type
decl_stmt|;
name|int16_t
name|tl_data_length
decl_stmt|;
name|void
modifier|*
name|tl_data_contents
decl_stmt|;
block|}
name|krb5_tl_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_kadm5_principal_ent_t
block|{
name|krb5_principal
name|principal
decl_stmt|;
name|krb5_timestamp
name|princ_expire_time
decl_stmt|;
name|krb5_timestamp
name|last_pwd_change
decl_stmt|;
name|krb5_timestamp
name|pw_expiration
decl_stmt|;
name|krb5_deltat
name|max_life
decl_stmt|;
name|krb5_principal
name|mod_name
decl_stmt|;
name|krb5_timestamp
name|mod_date
decl_stmt|;
name|krb5_flags
name|attributes
decl_stmt|;
name|krb5_kvno
name|kvno
decl_stmt|;
name|krb5_kvno
name|mkvno
decl_stmt|;
name|char
modifier|*
name|policy
decl_stmt|;
name|u_int32_t
name|aux_attributes
decl_stmt|;
name|krb5_deltat
name|max_renewable_life
decl_stmt|;
name|krb5_timestamp
name|last_success
decl_stmt|;
name|krb5_timestamp
name|last_failed
decl_stmt|;
name|krb5_kvno
name|fail_auth_count
decl_stmt|;
name|int16_t
name|n_key_data
decl_stmt|;
name|int16_t
name|n_tl_data
decl_stmt|;
name|krb5_tl_data
modifier|*
name|tl_data
decl_stmt|;
name|krb5_key_data
modifier|*
name|key_data
decl_stmt|;
block|}
name|kadm5_principal_ent_rec
operator|,
typedef|*
name|kadm5_principal_ent_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_kadm5_policy_ent_t
block|{
name|char
modifier|*
name|policy
decl_stmt|;
name|u_int32_t
name|pw_min_life
decl_stmt|;
name|u_int32_t
name|pw_max_life
decl_stmt|;
name|u_int32_t
name|pw_min_length
decl_stmt|;
name|u_int32_t
name|pw_min_classes
decl_stmt|;
name|u_int32_t
name|pw_history_num
decl_stmt|;
name|u_int32_t
name|policy_refcnt
decl_stmt|;
block|}
name|kadm5_policy_ent_rec
operator|,
typedef|*
name|kadm5_policy_ent_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KADM5_CONFIG_REALM
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_PROFILE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_KADMIND_PORT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_ADMIN_SERVER
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_DBNAME
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_ADBNAME
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_ADB_LOCKFILE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_ACL_FILE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_DICT_FILE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_ADMIN_KEYTAB
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_MKEY_FROM_KEYBOARD
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_STASH_FILE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_MKEY_NAME
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_ENCTYPE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_MAX_LIFE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_MAX_RLIFE
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_EXPIRATION
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_FLAGS
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|KADM5_CONFIG_ENCTYPES
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|KADM5_PRIV_GET
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|KADM5_PRIV_ADD
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|KADM5_PRIV_MODIFY
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|KADM5_PRIV_DELETE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|KADM5_PRIV_LIST
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|KADM5_PRIV_CPW
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|KADM5_PRIV_ALL
value|(KADM5_PRIV_GET | KADM5_PRIV_ADD | KADM5_PRIV_MODIFY | KADM5_PRIV_DELETE | KADM5_PRIV_LIST | KADM5_PRIV_CPW)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|XXX
decl_stmt|;
block|}
name|krb5_key_salt_tuple
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_kadm5_config_params
block|{
name|u_int32_t
name|mask
decl_stmt|;
comment|/* Client and server fields */
name|char
modifier|*
name|realm
decl_stmt|;
name|int
name|kadmind_port
decl_stmt|;
comment|/* client fields */
name|char
modifier|*
name|admin_server
decl_stmt|;
comment|/* server fields */
name|char
modifier|*
name|dbname
decl_stmt|;
name|char
modifier|*
name|acl_file
decl_stmt|;
comment|/* server library (database) fields */
name|char
modifier|*
name|stash_file
decl_stmt|;
block|}
name|kadm5_config_params
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_error_code
name|kadm5_ret_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"kadm5-protos.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* unimplemented functions */
end_comment

begin_endif
unit|kadm5_ret_t  kadm5_decrypt_key(void *server_handle, 		  kadm5_principal_ent_t entry, int32_t 		  ktype, int32_t stype, int32_t 		  kvno, krb5_keyblock *keyblock, 		  krb5_keysalt *keysalt, int *kvnop);  kadm5_ret_t kadm5_create_policy(void *server_handle, 		    kadm5_policy_ent_t policy, u_int32_t mask);   kadm5_ret_t kadm5_delete_policy(void *server_handle, char *policy);   kadm5_ret_t kadm5_modify_policy(void *server_handle, 		    kadm5_policy_ent_t policy,  		    u_int32_t mask);  kadm5_ret_t kadm5_get_policy(void *server_handle, char *policy, kadm5_policy_ent_t ent);   kadm5_ret_t kadm5_get_policies(void *server_handle, char *exp, 		   char ***pols, int *count);  void  kadm5_free_policy_ent(kadm5_policy_ent_t policy);
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KADM5_ADMIN_H__ */
end_comment

end_unit

