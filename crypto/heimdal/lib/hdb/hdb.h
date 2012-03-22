begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2007 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HDB_H__
end_ifndef

begin_define
define|#
directive|define
name|__HDB_H__
end_define

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_include
include|#
directive|include
file|<hdb_err.h>
end_include

begin_include
include|#
directive|include
file|<heim_asn1.h>
end_include

begin_include
include|#
directive|include
file|<hdb_asn1.h>
end_include

begin_struct_decl
struct_decl|struct
name|hdb_dbinfo
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|hdb_lockop
block|{
name|HDB_RLOCK
block|,
name|HDB_WLOCK
block|}
enum|;
end_enum

begin_comment
comment|/* flags for various functions */
end_comment

begin_define
define|#
directive|define
name|HDB_F_DECRYPT
value|1
end_define

begin_comment
comment|/* decrypt keys */
end_comment

begin_define
define|#
directive|define
name|HDB_F_REPLACE
value|2
end_define

begin_comment
comment|/* replace entry */
end_comment

begin_define
define|#
directive|define
name|HDB_F_GET_CLIENT
value|4
end_define

begin_comment
comment|/* fetch client */
end_comment

begin_define
define|#
directive|define
name|HDB_F_GET_SERVER
value|8
end_define

begin_comment
comment|/* fetch server */
end_comment

begin_define
define|#
directive|define
name|HDB_F_GET_KRBTGT
value|16
end_define

begin_comment
comment|/* fetch krbtgt */
end_comment

begin_define
define|#
directive|define
name|HDB_F_GET_ANY
value|28
end_define

begin_comment
comment|/* fetch any of client,server,krbtgt */
end_comment

begin_define
define|#
directive|define
name|HDB_F_CANON
value|32
end_define

begin_comment
comment|/* want canonicalition */
end_comment

begin_define
define|#
directive|define
name|HDB_F_ADMIN_DATA
value|64
end_define

begin_comment
comment|/* want data that kdc don't use  */
end_comment

begin_define
define|#
directive|define
name|HDB_F_KVNO_SPECIFIED
value|128
end_define

begin_comment
comment|/* we want a particular KVNO */
end_comment

begin_define
define|#
directive|define
name|HDB_F_CURRENT_KVNO
value|256
end_define

begin_comment
comment|/* we want the current KVNO */
end_comment

begin_comment
comment|/* 512, 1024, 2048 are reserved for kvno operations that is not part of the 1.5 branch */
end_comment

begin_define
define|#
directive|define
name|HDB_F_ALL_KVNOS
value|2048
end_define

begin_comment
comment|/* we want all the keys, live or not */
end_comment

begin_define
define|#
directive|define
name|HDB_F_FOR_AS_REQ
value|4096
end_define

begin_comment
comment|/* fetch is for a AS REQ */
end_comment

begin_define
define|#
directive|define
name|HDB_F_FOR_TGS_REQ
value|8192
end_define

begin_comment
comment|/* fetch is for a TGS REQ */
end_comment

begin_comment
comment|/* hdb_capability_flags */
end_comment

begin_define
define|#
directive|define
name|HDB_CAP_F_HANDLE_ENTERPRISE_PRINCIPAL
value|1
end_define

begin_define
define|#
directive|define
name|HDB_CAP_F_HANDLE_PASSWORDS
value|2
end_define

begin_define
define|#
directive|define
name|HDB_CAP_F_PASSWORD_UPDATE_KEYS
value|4
end_define

begin_comment
comment|/* auth status values */
end_comment

begin_define
define|#
directive|define
name|HDB_AUTH_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|HDB_AUTH_WRONG_PASSWORD
value|1
end_define

begin_define
define|#
directive|define
name|HDB_AUTH_INVALID_SIGNATURE
value|2
end_define

begin_comment
comment|/* key usage for master key */
end_comment

begin_define
define|#
directive|define
name|HDB_KU_MKEY
value|0x484442
end_define

begin_typedef
typedef|typedef
name|struct
name|hdb_master_key_data
modifier|*
name|hdb_master_key
typedef|;
end_typedef

