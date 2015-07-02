begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: hostfile.h,v 1.24 2015/02/16 22:08:57 djm Exp $ */
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HOSTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|HOSTFILE_H
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|HOST_OK
block|,
name|HOST_NEW
block|,
name|HOST_CHANGED
block|,
name|HOST_REVOKED
block|,
name|HOST_FOUND
block|}
name|HostStatus
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|MRK_ERROR
block|,
name|MRK_NONE
block|,
name|MRK_REVOKE
block|,
name|MRK_CA
block|}
name|HostkeyMarker
typedef|;
end_typedef

begin_struct
struct|struct
name|hostkey_entry
block|{
name|char
modifier|*
name|host
decl_stmt|;
name|char
modifier|*
name|file
decl_stmt|;
name|u_long
name|line
decl_stmt|;
name|struct
name|sshkey
modifier|*
name|key
decl_stmt|;
name|HostkeyMarker
name|marker
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|hostkeys
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|hostkeys
modifier|*
name|init_hostkeys
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_hostkeys
parameter_list|(
name|struct
name|hostkeys
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_hostkeys
parameter_list|(
name|struct
name|hostkeys
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HostStatus
name|check_key_in_hostkeys
parameter_list|(
name|struct
name|hostkeys
modifier|*
parameter_list|,
name|struct
name|sshkey
modifier|*
parameter_list|,
specifier|const
name|struct
name|hostkey_entry
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lookup_key_in_hostkeys_by_type
parameter_list|(
name|struct
name|hostkeys
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|hostkey_entry
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostfile_read_key
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|struct
name|sshkey
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|add_host_to_hostfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|sshkey
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hostfile_replace_entries
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
specifier|const
name|char
modifier|*
name|ip
parameter_list|,
name|struct
name|sshkey
modifier|*
modifier|*
name|keys
parameter_list|,
name|size_t
name|nkeys
parameter_list|,
name|int
name|store_hash
parameter_list|,
name|int
name|quiet
parameter_list|,
name|int
name|hash_alg
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HASH_MAGIC
value|"|1|"
end_define

begin_define
define|#
directive|define
name|HASH_DELIM
value|'|'
end_define

begin_define
define|#
directive|define
name|CA_MARKER
value|"@cert-authority"
end_define

begin_define
define|#
directive|define
name|REVOKE_MARKER
value|"@revoked"
end_define

begin_function_decl
name|char
modifier|*
name|host_hash
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Iterate through a hostkeys file, optionally parsing keys and matching  * hostnames. Allows access to the raw keyfile lines to allow  * streaming edits to the file to take place.  */
end_comment

begin_define
define|#
directive|define
name|HKF_WANT_MATCH
value|(1)
end_define

begin_comment
comment|/* return only matching hosts/addrs */
end_comment

begin_define
define|#
directive|define
name|HKF_WANT_PARSE_KEY
value|(1<<1)
end_define

begin_comment
comment|/* need key parsed */
end_comment

begin_define
define|#
directive|define
name|HKF_STATUS_OK
value|0
end_define

begin_comment
comment|/* Line parsed, didn't match host */
end_comment

begin_define
define|#
directive|define
name|HKF_STATUS_INVALID
value|1
end_define

begin_comment
comment|/* line had parse error */
end_comment

begin_define
define|#
directive|define
name|HKF_STATUS_COMMENT
value|2
end_define

begin_comment
comment|/* valid line contained no key */
end_comment

begin_define
define|#
directive|define
name|HKF_STATUS_MATCHED
value|3
end_define

begin_comment
comment|/* hostname or IP matched */
end_comment

begin_define
define|#
directive|define
name|HKF_MATCH_HOST
value|(1)
end_define

begin_comment
comment|/* hostname matched */
end_comment

begin_define
define|#
directive|define
name|HKF_MATCH_IP
value|(1<<1)
end_define

begin_comment
comment|/* address matched */
end_comment

begin_define
define|#
directive|define
name|HKF_MATCH_HOST_HASHED
value|(1<<2)
end_define

begin_comment
comment|/* hostname was hashed */
end_comment

begin_define
define|#
directive|define
name|HKF_MATCH_IP_HASHED
value|(1<<3)
end_define

begin_comment
comment|/* address was hashed */
end_comment

begin_comment
comment|/* XXX HKF_MATCH_KEY_TYPE? */
end_comment

begin_comment
comment|/*  * The callback function receives this as an argument for each matching   * hostkey line. The callback may "steal" the 'key' field by setting it to NULL.  * If a parse error occurred, then "hosts" and subsequent options may be NULL.  */
end_comment

begin_struct
struct|struct
name|hostkey_foreach_line
block|{
specifier|const
name|char
modifier|*
name|path
decl_stmt|;
comment|/* Path of file */
name|u_long
name|linenum
decl_stmt|;
comment|/* Line number */
name|u_int
name|status
decl_stmt|;
comment|/* One of HKF_STATUS_* */
name|u_int
name|match
decl_stmt|;
comment|/* Zero or more of HKF_MATCH_* OR'd together */
name|char
modifier|*
name|line
decl_stmt|;
comment|/* Entire key line; mutable by callback */
name|int
name|marker
decl_stmt|;
comment|/* CA/revocation markers; indicated by MRK_* value */
specifier|const
name|char
modifier|*
name|hosts
decl_stmt|;
comment|/* Raw hosts text, may be hashed or list multiple */
specifier|const
name|char
modifier|*
name|rawkey
decl_stmt|;
comment|/* Text of key and any comment following it */
name|int
name|keytype
decl_stmt|;
comment|/* Type of key; KEY_UNSPEC for invalid/comment lines */
name|struct
name|sshkey
modifier|*
name|key
decl_stmt|;
comment|/* Key, if parsed ok and HKF_WANT_MATCH_HOST set */
specifier|const
name|char
modifier|*
name|comment
decl_stmt|;
comment|/* Any comment following the key */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Callback fires for each line (or matching line if a HKF_WANT_* option  * is set). The foreach loop will terminate if the callback returns a non-  * zero exit status.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|hostkeys_foreach_fn
parameter_list|(
name|struct
name|hostkey_foreach_line
modifier|*
name|l
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Iterate over a hostkeys file */
end_comment

begin_function_decl
name|int
name|hostkeys_foreach
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|hostkeys_foreach_fn
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
specifier|const
name|char
modifier|*
name|ip
parameter_list|,
name|u_int
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