begin_comment
comment|/**  * hdb_entry_ex is a wrapper structure around the hdb_entry structure  * that allows backends to keep a pointer to the backing store, ie in  * ->hdb_fetch_kvno(), so that we the kadmin/kpasswd backend gets around to  * ->hdb_store(), the backend doesn't need to lookup the entry again.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hdb_entry_ex
block|{
name|void
modifier|*
name|ctx
decl_stmt|;
name|hdb_entry
name|entry
decl_stmt|;
name|void
function_decl|(
modifier|*
name|free_entry
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|hdb_entry_ex
modifier|*
parameter_list|)
function_decl|;
block|}
name|hdb_entry_ex
typedef|;
end_typedef

begin_comment
comment|/**  * HDB backend function pointer structure  *  * The HDB structure is what the KDC and kadmind framework uses to  * query the backend database when talking about principals.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|HDB
block|{
name|void
modifier|*
name|hdb_db
decl_stmt|;
name|void
modifier|*
name|hdb_dbc
decl_stmt|;
comment|/** don't use, only for DB3 */
name|char
modifier|*
name|hdb_name
decl_stmt|;
name|int
name|hdb_master_key_set
decl_stmt|;
name|hdb_master_key
name|hdb_master_key
decl_stmt|;
name|int
name|hdb_openp
decl_stmt|;
name|int
name|hdb_capability_flags
decl_stmt|;
comment|/**      * Open (or create) the a Kerberos database.      *      * Open (or create) the a Kerberos database that was resolved with      * hdb_create(). The third and fourth flag to the function are the      * same as open(), thus passing O_CREAT will create the data base      * if it doesn't exists.      *      * Then done the caller should call hdb_close(), and to release      * all resources hdb_destroy().      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_open
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|int
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
comment|/**      * Close the database for transaction      *      * Closes the database for further transactions, wont release any      * permanant resources. the database can be ->hdb_open-ed again.      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_close
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|)
function_decl|;
comment|/**      * Free an entry after use.      */
name|void
function_decl|(
modifier|*
name|hdb_free
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|hdb_entry_ex
modifier|*
parameter_list|)
function_decl|;
comment|/**      * Fetch an entry from the backend      *      * Fetch an entry from the backend, flags are what type of entry      * should be fetch: client, server, krbtgt.      * knvo (if specified and flags HDB_F_KVNO_SPECIFIED set) is the kvno to get      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_fetch_kvno
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|krb5_const_principal
parameter_list|,
name|unsigned
parameter_list|,
name|krb5_kvno
parameter_list|,
name|hdb_entry_ex
modifier|*
parameter_list|)
function_decl|;
comment|/**      * Store an entry to database      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_store
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|hdb_entry_ex
modifier|*
parameter_list|)
function_decl|;
comment|/**      * Remove an entry from the database.      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_remove
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|krb5_const_principal
parameter_list|)
function_decl|;
comment|/**      * As part of iteration, fetch one entry      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_firstkey
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|hdb_entry_ex
modifier|*
parameter_list|)
function_decl|;
comment|/**      * As part of iteration, fetch next entry      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_nextkey
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|hdb_entry_ex
modifier|*
parameter_list|)
function_decl|;
comment|/**      * Lock database      *      * A lock can only be held by one consumers. Transaction can still      * happen on the database while the lock is held, so the entry is      * only useful for syncroning creation of the database and renaming of the database.      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_lock
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/**      * Unlock database      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_unlock
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|)
function_decl|;
comment|/**      * Rename the data base.      *      * Assume that the database is not hdb_open'ed and not locked.      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_rename
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/**      * Get an hdb_entry from a classical DB backend      *      * If the database is a classical DB (ie BDB, NDBM, GDBM, etc)      * backend, this function will take a principal key (krb5_data)      * and return all data related to principal in the return      * krb5_data. The returned encoded entry is of type hdb_entry or      * hdb_entry_alias.      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb__get
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|krb5_data
parameter_list|,
name|krb5_data
modifier|*
parameter_list|)
function_decl|;
comment|/**      * Store an hdb_entry from a classical DB backend      *      * Same discussion as in @ref HDB::hdb__get      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb__put
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|int
parameter_list|,
name|krb5_data
parameter_list|,
name|krb5_data
parameter_list|)
function_decl|;
comment|/**      * Delete and hdb_entry from a classical DB backend      *      * Same discussion as in @ref HDB::hdb__get      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb__del
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|krb5_data
parameter_list|)
function_decl|;
comment|/**      * Destroy the handle to the database.      *      * Destroy the handle to the database, deallocate all memory and      * related resources. Does not remove any permanent data. Its the      * logical reverse of hdb_create() function that is the entry      * point for the module.      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_destroy
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|)
function_decl|;
comment|/**      * Get the list of realms this backend handles.      * This call is optional to support. The returned realms are used      * for announcing the realms over bonjour. Free returned array      * with krb5_free_host_realm().      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_get_realms
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|krb5_realm
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/**      * Change password.      *      * Will update keys for the entry when given password.  The new      * keys must be written into the entry and will then later be      * ->hdb_store() into the database. The backend will still perform      * all other operations, increasing the kvno, and update      * modification timestamp.      *      * The backend needs to call _kadm5_set_keys() and perform password      * quality checks.      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_password
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|hdb_entry_ex
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/**      * Auth feedback      *      * This is a feedback call that allows backends that provides      * lockout functionality to register failure and/or successes.      *      * In case the entry is locked out, the backend should set the      * hdb_entry.flags.locked-out flag.      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_auth_status
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|hdb_entry_ex
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/**      * Check if delegation is allowed.      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_check_constrained_delegation
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|hdb_entry_ex
modifier|*
parameter_list|,
name|krb5_const_principal
parameter_list|)
function_decl|;
comment|/**      * Check if this name is an alias for the supplied client for PKINIT userPrinicpalName logins      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_check_pkinit_ms_upn_match
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|hdb_entry_ex
modifier|*
parameter_list|,
name|krb5_const_principal
parameter_list|)
function_decl|;
comment|/**      * Check if s4u2self is allowed from this client to this server      */
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_check_s4u2self
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|HDB
modifier|*
parameter_list|,
name|hdb_entry_ex
modifier|*
parameter_list|,
name|krb5_const_principal
parameter_list|)
function_decl|;
block|}
name|HDB
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HDB_INTERFACE_VERSION
value|7
end_define

begin_struct
struct|struct
name|hdb_so_method
block|{
name|int
name|version
decl_stmt|;
specifier|const
name|char
modifier|*
name|prefix
decl_stmt|;
name|krb5_error_code
function_decl|(
modifier|*
name|create
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|HDB
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|krb5_error_code
function_decl|(
modifier|*
name|hdb_foreach_func_t
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|HDB
modifier|*
parameter_list|,
name|hdb_entry_ex
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|krb5_kt_ops
name|hdb_kt_ops
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|hdb_method
block|{
name|int
name|interface_version
decl_stmt|;
specifier|const
name|char
modifier|*
name|prefix
decl_stmt|;
name|krb5_error_code
function_decl|(
modifier|*
name|create
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|HDB
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|hdb_interface_version
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<hdb-protos.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HDB_H__ */
end_comment

end_unit

